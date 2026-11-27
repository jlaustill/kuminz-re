#!/usr/bin/env python3
"""Read CM550 dump values. Usage: peek.py ADDR WIDTH [COUNT]  (hex addr; width 1/2/4)
RAM 0x800000-0x8091C1 -> ram.bin at addr-0x800000; extended RAM from 0x8092C2 -> extended_ram.bin at addr-0x809242;
ROM < 0x40000; EEPROM 0x1000000+."""
import sys
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
a = int(sys.argv[1], 16)
w = int(sys.argv[2])
n = int(sys.argv[3]) if len(sys.argv) > 3 else 1
if a < 0x40000:
    f, off = 'J90350.00.rom.bin', a
elif 0x800000 <= a <= 0x8091c1:
    f, off = 'J90350.00.ram.bin', a - 0x800000
elif a >= 0x8092c2 and a < 0x810000:
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
    vals.append('%d(0x%0*x,s%d)' % (v, 2 * w, v, s))
print('%s @%x: %s' % (f, a, ' '.join(vals)))
