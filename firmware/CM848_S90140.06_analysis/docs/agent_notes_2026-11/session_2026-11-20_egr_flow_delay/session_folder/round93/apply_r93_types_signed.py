"""Round 93 (CM550): the typed rows that the code reads as signed take a signed type. signedness_r93.py found them
from the decompiler's casts: typed as unsigned word / dword they print '(short)name' / '(int)name' at signed uses, and
before typing none of their uses printed an unsigned cast. word -> i16, dword -> i32 (the importer's names for the
signed 16 / 32 bit types). Rows with casts of both kinds (7) stay unsigned. Idempotent.
usage: apply_r93_types_signed.py <repo> <signed_rows.csv>"""
import csv
import os
import sys

repo, signed = os.path.abspath(sys.argv[1]), sys.argv[2]
G = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
NEW = {"word": "i16", "dword": "i32"}
want = {r["address"].lower(): (r["name"], r["type"]) for r in csv.DictReader(open(signed))}
lines = open(G, newline="").read().split("\n")
done = 0
for i, line in enumerate(lines):
    key = line[:10].lower()
    if key not in want or line[10:11] != ",":
        continue
    parts = line.split(",", 3)
    name, typ = want[key]
    assert parts[1] == name, (key, parts[1])
    if parts[2] == NEW[typ]:
        continue
    assert parts[2] == typ, (key, parts[2], typ)
    comment = parts[3] if len(parts) > 3 else ""
    old_note, new_note = f"typed {typ}: ", f"typed {NEW[typ]} (the code reads it signed): "
    assert old_note in comment, (key, comment[-80:])
    lines[i] = f"{parts[0]},{name},{NEW[typ]},{comment.replace(old_note, new_note)}"
    done += 1
if done:
    open(G, "w", newline="").write("\n".join(lines))
print(done, "rows retyped signed")
