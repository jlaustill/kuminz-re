import json, collections
rows = [json.loads(l) for l in open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W7_vgt_egr.jsonl')]
by = {r.get('address'): r for r in rows if r['kind'] in ('function', 'global', 'new_global')}
for a in ['0x00019b20', '0x0001a204', '0x000191e8', '0x00507644', '0x0001a9a8']:
    r = by[a]
    print(a, r['old'], '->', r['new'])
    print('  PLATE:', r['plate_comment'][:800])
    print('  EVID:', r['evidence'][:260])
    print()
for a in ['0x0040a66a', '0x0040a34c', '0x0040a61c', '0x003fe9ce', '0x003fdfb4', '0x0040a670']:
    r = by[a]
    print(a, r.get('old'), '->', r['new'])
    print('  EVID:', r['evidence'][:650])
    print()
print(collections.Counter(r['kind'] for r in rows))
