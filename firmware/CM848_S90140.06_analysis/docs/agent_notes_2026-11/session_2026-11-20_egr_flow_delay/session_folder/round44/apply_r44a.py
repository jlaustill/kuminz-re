"""Round 44 stage A: the three rows round 39 marked unverified, named from their code use, and the last typed junk row.
- The parameter ID table resolves none of the three. 0x3ff6ce = 107D +0x48 and 0x408e96 = 118F +0x0E: no record at
  those offsets in any of the 68 e2m files. 0x408a76 sits in a pedal block past the dumped table (8C5F ends at
  0x408a64, 8C55 starts at 0x408a8e), and no e2m pedal record lines up with it.
- 0x3fb52a was fuel_demand_enable_sync_flag_shadow+2 (undefined2), the one typed row round 43 stage B kept.
- 0x408e94 gets a documentation row from e2m 118F +0x0C (no code reads it).
Dump values agree with ROM through the copy rule (RAM = ROM + 0x39a3e6). Idempotent.
usage: apply_r44a.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 44"
NONE68 = "none of the 68 e2m files has a record at"
# address, current name, rendered old name (for the proof), new name, new type (None = keep), comment, history extra
ROWS = [
    ("0x003ff6ce", "governor_override_fuel_decay", "governor_override_fuel_decay",
     "all_speed_governor_vacuum_cruise_fueling_reduction", None,
     "cm848_runOperatingModeSpeedGovernor (lhz @ 0xf738, its only access): while cruise_control_engaged_flag is 1 and "
     "algorithm_enable_flags_43_cal.vacuum_throttle_cruise_enable is set, all_speed_governor_fueling is reduced by this "
     "and floored at 0 (44 here). In the ASG block 107D at +0x48: 107D's records end at +0x42 ASG_Delta_Max_Limit, 107B "
     f"starts at 0x3ff6d0, and {NONE68} +0x44..+0x49 (offsets read as numbers)", ""),
    ("0x00408e96", "governor_override_fuel_threshold", "governor_override_fuel_threshold",
     "cruise_accelerator_override_throttle_threshold", None,
     "cm848_selectCruiseOrUserFueling (lhz @ 0x41270, its only access): on the accelerator path the operating mode "
     "governor takes the fueling from cruise only while commanded_throttle_state.commanded_throttle is above this, its "
     "fuel demand is above the cruise fueling and the cruise output differs from the road speed governor's; TSC1, modes "
     "37 / 38 and the calibrated fixed fuel demand take it regardless. 0 here, so any throttle above 0 qualifies. In "
     "the cruise block 118F at +0x0E: 118F's records end at +0x0C Cruise_Out_Of_Gear_Disable, 1071 starts at 0x408e9a, "
     f"and {NONE68} +0x0D..+0x11", ""),
    ("0x00408a76", "cruise_speed_target_min", "cruise_speed_target_min",
     "accelerator_pedal_single_channel_minimum_idle_threshold", None,
     "cm848_calculateAcceleratorPedalDemandFromChannels (lhz @ 0x3d358, its only access): with the pedal fault latched, "
     "the demand stays valid only while the fault is pedal_position_sensor_2_low_error (fault 349, P2127: channel 98) "
     "and accelerator_pedal_idle_threshold_a_cal (channel 97's learned idle threshold, 78 in the dump) is at least this "
     "(68). So it is the minimum learned idle threshold for running on channel 97 alone. In the pedal block "
     "0x408a72-0x408a7e, past the dumped parameter ID table (8C5F ends at 0x408a64, 8C55 starts at 0x408a8e); no record "
     "in the 68 e2m files describes dual-channel pedal idle learning or disagreement. The old name came from reading "
     "0x3fee46 as a cruise target", ""),
    ("0x003fb52a", "fuel_demand_enable_sync_flag_shadow+2", "fuel_demand_enable_sync_flag_shadow_2",
     "cruise_control_engaged_flag_previous_arbitration", "word",
     "cruise_control_engaged_flag at the end of the previous cm848_arbitrateGovernedFueling pass (lhz @ 0x406d4, "
     "sth @ 0x407cc through the pointer formed at 0x406c0; the raw scan finds no other access). 1 then 0 = cruise has "
     "just disengaged, and the pass starts cruise_fuel_ramp_down_working at final_fueling. "
     "cruise_control_engaged_previous_flag (0x3fb530, a dword: lwz / stw) is the same signal's copy for "
     "cm848_calculateCruiseControlFueling",
     ", rendered fuel_demand_enable_sync_flag_shadow_2: the typed junk row of an old export, undefined2"),
]
NEW_ROW = ("0x00408e94,cruise_out_of_gear_disable,word,e2m 118F +0x0C Cruise_Out_Of_Gear_Disable 'If enabled then it "
           "disables cruise when an out of gear situation is detected' (HEX, unsigned; 1 here). No code reads it: no "
           "instruction in the ROM or the live flash2 forms its address (raw lis + displacement scan), and none forms a "
           "pointer to the 118F block. A ROM constant copied to RAM (ROM 0x6eaae), so no _cal (PR #53 round 44)")
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "cruise_control_engaged_flag_previous_arbitration" in names:
    print("already applied")
    sys.exit(0)
rows = ["address,name,old_label,kind,dims"]
for a, cur, rendered, new, typ, head, extra in ROWS:
    assert not any(t in BANNED for t in new.split("_")), new
    assert new not in names, new
    i = next(k for k, l in enumerate(g) if l.startswith(a + "," + cur + ","))
    p = g[i].split(",", 3)
    earlier = f" | earlier note: {p[3]}" if len(p) > 3 and p[3] else ""
    g[i] = f"{a},{new},{typ or p[2]},{head} (was {cur}{extra}; {R}){earlier}"
    rows.append(f"{a},{new},{rendered},global,1")
assert not any(l.startswith("0x00408e94,") for l in g)
k = next(k for k, l in enumerate(g) if l.startswith("0x00408e96,"))
g.insert(k, NEW_ROW)
open(gp, "w").write("\n".join(g))
fp = os.path.join(out, "function_renames.csv")
f = open(fp).read()
old = "(fuel_demand_control.calculated above governor_override_fuel_threshold)"
new = ("(the operating mode governor's fuel demand above the cruise fueling, with "
       "commanded_throttle_state.commanded_throttle above cruise_accelerator_override_throttle_threshold)")
if new not in f:
    assert f.count(old) == 1, f.count(old)
    f = f.replace(old, new)
    open(fp, "w").write(f)
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print("4 rows renamed (0x3fb52a typed word), 0x408e94 documented, 1 plate corrected")
