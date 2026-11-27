"""Round 97: in the working-tree diff (-U0, given as a file), '+' lines whose history notes ('was ...', 'removed ...',
'were ...') now hold a NEW name from the stage A plan (a rewrite of history). usage: history_rewrites_r97.py <diff> <plan.csv>"""
import csv
import re
import sys

news = {r["new"] for r in csv.DictReader(open(sys.argv[2]))}
pat = re.compile(r"\b(was|were|removed|old)\b[^;)|]{0,120}")
cur = None
n = 0
for line in open(sys.argv[1], errors="replace"):
    if line.startswith("+++ b/"):
        cur = line[6:].strip()
        continue
    if line.startswith("+") and not line.startswith("+++"):
        for m in pat.finditer(line):
            span = m.group(0)
            hit = [w for w in news if re.search(r"(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])" % re.escape(w), span)]
            if hit:
                n += 1
                print(f"{cur.split('/')[-1]}: {hit} in {span[:150]!r}")
print(n, "history spans hold a new name")
