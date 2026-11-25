"""Round 94: CM550 function_renames.csv rows for the two functions batch L2 names that have no row yet (0x1fe84,
reached through movea.l #0x1fe84,a4 in mc68k_initializeJ1939Datalink; 0x33d38, the PGN 65252 shutdown payload
builder): the apply renames rows, it does not create them. The placeholder name is the decompiler's default with the
cm550_ prefix. Idempotent; keeps line endings. usage: add_function_placeholders_r94.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
path = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv")
text = open(path, newline="").read()
E = "\r\n" if "\r\n" in text else "\n"
lines = text.split(E)
for a in (0x1fe84, 0x33d38):
    key = f"0x{a:08x}"
    if any(l.lower().startswith(key + ",") for l in lines):
        continue
    idx = next(i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) > a)
    lines.insert(idx, f"{key},cm550_FUN_{a:08x},")
    print("inserted", key)
open(path, "w", newline="").write(E.join(lines))
