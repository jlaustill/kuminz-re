#!/usr/bin/env python3
"""Pop corroboration: compare the bytes a call's arguments occupy (from the
pushes the callee reads) with what the instruction after the call releases."""
import json
from collections import Counter

H = __file__.rsplit('/', 1)[0] + '/'
for label, fn, key in (('affected', 'survey.json', None), ('all', 'all_sites.json', 'sites')):
    data = json.load(open(H + fn))
    sites = []
    if key is None:
        for f in data:
            sites.extend(f['sites'])
    else:
        sites = data[key]
    c = Counter()
    smaller = []
    for s in sites:
        if s['via'] not in ('walker', 'scan'):
            continue
        n = sum(g['len'] for g in s.get('layout', []) if g['rec'])
        p = s.get('pop')
        if p is None:
            c['no pop right after the call (deferred to a later pop / unlk)'] += 1
        elif p == n:
            c['pop == argument bytes'] += 1
        elif p > n:
            c['pop > argument bytes (one pop for several calls)'] += 1
        else:
            c['pop < argument bytes'] += 1
            smaller.append((s['addr'], p, n, s.get('desc')))
    print(label, dict(c))
    for x in smaller[:10]:
        print('   pop<args: call %06x pop %s args %s %s' % x)
