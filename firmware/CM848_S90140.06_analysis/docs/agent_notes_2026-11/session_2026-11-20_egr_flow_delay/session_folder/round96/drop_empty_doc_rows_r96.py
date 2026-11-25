"""Round 96 stage B: the eight documentation rows that stale_doc_rows_r96.py renamed carry no text of their own (only a
name that repeats the struct field at that offset), so they go. Each must still be exactly the renamed, empty row.
usage: drop_empty_doc_rows_r96.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
DROP = {"0x003024f8", "0x00302882", "0x00302886", "0x003045e2", "0x003045e6", "0x00305186", "0x00305188", "0x0030518a"}
keep, dropped = [], 0
for line in lines:
    if line.split(",", 1)[0].lower() in DROP:
        parts = line.split(",", 3)
        assert parts[2] == "" and parts[3].startswith("(was ") and parts[3].endswith("the covering row was renamed; PR #53 round 96)"), line
        dropped += 1
        continue
    keep.append(line)
if dropped:
    assert dropped == 8, dropped
    open(p, "w", newline="").write(E.join(keep))
print("dropped", dropped)
