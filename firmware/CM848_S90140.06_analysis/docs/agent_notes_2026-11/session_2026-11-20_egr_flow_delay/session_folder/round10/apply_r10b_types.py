"""Round 10 stage B (types). String edits only (global_variables.csv takes commas unquoted).
- 26 RE rows word -> i16: their e2m record is signed 2-byte and every load of them is lha (classify_signed_loads.py over
  re_audit.csv; the round 3 rule).
- The label-only rows of rounds 9 / 10 get their types: the 8BB5 / 8BBB calibration words (word; 0x408af2
  RE_Max_Pressure_Delta i32 - lwz + a signed compare; 0x408b22 RE_PID_Switch_Temperature i16 - lha; 0x408b26 a byte), the
  controller's integral / proportional terms (word), the 54 lookup caches (word; the five 2-D grid caches word[2]).
- 0x3fede2: transmission_1_2_shift_lag_cal word[6] (e2m RE_One_Two_Lag, 'Shift lag tbl corresponding to temperature
  range, pwr-dwn trim'), read as *(word *)(transmission_temperature_range * 2 + 0x3fede2) by the WOT / low range modes.
  Its 2-3 twin at 0x3fedee overlaps the boot kernel's diagnostic rows (eeprom_calibration_pending_flag ...), so those
  rows keep their names and get the application role in their comments.
usage: apply_r10b_types.py <repo> <re_signed_loads.csv> <map_r9a.csv> <map_r9f.csv> <map_r10a.csv>"""
import csv
import os
import re
import sys

repo, loads_path, *maps = sys.argv[1:]
repo = os.path.abspath(repo)
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
lines = open(p).read().split("\n")
index = {}
for i, l in enumerate(lines):
    m = re.match(r"^(0x[0-9a-f]{8}),", l)
    if m:
        index.setdefault(m.group(1), i)
I16 = [r["address"] for r in csv.DictReader(open(loads_path)) if r["verdict"] == "lha-only"]
label_only = []
for m in maps:
    for r in csv.DictReader(open(m)):
        if r["old_label"].startswith("DAT_") and r["address"]:
            label_only.append((r["address"].lower(), r["name"]))
SPECIAL = {"0x00408af2": "i32", "0x00408b22": "i16", "0x00408b26": "byte"}
GRID_CACHES = {"0x003fb10a", "0x003fb10e", "0x003fb164", "0x003fb168", "0x003fb16c"}
n16 = typed = 0
for a in I16:
    a, name, typ, comment = lines[index[a]].split(",", 3)
    assert typ == "word", (a, typ)
    lines[index[a]] = ",".join([a, name, "i16", comment + " Typed i16 (round 10): the e2m record is signed and every "
                                                          "load is lha."])
    n16 += 1
for a, name in label_only:
    if a not in index:
        continue
    row = lines[index[a]].split(",", 3)
    if row[1] != name:
        continue  # renamed again later (e.g. the DAT_003fb192 ring, typed in round 9)
    if row[2]:
        continue
    t = SPECIAL.get(a, "word[2]" if a in GRID_CACHES else "word")
    row[2] = t
    lines[index[a]] = ",".join(row)
    typed += 1
# the 1-2 shift lag table
assert "0x003fede2" not in index
new = ",".join(["0x003fede2", "transmission_1_2_shift_lag_cal", "word[6]",
                "e2m RE_One_Two_Lag (T table, 'Shift lag tbl corresponding to temperature range, pwr-dwn trim'): the "
                "learned 1-2 shift lag per transmission_temperature_range (index 1..5; EEPROM 0x1960, so _cal). The WOT and "
                "low range modes load transmission_predicted_1_2_shift_delay from it. The 2-3 twin (RE_Two_Three_Lag) is "
                "at 0x3fedee, under the boot kernel's diagnostic row names"])
k = next(i for i, l in enumerate(lines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > 0x3fede2)
lines.insert(k, new)
# the 2-3 shift lag table's boot rows
ROLE = (" | application side (time-shared, the EEPROM mirror): word {} of e2m RE_Two_Three_Lag, the learned 2-3 shift "
        "lag per transmission_temperature_range (0x3fedee + 2 x range), read into transmission_predicted_2_3_shift_delay")
for a, word_index in [("0x003fedee", "0"), ("0x003fedf0", "1"), ("0x003fedf4", "3"), ("0x003fedf6", "4"),
                      ("0x003fedf8", "5")]:
    i = next(j for j, l in enumerate(lines) if l.startswith(a + ","))
    if "RE_Two_Three_Lag" not in lines[i]:
        lines[i] = lines[i] + ROLE.format(word_index + (" (with the next byte)" if a == "0x003fedee" else ""))
open(p, "w").write("\n".join(lines))
print(f"i16 {n16}, typed {typed} label-only rows, 1 table added, 5 boot rows annotated")
