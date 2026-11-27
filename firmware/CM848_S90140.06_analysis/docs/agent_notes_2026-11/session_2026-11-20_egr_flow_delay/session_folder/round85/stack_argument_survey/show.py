#!/usr/bin/env python3
"""Print survey.json per function (optionally only the given hex addresses)."""
import json
import sys

HERE = __file__.rsplit('/', 1)[0]
rep = json.load(open(HERE + '/survey.json'))
want = {int(a, 16) for a in sys.argv[1:]}
for f in rep:
    if want and f['address'] not in want:
        continue
    print('=' * 100)
    print('0x%x %s' % (f['address'], f['name']))
    print('  sig: %s' % f['signature'])
    print('  cpp: %s' % '; '.join('%s@+%s/w%s x%s' % (r['token'], r['offset'], r['width'], r['count'])
                                  for r in f['cpp_refs']))
    print('  rom reads: %s  extent=%d' % (f['rom_reads'], f['extent']))
    for a in f['rom_read_list']:
        print('     %06x %-24s %s' % (a['addr'], a['bytes'], a['text']))
    if f['retaddr_reads']:
        print('  RETURN-ADDRESS-AREA accesses: %s' % [(hex(a['addr']), a['text'], a['offset']) for a in f['retaddr_reads']])
    if f['issues']:
        print('  issues: %s' % f['issues'])
    if f['is_flowed_into']:
        print('  NOTE: another function flows into this entry')
    if f['data_refs']:
        print('  data longs = this address at: %s' % [hex(x) for x in f['data_refs']])
    for s in f['sites']:
        if s['via'] in ('walker', 'scan'):
            print('  %06x %-6s %-26s pop=%-4s %-10s | %s' % (
                s['addr'], s['via'], s.get('call', ''), s['pop'], s.get('pop_bytes') or '-', s['desc']))
            for g in s['layout']:
                if g['rec']:
                    print('         +%d len %d  %06x %-22s %s' % (g['off'], g['len'], g['rec']['addr'],
                                                              g['rec']['bytes'], g['rec']['text']))
        else:
            print('  %06x %s %s %s' % (s['addr'], s['via'], s['call_text'], s.get('caller')))
