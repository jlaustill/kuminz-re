"""Round 55: refresh_references.py does not cover structure_definitions.csv, so fault_status_record_t's field comments
still named four of the renamed functions. Replace them (whole words). Idempotent.
usage: refresh_struct_comments_r55.py <repo> <map.csv>"""
import csv
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
t = open(p).read()
n = 0
for r in csv.DictReader(open(map_path)):
    t, k = re.subn(rf"\b{re.escape(r['old_label'])}\b", r["name"], t)
    n += k
open(p, "w").write(t)
print(f"{n} mentions refreshed")
