"""Judge F1 run 2: for every 'move.w #N,(An)' / 'cmpi.w #N,(An)' in the CM550 ROM, find the nearest earlier
'movea.l #imm,An' (within 0x300 bytes) and print the address the register holds (a heuristic: read the hits that land
on a fueling state word). usage: reg_targets.py N [N ...]"""
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
FUELING_STATE_WORDS = {0x8000fe, 0x80a8f2, 0x80d330, 0x80d334, 0x80d33c, 0x80dc32, 0x80deca, 0x80ded0, 0x80ded4,
                       0x80d33a, 0x80a98e}


def w(o):
    return struct.unpack(">H", rom[o:o + 2])[0]


def l(o):
    return struct.unpack(">I", rom[o:o + 4])[0]


for arg in sys.argv[1:]:
    n = int(arg)
    print(f"===== {n}")
    for o in range(0, 0x40000 - 8, 2):
        op, imm = w(o), w(o + 2)
        if imm != n:
            continue
        reg = None
        if (op & 0xf1ff) == 0x30bc:
            reg, kind = (op >> 9) & 7, "move.w"
        elif (op & 0xfff8) == 0x0c50:
            reg, kind = op & 7, "cmpi.w"
        if reg is None:
            continue
        target = None
        for back in range(2, 0x300, 2):
            p = o - back
            if p < 0:
                break
            if w(p) == (0x207c | (reg << 9)):
                target = l(p + 2)
                break
        flag = "  <== FUELING_STATE word" if target in FUELING_STATE_WORDS else ""
        print(f"  0x{o:05x}: {kind} #{n},(a{reg})  a{reg} = {hex(target) if target is not None else '?'}{flag}")
