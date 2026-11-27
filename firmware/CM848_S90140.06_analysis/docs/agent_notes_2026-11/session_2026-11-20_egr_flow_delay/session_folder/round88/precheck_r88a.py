"""Round 88 stage A pre-check (read-only): for each filter record instance, the CM550 global rows inside its 8 bytes
(and how often each row's name renders in the .cpp); for each coefficient word, its current row; the current
function_definitions rows of the four filter functions. usage: precheck_r88a.py <repo> <ema_changes.tsv>"""
import csv
import os
import re
import sys

repo, tsv = sys.argv[1], sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
cpp = open(os.path.join(O5, "J90350.00.ghidra.cpp"), errors="replace").read()
rows = {}
for r in csv.reader(open(os.path.join(O5, "global_variables.csv"), newline="")):
    if r and r[0].startswith("0x"):
        rows[int(r[0], 16)] = r
changes = [l.rstrip("\n").split("\t") for l in open(tsv)]
for kind, address, current, proposed, typ, fields, verdict, final, final_type, conf, reason in changes:
    if kind == "struct_instance":
        a = int(address, 16)
        inside = [(o, rows[a + o][1], rows[a + o][2]) for o in range(8) if a + o in rows]
        desc = "; ".join(f"+{o} {n or '(type-only)'}:{t} renders {len(re.findall(rf'(?<![A-Za-z0-9_]){re.escape(n)}(?![A-Za-z0-9_])', cpp)) if n else '-'}"
                         for o, n, t in inside)
        print(f"INSTANCE {address} -> {final}: {desc or 'no rows'}")
    elif kind == "global":
        a = int(address, 16)
        r = rows.get(a)
        print(f"COEFF {address} {final}: {'row ' + r[1] + ':' + r[2] if r else 'NO ROW'}")
for line in open(os.path.join(O5, "function_definitions.csv"), newline=""):
    if line[:10] in ("0x00034e9a", "0x00034f8a", "0x00034f00", "0x00034fe0"):
        print("FUNCDEF", line.rstrip()[:200])
