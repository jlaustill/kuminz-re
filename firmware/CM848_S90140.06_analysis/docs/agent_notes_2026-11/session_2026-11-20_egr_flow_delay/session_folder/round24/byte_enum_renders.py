"""Do applied size-1 enums render? For each enum of size 1 that a global_variables.csv row uses as its type, count
its member names in the .cpp. usage: byte_enum_renders.py <output dir>"""
import csv
import os
import re
import sys

out = sys.argv[1]
enums = {}
for r in csv.reader(open(os.path.join(out, "enums.csv"))):
    if r and not r[0].startswith("#") and len(r) >= 5 and r[0] != "enum_name":
        enums.setdefault(r[0], {"size": r[4], "members": []})["members"].append(r[2])
used = {}
for line in open(os.path.join(out, "global_variables.csv")):
    if line.startswith("0x"):
        a, n, t = line.split(",", 3)[:3]
        if t in enums:
            used.setdefault(t, []).append(n)
for line in open(os.path.join(out, "structure_definitions.csv")):
    r = next(csv.reader([line]))
    if len(r) > 3 and r[3] in enums:
        used.setdefault(r[3], []).append(r[0] + "." + r[2])
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()
for e, v in sorted(enums.items()):
    if v["size"] == "1":
        hits = sum(len(re.findall(r"\b" + re.escape(m) + r"\b", cpp)) for m in v["members"])
        print(f"{e}: size 1, applied to {used.get(e, [])[:3]}, member renders {hits}")
