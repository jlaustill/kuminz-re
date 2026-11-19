"""Stage 6b (PR #52): the emission manager (EMO / EMM) family and the power take-off helpers, from the two stage-6
agents' reports. Every e2m identity was re-resolved with firmware/scripts/e2m_block_addresses.py (the ECU's own
parameter ID table in flash2), which reproduces every earlier block base; the code roles were spot-checked.
Writes map_stage6b.csv.
usage: apply_stage6b.py <CM848 output dir>"""
import os
import sys

OUT = sys.argv[1]
here = os.path.dirname(os.path.abspath(__file__))
T = " (address from the ECU's parameter ID table)"
ROM = " - ROM copy, no _cal"
NEW = " (new row 2026-11-19)"
PROTECTION = "air_handling_system_protection"

RENAMES = [  # (address, old, new, new comment or None = keep and add "(was old)"; prefix "+" = prepend to the old)
    # --- the emission manager core
    ("0x0040a5b4", "fuel_demand_min_threshold", "emission_level_cap_command",
     "e2m 198E +0 EMM_Cap_EL_Cmd 'Emission level cap after AECDs'" + T + " (1/1024; 1024 = 1.0 in the dump): the "
     "rate-limited maximum of the AECD caps and emission_level_cap_reference (cm848_calculateEmissionLevelCapCommand), or "
     "emission_level_cap_override_value while emission_level_cap_user_override_enable_cal is set. A lower bound on the "
     "combustion chi: cm848_lookupProtectiveChi raises each protective chi's level to at least twice this (1/1024 to "
     "1/2048) - not an air handling or EGR limit (was fuel_demand_min_threshold)"),
    ("0x003fba2a", "fuel_demand_min_rate_limited", "emission_level_cap_rate_limited",
     "The slew-limited emission level cap before the user override (cm848_calculateEmissionLevelCapCommand) "
     "(was fuel_demand_min_rate_limited)"),
    ("0x003fba2c", "fuel_demand_min_rate_limiter_prev", "emission_level_cap_rate_limited_previous",
     "The rate limiter's previous output; cleared by cm848_initializeEmissionLevelCapRateLimiter "
     "(was fuel_demand_min_rate_limiter_prev)"),
    ("0x00406548", "fuel_demand_min_rate_limit_decrease", "emission_level_cap_rate_limit_decrease",
     "e2m 198B +0 C_EMO_Cap_EL_Down_Rate 'Down rate for EMO Cap EL variable rate limiter'" + T + " (1/1024 per pass; "
     "15 here)" + ROM + " (was fuel_demand_min_rate_limit_decrease)"),
    ("0x0040654a", "fuel_demand_min_rate_limit_increase", "emission_level_cap_rate_limit_increase",
     "e2m 198B +2 C_EMO_Cap_EL_Up_Rate (1/1024 per pass; 15 here)" + ROM + " (was fuel_demand_min_rate_limit_increase)"),
    ("0x0040a5ee", "combustion_status_flags", "emission_manager_engine_protection_state",
     "+e2m 19B5 +2 EMM_Protection_State 'EMM protection state'" + T + ", written by "
     "cm848_calculateEmissionManagerEngineProtectionState. "),
    ("0x0040a72e", "fuel_demand_blend_weight", "emission_level_cap_reference",
     "e2m 198D +0 EMR_Cap_EL_Ref 'Scheduled emission level cap before AECD's and overrides'" + T + " (1/1024; 1024 in "
     "the dump): the altitude x ambient temperature cap table times the engine speed x net torque ratio table >> 10 "
     "(cm848_calculateEmissionLevelCapReference); an input of the max-select in cm848_calculateEmissionLevelCapCommand "
     "(was fuel_demand_blend_weight)"),
    ("0x0040a730", "fuel_demand_blend_rpm_in_range_flag", "not_to_exceed_zone_flag",
     "e2m 198D +2 EMR_NTE_Flag 'Emission tracker NTE flag'" + T + ": 1 while net_combustion_torque_copy is between the "
     "not-to-exceed zone's lower and upper torque for the engine speed (cm848_checkNotToExceedZone); the 150-sample "
     "averages restart while it is 0. Both torque bands are 0 in this calibration (was fuel_demand_blend_rpm_in_range_flag)"),
    ("0x0040afc0", "fuel_demand_aux_blend_deviation", "net_combustion_torque_copy",
     "A copy of net_combustion_torque made by cm848_applyProtectionRpmCorrectionFilter; the torque axis of the emission "
     "level cap ratio table and of the not-to-exceed zone check (was fuel_demand_aux_blend_deviation)"),
    # --- air handling system protection (e2m 1997)
    ("0x0040a596", "fuel_blendMode_condition_a_flag", f"{PROTECTION}_level_1_condition_flag",
     "e2m 1997 +0 EMO_Air_AECD_Level_1" + T + ": the level 1 altitude and ambient temperature condition "
     "(cm848_checkAirHandlingSystemProtectionLevelConditions) (was fuel_blendMode_condition_a_flag)"),
    ("0x0040a598", "fuel_blendMode_condition_b_flag", f"{PROTECTION}_level_2_condition_flag",
     "e2m 1997 +2 EMO_Air_AECD_Level_2: the level 2 condition (was fuel_blendMode_condition_b_flag)"),
    ("0x0040a59a", "fuel_blendMode_condition_b_combined_flag", f"{PROTECTION}_level_2_allowed_flag",
     "e2m 1997 +4 EMO_Air_AECD_Level_2_Allowed (was fuel_blendMode_condition_b_combined_flag)"),
    ("0x0040a59c", "fuel_blendMode_no_condition_active_flag", f"{PROTECTION}_level_3_condition_flag",
     "e2m 1997 +6 EMO_Air_AECD_Level_3 (was fuel_blendMode_no_condition_active_flag)"),
    ("0x0040a59e", "fuel_blendMode_no_condition_combined_flag", f"{PROTECTION}_level_3_allowed_flag",
     "e2m 1997 +8 EMO_Air_AECD_Level_3_Allowed (was fuel_blendMode_no_condition_combined_flag)"),
    ("0x0040a5a0", "fuel_blendMode_active_flag", f"{PROTECTION}_active_flag",
     "e2m 1997 +A EMO_Air_Handling_AECD_Active; enabled by algorithm_enable_flags_20_cal bit 0x100, which is set: the "
     "only AECD enabled on this truck (was fuel_blendMode_active_flag)"),
    ("0x0040a5a2", "fuel_blend_weight_threshold_active", f"{PROTECTION}_emission_level_cap",
     "e2m 1997 +C EMO_Air_Handling_Cap_EL (1/1024): the level 3 cap when level 3 is allowed, else the level 2 cap when "
     "level 2 is allowed, else 0 (cm848_updateAirHandlingSystemProtection); an input of the max-select "
     "(was fuel_blend_weight_threshold_active)"),
    ("0x0040a5a4", "governor_adjustment_flow_rate_threshold", f"{PROTECTION}_compressor_outlet_temperature_limit",
     f"e2m 1997 +E EMO_Air_Handling_COT_Limit (degF): from {PROTECTION}_compressor_outlet_temperature_limit_values over "
     "altitude (was governor_adjustment_flow_rate_threshold)"),
    ("0x0040a5a6", "governor_adjustment_any_compare_flag", f"{PROTECTION}_near_limit_flag",
     "e2m 1997 +10 EMO_Air_Handling_Near_Limit: the OR of the three near-limit flags "
     "(was governor_adjustment_any_compare_flag)"),
    ("0x0040a5a8", "governor_adjustment_fuel_qty_threshold", f"{PROTECTION}_turbocharger_speed_limit",
     f"e2m 1997 +12 EMO_Air_Handling_Speed_Limit (krpm): from {PROTECTION}_turbocharger_speed_limit_values "
     "(was governor_adjustment_fuel_qty_threshold)"),
    ("0x0040a5aa", "governor_adjustment_boost_threshold", f"{PROTECTION}_exhaust_temperature_limit",
     f"e2m 1997 +14 EMO_Air_Handling_Texh_Limit (degF): from {PROTECTION}_exhaust_temperature_limit_values "
     "(was governor_adjustment_boost_threshold)"),
    ("0x0040a5ac", "etc1_speed_below_threshold_flag", f"{PROTECTION}_high_load_flag",
     f"e2m 1997 +16 EMO_High_Load (cm848_checkAirHandlingSystemProtectionHighLoad: a torque input against "
     f"{PROTECTION}_high_load_torque_values over engine speed); the old 'etc1' was unrelated "
     "(was etc1_speed_below_threshold_flag)"),
    # --- air handling system protection settings (e2m 1990) and tables
    ("0x00406462", "fuel_blend_weight_threshold_cal", f"{PROTECTION}_level_3_emission_level_cap_when_active",
     "e2m 1990 +2 C_EMO_Air_AECD_Level_3_Cap_EL" + T + " (1/1024; 2048 = 2.0 here); also read by "
     "cm848_applyOffNominalTimingAdjustment, which compares a chi with it (EL and chi share the scale)" + ROM +
     " (was fuel_blend_weight_threshold_cal)"),
    ("0x00406464", "fuel_blendMode_condition_a_slope", f"{PROTECTION}_level_1_ambient_temperature_limit_slope",
     "e2m 1990 +4 C_EMO_Altitude_Multiplier_1 (degF per ft): the level 1 ambient temperature limit is altitude x this "
     "/ 16 + the offset (-2 here)" + ROM + " (was fuel_blendMode_condition_a_slope)"),
    ("0x00406466", "fuel_blendMode_condition_b_slope", f"{PROTECTION}_level_2_ambient_temperature_limit_slope",
     "e2m 1990 +6 C_EMO_Altitude_Multiplier_2 (-2 here)" + ROM + " (was fuel_blendMode_condition_b_slope)"),
    ("0x004062d8", "fuel_demand_floor_altitude_ambient_air_factor_x_axis", "emission_level_cap_altitude_ambient_temperature_x_axis",
     "Lookup table - x axis - e2m 18AD C_EMR_Cap_EL_Altitude_Axis (ft; -300 to 12000 here)" + T +
     " (was fuel_demand_floor_altitude_ambient_air_factor_x_axis)"),
    ("0x004062ea", "fuel_demand_floor_altitude_ambient_air_factor_y_axis", "emission_level_cap_altitude_ambient_temperature_y_axis",
     "Lookup table - y axis - e2m 18AE C_EMR_Cap_EL_Tmptr_Axis (degF; -50 to 125 here)"
     " (was fuel_demand_floor_altitude_ambient_air_factor_y_axis)"),
    ("0x004062fc", "fuel_demand_floor_altitude_ambient_air_factor_grid", "emission_level_cap_altitude_ambient_temperature_grid",
     "Lookup table - 2-D grid - e2m 18AF C_EMR_Cap_EL_Table (1/1024; all 1024 here)"
     " (was fuel_demand_floor_altitude_ambient_air_factor_grid)"),
    ("0x0040637c", "", "emission_level_cap_speed_torque_ratio_x_axis",
     "Lookup table - x axis - e2m 18B0 C_EMR_Cap_EL_Speed_Axis (rpm; 0 to 3500 here)"),
    ("0x0040638e", "", "emission_level_cap_speed_torque_ratio_y_axis",
     "Lookup table - y axis - e2m 18B1 C_EMR_Cap_EL_Torque_Axis (ft-lb; -200 to 500 here)"),
    ("0x004063a0", "", "emission_level_cap_speed_torque_ratio_grid",
     "Lookup table - 2-D grid - e2m 18B2 C_EMR_Cap_EL_Ratio_Table (1/1024; all 1024 here)"),
    ("0x00406420", "fuel_demand_auxiliary_blend_deviation_maximum_by_rpm_axis", "not_to_exceed_zone_upper_torque_axis",
     "Lookup table - x axis - e2m 18B3 C_EMR_NTE_Upper_Speed_Axis (rpm)" +
     " (was fuel_demand_auxiliary_blend_deviation_maximum_by_rpm_axis)"),
    ("0x00406430", "fuel_demand_auxiliary_blend_deviation_maximum_by_rpm_values", "not_to_exceed_zone_upper_torque_values",
     "Lookup table - data - e2m 18B4 C_EMR_NTE_Upper_Torque_Table (ft-lb; all 0 here)" +
     " (was fuel_demand_auxiliary_blend_deviation_maximum_by_rpm_values)"),
    ("0x00406440", "fuel_demand_auxiliary_blend_deviation_minimum_by_rpm_axis", "not_to_exceed_zone_lower_torque_axis",
     "Lookup table - x axis - e2m 18B5 C_EMR_NTE_Lower_Speed_Axis (rpm)" +
     " (was fuel_demand_auxiliary_blend_deviation_minimum_by_rpm_axis)"),
    ("0x00406450", "fuel_demand_auxiliary_blend_deviation_minimum_by_rpm_values", "not_to_exceed_zone_lower_torque_values",
     "Lookup table - data - e2m 18B6 C_EMR_NTE_Lower_Torque_Table (ft-lb; all 0 here)" +
     " (was fuel_demand_auxiliary_blend_deviation_minimum_by_rpm_values)"),
    ("0x00406470", "", f"{PROTECTION}_high_load_torque_axis",
     "Lookup table - x axis - e2m 1991 C_EMO_High_Load_Speed_Axis (rpm)"),
    ("0x00406498", "", f"{PROTECTION}_high_load_torque_values",
     "Lookup table - data - e2m 1992 C_EMO_High_Load_Torque_Table (ft-lb)"),
    ("0x004064c0", "governor_adjustment_threshold_input_axis", f"{PROTECTION}_limit_altitude_axis",
     "Lookup table - x axis shared by the three air handling limit tables - e2m 1993 C_EMO_Altitude_Axis (ft)" +
     " (was governor_adjustment_threshold_input_axis)"),
    ("0x004064e2", "governor_adjustment_flow_rate_threshold_values", f"{PROTECTION}_compressor_outlet_temperature_limit_values",
     "Lookup table - data - e2m 1994 C_EMO_Comp_Tmptr_Limit_Table (degF)" +
     " (was governor_adjustment_flow_rate_threshold_values)"),
    ("0x00406504", "governor_adjustment_boost_threshold_values", f"{PROTECTION}_exhaust_temperature_limit_values",
     "Lookup table - data - e2m 1995 C_EMO_Exhaust_Tmptr_Limit_Table (degF)" +
     " (was governor_adjustment_boost_threshold_values)"),
    ("0x00406526", "governor_adjustment_fuel_quantity_threshold_values", f"{PROTECTION}_turbocharger_speed_limit_values",
     "Lookup table - data - e2m 1996 C_EMO_Turbo_Speed_Limit_Table (krpm)" +
     " (was governor_adjustment_fuel_quantity_threshold_values)"),
    # --- white smoke and misfire protection (e2m 19A8 / 19A9), general engine protection (1A41 / 1A42)
    ("0x0040a600", "injection_timing_temperature_component_check_flags", "white_smoke_and_misfire_protection_state",
     "e2m 19A9 +0 EMO_White_Smoke_AECD_State" + T + " (cm848_updateWhiteSmokeAndMisfireProtection): with "
     "algorithm_enable_flags_20_cal bit 0x400 (clear on this truck) bit 0x20 while "
     "injection_timing_combustion_reference_at_base_chi is below injection_timing_main_intake_temperature_component, and "
     "bit 0x40 while it is below injection_timing_main_coolant_component with the coolant temperature at or below "
     "white_smoke_and_misfire_protection_coolant_temperature_limit; else 0. Feeds bits 0x20 / 0x40 of "
     "emission_manager_engine_protection_state (was injection_timing_temperature_component_check_flags)"),
    ("0x0040a602", "fuel_timing_cylinder_check_demand_floor", "white_smoke_and_misfire_protection_emission_level_cap",
     "e2m 19A9 +2 EMO_White_Smoke_Cap_EL (1/1024): white_smoke_and_misfire_protection_emission_level_cap_when_active "
     "while the state is not 0, else 0; an input of the max-select (was fuel_timing_cylinder_check_demand_floor)"),
    ("0x0040a8a9", "fuel_demand_sensor_validation_flags", "general_engine_protection_state",
     "e2m 1A42 +0 EMO_Gen_Protect_AECD_State" + T + " (cm848_updateGeneralEngineProtection): bit 0x100 "
     "egr_system_failure_flag, 0x08 DAT_0040a43c, 0x04 DAT_0040a43e (0x10 / 0x200 have no writer), only while "
     "governor_feature_config_flags bit 0x40 is set (clear on this truck); an input of "
     "emission_manager_engine_protection_state (was fuel_demand_sensor_validation_flags)"),
    ("0x0040a8ab", "fuel_demand_sensor_validation_floor", "general_engine_protection_emission_level_cap",
     "e2m 1A42 +2 EMO_Gen_Protect_Cap_EL: general_engine_protection_emission_level_cap_when_active while the state is "
     "not 0, else 0; an input of the max-select (was fuel_demand_sensor_validation_floor)"),
    # --- power take-off governor working words (the PTO agent's report)
    ("0x003fafac", "protection_monitored_rpm_snapshot", "power_take_off_governor_smoothed_reference_engine_speed_previous",
     "The smoothed reference at the last multiplier update: cm848_calculatePowerTakeOffGovernorSpeedError recomputes "
     "power_take_off_gain_adjustment_multiplier only when power_take_off_governor_smoothed_reference_engine_speed "
     "differs from it (was protection_monitored_rpm_snapshot)"),
    ("0x003fafae", "governor_speed_gain_factor", "power_take_off_gain_adjustment_multiplier",
     "Q14 multiplier of the power take-off speed error (0x4000 = 1.0): calculated from "
     "power_take_off_gain_adjustment_offset_cal / _slope_cal and clamped to 0x20c-0x7ccc (0.032-1.95, the e2m PTGNTB "
     "limits), or looked up in power_take_off_gain_adjustment_axis / _values when power_take_off_gain_adjustment_mode "
     "is not 0; also scales the droop in the PID (was governor_speed_gain_factor)"),
    ("0x003fafb0", "governor_integrator_prev_snapshot", "power_take_off_governor_filtered_speed_error_previous",
     "power_take_off_governor_filtered_speed_error of the previous pass (lha): the derivative term is (error - this) x "
     "the derivative gain x QD (was governor_integrator_prev_snapshot)"),
    ("0x003fafba", "governor_pid_derivative_snapshot", "power_take_off_governor_proportional_derivative_fueling_previous",
     "power_take_off_governor_proportional_derivative_fueling of the previous pass (copied by "
     "cm848_runPowerTakeOffGovernor); used only while the power take-off governor does not have the fueling, to track "
     "fuel_demand_computed (was governor_pid_derivative_snapshot)"),
    ("0x003fafbe", "governor_speed_product", "power_take_off_governor_integral_fueling_working",
     "The PID integrator: tracking start, += (P + D - droop) x (0x8000 - K) / 0x8000 x QI / 0x80, clamped, then "
     "published to power_take_off_governor_integral_fueling (was governor_speed_product)"),
    ("0x003fafc2", "governor_fuel_active_prev_flag", "power_take_off_governor_active_previous_flag",
     "power_take_off_governor_active_flag of the previous pass: the first active pass runs "
     "cm848_presetPowerTakeOffGovernorOnEngagement (was governor_fuel_active_prev_flag)"),
    ("0x003fafc4", "governor_pid_interp_state_d", "power_take_off_gain_adjustment_cached_axis_offset",
     "The cached axis offset of the two power_take_off_gain_adjustment_axis / _values lookups; initialized to 2 "
     "(was governor_pid_interp_state_d)"),
    ("0x003fafc6", "governor_pid_interp_state_a", "power_take_off_unused_cached_axis_offset_1",
     "Initialized to 2 with the lookup cache but never read (was governor_pid_interp_state_a)"),
    ("0x003fafc8", "governor_pid_interp_state_b", "power_take_off_unused_cached_axis_offset_2",
     "Initialized to 2 but never read (was governor_pid_interp_state_b)"),
    ("0x003fafca", "governor_pid_interp_state_c", "power_take_off_unused_cached_axis_offset_3",
     "Initialized to 2 but never read (was governor_pid_interp_state_c)"),
    ("0x003fafcc", "protection_smoothing_filter_state", "power_take_off_reference_filter_state",
     "exponentialMovingAverage record: coefficient power_take_off_reference_filter_coefficient (0.95); smooths "
     "power_take_off_requested_engine_speed into power_take_off_governor_smoothed_reference_engine_speed "
     "(was protection_smoothing_filter_state, before that protection_smoothing_state_ptr)"),
    ("0x003fafd4", "protection_control_state_flags", "power_take_off_governor_switch_state_bits",
     "Ten switch channels, bit 2n this pass and bit 2n+1 the last pass: 0x1 cruise resume = accelerate, 0x4 coast, "
     "0x10 the cruise on / off toggle (switch 3 when hardwired) = cab power take-off on, 0x40 switch 31 (hardwired "
     "mode), 0x100 cruise set, 0x400 switch 31 (set + resume), 0x1000 switch 19 = the remote switch, 0x4000 switch 15 "
     "clutch, 0x10000 switch 11 brake, 0x40000 cruise cancel (was protection_control_state_flags)"),
    ("0x003fafd8", "governor_rpm_transition_flag", "power_take_off_engagement_ramp_complete_flag",
     "1 once the engagement slew ramp reached power_take_off_target_engine_speed; the reference then follows the target "
     "directly. Cleared while inactive and in WAIT (was governor_rpm_transition_flag)"),
    ("0x003fafda", "governor_rpm_reference_ramped", "power_take_off_engagement_ramp_engine_speed",
     "The running value of the engagement ramp (cm848_rampPowerTakeOffReferenceEngineSpeed), copied to "
     "power_take_off_requested_engine_speed each pass (was governor_rpm_reference_ramped)"),
    ("0x003fafdc", "governor_rpm_reference_target", "power_take_off_target_engine_speed",
     "The state machine's target: a remote speed, resume, set, set + resume, the current engine speed (+ droop), or +- "
     "power_take_off_ramp_rate_cal on accelerate / coast, clamped to power_take_off_minimum_reference_engine_speed_cal "
     "..power_take_off_maximum_reference_engine_speed_cal (was governor_rpm_reference_target)"),
    ("0x003fafde", "governor_rpm_integrator_high", "power_take_off_saved_cab_target_engine_speed",
     "The cab target saved when the remote switch takes over (NORMAL to REMOTE_COUNT); restored on the REMOTE_COUNT "
     "timeout, or WAIT when it is 0 (was governor_rpm_integrator_high)"),
    ("0x003fafe0", "protection_eval_step_index", "power_take_off_remote_switch_press_count",
     "REMOTE_COUNT: +1 on each rising edge of the remote switch, up to power_take_off_remote_count_limit_cal; indexes "
     "power_take_off_remote_speed_by_press_count (was protection_eval_step_index)"),
    ("0x003fafe2", "protection_eval_frame_counter", "power_take_off_remote_switch_pressed_pass_count",
     "REMOTE_COUNT: passes with the remote switch pressed (0 when released), against power_take_off_remote_switch_timeout "
     "(was protection_eval_frame_counter)"),
    ("0x003fafe4", "protection_eval_sub_counter", "power_take_off_remote_switch_released_pass_count",
     "REMOTE_COUNT: passes with the remote switch released (0 when pressed) (was protection_eval_sub_counter)"),
    ("0x004071ac", "protection_rpm_axis_cal", "power_take_off_gain_adjustment_axis",
     "Lookup table - x axis (0-4500 rpm in 500 rpm steps) - e2m 13B2 PTO_Gain_Speed_Axis" + T + "; read with "
     "power_take_off_governor_smoothed_reference_engine_speed when power_take_off_gain_adjustment_mode is not 0 (0 here)"
     + ROM + " (was protection_rpm_axis_cal)"),
    ("0x004071c2", "protection_rpm_values_cal", "power_take_off_gain_adjustment_values",
     "Lookup table - data (Q14 multipliers 0.10-0.60) - e2m 13B3 PTO_Gain_Adjust_Table 'Gain adjustment in function of "
     "RPM'" + ROM + " (was protection_rpm_values_cal)"),
    # --- e2m 0008 (EEPROM adjustable parameters, base EEPROM 0x872 = 0x3fdcf4)
    ("0x003fdcfe", "governor_rpm_reference_working", "power_take_off_remote_speed_1_cal",
     "EEPROM 0x87c - e2m 0008 +A PTO_Remote_Speed" + T + " (rpm x 8; 11200 = 1400 rpm here) "
     "(was governor_rpm_reference_working)"),
    ("0x003fdd00", "governor_rpm_reference_snapshot", "power_take_off_maximum_reference_engine_speed_cal",
     "EEPROM 0x87e - e2m 0008 +C PTO_Maximum_Reference_Speed (12000 = 1500 rpm here): the target's upper clamp "
     "(was governor_rpm_reference_snapshot)"),
    ("0x003fdd04", "governor_speed_ratio_working", "power_take_off_droop_slope_cal",
     "EEPROM 0x882 - e2m 0008 +10 PTO_Droop_Slope (0 here) (was governor_speed_ratio_working)"),
    ("0x003fdd06", "governor_speed_error_gain_factor", "power_take_off_gain_adjustment_offset_cal",
     "EEPROM 0x884 - e2m 0008 +12 PTO_Gain_Adjust_Offset (328 = 0.02 here) (was governor_speed_error_gain_factor)"),
    ("0x003fdd08", "protection_rpm_gain_factor_cal", "power_take_off_gain_adjustment_slope_cal",
     "EEPROM 0x886 - e2m 0008 +14 PTO_Gain_Adjust_Slope (0 here) (was protection_rpm_gain_factor_cal)"),
    ("0x003fdd50", "protection_rpm_reference_a", "power_take_off_resume_speed_cal",
     "EEPROM 0x8ce - e2m 0008 +5C PTO_Resume_Speed (8800 = 1100 rpm here) (was protection_rpm_reference_a)"),
    ("0x003fdd54", "protection_rpm_reference_b", "power_take_off_set_speed_cal",
     "EEPROM 0x8d2 - e2m 0008 +60 PTO_Set_Speed (8800 = 1100 rpm here) (was protection_rpm_reference_b)"),
    # --- J1939 priorities (e2m 1254) and the PGN 65264 transmit buffer
    ("0x003fd864", "j1939_pgn65270_source_address_bits", "j1939_pgn65270_priority_cal",
     "EEPROM 0x3e2 - e2m 1254 +2A Jcomm_Inlet_Exhaust_Cond_Message_Priority" + T + ": (value & 7) << 2 is the CAN id's "
     "top byte (was j1939_pgn65270_source_address_bits)"),
    ("0x003fd866", "j1939_pgn65264_source_address_bits", "j1939_pgn65264_priority_cal",
     "EEPROM 0x3e4 - e2m 1254 +2C Jcomm_PTO_Info_Message_Default_Priority: (value & 7) << 2 is the CAN id's top byte "
     "(6 here: 0x18FEF000) (was j1939_pgn65264_source_address_bits)"),
    ("0x003fd868", "j1939_pgn65249_source_address_bits", "j1939_pgn65249_priority_cal",
     "EEPROM 0x3e6 - e2m 1254 +2E Jcomm_Retarder_Config_Message_Default_Priority: (value & 7) << 2 is the CAN id's top "
     "byte (was j1939_pgn65249_source_address_bits)"),
    ("0x003faff4", "j1939_working_tx_message", "j1939_pgn65264_tx_message", None),
    ("0x003fb003", "j1939_msg_payload_init_word", "j1939_pgn65264_payload_bytes_2_to_3", None),
    ("0x003fb005", "j1939_protection_rpm_tx_word", "j1939_pgn65264_requested_engine_speed_tx_word",
     "PGN 65264 bytes 4-5: power_take_off_requested_engine_speed, byte-swapped, when j1939_governor_feature_cal bit 0x10 "
     "is set, else 0xFFFF (was j1939_protection_rpm_tx_word)"),
    ("0x003fb007", "j1939_protection_data_byte_a", "j1939_pgn65264_payload_byte_6",
     "PGN 65264 byte 6: 2-bit switch fields (0 off, 1 on, 3 from the data link) from switches 19 and 3 "
     "(was j1939_protection_data_byte_a)"),
    ("0x003fb008", "j1939_protection_data_byte_b", "j1939_pgn65264_payload_byte_7",
     "PGN 65264 byte 7: a 2-bit switch field from switch 31 (was j1939_protection_data_byte_b)"),
]
NEW_ROWS = [  # (address, name, type, comment)
    ("0x003fba28", "emission_level_cap_before_rate_limit", "word",
     "The running maximum of the nine caps before the rate limiter (cm848_calculateEmissionLevelCapCommand stores each "
     "partial maximum here; nothing reads it) - no e2m record" + NEW),
    ("0x0040654c", "emission_level_cap_override_value", "word",
     "e2m 198B +4 C_EMO_Cap_EL_Override_Value 'Cap EL override value'" + T + " (1/1024; 1024 here): "
     "emission_level_cap_command while emission_level_cap_user_override_enable_cal is set" + ROM + NEW),
    ("0x003fd7e8", "emission_level_cap_user_override_enable_cal", "word",
     "EEPROM 0x366 - e2m 198F +0 T_EMO_Cap_EL_User_Override 'Enable trim to use Cap EL override value'" + T +
     " (0 here)" + NEW),
    ("0x003fd7ea", "emission_manager_engine_protection_state_user_override_enable_cal", "word",
     "EEPROM 0x368 - e2m 198F +2 T_EMO_State_User_Override 'EMM general engine protection state user override "
     "enable': not 0 makes emission_manager_engine_protection_state = "
     "emission_manager_engine_protection_state_override_value (0 here)" + NEW),
    ("0x00406568", "emission_manager_engine_protection_state_override_value", "word",
     "e2m 19B4 +0 C_EMO_State_Override_Value 'EMO protection state override'" + T + " (1024 here)" + ROM + NEW),
    ("0x0040656a", "emission_manager_engine_protection_state_forced_on_mask", "word",
     "e2m 19B4 +2 C_EMO_Override_Enable_Mask: ORed into the computed state when there is no user override, so it forces "
     "bits on (0x400 here, a bit nothing tests - hence the dump's 0x402)" + ROM + NEW),
    ("0x0040a5ec", "emission_manager_auxiliary_emission_control_state", "word",
     "e2m 19B5 +0 EMM_AECD_State" + T + ": bit 0 air handling, 1 extreme ambient overheat, 2 condensation, 3 white "
     "smoke and misfire, 4 extended idle, 5 engine start and warmup, 6 general engine protection, 7 DAT_003fba36 "
     "(cm848_packAuxiliaryEmissionControlState; nothing reads it; 0 in the dump)" + NEW),
    ("0x0040a5f0", "emission_level_cap_average", "word",
     "e2m 199B +0 EMM_Cap_EL_Avg" + T + ": the 150-sample average of emission_level_cap_command "
     "(cm848_updateNotToExceedAverages; nothing reads it; 1024 in the dump)" + NEW),
    ("0x0040a5f2", "nitrogen_oxide_target_off_nominal_adjusted_average", "word",
     "e2m 199B +2 EMM_bsNOx_Avg (g/hp-h, 1/4096): the 150-sample average of nitrogen_oxide_target_off_nominal_adjusted "
     "(nothing reads it)" + NEW),
    ("0x0040a5ae", f"{PROTECTION}_near_compressor_outlet_temperature_limit_flag", "word",
     "e2m 1997 +18 EMO_Near_COT_Limit (cm848_checkAirHandlingSystemNearLimits)" + T + NEW),
    ("0x0040a5b0", f"{PROTECTION}_near_turbocharger_speed_limit_flag", "word",
     "e2m 1997 +1A EMO_Near_Speed_Limit (cm848_checkAirHandlingSystemNearLimits)" + NEW),
    ("0x0040a5b2", f"{PROTECTION}_near_exhaust_temperature_limit_flag", "word",
     "e2m 1997 +1C EMO_Near_Texh_Limit (cm848_checkAirHandlingSystemNearLimits)" + NEW),
    ("0x00406460", f"{PROTECTION}_level_2_emission_level_cap_when_active", "word",
     "e2m 1990 +0 C_EMO_Air_AECD_Level_2_Cap_EL" + T + " (1/1024; 2048 = 2.0 here)" + ROM + NEW),
    ("0x00406468", f"{PROTECTION}_level_1_altitude_limit", "i16",
     "e2m 1990 +8 C_EMO_Altitude_Thd_1 (ft, lha; 15000 here): level 1 needs the altitude at or below it" + ROM + NEW),
    ("0x0040646a", f"{PROTECTION}_level_2_altitude_limit", "i16",
     "e2m 1990 +A C_EMO_Altitude_Thd_2 (ft, lha; 15000 here)" + ROM + NEW),
    ("0x0040646c", f"{PROTECTION}_level_1_ambient_temperature_offset", "i16",
     "e2m 1990 +C C_EMO_Amb_Tmptr_Offset_1 (1/64 degF, lha; 6464 = 101 degF here)" + ROM + NEW),
    ("0x0040646e", f"{PROTECTION}_level_2_ambient_temperature_offset", "i16",
     "e2m 1990 +E C_EMO_Amb_Tmptr_Offset_2 (1/64 degF, lha; 19264 = 301 degF here)" + ROM + NEW),
    ("0x004065ba", "white_smoke_and_misfire_protection_coolant_temperature_limit", "i16",
     "e2m 19A8 +0 C_EMO_UHC_Coolant_Tmptr_Limit (unburned hydrocarbons; 1/64 degF, lha; 10880 = 170 degF here)" + T +
     ROM + NEW),
    ("0x004065bc", "white_smoke_and_misfire_protection_emission_level_cap_when_active", "word",
     "e2m 19A8 +2 C_EMO_White_Smoke_Cap_EL (1/1024; 1024 here)" + ROM + NEW),
    ("0x00406fb2", "general_engine_protection_emission_level_cap_when_active", "word",
     "e2m 1A41 +0 C_EMO_Gen_Protect_Cap_EL" + T + " (the e2m scale is 0.001: 1000 = 1.0 here, while the other caps "
     "of the max-select use 1/1024)" + ROM + NEW),
]
ARRAY = ("0x003fafe8", "power_take_off_remote_speed_by_press_count", "word[6]",
         ["protection_rpm_reference_snapshot", "governor_rpm_reference_snapshot_a", "governor_rpm_ref_target_0_snapshot",
          "governor_rpm_ref_target_1_snapshot", "governor_rpm_ref_target_2_snapshot", "governor_rpm_ref_target_3_snapshot"],
         "The remote speed for each remote switch press count: power_take_off_remote_speed_1_cal twice, then "
         "power_take_off_remote_speed_2_cal .. _5_cal (copied at initialization); read indexed by "
         "power_take_off_remote_switch_press_count, [0] never (11200 11200 11200 12800 14400 16000 here) "
         "(was protection_rpm_reference_snapshot, governor_rpm_reference_snapshot_a, governor_rpm_ref_target_0..3_snapshot)")
FUNCTIONS = [  # (address, old, new, plate or None = keep the old plate and add "(was old)"; "+" prefix = prepend)
    ("0x0050477c", "fuel_demandMin_maxSelect_rateLimit", "cm848_calculateEmissionLevelCapCommand",
     "The emission manager's cap: the maximum of nine inputs (the air handling, condensation, engine start and warmup, "
     "extended idle, extreme ambient overheat, general engine protection and white smoke and misfire AECD caps, "
     "DAT_003fba26 and emission_level_cap_reference), slew-limited by emission_level_cap_rate_limit_increase / "
     "_decrease, then emission_level_cap_override_value instead while emission_level_cap_user_override_enable_cal is "
     "set, into emission_level_cap_command (was fuel_demandMin_maxSelect_rateLimit)"),
    ("0x00505260", "fuel_modeStatusBits_pack", "cm848_packAuxiliaryEmissionControlState",
     "Packs the eight AECD activity bits into emission_manager_auxiliary_emission_control_state (e2m EMM_AECD_State) "
     "(was fuel_modeStatusBits_pack)"),
    ("0x0050530c", "fuel_modeStatusFlags_update", "cm848_calculateEmissionManagerEngineProtectionState",
     "emission_manager_engine_protection_state (e2m EMM_Protection_State): the override value while the user override "
     "is enabled, else general_engine_protection_state OR white_smoke_and_misfire_protection_state OR 0x01 engine start "
     "and warmup OR 0x80 extended idle or condensation OR 0x02 engine neither starting nor active, OR the forced-on mask "
     "(was fuel_modeStatusFlags_update)"),
    ("0x00504528", "fuel_blendMode_conditionCheck_update", "cm848_updateAirHandlingSystemProtection",
     "The e2m EMO air handling system protection AECD (blocks 1990-1997; algorithm_enable_flags_20_cal bit 0x100, set "
     "on this truck): the level 2 / 3 conditions and their allowed flags, air_handling_system_protection_active_flag "
     "and air_handling_system_protection_emission_level_cap (the level 3 or level 2 cap when allowed, else 0) "
     "(was fuel_blendMode_conditionCheck_update)"),
    ("0x005041bc", "etc1_threshold_lookup", "cm848_checkAirHandlingSystemProtectionHighLoad",
     "Sets air_handling_system_protection_high_load_flag from a torque input and "
     "air_handling_system_protection_high_load_torque_axis / _values over engine speed (was etc1_threshold_lookup)"),
    ("0x0050422c", "governor_adjustment_blend_check", "cm848_checkAirHandlingSystemProtectionLevelConditions",
     "The level 1 / 2 conditions: the altitude at or below air_handling_system_protection_level_N_altitude_limit and the "
     "ambient temperature at or below altitude x the level's ambient temperature limit slope / 16 + its offset "
     "(was governor_adjustment_blend_check)"),
    ("0x005043b4", "governor_adjustment_compare", "cm848_checkAirHandlingSystemNearLimits",
     "Looks up the compressor outlet temperature, exhaust temperature and turbocharger speed limits over altitude and "
     "sets the three near-limit flags and their OR (was governor_adjustment_compare)"),
    ("0x005057ec", "cm848_updateInjectionTimingTemperatureComponentCheckFlags", "cm848_updateWhiteSmokeAndMisfireProtection",
     "+The e2m EMO white smoke and misfire protection AECD (blocks 19A8 / 19A9). "),
    ("0x00509a7c", "cm848_updateSensorValidationFlags", "cm848_updateGeneralEngineProtection",
     "The e2m EMO general engine protection AECD (blocks 1A41 / 1A42; governor_feature_config_flags bit 0x40, clear on "
     "this truck): general_engine_protection_state from egr_system_failure_flag (0x100), DAT_0040a43c (8) and "
     "DAT_0040a43e (4), and its cap (was cm848_updateSensorValidationFlags)"),
    ("0x00507694", "fuel_demandBlend_weight_calc", "cm848_calculateEmissionLevelCapReference",
     "emission_level_cap_reference = the altitude x ambient temperature cap table times the engine speed x net torque "
     "ratio table >> 10 (e2m C_EMR_Cap_EL_Table x C_EMR_Cap_EL_Ratio_Table) (was fuel_demandBlend_weight_calc)"),
    ("0x00507748", "fuel_demandBlend_rpmRange_check", "cm848_checkNotToExceedZone",
     "not_to_exceed_zone_flag = 1 while net_combustion_torque_copy is between the zone's lower and upper torque for the "
     "engine speed (was fuel_demandBlend_rpmRange_check)"),
    ("0x005077fc", "main_loop_callPhaseGroupProcessors", "cm848_updateEmissionLevelCapReference",
     "Main-loop phase 0x17: cm848_calculateEmissionLevelCapReference, then cm848_checkNotToExceedZone "
     "(was main_loop_callPhaseGroupProcessors)"),
    ("0x005053e0", "fuel_demandTiming_rollingAverage_update", "cm848_updateNotToExceedAverages", None),
    ("0x00504948", "cm848_mainLoop_step", "cm848_runEmissionManager",
     "Main-loop phase 0x15, the emission manager: the load rate, the air handling, extreme ambient, condensation, white "
     "smoke, extended idle and engine start protections, the cap command, the protection state, the AECD state and the "
     "not-to-exceed averages (was cm848_mainLoop_step)"),
    ("0x00504938", "cm848_initialization_step_6", "cm848_initializeEmissionLevelCapRateLimiter",
     "Clears emission_level_cap_rate_limited_previous (was cm848_initialization_step_6)"),
    ("0x0002abc8", "cm848_initProtectionFilterState", "cm848_initializePowerTakeOffGovernorFiltersAndGains",
     "Boot initialization of the power take-off governor: power_take_off_speed_error_filter (accumulator 0, coefficient "
     "power_take_off_speed_error_filter_coefficient), the reference filter (cm848_initializePowerTakeOffReferenceFilter), "
     "the QD / QI / QP gain adjustments = 0x80 (1.0) and the four lookup caches = 2 (was cm848_initProtectionFilterState)"),
    ("0x0002ad28", "cm848_setProtectionParamFromRpm", "cm848_presetPowerTakeOffSmoothedReferenceEngineSpeed",
     "On the first active pass (from cm848_presetPowerTakeOffGovernorOnEngagement): "
     "power_take_off_governor_smoothed_reference_engine_speed = the engine speed and the reference filter's accumulator "
     "= 0 (was cm848_setProtectionParamFromRpm)"),
    ("0x0002ad48", "cm848_initProtectionSmoothingPointer", "cm848_initializePowerTakeOffReferenceFilter",
     "Clears power_take_off_reference_filter_state's accumulator and points its coefficient at "
     "power_take_off_reference_filter_coefficient (was cm848_initProtectionSmoothingPointer)"),
    ("0x0002bd38", "cm848_resetProtectionBypass", "cm848_initializePowerTakeOffThrottleOverride",
     "At boot: power_take_off_throttle_override_flag = 0 and power_take_off_throttle_override_engine_speed_limit = "
     "engine_speed_limit_default_cal - the stores cm848_selectPowerTakeOffOrUserFueling makes whenever the throttle is "
     "not overriding (was cm848_resetProtectionBypass)"),
    ("0x0002bd58", "cm848_j1939HandlePgn65264Pto", "cm848_buildPgn65264PowerTakeOffInformationMessage",
     "Builds and sends PGN 65264 (power take-off information, 8 bytes): bytes 4-5 = power_take_off_requested_engine_speed "
     "(byte-swapped) when j1939_governor_feature_cal bit 0x10 is set, else 0xFFFF; bytes 6 / 7 = 2-bit switch fields "
     "(switches 19 + 3, switch 31). The PGN 65264 request responder (cm848_initJ1939ProtocolHandlers) and a 100 ms "
     "broadcast (cm848_j1939_system_init) (was cm848_j1939HandlePgn65264Pto)"),
    ("0x0002bed4", "cm848_initJ1939PtoBuffer", "cm848_initializePgn65264PowerTakeOffInformationBuffer",
     "Fills j1939_pgn65264_tx_message: the CAN id from j1939_pgn65264_priority_cal and j1939_source_address (0x18FEF000 "
     "here), length 8, payload bytes 1, 2-3 and 8 = 0xFF (was cm848_initJ1939PtoBuffer)"),
    ("0x005129b0", "protection_control_state_check_2", "cm848_debounceCruiseSwitchRequest",
     "Debounces cruise_switch_button_code into a CRUISE_SWITCH_REQUEST (returns 5 while the code settles); used by the "
     "power take-off state machine and cm848_cruiseControlPeriodicUpdate (was protection_control_state_check_2)"),
]
TEXT = [  # (file, exact old text, new text)
    ("global_variables.csv", "PTO_Reference_Step_Limit: the largest step of the smoothed reference per pass",
     "PTO_Reference_Step_Limit (e2m PTRFLM 'Min. step change of Reference speed'): within it the smoothed reference "
     "snaps to the requested speed; otherwise one EMA step, but at least this"),
    ("global_variables.csv", "the target the state machine sets and cm848_rampPowerTakeOffReferenceEngineSpeed ramps",
     "the output of cm848_rampPowerTakeOffReferenceEngineSpeed, which ramps power_take_off_target_engine_speed (set by the "
     "state machine) into it"),
    ("global_variables.csv", "e2m 10AB +1A PTO_Droop_Compensated_Error (was governor_fuel_integral_error)",
     "e2m 10AB +1A PTO_Droop_Compensated_Error; nothing stores it in this build, and its only reader "
     "(cm848_calculateFuelDemandWithConditions, while the power take-off governor is active) reads 0, so the label rests "
     "on the e2m position alone (was governor_fuel_integral_error)"),
    ("global_variables.csv", "like algorithm_enable_flags_12_cal); 0x0100 here",
     "like algorithm_enable_flags_12_cal); 0x0100 here. Tested bits: 0x100 the air handling system protection AECD (set: "
     "the only AECD enabled on this truck), 0x200 extreme ambient overheat, 0x400 white smoke and misfire, 0x800 extended "
     "idle, 0x1000 engine start and warmup"),
    ("function_renames.csv", "power_take_off_requested_engine_speed minus engine speed, clamped to +-1000 rpm and filtered",
     "power_take_off_governor_smoothed_reference_engine_speed minus engine speed, clamped to +-1000 rpm, times "
     "power_take_off_gain_adjustment_multiplier >> 14, through power_take_off_speed_error_filter"),
    ("function_renames.csv", "Smooths power_take_off_requested_engine_speed toward its target (minimum step + EMA)",
     "Runs the engagement ramp (cm848_rampPowerTakeOffReferenceEngineSpeed: power_take_off_target_engine_speed into "
     "power_take_off_requested_engine_speed), then smooths power_take_off_requested_engine_speed into "
     "power_take_off_governor_smoothed_reference_engine_speed (minimum step + EMA)"),
    ("function_renames.csv", "restarted whenever fuel_demand_blend_rpm_in_range_flag is 0; the two averages have no reader. "
                             "Name kept.",
     "restarted whenever fuel_demand_blend_rpm_in_range_flag is 0; the two averages have no reader "
     "(was fuel_demandTiming_rollingAverage_update)"),
]

path = os.path.join(OUT, "global_variables.csv")
lines = open(path, newline="").read().split("\n")


def index_of(address):
    hits = [i for i, line in enumerate(lines) if line.split(",", 1)[0] == address]
    assert len(hits) == 1, (address, len(hits))
    return hits[0]


renames = []
for address, old, new, comment in RENAMES:
    i = index_of(address)
    a, name, typ, current = (lines[i].split(",", 3) + [""])[:4]
    assert name == old, (address, name, old)
    if comment is None:
        comment = (current + " " if current else "") + f"(was {old})"
    elif comment.startswith("+"):
        comment = comment[1:] + current + f" (was {old})"
    lines[i] = ",".join([a, new, typ, comment])
    old_label = old or (f"WORD_ARRAY_{int(address, 16):08x}" if typ.startswith("word[") else f"DAT_{int(address, 16):08x}")
    renames.append((address, new, old_label, "global"))
for address, name, typ, comment in NEW_ROWS:
    assert not any(line.split(",", 1)[0] == address for line in lines), address
    base = int(address, 16)
    before = [k for k, line in enumerate(lines) if line.startswith("0x") and 0 < base - int(line.split(",", 1)[0], 16) < 0x40]
    k = max(before) if before else len(lines) - 1
    lines.insert(k + 1, ",".join([address, name, typ, comment]))
    renames.append((address, name, f"DAT_{base:08x}", "global"))
address, name, typ, olds, comment = ARRAY
base = int(address, 16)
for k, old in enumerate(olds):
    i = index_of(f"0x{base + 2 * k:08x}")
    assert lines[i].split(",")[1] == old, (hex(base + 2 * k), lines[i][:60])
for k in range(len(olds) - 1, 0, -1):
    del lines[index_of(f"0x{base + 2 * k:08x}")]
i = index_of(address)
lines[i] = ",".join([address, name, typ, comment])
open(path, "w", newline="").write("\n".join(lines))

path = os.path.join(OUT, "function_renames.csv")
lines = open(path, newline="").read().split("\n")
for address, old, new, plate in FUNCTIONS:
    i = next(k for k, line in enumerate(lines) if line.split(",", 1)[0] == address)
    parts = (lines[i].split(",", 2) + [""])[:3]
    assert parts[1] == old, (address, parts[1], old)
    if plate is None:
        plate = parts[2]
    elif plate.startswith("+"):
        plate = plate[1:] + parts[2] + f" (was {old})"
    lines[i] = ",".join([address, new, plate])
    renames.append((address, new, old, "function"))
open(path, "w", newline="").write("\n".join(lines))
for csv_name in ("function_definitions.csv", "local_variables.csv"):
    p = os.path.join(OUT, csv_name)
    text = open(p, newline="").read()
    for address, old, new, _ in FUNCTIONS:
        text = text.replace(f"{address},{old},", f"{address},{new},")
    open(p, "w", newline="").write(text)

for name_, old, new in TEXT:
    p = os.path.join(OUT, name_)
    text = open(p, newline="").read()
    assert text.count(old) == 1, (name_, old[:60], text.count(old))
    open(p, "w", newline="").write(text.replace(old, new))

with open(os.path.join(here, "map_stage6b.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, new, old, kind in renames:
        f.write(f"{address},{new},{old},{kind}\n")
print(f"stage 6b: {len(RENAMES)} renames, {len(NEW_ROWS)} new rows, 1 array, {len(FUNCTIONS)} functions, {len(TEXT)} text fixes")
