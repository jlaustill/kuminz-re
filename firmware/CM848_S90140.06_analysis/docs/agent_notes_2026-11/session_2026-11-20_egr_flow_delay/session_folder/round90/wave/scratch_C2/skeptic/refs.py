import re, sys
cpp = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp'
names = sys.argv[1:]
lines = open(cpp, encoding='utf-8', errors='replace').read().split('\n')
func_at = []
cur = None
for i, l in enumerate(lines):
    m = re.match(r'\s*// Function: (\S+) @ (0x[0-9a-fA-F]+)', l)
    if m:
        cur = (m.group(1), m.group(2), i + 1)
    func_at.append(cur)
for n in names:
    pat = re.compile(r'(?<![A-Za-z0-9_])_*' + re.escape(n) + r'(?![A-Za-z0-9_])')
    print('=====', n)
    for i, l in enumerate(lines):
        if pat.search(l):
            f = func_at[i]
            print('  L%d [%s @ %s, L%d]: %s' % (i + 1, f[0] if f else '-', f[1] if f else '-', f[2] if f else 0, l.strip()[:200]))
