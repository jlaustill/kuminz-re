"""Round 44 stage B check: every renamed row keeps its '(was <old>' note after refresh_references.py, and list the other
rows whose comments now carry a stage B name (the refreshed references).  usage: check_history_r44b.py <repo> <map.csv>"""
import csv
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
m = list(csv.DictReader(open(map_path)))
lines = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")).read().split("\n")
g = {l[:10]: l for l in lines if l.startswith("0x")}
renamed = {r["address"] for r in m}
for r in m:
    print(("ok  " if f"(was {r['old_label']}" in g[r["address"]] else "LOST"), r["address"], r["name"])
news = {r["name"] for r in m}
for a, l in g.items():
    if a in renamed:
        continue
    comment = l.split(",", 3)[-1]
    hits = sorted(n for n in news if n in comment)
    if hits:
        print("refreshed:", a, l.split(",")[1], hits)
