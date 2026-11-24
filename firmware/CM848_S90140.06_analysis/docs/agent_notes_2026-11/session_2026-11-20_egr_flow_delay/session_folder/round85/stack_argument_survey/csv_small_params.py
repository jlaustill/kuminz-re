#!/usr/bin/env python3
"""For every CM550 function_definitions.csv function with a 1- or 2-byte
parameter: Ghidra's storage (slot 4-aligned, right-justified) vs the offsets the
ROM body actually reads and the layout its callers push."""
import csv
import json
import sys

H = __file__.rsplit('/', 1)[0] + '/'
CSV = sys.argv[1]
r = {int(k, 16): v for k, v in json.load(open(H + 'results.json')).items()}
alls = json.load(open(H + 'all_sites.json'))['sites']
SMALL = {'byte': 1, 'char': 1, 'uchar': 1, 'bool': 1, 'ushort': 2, 'short': 2, 'word': 2,
         'uint16_t': 2, 'int16_t': 2, 'uint8_t': 1}
funcs = {}
for row in csv.reader(open(CSV)):
    if not row or row[0].startswith('#') or row[0] == 'function_address':
        continue
    if len(row) < 5 or row[2] == 'return':
        continue
    a = int(row[0], 16)
    funcs.setdefault(a, {'name': row[1], 'params': []})['params'].append((int(row[2]), row[3], row[4]))


def size_of(t):
    t = t.strip()
    if t.endswith('*'):
        return 4
    if t in SMALL:
        return SMALL[t]
    if t in ('division_operand_t',):
        return 4
    return 4


layouts = {}
for s in alls:
    if s['via'] in ('walker', 'scan'):
        layouts.setdefault(s['callee'], set()).add(s['desc'])
for a in sorted(funcs):
    ps = sorted(funcs[a]['params'])
    if not any(p[2].strip() in SMALL for p in ps):
        continue
    off = 4
    ghidra = []
    for idx, name, t in ps:
        sz = size_of(t)
        slots = (sz + 3) // 4
        ghidra.append('%s %s@+%d/%d' % (t, name, off + slots * 4 - sz, sz))
        off += slots * 4
    v = r.get(a)
    reads = sorted({(x['offset'], x['width'], x['kind']) for x in v['arg_access']
                    if not x.get('retaddr') and x['width']}) if v else []
    print('0x%05x %s' % (a, funcs[a]['name']))
    print('    csv/ghidra: %s' % ', '.join(ghidra))
    print('    rom reads : %s' % (' '.join('%s%d@+%d' % (k, w, o) for o, w, k in reads) or 'none'))
    print('    callers   : %s' % (' || '.join(sorted(layouts.get(a, []))) or '(none found)'))
