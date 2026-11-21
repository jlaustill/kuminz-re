"""Print each named global's address, type and its e2m record (by address, through the ECU's parameter ID table).
usage: e2m_of_names.py <repo> NAME [NAME ...]"""
import csv
import os
import subprocess
import sys

repo = os.path.abspath(sys.argv[1])
fw = os.path.join(repo, "firmware")
gv = os.path.join(fw, "CM848_S90140.06_analysis", "output", "global_variables.csv")
rows = {}
for line in open(gv):
    if line.startswith("0x"):
        r = next(csv.reader([line]))
        if len(r) > 2:
            rows.setdefault(r[1], (r[0], r[2]))
for name in sys.argv[2:]:
    if name not in rows:
        print(f"{name}: no row")
        continue
    a, t = rows[name]
    out = subprocess.run([sys.executable, os.path.join(fw, "scripts", "e2m_block_addresses.py"), "--address", a],
                         capture_output=True, text=True, cwd=fw).stdout.strip().split("\n")[0]
    print(f"{name} {a} {t} | {out[:150]}")
