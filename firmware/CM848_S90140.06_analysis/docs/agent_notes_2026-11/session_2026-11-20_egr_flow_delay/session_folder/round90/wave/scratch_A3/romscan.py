import sys
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin', 'rb').read()
for arg in sys.argv[1:]:
    a = int(arg, 16)
    pat = a.to_bytes(4, 'big')
    hits = []
    i = rom.find(pat)
    while i >= 0:
        hits.append(i)
        i = rom.find(pat, i + 1)
    print('%#010x: %d hits %s' % (a, len(hits), ' '.join('%#x(op %02x%02x)' % (h, rom[h - 2], rom[h - 1]) for h in hits[:20])))
