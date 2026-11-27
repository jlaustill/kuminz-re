"""Check proposed names for collisions in the frozen CSVs AND in the live repository CSVs (the orchestrator applies
other batches while this one runs) - read-only helper, round 93 batch D1 investigator, session 2.
usage: check_names2.py name [name ...]   (reports every row whose name column equals the name; also reports a
duplicate inside the argument list)"""
import csv
import sys
from collections import Counter

F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/"
R = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/"
FILES = {
    "frozen cm550 functions": F + "cm550/function_renames.csv",
    "frozen cm848 functions": F + "cm848/function_renames.csv",
    "frozen cm550 globals": F + "cm550/global_variables.csv",
    "frozen cm848 globals": F + "cm848/global_variables.csv",
    "live cm550 functions": R + "CM550_J90350.00_analysis/output/function_renames.csv",
    "live cm848 functions": R + "CM848_S90140.06_analysis/output/function_renames.csv",
    "live cm550 globals": R + "CM550_J90350.00_analysis/output/global_variables.csv",
    "live cm848 globals": R + "CM848_S90140.06_analysis/output/global_variables.csv",
}
tables = {}
for label, path in FILES.items():
    names = {}
    for row in csv.reader(open(path, errors="replace")):
        if len(row) >= 2 and not row[0].startswith("#"):
            names.setdefault(row[1].strip(), []).append(row[0].strip())
    tables[label] = names
# struct field / enum member names too (a global must not shadow them badly; informational)
dups = [n for n, c in Counter(sys.argv[1:]).items() if c > 1]
if dups:
    print("DUPLICATE PROPOSALS:", dups)
for name in sys.argv[1:]:
    hits = [f"{label}: {','.join(t[name])}" for label, t in tables.items() if name in t]
    print(f"{name}: " + ("; ".join(hits) if hits else "free"))
