"""Round 94 (read-only): a batch's CM848-only function renames with their verdicts and roles, and its globals.
usage: show_cm848_functions_r94.py <batch_X.json>"""
import json
import sys

d = json.load(open(sys.argv[1]))


def key(a):
    return a.lower().replace("0x", "").lstrip("0")


v = {(x["kind"], key(x["address"])): x for x in d["verdict"]["verdicts"]}
for f in d["proposal"].get("cm848_functions") or []:
    x = v.get(("cm848_function", key(f["address"])), {})
    print(f["address"], f["current_name"], "->", x.get("final_name") or f["proposed_name"], "|", x.get("verdict"), "|", f["role"][:110])
for g in d["proposal"].get("globals") or []:
    print("G", g["firmware"], g["address"], g["current_name"], "->", g["proposed_name"], g["proposed_type"])
