"""Round 93 J1 describer (read-only): list e2m records by block and offset(s), or by a mnemonic / description regex.
usage: e2m_grep.py <e2m file> block <BLOCK> [<OFFSET hex> ...]
       e2m_grep.py <e2m file> re <regex>"""
import re
import sys

path, mode = sys.argv[1], sys.argv[2]
lines = open(path, errors="replace").read().splitlines()
seen = set()
for line in lines:
    head = line.split(";")[0].split(",")
    if len(head) < 11:
        continue
    if mode == "block":
        block = sys.argv[3].upper()
        offsets = {o.upper() for o in sys.argv[4:]}
        if head[2].upper() != block or (offsets and head[3].upper() not in offsets):
            continue
    else:
        if not re.search(sys.argv[3], line, flags=re.I):
            continue
    key = (head[0], head[2], head[3], head[10] if head[5] == "S" else "")
    if key in seen:
        continue
    seen.add(key)
    desc = line.split(";", 1)[1] if ";" in line else ""
    mask = f" mask 0x{head[10]}" if head[5] == "S" else f" scale {head[10]}"
    print(f"{head[0]:10s} {head[2]} +{head[3]:4s} type {head[5]} len {head[7]}{mask} unit {head[1]!r}: {desc[:150]}")
