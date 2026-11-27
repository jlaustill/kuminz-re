"""Round 94 (read-only): a batch proposal's functions, the globals in an address range, its enum members and the set
of types it proposes. usage: show_proposal_r94.py <batch_X.json> [<lo hex> <hi hex>]"""
import json
import sys

d = json.load(open(sys.argv[1]))
lo, hi = (int(sys.argv[2], 16), int(sys.argv[3], 16)) if len(sys.argv) > 3 else (0, 0)
p = d["proposal"]
for f in p.get("functions") or []:
    print(hex(int(f["address"], 16)), f["current_name"], "->", f["proposed_name"], f["relation"], f.get("cm848_address") or "", f["confidence"])
if hi:
    print("globals in range:", [(g["address"], g["current_name"], g["proposed_name"]) for g in p.get("globals") or [] if lo <= int(g["address"], 16) <= hi])
print("enum members:", [(e["enum_name"], e["value"], e["proposed_member"]) for e in p.get("enum_members") or []])
print("types:", sorted({g["proposed_type"] for g in p.get("globals") or []}))
