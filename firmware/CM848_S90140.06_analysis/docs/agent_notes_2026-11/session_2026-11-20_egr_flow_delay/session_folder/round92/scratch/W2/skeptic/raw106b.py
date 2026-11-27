"""Skeptic: raw e2m records of a block at given offsets (full lines, duplicates dropped).
usage: raw106b.py <e2m file> <block> <offset hex>..."""
import sys

path = sys.argv[1]
block = sys.argv[2].upper()
offs = [int(x, 16) for x in sys.argv[3:]]
seen = set()
for raw in open(path, encoding="latin-1"):
    line = raw.rstrip("\r\n")
    data, _, comment = line.partition(";")
    c = data.split(",")
    if len(c) < 12 or c[2].upper() != block:
        continue
    try:
        off = int(c[3], 16)
    except ValueError:
        continue
    if offs and off not in offs:
        continue
    if line in seen:
        continue
    seen.add(line)
    print(f"+{off:02X} | {line}")
