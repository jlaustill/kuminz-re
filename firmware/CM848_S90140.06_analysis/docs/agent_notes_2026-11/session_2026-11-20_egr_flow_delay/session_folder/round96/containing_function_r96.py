"""Round 96: the CM550 function_renames.csv row at or below each address (the function a call site is most likely in;
check the body's end by hand). usage: containing_function_r96.py <repo> <hex>..."""
import bisect
import os
import sys

rows = []
for line in open(os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/function_renames.csv"), newline=""):
    p = line.rstrip("\r\n").split(",", 2)
    if len(p) > 1 and p[0].startswith("0x"):
        rows.append((int(p[0], 16), p[1]))
rows.sort()
starts = [a for a, _ in rows]
for h in sys.argv[2:]:
    a = int(h, 16)
    k = bisect.bisect_right(starts, a) - 1
    print(f"0x{a:x}: in {rows[k][1]} (0x{rows[k][0]:x}); next row 0x{rows[k + 1][0]:x}")
