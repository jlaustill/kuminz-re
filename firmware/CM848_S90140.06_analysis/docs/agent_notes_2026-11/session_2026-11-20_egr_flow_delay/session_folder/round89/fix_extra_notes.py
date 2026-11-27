"""Round 89 stage B fix: nine plate comments begin with the audit's framing "(Extra: not in the task list. It is
[the / a / the third] user of X.)". Keep the link, drop the framing: "It uses X." ("It is the third user of X." keeps
its count). Also teach apply_r89b.py's clean() the same rewrite. Idempotent. usage: fix_extra_notes.py <repo> <apply.py>"""
import os
import re
import sys

repo, script = os.path.abspath(sys.argv[1]), sys.argv[2]
PATTERN = re.compile(r"\(Extra: not in the task list\. It is (the|a|the third) user of ([^)]+?)\.\) ")


def rewrite(m):
    return f"It is the third user of {m.group(2)}. " if m.group(1) == "the third" else f"It uses {m.group(2)}. "


for rel in ("firmware/CM550_J90350.00_analysis/output/function_renames.csv",
            "firmware/CM848_S90140.06_analysis/output/function_renames.csv"):
    p = os.path.join(repo, rel)
    t = open(p, newline="").read()
    t2, n = PATTERN.subn(rewrite, t)
    if n:
        open(p, "w", newline="").write(t2)
    print(rel, n, "rewritten")
s = open(script).read()
old = '    r = " ".join(reason.split())\n    sentences = re.split('
new = ('    r = " ".join(reason.split())\n'
       '    r = re.sub(r"\\(Extra: not in the task list\\. It is (the|a|the third) user of ([^)]+?)\\.\\) ",\n'
       '               lambda m: (f"It is the third user of {m.group(2)}. " if m.group(1) == "the third"\n'
       '                          else f"It uses {m.group(2)}. "), r)\n'
       '    sentences = re.split(')
if "Extra: not in the task list" not in s:
    assert s.count(old) == 1
    open(script, "w").write(s.replace(old, new))
    print("clean() taught")
