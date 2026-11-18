"""Wave 3 inputs: the retry bin for the still-unnamed tables, the duplicate-name list, the brief addendum."""
import csv
import json
import os
import sys
from collections import defaultdict

tmp, out = sys.argv[1], sys.argv[2]
prov = os.path.join(os.path.dirname(out), "docs/table_naming_campaign_2026-11-16.csv")
unnamed = {r["address"] for r in csv.DictReader(l for l in open(prov) if not l.startswith("#")) if r["status"] == "unnamed"}
lookups = json.load(open(os.path.join(tmp, "tables/lookups.json")))
retry = [lk for lk in lookups if any(t.get("address") in unnamed for t in lk["tables"])]
for lk in retry:
    lk["note"] = ("statement / current_name fields are from before the 2026-11-16 renames; the .cpp is current - "
                  "find the call there by the table addresses (WORD_ARRAY_<address>)")
json.dump({"bin": "retry", "functions": sorted({c["function"] for lk in retry for c in lk["calls"]}),
           "assigned_tables": sorted(unnamed), "lookups": retry},
          open(os.path.join(tmp, "tables/bin_retry.json"), "w"), indent=1)
names = defaultdict(list)
for line in open(os.path.join(out, "global_variables.csv")):
    p = line.rstrip("\n").split(",", 3)
    if p[0].startswith("0x") and len(p) > 1 and p[1]:
        names[p[1]].append((p[0], p[2] if len(p) > 2 else "", (p[3] if len(p) > 3 else "")[:160]))
fnames = defaultdict(list)
for line in open(os.path.join(out, "function_renames.csv")):
    p = line.rstrip("\n").split(",", 2)
    if p[0].startswith("0x") and len(p) > 1:
        fnames[p[1]].append((p[0], (p[2] if len(p) > 2 else "")[:160]))
dups = {"globals": {n: v for n, v in names.items() if len(v) > 1},
        "functions": {n: v for n, v in fnames.items() if len(v) > 1}}
json.dump(dups, open(os.path.join(tmp, "renames/duplicates.json"), "w"), indent=1)
print(f"retry: {len(retry)} lookups, {len(unnamed)} tables; duplicates: {len(dups['globals'])} globals, "
      f"{len(dups['functions'])} functions")
