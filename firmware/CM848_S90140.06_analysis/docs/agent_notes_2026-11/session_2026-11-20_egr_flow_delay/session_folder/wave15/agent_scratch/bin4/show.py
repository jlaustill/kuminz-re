import json
import sys
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin4.json'))
lo = int(sys.argv[1])
hi = int(sys.argv[2]) if len(sys.argv) > 2 else lo
blocks = '--blocks' in sys.argv
for i in range(lo, hi + 1):
    r = d[i]
    print(f"##### [{i}] {r['address']}  e2m {r['block']} +{r['offset']}  {r['record']}  unit={r['unit']} size={r['size_bytes']} signed={r['signed']} scale={r['scale']} min={r['min']} max={r['max']}")
    print(f"  desc: {r['description']}")
    print(f"  region: {r['region']}   dump_raw={r.get('dump_raw')}  refs={r['references']}  overlap={r['token_overlap']}")
    print(f"  CURRENT: {r['label_in_cpp']}  type={r['current_row_type']}  access={r['access_widths']}")
    print(f"  comment: {r['current_comment']}")
    for c in r['code']:
        print(f"    code| {c}")
    if r.get('other_records_at_this_address'):
        print(f"  other_records: {r['other_records_at_this_address']}")
    if r.get('earlier_verdict'):
        print(f"  earlier_verdict: {r['earlier_verdict']}")
    if blocks:
        for b in r['block_named_rows']:
            print(f"    blk| {b[0]} {b[1]} -> {b[2]} ({b[3]})")
    print()
