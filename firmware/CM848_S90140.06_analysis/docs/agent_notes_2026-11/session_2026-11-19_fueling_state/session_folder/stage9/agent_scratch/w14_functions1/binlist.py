"""binlist.py: list the items of the other function bins and check overlap with functions1."""
import json

BINS = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/"
b1 = {x["address"] for x in json.load(open(BINS + "functions1.json"))["functions"]}
for n in ("functions2", "functions3"):
    d = json.load(open(BINS + n + ".json"))
    items = d["functions"]
    s = {x["address"] for x in items}
    print(n, len(items), "overlap with functions1:", b1 & s, "keys", list(d.keys()))
    for x in items:
        print("  ", x["address"], x["current"], "->", [p["name"] for p in x.get("proposals", [])][:2])
