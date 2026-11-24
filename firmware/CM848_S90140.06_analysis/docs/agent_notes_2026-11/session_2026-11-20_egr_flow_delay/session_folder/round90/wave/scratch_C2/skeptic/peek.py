#!/usr/bin/env python3
"""Read CM550 dump values. Usage: peek.py ADDR WIDTH [COUNT]  (hex addr; width 1/2/4)"""
import sys
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
a = int(sys.argv[1], 16)
w = int(sys.argv[2])
n = int(sys.argv[3]) if len(sys.argv) > 3 else 1
if a < 0x40000:
    f, off = 'J90350.00.rom.bin', a
elif 0x800000 <= a <= 0x8091c1:
    f, off = 'J90350.00.ram.bin', a - 0x800000
elif 0x8092c2 <= a < 0x810000:
    f, off = 'J90350.00.extended_ram.bin', a - 0x809242
elif a >= 0x1000000:
    f, off = 'J90350.00.eeprom.bin', a - 0x1000000
else:
    sys.exit('uncertain region for %x' % a)
d = open(FW + f, 'rb').read()
vals = []
for k in range(n):
    b = d[off + k * w: off + (k + 1) * w]
    v = int.from_bytes(b, 'big')
    s = int.from_bytes(b, 'big', signed=True)
    vals.append('%d/0x%0*x/s%d' % (v, 2 * w, v, s))
print('%s @%x (file off %x, size %x): %s' % (f, a, off, len(d), ' '.join(vals)))
