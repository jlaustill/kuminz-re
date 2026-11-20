import json
import sys

d = json.load(open('/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/globals3.json'))
for a in sys.argv[1:]:
    for i, it in enumerate(d):
        want = a.lower().replace('0x', '').lstrip('0')
        have = it['address'].lower().replace('0x', '').lstrip('0')
        if want == have or a == f'#{i}':
            print('=== ITEM', i, it['address'], it['current_name'], it['current_type'], '| region:', it['region'])
            print(' comment:', it['current_comment'])
            print(' access:', it['access_widths'], '| dump_raw:', it['dump_raw'], '| refs:', it['references'],
                  '| row_width:', it['row_width_bytes'])
            print(' e2m:', it['e2m_records_here'])
            print(' covered:', it['covered_records'], '| wp:', it.get('width_problem'))
            for c in it['code']:
                print('   code:', c)
            for lead in it['report_leads']:
                print('   lead:', lead[:600])
            for b in it['block_named_rows']:
                print('   blk:', b)
