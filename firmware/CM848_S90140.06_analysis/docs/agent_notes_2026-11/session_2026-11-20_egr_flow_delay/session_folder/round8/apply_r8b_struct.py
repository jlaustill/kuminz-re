"""Round 8 stage B (from the stage A script): protection_lockout_t (0x40b11c) is e2m 8C17 +1A..+24. Stage A: protection_timer_state_t (0x40b100) is the RE transmission pressure state (e2m 8C53 +0
RE_Trans_Pressure_State, table-resolved to 0x40b100) followed by the e2m 8C17 anti-hunt timers (+0..+6 at 0x40b102).
Renames the type and fields (new comments), the dotted alias rows, and writes the map rows. Label-only.
usage: apply_r8a_struct.py <repo> <map.csv> [--dry-run]"""
import csv
import io
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
OLD_T, NEW_T = "protection_lockout_t", "transmission_lockup_timers_t"
OLD_I, NEW_I = "protection_lockout_t_0040b11c", "transmission_lockup_timers"
FIELDS = {
    "thermal_lockout": ("lockup_delay_2_3_timer",
        "e2m 8C17 +1A RE_Lockup_Delay_2_3 ('Timer used to delay lockup') after the 2-3 shift (was thermal_lockout)"),
    "load_lockout": ("lockup_delay_3_4_timer",
        "e2m 8C17 +1C RE_Lockup_Delay_3_4 ('Timer used to delay lockup') after the 3-4 shift (was load_lockout)"),
    "rpm_lockout": ("lockup_delay_4_3_timer",
        "e2m 8C17 +1E RE_Lockup_Delay_4_3 ('Timer used to delay lockup') after the 4-3 shift (was rpm_lockout)"),
    "sensor_fault_active": ("lockup_off_timer",
        "e2m 8C17 +20 RE_Lockup_Off_Timer ('Timer used to anticipate unlock delay') (was sensor_fault_active)"),
    "reserved_08": ("low_range_hold_timer",
        "e2m 8C17 +22 RE_Low_Range_Hold_Timer ('Timer used to delay low range hold pressure') (was reserved_08)"),
    "timer_expired": ("low_range_shift_timer",
        "e2m 8C17 +24 RE_Low_Range_Shift_Timer ('Timer used to delay low range shifts'): reloaded from "
        "transmission_low_range_1_2_boost_time / _2_3_ (was timer_expired)"),
}


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()
problems = [f"{n} is taken" for n, _ in FIELDS.values() if re.search(r"\b" + n + r"\b", cpp)]
if re.search(r"\b" + NEW_T + r"\b", cpp):
    problems.append("type name taken")
sd_path = os.path.join(out, "structure_definitions.csv")
lines, n = open(sd_path).read().split("\n"), 0
for i, line in enumerate(lines):
    if line.startswith(OLD_T + ","):
        row = next(csv.reader([line]))
        if row[2] in FIELDS:
            row[2], row[5] = FIELDS[row[2]]
            n += 1
        row[0] = NEW_T
        lines[i] = text_of(row)
    elif line.startswith("#") and OLD_T in line:
        lines[i] = line.replace(OLD_T, NEW_T)
if n != len(FIELDS):
    problems.append(f"{n} of {len(FIELDS)} fields")
gv_path = os.path.join(out, "global_variables.csv")
gv = open(gv_path).read()
gv, k = re.subn(r"(?m)^(0x0040b11c,)" + re.escape(OLD_I) + "," + re.escape(OLD_T) + ",",
                lambda m: m.group(1) + OLD_I + "," + NEW_T + ",", gv)
if k != 1:
    problems.append("instance row type not found")
aliases = 0
for old, (new, _) in FIELDS.items():
    gv, c = re.subn(r"(?m)^(0x[0-9a-f]+)," + re.escape(OLD_I) + r"\." + re.escape(old) + ",",
                    lambda m, new=new: f"{m.group(1)},{NEW_I}.{new},", gv)
    aliases += c
if problems:
    print("\n".join("PROBLEM " + p for p in problems))
    sys.exit(1)
print(f"{n} fields, {aliases} alias rows")
if dry:
    sys.exit(0)
open(sd_path, "w").write("\n".join(lines))
open(gv_path, "w").write(gv)
with open(map_path, "a") as f:
    f.write(f",{NEW_T},{OLD_T},type\n")
    for old, (new, _) in FIELDS.items():
        f.write(f",{new},{old},field\n")
print("written")
