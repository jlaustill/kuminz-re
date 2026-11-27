"""Round 91 (read-only): the CM550 rows inside each struct candidate's range, with their types and .cpp reference
counts. usage: rows_in_ranges_r91.py <repo>"""
import collections
import csv
import os
import re
import sys

repo = sys.argv[1]
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
rows = [r for r in csv.reader(open(os.path.join(O, "global_variables.csv"), newline="")) if r and r[0].startswith("0x")]
cpp = open(os.path.join(O, "J90350.00.ghidra.cpp"), errors="replace").read()
code = "\n".join(l for l in cpp.split("\n") if not l.strip().startswith(("//", "/*", "*")))
refs = collections.Counter(re.findall(r"\b[A-Za-z_]\w*\b", code))
RANGES = {
    "fault count table (125 x 10 bytes)": (0x805a1c, 0x805a1c + 1250),
    "datalogger triggers / data (e2m 1282 area)": (0x803d60, 0x803e10),
    "TSC1 gain sets": (0x807b92, 0x807b92 + 72),
}
for title, (a, b) in RANGES.items():
    inside = [r for r in rows if a <= int(r[0], 16) < b]
    print(f"== {title} 0x{a:x}-0x{b - 1:x}: {len(inside)} rows")
    for r in inside[:40]:
        print(f"   {r[0]} {r[1]} {r[2]} refs={refs.get(r[1], 0) + refs.get('_' + r[1], 0)}")
