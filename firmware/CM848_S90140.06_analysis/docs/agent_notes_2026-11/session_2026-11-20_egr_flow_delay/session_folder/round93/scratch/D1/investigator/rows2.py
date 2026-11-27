"""Print the FROZEN and the LIVE (repository working tree) CM550 global_variables.csv rows for given addresses, and
flag a difference (read-only helper, round 93 batch D1 investigator, session 2).
usage: rows2.py [--cm848] 0xADDR ..."""
import csv
import sys

args = sys.argv[1:]
fw = "cm550"
if args and args[0] == "--cm848":
    fw = "cm848"
    args = args[1:]
FROZEN = f"/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/{fw}/global_variables.csv"
LIVE = {
    "cm550": "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output/global_variables.csv",
    "cm848": "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/global_variables.csv",
}[fw]


def load(path):
    rows = {}
    for row in csv.reader(open(path, errors="replace")):
        if row and row[0].lower().startswith("0x"):
            try:
                rows.setdefault(int(row[0], 16), []).append(row)
            except ValueError:
                pass
    return rows


frozen = load(FROZEN)
live = load(LIVE)
for arg in args:
    a = int(arg, 16)
    f = frozen.get(a, [])
    l = live.get(a, [])
    fs = "; ".join(f"{r[1] if len(r) > 1 else ''} | {r[2] if len(r) > 2 else ''}" for r in f) or "(no row)"
    ls = "; ".join(f"{r[1] if len(r) > 1 else ''} | {r[2] if len(r) > 2 else ''}" for r in l) or "(no row)"
    mark = "" if fs == ls else "   <-- LIVE DIFFERS: " + ls
    com = (f[0][3] if f and len(f[0]) > 3 else "")[:90]
    print(f"0x{a:08x} | {fs} | {com}{mark}")
