"""Round 33: for each address, every CSV row whose span covers it (global_variables.csv rows incl. type-only ones,
arrays.csv rows, structure_definitions.csv instances), with struct sizes computed from the field rows.
usage: coverage_check.py <output dir> <address> [<address> ...]"""
import csv
import os
import re
import sys

out = sys.argv[1]
targets = [int(a, 16) for a in sys.argv[2:]]
BASIC = {"byte": 1, "char": 1, "bool": 1, "undefined1": 1, "uchar": 1, "i8": 1, "sbyte": 1,
         "word": 2, "i16": 2, "short": 2, "ushort": 2, "sword": 2, "undefined2": 2,
         "dword": 4, "i32": 4, "int": 4, "uint": 4, "pointer": 4, "float": 4, "undefined4": 4, "sdword": 4,
         "qword": 8, "double": 8, "undefined8": 8}
enum_sizes = {}
with open(os.path.join(out, "enums.csv"), newline="") as fh:
    for r in csv.reader(fh):
        if len(r) >= 5 and not r[0].startswith("#") and r[4].strip().isdigit():
            enum_sizes[r[0]] = int(r[4])
fields, instances = {}, {}
with open(os.path.join(out, "structure_definitions.csv"), newline="") as fh:
    for r in csv.reader(fh):
        if not r or r[0].startswith("#") or r[0] == "struct_name" or len(r) < 5:
            continue
        name, address, field, typ, size = r[0], r[1].strip(), r[2].strip(), r[3].strip(), r[4].strip()
        if address:
            instances.setdefault(name, set()).add(int(address, 16))
        if field and size.isdigit():
            fields.setdefault(name, []).append(int(size))


def size_of(typ):
    typ = typ.strip()
    m = re.match(r"^(.*)\[(\d+)\]$", typ)
    if m:
        s = size_of(m.group(1))
        return None if s is None else s * int(m.group(2))
    if typ.endswith("*"):
        return 4
    if typ in BASIC:
        return BASIC[typ]
    if typ in enum_sizes:
        return enum_sizes[typ]
    if typ in fields:
        return sum(fields[typ])
    return None


spans = []
with open(os.path.join(out, "global_variables.csv"), errors="replace") as fh:
    for line in fh:
        p = line.rstrip("\n").split(",", 3)
        if len(p) >= 3 and p[0].startswith("0x"):
            spans.append((int(p[0], 16), size_of(p[2]) or 1, "global", p[1] or "(type-only)", p[2]))
with open(os.path.join(out, "arrays.csv"), newline="", errors="replace") as fh:
    for r in csv.reader(fh):
        if len(r) >= 4 and r[0].startswith("0x") and r[3].strip().isdigit():
            spans.append((int(r[0], 16), (size_of(r[2]) or 1) * int(r[3]), "array", r[1], f"{r[2]}[{r[3]}]"))
for name, addresses in instances.items():
    s = size_of(name)
    for a in addresses:
        spans.append((a, s or 1, "struct", name, f"size {s}"))
for t in targets:
    hits = [f"{kind} {name} @0x{a:x} +{t - a} ({typ})" for a, s, kind, name, typ in spans if a <= t < a + s]
    print(f"0x{t:06x}: " + ("; ".join(hits) if hits else "free"))
