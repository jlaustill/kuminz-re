import sys, re, bisect
cpp = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp'
lines = open(cpp, errors='replace').read().split('\n')
starts = []
for i, l in enumerate(lines):
    m = re.search(r'Function: (\S+)', l)
    if m:
        starts.append((i, l.strip()))
idx = [s[0] for s in starts]
for lab in sys.argv[1:]:
    pat = re.compile(r'\b' + re.escape(lab) + r'\b')
    print('=====', lab)
    for i, l in enumerate(lines):
        if pat.search(l):
            k = bisect.bisect_right(idx, i) - 1
            fn = starts[k][1] if k >= 0 else '?'
            print('%6d [%s] %s' % (i + 1, fn[:70], l.strip()[:220]))
