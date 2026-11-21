"""Round 7 stage A: two j1939_powertrain_control_state_t retarder fields (read in cm848_processEngineRetarderTsc1Request),
their dotted alias rows, and the session functions' prototypes (param_1 -> session_kind). Label-only.
usage: apply_r7a_fields.py <repo> <map.csv> [--dry-run]"""
import csv
import io
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
T, I = "j1939_powertrain_control_state_t", "j1939_powertrain_control_state"
RENAMES = {
    "retarder_tsc1_mode_transition_timer": ("retarder_tsc1_zero_torque_request_timer",
        "armed with the retarder request timeout while the requested torque (torque control) or the torque limit "
        "(limit control) is 0, cleared otherwise; at 1 it counts as a link timeout, and a drop to override disabled "
        "while it runs counts as a request change (cm848_runJ1939PowertrainControlTimeouts). Why a zero torque request "
        "is timed is not settled (was retarder_tsc1_mode_transition_timer, before that etc1_mode_transition_timer)"),
    "retarder_tsc1_speed_mode_flag": ("retarder_tsc1_speed_control_flag",
        "the retarder twin of tsc1_speed_control_flag: always written 0, since cm848_processEngineRetarderTsc1Request "
        "rejects speed control (SPN 695 = 1); no reader (was retarder_tsc1_speed_mode_flag, before that "
        "etc1_speed_mode_flag)"),
}
PROTOTYPES = [
    ("0x0050be6c", "cm848_storeJ1939ControlSessionInHistoryTable", "session_kind",
     "0 = the engine control session record, else the retarder's"),
    ("0x0050beec", "cm848_startJ1939ControlSession", "session_kind",
     "0 = open the engine control session record, else the retarder's"),
]


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()
problems = [f"{n} is taken" for n, _ in RENAMES.values() if re.search(r"\b" + n + r"\b", cpp)]
if re.search(r"\bsession_kind\b", cpp):
    problems.append("session_kind is taken")
sd_path = os.path.join(out, "structure_definitions.csv")
lines, n = open(sd_path).read().split("\n"), 0
for i, line in enumerate(lines):
    if line.startswith(T + ","):
        row = next(csv.reader([line]))
        if row[2] in RENAMES:
            row[2], row[5] = RENAMES[row[2]]
            lines[i] = text_of(row)
            n += 1
if n != len(RENAMES):
    problems.append(f"{n} of {len(RENAMES)} fields found")
fd_path = os.path.join(out, "function_definitions.csv")
fd = open(fd_path).read()
for a, name, _, _ in PROTOTYPES:
    if re.search(r"(?m)^" + a + ",", fd):
        problems.append(f"{a} already has a prototype")
if problems:
    print("\n".join("PROBLEM " + p for p in problems))
    sys.exit(1)
gv_path = os.path.join(out, "global_variables.csv")
gv, aliases = open(gv_path).read(), 0
for old, (new, _) in RENAMES.items():
    gv, k = re.subn(r"(?m)^(0x[0-9a-f]+)," + re.escape(I) + r"\." + re.escape(old) + r",",
                    lambda m: f"{m.group(1)},{I}.{new},", gv)
    aliases += k
print(f"{n} fields, {aliases} alias rows, {len(PROTOTYPES)} prototypes")
if dry:
    sys.exit(0)
open(sd_path, "w").write("\n".join(lines))
open(gv_path, "w").write(gv)
rows = []
for a, name, param, comment in PROTOTYPES:
    rows.append(text_of([a, name, "return", "", "void", "returns nothing"]))
    rows.append(text_of([a, name, "0", param, "int", comment]))
open(fd_path, "w").write(fd.rstrip("\n") + "\n" + "\n".join(rows) + "\n")
with open(map_path, "a") as f:
    for old, (new, _) in RENAMES.items():
        f.write(f",{new},{old},field\n")
    f.write(",session_kind,param_1,local\n")
print("written")
