"""Keyed version of worktree_refresh_audit.py: compares HEAD and the working tree row by row (key = address + name)
for rows whose address is not a renamed row of the map, so an inserted row cannot misalign the pairs.
usage: keyed_refresh_audit.py <repo> <map.csv> <csv file>..."""
import csv
import difflib
import subprocess
import sys

repo, map_path, *files = sys.argv[1:]
renamed = {r["address"].lower() for r in csv.DictReader(open(map_path)) if r.get("address")}


def keyed(lines):
    d = {}
    for line in lines:
        if line.startswith("0x"):
            parts = line.split(",", 2)
            d.setdefault(parts[0].lower() + "|" + (parts[1] if len(parts) > 1 else ""), line)
    return d


for f in files:
    head = subprocess.run(["git", "-C", repo, "show", f"HEAD:{f}"], capture_output=True, text=True).stdout.split("\n")
    now = open(f"{repo}/{f}").read().split("\n")
    h, n = keyed(head), keyed(now)
    for k in sorted(set(h) & set(n)):
        a = k.split("|")[0]
        if a in renamed or h[k] == n[k]:
            continue
        sm = difflib.SequenceMatcher(None, h[k], n[k])
        for op, i1, i2, j1, j2 in sm.get_opcodes():
            if op != "equal":
                print(f"{f.split('/')[-1]} {a}: ...{h[k][max(0, i1 - 60):i1]}[{h[k][i1:i2][:80]} -> {n[k][j1:j2][:80]}]")
    gone = sorted(set(h) - set(n))
    print(f"{f.split('/')[-1]}: rows only in HEAD (renamed): {len(gone)}; only in the tree: {len(set(n) - set(h))}")
