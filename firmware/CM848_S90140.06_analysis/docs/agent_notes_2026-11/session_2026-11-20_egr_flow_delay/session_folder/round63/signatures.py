"""Print each named function's decompiled signature (from the CM848 .cpp, joined onto one line) and its
function_definitions.csv rows.  usage: signatures.py <repo> <name>..."""
import os
import re
import sys

repo, names = os.path.abspath(sys.argv[1]), sys.argv[2:]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
cpp = open(os.path.join(O, "cm848_rom.ghidra.cpp"), errors="replace").read()
rows = open(os.path.join(O, "function_definitions.csv")).read().split("\n")
for name in names:
    m = re.search(rf"^// Function: {re.escape(name)} @ (0x[0-9a-f]+)\n(.*?)\n\{{", cpp, re.M | re.S)
    if not m:
        print(f"{name}: not found")
        continue
    head = m.group(2).split("*/")[-1]
    signature = " ".join(head.split())
    defs = [r.split(",", 5)[2:5] for r in rows if re.match(rf"0x[0-9a-f]+,{re.escape(name)},", r)]
    print(f"{m.group(1)} {signature}  | csv rows: {defs if defs else 'none'}")
