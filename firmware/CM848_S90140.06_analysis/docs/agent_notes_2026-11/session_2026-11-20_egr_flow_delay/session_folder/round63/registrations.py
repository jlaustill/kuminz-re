"""Round 63: every cm848_j1939RegisterDiagnosticService(<constant>, <handler>) call in the .cpp, with the enum member
the constant has today, the member's comment, and the handler's plate head.  usage: registrations.py <repo>"""
import csv
import os
import re
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
cpp = open(os.path.join(O, "cm848_rom.ghidra.cpp"), errors="replace").read()
calls = re.findall(r"cm848_j1939RegisterDiagnosticService\s*\(\s*(0x[0-9a-f]+|\d+)\s*,\s*(\w+)\s*\)", cpp)
members = {}
for r in csv.reader(open(os.path.join(O, "enums.csv"))):
    if r and r[0] == "EF00_SERVICE_ID":
        members[int(r[1], 0)] = (r[2], r[3])
plates = {}
for line in open(os.path.join(O, "function_renames.csv")):
    if line.startswith("0x"):
        p = line.rstrip("\n").split(",", 2)
        plates[p[1]] = p[2] if len(p) > 2 else ""
for value, handler in sorted({(int(v, 0), h) for v, h in calls}):
    name, comment = members.get(value, ("(none)", ""))
    print(f"{value:#04x} {name:30} {comment[:44]:44} <- {handler} | {plates.get(handler, '')[:90]}")
print("members never registered:", {hex(k): v[0] for k, v in members.items() if k not in {int(v, 0) for v, _ in calls}})
