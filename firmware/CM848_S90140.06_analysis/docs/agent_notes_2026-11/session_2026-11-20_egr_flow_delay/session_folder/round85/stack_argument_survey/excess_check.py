#!/usr/bin/env python3
"""Check the bytes above each call's argument layout (what the callee reads).

For a site with a pop larger than its arguments, every byte between the layout
end and the pop must be a leftover of an earlier call (its push precedes a call
that comes before this one). For a site with no pop right after the call, the
pushes directly above the layout are checked the same way. A push made for
this call (no call between it and this call) that no callee reads, and that no
other call's layout uses, would be an unread trailing argument or padding.
"""
import json
from collections import Counter, defaultdict

H = __file__.rsplit('/', 1)[0] + '/'
results = {int(k, 16): v for k, v in json.load(open(H + 'results.json')).items()}
alls = json.load(open(H + 'all_sites.json'))['sites']
aff = {f['address'] for f in json.load(open(H + 'affected.json'))}
frag = set(json.load(open(H + 'fragments.json')))
call_addrs = sorted({c['addr'] for v in results.values() for c in v['calls']})
import bisect  # noqa: E402


def call_between(lo, hi):
    """Is there a call instruction with lo < addr < hi?"""
    i = bisect.bisect_right(call_addrs, lo)
    return i < len(call_addrs) and call_addrs[i] < hi


# which call layouts use which push record
used_by = defaultdict(set)
for s in alls:
    for g in s.get('layout', []):
        if g['rec']:
            used_by[g['rec']['addr']].add(s['addr'])

stats = Counter()
flags = []
for s in alls:
    if s['via'] not in ('walker', 'scan') or s['callee'] in frag:
        continue
    lay = [g for g in s['layout']]
    if not lay:
        continue
    end = max(g['off'] + g['len'] for g in lay)        # callee offset past the layout
    n = end - 4
    pop = s.get('pop')
    shadow = s.get('shadow', [])
    # bytes above the layout, by callee offset
    above = []
    for g in shadow:
        lo, hi = g['callee_offset'], g['callee_offset'] + g['len']
        if hi <= end:
            continue
        above.append((max(lo, end), hi, g['rec']))
    above.sort(key=lambda x: x[0])
    if pop is not None and pop > n:
        limit = 4 + pop
        kind = 'excess-pop'
    elif pop is None:
        limit = end + 16
        kind = 'no-pop'
    else:
        stats['pop == args or smaller'] += 1
        continue
    verdict = 'ok'
    for lo, hi, rec in above:
        if lo >= limit:
            break
        if rec is None:
            if kind == 'excess-pop':
                verdict = 'UNWRITTEN bytes +%d..+%d inside the pop' % (lo, min(hi, limit) - 1)
            break
        prologue = rec['addr'] in (s.get('caller_addr'), (s.get('caller_addr') or 0) + 4) and \
            rec['text'].startswith('move.l') and rec['text'].endswith(',-(sp)') and \
            rec['text'].split(' ')[1].split(',')[0] in ('d2', 'd3', 'd4', 'd5', 'd6', 'd7', 'a2', 'a3', 'a4', 'a5', 'a6')
        if rec['text'].startswith('move sr,'):
            prologue = True
        if rec['how'] in ('movem', 'link') or prologue:
            if kind == 'excess-pop':
                verdict = 'register save inside the pop (+%d)' % lo
            break
        if call_between(rec['addr'], s['addr']):
            continue   # leftover of an earlier call: fine
        others = used_by.get(rec['addr'], set()) - {s['addr']}
        if others:
            verdict = 'ok (nested: +%d belongs to call %s)' % (lo, ','.join('%06x' % o for o in sorted(others)))
            break
        if rec['how'] == 'store':
            continue   # a local in the caller's frame
        verdict = 'PUSHED FOR THIS CALL BUT NOT READ: +%d %s (%s)' % (lo, rec['bytes'], rec['text'])
        break
    stats['%s: %s' % (kind, verdict.split(':')[0] if verdict.startswith(('PUSHED', 'UNWRITTEN', 'register')) else verdict.split(' (')[0])] += 1
    if not verdict.startswith('ok'):
        flags.append((s['addr'], s['callee'], results.get(s['callee'], {}).get('name'), kind, pop, n, verdict,
                      s['callee'] in aff))
print(dict(stats))
for f in flags:
    print('call %06x -> 0x%x %s [%s pop=%s args=%d] %s%s' % (f[0], f[1], f[2], f[3], f[4], f[5], f[6],
                                                           '  (AFFECTED)' if f[7] else ''))
