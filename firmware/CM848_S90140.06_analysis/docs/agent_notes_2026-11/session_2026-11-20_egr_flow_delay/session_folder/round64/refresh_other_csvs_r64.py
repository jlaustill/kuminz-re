"""refresh_other_csvs_r57.py with history protection (round 64: the r57 version rewrote "(was DIAG_ACK / ...)" notes
into the new names). Replaces every renamed old name (whole words; never a default label such as DAT_ / WORD_ / a
struct type's address name) in the output CSVs refresh_references.py does not cover - except where the text before
the match on its line ends in a history marker ("was" / "were" / "formerly" / "old name" / "(was"), also through a
"was a / b / c" list.  Idempotent.  usage: refresh_other_csvs_r64.py <repo> <map.csv>"""
import csv
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
OUT = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
OTHERS = ["enums.csv", "structure_definitions.csv", "arrays.csv", "labels.csv", "constants.csv",
          "local_variables.csv", "function_definitions.csv"]
HISTORY = re.compile(r"(\bwas|\bwere|formerly|old name|\(was)\s*`?(\s*[\w`]+\s*/\s*`?)*$")
rows = [r for r in csv.DictReader(open(map_path)) if not re.match(r"(DAT|WORD|BYTE)_|.*_t_[0-9a-f]{8}$", r["old_label"])]
total = 0
for name in OTHERS:
    p = os.path.join(OUT, name)
    lines = open(p).read().split("\n")
    n = 0
    for i, line in enumerate(lines):
        for r in rows:
            pattern = re.compile(rf"(?<![\w.]){re.escape(r['old_label'])}\b")

            def sub(m, line=line):
                nonlocal_count[0] += 0
                before = m.string[max(0, m.start() - 160):m.start()]
                if HISTORY.search(before):
                    return m.group(0)
                nonlocal_count[0] += 1
                return r["name"]

            nonlocal_count = [0]
            line = pattern.sub(sub, line)
            n += nonlocal_count[0]
        lines[i] = line
    if n:
        open(p, "w").write("\n".join(lines))
        print(f"{name}: {n} mentions refreshed")
    total += n
print(f"{total} mentions refreshed")
