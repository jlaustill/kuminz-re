"""Round 32: prove_tokens.py token file from the stage A map (old label <-> new name, one token per row), plus the
underscore variants of the old labels (the too-narrow old types rendered _DAT_...).
usage: make_tokens_r32a.py <map.csv> <tokens.json>"""
import csv
import json
import sys

rows = list(csv.DictReader(open(sys.argv[1])))
old, new = {}, {}
for i, r in enumerate(rows):
    tok = f"TOKEN{i:03d}"
    old[r["old_label"]] = tok
    old["_" + r["old_label"]] = tok
    new[r["name"]] = tok
json.dump({"old": old, "new": new, "old_regex": []}, open(sys.argv[2], "w"), indent=0)
print(len(rows), "rows")
