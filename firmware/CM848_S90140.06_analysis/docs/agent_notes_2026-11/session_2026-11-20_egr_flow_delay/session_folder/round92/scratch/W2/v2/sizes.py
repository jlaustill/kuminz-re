"""Print the size of each section of result_W2.json. usage: sizes.py <result.json>"""
import json
import sys

d = json.load(open(sys.argv[1]))
print("notes", len(d["notes"]))
print("renames", len(json.dumps(d["cm848_field_renames"])))
tot = 0
for w in d["words"]:
    f = sum(len(x["comment"]) + len(x["name"]) for x in w["fields"])
    o = {k: len(w[k]) for k in ("row_comment", "differences_from_cm848", "code_tests", "writes")}
    print(w["word"], "fields", f, o)
    tot += f + sum(o.values())
print("total chars in words", tot)
