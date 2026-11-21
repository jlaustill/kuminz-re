"""usage: show.py <block> [<block> ...]  - print every bin1 record of the given e2m blocks in full"""
import json
import sys

d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin1.json'))
want = set(a.upper() for a in sys.argv[1:])
for r in d:
    if r['block'].upper() not in want:
        continue
    print('=' * 100)
    print('BLOCK %s +%s  addr %s  record %s' % (r['block'], r['offset'], r['address'], r['record']))
    print('  desc: %s' % r['description'])
    print('  unit=%s size=%s signed=%s scale=%s min=%s max=%s' % (r['unit'], r['size_bytes'], r['signed'], r['scale'],
                                                                   r['min'], r['max']))
    print('  region: %s' % r['region'])
    print('  current: %s  type=%s  refs=%s  dump_raw=%s  overlap=%s' % (r['label_in_cpp'], r['current_row_type'],
                                                                         r['references'], r['dump_raw'],
                                                                         r['token_overlap']))
    print('  widths: %s' % r['access_widths'])
    print('  comment: %s' % r['current_comment'])
    for c in r['code']:
        print('  code: %s' % c)
    if r['other_records_at_this_address']:
        print('  other_records_at_address: %s' % json.dumps(r['other_records_at_this_address']))
    if 'earlier_verdict' in r:
        for e in r['earlier_verdict']:
            print('  EARLIER: %s' % e)
    print('  block rows:')
    for br in r['block_named_rows']:
        print('     %s %s -> %s (%s)' % tuple(br))
