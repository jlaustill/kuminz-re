"""Skeptic: the records of one e2m block at given offsets as (offset, type, size, mask, name, text), one line per
distinct record (the 0= / 1= value-label duplicates of an S record collapse).
usage: blockmasks.py <e2m file> <block hex> [<offset hex>...]"""
import sys

path = sys.argv[1]
block = int(sys.argv[2], 16)
offs = [int(x, 16) for x in sys.argv[3:]]
seen = {}
for raw in open(path, encoding="latin-1"):
    line = raw.rstrip("\r\n")
    data, _, comment = line.partition(";")
    c = data.split(",")
    if len(c) < 12:
        continue
    try:
        if int(c[2], 16) != block:
            continue
        off = int(c[3], 16)
    except ValueError:
        continue
    if offs and off not in offs:
        continue
    try:
        mask = int(c[10], 16) if c[5] == "S" else None
    except ValueError:
        mask = None
    key = (off, c[5], c[7], mask, c[0])
    seen.setdefault(key, comment.split("~")[0].strip())
for (off, typ, size, mask, name), text in sorted(seen.items(), key=lambda kv: (kv[0][0], kv[0][3] or 0, kv[0][4])):
    m = ("0x%x" % mask) if mask is not None else "-"
    bit = ""
    if mask and mask & (mask - 1) == 0:
        bit = "bit %d" % (mask.bit_length() - 1)
    print(f"+{off:02X} {typ} size={size} mask={m:>10} {bit:7} {name:10} {text}")
