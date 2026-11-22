"""Round 18 stage B: rename the timing source enum members to the e2m 103B value labels (labels; checked at each store).
Appends the renamed members to the map (kind global). usage: apply_r18b_enums.py <repo> <map.csv>"""
import csv
import io
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/enums.csv")
L = "e2m 103B value label "
NEW = {
    ("MAIN_INJECTION_TIMING_SOURCE", "5"): ("MAIN_INJECTION_TIMING_SOURCE_CRANK", L + "05 CRANK: the cranking timing map (engine state CRANKING / JUMP_START / REENTRY)"),
    ("MAIN_INJECTION_TIMING_SOURCE", "7"): ("MAIN_INJECTION_TIMING_SOURCE_USER_OVERRIDE", L + "07 USEROVRD: main_injection_timing_selection 2 takes user_commanded_injection_timing_cal"),
    ("MAIN_INJECTION_TIMING_SOURCE", "8"): ("MAIN_INJECTION_TIMING_SOURCE_ENGINE_STOPPED", L + "08 STOP: the power-up value (cm848_initTimingFilterStates)"),
    ("MAIN_INJECTION_TIMING_SOURCE", "11"): ("MAIN_INJECTION_TIMING_SOURCE_MISFIRE_LIMIT", L + "0B MISFIRE: main_injection_timing_misfire_limit (e2m 8A3D Misfire_Timing_Limit) raised the timing"),
    ("MAIN_INJECTION_TIMING_SOURCE", "18"): ("MAIN_INJECTION_TIMING_SOURCE_COMBUSTION_MANAGER", L + "12 COMB_MGR: injection_timing_main_base_command (e2m 171B +8 CBL_SOI_Cmd) won or the sum includes it"),
    ("MAIN_INJECTION_TIMING_SOURCE", "23"): ("MAIN_INJECTION_TIMING_SOURCE_EXTENDED_IDLE", L + "17 EX_IDLE: main_injection_timing_extended_idle_minimum raised the timing during extended idle"),
    ("MAIN_INJECTION_TIMING_SOURCE", "24"): ("MAIN_INJECTION_TIMING_SOURCE_COOLANT_OVERHEAT_DERATE", L + "18 CTDRATE: coolant_overheat_derate_minimum_injection_timing raised the timing"),
    ("INJECTION_TIMING_INTERMEDIATE_SOURCE", "0"): ("INJECTION_TIMING_INTERMEDIATE_SOURCE_FOUR_DIMENSIONAL_TIMING", L + "00 FOUR_D: the 4D timing maps"),
    ("INJECTION_TIMING_INTERMEDIATE_SOURCE", "2"): ("INJECTION_TIMING_INTERMEDIATE_SOURCE_USER_COMMANDED_TIMING", L + "02 USERCOMD: user_commanded_injection_timing_cal (algorithm_enable_flags_4_cal bit 8)"),
    ("INJECTION_TIMING_INTERMEDIATE_SOURCE", "25"): ("INJECTION_TIMING_INTERMEDIATE_SOURCE_COMBUSTION_REFERENCE", L + "19 CBR_SOI: cm848_storeFuelDemandPreviousValues copies the off-nominal compensated reference (1711 +8 CBO_SOI_Ref) into ANC_SOI (10A4 +14)"),
}
out, maps = [], []
for line in open(p).read().split("\n"):
    if line and not line.startswith("#"):
        row = next(csv.reader([line]))
        key = (row[0], row[1]) if len(row) > 3 else None
        if key in NEW:
            new, comment = NEW.pop(key)
            old = row[2]
            maps.append(f",{new},{old},global")
            row[2] = new
            row[3] = comment + f" (was {old})" + (" | earlier note: " + row[3] if row[3] else "")
            b = io.StringIO()
            csv.writer(b, lineterminator="").writerow(row)
            line = b.getvalue()
    out.append(line)
assert not NEW, NEW
open(p, "w").write("\n".join(out))
with open(map_path, "a") as f:
    f.write("\n".join(maps) + "\n")
print(len(maps), "members renamed")
