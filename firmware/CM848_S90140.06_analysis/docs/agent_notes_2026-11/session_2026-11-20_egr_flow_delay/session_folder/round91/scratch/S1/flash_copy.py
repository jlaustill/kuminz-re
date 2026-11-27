"""Compare the fault count table in RAM with its two flash parameter block copies."""
ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
rom = open(ROOT + 'J90350.00.rom.bin', 'rb').read()
ram = open(ROOT + 'J90350.00.ram.bin', 'rb').read()
BASE, RECORD, COUNT = 0x805a1c, 10, 125
for block in (0x4004, 0x6004):
    flash = block + (BASE - 0x804f9a)
    print('flash block 0x%04x: table at flash 0x%05x' % (block, flash))
    differ = 0
    for index in range(COUNT + 1):
        ram_bytes = ram[BASE - 0x800000 + index * RECORD:BASE - 0x800000 + (index + 1) * RECORD]
        flash_bytes = rom[flash + index * RECORD:flash + (index + 1) * RECORD]
        nonzero = any(ram_bytes) or any(flash_bytes)
        if nonzero:
            print('  %3d ram %s %s %s %s | flash %s %s %s %s' % (
                index, ram_bytes[:4].hex(), ram_bytes[4:8].hex(), ram_bytes[8:9].hex(), ram_bytes[9:].hex(),
                flash_bytes[:4].hex(), flash_bytes[4:8].hex(), flash_bytes[8:9].hex(), flash_bytes[9:].hex()))
        if ram_bytes != flash_bytes:
            differ += 1
    print('  records that differ:', differ)
