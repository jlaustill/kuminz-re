"""Check the RAM dump's address mapping: known strings at the start, and rows above the suspected gap at 0x40c200-0x40c27f."""
ORIG = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/'
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/'
ram = open(ORIG + 'cm848_ram.bin', 'rb').read()
eeprom = open(ORIG + 'cm848_eeprom.bin', 'rb').read()
print('ram file', hex(len(ram)), 'ends at', hex(0x3FA000 + len(ram)))
# EEPROM mirror at 0x3fd482 + offset: compare the EEPROM image with the dump at the mirror, offset 0x130 is the calibration version
for off in (0x130, 0x46, 0x217):
    a = 0x3fd482 + off
    print(hex(off), ram[a - 0x3FA000:a - 0x3FA000 + 12], eeprom[off:off + 12])
# rows above 0x40c280
rows = []
for line in open(OUT + 'global_variables.csv', errors='replace'):
    if line.startswith('0x'):
        p = line.split(',', 3)
        a = int(p[0], 16)
        if 0x40c280 <= a < 0x440000:
            rows.append((a, p[1], p[2]))
rows.sort()
print(len(rows), 'rows at or above 0x40c280')
for a, name, typ in rows[:40]:
    w = {'byte': 1, 'word': 2, 'i16': 2, 'dword': 4, 'pointer': 4}.get(typ, 2)
    here = int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + w], 'big')
    shifted = int.from_bytes(ram[a - 0x80 - 0x3FA000:a - 0x80 - 0x3FA000 + w], 'big')
    print(hex(a), name, typ, 'dump at a:', hex(here), '| dump at a-0x80:', hex(shifted))
