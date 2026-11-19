"""Read-only scratch helper: find `lis rN,hi ; addi rN,rN,lo` (or displacement) forms whose address falls in a window.
usage: find_table_refs.py <all.dis> <lo hex> <hi hex>"""
import re
import sys

lines = open(sys.argv[1]).read().split("\n")
lo_w, hi_w = int(sys.argv[2], 16), int(sys.argv[3], 16)
INS = re.compile(r"^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2} ){4}\s*(\S+)\s+(\S+)")
parsed = [INS.match(line) for line in lines]
for i, m in enumerate(parsed):
    if not m or m.group(2) != "lis":
        continue
    reg, hi = m.group(3).split(",")
    hi = int(hi)
    for j in range(i + 1, min(i + 8, len(parsed))):
        p = parsed[j]
        if not p:
            continue
        mm = re.match(rf"^r\d+,r{reg[1:]},(-?\d+)$", p.group(3)) if p.group(2) == "addi" else None
        mm2 = re.match(rf"^r\d+,(-?\d+)\({reg}\)$", p.group(3)) if p.group(2) in ("lhz", "lwz", "lbz", "lha", "sth", "stw", "stb") else None
        value = None
        if mm:
            value = (hi << 16) + int(mm.group(1))
        elif mm2:
            value = (hi << 16) + int(mm2.group(1))
        if value is not None and lo_w <= value <= hi_w:
            print(m.group(1), "->", hex(value), "|", p.group(1), p.group(2), p.group(3))
            break
