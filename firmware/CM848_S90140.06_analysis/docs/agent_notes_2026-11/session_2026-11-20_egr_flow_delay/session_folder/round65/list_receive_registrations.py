"""Every cm848_registerJ1939ReceiveHandler(<key>, <handler>) call in the CM848 .cpp, with comments stripped first (a
plate mentioning the registrar garbled the first listing).  usage: list_receive_registrations.py <repo>"""
import os
import re
import sys

text = open(os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"),
            errors="replace").read()
code = " ".join(re.sub(r"/\*.*?\*/", " ", text, flags=re.S).split())
calls = re.findall(r"cm848_registerJ1939ReceiveHandler\s*\(\s*([0-9a-fx]+)\s*,\s*([A-Za-z0-9_]+)\s*\)\s*;", code)
for key, handler in calls:
    print(f"{key:8} {handler}")
print("registrations:", len(calls))
