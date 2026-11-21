"""Replace the names of struct member rows a shape stage removed with <instance>.<field> in the CSV comments, plates,
firmware/CLAUDE.md and the given docs (word-bounded; "(was ...)" history keeps the old name).
usage: replace_member_refs.py <repo> <removed.csv: address,old_name,now> <file>..."""
import csv
import os
import re
import sys

repo, removed = os.path.abspath(sys.argv[1]), sys.argv[2]
pairs = [(r["old_name"], r["now"]) for r in csv.DictReader(open(removed))]
pairs.sort(key=lambda p: len(p[0]), reverse=True)
for rel in sys.argv[3:]:
    path = os.path.join(repo, rel)
    text = open(path, newline="").read()
    count = 0
    out_lines = []
    for line in text.split("\n"):
        # keep "(was X)" history: split it out, replace in the rest
        parts = re.split(r"(\(was [^)]*\))", line)
        for k in range(0, len(parts), 2):
            for old, new in pairs:
                parts[k], n = re.subn(r"(?<![A-Za-z0-9_.])" + re.escape(old) + r"(?![A-Za-z0-9_])", new, parts[k])
                count += n
        out_lines.append("".join(parts))
    if count:
        open(path, "w", newline="").write("\n".join(out_lines))
    print(f"{rel}: {count}")
