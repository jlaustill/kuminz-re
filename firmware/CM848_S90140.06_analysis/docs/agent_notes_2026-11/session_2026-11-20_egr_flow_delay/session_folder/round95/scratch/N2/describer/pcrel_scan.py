"""Scan the CM550 ROM for PC-relative calls / address loads that reach a target (bsr.b/.w/.l, jsr/lea/pea (d16,pc)).
usage: pcrel_scan.py <target hex>"""
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
target = int(sys.argv[1], 16)
for pc in range(0, len(rom) - 4, 2):
    op = struct.unpack_from(">H", rom, pc)[0]
    # bsr
    if (op & 0xFF00) == 0x6100:
        d8 = op & 0xFF
        if d8 == 0:
            d16 = struct.unpack_from(">h", rom, pc + 2)[0]
            if pc + 2 + d16 == target:
                print("bsr.w at 0x%x" % pc)
        elif d8 == 0xFF:
            d32 = struct.unpack_from(">i", rom, pc + 2)[0]
            if pc + 2 + d32 == target:
                print("bsr.l at 0x%x" % pc)
        else:
            if d8 & 0x80:
                d8 -= 0x100
            if pc + 2 + d8 == target:
                print("bsr.s at 0x%x" % pc)
    # jsr (d16,pc) = 4eba ; lea (d16,pc),an = 41fa|(n<<9) ; pea (d16,pc) = 487a
    if op == 0x4EBA or op == 0x487A or (op & 0xF1FF) == 0x41FA:
        d16 = struct.unpack_from(">h", rom, pc + 2)[0]
        if pc + 2 + d16 == target:
            print("op %04x (pc-relative) at 0x%x" % (op, pc))
