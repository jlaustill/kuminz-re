"""Round 97 stage F: R5's judged 0x80060e row and the scheduler's final name (for the enum rename)."""
import json
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/r97/batch_R5.json'))
v = {(x['kind'], str(x['address']).lower()): x for x in d['verdict']['verdicts']}
for g in d['proposal']['globals']:
    if g['address'].lower() in ('0x0080060e', '0x80060e'):
        x = v.get(('global', g['address'].lower())) or {}
        print(g['proposed_name'], g['proposed_type'], x.get('verdict'), x.get('final_name'), x.get('final_type'))
        print((x.get('final_comment') or g['comment'])[:900])
for f in d['proposal']['functions']:
    if f['address'].lower().endswith('18620'):
        print(f['proposed_name'])
