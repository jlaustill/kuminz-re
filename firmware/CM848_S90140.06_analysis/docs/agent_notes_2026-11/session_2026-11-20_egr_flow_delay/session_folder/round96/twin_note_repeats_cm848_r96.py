"""Round 96: list CM848 plates that name the same CM550 twin address twice ('twin of CM550 0x...'). Read-only.
usage: twin_note_repeats_cm848_r96.py <repo>"""
import collections
import os
import re
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/function_renames.csv")
n = 0
for k, line in enumerate(open(p, newline=""), 1):
    hits = [h.lstrip("0") for h in re.findall(r"twin of CM550 (?:0x)?([0-9a-f]+)", line, re.I)]
    for a, c in collections.Counter(hits).items():
        if c > 1:
            n += 1
            print(k, line.split(",", 2)[1], "0x" + a, c, "times")
print(n, "CM848 plates repeat a CM550 twin address")
