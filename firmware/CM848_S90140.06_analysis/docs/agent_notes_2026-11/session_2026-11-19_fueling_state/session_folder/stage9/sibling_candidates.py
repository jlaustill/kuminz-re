"""Wave 14 sibling worklist: named rows of the e2m blocks that waves 13 / 8c renamed into, whose name still shares little
with their record (token overlap < 0.34), and that wave 13 did not review. Prints counts and writes sibling_rows.json.
usage: sibling_candidates.py <audit.csv> <stage8 dir> <out.json> [exclude addresses...]"""
import csv
import glob
import json
import os
import sys

audit_path, stage8, out_path = sys.argv[1:4]
exclude = {int(a, 16) for a in sys.argv[4:]}
audit = list(csv.DictReader(open(audit_path)))
renamed = set()
for name in ("map_stage8.csv", "map_stage8c.csv"):
    for r in csv.DictReader(open(os.path.join(stage8, name))):
        renamed.add(int(r["address"], 16))
reviewed = set()
for path in glob.glob(os.path.join(stage8, "bins", "bin*.json")):
    for item in json.load(open(path)):
        reviewed.add(int(item["address"], 16))
blocks = {r["block"] for r in audit if int(r["address"], 16) in renamed}
rows = []
for r in audit:
    a = int(r["address"], 16)
    if r["block"] in blocks and r["status"] == "named" and float(r["token_overlap"] or 0) < 0.34 \
            and a not in reviewed and a not in renamed and a not in exclude:
        rows.append(r)
seen, unique = set(), []
for r in rows:
    if r["address"] not in seen:
        seen.add(r["address"])
        unique.append(r)
used = [r for r in unique if int(r["references"] or 0) >= 1]
print(f"{len(blocks)} blocks; {len(unique)} candidate rows, {len(used)} with code references")
json.dump(used, open(out_path, "w"), indent=1)
by_block = {}
for r in used:
    by_block[r["block"]] = by_block.get(r["block"], 0) + 1
print(sorted(by_block.items(), key=lambda kv: -kv[1])[:30])
