"""Round 94 (read-only): the live CM550 global rows inside each given span (start, size, label), with their type and
how often their name renders in the .cpp. usage: rows_inside_r94.py <repo> <start hex>:<size>:<label>..."""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
cpp = open(os.path.join(O, "J90350.00.ghidra.cpp"), errors="replace").read()
rows = []
for line in open(os.path.join(O, "global_variables.csv"), newline="").read().split("\n"):
    parts = line.split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x"):
        rows.append((int(parts[0], 16), parts[1], parts[2]))
for spec in sys.argv[2:]:
    start, size, label = spec.split(":")
    a, n = int(start, 16), int(size)
    inside = [r for r in rows if a <= r[0] < a + n]
    print(f"== {label} 0x{a:x}-0x{a + n - 1:x} ({n} bytes): {len(inside)} rows")
    for addr, name, typ in inside:
        uses = len(re.findall(rf"\b_?{re.escape(name)}\b", cpp)) if name else 0
        print(f"   0x{addr:x} +{addr - a} {name or '(no name)'} {typ} renders {uses}")
