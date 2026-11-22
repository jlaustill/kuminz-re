"""List round 19's retired words in current comment text (outside '| earlier note:' and '(was ...)') of the four CSVs.
usage: retired_prose_r19.py <output dir>"""
import os
import re
import sys

out = sys.argv[1]
WORDS = re.compile(r"cold[- ]start (timing|map|rpm)|timing[^.;]{0,40}cold[- ]start|blend scale|boost[- ]fuel rpm|"
                   r"rpm boost-fuel|dims\b|row count|fuel correction (table|output|timer|temp)|"
                   r"compensated reference previous|previous compensated|governor adjustment input", re.I)
for name in ("global_variables.csv", "function_renames.csv", "enums.csv", "structure_definitions.csv"):
    for n, line in enumerate(open(os.path.join(out, name)), 1):
        current = re.sub(r"\(was [^)]*\)", "", line.split("| earlier note:")[0])
        if WORDS.search(current):
            hits = sorted(set(m.group(0) for m in WORDS.finditer(current)))
            print(f"{name}:{n}: {hits} | {current.strip()[:130]}")
