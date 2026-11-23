"""List every function that differs after prove_caches.py's canonicalization (it prints only 12).
usage: list_differing.py <old_stripped.cpp> <new_stripped.cpp> <map_globals.csv>"""
import csv
import re
import sys


def bodies(t):
    parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
    return {parts[i]: re.sub(r"\s+", "", re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S))
            for i in range(1, len(parts), 2)}


old_b = bodies(open(sys.argv[1], errors="replace").read())
new_b = bodies(open(sys.argv[2], errors="replace").read())
rows = list(csv.DictReader(open(sys.argv[3])))
for f in sorted(old_b):
    ob = old_b[f]
    for r in rows:
        ob = re.sub(rf"(?<![\w.]){re.escape(r['old_label'])}\b", r["name"], ob)
    if ob != new_b.get(f):
        print(f)
