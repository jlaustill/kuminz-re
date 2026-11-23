"""Round 63 stage A pre-build checks: the boot kernel's registrations, enum prefix collisions, existing enum-typed struct
fields / prototype rows (does the importer take an enum type there?), and which handler family names CM550 has.
usage: checks_r63a.py <repo>"""
import collections
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
cpp = open(os.path.join(O, "cm848_rom.ghidra.cpp"), errors="replace").read()
print("== boot kernel registrations (cm848_registerDiagnosticService):")
for call, n in sorted(collections.Counter(re.findall(r"cm848_registerDiagnosticService\s*\([^;]*;", cpp)).items()):
    print(f"  {n} x {' '.join(call.split())[:130]}")
rows = [r for r in csv.reader(open(os.path.join(O, "enums.csv"))) if r and not r[0].startswith("#")]
enums = {r[0] for r in rows}
print("== enums named J1939_DIAGNOSTIC*:", sorted(e for e in enums if e.startswith("J1939_DIAGNOSTIC")))
members = collections.Counter(r[2] for r in rows if len(r) > 2)
print("== duplicate member names anywhere:", [m for m, n in members.items() if n > 1][:10])
n = [r for r in csv.reader(open(os.path.join(O, "structure_definitions.csv"))) if len(r) > 3 and r[3] in enums]
print("== enum-typed struct fields:", len(n), [(r[0], r[2], r[3]) for r in n[:3]])
d = [r for r in csv.reader(open(os.path.join(O, "function_definitions.csv"))) if len(r) > 4 and r[4] in enums]
print("== enum-typed prototype rows:", len(d), [(r[1], r[2], r[4]) for r in d[:3]])
family = sorted(set(re.findall(r"\bj1939_(?:diagService\w+|readDiag\w+|writeDiag\w+)", cpp)))
cm550 = ""
for name in os.listdir(O5):
    if name.endswith((".csv", ".cpp")):
        cm550 += open(os.path.join(O5, name), errors="replace").read()
print("== CM848 j1939_diagService* / readDiag* / writeDiag* names and CM550 hits:")
for name in family:
    print(f"  {name}: CM550 {len(re.findall(rf'\\b{name}\\b', cm550))}")
