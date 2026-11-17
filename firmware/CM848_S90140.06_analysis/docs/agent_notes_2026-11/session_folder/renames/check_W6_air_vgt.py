import csv
import json
import os
import re
import sys

ROOT = sys.argv[1]
RES = sys.argv[2]
B = ROOT + '/firmware/CM848_S90140.06_analysis/output/'
rows = [json.loads(l) for l in open(RES) if l.strip()]


def rd(name):
    with open(B + name, newline='') as f:
        return list(csv.reader(f))


gv = [r for r in rd('global_variables.csv')[1:] if len(r) >= 2 and r[0].startswith('0x')]
fr = [r for r in rd('function_renames.csv')[1:] if len(r) >= 2 and r[0].startswith('0x')]
ar = [r for r in rd('arrays.csv')[1:] if len(r) >= 2 and r[0].startswith('0x')]
names = {}
for r in gv + fr + ar:
    if r[1]:
        names.setdefault(r[1], []).append(r[0])

problems = []
seen_new = {}
seen_addr = {}
kinds = {}
toks = set()
for i, r in enumerate(rows):
    kinds[r['kind']] = kinds.get(r['kind'], 0) + 1
    k = r['kind']
    if k in ('function', 'global', 'new_global'):
        a = int(r['address'], 16)
        key = (k == 'function', a)
        if key in seen_addr:
            problems.append(('duplicate address', r['address'], i))
        seen_addr[key] = i
    n = r.get('new')
    if n:
        if n in names:
            problems.append(('new name exists', n, names[n]))
        if n in seen_new:
            problems.append(('new name duplicated', n))
        seen_new[n] = i
        if k == 'function':
            toks |= {t.lower() for t in re.findall(r'[A-Z]?[a-z0-9]+', n)}
            if not re.match(r'^cm848_[a-z][A-Za-z0-9]*$', n):
                problems.append(('function name shape', n))
        else:
            toks |= set(re.split(r'[_+]', n))
            if not re.match(r'^[a-z][a-z0-9_]*(\+2)?$', n):
                problems.append(('global name shape', n))
            a = int(r['address'], 16)
            if 'cal' in re.split(r'[_+]', n) and not (0x3fd482 <= a <= 0x3feec1):
                problems.append(('_cal outside the mirror', n, r['address']))
            if (0x3fd482 <= a <= 0x3feec1) and a in (0x3fd8cc, 0x3fd8ce, 0x3fd8d0, 0x3fdcea, 0x3fd7de) and not n.endswith('_cal'):
                problems.append(('missing _cal', n))
    if k == 'global':
        a = int(r['address'], 16)
        cur = [x[1] for x in gv if int(x[0], 16) == a]
        if r['old'] not in cur:
            problems.append(('old name mismatch', r['address'], r['old'], cur))
    if k == 'function':
        a = int(r['address'], 16)
        cur = [x[1] for x in fr if int(x[0], 16) == a]
        if r['old'] not in cur:
            problems.append(('old function mismatch', r['address'], r['old'], cur))
        if r.get('new') and not r.get('plate_comment'):
            problems.append(('no plate', r['address']))
        if r.get('new') and '(was ' not in r['plate_comment']:
            problems.append(('plate without (was)', r['address']))
    if k in ('function', 'global', 'new_global') and r.get('new') and 'code:' not in r.get('evidence', '') and k != 'function':
        problems.append(('evidence without code:', r['address']))
    if k == 'new_global':
        if not re.search(r'xref_addr.py says (word|i16|byte|dword) \(\d+ reads? / \d+ writes?', r['evidence']):
            problems.append(('new_global evidence phrase', r['address']))

print('kinds', kinds)
print('problems', problems)
print('tokens', sorted(toks))
print('file bytes', os.path.getsize(RES))
print('max evidence', max(len(r.get('evidence', '')) for r in rows), 'max plate', max(len(r.get('plate_comment', '')) for r in rows))
for r in rows:
    if r['kind'] == 'note':
        print('NOTE', len(r['text']), r['text'][:80])
