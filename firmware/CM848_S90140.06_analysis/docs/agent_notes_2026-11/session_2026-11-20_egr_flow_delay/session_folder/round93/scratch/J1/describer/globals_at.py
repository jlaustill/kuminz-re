"""Round 93 J1 describer (read-only): print the global_variables.csv rows that cover given addresses
(exact row, or the nearest row below with its distance).
usage: globals_at.py <cm550|cm848> <0xADDR> [...]"""
import bisect
import csv
import sys

FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen"
fw = sys.argv[1]
rows = []
for r in csv.reader(open(f"{FROZEN}/{fw}/global_variables.csv", errors="replace")):
    if r and r[0].lower().startswith("0x"):
        try:
            rows.append((int(r[0], 16), r))
        except ValueError:
            pass
rows.sort(key=lambda x: x[0])
addrs = [a for a, _ in rows]
for arg in sys.argv[2:]:
    a = int(arg, 16)
    k = bisect.bisect_right(addrs, a) - 1
    if k < 0:
        print(f"0x{a:x}: (below first row)")
        continue
    base, r = rows[k]
    tag = "EXACT" if base == a else f"+0x{a - base:x} into"
    print(f"0x{a:x}: {tag} 0x{base:x} {r[1]} | {r[2] if len(r) > 2 else ''} | {(r[3] if len(r) > 3 else '')[:300]}")
