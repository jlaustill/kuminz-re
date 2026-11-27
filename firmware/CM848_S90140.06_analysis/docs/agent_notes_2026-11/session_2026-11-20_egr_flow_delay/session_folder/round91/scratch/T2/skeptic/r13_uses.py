#!/usr/bin/env python3
"""List CM848 D-form loads/stores through r13 or r2 (small data area check, skeptic T2)."""
import struct

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
NAMES = {32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu',
         40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau', 44: 'sth', 45: 'sthu', 46: 'lmw', 47: 'stmw'}


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


for name, base in (('cm848_rom.bin', 0), ('cm848_flash2_live.bin', 0x500000)):
    d = open(FW + name, 'rb').read()
    for reg in (13,):
        out = []
        for o in range(0, len(d) - 4, 4):
            w = struct.unpack('>I', d[o:o + 4])[0]
            op = w >> 26
            ra = (w >> 16) & 31
            if 32 <= op <= 47 and ra == reg:
                out.append('%x %s r%d,%d(r%d)' % (base + o, NAMES[op], (w >> 21) & 31, s16(w & 0xffff), reg))
        print(name, 'r%d' % reg, out)
