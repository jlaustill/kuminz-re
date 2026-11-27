"""usage: show.py <index> [<index> ...]  -- print the full bin record(s) compactly"""
import json
import sys

d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin3.json'))
for arg in sys.argv[1:]:
    r = d[int(arg)]
    print(f"##### [{arg}] {r['address']} {r['block']}+{r['offset']} {r['record']} [{r['unit']}] {r['size_bytes']}B {r['signed']} scale={r['scale']} {r['min']}..{r['max']}")
    print(f"description: {r['description']}")
    print(f"region: {r['region']}")
    print(f"current: {r['label_in_cpp']} (type {r['current_row_type']}) refs={r['references']} dump_raw={r['dump_raw']} overlap={r['token_overlap']}")
    print(f"access_widths: {r['access_widths']}")
    print(f"current_comment: {r['current_comment']}")
    print("code:")
    for c in r['code']:
        print(f"   {c}")
    print("block_named_rows:")
    for b in r['block_named_rows']:
        print(f"   +{b[0]} {b[1]} -> {b[2]} ({b[3]})")
    print(f"other_records_at_this_address: {r['other_records_at_this_address']}")
    ev = r.get('earlier_verdict')
    if ev:
        print("earlier_verdict:")
        for e in ev:
            print(f"   {e}")
    print()
