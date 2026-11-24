"""Round 90 (read-only): the committed CM550 parameter ID table's firmware_variable values that a regeneration
changes, by kind: renamed (the address has a current global under another name), dropped (no global covers the
address now), filled (empty before). For a dropped name: was it ever a global_variables.csv row (git log -S)?
usage: classify_table_names_r90.py <committed.csv> <regenerated.csv>"""
import collections
import csv
import sys

old = {r["param_id_hex"]: r for r in csv.DictReader(open(sys.argv[1], newline=""))}
new = {r["param_id_hex"]: r for r in csv.DictReader(open(sys.argv[2], newline=""))}
kinds = collections.defaultdict(list)
for k, o in old.items():
    a, b = o["firmware_variable"], new[k]["firmware_variable"]
    if a == b:
        continue
    kind = "filled" if not a else ("dropped" if not b else "renamed")
    kinds[kind].append((k, o["address_hex"], o["region"], a, b))
for kind, items in kinds.items():
    regions = collections.Counter(i[2] for i in items)
    print(f"{kind}: {len(items)} {dict(regions)}")
    for i in items[:6]:
        print("   ", i)
