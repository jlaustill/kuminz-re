"""Round 57: refresh_references.py covers global_variables.csv and function_renames.csv only. Rounds 55 / 57 found old
names in the comments of the other CSVs (structure_definitions.csv in round 55, enums.csv here), so replace every
renamed old name (whole words; never a default label such as DAT_ / WORD_ / a struct type's address name) in the
other output CSVs. Idempotent.  usage: refresh_other_csvs_r57.py <repo> <map.csv>"""
import csv
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
OUT = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
OTHERS = ["enums.csv", "structure_definitions.csv", "arrays.csv", "labels.csv", "constants.csv",
          "local_variables.csv", "function_definitions.csv"]
rows = [r for r in csv.DictReader(open(map_path)) if not re.match(r"(DAT|WORD|BYTE)_|.*_t_[0-9a-f]{8}$", r["old_label"])]
total = 0
for name in OTHERS:
    p = os.path.join(OUT, name)
    t = open(p).read()
    n = 0
    for r in rows:
        t, k = re.subn(rf"(?<![\w.]){re.escape(r['old_label'])}\b", r["name"], t)
        n += k
    if n:
        open(p, "w").write(t)
        print(f"{name}: {n} mentions refreshed")
    total += n
print(f"{total} mentions refreshed")
