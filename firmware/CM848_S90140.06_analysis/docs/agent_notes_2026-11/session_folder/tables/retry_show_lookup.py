import json
import sys

# usage: retry_show_lookup.py L197 L198 ...   (prints tables and calls of those lookups from lookups.json)
data = json.load(open('/home/linux/.claude/jobs/d55ae3c6/tmp/tables/lookups.json'))
lookups = data['lookups'] if isinstance(data, dict) and 'lookups' in data else data
wanted = set(sys.argv[1:])
for lk in lookups:
    if lk['id'] not in wanted:
        continue
    print('=====', lk['id'], lk['interpolator'], lk['kind'])
    for t in lk['tables']:
        c = t['contents']
        keep = {}
        for k, v in c.items():
            if k in ('breakpoints_signed', 'values_unsigned', 'values_signed', 'grid_min_max_signed', 'shape_x_by_y', 'first_row', 'last_row'):
                keep[k] = v
        print('  ', t['role'], t['address'], t.get('current_name'), json.dumps(keep))
    for call in lk['calls']:
        print('   CALL', call['function'], call['statement'][:300])
