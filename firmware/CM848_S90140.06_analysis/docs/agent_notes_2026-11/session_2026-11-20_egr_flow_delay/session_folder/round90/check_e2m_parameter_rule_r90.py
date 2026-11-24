"""Round 90 (read-only): does "the first e2m record (file order) whose resolved address is the entry's address"
reproduce parameter_id_lookup_table.csv's e2m_parameter column? Tried per e2m original.
usage: check_e2m_parameter_rule_r90.py <repo>"""
import csv
import glob
import os
import sys

repo = sys.argv[1]
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
rows = list(csv.DictReader(open(os.path.join(O, "parameter_id_lookup_table.csv"), newline="")))
table = {int(r["param_id_hex"], 16): int(r["address_hex"], 16) for r in rows}
results = []
for f in sorted(glob.glob(os.path.join(repo, "e2m-analysis/originals/*.e2m"))):
    first = {}
    for line in open(f, encoding="latin-1"):
        c = line.split(",")
        if len(c) < 4:
            continue
        try:
            b, o = int(c[2], 16), int(c[3], 16)
        except ValueError:
            continue
        if b in table:
            first.setdefault(table[b] + o, c[0])
    same = sum(1 for r in rows if r["e2m_parameter"] and first.get(int(r["address_hex"], 16)) == r["e2m_parameter"])
    differ = [(r["param_id_hex"], r["e2m_parameter"], first.get(int(r["address_hex"], 16)))
              for r in rows if r["e2m_parameter"] and first.get(int(r["address_hex"], 16)) != r["e2m_parameter"]]
    new = sum(1 for r in rows if not r["e2m_parameter"] and int(r["address_hex"], 16) in first)
    results.append((same, os.path.basename(f), len(differ), new, differ[:4]))
results.sort(reverse=True)
for r in results[:5]:
    print(f"{r[1]}: {r[0]} of 91 reproduced, {r[2]} differ, {r[3]} empty rows would gain one; e.g. {r[4]}")
