"""Print the frozen CM550 global_variables.csv rows for given addresses (read-only helper, round 93 batch D1 investigator).
usage: rows.py 0xADDR ..."""
import csv
import sys

PATH = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen/cm550/global_variables.csv"
rows = {}
for row in csv.reader(open(PATH, errors="replace")):
    if row and row[0].lower().startswith("0x"):
        rows.setdefault(int(row[0], 16), []).append(row)
for arg in sys.argv[1:]:
    a = int(arg, 16)
    if a in rows:
        for r in rows[a]:
            name = r[1] if len(r) > 1 else ""
            typ = r[2] if len(r) > 2 else ""
            com = (r[3] if len(r) > 3 else "")[:110]
            print(f"0x{a:08x} | {name} | {typ} | {com}")
    else:
        print(f"0x{a:08x} | (no row)")
