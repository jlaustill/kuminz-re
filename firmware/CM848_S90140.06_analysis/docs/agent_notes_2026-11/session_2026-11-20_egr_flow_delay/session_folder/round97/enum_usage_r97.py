"""Round 97 (read-only): for each enum type of a firmware, how many CSV rows use it as a type (globals, prototypes,
struct fields, locals) and how many of its members render in the decompilation. usage: enum_usage_r97.py <repo> <cm550|cm848> [type ...]"""
import collections
import csv
import os
import re
import sys

repo, fw = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, {"cm550": "firmware/CM550_J90350.00_analysis/output", "cm848": "firmware/CM848_S90140.06_analysis/output"}[fw])
cpp = open(os.path.join(out, "J90350.00.ghidra.cpp" if fw == "cm550" else "cm848_rom.ghidra.cpp"), errors="replace").read()
members = collections.defaultdict(list)
for r in csv.reader(l for l in open(os.path.join(out, "enums.csv"), newline="") if not l.startswith("#")):
    if len(r) > 2 and r[0] and r[0] != "enum_name":
        members[r[0]].append(r[2])
types = collections.Counter()
for f, col in (("global_variables.csv", 2), ("function_definitions.csv", 4), ("structure_definitions.csv", 3), ("local_variables.csv", 4)):
    for line in open(os.path.join(out, f), newline=""):
        cells = line.rstrip("\r\n").split(",")
        if len(cells) > col:
            t = re.sub(r"[\s*\[\]0-9]+$", "", cells[col].strip())
            if t in members:
                types[t] += 1
wanted = sys.argv[3:] or sorted(members)
for t in wanted:
    if t not in members:
        continue
    renders = sum(len(re.findall(r"(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])" % re.escape(m), cpp)) for m in members[t])
    tr = len(re.findall(r"(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])" % re.escape(t), cpp))
    print(f"{t:40s} members {len(members[t]):3d}  type rows {types[t]:3d}  type renders {tr:4d}  member renders {renders:4d}")
