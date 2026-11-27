"""Round 16 stage B (types): the cruise / road speed governor records.
- cruise_governor_gain_set_t (8 bytes: proportional / integral / derivative / integral acceleration gain, signed): the
  three e2m 1186 gain sets at 0x408e02 / 0x408e18 / 0x408e26, which cm848_selectCruiseGovernorGainSet reads through
  cruise_governor_gain_set_pointer (+0 / +2 / +4 / +6, sword loads); the pointer row is typed
  cruise_governor_gain_set_t *.
- second_order_filter_state_t (16 bytes: coefficient 1 / coefficient 3 pointers, output / previous output dwords): the
  record cm848_secondOrderFilter and cm848_secondOrderFilterUnsigned read (+0 / +4 pointers to the coefficients, +8 /
  +C the state; cm848_presetCruiseAndRoadSpeedGovernor writes +8 and +C). Two instances, cruise_pid_driveline_filter
  (0x3fd012) and cruise_pid_derivative_filter (0x3fd022); their four type-only pointer rows go. Both filters get
  full prototypes.
- cruise_governor_fueling_maximum_pointer (0x3fd038, was cruise_speed_upper_limit_ptr): a word row read as a pointer
  (it rendered _-prefixed); typed word *.
- New rows for the governor's DAT_ words, each with the width of its access.
usage: apply_r16b.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
GV = os.path.join(out, "global_variables.csv")
SD = os.path.join(out, "structure_definitions.csv")
FD = os.path.join(out, "function_definitions.csv")

GAIN = "e2m 1186 Cruise_RSG_{0}_Gain_Cal{1} (address from the ECU's parameter ID table)"
# address -> (name or None to keep, type, comment or None to keep; prefix 'APPEND:' appends to the old comment)
RETYPE = {
    "0x00408e02": ("cruise_governor_gain_set_1", "cruise_governor_gain_set_t",
                   "e2m 1186 +6..+C Cruise_RSG_Proportional / Integral / Derivative / Integral_Acc_Gain_Cal 'THE "
                   "PROPORTIONAL GAIN OF THE CRUISE / RSG' (address from the ECU's parameter ID table): PID gain set 1, the "
                   "normal set (1206 / 39 / 0 / 255 in the RAM dump)"),
    "0x00408e18": ("cruise_governor_gain_set_2", "cruise_governor_gain_set_t",
                   "e2m 1186 +1C..+22 Cruise_RSG_*_Gain_Cal2 'Proportional Gain for Cruise/RSG during large tracking "
                   "error': PID gain set 2, picked above cruise_governor_gain_set_2_speed_error_threshold (1809 / 58 / 0 / "
                   "255)"),
    "0x00408e26": ("cruise_governor_gain_set_3", "cruise_governor_gain_set_t",
                   "e2m 1186 +2A..+30 Cruise_RSG_*_Gain_Cal3: PID gain set 3, picked below "
                   "cruise_governor_gain_set_3_speed_error_threshold at or below the bottom droop offset (1206 / 39 / 0 / "
                   "255)"),
    "0x0040b6c0": (None, "cruise_governor_gain_set_t *", None),
    "0x003fd012": ("cruise_pid_driveline_filter", "second_order_filter_state_t",
                   "The driveline filter of the cruise / road speed governor: cm848_secondOrderFilter on the engine speed "
                   "error (coefficients cruise_pid_driveline_filter_coefficient_1 / _3, e2m 1189 +C / +E Cruise_RSG_"
                   "Driveline_Filter_C1 / C3 '2nd order driveline filter in cc/rsg gov.'); the preset loads its outputs "
                   "with the error << 16 (was the type-only pointer rows 0x3fd012 / 0x3fd016)"),
    "0x003fd022": ("cruise_pid_derivative_filter", "second_order_filter_state_t",
                   "The derivative filter of the cruise / road speed governor: cm848_secondOrderFilterUnsigned on "
                   "vehicle_speed_rise_limited into cruise_governor_filtered_road_speed (coefficients "
                   "cruise_pid_derivative_filter_coefficient_1 / _3, e2m 1189 +4 / +6 Cruise_RSG_Derivative_Filter_C1 / "
                   "C3); the preset loads its outputs with the road speed << 16 (was the type-only pointer rows 0x3fd022 / "
                   "0x3fd026)"),
    "0x003fd038": ("cruise_governor_fueling_maximum_pointer", "word *",
                   "Points at the governor's fueling maximum: cruise_governor_fueling_maximum, or "
                   "current_horsepower_peak_fueling_cal while programmable power is on (set by the preset); the governor "
                   "clamps the integrator and its output to it (was cruise_speed_upper_limit_ptr, a word row read as a "
                   "pointer)"),
}
DELETE = {"0x003fd016", "0x003fd026"}
NEW = [
    ("0x003fcff2", "cruise_top_droop_gain_for_rear_axle_ratio_high", "word",
     "Cruise control top droop gain computed for the high rear axle ratio (rear_axle_ratio_high_cal) at power-up "
     "(cm848_initializeCruiseAndRoadSpeedGovernorDroops); cm848_updateCruiseAndRoadSpeedGovernorDroops uses it while the "
     "two-speed axle switch (switch 31) is set"),
    ("0x003fcff6", "road_speed_governor_top_droop_gain_for_rear_axle_ratio_high", "word",
     "Road speed governor top droop gain computed for the high rear axle ratio at power-up; used while the two-speed "
     "axle switch is set"),
    ("0x003fcffa", "cruise_governor_gain_set_number_previous", "word",
     "cruise_governor_gain_set_number of the previous pass: a change raises cruise_governor_bumpless_transfer_flag"),
    ("0x003fcffc", "cruise_governor_speed_error_after_droop_magnitude", "word",
     "|cruise_governor_speed_error_after_droop| as cm848_selectCruiseGovernorGainSet last used it (no reader in this "
     "code)"),
    ("0x003fcffe", "cruise_governor_gear_ratio_gain_cached_axis_offset", "word",
     "Lookup cache of cruise_governor_gear_ratio_gain_axis (2 at power-up)"),
    ("0x003fd044", "cruise_governor_preset_fueling_filtered", "word",
     "final_fueling through cruise_governor_preset_fueling_filter: the fueling the steady speed window snapshots"),
    ("0x003fd046", "cruise_governor_preset_fueling_snapshot", "word",
     "cruise_governor_preset_fueling_filtered at the start of the steady speed window; becomes "
     "cruise_governor_preset_fueling when the window completes"),
    ("0x003fd04e", "cruise_governor_preset_fueling_learned_flag", "byte",
     "1 once a steady speed window has completed (stb); while 0 cruise_governor_preset_fueling follows final_fueling"),
    ("0x003fd057", "cruise_governor_sump_activation", "i16",
     "The sump activation value: (road speed change << 5) - cruise_governor_sump_threshold_gain x "
     "cruise_governor_speed_error_after_droop / 25 (sth, then extsh); the sump counts toward a trigger while it is "
     "above cruise_governor_sump_acceleration_threshold and the speed error is below "
     "cruise_governor_sump_speed_error_threshold"),
    ("0x00408e7c", "cruise_governor_sump_acceleration_threshold", "i16",
     "e2m 1189 +30 Cruise_RSG_Sump_Thres_Accel 'Threshold used in cruise sump activation equation' (MPH, 0.003051758 "
     "per count; address from the ECU's parameter ID table; lha): compared with cruise_governor_sump_activation"),
    ("0x00408e7e", "cruise_governor_sump_speed_error_threshold", "i16",
     "e2m 1189 +32 Cruise_RSG_Sump_Thres_Error 'Error threshold used in cruise sump activation equation' (MPH, 1/256 "
     "per count; lha): the sump triggers only while cruise_governor_speed_error_after_droop is below it (0x8100 = "
     "-32512 here, so it never triggers in this calibration)"),
]
STRUCTS = """# cruise_governor_gain_set_t: one PID gain set of the cruise / road speed governor (e2m 1186, PR #53 round 16):
# three instances at 0x408e02 / 0x408e18 / 0x408e26; cm848_selectCruiseGovernorGainSet loads the selected one through
# cruise_governor_gain_set_pointer into cruise_pid_proportional_gain / _integral_gain / _derivative_gain /
# _integral_acceleration_gain (lha loads)
cruise_governor_gain_set_t,,proportional_gain,short,2,"+0: e2m Cruise_RSG_Proportional_Gain_Cal* (MM3S/RPM); the working cruise_pid_proportional_gain",,verified
cruise_governor_gain_set_t,,integral_gain,short,2,"+2: e2m Cruise_RSG_Integral_Gain_Cal* (MM3S/RPM/SEC); the working cruise_pid_integral_gain",,verified
cruise_governor_gain_set_t,,derivative_gain,short,2,"+4: e2m Cruise_RSG_Derivative_Gain_Cal* (MM3S*SEC/RPM); the working cruise_pid_derivative_gain",,verified
cruise_governor_gain_set_t,,integral_acceleration_gain,short,2,"+6: e2m Cruise_RSG_Integral_Acc_Gain_Cal* (MM3S/RPM) 'Integral Acceleration Gain from the differential path'; the working cruise_pid_integral_acceleration_gain",,verified
# second_order_filter_state_t: the record of cm848_secondOrderFilter / cm848_secondOrderFilterUnsigned (PR #53 round 16):
# output = (c1 x input << 16 - c3 x output_previous + (c3 - c1 + 0x10000) x output) >> 16; instances
# cruise_pid_driveline_filter (0x3fd012) and cruise_pid_derivative_filter (0x3fd022)
second_order_filter_state_t,,coefficient_1,word*,4,"+0: points at coefficient 1 (1/65536): the weight of the new input",,verified
second_order_filter_state_t,,coefficient_3,word*,4,"+4: points at coefficient 3 (1/65536): the weight of the output before last",,verified
second_order_filter_state_t,,output,dword,4,"+8: the filter output (Q16.16 in cm848_secondOrderFilter; its integer part is returned)",,verified
second_order_filter_state_t,,output_previous,dword,4,"+C: the output of the previous call",,verified
"""
PROTOS = """0x000564c0,cm848_secondOrderFilter,return,,sword,The new output's integer part (r3: (output >> 16) sign-extended)
0x000564c0,cm848_secondOrderFilter,0,input,sword,The input (r3; signed 16-bit)
0x000564c0,cm848_secondOrderFilter,1,filter,second_order_filter_state_t *,The filter record (r4): coefficient pointers and the two outputs
0x00056608,cm848_secondOrderFilterUnsigned,return,,word,(output >> 16) & 0xffff of an output already shifted down 16 (r3): 0 in this build
0x00056608,cm848_secondOrderFilterUnsigned,0,input,uint,The input (r3; the caller passes a 16-bit road speed)
0x00056608,cm848_secondOrderFilterUnsigned,1,filter,second_order_filter_state_t *,The filter record (r4)
"""

lines = open(GV).read().split("\n")
index = {l[:10]: i for i, l in enumerate(lines) if l.startswith("0x")}
for addr in list(RETYPE) + sorted(DELETE):
    assert addr in index, f"{addr}: no row"
for addr, _, _, _ in NEW:
    assert addr not in index, f"{addr}: has a row"
for addr, (name, typ, comment) in RETYPE.items():
    i = index[addr]
    a, n, t, c = (lines[i].split(",", 3) + ["", "", ""])[:4]
    was = f" (was {n} {t})" if (name and name != n) else (f" (was {t})" if t != typ else "")
    new_comment = (comment + was) if comment else (c + (f" | typed {typ} in PR #53 round 16 (was {t})" if t != typ else ""))
    if comment and c:
        new_comment += " | earlier note: " + c
    lines[i] = ",".join([a, name or n, typ, new_comment])
for addr in DELETE:
    lines[index[addr]] = None
for addr, name, typ, comment in NEW:
    v = int(addr, 16)
    best = max((k for k in index if int(k, 16) < v), key=lambda k: int(k, 16))
    i = index[best]
    lines[i] = lines[i] + "\n" + ",".join([addr, name, typ, comment])
open(GV, "w").write("\n".join(l for l in lines if l is not None))

sd = open(SD).read()
assert "cruise_governor_gain_set_t" not in sd and "second_order_filter_state_t" not in sd
anchor = sd.index("ema_filter_state_t,,coefficient,")
start = sd.rfind("\n", 0, anchor) + 1
open(SD, "w").write(sd[:start] + STRUCTS + sd[start:])

fd = open(FD).read()
assert "0x000564c0" not in fd and "0x00056608" not in fd
fd = fd.rstrip("\n") + "\n" + PROTOS
open(FD, "w").write(fd)
print(f"{len(RETYPE)} retyped, {len(DELETE)} deleted, {len(NEW)} new rows, 2 struct types, 2 prototypes")
