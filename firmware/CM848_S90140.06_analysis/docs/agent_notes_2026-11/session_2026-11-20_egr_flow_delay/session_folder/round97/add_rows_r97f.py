"""Round 97 stage F pre-step: R6 names two CM550 functions that have no function_renames.csv row - 0x224f4 (a Ghidra
function, FUN_000224f4, whose body is not exported) and 0x1ffd2 (today the label LAB_0001ffd2: two diagnostic services
register it, so the row creates the function). Each gets a row with its current default label, in address order, so
the apply renames it. usage: add_rows_r97f.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/function_renames.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
for address, label in ((0x224f4, "FUN_000224f4"), (0x1ffd2, "LAB_0001ffd2")):
    assert not any(l.startswith(f"0x{address:08x},") for l in lines)
    k = next(i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",", 1)[0], 16) > address)
    lines.insert(k, f"0x{address:08x},{label},")
    print("inserted", hex(address), "before", lines[k + 1][:60])
open(p, "w", newline="").write(E.join(lines))
