import json
d = json.load(open('/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin4.json'))
for i, r in enumerate(d):
    ev = r.get('earlier_verdict')
    print(f"{i:2d} {r['address']} {r['block']}+{r['offset']} {r['record']} [{r['unit']}/{r['size_bytes']}/{r['signed']}] -> {r['label_in_cpp']} ({r['current_row_type']}) ov={r['token_overlap']} refs={r['references']} {'EV:'+str(ev)[:80] if ev else ''}")
