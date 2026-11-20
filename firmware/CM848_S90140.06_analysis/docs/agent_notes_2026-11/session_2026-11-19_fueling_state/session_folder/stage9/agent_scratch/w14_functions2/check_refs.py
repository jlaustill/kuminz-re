"""Lists identifiers cited in the W14 functions2 plates / evidence that exist nowhere in the repo CSVs or the .cpp."""
import glob
import json
import os
import re

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output"
RESULT = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions2.jsonl"

corpus = open(os.path.join(OUT, "cm848_rom.ghidra.cpp"), errors="replace").read()
for path in glob.glob(os.path.join(OUT, "*.csv")):
    corpus += "\n" + open(path, errors="replace").read()
known = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", corpus))
mine = set()
unknown = {}
for line in open(RESULT):
    record = json.loads(line)
    mine.add(record["new"])
    for field in ("evidence", "plate_comment"):
        for token in set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", record[field])):
            if token in known or token in mine:
                continue
            if "_" in token or re.match(r"(cm848|hpcr|mpc555)[A-Z_]", token):
                if token[0].isupper():
                    continue                       # e2m record names
                unknown.setdefault(token, set()).add(record["address"])
for token, where in sorted(unknown.items()):
    print(token, sorted(where))
print(f"{len(unknown)} unknown identifier-like tokens")
