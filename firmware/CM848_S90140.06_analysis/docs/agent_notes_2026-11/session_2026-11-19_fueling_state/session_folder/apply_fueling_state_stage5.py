"""Stage 5 of the FUELING_STATE work (2026-11-19, PR #52): the power take-off governor's words named from the e2m
blocks that line up by offset with matching units and code use (10AB the governor terms, 109E its state words, 11B4
the speed settings, 109D the engage window, 10AA the gains), code 32 named (e2m MSOVRIDE + [MSODEN] master / slave
override), and the crank routine merged from a second file. Every old row is asserted before it is replaced.
Usage: apply_fueling_state_stage5.py <CM848 output dir> [extra.py]"""
import os
import sys

OUT = sys.argv[1]
MEMBER_RENAMES = {   # FUELING_STATE value: (new suffix or None, new comment) - the e2m label part is kept
    32: ("MASTER_SLAVE_OVERRIDE", "final_fueling_state / fuel_demand_arbitrated_state: fuel_limit_mode_active_flag set "
         "without fuel_limit_secondary_flag - the fuel is fuel_demand_arbitrated_a. e2m MSOVRIDE with [MSODEN] Enable "
         "overriding slave Final_Fueling / Final_Timing: one ECM overrides another's final fueling. Nothing stores "
         "either word (both only lhz; 0 in the RAM dump): not fitted on this single-ECM truck"),
    37: (None, "only compared (engine_operating_mode / operating_mode_governor_output.mode_code / cruise_fuel_demand_mode_prev "
         "- next to the TSC1 modes 1 / 2) - never stored in this build. The e2m T2 family has high gear / low gear / "
         "neutral / shift / lockout / lamp drivers: probably a two-speed axle or transfer case shift controller (not proved)"),
    38: (None, "only compared (engine_operating_mode / operating_mode_governor_output.mode_code / cruise_fuel_demand_mode_prev "
         "- next to the TSC1 modes 1 / 2) - never stored in this build; see 37 for the T2 family"),
    49: (None, "only compared (final_fueling_state) - never stored in this build. OFC is the combustion reference's "
         "oxygen-fuel control (e2m CBR_OFC_*; code 58 OFCDERAT is its derate)"),
    50: (None, "only compared (final_fueling_state) - never stored in this build. AFR is the air-fuel ratio (e2m "
         "CBO_Air_Fuel_Ratio_Ref / CBP_Air_Fuel_Ratio)"),
}
FUNCTIONS = {}
GLOBALS = {   # address: (old name, new name, new type or None, comment)
    # e2m block 10AB (PTO governor terms; base 0x40af28 = power_take_off_governor_fuel_demand = PTO_Fueling)
    "0x0040af2a": ("governor_speed_error_term", "power_take_off_governor_filtered_speed_error", None,
                   "e2m 10AB +2 PTO_Filtered_Error_Term (rpm x 8): the filtered speed error of "
                   "cm848_calculatePowerTakeOffGovernorSpeedError (was governor_speed_error_term)"),
    "0x0040af2c": ("governor_pid_derivative_clamped", "power_take_off_governor_proportional_term", None,
                   "e2m 10AB +4 PTO_Proportional_Term: power_take_off_proportional_gain x "
                   "power_take_off_governor_proportional_gain_adjustment x the speed error, clamped (was "
                   "governor_pid_derivative_clamped)"),
    "0x0040af30": ("governor_pid_derivative_component", "power_take_off_governor_derivative_term", None,
                   "e2m 10AB +8 PTO_Derivative_Term: power_take_off_derivative_gain x "
                   "power_take_off_governor_derivative_gain_adjustment x the error change, clamped (was "
                   "governor_pid_derivative_component)"),
    "0x0040af34": ("governor_speed_product_cached", "power_take_off_governor_integral_fueling", None,
                   "e2m 10AB +C PTO_Integral_Fueling (was governor_speed_product_cached)"),
    "0x0040af38": ("governor_pid_derivative_prev", "power_take_off_governor_droop_adjusted_fueling", None,
                   "e2m 10AB +10 PTO_Droop_Adjusted_Fueling: the fuel above power_take_off_governor_no_load_fuel scaled "
                   "by the droop (was governor_pid_derivative_prev)"),
    "0x0040af3c": ("governor_pid_derivative", "power_take_off_governor_proportional_derivative_fueling", None,
                   "e2m 10AB +14 PTO_PD_Fueling: the proportional + derivative terms, clamped (was "
                   "governor_pid_derivative)"),
    "0x0040af40": ("protection_monitored_rpm", "power_take_off_governor_smoothed_reference_engine_speed", None,
                   "e2m 10AB +18 PTO_Reference_Speed: power_take_off_requested_engine_speed smoothed by "
                   "cm848_smoothPowerTakeOffReferenceEngineSpeed (stale while inactive) (was protection_monitored_rpm)"),
    "0x0040af42": ("governor_fuel_integral_error", "power_take_off_governor_droop_compensated_speed_error", None,
                   "e2m 10AB +1A PTO_Droop_Compensated_Error (was governor_fuel_integral_error)"),
    "0x0040af44": ("governor_speed_d_gain_factor", "power_take_off_governor_derivative_gain_adjustment", None,
                   "e2m 10AB +1C PTO_QD_Adjustment (x 1/128; 0x80 = 1.0): scales the derivative term (was "
                   "governor_speed_d_gain_factor)"),
    "0x0040af46": ("governor_speed_d_gain_factor_b", "power_take_off_governor_integral_gain_adjustment", None,
                   "e2m 10AB +1E PTO_QI_Adjustment (x 1/128; 0x80 = 1.0): scales the integral step - not a second "
                   "derivative factor (was governor_speed_d_gain_factor_b)"),
    "0x0040af48": ("governor_speed_p_gain_factor", "power_take_off_governor_proportional_gain_adjustment", None,
                   "e2m 10AB +20 PTO_QP_Adjustment (x 1/128; 0x80 = 1.0): scales the proportional term (was "
                   "governor_speed_p_gain_factor)"),
    "0x0040af4a": ("governor_speed_target_ceiling", "power_take_off_governor_no_load_fuel", None,
                   "e2m 10AB +22 PTO_No_Load_Fuel: the fuel the droop is measured from (was governor_speed_target_ceiling)"),
    # e2m block 109E (base 0x40af4c)
    "0x0040af4c": ("power_take_off_governor_reference_engine_speed", "power_take_off_requested_engine_speed", None,
                   "e2m 109E +0 PTO_Requested_Speed (rpm x 8): the target the state machine sets and "
                   "cm848_rampPowerTakeOffReferenceEngineSpeed ramps; the engine speed while inactive; PGN 65264 bytes "
                   "4-5. 109E goes on with PTO_Status / PTO_State / J1939_PTO_State / Chrysler_Park_Neutral_Flag = "
                   "0x40af4e / 50 / 52 / 54 (was power_take_off_governor_reference_engine_speed / protection_rpm_reference)"),
    # e2m block 11B4 (base 0x3fd884, the EEPROM mirror = EEPROM 0x402 + offset; RAM dump values in the comments)
    "0x003fd886": ("governor_rpm_integrator_step", "power_take_off_engagement_slew_rate_cal", None,
                   "EEPROM 0x404 - e2m 11B4 +2 PTO_Engagement_Slew_Rate (64) (was governor_rpm_integrator_step)"),
    "0x003fd888": ("engine_speed_control_maximum_vehicle_speed_cal", "power_take_off_maximum_vehicle_speed_cal", None,
                   "EEPROM 0x406 - e2m 11B4 +4 PTO_Max_Road_Speed (512 = 2 mph): the power take-off governor waits "
                   "above it (was engine_speed_control_maximum_vehicle_speed_cal)"),
    "0x003fd88a": ("protection_rpm_high_reference", "power_take_off_minimum_reference_engine_speed_cal", None,
                   "EEPROM 0x408 - e2m 11B4 +6 PTO_Minimum_Reference_Speed (8800 = 1100 rpm) (was "
                   "protection_rpm_high_reference)"),
    "0x003fd88c": ("protection_eval_step_count", "power_take_off_remote_count_limit_cal", None,
                   "EEPROM 0x40a - e2m 11B4 +8 PTO_Remote_Count_Limit (5): remote switch presses counted (was "
                   "protection_eval_step_count)"),
    "0x003fd88e": ("governor_rpm_ref_target_0", "power_take_off_remote_speed_2_cal", None,
                   "EEPROM 0x40c - e2m 11B4 +A PTO_Remote_Speed_2 (11200 = 1400 rpm) (was governor_rpm_ref_target_0)"),
    "0x003fd890": ("governor_rpm_ref_target_1", "power_take_off_remote_speed_3_cal", None,
                   "EEPROM 0x40e - e2m 11B4 +C PTO_Remote_Speed_3 (12800 = 1600 rpm) (was governor_rpm_ref_target_1)"),
    "0x003fd892": ("governor_rpm_ref_target_2", "power_take_off_remote_speed_4_cal", None,
                   "EEPROM 0x410 - e2m 11B4 +E PTO_Remote_Speed_4 (14400 = 1800 rpm) (was governor_rpm_ref_target_2)"),
    "0x003fd894": ("governor_rpm_ref_target_3", "power_take_off_remote_speed_5_cal", None,
                   "EEPROM 0x412 - e2m 11B4 +10 PTO_Remote_Speed_5 (16000 = 2000 rpm) (was governor_rpm_ref_target_3)"),
    "0x003fd896": ("governor_rpm_ref_target_4", "power_take_off_set_resume_speed_cal", None,
                   "EEPROM 0x414 - e2m 11B4 +12 PTO_Set_Resume_Speed (8800 = 1100 rpm) (was governor_rpm_ref_target_4)"),
    "0x003fd898": ("governor_rpm_ref_step_delta", "power_take_off_ramp_rate_cal", None,
                   "EEPROM 0x416 - e2m 11B4 +14 PTO_Ramp_Rate (200): the accelerate / coast step (was "
                   "governor_rpm_ref_step_delta)"),
    "0x003fd89a": ("power_take_off_remote_switch_mode_cal", "power_take_off_switch_enable_option_cal", None,
                   "EEPROM 0x418 - e2m 11B4 +16 PTO_Switch_Enable_Option (0 here; 0 lets the remote switch 19 take over "
                   "from cab control) (was power_take_off_remote_switch_mode_cal - the first word of the dword "
                   "protection_override_active_flag)"),
    # e2m block 109D (base 0x4071d8; ROM-copied - no _cal)
    "0x004071d8": ("protection_eval_rpm_upper_cal", "power_take_off_maximum_engage_engine_speed", None,
                   "e2m 109D +0 PTO_Maximum_Engage_Speed: the engine speed window for engaging (was "
                   "protection_eval_rpm_upper_cal)"),
    "0x004071da": ("protection_eval_rpm_lower_cal", "power_take_off_minimum_engage_engine_speed", None,
                   "e2m 109D +2 PTO_Minimum_Engage_Speed (was protection_eval_rpm_lower_cal)"),
    "0x004071dc": ("protection_eval_frame_limit_cal", "power_take_off_remote_switch_timeout", None,
                   "e2m 109D +4 PTO_Remote_Switch_Timeout: the time limit of the remote switch press count (passes) (was "
                   "protection_eval_frame_limit_cal)"),
    # e2m block 10AA (base 0x40718e; ROM-copied - no _cal)
    "0x0040718e": ("governor_speed_d_scale_cal", "power_take_off_derivative_gain", None,
                   "e2m 10AA +0 PTO_Derivative_Gain (was governor_speed_d_scale_cal)"),
    "0x00407190": ("protection_filter_state_cal", "power_take_off_speed_error_filter_coefficient", "word",
                   "e2m 10AA +2 PTO_Error_Filter_Constant (a word): the coefficient the speed error filter state "
                   "points at (was protection_filter_state_cal, typed byte)"),
    "0x00407192": ("governor_integrator_lower_bound_cal", "power_take_off_speed_error_clamp_maximum", None,
                   "e2m 10AA +4 PTO_Filter_Clamp_Max (+8000 = 1000 rpm): the upper clamp of the speed error - the old "
                   "name had it as the lower bound (was governor_integrator_lower_bound_cal)"),
    "0x00407194": ("governor_integrator_upper_bound_cal", "power_take_off_speed_error_clamp_minimum", None,
                   "e2m 10AA +6 PTO_Filter_Clamp_Min (-8000): the lower clamp of the speed error (was "
                   "governor_integrator_upper_bound_cal)"),
    "0x00407198": ("governor_speed_p_scale_cal", "power_take_off_fueling_clamp_minimum", None,
                   "e2m 10AA +A PTO_Fueling_Clamp_Min: the floor of the integral and of "
                   "power_take_off_governor_fuel_demand (was governor_speed_p_scale_cal)"),
    "0x0040719a": ("governor_blend_factor_cal", "power_take_off_integral_constant", None,
                   "e2m 10AA +C PTO_Integral_Constant: its complement (0x8000 - it) scales the integral step (was "
                   "governor_blend_factor_cal)"),
    "0x0040719c": ("governor_speed_gain_scale_cal", "power_take_off_proportional_gain", None,
                   "e2m 10AA +E PTO_Proportional_Gain (was governor_speed_gain_scale_cal)"),
    "0x0040719e": ("protection_rpm_hysteresis_cal", "power_take_off_reference_step_limit", None,
                   "e2m 10AA +10 PTO_Reference_Step_Limit: the largest step of the smoothed reference per pass (was "
                   "protection_rpm_hysteresis_cal)"),
    "0x004071a0": ("protection_smoothing_filter_coefficient", "power_take_off_reference_filter_coefficient", None,
                   "e2m 10AA +12 PTO_Reference_Ramp_Const: the EMA coefficient of the smoothed reference (was "
                   "protection_smoothing_filter_coefficient)"),
    "0x004071a2": ("protection_rpm_monitor_mode_cal", "power_take_off_gain_adjustment_mode", None,
                   "e2m 10AA +14 PTO_Gain_Adj_Mode (was protection_rpm_monitor_mode_cal)"),
}
TEXT_REPLACEMENTS = []   # (csv file name, exact old text, new text) applied after the row edits
if len(sys.argv) > 2:
    exec(open(sys.argv[2]).read())


def edit(path, fn):
    with open(path, newline="") as f:
        text = f.read()
    eol = "\r\n" if "\r\n" in text else "\n"
    lines = fn(text.split(eol))
    with open(path, "w", newline="") as f:
        f.write(eol.join(lines))


def one(lines, predicate, what):
    hits = [i for i, line in enumerate(lines) if predicate(line)]
    assert len(hits) == 1, (what, len(hits))
    return hits[0]


renamed_members = []


def enums(lines):
    for value, (suffix, comment) in MEMBER_RENAMES.items():
        i = one(lines, lambda line, v=value: line.startswith(f"FUELING_STATE,{v},"), f"member {value}")
        enum, v, name, rest = lines[i].split(",", 3)
        old_comment, size = rest.rsplit(",", 1)
        label = " - e2m label " + old_comment.split(" - e2m label ", 1)[1] if " - e2m label " in old_comment else ""
        new_name = f"FUELING_STATE_{suffix}" if suffix else name
        if new_name != name:
            renamed_members.append((name, new_name))
        comment = comment + label
        assert "," not in comment and '"' not in comment, value
        lines[i] = f"{enum},{v},{new_name},{comment},{size}"
    header = one(lines, lambda line: line.startswith("# Fueling State (renamed 2026-11-19"), "header")
    lines[header] = lines[header].replace("FUELING_STATE_UNIDENTIFIED_<n> (32 37 38 49 50)",
                                          "FUELING_STATE_UNIDENTIFIED_<n> (37 38 49 50)")
    return lines


def functions(lines):
    for address, (old, new, comment) in FUNCTIONS.items():
        i = one(lines, lambda line, a=address, o=old: line.split(",")[:2] == [a, o], f"function {address}")
        lines[i] = f"{address},{new},{comment}"
    return lines


def globals_(lines):
    for address, (old, new, new_type, comment) in GLOBALS.items():
        i = one(lines, lambda line, a=address, o=old: line.startswith(f"{a},{o},"), f"global {address}")
        parts = lines[i].split(",", 3)
        if comment is None:
            kept = parts[3] if len(parts) > 3 else ""
            comment = (kept + " " if kept else "") + f"(was {old})"
        lines[i] = f"{address},{new},{new_type or parts[2]},{comment}"
    return lines


edit(os.path.join(OUT, "enums.csv"), enums)
edit(os.path.join(OUT, "function_renames.csv"), functions)
edit(os.path.join(OUT, "global_variables.csv"), globals_)
for name, old, new in TEXT_REPLACEMENTS:
    path = os.path.join(OUT, name)
    text = open(path, newline='').read()
    assert text.count(old) == 1, (name, old[:60], text.count(old))
    open(path, 'w', newline='').write(text.replace(old, new))
here = os.path.dirname(os.path.abspath(__file__))
with open(os.path.join(here, "map_stage5.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, (old, new, _) in FUNCTIONS.items():
        f.write(f"{address},{new},{old},function\n")
    for address, (old, new, *_rest) in GLOBALS.items():
        f.write(f"{address},{new},{old},global\n")
    for old, new in renamed_members:
        f.write(f",{new},{old},enum member\n")
print(f"applied stage 5: {len(renamed_members)} members renamed, {len(FUNCTIONS)} functions, {len(GLOBALS)} globals")
