from helpers import keep, rename

# the apply appends the old comment as "| earlier note: ...", which already carries the 2026-11-20 retype note
RETYPED = ""

ENTRIES = [
    # ---- block 1046 ---------------------------------------------------------------------------------------
    rename(
        "0x003fefea", "governor_integrator_deadband_cal", "low_speed_governor_reference_offset",
        "e2m 1046 +0 LSG_Reference_Offset (RPM, 0.125; 800 = 100 rpm): selectEngineSpeedLimit floors the engine speed limit "
        "at idle_reference_speed + it for sources 9 / 16, and cm848_arbitrateGovernedFueling hands over to the low speed "
        "governor within it above governor_speed_demand_working (the record's no adjust-to-LSG transition); no integrator "
        "or deadband is involved; _cal is wrong outside the EEPROM mirror",
        "selectEngineSpeedLimit: uVar4 = governor_output_t_0040aec2.idle_reference_speed + governor_integrator_deadband_cal;",
        "e2m 1046 +0 LSG_Reference_Offset '[LSRFOF] offset to low idle reference used in no adjust-to-LSG transition' (RPM, "
        "0.125 per count; 800 in the dump = 100 rpm): read-only; an offset added to the low speed governor's low idle "
        "reference. cm848_arbitrateGovernedFueling selects FUELING_STATE_LOW_SPEED_GOVERNOR (no pedal demand, no cruise, "
        "variable speed governor or dual axis fuel table mode) while filtered engine speed is at most "
        "governor_speed_demand_working + this; selectEngineSpeedLimit holds the engine speed limit at least at "
        "governor_output_t_0040aec2.idle_reference_speed + this when the limiting source is 9 (TSC1 torque limit) or 16 "
        "(turbocharger speed limiter)"),
    rename(
        "0x003feff0", "fuel_demand_correction_step_cal", "cruise_road_speed_governor_neutral_fuel_ramp_rate",
        "e2m 1046 +6 Cruise_RSG_Neutral_Fuel_Ramp_Rate (MM3S/SEC; 2944 counts = 200 mm3 per pass): "
        "cm848_arbitrateGovernedFueling lowers fuel_demand_corrected_working by it every pass after a cruise cutout by "
        "clutch (reason 11, transmission_type_cal 0) or park / neutral (12, type 1), else by fuel_demand_corrected_step_cal "
        "(e2m 1189 +22 Cruise_RSG_Min_Fuel_Ramp_Rate); _cal is wrong outside the EEPROM mirror",
        "cm848_arbitrateGovernedFueling: if (fuel_demand_correction_step_cal < fuel_demand_corrected_working) {",
        "e2m 1046 +6 Cruise_RSG_Neutral_Fuel_Ramp_Rate 'cc/rsg min fuel transition ramp rate used if clutch or neutral' "
        "(MM3S/SEC, 3.397 per count; 2944 in the dump = 10000 mm3/s = 200 mm3 per pass): read-only; the per-pass step by "
        "which cm848_arbitrateGovernedFueling lowers fuel_demand_corrected_working (loaded from final_fueling when cruise "
        "control disengages) after cruise control cut out by the clutch (cruise_control_last_cutout_reason 11 with "
        "transmission_type_cal 0) or by park / neutral (12 with type 1); at or below the step the working fuel and "
        "adjusted_user_fueling go to 0. Other cutouts ramp by fuel_demand_corrected_step_cal (e2m 1189 +22 "
        "Cruise_RSG_Min_Fuel_Ramp_Rate)"),
    # ---- block 1064 (low speed governor) ----------------------------------------------------------------------
    rename(
        "0x004070b8", "governor_cold_start_fuel_step_cal", "low_speed_governor_fueling_clamp_minimum",
        "e2m 1064 +2 LSG_Fueling_Clamp_Min (MM3S): cm848_runLowSpeedGovernor limits the sum of its terms between it and "
        "governor_speed_setpoint_integrated (e2m 1065 +A LSG_Fueling_Clamp_Max) into low_speed_governor_fueling_working "
        "(e2m 1065 +0 LSG_Fueling); nothing here is a cold start step; _cal is wrong outside the EEPROM mirror",
        "cm848_runLowSpeedGovernor: (wStack_4e = governor_cold_start_fuel_step_cal,",
        "e2m 1064 +2 LSG_Fueling_Clamp_Min '[LSMNLMFL] LSG FUELING CLAMP MIN' (MM3S, 0.0679 mm3 per count; 0 in the dump): "
        "read-only; the lower clamp of the low speed governor's fueling. cm848_runLowSpeedGovernor sums the proportional, "
        "derivative, integral and jerk terms, the no-load fuel feed forward and the alternator load fuel, and limits the sum "
        "between this word and governor_speed_setpoint_integrated (the upper clamp, e2m 1065 +A LSG_Fueling_Clamp_Max) into "
        "low_speed_governor_fueling_working"),
    rename(
        "0x004070bc", "governor_fuel_correction_lower_cal", "low_speed_governor_integrator_preset_minimum",
        "e2m 1064 +6 LSG_Integrator_Preset_Min (MM3S signed): cm848_updateSpeedProtectionLimits, which presets the LSG "
        "integrator, floors the preset at it while transmission_park_or_neutral_flag is set (in gear it uses +22 "
        "LSG_Integrator_Preset_Min_Drive); _cal is wrong outside the EEPROM mirror",
        "cm848_updateSpeedProtectionLimits: (wVar2 = governor_fuel_correction_lower_cal,",
        "e2m 1064 +6 LSG_Integrator_Preset_Min '[LSMNITPZ] LSG INTEGRATOR PRESET MIN' (MM3S, signed, 0.0679 mm3 per count; "
        "0 in the dump): read-only; the lower limit of the low speed governor integrator preset in park or neutral. "
        "cm848_updateSpeedProtectionLimits (the integrator preset; cm848_runLowSpeedGovernor calls it on the governor's first "
        "pass and again once the governor has not controlled the fuel for the reset delay governor_speed_debounce_limit_cal) "
        "sets governor_fuel_demand_correction_accumulator from the final fueling and keeps it between this word "
        "(transmission_park_or_neutral_flag set) or low_speed_governor_integrator_preset_minimum_in_drive and "
        "governor_speed_reference_computed (e2m 1065 +E LSG_Integrator_Preset_Max)" + RETYPED),
    rename(
        "0x004070c2", "governor_fuel_correction_init_cal", "low_speed_governor_integrator_reset_value",
        "e2m 1064 +C LSG_Integrator_Reset (MM3S signed): cm848_runLowSpeedGovernor loads the LSG integral term "
        "(governor_fuel_demand_correction, e2m 1065 +6 LSG_Integral_Term) and its Q16.16 accumulator with it and zeroes the "
        "proportional / derivative / jerk terms when engine speed is above the idle reference + LSG_Reset_RPM with fueling "
        "below LSG_Reset_Fueling; the old name had init and a wrong _cal",
        "cm848_runLowSpeedGovernor: governor_fuel_demand_correction = governor_fuel_correction_init_cal;",
        "e2m 1064 +C LSG_Integrator_Reset '[LSCNRSFL] LSG integrator reset value used to adjust integrator under defined "
        "RPM/TVO limits' (MM3S, signed, 0.0679 mm3 per count; 0 in the dump): read-only; the value the low speed governor "
        "integrator is reset to. cm848_runLowSpeedGovernor loads governor_fuel_demand_correction (the integral term, e2m "
        "1065 +6 LSG_Integral_Term) and its Q16.16 accumulator with it and zeroes the proportional, derivative and jerk "
        "terms while engine speed is above the idle reference + governor_integrator_offset_cal (e2m +E LSG_Reset_RPM) and "
        "adjusted_user_fueling is below governor_fuel_demand_reset_threshold_cal (e2m +10 LSG_Reset_Fueling)" + RETYPED),
    rename(
        "0x004070ce", "governor_derivative_clamp_cal", "low_speed_governor_jerk_term_limit",
        "e2m 1064 +18 LSG_Jerk_Term_Limit (MM3S signed, 0 in the dump): cm848_runLowSpeedGovernor clamps the jerk term "
        "governor_speed_error_derivative (e2m 1065 +8 LSG_Jerk_Term) to +- it after the deadband (+14 LSG_Jerk_Deadband); the "
        "old name said derivative, but the e2m derivative term is governor_speed_weight_b (clamped by +1E); _cal is wrong "
        "outside the EEPROM mirror",
        "cm848_runLowSpeedGovernor: if (-(int)governor_derivative_clamp_cal <= (int)governor_speed_error_derivative)",
        "e2m 1064 +18 LSG_Jerk_Term_Limit '[LSJKFLLM] Fuel limitation for absolute value of LSG jerk fueling' (MM3S, signed, "
        "0.0679 mm3 per count; 0 in the dump, so the jerk term is always 0): read-only; the limit of the low speed governor "
        "jerk term. cm848_runLowSpeedGovernor takes the filtered jerk signal, removes the deadband "
        "(governor_derivative_deadband_cal, e2m +14 LSG_Jerk_Deadband) and clamps what is left to +- this into "
        "governor_speed_error_derivative (e2m 1065 +8 LSG_Jerk_Term). The derivative term of the e2m is governor_speed_weight_b, "
        "limited by low_speed_governor_derivative_term_maximum" + RETYPED),
    rename(
        "0x004070d4", "governor_integral_clamp_cal", "low_speed_governor_derivative_term_maximum",
        "e2m 1064 +1E LSG_Derivative_Max (MM3S signed): cm848_runLowSpeedGovernor limits the new governor_speed_weight_b to +- "
        "it; weight_b is the speed error rate x D gain x governor_pid_gain_factor_a (e2m 1065 +10 LSG_QD_Adjustment) term, "
        "e2m 1065 +4 LSG_Derivative_Term; the old name said integral, but the integral term (governor_fuel_demand_correction) "
        "is limited by the integrator clamp words; _cal is wrong outside the EEPROM mirror",
        "cm848_runLowSpeedGovernor: wStack_4e = governor_integral_clamp_cal;",
        "e2m 1064 +1E LSG_Derivative_Max 'limitation on LSG derivative term.' (MM3S, signed, 0.0679 mm3 per count; 147 in "
        "the dump = 10.0 mm3): read-only; the symmetric limit of the low speed governor derivative term. "
        "cm848_runLowSpeedGovernor builds governor_speed_weight_b (e2m 1065 +4 LSG_Derivative_Term: the speed error rate x "
        "the derivative gain of the active gain set x governor_pid_gain_factor_a = LSG_QD_Adjustment, plus the previous "
        "term x governor_speed_weight_b_scale_cal = LSG_Derivative_Filter_Coefficient) and limits it to +- this. The "
        "integral term is limited by the integrator clamp min / max words" + RETYPED),
    rename(
        "0x004070d8", "governor_fuel_correction_lower_b_cal", "low_speed_governor_integrator_preset_minimum_in_drive",
        "e2m 1064 +22 LSG_Integrator_Preset_Min_Drive (MM3S signed, 'if in drive'): cm848_updateSpeedProtectionLimits uses it "
        "as the preset floor while transmission_park_or_neutral_flag is 0 (in gear); the park / neutral floor is +6; the "
        "lower_b name and _cal are not meaningful (_cal is wrong outside the EEPROM mirror)",
        "cm848_updateSpeedProtectionLimits: (wVar2 = governor_fuel_correction_lower_b_cal,",
        "e2m 1064 +22 LSG_Integrator_Preset_Min_Drive 'LSG INTEGRATOR PRESET MIN if in drive' (MM3S, signed, 0.0679 mm3 per "
        "count; 74 in the dump = 5.0 mm3): read-only; the lower limit of the low speed governor integrator preset while "
        "the transmission is in gear (transmission_park_or_neutral_flag 0) in cm848_updateSpeedProtectionLimits; in park or "
        "neutral low_speed_governor_integrator_preset_minimum applies" + RETYPED),
    rename(
        "0x004070da", "cold_start_fuel_demand_correction_enable_cal", "low_speed_governor_integrator_preset_use_previous_enable",
        "e2m 1064 +24 LSG_Integrator_Preset_Use_Previous (flag, 'If=1, resets LSG integrator to its previous value'): "
        "cm848_updateSpeedProtectionLimits loads the previous integral term into the accumulator and sets "
        "governor_fuel_demand_correction_active_flag (e2m 1065 +1A LSG_Integrator_Preset_Used_Previous) only while engine_state "
        "is RUNNING and this is set; no cold start is involved; _cal is wrong outside the EEPROM mirror",
        "cm848_updateSpeedProtectionLimits: if (((engine_state == ENGINE_STATE_RUNNING) && "
        "(cold_start_fuel_demand_correction_enable_cal != 0)",
        "e2m 1064 +24 LSG_Integrator_Preset_Use_Previous 'If=1, resets LSG integrator to its previous value' (flag; 1 in the "
        "dump): read-only; enables the learned integrator in the low speed governor preset. With engine_state RUNNING and "
        "this set, cm848_updateSpeedProtectionLimits keeps the previous integral term (governor_fuel_demand_correction) in "
        "the accumulator and sets governor_fuel_demand_correction_active_flag (e2m 1065 +1A "
        "LSG_Integrator_Preset_Used_Previous) when the recent engine acceleration (governor_speed_low_clamp) is below "
        "cold_start_governor_speed_clamp_threshold_cal (e2m +26 LSG_Integrator_Preset_Accel_Limit) or vehicle_speed is at "
        "most governor_fuel_demand_correction_maximum_vehicle_speed (e2m +28 LSG_Integrator_Preset_VSS_Limit); otherwise the "
        "accumulator is preset from the final fueling"),
    # ---- block 107A -----------------------------------------------------------------------------------------
    keep(
        "0x0040a24c", "speed_request_base",
        "e2m 107A +0 ASG_Throttle_Reference_RPM 'All Speed Governor reference speed based upon throttle position'"),
    # ---- block 10EE (low speed governor gain logic) ------------------------------------------------------------
    rename(
        "0x004070aa", "governor_setpoint_table_cal", "low_speed_governor_aggressive_gain_set",
        "e2m 10EE +12 LSG_Aggressive_Proportional_Gain, the first word of the 4-word aggressive gain set (+14 integral, +16 "
        "derivative, +18 jerk): cm848_processGovernorLoadCondition points governor_setpoint_table_requested_ptr at it while "
        "the aggressive gain logic is active and cm848_updateGovernorSetpointParameters reads four words through the pointer "
        "(P, I, D, J gains); TYPE: the row is byte (address-taken, no direct load) but is the base of a record of four signed "
        "2-byte words (e2m S, read as sword), i16[4], like governor_setpoint_table_a = e2m 10EC +0 at 0x4070e6; _cal is wrong "
        "outside the EEPROM mirror",
        "cm848_processGovernorLoadCondition: governor_setpoint_table_requested_ptr = &governor_setpoint_table_cal;",
        "e2m 10EE +12 LSG_Aggressive_Proportional_Gain '[LSAGPPGN] Low speed governor aggressive proportional gain.' (MM3S/RPM, "
        "signed, 1/2048 per count; 164 in the dump = 0.080): read-only; the first word of the low speed governor's "
        "aggressive gain set, four words {proportional +0 = e2m 10EE +12, integral +2 = +14 LSG_Aggressive_Integral_Gain (164), "
        "derivative +4 = +16 (0), jerk +6 = +18 (0)}. cm848_processGovernorLoadCondition requests the set "
        "(governor_setpoint_table_requested_ptr) while the aggressive gain logic is active, and "
        "cm848_updateGovernorSetpointParameters copies its four words into the live gains (e2m 10ED +0 / +2 / +4 and the "
        "jerk gain). The default set is the same layout at 0x4070e6 (e2m 10EC). TYPE: only the first byte is typed; the "
        "record is 4 words"),
    rename(
        "0x004070b2", "governor_cold_start_load_timer_limit", "low_speed_governor_aggressive_gain_minimum_run_time",
        "e2m 10EE +1A LSG_Aggressive_Inhibit_Coolant_Time (SEC, 0.02; 250 = 5.0 s): cm848_processGovernorLoadCondition counts "
        "governor_cold_start_load_timer up to it and allows the aggressive gains (governor_enabled_flag = 0 = "
        "ALLOW_AGGRESSIVE_LOGIC, e2m 10EF +0) only once it is reached with coolant above +1C; the timer counts engine run "
        "passes and the function reads no load anywhere, so 'load' in the old name matches nothing; the generic governor_ "
        "prefix is shared with 0x4070aa, which needs a rename for its wrong _cal, so the block keeps one prefix",
        "cm848_processGovernorLoadCondition: (governor_cold_start_load_timer < governor_cold_start_load_timer_limit)))) {",
        "e2m 10EE +1A LSG_Aggressive_Inhibit_Coolant_Time 'If engine has been running for this long after start, will allow "
        "LSG agg gains' (SEC, 0.02 per count; 250 in the dump = 5.0 s): read-only; how long the engine must have run before "
        "the low speed governor may use its aggressive gain set. cm848_processGovernorLoadCondition counts "
        "governor_cold_start_load_timer (in FUELING_STATE_LOW_SPEED_GOVERNOR, from engine_state RUNNING, 0 when stopped) up "
        "to this limit; with the timer at the limit, the coolant above governor_cold_start_coolant_threshold_cal (e2m +1C "
        "LSG_Aggressive_Inhibit_Coolant_Temp) and the speed error settled it clears governor_enabled_flag (e2m 10EF +0 "
        "LSG_Gain_Logic_Flag: 0 = ALLOW_AGGRESSIVE_LOGIC)"),
]
