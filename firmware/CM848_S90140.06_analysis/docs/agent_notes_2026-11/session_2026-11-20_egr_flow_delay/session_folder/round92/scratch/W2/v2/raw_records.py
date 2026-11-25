"""Print the raw v64t6_s.e2m lines of block 106B at the given hex offsets (full line, untruncated by this tool).
usage: raw_records.py <e2m> <hex offset>..."""
import sys

path = sys.argv[1]
offs = {int(x, 16) for x in sys.argv[2:]}
rows = []
for i, raw in enumerate(open(path, encoding="latin-1"), 1):
    line = raw.rstrip("\r\n")
    data, _, comment = line.partition(";")
    c = data.split(",")
    if len(c) < 12 or c[2] != "106B":
        continue
    try:
        off = int(c[3], 16)
    except ValueError:
        continue
    if off in offs:
        rows.append((off, c[5], c[10], i, line))
for off, typ, mask, i, line in sorted(rows, key=lambda r: (r[0], r[1], int(r[2], 16) if all(ch in "0123456789abcdefABCDEF" for ch in r[2]) else 0, r[3])):
    print(f"{i}: +0x{off:x} | {line}")
