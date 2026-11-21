import json, sys
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin6.json'))
for i, r in enumerate(d):
    print(i, r['block'], r['offset'], r['address'], r['record'], '|', r['label_in_cpp'], '|', r['current_row_type'], '|', r['region'], '| ov', r['token_overlap'], '| refs', r['references'], '| sz', r['size_bytes'], 'sg', r['signed'])
