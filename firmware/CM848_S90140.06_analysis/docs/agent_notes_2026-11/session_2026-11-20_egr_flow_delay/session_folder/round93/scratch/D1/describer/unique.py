"""Describer D1 scratch: count exact-name hits of proposed names in both firmwares' function, global and enum CSVs.
usage: unique.py name [...]"""
import csv
import sys

R = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen"
FILES = [("cm550 functions", f"{R}/cm550/function_renames.csv", 1), ("cm550 globals", f"{R}/cm550/global_variables.csv", 1),
         ("cm848 functions", f"{R}/cm848/function_renames.csv", 1), ("cm848 globals", f"{R}/cm848/global_variables.csv", 1),
         ("cm550 enums", f"{R}/cm550/enums.csv", 0), ("cm848 enums", f"{R}/cm848/enums.csv", 0),
         ("cm550 enum members", f"{R}/cm550/enums.csv", 2), ("cm848 enum members", f"{R}/cm848/enums.csv", 2)]
names = {}
for label, path, col in FILES:
    for row in csv.reader(open(path, errors="replace")):
        if len(row) > col and not row[0].startswith("#"):
            names.setdefault(row[col].strip(), set()).add(label)
for n in sys.argv[1:]:
    print(f"{n}: {sorted(names.get(n, [])) or 'unique'}")
