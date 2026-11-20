import json, sys
d = json.load(open('/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin6.json'))
lo, hi = int(sys.argv[1]), int(sys.argv[2])
for i, r in enumerate(d):
    if not (lo <= i <= hi):
        continue
    print(f"##### [{i}] {r['address']}  e2m {r['block']} +{r['offset']} {r['record']}")
    print(f"  unit={r['unit']} size={r['size_bytes']} signed={r['signed']} scale={r['scale']} min={r['min']} max={r['max']}")
    print(f"  desc: {r['description']}")
    print(f"  region: {r['region']}")
    print(f"  label: {r['label_in_cpp']}  type={r['current_row_type']} refs={r['references']} dump_raw={r['dump_raw']}")
    print(f"  widths: {r['access_widths']}")
    print(f"  comment: {r['current_comment']}")
    print("  code:")
    for c in r['code']:
        print("    ", c)
    print("  block_named_rows:")
    for b in r['block_named_rows']:
        print("    ", b)
    print("  other_records_here:", r['other_records_at_this_address'])
