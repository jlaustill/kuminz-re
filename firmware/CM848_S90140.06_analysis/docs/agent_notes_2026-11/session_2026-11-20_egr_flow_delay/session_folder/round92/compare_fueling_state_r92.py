"""Round 92 (read-only): CM848's FUELING_STATE members against CM550's e2m FSFNFLST labels (v64t6_s.e2m), code by code:
the label each firmware's member quotes, and whether they agree. usage: compare_fueling_state_r92.py <repo>"""
import csv
import os
import re
import sys

repo = sys.argv[1]
labels = {}
for line in open(os.path.join(repo, "e2m-analysis/originals/v64t6_s.e2m"), encoding="latin-1"):
    if line.startswith("FSFNFLST,"):
        data = line.split(";", 1)[0].split(",")
        if len(data) > 15 and "=" in data[15]:
            k, v = data[15].split("=", 1)
            labels[int(k, 16)] = v.strip()
members = {}
for row in csv.reader(open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/enums.csv"), newline="")):
    if row and row[0] == "FUELING_STATE":
        try:
            members[int(row[1], 0)] = (row[2], row[3] if len(row) > 3 else "")
        except ValueError:
            pass
agree = differ = 0
for code in sorted(set(labels) | set(k for k in members if k <= 0x29)):
    lab = labels.get(code, "")
    name, comment = members.get(code, ("", ""))
    m = re.search(r"\b([A-Z_0-9]{3,12})\b", comment)
    quoted = lab in comment if lab else False
    if quoted:
        agree += 1
    else:
        differ += 1
    print(f"{code:3} 0x{code:02x} CM550 {lab:10} CM848 {name:52} {'agrees' if quoted else 'DIFFERS: ' + comment[:70]}")
print(f"{agree} agree, {differ} differ; CM848 members above 0x29: {sorted(k for k in members if k > 0x29)}")
