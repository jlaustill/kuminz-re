#!/usr/bin/env python3
"""The 89-function table grouped by argument layout (unit sequence)."""
import json
import re
from collections import OrderedDict

H = __file__.rsplit('/', 1)[0] + '/'
t = json.load(open(H + 'classes.json'))['table']
GROUPS = OrderedDict([
    ('W4', 'one word at +4'),
    ('W4 W6', 'two words at +4, +6'),
    ('W4 W6 W8', 'three words at +4, +6, +8'),
    ('W4 W6 W8 W10', 'four words at +4..+10'),
    ('W4 L6', 'word at +4, long at +6'),
    ('L4 W8', 'long at +4, word at +8'),
    ('L4 L8 W12', 'long, long, word (+4, +8, +12)'),
    ('L4 L8 W12 W14', 'long, long, word, word (+4, +8, +12, +14)'),
    ('L4 L8 L12 W16', 'long, long, long, word (+4, +8, +12, +16)'),
    ('L4 W8 W10 W12', 'long, word, word, word (+4, +8, +10, +12)'),
    ('L4', 'one long at +4'),
    ('none', 'no argument read (not a callee-argument case)'),
])
CALLEE_ONLY = {0x16628: 'L4 W8 W10 W12', 0x2cf52: 'L4 W8', 0x2f4be: 'L4', 0x34f00: 'W4 L6'}


def key_of(e):
    if e['address'] in CALLEE_ONLY:
        return CALLEE_ONLY[e['address']]
    c = e['class']
    if c.startswith('no argument'):
        return 'none'
    units = re.findall(r'(word|long)@\+(\d+)', c)
    return ' '.join(('W' if u == 'word' else 'L') + o for u, o in units)


def short_reads(e):
    c = e['class']
    if e['address'] in CALLEE_ONLY:
        return 'callee only: ' + c.split(': ', 1)[1]
    if c.startswith('no argument'):
        return ''
    parts = re.findall(r'(word|long)@\+(\d+) \[([^\]]*)\]', c)
    out = []
    for u, o, r in parts:
        if r in (u,):
            continue
        out.append('+%s %s' % (o, r))
    return ('reads ' + ', '.join(out)) if out else 'reads as pushed'


groups = OrderedDict((k, []) for k in GROUPS)
for e in t:
    groups[key_of(e)].append(e)
for k, lst in groups.items():
    print('## %s (%d)' % (GROUPS[k], len(lst)))
    for e in lst:
        cpp = '; '.join(re.sub(r'\(\+(\w+),w(\w+)\)x(\d+)', r'@\1/\2 x\3', c) for c in e['cpp'])
        print('0x%05x %s | %s | sites %d%s | cpp %s' % (
            e['address'], e['name'], short_reads(e), e['n_sites'],
            (' (%d scan)' % e['n_scan']) if e['n_scan'] else '', cpp))
