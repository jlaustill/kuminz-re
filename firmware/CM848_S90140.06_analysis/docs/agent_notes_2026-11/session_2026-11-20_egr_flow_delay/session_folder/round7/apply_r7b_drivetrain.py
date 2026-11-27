"""Round 7 stage B, the drivetrain part: five unnamed cals (each read with lhz) and the gear range enum.
- e2m 106D (the parameter ID table gives the addresses): +0 Gear_Ratio_Tolerance 0x5c92e (lhz r,-14034), +4
  Gear_Ratio_Max_Limit 0x5c932 (lhz x3), +0x10 Gear_Ratio_Final_Fueling 0x5c93e, +0x16 Gear_Ratio_OOG_Tolerance 0x5c944.
- 0x3fd900 (EEPROM mirror, lhz r,-9984): the gear down gear ratio. Block 8B8B Gear_Down_Gear_Ratio ('Tool entered
  value of gear down gear ratio, down from top gear', 1/2048) is not in the parameter ID table, so the address is from
  the code: cm848_updateDrivetrainRatio scales it exactly as top_gear_ratio_cal into the second threshold; 2048 = 1.0
  in the EEPROM image against the top gear ratio's 0.8.
- drivetrain_gear_range (0x40b5c2: lha x2, sth x3) holds 1 / 2 / 3.
usage: apply_r7b_drivetrain.py <repo> [--dry-run]"""
import csv
import io
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
NEW_ROWS = [
    ("0x003fd900", "gear_down_gear_ratio_cal", "word",
     "the gear down gear ratio (x 2048; 2048 = 1.0 in the EEPROM image): cm848_updateDrivetrainRatio scales it like "
     "top_gear_ratio_cal into gear_down_ratio_threshold. Matches e2m 8B8B Gear_Down_Gear_Ratio ('Tool entered value of "
     "gear down gear ratio; down from top gear'; 1/2048), a block the parameter ID table does not list, so the address "
     "is from the code. lhz"),
    ("0x0005c92e", "drivetrain_ratio_tolerance", "word",
     "e2m 106D +0 Gear_Ratio_Tolerance ('Tolerance used to determine an out of gear condition'): the allowed difference "
     "between the raw and the filtered drivetrain ratio while settled. lhz"),
    ("0x0005c932", "drivetrain_ratio_maximum_limit", "word",
     "e2m 106D +4 Gear_Ratio_Max_Limit ('Maximum gear ratio limit above which out of gear is true'); also the cap of "
     "both gear range thresholds. lhz"),
    ("0x0005c93e", "drivetrain_ratio_when_loaded_minimum_fueling", "word",
     "e2m 106D +0x10 Gear_Ratio_Final_Fueling ('Fueling used to determine Gear_Ratio_When_Loaded'): final_fueling must "
     "exceed it before drivetrain_ratio_when_loaded takes the settled ratio. lhz"),
    ("0x0005c944", "drivetrain_ratio_out_of_gear_tolerance", "word",
     "e2m 106D +0x16 Gear_Ratio_OOG_Tolerance ('Tolerance for remaining OOG'): the ratio difference allowed while "
     "drivetrain_ratio_unsettled_flag is set. lhz"),
]
RETYPE = {"0x0040b5c2": "DRIVETRAIN_GEAR_RANGE"}
ENUM = ["# Drivetrain gear range (drivetrain_gear_range; cm848_updateDrivetrainRatio): the gear-down protection ranges",
        "DRIVETRAIN_GEAR_RANGE,1,DRIVETRAIN_GEAR_RANGE_TOP_GEAR,drivetrain_ratio below top_gear_ratio_threshold,2",
        "DRIVETRAIN_GEAR_RANGE,2,DRIVETRAIN_GEAR_RANGE_ONE_GEAR_DOWN,below gear_down_ratio_threshold but not top gear,2",
        "DRIVETRAIN_GEAR_RANGE,3,DRIVETRAIN_GEAR_RANGE_LOWER,at or above gear_down_ratio_threshold,2"]


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()
problems = [f"{n} is taken" for _, n, _, _ in NEW_ROWS if re.search(r"\b" + n + r"\b", cpp)]
if "DRIVETRAIN_GEAR_RANGE" in cpp:
    problems.append("the enum name is taken")
gv_path = os.path.join(out, "global_variables.csv")
rows = open(gv_path).read().split("\n")
seen = {l[:10] for l in rows if re.match(r"^0x[0-9a-f]{8},", l)}
for a, *_ in NEW_ROWS:
    if a in seen:
        problems.append(f"{a} has a row")
retyped = 0
for i, l in enumerate(rows):
    a = l[:10]
    if a in RETYPE and re.match(r"^0x[0-9a-f]{8},", l):
        row = next(csv.reader([l]))
        row[2] = RETYPE[a]
        rows[i] = text_of(row)
        retyped += 1
if retyped != len(RETYPE):
    problems.append("retype not found")
if problems:
    print("\n".join("PROBLEM " + p for p in problems))
    sys.exit(1)
for a, n, t, c in NEW_ROWS:
    v = int(a, 16)
    idx = next(i for i, l in enumerate(rows) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > v)
    rows.insert(idx, text_of([a, n, t, c]))
en_path = os.path.join(out, "enums.csv")
en = open(en_path).read().rstrip("\n") + "\n\n" + "\n".join(ENUM) + "\n"
print(f"{len(NEW_ROWS)} new rows, {retyped} retyped, enum DRIVETRAIN_GEAR_RANGE")
if dry:
    sys.exit(0)
open(gv_path, "w").write("\n".join(rows))
open(en_path, "w").write(en)
print("written")
