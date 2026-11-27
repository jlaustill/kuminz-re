#!/usr/bin/env python3
"""For each CM550 function with parameter rows (or a given address list), print
what the ROM walker saw: the callee's argument reads (results.json arg_access) and
the layouts its call sites push (all_sites.json). Read-only.

usage: rows_vs_rom.py <function_definitions.csv> <survey dir> [0xADDR ...]
"""
import csv
import json
import sys
from collections import Counter

CSV, SURVEY = sys.argv[1], sys.argv[2]
extra = [int(a, 16) for a in sys.argv[3:]]

results = {int(k, 16): v for k, v in json.load(open(SURVEY + '/results.json')).items()}
sites = json.load(open(SURVEY + '/all_sites.json'))['sites']
by_callee = {}
for s in sites:
    by_callee.setdefault(s['callee'], []).append(s)

rows = {}
with open(CSV, newline='') as f:
    for line in f:
        if line.startswith('#') or not line.strip():
            continue
        p = next(csv.reader([line]))
        if len(p) < 5 or not p[0].startswith('0x'):
            continue
        a = int(p[0], 16)
        rows.setdefault(a, {'name': p[1], 'params': []})
        if p[2] != 'return':
            rows[a]['params'].append((int(p[2]), p[3], p[4]))

addrs = extra if extra else sorted(rows)
for a in addrs:
    r = results.get(a)
    name = rows.get(a, {}).get('name') or (r or {}).get('name', '?')
    params = sorted(rows.get(a, {}).get('params', []))
    print('0x%05x %s rows=%s' % (a, name, ', '.join('%d:%s %s' % (i, t, n) for i, n, t in params) or '-'))
    if not r:
        print('    (not walked)')
        continue
    acc = [x for x in r['arg_access'] if not x.get('retaddr')]
    c = Counter('%s+%d/%s' % (x['kind'], x['offset'], x['width']) for x in acc)
    print('    reads: ' + (' '.join('%s x%d' % kv for kv in sorted(c.items(), key=lambda kv: int(kv[0].split('+')[1].split('/')[0]))) or 'none'))
    ex = [x for x in acc][:6]
    for x in ex:
        print('      %s' % x.get('text', x))
    lays = Counter(s.get('desc') for s in by_callee.get(a, []))
    print('    call sites %d: %s' % (len(by_callee.get(a, [])), '; '.join('%s x%d' % kv for kv in lays.most_common(4))))
