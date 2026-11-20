import glob
import json
import os
import re

repo = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum"
shared_text = ""
files = glob.glob(os.path.join(repo, "firmware", "CM550_J90350.00_analysis", "output", "*.csv")) + [
    os.path.join(repo, "firmware", "cross_firmware_matches.csv"),
    os.path.join(repo, "docs", "cross_firmware_variable_map.csv")]
for f in files:
    if os.path.exists(f):
        shared_text += open(f, errors="replace").read()
rows = [json.loads(l) for l in open("/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin6.jsonl")]
for r in rows:
    if r["verdict"] == "confirmed":
        if re.search(r"(?<![A-Za-z0-9_])" + re.escape(r["old"]) + r"(?![A-Za-z0-9_])", shared_text):
            print("SHARED (would be held back):", r["address"], r["old"], "->", r["new"])
print("checked", sum(1 for r in rows if r["verdict"] == "confirmed"), "renames")
