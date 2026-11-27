"""Round 93 (CM550): the second typing pass - rows still 'undefined' that the ROM does not address directly (or
only through address loads), typed from their Calterm record (e2m_type_candidates_r93.py): the row's plain-value (N)
records give one length and one sign, no bit / table record sits on the address, the next row does not overlap, no
decoded ROM access has another width, and the decompiler never prints the row at another width. In the first pass
the record length equalled the ROM-proven width for 418 of the 419 rows that had both.
byte / i8 / word / i16 / dword / i32 by length and sign. Only the type column and a provenance note change.
A row listed in <drop.csv> (it printed with an underscore or as a piece after a build) goes back to 'undefined'.
Writes the label map (_name -> name) for the token proof. Idempotent.
usage: apply_r93_types_e2m.py <repo> <candidates.csv> <label_map.csv> [<drop.csv>]"""
import csv
import os
import sys

repo, candidates, map_out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
drop = set()
if len(sys.argv) > 4 and os.path.exists(sys.argv[4]):
    drop = {l.strip().lower() for l in open(sys.argv[4]) if l.startswith("0x")}
R = "PR #53 round 93"
G = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
LENGTH = {"byte": 1, "i8": 1, "word": 2, "i16": 2, "dword": 4, "i32": 4}
want = {r["address"].lower(): r for r in csv.DictReader(open(candidates))}
lines = open(G, newline="").read().split("\n")
done = undone = 0
pairs = []
for i, line in enumerate(lines):
    key = line[:10].lower()
    if key not in want or line[10:11] != ",":
        continue
    parts = line.split(",", 3)
    r = want[key]
    assert parts[1] == r["name"], (key, parts[1])
    typ = r["type"]
    signed = "signed" if typ.startswith("i") else "unsigned"
    note = f"typed {typ}: Calterm record {r['record']} is {LENGTH[typ]} byte{'s' if LENGTH[typ] > 1 else ''} {signed} ({R})"
    comment = parts[3] if len(parts) > 3 else ""
    if key in drop:
        if parts[2] == typ:
            base = comment.replace(" | " + note, "").replace(note, "")
            lines[i] = f"{parts[0]},{r['name']},undefined,{base}"
            undone += 1
        continue
    if LENGTH[typ] > 1:
        pairs.append((parts[0], r["name"], "_" + r["name"]))
    if parts[2] == typ:
        continue
    assert parts[2] == "undefined", (key, parts[2])
    lines[i] = f"{parts[0]},{r['name']},{typ},{comment + ' | ' if comment else ''}{note}"
    done += 1
if done or undone:
    open(G, "w", newline="").write("\n".join(lines))
with open(map_out, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for a, new, old in pairs:
        fh.write(f"{a},{new},{old},symbol,1\n")
print(f"{done} rows typed; {undone} rows set back to undefined; {len(pairs)} wide rows in the label map")
