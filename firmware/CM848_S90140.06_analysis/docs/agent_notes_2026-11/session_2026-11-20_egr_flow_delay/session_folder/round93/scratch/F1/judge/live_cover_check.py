"""Judge F1: is any of the 43 proposed addresses (or a byte of its proposed width) inside another row of the LIVE CM550
global_variables.csv (arrays and structs sized from the live structure_definitions.csv)? Also: a live row inside the
proposed width, and the live row's own name / type."""
import csv
import json
import re

R = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93"
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output"
d = json.load(open(f"{R}/scratch/F1/judge/verdicts_f1.json"))
PRIM = {"byte": 1, "sbyte": 1, "char": 1, "uchar": 1, "bool": 1, "undefined": 1, "undefined1": 1, "word": 2, "short": 2,
        "ushort": 2, "i16": 2, "u16": 2, "undefined2": 2, "dword": 4, "int": 4, "uint": 4, "long": 4, "ulong": 4, "i32": 4,
        "u32": 4, "pointer": 4, "undefined4": 4}
structs = {}
for row in csv.reader(open(f"{OUT}/structure_definitions.csv", newline="")):
    if row and not row[0].startswith("#") and len(row) > 4 and row[0] != "struct_name":
        try:
            structs.setdefault(row[0], 0)
            if not row[3].startswith("bitfield"):
                structs[row[0]] += int(row[4])
        except ValueError:
            pass
enums = {}
for row in csv.reader(open(f"{OUT}/enums.csv", newline="")):
    if row and not row[0].startswith("#") and len(row) > 4 and row[0] != "enum_name":
        try:
            enums[row[0]] = int(row[4])
        except ValueError:
            pass
# bitfield structs: size = the size column of their first field (the storage unit)
for row in csv.reader(open(f"{OUT}/structure_definitions.csv", newline="")):
    if row and not row[0].startswith("#") and len(row) > 4 and row[3].startswith("bitfield") and structs.get(row[0]) == 0:
        try:
            structs[row[0]] = int(row[4]) or 2
        except ValueError:
            structs[row[0]] = 2


def size_of(t):
    m = re.match(r"^([A-Za-z0-9_]+)\s*(\*)?\s*(?:\[(\d+)\])?$", t.strip())
    if not m:
        return None
    base, ptr, n = m.group(1), m.group(2), int(m.group(3) or 1)
    if ptr:
        return 4 * n
    s = PRIM.get(base) or structs.get(base) or enums.get(base)
    return s * n if s else None


rows = []
for line in open(f"{OUT}/global_variables.csv", newline=""):
    p = line.rstrip("\r\n").split(",", 3)
    if p[0].startswith("0x") and len(p) > 2:
        rows.append((int(p[0], 16), p[1], p[2]))
rows.sort()
by = {r[0]: r for r in rows}
unknown = set()
problems = 0
for v in d:
    if v["kind"] != "global":
        continue
    a = int(v["address"], 16)
    w = size_of(v["final_type"]) or 1
    own = by.get(a)
    print(f"0x{a:x} -> {v['final_name']} : {v['final_type']} ({w} bytes); live row: {own[1] + ' ' + own[2] if own else 'NONE'}")
    for r in rows:
        if r[0] >= a + w:
            break
        if r[0] == a:
            continue
        if a < r[0] < a + w:
            print(f"   !! live row inside the width: 0x{r[0]:x} {r[1]} {r[2]}")
            problems += 1
            continue
        if not r[2]:
            continue
        s = size_of(r[2])
        if s is None:
            if a - r[0] < 0x400:
                unknown.add((r[2], hex(r[0])))
            continue
        if r[0] < a < r[0] + s:
            print(f"   !! covered by the live row 0x{r[0]:x} {r[1]} {r[2]} ({s} bytes)")
            problems += 1
print("problems:", problems)
print("types of unknown size within 0x400 before a proposed address:", sorted(unknown))
