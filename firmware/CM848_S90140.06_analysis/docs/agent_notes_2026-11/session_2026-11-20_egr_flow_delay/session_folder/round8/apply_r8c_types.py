"""Round 8 stage C types:
- transmission_gear_ratio_table (0x40786a): byte -> word[6]. Its one reader, cm848_calculateTransmissionOutputTorqueInGear,
  indexes it with lhzx from base 0x40786a (addi r31,r31,30826 @ 0x320f8); indexes 2..5 hold 1st..4th, and the next
  word (0x407876) is the following table's byte-length header (14 = 7 breakpoints).
- 0x40781c: transmission_vehicle_inertia_default (word, lhz @ 0x331d4): e2m 8BBC +10 RE_Inertia_Default.
usage: apply_r8c_types.py <repo> [--dry-run]"""
import csv
import io
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
p = os.path.join(out, "global_variables.csv")
rows = open(p).read().split("\n")


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


done = 0
for i, l in enumerate(rows):
    if l.startswith("0x0040786a,transmission_gear_ratio_table,byte,"):
        row = next(csv.reader([l]))
        row[2] = "word[6]"
        row[3] = row[3].replace("Typed byte, read as words", "word[6]: index 6 would be the next table's length header")
        rows[i] = text_of(row)
        done += 1
assert done == 1
assert not any(l.startswith("0x0040781c,") for l in rows)
new = ["0x0040781c", "transmission_vehicle_inertia_default", "word",
       "e2m 8BBC +10 RE_Inertia_Default ('Initial value for calculated vehicle inertia'; x 0.32164 slug ft2; 53 = 17): "
       "cm848_initializeTransmissionShiftLogic copies it into transmission_vehicle_inertia (lhz @ 0x331d4)"]
idx = next(i for i, l in enumerate(rows) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > 0x40781c)
rows.insert(idx, text_of(new))
print("retyped 1, added 1")
if not dry:
    open(p, "w").write("\n".join(rows))
