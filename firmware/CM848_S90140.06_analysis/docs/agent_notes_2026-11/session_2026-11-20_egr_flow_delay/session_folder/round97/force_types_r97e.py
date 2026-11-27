"""Round 97 stage E: force the four judged types the apply kept (the live type differs). usage: force_types_r97e.py <overrides.json>"""
import json
import sys

p = sys.argv[1]
o = json.load(open(p))
for key, reason in (("global|CM550|0x00808314", "R1 judge: the default gain set is a cm550_low_speed_governor_gain_set_t (the 3-word layout the RAM dump proves)"),
                    ("global|CM550|0x0080a942", "R2 judge: typed word (confirmed)"),
                    ("global|CM550|0x0080d652", "R2 judge: i16 (signed tst.w + ble)"),
                    ("global|CM550|0x0080de68", "R3 judge: i16")):
    o.setdefault(key, {}).update({"force_type": True, "reason": reason})
json.dump(o, open(p, "w"), indent=1)
print("forced 4")
