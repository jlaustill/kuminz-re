"""Build result_W13_bin6.jsonl from the bin (address / old name / e2m record come from the bin, the verdicts, names,
evidence and comments are written here)."""
import json

BIN = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/bins/bin6.json"
OUT = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/result_W13_bin6.jsonl"
bin_ = json.load(open(BIN))
PID = "address from the ECU's parameter ID table"

entries = {}


def rename(i, record, new, evidence, comment):
    r = bin_[i]
    assert r["record"] == record, (i, r["record"], record)
    entries[i] = {"kind": "global", "verdict": "confirmed", "address": r["address"], "old": r["label_in_cpp"],
                  "new": new, "evidence": evidence, "comment": comment}


def keep(i, record, note):
    r = bin_[i]
    assert r["record"] == record, (i, r["record"], record)
    entries[i] = {"kind": "global", "verdict": "keep", "address": r["address"], "old": r["label_in_cpp"],
                  "new": r["label_in_cpp"], "e2m_note": note}


def drift(i, record, evidence):
    r = bin_[i]
    assert r["record"] == record, (i, r["record"], record)
    entries[i] = {"kind": "global", "verdict": "drift", "address": r["address"], "old": r["label_in_cpp"],
                  "evidence": evidence}


# ---------------------------------------------------------------------------------------------------------- 0033
rename(0, "Collector_Start_Address", "data_collector_start_address",
       "e2m 0033 +8 Collector_Start_Address (logical beginning of the data collector buffer): diag_dm1Buffer_circularFill "
       "advances / wraps it when the write pointer catches it, j1939_dm1_diagnosticMessage_send advances it past the bytes "
       "it sends, hpcr_exception_process sets it to &DAT_0040c28a; the diag_dm1_buffer_* words are the e2m data collector "
       "(data_collector_schedule_cal, _multiple_cal, _trigger_*_cal, data_collector_table_address), not J1939 DM1",
       f"e2m 0033 +8 Collector_Start_Address 'Logical beginning address of the data collector buffer' (HEX, 4 bytes; {PID}): "
       "the read / tail pointer of the data collector ring buffer, the oldest byte still held (storage &DAT_0040c28a, start "
       "pointer 0x40c270, end pointer 0x40c274, write pointer 0x40c280). diag_dm1Buffer_circularFill advances it and wraps "
       "it to the start pointer when the write pointer catches it, j1939_dm1_diagnosticMessage_send advances it past the "
       "bytes it sends, hpcr_exception_process initializes it. The diag_dm1_buffer_* family is the data collector "
       "(data_collector_*_cal settings, e2m 0033 / 0037 / 003B), not DM1.")

# ---------------------------------------------------------------------------------------------------------- 1008
keep(1, "Accumulated_TPU_Pulses",
     "e2m 1008 +10 Accumulated_TPU_Pulses 'Running total of VSS pulses accumulated due to TPU interrupts'")

# ---------------------------------------------------------------------------------------------------------- 104A alpha
rename(2, "Alpha_Base", "alpha_base",
       "e2m 104A +2 Alpha_Base: timingProtectionFlagsOrchestrator ramps it 0..0x4000 (alpha 1.0) by alpha_ramp_rate_* "
       "while any of the five alpha conditions is set and zeroes it otherwise; hpcr_calculateFuelTrimOutput copies it to "
       "combustion_alpha_input when governor_startup_state is 0; the old name says fuel demand, it is the base alpha",
       f"e2m 104A +2 Alpha_Base '[APAPBA] Result of AFC, LSG, On Governor, and Fuel Rate alpha comparison' (UNITLESS, "
       f"1/16384 per count, 0..1; {PID}): the base alpha ramp. timingProtectionFlagsOrchestrator sets it to 0 while none "
       "of the five alpha conditions (low speed governor, air fuel control, fuel rate, on governor, low ambient air "
       "pressure) is set, otherwise adds alpha_ramp_rate_below_threshold / alpha_ramp_rate_at_or_above_threshold each pass "
       "up to 0x4000 (1.0); hpcr_calculateFuelTrimOutput outputs it as combustion_alpha_input when governor_startup_state "
       "is 0 (base) and zeroes it with the engine stopped, cranking or jump starting. Not a fuel demand.")

rename(3, "Alpha_Fuel_Rate", "alpha_fuel_rate_result",
       "e2m 104A +8 Alpha_Fuel_Rate [APFLRTAP]: cm848_calculateSensorEma returns 1 above alpha_threshold_fuel_rate, 0 at or "
       "below alpha_reset_fuel_rate, else this word (hysteresis); timingProtectionFlagsOrchestrator stores it and ORs it "
       "into the alpha ramp condition when bit 0x1000 of governor_fault_status_flags is set; the old name says cold start",
       f"e2m 104A +8 Alpha_Fuel_Rate '[APFLRTAP] result of Fuel Rate algorithm' (UNITLESS, 0..65535; {PID}): the fuel "
       "rate alpha condition, 1 while the filtered fuel rate alpha_filtered_fuel_delivery_rate is above "
       "alpha_threshold_fuel_rate, 0 at or below alpha_reset_fuel_rate, otherwise the previous value (hysteresis). "
       "cm848_calculateSensorEma computes it, timingProtectionFlagsOrchestrator stores it when bit 0x1000 of "
       "governor_fault_status_flags is set and ORs it into the alpha ramp condition (alpha_base). Not a cold start value.")

rename(4, "Fueling_AFC_State_Detected", "alpha_air_fuel_control_state_detected_flag",
       "e2m 104A +E Fueling_AFC_State_Detected [FLAFSTFG]: cm848_selectFinalFueling sets it when final_fueling_state is "
       "AIR_FUEL_CONTROL_DERATE or COMBUSTION_OXYGEN_LIMIT, cm848_checkPressureFuelDelayB reads it, "
       "timingProtectionFlagsOrchestrator clears it every alpha pass; the old name says cold start pressure",
       f"e2m 104A +E Fueling_AFC_State_Detected '[FLAFSTFG] semaphore used to latch AFC events that occur between alpha "
       f"executions' (UNITLESS, 0..65535; {PID}): set to 1 by cm848_selectFinalFueling when final_fueling_state is "
       "AIR_FUEL_CONTROL_DERATE or COMBUSTION_OXYGEN_LIMIT (the air fuel control limits), read by the air fuel control "
       "alpha check cm848_checkPressureFuelDelayB and cleared every alpha execution at the end of "
       "timingProtectionFlagsOrchestrator. Not a cold start flag.")

rename(5, "Fueling_LSG_State_Detected", "alpha_low_speed_governor_state_detected_flag",
       "e2m 104A +10 Fueling_LSG_State_Detected [FSLSSTFG]: cm848_selectFinalFueling sets it on the pass final_fueling_state "
       "enters LOW_SPEED_GOVERNOR, cm848_checkPressureFuelDelayA / B and cm848_calculateSensorEma read it, "
       "timingProtectionFlagsOrchestrator and cm848_initFuelPressureVariables clear it; the old name says cold start",
       f"e2m 104A +10 Fueling_LSG_State_Detected '[FSLSSTFG] semaphore used to latch LSG events that occur between alpha "
       f"executions' (UNITLESS, 0..65535; {PID}): set to 1 by cm848_selectFinalFueling on the pass final_fueling_state "
       "enters LOW_SPEED_GOVERNOR (the previous state was not), read by the low speed governor alpha check "
       "cm848_checkPressureFuelDelayA, the air fuel control check cm848_checkPressureFuelDelayB and the fuel rate filter "
       "restart in cm848_calculateSensorEma; cleared every alpha execution at the end of "
       "timingProtectionFlagsOrchestrator and by cm848_initFuelPressureVariables. Not a cold start flag.")

rename(6, "Filtered_Fuel_Delivery_Rate", "alpha_filtered_fuel_delivery_rate",
       "e2m 104A +14 Filtered_Fuel_Delivery_Rate [APFLDLRT] (LB/HR): cm848_calculateSensorEma runs exponentialMovingAverage "
       "on fuel_mass_flow_raw into it and compares it with alpha_reset_fuel_rate / alpha_threshold_fuel_rate; "
       "hpcr_calculateFuelTrimOutput zeroes it while stopped / cranking / jump starting; it is a fuel rate, not an intake "
       "temperature",
       f"e2m 104A +14 Filtered_Fuel_Delivery_Rate '[APFLDLRT] fuel rate, after filtering, which alpha uses in comparison to "
       f"trigger Fuel_Rate' (LB/HR, 0.1 per count, 0..3200; {PID}): cm848_calculateSensorEma filters fuel_mass_flow_raw "
       "into it (filter state cold_start_intake_temperature_filter_state) and compares it with alpha_reset_fuel_rate / "
       "alpha_threshold_fuel_rate; a low speed governor entry with it above the reset rate restarts the filter at the "
       "reset rate; hpcr_calculateFuelTrimOutput zeroes it and the filter with the engine stopped, cranking or jump "
       "starting. Not an intake temperature.")

rename(7, "Alpha_Altitude_Derate_Timer", "alpha_altitude_derate_timer",
       "e2m 104A +1A Alpha_Altitude_Derate_Timer (SEC; its e2m description repeats the AFC latch text): cm848_checkPressureFuelState reloads it with "
       "altitude_derate_alpha_timeout every pass while final_fueling_state is ALTITUDE_DERATE and counts it down after "
       "that (0 when bit 0x20 of feature_enable_flags_cal is clear); hpcr_calculateFuelTrimOutput zeroes it when stopped / "
       "cranking; the old name says governor init",
       f"e2m 104A +1A Alpha_Altitude_Derate_Timer (SEC, 0.2 per count, 0..900; {PID}; the e2m description repeats the AFC "
       "latch text): the latch timer of the altitude derate alpha. cm848_checkPressureFuelState reloads it with "
       "altitude_derate_alpha_timeout every pass while final_fueling_state is ALTITUDE_DERATE and counts it down once that "
       "ends (it stays 0 when bit 0x20 of feature_enable_flags_cal is clear); hpcr_calculateFuelTrimOutput zeroes it with "
       "the engine stopped, cranking or jump starting. Not a governor initialization count.")

# ---------------------------------------------------------------------------------------------------------- 1069
keep(8, "Poweroff_Command_Ignored",
     "e2m 1069 +4 Poweroff_Command_Ignored '[SDENER] A status indicator saved to EEPROM indicating power was commanded off "
     "and is st...' (the e2m text is cut there)")
keep(9, "Parameter_Block_Image_Start",
     "e2m 1069 +C Parameter_Block_Image_Start '[SDRMIMSR] Counts number of times RAM image storage has started'")
keep(10, "Parameter_Block_Image_Complete",
     "e2m 1069 +E Parameter_Block_Image_Complete '[SDRMIMCP] Counts number of times RAM image storage has completed'")
keep(11, "Powerdown_Data_Lost",
     "e2m 1069 +10 Powerdown_Data_Lost '[SDDLCU] Number of consecutive occurances of powerdown data lost, updated each "
     "powerup'")

# ---------------------------------------------------------------------------------------------------------- 1070
keep(12, "VG_Brake_State", "e2m 1070 +22 VG_Brake_State 'Indicates VG is being used for engine braking'")

# ---------------------------------------------------------------------------------------------------------- 107C ASG
rename(13, "ASG_Error_Difference", "all_speed_governor_error_difference",
       "e2m 107C +2 ASG_Error_Difference [ASERDC] (RPM, +-4000): in cm848_runOperatingModeSpeedGovernor it is the new speed "
       "error (all_speed_governor_state_speed_error) minus the previous pass error, clamped to +-32000 counts, and feeds both "
       "difference equations of the PID; the old name says PID input",
       f"e2m 107C +2 ASG_Error_Difference '[ASERDC] ASG error difference' (RPM, 0.125 per count, -4000..4000; {PID}): the "
       "change of the speed error between two passes in cm848_runOperatingModeSpeedGovernor: the new error "
       "(governor_reference_speed_filtered minus governor_rpm_actual, all_speed_governor_state_speed_error) minus the "
       "previous pass error, clamped to +-32000 counts. It is the error-difference term of the governor's PID difference "
       "equations.")

rename(14, "ASG_Feedback_Difference", "all_speed_governor_feedback_difference",
       "e2m 107C +4 ASG_Feedback_Difference [ASFBDC] (RPM, +-1000): cm848_runOperatingModeSpeedGovernor stores governor_rpm_actual "
       "minus the previous pass speed (fuel_trim_pid_ema_snapshot) clamped to +-8000 counts (0xe0c0 / 8000 stores) and "
       "subtracts it times a gain in both PID difference equations; the old name says previous output",
       f"e2m 107C +4 ASG_Feedback_Difference '[ASFBDC] ASG feedback difference term' (RPM, 0.125 per count, -1000..1000; "
       f"{PID}): the change of the measured engine speed between two passes in cm848_runOperatingModeSpeedGovernor: "
       "governor_rpm_actual minus the previous pass speed (fuel_trim_pid_ema_snapshot, the state X3 memory), clamped to "
       "+-8000 counts (+-1000 rpm); it is subtracted times a gain in both difference equations of the governor's PID. Not "
       "a previous PID output.")

rename(15, "ASG_100_Fueling", "all_speed_governor_fueling",
       "e2m 107C +A ASG_Fueling [ASFL] (the alias record ASG_100_Fueling [ASMXFL] 'from 4D tables' shares +A but nothing here "
       "reads a table): cm848_runOperatingModeSpeedGovernor clamps correction state + no-load fuel + ASG delta between "
       "governor_fuel_demand_tracking_floor / _limit into it; cm848_calculateEffectiveFuelLimit uses it in the droop equation "
       "and the CCVS1 cruise state compares cruise_fuel_demand_hold with it",
       f"e2m 107C +A ASG_Fueling '[ASFL] ASG FUELING' (MM3S, 0.0679 per count, 0..400; {PID}; the record ASG_100_Fueling "
       "[ASMXFL] 'Fueling from 4D tables using ASG_Selected_Speed, 100% throttle, and alpha' shares offset +A): the "
       "all-speed governor fueling. cm848_runOperatingModeSpeedGovernor clamps the correction state, the filtered no-load "
       "fuel and the ASG delta between governor_fuel_demand_tracking_floor and _limit into it (minus "
       "governor_override_fuel_decay_cal while cruise is engaged); cm848_calculateEffectiveFuelLimit uses it in the droop "
       "equation. Not a previous demand.")

rename(16, "ASG_State_X1", "all_speed_governor_state_speed_error",
       "e2m 107C +C ASG_State_X1 [ASSTX1] (RPM, +-4000): cm848_runOperatingModeSpeedGovernor stores governor_reference_speed_filtered "
       "minus governor_rpm_actual clamped to +-32000 counts every pass and reads the old value as the previous error; an "
       "external reset seeds it from all_speed_governor_reset_state_speed_error_previous (e2m ASG_State_X1_As)",
       f"e2m 107C +C ASG_State_X1 '[ASSTX1] ASG state X1' (RPM, 0.125 per count, -4000..4000; {PID}): state 1 of the "
       "all-speed governor, the speed error: governor_reference_speed_filtered minus governor_rpm_actual clamped to +-32000 "
       "counts (+-4000 rpm), recomputed every pass by cm848_runOperatingModeSpeedGovernor; its previous value is the "
       "previous pass error that an external reset seeds from all_speed_governor_reset_state_speed_error_previous "
       "(e2m ASG_State_X1_As). Not a PID reference.")

rename(17, "ASG_State_X6", "all_speed_governor_state_fuel_demand_correction",
       "e2m 107C +14 ASG_State_X6 [ASSTX6] (MM3S, +-400): cm848_runOperatingModeSpeedGovernor computes it as (x5 x gain a - previous x5 x "
       "gain b + x6 x gain c) >> 8 clamped to +-0x1700 and adds it to the filtered no-load fuel for the governor fueling; "
       "seeded from all_speed_governor_reset_state_fuel_demand_correction (e2m ASG_State_X6_As)",
       f"e2m 107C +14 ASG_State_X6 '[ASSTX6] ASG state X6' (MM3S, 0.0679 per count, -400..400; {PID}): state 6 of the "
       "all-speed governor, the PID's fuel correction: (clamped integral state x gain a - previous one x gain b + this x "
       "gain c) >> 8 clamped to +-0x1700 (+-400) in cm848_runOperatingModeSpeedGovernor, added to the filtered no-load fuel "
       "to give the governor fueling. An external reset seeds it from all_speed_governor_reset_state_fuel_demand_correction "
       "(e2m ASG_State_X6_As), a speed mode start from final_fueling minus no-load fuel minus the ASG delta.")

rename(18, "ASG_Delta", "all_speed_governor_delta",
       "e2m 107C +56 ASG_Delta (MM3S, 0..400): cm848_runOperatingModeSpeedGovernor integrates final_fueling minus the governor "
       "fueling (minus fuel_demand_integrator_offset_cal) into it in the low speed governor state and decays it above the "
       "idle reference speed, limit fuel_demand_integrator_upper_limit; it is added to the governor fueling and to the droop "
       "equation of cm848_calculateEffectiveFuelLimit; the old name says integrator",
       f"e2m 107C +56 ASG_Delta 'Calculated amount to add to ASG to eliminate LSG-ASG deadband' (MM3S, 0.0679 per count, "
       f"0..400; {PID}): in the low speed governor state cm848_runOperatingModeSpeedGovernor integrates final_fueling minus "
       "the governor fueling (minus fuel_demand_integrator_offset_cal, e2m ASG_Delta_Offset) into it, otherwise it decays "
       "above the idle reference speed; limited to fuel_demand_integrator_upper_limit (e2m ASG_Delta_Max_Limit). It is added "
       "to the governor fueling and to the droop equation in cm848_calculateEffectiveFuelLimit; "
       "cm848_calculateFuelDemandWithConditions tests it for 0.")

rename(19, "Decel_Rate_I_Term", "rpm_deceleration_limit_integral_term",
       "e2m 107C +5A Decel_Rate_I_Term (MM3S): first word of the dword; cm848_runOperatingModeSpeedGovernor adds "
       "fuel_demand_integrator_gain_a_cal x (engine_rpm_delta - offset) >> 8 per pass, clamped 0..fuel_demand_integrator_b_limit, zero "
       "below rpm_drop_fuel_minimum_manifold_pressure; type note: the dword covers two words (I term here, P term "
       "0x40a206 = e2m +5C Decel_Rate_P_Term)",
       f"e2m 107C +5A Decel_Rate_I_Term 'Integral term of rpm decel limit control' (MM3S, 0.0679 per count, -400..400; {PID}): "
       "the first word of the dword (the proportional term is the second, e2m +5C Decel_Rate_P_Term). "
       "cm848_runOperatingModeSpeedGovernor adds fuel_demand_integrator_gain_a_cal x (engine_rpm_delta minus an offset) >> 8 per "
       "pass, clamped between 0 and fuel_demand_integrator_b_limit, and zeroes it while the intake manifold pressure is below "
       "rpm_drop_fuel_minimum_manifold_pressure; its sum with the proportional term (fuel_demand_integrator_b_sum, e2m "
       "Decel_Limit_Fuel) is a floor of the governor output. Not an ASG fuel demand integrator.")

# ---------------------------------------------------------------------------------------------------------- 1100
rename(20, "J1939_Engine_Control_Status", "j1939_engine_control_active_flag_cal",
       "e2m 1100 +0 J1939_Engine_Control_Status [JCEGCOSS] (0 = INACTIVE): governor_sourceData_init(0) sets it when "
       "j1939_tsc1_override_state.governor_mode becomes non-zero with etc1_active_state 1, phase_group_a_setupETC1Controller "
       "clears it when that ends and stores the finished session record in the J1939 history table; EEPROM mirror, so _cal",
       f"e2m 1100 +0 J1939_Engine_Control_Status '[JCEGCOSS] J1939 ENGINE CONTROL STATUS 0 = INACTIVE' (UNITLESS, 0..1; "
       f"EEPROM mirror, {PID}): 1 while a J1939 engine control session is open: governor_sourceData_init(0) sets it when "
       "j1939_tsc1_override_state.governor_mode becomes non-zero with etc1_active_state 1 (or the controlling source "
       "address changes), phase_group_a_setupETC1Controller clears it when the control ends and "
       "governor_calibSnapshot_rollingBuffer_update stores the finished session record in the J1939 history table. Sibling "
       "of j1939_engine_control_source_index_cal. Not a calibration snapshot gate.")

rename(21, "J1939_Retarder_Control_Status", "j1939_retarder_control_active_flag_cal",
       "e2m 1100 +2 J1939_Retarder_Control_Status [JCRDCOSS] (0 = INACTIVE): governor_sourceData_init(1) sets it when "
       "engine_retarder_override_control_mode is non-zero, phase_group_a_setupETC1Controller clears it when that ends and "
       "stores the session record in the J1939 history table; EEPROM mirror, so _cal",
       f"e2m 1100 +2 J1939_Retarder_Control_Status '[JCRDCOSS] J1939 RETARDER CONTROL STATUS 0 = INACTIVE' (UNITLESS, "
       f"0..1; EEPROM mirror, {PID}): 1 while a J1939 retarder control session is open: governor_sourceData_init(1) sets it "
       "when engine_retarder_override_control_mode is non-zero (or the controlling source address changes), "
       "phase_group_a_setupETC1Controller clears it when the control ends and governor_calibSnapshot_rollingBuffer_update "
       "stores the finished session record in the J1939 history table. Sibling of "
       "j1939_retarder_control_source_index_cal. Not a governor-mode calibration snapshot gate.")

rename(22, "J1939_History_Table_Next_Entry", "j1939_history_table_next_entry_index_cal",
       "e2m 1100 +8 J1939_History_Table_Next_Entry [JCHSTBPO]: governor_calibSnapshot_rollingBuffer_update copies the finished "
       "engine (argument 0) or retarder (argument 1) control session record (12 words from 0x3feb50 / 0x3feb6a) into slot "
       "this and then adds 1, wrapping from 5 to 0 (5 records of 24 bytes = e2m 10FD J1939_History_Table at 0x3fead4); "
       "EEPROM mirror, so _cal",
       f"e2m 1100 +8 J1939_History_Table_Next_Entry '[JCHSTBPO] pointer into J1939_History_Table' (UNITLESS, 0..65535; EEPROM "
       f"mirror, {PID}): the index 0-4 of the J1939 history table slot written next (e2m 10FD J1939_History_Table: 5 records "
       "of 24 bytes at 0x3fead4). governor_calibSnapshot_rollingBuffer_update copies the finished engine (argument 0) or "
       "retarder (argument 1) control session record (12 words from 0x3feb50 / 0x3feb6a) into that slot, then adds 1 and "
       "wraps from 5 to 0.")

# ---------------------------------------------------------------------------------------------------------- 1143
rename(23, "Fuel_Temperature_Fueling_Index", "fuel_temperature_derate_fueling_severity_index_cal",
       "e2m 1143 +0 Fuel_Temperature_Fueling_Index [EPFTFLIX] (1/256, 0..1): word 0 of the 30-byte record of the single fault "
       "derate channel (fuel temperature, ROM 0x597b2; stride 15 words in the channel loops): "
       "cm848_calculateFaultDerateFuelLimit stores the channel's fueling derate level (0..256) with *pwVar4 = level; word 1 is "
       "fuel_temperature_derate_engine_speed_severity_index_cal; EEPROM mirror, so _cal",
       f"e2m 1143 +0 Fuel_Temperature_Fueling_Index '[EPFTFLIX] Fuel temperature fueling severity index.' (UNITLESS, 1/256 per "
       f"count, 0..1; EEPROM mirror, {PID}): word 0 of the 30-byte state record of the single fault derate channel (the fuel "
       "temperature channel at ROM 0x597b2; the channel loops step the record by 15 words and the row is the base of the "
       "state array): cm848_calculateFaultDerateFuelLimit stores the channel's fueling derate level (0-256) here, "
       "governor_faultDerate_mainLoop_update clears the active channel when it and "
       "fuel_temperature_derate_engine_speed_severity_index_cal (word 1) are both 0.")

# ---------------------------------------------------------------------------------------------------------- 1227
rename(24, "Intake_Air_Heater_Status", "intake_air_heater_monitor_result",
       "e2m 1227 +0 Intake_Air_Heater_Status [JCGPSS] (+2 Misfire_Monitor_Status = misfire_monitor_result): "
       "cm848_j1939HandlePgn58112Dm7 sends it as the test-0 value of its PGN 65232 (DM8) answer, test 1 being "
       "misfire_monitor_result, and cm848_j1939HandlePgn65230Dm5Readiness reads it; no store anywhere in ROM / flash2 "
       "(2 loads only), so it stays 0; the attribution to the intake air heater comes from the e2m name and the test order; "
       "the old name says DM1 response mode",
       f"e2m 1227 +0 Intake_Air_Heater_Status '[JCGPSS] Status from fault handler indicating OBDII def. of monitor status' "
       f"(UNITLESS, 0..65535; {PID}): the J1939 monitor status of the intake air heater, twin of misfire_monitor_result "
       "(e2m 1227 +2): cm848_j1939HandlePgn58112Dm7 sends it as the test-0 value of its PGN 65232 (DM8) answer "
       "(cm848_j1939SendDm1ResponseMessage) and cm848_j1939HandlePgn65230Dm5Readiness reads it for the DM5 status word. "
       "Nothing in the ROM or flash2 stores it (2 loads only), so it stays 0. Not a DM1 response mode.")

# ---------------------------------------------------------------------------------------------------------- 162B
drift(25, "IAH_Function_Timer",
      "e2m 162B +A IAH_Function_Timer (SEC 0.1, 0..60, 'how long the IAH drivers have been on this drive cycle') resolves to "
      "0x40b9ee, which the code uses as the misfire attempt count array (e2m 1651 +0 Misfire_Cyl_1_Attempt_Number resolves "
      "to the same address: cm848_resetMisfireMonitorTest zeroes slot n, cm848_evaluateMisfireMonitorCylinderResponse counts "
      "attempts per slot against misfire_monitor_attempt_limit); the IAH block's own words end at +8 (0x40b9ec "
      "intake_air_heater_performance_test_state) and nothing counts IAH driver on-time, so 162B +A / +C (IAH_Ratio at "
      "0x40b9f0 = misfire slot 2) are the 11.45 tail without a counterpart (drift); keep the name")

# ---------------------------------------------------------------------------------------------------------- 1735
rename(26, "C_CBP_Residual_Mass_Min", "cylinder_residual_gas_mass_lower_limit",
       "e2m 1735 +2 C_CBP_Residual_Mass_Min 'Min limit on residual mass estimation' (MM3S): cm848_calculateResidualGasMass floors "
       "cylinder_residual_gas_mass at it (cylinder_residual_gas_mass = this when the unclamped value is below it); it is a "
       "mass limit, not a boost pressure ratio; its twin at 0x4062d2 (e2m C_CBP_Residual_Mass_Max, boost_pressure_ratio_upper_limit) "
       "has the same wrong name",
       f"e2m 1735 +2 C_CBP_Residual_Mass_Min 'Min limit on residual mass estimation' (MM3S, 0.1359 per count, 0..8000; {PID}): "
       "the floor that cm848_calculateResidualGasMass applies to the residual gas mass cylinder_residual_gas_mass "
       "(cylinder_residual_gas_mass_unclamped is raised to it); the ceiling is the row at 0x4062d2 (e2m C_CBP_Residual_Mass_Max). "
       "ROM-copied constant. Not a boost pressure ratio.")

# ---------------------------------------------------------------------------------------------------------- 175F
rename(27, "TPE_Corrected_Turbo_Speed", "compressor_map_corrected_turbocharger_speed",
       "e2m 175F +2 TPE_Corrected_Turbo_Speed [REV/SEC/SQRT(K)]: cm848_estimateCompressorOutletTemperature stores turbocharger_speed x "
       "0x106 / 10000 x 0x28b0b / compressor_inlet_temperature_square_root (capped 65535) and uses it as the y input of the "
       "compressor map lookup; cm848_calculateBoostTorqueOffset uses it as the x input of three lookups; the old name says fuel "
       "timing",
       f"e2m 175F +2 TPE_Corrected_Turbo_Speed 'Turbo speed input to compressor map in corporate units' (REV/SEC/SQRT(K), 1/256 per "
       f"count, 0..255.99; {PID}): the corrected turbocharger speed. cm848_estimateCompressorOutletTemperature stores "
       "turbocharger_speed x 0x106 / 10000 x 0x28b0b / compressor_inlet_temperature_square_root here (capped at 65535) and "
       "uses it as the y input of the compressor map lookup next to the corrected air flow (e2m TPE_Corrected_Air_Flow, "
       "0x40a60e); cm848_calculateBoostTorqueOffset uses it as the input of three lookups. dump 4241. Not a fuel timing input.")

rename(28, "TPE_CIT_Sqrt", "compressor_inlet_temperature_square_root",
       "e2m 175F +6 TPE_CIT_Sqrt [SQRT(DEG_K)]: cm848_estimateCompressorOutletTemperature looks it up from ambient_air_temperature_selected "
       "(fuel_timing_correction_b_axis_cal / _output_cal) and divides the corrected air flow and corrected speed by it; "
       "cm848_estimateTurbochargerSpeed multiplies the corrected speed by it; dump 2122 = 16.58 = sqrt(275 K)",
       f"e2m 175F +6 TPE_CIT_Sqrt 'Square root of CIT' (SQRT(DEG_K), 1/128 per count, 10..30; {PID}): "
       "cm848_estimateCompressorOutletTemperature looks it up from ambient_air_temperature_selected in "
       "fuel_timing_correction_b_axis_cal / fuel_timing_correction_b_output_cal and divides the corrected air flow and the "
       "corrected turbocharger speed by it; cm848_estimateTurbochargerSpeed multiplies the corrected speed by it to get "
       "turbocharger_speed_estimate. dump 2122 (16.58 = square root of 275 K). Not a fuel timing correction.")

rename(29, "TPE_COT_Est_Enable", "compressor_outlet_temperature_estimation_active_flag",
       "e2m 175F +C TPE_COT_Est_Enable: cm848_selectCompressorOutletTemperature sets it to 0 when bit 0x80 of feature_enable_flags_cal is "
       "clear or both source states are 2 (compressor_outlet_temperature = fuel_flow_rate_default_cal), else 1 and the "
       "temperature comes from cm848_estimateCompressorOutletTemperature; the old name says fuel timing range",
       f"e2m 175F +C TPE_COT_Est_Enable 'Indicates whether the compressor estimation is active.' (UNITLESS, 0..1; {PID}): "
       "cm848_selectCompressorOutletTemperature sets it to 0 when bit 0x80 of feature_enable_flags_cal is clear or both "
       "source states are 2 (compressor_outlet_temperature = the calibrated default fuel_flow_rate_default_cal, "
       "fuel_timing_state_code 2) and to 1 otherwise, when compressor_outlet_temperature comes from "
       "cm848_estimateCompressorOutletTemperature. dump 1. Not a fuel timing range flag.")

# ---------------------------------------------------------------------------------------------------------- 1781
rename(30, "CHP_Pumping_Torque_Adj", "pumping_torque_adjustment",
       "e2m 1781 +2 CHP_Pumping_Torque_Adj [FT*LB] 'Used by CBR in determination of gross fuel from net torque cmd': "
       "cm848_calculateBoostPressureOffset turns nominal engine delta-P minus egr_delta_pressure_negated into torque, adds "
       "fuel_demand_blend_offset_cal and clamps it; cm848_calculateNetCombustionTorque subtracts it from the combustion torque and "
       "cm848_applyProtectionRpmCorrectionFilter adds it to the friction torque for engine_no_load_torque",
       f"e2m 1781 +2 CHP_Pumping_Torque_Adj 'Used by CBR in determination of gross fuel from net torque cmd' (FT*LB, 0.5 per "
       f"count, -4000..4000; {PID}): the pumping torque. cm848_calculateBoostPressureOffset turns the nominal engine delta-P "
       "(fuel_demand_blend_lookup) minus egr_delta_pressure_negated into torque (deadband, scale), adds "
       "fuel_demand_blend_offset_cal and clamps it between fuel_demand_min_limit_cal and fuel_demand_blend_upper_cal (0 below "
       "fuel_demand_load_threshold_cal). cm848_calculateNetCombustionTorque subtracts it from the combustion torque, "
       "cm848_applyProtectionRpmCorrectionFilter adds it to the friction torque for engine_no_load_torque. Not a fuel demand blend.")

# ---------------------------------------------------------------------------------------------------------- 17A1
rename(31, "Temperature_Delta", "exhaust_temperature_model_delta",
       "e2m 17A1 +0 Temperature_Delta [DEG_F 0.5, 0..1500]: cm848_calculateCombustionTemperatureRise stores "
       "(boost_target_load_rpm_output << 8) / charge_fuel_ratio (floor 128) capped at 3000 = 1500 deg F; "
       "cm848_auxiliaryControl_exponentialAverage copies it to exhaust_temperature_rise_over_intake_manifold_temperature (0 when "
       "the model is invalid) and adds it to 2 x the intake manifold temperature for exhaust_temperature; it is not a boost target",
       f"e2m 17A1 +0 Temperature_Delta 'Difference between IMT and exhaust temperature' (DEG_F, 0.5 per count, 0..1500; {PID}): "
       "the exhaust temperature model's rise over the intake manifold temperature. "
       "cm848_calculateCombustionTemperatureRise stores the energy term boost_target_load_rpm_output << 8 / charge_fuel_ratio "
       "(floor 128) here, capped at 3000 (1500 deg F); cm848_auxiliaryControl_exponentialAverage copies it to "
       "exhaust_temperature_rise_over_intake_manifold_temperature (0 while the model is invalid) and adds it to twice the "
       "intake manifold temperature for exhaust_temperature. Not a boost target ratio.")

rename(32, "TPE_Invalid_Model", "exhaust_temperature_model_invalid_flag",
       "e2m 17A1 +6 TPE_Invalid_Model 'Set to TRUE to protect against divide by zero in model': "
       "cm848_auxiliaryControl_exponentialAverage sets it when engine_rpm_state.current_rpm is below 8 counts or charge_fuel_ratio is below "
       "128, else 0; while set the combustion temperature rise is not calculated (the rise word is 0) and "
       "exhaust_temperature_source is 1; it blocks the exhaust temperature model, not a boost target calculation",
       f"e2m 17A1 +6 TPE_Invalid_Model 'Set to TRUE to protect against divide by zero in model' (UNITLESS, 0..1; {PID}): "
       "cm848_auxiliaryControl_exponentialAverage sets it to 1 when engine_rpm_state.current_rpm is below 8 counts (1 rpm) or "
       "charge_fuel_ratio is below 128, else 0; while it is 1 cm848_calculateCombustionTemperatureRise is skipped "
       "(exhaust_temperature_rise_over_intake_manifold_temperature = 0) and exhaust_temperature_source is 1. dump 1. Not a "
       "boost target inhibit.")

# ---------------------------------------------------------------------------------------------------------- 191A
rename(33, "WIF_Miles", "water_in_fuel_distance_cal",
       "e2m 191A +0 WIF_Miles 'Actual miles for WIF too long' (MI, 1/256, EEPROM 0x1a36): meaning kept, the name only gains _cal "
       "(0x3feeb8 is inside the EEPROM mirror 0x3fd482-0x3feec1); cm848_monitorWaterInFuelDistance accumulates it while "
       "P2269 is active and zeroes it while P2269 is clear; e2m 1930 +12 AATR_Numerator resolves to the same address (the "
       "drifted tail of block 1930), this record is the one the code matches",
       f"e2m 191A +0 WIF_Miles 'Actual miles for WIF too long' (MI, 1/256 per count, 0..9999999; EEPROM 0x1a36, {PID}): "
       "persistent distance with P2269 water in fuel active (1/256 mile per count if the task runs every 100 ms): zeroed "
       "while P2269 is clear, at 128000 (0x40a026 - 500 miles at that rate) it sets P0169 (fault_detected_bits_336_to_351 bit "
       "0). EEPROM-backed (inside the mirror), so _cal. e2m 1930 +12 AATR_Numerator resolves to the same address (the "
       "drifted tail of block 1930).")

# ---------------------------------------------------------------------------------------------------------- 1921
rename(34, "Ambient_Air_Tmptr", "ambient_air_temperature_reference",
       "e2m 1921 +6 Ambient_Air_Tmptr 'Ambient Air Temperature' (DEG_F, 1/64): hpcr_fuelFinal_exponentialAverage stores the user "
       "override ambient_air_temperature_override_value, the default ambient_air_temperature_default_value (source state 2) or the "
       "filtered ambient_air_temperature_selected minus compressor_inlet_temperature_rise; cm848_blendBoostAndThrottleFuelDemand "
       "looks up the water saturation vapor pressure with it (capped at 90 F); reference twin of ambient_air_temperature_selected "
       "like barometric_pressure_reference; the old name says boost fuel demand blend",
       f"e2m 1921 +6 Ambient_Air_Tmptr 'Ambient Air Temperature' (DEG_F, 1/64 per count, -50..150; {PID}): the ambient air "
       "temperature of the air handling models. hpcr_fuelFinal_exponentialAverage stores the user override "
       "(ambient_air_temperature_override_value), the default (ambient_air_temperature_default_value, source state 2) or the "
       "filtered ambient_air_temperature_selected minus the compressor inlet temperature rise; "
       "cm848_blendBoostAndThrottleFuelDemand looks up the water saturation vapor pressure with it (capped at 90 F). Reference "
       "twin of ambient_air_temperature_selected, like barometric_pressure_reference of barometric_pressure_selected. dump "
       "1620. Not a fuel demand blend.")

rename(35, "Compressor_Inlet_Press", "compressor_inlet_pressure",
       "e2m 1921 +A Compressor_Inlet_Press (IN_HG): hpcr_fuelFinal_exponentialAverage stores barometric_pressure_selected (minus "
       "boost_fuel_pressure_offset_lookup when barometric_pressure_sensor_senses_ambient_air_flag_cal is set), floored at 1; it is the "
       "divisor of the charge pressure ratio in cm848_estimateTurbochargerSpeed, the multiplier of the boost pressure "
       "target in cm848_calculateBoostTorqueOffset and the divisor in the corrected air flow of "
       "cm848_estimateCompressorOutletTemperature; the old name says fuel scale divisor",
       f"e2m 1921 +A Compressor_Inlet_Press 'Compressor_Inlet_Pressure' (IN_HG, 0.0159 per count, 0..30; {PID}): the "
       "pressure at the compressor inlet. hpcr_fuelFinal_exponentialAverage stores barometric_pressure_selected (minus "
       "boost_fuel_pressure_offset_lookup, the inlet pressure drop, when barometric_pressure_sensor_senses_ambient_air_flag_cal "
       "is set), floored at 1. cm848_estimateTurbochargerSpeed divides the intake manifold pressure by it for the charge "
       "pressure ratio, cm848_calculateBoostTorqueOffset multiplies the boost pressure target by it, "
       "cm848_estimateCompressorOutletTemperature divides the corrected air flow by it. dump 1647. Not a fuel scale "
       "divisor.")

rename(36, "Compressor_Inlet_Tmptr_Rise", "compressor_inlet_temperature_rise",
       "e2m 1921 +10 Compressor_Inlet_Tmptr_Rise (DEG_F, 1/64): hpcr_fuelFinal_exponentialAverage looks it up in a dual-axis table "
       "of the filtered fresh air mass flow and vehicle_speed_copy; ambient_air_temperature_selected minus it is the ambient "
       "air temperature (also cm848_initialization_step_3); the old name says boost fuel timing target",
       f"e2m 1921 +10 Compressor_Inlet_Tmptr_Rise 'Temperature rise from ambient to compressor inlet' (DEG_F, 1/64 per count, "
       f"0..255; {PID}): hpcr_fuelFinal_exponentialAverage looks it up in a dual-axis table of the filtered fresh air mass "
       "flow and vehicle_speed_copy; ambient_air_temperature_selected minus it, filtered, is the ambient air temperature "
       "(ambient_air_temperature_reference; cm848_initialization_step_3 does the subtraction once at start). dump 640 "
       "(10 F). Not a timing target.")

rename(37, "Ambient_Relative_Humidity", "ambient_relative_humidity",
       "e2m 1921 +14 Ambient_Relative_Humidity (UNITLESS, 1/1024, 0 = dry, 1 = saturated): hpcr_fuelFinal_exponentialAverage looks it "
       "up in a dual-axis table of engine speed and injection_quantity_combustion_reference; "
       "cm848_blendBoostAndThrottleFuelDemand multiplies ambient_saturation_vapor_pressure by it >> 10 for "
       "ambient_water_vapor_partial_pressure (dump 1024 = saturated); the old name says rpm blend scale",
       f"e2m 1921 +14 Ambient_Relative_Humidity 'Relative humidity of ambient air (0 = dry air, 1 = saturated air).' (UNITLESS, "
       f"1/1024 per count, 0..1; {PID}): hpcr_fuelFinal_exponentialAverage looks it up in a dual-axis table of engine speed "
       "and injection_quantity_combustion_reference (the boost_fuel_rpm_blend_scale_* tables); "
       "cm848_blendBoostAndThrottleFuelDemand multiplies ambient_saturation_vapor_pressure by it >> 10 for "
       "ambient_water_vapor_partial_pressure, the input of the water vapor fractions of the condensation model. dump 1024 "
       "(saturated). Not an rpm blend scale.")

# ---------------------------------------------------------------------------------------------------------- 1B2E
keep(38, "CWG_High_Boost_Time",
     "e2m 1B2E +2 CWG_High_Boost_Time 'minimum time at high boost condition before setting the error' (SEC, 0.1 per count; "
     "the same limit also serves the pass debounce)")

# ---------------------------------------------------------------------------------------------------------- 8000
keep(39, "HPCR_Precontrol",
     "e2m 8000 +1 HPCR_Precontrol 'Switch to select/deselect Precontrol' (precontrol = the rpm-table feed-forward)")
keep(40, "HPCR_Testbench",
     "e2m 8000 +3 HPCR_Testbench 'Switch to select test bench mode' (test bench mode = governor disabled; the replacement "
     "duty is e2m +24 HPCR_Dutycycle_Repl_Testbench = fuel_pressure_governor_disabled_command)")

rename(41, "HPCR_Max_Scaling_Current_Compensation", "fuel_metering_feedback_trim_maximum_scaling_factor",
       "e2m 8000 +20 HPCR_Max_Scaling_Current_Compensation (1/4096, dump 2049 = 0.5): cm848_calculateFuelMeteringCommand limits the PI sum on "
       "fuel_metering_feedback_error (proportional + fuel_metering_feedback_trim_integrator) to it, winds the integrator back "
       "to it minus the proportional term, and the command is base + trim x base / 4096; ROM-copied constant, so no _cal; "
       "the old name says engine sync protection",
       f"e2m 8000 +20 HPCR_Max_Scaling_Current_Compensation 'Maximum scaling factor for current compensation' (UNITLESS, "
       f"signed, 1/4096 per count, 0..1; {PID}): the upper clamp of the fuel metering feedback trim in "
       "cm848_calculateFuelMeteringCommand: the PI sum on fuel_metering_feedback_error (proportional term + "
       "fuel_metering_feedback_trim_integrator) is limited to it and the integrator is wound back to it minus the "
       "proportional term; the command is base + trim x base / 4096. ROM-copied constant, so no _cal. dump 2049 "
       "(0.5). Not an engine sync limit.")

rename(42, "HPCR_Min_Scaling_Current_Compensation", "fuel_metering_feedback_trim_minimum_scaling_factor",
       "e2m 8000 +22 HPCR_Min_Scaling_Current_Compensation (1/4096, dump -2049 = -0.5): the lower clamp of the same PI trim sum in "
       "cm848_calculateFuelMeteringCommand (integrator wound back to it minus the proportional term); ROM-copied constant, so no "
       "_cal; the old name says engine sync protection",
       f"e2m 8000 +22 HPCR_Min_Scaling_Current_Compensation 'Minimum scaling factor for current compensation' (UNITLESS, "
       f"signed, 1/4096 per count, -1..1; {PID}): the lower clamp of the fuel metering feedback trim in "
       "cm848_calculateFuelMeteringCommand (twin of fuel_metering_feedback_trim_maximum_scaling_factor): the PI sum on "
       "fuel_metering_feedback_error is limited to it and the integrator is wound back to it minus the proportional term. "
       "ROM-copied constant, so no _cal. dump -2049 (-0.5). Not an engine sync limit.")

rename(43, "HPCR_Fuel_Pressure_Filter_Constant", "fuel_pressure_sensor_filter_coefficient",
       "e2m 8000 +32 HPCR_Fuel_Pressure_Filter_Constant 'Fuel pressure filter constant for Derivative Component' (1/65536): "
       "cm848_resetEngineSyncState points fuel_pressure_sensor_filter.coefficient at it, cm848_calculateFuelMeteringCommand uses it "
       "(times a speed factor >> 16 when cam_timing_alt_mode_enable_cal is 0) as the coefficient of the filter on "
       "fuel_pressure_sensor whose output feeds the derivative term; ROM-copied constant, so no _cal; the old name says engine sync scale",
       f"e2m 8000 +32 HPCR_Fuel_Pressure_Filter_Constant 'Fuel pressure filter constant for Derivative Component' (UNITLESS, "
       f"1/65536 per count, 0..1; {PID}): the base coefficient of fuel_pressure_sensor_filter, the first order filter that "
       "cm848_calculateFuelMeteringCommand runs on fuel_pressure_sensor before the derivative term (fuel_pressure_setpoint "
       "minus the filtered pressure): cm848_resetEngineSyncState points the filter at it, and the governor uses it times a "
       "speed factor >> 16 (lookup on engine_rpm_measured) while cam_timing_alt_mode_enable_cal is 0. ROM-copied constant, "
       "so no _cal. dump 43693. Not an engine sync scale factor.")

# ---------------------------------------------------------------------------------------------------------- 801D / 8021
keep(44, "HPCR_Current_Pressure_Regulator",
     "e2m 801D +0 HPCR_Current_Pressure_Regulator 'Current through pressure regulator valve' (mA, 1.2218 per count, 0..5000: "
     "the e2m names the physical signal, the pressure regulator valve current = the fuel metering output feedback)")
keep(45, "HPCR_Current_Sensor_Status_N", "e2m 801D +2 HPCR_Current_Sensor_Status_N 'Defect status of current sensor'")
keep(46, "HPCR_Fuelpr_Status_N", "e2m 801D +3 HPCR_Fuelpr_Status_N 'Status of fuel pressure'")
keep(47, "HPCR_Voltage_Fuelpr", "e2m 8021 +0 HPCR_Voltage_Fuelpr 'Ratiometric voltage of fuel pressure sensor'")
keep(48, "HPCR_Fuelpr_Defect_N", "e2m 8021 +6 HPCR_Fuelpr_Defect_N 'Defect status of fuel pressure sensor'")

# ---------------------------------------------------------------------------------------------------------- 819B
rename(49, "Backup_Lost_Counter", "crank_tooth_period_countdown",
       "e2m 819B +A Backup_Lost_Counter [ESTMCU02] 'Timeout counter for secondary speed input': mpc555_updateEngineCrankState (TPU-A "
       "channel 1 interrupt) reloads it with crank_sync_timing_scale_working on every tooth period capture, "
       "cm848_updateEngineSpeedFromCrankSignal counts it down, sets crank_tooth_rpm to 0 at 0 and counts passes at 0 in "
       "crank_sync_event_count; primary twin crank_period_countdown (e2m +32); the old name says engine sync startup",
       f"e2m 819B +A Backup_Lost_Counter '[ESTMCU02] Backup_Lost_Counter: Timeout counter for secondary speed input' (CNTS, "
       f"0..10000; {PID}): the lost-signal timeout counter of the tooth (secondary) speed input. "
       "mpc555_updateEngineCrankState (the TPU-A channel 1 interrupt) reloads it with crank_sync_timing_scale_working on every "
       "tooth period capture; cm848_updateEngineSpeedFromCrankSignal counts it down, sets crank_tooth_rpm to 0 when it is 0 "
       "and otherwise divides by crank_tooth_period_raw, and counts the passes with it at 0 while the engine turns in "
       "crank_sync_event_count. Primary twin: crank_period_countdown. Not an engine sync start-up countdown.")

rename(50, "Low_Speed_Filtering", "crank_low_speed_filtering_flag",
       "e2m 819B +30 Low_Speed_Filtering 'Flag indicating low speed operation': cm848_updateEngineSpeedFromCrankSignal sets it to 1 "
       "when engine_rpm_measured is below crank_speed_setpoint_threshold_cal (after loading the low speed TPU-A channel 0 / 1 "
       "parameters) and to 0 above it (high speed parameters), mpc555_resetEngineTimingAccumulators starts it at 1; 3 stores, "
       "no reader; the old name says crank sync valid",
       f"e2m 819B +30 Low_Speed_Filtering 'Flag indicating low speed operation' (UNITLESS, 0..65535; {PID}): "
       "cm848_updateEngineSpeedFromCrankSignal sets it to 1 when engine_rpm_measured is below "
       "crank_speed_setpoint_threshold_cal, after loading the low speed TPU-A channel 0 / 1 parameters from the "
       "crank_mios_*_cal words, and to 0 above it with the high speed parameters; mpc555_resetEngineTimingAccumulators "
       "starts it at 1. Written only (3 stores, no reader). dump 1. Not a crank sync validity flag.")

keep(51, "Main_Lost_Counter",
     "e2m 819B +32 Main_Lost_Counter '[ESTMCU01] Main_Lost_Counter: Timeout counter for primary speed sensor' (reloaded with "
     "crank_period_adjusted_working by hpcr_processEngineSyncPulses, counted down by cm848_updateEngineSpeedFromCrankSignal)")

rename(52, "PMA_Good_Window", "crank_tooth_good_window_fraction",
       "e2m 819B +42 PMA_Good_Window 'Tooth fraction defining expected normal tooth location' (1/64, 0..3.98): "
       "cm848_updateEngineSpeedFromCrankSignal looks it up from engine_rpm_measured (crank_mios_timing_axis_cal / _values_cal) and "
       "programs the TPU-A channel 1 window bytes 0x40 + (this >> 1) and 0x40 - (this >> 1), a symmetric window around a "
       "ratio of 1.0 (0x40); reset to 0 by mpc555_resetEngineTimingAccumulators; the old name says MIOS timing output, it is TPU-A "
       "channel 1; dump 64 = 1.0",
       f"e2m 819B +42 PMA_Good_Window 'Tooth fraction defining expected normal tooth location' (UNITLESS, 1/64 per count, "
       f"0..3.98; {PID}): cm848_updateEngineSpeedFromCrankSignal looks it up from engine_rpm_measured "
       "(crank_mios_timing_axis_cal / _values_cal) and programs the TPU-A channel 1 (tooth capture) window bytes as 0x40 + (this "
       ">> 1) and 0x40 - (this >> 1): a symmetric window of this width around a ratio of 1.0 (0x40). "
       "mpc555_resetEngineTimingAccumulators resets it to 0. dump 64 (1.0). Not a MIOS timing output.")

rename(53, "Prelim_Sync_Count", "crank_preliminary_sync_count",
       "e2m 819B +44 Prelim_Sync_Count: mpc555_updateEngineRunState counts it down in run state 3 and at 0 compares "
       "crank_tooth_count_b with crank_tooth_count_b_min_cal (e2m Prelim_Sync_Detection_Threshold) to enter run state 4, else "
       "reloads it from engine_event_countdown_cal (e2m Prelim_Sync_Evaluation_Count; bin 5 renames that cal to "
       "crank_preliminary_sync_evaluation_count, this keeps the pair readable)",
       "e2m 819B +44 Prelim_Sync_Count 'Counts crank revs until verification decision is made' (UNITLESS, 0..255): the "
       "countdown of engine run state 3 (preliminary sync): reloaded from engine_event_countdown_cal (e2m "
       "Prelim_Sync_Evaluation_Count) by mpc555_resetEngineTimingAccumulators and the run state 3 handlers, counted down "
       "by mpc555_updateEngineRunState; at 0 crank_tooth_count_b is checked against crank_tooth_count_b_min_cal to enter "
       "run state 4. dump 6.")

rename(54, "First_Speed_ISR_Time", "first_speed_interrupt_time_ticks",
       "e2m 819B +60 First_Speed_ISR_Time 'Global ECM start time information of POR time to 1st Speed ISR Time': "
       "hpcr_processEngineSyncPulses (TPU-A channel 11 speed interrupt) stores TBLr here once, while it is 0; every later "
       "time since the first speed interrupt is TBLr minus it (engine_state_crank_time / _run_time, crank_tooth_period_tbl, "
       "crank_event_timebase_a / b / c, the resync time); the old name says previous capture",
       f"e2m 819B +60 First_Speed_ISR_Time 'Global ECM start time information of POR time to 1st Speed ISR Time' (MSEC, 0.0004 "
       f"per count, dword; {PID}): the time base (TBLr) value captured once, by hpcr_processEngineSyncPulses (the TPU-A "
       "channel 11 speed interrupt) on the first speed interrupt after power-on reset (while it is 0). Every later start "
       "time is TBLr minus it: engine_state_crank_time / engine_state_run_time, crank_tooth_period_tbl, "
       "crank_event_timebase_a / b / c and crank_resync_time_ticks. Not a previous capture.")

rename(55, "Crank_Resync_Time", "crank_resync_time_ticks",
       "e2m 819B +64 Crank_Resync_Time 'First speed isr time to Last Crank Re-Sync Time': TBLr minus first_speed_interrupt_time_ticks, "
       "stored together with crank_tbl_event_counter (e2m Crank_Resync_Count) at every re-sync (6 sites in the crank "
       "sync state functions, incl. hpcr_processEngineSyncPulses, mpc555_updateEngineRunState, mpc555_updateEngineCrankState); the old name is "
       "only the generic 'timebase delta'",
       f"e2m 819B +64 Crank_Resync_Time 'First speed isr time to Last Crank Re-Sync Time' (MSEC, 0.0004 per count, dword; "
       f"{PID}): the time base time from the first speed interrupt (first_speed_interrupt_time_ticks) to the latest crank "
       "re-sync, TBLr minus it, stored together with the re-sync count crank_tbl_event_counter (e2m Crank_Resync_Count) at "
       "each re-sync in hpcr_processEngineSyncPulses, mpc555_updateEngineRunState and mpc555_updateEngineCrankState.")

rename(56, "HPCR_Fuelpr_Start_Undershoot", "fuel_pressure_start_undershoot",
       "e2m 819B +7A HPCR_Fuelpr_Start_Undershoot 'Global ECM start time information of HPCR_Fuel_Pressure Undershoot.': "
       "hpcr_processEngineSyncPulses lowers it to fuel_pressure_sensor in engine run state 3 when the sensor is below it, "
       "mpc555_resetEngineTimingAccumulators sets 0xfff (4095 = 199.8 MPa, the e2m maximum) when it is 0 (dump 4095); the old name says cam "
       "sync position; type note: the decompile compares it as short and the e2m is signed (i16), check lha / lhz before retyping",
       f"e2m 819B +7A HPCR_Fuelpr_Start_Undershoot 'Global ECM start time information of HPCR_Fuel_Pressure Undershoot.' (MPa, "
       f"signed, 0.0488 per count, 0..200; {PID}): the lowest rail pressure sensor reading during the start. "
       "hpcr_processEngineSyncPulses lowers it to fuel_pressure_sensor on each speed interrupt in engine run state 3 while "
       "the sensor is below it; mpc555_resetEngineTimingAccumulators sets it to 0xfff (4095 = 199.8 MPa, the e2m "
       "maximum) when it is 0. dump 4095. Not a cam sync position.")

# ---------------------------------------------------------------------------------------------------------- 8A0E
rename(57, "Coast_Accel_Timer", "cruise_coast_accelerate_hold_time",
       "e2m 8A0E +2 Coast_Accel_Timer 'Amount of time bump must be held before transitioning to coast/accel' (SEC 0.04, dump 13 = 0.52 s): "
       "governor_cruise_coastButton_handler / _setButton_handler / _resumeButton_handler load "
       "governor_cruiseOverride_holdoff_countdown with it on the button press and the held button becomes CRUISE_DECELERATE / "
       "CRUISE_ACCELERATE when the countdown reaches 0; the old name is camelCase and says override, these are the cruise "
       "switch buttons",
       f"e2m 8A0E +2 Coast_Accel_Timer 'Amount of time bump must be held before transitioning to coast/accel' (SEC, 0.04 per "
       f"count, 0..50; {PID}): the reload of the cruise switch hold-off countdown "
       "governor_cruiseOverride_holdoff_countdown. governor_cruise_coastButton_handler, _setButton_handler and "
       "_resumeButton_handler load it on a button press; the held button turns into continuous deceleration / "
       "acceleration (CRUISE_DECELERATE / CRUISE_ACCELERATE) when the countdown reaches 0. ROM-copied constant, so no _cal. "
       "dump 13 (0.52 s). Not a cruise override value.")

# ---------------------------------------------------------------------------------------------------------- 8C5B / 8D1B
keep(58, "RE_PN_Rationality_Timer", "e2m 8C5B +2 RE_PN_Rationality_Timer 'Timer for PN on diagnostics'")
keep(59, "RE_PN_Crank_Timer", "e2m 8C5B +4 RE_PN_Crank_Timer 'Crank timer for PN off diagnostics'")
keep(60, "RE_PN_Engine_Run_Timer", "e2m 8C5B +8 RE_PN_Engine_Run_Timer 'Engine run timer for PN rationality diagnostics'")
keep(61, "TTSR_Cold_Test_Fail",
     "e2m 8D1B +0 TTSR_Cold_Test_Fail 'Flag for cold section of TTSR test result (True = Fail)'")
keep(62, "TTSR_Dither_Test_Fail",
     "e2m 8D1B +1 TTSR_Dither_Test_Fail (the e2m description repeats the cold section text 'Flag for cold section of TTSR "
     "test result (True = Fail)'; the code treats it as the dither / temperature swing test)")

# ---------------------------------------------------------------------------------------------------------- fixes
EVIDENCE = {
    0: "e2m 0033 +8 Collector_Start_Address (logical beginning of the collector buffer; e2m 0034 +C Collector_Center_Address = 0x40c27c and 0035 +10 Collector_End_Address = 0x40c280 share the base 0x40c270): diag_dm1Buffer_circularFill advances / wraps it when the write pointer catches it and j1939_dm1_diagnosticMessage_send advances it past the bytes it sends; the diag_dm1_* buffer words are the data collector, not DM1",
    2: "e2m 104A +2 Alpha_Base: timingProtectionFlagsOrchestrator ramps it 0..0x4000 with alpha_ramp_rate_* while any alpha "
       "condition is set (0 otherwise); hpcr_calculateFuelTrimOutput copies it to combustion_alpha_input (state 0); the old "
       "name says fuel demand",
    3: "e2m 104A +8 Alpha_Fuel_Rate: cm848_calculateSensorEma returns 1 above alpha_threshold_fuel_rate, 0 at or below "
       "alpha_reset_fuel_rate, else the old value; the orchestrator stores it and ORs it into the alpha ramp condition; the "
       "old name says cold start",
    4: "e2m 104A +E Fueling_AFC_State_Detected: cm848_selectFinalFueling sets it on AIR_FUEL_CONTROL_DERATE / "
       "COMBUSTION_OXYGEN_LIMIT, cm848_checkPressureFuelDelayB reads it, timingProtectionFlagsOrchestrator clears it every "
       "alpha pass; the old name says cold start pressure",
    5: "e2m 104A +10 Fueling_LSG_State_Detected: cm848_selectFinalFueling sets it when final_fueling_state enters "
       "LOW_SPEED_GOVERNOR, cm848_checkPressureFuelDelayA / B and cm848_calculateSensorEma read it, the orchestrator clears "
       "it every alpha pass; the old name says cold start",
    6: "e2m 104A +14 Filtered_Fuel_Delivery_Rate (LB/HR): cm848_calculateSensorEma filters fuel_mass_flow_raw into it and "
       "compares it with alpha_reset_fuel_rate / alpha_threshold_fuel_rate; a fuel rate, not an intake temperature",
    7: "e2m 104A +1A Alpha_Altitude_Derate_Timer: cm848_checkPressureFuelState reloads it with altitude_derate_alpha_timeout "
       "while final_fueling_state is ALTITUDE_DERATE and counts it down after that; the old name says governor init",
    13: "e2m 107C +2 ASG_Error_Difference: cm848_runOperatingModeSpeedGovernor stores the new speed error minus the previous "
        "pass error (clamped +-32000) and feeds both PID difference equations with it; the old name says PID input; type "
        "note: e2m signed, the decompile casts it to short (row is word)",
    14: "e2m 107C +4 ASG_Feedback_Difference: cm848_runOperatingModeSpeedGovernor stores governor_rpm_actual minus the "
        "previous pass speed clamped to +-8000 (the 0xe0c0 / 8000 stores) and subtracts it times a gain in both PID "
        "equations; the old name says previous output; type note: e2m signed, cast to short (row is word)",
    15: "e2m 107C +A ASG_Fueling [ASFL] (alias ASG_100_Fueling shares +A, no table read here): "
        "cm848_runOperatingModeSpeedGovernor clamps correction + no-load fuel + ASG delta between "
        "governor_fuel_demand_tracking_floor / _limit into it; cm848_calculateEffectiveFuelLimit uses it in the droop equation",
    16: "e2m 107C +C ASG_State_X1: cm848_runOperatingModeSpeedGovernor stores governor_reference_speed_filtered minus "
        "governor_rpm_actual (clamped +-32000) every pass and reads the old value as the previous error; an external reset "
        "seeds it from all_speed_governor_reset_state_speed_error_previous; type note: lha, e2m signed (row is word)",
    17: "e2m 107C +14 ASG_State_X6: cm848_runOperatingModeSpeedGovernor computes (x5 x gain - previous x5 x gain + x6 x gain) "
        ">> 8 clamped to +-0x1700 and adds it to the no-load fuel for the governor fueling; seeded from "
        "all_speed_governor_reset_state_fuel_demand_correction; type note: lha, e2m signed (row is word)",
    18: "e2m 107C +56 ASG_Delta: cm848_runOperatingModeSpeedGovernor integrates final_fueling minus the governor fueling into "
        "it in the low speed governor state and decays it above idle (limit fuel_demand_integrator_upper_limit); added to the "
        "governor fueling and to the droop equation of cm848_calculateEffectiveFuelLimit; the old name says integrator",
    19: "e2m 107C +5A Decel_Rate_I_Term: first word of the dword; cm848_runOperatingModeSpeedGovernor adds gain x (engine_rpm_delta - offset) >> 8 per pass, clamped 0..fuel_demand_integrator_b_limit, zero below rpm_drop_fuel_minimum_manifold_pressure; type note: the dword covers two words (I term here, P term at 0x40a206 = e2m +5C Decel_Rate_P_Term, so the row needs splitting)",
    20: "e2m 1100 +0 J1939_Engine_Control_Status: governor_sourceData_init(0) sets it when j1939_tsc1_override_state.governor_mode "
        "becomes non-zero with etc1_active_state 1, phase_group_a_setupETC1Controller clears it when the control ends and "
        "stores the session in the J1939 history table; EEPROM mirror, so _cal",
    21: "e2m 1100 +2 J1939_Retarder_Control_Status: governor_sourceData_init(1) sets it when engine_retarder_override_control_mode "
        "is non-zero, phase_group_a_setupETC1Controller clears it when the control ends and stores the session in the J1939 "
        "history table; EEPROM mirror, so _cal",
    22: "e2m 1100 +8 J1939_History_Table_Next_Entry: governor_calibSnapshot_rollingBuffer_update copies the finished engine / "
        "retarder control session record (12 words from 0x3feb50 / 0x3feb6a) into slot this, then adds 1 wrapping 5 to 0 "
        "(5 x 24 bytes = e2m 10FD J1939_History_Table at 0x3fead4); EEPROM mirror, so _cal",
    23: "e2m 1143 +0 Fuel_Temperature_Fueling_Index (1/256): word 0 of the 30-byte record of the single fault derate channel "
        "(fuel temperature, ROM 0x597b2); cm848_calculateFaultDerateFuelLimit stores the fueling derate level (0..256) there "
        "(*pwVar4 = level); word 1 is fuel_temperature_derate_engine_speed_severity_index_cal; EEPROM mirror, so _cal",
    24: "e2m 1227 +0 Intake_Air_Heater_Status [JCGPSS]: cm848_j1939HandlePgn58112Dm7 sends it as the test-0 value of its PGN "
        "65232 (DM8) answer (test 1 = misfire_monitor_result, e2m 1227 +2) and cm848_j1939HandlePgn65230Dm5Readiness reads "
        "it; 2 loads, no store in ROM / flash2, so 0; the intake air heater attribution is from the e2m name and test order; "
        "the old name says DM1 response mode",
    25: "e2m 162B +A IAH_Function_Timer (SEC 0.1, 0..60) resolves to 0x40b9ee, the base of the misfire attempt count array (e2m "
        "1651 +0 Misfire_Cyl_1_Attempt_Number resolves there too: cm848_resetMisfireMonitorTest zeroes slot n, "
        "cm848_evaluateMisfireMonitorCylinderResponse counts attempts against misfire_monitor_attempt_limit); the IAH words "
        "end at +8 (0x40b9ec intake_air_heater_performance_test_state) and nothing counts IAH driver on-time, so 162B +A / +C "
        "(IAH_Ratio = 0x40b9f0, the second misfire slot) are a tail without a counterpart (drift); keep the name",
    26: "e2m 1735 +2 C_CBP_Residual_Mass_Min (MM3S): cm848_calculateResidualGasMass floors cylinder_residual_gas_mass at it, a mass "
        "limit and not a boost pressure ratio; its twin at 0x4062d2 (e2m C_CBP_Residual_Mass_Max, "
        "boost_pressure_ratio_upper_limit) has the same wrong name",
    27: "e2m 175F +2 TPE_Corrected_Turbo_Speed: cm848_estimateCompressorOutletTemperature stores turbocharger_speed x 0x106 / 10000 "
        "x 0x28b0b / compressor_inlet_temperature_square_root (cap 65535) and uses it as the y input of the compressor map "
        "lookup; cm848_calculateBoostTorqueOffset uses it as the input of three lookups; the old name says fuel timing",
    28: "e2m 175F +6 TPE_CIT_Sqrt: cm848_estimateCompressorOutletTemperature looks it up from ambient_air_temperature_selected "
        "(fuel_timing_correction_b_*) and multiplies the air flow / divides the turbo speed by it; "
        "cm848_estimateTurbochargerSpeed multiplies the corrected speed by it; dump 2122 = 16.58 = sqrt(275 K)",
    29: "e2m 175F +C TPE_COT_Est_Enable: cm848_selectCompressorOutletTemperature sets it to 0 when bit 0x80 of "
        "feature_enable_flags_cal is clear or both source states are 2 (compressor_outlet_temperature = "
        "fuel_flow_rate_default_cal), else 1 (the estimate is used); the old name says fuel timing range",
    30: "e2m 1781 +2 CHP_Pumping_Torque_Adj: cm848_calculateBoostPressureOffset turns nominal delta-P minus egr_delta_pressure_negated into torque and clamps it; cm848_calculateNetCombustionTorque subtracts it from the combustion torque (net = gross - it), cm848_applyProtectionRpmCorrectionFilter adds it to the friction torque; type note: lha, e2m signed (row is word)",
    31: "e2m 17A1 +0 Temperature_Delta (DEG_F 0.5, 0..1500): cm848_calculateCombustionTemperatureRise stores (boost_target_load_rpm_output << 8) / charge_fuel_ratio capped at 3000 = 1500 F; cm848_auxiliaryControl_exponentialAverage copies it to exhaust_temperature_rise_over_intake_manifold_temperature and adds it to 2 x the intake manifold temperature for exhaust_temperature; not a boost target",
    32: "e2m 17A1 +6 TPE_Invalid_Model: cm848_auxiliaryControl_exponentialAverage sets it when current_rpm < 8 counts or "
        "charge_fuel_ratio < 128 and then skips cm848_calculateCombustionTemperatureRise (rise word = 0, "
        "exhaust_temperature_source 1); it blocks the exhaust temperature model, not a boost target calculation",
    33: "e2m 191A +0 WIF_Miles (MI, 1/256, EEPROM 0x1a36): meaning kept, the name gains _cal (0x3feeb8 is in the EEPROM mirror); "
        "cm848_monitorWaterInFuelDistance accumulates it while P2269 is active and zeroes it while clear; e2m 1930 +12 "
        "AATR_Numerator resolves here too (the drifted tail of block 1930), this record is the one the code matches",
    34: "e2m 1921 +6 Ambient_Air_Tmptr (DEG_F 1/64): hpcr_fuelFinal_exponentialAverage stores the override, the default (source state 2) or the filtered ambient_air_temperature_selected minus compressor_inlet_temperature_rise; cm848_blendBoostAndThrottleFuelDemand looks up the water saturation vapor pressure with it (cap 90 F); the old name says boost fuel demand blend; type note: lha, e2m signed (row is word)",
    35: "e2m 1921 +A Compressor_Inlet_Press: hpcr_fuelFinal_exponentialAverage stores barometric_pressure_selected (minus "
        "boost_fuel_pressure_offset_lookup when barometric_pressure_sensor_senses_ambient_air_flag_cal is set), floored at 1; "
        "divisor of the charge pressure ratio in cm848_estimateTurbochargerSpeed and of the corrected air flow in "
        "cm848_estimateCompressorOutletTemperature; the old name says fuel scale divisor",
    36: "e2m 1921 +10 Compressor_Inlet_Tmptr_Rise (DEG_F 1/64): hpcr_fuelFinal_exponentialAverage looks it up on the filtered "
        "fresh air mass flow and vehicle_speed_copy and subtracts it from ambient_air_temperature_selected (also "
        "cm848_initialization_step_3); the old name says boost fuel timing target",
    37: "e2m 1921 +14 Ambient_Relative_Humidity (1/1024, dump 1024 = saturated): cm848_blendBoostAndThrottleFuelDemand multiplies "
        "ambient_saturation_vapor_pressure by it >> 10 for ambient_water_vapor_partial_pressure; "
        "hpcr_fuelFinal_exponentialAverage looks it up on engine speed and injection_quantity_combustion_reference; the old "
        "name says rpm blend scale",
    41: "e2m 8000 +20 HPCR_Max_Scaling_Current_Compensation (1/4096, dump 2049 = 0.5): cm848_calculateFuelMeteringCommand limits the "
        "PI sum on fuel_metering_feedback_error to it (command = base + trim x base / 4096); ROM-copied constant, so no _cal; "
        "the old name says engine sync protection; type note: lha, e2m signed (row is word)",
    42: "e2m 8000 +22 HPCR_Min_Scaling_Current_Compensation (1/4096, dump -2049 = -0.5): the lower clamp of the same PI trim sum in "
        "cm848_calculateFuelMeteringCommand; ROM-copied constant, so no _cal; the old name says engine sync protection; type "
        "note: lha, e2m signed (row is word)",
    43: "e2m 8000 +32 HPCR_Fuel_Pressure_Filter_Constant (1/65536): cm848_resetEngineSyncState points "
        "fuel_pressure_sensor_filter.coefficient at it and cm848_calculateFuelMeteringCommand uses it for the filter on "
        "fuel_pressure_sensor whose output feeds the derivative term; ROM-copied constant, so no _cal; the old name says engine "
        "sync scale",
    49: "e2m 819B +A Backup_Lost_Counter [ESTMCU02]: mpc555_updateEngineCrankState (TPU-A channel 1 interrupt) reloads it with "
        "crank_sync_timing_scale_working on every tooth capture, cm848_updateEngineSpeedFromCrankSignal counts it down and "
        "zeroes crank_tooth_rpm at 0; primary twin crank_period_countdown (e2m +32); the old name says engine sync startup",
    50: "e2m 819B +30 Low_Speed_Filtering: cm848_updateEngineSpeedFromCrankSignal sets it to 1 when engine_rpm_measured is below "
        "crank_speed_setpoint_threshold_cal (low speed TPU-A parameters) and 0 above it; mpc555_resetEngineTimingAccumulators "
        "starts it at 1; 3 stores, no reader; the old name says crank sync valid",
    52: "e2m 819B +42 PMA_Good_Window (1/64, dump 64 = 1.0): cm848_updateEngineSpeedFromCrankSignal looks it up from "
        "engine_rpm_measured and programs the TPU-A channel 1 window bytes 0x40 +- (this >> 1), a symmetric window around a "
        "ratio of 1.0; the old name says MIOS timing output",
    54: "e2m 819B +60 First_Speed_ISR_Time: hpcr_processEngineSyncPulses (TPU-A channel 11 speed interrupt) stores TBLr here "
        "once while it is 0; engine_state_crank_time / _run_time, crank_tooth_period_tbl and crank_event_timebase_a / b / c "
        "are TBLr minus it; the old name says previous capture",
    55: "e2m 819B +64 Crank_Resync_Time: TBLr minus first_speed_interrupt_time_ticks, stored with crank_tbl_event_counter (e2m "
        "Crank_Resync_Count) at each re-sync in 6 places (hpcr_processEngineSyncPulses, mpc555_updateEngineRunState, "
        "mpc555_updateEngineCrankState); the old name is only a generic timebase delta",
    56: "e2m 819B +7A HPCR_Fuelpr_Start_Undershoot (MPa 0.0488, dump 4095 = 199.8 MPa = the e2m maximum): "
        "hpcr_processEngineSyncPulses lowers it to fuel_pressure_sensor in engine run state 3, "
        "mpc555_resetEngineTimingAccumulators sets 0xfff when it is 0; the old name says cam sync position; type note: "
        "compared as short and the e2m is signed (i16), check lha / lhz before retyping",
    57: "e2m 8A0E +2 Coast_Accel_Timer (SEC 0.04, dump 13 = 0.52 s): governor_cruise_coastButton_handler / _setButton_handler / "
        "_resumeButton_handler load governor_cruiseOverride_holdoff_countdown with it on a button press and the held button "
        "becomes CRUISE_DECELERATE / CRUISE_ACCELERATE when it reaches 0; the old name is camelCase and says override",
}
COMMENTS = {
    0: "e2m 0033 +8 Collector_Start_Address 'Logical beginning address of the data collector buffer' (HEX): the read / tail pointer of the data collector ring buffer, the oldest byte still held (center 0x40c27c, end = write pointer 0x40c280): diag_dm1Buffer_circularFill advances / wraps it when the write pointer catches it, j1939_dm1_diagnosticMessage_send moves it past the bytes it sends. The diag_dm1_buffer_* words are the data collector, not DM1.",
    2: "e2m 104A +2 Alpha_Base '[APAPBA] Result of AFC, LSG, On Governor, and Fuel Rate alpha comparison' (UNITLESS, "
       "1/16384 per count): the base alpha ramp: timingProtectionFlagsOrchestrator zeroes it while no alpha condition is "
       "set, else adds alpha_ramp_rate_below_threshold / _at_or_above_threshold per pass up to 0x4000 (1.0); "
       "hpcr_calculateFuelTrimOutput outputs it as combustion_alpha_input (state 0).",
    3: "e2m 104A +8 Alpha_Fuel_Rate '[APFLRTAP] result of Fuel Rate algorithm' (UNITLESS): the fuel rate alpha condition: "
       "cm848_calculateSensorEma returns 1 while alpha_filtered_fuel_delivery_rate is above alpha_threshold_fuel_rate, 0 at "
       "or below alpha_reset_fuel_rate, else the old value; timingProtectionFlagsOrchestrator stores it and ORs it into the "
       "alpha ramp condition (alpha_base).",
    4: "e2m 104A +E Fueling_AFC_State_Detected '[FLAFSTFG] semaphore used to latch AFC events that occur between alpha "
       "executions' (UNITLESS): set to 1 by cm848_selectFinalFueling when final_fueling_state is AIR_FUEL_CONTROL_DERATE or "
       "COMBUSTION_OXYGEN_LIMIT; read by cm848_checkPressureFuelDelayB (air fuel control alpha) and cleared each alpha "
       "execution by timingProtectionFlagsOrchestrator.",
    5: "e2m 104A +10 Fueling_LSG_State_Detected '[FSLSSTFG] semaphore used to latch LSG events that occur between alpha "
       "executions' (UNITLESS): set to 1 by cm848_selectFinalFueling when final_fueling_state enters LOW_SPEED_GOVERNOR; "
       "read by cm848_checkPressureFuelDelayA / B and cm848_calculateSensorEma (filter restart); cleared each alpha "
       "execution by timingProtectionFlagsOrchestrator and by cm848_initFuelPressureVariables.",
    6: "e2m 104A +14 Filtered_Fuel_Delivery_Rate '[APFLDLRT] fuel rate, after filtering, which alpha uses in comparison to "
       "trigger Fuel_Rate' (LB/HR, 0.1 per count): cm848_calculateSensorEma filters fuel_mass_flow_raw into it and compares "
       "it with alpha_reset_fuel_rate / alpha_threshold_fuel_rate; hpcr_calculateFuelTrimOutput zeroes it with the engine "
       "stopped or cranking. Not an intake temperature.",
    7: "e2m 104A +1A Alpha_Altitude_Derate_Timer (SEC, 0.2 per count): the altitude derate alpha latch timer: "
       "cm848_checkPressureFuelState reloads it with altitude_derate_alpha_timeout every pass while final_fueling_state is "
       "ALTITUDE_DERATE and counts it down after that (0 when bit 0x20 of feature_enable_flags_cal is clear).",
    13: "e2m 107C +2 ASG_Error_Difference '[ASERDC] ASG error difference' (RPM, 0.125 per count, signed): the change of the "
        "speed error between two passes in cm848_runOperatingModeSpeedGovernor: the new error "
        "(all_speed_governor_state_speed_error) minus the previous pass error, clamped to +-32000; the error-difference term "
        "of both PID difference equations.",
    14: "e2m 107C +4 ASG_Feedback_Difference '[ASFBDC] ASG feedback difference term' (RPM, 0.125 per count, signed): the "
        "change of the measured engine speed between two passes: governor_rpm_actual minus the previous pass speed "
        "(fuel_trim_pid_ema_snapshot; a reset seeds it from all_speed_governor_reset_state_engine_speed_previous, e2m "
        "ASG_Reset_State_X3), clamped to +-8000; subtracted times a gain in both PID equations.",
    15: "e2m 107C +A ASG_Fueling '[ASFL] ASG FUELING' (MM3S, 0.0679 per count; the alias ASG_100_Fueling [ASMXFL] 'from 4D "
        "tables' shares +A): the all-speed governor fueling: cm848_runOperatingModeSpeedGovernor clamps correction + no-load "
        "fuel + ASG delta between governor_fuel_demand_tracking_floor / _limit into it; cm848_calculateEffectiveFuelLimit "
        "uses it in the droop equation.",
    16: "e2m 107C +C ASG_State_X1 '[ASSTX1] ASG state X1' (RPM, 0.125 per count, signed): state 1 of the all-speed governor, "
        "the speed error governor_reference_speed_filtered minus governor_rpm_actual (clamped to +-32000), stored every pass "
        "by cm848_runOperatingModeSpeedGovernor; the old value is the previous error that a reset seeds from "
        "all_speed_governor_reset_state_speed_error_previous (e2m ASG_Reset_State_X1).",
    17: "e2m 107C +14 ASG_State_X6 '[ASSTX6] ASG state X6' (MM3S, 0.0679 per count, signed): state 6 of the all-speed "
        "governor, the PID's fuel correction: (x5 x gain - previous x5 x gain + x6 x gain) >> 8 clamped to +-0x1700 by "
        "cm848_runOperatingModeSpeedGovernor, added to the filtered no-load fuel for the governor fueling; a reset seeds it "
        "from all_speed_governor_reset_state_fuel_demand_correction.",
    18: "e2m 107C +56 ASG_Delta 'Calculated amount to add to ASG to eliminate LSG-ASG deadband' (MM3S): "
        "cm848_runOperatingModeSpeedGovernor integrates final_fueling minus the governor fueling into it in the low speed "
        "governor state (offset fuel_demand_integrator_offset_cal) and decays it above idle, limit "
        "fuel_demand_integrator_upper_limit; it is added to the governor fueling and to the droop equation of "
        "cm848_calculateEffectiveFuelLimit.",
    19: "e2m 107C +5A Decel_Rate_I_Term 'Integral term of rpm decel limit control' (MM3S): first word of the dword (proportional term = second word, e2m +5C): cm848_runOperatingModeSpeedGovernor adds fuel_demand_integrator_gain_a_cal x (engine_rpm_delta minus an offset) >> 8 per pass, clamped 0..fuel_demand_integrator_b_limit, zero below rpm_drop_fuel_minimum_manifold_pressure; it floors the governor output with the proportional term.",
    20: "e2m 1100 +0 J1939_Engine_Control_Status '[JCEGCOSS] J1939 ENGINE CONTROL STATUS 0 = INACTIVE' (0..1; EEPROM "
        "mirror): 1 while a J1939 engine control session is open: governor_sourceData_init(0) sets it when "
        "j1939_tsc1_override_state.governor_mode becomes non-zero with etc1_active_state 1, phase_group_a_setupETC1Controller "
        "clears it when the control ends and files the session in the J1939 history table.",
    21: "e2m 1100 +2 J1939_Retarder_Control_Status '[JCRDCOSS] J1939 RETARDER CONTROL STATUS 0 = INACTIVE' (0..1; EEPROM "
        "mirror): 1 while a J1939 retarder control session is open: governor_sourceData_init(1) sets it when "
        "engine_retarder_override_control_mode is non-zero, phase_group_a_setupETC1Controller clears it when the control "
        "ends and files the session in the J1939 history table.",
    22: "e2m 1100 +8 J1939_History_Table_Next_Entry '[JCHSTBPO] pointer into J1939_History_Table' (EEPROM mirror): index "
        "0-4 of the history slot written next: governor_calibSnapshot_rollingBuffer_update copies the finished engine "
        "(argument 0) or retarder (argument 1) control session record (12 words from 0x3feb50 / 0x3feb6a) into it (24 bytes "
        "each from 0x3fead6, e2m 10FD, length word 0x78 at 0x3fead4), then adds 1 and wraps 5 to 0.",
    23: "e2m 1143 +0 Fuel_Temperature_Fueling_Index '[EPFTFLIX] Fuel temperature fueling severity index.' (1/256 per "
        "count; EEPROM mirror): word 0 of the 30-byte record of the single fault derate channel (fuel temperature, ROM "
        "0x597b2; the channel loops step 15 words): cm848_calculateFaultDerateFuelLimit stores the fueling derate level "
        "(0-256) here; governor_faultDerate_mainLoop_update clears the active channel when it and word 1 are 0.",
    24: "e2m 1227 +0 Intake_Air_Heater_Status '[JCGPSS] Status from fault handler indicating OBDII def. of monitor status' "
        "(UNITLESS): the J1939 monitor status of the intake air heater test, twin of misfire_monitor_result (e2m 1227 +2): "
        "cm848_j1939HandlePgn58112Dm7 sends it as the test-0 value of its PGN 65232 (DM8) answer, "
        "cm848_j1939HandlePgn65230Dm5Readiness reads it; no store anywhere in ROM / flash2, so 0.",
    26: "e2m 1735 +2 C_CBP_Residual_Mass_Min 'Min limit on residual mass estimation' (MM3S, 0.1359 per count): the floor "
        "that cm848_calculateResidualGasMass applies to cylinder_residual_gas_mass (the ceiling is the row at 0x4062d2, e2m "
        "C_CBP_Residual_Mass_Max); ROM-copied constant. Not a boost pressure ratio.",
    27: "e2m 175F +2 TPE_Corrected_Turbo_Speed 'Turbo speed input to compressor map in corporate units' (1/256 per count): "
        "the corrected turbocharger speed: cm848_estimateCompressorOutletTemperature stores turbocharger_speed x 0x106 / "
        "10000 x 0x28b0b / compressor_inlet_temperature_square_root (cap 65535) as the y input of the compressor map "
        "lookup; cm848_calculateBoostTorqueOffset uses it as the input of three lookups. dump 4241.",
    28: "e2m 175F +6 TPE_CIT_Sqrt 'Square root of CIT' (1/128 per count, 10..30): "
        "cm848_estimateCompressorOutletTemperature looks it up from ambient_air_temperature_selected "
        "(fuel_timing_correction_b_* tables), multiplies the fresh air mass flow by it and divides the turbocharger speed by "
        "it (corrected flow / speed); cm848_estimateTurbochargerSpeed multiplies the corrected speed by it. dump 2122 (16.58 "
        "= sqrt of 275 K).",
    29: "e2m 175F +C TPE_COT_Est_Enable 'Indicates whether the compressor estimation is active.' (UNITLESS, 0..1): "
        "cm848_selectCompressorOutletTemperature sets it to 0 when bit 0x80 of feature_enable_flags_cal is clear or both "
        "source states are 2 (compressor_outlet_temperature = the default fuel_flow_rate_default_cal) and to 1 otherwise "
        "(cm848_estimateCompressorOutletTemperature is used). dump 1.",
    30: "e2m 1781 +2 CHP_Pumping_Torque_Adj 'Used by CBR in determination of gross fuel from net torque cmd' (FT*LB): the pumping torque adjustment between net and gross torque: cm848_calculateBoostPressureOffset turns the nominal delta-P minus egr_delta_pressure_negated into torque (plus an offset, clamped); cm848_calculateNetCombustionTorque subtracts it from the combustion torque, cm848_applyProtectionRpmCorrectionFilter adds it to the friction torque.",
    31: "e2m 17A1 +0 Temperature_Delta 'Difference between IMT and exhaust temperature' (DEG_F, 0.5 per count): the exhaust temperature model's rise over the intake manifold temperature: cm848_calculateCombustionTemperatureRise stores boost_target_load_rpm_output << 8 / charge_fuel_ratio (floor 128) capped at 3000 (1500 F); cm848_auxiliaryControl_exponentialAverage passes it on (0 while the model is invalid).",
    32: "e2m 17A1 +6 TPE_Invalid_Model 'Set to TRUE to protect against divide by zero in model' (UNITLESS, 0..1): "
        "cm848_auxiliaryControl_exponentialAverage sets it to 1 when current_rpm is below 8 counts (1 rpm) or "
        "charge_fuel_ratio is below 128, else 0; while it is 1 cm848_calculateCombustionTemperatureRise is skipped (rise = 0) "
        "and exhaust_temperature_source is 1. dump 1. Not a boost target inhibit.",
    33: "e2m 191A +0 WIF_Miles 'Actual miles for WIF too long' (MI, 1/256 per count; EEPROM 0x1a36): persistent distance "
        "with P2269 water in fuel active (1/256 mile per count if the task runs every 100 ms): zeroed while P2269 is clear, "
        "at 128000 (0x40a026, 500 miles at that rate) it sets P0169 (fault_detected_bits_336_to_351 bit 0). EEPROM-backed, "
        "so _cal. e2m 1930 +12 AATR_Numerator resolves here too (drifted block tail).",
    34: "e2m 1921 +6 Ambient_Air_Tmptr 'Ambient Air Temperature' (DEG_F): the ambient air temperature of the air handling models, reference twin of ambient_air_temperature_selected: hpcr_fuelFinal_exponentialAverage stores an override, the default (source state 2) or the filtered ambient_air_temperature_selected minus compressor_inlet_temperature_rise; cm848_blendBoostAndThrottleFuelDemand takes the water saturation vapor pressure at it. dump 1620.",
    35: "e2m 1921 +A Compressor_Inlet_Press 'Compressor_Inlet_Pressure' (IN_HG): hpcr_fuelFinal_exponentialAverage stores "
        "barometric_pressure_selected (minus the inlet pressure drop boost_fuel_pressure_offset_lookup when "
        "barometric_pressure_sensor_senses_ambient_air_flag_cal is set), floored at 1; divisor of the charge pressure ratio "
        "(cm848_estimateTurbochargerSpeed) and of the corrected air flow (cm848_estimateCompressorOutletTemperature). dump "
        "1647.",
    36: "e2m 1921 +10 Compressor_Inlet_Tmptr_Rise 'Temperature rise from ambient to compressor inlet' (DEG_F): "
        "hpcr_fuelFinal_exponentialAverage looks it up in a dual-axis table of the filtered fresh air mass flow and "
        "vehicle_speed_copy; ambient_air_temperature_selected minus it (filtered) is ambient_air_temperature_reference "
        "(cm848_initialization_step_3 subtracts it once at start). dump 640 (10 F).",
    37: "e2m 1921 +14 Ambient_Relative_Humidity 'Relative humidity of ambient air (0 = dry air, 1 = saturated air).' "
        "(UNITLESS, 1/1024 per count): hpcr_fuelFinal_exponentialAverage looks it up on engine speed and "
        "injection_quantity_combustion_reference; cm848_blendBoostAndThrottleFuelDemand multiplies "
        "ambient_saturation_vapor_pressure by it >> 10 for ambient_water_vapor_partial_pressure. dump 1024 (saturated).",
    41: "e2m 8000 +20 HPCR_Max_Scaling_Current_Compensation 'Maximum scaling factor for current compensation' (1/4096 per "
        "count, signed): the upper clamp of the fuel metering feedback trim: cm848_calculateFuelMeteringCommand limits the "
        "PI sum on fuel_metering_feedback_error to it (command = base + trim x base / 4096). ROM-copied constant, no _cal. "
        "dump 2049 (0.5).",
    42: "e2m 8000 +22 HPCR_Min_Scaling_Current_Compensation 'Minimum scaling factor for current compensation' (1/4096 per "
        "count, signed): the lower clamp of the fuel metering feedback trim (twin of "
        "fuel_metering_feedback_trim_maximum_scaling_factor): cm848_calculateFuelMeteringCommand limits the PI sum on "
        "fuel_metering_feedback_error to it. ROM-copied constant, no _cal. dump -2049 (-0.5).",
    43: "e2m 8000 +32 HPCR_Fuel_Pressure_Filter_Constant 'Fuel pressure filter constant for Derivative Component' (1/65536 "
        "per count): the base coefficient of fuel_pressure_sensor_filter, the filter cm848_calculateFuelMeteringCommand runs "
        "on fuel_pressure_sensor before the derivative term (setpoint minus filtered pressure); cm848_resetEngineSyncState "
        "points the filter at it. ROM-copied constant, no _cal. dump 43693.",
    49: "e2m 819B +A Backup_Lost_Counter '[ESTMCU02] Backup_Lost_Counter: Timeout counter for secondary speed input' (CNTS): "
        "the lost-signal timeout counter of the tooth (secondary) speed input: mpc555_updateEngineCrankState (TPU-A channel 1 "
        "interrupt) reloads it with crank_sync_timing_scale_working on every tooth capture, "
        "cm848_updateEngineSpeedFromCrankSignal counts it down and zeroes crank_tooth_rpm at 0. Primary twin: "
        "crank_period_countdown.",
    50: "e2m 819B +30 Low_Speed_Filtering 'Flag indicating low speed operation' (UNITLESS): "
        "cm848_updateEngineSpeedFromCrankSignal sets it to 1 when engine_rpm_measured is below "
        "crank_speed_setpoint_threshold_cal (loading the low speed TPU-A channel 0 / 1 parameters) and to 0 above it; "
        "mpc555_resetEngineTimingAccumulators starts it at 1; written only (3 stores). dump 1.",
    52: "e2m 819B +42 PMA_Good_Window 'Tooth fraction defining expected normal tooth location' (1/64 per count): "
        "cm848_updateEngineSpeedFromCrankSignal looks it up from engine_rpm_measured and programs the TPU-A channel 1 "
        "(tooth capture) window bytes 0x40 +- (this >> 1), a symmetric window around a ratio of 1.0 (0x40); "
        "mpc555_resetEngineTimingAccumulators resets it to 0. dump 64 (1.0).",
    54: "e2m 819B +60 First_Speed_ISR_Time 'Global ECM start time information of POR time to 1st Speed ISR Time' (MSEC, "
        "0.0004 per count): the time base (TBLr) captured once by hpcr_processEngineSyncPulses (TPU-A channel 11 speed "
        "interrupt) on the first speed interrupt after power-on reset; engine_state_crank_time / _run_time, "
        "crank_tooth_period_tbl, crank_event_timebase_a / b / c and crank_resync_time_ticks are TBLr minus it.",
    55: "e2m 819B +64 Crank_Resync_Time 'First speed isr time to Last Crank Re-Sync Time' (MSEC): the time base time from the "
        "first speed interrupt (first_speed_interrupt_time_ticks) to the latest crank re-sync, TBLr minus it, stored with "
        "the re-sync count crank_tbl_event_counter (e2m Crank_Resync_Count) at each re-sync in "
        "hpcr_processEngineSyncPulses, mpc555_updateEngineRunState and mpc555_updateEngineCrankState.",
    56: "e2m 819B +7A HPCR_Fuelpr_Start_Undershoot 'Global ECM start time information of HPCR_Fuel_Pressure Undershoot.' "
        "(MPa, 0.0488 per count): the lowest rail pressure sensor reading during the start: hpcr_processEngineSyncPulses "
        "lowers it to fuel_pressure_sensor in engine run state 3 when the sensor is below it; "
        "mpc555_resetEngineTimingAccumulators sets it to 0xfff (4095 = 199.8 MPa, the e2m maximum) when it is 0. dump 4095.",
    57: "e2m 8A0E +2 Coast_Accel_Timer 'Amount of time bump must be held before transitioning to coast/accel' (SEC, 0.04 "
        "per count): the reload of the cruise switch hold-off countdown governor_cruiseOverride_holdoff_countdown: the coast, "
        "set and resume button handlers (governor_cruise_*Button_handler) load it on a press and the held button becomes "
        "CRUISE_DECELERATE / CRUISE_ACCELERATE when it reaches 0. ROM-copied constant. dump 13 (0.52 s).",
}
for i, text in COMMENTS.items():
    assert entries[i]["verdict"] == "confirmed", i
    entries[i]["comment"] = text

EVIDENCE[22] = ("e2m 1100 +8 J1939_History_Table_Next_Entry: governor_calibSnapshot_rollingBuffer_update copies the finished "
                "engine / retarder control session record (12 words from 0x3feb50 / 0x3feb6a) into slot this (base 0x3fead6 "
                "from the asm: e2m 10FD starts at 0x3fead4 with the length word 0x78), then adds 1 wrapping 5 to 0; EEPROM "
                "mirror, so _cal")
EVIDENCE[14] = ("e2m 107C +4 ASG_Feedback_Difference: cm848_runOperatingModeSpeedGovernor stores governor_rpm_actual minus the "
                "previous pass speed clamped to +-8000 (the 0xe0c0 / 8000 stores) and subtracts it times a gain in both PID "
                "equations; the old name says previous output; type note: e2m signed, cast to short (row is word)")
for i, text in EVIDENCE.items():
    assert entries[i]["verdict"] in ("confirmed", "drift"), i
    entries[i]["evidence"] = text

assert sorted(entries) == list(range(len(bin_))), sorted(set(range(len(bin_))) - set(entries))
with open(OUT, "w") as f:
    for i in range(len(bin_)):
        f.write(json.dumps(entries[i], ensure_ascii=True) + "\n")
print("wrote", len(bin_), "lines to", OUT)
