"""Round 90 (read-only): split the CM550 naming wave's candidates into investigator batches (about 20-28 each, kept
together by e2m block / address so related records share one agent). usage: make_batches_r90.py <wave dir>"""
import csv
import os
import sys

d = sys.argv[1]
A = list(csv.DictReader(open(os.path.join(d, "candidates_A.tsv")), delimiter="\t"))
B = list(csv.DictReader(open(os.path.join(d, "candidates_B.tsv")), delimiter="\t"))
C = list(csv.DictReader(open(os.path.join(d, "candidates_C.tsv")), delimiter="\t"))
batches = []
blocks = {}
for r in A:
    blocks.setdefault(r["block"], []).append(r)
a1 = blocks.pop("12E8", [])
a2 = blocks.pop("12A7", []) + blocks.pop("1216", [])
a3 = [r for rs in blocks.values() for r in rs]
for name, rows in (("A1", a1), ("A2", a2), ("A3", a3)):
    batches.append((name, "A", rows))
batches.append(("B1", "B", B))
C.sort(key=lambda r: int(r["address"], 16))
third = (len(C) + 2) // 3
for i in range(3):
    batches.append((f"C{i + 1}", "C", C[i * third:(i + 1) * third]))
for name, group, rows in batches:
    path = os.path.join(d, f"batch_{name}.tsv")
    with open(path, "w") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0]), delimiter="\t")
        w.writeheader()
        w.writerows(rows)
    print(name, group, len(rows), path)
