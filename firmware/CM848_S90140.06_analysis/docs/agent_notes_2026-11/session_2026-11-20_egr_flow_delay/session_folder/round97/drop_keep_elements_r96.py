"""Round 96: drop the judged function elements whose final comment is the instruction 'Keep the round N name and plate'
(no change wanted; the apply rightly refuses an instruction as a comment). usage: drop_keep_elements_r96.py <overrides> <batch.json>..."""
import json
import re
import sys

path = sys.argv[1]
o = json.load(open(path))
n = 0
for p in sys.argv[2:]:
    d = json.load(open(p))
    vd = {(x.get("kind"), str(x.get("address")).lower()): x for x in d["verdict"]["verdicts"]}
    for kind, items in (("function", d["proposal"].get("functions") or []), ("cm848_function", d["proposal"].get("cm848_functions") or [])):
        for f in items:
            v = vd.get((kind, f["address"].lower())) or {}
            text = v.get("final_comment") or f.get("plate_comment") or ""
            if re.match(r"^\s*Keep the round \d+ name", text):
                a = "0x" + f["address"].lower()[2:].rjust(8, "0")
                o[f"{kind}|{a}"] = {"drop": True, "reason": f"{d['batch']}: no change (the judge kept the earlier round's name and plate)"}
                n += 1
json.dump(o, open(path, "w"), indent=1)
print("dropped", n)
