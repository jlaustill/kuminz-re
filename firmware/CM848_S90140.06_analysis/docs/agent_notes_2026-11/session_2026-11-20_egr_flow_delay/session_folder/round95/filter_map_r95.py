"""Round 95: drop the CM550 refresh map rows whose old label is still a live CM848 function or global name (CM848
keeps that name - a counterpart, not a twin - so the refresh's cross-firmware step must not rewrite CM848 text).
usage: filter_map_r95.py <repo> <cm550 map in> <cm550 map out>"""
import csv
import os
import sys

repo = os.path.abspath(sys.argv[1])
live = set()
for name in ("function_renames.csv", "global_variables.csv"):
    for line in open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output", name), newline=""):
        p = line.rstrip("\r\n").split(",", 2)
        if len(p) > 1 and p[0].startswith("0x") and p[1]:
            live.add(p[1])
rows = list(csv.DictReader(open(sys.argv[2])))
kept = [r for r in rows if r["old_label"] not in live]
for r in rows:
    if r["old_label"] in live:
        print("dropped", r["address"], r["old_label"], "->", r["name"])
with open(sys.argv[3], "w", newline="") as f:
    w = csv.DictWriter(f, fieldnames=rows[0].keys())
    w.writeheader()
    w.writerows(kept)
print(len(rows), "->", len(kept))
