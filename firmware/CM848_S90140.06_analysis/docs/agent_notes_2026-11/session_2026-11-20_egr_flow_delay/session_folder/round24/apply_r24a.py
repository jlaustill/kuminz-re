"""Round 24 stage A (comments): refresh the CSV comments' present-tense Ghidra labels to the names their addresses now
have (round 23's stale_ghidra_labels.py lead), by classify_labels.py's review plus these rules, from reading every
REVIEW hit:
- only comment columns (global_variables 4th, function_renames 3rd, structure_definitions 6th, enums 4th, arrays 5th);
  the dotted alias rows' names (instance_label.field) stay;
- KEEP: '#' lines (legacy notes, some describing old guesses), an 'earlier note:' tail, a history word just before
  the label ('(was', 'renamed from', 'render', 'label', ...), a comment that opens with the row's own former label
  ('DAT_003fd90c: ...'), a rename arrow ('LABEL -> name'), and a target that is an offset name ('x+2');
- REPLACE: the rest.
Prints every replacement. usage: apply_r24a.py <repo> <out.tsv> [--apply]"""
import csv
import io
import os
import re
import sys

repo, out_path = os.path.abspath(sys.argv[1]), sys.argv[2]
apply = "--apply" in sys.argv
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
names = {}
for l in open(os.path.join(out, "global_variables.csv")):
    if l.startswith("0x"):
        a, n = l.split(",", 2)[:2]
        if n:
            names[int(a, 16)] = n
LABEL = re.compile(r"\b(?:DAT|WORD|DWORD|BYTE|WORD_ARRAY|DWORD_ARRAY|BYTE_ARRAY|PTR_[A-Za-z0-9_]+?|[a-z_0-9]+_t)_00([0-9a-f]{6})\b")
HISTORY = re.compile(r"(\(was|\bwas|\bwere|renamed|render|shows|showed|formerly|previously|\blabel|Ghidra|named after|"
                     r"\bold\b|auto-?name|placeholder)[^|;.]{0,40}$", re.I)
COMMENT_COLUMN = {"global_variables.csv": 3, "function_renames.csv": 2, "structure_definitions.csv": 5,
                  "enums.csv": 3, "arrays.csv": 4}
log = []
for name, col in COMMENT_COLUMN.items():
    p = os.path.join(out, name)
    if not os.path.exists(p):
        continue
    lines = open(p).read().split("\n")
    changed = 0
    for i, line in enumerate(lines):
        if not line or line.startswith("#"):
            continue
        # global_variables / function_renames / arrays keep the comment as unquoted text after a fixed number of commas
        # (it may contain commas); structure_definitions / enums quote it
        if name in ("global_variables.csv", "function_renames.csv", "arrays.csv"):
            fields = line.split(",", col)
        else:
            fields = next(csv.reader(io.StringIO(line)))
        if len(fields) <= col:
            continue
        own = int(fields[0], 16) if re.fullmatch(r"0x[0-9a-fA-F]+", fields[0] or "") else None
        comment = fields[col]
        if not LABEL.search(comment):
            continue

        def repl(m):
            a = int(m.group(1), 16)
            if a not in names:
                return m.group(0)
            label, target = m.group(0), names[a]
            before = comment[:m.start()]
            after = comment[m.end():m.end() + 4]
            keep = (label == target or "+" in target or "earlier note:" in before or HISTORY.search(before)
                    or (a == own and before.strip() == "") or after.startswith(" ->") or after.startswith("->"))
            if keep:
                return label
            log.append((name, i + 1, label, target, comment[max(0, m.start() - 60):m.end() + 30]))
            return target

        new_comment = LABEL.sub(repl, comment)
        if new_comment != comment:
            # rewrite only the comment field, inside the original line (keeps the other fields' quoting)
            assert line.count(comment) == 1, (name, i + 1)
            lines[i] = line.replace(comment, new_comment, 1)
            changed += 1
    if apply and changed:
        open(p, "w").write("\n".join(lines))
with open(out_path, "w") as fh:
    w = csv.writer(fh, delimiter="\t")
    w.writerow(["file", "line", "label", "name", "context"])
    w.writerows(log)
from collections import Counter
print(len(log), "replacements", dict(Counter(r[0] for r in log)))
