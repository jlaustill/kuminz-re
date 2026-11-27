import json, sys
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin2.json'))
lo, hi = int(sys.argv[1]), int(sys.argv[2])
full = len(sys.argv) > 3
for i in range(lo, hi):
    r = d[i]
    print(f"##### [{i}] {r['address']}  e2m {r['block']} +{r['offset']}  {r['record']}")
    try:
        raw = int(r['dump_raw'])
        scaled = raw * float(r['scale'])
    except Exception:
        raw, scaled = r['dump_raw'], None
    print(f"  record: unit={r['unit']} size={r['size_bytes']} signed={r['signed']} scale={r['scale']} min={r['min']} max={r['max']}  desc={r['description']!r}")
    print(f"  dump_raw={r['dump_raw']}  raw*scale={scaled}")
    print(f"  current: {r['label_in_cpp']}  type={r['current_row_type']} row={r['current_row']} refs={r['references']} overlap={r['token_overlap']}  region={r['region']}")
    print(f"  access: {r['access_widths']}")
    print(f"  comment: {r['current_comment']!r}")
    for c in r['code']:
        print(f"  code: {c}")
    if r.get('other_records_at_this_address'):
        print(f"  OTHER RECORDS: {r['other_records_at_this_address']}")
    if r.get('earlier_verdict'):
        print(f"  EARLIER: {r['earlier_verdict']}")
    if full:
        print("  block rows:")
        for b in r['block_named_rows']:
            print("    ", b)
