import json
from collections import OrderedDict

d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin1.json'))
blocks = OrderedDict()
for r in d:
    blocks.setdefault(r['block'], []).append(r)
for b, rs in blocks.items():
    print(b, len(rs))
    for r in rs:
        print('   ', r['offset'], r['address'], r['record'], '->', r['label_in_cpp'], 'ov=%s' % r['token_overlap'],
              'refs=%s' % r['references'], 'type=%s' % r['current_row_type'], 'sz=%s' % r['size_bytes'], r['signed'],
              'earlier' if 'earlier_verdict' in r else '')
keys = set()
for r in d:
    keys |= set(r.keys())
print(sorted(keys))
