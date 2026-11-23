"""Round 57 stage A: the cruise cluster at 0x511ea8-0x513980, read function by function, and the cruise engine speed /
vehicle speed ratio ("N_V ratio") family named from e2m 8A0E / 8A0F (table-resolved).
- 10 unprefixed legacy names (none in CM550). Two were wrong-domain: governor_cruise_dualCalc_dispatch runs the coolant
  overheat derate monitors and engine_coolantTemp_delta_calc is e2m 8A72 +0 CT_Derate_Temp_Error. fuel_demand_timing_
  initialize initializes the TSC1 lost management and the rock cycle lookup cache, nothing of fuel demand or timing.
- cm848_integrateCruiseRpmRatioChange follows the ratio vocabulary.
- The five cruise state getters get a CRUISE_CONTROL_STATE return (no parameters: the return row is the whole
  prototype; they return in r3: li r3 / extsh r3 before blr). A pilot: dropped if the build adds casts.
- The ratio family: 12 rows (two type-only rows named: the filter state and its coefficient).
Idempotent.  usage: apply_r57a.py <repo> <map.csv>"""
import os
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r53")
from e2m_cite import Records, Rows  # noqa: E402

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
OUT = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 57"
fr_path = os.path.join(OUT, "function_renames.csv")
fr = open(fr_path).read()
if "cm848_selectBaseCruiseState," in fr:
    print("already applied")
    sys.exit(0)
rec = Records(repo)
g = Rows(repo, R)
RATIO = "cruise_engine_to_vehicle_speed_ratio"

# the ratio family: (address, current, new, e2m block / offset or None, text)
GLOBALS = [
    ("0x0040b206", "cruise_rpm_ratio_ema", RATIO, 0x8A0F, 0x2,
     "cm848_filterCruiseEngineToVehicleSpeedRatio's output: the filtered (filtered_engine_speed + "
     "cruise_engine_speed_previous) x 128 / vehicle_speed_rise_limited. cm848_updateCruiseControlDeniedStatus denies "
     f"cruise (status 0xa) outside {RATIO}_minimum..{RATIO}_maximum."),
    ("0x003fcda6", "cruise_rpm_ratio_ema_prev", f"{RATIO}_previous", None, None,
     f"{RATIO} of the previous pass (cm848_cruiseControlPeriodicUpdate stores it last): "
     "cm848_integrateCruiseEngineToVehicleSpeedRatioChange integrates the difference."),
    ("0x0040b204", "cruise_rpm_ratio_integral", f"{RATIO}_integral", None, None,
     "The engine speed / vehicle speed ratio integrator (e2m 8A0F +0 Cruise_N_V_Ratio_Int - cited in the earlier "
     "note): the running sum of the ratio's change (cm848_integrateCruiseEngineToVehicleSpeedRatioChange)."),
    ("0x00408728", "cruise_rpm_ratio_integral_limit", f"{RATIO}_integral_limit", None, None,
     "The integrator's kick-out level (e2m 8A0E +A Cruise_N_V_Ratio_Int_Tolerance - cited in the earlier note)."),
    ("0x0040872c", "cruise_rpm_ratio_max", f"{RATIO}_maximum", 0x8A0E, 0xE,
     f"Cruise is denied (cruise_control_denied_status 0xa) while {RATIO} is above it."),
    ("0x0040872e", "cruise_rpm_ratio_min", f"{RATIO}_minimum", 0x8A0E, 0x10,
     f"Cruise is denied (cruise_control_denied_status 0xa) while {RATIO} is below it."),
    ("0x00408724", "cruise_steady_debounce_count", f"{RATIO}_integral_clear_count", 0x8A0E, 0x6,
     f"When {RATIO}_steady_count reaches it the integral is zeroed "
     "(cm848_integrateCruiseEngineToVehicleSpeedRatioChange)."),
    ("0x00408726", "cruise_ratio_steady_threshold", f"{RATIO}_integral_clear_level", 0x8A0E, 0x8,
     f"A pass whose ratio change is below it counts toward {RATIO}_steady_count; a larger change is integrated."),
    ("0x003fcdae", "cruise_steady_state_debounce_counter", f"{RATIO}_steady_count", None, None,
     f"Passes in a row with the ratio's change below {RATIO}_integral_clear_level; held at "
     f"{RATIO}_integral_clear_count - where the integral is zeroed - and reset by a larger change "
     "(cm848_integrateCruiseEngineToVehicleSpeedRatioChange)."),
    ("0x003fcdac", "cruise_rpm_prev_sample", "cruise_engine_speed_previous", None, None,
     "filtered_engine_speed of the previous pass (cm848_cruiseControlPeriodicUpdate stores it last): the ratio "
     "averages it with the current one."),
]
for a, cur, new, block, off, text in GLOBALS:
    if block is not None:
        assert rec.size(block, off) == 2, (a, block, off)
    g.rename(rec, a, cur, new, block, off, text)
# the two type-only rows
for a, rendered, new, typ, block, off, text in [
        ("0x0040872a", "WORD_0040872a", f"{RATIO}_filter_coefficient", "word", 0x8A0E, 0xC,
         f"The EMA weight of the previous value in 1/65536 that {RATIO}_filter_state.coefficient points at "
         "(cm848_initializeCruiseControl sets the pointer)."),
        ("0x003fcd96", "ema_filter_state_t_003fcd96", f"{RATIO}_filter_state", "ema_filter_state_t", None, None,
         f"The EMA state of cm848_filterCruiseEngineToVehicleSpeedRatio: coefficient -> {RATIO}_filter_coefficient "
         "(e2m 8A0E +C) and the Q16.16 accumulator - both set by cm848_initializeCruiseControl.")]:
    p = g.row(a)
    assert p[1] == "" and p[2] == typ, p
    g.check(new)
    head = (rec.cite(block, off, int(a, 16)) + " " if block is not None else "") + text
    g.g[g.idx[a]] = f"{a},{new},{typ},{head} (was {rendered} - a type-only row; {R}) | earlier note: {p[3]}"
    g.mapping.append(f"{a},{new},{rendered},global,1")
g.save(map_path)

KEEP = None
FUNCS = [
    ("0x00511ea8", "fuel_demand_timing_initialize", "cm848_initializeRockCycleAndTsc1LostManagement",
     "Boot (cm848_applicationMain): the initializer of cm848_updateRockCycleEngineSpeedLimitWindow and "
     "cm848_updateParkNeutralFlagAndTsc1Activity just before it in ROM - sets tsc1_lost_management_active_flag / "
     "loads tsc1_lost_counter from tsc1_lost_counter_initial_value / sets the rock cycle countdown lookup's cache to "
     "its first segment (2). Nothing here is fuel demand or timing"),
    ("0x00512554", "governor_fuel_mode_initialization", "cm848_initializeCruiseControl",
     "Boot (cm848_applicationMain): the initializer of cm848_cruiseControlPeriodicUpdate - the on / off toggle off - "
     "cruise_control_denied_status and cruise_control_last_cutout_reason 1 - the raw switch requests 5 and the "
     "debounced ones CRUISE_SWITCH_IDLE - the engine speed / vehicle speed ratio filter (coefficient e2m 8A0E +C) with "
     "its previous sample / integral / steady count zeroed. It also zeroes the word at 0x3fcd90 which nothing reads"),
    ("0x005125f4", "governor_cruise_coastButton_handler", "cm848_selectCruiseStateForCoastSwitch",
     "Cruise state for a COAST switch request (cm848_cruiseControlPeriodicUpdate while the cruise is not denied): "
     "while engaged a new press gives CRUISE_BUMP_DOWN and reloads cruise_coast_accelerate_hold_countdown from "
     "cruise_coast_accelerate_hold_time (e2m 8A0E +2 Coast_Accel_Timer) and holding it until the countdown ends gives "
     "CRUISE_COAST; otherwise the state stays"),
    ("0x00512724", "governor_cruise_baseState_get", "cm848_selectBaseCruiseState",
     "The base cruise state of each pass before the switch handlers (cm848_cruiseControlPeriodicUpdate): CRUISE_HOLD "
     "while cruise_control_engaged_flag is set / else CRUISE_CANCEL while cruise_resume_speed_valid_flag is set (a "
     "resume speed is kept) / else CRUISE_OFF"),
    ("0x0051275c", "governor_cruise_rpmRatio_ema", "cm848_filterCruiseEngineToVehicleSpeedRatio",
     f"e2m 8A0F +2 Cruise_N_V_Ratio: (filtered_engine_speed + cruise_engine_speed_previous) x 128 / "
     f"vehicle_speed_rise_limited (0xffff when that would overflow) filtered by exponentialMovingAverage with "
     f"{RATIO}_filter_state (coefficient e2m 8A0E +C Cruise_N_V_Calc_Filter_Constant) into {RATIO}. The first step "
     "of cm848_cruiseControlPeriodicUpdate"),
    ("0x005127d8", "cm848_integrateCruiseRpmRatioChange", "cm848_integrateCruiseEngineToVehicleSpeedRatioChange",
     f"e2m 8A0F +0 Cruise_N_V_Ratio_Int: adds the pass's change of {RATIO} to {RATIO}_integral; a change below "
     f"{RATIO}_integral_clear_level (8A0E +8) counts {RATIO}_steady_count instead and at "
     f"{RATIO}_integral_clear_count (8A0E +6) passes the integral is zeroed. The kick-out level is "
     f"{RATIO}_integral_limit (8A0E +A)"),
    ("0x00512878", "governor_cruise_resumeButton_handler", "cm848_selectCruiseStateForResumeSwitch",
     "Cruise state for a RESUME switch request: not engaged with a resume speed kept (cruise_resume_speed_valid_flag) "
     "it gives CRUISE_RESUME and reloads the hold countdown; while engaged a new press gives CRUISE_BUMP_UP (and "
     "reloads the countdown) and holding it until the countdown ends gives CRUISE_ACCELERATE; otherwise the state "
     "stays"),
    ("0x0051291c", "governor_cruise_setButton_handler", "cm848_selectCruiseStateForSetSwitch",
     "Cruise state for a SET switch request: a new press with vehicle_speed_rise_limited at or above "
     "cruise_minimum_set_speed gives CRUISE_SET (the set speed latches) and reloads the hold countdown; holding it "
     "while engaged until the countdown ends gives CRUISE_COAST; otherwise the state stays. It runs only while the "
     "cruise is not denied (cm848_updateCruiseControlDeniedStatus returned 0)"),
    ("0x00512f18", "governor_cruise_standbyState_get", "cm848_selectDeniedCruiseState",
     "The cruise state while the cruise is denied (cm848_updateCruiseControlDeniedStatus nonzero - in place of the "
     "switch handlers): CRUISE_CANCEL (the resume speed is kept) when the on / off toggle is on - "
     "algorithm_enable_flags_3_cal.cruise_control_enable is set - the switches are learned - there is no fault "
     "reaction and no vehicle speed / cruise switch / brake switch fault - the vacuum throttle actuator is not "
     "disabled for cruise - and cruise_resume_speed_valid_flag is set; else CRUISE_OFF"),
    ("0x0051395c", "governor_cruise_dualCalc_dispatch", "cm848_runCoolantOverheatDerateMonitors",
     "A step of cm848_runCoolantOverheatFuelDerate: runs cm848_monitorCoolantOverheatMinimumDerate then "
     "cm848_monitorCoolantOverheatAggressiveDerate. Nothing to do with cruise despite the old name"),
    ("0x00513980", "engine_coolantTemp_delta_calc", "cm848_calculateCoolantOverheatTemperatureError",
     "e2m 8A72 +0 CT_Derate_Temp_Error: coolant_overheat_temperature_error = "
     "engine_overheat_derate_coolant_temperature_setpoint - coolant_temperature_sensor_filtered while "
     "engine_overheat_derate_active_flag is 1 - else 0. A step of cm848_runCoolantOverheatFuelDerate (before the PI "
     "fuel limit)"),
]
original = fr
mapping = []
for a, cur, new, plate in FUNCS:
    m = re.search(rf"^{a},{cur}(,[^\n]*)?$", fr, re.M)
    assert m, (a, cur)
    assert re.fullmatch(r"cm848_[a-z][A-Za-z0-9]*", new) and not re.search(rf"\b{new}\b", original), new
    assert "," not in plate, (a, plate[:60])
    old_plate = (m.group(1) or ",")[1:].strip()
    text = f"{plate} (was {cur}; {R})" + (f" | earlier note: {old_plate}" if old_plate else "")
    fr = fr[:m.start()] + f"{a},{new},{text}" + fr[m.end():]
    mapping.append(f"{a},{new},{cur},function,1")
open(fr_path, "w").write(fr)
with open(map_path, "a") as fh:
    fh.write("\n".join(mapping) + "\n")

# the pilot: CRUISE_CONTROL_STATE returns for the five state getters (no parameters)
dp = os.path.join(OUT, "function_definitions.csv")
d = open(dp).read()
assert d.endswith("\n")
for a, name in [("0x005125f4", "cm848_selectCruiseStateForCoastSwitch"), ("0x00512724", "cm848_selectBaseCruiseState"),
                ("0x0051291c", "cm848_selectCruiseStateForSetSwitch"),
                ("0x00512878", "cm848_selectCruiseStateForResumeSwitch"),
                ("0x00512f18", "cm848_selectDeniedCruiseState")]:
    assert f"{a}," not in d
    d += f"{a},{name},return,,CRUISE_CONTROL_STATE,The cruise state for this pass (r3) - no parameters\n"
open(dp, "w").write(d)
print(f"{len(GLOBALS) + 2} globals, {len(FUNCS)} functions, 5 return types")
