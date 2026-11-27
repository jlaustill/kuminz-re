"""Round 94 (read-only): a batch's verdict counts, every non-CONFIRMED verdict (with its reason) and the judge's
overall text. usage: show_verdicts_r94.py <batch_X.json> [reason chars] [overall chars]"""
import collections
import json
import sys

d = json.load(open(sys.argv[1]))
rc = int(sys.argv[2]) if len(sys.argv) > 2 else 260
oc = int(sys.argv[3]) if len(sys.argv) > 3 else 4000
v = (d.get("verdict") or {}).get("verdicts") or []
p = d["proposal"]
print(d.get("batch"), "proposal:", {k: len(p.get(k) or []) for k in ("functions", "cm848_functions", "globals", "enum_members", "skipped")},
      "verdicts:", dict(collections.Counter(x["verdict"] for x in v)))
for x in v:
    if x["verdict"] != "CONFIRMED":
        print(f"  {x['verdict']} {x['kind']} {x.get('firmware', '')} {x['address']} -> {x.get('final_name')} {x.get('final_type') or ''} | {x['reason'][:rc]}")
print("OVERALL:", ((d.get("verdict") or {}).get("overall") or "")[:oc])
