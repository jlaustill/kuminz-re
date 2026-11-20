import json
import glob

STAGE = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/'
want = {'0x0040c270', '0x003fddba', '0x0040b9a2', '0x0040b9a4', '0x0040b9a6', '0x003fa0da', '0x003fa0dc',
        '0x003fcff0', '0x003fcff4', '0x0040b6b0', '0x0040a3e0', '0x0040a3e2', '0x00408f28', '0x00408f2a', '0x0040b7d0'}
for f in sorted(glob.glob(STAGE + 'result_W14_globals[234].jsonl')):
    for l in open(f):
        r = json.loads(l)
        if r.get('address') in want:
            print(f.split('_')[-1], r['address'], r.get('old'), '->', r.get('new'), '|', r['verdict'], '|',
                  (r.get('comment') or r.get('evidence') or r.get('e2m_note') or '')[:260])
