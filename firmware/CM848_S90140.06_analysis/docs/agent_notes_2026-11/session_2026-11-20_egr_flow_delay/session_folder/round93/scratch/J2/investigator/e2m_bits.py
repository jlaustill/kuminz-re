"""J2 investigator (round 93, read-only): the S (bit) records of an e2m block / offset with their masks.
usage: e2m_bits.py <e2m file> <block hex> <offset hex> [<offset hex> ...]"""
import sys

path, block = sys.argv[1], sys.argv[2].upper()
offsets = {o.upper().lstrip("0") or "0" for o in sys.argv[3:]}
seen = set()
for line in open(path, errors="replace"):
    head = line.split(";")[0].split(",")
    if len(head) < 11 or head[2].upper() != block:
        continue
    off = head[3].upper().lstrip("0") or "0"
    if offsets and off not in offsets:
        continue
    key = (head[0], off, head[5], head[10])
    if key in seen:
        continue
    seen.add(key)
    desc = line.split(";", 1)[1].strip() if ";" in line else ""
    print(f"{head[0]:10s} +{off:>4s} type {head[5]} len {head[7]} mask/scale {head[10]:>6s} | {desc[:150]}")
