# Content for bin items 31-63 (crank / cam calibration block 8194, 819B and 8C73).
B = {}
TAIL = " ROM-copied constant in RAM (never written) outside the EEPROM mirror, so no _cal."

B[31] = dict(
    new="cam_crank_mismatch_count_limit",
    evidence="e2m 8194 +4 Cam_Crank_Mismatch_Threshold 'value of cam-crank mismatch persistence counter which sets error': mpc555_updateEngineCrankState adds 1 to crank_sync_timeout_count (e2m 819B +10 Cam_Crank_Mismatch_Count) `if (crank_sync_timeout_count < crank_sync_timeout_limit_cal) {` when a cam pulse matches neither expected crank tooth number and subtracts 1 per match; cm848_updateEngineSpeedFromCrankSignal sets fault_detected_bits_112_to_127 bit 0x20 (fault 117 -> ROM 0x5985a slot table -> obd_dtc_code_table = P0016) at the limit and clamps the count to it; lhz 3, never written; 60 in the dump; the old name says timeout",
    quote="if (crank_sync_timeout_count < crank_sync_timeout_limit_cal) {",
    comment="e2m 8194 +4 Cam_Crank_Mismatch_Threshold (UNITLESS, 2 bytes, 0-255): 'value of cam-crank mismatch persistence counter which sets error'. The limit of the cam / crank mismatch persistence counter crank_sync_timeout_count (e2m 819B +10 Cam_Crank_Mismatch_Count): mpc555_updateEngineCrankState (the TPU-A channel 1 cam handler) adds 1 to it, up to this limit, for each cam pulse whose crank tooth number matches neither of the two expected entries of crank_tooth_pattern_table and subtracts 1 for each matching pulse; cm848_updateEngineSpeedFromCrankSignal sets fault_detected_bits_112_to_127 bit 0x20 (fault 117 -> ROM 0x5985a slot table -> obd_dtc_code_table = P0016, crank / cam correlation) when the count reaches the limit and holds the count there. 60 in the dump." + TAIL + " Not a timeout.",
)

B[32] = dict(
    new="cam_sync_error_count_limit",
    evidence="e2m 8194 +6 [CSCMMXCU] Cam_Sync_Max_Count 'limit on cam sync error count': cm848_updateEngineSpeedFromCrankSignal `if (engine_crank_state_t_0040b80a.start_counter < engine_start_counter_min_cal) {` else sets fault_detected_bits_0_to_15 bit 0x20 (fault 5 -> slot table -> P0341) and clamps start_counter to it, so it is a maximum, not a minimum; start_counter is e2m 819C +0 [CSERCU] Cam_Sync_Error_Count (its struct field name is stale); 2 lhz, never written; 130 in the dump",
    quote="if (engine_crank_state_t_0040b80a.start_counter < engine_start_counter_min_cal) {",
    comment="e2m 8194 +6 [CSCMMXCU] Cam_Sync_Max_Count (CNTS, 2 bytes, 0-65535): 'limit on cam sync error count'. The limit of the cam sync error count, engine_crank_state_t.start_counter (e2m 819C +0 [CSERCU] Cam_Sync_Error_Count 'TOTAL NUMBER OF SYNC LOSSES'; the field name is stale): the TPU-A channel 0 / 1 handlers (mpc555_updateEngineRunState, mpc555_updateEngineCrankState) add 1 to it while the engine speed is above speed_setpoint_minimum (e2m EPS_Failure_Detect_RPM) and the cam sync state (engine_crank_state_t.crank_state, e2m 819C +2 Cam_Sync_State) is not 4, and subtract 1 while it is 4 (the in-sync state: a run state 1 with cam state 4 switches to the cam input); cm848_updateEngineSpeedFromCrankSignal sets fault_detected_bits_0_to_15 bit 0x20 (fault 5 -> ROM 0x5985a slot table -> obd_dtc_code_table = P0341, cam signal range / performance) when the count reaches this limit and clamps the count to it. 130 in the dump." + TAIL + " It is a maximum, not an engine start counter minimum.",
)

B[33] = dict(
    new="crank_tooth_position_target",
    evidence="e2m 8194 +A Crank_Sync_Determination_Count 'Number of speed interrupts before cam pulse count is checked': hpcr_processEngineSyncPulses adds 1 to crank_tooth_position_count (e2m 819B +1A Crank_Speed_Count) per speed interrupt in crank run state 2 and `wVar3 == crank_tooth_position_target_cal)) {` then checks the cam pulse count; lhz 1, never written; 5 in the dump; only the _cal is wrong (RAM outside the EEPROM mirror)",
    quote="wVar3 == crank_tooth_position_target_cal)) {",
    comment="e2m 8194 +A Crank_Sync_Determination_Count (UNITLESS, 2 bytes, 0-255): 'Number of speed interrupts before cam pulse count is checked'. The target of crank_tooth_position_count (e2m 819B +1A Crank_Speed_Count 'number of speed interrupts before extra cam pulse should occur'): hpcr_processEngineSyncPulses (the TPU-A channel 11 speed interrupt) adds 1 to the count per interrupt in crank run state 2 (start sync) and, when the count equals this word, reads the crank signal window (tpu_a_ch0_param0.PARAM0 bit 15) and the tooth counter and compares the cam pulse count crank_tooth_count_a with crank_pattern_tooth_count_cal to decide the sync. 5 in the dump." + TAIL,
)

B[34] = dict(
    new="crank_sync_error_count_speed_limp_home_threshold",
    evidence="e2m 8194 +C [CSCKFXCU] Crank_Sync_Fail_Count 'Threshold at which crank sensor no longer used': mpc555_updateEngineCrankState `(cranking_flag_threshold_cal < engine_crank_state_t_0040b80a.cranking_flag)) {` calls cm848_enterSpeedLimpHome (position from the cam signal, TPU-A channel 0 disabled) and engine_injectionTiming_crankSyncDispatch while speed limp home is not active; cranking_flag is e2m 819C +4 [CSCKERCU] Crank_Sync_Error_Count (its struct field name is stale); lhz 1, never written; 0 in the dump",
    quote="(cranking_flag_threshold_cal < engine_crank_state_t_0040b80a.cranking_flag)) {",
    comment="e2m 8194 +C [CSCKFXCU] Crank_Sync_Fail_Count (CNTS, 2 bytes, 0-65535): 'Threshold at which crank sensor no longer used'. The crank sync error count (engine_crank_state_t.cranking_flag, e2m 819C +4 [CSCKERCU] Crank_Sync_Error_Count 'Incremented 6/cam when crank not synched'; the field name is stale) above which the crank signal is abandoned: mpc555_updateEngineCrankState (the cam handler, counting up per cam pulse while the crank run state is 0 or 1 and the engine speed is above speed_setpoint_minimum) calls cm848_enterSpeedLimpHome (engine position from the cam signal, TPU-A channel 0 disabled) and engine_injectionTiming_crankSyncDispatch when speed limp home is not active and the count exceeds this word. 0 in the dump: one counted error is enough." + TAIL,
)

B[35] = dict(
    new="crank_sync_error_count_limit",
    evidence="e2m 8194 +E [CSCKMXCU] Crank_Sync_Max_Count 'limit on crank sync error count': cm848_updateEngineSpeedFromCrankSignal `if (engine_crank_state_t_0040b80a.cranking_flag < engine_cranking_flag_min_cal) {` else sets fault_detected_bits_112_to_127 bit 0x1000 (fault 124 -> ROM 0x5985a slot table -> obd_dtc_code_table = P0336) and clamps cranking_flag (e2m 819C +4 Crank_Sync_Error_Count) to it, so it is a maximum, not a minimum; 2 lhz, never written; 40 in the dump",
    quote="if (engine_crank_state_t_0040b80a.cranking_flag < engine_cranking_flag_min_cal) {",
    comment="e2m 8194 +E [CSCKMXCU] Crank_Sync_Max_Count (CNTS, 2 bytes, 0-65535): 'limit on crank sync error count'. The limit of the crank sync error count engine_crank_state_t.cranking_flag (e2m 819C +4 [CSCKERCU] Crank_Sync_Error_Count; the field name is stale): cm848_updateEngineSpeedFromCrankSignal sets fault_detected_bits_112_to_127 bit 0x1000 (fault 124 -> ROM 0x5985a slot table -> obd_dtc_code_table = P0336, crank signal range / performance) when the count reaches it and clamps the count to it; it clears the fault bit only when the count is back to 0. 40 in the dump." + TAIL + " It is a maximum, not a cranking flag minimum.",
)

B[36] = dict(
    new="backup_period_rpm_conversion_factor",
    evidence="e2m 8194 +16 [ESCUCF02] Engine_Speed_Constant_1_Backup 'Conversion factor from tcnts to rpm - secondary': cm848_updateEngineSpeedFromCrankSignal computes `crank_tooth_rpm = (word)(crank_tooth_rpm_divisor_cal / crank_tooth_period_raw);` (the backup rpm, e2m Backup_RPM) while backup_pulse_period_countdown is not 0 - it is the dividend, not a divisor; the primary twin is primary_period_rpm_conversion_factor (e2m +12); lwz 1, never written; 400000000 in the dump",
    quote="crank_tooth_rpm = (word)(crank_tooth_rpm_divisor_cal / crank_tooth_period_raw);",
    comment="e2m 8194 +16 [ESCUCF02] Engine_Speed_Constant_1_Backup (UNITLESS, x 0.125, 4 bytes, 0-134217728): 'Engine_Speed_Constant_1_Backup: Conversion factor from tcnts to rpm - secondary'. The backup (secondary, TPU-A channel 1 cam signal) counterpart of primary_period_rpm_conversion_factor: cm848_updateEngineSpeedFromCrankSignal computes crank_tooth_rpm (1/8 rpm per count, e2m 819B +C Backup_RPM) = this / crank_tooth_period_raw (the summed backup tooth period, e2m Average_Pulse_Period_Backup) while backup_pulse_period_countdown is not 0. 400000000 in the dump." + TAIL + " It is the dividend of that division, not a divisor.",
)

B[37] = dict(
    new="cylinder_firing_acceleration_threshold",
    evidence="e2m 8194 +1E Firing_Acceleration_Threshold 'Acceleration level which indicates cylinder combustion' (RPM/SEC, signed): hpcr_processEngineSyncPulses counts a firing detection `((int)crank_period_tooth_count_threshold_cal < (int)(short)crank_period_variation_metric)) {` where crank_period_variation_metric is e2m 819B +1C Cylinder_Acceleration (acceleration above the threshold = combustion), together with the fueling minimum cylinder_firing_detection_minimum_fueling; lwz 1, never written, compared as signed int (e2m signed, the row is dword: i32 would fit); 500 in the dump; the old name says tooth count",
    quote="((int)crank_period_tooth_count_threshold_cal < (int)(short)crank_period_variation_metric)) {",
    comment="e2m 8194 +1E Firing_Acceleration_Threshold (RPM/SEC, signed, 4 bytes, -5000..5000): 'Acceleration level which indicates cylinder combustion'. hpcr_processEngineSyncPulses (the TPU-A channel 11 speed interrupt, crank run state 3) counts a firing detection (crank_tooth_count_b, e2m 819B +2E Firing_Detection_Count 'counts number of fueling events which caused accel') when the cylinder acceleration crank_period_variation_metric (e2m 819B +1C Cylinder_Acceleration 'Acceleration measured over one cylinder') is above this word and the previous injection quantity was above cylinder_firing_detection_minimum_fueling (e2m +30 Min_Fuel_For_Accel). 500 in the dump." + TAIL + " Signed in the e2m, compared as int. Not a tooth count threshold.",
)

B[38] = dict(
    new="primary_consecutive_error_threshold",
    evidence="e2m 8194 +2A [ESTDCU01] Main_Consec_Error_Thres 'Threshold count at which ESS is lost': cm848_updateEngineSpeedFromCrankSignal adds 1 to crank_period_timeout_count while crank_period_countdown is 0 and the engine speed is non-zero (`if (crank_period_timeout_count < crank_sync_period_confirm_count_cal) {` else sets fault_detected_bits_80_to_95 bit 0x1000 = fault 92 -> ROM 0x5985a slot table -> obd_dtc_code_table = P0335 and clamps the count to it); the backup twin is backup_consecutive_error_threshold (fault 93 = P0340); lhz 2, never written; 150 in the dump; lead from wave 13 bin 5",
    quote="if (crank_period_timeout_count < crank_sync_period_confirm_count_cal) {",
    comment="e2m 8194 +2A [ESTDCU01] Main_Consec_Error_Thres (CNTS, 2 bytes, 0-255): 'Main_Consec_Error_Thresh:Threshold count at which ESS is lost.'. Threshold of the consecutive error count of the primary engine speed signal (the crank signal, TPU-A channel 0): cm848_updateEngineSpeedFromCrankSignal adds 1 to crank_period_timeout_count per pass while crank_period_countdown is 0 and the engine speed is non-zero, else clears it; at this threshold it sets fault_detected_bits_80_to_95 bit 0x1000 (fault 92 -> ROM 0x5985a slot table -> obd_dtc_code_table = P0335, crank signal circuit) and holds the count here. The backup counterpart is backup_consecutive_error_threshold (e2m Backup_Consec_Error_Thresh, fault 93 = P0340). 150 in the dump." + TAIL,
)

B[39] = dict(
    new="primary_pulse_period_timeout",
    evidence="e2m 8194 +2C [ESMXTM01] Maximum_Pulse_Period_Timeout 'max reset value for Main_Lost_Counter' (MSEC 20): cm848_updateEngineSpeedFromCrankSignal scales it by engine speed into crank_period_adjusted_working (`crank_period_adjusted_working = crank_period_raw;` below 256 rpm) and hpcr_processEngineSyncPulses reloads `crank_period_countdown = crank_period_adjusted_working;` on every speed interrupt; mpc555_resetEngineTimingAccumulators copies it to crank_period_prev_snapshot; 4 lhz, never written; 16 in the dump = 320 ms; the backup twin is backup_pulse_period_timeout (+2E); lead from wave 13 bin 5",
    quote="crank_period_adjusted_working = crank_period_raw;",
    comment="e2m 8194 +2C [ESMXTM01] Maximum_Pulse_Period_Timeout (MSEC, 20 per count, 2 bytes, 0-1000000): 'Maximum_Pulse_Period_Timeout: max reset value for Main_Lost_Counter'. Reload value of the primary pulse lost countdown crank_period_countdown (e2m 819B +32 Main_Lost_Counter): cm848_updateEngineSpeedFromCrankSignal divides it by 1 / 2 / 4 / 8 as the filtered engine speed rises (below 256 rpm / below 511 / below 768 / above) into crank_period_adjusted_working, hpcr_processEngineSyncPulses reloads crank_period_countdown from that on every speed interrupt, and the countdown runs down once per pass in cm848_updateEngineSpeedFromCrankSignal; a 0 zeroes crank_derived_rpm and counts crank_period_timeout_count. mpc555_resetEngineTimingAccumulators copies it to crank_period_prev_snapshot. The backup counterpart is backup_pulse_period_timeout (e2m +2E). 16 in the dump = 320 ms." + TAIL + " It is a timeout constant, not a raw period.",
)

B[40] = dict(
    new="cylinder_firing_detection_minimum_fueling",
    evidence="e2m 8194 +30 Min_Fuel_For_Accel 'Minimum fueling command to detect cylinder firing' (MM3S 0.0679): hpcr_processEngineSyncPulses `if ((crank_sync_period_captured_threshold_cal < injection_fuel_quantity_snapshot_previous) &&` counts a firing detection (crank_tooth_count_b) only when the previous injection quantity is above it and the acceleration exceeds cylinder_firing_acceleration_threshold; lhz 1, never written; 515 in the dump = 35.0 mm3",
    quote="if ((crank_sync_period_captured_threshold_cal < injection_fuel_quantity_snapshot_previous) &&",
    comment="e2m 8194 +30 Min_Fuel_For_Accel (MM3S, 0.0679 mm3 per count, 2 bytes, 0-400): 'Minimum fueling command to detect cylinder firing'. hpcr_processEngineSyncPulses (the TPU-A channel 11 speed interrupt, crank run state 3) counts a firing detection (crank_tooth_count_b, e2m 819B +2E Firing_Detection_Count) only when the injection quantity of the previous event, injection_fuel_quantity_snapshot_previous, is above this word and the cylinder acceleration exceeds cylinder_firing_acceleration_threshold (e2m +1E Firing_Acceleration_Threshold). 515 in the dump = 35.0 mm3." + TAIL + " Not a sync period threshold.",
)

B[41] = dict(
    new="crank_recovery_minimum_good_cam_pulse_count",
    evidence="e2m 8194 +32 Min_Good_Pulses_For_Crank_Recovery 'Min number of good cam pulses to resync crank': mpc555_updateEngineRunState in run state 1 `(crank_sync_period_counter_threshold_cal < crank_sync_period_counter)) {` with the cam state 4 calls cm848_engineRunState4Handler (run state 4) instead of cm848_engineRunState3Handler; crank_sync_period_counter is e2m 819B +14 Cam_Crank_Plausibility_2 (cam pulses with the expected crank tooth number); lhz 1, never written; 3 in the dump",
    quote="(crank_sync_period_counter_threshold_cal < crank_sync_period_counter)) {",
    comment="e2m 8194 +32 Min_Good_Pulses_For_Crank_Recovery (UNITLESS, 2 bytes, 0-255): 'Min number of good cam pulses to resync crank'. mpc555_updateEngineRunState (the TPU-A channel 0 handler), in crank run state 1 (lost sync), goes straight to run state 4 (have sync, cm848_engineRunState4Handler) when the cam state is 4 and crank_sync_period_counter (e2m 819B +14 Cam_Crank_Plausibility_2, the cam pulses with the expected crank tooth number counted in a row) is above this word; otherwise it takes the preliminary sync path through run state 3 (cm848_engineRunState3Handler). 3 in the dump." + TAIL,
)

B[42] = dict(
    new="backup_period_capture_count",
    evidence="e2m 8194 +36 Period_Meas_Per_Backup 'Number of cam measurements used in speed calculation' (1 byte) and +37 Periods_Per_Sum 'Number of crank periods per interrupt' (1 byte): mpc555_updateEngineCrankState reads the high byte 0x408f8c (`uVar8 = (uint)crank_period_capture_index_max_cal._0_1_;`, lbz) as the number of captured backup tooth periods summed into crank_tooth_period_raw and the wrap point of crank_period_capture_index (the ring is written by the TPU-A channel 1 cam handler: the backup path, hence backup_ and not crank_); mpc555_resetEngineTimingAccumulators reads the low byte 0x408f8d (`(byte)crank_period_capture_index_max_cal * engine_speed_interrupts_per_cylinder;`, lbz r10,0(r8) with r8 = 0x408f8d @ 0x43edc and 0x44168); 2 in the dump (0x408f8c)",
    quote="uVar8 = (uint)crank_period_capture_index_max_cal._0_1_;",
    comment="e2m 8194 +36 Period_Meas_Per_Backup (UNITLESS, 1 byte, 0-255): 'Number of cam measurements used in speed calculation'. The number of captured backup (TPU-A channel 1 cam signal) tooth periods that make up the backup speed: mpc555_updateEngineCrankState stores each capture in crank_period_capture_array[backup_period_capture_index], wraps the index to 0 at this count (read with lbz as the high byte of this word) and sums this many entries into crank_tooth_period_raw (e2m 819B +6 Average_Pulse_Period_Backup). 2 in the dump. The row is typed word and also covers the next byte 0x408f8d (e2m +37 Periods_Per_Sum): mpc555_resetEngineTimingAccumulators reads it as (byte) of this word (2 lbz) - see the split." + TAIL + " It is the entry count of the backup period ring (the index wraps to 0 when it reaches it), not a maximum index; the ring and its index are the backup (cam) path, as in the e2m Period_Meas_Per_Backup / Next_Table_Position_Backup names.",
    type_note="word row over two 1-byte e2m records: +36 Period_Meas_Per_Backup at 0x408f8c (lbz in mpc555_updateEngineCrankState, the ._0_1_ read) and +37 Periods_Per_Sum at 0x408f8d (lbz in mpc555_resetEngineTimingAccumulators, the (byte) read; the typeless label row crank_period_reference_scale_cal sits there); should be two byte rows",
    split=[
        dict(address="0x00408f8c", name="backup_period_capture_count", type="byte",
             comment="e2m 8194 +36 Period_Meas_Per_Backup (UNITLESS, 1 byte, 0-255): 'Number of cam measurements used in speed calculation'. The number of captured backup (TPU-A channel 1 cam signal) tooth periods that make up the backup speed: mpc555_updateEngineCrankState stores each capture in crank_period_capture_array[backup_period_capture_index], wraps the index to 0 at this count and sums this many entries into crank_tooth_period_raw (e2m 819B +6 Average_Pulse_Period_Backup). lbz. 2 in the dump." + TAIL),
        dict(address="0x00408f8d", name="crank_periods_per_speed_interrupt", type="byte",
             comment="e2m 8194 +37 Periods_Per_Sum (UNITLESS, 1 byte, 0-255): 'Number of crank periods per interrupt'. The number of crank tooth periods the TPU-A channel 12 sums per speed interrupt: mpc555_resetEngineTimingAccumulators (2 lbz, 0x43edc and 0x44168) multiplies it by engine_speed_interrupts_per_cylinder (e2m +4A Sums_Per_Cylinder) into crank_period_scale_divisor (e2m 819B +46 RPM_Cylinder_Width 'number of crank teeth per cylinder': 5 x 4 = 20), programs TPUA_CH12_PARAM0.PARAM6 with it x 256 - 256 and presets the TPU-A channel 11 / 12 period buffers with it x 20000000 / tooth_period_buffer_initial_engine_speed. lbz. 5 in the dump." + TAIL),
    ],
)

B[43] = dict(
    new="crank_tooth_pattern_size",
    evidence="e2m 8194 +38 Plausible_Cam_Positions 'Number of elements in the Cam_2_Crank_Position_Array': mpc555_updateEngineCrankState `if (crank_tooth_pattern_size_cal != 0) {` loops over that many entries of crank_tooth_pattern_table (e2m 819D Cam_2_Crank_Position_Array 'Expected crank tooth numbers at each cam pulse') counting those equal to the crank tooth number or one less; lhz 1, never written; 26 in the dump (2 x cam_wheel_pulse_count 13); only the _cal is wrong (RAM outside the EEPROM mirror)",
    quote="if (crank_tooth_pattern_size_cal != 0) {",
    comment="e2m 8194 +38 Plausible_Cam_Positions (UNITLESS, 2 bytes, 0-255): 'Number of elements in the Cam_2_Crank_Position_Array'. The entry count of crank_tooth_pattern_table (e2m 819D +0 Cam_2_Crank_Position_Array, 'Expected crank tooth numbers at each cam pulse'): mpc555_updateEngineCrankState loops over that many entries, counting those equal to the current crank tooth number or one less (when none match, or the scan is skipped because this word is 0, crank_tooth_count_a and crank_sync_period_counter are cleared). 26 in the dump = 2 x 13 (cam_wheel_pulse_count)." + TAIL,
)

B[44] = dict(
    new="cam_signal_low_speed_special_window_fraction",
    evidence="e2m 8194 +3A PMA_Low_Speed_Special_Window 'Tooth fraction defining special cam tooth at low speed' (1/64): `tpu_a_ch1_param2.PARAM7 = (ushort)crank_mios_period_byte_cal << 8 | 0x40;` in mpc555_resetEngineTimingAccumulators and the same high byte again in cm848_updateEngineSpeedFromCrankSignal while engine_rpm_measured < crank_speed_setpoint_threshold_cal; TPU-A channel 1 is the cam signal (e2m PMA_Edge_Type 'Capture edge for cam signal'; PMA = the TPU period measurement with additional transition detect); 2 lbz, never written; 26 in the dump = 0.41 tooth; not MIOS",
    quote="tpu_a_ch1_param2.PARAM7 = (ushort)crank_mios_period_byte_cal << 8 | 0x40;",
    comment="e2m 8194 +3A PMA_Low_Speed_Special_Window (UNITLESS, 1/64 per count, 1 byte, 0-3.98): 'Tooth fraction defining special cam tooth at low speed'. The low speed special (additional) pulse window of the cam signal's TPU-A channel 1 function (e2m PMA: period measurement with additional transition detect; channel 1 is the cam signal, see PMA_Edge_Type): mpc555_resetEngineTimingAccumulators loads it as the high byte of tpu_a_ch1_param2.PARAM7 (low byte 0x40) and cm848_updateEngineSpeedFromCrankSignal reloads it there whenever engine_rpm_measured is below crank_speed_setpoint_threshold_cal (e2m Low_Speed_Filtering_Threshold); the normal speed counterpart is cam_signal_special_window_fraction. 26 in the dump = 0.41 tooth." + TAIL + " It programs a TPU channel, not a MIOS one.",
)

B[45] = dict(
    new="cam_signal_tooth_count",
    evidence="e2m 8194 +3B PMA_Special_Count 'Number of teeth on cam wheel': `tpu_a_ch1_param2.PARAM6 = (ushort)mios_timing_byte_b_cal << 8 | 0x40;` in mpc555_resetEngineTimingAccumulators (its only reader, lbz 1; cm848_updateEngineSpeedFromCrankSignal later rewrites only the low byte of PARAM6); the same number as cam_wheel_pulse_count (e2m Number_Of_Cam_Pulses); never written; 13 in the dump",
    quote="tpu_a_ch1_param2.PARAM6 = (ushort)mios_timing_byte_b_cal << 8 | 0x40;",
    comment="e2m 8194 +3B PMA_Special_Count (UNITLESS, 1 byte, 0-255): 'Number of teeth on cam wheel'. The tooth count of the cam signal's TPU-A channel 1 function (e2m PMA): mpc555_resetEngineTimingAccumulators loads it as the high byte of tpu_a_ch1_param2.PARAM6 (low byte 0x40; cm848_updateEngineSpeedFromCrankSignal later rewrites only the low byte). 13 in the dump, the same number as cam_wheel_pulse_count (e2m Number_Of_Cam_Pulses 'Number of targets on the cam wheel')." + TAIL + " It programs a TPU channel, not a MIOS one.",
)

B[46] = dict(
    new="cam_signal_special_window_fraction",
    evidence="e2m 8194 +3C PMA_Special_Window 'Fraction of tooth defining special pulse' (1/64): cm848_updateEngineSpeedFromCrankSignal `(ushort)mios_timing_byte_a_cal << 8 | (crank_tooth_good_window_fraction >> 1) + 0x40 & 0xff` into tpu_a_ch1_param2.PARAM7 once crank_speed_setpoint_threshold_cal < engine_rpm_measured; TPU-A channel 1 is the cam signal (PMA); lbz 1, never written; 31 in the dump = 0.48 tooth",
    quote="(ushort)mios_timing_byte_a_cal << 8 | (crank_tooth_good_window_fraction >> 1) + 0x40 & 0xff",
    comment="e2m 8194 +3C PMA_Special_Window (UNITLESS, 1/64 per count, 1 byte, 0-3.98): 'Fraction of tooth defining special pulse'. The normal speed special (additional) pulse window of the cam signal's TPU-A channel 1 function (e2m PMA): cm848_updateEngineSpeedFromCrankSignal loads it as the high byte of tpu_a_ch1_param2.PARAM7 (low byte 0x40 + (crank_tooth_good_window_fraction >> 1)) whenever engine_rpm_measured is above crank_speed_setpoint_threshold_cal; the low speed counterpart is cam_signal_low_speed_special_window_fraction. 31 in the dump = 0.48 tooth." + TAIL + " It programs a TPU channel, not a MIOS one.",
)

B[47] = dict(
    new="crank_signal_early_window_fraction",
    evidence="e2m 8194 +3D PMM_Early_Window 'Tooth fraction where tooth is too early to be plausible' (1/64): `tpu_a_ch0_param0.PARAM7 = CONCAT11(mios_config_byte_a_cal,crank_mios_config_e_cal);` in cm848_updateEngineSpeedFromCrankSignal once crank_speed_setpoint_threshold_cal < engine_rpm_measured; TPU-A channel 0 is the crank signal (e2m PMM_Edge_Type 'Capture edge for crank signal'; PMM = period measurement with missing transition detect); lbz 1, never written; 51 in the dump = 0.80 tooth",
    quote="tpu_a_ch0_param0.PARAM7 = CONCAT11(mios_config_byte_a_cal,crank_mios_config_e_cal);",
    comment="e2m 8194 +3D PMM_Early_Window (UNITLESS, 1/64 per count, 1 byte, 0-3.98): 'Tooth fraction where tooth is too early to be plausible'. The early window of the crank signal's TPU-A channel 0 function (e2m PMM: period measurement with missing transition detect; channel 0 is the crank signal, see PMM_Edge_Type): cm848_updateEngineSpeedFromCrankSignal writes CONCAT11(this, crank_signal_late_window_fraction) into tpu_a_ch0_param0.PARAM7 whenever engine_rpm_measured is above crank_speed_setpoint_threshold_cal; the low speed set is crank_signal_low_speed_early_window_fraction / _late_window_fraction. 51 in the dump = 0.80 tooth." + TAIL + " It programs a TPU channel, not a MIOS one.",
)

B[48] = dict(
    new="crank_signal_good_window_fraction",
    evidence="e2m 8194 +3E PMM_Good_Window 'Tooth Fraction where tooth is plausible' (1/64): `tpu_a_ch0_param0.PARAM6 = wVar1 & 0xff00 | (ushort)mios_config_byte_b_cal;` in cm848_updateEngineSpeedFromCrankSignal once crank_speed_setpoint_threshold_cal < engine_rpm_measured (the high byte of PARAM6 is crank_signal_tooth_count); TPU-A channel 0 is the crank signal (PMM); lbz 1, never written; 77 in the dump = 1.20 tooth",
    quote="tpu_a_ch0_param0.PARAM6 = wVar1 & 0xff00 | (ushort)mios_config_byte_b_cal;",
    comment="e2m 8194 +3E PMM_Good_Window (UNITLESS, 1/64 per count, 1 byte, 0-3.98): 'Tooth Fraction where tooth is plausible'. The plausible (good) window of the crank signal's TPU-A channel 0 function (e2m PMM): cm848_updateEngineSpeedFromCrankSignal writes it into the low byte of tpu_a_ch0_param0.PARAM6 (the high byte is crank_signal_tooth_count) whenever engine_rpm_measured is above crank_speed_setpoint_threshold_cal; the low speed counterpart is crank_signal_low_speed_good_window_fraction. 77 in the dump = 1.20 tooth." + TAIL + " Not the cam signal's good window (that is crank_tooth_good_window_fraction, e2m 819B +42 PMA_Good_Window) and not a MIOS value.",
)

B[49] = dict(
    new="crank_signal_late_window_fraction",
    evidence="e2m 8194 +3F PMM_Late_Window 'Tooth fraction which defines a late (not plausible) tooth' (1/64): `tpu_a_ch0_param0.PARAM7 = CONCAT11(mios_config_byte_a_cal,crank_mios_config_e_cal);` (the low byte) in cm848_updateEngineSpeedFromCrankSignal once crank_speed_setpoint_threshold_cal < engine_rpm_measured; TPU-A channel 0 is the crank signal (PMM); lbz 1, never written; 147 in the dump = 2.30 tooth",
    quote="tpu_a_ch0_param0.PARAM7 = CONCAT11(mios_config_byte_a_cal,crank_mios_config_e_cal);",
    comment="e2m 8194 +3F PMM_Late_Window (UNITLESS, 1/64 per count, 1 byte, 0-3.98): 'Tooth fraction which defines a late (not plausible) tooth'. The late window of the crank signal's TPU-A channel 0 function (e2m PMM): cm848_updateEngineSpeedFromCrankSignal writes CONCAT11(crank_signal_early_window_fraction, this) into tpu_a_ch0_param0.PARAM7 (this is the low byte) whenever engine_rpm_measured is above crank_speed_setpoint_threshold_cal; the low speed counterpart is crank_signal_low_speed_late_window_fraction. 147 in the dump = 2.30 tooth." + TAIL + " It programs a TPU channel, not a MIOS one.",
)

B[50] = dict(
    new="crank_signal_low_speed_early_window_fraction",
    evidence="e2m 8194 +40 PMM_Low_Speed_Early_Window 'Low Speed Tooth fraction where tooth is too early to be plausible' (1/64): `tpu_a_ch0_param0.PARAM7 = CONCAT11(crank_mios_compare_a_high_cal,crank_mios_compare_a_low_cal);` in mpc555_resetEngineTimingAccumulators and in cm848_updateEngineSpeedFromCrankSignal while engine_rpm_measured < crank_speed_setpoint_threshold_cal; TPU-A channel 0 is the crank signal (PMM); 2 lbz, never written; 32 in the dump = 0.50 tooth",
    quote="tpu_a_ch0_param0.PARAM7 = CONCAT11(crank_mios_compare_a_high_cal,crank_mios_compare_a_low_cal);",
    comment="e2m 8194 +40 PMM_Low_Speed_Early_Window (UNITLESS, 1/64 per count, 1 byte, 0-3.98): 'Low Speed Tooth fraction where tooth is too early to be plausible'. The low speed early window of the crank signal's TPU-A channel 0 function (e2m PMM): mpc555_resetEngineTimingAccumulators and cm848_updateEngineSpeedFromCrankSignal (whenever engine_rpm_measured is below crank_speed_setpoint_threshold_cal) write CONCAT11(this, crank_signal_low_speed_late_window_fraction) into tpu_a_ch0_param0.PARAM7; the normal speed counterpart is crank_signal_early_window_fraction. 32 in the dump = 0.50 tooth." + TAIL + " It programs a TPU channel, not a MIOS one.",
)

B[51] = dict(
    new="crank_signal_low_speed_good_window_fraction",
    evidence="e2m 8194 +41 PMM_Low_Speed_Good_Window 'Low speed Tooth Fraction where tooth is plausible' (1/64): `tpu_a_ch0_param0.PARAM6 = wVar1 & 0xff00 | (ushort)crank_mios_compare_b_low_cal;` in cm848_updateEngineSpeedFromCrankSignal while engine_rpm_measured < crank_speed_setpoint_threshold_cal, and as the low byte of CONCAT11(crank_signal_tooth_count, this) in mpc555_resetEngineTimingAccumulators; TPU-A channel 0 is the crank signal (PMM); 2 lbz, never written; 96 in the dump = 1.50 tooth",
    quote="tpu_a_ch0_param0.PARAM6 = wVar1 & 0xff00 | (ushort)crank_mios_compare_b_low_cal;",
    comment="e2m 8194 +41 PMM_Low_Speed_Good_Window (UNITLESS, 1/64 per count, 1 byte, 0-3.98): 'Low speed Tooth Fraction where tooth is plausible'. The low speed plausible (good) window of the crank signal's TPU-A channel 0 function (e2m PMM): mpc555_resetEngineTimingAccumulators loads it as the low byte of tpu_a_ch0_param0.PARAM6 (high byte crank_signal_tooth_count) and cm848_updateEngineSpeedFromCrankSignal rewrites the low byte whenever engine_rpm_measured is below crank_speed_setpoint_threshold_cal; the normal speed counterpart is crank_signal_good_window_fraction. 96 in the dump = 1.50 tooth." + TAIL + " It programs a TPU channel, not a MIOS one.",
)

B[52] = dict(
    new="crank_signal_low_speed_late_window_fraction",
    evidence="e2m 8194 +42 PMM_Low_Speed_Late_Window 'Low Speed Tooth fraction which defines a late (not plausible) tooth' (1/64): the low byte of `tpu_a_ch0_param0.PARAM7 = CONCAT11(crank_mios_compare_a_high_cal,crank_mios_compare_a_low_cal);` in mpc555_resetEngineTimingAccumulators and in cm848_updateEngineSpeedFromCrankSignal while engine_rpm_measured < crank_speed_setpoint_threshold_cal; TPU-A channel 0 is the crank signal (PMM); 2 lbz, never written; 180 in the dump = 2.81 tooth",
    quote="tpu_a_ch0_param0.PARAM7 = CONCAT11(crank_mios_compare_a_high_cal,crank_mios_compare_a_low_cal);",
    comment="e2m 8194 +42 PMM_Low_Speed_Late_Window (UNITLESS, 1/64 per count, 1 byte, 0-3.98): 'Low Speed Tooth fraction which defines a late (not plausible) tooth'. The low speed late window of the crank signal's TPU-A channel 0 function (e2m PMM): mpc555_resetEngineTimingAccumulators and cm848_updateEngineSpeedFromCrankSignal (whenever engine_rpm_measured is below crank_speed_setpoint_threshold_cal) write CONCAT11(crank_signal_low_speed_early_window_fraction, this) into tpu_a_ch0_param0.PARAM7 (this is the low byte); the normal speed counterpart is crank_signal_late_window_fraction. 180 in the dump = 2.81 tooth." + TAIL + " It programs a TPU channel, not a MIOS one.",
)

B[53] = dict(
    new="crank_signal_tooth_count",
    evidence="e2m 8194 +43 PMM_Special_Count (the e2m text says 'Expected cam tooth number at additional pulse'): `tpu_a_ch0_param0.PARAM6 = CONCAT11(crank_mios_compare_b_high_cal,crank_mios_compare_b_low_cal);` in mpc555_resetEngineTimingAccumulators (high byte) and `wVar5 = wVar5 - crank_mios_compare_b_high_cal;` in hpcr_processEngineSyncPulses while the crank signal window bit (tpu_a_ch0_param0.PARAM0 bit 15) is set; 58 in the dump = 58 teeth of a 60 position wheel less two missing (crank_period_scale_divisor 5 x 4 = 20 teeth per cylinder x 3 cylinders per revolution: inferred); 2 lbz, never written",
    quote="tpu_a_ch0_param0.PARAM6 = CONCAT11(crank_mios_compare_b_high_cal,crank_mios_compare_b_low_cal);",
    comment="e2m 8194 +43 PMM_Special_Count (UNITLESS, 1 byte, 0-255): 'Expected cam tooth number at additional pulse' (the e2m text; the code uses it as the tooth count of the crank wheel). The tooth count of the crank signal's TPU-A channel 0 function (e2m PMM): mpc555_resetEngineTimingAccumulators loads it as the high byte of tpu_a_ch0_param0.PARAM6 (low byte crank_signal_low_speed_good_window_fraction; the later rewrites keep the high byte) and hpcr_processEngineSyncPulses subtracts it from the tooth counter (tpu_a_ch0_param0.PARAM4) while the crank signal window bit (PARAM0 bit 15) is set. 58 in the dump: 58 teeth, a 60 position crank wheel less two missing teeth (inferred from crank_period_scale_divisor = 5 x 4 = 20 teeth per cylinder x 3 cylinders per revolution)." + TAIL + " It programs a TPU channel, not a MIOS one.",
)

B[54] = dict(
    new="crank_preliminary_sync_firing_detection_threshold",
    evidence="e2m 8194 +44 Prelim_Sync_Detection_Threshold 'Number of firing detections needed to verify crank sync': mpc555_updateEngineRunState in crank run state 3, when crank_preliminary_sync_count has counted down to 0, `if (crank_tooth_count_b_min_cal <= crank_tooth_count_b) {` moves to run state 4 (have sync, cm848_exitSpeedLimpHome); crank_tooth_count_b is e2m 819B +2E Firing_Detection_Count; lhz 1, never written; 3 in the dump",
    quote="if (crank_tooth_count_b_min_cal <= crank_tooth_count_b) {",
    comment="e2m 8194 +44 Prelim_Sync_Detection_Threshold (UNITLESS, 2 bytes, 0-255): 'Number of firing detections needed to verify crank sync'. mpc555_updateEngineRunState (the TPU-A channel 0 handler), in preliminary sync (crank run state 3), when crank_preliminary_sync_count has counted down to 0, moves to run state 4 (have sync) and leaves speed limp home (cm848_exitSpeedLimpHome) once the firing detection count crank_tooth_count_b (e2m 819B +2E Firing_Detection_Count 'counts number of fueling events which caused accel') is at least this word; with no firing detections (crank_tooth_count_b = 0) it requests a resync instead (tpu_a_mcr.HSRR1 = 1). 3 in the dump." + TAIL,
)

B[55] = dict(
    new="crank_sync_attempt_limit",
    evidence="e2m 8194 +48 Start_Sync_Max_Count 'Max number of crank revs to stay in Start_Sync before forcing Prelim sync': mpc555_updateEngineRunState in crank run state 2 adds 1 to crank_sync_attempt_counter (e2m 819B +4C Start_Sync_Count) per crank revolution and `if (crank_sync_attempt_limit_cal <= crank_sync_attempt_counter) {` reloads crank_preliminary_sync_count and goes to preliminary sync (cm848_engineRunState3HandlerWithTimebaseCapture); lhz 1, never written; 1 in the dump; only the _cal is wrong (RAM outside the EEPROM mirror)",
    quote="if (crank_sync_attempt_limit_cal <= crank_sync_attempt_counter) {",
    comment="e2m 8194 +48 Start_Sync_Max_Count (UNITLESS, 2 bytes, 0-255): 'Max number of crank revs to stay in Start_Sync before forcing Prelim sync'. mpc555_updateEngineRunState (the TPU-A channel 0 handler) adds 1 to crank_sync_attempt_counter (e2m 819B +4C Start_Sync_Count 'number of crank revs spent in Start_Sync mode') per crank revolution in start sync (crank run state 2) and, when the counter reaches this word, reloads crank_preliminary_sync_count from crank_preliminary_sync_evaluation_count and goes to preliminary sync (run state 3, cm848_engineRunState3HandlerWithTimebaseCapture). 1 in the dump." + TAIL,
)

B[56] = dict(
    new="crank_lost_resync_cam_tooth_threshold",
    evidence="e2m 8194 +4D Lost_Resync_With_Cam_Threshold 'Cam tooth threshold at which +1 tooth resync in LOST crank state is allowed' (1 byte) and +4E Prelim_Resync_With_Cam_Threshold 'Cam tooth threshold at which +1 tooth resync to PRELIM crank bank is allowed' (1 byte): mpc555_updateEngineCrankState compares crank_sync_period_counter with the byte 0x408fa3 in crank run state 1 (`crank_sync_period_limit_state1_cal._0_1_ < crank_sync_period_counter`, lbz @ 0x45ab8 after cmpwi 1) and with the byte 0x408fa4 in run state 3 (`(byte)crank_sync_period_limit_state1_cal < crank_sync_period_counter`, lbz @ 0x45aa0 after cmpwi 3); 1 in the dump (0x408fa3)",
    quote="(crank_sync_period_limit_state1_cal._0_1_ < crank_sync_period_counter)))))) &&",
    comment="e2m 8194 +4D Lost_Resync_With_Cam_Threshold (UNITLESS, 1 byte, 0-255): 'Cam tooth threshold at which +1 tooth resync in LOST crank state is allowed'. mpc555_updateEngineCrankState compares crank_sync_period_counter (e2m 819B +14 Cam_Crank_Plausibility_2) with it in crank run state 1 (lbz @ 0x45ab8 after cmpwi 1) and, above it with the tooth counter at zero, no firing detections and no speed limp home, requests the +1 tooth resync (tpu_a_mcr.HSRR1 = 1, crank_tbl_event_counter + 1). 1 in the dump. The row is typed word and also covers the next byte 0x408fa4 (e2m +4E Prelim_Resync_With_Cam_Threshold), which the run state 3 branch reads (lbz @ 0x45aa0, rendered as (byte) of this word) - see the split." + TAIL,
    type_note="word row over two 1-byte e2m records: +4D Lost_Resync_With_Cam_Threshold at 0x408fa3 (lbz @ 0x45ab8, run state 1, the ._0_1_ read) and +4E Prelim_Resync_With_Cam_Threshold at 0x408fa4 (lbz @ 0x45aa0, run state 3, the (byte) read; the typeless label row crank_sync_period_limit_state3_cal sits there); should be two byte rows",
    split=[
        dict(address="0x00408fa3", name="crank_lost_resync_cam_tooth_threshold", type="byte",
             comment="e2m 8194 +4D Lost_Resync_With_Cam_Threshold (UNITLESS, 1 byte, 0-255): 'Cam tooth threshold at which +1 tooth resync in LOST crank state is allowed'. mpc555_updateEngineCrankState compares crank_sync_period_counter (e2m 819B +14 Cam_Crank_Plausibility_2) with it in crank run state 1 (lbz @ 0x45ab8 after cmpwi 1) and, above it with the tooth counter at zero, no firing detections and no speed limp home, requests the +1 tooth resync (tpu_a_mcr.HSRR1 = 1, crank_tbl_event_counter + 1). lbz. 1 in the dump." + TAIL),
        dict(address="0x00408fa4", name="crank_preliminary_resync_cam_tooth_threshold", type="byte",
             comment="e2m 8194 +4E Prelim_Resync_With_Cam_Threshold (UNITLESS, 1 byte, 0-255): 'Cam tooth threshold at which +1 tooth resync to PRELIM crank bank is allowed'. The preliminary sync twin of crank_lost_resync_cam_tooth_threshold: mpc555_updateEngineCrankState compares crank_sync_period_counter with it in crank run state 3 (lbz @ 0x45aa0 after cmpwi 3) before it requests the +1 tooth resync. lbz. 5 in the dump." + TAIL),
    ],
)

B[57] = dict(
    new="crank_preliminary_sync_tooth_shift_upper_threshold",
    evidence="e2m 8194 +4F Speed_Latency_Sync_Threshold 'Crank Speed ISR tooth shift limit for PRELIM sync determination += 1' (1 byte) and +50 Speed_Negative_Shift_Threshold 'Crank Speed ISR tooth shift lower limit for PRELIM sync determination' (2 bytes at 0x408fa6): hpcr_processEngineSyncPulses skips the check while the tooth shift (wVar5 & 0xff) is below the word at 0x408fa6 (lhz @ 0x45224, `blt`) and subtracts 1 from crank_tooth_count_a when `(uint)((ushort)crank_tooth_timer_max_cal._0_1_ < (wVar5 & 0xff))` (lbz @ 0x4523c, `ble` skip): the byte at 0x408fa5 is the upper limit; 25 in the dump (0x408fa5)",
    quote="(uint)((ushort)crank_tooth_timer_max_cal._0_1_ < (wVar5 & 0xff));",
    comment="e2m 8194 +4F Speed_Latency_Sync_Threshold (UNITLESS, 1 byte, 0-255): 'Crank Speed ISR tooth shift limit for PRELIM sync determination += 1.'. The upper limit of the tooth shift of the crank speed interrupt in the preliminary sync determination: hpcr_processEngineSyncPulses (the TPU-A channel 11 speed interrupt, crank run state 2) subtracts 1 from the cam pulse count crank_tooth_count_a before comparing it with crank_pattern_tooth_count_cal when the shift (tpu_a_ch0_param0.PARAM4 low byte, less crank_signal_tooth_count while the window bit is set) is above it (lbz @ 0x4523c). 25 in the dump. The row is typed word and also covers the first byte of the 2-byte record 0x408fa6 (e2m +50 Speed_Negative_Shift_Threshold), the lower limit: the check is skipped while the shift is below it (lhz @ 0x45224) - see the split." + TAIL,
    type_note="word row at 0x408fa5 over the 1-byte e2m record +4F Speed_Latency_Sync_Threshold (lbz @ 0x4523c, the ._0_1_ read) and the first byte of the 2-byte record +50 Speed_Negative_Shift_Threshold at 0x408fa6 (lhz @ 0x45224; the typeless label row crank_tooth_timer_min_cal sits there); should be a byte row at 0x408fa5 and a word row at 0x408fa6",
    split=[
        dict(address="0x00408fa5", name="crank_preliminary_sync_tooth_shift_upper_threshold", type="byte",
             comment="e2m 8194 +4F Speed_Latency_Sync_Threshold (UNITLESS, 1 byte, 0-255): 'Crank Speed ISR tooth shift limit for PRELIM sync determination += 1.'. The upper limit of the tooth shift of the crank speed interrupt in the preliminary sync determination: hpcr_processEngineSyncPulses (the TPU-A channel 11 speed interrupt, crank run state 2) subtracts 1 from the cam pulse count crank_tooth_count_a before comparing it with crank_pattern_tooth_count_cal when the shift (tpu_a_ch0_param0.PARAM4 low byte, less crank_signal_tooth_count while the window bit is set) is above it (lbz @ 0x4523c). 25 in the dump." + TAIL),
        dict(address="0x00408fa6", name="crank_preliminary_sync_tooth_shift_lower_threshold", type="word",
             comment="e2m 8194 +50 Speed_Negative_Shift_Threshold (UNITLESS, 2 bytes, 0-255): 'Crank Speed ISR tooth shift lower limit for PRELIM sync determination.'. The lower limit of the tooth shift of the crank speed interrupt in the preliminary sync determination: hpcr_processEngineSyncPulses skips the cam pulse count check while the shift (tpu_a_ch0_param0.PARAM4 low byte, less crank_signal_tooth_count while the window bit is set) is below it (lhz @ 0x45224, blt), so shifts from this word up to crank_preliminary_sync_tooth_shift_upper_threshold are the normal range. lhz. 19 in the dump." + TAIL),
    ],
)

B[58] = dict(
    new="cam_signal_capture_edge_type",
    evidence="e2m 8194 +56 PMA_Edge_Type_N (and PMA_Edge_Type, same byte) 'Capture edge for cam signal : 0 = rising, 2 = falling': `tpu_a_ch1_param2.PARAM0 = crank_mios_channel1_config_cal | 0x10;` in mpc555_resetEngineTimingAccumulators (its only reader, lbz 1); TPU-A channel 1 is the cam signal (PMA); never written; 2 in the dump = falling edge",
    quote="tpu_a_ch1_param2.PARAM0 = crank_mios_channel1_config_cal | 0x10;",
    comment="e2m 8194 +56 PMA_Edge_Type_N (UNITLESS, 1 byte, 0-2; the e2m also lists PMA_Edge_Type at the same byte): 'Capture edge for cam signal : 0 = rising, 2 = falling'. mpc555_resetEngineTimingAccumulators ORs it with 0x10 into tpu_a_ch1_param2.PARAM0, the control word of the cam signal's TPU-A channel 1 function (e2m PMA). 2 in the dump = falling edge." + TAIL + " It configures a TPU channel, not a MIOS one.",
)

B[59] = dict(
    new="crank_signal_capture_edge_type",
    evidence="e2m 8194 +57 PMM_Edge_Type_N (and PMM_Edge_Type, same byte) 'Capture edge for crank signal : 0 = rising, 2 = falling': `tpu_a_ch0_param0.PARAM0 = crank_mios_channel0_config_cal | 0xb1;` in mpc555_resetEngineTimingAccumulators (its only reader, lbz 1); TPU-A channel 0 is the crank signal (PMM); never written; 0 in the dump = rising edge",
    quote="tpu_a_ch0_param0.PARAM0 = crank_mios_channel0_config_cal | 0xb1;",
    comment="e2m 8194 +57 PMM_Edge_Type_N (UNITLESS, 1 byte, 0-2; the e2m also lists PMM_Edge_Type at the same byte): 'Capture edge for crank signal : 0 = rising, 2 = falling'. mpc555_resetEngineTimingAccumulators ORs it with 0xb1 into tpu_a_ch0_param0.PARAM0, the control word of the crank signal's TPU-A channel 0 function (e2m PMM). 0 in the dump = rising edge." + TAIL + " It configures a TPU channel, not a MIOS one.",
)

B[60] = dict(
    new="backup_period_capture_index",
    evidence="e2m 819B +3E [ESNXPS02] Next_Table_Position_Backup 'pointer to next spot in backup Pulse_period table': mpc555_updateEngineCrankState (the TPU-A channel 1 cam handler) stores each 24-bit period capture at `(&crank_period_capture_array)[crank_period_capture_index] = uVar5 & 0xffffff;` (e2m 819B +4E Pulse_Period_Table_Backup), adds 1 and wraps to 0 at backup_period_capture_count (e2m Period_Meas_Per_Backup); mpc555_resetEngineTimingAccumulators sets it to 0; the code uses an element index, not the pointer the e2m describes; it is the backup (cam) ring, hence backup_ and not crank_; stw 1 / lwz; 0 in the dump",
    quote="(&crank_period_capture_array)[crank_period_capture_index] = uVar5 & 0xffffff;",
    comment="e2m 819B +3E [ESNXPS02] Next_Table_Position_Backup (HEX, 4 bytes, 8388608..8650751): 'Next_Table_Position_Backup: pointer to next spot in backup Pulse_period table'. The element index of the next entry of the backup tooth period ring crank_period_capture_array (e2m 819B +4E Pulse_Period_Table_Backup): mpc555_resetEngineTimingAccumulators sets it to 0, mpc555_updateEngineCrankState (the TPU-A channel 1 cam handler) stores each 24-bit period capture at that element, adds 1 and wraps to 0 at backup_period_capture_count (e2m 8194 +36 Period_Meas_Per_Backup), then sums the entries into crank_tooth_period_raw (e2m Average_Pulse_Period_Backup). The e2m calls it a pointer (range 0x800000-0x83ffff, RAM addresses of the tool's map); this build indexes the array. 0 in the dump. Dword (stw). RAM working value, so no _cal. The array itself keeps its crank_ name for now (it is the e2m Pulse_Period_Table_Backup).",
    old_comment_wrong=False,
)

B[61] = dict(
    new="cylinder_balance_service_fueling_trim_maximum",
    evidence="e2m 8C73 +4 CBD_Service_Trim_Maximum 'Cylinder Balancing Fueling Trim Service Maximum' (MM3S, signed): cm848_runCylinderContributionTest `cylinder_balance_fueling_trim_maximum = cylinder_diag_low_threshold_cal;` loads it as the trim maximum for the test (the learned maximum is saved in cylinder_balance_fueling_trim_maximum_snapshot and restored at the end); lha 1, never written (signed, i16 would fit); 147 in the dump = 10.0 mm3; the old name says low threshold and has a _cal in RAM; wave 13 bin 2 lead",
    quote="cylinder_balance_fueling_trim_maximum = cylinder_diag_low_threshold_cal;",
    comment="e2m 8C73 +4 CBD_Service_Trim_Maximum (MM3S, 0.0679 mm3 per count, signed, 2 bytes, 0-400): 'Cylinder Balancing Fueling Trim Service Maximum'. The trim maximum used while the cylinder contribution test runs: cm848_runCylinderContributionTest stores it in cylinder_balance_fueling_trim_maximum (e2m 81AE +C CBD_Fueling_Trim_Maximum) when the test starts, after saving the learned maximum in cylinder_balance_fueling_trim_maximum_snapshot, and the learned value comes back when the test ends. Signed (lha). 147 in the dump = 10.0 mm3." + TAIL + " Not a low threshold.",
)

B[62] = dict(
    new="cylinder_balance_service_fueling_trim_minimum",
    evidence="e2m 8C73 +6 CBD_Service_Trim_Minimum 'Cylinder Balancing Fueling Trim Service Minimum' (MM3S, signed): cm848_runCylinderContributionTest `cylinder_balance_fueling_trim_minimum = cylinder_diag_high_threshold_cal;` loads it as the trim minimum for the test (the learned minimum is saved in cylinder_balance_fueling_trim_minimum_snapshot and restored at the end); lha 1, never written (signed, i16 would fit); -147 in the dump = -10.0 mm3; the old name says high threshold and has a _cal in RAM; wave 13 bin 2 lead",
    quote="cylinder_balance_fueling_trim_minimum = cylinder_diag_high_threshold_cal;",
    comment="e2m 8C73 +6 CBD_Service_Trim_Minimum (MM3S, 0.0679 mm3 per count, signed, 2 bytes, -400..0): 'Cylinder Balancing Fueling Trim Service Minimum'. The trim minimum used while the cylinder contribution test runs: cm848_runCylinderContributionTest stores it in cylinder_balance_fueling_trim_minimum (e2m 81AE +E CBD_Fueling_Trim_Minimum) when the test starts, after saving the learned minimum in cylinder_balance_fueling_trim_minimum_snapshot, and the learned value comes back when the test ends. Signed (lha). -147 in the dump = -10.0 mm3." + TAIL + " Not a high threshold.",
)

B[63] = dict(
    new="cylinder_contribution_test_gain",
    evidence="e2m 8C73 +8 Cylinder_Contribution_Gain 'Gain for cylinder contribution calculation (100 - delta fueling * gain)' (0.125 per count): cm848_runCylinderContributionTest `uVar3 = (uint)cylinder_diag_scale_factor_cal;` then each cylinder_N_contribution_percent = 100 - learned trim x gain x 4 / 471 clamped to 0-200; 2 lhz, never written; 24 in the dump = 3.0; wave 13 bin 2 lead",
    quote="uVar3 = (uint)cylinder_diag_scale_factor_cal;",
    comment="e2m 8C73 +8 Cylinder_Contribution_Gain (UNITLESS, 0.125 per count, 2 bytes, 0-10): 'Gain for cylinder contribution calculation (100 - delta fueling * gain)'. cm848_runCylinderContributionTest turns each firing order slot's learned fueling trim (cylinder_balance_fueling_trim_cal) into the cylinder's contribution percent = 100 - trim x this x 4 / 471, clamped to 0-200 (cylinder_N_contribution_percent, DRB SCI FD-E1 to FD-EB); the 0.0679 mm3 per count of the trim makes it 3.0 percent per mm3 of trim at the dump value. 24 in the dump = 3.0." + TAIL + " Not a diagnostic scale factor.",
)
