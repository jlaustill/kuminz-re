"""Place each global row in 0x805a1c-0x805efd inside the 10-byte fault count records."""
import csv
import sys

GLOBALS = ('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/'
           'CM550_J90350.00_analysis/output/global_variables.csv')
RAM = ('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/'
       'CM550_J90350.00_analysis/firmware/J90350.00.ram.bin')
CPP = ('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/'
       'CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp')
BASE, RECORD, COUNT = 0x805a1c, 10, 125
FIELDS = ['status_change_time'] * 4 + ['countdown_time'] * 4 + ['status', 'occurrence_count']

ram = open(RAM, 'rb').read()
cpp = open(CPP).read()
count = 0
for line in open(GLOBALS):
    parts = line.rstrip('\n').split(',', 3)
    try:
        address = int(parts[0], 16)
    except ValueError:
        continue
    if not BASE <= address < BASE + RECORD * COUNT:
        continue
    count += 1
    offset = address - BASE
    name = parts[1]
    references = cpp.count(name)
    value = ram[address - 0x800000:address - 0x800000 + 2].hex()
    print('0x%06x %-42s record %3d +%d %-22s refs %2d dump %s' % (
        address, name, offset // RECORD, offset % RECORD,
        FIELDS[offset % RECORD] + ('' if offset % RECORD in (0, 4, 8, 9) else ' (mid)'), references, value))
print(count, 'rows')
