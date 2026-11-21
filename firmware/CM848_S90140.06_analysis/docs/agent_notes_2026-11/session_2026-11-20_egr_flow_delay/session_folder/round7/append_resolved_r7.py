"""Append to each task file that still cites round 4's old names a short section listing, for each name it cites
(outside history), what PR #53 round 7 renamed it to. History lines stay as they are.
usage: append_resolved_W15.py <repo> <map.csv> <task file>..."""
import csv
import os
import re
import sys

repo, mapping = os.path.abspath(sys.argv[1]), sys.argv[2]
new_of = {}
for r in csv.DictReader(open(mapping)):
    if r.get("old_label") and r["old_label"] != r["name"]:
        new_of[r["old_label"]] = r["name"]
pattern = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(map(re.escape, sorted(new_of, key=len, reverse=True))) +
                     r")(?![A-Za-z0-9_])")
for rel in sys.argv[3:]:
    path = os.path.join(repo, rel)
    text = open(path).read()
    if "## Resolved by PR #53 round 7" in text:
        print(f"{rel}: already marked")
        continue
    found = []
    for line in text.split("\n"):
        live = re.sub(r"\(was [^)]*\)", "", line)
        for m in pattern.finditer(live):
            if m.group(1) not in found:
                found.append(m.group(1))
    if not found:
        print(f"{rel}: none")
        continue
    block = ["", "## Resolved by PR #53 round 7 (2026-11-21)", "",
             "The old names this file cites were renamed in PR #53 (the leads above keep their wording):"]
    block += [f"- `{old}` → `{new_of[old]}`" for old in found]
    open(path, "w").write(text.rstrip("\n") + "\n" + "\n".join(block) + "\n")
    print(f"{rel}: {len(found)} names")
