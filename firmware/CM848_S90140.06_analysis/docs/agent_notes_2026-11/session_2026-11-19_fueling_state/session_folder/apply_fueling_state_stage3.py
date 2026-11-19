"""Stage 3 of the FUELING_STATE work (2026-11-19, PR #52): rename the functions and words of the fueling arbitration
that the stage 1 / 2 reading proved, with plate comments / comments that keep the old names.
Every old row is asserted before it is replaced. Usage: apply_fueling_state_stage3.py <CM848 output dir>"""
import os
import sys

OUT = sys.argv[1]
FUNCTIONS = {   # address: (old name, new name, plate comment)
    "0x0004043c": ("cm848_processProtectionRampControl", "cm848_arbitrateGovernedFueling",
                   "Sets governor_fuel_demand_value and its state governor_fuel_demand_mode (the Cummins FSGVFLST governed "
                   "fueling state): the smallest of the user fueling governor_fuel_demand_working (state "
                   "governor_fuel_demand_working_mode), high_speed_governor_fueling_snapshot (12) and "
                   "vehicle_speed_limit_fueling (10), then the low speed governor (11) as a max select at or below its "
                   "speed (low_speed_governor_fueling); starts protectionRampRateControl on the first pass of 9 / 10 and "
                   "latches low_speed_governor_active_flag in 11 (was cm848_processProtectionRampControl)"),
    "0x0001e5a4": ("cm848_processProtectionSelection", "cm848_arbitrateRequestedFueling",
                   "Runs the derate chain (torque_derate_fuel_quantity / torque_derate_fuel_source_code, or the calibrated "
                   "fixed limit 13 while governor_feature_flags bit 0x10 is set), takes the smaller of it and the governed "
                   "fuel into fuel_demand_arbitration_working / requested_fueling_state (Cummins FSLMDSST) and the smaller "
                   "of that and fuel_demand_minimum_tracked into fuel_demand_arbitrated / fuel_demand_arbitrated_state "
                   "(was cm848_processProtectionSelection)"),
    "0x0001e22c": ("cm848_selectFuelDemandSource", "cm848_selectFinalFueling",
                   "Sets the final fueling fuel_demand_computed and final_fueling_state (Cummins FSFNFL / FSFNFLST, e2m "
                   "block 1051): the combustion reference and its source code, overridden by the engine state "
                   "(cold_start_phase: 26 engine stopped, 22 starting, 24 / 25 / 27), 41 immobilizer fuel disable, 23 "
                   "fuel override and 32 limit mode, clamped to timing_limit_upper..fuel_demand_maximum (was "
                   "cm848_selectFuelDemandSource)"),
    "0x0001f03c": ("cm848_processActiveFaultList", "cm848_calculateMaximumFuelCurve",
                   "Returns the maximum fuel at (param_1 engine speed, param_2): two engine speed x param_2 tables blended "
                   "by thermal_fuel_limit_factor (Q14; 0 = the governor_fuel_table grid, 0x4000 = the fuel_demand_rpm "
                   "grid), clamped to timing_limit_upper..5888. Called with param_2 = 400 for "
                   "protection_fuel_limit_cal_active (FUELING_STATE_MAXIMUM_FUEL_CURVE) and active_fault_fuel_correction. "
                   "Nothing in it reads a fault list (was cm848_processActiveFaultList)"),
    "0x0003889c": ("cm848_processSafetyConditionProtection", "cm848_applyFuelPressureGovernorFaultBlend",
                   "While safety_system_enable_cal is set: takes injection_quantity_combustion_chi_maximum as a derate "
                   "limit (code 62, FUELING_STATE_FUEL_PRESSURE_GOVERNOR_FAULT_BLEND) and, while fault 57 / 58 / 60 "
                   "(P1221 / P1222 / P1223, the fuel pressure governor plausibility checks) or 59 is set, blends it toward "
                   "the engine speed table safety_fuel_limit_rpm_output_cal at safety_fuel_blend_increment_cal per pass "
                   "(back at safety_fuel_blend_decrement_cal) (was cm848_processSafetyConditionProtection)"),
    "0x00040f80": ("cm848_processProtectionRampTimer", "cm848_calculateVehicleSpeedLimitFueling",
                   "Sets vehicle_speed_limit_fueling (FUELING_STATE_VEHICLE_SPEED_LIMIT when it wins the arbitration): "
                   "from the error between vehicle_speed_rise_limited and cruise_speed_limit_working through "
                   "cruise_speed_reference_c / _d (5888 = no limit while j1939_governor_feature_cal bit 0x80 is clear, "
                   "fault 29 (P0500 vehicle speed sensor) is set or TSC1 controls the engine); capped at governor_fuel_demand_value + 58 while the "
                   "limit governs (was cm848_processProtectionRampTimer)"),
    "0x00040e4c": ("cm848_processGovernorFuelRate", "cm848_calculateCruiseControlFueling",
                   "Sets cruise_control_fueling: while governor_override_active_prev_flag is 1 from "
                   "the error between cruise_speed_command and vehicle_speed_rise_limited through "
                   "cruise_speed_reference_a / _b, else the operating mode governor fuel "
                   "(operating_mode_governor_output.fuel_demand) (was cm848_processGovernorFuelRate)"),
    "0x000411b0": ("cm848_calculateProtectionLevelLimit", "cm848_selectCruiseOrUserFueling",
                   "Sets the user fueling governor_fuel_demand_working and its state governor_fuel_demand_working_mode: "
                   "cruise_control_fueling with FUELING_STATE_CRUISE_CONTROL while cruise control is engaged - unless the "
                   "accelerator asks for more fuel than cruise (fuel_demand_control.calculated above "
                   "governor_override_fuel_threshold_cal) or TSC1 / mode 5 / 37 / 38 controls - else the operating mode "
                   "governor output and its mode_code (was "
                   "cm848_calculateProtectionLevelLimit)"),
    "0x00040dd4": ("cm848_copyProtectionRampValue", "cm848_snapshotHighSpeedGovernorFueling",
                   "Copies high_speed_governor_fueling into high_speed_governor_fueling_snapshot for the arbitration (was "
                   "cm848_copyProtectionRampValue)"),
    "0x00040de8": ("cm848_calculateGovernorFuelDemandUpperLimit", "cm848_limitLowSpeedGovernorFueling",
                   "Sets low_speed_governor_fueling (fuel quantity counts) to low_speed_governor_fueling_working, or to "
                   "governor_fuel_demand_value + governor_fuel_demand_mode_b_offset_cal while governor_fuel_demand_mode is "
                   "11 (the low speed governor), and caps it at 5888 (the 400 mm3 fuel maximum). "
                   "cm848_arbitrateGovernedFueling compares the user fueling and the TSC1 mode 3 limit with it (was "
                   "cm848_calculateGovernorFuelDemandUpperLimit, cm848_processTorqueLimitBounded)"),
    "0x00027ff8": ("cm848_processSpeedGovernorControl", "cm848_runLowSpeedGovernor",
                   "The low speed governor: while low_speed_governor_active_flag is set it sums its speed-error terms into "
                   "low_speed_governor_fueling_working (clamped between governor_cold_start_fuel_step_cal and "
                   "governor_speed_setpoint_integrated) and, in FUELING_STATE_LOW_SPEED_GOVERNOR, writes it into "
                   "governor_fuel_demand_value; else the working value follows governor_speed_setpoint_integrated (was "
                   "cm848_processSpeedGovernorControl)"),
    "0x000427cc": ("cm848_applySpeedControlProtectionLimit", "cm848_applyTsc1TorqueLimit",
                   "J1939 TSC1 override control mode 3: takes j1939_tsc1_override_state.etc1_mode3_torque_limit as the "
                   "derate limit (FUELING_STATE_TSC1_TORQUE_LIMIT) when it is below torque_derate_fuel_quantity (was "
                   "cm848_applySpeedControlProtectionLimit)"),
    "0x00509510": ("cm848_enforceFuelLimitProtection", "cm848_applyFaultDerateFuelLimit",
                   "Takes fault_derate_fuel_limit as the derate limit (FUELING_STATE_FAULT_DERATE) when it is below "
                   "torque_derate_fuel_quantity (was cm848_enforceFuelLimitProtection)"),
    "0x00040844": ("cm848_calculateFuelRateFromRpm", "cm848_calculateRiseLimitedVehicleSpeed",
                   "Sets vehicle_speed_rise_limited: vehicle_speed, or (fuel_flow_rpm_mode_flag 0) engine speed over the "
                   "drivetrain ratio terms fuel_flow_rpm_numerator / fuel_flow_rpm_divisor, with each rise limited to "
                   "cruise_speed_setpoint_adj_offset_cal per pass; the speed the cruise control and vehicle speed limit "
                   "fueling work on (was cm848_calculateFuelRateFromRpm)"),
    "0x0002bbe8": ("cm848_updateGovernorFromProtection", "cm848_selectPowerTakeOffOrUserFueling",
                   "Sets operating_mode_governor_output: the user fueling (engine_operating_mode_fuel_demand with "
                   "engine_operating_mode) or, while governor_fuel_active_flag is 1 and j1939_governor_feature_cal bit "
                   "0x10 is set, governor_fuel_demand_command with FUELING_STATE_POWER_TAKE_OFF (modes 5 / 6 always; 7 / 8 "
                   "/ 30 unless the user fuel is larger and governor_feature_config_word bit 0x2000 lets the throttle "
                   "override - then power_take_off_throttle_override_flag and its engine speed limit are set). Power "
                   "take-off is e2m-derived (block 1265) (was cm848_updateGovernorFromProtection)"),
    "0x0001f318": ("cm848_initProtectionStateWithFuelDemand", "cm848_initializeFuelLimitChains",
                   "Starts both running minimums at protection_fuel_limit_cal_active (the maximum fuel curve): "
                   "torque_derate_fuel_quantity with state 19 (FUELING_STATE_MAXIMUM_FUEL_CURVE) and "
                   "fuel_demand_minimum_tracked with state 40 (was cm848_initProtectionStateWithFuelDemand)"),
}
GLOBALS = {     # address: (old name, new name, comment)
    "0x0040b674": ("cruise_fuel_demand_setpoint", "vehicle_speed_limit_fueling",
                   "The vehicle speed limit fuel (cm848_calculateVehicleSpeedLimitFueling): 5888 = no limit; the "
                   "arbitration gives it FUELING_STATE_VEHICLE_SPEED_LIMIT when it is the smallest demand (was "
                   "cruise_fuel_demand_setpoint)"),
    "0x0040b676": ("governor_pid_fuel_output", "cruise_control_fueling",
                   "The cruise control fuel (cm848_calculateCruiseControlFueling), capped at governor_fuel_demand_value by "
                   "cm848_selectCruiseOrUserFueling; FUELING_STATE_CRUISE_CONTROL when it is the user fueling (was "
                   "governor_pid_fuel_output)"),
    "0x0040b672": ("governor_fuel_demand_low_threshold", "high_speed_governor_fueling_snapshot",
                   "high_speed_governor_fueling copied at the start of cm848_arbitrateGovernedFueling "
                   "(cm848_snapshotHighSpeedGovernorFueling); FUELING_STATE_HIGH_SPEED_GOVERNOR when it is the smallest "
                   "demand (was governor_fuel_demand_low_threshold)"),
    "0x0040b67a": ("governor_fuel_demand_upper", "low_speed_governor_fueling",
                   "The low speed governor fuel (cm848_limitLowSpeedGovernorFueling, capped at 5888); the arbitration "
                   "selects FUELING_STATE_LOW_SPEED_GOVERNOR when the user fueling is below it at or below the governor "
                   "speed (was governor_fuel_demand_upper)"),
    "0x0040ae94": ("governor_fuel_demand_upper_working", "low_speed_governor_fueling_working",
                   "The low speed governor output of cm848_runLowSpeedGovernor (or governor_speed_setpoint_integrated "
                   "while it is not active; fuel_demand_computed from cm848_updateSpeedProtectionLimits) before "
                   "cm848_limitLowSpeedGovernorFueling (was governor_fuel_demand_upper_working)"),
    "0x0040a156": ("governor_request_active_flag", "low_speed_governor_active_flag",
                   "1 while the low speed governor runs: set in FUELING_STATE_LOW_SPEED_GOVERNOR, cleared once engine "
                   "speed is above governor_speed_demand_working + governor_integrator_offset_cal; while 0 "
                   "cm848_runLowSpeedGovernor resets. e2m block 1045 +4 LSLOFG (when 1 transition from LSG to no adjust "
                   "fuel is prohibited). RAM dump: 1 (was governor_request_active_flag)"),
    "0x0040b6e0": ("cruise_speed_setpoint_adjusted", "vehicle_speed_rise_limited",
                   "The vehicle speed the cruise control and vehicle speed limit fueling work on "
                   "(cm848_calculateRiseLimitedVehicleSpeed): vehicle_speed or the engine-speed-derived speed with each "
                   "rise limited per pass (was cruise_speed_setpoint_adjusted)"),
    "0x003fb52c": ("cruise_speed_setpoint_prev", "vehicle_speed_rise_limited_prev",
                   "vehicle_speed_rise_limited of the last pass (was cruise_speed_setpoint_prev)"),
    "0x0040af56": ("governor_fuel_idle_limit", "power_take_off_throttle_override_engine_speed_limit",
                   "Input 11 of the engine speed limit arbitration (selectEngineSpeedLimit): set in "
                   "cm848_selectPowerTakeOffOrUserFueling while the throttle overrides the power take-off fuel, else "
                   "engine_speed_limit_default_cal (no limit). e2m block 1265 +0 PTTHDQRP (max engine speed while "
                   "throttle fueling overrides PTO fueling) (was governor_fuel_idle_limit)"),
    "0x0040af58": ("governor_idle_transition_flag", "power_take_off_throttle_override_flag",
                   "1 while the throttle fuel overrides the power take-off fuel (cm848_selectPowerTakeOffOrUserFueling). "
                   "e2m block 1265 +2 PTTHOV (was governor_idle_transition_flag)"),
}


def edit(path, fn):
    with open(path, newline="") as f:
        text = f.read()
    eol = "\r\n" if "\r\n" in text else "\n"
    lines = fn(text.split(eol))
    with open(path, "w", newline="") as f:
        f.write(eol.join(lines))


def functions(lines):
    for address, (old, new, comment) in FUNCTIONS.items():
        hits = [i for i, line in enumerate(lines) if line.split(",")[:2] == [address, old]]
        assert len(hits) == 1, (address, old, len(hits))
        lines[hits[0]] = f"{address},{new},{comment}"
    return lines


def globals_(lines):
    for address, (old, new, comment) in GLOBALS.items():
        hits = [i for i, line in enumerate(lines) if line.startswith(f"{address},{old},")]
        assert len(hits) == 1, (address, old, len(hits))
        parts = lines[hits[0]].split(",", 3)
        assert parts[2] == "word" and (len(parts) < 4 or parts[3] == ""), (address, parts)
        lines[hits[0]] = f"{address},{new},word,{comment}"
    return lines


edit(os.path.join(OUT, "function_renames.csv"), functions)
edit(os.path.join(OUT, "global_variables.csv"), globals_)
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "map_stage3.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, (old, new, _) in FUNCTIONS.items():
        f.write(f"{address},{new},{old},function\n")
    for address, (old, new, _) in GLOBALS.items():
        f.write(f"{address},{new},{old},global\n")
print("applied stage 3")
