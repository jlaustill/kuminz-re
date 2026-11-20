"""Which other W14 result files mention one of my new names (as a token)?"""
import glob
import json
import re

STAGE9 = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9"
mine = f"{STAGE9}/result_W14_functions3.jsonl"
names = set()
for line in open(mine):
    r = json.loads(line)
    names.add(r["new"])
    if r["kind"] == "enum":
        names.add(r["enum_new"])
        names |= {m["new"] for m in r["members"] if m["new"]}
token = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
found = False
for path in sorted(glob.glob(f"{STAGE9}/result_W14_*.jsonl")):
    if path == mine:
        continue
    text = open(path, errors="replace").read()
    hits = sorted(names & set(token.findall(text)))
    if hits:
        found = True
        print(path.split("/")[-1], hits)
print("checked", len(names), "names;", "mentions found" if found else "no mention in any other W14 result file")
# and the reverse: names the other files propose that equal one of my old names or row names
others = set()
for path in sorted(glob.glob(f"{STAGE9}/result_W14_*.jsonl")):
    if path == mine:
        continue
    for line in open(path):
        line = line.strip()
        if not line:
            continue
        try:
            r = json.loads(line)
        except ValueError:
            continue
        if r.get("new"):
            others.add(r["new"])
        for s in r.get("split", []) or []:
            if s.get("name"):
                others.add(s["name"])
print("collisions on new names / split names:", sorted(names & others) or "none")
