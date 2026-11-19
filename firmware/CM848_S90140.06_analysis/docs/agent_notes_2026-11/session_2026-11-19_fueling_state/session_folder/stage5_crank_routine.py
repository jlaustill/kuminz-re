# Merged into apply_fueling_state_stage5.py (exec'd there): the crank routine, from the read-only agent's report.
# Checked in this session before applying:
# - e2m 105E / 105F / 1032 / 10B1 record names and offsets in CHR_CC_11.45.01.07.e2m;
# - the 10B1 anchors (+A fault_derate_fuel_limit = Engine_Protection_Derate_Fueling, +C / +E / +16 / +18 byte / +1E);
# - 1032 6/6 with the overspeed words;
# - the code anchors crank exit speed (ends CRANKING), crank fuel (the CRANKING fuel), reentry speed (REENTRY);
# - the two flags in cm848_updateEngineState and the injection gate of engine_injectionAngle_writeTpuEvent.
# Skipped on purpose:
# - the low / medium rows (0x40a79c 4D timing, 0x40a7a2 wet stack timing, 0x40a7b8 SOI before startup, 0x3fdfdc
#   startup inhibit);
# - the i16 retypes (a label-only stage);
# - the unnamed DAT_0005b1b6..bc words.

def crank(address, old, new, e2m, extra=""):
    GLOBALS[address] = (old, new, None, f"{e2m}{extra} (was {old})")


for a, o, n, e in [
    ("0x0040a798", "cold_start_advance_counter", "crank_exit_timer", "e2m 105E +0 Crank_Exit_Timer"),
    ("0x0040a79a", "cold_start_rpm_adjust_b", "crank_advance", "e2m 105E +2 Crank_Advance (signed - lha)"),
    ("0x0040a79e", "injection_timing_base_limit_working", "crank_adjusted_initial_fuel", "e2m 105E +6 Crank_Adjusted_Initial_Fuel"),
    ("0x0040a7a0", "fuel_timing_rpm_upper_limit", "crank_adjusted_initial_rpm", "e2m 105E +8 Crank_Adjusted_Initial_RPM"),
    ("0x0040a7a4", "fuel_timing_correction_c", "crank_coolant_exit_fuel", "e2m 105E +C Crank_Coolant_Exit_Fuel"),
    ("0x0040a7a6", "fuel_timing_correction_a", "crank_initial_advance", "e2m 105E +E Crank_Initial_Advance (signed - lha)"),
    ("0x0040a7a8", "fuel_timing_correction_b", "crank_exit_fuel_adjustment", "e2m 105E +10 Crank_Exit_Fuel_Adjustment"),
    ("0x0040a7aa", "governor_rpm_setpoint_output", "crank_exit_speed",
     "e2m 105E +12 Crank_Exit_Speed: CRANKING ends at it (cm848_updateEngineState)"),
    ("0x0040a7ac", "governor_cold_start_rpm_output", "crank_fuel",
     "e2m 105E +14 Crank_Fuel: the CRANKING fuel of cm848_selectFinalFueling (FUELING_STATE_CRANKING) - a fuel quantity, not an rpm"),
    ("0x0040a7ae", "fuel_timing_base_limit", "crank_initial_fuel", "e2m 105E +16 Crank_Initial_Fuel"),
    ("0x0040a7b0", "governor_fuel_timing_offset", "crank_initial_fuel_adjustment", "e2m 105E +18 Crank_Initial_Fuel_Adjustment"),
    ("0x0040a7b2", "fuel_timing_advance_cal", "crank_initial_advance_break_speed",
     "e2m 105E +1A Crank_Initial_Advance_Break_Speed (working RAM - no _cal)"),
    ("0x0040a7b4", "fuel_timing_table_output", "crank_initial_fuel_break_speed", "e2m 105E +1C Crank_Initial_Fuel_Break_Speed"),
    ("0x0040a7b6", "cold_start_rpm_adjust_a", "crank_exit_advance", "e2m 105E +1E Crank_Exit_Advance (signed - lha)"),
    ("0x0040a7ba", "torque_fuel_offset_trim", "crank_initial_rpm_adjustment", "e2m 105E +22 Crank_Initial_RPM_Adjustment"),
    ("0x0040a7bc", "crank_event_sample_counter", "crank_jump_start_timer",
     "e2m 105E +24 Crank_Jumpstart_Timer: CRANKING passes toward JUMP_START"),
    ("0x0040a7be", "cold_start_rpm_threshold", "crank_reentry_speed",
     "e2m 105E +26 Crank_Reentry_Speed: RUNNING drops to REENTRY at it (cm848_updateEngineState)"),
]:
    crank(a, o, n, e)

for a, o, n, e in [   # e2m 105F (base 0x406852): ROM-copied calibration outside the EEPROM mirror - the _cal goes
    ("0x00406852", "fuel_timing_correction_c_cal", "crank_exit_fuel_override", "+0 Crank_Exit_Fuel_Override"),
    ("0x00406854", "fuel_timing_correction_b_max_cal", "crank_exit_fuel_ramp_maximum", "+2 Crank_Exit_Fuel_Ramp_Max"),
    ("0x00406856", "cold_start_fuel_timing_correction_addend_cal", "crank_exit_fuel_ramp_rate", "+4 Crank_Exit_Fuel_Ramp_Rate"),
    ("0x00406858", "fuel_timing_correction_load_max_cal", "crank_high_manifold_temperature", "+6 Crank_Hi_Manifold_Temp"),
    ("0x0040685a", "fuel_timing_correction_offset_cal", "crank_low_manifold_temperature", "+8 Crank_Lo_Manifold_Temp"),
    ("0x0040685c", "torque_fuel_timing_offset_cal", "crank_jump_start_rpm_ramp_rate", "+A Crank_Jumpstart_RPM_Ramp_Rate"),
    ("0x0040685e", "cold_start_fuel_timing_rpm_threshold_cal", "crank_exit_fuel_ramp_rpm", "+C Crank_Exit_Fuel_Ramp_RPM"),
    ("0x00406860", "cold_start_rpm_setpoint_cal", "crank_exit_rpm", "+E Crank_Exit_RPM"),
    ("0x00406862", "cold_start_advance_count_cal", "crank_exit_time", "+10 Crank_Exit_Time"),
    ("0x00406864", "cold_start_coolant_temp_threshold_cal", "crank_jump_start_temperature_threshold",
     "+12 Crank_Jumpstart_Temperature_Threshold"),
    ("0x00406866", "fuel_timing_correction_a_high_cal", "crank_high_manifold_temperature_timing", "+14 Crank_Hi_Manifold_Temp_Timing"),
    ("0x00406868", "fuel_timing_correction_a_low_cal", "crank_low_manifold_temperature_timing", "+16 Crank_Lo_Manifold_Temp_Timing"),
    ("0x0040686a", "fuel_timing_advance_high_cal", "crank_high_manifold_temperature_rpm", "+18 Crank_Hi_Manifold_Temp_RPM"),
    ("0x0040686c", "fuel_timing_advance_low_cal", "crank_low_manifold_temperature_rpm", "+1A Crank_Lo_Manifold_Temp_RPM"),
    ("0x0040686e", "cold_start_rpm_base_cal", "crank_initial_reentry_speed", "+1C Crank_Initial_Reentry_Speed"),
    ("0x00406870", "cold_start_rpm_threshold_addend_cal", "crank_exited_reentry_speed_offset", "+1E Crank_Exited_Reentry_Speed_Offset"),
    ("0x00406872", "cold_start_torque_fuel_offset_cal", "crank_exited_initial_rpm_offset", "+20 Crank_Exited_Initial_RPM_Offset"),
    ("0x00406874", "governor_fuel_timing_offset_addend_cal", "crank_jump_start_fueling_ramp_rate",
     "+22 Crank_Jumpstart_Fueling_Ramp_Rate"),
    ("0x00406876", "fuel_timing_base_limit_cal", "crank_initial_fuel_override", "+24 Crank_Initial_Fuel_Override"),
    ("0x00406878", "fuel_timing_table_override_cal", "crank_initial_speed_override", "+26 Crank_Initial_Speed_Override"),
    ("0x0040687a", "cold_start_governor_fuel_timing_offset_cal", "crank_exited_initial_fueling_offset",
     "+28 Crank_Exited_Initial_Fueling_Offset"),
    ("0x0040687c", "cold_start_crank_event_threshold_cal", "crank_jump_start_time",
     "+2A Crank_Jumpstart_Time: the CRANKING passes before JUMP_START"),
]:
    crank(a, o, n, "e2m 105F " + e, " - ROM copy, no _cal")

for a, o, n, e in [   # e2m 1032 (base 0x40687e, 6/6 with the overspeed words)
    ("0x00406884", "engine_rpm_trigger_cal", "engine_stopped_speed",
     "e2m 1032 +6 Engine_Stopped_Speed: engine_state is STOPPED at or below it (ROM copy, no _cal)"),
    ("0x00406886", "governor_speed_engage_count_target_cal", "ecm_power_down_timer_threshold",
     "e2m 1032 +8 ECM_Powerdown_Timer_Threshold: ecm_power_down_timer target in SHUTDOWN (ROM copy, no _cal)"),
    ("0x00406888", "governor_speed_engage_fault_count_threshold_cal", "ecm_power_down_delay",
     "e2m 1032 +A ECM_Powerdown_Delay (ROM copy, no _cal)"),
]:
    crank(a, o, n, e)

for a, o, n, e in [   # EEPROM mirror words (0x3fd482 + EEPROM offset) - _cal
    ("0x003fd872", "cold_start_rpm_active_flag", "crank_exit_speed_switch_cal",
     "EEPROM 0x3f0 - e2m 1254 +38 Crank_Exit_Speed_Switch: picks the crank exit speed source (0 here = the idle reference)"),
    ("0x003fd53e", "cold_start_fuel_mode_ready_flag", "engine_brake_driveline_brake_type_cal",
     "EEPROM 0xbc - e2m 1180 +16 EB_Driveline_Brake_Type: ENGINE_BRAKE is entered only while it is 0 (1 here = retarder)"),
    ("0x003fd5c4", "cold_start_feature_enable_flags", "algorithm_enable_flags_20_cal",
     "EEPROM 0x142 - word 20 of the algorithm enable flags (word 0 at 0x3fd59c like algorithm_enable_flags_12_cal); 0x0100 here"),
]:
    crank(a, o, n, e)

crank("0x003fa840", "cold_start_rpm_threshold_updated_flag", "crank_reentry_speed_offset_applied_flag",
      "1 once crank_reentry_speed has taken crank_exited_reentry_speed_offset (no e2m record)")
for a, o, n, e in [   # the crank tables (e2m single-table blocks 8A44-8A4C)
    ("0x0005b1be", "cold_start_fuel_demand_base_x_axis", "crank_initial_fuel_x_axis", "e2m 8A49"),
    ("0x0005b1d8", "cold_start_fuel_demand_base_y_axis", "crank_initial_fuel_y_axis", "e2m 8A48"),
    ("0x0005b1e4", "cold_start_fuel_demand_base_grid", "crank_initial_fuel_grid", "e2m 8A47"),
    ("0x0005b25c", "cold_start_fuel_demand_at_governor_setpoint_x_axis", "crank_exit_fuel_x_axis", "e2m 8A4C"),
    ("0x0005b276", "cold_start_fuel_demand_at_governor_setpoint_y_axis", "crank_exit_fuel_y_axis", "e2m 8A4B"),
    ("0x0005b282", "cold_start_fuel_demand_at_governor_setpoint_grid", "crank_exit_fuel_grid", "e2m 8A4A"),
    ("0x0005b2fa", "cold_start_fuel_ramp_start_rpm_axis", "crank_initial_speed_axis", "e2m 8A46"),
    ("0x0005b30c", "cold_start_fuel_ramp_start_rpm_values", "crank_initial_speed_values", "e2m 8A45"),
]:
    crank(a, o, n, e + " crank table")

for a, o, n, e in [   # the auxiliary emission control devices (e2m EMO ..._AECD_Active / _Cap_EL)
    ("0x0040a5f4", "cold_start_phase26_fuel_mode_flag", "engine_start_emission_control_active_flag",
     "e2m 19B3 +0 EMO_Engine_Start_AECD_Active (CRANKING / JUMP_START)"),
    ("0x0040a5f6", "fuel_coldStart_phase26_demand_floor", "engine_start_emission_level_cap", "e2m 19B3 +2 EMO_Engine_Start_Cap_EL"),
    ("0x0040a5f8", "cold_start_phase3_fuel_mode_count_met_flag", "extended_idle_emission_control_active_flag",
     "e2m 19B1 +0 EMO_Extended_Idle_AECD_Active"),
    ("0x0040a5fa", "cold_start_phase3_fuel_demand_floor", "extended_idle_emission_level_cap", "e2m 19B1 +2 EMO_Extended_Idle_Cap_EL"),
    ("0x0040a5fc", "cold_start_boost_override_active_flag", "extreme_ambient_emission_control_active_flag",
     "e2m 19A4 +0 EMO_Extreme_Amb_AECD_Active"),
    ("0x0040a5fe", "cold_start_boost_override_fuel_demand", "extreme_ambient_emission_level_cap", "e2m 19A4 +2 EMO_Extreme_Amb_Cap_EL"),
    ("0x003fbc9c", "cold_start_phase3_fuel_mode_count", "extended_idle_timer", "the extended idle time count (no e2m record)"),
    ("0x00406570", "cold_start_phase3_fuel_mode_count_max", "extended_idle_time_threshold",
     "e2m 19B0 +2 C_EMO_Extended_Idle_Timer (ROM copy, no _cal)"),
]:
    crank(a, o, n, e)

GLOBALS["0x0040a784"] = ("engine_starting", "engine_shutdown_command_flag", None,
    "e2m 10B1 +12 Shutdown (the engine protection block; base 0x40a772 - +A Engine_Protection_Derate_Fueling = "
    "fault_derate_fuel_limit): set by the fault derate monitor and a J1939 diagnostic service "
    "(cm848_commandEngineShutdown); takes engine_state to SHUTDOWN and zeroes the injection quantity and the rail pressure "
    "setpoint; cleared at engine speed 0 in SHUTDOWN. Reads backwards under its old name (was engine_starting)")
GLOBALS["0x0040aa98"] = ("engine_shutdown_active_flag", "key_off_shutdown_inhibit_flag", None,
    "1 stops a key-off from shutting the engine down (cm848_updateEngineState / the injection gate); set only by J1939 "
    "diagnostic service 24 (cm848_inhibitKeyOffShutdown), cleared at the next key-on edge. Reads backwards under its old "
    "name (was engine_shutdown_active_flag)")
FUNCTIONS["0x000216e8"] = ("cm848_setEngineStarting", "cm848_commandEngineShutdown",
    "J1939 PGN 61184 diagnostic service handler: sets engine_shutdown_command_flag (was cm848_setEngineStarting) | "
    "jlaustill reviewed 2026-5-25 - annoyed that = 1 rejects bool = TRUE, but otherwise hoping accurate")
FUNCTIONS["0x00021904"] = ("cm848_setColdStartMode2Flag", "cm848_inhibitKeyOffShutdown",
    "handles J1939 PGN 61184 diagnostic service id 24 via the 0x3fa8b2 table (cm848_j1939DiagnosticServiceHandler) - "
    "sets key_off_shutdown_inhibit_flag: until the next key-on edge a key-off does not shut the engine down - registered "
    "by cm848_registerJ1939DiagnosticHandlers (was cm848_setColdStartMode2Flag)")
TEXT_REPLACEMENTS += [
    ("enums.csv", "while engine_state is CSP_ABOVE_RPM_TRIGGER / CSP_ABOVE_RPM_VIA_EVENTS / CSP_SETPOINT_UNDERRUN",
     "while engine_state is ENGINE_STATE_CRANKING / ENGINE_STATE_JUMP_START / ENGINE_STATE_REENTRY"),
    ("function_renames.csv", "while engine_state is CSP_ABOVE_RPM_TRIGGER / CSP_ABOVE_RPM_VIA_EVENTS / CSP_SETPOINT_UNDERRUN",
     "while engine_state is ENGINE_STATE_CRANKING / ENGINE_STATE_JUMP_START / ENGINE_STATE_REENTRY"),
    ("function_renames.csv", "at key on (CSP_CRANKING)", "at key on (ENGINE_STATE_STOPPED)"),
    ("function_renames.csv", "(only while engine_state is CSP_CRANKING)", "(only while engine_state is ENGINE_STATE_STOPPED)"),
    ("function_renames.csv", "quantity forced to 0 during shutdown / protection unless the engine is starting",
     "quantity forced to 0 while the ignition key switch is off (unless key_off_shutdown_inhibit_flag is set) or "
     "engine_shutdown_command_flag is set"),
]
