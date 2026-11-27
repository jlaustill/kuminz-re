"""Find history notes a reference refresh rewrote: a "was <name>" / "(was <name>" / "formerly <name>" whose <name> is a
NEW name from one of the maps (a history note should keep the OLD name). Scans every CM848 output CSV.
usage: history_corruption.py <repo> <map>..."""
import csv
import os
import re
import sys

repo, maps = os.path.abspath(sys.argv[1]), sys.argv[2:]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
pairs = {}
for m in maps:
    for r in csv.DictReader(open(m)):
        if r["name"] and r["old_label"] and r["name"] != r["old_label"]:
            pairs[r["name"]] = r["old_label"]
pattern = re.compile(r"(\bwas|\bwere|formerly|\(was)\s+`?(" + "|".join(map(re.escape, sorted(pairs, key=len,
                                                                                         reverse=True))) + r")\b")
hits = 0
for name in sorted(os.listdir(O)):
    if not name.endswith(".csv"):
        continue
    for number, line in enumerate(open(os.path.join(O, name), errors="replace"), 1):
        for m in pattern.finditer(line):
            hits += 1
            print(f"{name}:{number}: '{m.group(0)}' (old: {pairs[m.group(2)]}) :: {line.strip()[:110]}")
print("suspect history notes:", hits)
