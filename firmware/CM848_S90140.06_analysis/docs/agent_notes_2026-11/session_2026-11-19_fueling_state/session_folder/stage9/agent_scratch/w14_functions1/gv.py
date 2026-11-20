"""gv.py: look up rows of global_variables.csv by address (0x...) or by name regex.
usage: gv.py [-n MAXCOMMENT] <addr-or-regex> ...   (addresses are matched as the integer value)"""
import csv
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"
args = sys.argv[1:]
maxc = 400
if args and args[0] == "-n":
    maxc = int(args[1])
    args = args[2:]
rows = [r + [""] * (4 - len(r)) for r in csv.reader(open(OUT + "global_variables.csv")) if r][1:]
for a in args:
    if re.fullmatch(r"0x[0-9a-fA-F]+", a):
        v = int(a, 16)
        hits = [r for r in rows if re.fullmatch(r"0x[0-9a-fA-F]+", r[0]) and int(r[0], 16) == v]
    else:
        rx = re.compile(a)
        hits = [r for r in rows if rx.search(r[1]) or rx.search(r[0])]
    print(f"### {a}: {len(hits)} row(s)")
    for r in hits:
        print(f"{r[0]} {r[1]} [{r[2]}] :: {r[3][:maxc]}")
