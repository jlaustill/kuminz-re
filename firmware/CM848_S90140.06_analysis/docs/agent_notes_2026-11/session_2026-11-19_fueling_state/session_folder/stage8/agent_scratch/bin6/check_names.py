import csv
import glob
import json
import os
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output"
RESULT_DIR = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8"

names = sys.argv[1:]
if not names:
    names = [json.loads(l)["new"] for l in open(f"{RESULT_DIR}/result_W13_bin6.jsonl") if l.strip() and json.loads(l)["verdict"] == "confirmed"]

# all CSVs in the output dir: scan every token
tokens = {}
for path in glob.glob(os.path.join(OUT, "*.csv")):
    text = open(path, errors="replace").read()
    for n in names:
        if re.search(r"(?<![A-Za-z0-9_])" + re.escape(n) + r"(?![A-Za-z0-9_])", text):
            tokens.setdefault(n, []).append(os.path.basename(path))
cpp = open(os.path.join(OUT, "cm848_rom.ghidra.cpp"), errors="replace").read()
for n in names:
    if re.search(r"(?<![A-Za-z0-9_])" + re.escape(n) + r"(?![A-Za-z0-9_])", cpp):
        tokens.setdefault(n, []).append("cm848_rom.ghidra.cpp")
hpp = glob.glob(os.path.join(OUT, "*.hpp"))
for path in hpp:
    text = open(path, errors="replace").read()
    for n in names:
        if re.search(r"(?<![A-Za-z0-9_])" + re.escape(n) + r"(?![A-Za-z0-9_])", text):
            tokens.setdefault(n, []).append(os.path.basename(path))

# other agents' results (read only)
others = {}
for path in glob.glob(f"{RESULT_DIR}/result_W13_bin*.jsonl"):
    if path.endswith("bin6.jsonl"):
        continue
    for l in open(path):
        if not l.strip():
            continue
        try:
            r = json.loads(l)
        except Exception:
            continue
        if r.get("verdict") == "confirmed":
            others.setdefault(r["new"], []).append(os.path.basename(path) + ":" + r["address"])

dups = {}
for n in names:
    dups[n] = dups.get(n, 0) + 1
print("names checked:", len(names))
bad = False
for n in names:
    if n in tokens:
        print("EXISTS:", n, tokens[n])
        bad = True
    if n in others:
        print("OTHER AGENT USES:", n, others[n])
        bad = True
    if dups[n] > 1:
        print("DUPLICATE IN BIN:", n)
        bad = True
print("OK" if not bad else "PROBLEMS")
