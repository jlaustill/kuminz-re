"""Round 62: the service IDs registered through cm848_j1939RegisterDiagnosticService with a constant, against the
EF00_SERVICE_ID enum's members.  usage: service_ids.py <repo>"""
import csv
import os
import re
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
cpp = open(os.path.join(O, "cm848_rom.ghidra.cpp"), errors="replace").read()
regs = sorted({int(v, 0) for v in re.findall(r"cm848_j1939RegisterDiagnosticService\s*\(\s*(0x[0-9a-f]+|\d+)\s*,", cpp)})
members = {}
for r in csv.reader(open(os.path.join(O, "enums.csv"))):
    if r and r[0] == "EF00_SERVICE_ID":
        members[int(r[1], 0)] = r[2]
print("registered:", [hex(v) for v in regs])
print("missing from EF00_SERVICE_ID:", [hex(v) for v in regs if v not in members])
print("members:", {hex(k): v for k, v in sorted(members.items())})
