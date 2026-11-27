"""Round 95: collapse a '(was X; PR #53 round 95)' note that follows itself (the judge's final comment already ended
with the note the apply appends) in both firmwares' CSVs. Idempotent; keeps line endings. usage: dedupe_notes_r95.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
NOTE = re.compile(r"(\((?:was|were) [^()]*; PR #53 round 95\))(\s*\1)+")
total = 0
for fw in ("firmware/CM550_J90350.00_analysis/output", "firmware/CM848_S90140.06_analysis/output"):
    for name in ("function_renames.csv", "global_variables.csv", "enums.csv", "structure_definitions.csv"):
        p = os.path.join(repo, fw, name)
        t = open(p, newline="").read()
        n = len(NOTE.findall(t))
        if n:
            open(p, "w", newline="").write(NOTE.sub(r"\1", t))
            print(f"{fw.split('/')[1]} {name}: {n} doubled notes collapsed")
            total += n
print("total", total)
