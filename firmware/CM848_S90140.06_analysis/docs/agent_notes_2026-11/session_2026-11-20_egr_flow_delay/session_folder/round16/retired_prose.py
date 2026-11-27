"""List retired round 16 vocabulary in the four CSVs, outside history segments ('| earlier note: ...' and '(was ...)').
usage: retired_prose.py <output dir>"""
import os
import re
import sys

out = sys.argv[1]
WORDS = re.compile(r"vehicle speed limit|vehicle_speed_limit|\bzones?\b|rate correction|rate-correction|stable[- ]speed|"
                   r"cruise zone|gain zone", re.I)
for name in ("global_variables.csv", "function_renames.csv", "enums.csv", "structure_definitions.csv"):
    for n, line in enumerate(open(os.path.join(out, name)), 1):
        current = line.split("| earlier note:")[0]
        current = re.sub(r"\(was [^)]*\)", "", current)
        if re.search(r"cruise|governor|road speed|RSG|sump", current, re.I) and WORDS.search(current):
            hits = sorted(set(m.group(0) for m in WORDS.finditer(current)))
            print(f"{name}:{n}: {hits} | {current.strip()[:150]}")
