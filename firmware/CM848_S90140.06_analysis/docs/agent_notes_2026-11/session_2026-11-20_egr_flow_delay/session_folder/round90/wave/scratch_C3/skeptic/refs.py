import sys, re
cpp = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp'
lines = open(cpp, encoding='utf-8', errors='replace').read().split('\n')
funcs = []
for i, l in enumerate(lines):
    m = re.match(r'// Function: (\S+) @ (0x[0-9a-fA-F]+)', l)
    if m:
        funcs.append((i, m.group(1), m.group(2)))
def func_of(i):
    best = None
    for f in funcs:
        if f[0] <= i:
            best = f
        else:
            break
    return best
for lab in sys.argv[1:]:
    pat = re.compile(r'(?<![A-Za-z0-9_])_?' + re.escape(lab) + r'(?![A-Za-z0-9_])')
    hits = {}
    for i, l in enumerate(lines):
        if pat.search(l):
            f = func_of(i)
            key = f[1] + ' @ ' + f[2] if f else 'header'
            hits.setdefault(key, []).append((i + 1, l.strip()))
    print('#### ' + lab + ': ' + str(sum(len(v) for v in hits.values())) + ' hits in ' + str(len(hits)) + ' functions')
    for k, v in hits.items():
        print('  ' + k)
        for ln, t in v:
            print('    %d: %s' % (ln, t[:200]))
