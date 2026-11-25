"""Print the algorithm enable flags table words from CM550's RAM dump (0x803c92..) and EEPROM dump (0x188..),
and CM848's from its RAM dump (0x3fd59a..) when present. usage: dump_values.py <repo>"""
import os
import struct
import sys

repo = sys.argv[1]
F = os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware")
ram = open(os.path.join(F, "J90350.00.ram.bin"), "rb").read()
eep = open(os.path.join(F, "J90350.00.eeprom.bin"), "rb").read()
RAM_BASE = 0x800000
print("CM550 length word: RAM 0x%04x EEPROM 0x%04x" % (
    struct.unpack(">H", ram[0x803c92 - RAM_BASE:0x803c94 - RAM_BASE])[0], struct.unpack(">H", eep[0x188:0x18a])[0]))
for n in range(35):
    a = 0x803c94 + 2 * n
    r = struct.unpack(">H", ram[a - RAM_BASE:a - RAM_BASE + 2])[0]
    e = struct.unpack(">H", eep[0x18a + 2 * n:0x18c + 2 * n])[0]
    bits = [b for b in range(16) if r >> b & 1]
    print("word %2d 0x%x EEPROM 0x%03x: RAM 0x%04x EEPROM 0x%04x %s bits %s" % (
        n, a, 0x18a + 2 * n, r, e, "same" if r == e else "DIFFER", bits))
C = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
for cand in ("originals/cm848_ram.bin", "firmware/cm848_ram.bin"):
    p = os.path.join(C, cand)
    if os.path.exists(p):
        d = open(p, "rb").read()
        base = 0x3FA000
        print("CM848", cand, "length word 0x%04x" % struct.unpack(">H", d[0x3fd59a - base:0x3fd59c - base])[0])
        for n in (7, 8, 9, 10, 11, 12, 13, 14):
            a = 0x3fd59c + 2 * n
            print("  CM848 word %2d 0x%x: 0x%04x" % (n, a, struct.unpack(">H", d[a - base:a - base + 2])[0]))
        break
