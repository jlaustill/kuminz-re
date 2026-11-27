#!/usr/bin/env python3
"""Find PC-relative bsr / jsr (d16,pc) / lea (d16,pc) references to the given CM550 targets (absolute references
are covered by abs_refs.py). Prints each even offset whose decoded target hits one of the addresses."""
import struct
import sys

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
rom = open(ROM, 'rb').read()
targets = {int(a, 16) for a in sys.argv[1:]}
for i in range(0, len(rom) - 6, 2):
    op = struct.unpack('>H', rom[i:i + 2])[0]
    # bsr.b / bsr.w / bsr.l
    if (op & 0xff00) == 0x6100:
        d8 = op & 0xff
        if d8 == 0:
            disp = struct.unpack('>h', rom[i + 2:i + 4])[0]
            t = i + 2 + disp
        elif d8 == 0xff:
            disp = struct.unpack('>i', rom[i + 2:i + 6])[0]
            t = i + 2 + disp
        else:
            disp = d8 - 256 if d8 & 0x80 else d8
            t = i + 2 + disp
        if t in targets:
            print('bsr at 0x%05x -> 0x%05x' % (i, t))
    # jsr (d16,pc) = 0x4eba ; lea (d16,pc),an = 0x41fa | an<<9 ; pea (d16,pc) = 0x487a
    if op == 0x4eba or op == 0x487a or (op & 0xf1ff) == 0x41fa:
        disp = struct.unpack('>h', rom[i + 2:i + 4])[0]
        t = i + 2 + disp
        if t in targets:
            print('pc-relative 0x%04x at 0x%05x -> 0x%05x' % (op, i, t))
