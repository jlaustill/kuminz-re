"""Which bin / result line holds each lead address (read-only)."""
import glob
import json
import sys

STAGE9 = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/'
want = {a.lower() for a in sys.argv[1:]}
for path in sorted(glob.glob(STAGE9 + 'bins/*.json')):
    data = json.load(open(path))
    items = data if isinstance(data, list) else data.get('functions', []) + data.get('held_enum_rows', [])
    for it in items:
        a = it['address'].lower()
        if a in want:
            print('bin', path.split('/')[-1], a, it.get('current_name') or it.get('current'))
for path in sorted(glob.glob(STAGE9 + 'result_W14_*.jsonl')):
    for line in open(path):
        if line.strip():
            r = json.loads(line)
            if r['address'].lower() in want:
                print('result', path.split('result_W14_')[1], r['address'], r['verdict'], r.get('old'), '->', r.get('new'))
