"""Round 93 (read-only): the final types of the rows typed this round, and the scan's verdict counts.
usage: types_counts_r93.py <repo> <dir>"""
import collections
import csv
import os
import sys

repo, w = os.path.abspath(sys.argv[1]), sys.argv[2]
passed = {r["address"].lower() for r in csv.DictReader(open(os.path.join(w, "untyped_pass_r93.csv")))}
final = collections.Counter()
for line in open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv"), newline="").read().split("\n"):
    if line[:10].lower() in passed and line[10:11] == ",":
        final[line.split(",")[2]] += 1
print("final types:", dict(final), "total", sum(final.values()))
print("signed by casts:", dict(collections.Counter(r["type"] for r in csv.DictReader(open(os.path.join(w, "signed_rows_r93.csv"))))))
print("signed by the Calterm record:", dict(collections.Counter(r["type"] for r in csv.DictReader(open(os.path.join(w, "signed_rows_e2m_r93.csv"))))))
print("scan verdicts:", dict(collections.Counter(r["verdict"] for r in csv.DictReader(open(os.path.join(w, "untyped_width_scan_r93.tsv")), delimiter="\t"))))
