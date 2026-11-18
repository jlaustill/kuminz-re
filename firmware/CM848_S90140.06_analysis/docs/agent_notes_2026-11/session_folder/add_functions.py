"""Append function rows for addresses Ghidra never made functions (result rows with old = "").
Usage: add_functions.py <function_renames.csv> <aligned results...>"""
import json
import sys

path, files = sys.argv[1], sys.argv[2:]
lines = open(path).read().split("\n")
addresses = {int(l.split(",")[0], 16) for l in lines if l.startswith("0x")}
names = {l.split(",")[1] for l in lines if l.startswith("0x") and len(l.split(",")) > 1}
new = []
for f in files:
    for l in open(f):
        r = json.loads(l) if l.strip() else {}
        if r.get("kind") == "function" and r.get("old") == "" and r.get("verdict") == "confirmed" and r.get("new"):
            a = int(r["address"], 16)
            assert a not in addresses and r["new"] not in names, (hex(a), r["new"])
            new.append(f"0x{a:08x},{r['new']},{' '.join(r.get('plate_comment', '').split())}")
tail = lines.pop() if lines and lines[-1] == "" else None
lines += new
if tail is not None:
    lines.append(tail)
open(path, "w").write("\n".join(lines))
print("new function rows:", len(new))
