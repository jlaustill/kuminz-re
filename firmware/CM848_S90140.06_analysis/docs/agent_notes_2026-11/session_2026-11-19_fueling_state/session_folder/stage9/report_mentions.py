"""Add the global rows the wave-13 reports name by address (their 'out-of-bin sibling' leads) to the wave-14 global
worklist: every quoted address (or address range start) that has a named global_variables.csv row, was not reviewed or
renamed in wave 13 / 8c, is not excluded, and is used in the .cpp.
usage: report_mentions.py <global_variables.csv> <.cpp> <audit.csv> <stage8 dir> <selected.json> <out.json>
       [exclude addresses...]"""
import csv
import glob
import json
import os
import re
import sys

gv_path, cpp_path, audit_path, stage8, selected_path, out_path = sys.argv[1:7]
exclude = {int(a, 16) for a in sys.argv[7:]}
rows = {}
for line in open(gv_path, errors="replace"):
    if line.startswith("0x"):
        address, name, typ = (line.rstrip("\n").split(",", 3) + ["", ""])[:3]
        if name and "+" not in name:
            rows[int(address, 16)] = (name, typ)
reviewed = {int(i["address"], 16) for p in glob.glob(os.path.join(stage8, "bins", "bin*.json")) for i in json.load(open(p))}
renamed = {int(r["address"], 16) for n in ("map_stage8.csv", "map_stage8c.csv", "map_stage8b.csv")
           for r in csv.DictReader(open(os.path.join(stage8, n)))}
selected = json.load(open(selected_path))
have = {int(r["address"], 16) for r in selected}
audit = {}
for r in csv.DictReader(open(audit_path)):
    audit.setdefault(int(r["address"], 16), r)
cpp = open(cpp_path, errors="replace").read()
added = []
for report in sorted(glob.glob(os.path.join(stage8, "reports", "*.md"))):
    for m in re.finditer(r"0x([0-9a-fA-F]{5,8})", open(report).read()):
        a = int(m.group(1), 16)
        if a in rows and a not in reviewed and a not in renamed and a not in have and a not in exclude:
            name = rows[a][0]
            if re.search(rf"(?<![A-Za-z0-9_]){re.escape(name)}(?![A-Za-z0-9_])", cpp):
                have.add(a)
                r = dict(audit.get(a, {}))
                r.update({"address": f"0x{a:08x}", "row_name": name, "row_type": rows[a][1],
                          "mentioned_in": os.path.basename(report)})
                added.append(r)
json.dump(selected + added, open(out_path, "w"), indent=1)
print(f"{len(added)} rows added from report mentions; {len(selected) + len(added)} in all")
print(" ".join(f"{r['address']}:{r['row_name']}" for r in added)[:3000])
