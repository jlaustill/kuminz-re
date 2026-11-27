"""Round 97 stage F: force the five judged types the apply kept (the live type differs). usage: force_types_r97f.py <overrides.json>"""
import json
import sys

p = sys.argv[1]
o = json.load(open(p))
LOG = "R5 judge: one 5-entry engine protection fault log (engine_protection_fault_log_entry_t[5], 40 bytes like the word[20] it replaces); the entry layout is proven field by field"
for key, reason in (("global|CM550|0x00805562", LOG), ("global|CM550|0x0080558a", LOG),
                    ("global|CM550|0x008055da", LOG), ("global|CM550|0x00805602", LOG),
                    ("global|CM550|0x008002ac", "R7 judge: one i32[6] array (the search loop walks it with a pointer from 0x8002b0)")):
    o.setdefault(key, {}).update({"force_type": True, "reason": reason})
json.dump(o, open(p, "w"), indent=1)
print("forced 5")
