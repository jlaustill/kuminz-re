"""Round 96: every function_definitions.csv / local_variables.csv row's function_name must equal the
function_renames.csv name at its address (both firmwares). Prints the mismatches; exit 1 when any.
usage: funcdef_name_check_r96.py <repo>"""
import csv
import os
import sys

repo = os.path.abspath(sys.argv[1])
bad = 0
for fw in ("CM550_J90350.00_analysis", "CM848_S90140.06_analysis"):
    out = os.path.join(repo, "firmware", fw, "output")
    names = {}
    for r in csv.reader(open(os.path.join(out, "function_renames.csv"), newline="")):
        if r and r[0].startswith("0x"):
            names[int(r[0], 16)] = r[1]
    for f in ("function_definitions.csv", "local_variables.csv"):
        for n, r in enumerate(csv.reader(open(os.path.join(out, f), newline="")), 1):
            if len(r) > 1 and r[0].startswith("0x"):
                a = int(r[0], 16)
                if a in names and names[a] != r[1]:
                    print(f"{fw[:5]} {f}:{n} 0x{a:x} {r[1]} != {names[a]}")
                    bad += 1
                elif a not in names:
                    print(f"{fw[:5]} {f}:{n} 0x{a:x} {r[1]}: no function_renames row")
print("mismatches", bad)
sys.exit(1 if bad else 0)
