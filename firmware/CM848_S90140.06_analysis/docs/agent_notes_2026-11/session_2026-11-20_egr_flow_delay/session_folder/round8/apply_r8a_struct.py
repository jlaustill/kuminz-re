"""Round 8 stage A: protection_timer_state_t (0x40b100) is the RE transmission pressure state (e2m 8C53 +0
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
OLD_T, NEW_T = "protection_timer_state_t", "transmission_pressure_state_t"
OLD_I, NEW_I = "protection_timer_state_t_0040b100", "transmission_pressure_state"
FIELDS = {
    "status_code": ("pressure_state",
        "e2m 8C53 +0 RE_Trans_Pressure_State ('Indicate the RE transmission pressure state'; table-resolved): which "
        "governor pressure curve sets governor_pressure_target, 1-0x18, written by every governor pressure mode "
        "(the anti-hunt mode: 1 base / 0x12 / 0x13 boost / 0x14 / 0x15 hold); 2 in the RAM dump (was status_code)"),
    "status_code_hold_timer": ("anti_hunt_boost_limit_timer",
        "e2m 8C17 +0 RE_AH_Boost_Limit_Timer ('Used to limit time trans gov pressure can be boosted for upshift'): "
        "reloaded from transmission_anti_hunt_boost_limit_time; at 0 the 1-2 boost stops (was status_code_hold_timer)"),
    "timeout_counter": ("anti_hunt_delay_timer",
        "e2m 8C17 +2 RE_AH_Delay_Timer ('Used to delay start of gov pressure boost for AH upshifts'): reloaded from "
        "transmission_anti_hunt_delay_time when a forced upshift completes; no new boost until it is 0 (was "
        "timeout_counter)"),
    "state1_timer": ("anti_hunt_1_2_boost_timer",
        "e2m 8C17 +4 RE_AH_Timer_1_2 ('Controls duration of boost press for AH 1-2 upshift'): reloaded from "
        "transmission_anti_hunt_1_2_boost_time (was state1_timer)"),
    "state2_timer": ("anti_hunt_2_3_boost_timer",
        "e2m 8C17 +6 RE_AH_Timer_2_3 ('Controls duration of boost press for AH 2-3 upshift'): reloaded from "
        "transmission_anti_hunt_2_3_boost_time (was state2_timer)"),
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
gv, k = re.subn(r"(?m)^(0x0040b100,)" + re.escape(OLD_I) + "," + re.escape(OLD_T) + ",",
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
