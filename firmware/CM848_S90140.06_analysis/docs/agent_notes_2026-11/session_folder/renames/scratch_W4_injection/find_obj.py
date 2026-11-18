import json
import re

B = '/home/linux/.claude/jobs/d55ae3c6/tmp/'
for path in (B + 'renames/result_G1b.jsonl', B + 'renames/aligned_G1b.jsonl'):
    try:
        for line in open(path):
            if '5fa1a' in line or '5f8ac' in line:
                try:
                    r = json.loads(line)
                except Exception:
                    continue
                print(path.split('/')[-1], r.get('kind'), r.get('address'), r.get('verdict'), r.get('new'))
                print('   ', (r.get('evidence') or r.get('text') or '')[:1800])
    except Exception as exc:
        print(path, exc)
for name in ('table_plan.csv', 'tables.csv', 'plan_a.csv'):
    try:
        for line in open(B + name):
            if '5fa1a' in line.lower():
                print(name, line[:1500])
                break
    except Exception as exc:
        print(name, exc)
