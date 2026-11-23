"""After a rename map is applied: every remaining mention of an old label in the CM848 CSVs / firmware/CLAUDE.md /
CLAUDE.md that is not a history note ("(was <old>" or inside an "earlier note:" tail).  usage: leftovers.py <repo> <map>"""
import csv
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
olds = [r["old_label"] for r in csv.DictReader(open(map_path))]
files = [os.path.join(O, n) for n in sorted(os.listdir(O)) if n.endswith(".csv")]
files += [os.path.join(repo, "firmware/CLAUDE.md"), os.path.join(repo, "CLAUDE.md")]
hits = 0
for path in files:
    for number, line in enumerate(open(path, errors="replace"), 1):
        live = line.split(" | earlier note:", 1)[0]
        for old in olds:
            for m in re.finditer(rf"\b{re.escape(old)}\b", live):
                if live[max(0, m.start() - 5):m.start()] == "(was ":
                    continue
                hits += 1
                print(f"{os.path.relpath(path, repo)}:{number}: {old} :: {live[max(0, m.start() - 60):m.end() + 40]!r}")
print("leftover mentions:", hits)
