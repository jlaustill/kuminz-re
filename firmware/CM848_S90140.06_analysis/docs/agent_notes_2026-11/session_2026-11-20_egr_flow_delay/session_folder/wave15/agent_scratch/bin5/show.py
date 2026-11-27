"""Print the bin-5 records of the given e2m blocks in full.
usage: show.py <block> [<block> ...]"""
import json
import sys

data = json.load(open("/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin5.json"))
for block in sys.argv[1:]:
    for r in data:
        if r["block"].upper() != block.upper():
            continue
        print("=" * 100)
        print(f"{r['address']}  e2m {r['block']} +{r['offset']}  {r['record']}  [{r['unit']}, {r['size_bytes']}B, signed={r['signed']}, "
              f"scale={r['scale']}, min={r['min']}, max={r['max']}]")
        print(f"  description : {r['description']}")
        print(f"  current name: {r['label_in_cpp']}  (type {r['current_row_type']}, refs {r['references']}, overlap {r['token_overlap']})")
        print(f"  region      : {r['region']}")
        print(f"  dump raw    : {r['dump_raw']}   access widths: {r['access_widths']}")
        print(f"  comment     : {r['current_comment']}")
        if r.get("earlier_verdict"):
            print(f"  earlier     : {r['earlier_verdict']}")
        if r["other_records_at_this_address"]:
            print(f"  other recs  : {r['other_records_at_this_address']}")
        for c in r["code"]:
            print(f"  code        : {c}")
        print("  block named rows:")
        for b in r["block_named_rows"]:
            print(f"     {b}")
