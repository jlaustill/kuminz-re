import json, re
rows = [json.loads(l) for l in open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W7_vgt_egr.jsonl')]
ident = re.compile(r'[a-z][a-z0-9_]{14,}')
bad = 0
for r in rows:
    for k in ('plate_comment', 'evidence'):
        t = r.get(k, '')
        for m in ident.finditer(t):
            name = m.group(0)
            # same identifier again within 80 characters
            nxt = t.find(name, m.end(), m.end() + 80)
            if nxt != -1:
                bad += 1
                if bad <= 25:
                    print(r.get('address'), k, '...', t[max(0, m.start() - 30):nxt + len(name) + 20].replace('\n', ' '))
                break
print('close repeats', bad)
