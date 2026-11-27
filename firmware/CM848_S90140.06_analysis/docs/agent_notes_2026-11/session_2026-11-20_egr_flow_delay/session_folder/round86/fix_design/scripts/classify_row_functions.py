#!/usr/bin/env python3
"""Classify every CM550 function with parameter rows for the packed-layout switch.

A = only 4-byte parameters and the rows match the ROM: storage unchanged -> output must not change
B = has a 1-/2-byte parameter and the packed offsets of the CURRENT rows match the ROM: the switch alone fixes it
C = the rows disagree with the ROM reads (need a correction in the same commit)
For every row, print its align-4 offset and its packed offset (a moved name is a re-index candidate).
Read-only. usage: classify_row_functions.py <function_definitions.csv> <survey dir>
"""
import csv
import json
import sys

CSV, SURVEY = sys.argv[1], sys.argv[2]
results = {int(k, 16): v for k, v in json.load(open(SURVEY + '/results.json')).items()}

SIZES = {'uint8_t': 1, 'byte': 1, 'char': 1, 'bool': 1,
         'uint16_t': 2, 'word': 2, 'ushort': 2, 'short': 2,
         'int32_t': 4, 'uint32_t': 4, 'dword': 4, 'uint': 4, 'int': 4, 'float': 4,
         'division_operand_t': 4}


def size_of(t):
    t = t.strip()
    return 4 if t.endswith('*') else SIZES.get(t, SIZES.get(t.lower()))


def place(sizes, slot):
    out, nxt = [], 4
    for s in sizes:
        space = (s + slot - 1) // slot * slot
        out.append(nxt + space - s)
        nxt += space
    return out


rows = {}
with open(CSV, newline='') as f:
    for line in f:
        if line.startswith('#') or not line.strip():
            continue
        p = next(csv.reader([line]))
        if len(p) < 5 or not p[0].startswith('0x') or p[2] == 'return':
            continue
        rows.setdefault(int(p[0], 16), {'name': p[1], 'p': {}})['p'][int(p[2])] = (p[3], p[4])

cls = {'A': [], 'B': [], 'C': []}
for a in sorted(rows):
    r = rows[a]
    idx = sorted(r['p'])
    names = [r['p'][i][0] for i in idx]
    sizes = [size_of(r['p'][i][1]) for i in idx]
    packed = place(sizes, 2)
    old = place(sizes, 4)
    reads = set()
    for x in results.get(a, {}).get('arg_access', []):
        if x.get('retaddr'):
            continue
        reads.add((x['offset'], x['width']))
    want = {(o, s) for o, s in zip(packed, sizes)}
    # a row matches when each declared (offset,width) is read as such, and every read lies in a row
    covered = all(any(o <= ro and ro + (rw or 1) <= o + s for o, s in zip(packed, sizes)) for ro, rw in reads)
    exact = all((o, s) in reads for o, s in zip(packed, sizes))
    small = any(s < 4 for s in sizes)
    if covered and exact:
        c = 'B' if small else 'A'
    else:
        c = 'C'
    cls[c].append(a)
    moved = ['%s %d->%d' % (n, o1, o2) for n, o1, o2 in zip(names, old, packed) if o1 != o2]
    print('%s 0x%05x %-36s rows %s | ROM reads %s%s' % (
        c, a, r['name'], ' '.join('%s@%d/%d' % (n, o, s) for n, o, s in zip(names, packed, sizes)),
        ' '.join('+%d/%s' % rw for rw in sorted(reads, key=lambda t: (t[0], t[1] or 0))) or '-',
        ('  moved: ' + ', '.join(moved)) if moved else ''))
print({k: len(v) for k, v in cls.items()})
