"""Round 93 proof for the typing pass (read-only). For the rows of <pass.csv> in the new .cpp (comments removed):
- no row prints with a leading underscore any more (a wider read than the type);
- no row prints as a piece (name._0_1_ ...: a narrower read than the type);
- how many plain renders each type has now.
usage: types_proof_r93.py <after.cpp> <pass.csv>"""
import csv
import re
import sys

cpp = open(sys.argv[1], errors="replace").read()
code = re.sub(r"/\*.*?\*/", " ", cpp, flags=re.S)
code = "\n".join(l for l in code.split("\n") if not l.lstrip().startswith("//"))
words = {}
for m in re.finditer(r"[A-Za-z_][A-Za-z0-9_]*", code):
    words[m.group(0)] = words.get(m.group(0), 0) + 1
pieces = {}
for m in re.finditer(r"\b([A-Za-z_][A-Za-z0-9_]*)\._\d+_\d+_", code):
    pieces[m.group(1)] = pieces.get(m.group(1), 0) + 1
under, piece, renders = [], [], {}
for r in csv.DictReader(open(sys.argv[2])):
    name = r["name"]
    if words.get("_" + name):
        under.append((name, r["type"], words["_" + name]))
    if pieces.get(name):
        piece.append((name, r["type"], pieces[name]))
    renders[r["type"]] = renders.get(r["type"], 0) + words.get(name, 0)
print("still printed with an underscore:", len(under), under[:12])
print("printed as pieces:", len(piece), piece[:12])
print("plain renders now:", renders)
