#!/usr/bin/env python3
"""For each absolute-long reference to a DGFUIDEN word (0x806abc + 2k, k = 0..18), print the instruction
context and check whether the same bit of the system error status word 0x806000 + 2k is tested nearby."""
import struct

ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'
rom = open(ROM, 'rb').read()
for k in range(19):
    target = 0x806abc + 2 * k
    pat = struct.pack('>I', target)
    pos = 0
    while True:
        i = rom.find(pat, pos)
        if i < 0:
            break
        pos = i + 1
        if i % 2:
            continue
        op = struct.unpack('>H', rom[i - 2:i])[0]
        kind = '?'
        mask = None
        if op == 0x3039:  # move.w (abs).l,d0
            kind = 'move.w abs,d0'
            nxt = struct.unpack('>HH', rom[i + 4:i + 8])
            if nxt[0] == 0x0240:
                mask = nxt[1]
        elif (op & 0xf1ff) == 0x207c:
            kind = 'movea.l #abs,a%d' % ((op >> 9) & 7)
        partner = 0x806000 + 2 * k
        ppat = struct.pack('>HI', 0x3039, partner)
        j = rom.rfind(ppat, max(0, i - 0x30), i)
        pm = None
        if j >= 0:
            nxt = struct.unpack('>HH', rom[j + 6:j + 10])
            if nxt[0] == 0x0240:
                pm = nxt[1]
        print('word %2d 0x%06x ref @0x%05x %-20s mask=%s | SSERSS%02d 0x%06x read @%s mask=%s %s' % (
            k, target, i - 2, kind, ('0x%04x' % mask) if mask is not None else '-', k, partner,
            ('0x%05x' % j) if j >= 0 else '-', ('0x%04x' % pm) if pm is not None else '-',
            'SAME BIT' if (pm is not None and pm == mask) else ''))
