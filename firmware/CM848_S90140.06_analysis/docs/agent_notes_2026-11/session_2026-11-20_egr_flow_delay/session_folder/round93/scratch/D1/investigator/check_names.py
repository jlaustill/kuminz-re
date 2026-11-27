"""Check proposed names for collisions in the frozen CSVs (read-only helper, round 93 batch D1 investigator).
usage: check_names.py name [name ...]   (reports every row whose name column equals the name, in both firmwares)"""
import csv
import sys

F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/"
FILES = {
    "cm550 functions": F + "cm550/function_renames.csv",
    "cm848 functions": F + "cm848/function_renames.csv",
    "cm550 globals": F + "cm550/global_variables.csv",
    "cm848 globals": F + "cm848/global_variables.csv",
}
tables = {}
for label, path in FILES.items():
    names = {}
    for row in csv.reader(open(path, errors="replace")):
        if len(row) >= 2 and not row[0].startswith("#"):
            names.setdefault(row[1].strip(), []).append(row[0].strip())
    tables[label] = names
for name in sys.argv[1:]:
    hits = [f"{label}: {','.join(t[name])}" for label, t in tables.items() if name in t]
    print(f"{name}: " + ("; ".join(hits) if hits else "free"))
