"""Round 96 stage G: name the four empty CM550 functions of batch Q3 by their one call site's role (the judge's plate
says it) instead of the numbered cm550_emptyStubFunction12-15; 12 is already 0x26b82's name.
usage: stub_names_r96.py <overrides_r96.json>"""
import json
import sys

p = sys.argv[1]
o = json.load(open(p))
NAMES = {"0x000133fc": "cm550_emptyExecutiveFrame5ExtraTask",
         "0x00019e8e": "cm550_emptyEnginePositionSignalConfiguration1ThirdStep",
         "0x0001a52a": "cm550_emptyEnginePositionSignalConfiguration2ThirdStep",
         "0x0001a8a2": "cm550_emptyEnginePositionSignalConfiguration3ThirdStep"}
for a, n in NAMES.items():
    o[f"function|{a}"] = {"name": n, "reason": "named by its one call site's role (the judge's plate); the numbered stub name 12 is taken"}
json.dump(o, open(p, "w"), indent=1)
print(len(NAMES), "name overrides")
