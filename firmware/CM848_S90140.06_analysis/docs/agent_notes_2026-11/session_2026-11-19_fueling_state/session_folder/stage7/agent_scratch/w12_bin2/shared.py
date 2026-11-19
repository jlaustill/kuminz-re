import json

BASE = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/bins/"
for k in range(1, 7):
    d = json.load(open(f"{BASE}bin{k}.json"))
    blocks = sorted({r['block'] for r in d})
    print(k, len(d), blocks)
mine = {r['address']: r for r in json.load(open(BASE + "bin2.json"))}
for k in range(1, 7):
    if k == 2:
        continue
    for r in json.load(open(f"{BASE}bin{k}.json")):
        if r['address'] in mine:
            print("shared address:", r['address'], "bin", k, r['block'], r['offset'], r['record'], "<->",
                  mine[r['address']]['block'], mine[r['address']]['record'])
