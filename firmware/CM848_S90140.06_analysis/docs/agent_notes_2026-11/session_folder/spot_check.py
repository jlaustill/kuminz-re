"""Print n random named lookups: base, inputs, first / last breakpoints, values range."""
import csv
import json
import random
import sys

d, n = sys.argv[1], int(sys.argv[2])
lookups = {lk["id"]: lk for lk in json.load(open(f"{d}/lookups.json"))}
rows = list(csv.DictReader(open(f"{d}/proposed_main.csv")))
by_lookup = {}
for r in rows:
    for k in r["lookups"].split():
        by_lookup.setdefault(k, []).append(r["name"])
random.seed(16)
for k in random.sample(sorted(by_lookup), n):
    lk = lookups[k]
    c = lk["calls"][0]
    parts = []
    for t in lk["tables"]:
        ct = t.get("contents") or {}
        v = ct.get("breakpoints_signed") or ct.get("breakpoints_unsigned") or ct.get("values_signed") or \
            ct.get("values_unsigned") or ct.get("grid_min_max_signed")
        if v:
            parts.append(f"{t['role']}[{v[0]}..{v[-1]}]")
    print(f"{k} {sorted(by_lookup[k])[0]}\n    inputs {c['inputs']} in {c['function']}\n    {' '.join(parts)}")
