"""Round 97: review a unified diff (-U0) of stage A: report header-line hunks (line 1) and print the changed lines of
the files whose changes are free-text rewrites (not the name columns), for reading. usage: review_stage_a_diff_r97.py <diff>"""
import re
import sys

NAME_FILES = ("function_definitions.csv", "local_variables.csv", "structure_definitions.csv")
cur = None
for line in open(sys.argv[1], errors="replace"):
    if line.startswith("+++ b/"):
        cur = line[6:].strip()
        continue
    m = re.match(r"^@@ -(\d+)", line)
    if m and m.group(1) == "1":
        print("HEADER HUNK:", cur)
    if cur and not cur.endswith(NAME_FILES) and line[:1] in "+-" and not line.startswith(("+++", "---")):
        print(f"{cur.split('/')[-1]}: {line[:200].rstrip()}")
