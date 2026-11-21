"""Stage 10 extras (main session, after apply_W15.py): complete the e2m 1170 'ASG application specific' family that bin
6 started - the 15 other engine_operating_mode_restore_* rows, the function that loads them and the FUELING_STATE member.
Every global: old = the current CSV name, the new name free, the quote found in the .cpp with the old name. Appends
the rows to map_stage10.csv. The function goes through the repo's apply_renames.py (it also updates the name columns
of function_definitions.csv / local_variables.csv).
usage: apply_stage10_extras.py <w15 dir> <repo>"""
import json
import os
import re
import subprocess
import sys

here, repo = sys.argv[1:3]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read()
norm = lambda t: re.sub(r"\s+", "", t)
cpp_norm = norm(cpp)
cpp_identifiers = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", cpp))
F = "cm848_selectAllSpeedGovernorApplicationMode"
# address, old, new, e2m offset, record, description, working word it is copied into (the quote's left side)
ROWS = [
    ("0x0040a21a", "droop_gain_1", "droop_gain_1", "10", "ASG_Droop_Gain_1_As", "droop gain 1",
     "all_speed_governor_droop_gain_1"),
    ("0x0040a21c", "droop_gain_2", "droop_gain_2", "12", "ASG_Droop_Gain_2_As", "droop gain 2",
     "all_speed_governor_droop_gain_2"),
    ("0x0040a21e", "speed_filter_coefficient", "reference_filter_coefficient", "14", "ASG_Filter_Coef_As",
     "reference filter coefficient", "all_speed_governor_reference_filter_coefficient_selected"),
    ("0x0040a220", "fuel_demand_tracking_limit", "fuel_demand_tracking_limit", "16", "ASG_High_Fuel_Limit_As",
     "fueling high limit", "governor_fuel_demand_tracking_limit"),
    ("0x0040a224", "governor_reset_flag", "reset_flag", "1A", "ASG_Reset_As", "reset",
     "all_speed_governor_external_reset_flag"),
    ("0x0040a232", "proportional_gain_1", "proportional_gain_1", "28", "ASG_Proportional_Gain_1_As",
     "proportional gain 1", "all_speed_governor_proportional_gain_1_selected"),
    ("0x0040a234", "proportional_gain_2", "proportional_gain_2", "2A", "ASG_Proportional_Gain_2_As",
     "proportional gain 2", "all_speed_governor_proportional_gain_2_selected"),
    ("0x0040a236", "integral_gain_1", "integral_gain_1", "2C", "ASG_Integral_Gain_1_As", "integral gain 1",
     "all_speed_governor_integral_gain_1_selected"),
    ("0x0040a238", "integral_gain_2", "integral_gain_2", "2E", "ASG_Integral_Gain_2_As", "integral gain 2",
     "all_speed_governor_integral_gain_2_selected"),
    ("0x0040a23a", "derivative_gain_1", "derivative_gain_1", "30", "ASG_Derivative_Gain_1_As", "derivative gain 1",
     "all_speed_governor_derivative_gain_1_selected"),
    ("0x0040a23c", "derivative_gain_2", "derivative_gain_2", "32", "ASG_Derivative_Gain_2_As", "derivative gain 2",
     "all_speed_governor_derivative_gain_2_selected"),
    ("0x0040a23e", "compensation_filter_coefficient_1", "compensation_filter_coefficient_1", "34",
     "ASG_Coefficient_1_As", "compensation filter coefficient 1",
     "all_speed_governor_compensation_filter_coefficient_1_selected"),
    ("0x0040a240", "compensation_filter_coefficient_2", "compensation_filter_coefficient_2", "36",
     "ASG_Coefficient_2_As", "compensation filter coefficient 2",
     "all_speed_governor_compensation_filter_coefficient_2_selected"),
    ("0x0040a242", "compensation_filter_coefficient_3", "compensation_filter_coefficient_3", "38",
     "ASG_Coefficient_3_As", "compensation filter coefficient 3",
     "all_speed_governor_compensation_filter_coefficient_3_selected"),
    ("0x0040a246", "no_load_fuel_speed_request", "no_load_speed", "3C", "ASG_App_No_Load_RPM",
     "application defined no load speed", "all_speed_governor_no_load_fuel_reference_speed"),
]
path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
names = {l.split(",")[1] for l in lines if l.startswith("0x")}
problems, mapping = [], []
for address, old_suffix, new_suffix, offset, record, description, working in ROWS:
    old = f"engine_operating_mode_restore_{old_suffix}"
    new = f"all_speed_governor_application_{new_suffix}"
    i = index[address]
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    quote = f"{working} = {old};"
    if name != old:
        problems.append(f"{address} current name {name} != {old}")
    if new in names or new in cpp_identifiers:
        problems.append(f"{address} {new} exists")
    if norm(quote) not in cpp_norm:
        problems.append(f"{address} quote not in the .cpp: {quote}")
    text = (f"e2m 1170 +{offset} {record} 'ASG application specific {description}': {F} copies it into {working} "
            f"when it selects FUELING_STATE_ALL_SPEED_GOVERNOR_APPLICATION (fueling state 30, e2m label ASG_APPL); "
            f"no code writes the 1170 application record (RAM, zero at every start), so the mode never engages in "
            f"this build (was {old})")
    if comment and comment[:40] not in text:
        text += f" | earlier note: {comment}"
    lines[i] = ",".join([a, new, typ, text])
    mapping.append((address, new, old, "global"))
if problems:
    print("\n".join(problems))
    sys.exit(1)
open(path, "w", newline="").write("\n".join(lines))
# the function, through the repo's apply
plate = (f"If no fueling state is selected (FUELING_STATE_NOT_SELECTED) and all_speed_governor_application_override_mode "
         f"(e2m 1170 +C ASG_As_Override_Mode) is set: selects FUELING_STATE_ALL_SPEED_GOVERNOR_APPLICATION (30; e2m "
         f"label ASG_APPL) and loads the application-specific all speed governor set (e2m 1170 +C..+3C: reference and "
         f"feedback speed - droop / proportional / integral / derivative gains - filter coefficients - fueling limits "
         f"- reset states) into the working governor selection. Nothing in this build writes that record (RAM - zero "
         f"at every start) so the mode never engages. Nothing is restored (was cm848_restoreEngineOperatingMode)")
gate = os.path.join(here, "gate_input_stage10_function.jsonl")
open(gate, "w").write(json.dumps({"kind": "function", "verdict": "confirmed", "address": "0x0000fb28",
                                  "old": "cm848_restoreEngineOperatingMode", "new": F, "plate_comment": plate}) + "\n")
done = subprocess.run([sys.executable, os.path.join(repo, "firmware", "scripts", "rename_waves", "apply_renames.py"),
                       out, gate, "--apply"], capture_output=True, text=True)
print(done.stdout.strip()[-300:])
assert done.returncode == 0 and "PROBLEM" not in done.stdout, done.stderr[-500:]
mapping.append(("0x0000fb28", F, "cm848_restoreEngineOperatingMode", "function"))
# the enum member
path = os.path.join(out, "enums.csv")
text = open(path, newline="").read()
old_row = [l for l in text.split("\n") if l.startswith("FUELING_STATE,30,FUELING_STATE_ALL_SPEED_GOVERNOR_RESTORE,")]
assert len(old_row) == 1, old_row
size = old_row[0].rsplit(",", 1)[1]
new_row = ("FUELING_STATE,30,FUELING_STATE_ALL_SPEED_GOVERNOR_APPLICATION,"
           f"{F}: all_speed_governor_application_override_mode nonzero; loads the application-specific record "
           "0x40a216-0x40a246 (e2m 1170 +C..+3C ASG_*_As; never set in this build and RAM is zeroed at every start) - "
           "e2m label ASG_APPL (CHR_CC_11.45.01.07 0x1E) (was FUELING_STATE_ALL_SPEED_GOVERNOR_RESTORE)," + size)
open(path, "w", newline="").write(text.replace(old_row[0], new_row))
mapping.append(("", "FUELING_STATE_ALL_SPEED_GOVERNOR_APPLICATION", "FUELING_STATE_ALL_SPEED_GOVERNOR_RESTORE", "enum"))
with open(os.path.join(here, "map_stage10.csv"), "a") as f:
    for address, new, old, kind in mapping:
        f.write(f"{address},{new},{old},{kind}\n")
print(f"stage 10 extras: {len(ROWS)} globals, 1 function, 1 enum member")
