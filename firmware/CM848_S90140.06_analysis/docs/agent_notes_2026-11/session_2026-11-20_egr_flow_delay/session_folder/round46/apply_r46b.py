"""Round 46 stage B: the park / neutral exit engine speed limit family is Chrysler's rock cycle torque management.
- Its enable bit is already algorithm_enable_flags_43_cal.rock_cycle_torque_management_enable (e2m 106B).
- 8C49 (in the dumped table) RE_RCTM_* = the window function's throttle / output shaft speed / run mode calibrations;
  8C4A / 8C4B = its transmission temperature dwell table; 8A7C +8 / +A = the flag and the dwell timer.
- 8C2A (past the table; field match, 6 of 6 records) TC_Rock_Cycle_* = the speed limit function's calibrations.
The trigger stays in the plates: after the park / neutral switch clears with throttle applied, the engine speed is held.
'park_neutral_exit_' becomes 'rock_cycle_'; every other word stays, so the two halves stay apart (TC: commanded throttle,
road speed, window; RE: engine_speed_limit_* enabling conditions and dwell). Idempotent.
usage: apply_r46b.py <repo> <map.csv> <globals-only map.csv>"""
import ast
import os
import re
import sys

repo, map_path, gmap_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
gp, fp = os.path.join(CM, "output/global_variables.csv"), os.path.join(CM, "output/function_renames.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 46"
ram = open(os.path.join(CM, "originals/cm848_ram.bin"), "rb").read()
recs = {}
for line in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    head, _, desc = line.strip().partition(";")
    f = head.split(",")
    if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
        recs.setdefault((int(f[2], 16), int(f[3], 16)), (f[0], f[1], f[7], f[9], f[10], desc.strip()))


def cite(block, off, a=None, extra=""):
    name, unit, size, sign, scale, desc = recs[(block, off)]
    unit = f"{unit}, " if unit.upper() not in ("NONE", "UNITLESS", "") else ""
    s = float(scale)
    val = ""
    if a is not None and 0x3FA000 <= a < 0x3FA000 + len(ram):
        v = int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + int(size)], "big")
        val = f"; {v} = {v * s:.6g} in the dump"
    return f"e2m {block:04X} +{off:X} {name} '{desc}' ({unit}{s:g} per count{val}){extra}."


g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "rock_cycle_engine_speed_limit" in names:
    print("already applied")
    sys.exit(0)
mapping, gmapping = ["address,name,old_label,kind,dims"], ["address,name,old_label,kind,dims"]
MEMBER = ("Part of rock cycle torque management (algorithm_enable_flags_43_cal.rock_cycle_torque_management_enable); "
          "no e2m record, named by code membership: ")
TC = " (8C2A lies past the dumped table: a field match, its 6 records on these 6 rows)"
rows = [
    ("0x003fb4e0", "park_neutral_exit_window_timer", "rock_cycle_window_timer",
     MEMBER + "counts the calls of cm848_calculateRockCycleEngineSpeedLimit while rock_cycle_engine_speed_limit_active_flag "
     "is 1, up to rock_cycle_window_duration"),
    ("0x00408b6c", "park_neutral_exit_engine_speed_limit", "rock_cycle_engine_speed_limit", cite(0x8C2A, 0, 0x408b6c, TC)),
    ("0x00408b6e", "park_neutral_exit_minimum_commanded_throttle", "rock_cycle_minimum_commanded_throttle",
     cite(0x8C2A, 2, 0x408b6e)),
    ("0x00408b70", "park_neutral_exit_maximum_commanded_throttle", "rock_cycle_maximum_commanded_throttle",
     cite(0x8C2A, 4, 0x408b70)),
    ("0x00408b72", "park_neutral_exit_maximum_vehicle_speed", "rock_cycle_maximum_vehicle_speed", cite(0x8C2A, 6, 0x408b72)),
    ("0x00408b74", "park_neutral_exit_engine_speed_limit_ramp_step", "rock_cycle_engine_speed_limit_ramp_step",
     cite(0x8C2A, 8, 0x408b74)),
    ("0x00408b76", "park_neutral_exit_window_duration", "rock_cycle_window_duration", cite(0x8C2A, 0xA, 0x408b76)),
    ("0x0040b0fd", "park_neutral_exit_engine_speed_limit_state_bits", "rock_cycle_engine_speed_limit_state_bits",
     MEMBER + "the state bits of cm848_updateRockCycleEngineSpeedLimitWindow"),
    ("0x0040b1f6", "park_neutral_exit_engine_speed_limit_active_flag", "rock_cycle_engine_speed_limit_active_flag",
     cite(0x8A7C, 8, 0x40b1f6) + " Set by cm848_updateRockCycleEngineSpeedLimitWindow once the park / neutral switch "
     "clears, until the dwell countdown runs out"),
    ("0x0040b5ba", "park_neutral_exit_engine_speed_limit_phase", "rock_cycle_engine_speed_limit_phase",
     MEMBER + "0 = held, 1 = ramping back, 2 = idle (cm848_calculateRockCycleEngineSpeedLimit / "
     "cm848_initializeRockCycleEngineSpeedLimit)"),
    ("0x0040b1f8", "park_neutral_exit_engine_speed_limit_countdown", "rock_cycle_engine_speed_limit_countdown",
     cite(0x8A7C, 0xA, 0x40b1f8)),
    ("0x003fcd80", "park_neutral_exit_engine_speed_limit_startup_delay_count",
     "rock_cycle_engine_speed_limit_startup_delay_count",
     MEMBER + "counts up to rock_cycle_engine_speed_limit_startup_delay (e2m 8C49 +8 RE_RCTM_Run_Mode_Time)"),
    ("0x004086d2", "park_neutral_exit_engine_speed_limit_minimum_throttle", "rock_cycle_engine_speed_limit_minimum_throttle",
     cite(0x8C49, 0, 0x4086d2)),
    ("0x004086d4", "park_neutral_exit_engine_speed_limit_maximum_throttle", "rock_cycle_engine_speed_limit_maximum_throttle",
     cite(0x8C49, 2, 0x4086d4)),
    ("0x004086d6", "park_neutral_exit_engine_speed_limit_minimum_output_shaft_speed",
     "rock_cycle_engine_speed_limit_minimum_output_shaft_speed", cite(0x8C49, 4, 0x4086d6)),
    ("0x004086da", "park_neutral_exit_engine_speed_limit_startup_delay", "rock_cycle_engine_speed_limit_startup_delay",
     cite(0x8C49, 8, 0x4086da)),
    ("0x004086de", "park_neutral_exit_engine_speed_limit_countdown_axis", "rock_cycle_engine_speed_limit_countdown_axis",
     cite(0x8C4A, 0)),
    ("0x004086f2", "park_neutral_exit_engine_speed_limit_countdown_values",
     "rock_cycle_engine_speed_limit_countdown_values", cite(0x8C4B, 0)),
    ("0x003fcd7e", "park_neutral_exit_engine_speed_limit_countdown_cached_axis_offset",
     "rock_cycle_engine_speed_limit_countdown_cached_axis_offset",
     MEMBER + "the lookup cache of rock_cycle_engine_speed_limit_countdown (e2m 8C4A / 8C4B)"),
    ("0x0040a32c", "engine_speed_limit_park_neutral_exit", "engine_speed_limit_rock_cycle",
     MEMBER + "engine speed limit source 15, held at rock_cycle_engine_speed_limit during the window and ramped back"),
]
for a, cur, new, head in rows:
    p = g[idx[a]].split(",", 3)
    p += [""] * (4 - len(p))
    assert p[1] == cur, (a, p[1], cur)
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
    g[idx[a]] = f"{a},{new},{p[2]},{head} (was {cur}; {R})" + (f" | earlier note: {p[3]}" if p[3] else "")
    names.add(new)
    mapping.append(f"{a},{new},{cur},global,1")
    gmapping.append(f"{a},{new},{cur},global,1")
new = "rock_cycle_engine_speed_limit_maximum_output_shaft_speed"
assert "0x004086d8" not in idx and new not in names
g.insert(idx["0x004086da"], f"0x004086d8,{new},word,{cite(0x8C49, 6, 0x4086d8)} Read once by "
         f"cm848_updateRockCycleEngineSpeedLimitWindow (lhz @ 0x511a0c) ({R})")
gmapping.append(f"0x004086d8,{new},DAT_004086d8,global,1")
open(gp, "w").write("\n".join(g))
FUNCS = [("0x0003e2bc", "cm848_calculateParkNeutralExitEngineSpeedLimit", "cm848_calculateRockCycleEngineSpeedLimit"),
         ("0x0003e400", "cm848_initializeParkNeutralExitEngineSpeedLimit", "cm848_initializeRockCycleEngineSpeedLimit"),
         ("0x0051193c", "cm848_updateParkNeutralExitEngineSpeedLimitWindow", "cm848_updateRockCycleEngineSpeedLimitWindow")]
PFX = ("Rock cycle torque management (e2m TC_Rock_Cycle_* 8C2A / RE_RCTM_* 8C49-8C4B; "
       "algorithm_enable_flags_43_cal.rock_cycle_torque_management_enable): ")
f = open(fp).read().split("\n")
for a, cur, newf in FUNCS:
    assert re.fullmatch(r"(cm848|hpcr|mpc555)_[a-z][A-Za-z0-9]*", newf), newf
    k = next(i for i, l in enumerate(f) if l.startswith(f"{a},{cur},"))
    plate = f[k].split(",", 2)[2]
    f[k] = f"{a},{newf},{PFX}{plate} (was {cur}; {R})"
    mapping.append(f"{a},{newf},{cur},function,1")
open(fp, "w").write("\n".join(f))
for path, rows_ in ((map_path, mapping), (gmap_path, gmapping)):
    with open(path, "w") as fh:
        fh.write("\n".join(rows_) + "\n")
print(f"{len(rows)} renames, 1 new row, {len(FUNCS)} functions")
