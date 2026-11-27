"""Print every comment-only change a commit made to a CSV (rows whose address is not a renamed row of the map), as
old -> new word runs, to check that the reference refresh did not rewrite a history mention.
usage: refresh_audit.py <repo> <commit> <map.csv> <file>..."""
import csv
import difflib
import os
import subprocess
import sys

repo, commit, map_path, *files = sys.argv[1:]
renamed = {r["address"].lower() for r in csv.DictReader(open(map_path)) if r.get("address")}
for f in files:
    diff = subprocess.run(["git", "-C", repo, "show", commit, "--format=", "--unified=0", "--", f],
                          capture_output=True, text=True).stdout.split("\n")
    minus = [l[1:] for l in diff if l.startswith("-") and not l.startswith("---")]
    plus = [l[1:] for l in diff if l.startswith("+") and not l.startswith("+++")]
    for a, b in zip(minus, plus):
        addr = a.split(",", 1)[0].lower()
        if addr in renamed:
            continue
        sm = difflib.SequenceMatcher(None, a, b)
        for op, i1, i2, j1, j2 in sm.get_opcodes():
            if op != "equal":
                print(f"{f} {addr}: ...{a[max(0, i1 - 60):i1]}[{a[i1:i2]} -> {b[j1:j2]}]{a[i2:i2 + 30]}")
