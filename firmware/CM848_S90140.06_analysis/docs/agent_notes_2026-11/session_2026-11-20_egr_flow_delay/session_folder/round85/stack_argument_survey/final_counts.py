#!/usr/bin/env python3
"""Deduplicated totals, misaligned long reads, sp-merge review for the 89."""
import json
from collections import Counter

H = __file__.rsplit('/', 1)[0] + '/'
results = {int(k, 16): v for k, v in json.load(open(H + 'results.json')).items()}
alls = json.load(open(H + 'all_sites.json'))['sites']
frag = set(json.load(open(H + 'fragments.json')))
aff = {f['address']: f for f in json.load(open(H + 'affected.json'))}

uniq_calls = {c['addr'] for v in results.values() for c in v['calls']}
resolved = {c['addr'] for v in results.values() for c in v['calls'] if c['target'] is not None}
via_reg = {c['addr'] for v in results.values() for c in v['calls'] if c.get('via_register')}
print('functions walked: %d (%d .cpp entries + %d extra call targets); fragments: %d' % (
    len(results), sum(1 for v in results.values() if v.get('cpp_entry')),
    sum(1 for v in results.values() if not v.get('cpp_entry')), len(frag)))
print('unique call instructions reached: %d, target known: %d (via a constant address register: %d)' % (
    len(uniq_calls), len(resolved), len(via_reg)))
sites = [s for s in alls if s['via'] in ('walker', 'scan') and s['callee'] not in frag]
print('call sites to callees that read arguments (dedup, fragments out): %d  (walker %d, scan-only %d), callees %d' % (
    len(sites), sum(1 for s in sites if s['via'] == 'walker'), sum(1 for s in sites if s['via'] == 'scan'),
    len({s['callee'] for s in sites})))
# misaligned longs
mis = Counter()
for a, v in results.items():
    if a in frag:
        continue
    for x in v['arg_access']:
        if x.get('retaddr') or x['width'] != 4:
            continue
        if x['offset'] % 4 == 2:
            mis[(a, v['name'], x['offset'])] += 1
print('functions reading a long argument at an offset = 2 mod 4: %d' % len({k[0] for k in mis}))
for (a, n, o), c in sorted(mis.items()):
    print('   0x%05x %-44s long @+%d' % (a, n, o))
# sp-merge among the affected
print('sp-merge in the 89:')
for a in sorted(aff):
    v = results[a]
    sm = [i for i in v['issues'] if i[0] == 'sp-merge']
    if not sm:
        continue
    reads = [x for x in v['arg_access'] if not x.get('retaddr')]
    hows = sorted({x['how'] for x in reads})
    first_merge = min(i[1] for i in sm)
    late_sp = [x for x in reads if x['how'] == 'sp' and x['addr'] > first_merge]
    print('   0x%05x %-40s merges at %s; reads via %s; sp-relative reads after the first merge: %s' % (
        a, v['name'], ','.join('%06x' % i[1] for i in sm[:4]), hows,
        [('%06x' % x['addr'], x['text']) for x in late_sp] or 'none'))
