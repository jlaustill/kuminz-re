"""Assemble spec_a + spec_b into the result file (63 lines, bin order)."""
import json
import sys

sys.path.insert(0, "/tmp/w14_globals4")
import importlib

import spec_a
import spec_b
import spec_c

importlib.reload(spec_a)
importlib.reload(spec_b)
importlib.reload(spec_c)
bin_ = json.load(open("/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/globals4.json"))
items = spec_a.A + spec_b.B
for it in items:
    if it['address'] in spec_c.COMMENTS:
        it['comment'] = spec_c.COMMENTS[it['address']]
for it in items:
    if it['address'] in ("0x003fcff0", "0x003fcff4"):
        it['old_comment_wrong'] = True
assert len(items) == len(bin_) == 63, (len(items), len(bin_))
OUT = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_globals4.jsonl"
with open(OUT, "w") as f:
    for b, it in zip(bin_, items):
        assert it["address"] == b["address"], (it["address"], b["address"])
        assert it["old"] == b["current_name"], (it["address"], it["old"], b["current_name"])
        f.write(json.dumps(it, ensure_ascii=False) + "\n")
print("wrote", OUT, len(items))
