import bisect
import sys

FUNCS = '/home/linux/.claude/jobs/374b0424/tmp/w15/r91/scratch/S1/funcs.txt'
ROM = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin'

funcs = []
for line in open(FUNCS):
    address, name = line.split(' ', 1)
    funcs.append((int(address, 16), name.strip()))
funcs.sort()
starts = [f[0] for f in funcs]

low = int(sys.argv[1], 16)
high = int(sys.argv[2], 16)
data = open(ROM, 'rb').read()
for offset in range(0, len(data) - 3, 2):
    value = int.from_bytes(data[offset:offset + 4], 'big')
    if low <= value <= high:
        index = bisect.bisect_right(starts, offset) - 1
        owner = funcs[index] if index >= 0 else (0, '?')
        print('%s at 0x%05x in %s @ 0x%05x' % (hex(value), offset, owner[1], owner[0]))
