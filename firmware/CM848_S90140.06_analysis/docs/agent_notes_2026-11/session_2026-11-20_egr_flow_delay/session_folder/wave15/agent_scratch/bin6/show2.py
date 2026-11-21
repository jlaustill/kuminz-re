import json, sys
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin6.json'))
idxs = [int(x) for x in sys.argv[1:]]
for i in idxs:
    r = d[i]
    print('=' * 80)
    print('IDX', i, 'block', r['block'], '+', r['offset'], 'addr', r['address'], 'record', r['record'], '| row', r['label_in_cpp'], '|', r['current_row_type'], '| refs', r['references'], '| ov', r['token_overlap'])
    print('  unit', r['unit'], 'size', r['size_bytes'], 'signed', r['signed'], 'scale', r['scale'], 'min', r['min'], 'max', r['max'], '| dump_raw', r['dump_raw'], '| access', r['access_widths'])
    print('  DESC:', r['description'])
    print('  COMMENT:', r['current_comment'])
    print('  CODE:')
    for c in (r['code'] or []):
        print('     ', c)
    if r['other_records_at_this_address']:
        print('  OTHER RECORDS:', r['other_records_at_this_address'])
    if 'earlier_verdict' in r:
        print('  EARLIER:', [e[:160] for e in r['earlier_verdict']])
