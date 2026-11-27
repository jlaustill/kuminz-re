"""The PR body's '**Round N.**' headings (rounds 28-84) follow the last line of the bullet above them with no blank line,
so CommonMark reads each one as a lazy continuation line: GitHub shows it at the end of the previous round's last bullet.
This adds the blank line before each such heading. Idempotent.  usage: fix_pr_body_round_headings_r84.py <pr_body.md>"""
import re
import sys

path = sys.argv[1]
lines = open(path).read().split("\n")
out = []
fixed = 0
for i, line in enumerate(lines):
    if re.match(r"^\*\*Round \d+[^*]*\*\*", line) and out and out[-1].strip():
        out.append("")
        fixed += 1
    out.append(line)
open(path, "w").write("\n".join(out))
print(f"{fixed} round headings separated from the bullet above")
