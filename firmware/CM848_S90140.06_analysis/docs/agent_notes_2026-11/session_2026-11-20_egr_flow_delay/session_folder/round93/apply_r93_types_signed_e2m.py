"""Round 93 (CM550): the typed rows whose Calterm record is signed take a signed type too (e2m_width_sign_r93.py:
column 10 of the row's N record is S). The code gave no signed cast for them, but a signed constant stored into one
printed as hex once the row was an unsigned word (asg_state_x1_2000_2000 = 0x8300 for -32000).
word -> i16, dword -> i32. Idempotent. usage: apply_r93_types_signed_e2m.py <repo> <signed_rows_e2m.csv>"""
import csv
import os
import sys

repo, signed = os.path.abspath(sys.argv[1]), sys.argv[2]
G = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
NEW = {"word": "i16", "dword": "i32"}
want = {r["address"].lower(): r for r in csv.DictReader(open(signed))}
lines = open(G, newline="").read().split("\n")
done = 0
for i, line in enumerate(lines):
    key = line[:10].lower()
    if key not in want or line[10:11] != ",":
        continue
    parts = line.split(",", 3)
    r = want[key]
    assert parts[1] == r["name"], (key, parts[1])
    if parts[2] == NEW[r["type"]]:
        continue
    assert parts[2] == r["type"], (key, parts[2], r["type"])
    comment = parts[3] if len(parts) > 3 else ""
    old_note = f"typed {r['type']}: "
    new_note = f"typed {NEW[r['type']]} (its Calterm record {r['record']} is signed): "
    assert old_note in comment, (key, comment[-80:])
    lines[i] = f"{parts[0]},{r['name']},{NEW[r['type']]},{comment.replace(old_note, new_note)}"
    done += 1
if done:
    open(G, "w", newline="").write("\n".join(lines))
print(done, "rows retyped signed by their Calterm record")
