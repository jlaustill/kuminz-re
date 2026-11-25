"""Judge L3: every 4-byte big-endian value inside [lo, hi) at any even ROM offset (absolute references, immediates,
table data), with the two opcode words before it, for the CM550 ROM.
usage: range_refs.py <0xLO> <0xHI_exclusive> [more pairs]"""
import struct
import sys

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/"
           "firmware/J90350.00.rom.bin", "rb").read()
args = sys.argv[1:]
for lo, hi in zip(args[0::2], args[1::2]):
    lo, hi = int(lo, 16), int(hi, 16)
    print("== [0x%x, 0x%x)" % (lo, hi))
    for i in range(0, len(rom) - 4, 2):
        v = struct.unpack_from(">I", rom, i)[0]
        if lo <= v < hi:
            print("  @0x%x value 0x%x (+0x%x) prev %s" % (i, v, v - lo, rom[max(0, i - 4):i].hex(" ")))
