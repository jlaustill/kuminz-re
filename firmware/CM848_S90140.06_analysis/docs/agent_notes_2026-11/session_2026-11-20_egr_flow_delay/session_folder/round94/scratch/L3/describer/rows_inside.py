"""List every global_variables.csv row whose address lies inside [start, start + size) for each 'start:size' arg."""
import csv
import sys

path = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/global_variables.csv"
rows = []
with open(path, newline="") as f:
    for r in csv.reader(f):
        if not r or r[0].startswith("#") or not r[0].startswith("0x"):
            continue
        try:
            rows.append((int(r[0], 16), r))
        except ValueError:
            pass
for arg in sys.argv[1:]:
    s, n = arg.split(":")
    s, n = int(s, 16), int(n, 0)
    print(f"== 0x{s:x} .. 0x{s + n - 1:x}")
    for a, r in sorted(rows):
        if s <= a < s + n:
            print(f"   0x{a:x} {r[1]} | {r[2] if len(r) > 2 else ''} | {(r[3] if len(r) > 3 else '')[:150]}")
    # also rows starting before s that may overlap (report the 4 rows before)
    before = [x for x in sorted(rows) if x[0] < s][-2:]
    for a, r in before:
        print(f"   (before) 0x{a:x} {r[1]} | {r[2] if len(r) > 2 else ''}")
