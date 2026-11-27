"""Rows that a proposed N2 global would split: a frozen row starting before the global whose type runs into it, or a
row starting inside it whose type runs past its end. usage: python3 overlap_check.py"""
import csv
import json
import re

J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge/"
F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/"
BASE = {"byte": 1, "bool": 1, "undefined": 1, "char": 1, "word": 2, "i16": 2, "short": 2, "ushort": 2, "dword": 4,
        "i32": 4, "int": 4, "uint": 4, "pointer": 4, "float": 4, "i8": 1}
struct_size = {}
for r in csv.reader(open(F + "structure_definitions.csv")):
    if r and not r[0].startswith("#") and len(r) > 4 and r[0] != "struct_name":
        try:
            struct_size[r[0]] = struct_size.get(r[0], 0) + int(r[4])
        except ValueError:
            pass


def size_of(t):
    t = t.strip()
    m = re.match(r"(.+?)\s*\[(\d+)\]$", t)
    if m:
        s = size_of(m.group(1))
        return None if s is None else s * int(m.group(2))
    if t.endswith("*"):
        return 4
    if t in BASE:
        return BASE[t]
    return struct_size.get(t)


rows = []
for r in csv.reader(open(F + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        rows.append((int(r[0], 16), r[1], r[2]))
props = json.load(open(J + "proposals_globals.json"))
for e in props:
    a = int(e["address"], 16)
    t = e["proposed_type"]
    n = 14 if t == "table_lookup_1d_arguments_t" else 2 * int(re.match(r"word\[(\d+)\]", t).group(1))
    for ra, nm, rt in rows:
        s = size_of(rt) or 1
        if ra < a < ra + s:
            print(f"SPLIT (row before): {e['address']} {e['proposed_name']} <- {hex(ra)} {nm} {rt} size {s}")
        if a <= ra < a + n and ra + s > a + n:
            print(f"SPLIT (row past the end): {e['address']} {e['proposed_name']} <- {hex(ra)} {nm} {rt} size {s}")
print("done")
