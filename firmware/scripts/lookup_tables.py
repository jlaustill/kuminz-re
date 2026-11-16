#!/usr/bin/env python3
"""Audit the CM848 lookup tables: every table argument of a table interpolator should be a
word[N] array of the right size (in global_variables.csv or arrays.csv), and a lookup cache word
should not need a cast. Can write the rows for tables that are not typed yet.

Usage:
    python3 lookup_tables.py               # audit the CSVs against the last build (exit 1 = findings)
    python3 lookup_tables.py --plan FILE   # also write every table (role / size / readers) as CSV
    python3 lookup_tables.py --apply       # add / retype global_variables.csv rows for the untyped
                                           # tables and cast cache words that have no conflict
                                           # (never deletes a row), then run ./analyze.sh build

Where the tables come from: the table arguments of the interpolators in LOOKUPS, read two ways -
the argument text in cm848_rom.ghidra.cpp, and the registers loaded right before each call in the
ROM / flash2 disassembly. A name that labels two addresses counts only from the disassembly.

How they are sized, from the loaded images (ROM, its 0x3F9800 mirror, the RAM dump, flash2):
  axis  1 + (first word = byte length of the breakpoints) / 2 words; the length is even and at
        most 0x400 and the breakpoints are monotonic (signed or unsigned)
  data  one value per axis breakpoint after its own byte-length word (checked against the axis)
  grid  nx x ny values, no header (cm848_dualAxisTableInterpolation reads z[(y - 1) x nx + x - 1])

CM848 / PowerPC big-endian only. See firmware/CLAUDE.md "Table lookups".
"""
import argparse
import bisect
import csv
import os
import re
import sys
from collections import defaultdict, namedtuple

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import disasm_func as D

OUTPUT = os.path.join(D.FW, "output")
ORIGINALS = os.path.join(D.FW, "originals")

# role -> (C argument index, argument register); cache = (argument index, register, words)
Lookup = namedtuple("Lookup", "name address roles cache")
SENSOR_ROLES = {"x": (3, "r6"), "y": (4, "r7")}
LOOKUPS = [
    Lookup("lookupTableInterpolation", 0x55ef4, {"x": (2, "r5"), "y": (3, "r6")}, (0, "r3", 1)),
    Lookup("cm848_interpolateTableWithoutCache", 0x15d2c, {"x": (1, "r4"), "y": (2, "r5")}, None),
    Lookup("cm848_dualAxisTableInterpolation", 0x566cc,
           {"x": (2, "r5"), "y_axis": (4, "r7"), "z": (5, "r8")}, (0, "r3", 2)),
    Lookup("cm848_interpolateFuelMapTable", 0x15e08,
           {"x": (2, "r5"), "y": (3, "r6"), "x2": (4, "r7"), "y2": (5, "r8"), "y3": (6, "r9"),
            "y4": (7, "r10")}, None),
    Lookup("sensorChannelTypeB_configInit", 0x5012dc, SENSOR_ROLES, (2, "r5", 1)),
    Lookup("sensorChannelTypeB_update", 0x501b4c, SENSOR_ROLES, (2, "r5", 1)),
    Lookup("sensorChannelConfigInit", 0x500234, SENSOR_ROLES, (2, "r5", 1)),
    Lookup("updateSensorChannelWithConfig", 0x500a4c, SENSOR_ROLES, (2, "r5", 1)),
]
AXIS_ROLES = ("x", "x2", "y_axis")
DATA_AXIS = {"y": "x", "y2": "x2", "y3": "x2", "y4": "x2"}     # 1-D data role -> its axis role
CACHE_CASTS = ("(word *)", "(table_interp_args_t *)")
JUNK_NAME = re.compile(r"^(u_|s_|BYTE_|WORD_|DWORD_|DAT_|UNK_)")
MAX_AXIS_BYTES = 0x400

Call = namedtuple("Call", "source callee roles function")       # roles: {role: address}


# ── memory ──────────────────────────────────────────────────────────────────────────

class MemoryImage:
    """The bytes Ghidra loads for CM848 (SetupMemoryMapCM848.java), read big-endian."""

    def __init__(self, originals=ORIGINALS):
        def load(name):
            with open(os.path.join(originals, name), "rb") as f:
                return f.read()
        rom = load("cm848_rom.bin")
        self.blocks = [(0x0, rom[:0x70000]),
                       (0x3F9800, rom[0x3C30:0x3C30 + 0x800]),        # ROM-to-RAM low mirror
                       (0x3FA000, load("cm848_ram.bin")),
                       (0x500000, load("cm848_flash2_live.bin"))]

    def word(self, addr):
        for base, data in self.blocks:
            if base <= addr and addr + 2 <= base + len(data):
                return int.from_bytes(data[addr - base:addr - base + 2], "big")
        return None

    def region(self, addr):
        names = {0x0: "rom", 0x3F9800: "rom mirror", 0x3FA000: "ram", 0x500000: "flash2"}
        for base, data in self.blocks:
            if base <= addr < base + len(data):
                return names[base]
        return None


# ── CSV state ───────────────────────────────────────────────────────────────────────

class CsvState:
    """The rows the audit compares against: globals, arrays.csv, struct instances, functions."""

    def __init__(self, globals_lines, array_lines=(), struct_rows=(), function_lines=()):
        self.rows = {}                       # address -> (name, type, comment)
        self.addresses = defaultdict(list)   # name -> [address]
        for line in globals_lines:
            p = line.rstrip("\n").split(",", 3)
            if p[0].startswith("0x") and len(p) > 1:
                a = int(p[0], 16)
                self.rows.setdefault(a, (p[1], p[2] if len(p) > 2 else "", p[3] if len(p) > 3 else ""))
                if p[1]:
                    self.addresses[p[1]].append(a)
        self.duplicates = {n for n, v in self.addresses.items() if len(v) > 1}
        self.arrays = {}                     # address -> (name, byte size)
        for line in array_lines:
            p = line.rstrip("\n").split(",", 4)
            if p[0].startswith("0x") and len(p) >= 4 and p[3].strip().isdigit():
                width = {"byte": 1, "word": 2, "dword": 4, "pointer": 4}.get(p[2].strip(), 1)
                self.arrays[int(p[0], 16)] = (p[1], width * int(p[3]))
        struct_size = defaultdict(int)
        for p in struct_rows:
            if len(p) >= 5 and p[0] and not p[0].startswith("#") and p[2] and p[4].strip().isdigit():
                struct_size[p[0]] += int(p[4])
        self.structs = {a: (r[0], struct_size[r[1]]) for a, r in self.rows.items() if r[1] in struct_size}
        self.functions = {}
        for line in function_lines:
            p = line.split(",", 2)
            if p[0].startswith("0x") and len(p) > 1:
                self.functions[int(p[0], 16)] = p[1].strip()
        self.array_names = ({v[0] for v in self.arrays.values()} |
                            {r[0] for r in self.rows.values() if r[0] and "[" in r[1]})
        self.sorted_rows = sorted(self.rows)

    @classmethod
    def load(cls, output=OUTPUT):
        def lines(name):
            path = os.path.join(output, name)
            return open(path).readlines() if os.path.exists(path) else []
        structs = list(csv.reader(open(os.path.join(output, "structure_definitions.csv"))))
        return cls(lines("global_variables.csv"), lines("arrays.csv"), structs, lines("function_renames.csv"))

    def declared_words(self, addr):
        """Words the CSVs declare at addr as a word array (global T[N] row or arrays.csv), else None."""
        if addr in self.arrays:
            return self.arrays[addr][1] // 2
        row = self.rows.get(addr)
        m = re.fullmatch(r"word\[(\d+)\]", row[1]) if row else None
        return int(m.group(1)) if m else None

    def rows_inside(self, start, end):
        """Addresses of rows strictly inside (start, end)."""
        i = bisect.bisect_right(self.sorted_rows, start)
        out = []
        while i < len(self.sorted_rows) and self.sorted_rows[i] < end:
            out.append(self.sorted_rows[i]); i += 1
        return out


# ── reading the calls ───────────────────────────────────────────────────────────────

_TOKEN = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)\s*\(|(\()|(\))|(,)|([^(),A-Za-z_]+|[A-Za-z_][A-Za-z0-9_]*)")
_HEADER = re.compile(r"^// Function: (\S+) @", re.M)


def parse_calls(text, wanted):
    """[(callee, [argument text], enclosing function)] for every call to a name in `wanted`.

    Tracks parentheses, so wrapped lines and nested calls / casts inside arguments are fine.
    """
    headers = [(m.start(), m.group(1)) for m in _HEADER.finditer(text)]
    starts = [p for p, _ in headers]
    stack, calls = [], []
    for m in _TOKEN.finditer(text):
        fn, op, cp, comma, other = m.groups()
        if fn is not None:
            stack.append([fn, [], [], m.start()])
        elif op is not None:
            stack.append(["(", [], [], m.start()])
        elif cp is not None:
            if not stack:
                continue
            owner, args, cur, pos = stack.pop()
            args.append("".join(cur))
            if owner in wanted:
                i = bisect.bisect_right(starts, pos) - 1
                calls.append((owner, [a.strip() for a in args], headers[i][1] if i >= 0 else "?"))
            if stack:
                stack[-1][2].append(("" if owner == "(" else owner) + "(" + ",".join(args) + ")")
        elif comma is not None:
            if stack:
                stack[-1][1].append("".join(stack[-1][2])); stack[-1][2] = []
        elif stack:
            stack[-1][2].append(other)
    return calls


def resolve_argument(text, state):
    """Address a table / cache argument points at, or None.

    Address-of forms, hex literals, WORD_ARRAY_<address> and names that are already arrays point at
    the global; a bare scalar name is passed by value (a pointer variable), so it is not the table.
    A name that labels two addresses is ambiguous here (the disassembly resolves it).
    """
    t = re.sub(r"^\((?:word|ushort|short|undefined2|byte|undefined|undefined1|void|table_interp_args_t) \*\)",
               "", text.strip()).strip()
    address_of = t.startswith("&")
    t = t.lstrip("&").strip()
    m = re.fullmatch(r"0x([0-9a-fA-F]+)", t)
    if m:
        return int(m.group(1), 16)
    m = re.fullmatch(r"WORD_ARRAY_([0-9a-fA-F]{8})", t)
    if m:
        return int(m.group(1), 16)
    if not address_of and t not in state.array_names:
        return None
    if t in state.duplicates:
        return None
    if t in state.addresses:
        return state.addresses[t][0]
    m = re.fullmatch(r"(?:_?DAT_|uRam|ram0x|UNK_|BYTE_|WORD_|u_\S*?_)([0-9a-fA-F]{8})", t)
    return int(m.group(1), 16) if m else None


def calls_from_cpp(text, state):
    """Call records from the decompiled argument text, plus cache arguments rendered with a cast."""
    by_name = {lk.name: lk for lk in LOOKUPS}
    calls, cast_caches = [], defaultdict(set)
    for callee, args, function in parse_calls(text, set(by_name)):
        lk = by_name[callee]
        roles = {}
        for role, (index, _) in lk.roles.items():
            if index < len(args):
                a = resolve_argument(args[index], state)
                if a is not None:
                    roles[role] = a
        calls.append(Call("cpp", callee, roles, function))
        if lk.cache and lk.cache[0] < len(args) and args[lk.cache[0]].startswith(CACHE_CASTS):
            a = resolve_argument(args[lk.cache[0]], state)
            if a is not None:
                cast_caches[a].add((callee, lk.cache[2]))
    return calls, cast_caches


def calls_from_disassembly(lines, function_at):
    """Call records from objdump lines: the argument registers' values at each lookup call.

    Register values come from D.step_address_registers; every branch or call clears them, so only
    straight-line argument setup counts (anything else is left to the .cpp side).
    """
    by_address = {lk.address: lk for lk in LOOKUPS}
    regs, calls = {0: 0}, []
    for line in lines:
        m = D.ASM_LINE.match(line)
        if not m:
            continue
        addr, mnem, ops = int(m.group(1), 16), m.group(2), m.group(3).split("#")[0].replace(" ", "")
        op = ops.split(",")
        if mnem == "bl":
            t = re.match(r"0x([0-9a-f]+)", ops)
            lk = by_address.get(int(t.group(1), 16)) if t else None
            if lk:
                roles = {role: regs.get(int(reg[1:])) for role, (_, reg) in lk.roles.items()}
                calls.append(Call("disasm", lk.name, {r: a for r, a in roles.items() if a is not None},
                                  function_at(addr)))
            regs = {0: 0}
        elif mnem.startswith("b"):
            regs = {0: 0}
        elif mnem in D.WIDTH:                                 # load / store
            if not mnem.startswith("st") and op and re.fullmatch(r"r\d+", op[0]):
                regs.pop(int(op[0][1:]), None)
        else:
            D.step_address_registers(regs, mnem, op)
    return calls


def disassembly_lines():
    rom, _ = D.objdump(0x0, 0x70000)
    flash2, _ = D.objdump(0x500000, 0x53e000)
    return rom + flash2


# ── sizing ──────────────────────────────────────────────────────────────────────────

def axis_points(word_at, addr):
    """Breakpoint count of the axis at addr, or None if its length word / order is not an axis's."""
    length = word_at(addr)
    if length is None or length == 0 or length & 1 or length > MAX_AXIS_BYTES:
        return None
    points = [word_at(addr + 2 * i) for i in range(1, length // 2 + 1)]
    if any(p is None for p in points):
        return None
    signed = [p - 0x10000 if p & 0x8000 else p for p in points]
    ascending = lambda v: all(v[i] <= v[i + 1] for i in range(len(v) - 1))
    return length // 2 if ascending(points) or ascending(signed) else None


Table = namedtuple("Table", "counts roles details readers")


def size_tables(calls, word_at):
    """({address: Table}, [problem]) from the call records."""
    counts, roles, details, readers = (defaultdict(set) for _ in range(4))
    problems = []

    def note(a, count, role, detail, function):
        counts[a].add(count); roles[a].add(role); details[a].add(detail); readers[a].add(function)

    for call in calls:
        n = {}
        for role in AXIS_ROLES:
            if role in call.roles:
                a = call.roles[role]
                points = axis_points(word_at, a)
                if points is None:
                    problems.append(f"{call.source} {call.callee} in {call.function}: {role} 0x{a:08x} is not an axis")
                    continue
                n[role] = points
                note(a, points + 1, "axis", f"{'y' if role == 'y_axis' else 'x'} axis of {points} breakpoints "
                     "after its byte-length word", call.function)
        for role, axis in DATA_AXIS.items():
            if role in call.roles and axis in n:
                a = call.roles[role]
                if word_at(a) != 2 * n[axis]:
                    problems.append(f"{call.source} {call.callee} in {call.function}: data 0x{a:08x} header "
                                    f"{word_at(a)} != axis length {2 * n[axis]}")
                note(a, n[axis] + 1, "data", f"data: {n[axis]} values (one per axis breakpoint) after a "
                     "byte-length word", call.function)
        if "z" in call.roles and "x" in n and "y_axis" in n:
            note(call.roles["z"], n["x"] * n["y_axis"], "grid", f"2-D grid: {n['y_axis']} rows of {n['x']} "
                 f"values (z[(y - 1) x {n['x']} + x - 1] / no header)", call.function)
    tables = {a: Table(counts[a], roles[a], details[a], readers[a] - {"?"}) for a in counts}
    return tables, problems


# ── audit / apply ───────────────────────────────────────────────────────────────────

Finding = namedtuple("Finding", "kind address words detail")


def audit(tables, state, cast_caches=None, region=None):
    """[Finding] for every table that is untyped, typed with another size, or has a conflict."""
    findings = []
    starts = sorted(tables)
    for a in starts:
        t = tables[a]
        words = max(t.counts)
        end = a + 2 * words
        if len(t.counts) > 1:
            findings.append(Finding("sizes disagree", a, words, "/".join(map(str, sorted(t.counts)))))
        declared = state.declared_words(a)
        if declared is None:
            findings.append(Finding("untyped", a, words, state.rows.get(a, ("", "", ""))[0] or "no row"))
        elif declared != words:
            findings.append(Finding("wrong size", a, words, f"declared {declared}"))
        inside = [b for b in state.rows_inside(a, end)]
        if inside:
            findings.append(Finding("rows inside", a, words, " ".join(f"0x{b:x}:{state.rows[b][0]}" for b in inside)))
        for s, (name, size) in state.structs.items():
            if s < end and a < s + max(size, 1) and s != a:
                findings.append(Finding("struct overlap", a, words, f"{name}@0x{s:x}"))
        for b, (name, size) in state.arrays.items():
            if b != a and b < end and a < b + size:
                findings.append(Finding("arrays.csv overlap", a, words, name))
        functions = [n for f, n in state.functions.items() if a <= f < end]
        if functions:
            findings.append(Finding("functions inside", a, words, " ".join(functions)))
        if region and region(a) not in ("rom", "ram", "flash2"):
            findings.append(Finding("region", a, words, str(region(a))))
        others = [b for b in starts if a < b < end]
        if others:
            findings.append(Finding("tables overlap", a, words, " ".join(f"0x{b:x}" for b in others)))
    for a, users in sorted((cast_caches or {}).items()):
        words = max(w for _, w in users)
        findings.append(Finding("cache cast", a, words, " / ".join(sorted({c for c, _ in users}))))
    return findings


def plan_rows(tables, findings, state, gap_to_next):
    """{address: (name, type, comment)} for the findings --apply may fix on its own."""
    blocked = {f.address for f in findings if f.kind not in ("untyped", "cache cast")}
    changes = {}
    for f in findings:
        if f.address in blocked:
            continue
        row = state.rows.get(f.address)
        if f.kind == "untyped":
            t = tables[f.address]
            readers = sorted(t.readers)
            shown = " / ".join(readers[:3]) + (f" (+{len(readers) - 3} more)" if len(readers) > 3 else "")
            comment = f"Lookup table - {' / '.join(sorted(t.details))} - read by {shown}"
            if row and row[0] and not JUNK_NAME.match(row[0]):
                changes[f.address] = (row[0], f"word[{f.words}]", row[2] or comment)
            else:
                changes[f.address] = ("", f"word[{f.words}]", comment)
        elif f.kind == "cache cast" and (gap_to_next(f.address) or 99) >= 2 * f.words:
            typ = "word" if f.words == 1 else f"word[{f.words}]"
            name = row[0] if row and row[0] and not JUNK_NAME.match(row[0]) else ""
            comment = (row[2] if row and row[0] else "") or (
                "Lookup cache: the last axis segment offset (2 x index)" if f.words == 1 else
                "Lookup cache: the last x / y axis segment offsets (2 x index)") + f" kept by {f.detail}"
            changes[f.address] = (name, typ, comment)
    return changes


def write_rows(path, changes):
    """Edit rows in place (the file is not strictly sorted); insert new ones after the nearest lower row."""
    lines = open(path).read().split("\n")
    done = set()
    for i, line in enumerate(lines):
        p = line.split(",", 1)
        if p[0].startswith("0x"):
            a = int(p[0], 16)
            if a in changes and a not in done:
                name, typ, comment = changes[a]
                lines[i] = f"0x{a:08x},{name},{typ},{comment}"
                done.add(a)
    index = {}
    for i, line in enumerate(lines):
        p = line.split(",", 1)
        if p[0].startswith("0x"):
            index.setdefault(int(p[0], 16), i)
    anchors = sorted(index)
    inserts = []
    for a in sorted(set(changes) - done):
        j = bisect.bisect_left(anchors, a) - 1
        inserts.append((index[anchors[j]] + 1 if j >= 0 else 1, a))
    for at, a in sorted(inserts, reverse=True):
        name, typ, comment = changes[a]
        lines.insert(at, f"0x{a:08x},{name},{typ},{comment}")
    open(path, "w").write("\n".join(lines))
    return len(done), len(inserts)


# ── main ────────────────────────────────────────────────────────────────────────────

def collect(state, image):
    text = open(D.CPP, errors="replace").read()
    cpp_calls, cast_caches = calls_from_cpp(text, state)
    functions = D.function_table()
    starts = [a for a, _ in functions]

    def function_at(addr):
        i = bisect.bisect_right(starts, addr) - 1
        return functions[i][1] if i >= 0 else "?"

    calls = cpp_calls + calls_from_disassembly(disassembly_lines(), function_at)
    tables, problems = size_tables(calls, image.word)
    return tables, problems, cast_caches


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--plan", help="write every table (address / words / roles / readers) to this CSV")
    parser.add_argument("--apply", action="store_true", help="write the rows for untyped, conflict-free tables")
    parser.add_argument("--limit", type=int, default=25, help="findings listed per kind (default 25)")
    args = parser.parse_args(argv)

    state, image = CsvState.load(), MemoryImage()
    tables, problems, cast_caches = collect(state, image)
    findings = audit(tables, state, cast_caches, image.region)

    roles = defaultdict(int)
    for t in tables.values():
        roles["+".join(sorted(t.roles))] += 1
    print(f"lookup tables: {len(tables)} ({', '.join(f'{k} {v}' for k, v in sorted(roles.items()))}); "
          f"typed: {sum(1 for a in tables if state.declared_words(a) is not None)}")
    by_kind = defaultdict(list)
    for f in findings:
        by_kind[f.kind].append(f)
    for kind, items in sorted(by_kind.items()):
        print(f"{kind}: {len(items)}")
        for f in items[:args.limit]:
            print(f"   0x{f.address:08x} {f.words:4d} words  {f.detail[:110]}")
    print(f"sizing problems: {len(problems)}")
    for p in problems[:args.limit]:
        print("  ", p)

    if args.plan:
        with open(args.plan, "w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(["address", "words", "roles", "name", "declared_words", "details", "readers"])
            for a in sorted(tables):
                t = tables[a]
                w.writerow([f"0x{a:08x}", max(t.counts), "+".join(sorted(t.roles)),
                            state.rows.get(a, ("", "", ""))[0], state.declared_words(a) or "",
                            " / ".join(sorted(t.details)), " ".join(sorted(t.readers))])
        print("plan written to", args.plan)

    if args.apply:
        rows = state.sorted_rows

        def gap_to_next(a):
            i = bisect.bisect_right(rows, a)
            return rows[i] - a if i < len(rows) else None
        changes = plan_rows(tables, findings, state, gap_to_next)
        edited, inserted = write_rows(os.path.join(OUTPUT, "global_variables.csv"), changes)
        print(f"--apply: {edited} rows retyped, {inserted} rows added - run ./analyze.sh build, then re-audit")
    return 1 if findings or problems else 0


if __name__ == "__main__":
    sys.exit(main())
