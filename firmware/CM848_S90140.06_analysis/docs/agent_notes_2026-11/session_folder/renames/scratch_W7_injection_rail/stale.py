import csv
import re
import sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
names = set()
rows = []
for fn in ('global_variables.csv', 'function_renames.csv'):
    for i, line in enumerate(open(OUT + fn), 1):
        if not line.startswith('0x'):
            continue
        parts = line.rstrip('\n').split(',', 3 if fn == 'global_variables.csv' else 2)
        names.add(parts[1].split('.')[0])
        names.add(parts[1])
        rows.append((fn, i, parts))
for r in csv.reader(open(OUT + 'structure_definitions.csv')):
    if r and not r[0].startswith('#') and len(r) > 2:
        names.add(r[0])
        names.add(r[2])
for fn in ('enums.csv', 'arrays.csv', 'constants.csv'):
    try:
        for r in csv.reader(open(OUT + fn)):
            for c in r[:3]:
                names.add(c)
    except FileNotFoundError:
        pass
pat = re.compile(sys.argv[1] if len(sys.argv) > 1 else r'(?:torque_[a-z0-9_]+|cm848_[A-Za-z0-9]*Torque[A-Za-z0-9]*|[a-z0-9_]*protection_torque[a-z0-9_]*)')
hits = {}
for fn, i, parts in rows:
    comment = parts[-1] if len(parts) > 2 else ''
    # drop the "(was ...)" marker
    comment = re.sub(r'\(was [^)]*\)', '', comment)
    for t in set(pat.findall(comment)):
        if t not in names:
            hits.setdefault(t, []).append('%s:%d(%s)' % (fn.split('_')[0], i, parts[1][:36]))
for t, w in sorted(hits.items()):
    print('%-48s %s' % (t, ' '.join(w[:5])))
print('distinct stale tokens', len(hits))
