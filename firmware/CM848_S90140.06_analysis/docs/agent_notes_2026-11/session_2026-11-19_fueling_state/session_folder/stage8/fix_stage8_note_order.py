"""Stage 8 fix: apply_W13.py wrote "<comment> | earlier note: <old comment> (was <old>)"; the repo convention
(apply_renames.py, 618 rows) is "<comment> (was <old>) | earlier note: <old comment>". Moves the "(was <old>)" of every
wave-13 rename row that carries an earlier note. No agent comment contains " | earlier note: ", so the first marker is
the one the apply added.
usage: fix_stage8_note_order.py <stage8 dir> <CM848 output dir>"""
import csv
import os
import sys

here, out = sys.argv[1:3]
old_of = {r["address"]: r["old_label"] for r in csv.DictReader(open(os.path.join(here, "map_stage8.csv")))}
path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
moved = 0
for i, line in enumerate(lines):
    address = line.split(",", 1)[0]
    if address not in old_of:
        continue
    a, name, typ, comment = (line.split(",", 3) + [""])[:4]
    tail = f" (was {old_of[address]})"
    if " | earlier note: " in comment and comment.endswith(tail):
        head, earlier = comment.split(" | earlier note: ", 1)
        lines[i] = ",".join([a, name, typ, f"{head}{tail} | earlier note: {earlier[:-len(tail)]}"])
        moved += 1
open(path, "w", newline="").write("\n".join(lines))
print(f"moved the rename note on {moved} rows")
