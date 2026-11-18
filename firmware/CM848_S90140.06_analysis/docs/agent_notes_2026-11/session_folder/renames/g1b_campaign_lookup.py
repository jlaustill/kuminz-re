import csv
import io
import re
import sys

path = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/docs/table_naming_campaign_2026-11-16.csv"
pattern = re.compile(sys.argv[1])
with open(path, newline="") as handle:
    lines = [line for line in handle if not line.startswith("#")]
reader = csv.DictReader(io.StringIO("".join(lines)))
for row in reader:
    if pattern.search(row["name"]) or pattern.search(row["address"]):
        print("=====", row["address"], row["name"], row["lookup"], row["bin"], row["confidence"])
        print("IN :", row["input"])
        print("OUT:", row["output"])
        print("EV :", row["evidence_or_reason"])
