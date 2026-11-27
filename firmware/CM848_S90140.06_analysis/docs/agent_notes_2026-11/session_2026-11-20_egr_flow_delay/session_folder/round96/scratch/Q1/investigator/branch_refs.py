#!/usr/bin/env python3
"""Raw scan of a CPU32 ROM image for PC-relative branches (Bcc / BRA / BSR with 8 / 16 / 32-bit
displacements), JMP / JSR (d16,PC), and LEA / PEA (d16,PC) whose target is one of the given addresses.
It is a raw scan (every even offset), so a hit can be data; a miss means no such encoding exists.

usage: branch_refs.py <rom.bin> <address hex> [...]
"""
import struct
import sys


def main():
    rom = open(sys.argv[1], 'rb').read()
    targets = {int(a, 16) for a in sys.argv[2:]}
    hits = {t: [] for t in targets}
    for pc in range(0, len(rom) - 6, 2):
        op = struct.unpack('>H', rom[pc:pc + 2])[0]
        if (op & 0xf000) == 0x6000:
            disp8 = op & 0xff
            if disp8 == 0:
                disp = struct.unpack('>h', rom[pc + 2:pc + 4])[0]
            elif disp8 == 0xff:
                disp = struct.unpack('>i', rom[pc + 2:pc + 6])[0]
            else:
                disp = disp8 - 256 if disp8 >= 128 else disp8
            target = pc + 2 + disp
            if target in targets:
                hits[target].append((pc, 'branch %04x' % op))
        # jsr (d16,pc) = 0x4eba, jmp (d16,pc) = 0x4efa, pea (d16,pc) = 0x487a, lea (d16,pc),An = 0x41fa | reg<<9
        if op in (0x4eba, 0x4efa, 0x487a) or (op & 0xf1ff) == 0x41fa:
            disp = struct.unpack('>h', rom[pc + 2:pc + 4])[0]
            target = pc + 2 + disp
            if target in targets:
                hits[target].append((pc, 'pc-relative %04x' % op))
        # dbcc dn,label = 0x50c8 | cc<<8 | reg
        if (op & 0xf0f8) == 0x50c8:
            disp = struct.unpack('>h', rom[pc + 2:pc + 4])[0]
            target = pc + 2 + disp
            if target in targets:
                hits[target].append((pc, 'dbcc %04x' % op))
    for target in sorted(hits):
        print('== %#x' % target)
        for pc, kind in hits[target]:
            print('   %#07x %s' % (pc, kind))


if __name__ == '__main__':
    main()
