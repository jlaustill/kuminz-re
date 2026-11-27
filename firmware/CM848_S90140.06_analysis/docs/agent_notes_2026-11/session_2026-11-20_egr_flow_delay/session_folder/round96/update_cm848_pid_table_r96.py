"""Round 96: CM848's parameter_id_lookup_table.csv (no generator script; CM550's is written by e2m_block_addresses.py).
- region: 0x302000-0x3037ff is the MPC555 DPTRAM array (MPC555UM: 'must be located at the address 0x30 2000',
  0x30 2000-0x30 37FF), not registers (QADC_A is 0x304800): MPC555_REG -> DPTRAM.
- firmware_variable: the live global_variables.csv name at the address, EEPROM 0x01000000+o read through the
  application's RAM mirror 0x3fd482+o (firmware/CLAUDE.md); empty where no row exists.
Prints each change. usage: update_cm848_pid_table_r96.py <repo>"""
import csv
import io
import os
import sys

repo = os.path.abspath(sys.argv[1])
D = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
live = {}
for line in open(os.path.join(D, "global_variables.csv"), newline=""):
    p = line.rstrip("\r\n").split(",", 2)
    if len(p) > 1 and p[0].startswith("0x"):
        live[int(p[0], 16)] = p[1]
path = os.path.join(D, "parameter_id_lookup_table.csv")
text = open(path, newline="").read()
E = "\r\n" if "\r\n" in text else "\n"
rows = list(csv.DictReader(io.StringIO(text)))
fields = list(rows[0].keys())
for r in rows:
    a = int(r["address_hex"], 16)
    region = r["region"]
    if 0x302000 <= a <= 0x3037ff:
        region = "DPTRAM"
    ram = 0x3fd482 + (a - 0x01000000) if 0x01000000 <= a < 0x01002000 else a
    name = live.get(ram, "")
    if (region, name) != (r["region"], r["firmware_variable"]):
        print(r["param_id_hex"], r["address_hex"], f"{r['region']} -> {region}", f"'{r['firmware_variable']}' -> '{name}'", f"(RAM 0x{ram:x})" if ram != a else "")
    r["region"], r["firmware_variable"] = region, name
out = io.StringIO()
w = csv.DictWriter(out, fieldnames=fields, lineterminator=E)
w.writeheader()
w.writerows(rows)
open(path, "w", newline="").write(out.getvalue())
