"""List round 18's retired main timing words in current comment text (outside '| earlier note:' and '(was ...)') of
the four CSVs. usage: retired_prose_r18.py <output dir>"""
import os
import re
import sys

out = sys.argv[1]
WORDS = re.compile(r"demand floor|governor[- ]limit minimum|working minimum|cold[- ]start (rpm|map)|"
                   r"offset maps|fixed offset|fixed injection_timing|DEMAND_FLOOR|GOVERNOR_LIMIT_MINIMUM|WORKING_MINIMUM|"
                   r"COLD_START_MAP|FIXED_OFFSET_CALIBRATION|OFFSET_MAPS|PREVIOUS_VALUES_STORED|SOURCE_INITIAL", re.I)
for name in ("global_variables.csv", "function_renames.csv", "enums.csv", "structure_definitions.csv"):
    for n, line in enumerate(open(os.path.join(out, name)), 1):
        current = re.sub(r"\(was [^)]*\)", "", line.split("| earlier note:")[0])
        if WORDS.search(current):
            hits = sorted(set(m.group(0) for m in WORDS.finditer(current)))
            print(f"{name}:{n}: {hits} | {current.strip()[:120]}")
