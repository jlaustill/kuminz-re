"""Judge L3: find PC-relative references to a target in the CM550 ROM (bsr.b/.w/.l, bra, jsr/jmp/lea/pea (d16,pc))
and 4-byte big-endian copies of the target in the RAM / extended RAM / EEPROM dumps.
usage: pcrel_scan.py <0xTARGET>"""
import struct
import sys

base = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
rom = open(base + "J90350.00.rom.bin", "rb").read()
t = int(sys.argv[1], 16)
hits = []
for pc in range(0, len(rom) - 6, 2):
    w = struct.unpack_from(">H", rom, pc)[0]
    if (w & 0xff00) in (0x6100, 0x6000):
        kind = "bsr" if (w & 0xff00) == 0x6100 else "bra"
        d8 = w & 0xff
        if d8 == 0:
            d = struct.unpack_from(">h", rom, pc + 2)[0]
            if pc + 2 + d == t:
                hits.append((pc, kind + ".w"))
        elif d8 == 0xff:
            d = struct.unpack_from(">i", rom, pc + 2)[0]
            if pc + 2 + d == t:
                hits.append((pc, kind + ".l"))
        else:
            d = d8 - 256 if d8 & 0x80 else d8
            if pc + 2 + d == t:
                hits.append((pc, kind + ".b"))
    if w in (0x4eba, 0x4efa, 0x487a) or (w & 0xf1ff) == 0x41fa:
        d = struct.unpack_from(">h", rom, pc + 2)[0]
        if pc + 2 + d == t:
            hits.append((pc, "0x%04x (d16,pc)" % w))
print("ROM pc-relative hits:", [(hex(p), k) for p, k in hits])
pat = t.to_bytes(4, "big")
for fn, off in (("J90350.00.ram.bin", 0x800000), ("J90350.00.extended_ram.bin", 0x809242),
                ("J90350.00.eeprom.bin", 0x1000000)):
    d = open(base + fn, "rb").read()
    i = d.find(pat)
    found = []
    while i != -1:
        found.append(hex(i + off))
        i = d.find(pat, i + 1)
    print(fn, "copies of target:", found)
