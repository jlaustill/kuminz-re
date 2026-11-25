"""List the frozen CM550 global rows inside each 14-byte record [rec, rec+14) (and rows that start before and run into
it by their type size).  usage: rows_inside.py <record hex> ..."""
import csv
import re
import sys

FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/"
SIZES = {"byte": 1, "char": 1, "bool": 1, "undefined": 1, "undefined1": 1, "word": 2, "i16": 2, "short": 2,
         "ushort": 2, "undefined2": 2, "dword": 4, "i32": 4, "pointer": 4, "undefined4": 4, "uint": 4, "int": 4,
         "float": 4, "": 1}
structs = {}
for line in open(FROZEN + "structure_definitions.csv"):
    p = next(csv.reader([line])) if line.strip() and not line.startswith("#") else None
    if p and len(p) > 4 and p[0] != "struct_name":
        try:
            structs[p[0]] = structs.get(p[0], 0) + int(p[4])
        except ValueError:
            pass
rows = []
for line in open(FROZEN + "global_variables.csv"):
    if line.startswith("0x"):
        p = next(csv.reader([line]))
        rows.append((int(p[0], 16), p[1], p[2] if len(p) > 2 else "", p[3] if len(p) > 3 else ""))


def size_of(t):
    m = re.match(r"(\w+)\[(\d+)\]$", t)
    if m:
        return size_of(m.group(1)) * int(m.group(2))
    if t.endswith("*"):
        return 4
    if t in SIZES:
        return SIZES[t]
    if t in structs:
        return structs[t]
    return 2


length = 14
args = sys.argv[1:]
if args and args[0] == "-n":
    length = int(args[1])
    args = args[2:]
for a in args:
    rec = int(a, 16)
    print("== 0x%x" % rec)
    for r in rows:
        s = size_of(r[2])
        if rec <= r[0] < rec + length or (r[0] < rec < r[0] + s):
            print("   0x%x (+%d) %s [%s size %d] %s" % (r[0], r[0] - rec, r[1], r[2], s, r[3][:140]))
