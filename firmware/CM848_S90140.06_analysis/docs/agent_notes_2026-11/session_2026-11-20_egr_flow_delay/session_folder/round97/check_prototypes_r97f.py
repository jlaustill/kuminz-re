"""Round 97 stage F: the judged prototypes of R5 / R6 - their types (known to CM550's CSVs or built in) and parameter
indexes (0..n-1, no gap: the CM550 stack layout needs every parameter row)."""
import collections
import csv
import json
import re

W = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97'
OUT = 'firmware/CM550_J90350.00_analysis/output'
BUILTIN = {"void", "byte", "char", "bool", "word", "short", "ushort", "dword", "int", "uint", "int32_t", "undefined4",
           "undefined2", "undefined", "pointer", "sword", "sdword", "uchar", "sbyte"}
known = set()
for r in csv.reader(open(f'{OUT}/enums.csv', newline='')):
    if r and r[0] and not r[0].startswith('#'):
        known.add(r[0])
for r in csv.reader(l for l in open(f'{OUT}/structure_definitions.csv', newline='') if not l.startswith('#')):
    if r and r[0] and r[0] != 'struct_name':
        known.add(r[0])
types = collections.Counter()
bad = []
for b in ('R5', 'R6'):
    d = json.load(open(f'{W}/batch_{b}.json'))
    vd = {int(str(x['address']), 16): x for x in d['verdict']['verdicts'] if x.get('kind') == 'prototype'}
    for p in d['proposal']['prototypes']:
        a = int(p['address'], 16)
        v = vd.get(a, {}).get('verdict')
        ts = [p['return_type']] + [q['type'] for q in p['params']]
        for t in ts:
            types[t] += 1
            base = re.sub(r"\s*\*+$", "", t.strip())
            if base not in BUILTIN and base not in known:
                bad.append((b, hex(a), t))
        idx = sorted(q['index'] for q in p['params'])
        if idx != list(range(len(idx))):
            bad.append((b, hex(a), f"indexes {idx}"))
        if v not in ('CONFIRMED', 'AMENDED'):
            bad.append((b, hex(a), f"verdict {v}"))
print(dict(types))
print('problems:', bad)
