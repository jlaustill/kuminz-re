"""usage: gv.py REGEX [REGEX...] -- print global_variables.csv rows whose name (col 2) matches the regex or whose
address equals it (0x40a298 style). Rows are printed in full."""
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output"
pats = [re.compile(a) for a in sys.argv[1:]]
for line in open(OUT + "/global_variables.csv", errors="replace"):
    p = line.rstrip("\n").split(",", 3)
    if len(p) >= 2 and any(pat.search(p[1]) or pat.fullmatch(p[0]) for pat in pats):
        print(line.rstrip("\n"))
