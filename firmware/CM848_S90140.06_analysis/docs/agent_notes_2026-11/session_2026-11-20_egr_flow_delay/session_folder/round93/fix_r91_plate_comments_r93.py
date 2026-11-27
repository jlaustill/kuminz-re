"""Round 93 fix of a round 91 defect (CM848 function_renames.csv): seven twin rows lost their plate comment. The
round 91 proposal's plate text for them was the instruction 'APPEND to the current comment: | (...)', and
apply_r91.py wrote that text in place of the comment. This restores each comment from the commit before round 91
(900ff89c~1, passed as a file), refreshes the function names round 91 renamed inside it (not after 'was'), and
appends the twin note once. Idempotent. usage: fix_r91_plate_comments_r93.py <repo> <function_renames before r91>"""
import os
import re
import sys

repo, before_path = os.path.abspath(sys.argv[1]), sys.argv[2]
P = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/function_renames.csv")
before = {}
for line in open(before_path, newline="").read().split("\n"):
    parts = line.split(",", 2)
    if len(parts) == 3 and parts[0].startswith("0x"):
        before[parts[0]] = (parts[1], parts[2])
lines = open(P, newline="").read().split("\n")
renamed = {}          # old name -> new name, for the rows this fixes
damaged = []
for i, line in enumerate(lines):
    parts = line.split(",", 2)
    if len(parts) == 3 and parts[2].startswith("APPEND to the current comment:"):
        damaged.append(i)
        renamed[before[parts[0]][0]] = parts[1]
fixed = 0
for i in damaged:
    address, name, text = lines[i].split(",", 2)
    old_name, old_comment = before[address]
    m = re.match(r"^APPEND to the current comment: \| \(was (\w+); (PR #53 round 91); (.+?)\) \(was \1; \2\)\s*$", text)
    assert m and m.group(1) == old_name, lines[i][:120]
    note = m.group(3)
    for old, new in renamed.items():      # a reference to a renamed twin, but never the name after 'was'
        old_comment = re.sub(rf"(?<!was ){re.escape(old)}\b", new, old_comment)
    lines[i] = f"{address},{name},{old_comment} | {note} (was {old_name}; PR #53 round 91)"
    fixed += 1
if fixed:
    open(P, "w", newline="").write("\n".join(lines))
print(f"{fixed} plate comments restored")
