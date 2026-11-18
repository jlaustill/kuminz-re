"""Keep only plan rows for tables not yet typed; report any size change for typed ones."""
import csv
import re
import sys

plan = list(csv.DictReader(open(sys.argv[1])))
typed = {}
for line in open(sys.argv[2]):
    p = line.rstrip("\n").split(",", 3)
    if p[0].startswith("0x") and len(p) > 2:
        m = re.fullmatch(r"word\[(\d+)\]", p[2])
        if m:
            typed[int(p[0], 16)] = int(m.group(1))
new, changed = [], []
for r in plan:
    a, n = int(r["address"], 16), int(r["count"])
    if a in typed:
        if typed[a] != n:
            changed.append((r["address"], r["name"], typed[a], n))
        continue
    new.append(r)
with open(sys.argv[3], "w", newline="") as f:
    w = csv.DictWriter(f, fieldnames=list(plan[0].keys()))
    w.writeheader(); w.writerows(new)
print("new tables:", len(new), " typed tables whose size would change:", changed)
