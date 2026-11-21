"""Drop the doubled leading e2m record that add_e2m_prefix_W15.py / the fixed apply put before a role text that already
starts with the same record (the five injector driver period rows of 10b-5).
usage: dedupe_e2m_prefix_W15.py <repo>"""
import os
import re
import sys

path = os.path.join(os.path.abspath(sys.argv[1]), "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
lines = open(path, newline="").read().split("\n")
fixed = 0
for i, line in enumerate(lines):
    if not line.startswith("0x"):
        continue
    a, name, typ, comment = (line.split(",", 3) + [""])[:4]
    m = re.match(r"(e2m (\S+) \+(\S+) (\S+) '[^']*' \([^)]*\): )(e2m \2 \+\3 \4 .*)", comment)
    if m:
        lines[i] = ",".join([a, name, typ, m.group(5)])
        fixed += 1
open(path, "w", newline="").write("\n".join(lines))
print(f"deduplicated {fixed} comments")
