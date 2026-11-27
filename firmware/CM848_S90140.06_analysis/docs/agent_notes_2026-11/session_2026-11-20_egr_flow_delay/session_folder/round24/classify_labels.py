"""Round 24: classify the CSV comments' Ghidra labels whose address now has a named row (round 23's
stale_ghidra_labels.py found 276) before any replacement.
- KEEP (history): the hit sits in an 'earlier note:' tail, or a history word comes just before it ('(was', 'was',
  'were', 'rendered', 'renders', 'render', 'showed', 'shows', 'formerly', 'previously', 'label', 'Ghidra', 'named
  after', 'old'), or it is quoted;
- SKIP: the row's name is the label itself (names that look like labels);
- REVIEW: the rest - printed with context for a by-eye decision.
usage: classify_labels.py <repo> <out.tsv>"""
import csv
import os
import re
import sys

repo, out_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
names = {}
for l in open(os.path.join(out, "global_variables.csv")):
    if l.startswith("0x"):
        a, n = l.split(",", 2)[:2]
        if n:
            names[int(a, 16)] = n
LABEL = re.compile(r"\b(?:DAT|WORD|DWORD|BYTE|WORD_ARRAY|DWORD_ARRAY|BYTE_ARRAY|PTR_[A-Za-z0-9_]+?|[a-z_0-9]+_t)_00([0-9a-f]{6})\b")
HISTORY = re.compile(r"(\(was|\bwas|\bwere|render|shows|showed|formerly|previously|\blabel|Ghidra|named after|\bold\b|"
                     r"auto-?name|placeholder)[^|;.]{0,40}$", re.I)
rows = []
for name in ("global_variables.csv", "function_renames.csv", "structure_definitions.csv", "enums.csv", "arrays.csv"):
    p = os.path.join(out, name)
    if not os.path.exists(p):
        continue
    for lineno, line in enumerate(open(p), 1):
        for m in LABEL.finditer(line):
            a = int(m.group(1), 16)
            if a not in names:
                continue
            label, target = m.group(0), names[a]
            before = line[:m.start()]
            if label == target:
                verdict = "SKIP"
            elif "earlier note:" in before or HISTORY.search(before) or before.rstrip().endswith("'"):
                verdict = "KEEP"
            else:
                verdict = "REVIEW"
            ctx = line[max(0, m.start() - 90):m.end() + 40].replace("\t", " ").replace("\n", " ")
            rows.append((verdict, name, lineno, label, target, ctx))
with open(out_path, "w") as fh:
    w = csv.writer(fh, delimiter="\t")
    w.writerow(["verdict", "file", "line", "label", "name", "context"])
    w.writerows(rows)
from collections import Counter
print(Counter(r[0] for r in rows))
