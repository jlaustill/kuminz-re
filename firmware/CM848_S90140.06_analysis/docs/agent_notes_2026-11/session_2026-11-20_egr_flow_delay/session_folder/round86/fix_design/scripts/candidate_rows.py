#!/usr/bin/env python3
"""Candidate function_definitions.csv rows for the survey's affected CM550 functions
that have no parameter rows yet, typed from what each callee reads (classes.json).

Type per slot: a word slot read as a word -> ushort, read only as its low byte -> byte;
a long -> dword (pointer use is for the reviewer to decide). Names are left as
'TBD_<offset>' on purpose. Ranked by call-site count. Read-only.

usage: candidate_rows.py <function_definitions.csv> <classes.json>
"""
import csv
import json
import re
import sys

CSV, CLASSES = sys.argv[1], sys.argv[2]

have_rows = set()
with open(CSV, newline='') as f:
    for line in f:
        if line.startswith('#') or not line.strip():
            continue
        p = next(csv.reader([line]))
        if len(p) >= 3 and p[0].startswith('0x') and p[2] != 'return':
            have_rows.add(int(p[0], 16))

SLOT = re.compile(r'(word|long)@\+(\d+) \[([^\]]*)\]')
out = []
for e in json.load(open(CLASSES))['table']:
    a = e['address']
    if a in have_rows:
        continue
    slots = SLOT.findall(e['class'])
    if not slots:
        out.append((e['n_sites'], a, e['name'], None, e['class']))
        continue
    rows = []
    for kind, off, how in slots:
        if kind == 'long':
            t = 'dword'
        elif how.startswith('low byte'):
            t = 'byte'
        else:
            t = 'ushort'
        rows.append((int(off), t, how))
    out.append((e['n_sites'], a, e['name'], rows, e['class']))

out.sort(key=lambda r: (-r[0], r[1]))
for n, a, name, rows, cls in out:
    if rows is None:
        print('# 0x%05x %s: no slot layout (%s)' % (a, name, cls))
        continue
    print('# 0x%05x %s - %d call site(s); %s' % (a, name, n, cls))
    for i, (off, t, how) in enumerate(rows):
        print('0x%08x,%s,%d,TBD_%d,%s,+%d (%s)' % (a, name, i, off, t, off, how))
