import json

STAGE = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/'
bin_items = json.load(open(STAGE + 'bins/globals1.json'))
n = 0
for i, l in enumerate(open(STAGE + 'result_W14_globals1.jsonl')):
    r = json.loads(l)
    n += 1
    assert r['kind'] == 'global'
    assert r['address'] == bin_items[i]['address'], (i, r['address'])
    assert r['old'] == bin_items[i]['current_name'], (i, r['old'])
    v = r['verdict']
    if v == 'confirmed':
        for k in ('new', 'evidence', 'code_quote', 'comment'):
            assert r.get(k), (i, k)
        assert r['new'] != r['old']
        assert set(r) <= {'kind', 'verdict', 'address', 'old', 'new', 'evidence', 'code_quote', 'comment', 'type_note', 'split', 'old_comment_wrong'}, (i, set(r))
        for s in r.get('split', []) or []:
            assert set(s) == {'address', 'name', 'type', 'comment'}, (i, s.keys())
            assert s['type'] in ('byte', 'word', 'dword')
        # one-line fields
        for k in ('evidence', 'comment'):
            assert '\n' not in r[k]
    elif v == 'keep':
        assert r['new'] == r['old'] and r.get('e2m_note')
        assert set(r) == {'kind', 'verdict', 'address', 'old', 'new', 'e2m_note'}, (i, set(r))
    elif v in ('drift', 'uncertain'):
        assert r.get('evidence')
        assert set(r) == {'kind', 'verdict', 'address', 'old', 'evidence'}, (i, set(r))
    else:
        raise AssertionError((i, v))
print('format ok', n)
