"""xmatch.py: which of the functions1 current names (with or without the cm848_ prefix) appear in cross_firmware_matches.csv
or in CM550's function_renames.csv."""
import json
import re

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/"
BINS = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/"
items = json.load(open(BINS + "functions1.json"))["functions"]
cross = open(FW + "cross_firmware_matches.csv").read().split("\n")
cm550 = open(FW + "CM550_J90350.00_analysis/output/function_renames.csv").read().split("\n")
for x in items:
    cur = x["current"]
    bare = re.sub(r"^(cm848|hpcr|mpc555)_", "", cur)
    hits = [l for l in cross if re.search(r"(^|,)(" + re.escape(cur) + "|" + re.escape(bare) + r")(,|$)", l)]
    hits550 = [l for l in cm550 if re.search(r"(^|,)(" + re.escape(cur) + "|" + re.escape(bare) + r")(,|$)", l)]
    if hits or hits550:
        print(cur, "| cross:", hits, "| cm550:", [h[:100] for h in hits550])
