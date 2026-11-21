"""Displacement-form access census: every load / store whose base register was set by `lis rN,<hi>` (within the
previous 40 instructions) and whose displacement reaches the address. Prints the width mix per address.
usage: width_census.py <all.dis> <0xaddress>..."""
import re
import sys
from collections import Counter

lines = open(sys.argv[1]).read().split("\n")
INS = re.compile(r"^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2} ){4}\s*(\S+)\s+(\S+)")
MEM = re.compile(r"^r(\d+),(-?\d+)\(r(\d+)\)$")
WIDTH = {"lbz": 1, "lbzu": 1, "stb": 1, "stbu": 1, "lhz": 2, "lhzu": 2, "lha": 2, "lhau": 2, "sth": 2, "sthu": 2,
         "lwz": 4, "lwzu": 4, "stw": 4, "stwu": 4}
targets = {int(a, 16): a for a in sys.argv[2:]}
found = {a: Counter() for a in targets}
parsed = [INS.match(line) for line in lines]
for i, m in enumerate(parsed):
    if not m or m.group(2) not in WIDTH:
        continue
    mm = MEM.match(m.group(3))
    if not mm:
        continue
    disp, base = int(mm.group(2)), mm.group(3)
    for j in range(i - 1, max(i - 40, -1), -1):
        p = parsed[j]
        if p and p.group(2) == "lis" and p.group(3).startswith(f"r{base},"):
            address = (int(p.group(3).split(",")[1]) << 16) + disp
            if address in found:
                found[address][f"{m.group(2)}"] += 1
            break
        if p and re.match(rf"^r{base},", p.group(3)) and p.group(2) not in ("cmpw", "cmpwi", "cmplw", "cmplwi"):
            break                                               # the base register was overwritten first
for a, c in found.items():
    widths = {WIDTH[k] for k in c}
    print(f"{targets[a]}: {dict(c)} -> {'/'.join(str(w) for w in sorted(widths)) or 'none'} byte")
