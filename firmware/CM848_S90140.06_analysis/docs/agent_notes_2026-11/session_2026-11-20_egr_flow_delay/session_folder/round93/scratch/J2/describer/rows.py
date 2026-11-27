"""Describer J2 (read-only): print the global_variables.csv row(s) of a firmware for given addresses (exact) and
the rows whose address lies in [addr, addr+span).  usage: rows.py <cm550|cm848> <0xADDR[:span]> ..."""
import csv
import os
import sys

frozen = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen"
fw = sys.argv[1]
rows = []
for r in csv.reader(open(os.path.join(frozen, fw, "global_variables.csv"), newline="", errors="replace")):
    if not r or r[0].startswith("#") or not r[0].lower().startswith("0x"):
        continue
    try:
        rows.append((int(r[0], 16), r))
    except ValueError:
        pass
rows.sort(key=lambda x: x[0])
for arg in sys.argv[2:]:
    if ":" in arg:
        a, span = arg.split(":")
        a = int(a, 16)
        span = int(span, 0)
    else:
        a = int(arg, 16)
        span = 1
    hits = [r for (x, r) in rows if a <= x < a + span]
    if not hits:
        print(f"0x{a:x}: (no row)")
    for r in hits:
        print(" | ".join(c[:260] for c in r))
