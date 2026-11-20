"""Items 0-22 of bin globals2 (bin order). Each entry: dict(addr, new, quote, evidence, comment, [type_note], [old_comment_wrong], [cal_note])."""

A = []


def add(**kw):
    A.append(kw)


# ---- 0..2 alpha
add(addr="0x003fa0d2", new="alpha_fuel_rate_filter_state",
    quote="((uint)fuel_mass_flow_raw,&cold_start_intake_temperature_filter_state);",
    evidence="cm848_calculateSensorEma passes fuel_mass_flow_raw through exponentialMovingAverage with this record into alpha_filtered_fuel_delivery_rate (e2m 104A +14 Filtered_Fuel_Delivery_Rate) and compares it with the alpha reset / threshold fuel rates; cm848_initFuelPressureVariables points its coefficient at flash 0x5be66 (e2m 104B +C Alpha_Fuel_Rate_Filter_Constant); hpcr_calculateFuelTrimOutput zeroes its accumulator while the engine is stopped or cranking; no intake temperature is involved. Pair for 0x5be66: alpha_fuel_rate_filter_coefficient.",
    comment="EMA filter record (ema_filter_state_t) of the alpha fuel rate: cm848_calculateSensorEma filters fuel_mass_flow_raw (LB/HR) through it into alpha_filtered_fuel_delivery_rate (e2m 104A +14 Filtered_Fuel_Delivery_Rate). Its coefficient points at the flash word 0x5be66 = e2m 104B +C Alpha_Fuel_Rate_Filter_Constant [APFLFTTC] (set in cm848_initFuelPressureVariables). No e2m record at this address.")

add(addr="0x003fa0da", new="alpha_low_speed_governor_timer_active_flag",
    quote="else if ((cold_start_timer_a_active_flag == 1) && (cold_start_timer_a != 0)) {",
    evidence="cm848_checkPressureFuelDelayA: while alpha_low_speed_governor_state_detected_flag is 1 it loads the timer at 0x40a17e (e2m 104A +16 Alpha_LSG_Timer, 'time since fueling state has left LSG state') with low_speed_governor_alpha_timeout and sets this flag to 1; the timer counts down while flag == 1 and timer != 0, else the flag clears and the function returns 1; hpcr_calculateFuelTrimOutput sets it while the engine is stopped or cranking; no cold start is involved.",
    comment="Timer-running flag of the alpha low speed governor timer (e2m 104A +16 Alpha_LSG_Timer [APLSTR], 0x40a17e): cm848_checkPressureFuelDelayA sets it while it reloads the timer with low_speed_governor_alpha_timeout, counts the timer down while it is 1 and clears it at 0 (the function then returns 1, alpha may go to one). No e2m record at this address.")

add(addr="0x003fa0dc", new="alpha_air_fuel_control_timer_active_flag",
    quote="else if ((cold_start_timer_b_active_flag == 1) && (cold_start_timer_b != 0)) {",
    evidence="cm848_checkPressureFuelDelayB: while alpha_air_fuel_control_state_detected_flag or alpha_low_speed_governor_state_detected_flag is 1 it loads the timer at 0x40a180 (e2m 104A +18 Alpha_AFC_Timer, 'time since fueling state is not AFC or LSG') with air_fuel_control_alpha_timeout and sets this flag to 1; the timer counts down while flag == 1 and timer != 0, else the flag clears and the function returns 1; no cold start is involved.",
    comment="Timer-running flag of the alpha air fuel control timer (e2m 104A +18 Alpha_AFC_Timer [APAFTR], 0x40a180): cm848_checkPressureFuelDelayB sets it while it reloads the timer with air_fuel_control_alpha_timeout, counts the timer down while it is 1 and clears it at 0 (the function then returns 1). No e2m record at this address.")

# ---- 3, 4 fueling arbitration (no timing in them)
add(addr="0x003fa86c", new="total_fueling_selected",
    quote="total_fueling = fuel_timing_target_arbitrated;",
    evidence="cm848_selectFinalFueling: the word starts as injection_quantity_combustion_command, is replaced by engine_overspeed_fueling / engine_brake_fueling / crank_fuel / the fuel override value per engine_state, is clamped to fuel_demand_minimum..fuel_demand_maximum (the clamp stores back into the same word, line 'fuel_timing_target_arbitrated = wVar1;') and then total_fueling = it; total_fueling is e2m 120C +A Total_Fueling (mm3); no timing is involved.",
    comment="Working copy of total_fueling (e2m 120C +A Total_Fueling, 0x40a33a) in cm848_selectFinalFueling: starts as injection_quantity_combustion_command, is replaced by the engine state source (engine_overspeed_fueling, engine_brake_fueling, crank_fuel or the fuel override value), is clamped to fuel_demand_minimum..fuel_demand_maximum, then copied to total_fueling. A fueling quantity, not a timing.")

add(addr="0x003fa870", new="total_fueling_previous_pass",
    quote="fuel_timing_arbitration_snapshot = total_fueling;",
    evidence="cm848_selectFinalFueling stores total_fueling into it as its last statement, after 'fuel_timing_arb_diag_snapshot = fuel_timing_arbitration_snapshot' has read the previous value (shutdown / fault snapshot), so it holds total_fueling of the pass before; xref_addr: 1 read / 1 write, both in cm848_selectFinalFueling; it is a fueling quantity, not a timing.",
    comment="total_fueling of the previous pass: cm848_selectFinalFueling stores total_fueling into it as its last statement, after the shutdown and excess injection fault snapshot (0x3feaa2) has read the old value. A fueling quantity, not a timing. No e2m record at this address.")

# ---- 5..7 commanded throttle filter
add(addr="0x003fa880", new="commanded_throttle_filter_coefficient_lookup_result",
    quote="commanded_throttle_filter_coefficient = fuel_mode_ema_output;",
    evidence="cm848_calculateFuelDemandChangeRate: fuel_mode_ema_output = lookupTableInterpolation(&fuel_mode_ema_state, |fuel_demand_control_t_0040a57a.calculated - commanded_throttle_filtered|, fuel_mode_ema_axis_cal, fuel_mode_ema_output_cal, 0); commanded_throttle_filter_coefficient (e2m 1053 +6 Active_Throttle_Filter_Constant) takes it unless the transient flag (mask 2 of the e2m 1053 +A word) holds a smaller one; cm848_initFuelDemandTracking presets 0xffff; wave 13 bin 3 report: the fuel_mode_ema_* rows are the throttle filter.",
    comment="Throttle filter constant looked up from the throttle error |fuel_demand_control_t_0040a57a.calculated - commanded_throttle_filtered|: cm848_calculateFuelDemandChangeRate copies it into commanded_throttle_filter_coefficient (e2m 1053 +6 Active_Throttle_Filter_Constant) unless the throttle transient flag (e2m 1053 +A) holds a smaller value. 65535 after cm848_initFuelDemandTracking. No e2m record.")

add(addr="0x003fa882", new="commanded_throttle_filter_coefficient_cached_axis_offset",
    quote="(&fuel_mode_ema_state,input,fuel_mode_ema_axis_cal,fuel_mode_ema_output_cal,0);",
    evidence="first argument (cached axis offset, 2 x segment index) of the lookupTableInterpolation call in cm848_calculateFuelDemandChangeRate, preset to 2 by cm848_initFuelDemandTracking; the same <lookup>_cached_axis_offset convention as the other lookup cache words; the filter it serves is the commanded throttle filter (e2m 1053).",
    comment="Lookup cache word (last axis segment offset, 2 x index) of the throttle filter constant lookup that produces commanded_throttle_filter_coefficient_lookup_result: first argument of lookupTableInterpolation in cm848_calculateFuelDemandChangeRate, preset to 2 by cm848_initFuelDemandTracking. No e2m record at this address.")

add(addr="0x003fa884", new="commanded_throttle_filter_state",
    quote="((uint)fuel_demand_control_t_0040a57a.calculated,&fuel_mode_filter_state);",
    evidence="cm848_calculateFuelDemandChangeRate: exponentialMovingAverage((uint)fuel_demand_control_t_0040a57a.calculated,&fuel_mode_filter_state) -> commanded_throttle_filtered (e2m 1053 +8 Filtered_Commanded_Throttle); cm848_initFuelDemandTracking sets .coefficient = &commanded_throttle_filter_coefficient (e2m 1053 +6) and clears .accumulator; an unsigned EMA record, so _filter_state.",
    comment="EMA filter record (ema_filter_state_t) of the filtered commanded throttle: cm848_calculateFuelDemandChangeRate filters fuel_demand_control.calculated through it into commanded_throttle_filtered (e2m 1053 +8 Filtered_Commanded_Throttle). Its coefficient points at commanded_throttle_filter_coefficient (e2m 1053 +6 Active_Throttle_Filter_Constant). No e2m record at this address.")

# ---- 8, 9 throttle 100 speed points request bit
add(addr="0x003fa8ae", new="throttle_100_speed_points_request_bit",
    quote="protection_mode_request_bit = (word)(1 << (throttle_100_priority_bit_index & 0x3f));",
    evidence="cm848_updateProtectionDiagnostics builds it once as 1 << throttle_100_priority_bit_index (e2m 12BD +A Throttle_100_Priority; its flash word at 0x5c33e is 7, so 128, which is what the flags word 0x40a732 reads), ORs it into j1939_pgn65251_speed_points_request_flags (e2m 12BB +0 Active_Speed_Points_State) while programmable_power_enable is 0 and compares it with the higher request bits; wave 13 bin 1 report: same wrong 'protection' prefix as 0x40a732.",
    comment="Request bit of the throttle 100 request in j1939_pgn65251_speed_points_request_flags (e2m 12BB +0 Active_Speed_Points_State): 1 << throttle_100_priority_bit_index (e2m 12BD +A Throttle_100_Priority; 7, so 128), built once by cm848_updateProtectionDiagnostics, which ORs it into the flags while programmable_power_enable is 0. No e2m record at this address.")

add(addr="0x003fa8b0", new="throttle_100_speed_points_request_bit_initialized_flag",
    quote="protection_mode_request_initialized_flag = 1;",
    evidence="cm848_updateProtectionDiagnostics tests it at entry (== 0) to build protection_mode_request_bit once and then sets it to 1; xref_addr: 1 read / 1 write, both in that function.",
    comment="Set to 1 once cm848_updateProtectionDiagnostics has built throttle_100_speed_points_request_bit; the function tests it at entry so the bit is built a single time. No e2m record at this address.")

# ---- 10 signed filter of the LSG alternator load
add(addr="0x003faf56", new="low_speed_governor_alternator_load_filter",
    quote="governor_speed_filter.coefficient = &governor_speed_filter_coefficient;",
    evidence="cm848_runLowSpeedGovernor: low_speed_governor_alternator_load_fuel = cm848_signedFirstOrderFilter((governor_speed_filter_input_scale_cal x (alternator_field_duty_target - governor_speed_filter_fuel_offset_cal)) >> 14, &governor_speed_filter) with e2m 1064 +2A LSG_EVR_Gain / +2C LSG_EVR_Offset; cm848_initSpeedProtectionParameters sets .coefficient to the word at 0x4070e4 (e2m 1064 +2E Alternator_Load_Filter_Coefficient); a cm848_signedFirstOrderFilter record is named <x>_filter (stage 6a, like egr_mass_flow_delayed_filter). Pair for 0x4070e4: low_speed_governor_alternator_load_filter_coefficient.",
    comment="cm848_signedFirstOrderFilter record (ema_filter_state_t) of the low speed governor alternator load: cm848_runLowSpeedGovernor filters the alternator field duty converted to fuel (e2m 1064 +2A LSG_EVR_Gain, +2C LSG_EVR_Offset) through it into low_speed_governor_alternator_load_fuel. Its coefficient is the word at 0x4070e4 = e2m 1064 +2E Alternator_Load_Filter_Coefficient.")

# ---- 11..13 EEPROM mirror rows
add(addr="0x003fea22", new="fault_registered_bits_592_to_607",
    quote="j1939_tsc1_mode_shadow = j1939_tsc1_mode_shadow & 0xfffb;",
    evidence="cm848_checkSensorDeviationFlags clears it with the same masks (0xfffb / 0xfff7 / 0xffef / 0xffe3) as fault_detected_bits_592_to_607 (faults 594 / 595 / 596, e2m 1036 +4A System_Error_Status_37): it is word 37 of the registered array 0x3fe9d8 + 2 x 37 = 0x3fea22, the registered twin; nothing in it is J1939 TSC1. REGION NOTE: the row is in the EEPROM mirror, but all 49 fault_detected / fault_registered / fault_previous_pass bit rows there, including its twin 0x3fe9be (applied in wave 13), carry no _cal; the family name is kept and the strict region rule would add _cal to all 49.",
    comment="Word 37 of the fault-registered array 0x3fe9d8 (0x3fe9d8 + 2 x 37), the registered twin of fault_detected_bits_592_to_607 (e2m 1036 +4A System_Error_Status_37): cm848_checkSensorDeviationFlags clears its masks 4 / 8 / 0x10 together with the detected bits (faults 594 / 595 / 596). Same convention as fault_registered_bits_512_to_527.",
    cal_note="EEPROM mirror row without _cal on purpose: the 49 fault_detected / fault_registered / fault_previous_pass bit rows in the mirror, including the twin 0x3fe9be named in wave 13, carry none (their comments call it runtime state); the strict region rule would give fault_registered_bits_592_to_607_cal, and then all 49 need it.")

add(addr="0x003feaa2", new="total_fueling_before_shutdown_or_excess_injection_fault_cal",
    quote="fuel_timing_arb_diag_snapshot = fuel_timing_arbitration_snapshot;",
    evidence="cm848_selectFinalFueling: when final_fueling_state is SHUTDOWN or fault_detected_bits_384_to_399 & 0x10 (fault 388, set by fuel_quantity_demand_monitor: the excess injection monitor, P0606) and governor_diag_entry_latch_flag == 0 it copies fuel_timing_arbitration_snapshot (total_fueling of the previous pass) here and the previous final_fueling_state into 0x3feaa0, then latches; cm848_clearFuelDemandFlag re-arms the latch at start-up; xref: 1 write, 0 reads; 0x3feaa2 - 0x3fd482 = EEPROM 0x1620, inside the mirror, so _cal; no timing is involved.",
    comment="Freeze frame (EEPROM mirror, EEPROM 0x1620): cm848_selectFinalFueling copies total_fueling_previous_pass here on the first pass where final_fueling_state is SHUTDOWN or the excess injection fault (fault_detected_bits_384_to_399 mask 0x10, fault 388) is set, once until cm848_clearFuelDemandFlag re-arms it. The previous final_fueling_state goes to the twin 0x3feaa0. Not read by the application.")

add(addr="0x003fedbc", new="recent_fault_dtc_codes_cal",
    quote="protection_event_spn_history[0] = obd_dtc_code_table[param_1];",
    evidence="cm848_latchNewlyActiveFault shifts the older entries down and stores obd_dtc_code_table[param_1] (BCD P-code of the fault slot) at [0]; cm848_sciCommand50ReportProtectionEventDtcs reports them as OBD DTC codes, not SPNs; e2m 128A +0 Recent_J2012_Codes_Table (16 B, 'J2012 codes for the eight most recent faults', DGROJCTB) resolves here; 0x3fedbc - 0x3fd482 = EEPROM 0x193a, inside the mirror, so _cal.",
    comment="e2m 128A +0 Recent_J2012_Codes_Table [DGROJCTB] (HEX, 16 B) 'J2012 codes for the eight most recent faults', EEPROM 0x193a: word[8] of BCD P-codes (obd_dtc_code_table entries), newest first: cm848_latchNewlyActiveFault shifts the entries and stores the new one at [0]; cm848_sciCommand50ReportProtectionEventDtcs reports them. Retyped word -> word[8] 2026-11-18.",
    old_comment_wrong=True)

# ---- 14..22 blocks 1053, 10C7, 1104, 177D/E, 1A2D
add(addr="0x0040a889", new="four_dimensional_fueling_interpolation_factor",
    quote="thermal_fuel_limit_factor = combustion_alpha_input;",
    evidence="hpcr_calculateFuelTrimOutput stores combustion_alpha_input (alpha, capped at 0x4000) into it unless bit 0x10 of its flag word holds it; cm848_calculateMaximumFuelCurve (and cm848_calculateDualAxisFuelLimit, cm848_calculateTorqueManagementFuelTableLimit, cm848_processSpeedSensorCompensation) blend two grid results by it / 0x4000 ('if (thermal_fuel_limit_factor < 0x4000)'); cm848_initFuelDemandTracking presets 0x4000; e2m 1053 +2 Fuel_Interp_Factor 'Interpolation factor for 4-D fueling, max fueling calculation' resolves here (width 2 B = row, 0 in the dump); nothing thermal.",
    comment="e2m 1053 +2 Fuel_Interp_Factor [FLINML] 'Interpolation factor for 4-D fueling, max fueling calculation' (UNITLESS, 1/16384 per count; 0 in the dump): hpcr_calculateFuelTrimOutput sets it to combustion_alpha_input; cm848_calculateMaximumFuelCurve and the other fueling grid code blend two grid results by it (0 = first grid, 0x4000 = second); cm848_initFuelDemandTracking presets 0x4000. Not thermal.")

add(addr="0x0040c04c", new="power_down_refresh_enable",
    quote="sensor_validation_result = 1;",
    evidence="e2m 10C7 +2 Powerdown_Refresh_Enable [RRPWEA] (HEX, 1 in the dump) resolves here; xref_addr: 0 reads, 2 writes: uds_session_state_init sets 1 next to the RAM refresh enable (e2m 10C7 +0 RAM_Refresh_Enable, 0x40c04a) and cm848_commitEepromMirrorToEeprom sets 0 when its mirror commit (J1939 diagnostic service 21) completes; the enable polarity rests on the e2m text and the initial value 1, nothing in the application reads it; no sensor validation is involved.",
    comment="e2m 10C7 +2 Powerdown_Refresh_Enable [RRPWEA] 'When this flag is FALSE RAM refresh is disabled for part of FLASH parameter blocks' (HEX; 1 in the dump): uds_session_state_init sets it to 1 next to the RAM refresh enable (e2m 10C7 +0, 0x40c04a); cm848_commitEepromMirrorToEeprom clears it after the EEPROM mirror commit. No application code reads it.")

add(addr="0x0005c34e", new="j1939_engine_speed_at_point_4",
    quote="j1939_torque_curve_speed_at_point_4 = protection_threshold_scale_cal;",
    evidence="cm848_updateProtectionStateMachine (the torque derate cases that jump to LAB_0002105c / LAB_000210c8) loads j1939_torque_curve_fueling_at_point_4 = j1939_derated_fueling_at_point_4 and j1939_torque_curve_speed_at_point_4 = protection_threshold_scale_cal; e2m 1104 +6 Jcomm_Engine_Speed_at_Point_4 [JC39P4RP] (RPM 0.125; 20800 in the dump = 2600 rpm) resolves here; the 12BD +4 twin at 0x5c338 holds the same value; sibling of j1939_engine_speed_at_point_3 (1104 +4) and j1939_derated_fueling_at_point_4 (1104 +E); flash constant, no _cal.",
    comment="e2m 1104 +6 Jcomm_Engine_Speed_at_Point_4 [JC39P4RP] 'RPM at pt 4 of engine config map' (RPM, 0.125 per count; 20800 in the dump = 2600 rpm): flash constant that cm848_updateProtectionStateMachine copies into j1939_torque_curve_speed_at_point_4 together with j1939_derated_fueling_at_point_4 in the torque derate cases. Twin value at e2m 12BD +4 (0x5c338).")

add(addr="0x0005c350", new="j1939_engine_speed_at_point_5",
    quote="j1939_torque_curve_speed_at_point_5 = protection_threshold_base_cal;",
    evidence="cm848_updateProtectionStateMachine (the torque derate case that jumps to LAB_0002105c) and cm848_processJ1939RxMessage (when its in_r4 argument is 0) load j1939_torque_curve_speed_at_point_5 = protection_threshold_base_cal; e2m 1104 +8 Jcomm_Engine_Speed_at_Point_5 [JC39P5RP] (RPM 0.125; 22400 in the dump = 2800 rpm) resolves here; the 12BD +6 twin at 0x5c33a holds the same value; sibling of j1939_derated_fueling_at_point_5 (1104 +10); flash constant, no _cal.",
    comment="e2m 1104 +8 Jcomm_Engine_Speed_at_Point_5 [JC39P5RP] 'RPM at pt 5 of engine config map' (RPM, 0.125 per count; 22400 in the dump = 2800 rpm): flash constant that cm848_updateProtectionStateMachine and cm848_processJ1939RxMessage copy into j1939_torque_curve_speed_at_point_5 for the derated curve. Twin value at e2m 12BD +6 (0x5c33a).")

add(addr="0x0040a406", new="charge_flow_estimate_terms",
    quote="boost_pressure_state_t_0040a406.load_input = intake_manifold_temperature_filtered + 0x7300;",
    evidence="16-byte record of charge flow model terms: load_input = intake_manifold_temperature_filtered + 0x7300 (1/64 F + 460 F = Rankine, e2m 177D +2 CHP_Intake_Manifold_Tmptr_R, 32042 in the dump = 500.7 R); rpm_modifier / lookup_result / computed_value / pressure_ratio = Veff Mach / Veff Sqrt / flow area constant / pressure ratio (177D +4..+A, written by cm848_boostBasedFuelModifier); reserved_0a = 177D +C Charge_Flow_Source (set 0 or 1); fresh_air_mass_flow_filtered / reserved_0e = 177B +0 Fresh_Air_Flow / +2 Fresh_Air_Flow_Source; nothing in it is a boost pressure state.",
    comment="Record of the charge flow model terms (8 words): e2m 177D +2 CHP_Intake_Manifold_Tmptr_R (degrees Rankine = intake_manifold_temperature_filtered + 460 F; 32042 in the dump), +4 CHP_Veff_Mach, +6 CHP_Veff_Sqrt, +8 CHP_Flow_Area_Constant, +A CHP_Pratio, +C Charge_Flow_Source, then e2m 177B +0 Fresh_Air_Flow and +2 Fresh_Air_Flow_Source. Written by cm848_boostBasedFuelModifier.",
    type_note="Struct instance: renaming the row alone leaves the type name boost_pressure_state_t, the field names and the seven dotted label rows 0x40a408..0x40a414 (boost_pressure_state_t_0040a406.<field>) stale. Hold for the main session: rename the type to charge_flow_estimate_terms_t and the fields load_input -> intake_manifold_temperature_rankine (177D +2), rpm_modifier -> volumetric_efficiency_mach (+4), lookup_result -> volumetric_efficiency_sqrt (+6), computed_value -> flow_area_constant (+8), pressure_ratio (+A, keep), reserved_0a -> charge_flow_source (+C), fresh_air_mass_flow_filtered -> fresh_air_flow_filtered (177B +0), reserved_0e -> fresh_air_flow_source (177B +2); drop or rename the dotted rows with the prefix.")

add(addr="0x004002e8", new="oxygen_flow_delay_volume_fraction",
    quote="uVar1 = (uint)throttle_conversion_scale_cal * 0x78 >> 10;",
    evidence="cm848_throttleBasedFuelCalculation: if (throttle_conversion_scale_cal < 0x2001) uVar1 = it x 0x78 >> 10 else 0xffff, then throttle_fuel_trim_t_0040a3ea.throttle_conversion = uVar1 x 1000 / (engine_volumetric_efficiency x current_rpm >> 13), which is e2m 177F +14 CHP_O2_Flow_Delay ('delay between exhaust manifold O2 and the intake valve'); e2m 177E +6 C_CHP_Volume_Fraction 'Volume fraction used to calculate flow delay' resolves here; 9552 in the dump is above its 0..1 range (8192 = 1.0), so the 0xffff branch is taken; it is no throttle conversion.",
    comment="e2m 177E +6 C_CHP_Volume_Fraction 'Volume fraction used to calculate flow delay' (UNITLESS, 1/8192 per count, range 0..1; 9552 in the dump = 1.166): cm848_throttleBasedFuelCalculation turns it into the oxygen flow delay (e2m 177F +14 CHP_O2_Flow_Delay): at most 8192 gives fraction x 120 / 1024 x 1000 / (volumetric efficiency x rpm), above it the delay is 0xffff.")

add(addr="0x004002ec", new="egr_flow_downstream_model_select",
    quote="if (rpm_fuel_trim_select_cal == 0) {",
    evidence="cm848_selectFuelTrimMode: == 0 runs cm848_calculateRpmBasedFuelTrim (e2m 177F +A CHP_Upstream_EGR_Flow: lift and hot side dP, uses egr_valve_position) into rpm_based_trim, else cm848_calculateLoadBasedFuelTrim (e2m 177F +8 CHP_Downstream_EGR_Flow: fixed orifice) into load_based_trim; e2m 177E +A C_CHP_Venturi_Vrt_Sensor_Active 'Select Upstream (0) or Downstream (1) EGR Flow Model' (1 in the dump = downstream) resolves here; sibling of egr_flow_cold_side_algorithm_select (+8); one read.",
    comment="e2m 177E +A C_CHP_Venturi_Vrt_Sensor_Active 'Select Upstream (0) or Downstream (1) EGR Flow Model' (UNITLESS 0..1; 1 in the dump): cm848_selectFuelTrimMode runs the upstream flow model (valve lift and hot side delta pressure, cm848_calculateRpmBasedFuelTrim) when it is 0, else the downstream orifice model (cm848_calculateLoadBasedFuelTrim). Sibling of egr_flow_cold_side_algorithm_select (+8).")

add(addr="0x004002ee", new="egr_flow_delay_fraction",
    quote="(uint)throttle_load_scale_factor_cal) / 0x7fff;",
    evidence="cm848_throttleBasedFuelCalculation: throttle_fuel_trim_t_0040a3ea.load_adjusted (= e2m 177F +6 CHP_EGR_Flow_Delay) = throttle_conversion (the oxygen flow delay, 177F +14) x throttle_load_scale_factor_cal / 0x7fff; e2m 177E +C C_CHP_EGR_Flow_Delay_Fraction 'Fraction of CHP_O2_Flow_Delay for flow between downstream venturi and int. man.' (1/32768 per count) resolves here, 0 in the dump; one read.",
    comment="e2m 177E +C C_CHP_EGR_Flow_Delay_Fraction 'Fraction of CHP_O2_Flow_Delay for flow between downstream venturi and int. man.' (UNITLESS, 1/32768 per count; 0 in the dump): cm848_throttleBasedFuelCalculation multiplies the oxygen flow delay by it / 0x7fff to get the EGR flow delay (e2m 177F +6 CHP_EGR_Flow_Delay).")

add(addr="0x0040a42e", new="charge_pressure",
    quote="map_fuel_correction_factor = boost_pressure_sensor_value;",
    evidence="cm848_selectLoadNormalizer writes it: boost_pressure_sensor_value (mode 0), boost_pressure_target (mode 1 branch) or boost_pressure_sensor_default_value (mode 2; fuel_demand_mode_index = e2m 1A2D +2 Charge_Press_Source); the readers use it as a pressure (cm848_calculateLoadBasedFuelTrim divides by it, cm848_loadBasedFuelAdjustment multiplies it with engine_displacement_cubic_inches, cm848_estimateTurbochargerSpeed, the condensation models); e2m 1A2D +0 Charge_Press (IN_HG, 0.0159 per count; 1700 in the dump = 27.04 inHg) resolves here; chose charge_pressure (e2m base name, as in charge_pressure_in_range_fault_count) over a _selected form like barometric_pressure_selected; globals4 holds the +2..+8 siblings.",
    comment="e2m 1A2D +0 Charge_Press 'Value of Charge Pressure' (IN_HG, 0.0159 inHg per count; 1700 in the dump = 27.04 inHg): the intake manifold pressure the charge flow, EGR and turbocharger speed code use. cm848_selectLoadNormalizer picks the sensor value, boost_pressure_target or the sensor default (source word e2m 1A2D +2 Charge_Press_Source, 0x40a430).",
    )
