"""build.py: build the W14 functions1 result file, validate it, and write it.
usage: build.py [--write]    (without --write only the checks run and a draft goes to /tmp/w14_functions1/result_draft.jsonl)"""
import csv
import glob
import json
import re
import sys

OUT_DIR = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"
BINS = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/functions1.json"
FINAL = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_functions1.jsonl"
DRAFT = "/tmp/w14_functions1/result_draft.jsonl"

R = {}      # address -> dict


def rename(address, old, new, evidence, code_quote, plate):
    R[address] = {"kind": "function", "verdict": "confirmed", "address": address, "old": old, "new": new,
                  "evidence": evidence, "code_quote": code_quote, "plate_comment": plate}


# ---------------------------------------------------------------- alpha (e2m 104A / 104B)
rename(
    "0x0000e0f4", "cm848_checkPressureFuelState", "cm848_calculateAlphaAltitudeDerateLatch",
    "Returns 1 while alpha must follow altitude_derate_alpha: when final_fueling_state is FUELING_STATE_ALTITUDE_DERATE it reloads "
    "alpha_altitude_derate_timer (e2m 104A +1A Alpha_Altitude_Derate_Timer) with altitude_derate_alpha_timeout (e2m 104B +A) and returns 1; "
    "otherwise it counts the timer down and returns 1 until it hits 0 (then clears it and returns 0); with bit 0x20 of feature_enable_flags_cal "
    "clear it clears the timer and returns 0. Only caller hpcr_calculateFuelTrimOutput (disassembly 0xe648: bl 0xe0f4, clrlwi r3,r3,16, "
    "cmpwi r3,0) turns a nonzero result into alpha source 2 with combustion_alpha_input = altitude_derate_alpha. Nothing about pressure or fuel state.",
    "if (final_fueling_state != FUELING_STATE_ALTITUDE_DERATE) {",
    "Alpha altitude derate latch: returns 1 while alpha must follow altitude_derate_alpha (e2m 104B +8 Altitude_Derate_Alpha), else 0. "
    "With bit 0x20 of feature_enable_flags_cal clear it clears alpha_altitude_derate_timer (e2m 104A +1A Alpha_Altitude_Derate_Timer) and returns 0. "
    "Otherwise, in every pass final_fueling_state is FUELING_STATE_ALTITUDE_DERATE it reloads the timer with altitude_derate_alpha_timeout "
    "(e2m 104B +A Altitude_Derate_Alpha_Timeout, 'time alpha is latched to ADALF after Altitude Derate stops fuel limiting') and returns 1; "
    "after the derate stops it counts the timer down by 1 per pass and keeps returning 1 until the timer is 0. "
    "Only caller hpcr_calculateFuelTrimOutput: a nonzero result selects alpha source 2 (altitude).")

rename(
    "0x0000e164", "cm848_calculateSensorEma", "cm848_calculateAlphaFuelRateResult",
    "Filters fuel_mass_flow_raw with exponentialMovingAverage into alpha_filtered_fuel_delivery_rate (e2m 104A +14 Filtered_Fuel_Delivery_Rate, LB/HR) "
    "and returns a hysteresis: 1 when alpha_threshold_fuel_rate < filtered, 0 when alpha_reset_fuel_rate >= filtered, else the previous alpha_fuel_rate_result "
    "(e2m 104A +8 Alpha_Fuel_Rate '[APFLRTAP] result of Fuel Rate algorithm'); ROM reset 330 < threshold 363. No sensor is involved: the old name read the EMA as a sensor filter. "
    "Shared-name note: cross_firmware_matches.csv line 16 maps CM550 0xc404 to it as 'calculateSensorEma' (review); CM550 0xc404 is the same function "
    "(called as _APFLRTAP = cm550_FUN_0000c404() in the CM550 alpha ramp 0xc582).",
    "if ((uint)alpha_threshold_fuel_rate < (dVar1 & 0xffff)) {",
    "Alpha fuel rate result (e2m 104A +8 Alpha_Fuel_Rate, '[APFLRTAP] result of Fuel Rate algorithm'): filters fuel_mass_flow_raw with exponentialMovingAverage "
    "(state cold_start_intake_temperature_filter_state, coefficient e2m 104B +C Alpha_Fuel_Rate_Filter_Constant at ROM 0x5be66) into alpha_filtered_fuel_delivery_rate "
    "(e2m 104A +14 Filtered_Fuel_Delivery_Rate, LB/HR). Result is a hysteresis on that rate: 1 above alpha_threshold_fuel_rate (e2m 104B +1A C_Alpha_Threshold_Rate), "
    "0 at or below alpha_reset_fuel_rate (e2m 104B +18 C_Alpha_Reset_Rate), else the previous alpha_fuel_rate_result. While alpha_low_speed_governor_state_detected_flag is 1 "
    "and the filtered rate is above the reset rate, the filter accumulator is first pulled down to the reset rate. Called by timingProtectionFlagsOrchestrator when bit 0x1000 "
    "of governor_fault_status_flags (algorithm enable flags word 0, 0x3fd59c) is set; a 1 lets alpha_base ramp toward 1.0.")

rename(
    "0x0000e218", "cm848_checkFuelRateCondition", "cm848_calculateAlphaOnGovernorResult",
    "Returns 1 when final_fueling_state is FUELING_STATE_VEHICLE_SPEED_LIMIT or cruise_control_engaged_flag is 1, else 0; this is e2m 104A +A Alpha_Governor "
    "'[APGVAP] result of On Governor' (word 0x40a172 fuel_rate_condition_status, written by timingProtectionFlagsOrchestrator). It has no fuel rate in it: "
    "the fuel rate condition is cm848_calculateSensorEma at 0xe164, so the two names were swapped. The CM550 twin (0xc496) tests fuel_limit_selection_state == 10 "
    "or _cruise_control_active_flag == 1. The word 0x40a172 should mirror this name (alpha_on_governor_result).",
    "if ((final_fueling_state == FUELING_STATE_VEHICLE_SPEED_LIMIT) ||",
    "Alpha on governor result (e2m 104A +A Alpha_Governor, '[APGVAP] result of On Governor'): returns 1 while the engine is on a speed governor, "
    "that is final_fueling_state is FUELING_STATE_VEHICLE_SPEED_LIMIT or cruise_control_engaged_flag is 1, else 0. Called by timingProtectionFlagsOrchestrator "
    "when bit 0x2000 of governor_fault_status_flags (algorithm enable flags word 0) is set; the result is stored in fuel_rate_condition_status "
    "(0x40a172) and a 1 lets alpha_base ramp toward 1.0.")

rename(
    "0x0000e248", "cm848_checkPressureFuelDelayA", "cm848_calculateAlphaLowSpeedGovernorResult",
    "While alpha_low_speed_governor_state_detected_flag is 1 it reloads cold_start_timer_a (e2m 104A +16 Alpha_LSG_Timer) with low_speed_governor_alpha_timeout "
    "(e2m 104B +14 LSG_Alpha_Timeout 'time that must expire without LSG commanding fuel before alpha is one') and returns 0; while the active flag is set and the timer "
    "is not 0 it counts down and returns 0; otherwise it clears the flag and returns 1. The result is e2m 104A +C Alpha_LSG (0x40a174 pressure_fuel_delay_a_status); "
    "the CM550 twin 0xc4b2 has the same shape. No pressure or fuel delay is involved.",
    "cold_start_timer_a = low_speed_governor_alpha_timeout;",
    "Alpha low speed governor result (e2m 104A +C Alpha_LSG, '[APLSAP] result of LSG algorithm'): a timeout after the low speed governor last acted. "
    "While alpha_low_speed_governor_state_detected_flag is 1 it reloads cold_start_timer_a (e2m 104A +16 Alpha_LSG_Timer) with low_speed_governor_alpha_timeout "
    "(e2m 104B +14 LSG_Alpha_Timeout, 'time that must expire without LSG commanding fuel before alpha is one'), sets cold_start_timer_a_active_flag and returns 0; "
    "while the active flag is set and the timer is above 0 it counts it down by 1 per pass and returns 0; otherwise it clears the active flag and returns 1. "
    "Called by timingProtectionFlagsOrchestrator when bit 0x400 of governor_fault_status_flags (algorithm enable flags word 0) is set; "
    "the result is stored in pressure_fuel_delay_a_status (0x40a174) and a 1 lets alpha_base ramp toward 1.0.")

rename(
    "0x0000e2cc", "cm848_checkPressureFuelDelayB", "cm848_calculateAlphaAirFuelControlResult",
    "Same timer shape as the low speed governor result, reloaded when alpha_air_fuel_control_state_detected_flag OR alpha_low_speed_governor_state_detected_flag is 1: "
    "cold_start_timer_b (e2m 104A +18 Alpha_AFC_Timer 'time since fueling state is not AFC or LSG') = air_fuel_control_alpha_timeout (e2m 104B +6 AFC_Alpha_Timeout "
    "'time that must elapse without AFC limiting before ALPHA may be set to one'), returns 0 while it runs and 1 once it ran out. The result is e2m 104A +6 Alpha_AFC "
    "(0x40a16e pressure_fuel_delay_b_status). The CM550 twin is cm550_fuelModeTransitionCountdownHandler 0xc504 (_afc_exit_countdown_timer). No pressure or fuel delay is involved.",
    "cold_start_timer_b = air_fuel_control_alpha_timeout;",
    "Alpha air fuel control result (e2m 104A +6 Alpha_AFC, '[APAFSS] result of AFC algorithm'): a timeout after air fuel control (or the low speed governor) last limited the fuel. "
    "While alpha_air_fuel_control_state_detected_flag or alpha_low_speed_governor_state_detected_flag is 1 it reloads cold_start_timer_b (e2m 104A +18 Alpha_AFC_Timer) with "
    "air_fuel_control_alpha_timeout (e2m 104B +6 AFC_Alpha_Timeout, 'time that must elapse without AFC limiting before ALPHA may be set to one'), sets "
    "cold_start_timer_b_active_flag and returns 0; while the active flag is set and the timer is above 0 it counts it down by 1 per pass and returns 0; otherwise it clears the "
    "active flag and returns 1. Called by timingProtectionFlagsOrchestrator when bit 0x800 of governor_fault_status_flags (algorithm enable flags word 0) is set; "
    "the result is stored in pressure_fuel_delay_b_status (0x40a16e) and a 1 lets alpha_base ramp toward 1.0.")

rename(
    "0x0000e360", "cm848_checkPressureHysteresis", "cm848_calculateAlphaLowAmbientAirPressureResult",
    "Hysteresis on barometric_pressure_reference: 1 when it is below alpha_lock_on_barometric_pressure (e2m 104B +10 Alpha_Lock_On_Air_Pressure 'air pressure below which alpha is ramped to 1', ROM 1507), "
    "0 when it is above alpha_lock_off_barometric_pressure (e2m 104B +E Alpha_Lock_Off_Air_Pressure 'air pressure after hysteresis to unlock alpha', ROM 1540), else the previous "
    "pressure_hysteresis_state = e2m 104A +12 Alpha_Low_Ambient_Air_Pressure '[APAAPRSS] alpha based only on ambient air pressure logic'. 'Low' is the compare "
    "barometric_pressure_reference < alpha_lock_on_barometric_pressure; the pressure is the ambient (barometric) one, not a fuel or boost pressure. CM550 twin 0xc556.",
    "if (barometric_pressure_reference < alpha_lock_on_barometric_pressure) {",
    "Alpha low ambient air pressure result (e2m 104A +12 Alpha_Low_Ambient_Air_Pressure, '[APAAPRSS] alpha based only on ambient air pressure logic'): a hysteresis on "
    "barometric_pressure_reference. Returns 1 (alpha may ramp to 1.0) while it is below alpha_lock_on_barometric_pressure (e2m 104B +10 Alpha_Lock_On_Air_Pressure, "
    "'air pressure below which alpha is ramped to 1'), 0 once it is above alpha_lock_off_barometric_pressure (e2m 104B +E Alpha_Lock_Off_Air_Pressure, 'air pressure after "
    "hysteresis to unlock alpha'; ROM 1540 against 1507 for the lock on value), and the previous pressure_hysteresis_state in between. Called by "
    "timingProtectionFlagsOrchestrator when bit 0x8000 of governor_fault_status_flags (algorithm enable flags word 0) is set; the result is stored in pressure_hysteresis_state (0x40a17a).")

rename(
    "0x0000e3a4", "timingProtectionFlagsOrchestrator", "cm848_calculateAlphaBase",
    "Runs the five alpha conditions enabled by bits 0x400 / 0x800 / 0x1000 / 0x2000 / 0x8000 of governor_fault_status_flags (low speed governor, air fuel control, fuel rate, on governor, "
    "low ambient air pressure) and ORs the results: alpha_base is cleared to 0 when none is 1, otherwise it ramps by alpha_ramp_rate_below_threshold while alpha_base < alpha_ramp_threshold "
    "and by alpha_ramp_rate_at_or_above_threshold from there on (e2m 104B +0 / +2 / +4), capped at 0x4000 = 1.0. alpha_base is e2m 104A +2 Alpha_Base '[APAPBA] result of AFC, LSG, On Governor, "
    "and Fuel Rate alpha comparison'. Nothing about timing or protection. SHARED NAME: CM550 0xc582 has the same name and is the same function (it writes _APAPBA, _APLSAP, _APAFSS, _APFLRTAP, "
    "_APGVAP, _APAAPRSS), so the main session holds this rename for both firmwares.",
    "alpha_base = alpha_base + wVar1;",
    "Alpha ramp (e2m 104A +2 Alpha_Base, '[APAPBA] result of AFC, LSG, On Governor, and Fuel Rate alpha comparison'; alpha 16384 = 1.0 = open road, 0 = urban). "
    "Runs the alpha conditions that bits of governor_fault_status_flags (algorithm enable flags word 0) enable and stores each result: 0x400 cm848_checkPressureFuelDelayA "
    "(low speed governor) into pressure_fuel_delay_a_status, 0x800 cm848_checkPressureFuelDelayB (air fuel control) into pressure_fuel_delay_b_status, 0x1000 cm848_calculateSensorEma "
    "(fuel rate) into alpha_fuel_rate_result, 0x2000 cm848_checkFuelRateCondition (on governor) into fuel_rate_condition_status and 0x8000 cm848_checkPressureHysteresis "
    "(low ambient air pressure) into pressure_hysteresis_state. When none of them is 1 alpha_base is reset to 0; otherwise it ramps up each pass by "
    "alpha_ramp_rate_below_threshold while it is below alpha_ramp_threshold and by alpha_ramp_rate_at_or_above_threshold from there on (e2m 104B +0 Alpha_Ramp_Rate_1 / +2 Alpha_Ramp_Rate_2 / "
    "+4 Alpha_Ramp_Threshold), capped at 16384. It then copies final_fueling_state to governor_mode_code_snapshot and clears alpha_low_speed_governor_state_detected_flag and "
    "alpha_air_fuel_control_state_detected_flag. Only caller hpcr_calculateFuelTrimOutput (every pass outside the engine states STOPPED, CRANKING and JUMP_START).")

rename(
    "0x0000e518", "hpcr_calculateFuelTrimOutput", "cm848_calculateAlpha",
    "Selects the alpha source and writes combustion_alpha_input (e2m 104A +0 Alpha 'ALPHA PARAMETER 0.0 = URBAN 1.0 = OPEN ROAD') and governor_startup_state (e2m 104A +4 Alpha_State "
    "'source (base, user, altitude, epf, slave, esp)'), codes 0 base / 1 user / 2 altitude / 3 engine protection / 4 slave / 5 esp, from the disassembly 0xe5b4-0xe6fc "
    "(the decompile around the 0xe0f4 call renders its result as a 64-bit pointer, pwVar1 / uVar2 & 0xffff00000000). It also copies the alpha to thermal_fuel_limit_factor (e2m 1053 +2 Fuel_Interp_Factor, the 4-D fueling "
    "interpolation factor) unless algorithm_enable_flags_12_cal bit 0x10 (ESP enable) is set (disassembly 0xe71c-0xe734: sth to 0x40a889). It is not a fuel trim. "
    "SHARED NAME: the flagged cross-firmware match (CM550 0x1abb2, review tier) is wrong: cm550_FUN_0001abb2 is the ESP / throttle fueling function; the CM550 twin of this function is "
    "vp44RpmBasedFaultDetector @ 0xc326 (writes _APAPST, _APAPBA and _alpha_blend_factor and calls timingProtectionFlagsOrchestrator). The main session holds this rename.",
    "combustion_alpha_input = engine_protection_alpha;",
    "Selects the alpha (0 = urban, 16384 = 1.0 = open road; e2m 104A +0 Alpha) and its source code (e2m 104A +4 Alpha_State) into combustion_alpha_input and governor_startup_state: "
    "0 base (alpha_base), 1 user (fuel_blend_coefficient_startup_cal), 2 altitude (altitude_derate_alpha, e2m 104B +8), 3 engine protection (engine_protection_alpha, e2m 104B +12), "
    "4 slave override (governor_startup_fuel_blend_coeff), 5 ESP (fuel_blend_coefficient_run_cal). In the engine states STOPPED, CRANKING and JUMP_START it preloads cold_start_timer_a / _b "
    "with low_speed_governor_alpha_timeout / air_fuel_control_alpha_timeout (active flags 1), clears alpha_altitude_derate_timer, alpha_filtered_fuel_delivery_rate, the fuel rate filter accumulator, "
    "alpha_base and governor_mode_code_snapshot; in every other state it runs timingProtectionFlagsOrchestrator (the alpha ramp). Source priority, tested in this order (disassembly 0xe5b4-0xe6fc): "
    "master_slave_override_enable_flag nonzero -> 4; bit 0x8000 of governor_feature_config_flags set and governor_startup_threshold = 0x4000 -> 5; mask 0x01 of governor_feature_flags set -> 1; "
    "cm848_checkPressureFuelState nonzero (altitude derate latched) -> 2; mask 0x4000 of governor_fault_status_flags set and fault_derate_active_flag = 1, unless alpha_altitude_derate_timer is nonzero "
    "while mask 0x20 of feature_enable_flags_cal is set -> 3; else 0. The alpha is limited to 16384 and copied to thermal_fuel_limit_factor (e2m 1053 +2 Fuel_Interp_Factor) unless bit 0x10 of "
    "algorithm_enable_flags_12_cal (ESP enable) is set. Caller main_loop.")

rename(
    "0x0000e748", "cm848_initFuelPressureVariables", "cm848_initializeAlpha",
    "Clears cold_start_intake_temperature_filter_state.accumulator and points its coefficient at cold_start_intake_temperature_filter_coefficient (ROM 0x5be66 = e2m 104B +C "
    "Alpha_Fuel_Rate_Filter_Constant, the alpha fuel rate filter), and zeroes alpha_base, cold_start_timer_a_active_flag, cold_start_timer_b_active_flag and "
    "alpha_low_speed_governor_state_detected_flag (disassembly 0xe748-0xe788). Only caller cm848_applicationMain. No fuel pressure variable is touched.",
    "cold_start_intake_temperature_filter_state.accumulator = 0;",
    "Boot initialization of the alpha state: clears the accumulator of the alpha fuel rate filter cold_start_intake_temperature_filter_state and points its coefficient at "
    "cold_start_intake_temperature_filter_coefficient (e2m 104B +C Alpha_Fuel_Rate_Filter_Constant, ROM 0x5be66), and sets alpha_base (e2m 104A +2 Alpha_Base), "
    "cold_start_timer_a_active_flag, cold_start_timer_b_active_flag and alpha_low_speed_governor_state_detected_flag to 0. Called once by cm848_applicationMain.")

# ---------------------------------------------------------------- EGR mass flow models (e2m 177E / 177F)
rename(
    "0x0001242c", "cm848_calculateLoadBasedFuelTrim", "cm848_calculateDownstreamEgrMassFlow",
    "Writes e2m 177F +E CHP_Downstream_Pratio (rpm_conversion = egr_orifice_delta_pressure x 32767 / map_fuel_correction_factor, limited to +-32440 = +-0.99 in Q15), +C CHP_Downstream_Corrected_Flow "
    "(reserved_0c, 3-D table of the filtered egr_valve_position and that ratio, e2m 193D / 193E / 193F), +16 CHP_Sqrt_Torifice_R (reserved_16, table of egr_orifice_temperature, e2m 1946 / 1940) and "
    "+8 CHP_Downstream_EGR_Flow (load_based_trim = corrected flow x charge pressure / sqrt(orifice temperature), saturated at +-0x6400 = +-200 lb/min; e2m 'model of incompressible flow across fixed orifice'). "
    "'Downstream' because cm848_selectFuelTrimMode runs it in the rpm_fuel_trim_select_cal != 0 branch and e2m 177E +A C_CHP_Venturi_Vrt_Sensor_Active reads 'select Upstream (0) or Downstream (1) EGR Flow Model'; "
    "that selector is separate from 177E +8 (hot / cold side delta pressure). Not a fuel trim; the bin-4 lead 'EgrOrificeFlowTerms' names only its inputs.",
    "iVar3 = (int)(short)egr_orifice_delta_pressure;",
    "Downstream EGR mass flow model (e2m 177F +8 CHP_Downstream_EGR_Flow, 'model of incompressible flow across fixed orifice', lb/min x 128; chosen when rpm_fuel_trim_select_cal "
    "= e2m 177E +A C_CHP_Venturi_Vrt_Sensor_Active is nonzero: 1 = downstream model). Writes the e2m 177F words of throttle_fuel_trim_t_0040a3ea: rpm_conversion = +E CHP_Downstream_Pratio "
    "(egr_orifice_delta_pressure x 32767 / map_fuel_correction_factor, the charge pressure e2m 1A2D +0 Charge_Press; limited to +-32440 = +-0.99 in Q15, +0x7eb8 when the charge pressure is 0 and the "
    "delta pressure positive); reserved_0c = +C CHP_Downstream_Corrected_Flow (3-D table of the egr_valve_position filtered by egr_valve_position_filter and that ratio, e2m 193D / 193E / 193F); "
    "reserved_16 = +16 CHP_Sqrt_Torifice_R (table of egr_orifice_temperature, e2m 1946 / 1940); load_based_trim = +8 CHP_Downstream_EGR_Flow = corrected flow x charge pressure / "
    "sqrt(orifice temperature), saturated at +-25600 (+-200 lb/min). Only caller cm848_selectFuelTrimMode.")

rename(
    "0x000125f4", "cm848_calculateRpmBasedFuelTrim", "cm848_calculateUpstreamEgrMassFlow",
    "Writes e2m 177F +12 CHP_Upstream_Corrected_Flow (reserved_12, 3-D table of egr_valve_position and boost_pressure_state_t_0040a406.pressure_ratio = e2m 177D +A CHP_Pratio, tables e2m 18E3 / 18E4 / 18E5), "
    "+10 CHP_Sqrt_Texhaust_R (reserved_10, table of exhaust_temperature, e2m 1974 / 1975) and +A CHP_Upstream_EGR_Flow (rpm_based_trim = corrected flow x boost_pressure_current_raw "
    "(e2m 1A5D +0 Exhaust_Press) / sqrt(exhaust temperature), saturated at +-0x6400 = +-200 lb/min; e2m 'empirical model relating lift and hot side dP to flow'). "
    "'Upstream' because cm848_selectFuelTrimMode runs it in the rpm_fuel_trim_select_cal = 0 branch and e2m 177E +A C_CHP_Venturi_Vrt_Sensor_Active reads 'select Upstream (0) or Downstream (1)'. "
    "Nothing in it depends on engine speed, so the old rpm-based fuel trim name is wrong.",
    "iVar1 = iVar2 * (uint)boost_pressure_current_raw;",
    "Upstream EGR mass flow model (e2m 177F +A CHP_Upstream_EGR_Flow, 'empirical model relating lift and hot side dP to flow', lb/min x 128; chosen when rpm_fuel_trim_select_cal "
    "= e2m 177E +A C_CHP_Venturi_Vrt_Sensor_Active is 0: 0 = upstream model). Writes the e2m 177F words of throttle_fuel_trim_t_0040a3ea: reserved_12 = +12 CHP_Upstream_Corrected_Flow "
    "(3-D table of egr_valve_position and the exhaust to charge pressure ratio boost_pressure_state_t_0040a406.pressure_ratio = e2m 177D +A CHP_Pratio; tables e2m 18E3 / 18E4 / 18E5); "
    "reserved_10 = +10 CHP_Sqrt_Texhaust_R (table of exhaust_temperature, e2m 1974 / 1975); rpm_based_trim = +A CHP_Upstream_EGR_Flow = corrected flow x boost_pressure_current_raw "
    "(e2m 1A5D +0 Exhaust_Press) / sqrt(exhaust temperature), saturated at +-25600 (+-200 lb/min). Only caller cm848_selectFuelTrimMode.")

rename(
    "0x000127bc", "cm848_selectFuelTrimMode", "cm848_calculateEgrMassFlowBeforeDelay",
    "Runs cm848_calculateRpmBasedFuelTrim when rpm_fuel_trim_select_cal == 0 (upstream; e2m 177E +A) and cm848_calculateLoadBasedFuelTrim otherwise (downstream), limits the chosen flow to "
    "egr_mass_flow_estimate_minimum .. egr_mass_flow_estimate_maximum (compares 'min <= trim' then 'max < trim', e2m 177E +4 / +2 C_CHP_EGR_Flow_Min / _Max) into throttle_fuel_trim_t_0040a3ea.final_trim = "
    "e2m 177F +4 CHP_EGR_Flow_Before_Delay, forces it to 0 while egr_valve_closed_flag is set, and sets engine_fuel_fault_status = e2m 177F +18 EGR_Flow_Source (0 primary, 1 backup) from "
    "cm848_checkEngineFaultConditions / cm848_checkFuelSystemFaultFlags. The caller cm848_throttleBasedFuelCalculation writes final_trim into a circular buffer (the delay) and filters it into "
    "egr_mass_flow_delayed_filtered, hence 'before delay'. Not a fuel trim mode select.",
    "if (rpm_fuel_trim_select_cal == 0) {",
    "EGR mass flow estimate before the delay (e2m 177F +4 CHP_EGR_Flow_Before_Delay, 'EGR flow before delay is imposed', lb/min x 128; throttle_fuel_trim_t_0040a3ea.final_trim). "
    "Runs the model that rpm_fuel_trim_select_cal chooses (e2m 177E +A C_CHP_Venturi_Vrt_Sensor_Active, 'select Upstream (0) or Downstream (1) EGR Flow Model'): 0 -> "
    "cm848_calculateRpmBasedFuelTrim (upstream, rpm_based_trim) and engine_fuel_fault_status from cm848_checkEngineFaultConditions; nonzero -> cm848_calculateLoadBasedFuelTrim "
    "(downstream, load_based_trim) and engine_fuel_fault_status from cm848_checkFuelSystemFaultFlags. The flow is limited to egr_mass_flow_estimate_minimum .. egr_mass_flow_estimate_maximum "
    "(e2m 177E +4 C_CHP_EGR_Flow_Min / +2 C_CHP_EGR_Flow_Max) and forced to 0 while egr_valve_closed_flag is set. engine_fuel_fault_status is e2m 177F +18 EGR_Flow_Source "
    "(0 primary, 1 backup). Only caller cm848_throttleBasedFuelCalculation, which delays and filters the estimate into egr_mass_flow_delayed_filtered and divides it by the charge flow.")

# ---------------------------------------------------------------- volumetric efficiency, charge flow, pumping torque, in range counter
rename(
    "0x00012ad4", "cm848_boostBasedFuelModifier", "cm848_calculateVolumetricEfficiency",
    "Writes engine_volumetric_efficiency (e2m 177D +0 CHP_Volumetric_Efficiency) last, limited to fuel_demand_rpm_factor_base_cal .. fuel_demand_rpm_factor_upper_cal (e2m 177C +10 C_CHP_Veff_Min / +E C_CHP_Veff_Max: "
    "compares 'base <= value' then 'upper < value'), plus its terms in boost_pressure_state_t_0040a406: rpm_modifier (177D +4 CHP_Veff_Mach), lookup_result (+6 CHP_Veff_Sqrt), computed_value "
    "(+8 CHP_Flow_Area_Constant) and pressure_ratio (+A CHP_Pratio = boost_pressure_current_raw << 10 / map_fuel_correction_factor, limited to 0x1400 = 5.0). No fuel modifier. "
    "function_definitions.csv declares two parameters (boost_denominator, base_fueling) but the disassembly at 0x12ad4-0x12b24 overwrites r3 and r4 before any read: the function takes no inputs.",
    "engine_volumetric_efficiency = fuel_demand_rpm_factor_base_cal;",
    "Calculates the engine volumetric efficiency model (e2m 177D, C_CHP_Veff_* constants in e2m 177C): engine_volumetric_efficiency (+0 CHP_Volumetric_Efficiency, Q13) plus its terms in "
    "boost_pressure_state_t_0040a406: rpm_modifier = +4 CHP_Veff_Mach (table of engine speed x boost_rpm_scale_factor_cal = e2m 177C +6 C_CHP_Veff_Stroke), lookup_result = +6 CHP_Veff_Sqrt "
    "(table of load_input, the intake manifold temperature in degrees Rankine = e2m 177D +2), computed_value = +8 CHP_Flow_Area_Constant (bore squared over valve diameter squared x 1024, limited to 0x5000; "
    "boost_pressure_factor_cal / boost_pressure_divisor_cal = e2m 177C +A C_CHP_Veff_Bore / +C C_CHP_Veff_Valve_Diameter) and pressure_ratio = +A CHP_Pratio (boost_pressure_current_raw = e2m 1A5D +0 "
    "Exhaust_Press, x 1024 over map_fuel_correction_factor = Charge_Press, limited to 0x1400 = 5.0). The efficiency is boost_pressure_upper_limit_cal (e2m 177C +16 C_CHP_Veff_Parameter_C) minus the smaller of that "
    "and (pressure_ratio + boost_pressure_offset_cal (+14 Parameter_B)) x -boost_map_correction_factor_cal (+12 Parameter_A) x rpm_modifier x computed_value / lookup_result, limited to "
    "fuel_demand_rpm_factor_base_cal .. fuel_demand_rpm_factor_upper_cal (e2m 177C +10 C_CHP_Veff_Min / +E C_CHP_Veff_Max). It reads engine speed and the globals directly: the two parameters "
    "in function_definitions.csv are never read (the disassembly overwrites r3 and r4 first). Caller cm848_fuelDemandWithLoadCompensation.")

rename(
    "0x00012cf4", "cm848_loadBasedFuelAdjustment", "cm848_calculateChargeMassFlow",
    "Speed density charge flow: engine speed x engine_volumetric_efficiency x map_fuel_correction_factor (e2m 1A2D +0 Charge_Press) x engine_displacement_cubic_inches (e2m 177C +8 C_CHP_Engine_Displacement) / "
    "(boost_pressure_state_t_0040a406.load_input x 0xa200) >> 10, limited to boost_load_lower_limit_cal .. fuel_quantity_ema_upper_limit_cal (e2m 177C +4 C_CHP_Charge_Flow_Min / +2 C_CHP_Charge_Flow_Max: "
    "compares 'lower <= value' then 'upper < value') and filtered with exponentialMovingAverage (state boost_modifier_filter_state, coefficient e2m 177C +0 C_CHP_Charge_Flow_Fil_Cnst) "
    "into charge_mass_flow_filtered = e2m 191B +10 Charge_Flow virtual sensor (LB/MIN). load_input is the intake manifold temperature in degrees Rankine "
    "(cm848_fuelDemandWithLoadCompensation stores intake_manifold_temperature_filtered + 0x7300 = 460 x 64 = e2m 177D +2 CHP_Intake_Manifold_Tmptr_R). It is not a fuel adjustment.",
    "charge_mass_flow_filtered = (word)dVar2;",
    "Charge mass flow by the speed density equation (e2m 191B +10 Charge_Flow virtual sensor, lb/min x 128; constants e2m 177C): engine speed x engine_volumetric_efficiency x "
    "map_fuel_correction_factor (e2m 1A2D +0 Charge_Press) x engine_displacement_cubic_inches (e2m 177C +8 C_CHP_Engine_Displacement) / (boost_pressure_state_t_0040a406.load_input x 0xa200) >> 10, "
    "where load_input is the intake manifold temperature in degrees Rankine (e2m 177D +2 CHP_Intake_Manifold_Tmptr_R). The result is limited to boost_load_lower_limit_cal .. "
    "fuel_quantity_ema_upper_limit_cal (e2m 177C +4 C_CHP_Charge_Flow_Min / +2 C_CHP_Charge_Flow_Max) and filtered by exponentialMovingAverage (state boost_modifier_filter_state, coefficient "
    "boost_modifier_filter_coefficient = e2m 177C +0 C_CHP_Charge_Flow_Fil_Cnst) into charge_mass_flow_filtered, the divisor of the EGR fraction in cm848_throttleBasedFuelCalculation. "
    "Caller cm848_fuelDemandWithLoadCompensation.")

rename(
    "0x000130dc", "cm848_calculateBoostPressureOffset", "cm848_calculatePumpingTorqueAdjustment",
    "Looks up e2m 1781 +0 CHP_Nominal_Engine_Delta_P (fuel_demand_blend_lookup, grid e2m 1954 over engine speed x total_injection_quantity_for_air_handling), subtracts the engine delta "
    "pressure egr_delta_pressure_negated (e2m 1A19 +8 Engine_Delta_Press), applies the deadband fuel_demand_deadband_cal (e2m 1780 +8 C_CHP_Pump_Torque_Deadband), converts to torque with "
    "engine_displacement_cubic_inches and fuel_demand_percent_scale_cal (e2m 1780 +4 C_CHP_Pump_Torque_Multiplier) into fuel_demand_blend_intermediate (1781 +4 CHP_Pumping_Torque_No_Offset, limited to +-8000) "
    "and, plus fuel_demand_blend_offset_cal (1780 +6 C_CHP_Pump_Torque_Offset), into pumping_torque_adjustment (1781 +2 CHP_Pumping_Torque_Adj), limited to fuel_demand_min_limit_cal .. fuel_demand_blend_upper_cal "
    "(1780 +2 / +0 C_CHP_Pumping_Torque_Min / _Max: compares 'iVar1 <= upper' then 'iVar1 < min'). Not a boost pressure offset. function_definitions.csv declares two parameters "
    "(manifold_pressure, rpm) but the disassembly at 0x130dc-0x13128 overwrites r3 and r4 before any read: the function takes no inputs.",
    "pumping_torque_adjustment = (word)iVar4;",
    "Pumping torque (e2m 1781): looks up the nominal engine delta pressure of the engine speed x total_injection_quantity_for_air_handling grid (e2m 1954 C_CHP_Nominal_Delta_P_Table) into "
    "fuel_demand_blend_lookup (+0 CHP_Nominal_Engine_Delta_P), subtracts the actual engine delta pressure egr_delta_pressure_negated (e2m 1A19 +8 Engine_Delta_Press), applies the deadband "
    "fuel_demand_deadband_cal (e2m 1780 +8 C_CHP_Pump_Torque_Deadband), converts the difference to torque with engine_displacement_cubic_inches and fuel_demand_percent_scale_cal "
    "(e2m 1780 +4 C_CHP_Pump_Torque_Multiplier) and limits it to +-8000 into fuel_demand_blend_intermediate (+4 CHP_Pumping_Torque_No_Offset). The same torque plus fuel_demand_blend_offset_cal "
    "(e2m 1780 +6 C_CHP_Pump_Torque_Offset), set to 0 while total_injection_quantity_for_air_handling is below fuel_demand_load_threshold_cal (e2m 1780 +A C_CHP_Pump_Torque_Min_Fuel) and limited to "
    "fuel_demand_min_limit_cal .. fuel_demand_blend_upper_cal (e2m 1780 +2 / +0 C_CHP_Pumping_Torque_Min / _Max), is pumping_torque_adjustment (+2 CHP_Pumping_Torque_Adj), the term between net and gross torque. "
    "It reads engine speed and the globals directly: the two parameters in function_definitions.csv are never read (r3 and r4 are overwritten first). Caller cm848_periodicTaskSet_controlLoop.")

rename(
    "0x0001359c", "cm848_processBoostControlState", "cm848_updateChargePressureInRangeFaultCount",
    "Up / down counter charge_pressure_in_range_fault_count (e2m 1A2D +A Charge_Press_IR_Fault_Cnt): counts up by charge_pressure_in_range_fault_count_increment (e2m 1A2C +4) while Charge_Press_IR_Enable "
    "(boost_condition_active_flag) is set and Charge_Press_IR_Cond (boost_fuel_below_threshold_flag) is 1, saturating at charge_pressure_in_range_fault_set_threshold (+6); counts down by "
    "fuel_demand_step_decrement_cal (+2) when the condition is 0; is 0 while the monitor is disabled (bit 0x10 of governor_feature_config_flags clear or air_handling_compensation_and_diagnostic_bypass_cal nonzero). "
    "At or above the set threshold it sets fault bit 527 (fault_detected_bits_512_to_527 | 0x8000); at or below fuel_demand_step_min_threshold_cal (+0 C_Charge_Press_Fault_Clear) it clears the detected and "
    "registered bits. Fault 527 has NO P-code: ROM 0x5985a slot for fault 527 is 170 (no obd_dtc_code_table entry), so no P-code is claimed. Not a boost control state machine.",
    "fault_detected_bits_512_to_527 = fault_detected_bits_512_to_527 | 0x8000;",
    "Charge pressure in range fault counter (e2m 1A2D +A Charge_Press_IR_Fault_Cnt), run every pass by cm848_processBoostProtectionConditions after it sets Charge_Press_IR_Cond "
    "(boost_fuel_below_threshold_flag: 0 good, 1 suspect). With the monitor disabled (bit 0x10 of governor_feature_config_flags clear, or air_handling_compensation_and_diagnostic_bypass_cal nonzero) the count is 0. "
    "While Charge_Press_IR_Enable (boost_condition_active_flag, e2m 1A2D +8) is set it adds charge_pressure_in_range_fault_count_increment (e2m 1A2C +4 C_Charge_Press_Fault_Cnt_Incrt) per suspect pass, "
    "limited to charge_pressure_in_range_fault_set_threshold (+6 C_Charge_Press_Fault_Set), and subtracts fuel_demand_step_decrement_cal (+2 C_Charge_Press_Fault_Cnt_Decrt) per good pass down to 0. "
    "At or above the set threshold it sets fault bit 527 (fault_detected_bits_512_to_527 | 0x8000); at or below fuel_demand_step_min_threshold_cal (+0 C_Charge_Press_Fault_Clear) it clears the detected and "
    "registered bit. Fault 527 has no P-code (ROM 0x5985a slot 170, no obd_dtc_code_table entry).")

# ---------------------------------------------------------------- intake manifold temperature (e2m 18D9) and EGR orifice temperature (e2m 19CA)
rename(
    "0x00013d14", "cm848_calculatePressureSensorDerivative", "cm848_calculateIntakeManifoldTemperatureLeadCompensation",
    "Channel 9 is the intake manifold temperature (sensor_channel_filtered_output[9] = intake_manifold_temperature_sensor_filtered, J1939 IC1 SPN 105; e2m 1966 +6 Charge_Tmptr_Sensor at sensor_channel9_pressure_value). "
    "Writes intake_manifold_temperature_lead_term (e2m 18D9 +2 TPE_IMT_Lead_Term) = intake_manifold_temperature_lead_time_constant (+4) x (value - snapshot), limited to +-32000, and "
    "intake_manifold_temperature_after_lead (+0 TPE_IMT_After_Lead) = value + lead term limited to pressure_sensor_lower_limit_cal .. injection_timing_offset_floor_cal (e2m 18D6 +2 C_TPE_Min_IMT / +4 C_TPE_Max_IMT; "
    "compares 'iVar1 < lower' and 'iVar1 <= upper'), then stores the value as the next snapshot. Twin of the EGR orifice lead function 0x506f88 (same code on channel 108). "
    "The e2m text says 'before limits' but the clamp is inside this function.",
    "intake_manifold_temperature_lead_term = (word)iVar2;",
    "Lead compensation of the intake manifold temperature sensor lag (sensor channel 9, e2m 18D9): intake_manifold_temperature_lead_term (+2 TPE_IMT_Lead_Term) = "
    "intake_manifold_temperature_lead_time_constant (+4 TPE_IMT_Lead_Time_Constant) x (sensor_channel9_pressure_value minus its previous value sensor_channel9_pressure_snapshot), limited to +-32000; "
    "intake_manifold_temperature_after_lead (+0 TPE_IMT_After_Lead) = the sensor value plus the lead term, limited to pressure_sensor_lower_limit_cal .. injection_timing_offset_floor_cal "
    "(e2m 18D6 +2 C_TPE_Min_IMT / +4 C_TPE_Max_IMT, 1/64 degree F per count). Then it stores the sensor value as the new snapshot. Same algorithm as the EGR orifice temperature lead function "
    "(sensor_channel108_filter). Caller cm848_calculatePressureSensorFiltered.")

rename(
    "0x00013dc8", "cm848_calculatePressureSensorFiltered", "cm848_filterAndSelectIntakeManifoldTemperature",
    "Builds the intake manifold temperature (e2m 18D9 +8 Charge_Tmptr, +A Charge_Tmptr_Source, +C Charge_Tmptr_State): lead time constant from charge_mass_flow_filtered (e2m 18D7 / 18D8 tables, 0 when "
    "sensor_channel9_fault_status or air_handling_compensation_and_diagnostic_bypass_cal is nonzero or bit 0x4000 of algorithm_enable_flags_20_cal is clear), cm848_calculatePressureSensorDerivative "
    "(lead), two cascaded cm848_signedFirstOrderFilter stages (coefficient e2m 18D6 +0 C_TPE_IMT_Lag_Filter_Constant), then the source: 0 primary (the filtered value), 1 backup "
    "(fuel_demand_boost_offset_filtered = e2m 1A1B +0 Charge_Tmptr_Est), 2 default (sensor_channel9_pressure_default_value = e2m 1966 +1E Charge_Tmptr_Default). The source is 2 only when a sensor fault bit is set "
    "AND bit 0x80 of the state is set (injection_enable_mode_byte = e2m 1A1B +4 Charge_Tmptr_EStat); faults 19 / 20 = P0113 / P0112 and 354 / 358 = P0111 (fault -> ROM 0x5985a slot -> obd_dtc_code_table). "
    "It both filters and selects (like 0x507028 + 0x50716c for the EGR orifice), so 'filter' alone is too narrow, and it is not a pressure sensor.",
    "intake_manifold_temperature_filtered = fuel_demand_boost_offset_filtered;",
    "Intake manifold temperature (e2m 18D9 +8 Charge_Tmptr, 1/64 degree F; +A Charge_Tmptr_Source; +C Charge_Tmptr_State): looks up the lead time constant from charge_mass_flow_filtered "
    "(cold_start_pressure_scale_working from fuel_quantity_ema_axis_cal / fuel_quantity_ema_output_cal = e2m 18D7 C_TPE_IMT_Lead_Mass_Flow_Axis / 18D8 C_TPE_IMT_Lead_Time_Cnst_Table; 0 when "
    "sensor_channel9_fault_status or air_handling_compensation_and_diagnostic_bypass_cal is nonzero or bit 0x4000 of algorithm_enable_flags_20_cal is clear), runs "
    "cm848_calculatePressureSensorDerivative (the lead compensation) and filters intake_manifold_temperature_after_lead with two cascaded cm848_signedFirstOrderFilter stages "
    "(pressure_correction_first_filter / pressure_correction_second_filter, coefficient e2m 18D6 +0 C_TPE_IMT_Lag_Filter_Constant), but only with the compensation on (sensor status 0, bypass cal 0 and mask 0x4000 of "
    "algorithm_enable_flags_20_cal set); otherwise intake_manifold_temperature_after_lead passes through unfiltered. It builds fuel_demand_phase_status_flags (Charge_Tmptr_State) from "
    "injection_enable_mode_byte (e2m 1A1B +4 Charge_Tmptr_EStat, the quality of the charge temperature estimate: cm848_processBoostProtectionMode sets 0x80 when the compressor inlet temperature source is default "
    "or the estimate is disabled, 0x40 when it is backup), the sensor channel 9 fault status and the gated sensor faults "
    "(fault bits 19 / 20 = P0113 / P0112, 354 / 358 = P0111, through ROM 0x5985a and obd_dtc_code_table), and selects the source into fuel_demand_phase_state (Charge_Tmptr_Source): "
    "0 primary = the filtered value, 1 backup = fuel_demand_boost_offset_filtered (e2m 1A1B +0 Charge_Tmptr_Est), 2 default = sensor_channel9_pressure_default_value (e2m 1966 +1E Charge_Tmptr_Default; "
    "only when a sensor fault is set and the estimate is unusable). The selected value is intake_manifold_temperature_filtered (Charge_Tmptr). Caller cm848_phase_group_b_processing.")

rename(
    "0x00017f50", "cm848_calculateFuelFlowWithMode", "cm848_calculateEgrDeltaPressures",
    "Writes the e2m 1A19 delta pressures: egr_orifice_delta_pressure (+0 EGR_Orifice_Delta_Press), egr_delta_pressure (+4 EGR_Valve_Delta_Press), egr_delta_pressure_negated (+8 Engine_Delta_Press) and their sources "
    "boost_fuel_mode_state (+2), egr_delta_pressure_source (+6), fuel_demand_enable_state_cached (+A). egr_flow_cold_side_algorithm_select == 0 (e2m 177E +8 C_CHP_Downstream_Delta_P_Active 'select hot side (0) or "
    "cold side (1)') copies the delta pressure sensor output to the valve delta pressure; nonzero computes (boost_pressure_current_raw - boost_pressure_baseline_cal) - map_fuel_correction_factor "
    "(Exhaust_Press minus Charge_Press) and uses the sensor output as the orifice delta pressure. Not a fuel flow; this selector is separate from rpm_fuel_trim_select_cal (177E +A).",
    "(boost_pressure_current_raw - boost_pressure_baseline_cal) - map_fuel_correction_factor;",
    "EGR delta pressures (e2m 1A19). egr_flow_cold_side_algorithm_select (e2m 177E +8 C_CHP_Downstream_Delta_P_Active: 0 = hot side, nonzero = cold side algorithm; not the model select "
    "rpm_fuel_trim_select_cal) = 0: egr_delta_pressure (+4 EGR_Valve_Delta_Press) is the sensor output egr_delta_pressure_sensor_output (channel 105 after the autozero), egr_orifice_delta_pressure "
    "(+0 EGR_Orifice_Delta_Press) is 0 with its source boost_fuel_mode_state (+2) = 2 (default), and the engine delta pressure source fuel_demand_enable_state_cached (+A Engine_Delta_Press_Source) is "
    "egr_delta_pressure_sensor_source. Nonzero: egr_delta_pressure = (boost_pressure_current_raw (e2m 1A5D +0 Exhaust_Press) - boost_pressure_baseline_cal) - map_fuel_correction_factor (Charge_Press), "
    "egr_orifice_delta_pressure is the sensor output (boost_fuel_mode_state = its source), and the computed source is 2 when the exhaust and charge pressure sources (fuel_demand_droop_state, "
    "fuel_demand_mode_index) are both 2, 0 when both are 0, else 1. Then egr_delta_pressure_negated = -egr_delta_pressure (+8 Engine_Delta_Press) and egr_delta_pressure_source (+6 "
    "EGR_Valve_Delta_Press_Source) = the engine delta pressure source. Caller cm848_phase_group_a_processing.")

rename(
    "0x00506f88", "sensor_channel108_filter", "cm848_calculateEgrOrificeTemperatureLeadCompensation",
    "Channel 108 is the EGR orifice temperature sensor (e2m 1966 +14 EGR_Orifice_Tmptr_Sensor at sensor_channel108_value). Writes egr_orifice_temperature_lead_term (e2m 19CA +8 INM_EGRT_Lead_Term) = "
    "egr_orifice_temperature_lead_time_constant (+A) x (value - previous value DAT_003fbcfa), limited to +-32000, and egr_orifice_temperature_after_lead (+6 INM_EGRT_After_Lead) = value + lead term limited to "
    "throttle_trim_predictor_output_min .. egr_orifice_temperature_estimate_maximum_limit (e2m 1A2E +4 C_INM_EGRT_Min / +2 C_INM_EGRT_Max; compares 'sum < maximum' and 'sum <= minimum'), then stores the value as "
    "the new previous value. Same algorithm as the intake manifold temperature lead function 0x13d14. Not a generic channel filter.",
    "egr_orifice_temperature_lead_term = (word)iVar3;",
    "Lead compensation of the EGR orifice temperature sensor lag (sensor channel 108 = e2m 1966 +14 EGR_Orifice_Tmptr_Sensor; e2m 19CA): egr_orifice_temperature_lead_term "
    "(+8 INM_EGRT_Lead_Term) = egr_orifice_temperature_lead_time_constant (+A INM_EGRT_Lead_Time_Constant) x (sensor_channel108_value minus its previous value, the word at 0x3fbcfa), limited to "
    "+-32000; egr_orifice_temperature_after_lead (+6 INM_EGRT_After_Lead) = the sensor value plus the lead term, limited to throttle_trim_predictor_output_min .. "
    "egr_orifice_temperature_estimate_maximum_limit (e2m 1A2E +4 C_INM_EGRT_Min / +2 C_INM_EGRT_Max, 1/64 degree F per count). Then it stores the sensor value as the new previous value. Same "
    "algorithm as the intake manifold temperature lead function (cm848_calculatePressureSensorDerivative). Caller sensor_throttleTrim_ema_faultProcess.")

rename(
    "0x00507028", "sensor_throttleTrim_ema_faultProcess", "cm848_filterEgrOrificeTemperature",
    "Sets egr_orifice_temperature_state (e2m 19CA +4 EGR_Orifice_Tmptr_State) = sensor_channel108_fault_status (e2m 1963 +12 EGR_Orifice_Tmptr_Status), or 0 when egr_flow_cold_side_algorithm_select == 0 "
    "(hot side algorithm, e2m 177E +8; the orifice temperature is unused); looks up the lead time constant from egr_mass_flow_delayed_filtered (e2m 1A2F / 1A30 C_INM_EGRT_Lead_* tables) into "
    "throttle_trim_predictor_gain_lookup (0 unless the sensor status is 0, the diagnostic bypass cal is 0 and bit 0x8000 of algorithm_enable_flags_20_cal is set); runs sensor_channel108_filter and, "
    "with the compensation on, two exponentialMovingAverage stages (states 0x3fbd00 / 0x3fbd08) into the filtered value at 0x3fbcf6. Twin of the filter half of cm848_calculatePressureSensorFiltered; "
    "the selection is the separate 0x50716c. Nothing about throttle trim.",
    "egr_orifice_temperature_state = sensor_channel108_fault_status;",
    "Filters the EGR orifice temperature (e2m 19CA, sensor channel 108): sets egr_orifice_temperature_state (+4 EGR_Orifice_Tmptr_State) to sensor_channel108_fault_status "
    "(e2m 1963 +12 EGR_Orifice_Tmptr_Status), or to 0 when egr_flow_cold_side_algorithm_select (e2m 177E +8, 0 = hot side algorithm) is 0 because the orifice temperature is unused there. "
    "Looks up the lead time constant from egr_mass_flow_delayed_filtered (tables e2m 1A2F C_INM_EGRT_Lead_EGR_Flow_Axis / 1A30 C_INM_EGRT_Lead_Time_Cnst_Table) into throttle_trim_predictor_gain_lookup "
    "and uses it as egr_orifice_temperature_lead_time_constant unless the sensor status is nonzero, air_handling_compensation_and_diagnostic_bypass_cal is nonzero or bit 0x8000 of "
    "algorithm_enable_flags_20_cal is clear (then 0). Runs sensor_channel108_filter (the lead compensation), then two cascaded exponentialMovingAverage filters (states at 0x3fbd00 / 0x3fbd08) "
    "over egr_orifice_temperature_after_lead into the filtered temperature at 0x3fbcf6, the primary value that sensor_throttleTrim_inputSelect selects; with the compensation off it stores "
    "egr_orifice_temperature_after_lead unfiltered. Caller cm848_phase_groupB_calculation_2.")

rename(
    "0x0050716c", "sensor_throttleTrim_inputSelect", "cm848_selectEgrOrificeTemperature",
    "Selects egr_orifice_temperature (e2m 19CA +0 EGR_Orifice_Tmptr) and egr_orifice_temperature_source (+2): when mask 0x02 of egr_orifice_temperature_state (sensor status 2, confirmed) is clear it takes the filtered "
    "value at 0x3fbcf6 and source 0 (primary), otherwise sensor_channel108_default_value (e2m 1966 +2C EGR_Orifice_Tmptr_Default) and source 2 (default). Called after cm848_filterEgrOrificeTemperature by "
    "cm848_phase_groupB_calculation_2. Nothing about throttle trim.",
    "egr_orifice_temperature = sensor_channel108_default_value;",
    "Selects the EGR orifice temperature (e2m 19CA +0 EGR_Orifice_Tmptr, 1/64 degree F) and its source (+2 EGR_Orifice_Tmptr_Source: 0 primary, 2 default): when mask 0x02 of "
    "egr_orifice_temperature_state (the sensor channel 108 fault status 2, confirmed) is clear it takes the filtered temperature at 0x3fbcf6 and source 0, otherwise "
    "sensor_channel108_default_value (e2m 1966 +2C EGR_Orifice_Tmptr_Default) and source 2. Called after sensor_throttleTrim_ema_faultProcess by cm848_phase_groupB_calculation_2.")

# ---------------------------------------------------------------- accelerator pedal, 4-D fueling, throttle 100
rename(
    "0x000173a8", "cm848_fuelDemandOverrideHandler", "cm848_learnAcceleratorPedalAutozero",
    "Learns Throttle_Min (e2m 1047 +A, fuel_demand_control_t.throttle_based) and writes accelerator_pedal_autozero_cal = candidate + fuel_demand_cal_offset (e2m 101A +0 Auto_Zero = Throttle_Min + 1048 +10 "
    "Auto_Zero_Offset); it overrides nothing. Gate: switch_input_state_bits[0] mask 0x80 set (switch 7 accelerator at idle) and [1] mask 0x01 clear (switch 8 off idle), fuel_demand_override_counter not above ROM "
    "0x5c2a6 (e2m 1048 +18 TPS_AZ_Time_Limit) and governor_speed_output_snapshot (accepted updates) not above accelerator_pedal_autozero_update_count_limit (1048 +1A TPS_AZ_Update_Limit). Candidate = lowest "
    "accelerator_pedal_sensor_counts below throttle_based; rate_delta (1047 +8 Current_Confidence_Counter) loads accelerator_pedal_minimum_learning_confidence_count_limit (1048 +8), counts down while the pedal is "
    "within accelerator_pedal_minimum_learning_confidence_band (1048 +A) of the candidate and the candidate is accepted at 0. Final compare 'throttle_fuel_demand_threshold_cal <= throttle_based' "
    "(1048 +6 Highest_Throttle_Min) restores throttle_based = autozero - offset.",
    "accelerator_pedal_autozero_cal = throttle_fuel_demand_tracked + fuel_demand_cal_offset;",
    "Learns the accelerator pedal minimum Throttle_Min (e2m 1047 +A, fuel_demand_control_t.throttle_based) and the autozero (e2m 101A +0 Auto_Zero, accelerator_pedal_autozero_cal, EEPROM 0x928). "
    "Learning runs only while switch 7 (accelerator at idle, switch_input_state_bits[0] mask 0x80) is on and switch 8 (off idle, [1] mask 0x01) is off, fuel_demand_override_counter is not above "
    "the time limit (e2m 1048 +18 TPS_AZ_Time_Limit, ROM 0x5c2a6) and the accepted update count governor_speed_output_snapshot is not above accelerator_pedal_autozero_update_count_limit "
    "(e2m 1048 +1A TPS_AZ_Update_Limit); otherwise throttle_fuel_demand_tracked follows throttle_based and the confidence counter fuel_demand_control_t.rate_delta (e2m 1047 +8 Current_Confidence_Counter) is 0. "
    "While learning it tracks the lowest accelerator_pedal_sensor_counts: a reading below throttle_based becomes the candidate and loads the counter with "
    "accelerator_pedal_minimum_learning_confidence_count_limit (e2m 1048 +8 Maximum_Confidence_Count); readings within accelerator_pedal_minimum_learning_confidence_band (+A Confidence_Band) of "
    "the candidate count it down and at 0 the candidate becomes throttle_based, accelerator_pedal_autozero_cal = candidate + fuel_demand_cal_offset (+10 Auto_Zero_Offset) is stored and the update count is "
    "incremented; readings above the band count it back up, and reaching the count limit drops the candidate. When throttle_based is at or above throttle_fuel_demand_threshold_cal "
    "(+6 Highest_Throttle_Min) and an update was accepted, it is set back to accelerator_pedal_autozero_cal - fuel_demand_cal_offset. Caller cm848_fuelDemandCoordinator.")

rename(
    "0x0001e830", "cm848_updateEngineTimingCompensation", "cm848_updateFourDimensionalFueling",
    "Only body: if (engine_operating_mode == FUELING_STATE_DUAL_AXIS_FUEL_DEMAND_TABLE) { four_dimensional_fueling = cm848_calculateDualAxisFuelLimit(); engine_operating_mode_fuel_demand = four_dimensional_fueling; }. "
    "FUELING_STATE 8 is e2m label FOUR_D, four_dimensional_fueling is e2m 1053 +0 Four_D_Fueling '[_5DFL] fueling value calculated from the 4D fueling tables', and engine_operating_mode_fuel_demand is e2m 1050 +0 "
    "User_Fueling (the writer of mode 8, sth 0x1e85c). No timing or compensation is involved. Vocabulary note: the callee and the enum member say 'dual axis' while the e2m and wave 13 say 'four dimensional'.",
    "four_dimensional_fueling = cm848_calculateDualAxisFuelLimit();",
    "User fueling state FOUR_D: while engine_operating_mode is FUELING_STATE_DUAL_AXIS_FUEL_DEMAND_TABLE (e2m label FOUR_D, code 8) it stores the result of "
    "cm848_calculateDualAxisFuelLimit in four_dimensional_fueling (e2m 1053 +0 Four_D_Fueling, '[_5DFL] fueling value calculated from the 4D fueling tables') and copies it to "
    "engine_operating_mode_fuel_demand (e2m 1050 +0 User_Fueling). Does nothing in the other modes. Caller cm848_periodicTaskSet_sensorProcessing.")

rename(
    "0x0001eae8", "cm848_calculateFuelDemandChangeRate", "cm848_filterCommandedThrottle",
    "Filters fuel_demand_control_t.calculated (e2m 1047 +0 Commanded_Throttle) with exponentialMovingAverage (state fuel_mode_filter_state) into commanded_throttle_filtered (e2m 1053 +8 Filtered_Commanded_Throttle), "
    "using commanded_throttle_filter_coefficient (+6 Active_Throttle_Filter_Constant), which follows fuel_mode_ema_output = table(|calculated - commanded_throttle_filtered|) (fuel_mode_ema_axis_cal / "
    "fuel_mode_ema_output_cal). fuel_limit_mode_flags are the 1053 +A flags: mask 0x01 Throttle_Decrease_Flag set when the error is negative, mask 0x02 Throttle_Transient_Flag set when the candidate constant drops and "
    "cleared when the error is back within DAT_0005c30e. No rate of change of fuel demand is calculated.",
    "commanded_throttle_filtered = (word)dVar2;",
    "Filters the commanded throttle for the 4-D fueling (e2m 1053): the error fuel_demand_control_t.calculated (e2m 1047 +0 Commanded_Throttle) minus commanded_throttle_filtered goes, as an absolute value, "
    "through the table fuel_mode_ema_axis_cal / fuel_mode_ema_output_cal into fuel_mode_ema_output, the candidate filter constant. fuel_limit_mode_flags holds the e2m 1053 +A flags (mask 0x01 "
    "Throttle_Decrease_Flag, mask 0x02 Throttle_Transient_Flag): a drop of the candidate starts a transient (mask 0x01 also set when the error is negative, i.e. the throttle is decreasing) and it ends "
    "when the error comes back to the ROM threshold DAT_0005c30e (at or below it while increasing, above its negative while decreasing). commanded_throttle_filter_coefficient (+6 "
    "Active_Throttle_Filter_Constant) follows the candidate, but during a transient it only follows a lower one. exponentialMovingAverage (state fuel_mode_filter_state, whose coefficient is that word) "
    "then filters the commanded throttle into commanded_throttle_filtered (+8 Filtered_Commanded_Throttle), the throttle input of the 4-D fueling tables. Caller hpcr_periodicTaskSet_fuelFinal.")

rename(
    "0x0001f17c", "cm848_calculateFuelDemandWithTrim", "cm848_calculateThrottle100Fuelings",
    "Stores the five e2m 105A fueling values at 100 % throttle (400): throttle_100_fueling (+0 Throttle_100_Fueling) = cm848_calculateMaximumFuelCurve(engine speed, 400) + correction, "
    "throttle_100_fueling_low_horsepower_curve (+2 Tau_0_Throttle_100_Fueling), engine_speed_limit_ramped_maximum_fuel_quantity (+4 Throttle_100_Fuel_At_HSG_Bef_Droop_Speed) and "
    "engine_speed_limit_reference_maximum_fuel_quantity (+6 Throttle_100_Fuel_At_HSG_Bkpt_Speed) while algorithm_enable_flags_18_cal.programmable_power_enable == 0, and "
    "throttle_100_fueling_without_programmable_power (+8 Throttle_100_Fueling_No_PP) always. No trim is applied; the bin-1 lead names only the first of the five. "
    "Real caller is cm848_periodicTaskSet_controlLoop (the other 'caller' in the bin is a plate comment that mentions the lookup caches).",
    "throttle_100_fueling = sVar1 + wVar3;",
    "Throttle 100 percent fuelings (e2m 105A; throttle 400 = 100 percent). With algorithm_enable_flags_18_cal.programmable_power_enable = 0 it stores throttle_100_fueling (+0 Throttle_100_Fueling) = "
    "cm848_calculateMaximumFuelCurve at the engine speed and throttle 400, throttle_100_fueling_low_horsepower_curve (+2 Tau_0_Throttle_100_Fueling, the fuel_demand_rpm_threshold_cal / "
    "fuel_demand_rpm_limit_*_cal grid at throttle 400), engine_speed_limit_ramped_maximum_fuel_quantity (+4 Throttle_100_Fuel_At_HSG_Bef_Droop_Speed) and "
    "engine_speed_limit_reference_maximum_fuel_quantity (+6 Throttle_100_Fuel_At_HSG_Bkpt_Speed), the last two from cm848_lookupChiMaximumFuelAtSpeed at engine_speed_limit_ramped / "
    "engine_speed_limit_reference; each gets fuel_demand_offset_correction added when mask 0x1000 of algorithm_enable_flags_41_cal (reserved_bit_12) is set, the first two are raised to at least fuel_demand_minimum and the low "
    "horsepower one is limited to the valid range. throttle_100_fueling_without_programmable_power (+8 Throttle_100_Fueling_No_PP) is always calculated like throttle_100_fueling, with "
    "thermal_fuel_limit_factor (the alpha, e2m 1053 +2 Fuel_Interp_Factor) forced to 0 while bit 0x10 of algorithm_enable_flags_12_cal (ESP enable) is set. Caller cm848_periodicTaskSet_controlLoop.")

# ---------------------------------------------------------------- no load fuel, torques, ambient, exhaust, water vapor
rename(
    "0x0050dba8", "governor_computeSpeedTargetWithThermalCorrection", "cm848_calculateNoLoadFuel",
    "Writes e2m 109C: friction_fuel_adjustment_for_coolant_temperature (+4 Coolant_Fuel_Adjustment, table of coolant_temp), friction_fuel_adjustment_for_air_conditioning_clutch (+8 AC_Fuel_Adjustment, table of engine "
    "speed, 0 unless bit 0x40 of air_conditioning_clutch_request_byte is set and fault_detected_bits_368_to_383 masks 0x08 / 0x10 are clear), friction_fuel_adjustment_for_radiator_fan (+A Fan_Fuel_Adjustment, grid of "
    "radiator_fan_speed and engine speed), friction_fueling (+6, table of engine speed) and fuel_demand_base_offset = the sum of the four = e2m 109C +0 No_Load_Fuel '[NLFL] fuel required to overcome friction' "
    "(0x40aeec). cm848_calculateEngineOutputTorque reads fuel_demand_base_offset as the friction fuel. No speed target or thermal governor correction exists in it.",
    "friction_fueling + friction_fuel_adjustment_for_coolant_temperature +",
    "No load fuel (e2m 109C +0 No_Load_Fuel, '[NLFL] fuel required to overcome friction', fuel_demand_base_offset at 0x40aeec) and its terms (e2m 109C): "
    "friction_fuel_adjustment_for_coolant_temperature (+4 Coolant_Fuel_Adjustment, table of the coolant temperature), friction_fuel_adjustment_for_air_conditioning_clutch (+8 AC_Fuel_Adjustment, "
    "table of engine speed; 0 unless bit 0x40 of air_conditioning_clutch_request_byte is set and the A/C fault bits fault_detected_bits_368_to_383 0x8 / 0x10 are clear), "
    "friction_fuel_adjustment_for_radiator_fan (+A Fan_Fuel_Adjustment, grid of radiator_fan_speed and engine speed) and friction_fueling (+6 Friction_Fueling, table of engine speed). "
    "fuel_demand_base_offset is the sum of the four. Caller cm848_periodicTaskGroup31_calibration13.")

rename(
    "0x0050eaa8", "cm848_applyProtectionRpmCorrectionFilter", "cm848_calculateFrictionNoLoadAndNetMachineTorque",
    "Writes the six e2m 175C torque words from combustion_torque_by_fuel_quantity (engine speed x fuel quantity map): friction_torque_adjustment_for_coolant_temperature (+8) = torque at "
    "friction_fuel_adjustment_for_coolant_temperature, engine_zero_fuel_base_friction_torque (+2 Zero_Fuel_Torque) = torque at friction_fueling, engine_friction_torque (+0 Friction_Torque) = first minus "
    "second, engine_no_load_torque (+4 No_Load_Torque) = engine_friction_torque + pumping_torque_adjustment, net_combustion_torque_copy (+A Net_Engine_Torque) = net_combustion_torque and net_machine_torque "
    "(+6 Net_Machine_Torque) = that copy minus the torque at (A/C + fan + low_speed_governor_alternator_load_fuel adjustments, not below 0). Real caller is cm848_periodicTaskSet_sensorProcessing only "
    "(cm848_calculateNetCombustionTorque merely mentions it in a plate comment). No protection or rpm correction filter.",
    "engine_no_load_torque = engine_friction_torque + pumping_torque_adjustment;",
    "Engine torque terms (e2m 175C), all from the engine speed x fuel quantity torque map combustion_torque_by_fuel_quantity (the map of cm848_calculateNetCombustionTorque): "
    "friction_torque_adjustment_for_coolant_temperature (+8 Coolant_Torque_Adjustment) = the torque at friction_fuel_adjustment_for_coolant_temperature; engine_zero_fuel_base_friction_torque "
    "(+2 Zero_Fuel_Torque) = the torque at friction_fueling; engine_friction_torque (+0 Friction_Torque) = the first minus the second; engine_no_load_torque (+4 No_Load_Torque) = "
    "engine_friction_torque + pumping_torque_adjustment; net_combustion_torque_copy (+A Net_Engine_Torque) = a copy of net_combustion_torque; net_machine_torque (+6 Net_Machine_Torque) = that copy "
    "minus the torque at friction_fuel_adjustment_for_air_conditioning_clutch + friction_fuel_adjustment_for_radiator_fan + low_speed_governor_alternator_load_fuel (not below 0), the torque left after the "
    "A/C, fan and alternator loads. The fuels are the e2m 109C words written by governor_computeSpeedTargetWithThermalCorrection. Caller cm848_periodicTaskSet_sensorProcessing.")

rename(
    "0x00502b6c", "hpcr_fuelFinal_exponentialAverage", "cm848_calculateAmbientAndCompressorInletConditions",
    "Writes every e2m 1921 record: barometric_altitude_feet (+0 Altitude), barometric_pressure_reference (+2 Ambient_Air_Press), ambient_air_temperature_reference (+6 Ambient_Air_Tmptr), compressor_inlet_pressure "
    "(+A Compressor_Inlet_Press), boost_fuel_pressure_offset_lookup (+E Compressor_Inlet_Pressure_Drop), compressor_inlet_temperature_rise (+10 Compressor_Inlet_Tmptr_Rise), ambient_relative_humidity (+14) and "
    "the three sources (+4 / +8 / +C, DAT_0040a1a6 = +12 Altitude_Source). Ambient temperature = ambient_air_temperature_selected - the rise, filtered, unless ambient_air_temperature_user_override_enable_cal "
    "(override value) or source default (default value). With barometric_pressure_sensor_senses_ambient_air_flag_cal clear the reference is the pressure plus the drop, set it is the pressure and the inlet "
    "pressure is minus the drop. Nothing here is a fuel final exponential average; it also uses the ambient (not a fuel) pressure. Caller hpcr_periodicTaskSet_fuelFinal.",
    "ambient_air_temperature_reference = wVar3;",
    "Ambient and compressor inlet conditions (e2m 1921). Filters the fresh air flow (boost_pressure_state_t_0040a406.fresh_air_mass_flow_filtered, e2m 177B +0 Fresh_Air_Flow) and looks up "
    "compressor_inlet_temperature_rise (+10 Compressor_Inlet_Tmptr_Rise) in a table of it and vehicle_speed_copy. ambient_air_temperature_reference (+6 Ambient_Air_Tmptr) = ambient_air_temperature_selected "
    "minus that rise, filtered by cm848_signedFirstOrderFilter, or ambient_air_temperature_override_value when ambient_air_temperature_user_override_enable_cal is set, or "
    "ambient_air_temperature_default_value when its source fuel_demand_timing_mode_state (+8 Ambient_Air_Tmptr_Source: the larger of fuel_demand_state_b = e2m 1A0C +2 Compressor_Inlet_Tmptr_Source and the "
    "fresh air flow source, 0 primary / 1 backup / 2 default) is 2. "
    "Looks up the inlet pressure drop boost_fuel_pressure_offset_lookup (+E Compressor_Inlet_Pressure_Drop) from the filtered fresh air flow, then barometric_pressure_reference (+2 Ambient_Air_Press) and "
    "compressor_inlet_pressure (+A Compressor_Inlet_Press) from barometric_pressure_selected: with barometric_pressure_sensor_senses_ambient_air_flag_cal clear the reference is the pressure plus the drop and "
    "the inlet pressure is the pressure; set, the reference is the pressure and the inlet pressure is the pressure minus the drop (at least 1). The pressure sources go to boost_pressure_fuel_mode_state "
    "(+4 Ambient_Air_Press_Source), fuel_demand_mode_state (+C Compressor_Inlet_Press_Source) and DAT_0040a1a6 (+12 Altitude_Source). Then barometric_altitude_feet (+0 Altitude) from "
    "barometric_pressure_reference (limited to 0x75e) through the altitude table and ambient_relative_humidity (+14 Ambient_Relative_Humidity) from a grid of engine speed and "
    "injection_quantity_combustion_reference. Caller hpcr_periodicTaskSet_fuelFinal.")

rename(
    "0x00506e28", "cm848_auxiliaryControl_exponentialAverage", "cm848_estimateExhaustTemperature",
    "Writes e2m 17A1: exhaust_temperature_model_invalid_flag (+6 TPE_Invalid_Model = 1 while engine speed < 8 (1 rpm) or charge_fuel_ratio < 128), exhaust_temperature_model_delta (+0, from "
    "cm848_calculateCombustionTemperatureRise) and exhaust_temperature_rise_over_intake_manifold_temperature (+2 TPE_Delta_Exhaust_Tmptr, 0 when invalid), exhaust_temperature (+8 Exhaust_Tmptr) = "
    "intake_manifold_temperature_filtered x 2 / 64 + the rise, not below 0, exhaust_metal_temperature (+C Exhaust_Metal_Tmptr) = exponentialMovingAverage of it and exhaust_temperature_source (+A: 0 only when "
    "the charge flow, charge pressure and intake manifold temperature sources are 0 and the model is valid, else 1). Verb follows cm848_estimateCompressorOutletTemperature. Real caller is "
    "cm848_periodicTaskSet_auxiliaryControl (cm848_calculateCombustionTemperatureRise only mentions it in its plate comment).",
    "exhaust_metal_temperature = (word)dVar1;",
    "Exhaust temperature estimate (e2m 17A1). The model is invalid (exhaust_temperature_model_invalid_flag, +6 TPE_Invalid_Model = 1, 'protect against divide by zero') while the engine speed is below 8 "
    "(1 rpm) or charge_fuel_ratio is below 128. Otherwise it calls cm848_calculateCombustionTemperatureRise for exhaust_temperature_model_delta (+0 Temperature_Delta); "
    "exhaust_temperature_rise_over_intake_manifold_temperature (+2 TPE_Delta_Exhaust_Tmptr) is that delta, or 0 when invalid. exhaust_temperature (+8 Exhaust_Tmptr, 0.5 degree F per count) = "
    "intake_manifold_temperature_filtered x 2 / 64 plus the rise, not below 0, and its copy is exhaust_temperature_virtual_sensor_copy (e2m 191B +14). exhaust_metal_temperature "
    "(+C Exhaust_Metal_Tmptr) = exponentialMovingAverage of it (state at 0x3fbcea). exhaust_temperature_source (+A Exhaust_Tmptr_Source) is 0 (primary) only when the charge flow, charge pressure and "
    "intake manifold temperature sources (boost_pressure_state_t_0040a406.reserved_0a, fuel_demand_mode_index, fuel_demand_phase_state) are all 0 and the model is valid, else 1 (backup). "
    "Caller cm848_periodicTaskSet_auxiliaryControl.")

rename(
    "0x0050e7f4", "cm848_blendBoostAndThrottleFuelDemand", "cm848_calculateWaterVaporAndSaturationTemperatures",
    "Writes e2m 1982: ambient_saturation_vapor_pressure (+E TPE_Saturation_Vapor_Press, table of ambient_air_temperature_reference), ambient_water_vapor_partial_pressure (+10 = that x ambient_relative_humidity >> 10), "
    "inlet_water_vapor_fraction (+4 = that over barometric_pressure_reference, limited to 4096), charge_water_vapor_fraction (+0) and exhaust_water_vapor_fraction (+2) with the combustion water from fuel_air_equivalence_ratio, "
    "charge_water_vapor_partial_pressure_times_4 (+6 Charge_H2O_PP) and exhaust_water_vapor_partial_pressure_times_4 (+8 Exhaust_H2O_PP) = fraction x map_fuel_correction_factor, charge_saturation_temperature and "
    "exhaust_saturation_temperature = table of those partial pressures (the dew points) and the source flag fuel_demand_mode_active_flag (+A Charge_Saturation_Tmptr_Source). It blends no boost or throttle fuel demand; "
    "the bin-6 lead 'WaterVaporFractions' leaves out the partial pressures and saturation temperatures it also computes. Caller main_loop.",
    "charge_water_vapor_fraction = (word)uVar2;",
    "Water vapor model of the intake charge and the exhaust (e2m 1982, the input of the condensation protection): ambient_saturation_vapor_pressure (+E TPE_Saturation_Vapor_Press) from "
    "ambient_air_temperature_reference through water_saturation_vapor_pressure_by_temperature_axis / _values; ambient_water_vapor_partial_pressure (+10 TPE_Vapor_Partial_Press) = it x "
    "ambient_relative_humidity (e2m 1921 +14) >> 10; inlet_water_vapor_fraction (+4 TPE_Inlet_H2O_Mole_Fraction) = that over barometric_pressure_reference, limited to 4096. "
    "charge_water_vapor_fraction (+0 TPE_Charge_H2O_Mole_Fraction) and exhaust_water_vapor_fraction (+2 TPE_Exhaust_H2O_Mole_Fraction) add the water that burning makes (from fuel_air_equivalence_ratio) to the "
    "inlet fraction; the charge one carries the part that the EGR returns, weighted by the larger of egr_fraction_combustion_reference_at_base_chi and egr_fraction_actual. "
    "charge_water_vapor_partial_pressure_times_4 (+6 Charge_H2O_PP) and exhaust_water_vapor_partial_pressure_times_4 (+8 Exhaust_H2O_PP) multiply the fractions by map_fuel_correction_factor (the charge pressure), "
    "and charge_saturation_temperature / exhaust_saturation_temperature (the dew points) look those up in fuel_demand_compensation_target_by_pressure_axis / _values. The source flag "
    "fuel_demand_mode_active_flag (+A Charge_Saturation_Tmptr_Source, copied to 0x40af74) is 0 only when the charge pressure, ambient temperature and ambient pressure sources are all 0, else 1. Caller main_loop.")


# ================================================================ validation
def read_bin():
    return json.load(open(BINS))["functions"]


def function_spans():
    text = open(OUT_DIR + "cm848_rom.ghidra.cpp").read().split("\n")
    starts = [(i, m.group(1)) for i, line in enumerate(text) if (m := re.match(r"^// Function: (\S+) @", line))]
    spans = {}
    for k, (i, name) in enumerate(starts):
        spans[name] = text[i:(starts[k + 1][0] if k + 1 < len(starts) else len(text))]
    return spans


def words(name):
    out = []
    for p in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg", "mil"}


def check():
    problems = []
    items = read_bin()
    spans = function_spans()
    cpp_tokens = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", open(OUT_DIR + "cm848_rom.ghidra.cpp").read()))
    csv_names = set()
    for path in glob.glob(OUT_DIR + "*.csv"):
        for line in open(path, errors="replace"):
            for tok in re.findall(r"[A-Za-z_][A-Za-z0-9_]*", line):
                csv_names.add(tok)
    hpp = ""
    for path in glob.glob(OUT_DIR + "*.hpp"):
        hpp += open(path, errors="replace").read()
    hpp_tokens = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", hpp))
    other = set()
    for path in glob.glob("/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/result_W14_*.jsonl"):
        if path.endswith("result_W14_functions1.jsonl"):
            continue
        for line in open(path):
            line = line.strip()
            if line:
                r = json.loads(line)
                if r.get("new"):
                    other.add(r["new"])
    news = {}
    if len(items) != len(R):
        problems.append(f"bin has {len(items)} items, result has {len(R)}")
    for x in items:
        a = x["address"]
        r = R.get(a)
        if not r:
            problems.append(f"{a}: missing")
            continue
        if r["old"] != x["current"]:
            problems.append(f"{a}: old {r['old']} != bin {x['current']}")
        if r["old"] not in spans:
            problems.append(f"{a}: old name not in .cpp")
        else:
            body = "\n".join(spans[r["old"]])
            lines = spans[r["old"]]
            q = r["code_quote"]
            if len(q) < 20 and q.strip() not in [l.strip() for l in lines]:
                problems.append(f"{a}: quote shorter than 20 chars and not a whole line")
            if not any(q in l for l in lines):
                problems.append(f"{a}: quote not in one physical line: {q}")
            # the quote is also a substring of the body
            if q not in body:
                problems.append(f"{a}: quote not in body: {q}")
        new = r["new"]
        if new in news:
            problems.append(f"{a}: new name {new} also used by {news[new]}")
        news[new] = a
        if new in other:
            problems.append(f"{a}: new name {new} used by another W14 result file")
        for label, pool in (("CSV", csv_names), (".cpp", cpp_tokens), (".hpp", hpp_tokens)):
            if new in pool:
                problems.append(f"{a}: new name {new} already in {label}")
        if not re.fullmatch(r"((cm848|cm550|mpc555|mc68k|hpcr|vp44)_)?[a-z][A-Za-z0-9]*", new):
            problems.append(f"{a}: name format {new}")
        bad = sorted(set(words(new)) & BANNED)
        if bad:
            problems.append(f"{a}: banned words {bad} in {new}")
        if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
            problems.append(f"{a}: hex-looking part in {new}")
        if "(was" in r["plate_comment"] or "(was" in r["evidence"]:
            problems.append(f"{a}: '(was' in text")
        for field in ("evidence", "code_quote", "plate_comment"):
            if "\n" in r[field] or not r[field].strip():
                problems.append(f"{a}: bad {field}")
        if not r["new"].startswith("cm848_"):
            problems.append(f"{a}: prefix of {new}")
    return problems, items


if __name__ == "__main__":
    problems, items = check()
    for p in problems:
        print("PROBLEM", p)
    lines = [json.dumps(R[x["address"]], ensure_ascii=True) for x in items if x["address"] in R]
    path = FINAL if ("--write" in sys.argv and not problems) else DRAFT
    with open(path, "w") as f:
        f.write("\n".join(lines) + "\n")
    print(f"wrote {len(lines)} lines to {path}; problems: {len(problems)}")
    for x in items:
        r = R[x["address"]]
        print(f"{x['address']}  {x['current']:52s} -> {r['new']}   (plate {len(r['plate_comment'])} chars)")
