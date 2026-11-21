"""Read-only: compare bin6 results with the other agents' result files (names, addresses)."""
import glob
import json

ROOT = '/home/linux/.claude/jobs/374b0424/tmp/w15/results/'
mine = {}
for line in open(ROOT + 'result_W15_bin6.jsonl'):
    r = json.loads(line)
    mine[r['address']] = r
my_new = {r['new']: a for a, r in mine.items() if r['verdict'] == 'confirmed'}
others = {}
for f in sorted(glob.glob(ROOT + 'result_W15_bin[1-5].jsonl')):
    for line in open(f):
        line = line.strip()
        if not line.startswith('{'):
            continue
        try:
            r = json.loads(line)
        except Exception:
            continue
        others.setdefault(r.get('address'), []).append((f.split('_')[-1], r))
print('my confirmed names:', len(my_new))
for f in sorted(glob.glob(ROOT + 'result_W15_bin[1-5].jsonl')):
    for line in open(f):
        line = line.strip()
        if not line.startswith('{'):
            continue
        try:
            r = json.loads(line)
        except Exception:
            continue
        if r.get('new') in my_new:
            print('NAME CLASH', f.split('_')[-1], r.get('address'), r.get('new'), 'mine at', my_new[r['new']])
        if r.get('address') in mine:
            print('ADDRESS CLASH', f.split('_')[-1], r.get('address'))
for a in ('0x003feff0', '0x003fd4b8', '0x0040b6e2', '0x0005c2a4', '0x0005c294', '0x0005c29e', '0x003ff6b0', '0x003ff6b2',
          '0x003ff6b6', '0x003ff6c6', '0x003ff69c', '0x003fb522', '0x003fb9ea', '0x003fb9d8', '0x0040b6fe', '0x003fd05c'):
    for src, r in others.get(a, []):
        print(a, src, r.get('verdict'), r.get('old'), '->', r.get('new'))
# any other agent name containing words of my families
for a, lst in others.items():
    for src, r in lst:
        n = r.get('new') or ''
        if any(w in n for w in ('cruise_minimum_fuel', 'ramp_rate', 'fuel_flow', 'target_speed', 'application_identifier',
                                'ecm_identifier', 'all_speed_governor_application')):
            print('related:', src, a, r.get('verdict'), r.get('old'), '->', n)
