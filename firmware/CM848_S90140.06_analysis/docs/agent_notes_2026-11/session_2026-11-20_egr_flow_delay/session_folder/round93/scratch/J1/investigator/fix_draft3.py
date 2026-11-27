"""Round 93 J1 investigator: the typing passes finished while this batch ran - say what the live CSV shows now.
usage: fix_draft3.py <draft_output.json>"""
import json
import sys

path = sys.argv[1]
d = json.load(open(path))
old = (
    "The pending second typing pass (rows typed from their Calterm record) will touch the same element rows: these "
    "array and word types take precedence there."
)
new = (
    "Since the freeze the two round 93 typing passes have typed some of these rows in the live CSV (seen read-only: "
    "0x808159 byte, 0x80bd51 / 0x80bd52 byte, 0x807d6e dword, 0x80bced byte, 0x80a6de / 0x80a6fc / 0x80815a / 0x80d728 "
    "word, 0x80d70c / 0x80d726 byte, each with a 'typed ...' comment). Those widths agree with the types proposed here; "
    "where an array or the word 0x808158 is proposed it replaces the typed element rows, and the comments proposed here "
    "replace the 'typed ...' comments."
)
assert d["notes"].count(old) == 1
d["notes"] = d["notes"].replace(old, new)
json.dump(d, open(path, "w"), indent=2, ensure_ascii=False)
d = json.load(open(path))
assert len(d["functions"]) == 22 and not d["skipped"] and len(d["globals"]) == 26
print("ok", len(d["notes"]))
