#!/usr/bin/env python3
"""Which functions will change only because a callee's prototype changes.

1. Class A row functions (4-byte rows only) that call a wave 0 / wave 1 callee - their bodies
   change for a correct build, so the "must not change" control has to exclude them.
2. The functions with local_variables.csv rows that call a wave 0 / wave 1 callee - their
   auto-named temporaries may renumber.
Callers come from the survey walker (all_sites.json); jsr (An) through a constant register is
resolved there. Read-only. usage: caller_hazards.py <survey dir> <local_variables.csv>
"""
import csv
import json
import sys
from collections import defaultdict

SURVEY, LOCALS = sys.argv[1], sys.argv[2]

WAVE0 = [0xb6e8, 0xfaa6, 0x10e16, 0x142a8, 0x142d4, 0x144bc, 0x14720, 0x1645e, 0x1651e, 0x16628,
         0x18968, 0x1c016, 0x1c5e8, 0x1cb76, 0x1e056, 0x1e086, 0x1e5f0, 0x1ec3c, 0x1edae, 0x20890,
         0x2f4be, 0x32244, 0x32b38, 0x3460e, 0x34e9a, 0x34f00, 0x34f8a]
SWITCH_ONLY = [0x3792, 0x16c3c, 0x18f86, 0x1bfa2, 0x34bf8]
WAVE1 = [0x3870, 0x26a64, 0x34bba]
CLASS_A = [0x3640, 0x104e8, 0x10520, 0x18c1c, 0x1bfde, 0x1c484, 0x1e02a, 0x206a8, 0x2148a, 0x217de,
           0x21826, 0x21982, 0x2238e, 0x22956, 0x22b50, 0x22d8e, 0x22de2, 0x22e5e, 0x2eea2, 0x2ef4a,
           0x2fbd8, 0x2fcdc, 0x34de0, 0x35064, 0x35076, 0x35088]
changed = set(WAVE0) | set(SWITCH_ONLY) | set(WAVE1)

results = {int(k, 16): v for k, v in json.load(open(SURVEY + '/results.json')).items()}
names = {a: v.get('name', hex(a)) for a, v in results.items()}
calls_by_caller = defaultdict(set)
for faddr, v in results.items():
    for c in v['calls']:
        if c['target'] is not None:
            calls_by_caller[faddr].add(c['target'])

local_fns = set()
with open(LOCALS, newline='') as f:
    for line in f:
        if line.startswith('#') or not line.strip():
            continue
        p = next(csv.reader([line]))
        if p and p[0].startswith('0x'):
            local_fns.add(int(p[0], 16))


def report(title, fns):
    print(title)
    for a in sorted(fns):
        hits = sorted(t for t in calls_by_caller.get(a, ()) if t in changed)
        flag = 'CHANGES' if hits else 'quiet'
        print('  0x%05x %-44s %s %s' % (a, names.get(a, '?'), flag,
                                         ', '.join('0x%x %s' % (t, names.get(t, '?')) for t in hits)))


report('class A row functions (4-byte rows only):', CLASS_A)
report('functions with local_variables.csv rows:', local_fns)
