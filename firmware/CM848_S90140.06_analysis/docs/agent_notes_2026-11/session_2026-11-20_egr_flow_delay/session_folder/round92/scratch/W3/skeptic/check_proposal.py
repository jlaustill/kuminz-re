"""Read-only hygiene check of the W3 proposal: all 16 bits present, unique names, snake_case, reserved numbering,
short tokens that might be abbreviations. usage: check_proposal.py <batch_W3.json>"""
import json
import re
import sys

d = json.load(open(sys.argv[1]))['proposal']
print(d['batch'], 'cm848 renames:', d.get('cm848_field_renames'))
COMMON = {'bit', 'air', 'fan', 'fuel', 'off', 'on', 'in', 'of', 'to', 'a', 'set', 'oil', 'and', 'raw', 'egr', 'low'}
for w in d['words']:
    bits = [f['bit'] for f in w['fields']]
    names = [f['name'] for f in w['fields']]
    print('word', w['word'], w['address'], w['proposed_name'], w['proposed_type'],
          'bits ok' if bits == list(range(16)) else bits,
          'unique' if len(set(names)) == 16 else 'DUP NAMES', 'shared=%s' % w['shared_with_cm848'])
    for f in w['fields']:
        n = f['name']
        if not re.fullmatch(r'[a-z][a-z0-9_]*', n) or '__' in n or n.endswith('_'):
            print('   BAD NAME', n)
        if n.startswith('reserved_bit_') and n != 'reserved_bit_%d' % f['bit']:
            print('   reserved number mismatch', n, f['bit'])
        short = [t for t in n.split('_') if len(t) <= 3 and t not in COMMON and not t.isdigit()]
        if short:
            print('   short tokens', n, short)
