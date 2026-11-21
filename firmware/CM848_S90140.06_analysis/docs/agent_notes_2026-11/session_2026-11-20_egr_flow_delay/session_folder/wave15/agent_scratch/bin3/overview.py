import json
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin3.json'))
for i, r in enumerate(d):
    print(f"{i:2d} {r['address']} {r['block']}+{r['offset']} {r['record']} [{r['unit']}] {r['size_bytes']}B {r['signed']} sc={r['scale']} {r['min']}..{r['max']} :: {r['description'][:90]}")
    print(f"     -> {r['label_in_cpp']} ({r['current_row_type']}) refs={r['references']} ov={r['token_overlap']} widths={r['access_widths']}")
