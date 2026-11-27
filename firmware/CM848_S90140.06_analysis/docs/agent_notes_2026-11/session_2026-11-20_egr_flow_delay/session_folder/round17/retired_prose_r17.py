"""List the retired round 17 engine retarder vocabulary in current comment text (outside '| earlier note:' and
'(was ...)') of the four CSVs. usage: retired_prose_r17.py <output dir>"""
import os
import re
import sys

out = sys.argv[1]
WORDS = re.compile(r"limit source code|enable state|output mode (bits|flags)|shift hold flag|arbitrated request|"
                   r"request source (code|index)|engaged flag|retarder (percent )?limit|road speed limit is active|"
                   r"request percent", re.I)
for name in ("global_variables.csv", "function_renames.csv", "enums.csv", "structure_definitions.csv"):
    for n, line in enumerate(open(os.path.join(out, name)), 1):
        current = line.split("| earlier note:")[0]
        current = re.sub(r"\(was [^)]*\)", "", current)
        if re.search(r"retarder|exhaust brake|engine brake", current, re.I) and WORDS.search(current):
            hits = sorted(set(m.group(0) for m in WORDS.finditer(current)))
            print(f"{name}:{n}: {hits} | {current.strip()[:140]}")
