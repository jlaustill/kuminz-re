"""Round 97: write stage D's type map as a plan CSV (firmware,file,owner,old,new,problem) for history_rewrites_r97.py.
usage: types_plan_r97d.py <map_r97d_types.csv> <out.csv>"""
import csv
import sys

rows = list(csv.DictReader(open(sys.argv[1])))
with open(sys.argv[2], "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["firmware", "file", "owner", "old", "new", "problem"])
    for r in rows:
        w.writerow(["both", "types", "", r["old_label"], r["name"], ""])
print(len(rows), "types")
