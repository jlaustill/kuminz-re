"""Round 93 (CM550): type the global rows that were 'undefined' and whose width has two witnesses
(untyped_width_scan_r93.py + untyped_cpp_check_r93.py):
- the ROM: every aligned occurrence of the row's address is the operand of an instruction of one size (byte / word /
  long), there is no access to the bytes inside that width, and the next row does not start inside it;
- the decompiler: a word / dword row prints only with a leading underscore (read wider than its 1 byte), a byte row
  only plain.
An 'undefined' row is 1 byte to Ghidra, so every word or long read of it printed as _name and its type was guessed
per use. Pointers (a movea.l load) are left out: their type should name the pointee.
Only the type column and a short provenance note change; no name changes. Writes a label map (_name -> name) for
the token proof. Idempotent. usage: apply_r93_types.py <repo> <pass.csv> <label_map.csv>"""
import csv
import os
import sys

repo, passed, map_out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
R = "PR #53 round 93"
G = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
want = {}
for r in csv.DictReader(open(passed)):
    want[r["address"].lower()] = (r["name"], r["type"])
scan = {}
scan_path = os.path.join(os.path.dirname(os.path.abspath(passed)), "untyped_width_scan_r93.tsv")
for r in csv.DictReader(open(scan_path), delimiter="\t"):
    scan[r["address"].lower()] = int(r["occurrences"])
lines = open(G, newline="").read().split("\n")
done, pairs = 0, []
for i, line in enumerate(lines):
    key = line[:10].lower()
    if key not in want or line[10:11] != ",":
        continue
    parts = line.split(",", 3)
    name, typ = want[key]
    assert parts[1] == name, (key, parts[1], name)
    if parts[2] == typ:
        continue
    assert parts[2] == "undefined", (key, parts[2])
    n = scan[key]
    unit = {"byte": "byte", "word": "word", "dword": "long"}[typ]
    note = f"typed {typ}: {n} {unit} access{'es' if n != 1 else ''} in the ROM and no other ({R})"
    comment = parts[3] if len(parts) > 3 else ""
    lines[i] = f"{parts[0]},{name},{typ},{comment + ' | ' if comment else ''}{note}"
    done += 1
    if typ != "byte":
        pairs.append((parts[0], name, "_" + name))
if done:
    open(G, "w", newline="").write("\n".join(lines))
    with open(map_out, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for a, new, old in pairs:
            fh.write(f"{a},{new},{old},symbol,1\n")
print(f"{done} rows typed ({len(pairs)} word / dword rows in the label map)")
