"""Round 91 (read-only): every text change the refresh made, against the post-apply snapshot: per file, each changed
line's replaced segments (old -> new). usage: review_refresh_r91.py <repo> <snapshot dir>"""
import collections
import difflib
import os
import sys

repo, snap = sys.argv[1], sys.argv[2]
pairs = [(f"{fw.split('_')[0]}_{c}.csv", f"firmware/{fw}/output/{c}.csv")
         for fw in ("CM550_J90350.00_analysis", "CM848_S90140.06_analysis")
         for c in ("global_variables", "function_renames", "function_definitions", "structure_definitions")]
pairs.append(("firmware_CLAUDE.md", "firmware/CLAUDE.md"))
census = collections.Counter()
for s, cur in pairs:
    old = open(os.path.join(snap, s), newline="").read().split("\n")
    new = open(os.path.join(repo, cur), newline="").read().split("\n")
    if len(old) != len(new):
        print(f"{cur}: line count {len(old)} -> {len(new)}")
    for a, b in zip(old, new):
        if a == b:
            continue
        sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
        for op, i1, i2, j1, j2 in sm.get_opcodes():
            if op != "equal":
                census[(cur.split("/")[-1], a[max(0, i1 - 12):i2 + 0].split()[-1] if a[i1:i2] else "", b[j1:j2])] += 0
                print(f"{cur.split('/')[-2] if 'output' in cur else 'CLAUDE.md'}/{cur.split('/')[-1]}: "
                      f"{a[max(0, i1 - 25):i2 + 5]!r} -> {b[max(0, j1 - 25):j2 + 5]!r}")
