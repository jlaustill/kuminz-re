#!/usr/bin/env python3
"""One line per affected function: layout from the pushes, what the callee
reads, site counts, the .cpp tokens, and one example call with its bytes."""
import json

H = __file__.rsplit('/', 1)[0] + '/'
t = json.load(open(H + 'classes.json'))['table']
rep = {f['address']: f for f in json.load(open(H + 'survey.json'))}
for e in t:
    f = rep[e['address']]
    ex = ''
    if e['examples']:
        x = e['examples'][0]
        pushes = list(reversed(x['pushes']))   # in execution order
        ex = 'call %s: %s / %s / %s' % (x['call'], ' ; '.join(p.split(' (')[0] for p in pushes),
                                       x['call_bytes'], x['pop'] or 'no pop')
    reads = '; '.join('%06x %s %s' % (a['addr'], a['bytes'].replace(' ', ''), a['text'])
                      for a in f['rom_read_list'][:4])
    print('0x%05x %s' % (e['address'], e['name']))
    print('    layout: %s' % e['class'])
    print('    cpp: %s | sites %d (walker %d, scan %d)' % ('; '.join(e['cpp']), e['n_sites'], e['n_walker'], e['n_scan']))
    print('    callee: %s' % reads)
    if ex:
        print('    %s' % ex)
