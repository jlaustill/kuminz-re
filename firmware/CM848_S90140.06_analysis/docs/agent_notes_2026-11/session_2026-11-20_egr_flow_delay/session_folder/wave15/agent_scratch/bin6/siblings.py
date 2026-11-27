import re, sys
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/'
rows = []
for line in open(OUT + 'global_variables.csv', errors='replace'):
    if line.startswith('0x'):
        p = line.rstrip('\n').split(',', 3) + ['']
        rows.append((p[0], p[1], p[2], p[3]))
pats = sys.argv[1:]
for pat in pats:
    print('=== ', pat)
    rx = re.compile(pat)
    for a, n, t, c in rows:
        if rx.search(n):
            print(' ', a, n, t, '|', c[:110])
