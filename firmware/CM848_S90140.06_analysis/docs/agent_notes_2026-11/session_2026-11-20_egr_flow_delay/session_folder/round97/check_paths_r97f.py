"""Round 97 stage F: every judged dotted / deleted name against the path make_overrides_r97_f.py computed."""
import json
W = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97'
o = json.load(open(f'{W}/overrides_r97.json'))
rem = o['remove_globals']['CM550']
agree = differ = 0
for b in ('R5', 'R6', 'R7'):
    d = json.load(open(f'{W}/batch_{b}.json'))
    vd = {(x.get('kind'), str(x.get('address')).lower()): x for x in d['verdict']['verdicts']}
    for g in d['proposal'].get('globals') or []:
        v = vd.get(('global', g['address'].lower())) or {}
        final = (v.get('final_name') or g['proposed_name']).strip()
        key = f"0x{int(g['address'], 16):08x}"
        if '.' in final or '[' in final:
            got = rem.get(key)
            if got == final:
                agree += 1
            else:
                differ += 1
                print(b, key, 'judge:', final, '| computed:', got)
print('agree', agree, 'differ', differ)
