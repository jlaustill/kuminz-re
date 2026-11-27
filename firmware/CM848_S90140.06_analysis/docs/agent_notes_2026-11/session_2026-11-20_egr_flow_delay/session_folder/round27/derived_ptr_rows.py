"""Round 27: Ghidra's derived pointer labels PTR_<target name>_<address> carry a renamed target's name. For the proof
only: map each new PTR_ label that holds a new name back to the old label (the old name or Ghidra label in its place)
and check that the old label exists in the old .cpp. Writes <proof map> = <map> + those rows.
usage: derived_ptr_rows.py <old cpp> <new cpp> <map.csv> <proof_map.csv>"""
import csv
import re
import sys

old_cpp, new_cpp, map_path, out = sys.argv[1:5]
rows = list(csv.DictReader(open(map_path)))
pairs = sorted(((r["name"], r["old_label"]) for r in rows if r["kind"] != "local"), key=lambda p: -len(p[0]))
old_labels = set(re.findall(r"\bPTR_[A-Za-z0-9_]+", open(old_cpp).read()))
new_labels = set(re.findall(r"\bPTR_[A-Za-z0-9_]+", open(new_cpp).read()))
extra = []
for label in sorted(new_labels - old_labels):
    for new, old in pairs:
        if label.startswith(f"PTR_{new}_"):
            back = f"PTR_{old}_" + label[len(f"PTR_{new}_"):]
            assert back in old_labels, (label, back)
            extra.append({"address": "", "name": label, "old_label": back, "kind": "global"})
            break
    else:
        raise SystemExit(f"no map row explains {label}")
with open(out, "w", newline="") as fh:
    w = csv.DictWriter(fh, fieldnames=["address", "name", "old_label", "kind"])
    w.writeheader()
    w.writerows(rows + extra)
print(f"{len(extra)} derived PTR_ rows; {len(old_labels - new_labels)} old-only, {len(new_labels - old_labels)} new-only labels")
