import glob
import json

base = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8"
mine = {}
for l in open(base + "/result_W13_bin6.jsonl"):
    if l.strip():
        r = json.loads(l)
        mine[r["address"].lower()] = r
news = {r["new"]: a for a, r in mine.items() if r["verdict"] == "confirmed"}
for path in sorted(glob.glob(base + "/result_W13_bin[1-5].jsonl")):
    for l in open(path):
        if not l.strip():
            continue
        r = json.loads(l)
        a = r.get("address", "").lower()
        if a in mine:
            print("SAME ADDRESS", path[-11:-6], a, r.get("verdict"), r.get("new"), "| mine", mine[a]["verdict"])
        if r.get("verdict") == "confirmed" and r.get("new") in news:
            print("SAME NEW NAME", path[-11:-6], r["new"])
        # olds that other agents reference in their text which I rename
print("checked; my confirmed:", len(news))
