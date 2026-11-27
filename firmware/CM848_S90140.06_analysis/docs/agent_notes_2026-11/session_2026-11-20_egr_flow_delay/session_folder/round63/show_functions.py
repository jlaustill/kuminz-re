"""Print the plate and body of each named function from the CM848 .cpp (blank lines dropped).
usage: show_functions.py <repo> <max lines per function> <name>..."""
import os
import re
import sys

repo, limit, names = os.path.abspath(sys.argv[1]), int(sys.argv[2]), sys.argv[3:]
cpp = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"), errors="replace").read()
for name in names:
    m = re.search(rf"^// Function: {re.escape(name)} @ (0x[0-9a-f]+)\n(.*?)(?=^// Function: )", cpp, re.M | re.S)
    if not m:
        print(f"=== {name}: not found")
        continue
    body = [l for l in m.group(2).split("\n") if l.strip() and l.strip() != "//"]
    print(f"=== {name} @ {m.group(1)} ({len(body)} lines)")
    for line in body[:limit]:
        print("  " + line[:150])
