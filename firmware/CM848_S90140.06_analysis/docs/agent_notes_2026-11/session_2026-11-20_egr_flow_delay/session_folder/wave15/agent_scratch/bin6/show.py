import json, sys
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin6.json'))
idxs = [int(x) for x in sys.argv[1:]]
for i in idxs:
    r = d[i]
    print('=' * 100)
    print('IDX', i, 'block', r['block'], '+', r['offset'], 'addr', r['address'], 'record', r['record'])
    print('  unit', r['unit'], 'size', r['size_bytes'], 'signed', r['signed'], 'scale', r['scale'], 'min', r['min'], 'max', r['max'])
    print('  description:', r['description'])
    print('  region:', r['region'])
    print('  label_in_cpp:', r['label_in_cpp'], '| row type:', r['current_row_type'], '| refs', r['references'], '| ov', r['token_overlap'])
    print('  current_comment:', r['current_comment'])
    print('  access_widths:', r['access_widths'])
    print('  dump_raw:', r['dump_raw'])
    print('  current_row:', r['current_row'])
    print('  code:')
    for c in (r['code'] or []):
        print('     ', c)
    print('  other_records_at_this_address:', r['other_records_at_this_address'])
    print('  block_named_rows:')
    for b in (r['block_named_rows'] or []):
        print('     ', b)
    if 'earlier_verdict' in r:
        print('  earlier_verdict:', r['earlier_verdict'])
