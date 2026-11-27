"""Round 96: print the 'twin of CM550' mentions (with context) of given CM848 function_renames.csv lines. Read-only.
usage: show_twin_mentions_r96.py <repo> <line>..."""
import os
import re
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/function_renames.csv")
lines = open(p, newline="").read().split("\n")
for n in map(int, sys.argv[2:]):
    line = lines[n - 1]
    print("==", n, line.split(",", 2)[1])
    for m in re.finditer(r"twin of CM550", line, re.I):
        print("   ...", line[max(0, m.start() - 100):m.end() + 70].replace("\r", ""))
