"""Check that no new function / row / enum name occurs in CM550's CSVs or the cross-firmware map."""
import glob
import json
import re

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum"
RESULT = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions3.jsonl"
names = set()
for line in open(RESULT):
    r = json.loads(line)
    names.add(r["new"])
    if r["kind"] == "enum":
        names.add(r["enum_new"])
        names |= {m["new"] for m in r["members"] if m["new"]}
files = glob.glob(f"{REPO}/firmware/CM550_J90350.00_analysis/output/*") + [f"{REPO}/firmware/cross_firmware_matches.csv"]
token = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
hits = []
for path in files:
    try:
        text = open(path, errors="replace").read()
    except (IsADirectoryError, OSError):
        continue
    found = names & set(token.findall(text))
    for n in sorted(found):
        hits.append((path.replace(REPO + "/", ""), n))
print(f"{len(names)} names checked in {len(files)} files")
for h in hits:
    print("HIT", h)
if not hits:
    print("no collision with CM550 or the cross-firmware map")
