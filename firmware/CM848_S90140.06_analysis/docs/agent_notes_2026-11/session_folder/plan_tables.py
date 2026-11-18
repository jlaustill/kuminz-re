#!/usr/bin/env python3
"""Plan word[N] array types for every CM848 lookup table (read-only).

Sources: the table arguments of the four interpolators, taken from the decompiled .cpp
(argument text -> address) and from the call-site disassembly (register loads). Sizes:
an axis has a byte-length first word (count = 1 + length / 2, breakpoints must be
monotonic); 1-D data has one value per axis point plus its header word; a 2-D grid has
nx * ny values and no header. Usage: plan_tables.py <analysis_dir> <disasm_csv> <out_plan_csv>
"""
import bisect
import csv
import re
import sys
from collections import defaultdict

ANALYSIS, DISASM_CSV, OUT = sys.argv[1], sys.argv[2], sys.argv[3]
CPP = f"{ANALYSIS}/output/cm848_rom.ghidra.cpp"
CALLEES = {
    "lookupTableInterpolation": {"x": 2, "y": 3},
    "cm848_interpolateTableWithoutCache": {"x": 1, "y": 2},
    "cm848_dualAxisTableInterpolation": {"x": 2, "y2d": 4, "z": 5},
    "cm848_interpolateFuelMapTable": {"x": 2, "y": 3, "x2": 4, "y2": 5, "y3": 6, "y4": 7},
    "sensorChannelTypeB_configInit": {"x": 3, "y": 4},
    "sensorChannelTypeB_update": {"x": 3, "y": 4},
    "sensorChannelConfigInit": {"x": 3, "y": 4},
    "updateSensorChannelWithConfig": {"x": 3, "y": 4},
}
PAIRS = (("y", "x"), ("y2", "x2"), ("y3", "x2"), ("y4", "x2"))
# callee -> (cache argument index, cache words)
CACHE_ARG = {"lookupTableInterpolation": (0, 1), "cm848_dualAxisTableInterpolation": (0, 2),
             "sensorChannelTypeB_configInit": (2, 1), "sensorChannelTypeB_update": (2, 1),
             "sensorChannelConfigInit": (2, 1), "updateSensorChannelWithConfig": (2, 1)}
CACHE_CASTS = ("(word *)", "(table_interp_args_t *)")
if len(sys.argv) > 4:
    CPP = sys.argv[4]

def load(name):
    with open(f"{ANALYSIS}/originals/{name}", "rb") as f:
        return f.read()
rom, flash2, ram = load("cm848_rom.bin"), load("cm848_flash2_live.bin"), load("cm848_ram.bin")

def region(a):
    if 0 <= a < 0x70000: return "rom"
    if 0x3F9800 <= a < 0x3FA000: return "romram_low"
    if 0x3FA000 <= a < 0x3FA000 + len(ram): return "ram"
    if 0x500000 <= a < 0x500000 + len(flash2): return "flash2"
    return None

def word_at(a):
    r = region(a)
    if r == "rom": b = rom[a:a + 2]
    elif r == "romram_low": b = rom[0x3C30 + a - 0x3F9800:0x3C30 + a - 0x3F9800 + 2]
    elif r == "ram": b = ram[a - 0x3FA000:a - 0x3FA000 + 2]
    elif r == "flash2": b = flash2[a - 0x500000:a - 0x500000 + 2]
    else: return None
    return int.from_bytes(b, "big") if len(b) == 2 else None

# --- CSV state ----------------------------------------------------------------------
rows_by_addr, addrs_by_name = {}, defaultdict(list)
for line in open(f"{ANALYSIS}/output/global_variables.csv"):
    p = line.rstrip("\n").split(",", 3)
    if p[0].startswith("0x"):
        a = int(p[0], 16)
        rows_by_addr[a] = (p[1], p[2] if len(p) > 2 else "", p[3] if len(p) > 3 else "")
        addrs_by_name[p[1]].append(a)
duplicate_names = {n for n, v in addrs_by_name.items() if len(v) > 1}
array_rows = {}
for line in open(f"{ANALYSIS}/output/arrays.csv"):
    p = line.rstrip("\n").split(",", 4)
    if p[0].startswith("0x") and len(p) >= 4:
        size = {"byte": 1, "word": 2, "dword": 4, "pointer": 4}.get(p[2], 1) * int(p[3])
        array_rows[int(p[0], 16)] = (p[1], size)
struct_size = defaultdict(int)
for p in csv.reader(open(f"{ANALYSIS}/output/structure_definitions.csv")):
    if len(p) >= 5 and p[0] and not p[0].startswith("#") and p[0] != "struct_name" and p[2]:
        try: struct_size[p[0]] += int(p[4])
        except ValueError: pass
struct_instances = {a: (r[0], r[1], struct_size[r[1]]) for a, r in rows_by_addr.items() if r[1] in struct_size}
functions = {}
for line in open(f"{ANALYSIS}/output/function_renames.csv"):
    p = line.split(",", 2)
    if p[0].startswith("0x"): functions[int(p[0], 16)] = p[1].strip()
array_names = {v[0] for v in array_rows.values()} | {r[0] for r in rows_by_addr.values() if "[" in r[1]}

def resolve(text):
    t = re.sub(r"^\((?:word|ushort|short|undefined2|byte|undefined|undefined1) \*\)", "", text.strip()).strip()
    address_of = t.startswith("&")
    t = t.lstrip("&").strip()
    m = re.fullmatch(r"0x([0-9a-fA-F]+)", t)
    if m: return int(m.group(1), 16)
    m = re.fullmatch(r"WORD_ARRAY_([0-9a-fA-F]{8})", t)           # an unnamed typed array
    if m: return int(m.group(1), 16)
    if not address_of and t not in array_names: return None          # passed by value
    if t in duplicate_names: return None                             # ambiguous: disasm decides
    if t in addrs_by_name: return addrs_by_name[t][0]
    m = re.fullmatch(r"(?:_?DAT_|uRam|ram0x|UNK_|BYTE_|WORD_|u_\S*?_)([0-9a-fA-F]{8})", t)
    if m: return int(m.group(1), 16)
    return None

# --- collect call tuples ------------------------------------------------------------
calls = []   # (source, callee, {role: addr}, function)
src = open(CPP).read()
header_pos = [(m.start(), m.group(1)) for m in re.finditer(r"^// Function: (\S+) @", src, re.M)]
header_starts = [p for p, _ in header_pos]
def cpp_function_at(pos):
    i = bisect.bisect_right(header_starts, pos) - 1
    return header_pos[i][1] if i >= 0 else "?"
function_addrs = sorted(functions)
def function_containing(addr):
    i = bisect.bisect_right(function_addrs, addr) - 1
    return functions[function_addrs[i]] if i >= 0 else "?"
tok = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)\s*\(|(\()|(\))|(,)|([^(),A-Za-z_]+|[A-Za-z_][A-Za-z0-9_]*)")
stack = []
cache_uses = defaultdict(lambda: [0, set()])
for m in tok.finditer(src):
    fn, op, cp, comma, other = m.groups()
    if fn is not None: stack.append([fn, [], []])
    elif op is not None: stack.append(["(", [], []])
    elif cp is not None:
        if not stack: continue
        owner, args, cur = stack.pop()
        args.append("".join(cur))
        if owner in CALLEES:
            roles = {}
            for role, idx in CALLEES[owner].items():
                if idx < len(args):
                    a = resolve(args[idx])
                    if a is not None: roles[role] = a
            calls.append(("cpp", owner, roles, cpp_function_at(m.start())))
        if owner in CACHE_ARG and len(args) > CACHE_ARG[owner][0]:
            raw = args[CACHE_ARG[owner][0]].strip()
            a = resolve(re.sub(r"^\(table_interp_args_t \*\)", "(word *)", raw))
            if a is not None:
                cache_uses[a][0] += 1
                cache_uses[a][1].add((owner, raw.startswith(CACHE_CASTS)))
        if stack: stack[-1][2].append(("" if owner == "(" else owner) + "(" + ",".join(args) + ")")
    elif comma is not None:
        if stack: stack[-1][1].append("".join(stack[-1][2])); stack[-1][2] = []
    else:
        if stack: stack[-1][2].append(other)
by_site = defaultdict(dict)
callee_of = {}
for r in csv.DictReader(open(DISASM_CSV)):
    if r["table"]:
        by_site[r["call_site"]][r["role"]] = int(r["table"], 16)
        callee_of[r["call_site"]] = r["callee"]
for site, roles in by_site.items():
    calls.append(("disasm", callee_of[site], roles, function_containing(int(site, 16))))

# --- size ------------------------------------------------------------------------------
def axis_points(a):
    n = word_at(a)
    if n is None or n == 0 or n & 1 or n > 0x400: return None
    pts = [word_at(a + 2 * i) for i in range(1, n // 2 + 1)]
    if any(v is None for v in pts): return None
    sig = [v - 0x10000 if v & 0x8000 else v for v in pts]
    ok = all(pts[i] <= pts[i + 1] for i in range(len(pts) - 1)) or all(sig[i] <= sig[i + 1] for i in range(len(sig) - 1))
    return n // 2 if ok else None

sizes = defaultdict(set)      # addr -> {count}
roles_of = defaultdict(set)
detail_of = defaultdict(set)
readers_of = defaultdict(set)
problems = []
for source, callee, roles, function in calls:
    n = {}
    for role in ("x", "x2", "y2d"):
        if role in roles:
            pts = axis_points(roles[role])
            if pts is None:
                problems.append((source, callee, role, hex(roles[role]), "axis header/monotonic check failed"))
                continue
            n[role] = pts
            a = roles[role]
            sizes[a].add(pts + 1); roles_of[a].add("axis"); readers_of[a].add(function)
            detail_of[a].add(f"{'y axis' if role == 'y2d' else 'x axis'} of {pts} breakpoints after its byte-length word")
    for role, axis_role in PAIRS:
        if role in roles and axis_role in n:
            a = roles[role]
            own = word_at(a)
            count = n[axis_role] + 1
            if own != n[axis_role] * 2:
                problems.append((source, callee, role, hex(a), f"data header {own} != axis length {n[axis_role] * 2}"))
            sizes[a].add(count); roles_of[a].add("data"); readers_of[a].add(function)
            detail_of[a].add(f"data: {n[axis_role]} values (one per axis breakpoint) after a byte-length word")
    if "z" in roles and "x" in n and "y2d" in n:
        a = roles["z"]
        sizes[a].add(n["x"] * n["y2d"]); roles_of[a].add("grid"); readers_of[a].add(function)
        detail_of[a].add(f"2-D grid: {n['y2d']} rows of {n['x']} values (z[(y - 1) x {n['x']} + x - 1] / no header)")

# --- plan ------------------------------------------------------------------------------
named = sorted(rows_by_addr)
plan = []
table_addrs = sorted(sizes)
for a in table_addrs:
    count = max(sizes[a])
    end = a + 2 * count
    notes = []
    if len(sizes[a]) > 1: notes.append("sizes " + "/".join(map(str, sorted(sizes[a]))))
    reg = region(a)
    if reg not in ("rom", "ram", "flash2"): notes.append(f"region {reg}")
    if 0x3F9800 <= a < 0x3FDB30: notes.append("copy window")
    inside = []
    i = bisect.bisect_right(named, a)
    while i < len(named) and named[i] < end:
        inside.append(f"0x{named[i]:x}:{rows_by_addr[named[i]][0]}"); i += 1
    tables_inside = [f"0x{b:x}" for b in table_addrs if a < b < end]
    structs = [f"{v[0]}@0x{s:x}" for s, v in struct_instances.items() if s < end and a < s + max(v[2], 1)]
    arrays = [v[0] for b, v in array_rows.items() if b < end and a < b + v[1]]
    funcs = [functions[f] for f in functions if a <= f < end]
    row = rows_by_addr.get(a)
    if row is None: action = "add_type_only"
    elif re.match(r"^(u_|s_|BYTE_|WORD_|DAT_|UNK_)", row[0]): action = "junk_to_type_only"
    elif row[0] in duplicate_names: action = "retype_duplicate_name"
    else: action = "retype_named"
    plan.append({"address": f"0x{a:08x}", "action": action, "name": row[0] if row else "",
                 "old_type": row[1] if row else "", "count": count, "roles": "+".join(sorted(roles_of[a])),
                 "region": reg, "named_inside": " ".join(inside), "tables_inside": " ".join(tables_inside),
                 "structs": " ".join(structs), "arrays": " ".join(arrays), "functions": " ".join(funcs),
                 "notes": "; ".join(notes), "detail": " / ".join(sorted(detail_of[a])),
                 "readers": " ".join(sorted(readers_of[a] - {"?"}))})

with open(OUT, "w", newline="") as f:
    w = csv.DictWriter(f, fieldnames=list(plan[0].keys()))
    w.writeheader(); w.writerows(plan)

from collections import Counter
print("tables:", len(plan), Counter(p["action"] for p in plan))
print("regions:", Counter(p["region"] for p in plan))
print("roles:", Counter(p["roles"] for p in plan))
for key in ("named_inside", "tables_inside", "structs", "arrays", "functions", "notes"):
    hits = [p for p in plan if p[key]]
    print(f"{key}: {len(hits)}")
    for p in hits[:14]:
        print(f"   {p['address']} {p['name'][:40]:40s} n={p['count']:<4} {p['roles']:10s} {p[key][:110]}")
print("problems:", len(problems))
for pr in problems[:25]: print("  ", pr)
# cache words: (addr) -> uses; show the ones rendered with a (word *) cast and their CSV type + gap
print("cache words with casts:")
cache_plan = []
for a in sorted(cache_uses):
    uses, kinds = cache_uses[a]
    if any(k[1] for k in kinds):
        row = rows_by_addr.get(a, ("", "", ""))
        nxt = named[bisect.bisect_right(named, a)] if bisect.bisect_right(named, a) < len(named) else None
        gap = (nxt - a) if nxt else None
        words = max(CACHE_ARG[k[0]][1] for k in kinds)
        print(f"   0x{a:08x} {row[0]:50s} type={row[1]:8s} uses={uses} gap={gap} words={words} {sorted(k[0] for k in kinds)}")
        cache_plan.append({"address": f"0x{a:08x}", "name": row[0], "old_type": row[1], "words": words, "gap": gap,
                           "callees": " ".join(sorted({k[0] for k in kinds}))})
with open(OUT.replace(".csv", "_cache.csv"), "w", newline="") as f:
    w = csv.DictWriter(f, fieldnames=["address", "name", "old_type", "words", "gap", "callees"])
    w.writeheader(); w.writerows(cache_plan)
