"""Find where RAM 0x80654c-0x806ae1 (e2m block F: countdown times, fault code assignment, fault data records)
comes from: search the ROM for the same bytes."""
ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
rom = open(ROOT + 'J90350.00.rom.bin', 'rb').read()
ram = open(ROOT + 'J90350.00.ram.bin', 'rb').read()
for start, length in ((0x80654c, 32), (0x8067c4, 64), (0x80656c, 64)):
    needle = ram[start - 0x800000:start - 0x800000 + length]
    hits = []
    position = rom.find(needle)
    while position >= 0:
        hits.append(position)
        position = rom.find(needle, position + 1)
    print('RAM 0x%06x (%d bytes): ROM hits %s' % (start, length, [hex(h) for h in hits]))
    print('   ', needle.hex())
