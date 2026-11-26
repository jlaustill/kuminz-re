"""For each given CM550 address, list the e2m records (v64t6_s.e2m) whose storage [start, start + length) covers it.
Uses the parameter ID table decoder of firmware/scripts/e2m_block_addresses.py."""
import sys

sys.path.insert(0, '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts')
import e2m_block_addresses as e  # noqa: E402

rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/'
           'firmware/J90350.00.rom.bin', 'rb').read()
table = e.parse_cm550_table(rom)
e2m = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/e2m-analysis/originals/v64t6_s.e2m'
records = []
for line in open(e2m, errors='replace'):
    f = line.rstrip('\r\n').split(',')
    if len(f) < 8 or f[5].strip() not in e.STORAGE_TYPES:
        continue
    try:
        block, offset, length = int(f[2], 16), int(f[3], 16), int(f[7])
    except ValueError:
        continue
    if block not in table:
        continue
    start = e.cm550_ram_address(table[block]) + offset
    desc = line.split(';', 1)[1].strip() if ';' in line else ''
    records.append((start, length, f[0], f[2], f[3], f[5], desc[:70]))
for arg in sys.argv[1:]:
    a = int(arg, 16)
    hits = [r for r in records if r[0] <= a < r[0] + max(r[1], 1)]
    print(f'0x{a:x}: ' + ('; '.join(f'{r[2]} {r[3]}+{r[4]} type {r[5]} @0x{r[0]:x} len {r[1]} ({r[6]})' for r in hits) or 'no record'))
