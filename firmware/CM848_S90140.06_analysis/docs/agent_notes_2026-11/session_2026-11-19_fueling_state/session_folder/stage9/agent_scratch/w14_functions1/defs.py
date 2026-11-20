"""defs.py: show function_definitions.csv / local_variables.csv rows for the functions1 addresses."""
import json

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"
BINS = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/"
addrs = {int(x["address"], 16): x["current"] for x in json.load(open(BINS + "functions1.json"))["functions"]}
for name in ("function_definitions.csv", "local_variables.csv", "call_fixups.csv", "labels.csv", "constants.csv", "arrays.csv"):
    print("=====", name)
    for line in open(OUT + name):
        p = line.rstrip("\n").split(",", 2)
        if p[0].startswith("0x"):
            try:
                a = int(p[0], 16)
            except ValueError:
                continue
            if a in addrs or (len(p) > 1 and p[1] in addrs.values()):
                print(line.rstrip("\n")[:300])
