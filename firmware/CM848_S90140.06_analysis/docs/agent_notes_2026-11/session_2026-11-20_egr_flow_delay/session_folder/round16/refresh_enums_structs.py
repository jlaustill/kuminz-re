"""Refresh old names in enums.csv and structure_definitions.csv comments (refresh_references.py skips both files):
each old label of the map becomes its new name, except inside '(was <old>)' notes. Prints the changed lines.
usage: refresh_enums_structs.py <repo> <map.csv>"""
import csv
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
pairs = []
for row in csv.reader(open(map_path)):
    if len(row) >= 3 and row[1] and row[2] and row[2] != "old_label":
        pairs.append((row[2], row[1]))
pairs.sort(key=lambda p: -len(p[0]))
for name in ("enums.csv", "structure_definitions.csv"):
    p = os.path.join(out, name)
    lines = open(p).read().split("\n")
    changed = 0
    for i, line in enumerate(lines):
        new = line
        for old, repl in pairs:
            new = re.sub(rf"(?<!was )(?<![A-Za-z0-9_]){re.escape(old)}(?![A-Za-z0-9_])", repl, new)
        if new != line:
            changed += 1
            print(f"{name}:{i + 1}: {new[:220]}")
            lines[i] = new
    open(p, "w").write("\n".join(lines))
    print(f"{name}: {changed} lines refreshed")
