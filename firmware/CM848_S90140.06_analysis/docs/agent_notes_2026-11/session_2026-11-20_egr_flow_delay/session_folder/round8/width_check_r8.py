"""Round 8 width check (firmware/CLAUDE.md stage 8c rule): for each e2m record of an offset-aligned block, compare the
record's size (e2m column 8, bytes) with the width the CSVs declare at base + offset (a global row, an array's element,
or a struct field). Prints the mismatches and the records with no row.
usage: width_check_r8.py <repo> <block>:<base>:<lo>:<hi>..."""
import csv
import os
import re
import sys

repo, *specs = sys.argv[1:]
repo = os.path.abspath(repo)
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
E2M = os.path.join(repo, "e2m-analysis", "CHR", "CHR_CC_11.45.01.07.e2m")
WIDTH = {"byte": 1, "bool": 1, "char": 1, "i8": 1, "u8": 1, "undefined1": 1, "word": 2, "i16": 2, "short": 2,
         "ushort": 2, "sword": 2, "undefined2": 2, "dword": 4, "i32": 4, "int": 4, "uint": 4, "undefined4": 4,
         "int32_t": 4, "float": 4, "pointer": 4}

# struct field sizes, by struct name, in order
fields, struct_at = {}, {}
for row in csv.reader(l for l in open(os.path.join(out, "structure_definitions.csv")) if not l.startswith("#")):
    if len(row) < 5 or row[0] == "struct_name":
        continue
    name, addr, field, typ, size = row[:5]
    if field:
        fields.setdefault(name, []).append((field, typ, int(size or 0)))
    if addr:
        struct_at.setdefault(int(addr, 16), name)


def struct_size(name):
    return sum(s for _, _, s in fields.get(name, []))


def field_width(name, off):
    o = 0
    for field, typ, size in fields.get(name, []):
        if size == 0:
            continue
        if o == off:
            if typ in fields:  # nested struct: its first field
                return field_width(typ, 0), f"{name}.{field}"
            m = re.match(r"^(\w+)\[(\d+)\]$", typ)
            if m:
                return WIDTH.get(m.group(1), size // int(m.group(2))), f"{name}.{field}[0]"
            return WIDTH.get(typ, size), f"{name}.{field}"
        if o < off < o + size:
            m = re.match(r"^(\w+)\[(\d+)\]$", typ)
            if m:
                w = WIDTH.get(m.group(1), 0)
                if w and (off - o) % w == 0:
                    return w, f"{name}.{field}[{(off - o) // w}]"
            return None, f"inside {name}.{field}"
        o += size
    return None, f"past {name}"


rows = {}
for line in open(os.path.join(out, "global_variables.csv")):
    if re.match(r"^0x[0-9a-f]{8},", line):
        a, n, t = (line.split(",", 3) + ["", ""])[:3]
        rows.setdefault(int(a, 16), (n, t))


def declared(addr):
    if addr in rows and rows[addr][1]:
        n, t = rows[addr]
        m = re.match(r"^(\w+)(?: \*)?\[(\d+)\]$", t)
        if m:
            base = m.group(1)
            return (WIDTH.get(base) or field_width(base, 0)[0]), f"{n} ({t})"
        if t in fields:
            w, f = field_width(t, 0)
            return w, f"{n} ({t}: {f})"
        return WIDTH.get(t), f"{n} ({t})"
    for a0 in sorted(struct_at, reverse=True):  # a struct instance covering the address
        if a0 <= addr < a0 + struct_size(struct_at[a0]):
            return field_width(struct_at[a0], addr - a0)
    for a0 in sorted(rows, reverse=True):  # an array row covering the address
        if a0 < addr:
            n, t = rows[a0]
            m = re.match(r"^(\w+)\[(\d+)\]$", t)
            if m and WIDTH.get(m.group(1)) and addr < a0 + WIDTH[m.group(1)] * int(m.group(2)):
                return WIDTH[m.group(1)], f"{n}[{(addr - a0) // WIDTH[m.group(1)]}]"
            break
    return None, "no row"


records = [l.split(";")[0].split(",") for l in open(E2M, errors="replace") if l.count(",") > 10]
for spec in specs:
    block, base, lo, hi = spec.split(":")
    base, lo, hi = int(base, 16), int(lo, 16), int(hi, 16)
    mism = 0
    checked = 0
    for r in sorted((r for r in records if r[2] == block), key=lambda r: int(r[3], 16)):
        off = int(r[3], 16)
        if not lo <= off <= hi:
            continue
        size = int(r[7])
        w, what = declared(base + off)
        checked += 1
        if w != size:
            mism += 1
            print(f"{block} +{off:02X} {hex(base + off)} {r[0]} e2m size {size} vs CSV {w}: {what}")
    print(f"== {block}: {checked} records checked, {mism} mismatches")
