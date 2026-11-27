"""Skeptic pass 2 (read-only): find address-register loads (movea.l #imm,An / lea (abs).l,An / pea (abs).l / move.l #imm,Dn)
of any address in [lo, hi] in a ROM image, i.e. base pointers that could reach other words through a displacement.
usage: sk2_bases.py <rom> <cpp> <lo hex> <hi hex>"""
import re
import sys

rom = open(sys.argv[1], "rb").read()
funcs = sorted({(int(m.group(2), 16), m.group(1)) for m in
                (re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", l) for l in open(sys.argv[2], errors="replace")) if m})
lo, hi = int(sys.argv[3], 16), int(sys.argv[4], 16)
for i in range(2, len(rom) - 4, 2):
    v = int.from_bytes(rom[i:i + 4], "big")
    if not lo <= v <= hi:
        continue
    op = int.from_bytes(rom[i - 2:i], "big")
    kind = None
    if (op & 0xf1ff) == 0x207c:
        kind = "movea.l #imm,a%d" % ((op >> 9) & 7)
    elif (op & 0xf1ff) == 0x41f9:
        kind = "lea (abs).l,a%d" % ((op >> 9) & 7)
    elif op == 0x4879:
        kind = "pea (abs).l"
    elif (op & 0xf1ff) == 0x203c:
        kind = "move.l #imm,d%d" % ((op >> 9) & 7)
    elif op == 0x2f3c:
        kind = "move.l #imm,-(sp)"
    if kind:
        f = [x for x in funcs if x[0] <= i]
        fn = "%s@0x%x" % (f[-1][1], f[-1][0]) if f else "?"
        print("0x%06x at 0x%05x %-20s next: %s  %s" % (v, i - 2, kind, rom[i + 4:i + 16].hex(" "), fn))
