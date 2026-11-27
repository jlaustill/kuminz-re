"""Round 97: drop the doubled round tag the apply appended after a comment that already ends with '...; PR #53 round 97)'.
usage: fix_double_tag_r97.py <csv>..."""
import re
import sys
pat = re.compile(r"(PR #53 round 97\)) \(PR #53 round 97\)(?=\r?$)", re.M)
for p in sys.argv[1:]:
    t = open(p, newline="").read()
    n = len(pat.findall(t))
    if n:
        open(p, "w", newline="").write(pat.sub(r"\1", t))
    print(p.split("/")[-3][:5], p.split("/")[-1], n)
