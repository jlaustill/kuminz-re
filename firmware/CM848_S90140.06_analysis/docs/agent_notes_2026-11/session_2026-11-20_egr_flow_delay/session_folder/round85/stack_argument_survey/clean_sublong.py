#!/usr/bin/env python3
"""Functions (not fragments) whose ROM body reads a sub-long argument but whose
.cpp shows no in_stack / partial token, with their .cpp signatures and the
layouts their callers push."""
import json
import re
import sys

H = __file__.rsplit('/', 1)[0] + '/'
CPP = sys.argv[1]
r = {int(k, 16): v for k, v in json.load(open(H + 'results.json')).items()}
aff = {f['address'] for f in json.load(open(H + 'affected.json'))}
alls = json.load(open(H + 'all_sites.json'))['sites']
frag = set(json.load(open(H + 'fragments.json')))
lines = open(CPP).read().split('\n')
sig = {}
cur = None
for i, l in enumerate(lines):
    m = re.match(r'^// Function: (\S+) @ 0x([0-9a-f]+)', l)
    if m:
        cur = int(m.group(2), 16)
        continue
    if cur is not None and cur not in sig and l and not l.startswith('//') \
            and not l.startswith('/*') and '(' in l and not l.startswith(' '):
        s = l
        j = i
        while s.count('(') > s.count(')'):
            j += 1
            s += ' ' + lines[j].strip()
        sig[cur] = s
layouts = {}
for s in alls:
    if s['via'] in ('walker', 'scan'):
        layouts.setdefault(s['callee'], set()).add(s['desc'])
rows = []
for a, v in sorted(r.items()):
    if a in frag:
        continue
    reads = [x for x in v['arg_access'] if not x.get('retaddr')]
    sub = [x for x in reads if x['width'] and x['width'] < 4]
    if not sub or a in aff:
        continue
    rows.append((a, v['name'], sorted({(x['offset'], x['width'], x['kind']) for x in reads if x['width']}),
                 sig.get(a), layouts.get(a, set())))
print(len(rows), 'functions with sub-long argument reads and no in_stack / partial token')
for a, n, rs, s, lay in rows:
    print('0x%05x %-48s reads %s' % (a, n, ' '.join('%s%d@+%d' % (k, w, o) for o, w, k in rs)))
    print('        sig: %s' % s)
    print('        caller layouts: %s' % (' || '.join(sorted(lay)) if lay else '(no direct caller)'))
