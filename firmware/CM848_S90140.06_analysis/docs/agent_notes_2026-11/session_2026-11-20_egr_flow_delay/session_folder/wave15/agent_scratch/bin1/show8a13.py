"""print compact detail of the 8A13 records of bin1 (no block rows)"""
import json

d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin1.json'))
for r in d:
    if r['block'] != '8A13':
        continue
    print('-' * 90)
    print('+%s %s %s | %s | %s sz=%s %s sc=%s [%s..%s]' % (r['offset'], r['address'], r['record'], r['description'],
                                                          r['unit'], r['size_bytes'], r['signed'], r['scale'],
                                                          r['min'], r['max']))
    print('   cur: %s type=%s refs=%s dump=%s widths=%s' % (r['label_in_cpp'], r['current_row_type'], r['references'],
                                                              r['dump_raw'], r['access_widths']))
    print('   comment: %s' % r['current_comment'])
    for c in r['code']:
        print('   code: %s' % c)
    if r['other_records_at_this_address']:
        print('   other: %s' % json.dumps(r['other_records_at_this_address']))
    if 'earlier_verdict' in r:
        print('   EARLIER: %s' % r['earlier_verdict'])
