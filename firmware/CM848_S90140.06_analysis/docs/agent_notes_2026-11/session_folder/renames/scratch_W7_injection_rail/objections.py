import json

for fn in ('result_09.jsonl', 'result_retry.jsonl'):
    for l in open('/home/linux/.claude/jobs/d55ae3c6/tmp/tables/' + fn):
        r = json.loads(l)
        if r.get('lookup') in ('L022', 'L023'):
            print('=====', fn, r.get('lookup'), {k: v for k, v in r.items() if k not in ('reason', 'lookup', 'evidence')})
            print(r.get('reason'))
            if r.get('evidence'):
                print('EVIDENCE:', r.get('evidence'))
            print()
