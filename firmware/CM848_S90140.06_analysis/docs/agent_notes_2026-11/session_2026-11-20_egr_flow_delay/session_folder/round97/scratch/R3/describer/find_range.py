import sys
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin','rb').read()
lo = int(sys.argv[1],16); hi = int(sys.argv[2],16)
from collections import defaultdict
d = defaultdict(list)
for i in range(0, len(rom)-3, 2):
    v = int.from_bytes(rom[i:i+4],'big')
    if lo <= v <= hi:
        d[v].append(i)
for v in sorted(d):
    print(hex(v), ' '.join(hex(x) for x in d[v][:12]), '...' if len(d[v])>12 else '')
