import json
import glob

STAGE = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/'
for f in sorted(glob.glob(STAGE + 'result_W14_functions[123].jsonl')):
    for l in open(f):
        r = json.loads(l)
        if r.get('address') in ('0x005268e8', '0x00505f98', '0x00505c20', '0x000457d0', '0x00044374'):
            print(f.split('_')[-1], r.get('address'), r.get('old'), '->', r.get('new'), '|', r.get('verdict'))
            print('   EVIDENCE:', r.get('evidence'))
            print('   PLATE:', r.get('plate_comment'))
