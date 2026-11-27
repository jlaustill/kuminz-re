import json
n = 0
for line in open('/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin6.jsonl'):
    r = json.loads(line)
    n += 1
    if r['verdict'] == 'confirmed':
        print(n, r['address'], r['old'], '->', r['new'])
        print('    EVIDENCE:', r['evidence'])
        print('    QUOTE:', r['code_quote'])
        print('    COMMENT:', r['comment'], '| len', len(r['comment']))
    elif r['verdict'] == 'keep':
        print(n, r['address'], 'KEEP', r['old'], '|', r['e2m_note'])
    else:
        print(n, r['address'], r['verdict'].upper(), r['old'], '|', r['evidence'])
