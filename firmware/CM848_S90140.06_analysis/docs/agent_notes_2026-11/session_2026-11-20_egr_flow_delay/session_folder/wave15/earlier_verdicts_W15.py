"""Which wave 15 candidates already have a verdict from waves 13 / 14 (the PR #52 archive): drift / uncertain / held
results of the agents, and stage 9's kept / later worklists. Adds 'earlier_verdict' to each bin item it matches.
usage: earlier_verdicts_W15.py <archive session_folder> <bins dir>"""
import glob
import json
import os
import sys

folder, bins_dir = sys.argv[1:3]
earlier = {}
for path in sorted(glob.glob(os.path.join(folder, "stage7", "result_W12_*.jsonl")) +
                   glob.glob(os.path.join(folder, "stage8", "result_W13_*.jsonl")) +
                   glob.glob(os.path.join(folder, "stage9", "result_W14_*.jsonl"))):
    for line in open(path):
        line = line.strip()
        if not line.startswith("{"):
            continue
        try:
            r = json.loads(line)
        except json.JSONDecodeError:
            continue
        if r.get("kind") in ("global", "new_global") and r.get("address"):
            a = int(r["address"], 16)
            earlier.setdefault(a, []).append(f"{os.path.basename(path)}: {r.get('verdict')} "
                                             f"{r.get('new') or ''} - {(r.get('evidence') or r.get('e2m_note') or '')[:200]}")
for name in ("global_worklist_kept.json", "global_worklist_later.json"):
    path = os.path.join(folder, "stage9", name)
    if os.path.exists(path):
        data = json.load(open(path))
        items = data if isinstance(data, list) else data.get("items", data.get("rows", []))
        for it in items:
            if isinstance(it, dict) and it.get("address"):
                earlier.setdefault(int(it["address"], 16), []).append(f"{name}: {json.dumps(it)[:200]}")
hits = 0
for path in sorted(glob.glob(os.path.join(bins_dir, "bin*.json"))):
    items = json.load(open(path))
    for it in items:
        a = int(it["address"], 16)
        if a in earlier:
            it["earlier_verdict"] = earlier[a]
            hits += 1
    json.dump(items, open(path, "w"), indent=1)
print(f"earlier verdicts known for {len(earlier)} addresses; {hits} wave 15 candidates have one")
