"""Scan the CM550 ROM / RAM / extended RAM / EEPROM dumps for big-endian 32-bit values in a range (pointers),
at every byte offset (the m68k needs even alignment for word / long data, but data can still sit at any byte)."""
import sys
BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
lo = int(sys.argv[1], 16)
hi = int(sys.argv[2], 16)
files = [('rom', 'J90350.00.rom.bin', 0), ('ram', 'J90350.00.ram.bin', 0x800000),
         ('extended_ram', 'J90350.00.extended_ram.bin', 0x809242), ('eeprom', 'J90350.00.eeprom.bin', 0x1000000)]
for label, name, base in files:
    d = open(BASE + name, 'rb').read()
    hits = []
    for i in range(len(d) - 3):
        v = int.from_bytes(d[i:i + 4], 'big')
        if lo <= v <= hi:
            hits.append((base + i, v))
    print(label, len(hits))
    for a, v in hits[:60]:
        print('   at 0x%06x (%s) value 0x%06x' % (a, 'even' if a % 2 == 0 else 'odd', v))
