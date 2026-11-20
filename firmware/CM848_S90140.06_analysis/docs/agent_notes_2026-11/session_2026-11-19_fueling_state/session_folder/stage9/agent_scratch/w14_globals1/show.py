import json
import sys

rows = [json.loads(l) for l in open('/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals1.jsonl') if l.strip()]
lo, hi = int(sys.argv[1]), int(sys.argv[2])
for i in range(lo, min(hi, len(rows))):
    r = rows[i]
    print('=== %d %s %s -> %s [%s]' % (i, r['address'], r['old'], r.get('new', '-'), r['verdict']))
    for k in ('evidence', 'code_quote', 'comment', 'e2m_note', 'type_note', 'old_comment_wrong'):
        if k in r:
            print('  %s: %s' % (k, r[k]))
    for s in r.get('split', []) or []:
        print('  SPLIT %s %s %s: %s' % (s['address'], s['name'], s['type'], s['comment']))
