"""Like refresh_audit.py, for the uncommitted working tree: print every comment-only change to a CSV on rows whose
address is not a renamed row of the map. usage: worktree_refresh_audit.py <repo> <map.csv> <file>..."""
import csv
import difflib
import subprocess
import sys

repo, map_path, *files = sys.argv[1:]
renamed = {r["address"].lower() for r in csv.DictReader(open(map_path)) if r.get("address")}
for f in files:
    diff = subprocess.run(["git", "-C", repo, "diff", "--unified=0", "--", f], capture_output=True, text=True).stdout
    lines = diff.split("\n")
    minus = [l[1:] for l in lines if l.startswith("-") and not l.startswith("---")]
    plus = [l[1:] for l in lines if l.startswith("+") and not l.startswith("+++")]
    for a, b in zip(minus, plus):
        key = a.split(",", 1)[0].lower()
        if key in renamed:
            continue
        sm = difflib.SequenceMatcher(None, a, b)
        for op, i1, i2, j1, j2 in sm.get_opcodes():
            if op != "equal":
                print(f"{f.split('/')[-1]} {key}: ...{a[max(0, i1 - 70):i1]}[{a[i1:i2]} -> {b[j1:j2]}]{a[i2:i2 + 30]}")
