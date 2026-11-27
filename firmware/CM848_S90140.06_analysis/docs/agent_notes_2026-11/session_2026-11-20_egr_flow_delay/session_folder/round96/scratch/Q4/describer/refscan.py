#!/usr/bin/env python3
"""List every code reference (jsr/jmp abs, bsr/bra/jsr pc-relative, 4-byte pointer) to each target in the CM550 ROM."""
import struct
import sys

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
rom = open(ROM, 'rb').read()
targets = [int(t, 16) for t in sys.argv[1:]]
found = {t: [] for t in targets}
for i in range(0, len(rom) - 6, 2):
    op = struct.unpack('>H', rom[i:i + 2])[0]
    if op in (0x4eb9, 0x4ef9):
        t = struct.unpack('>I', rom[i + 2:i + 6])[0]
        if t in found:
            found[t].append('%s %s' % (hex(i), 'jsr' if op == 0x4eb9 else 'jmp'))
    if op in (0x6100, 0x4eba, 0x6000, 0x4efa):
        d = struct.unpack('>h', rom[i + 2:i + 4])[0]
        t = i + 2 + d
        if t in found:
            found[t].append('%s %s.w' % (hex(i), {0x6100: 'bsr', 0x4eba: 'jsr pc', 0x6000: 'bra', 0x4efa: 'jmp pc'}[op]))
    elif (op & 0xff00) in (0x6100, 0x6000) and (op & 0xff) not in (0, 0xff):
        d = op & 0xff
        if d >= 0x80:
            d -= 0x100
        t = i + 2 + d
        if t in found:
            found[t].append('%s %s.s' % (hex(i), 'bsr' if (op & 0xff00) == 0x6100 else 'bra'))
for t in targets:
    pat = struct.pack('>I', t)
    ptrs = [hex(j) for j in range(0, len(rom) - 3) if rom[j:j + 4] == pat]
    print(hex(t), found[t], 'pointer bytes at', ptrs)
