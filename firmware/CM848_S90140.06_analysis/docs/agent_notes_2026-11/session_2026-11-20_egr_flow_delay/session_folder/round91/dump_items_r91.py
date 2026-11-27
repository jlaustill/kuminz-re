"""Round 91 (read-only): write each finished item's proposal and verdicts to <outdir>/item_<id>.json and print the
AMENDED / REFUTED verdicts. usage: dump_items_r91.py <journal.jsonl> <outdir>"""
import json
import os
import sys

journal, outdir = sys.argv[1], sys.argv[2]
props, verdicts = {}, {}
for line in open(journal):
    try:
        e = json.loads(line)
    except ValueError:
        continue
    if e.get("type") != "result":
        continue
    v = e.get("result") or e.get("value") or {}
    if isinstance(v, dict) and "summary" in v:
        props[v["item"]] = v
    elif isinstance(v, dict) and "verdicts" in v:
        verdicts[v["item"]] = v
for item in sorted(props):
    json.dump({"proposal": props[item], "verdict": verdicts.get(item)}, open(os.path.join(outdir, f"item_{item}.json"), "w"),
              indent=1)
    for x in (verdicts.get(item) or {}).get("verdicts", []):
        if x["verdict"] != "CONFIRMED":
            print(f"{item} {x['verdict']} {x['element']}: {x.get('amendment', '')[:400]} || {x.get('reason', '')[:300]}")
print("items:", sorted(props), "verified:", sorted(verdicts))
