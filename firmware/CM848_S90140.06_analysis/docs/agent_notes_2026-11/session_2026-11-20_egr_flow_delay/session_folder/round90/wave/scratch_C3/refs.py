import re, sys
cpp = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp'
lines = open(cpp, encoding='utf-8', errors='replace').read().split('\n')
func_re = re.compile(r'// Function: (\S+) @ (0x[0-9a-fA-F]+)')
cur = None
starts = []
for i, l in enumerate(lines):
    m = func_re.search(l)
    if m:
        cur = (m.group(1), m.group(2), i + 1)
    starts.append(cur)
for name in sys.argv[1:]:
    pat = re.compile(r'(?<![A-Za-z0-9_])_?' + re.escape(name) + r'(?![A-Za-z0-9_])')
    print('=====', name)
    for i, l in enumerate(lines):
        if pat.search(l):
            f = starts[i]
            print('%6d  [%s @ %s]  %s' % (i + 1, f[0] if f else '-', f[1] if f else '-', l.strip()[:220]))
