import glob
import json
import os

STAGE = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/"
mine = {}
for line in open(STAGE + "result_W13_bin4.jsonl"):
    d = json.loads(line)
    if d["verdict"] == "confirmed":
        mine[d["new"]] = d["address"]
for path in sorted(glob.glob(STAGE + "result_W13_bin*.jsonl")):
    if path.endswith("bin4.jsonl"):
        continue
    count = 0
    for line in open(path):
        line = line.strip()
        if not line:
            continue
        try:
            d = json.loads(line)
        except ValueError:
            continue
        count += 1
        new = d.get("new")
        if d.get("verdict") == "confirmed" and new in mine and d["address"] != mine[new]:
            print("COLLISION", os.path.basename(path), d["address"], new)
        # a keep or rename elsewhere whose OLD name equals one of my new names would also clash
        if d.get("old") in mine:
            print("OLD-CLASH", os.path.basename(path), d["address"], d.get("old"))
    print(os.path.basename(path), count, "lines")
print("checked", len(mine), "new names")
