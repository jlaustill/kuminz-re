"""Finish stage 5 after its TEXT_REPLACEMENTS step stopped (the stale CSP sentence occurs twice): replace every old
COLD_START_PHASE-era CSP_* state name in the comment columns token-wise (values 0-8 in the old order INITIAL /
CRANKING / ABOVE_RPM_TRIGGER / AT_GOVERNOR_SETPOINT / FUEL_MODE_SWITCH / SUSPENDED / ABOVE_RPM_VIA_EVENTS /
SETPOINT_UNDERRUN / ENGINE_STANDBY), fix the injection-gate phrase, and write map_stage5.csv.
Usage: finish_stage5.py <CM848 output dir>"""
import os
import re
import sys

OUT = sys.argv[1]
here = os.path.dirname(os.path.abspath(__file__))
CSP = {"CSP_INITIAL": "ENGINE_STATE_UNINITIALIZED", "CSP_CRANKING": "ENGINE_STATE_STOPPED",
       "CSP_ABOVE_RPM_TRIGGER": "ENGINE_STATE_CRANKING", "CSP_AT_GOVERNOR_SETPOINT": "ENGINE_STATE_RUNNING",
       "CSP_FUEL_MODE_SWITCH": "ENGINE_STATE_ENGINE_BRAKE", "CSP_SUSPENDED": "ENGINE_STATE_OVERSPEED",
       "CSP_ABOVE_RPM_VIA_EVENTS": "ENGINE_STATE_JUMP_START", "CSP_SETPOINT_UNDERRUN": "ENGINE_STATE_REENTRY",
       "CSP_ENGINE_STANDBY": "ENGINE_STATE_SHUTDOWN"}
total = 0
for name in ("function_renames.csv", "global_variables.csv", "structure_definitions.csv", "enums.csv"):
    path = os.path.join(OUT, name)
    text = open(path, newline="").read()
    unknown = set(re.findall(r"\bCSP_[A-Z0-9_]+\b", text)) - set(CSP)
    assert not unknown, (name, unknown)
    text, n = re.subn(r"\bCSP_[A-Z0-9_]+\b", lambda m: CSP[m.group(0)], text)
    total += n
    if name == "function_renames.csv":
        old = "quantity forced to 0 during shutdown / protection unless the engine is starting"
        assert text.count(old) == 1
        text = text.replace(old, "quantity forced to 0 while the ignition key switch is off (unless "
                                 "key_off_shutdown_inhibit_flag is set) or engine_shutdown_command_flag is set")
    open(path, "w", newline="").write(text)
print(f"{total} CSP_ names replaced")

src = open(os.path.join(here, "apply_fueling_state_stage5.py")).read().split("if len(sys.argv) > 2:")[0]
ns = {"__name__": "definitions", "os": os, "sys": sys}
exec(src.replace("OUT = sys.argv[1]", "OUT = None"), ns)
exec(open(os.path.join(here, "stage5_crank_routine.py")).read(), ns)
with open(os.path.join(here, "map_stage5.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, (old, new, _) in ns["FUNCTIONS"].items():
        f.write(f"{address},{new},{old},function\n")
    for address, (old, new, *_rest) in ns["GLOBALS"].items():
        f.write(f"{address},{new},{old},global\n")
    f.write(",FUELING_STATE_MASTER_SLAVE_OVERRIDE,FUELING_STATE_UNIDENTIFIED_32,enum member\n")
print("map_stage5.csv written:", len(ns["FUNCTIONS"]) + len(ns["GLOBALS"]) + 1, "rows")
