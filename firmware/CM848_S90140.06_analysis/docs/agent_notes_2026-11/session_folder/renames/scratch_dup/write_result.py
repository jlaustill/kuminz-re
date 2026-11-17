import json, re, bisect

ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
OUT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W3_duplicates.jsonl'
dups = json.load(open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/duplicates.json'))

# function lookup for the switchD rows
fs = []
for l in open(ROOT + 'cm848_rom.ghidra.cpp', errors='replace'):
    m = re.match(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)', l)
    if m:
        fs.append((int(m.group(2), 16), m.group(1)))
fs.sort()
keys = [a for a, _ in fs]


def containing(addr):
    a = int(addr, 16)
    j = bisect.bisect_right(keys, a) - 1
    return fs[j][1] if j >= 0 else '?'


rows = []


def G(address, old, new, evidence):
    rows.append({"kind": "global", "address": address, "old": old, "verdict": "confirmed", "new": new, "evidence": evidence})


def F(address, old, new, plate, evidence):
    rows.append({"kind": "function", "address": address, "old": old, "verdict": "confirmed", "new": new, "plate_comment": plate, "evidence": evidence})


def N(text):
    rows.append({"kind": "note", "text": text})


# ---------------- globals ----------------
G("0x003fb08e", "protection_confirm_counter_a", "load_protection_condition_absent_counter",
  "0x003fb0a8 keeps protection_confirm_counter_a (the up/down counter of cm848_updateLoadProtectionConfirmCounterB, whose value is copied to protection_confirm_counter_a_snapshot at 0x003fb0b0). 0x003fb08e is a different counter, used only by cm848_evaluateLoadProtectionOverspeedStage and cleared by cm848_clearLoadProtectionConfirmState: it is reset to 0 while protection_fault_condition_flag (either half) or fault_threshold_condition_flag is set, otherwise it counts up one per pass and saturates at protection_confirm_limit_cal; the stage then compares it with the threshold returned in r4 by cm848_calculateLoadProtectionDeviationFlag to set governor_overspeed_threshold_flag. So it counts the passes in which the load protection condition has been absent. xref_addr.py: word, 2 reads / 2 writes at 0x003fb08e.")
G("0x003fb0c4", "protection_confirm_counter_b", "protection_confirm_delay_counter_b",
  "0x003fb0c6 keeps protection_confirm_counter_b (stage 2 of cm848_updateLoadProtectionConfirmCounterA: the up/down counter against protection_confirm_limit_b_cal, its value is copied to protection_confirm_counter_b_snapshot at 0x003fb0ce). 0x003fb0c4 is stage 1 of the same function (code at 0x2ee00-0x2ee1c, before the 0x2eeac-0x2eefc stage 2 accesses): it is cleared while protection_confirm_active_a is 0, otherwise counts up and saturates at protection_confirm_limit_a_cal, and protection_confirm_counter_b_match_flag (0x003fb0cc) = (limit == counter). That is an on-delay (persistence) counter. xref_addr.py: word, 2 reads / 1 write at 0x003fb0c4 and 3 reads / 1 write at 0x003fb0c6.")

G("0x003fd530", "j1939_tsc1_active_flag", "j1939_ccvs1_switch_logic_option_cal",
  "The name fits neither address; 0x0040b558 is not a TSC1 flag either (see its row). 0x003fd530 is inside the EEPROM-backed block (EEPROM offset 0xae; the original image holds 0x0000 there), is never written, and its only 4 reads are in cm848_buildPgn65265CruiseControlVehicleSpeedMessage (disassembly 0x243f8 / 0x2440c and 0x244d4 / 0x244e8), in the logic that fills the set and resume switch fields of byte 5 of CCVS1 (PGN 65265) from switch_input_state_bits[3] & 0x80. The code tests (flag = 0 and switch) or (flag != 0 and switch), so the output does not depend on its value. The new name states only what is verified (a cal option read by the CCVS1 builder); its true meaning is not settled. xref_addr.py: word, 4 reads / 0 writes.")
G("0x0040b558", "j1939_tsc1_active_flag", "accelerator_pedal_input_fault_flag",
  "Not TSC1: written only by cm848_processFuelDemandEnableFlag (0 or 1 after the two analog pedal channel cross-check: 1 = the channels disagree without a latched sensor fault, or a sensor fault is latched and it is not the channel B case with cruise_speed_target_min_cal <= the channel A idle threshold; it also zeroes governor_speed_demand_limit_prev when set) and read only by cm848_transitionEngineOperatingMode, where, on the branch that does not use the J1939 pedal flags (fuel_demand_feature_flags bit 0x2000 clear) and with fuel_demand_enable_flag set, it sends the engine into operating mode 6; the other branch of the same function uses j1939_accelerator_position_error_fallback_flag / j1939_pedal_input_timeout_active_flag for the same job. governor_speed_demand_limit is the 0..400 pedal position (it feeds fuel_demand_control_t.accelerator_off_idle). xref_addr.py: word, 1 read / 2 writes. Confidence moderate-high: the pedal reading is inferred from the code, no DTC is named.")

G("0x003fee46", "cruise_speed_target_working", "accelerator_pedal_idle_threshold_a_cal",
  "0x0040b6e4 keeps cruise_speed_target_working: it is the real cruise target (written and read in cm848_cruiseSpeedCommandStateMachine, written by cm848_validateFuelRateTarget, assigned from cruise_speed_high_limit / cruise_speed_command). 0x003fee46 is only touched by the dual pedal channel block: cm848_processCalibration12FuelDemand writes cruise_speed_setpoint_a + cruise_speed_setpoint_offset_cal into it (setpoint_a only ever moves down toward cruise_speed_current_a, i.e. a learned closed-pedal position), cm848_processOperatingModeFlags and cm848_processFuelDemandEnableFlag subtract it from cruise_speed_current_a, and cm848_processFuelDemandEnableFlag compares it with cruise_speed_target_min_cal. It is in the EEPROM-backed block (EEPROM offset 0x19c4 = 78 in the original image, the same as 0x003fee48, channel B), hence _cal. xref_addr.py: word, 4 reads / 1 write at 0x003fee46 and 5 reads / 5 writes at 0x0040b6e4.")
G("0x0040b556", "cruise_speed_setpoint_b", "accelerator_pedal_idle_position_b",
  "The name fits neither address. 0x0040b556 is channel B of the same dual pedal block: cm848_initFuelDemandLimits sets it to cruise_speed_setpoint_init, then cm848_processCalibration12FuelDemand moves it down by gain / 256 of (cruise_speed_current_b - itself) while the channel stays below setpoint + deadband for the debounce time and the settle count is not exhausted, and adds cruise_speed_setpoint_offset_cal to get cruise_speed_target_b. That is a learned closed-pedal position, not a cruise speed. xref_addr.py: word, 2 reads / 1 write in cm848_processCalibration12FuelDemand + 1 write in cm848_initFuelDemandLimits. Its twin cruise_speed_setpoint_a (0x0040b554) should be renamed with it (see note).")
G("0x0040b69a", "cruise_speed_setpoint_b", "cruise_governor_fuel_demand_lower_ramp_start",
  "Written once, by governorCruiseStateMachine (store at 0x525070), from governor_cruise_fuel_demand_setpoint (together with cruise_speed_setpoint_c), and read once, in cm848_processGovernorFuelRate: when cruise_speed_command < cruise_speed_setpoint_adjusted the output is cruise_speed_setpoint_b minus (difference x 1024 / cruise_speed_reference_a), clamped to 0..5888 (the governor_pid_fuel_output range), so it is the value the downward fuel ramp starts from, not a speed. xref_addr.py: word, 1 read / 1 write.")

G("0x00406fc4", "injection_timing_compensation_lower_cal", "injection_timing_compensation_limit_lower",
  "0x00406fcc keeps the name: cm848_calculateTimingCompensation clamps the accumulator between injection_timing_compensation_upper_cal (0x00406fce) and 0x00406fcc (load at 0x1f3d4). 0x00406fc4 is the lower bound in cm848_processTorqueLimitTiming (load at 0x1f908), whose upper bound is injection_timing_compensation_limit_cal (0x00406fc2): if (accumulator >> 16) >= limit the accumulator becomes limit << 16, if it is below 0x00406fc4 it becomes that value << 16. Both words are ROM-initialised and never written, outside 0x3fd482-0x3feec1, so the new name has no _cal (the kept name's _cal is legacy backlog).")

G("0x0040a8b1", "fuel_demand_mode_code", "fuel_demand_filter_coefficient_working_set_code",
  "0x0040a2f2 keeps fuel_demand_mode_code (written 0x1c / 0x1b by cm848_calculateRpmLoadTables, which also takes fuel_demand_mode_code_snapshot / _prev_snapshot, 0x19 by cm848_storeFuelDemandPreviousValues, 0 / 2 by cm848_processTorqueLimitState, read by cm848_calculateMainInjectionTiming together with torque_limit_arb_t.source_priority == 0x12). 0x0040a8b1 sits in the packed (odd-address, halfword access) block fuel_ema_coeff_3/4/2/1_working: cm848_processSystemStatusLimits writes 0x14 or 0x15 into it together with one of two ROM coefficient sets, and selectSensorRawChannels uses the working set and copies the code into fuel_demand_state_code when it is non-zero (0 = use the default or load-selected sets, codes 0x10 / 0x12 / 0x13). xref_addr.py: word, 1 read / 2 writes at 0x0040a8b1 and 3 reads / 3 writes at 0x0040a2f2.")
G("0x0040a404", "fuel_demand_rpm_factor", "boost_pressure_rpm_scale_factor",
  "0x0040a426 keeps fuel_demand_rpm_factor: cm848_calculateBoostTorqueOffset sets it from the rpm table lookupTableInterpolation(fuel_demand_rpm_axis_b_cal, fuel_demand_rpm_factor_values_cal) and multiplies it with fuel_demand_base_quantity. 0x0040a404 is computed by cm848_boostBasedFuelModifier from boost_pressure_state_t terms (boost_pressure_upper_limit_cal minus a pressure-ratio term, clamped between fuel_demand_rpm_factor_base_cal and fuel_demand_rpm_factor_upper_cal) and is a Q13 multiplier of engine rpm: cm848_throttleBasedFuelCalculation uses (factor x current_rpm) >> 13 and cm848_loadBasedFuelAdjustment uses rpm x factor x map_fuel_correction_factor ... / (load_input x 0xa200). It is the word right in front of boost_pressure_state_t (0x0040a406). xref_addr.py: 0x0040a404 word, 2 reads / 1 write; 0x0040a426 word, 0 reads / 1 write (the value stays in a register).")
G("0x0040a51e", "fuel_demand_rate_output", "fuel_demand_rate_raw_cached",
  "0x0040b53c keeps fuel_demand_rate_output: cm848_calculateFuelDemandLimit writes the rate-limited output there (limiter state +/- step, 0x1700 maximum) and cm848_trackFuelDemandMinimum reads it. 0x0040a51e is only a copy: cm848_storeFuelLimitValues does fuel_demand_rate_output = fuel_demand_rate_raw (0x0040a48a) next to fuel_blend_load_ratio_cached (0x0040a518) and fuel_demand_high_limit_cached (0x0040a51a), and cm848_calculateRpmLoadLimit reads it to cap fuel_demand_load_rate_cap at 0xc800. xref_addr.py: word, 2 reads / 1 write at 0x0040a51e and 2 reads / 2 writes at 0x0040b53c.")

G("0x0040ac34", "engine_data_log_buffer", "can_transmit_queue_buffer",
  "Two ring buffers share the name. 0x0040aacc keeps engine_data_log_buffer: 20 entries of 18 bytes (0x0040aacc + 20 x 18 = 0x0040ac34), wrap test against engine_data_log_buffer_limit (0x0040ac22), filled by mpc555_queueCanReceiveMessage from the TouCAN receive mailboxes (engine_data_log_write_ptr 0x0040ad2c, engine_data_log_full_flag) and drained by cm848_dispatchJ1939ReceivedMessages through engine_data_log_read_ptr (0x0040ad30). 0x0040ac34 is the transmit queue: 20 entries of 12 bytes (0x0040ac34 + 20 x 12 = 0x0040ad24), wrap test '0x40ad18 < pointer' in mpc555_sendJ1939SingleFrame (enqueue) and mpc555_processJ1939TxBufferSend (dequeue into the TouCAN transmit mailbox).")
G("0x0040ad24", "engine_data_log_read_ptr", "can_transmit_queue_enqueue_ptr",
  "0x0040ad30 keeps engine_data_log_read_ptr: it is the receive queue read pointer (cm848_dispatchJ1939ReceivedMessages 3 reads / 2 writes, mpc555_queueCanReceiveMessage compares the write pointer with it, cm848_j1939_system_init resets it). 0x0040ad24 is the transmit queue pointer that mpc555_sendJ1939SingleFrame uses to store a new 12-byte message (copies 6 halfwords to the slot at the pointer, then pointer += 12 with wrap at 0x40ad18) and that mpc555_processJ1939TxBufferSend compares with engine_data_log_write_sentinel (0x0040ad28, which advances when a frame is sent) to see whether the queue is empty, so it is the enqueue side despite the old 'read' name. xref_addr.py: dword, 0x0040ad24 1 read in mpc555_processJ1939TxBufferSend / 1 write in cm848_j1939_system_init (the other accesses go through a register copy), 0x0040ad30 4 reads / 3 writes.")

G("0x0040ae8c", "governor_setpoint_table_ptr", "governor_setpoint_table_requested_ptr",
  "0x0040ae90 keeps governor_setpoint_table_ptr: it is the pointer dereferenced in cm848_updateGovernorSetpointParameters (setpoint, d gain, p gain, extra gain words at +0 / +2 / +4 / +6) and the one cm848_selectGovernorSetpointSource (J1939 speed target table) and cm848_getGovernorOverrideSource (override table) write. 0x0040ae8c is the table chosen by the load and speed logic (cm848_processGovernorLoadCondition stores governor_setpoint_table_cal when the governor is active, cm848_processGovernorSpeedSetpoint stores the mode 2 / mode 3 cal tables); cm848_updateGovernorSetpointParameters copies it into 0x0040ae90 (lwz at 0x28a70 from 0x0040ae8c, stw at 0x28a74 to 0x0040ae90) only when no J1939 or override source applies, and falls back to governor_setpoint_table_a when governor_operational_mode_request is 0. xref_addr.py: dword, 0x0040ae8c 1 read / 2 writes, 0x0040ae90 1 read / 3 writes.")
G("0x0040b00e", "governor_speed_error_delta", "governor_speed_error_filtered_change",
  "0x0040aede keeps governor_speed_error_delta: cm848_calculateSpeedRateLimiting writes the clamped, filtered speed error there ((demand - rpm) x scale through cm848_signedFirstOrderFilter, clamped to DAT_0005c4b4..DAT_0005c4b2; governor_speed_error_rate is its change) and 5 other governor functions read it (6 reads). 0x0040b00e is written once, by cm848_calculateSpeedControlFiltered (store at 0x2cf80), as the sample-to-sample change of the filtered error (filter output minus governor_speed_error_filtered_snapshot); its absolute value is compared with governor_speed_i_gain_deadzone_cal to build governor_speed_i_term. xref_addr.py: word, 0x0040b00e 0 reads (the reads go through a register) / 1 write, 0x0040aede 6 reads / 2 writes.")

# ---------------- functions ----------------
F("0x00020aec", "emptyStubFunction3", "cm848_emptyStubFunction7",
  "Empty function: returns immediately (a single blr). Called once, from cm848_initPgn61443Eec2Handler. (was emptyStubFunction3)",
  "Both emptyStubFunction3 rows are a lone blr, so the shared name most likely came from fingerprint matching with the CM550 stub at 0x1b666, which cannot tell stubs apart; 0x0001806c (called once from cm848_applicationMain, just before cm848_throttlePositionProcessing) keeps the name. Callers found by scanning both banks for bl: 0x25dc0 -> 0x20aec, 0x54c84 -> 0x1806c.")
F("0x0001ec48", "cm848_processFaultIncrement", "cm848_clampFuelDemandToValidRange",
  "Clamps the signed 16-bit value at param_1 to the governor fuel demand range 0..5888: negative values become 0 and values above 5888 become 5888. Called after most dual-axis table interpolations in the fuel demand code (cm848_throttlePositionProcessing, cm848_calculateDualAxisFuelLimit and others). (was cm848_processFaultIncrement)",
  "The body only compares *param_1 with 0 and 0x1700 and stores the bound; nothing about faults or increments. 0x0001860c keeps cm848_processFaultIncrement: it is the table-driven two-stage counter (param_1[2] counts up by param_1[5] toward param_1[1] while param_1[0] is set, then an up/down counter param_1[4] with steps param_1[5] / param_1[6]), the same on-delay plus hysteresis pattern as the load protection confirm counters. bl callers of 0x1ec48: 0x180c0, eight in cm848_calculateDualAxisFuelLimit (0x1ed28..0x1f264), 0x27d98, 0x27de4, 0x3ef68, 0x3efc4 and flash2 0x524d70; of 0x1860c: only 0x1889c (cm848_processFaultStateWithFilter).")
F("0x000191a0", "mpc555_updateSensorDiagnosticFlags", "cm848_updateBoostFuelCorrectionSquaredAverage",
  "Calls cm848_calculateSensorDiagnosticValue to refresh boost_fuel_correction_input, then updates boost_fuel_correction_squared_ema with an exponential moving average of the input squared ((input x input) >> 13). Called from cm848_phase_group_b_processing. (was mpc555_updateSensorDiagnosticFlags)",
  "The name fits neither function. This one sets no flag at all: two statements, calculateSensorDiagnosticValue and the squared average. Its only cross-firmware match is a review-tier guess (CM550 FUN_0001c308, jaccard 0.50, firmware/cross_firmware_matches.csv). Caller: bl at 0xb87c in cm848_phase_group_b_processing.")
F("0x00044374", "mpc555_updateSensorDiagnosticFlags", "cm848_updateEngineSpeedFromCrankSignal",
  "Engine speed update from the crank signals: counts crank sync periods, sync events, cranking flag, start counter and sync timeouts against their cal limits (setting the crank sync fault bits), converts the crank period and tooth period into crank_derived_rpm / crank_tooth_rpm, selects one as engine_rpm_measured, filters it into engine_rpm_state.target_rpm / current_rpm, and reprograms the TPU-A channel 0 / 1 crank timing parameters from the rpm thresholds. Called from hpcr_periodicTaskSet_fuelFinal. (was mpc555_updateSensorDiagnosticFlags)",
  "Only the first part of the body sets diagnostic fault bits; the rest measures engine speed and programs the TPU. Its cross-firmware match is review-tier (CM550 epsPositionSensorIsrHandler 0x1e288, jaccard 0.20), consistent with an engine position (crank) sensor handler. Caller: bl at 0xb920 in hpcr_periodicTaskSet_fuelFinal.")
F("0x00053cd8", "cm848_addCoolantCalEntry", "cm848_refreshTsc1RequestEntry",
  "Looks up the TSC1 request list B (fault_entry_data_array, 6-byte entries of source address, override control mode and timeout) for the entry with source address param_1 and control mode param_2; if found it reloads the entry timeout from etc1_torque_mode_timeout_cal and returns 1, otherwise returns 0. Called by cm848_j1939ProcessGovernorRequest for every TSC1 request whose control mode is not 0. (was cm848_addCoolantCalEntry)",
  "It never adds anything: it searches and refreshes. 0x00053d3c keeps cm848_addCoolantCalEntry (it appends {param_1, param_2, param_3, timeout} to list A while coolant_cal_entry_count_a < 10; callers 0x27810 and 0x511e28 / 0x511e3c / 0x511e50 in cm848_updateParkNeutralFlagAndTsc1Activity). The 'coolant cal' wording is a domain error for the whole family: cm848_processCoolantCalEntries counts the timeouts down and on expiry clears j1939_tsc1_override_state fields for j1939_tsc1_auth_primary_sa, and the only search caller is the TSC1 receive handler (tsc1_rx_byte_0 & 3 = override control mode). Caller of 0x53cd8: bl at 0x237b4.")
F("0x00055e9c", "cm848_emptyStubFunction", "cm848_emptyStubFunction8",
  "Empty function: returns immediately (a single blr). No bl caller found in either bank. (was cm848_emptyStubFunction)",
  "Both cm848_emptyStubFunction rows are a lone blr. 0x00054220 (called once from cm848_applicationMain) keeps the name; 0x00055e9c has no bl caller in ROM or flash2 (reachable only through a pointer, if at all).")

# ---------------- junk rows ----------------
for addr, typ, cm in dups["globals"]["switchD"]:
    N(f"DELETE {addr} switchD: Ghidra switch-dispatch label (a switchD jump-table namespace entry) inside {containing(addr)}, not a data global; type and comment are empty and no code reads or writes it as data.")
N("DELETE 0x002fc22c USIU_RTCAL: duplicate register label, mpc555_registers.csv already defines USIU_RTCAL (u32, RTC Alarm Register) at 0x002fc22c; this row also types it byte; xref_addr.py finds no reference.")
N("DELETE 0x002fc248 USIU_PITR: duplicate register label, mpc555_registers.csv already defines USIU_PITR (u16, PIT Register) at 0x002fc248; xref_addr.py finds no reference.")
N("DELETE 0x002fc348 USIU_PITR: mislabel. The PIT register is at 0x002fc248 (mpc555_registers.csv); 0x002fc348 is in the key-register block (PISCRK 0x002fc340, PITCK 0x002fc344) where no register is defined, nothing references it, and the byte type is wrong.")
N("DELETE 0x002fc38c USIU_RTCAL: mislabel. RTCAL is at 0x002fc22c (its key RTCALK is 0x002fc32c); 0x002fc38c is in the key-register block, +0x100 from USIU_COLIR (0x002fc28c) like SCCRK / PLPRCK / RSRK, so it is most likely the COLIR key (add USIU_COLIRK to mpc555_registers.csv if wanted); nothing references it.")

# ---------------- notes ----------------
N("protection confirm counters: cm848_updateLoadProtectionConfirmCounterA (0x2edc0) and ...B (0x2f154) are two instances of the same two-stage pattern (stage 1 on-delay counter against protection_confirm_limit_a_cal, stage 2 up/down counter against protection_confirm_limit_b_cal), and the a / b / c suffixes cross the function letters: function A uses protection_confirm_counter_b (0x003fb0c4 stage 1, 0x003fb0c6 stage 2), function B uses protection_confirm_counter_c (0x003fb0a6 stage 1) and protection_confirm_counter_a (0x003fb0a8 stage 2). For a consistent set, rename 0x003fb0a6 protection_confirm_counter_c to protection_confirm_delay_counter_a (the stage 1 name used above for function A), and consider ..._hysteresis_counter_a / _b for 0x003fb0a8 / 0x003fb0c6 together with their _snapshot and _match_flag names.")
N("engine_data_log_* is the J1939 CAN receive queue (engine_data_log_buffer 0x0040aacc, engine_data_log_buffer_limit 0x0040ac22, engine_data_log_write_ptr 0x0040ad2c, engine_data_log_read_ptr 0x0040ad30, engine_data_log_full_flag 0x0040ad35), not a data log. Suggested rename of that family to can_receive_queue_*; for the transmit queue also rename engine_data_log_write_sentinel (0x0040ad28, the dequeue pointer advanced by mpc555_processJ1939TxBufferSend) to can_transmit_queue_dequeue_ptr and engine_data_log_active_flag (0x0040ad34, set by mpc555_sendJ1939SingleFrame when the enqueue pointer catches the dequeue pointer) to can_transmit_queue_full_flag. engine_data_log_ptr (0x0040ad38) was not checked.")
N("cruise_speed_* at 0x003fee46 / 0x003fee48 / 0x0040b554 / 0x0040b556 / 0x0040bbb2 / 0x0040bbb4 plus cruise_active_flag_a / _b, cruise_setpoint_a_valid_flag / _b_valid_flag, cruise_speed_setpoint_init (0x00408a78), cruise_speed_setpoint_offset_cal, cruise_speed_deadband_cal, cruise_speed_diff_threshold_cal, cruise_set_debounce_timer and fuel_demand_enable_flag (0x00408a84) form the dual analog accelerator pedal block (cm848_processFaultPendingFlags, cm848_processOperatingModeFlags, cm848_processFuelDemandEnableFlag, cm848_processCalibration12FuelDemand, cm848_initFuelDemandLimits): channel positions A / B, learned closed-pedal positions, idle thresholds, plausibility and sensor fault latches, then governor_speed_demand_limit = pedal position 0..400 feeding fuel_demand_control_t.accelerator_off_idle. They are not the cruise controller (cm848_cruiseSpeedCommandStateMachine). Companions of the renames above that should follow: 0x0040b554 cruise_speed_setpoint_a -> accelerator_pedal_idle_position_a, 0x003fee48 cruise_speed_target_b -> accelerator_pedal_idle_threshold_b_cal, 0x0040bbb2 / 0x0040bbb4 cruise_speed_current_a / _b -> accelerator_pedal_position_a / _b (the sensor channel source of the last two was not verified).")
N("The coolant_cal_entry family (cm848_addCoolantCalEntry, cm848_addCoolantCalEntryAlt, cm848_processCoolantCalEntries, cm848_removeCoolantCalEntry*, coolant_cal_entry_count_a / _b, fault_entry_data_array, fault_severity_data_array, DAT_003fb918..DAT_003fb96a) is the TSC1 override request tracker (source address, control mode, countdown timeout from etc1_torque_mode_timeout_cal; expiry clears j1939_tsc1_override_state), not coolant; the whole family should be renamed together (for example cm848_addTsc1RequestEntry / ...Alt, cm848_processTsc1RequestTimeouts, cm848_removeTsc1RequestEntry). Only the duplicate at 0x00053cd8 is renamed above.")
N("injection_timing_compensation_lower_cal at 0x00406fcc (kept) is outside 0x3fd482-0x3feec1 and is ROM-initialised and never written, so its _cal suffix is legacy audit backlog, not changed here. injection_timing_compensation_limit_cal (0x00406fc2) is the upper bound paired with the renamed 0x00406fc4 in cm848_processTorqueLimitTiming; consider injection_timing_compensation_limit_upper (no _cal) for it.")
N("0x0040a8b1 (renamed above) is in the packed halfword block 0x0040a8ad..0x0040a8b7 (fuel_ema_coeff_3/4/2/1_working, fuel_demand_state_code): the odd-address sth / lha accesses at 0x424dc, 0x42524 and 0x1fbe8 are real, not a width error. The fuel_ema_coeff_* / fuel_demand_ema_* names use coeff and ema; spell them out if that family is renamed.")

# ---------------- validate ----------------
names_new = [r['new'] for r in rows if 'new' in r]
assert len(names_new) == len(set(names_new)), 'duplicate new names'
alltext = ''.join(open(ROOT + fn, errors='replace').read() for fn in ['global_variables.csv', 'function_renames.csv', 'arrays.csv'])
tokens = set(re.findall(r'[A-Za-z_][A-Za-z0-9_]*', alltext))
bad = [n for n in names_new if n in tokens]
print('new names that already exist:', bad)
for extra in ['protection_confirm_delay_counter_a', 'can_receive_queue_buffer', 'can_transmit_queue_dequeue_ptr', 'can_transmit_queue_full_flag', 'accelerator_pedal_idle_position_a', 'accelerator_pedal_idle_threshold_b_cal', 'injection_timing_compensation_limit_upper']:
    if extra in tokens:
        print('suggested name already exists:', extra)
for r in rows:
    if 'new' in r:
        assert not re.search(r'0x|[0-9a-f]{6,}', r['new']), r['new']
        assert len(r['new']) < 70, r['new']
with open(OUT, 'w') as f:
    for r in rows:
        f.write(json.dumps(r) + '\n')
chk = [json.loads(l) for l in open(OUT)]
from collections import Counter
print(Counter(r['kind'] for r in chk))
print('renames:', len(names_new))
