"""Round 94 (read-only): print the full proposal entries (function / global / enum members) of a batch for the given
addresses or enum names. usage: show_element_r94.py <batch_X.json> <0xADDR | ENUM_NAME>..."""
import json
import sys

d = json.load(open(sys.argv[1]))
p = d["proposal"]
want = sys.argv[2:]
for kind in ("functions", "globals"):
    for x in p.get(kind) or []:
        if any(w.startswith("0x") and int(w, 16) == int(x["address"], 16) for w in want):
            print(f"== {kind[:-1]} {x['address']}")
            for k, v in x.items():
                print(f"  {k}: {str(v)[:1500]}")
for e in p.get("enum_members") or []:
    if e["enum_name"] in want:
        print(f"== enum {e['enum_name']} {e['value']} {e['current_member']!r} -> {e['proposed_member']} ({e['firmware']}, {e['confidence']}) | {e['comment'][:200]}")
