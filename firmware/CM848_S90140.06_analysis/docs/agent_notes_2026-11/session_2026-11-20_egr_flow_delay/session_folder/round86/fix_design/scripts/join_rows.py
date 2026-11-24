#!/usr/bin/env python3
"""Join CM550 function_definitions.csv rows with the stack-argument survey.

For every function with parameter rows: the layout today's align-4 model gives,
the layout the packed rule gives from the SAME rows, and what the ROM shows
(survey class + callee reads). Read-only.
"""
import csv, json, sys

CSV = sys.argv[1]
SURVEY = sys.argv[2]   # classes.json

SIZES = {'uint8_t': 1, 'byte': 1, 'char': 1, 'bool': 1,
         'uint16_t': 2, 'word': 2, 'ushort': 2, 'short': 2,
         'int32_t': 4, 'uint32_t': 4, 'dword': 4, 'uint': 4, 'int': 4, 'float': 4,
         'uint64_t': 8, 'qword': 8, 'ulong': 8, 'long': 8, 'double': 8,
         'division_operand_t': 4, 'MEMORY_REGION_TYPE': 1}


def size_of(t):
    t = t.strip()
    if t.endswith('*'):
        return 4
    return SIZES.get(t, SIZES.get(t.lower()))


def align4(types):
    out = []
    off = 4
    for t in types:
        s = size_of(t)
        slots = (s + 3) // 4 * 4
        out.append((off + slots - s, s))
        off += slots
    return out


def packed(types):
    out = []
    off = 4
    for t in types:
        s = size_of(t)
        if s <= 2:
            out.append((off + 2 - s, s))
            off += 2
        else:
            out.append((off, s))
            off += (s + 1) // 2 * 2
    return out


rows = {}
with open(CSV, newline='') as f:
    for line in f:
        if line.startswith('#') or not line.strip():
            continue
        p = next(csv.reader([line]))
        if len(p) < 5 or not p[0].startswith('0x'):
            continue
        if p[2] == 'return':
            continue
        a = int(p[0], 16)
        rows.setdefault(a, {'name': p[1], 'params': {}})['params'][int(p[2])] = (p[3], p[4])

survey = {e['address']: e for e in json.load(open(SURVEY))['table']}
for a in sorted(rows):
    r = rows[a]
    idx = sorted(r['params'])
    types = [r['params'][i][1] for i in idx]
    if any(size_of(t) is None for t in types):
        print(f'0x{a:05x} {r["name"]}: unknown size in {types}')
        continue
    small = any(size_of(t) < 4 for t in types)
    s = survey.get(a)
    lay_a = ' '.join(f'{o}:{z}' for o, z in align4(types))
    lay_p = ' '.join(f'{o}:{z}' for o, z in packed(types))
    cls = s['class'] if s else '-'
    reads = ' '.join(sorted(s['rom_reads'])) if s else '-'
    mark = 'SMALL' if small else '     '
    print(f'0x{a:05x} {mark} {r["name"]}  types={types}')
    print(f'      align4[{lay_a}] packed[{lay_p}]')
    print(f'      survey: {cls} | reads {reads}')
