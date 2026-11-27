#!/usr/bin/env python3
"""Census of every push in flow-reached code, and of what each call receives.

- every instruction writing -(sp): mnemonic / size counts; byte pushes listed
- per call (all 2266 walker calls): the arg bytes from the pushes (via shadow)
  classified by push unit sizes; word pushes preceded by a clr.w/ext.l that
  pairs into a long (a word padded to 4 bytes) are flagged
"""
import json
import sys
from collections import Counter

H = __file__.rsplit('/', 1)[0] + '/'
sys.path.insert(0, H)
from m68k import decode  # noqa: E402

rom = open(sys.argv[1], 'rb').read()
r = {int(k, 16): v for k, v in json.load(open(H + 'results.json')).items()}
cov = set()
for v in r.values():
    cov.update(v['covered'])
push_kinds = Counter()
byte_pushes = []
for pc in sorted(cov):
    ins = decode(rom, pc)
    d = ins.dst
    if getattr(d, 'mode', None) == '-(An)' and d.reg == 7:
        key = ins.mn
        if ins.mn.startswith('move') and getattr(ins.src, 'mode', None) == '#':
            key += ' #imm'
        push_kinds[key] += 1
        if ins.size == 1:
            byte_pushes.append((pc, ins.hexbytes(), ins.text()))
    elif ins.mn == 'pea':
        push_kinds['pea'] += 1
print('pushes in flow-reached code by mnemonic:')
for k, n in push_kinds.most_common():
    print('  %5d %s' % (n, k))
print('byte pushes (move.b ...,-(sp) etc.): %d' % len(byte_pushes))
for b in byte_pushes:
    print('   %06x %s %s' % b)

# per call: unit sequence of the arguments actually read by the callee
alls = json.load(open(H + 'all_sites.json'))['sites']
frag = set(json.load(open(H + 'fragments.json')))
unit_sizes = Counter()
pairs = []
for s in alls:
    if s['via'] not in ('walker', 'scan') or s['callee'] in frag:
        continue
    for g in s['layout']:
        rec = g['rec']
        if rec is None:
            continue
        unit_sizes['%s %d-byte push (%s)' % ('pea' if rec['how'] == 'pea' else rec['how'], rec['slot'],
                                              rec['text'].split(' ')[0])] += 1
    # two adjacent 2-byte units where the higher one (pushed first) is clr.w: a
    # word zero-extended to a long by hand?
    lay = [g for g in s['layout'] if g['rec']]
    for a, b in zip(lay, lay[1:]):
        if a['rec']['slot'] == 2 and b['rec']['slot'] == 2 and b['rec']['text'].startswith('clr.w'):
            pairs.append((s['addr'], s['callee'], a['off'], a['rec']['text'], b['off'], b['rec']['text']))
print('argument units (slot sizes) over all calls whose callee reads its arguments:')
for k, n in unit_sizes.most_common():
    print('  %5d %s' % (n, k))
print('word push followed (higher address) by a clr.w push: %d (a hand-made zero-extended long would look like this)' % len(pairs))
for p in pairs[:12]:
    print('   call %06x -> 0x%x : +%d %s / +%d %s' % p)
