"""Round 96: is every firmware_variable in a parameter_id_lookup_table.csv the live global_variables.csv name at its
address? Prints the mismatches. usage: pid_table_names_check_r96.py <repo> <cm550|cm848>"""
import csv
import os
import sys

repo, fw = os.path.abspath(sys.argv[1]), sys.argv[2]
D = os.path.join(repo, {"cm550": "firmware/CM550_J90350.00_analysis/output", "cm848": "firmware/CM848_S90140.06_analysis/output"}[fw])
live = {}
for line in open(os.path.join(D, "global_variables.csv"), newline=""):
    p = line.rstrip("\r\n").split(",", 2)
    if len(p) > 1 and p[0].startswith("0x"):
        live[int(p[0], 16)] = p[1]
bad = total = 0
for r in csv.DictReader(open(os.path.join(D, "parameter_id_lookup_table.csv"), newline="")):
    name = (r.get("firmware_variable") or "").strip()
    if not name:
        continue
    total += 1
    a = int(r["address_hex"], 16)
    if live.get(a) != name:
        bad += 1
        print(r["param_id"], r["address_hex"], name, "->", live.get(a))
print(fw, total, "named rows;", bad, "not the live name")
