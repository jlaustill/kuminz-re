"""Round 96: the CM550 global rows in HEAD's file that sat in [start, end) and are gone now; print each removed name that
is still cited anywhere in the firmware CSVs / docs / CLAUDE.md (word-bounded), with the file.
usage: removed_names_cited_r96.py <repo> <head global_variables.csv> <hex start> <hex end>"""
import glob
import os
import re
import sys

repo, head, start, end = os.path.abspath(sys.argv[1]), sys.argv[2], int(sys.argv[3], 16), int(sys.argv[4], 16)
names = []
for line in open(head, newline=""):
    p = line.rstrip("\r\n").split(",", 2)
    if len(p) > 1 and p[0].startswith("0x") and p[1] and start <= int(p[0], 16) < end:
        names.append(p[1])
files = glob.glob(os.path.join(repo, "firmware/*/output/*.csv")) + glob.glob(os.path.join(repo, "firmware/*/docs/*.md"))
files += [os.path.join(repo, "firmware/CLAUDE.md")]
texts = {f: open(f, errors="replace").read() for f in files}
cited = 0
for n in names:
    pat = re.compile(r"(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])" % re.escape(n))
    where = [os.path.relpath(f, repo) for f, t in texts.items() if pat.search(t)]
    if where:
        cited += 1
        print(n, "->", ", ".join(where[:3]))
print(len(names), "removed names;", cited, "still cited")
