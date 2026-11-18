import sys, re, bisect
CPP = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp'
starts = []
names = []
for i, l in enumerate(open(CPP, errors='replace'), 1):
    m = re.match(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)', l)
    if m:
        starts.append(i)
        names.append((m.group(1), m.group(2)))
for a in sys.argv[1:]:
    n = int(a)
    k = bisect.bisect_right(starts, n) - 1
    print(n, names[k][0], '@0x' + names[k][1], '(starts line %d)' % starts[k])
