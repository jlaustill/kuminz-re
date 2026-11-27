"""J2 investigator (round 93): assembles result.json from build_result_part1.py (functions) and build_result_part2.py
(globals, enum members) plus summary_notes.py (summary / notes text, optional)."""
import importlib
import json
import os
import sys

here = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, here)
p1 = importlib.import_module("build_result_part1")
p2 = importlib.import_module("build_result_part2")
try:
    sn = importlib.import_module("summary_notes")
    summary, notes, skipped = sn.summary, sn.notes, sn.skipped
except ModuleNotFoundError:
    summary, notes, skipped = "PRELIMINARY (summary not written yet)", "PRELIMINARY", []

p3 = importlib.import_module("build_result_part3")
result = dict(batch="J2", summary=summary, functions=p1.functions + p3.functions, skipped=skipped,
              globals=p2.globals_ + p3.globals_, enum_members=p2.enum_members + p3.enum_members, notes=notes)
out = os.path.join(here, "result.json")
json.dump(result, open(out, "w"), indent=1)
print(out, os.path.getsize(out), "bytes;", len(result["functions"]), "functions,", len(result["globals"]), "globals,",
      len(result["enum_members"]), "enum members,", len(skipped), "skipped")
