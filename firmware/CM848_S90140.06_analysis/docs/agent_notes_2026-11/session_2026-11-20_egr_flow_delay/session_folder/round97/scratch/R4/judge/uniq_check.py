import csv, sys
from collections import Counter

frozen = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/'
g = list(csv.reader(open(frozen + 'global_variables.csv')))
f = list(csv.reader(open(frozen + 'function_renames.csv')))
s = list(csv.reader(open(frozen + 'structure_definitions.csv')))
names = {}
for r in g[1:]:
    if len(r) > 1:
        names.setdefault(r[1], []).append(('global', r[0]))
for r in f[1:]:
    if len(r) > 1:
        names.setdefault(r[1], []).append(('function', r[0]))
fields = {}
for r in s[1:]:
    if len(r) > 2:
        fields.setdefault(r[2], []).append((r[0], r[1]))
props = [l.strip() for l in open(sys.argv[1]) if l.strip()]
c = Counter(props)
for p in props:
    hit = names.get(p)
    extra = ''
    if c[p] > 1:
        extra += ' DUP-IN-PROPOSALS'
    if p in fields:
        extra += ' (also struct field ' + str(fields[p][:2]) + ')'
    print(f"{p}: {'USED ' + str(hit) if hit else 'free'}{extra}")
