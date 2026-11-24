"""Summarize the wave 2 workflow result: verdict counts, the parameter rows to apply, every amend / reject with its
problems, and the investigators' skips. usage: wave2_summary.py <workflow output file>"""
import collections
import json
import sys

data = json.load(open(sys.argv[1]))["result"]
counts = collections.Counter()
rows = 0
skipped = []
for group in data:
    proposals = {f["address"]: f for f in group["proposal"]["functions"]}
    for v in group["verdicts"]["verdicts"]:
        counts[v["verdict"]] += 1
        rows += sum(1 for r in v["rows"] if r["param_index"] != "return")
        if v["verdict"] != "accept":
            name = proposals.get(v["address"], {}).get("name", "?")
            print(f"{v['verdict']:6} {v['address']} {name}: " + " | ".join(v["problems"])[:330])
    for address, f in proposals.items():
        if f["action"] == "skip":
            skipped.append((address, f["name"], f.get("skip_reason", "")[:160]))
print(dict(counts), "parameter rows:", rows)
print("investigator skips:", len(skipped))
for s in skipped:
    print("  ", *s)
