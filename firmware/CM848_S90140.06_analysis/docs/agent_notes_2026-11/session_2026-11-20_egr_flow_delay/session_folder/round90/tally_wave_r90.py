"""Round 90 (read-only): pull the naming wave's result out of the workflow journal (one result line per agent) into
one JSON, and tally the verdicts. usage: tally_wave_r90.py <journal.jsonl> <out.json>"""
import collections
import json
import sys

journal, out = sys.argv[1], sys.argv[2]
investigations, verdicts = {}, {}
for line in open(journal):
    try:
        e = json.loads(line)
    except ValueError:
        continue
    if e.get("type") != "result":
        continue
    v = e.get("value") or e.get("result")
    if isinstance(v, dict) and "proposals" in v and isinstance(v["proposals"], list):
        investigations[v["batch"]] = v
    elif isinstance(v, dict) and "verdicts" in v:
        verdicts[v["batch"]] = v
results = [{"batch": b, "proposals": investigations[b], "verdicts": verdicts.get(b)} for b in sorted(investigations)]
json.dump({"results": results}, open(out, "w"), indent=1)
total = collections.Counter()
for r in results:
    ps = r["proposals"]["proposals"]
    vs = (r["verdicts"] or {}).get("verdicts", [])
    c = collections.Counter(v["verdict"] for v in vs)
    skips = sum(1 for p in ps if p.get("action") == "skip")
    total.update(c)
    total["skip"] += skips
    print(f"{r['batch']}: {len(ps)} candidates, {skips} skipped; verdicts {dict(c)}")
print("total:", dict(total))
