#!/usr/bin/env python3
"""Classify argument layouts: per affected function and over every call site.

Reads survey.json / all_sites.json / results.json; writes classes.json and
prints the tables used in the report.
"""
import json
import sys
from collections import Counter, defaultdict

HERE = __file__.rsplit('/', 1)[0]
rep = json.load(open(HERE + '/survey.json'))
alls = json.load(open(HERE + '/all_sites.json'))['sites']
results = {int(k, 16): v for k, v in json.load(open(HERE + '/results.json')).items()}
names = {k: v['name'] for k, v in results.items()}


def unit_kind(rec):
    if rec is None:
        return None
    t = rec['text'].split(' ')[0]
    if rec['how'] == 'pea':
        return 'L'
    if rec['how'] in ('movem', 'link'):
        return 'X'
    size = rec['slot']
    if t.endswith('.b') and rec['how'] == 'push':
        return 'B'   # move.b -(sp): data byte at the lower address, pad above
    if size == 2:
        return 'W'
    if size == 4:
        return 'L'
    return '?%d' % size


def units_of(site):
    """[(callee_offset, slot_size, kind, rec)] for whole records inside the layout."""
    out = []
    for g in site.get('layout', []):
        rec = g['rec']
        k = unit_kind(rec)
        if rec is None:
            out.append((g['off'], g['len'], 'unwritten', None))
            continue
        if g['first'] != 0 or g['len'] != rec['slot']:
            out.append((g['off'], g['len'], k + '(part %d-%d of %d)' % (g['first'], g['first'] + g['len'] - 1, rec['slot']), rec))
            continue
        out.append((g['off'], g['len'], k, rec))
    return out


def unit_str(units):
    return ' '.join('%s@+%d' % (k, o) for o, n, k, rec in units)


def read_parts(reads, o, n):
    """How the callee reads the unit [o, o+n)."""
    parts = set()
    for a in reads:
        ao, w, kind = a['offset'], a['width'], a['kind']
        if w is None:
            if o <= ao < o + n:
                parts.add('&addr@+%d' % ao)
            continue
        if ao + w <= o or ao >= o + n:
            continue
        rel = ao - o
        if rel == 0 and w == n:
            parts.add({1: 'byte', 2: 'word', 4: 'long'}.get(w, 'w%d' % w) + ('' if kind == 'r' else '(%s)' % kind))
        elif rel >= 0 and rel + w <= n:
            if n == 2 and w == 1:
                parts.add(('low byte' if rel == 1 else 'high byte') + ('' if kind == 'r' else '(%s)' % kind))
            elif n == 4 and w == 2:
                parts.add(('low word' if rel == 2 else 'high word') + ('' if kind == 'r' else '(%s)' % kind))
            elif n == 4 and w == 1:
                parts.add('byte %d of long' % rel + ('' if kind == 'r' else '(%s)' % kind))
            else:
                parts.add('w%d@%d' % (w, rel))
        else:
            parts.add('SPANS %d bytes at +%d' % (w, ao))
    return ', '.join(sorted(parts)) if parts else 'not read'


def callee_reads(addr):
    r = results.get(addr)
    return [a for a in r['arg_access'] if not a.get('retaddr')] if r else []


def callee_only_units(reads):
    """Layout guess from the callee alone: (offset, width) of each read."""
    return sorted({(a['offset'], a['width'], a['kind']) for a in reads if a['width']})


# ------------------------------------------------------------ affected table
table = []
class_count = Counter()
class_examples = defaultdict(list)
for f in rep:
    addr = f['address']
    reads = callee_reads(addr)
    sites = [s for s in f['sites'] if s['via'] in ('walker', 'scan')]
    layouts = Counter()
    per_site = []
    for s in sites:
        us = units_of(s)
        key = unit_str(us)
        layouts[key] += 1
        per_site.append((s, us, key))
    if not reads:
        cls = 'no argument read in the body (not a callee-argument case)'
        desc = cls
    elif not sites:
        cls = 'callee reads only (no direct caller in the dump): ' + \
            ', '.join('%s %d@+%d' % (k, w, o) for o, w, k in callee_only_units(reads))
        desc = cls
    else:
        # the dominant layout, annotated with the reads
        key = layouts.most_common(1)[0][0]
        s0, us0, _ = [p for p in per_site if p[2] == key][0]
        parts = []
        for o, n, k, rec in us0:
            parts.append('%s@+%d [%s]' % ({'W': 'word', 'L': 'long', 'B': 'byte(move.b)'}.get(k, k), o,
                                          read_parts(reads, o, n)))
        desc = '; '.join(parts)
        cls = desc
    class_count[cls] += 1
    class_examples[cls].append(addr)
    table.append({'address': addr, 'name': f['name'], 'signature': f['signature'],
                  'cpp': ['%s(+%s,w%s)x%s' % (r['token'], r['offset'], r['width'], r['count']) for r in f['cpp_refs']],
                  'rom_reads': f['rom_reads'], 'class': cls,
                  'layouts': dict(layouts), 'n_sites': len(sites),
                  'n_walker': sum(1 for s in sites if s['via'] == 'walker'),
                  'n_scan': sum(1 for s in sites if s['via'] == 'scan'),
                  'pops': dict(Counter(str(s['pop']) for s in sites)),
                  'issues': f['issues'],
                  'examples': [{'call': '%06x' % s['addr'], 'caller': s['caller'],
                                'pushes': ['%06x %s (%s)' % (rec['addr'], rec['bytes'], rec['text'])
                                           for o, n, k, rec in us if rec],
                                'call_bytes': s.get('call'), 'pop': s.get('pop_bytes')}
                               for s, us, key2 in per_site[:3]]})

json.dump({'table': table, 'class_count': class_count}, open(HERE + '/classes.json', 'w'), indent=1)

if '--table' in sys.argv:
    for t in table:
        print('0x%05x %-46s sites=%d(w%d/s%d) pops=%s' % (t['address'], t['name'], t['n_sites'], t['n_walker'], t['n_scan'], t['pops']))
        print('        cpp: %s' % '; '.join(t['cpp']))
        print('        rom: %s' % t['rom_reads'])
        print('        class: %s' % t['class'])
        if len(t['layouts']) > 1:
            print('        LAYOUT VARIANTS: %s' % t['layouts'])
        for e in t['examples'][:2]:
            print('        e.g. %s in %s: %s | %s | pop %s' % (e['call'], e['caller'], ' ; '.join(e['pushes']), e['call_bytes'], e['pop']))

if '--classes' in sys.argv:
    for cls, n in class_count.most_common():
        print('%3d  %s' % (n, cls))
        print('       %s' % ' '.join('0x%x' % a for a in class_examples[cls]))

# ------------------------------------------------------------ global padding tests
fragments = set(json.load(open(HERE + '/fragments.json')))

if '--global' in sys.argv:
    cat = Counter()
    cat_ex = defaultdict(list)
    for s in alls:
        if s['via'] not in ('walker', 'scan'):
            continue
        callee = s['callee']
        if callee in fragments:
            continue
        reads = callee_reads(callee)
        # map offset -> group
        for a in reads:
            if a['width'] is None:
                continue
            o, w = a['offset'], a['width']
            g = None
            for gg in s['layout']:
                if gg['off'] <= o < gg['off'] + gg['len']:
                    g = gg
                    break
            if g is None:
                cat['read outside the pushed layout'] += 1
                continue
            rec = g['rec']
            if rec is None:
                c = 'read of an unwritten byte (w%d @+%d)' % (w, o)
                cat[c] += 1
                cat_ex[c].append((s['addr'], callee))
                continue
            k = unit_kind(rec)
            start = g['off'] - g['first']
            rel = o - start
            slot = rec['slot']
            if rel + w > slot:
                c = 'read of %d bytes spans past one %d-byte push (%s)' % (w, slot, k)
            elif k == 'B':
                c = 'move.b push, %s read at +%d of slot' % ({1: 'byte', 2: 'word'}.get(w, w), rel)
            elif slot == w:
                c = 'natural: %d-byte read of a %d-byte push' % (w, slot)
            elif slot == 2 and w == 1:
                c = 'byte read at %s byte of a word push' % ('low (+1)' if rel == 1 else 'high (+0)')
            elif slot == 4 and w == 2:
                c = 'word read at the %s of a long push' % ('LOW half (+2) = padded word?' if rel == 2 else 'high half (+0)')
            elif slot == 4 and w == 1:
                c = 'byte read at +%d of a long push' % rel
            else:
                c = 'other (w%d rel %d slot %d)' % (w, rel, slot)
            cat[c] += 1
            cat_ex[c].append((s['addr'], callee, rec['bytes'], rec['text'], a['text']))
    for c, n in cat.most_common():
        print('%5d  %s' % (n, c))
        seen = set()
        shown = 0
        for e in cat_ex[c]:
            if e[1] in seen:
                continue
            seen.add(e[1])
            print('         call %06x -> %s(0x%x)  %s' % (e[0], names.get(e[1], '?'), e[1], ' | '.join(str(x) for x in e[2:])))
            shown += 1
            if shown >= 6:
                break
