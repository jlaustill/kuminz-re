import json
import sys

d = json.load(open('/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin4.json'))


def show(r, brief=False):
    print("=" * 100)
    print(f"[{r['address']}] e2m {r['block']} +{r['offset']} {r['record']}  unit={r['unit']} size={r['size_bytes']} signed={r['signed']} scale={r['scale']} min={r['min']} max={r['max']}")
    print("  DESC:", r['description'])
    print("  NAME:", r['label_in_cpp'], "| type:", r['current_row_type'], "| refs:", r['references'], "| dump_raw:", r.get('dump_raw'))
    print("  REGION:", r['region'], "| widths:", r['access_widths'])
    print("  COMMENT:", r['current_comment'])
    print("  CODE:")
    for c in r['code']:
        print("    ", c)
    if not brief:
        print("  BLOCK_NAMED:", [(a, b, c) for a, b, c, e in r['block_named_rows']])
    print("  OTHER@ADDR:", r['other_records_at_this_address'])


lo, hi = int(sys.argv[1]), int(sys.argv[2])
for r in d[lo:hi]:
    show(r, brief=(len(sys.argv) > 3))
