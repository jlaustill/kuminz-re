import json
import sys

d = json.load(open('/home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_11.json'))
only = set(sys.argv[1:])
for l in d['lookups']:
    if only and l['id'] not in only:
        continue
    print('###', l['id'], l['interpolator'], l['kind'])
    for t in l['tables']:
        c = t['contents']
        cs = json.dumps({k: v for k, v in c.items() if k not in ('breakpoints_signed', 'grid_min_max_signed')})
        print('  T', t['role'], t['address'], 'cur=', t.get('current_name'), 'to_name=', t.get('to_name'), 'shared=', t.get('shared_by_lookups'))
        print('     ', cs)
    for c in l['calls']:
        print('  CALL in', c['function'])
        print('     ', c['statement'])
        print('     inputs:', c['inputs'])
        for k, v in c.items():
            if k not in ('function', 'statement', 'inputs'):
                print('     ', k, ':', json.dumps(v)[:500])
    for k, v in l.items():
        if k not in ('id', 'interpolator', 'kind', 'tables', 'calls'):
            print('  ', k, ':', json.dumps(v)[:500])
