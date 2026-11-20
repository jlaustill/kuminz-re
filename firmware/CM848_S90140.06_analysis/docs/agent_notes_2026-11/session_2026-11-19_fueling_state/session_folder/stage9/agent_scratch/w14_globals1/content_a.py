# Content for bin items 0-30 (renames, one keep, one drift). Keys: new, evidence, quote, comment, plus optional flags.
A = {}

A[0] = dict(
    new="cruise_resume_active_flag_previous",
    evidence="cm848_arbitrateGovernedFueling stores cruise_resume_active_flag in it at the end of every pass (sth @ 0x406b8) and reads it at the start of the next (lhz @ 0x4064c): `(fuel_demand_enable_sync_flag_shadow == 0)` in the first pass of cruise control (9) or vehicle speed limit (10) calls protectionRampRateControl; the old name carries the retired name of cruise_resume_active_flag (fuel_demand_enable_sync_flag); no e2m record here",
    quote="fuel_demand_enable_sync_flag_shadow = cruise_resume_active_flag;",
    comment="cruise_resume_active_flag (e2m 117D +60 Cruise_Resume_Status 'Status of the Cruise Control Resume') as it was at the end of the previous pass: cm848_arbitrateGovernedFueling stores it at the end of every pass (sth @ 0x406b8) and reads it back in the next one (lhz @ 0x4064c). In a first pass of cruise control (9) or vehicle speed limit (10), when the previous pass was neither of them and this word is 0, it calls protectionRampRateControl. The dword at 0x3fb526 is two words: governor_fuel_demand_working_mode_prev and this one. No e2m record at this address.",
)

A[1] = dict(
    new="cylinder_balance_fueling_trim_maximum_snapshot",
    evidence="cm848_runCylinderContributionTest saves the limit before it loads the service value and restores it when the test ends: `cylinder_diag_low_threshold_snapshot = cylinder_balance_fueling_trim_maximum;` ... `cylinder_balance_fueling_trim_maximum = cylinder_diag_low_threshold_snapshot;`; the limit is a trim maximum (e2m 81AE +C CBD_Fueling_Trim_Maximum), not a low threshold; sth 1 / lha 1 (signed, i16 would fit)",
    quote="cylinder_diag_low_threshold_snapshot = cylinder_balance_fueling_trim_maximum;",
    comment="Saved copy of cylinder_balance_fueling_trim_maximum (e2m 81AE +C CBD_Fueling_Trim_Maximum, the upper limit of the learned cylinder trims) while the cylinder contribution test runs: cm848_runCylinderContributionTest stores it (sth) when the test starts and loads the service maximum cylinder_balance_service_fueling_trim_maximum (e2m 8C73 +4) in its place, then writes it back (lha) once cylinder_contribution_test_status is no longer 1. Signed word. Its twin is cylinder_balance_fueling_trim_minimum_snapshot at 0x3fb5a6; the six saved trims before them (0x3fb598) are unnamed. No e2m record at this address.",
)

A[2] = dict(
    new="cylinder_balance_fueling_trim_minimum_snapshot",
    evidence="cm848_runCylinderContributionTest: `cylinder_diag_high_threshold_snapshot = cylinder_balance_fueling_trim_minimum;` saves the limit, `cylinder_balance_fueling_trim_minimum = cylinder_diag_high_threshold_snapshot;` restores it when the test ends; the limit is a trim minimum (e2m 81AE +E CBD_Fueling_Trim_Minimum), not a high threshold; sth 1 / lha 1 (signed, i16 would fit)",
    quote="cylinder_diag_high_threshold_snapshot = cylinder_balance_fueling_trim_minimum;",
    comment="Saved copy of cylinder_balance_fueling_trim_minimum (e2m 81AE +E CBD_Fueling_Trim_Minimum, the lower limit of the learned cylinder trims) while the cylinder contribution test runs: cm848_runCylinderContributionTest stores it (sth) when the test starts and loads the service minimum cylinder_balance_service_fueling_trim_minimum (e2m 8C73 +6) in its place, then writes it back (lha) once cylinder_contribution_test_status is no longer 1. Signed word. Its twin is cylinder_balance_fueling_trim_maximum_snapshot at 0x3fb5a4. No e2m record at this address.",
)

A[3] = dict(
    new="data_collector_fill_stop_address",
    evidence="diag_dm1Buffer_circularFill copies it at entry (`dVar1 = diag_dm1_buffer_fill_end_ptr;`) and stops when the write pointer reaches it (`} while (data_collector_end_address != (undefined *)dVar1)`, then fill phase 3); cm848_phase_groupB_calculation writes it 6 times (stw) with buffer start + 0x8000 - remainder, start + entries x (capacity >> 1) - 1 (stop mode 1), the buffer end (stop mode 2) or end pointer + entries x half capacity; no e2m record here; the diag_dm1_* words are the data collector",
    quote="diag_dm1_buffer_fill_end_ptr = (dword)diag_dm1_buffer_end_ptr;",
    comment="Address at which the current data collector fill stops (no e2m record at this address in the 11.46.06 table). cm848_phase_groupB_calculation (the collector pass) sets it when it starts a fill: one past the buffer end (buffer start + 0x8000 - the unused remainder) while it records before the trigger - never reached, the write pointer wraps at the buffer end first -, buffer start + table entries x (data_collector_sample_capacity >> 1) - 1 for stop mode 1 (diag_dm1_fill_mode_config, e2m Collector_Stop_Mode), the buffer end data_collector_buffer_end_address for stop mode 2, and the write pointer + entries x half the capacity (wrapped) when the trigger arrives in mode 1 with the buffer already running. diag_dm1Buffer_circularFill copies it at entry and stops filling when the write pointer data_collector_end_address reaches it, then sets fill phase 3. Written 6 times (stw), read once (lwz). Not a DM1 buffer.",
    old_comment_wrong=True,
)

A[4] = dict(
    new="data_collector_fill_phase",
    evidence="cm848_phase_groupB_calculation tests `if (diag_dm1_buffer_fill_phase == 0) {` to start the buffer and sets 1 (trigger not yet active: `diag_dm1_buffer_fill_phase = 1; diag_dm1Buffer_circularFill();`), 2 (trigger active: fill up to the stop address) or 3; diag_dm1Buffer_circularFill sets 3 when the fill ends or the buffer is full in stop mode 3; hpcr_exception_process (the collector reset) sets 0; dword (stw 8 / lwz 1); no e2m record",
    quote="if (diag_dm1_buffer_fill_phase == 0) {",
    comment="Fill phase of the data collector ring buffer (no e2m record at this address): 0 idle or not started (cm848_phase_groupB_calculation sets it while the collector is disabled - governor_fault_status_flags bit 0x100 clear - and in phase 3 once the trigger is cleared; hpcr_exception_process, the collector reset, sets it too), 1 recording before the trigger (circular fill with no stop address), 2 recording after the trigger up to data_collector_fill_stop_address, 3 stopped (the post-trigger fill ended, or the buffer filled in stop mode 3 and diag_dm1Buffer_circularFill set data_collector_status 2). Dword (stw / lwz). Not a DM1 state.",
    old_comment_wrong=True,
)

A[5] = dict(
    new="data_collector_buffer_has_data_flag",
    evidence="diag_dm1Buffer_circularFill: `if (diag_dm1_buffer_slot_started_flag != 0) break;` leads to the normal path that moves the write pointer on before it stores, otherwise it stores the first byte at the write pointer itself and sets the flag to 1; cm848_phase_groupB_calculation clears it when it restarts the buffer (write = read = buffer start), j1939_dm1_diagnosticMessage_send clears it when the read pointer has caught up with the write pointer; word (sth 4 / lhz 1)",
    quote="if (diag_dm1_buffer_slot_started_flag != 0) break;",
    comment="Set to 1 once the data collector ring buffer holds a byte at the write pointer (data_collector_end_address), 0 while the buffer is empty (no e2m record at this address): diag_dm1Buffer_circularFill stores the first byte of an empty buffer at the write pointer itself and sets this word to 1, every later byte goes one position further (pointer + 1, wrapped from data_collector_buffer_end_address to the buffer start); cm848_phase_groupB_calculation clears it whenever it restarts the buffer (write pointer = read pointer = buffer start) and j1939_dm1_diagnosticMessage_send clears it when the read pointer data_collector_start_address has reached the write pointer, i.e. the whole buffer was sent. 0 / 1, word (sth / lhz). Not a DM1 buffer slot.",
    old_comment_wrong=True,
)

A[6] = dict(
    new="data_collector_multiple_countdown",
    evidence="cm848_phase_groupB_calculation: `if (diag_dm1_protection_repeat_countdown != 0) { ... - 1; goto LAB_00506360; }` skips the sample while it counts down, and `diag_dm1_protection_repeat_countdown = data_collector_multiple_cal - 1;` reloads it (e2m 003A +6 Collector_Multiple 'Value indicating 20 msec multiple for data collection') before the trigger line is read and the buffer filled; word (lhz 1 / sth 2); the old name says DM1 protection warning",
    quote="diag_dm1_protection_repeat_countdown = data_collector_multiple_cal - 1;",
    comment="Countdown of the data collector sampling interval (no e2m record at this address; the interval is e2m 003A +6 Collector_Multiple, 'Value indicating 20 msec multiple for data collection', data_collector_multiple_cal): cm848_phase_groupB_calculation counts it down once per pass while it is not 0 and skips the sample (it only calls j1939_dm1_diagnosticMessage_send); when it is 0 it reloads data_collector_multiple_cal - 1 (when that is not 0), reads the trigger input line and fills the buffer. So one sample is taken every data_collector_multiple_cal passes. Word (lhz / sth). Not a DM1 protection warning repeat interval.",
    old_comment_wrong=True,
)

A[7] = dict(
    new="data_collector_table_entry_count",
    evidence="cm848_phase_groupB_calculation counts the non-zero entries of the collector address table into it (`diag_dm1_active_fault_entry_count = diag_dm1_active_fault_entry_count + 1;` per entry, at most up to load_histogram_start_engine_hours_cal) and divides 0x8000 by it; diag_dm1Buffer_circularFill stops a sample after that many entries (`&diag_dm1_fault_source_table + uVar3 <= pdVar2`); j1939_dm1_diagnosticMessage_send rounds its 0x20 byte limit to whole samples with it; hpcr_exception_process clears it; word (lhz 5 / sth 3)",
    quote="diag_dm1_active_fault_entry_count = diag_dm1_active_fault_entry_count + 1;",
    comment="Number of address entries of the data collector table (data_collector_address_table_cal, e2m 003B Collector_Table; no e2m record at this address): cm848_phase_groupB_calculation counts the non-zero entries (up to the 32 the table holds) when it starts the buffer; one sample is one byte read from each entry, so diag_dm1Buffer_circularFill stops a sample after this many entries, 0x8000 / this = data_collector_sample_capacity, and j1939_dm1_diagnosticMessage_send rounds its 0x20 byte message limit down to a whole number of samples with it. hpcr_exception_process (the collector reset) clears it, and so does cm848_phase_groupB_calculation in phase 3 when the stop mode is not 3. Word (lhz / sth). Not a DM1 fault entry count.",
    old_comment_wrong=True,
)

A[8] = dict(
    new="data_collector_sample_capacity",
    evidence="cm848_phase_groupB_calculation: `uVar2 = 0x8000 / uVar3;` (uVar3 = entry count) is stored here (`diag_dm1_bytes_per_fault_slot = (word)uVar2;`), `DAT_003fbcb4 = diag_dm1_active_fault_entry_count * diag_dm1_bytes_per_fault_slot;` is the bytes used, the buffer end is start + 0x7fff - (0x8000 - entries x this), and the stop mode 1 fill is entries x (this >> 1) bytes: it is the sample capacity of the 0x8000 byte buffer; word (sth 1 / lhz 1); no e2m record",
    quote="DAT_003fbcb4 = diag_dm1_active_fault_entry_count * diag_dm1_bytes_per_fault_slot;",
    comment="Capacity of the data collector ring buffer in samples, one sample being one byte per table entry (no e2m record at this address): cm848_phase_groupB_calculation sets it to 0x8000 / data_collector_table_entry_count when it starts the buffer; the bytes actually used are entries x this (DAT_003fbcb4), the leftover 0x8000 - entries x this bytes stay unused, so data_collector_buffer_end_address = buffer start + 0x7fff - leftover, and the post-trigger fill of stop mode 1 is half a buffer (entries x (this >> 1) bytes). Word (sth / lhz). Not a bytes per DM1 fault slot.",
    old_comment_wrong=True,
)

A[9] = dict(
    new="data_collector_trigger_input_previous_flag",
    evidence="cm848_phase_groupB_calculation: after `sVar1 = cm848_readDiscreteInputLine(data_collector_trigger_input_line_cal)` a 0 clears it, an active line sets data_collector_trigger_active_cal and, `if (diag_dm1_protection_warning_latch == 0) {`, adds 1 to data_collector_trigger_count_cal and sets it to 1: a rising edge memory of the trigger input; word (lhz 1 / sth 1)",
    quote="if (diag_dm1_protection_warning_latch == 0) {",
    comment="Memory of the data collector trigger input line from the previous sample (no e2m record at this address): cm848_phase_groupB_calculation reads the line (data_collector_trigger_input_line_cal, e2m Data_Collector_Trigger_Map) with cm848_readDiscreteInputLine each sample; a low line clears this word, an active line sets the trigger data_collector_trigger_active_cal and, when this word is still 0, adds 1 to data_collector_trigger_count_cal (e2m Data_Collector_Trigger_Count) and sets this word to 1, so each activation of the line is counted once. 0 / 1, word (lhz / sth). Not a DM1 protection warning latch.",
    old_comment_wrong=True,
)

A[10] = dict(
    new="egr_orifice_temperature_lead_time_constant_lookup",
    evidence="sensor_throttleTrim_ema_faultProcess: `throttle_trim_predictor_gain_lookup = lookupTableInterpolation(&WORD_003fbcfe, egr_mass_flow_delayed_filtered, WORD_ARRAY_00406778, WORD_ARRAY_0040678c, 0)` then `egr_orifice_temperature_lead_time_constant = throttle_trim_predictor_gain_lookup` unless sensor_channel108_fault_status != 0, air_handling_compensation_and_diagnostic_bypass_cal != 0 or algorithm_enable_flags_20_cal bit 0x8000 clear (then 0); sensor_channel108_filter multiplies the channel 108 step by that constant; cm848_initialization_step_14 points ema_filter_state_t_003fbd00.coefficient at it; sth 1; wave 13 renamed the e2m 19CA siblings (0x40a692 / 0x40a696) but not this table result",
    quote="(egr_orifice_temperature_lead_time_constant = throttle_trim_predictor_gain_lookup,",
    comment="Table lookup result of the EGR orifice temperature lead time constant (e2m 19CA +A INM_EGRT_Lead_Time_Constant 'Current active EGR orifice temperature lead time constant', SEC at 0.01 per count; the active value is egr_orifice_temperature_lead_time_constant; no e2m record at this address): sensor_throttleTrim_ema_faultProcess interpolates it every pass from egr_mass_flow_delayed_filtered (lookupTableInterpolation over the ROM tables WORD_ARRAY_00406778 / WORD_ARRAY_0040678c) and copies it into egr_orifice_temperature_lead_time_constant unless sensor channel 108 has a fault, air_handling_compensation_and_diagnostic_bypass_cal is set or algorithm_enable_flags_20_cal bit 0x8000 is clear (then that constant is 0). cm848_initialization_step_14 also points the coefficient of the EMA filter record at 0x3fbd00 (ema_filter_state_t_003fbd00) at it. Written once (sth). 500 in the dump = 5.0 s, while the active egr_orifice_temperature_lead_time_constant reads 0 there (algorithm_enable_flags_20_cal bit 0x8000 is clear in this calibration). Not a throttle trim predictor.",
    old_comment_wrong=True,
)

A[11] = dict(
    new="output_shaft_to_vehicle_speed_divisor_low_axle_ratio",
    evidence="cm848_computeProtectionTrimDivisors: `(uint)rear_axle_ratio_low_cal * (uint)protection_timing_period_cal` (e2m 1180 +6 Rear_Axle_Ratio_Low x e2m 132C +0 Tire_Size 'NUMBER OF TIRE REVOLUTIONS PER MILE') is stored here; cm848_calculateVehicleSpeedFromOutputShaft divides output_shaft_speed_current x 0x3c000 by it into vehicle_speed_unfiltered when `two_speed_axle_enable_cal == 0` or switch 31 (switch_input_state_bits[3] & 0x80) is clear, else by the high ratio twin; lwz 1 / stw 1; no fuel trim or protection logic",
    quote="(ulonglong)protection_trim_divisor_working);",
    comment="Divisor that turns the transmission output shaft speed into vehicle speed, for the low rear axle ratio (no e2m record at this address): cm848_computeProtectionTrimDivisors stores rear_axle_ratio_low_cal (e2m 1180 +6 Rear_Axle_Ratio_Low, 1/128 per count) x protection_timing_period_cal (e2m 132C +0 Tire_Size, 'NUMBER OF TIRE REVOLUTIONS PER MILE') here, i.e. output shaft revolutions per mile x 128. cm848_calculateVehicleSpeedFromOutputShaft, on the J1939 automatic drivetrain, divides output_shaft_speed_current (1/8 rpm) x 0x3c000 (60 x 4096) by it to get vehicle_speed_unfiltered (1/256 mph; the divisor carries the 1/128 scale of the axle ratio) when two_speed_axle_enable_cal is 0 or switch 31 is clear; with a two-speed axle and switch 31 set it divides by output_shaft_to_vehicle_speed_divisor_high_axle_ratio. Dword (lwz / stw). 113703 in the dump = 453 x 251 (rear_axle_ratio_low_cal x protection_timing_period_cal; the 251 is below the e2m Tire_Size range 300-725). Not a fuel trim or protection divisor.",
    old_comment_wrong=True,
)

A[12] = dict(
    new="output_shaft_to_vehicle_speed_divisor_high_axle_ratio",
    evidence="cm848_computeProtectionTrimDivisors: `protection_trim_divisor_cal = (uint)rear_axle_ratio_high_cal * (uint)protection_timing_period_cal;` (e2m 1180 +C Rear_Axle_Ratio_High x e2m 132C +0 Tire_Size); cm848_calculateVehicleSpeedFromOutputShaft divides output_shaft_speed_current x 0x3c000 by it when two_speed_axle_enable_cal is set and switch 31 (switch_input_state_bits[3] & 0x80) is set, else by the low ratio twin; lwz 1 / stw 1; the old name has a _cal outside the EEPROM mirror and says fuel trim",
    quote="protection_trim_divisor_cal = (uint)rear_axle_ratio_high_cal * (uint)protection_timing_period_cal;",
    comment="Divisor that turns the transmission output shaft speed into vehicle speed, for the high (second) rear axle ratio (no e2m record at this address): cm848_computeProtectionTrimDivisors stores rear_axle_ratio_high_cal (e2m 1180 +C Rear_Axle_Ratio_High, 1/128 per count) x protection_timing_period_cal (e2m 132C +0 Tire_Size, tire revolutions per mile) here, i.e. output shaft revolutions per mile x 128. cm848_calculateVehicleSpeedFromOutputShaft divides output_shaft_speed_current x 0x3c000 by it into vehicle_speed_unfiltered when two_speed_axle_enable_cal is set and switch 31 is set (the second axle ratio is selected); otherwise it uses output_shaft_to_vehicle_speed_divisor_low_axle_ratio. Dword (lwz / stw). 113703 in the dump = 453 x 251 (rear_axle_ratio_high_cal x protection_timing_period_cal). ROM-to-RAM window outside the EEPROM mirror, so no _cal. Not a fuel trim or protection divisor.",
    old_comment_wrong=True,
)

A[13] = dict(
    new="coolant_temperature_sensor_performance_temperature_minimum",
    evidence="cm848_checkCoolantTemperatureSensorPerformance (P0116: fault 401 -> ROM 0x5985a slot table -> obd_dtc_code_table): loaded with protection_group29_coolant_temp_snapshot at the start of a run and lowered by `if ((short)sensor_readings_t_0040baf2.coolant_temp < (short)cssc_coolant_temp_min) {` ... = coolant_temp; its span to the maximum is cssc_coolant_temp_span; sth 2 / lha 1 (signed, i16 would fit); lead from wave 13 bin 5 (cssc is an invented abbreviation)",
    quote="if ((short)sensor_readings_t_0040baf2.coolant_temp < (short)cssc_coolant_temp_min) {",
    comment="Lowest coolant temperature (sensor_readings_t.coolant_temp, 1/64 degree F per count) seen by the coolant temperature sensor performance monitor (no e2m record at this address): cm848_checkCoolantTemperatureSensorPerformance, the P0116 coolant temperature rationality monitor (fault 401 -> ROM 0x5985a slot table -> obd_dtc_code_table), loads it with the soak snapshot protection_group29_coolant_temp_snapshot when it starts watching (engine running after the snapshot) and lowers it whenever the coolant reads lower; the span to coolant_temperature_sensor_performance_temperature_maximum (cssc_coolant_temp_span) must reach the ROM constant DAT_000642d6 for the monitor to pass. Signed word (sth / lha).",
    old_comment_wrong=True,
)

A[14] = dict(
    new="coolant_temperature_sensor_performance_temperature_maximum",
    evidence="cm848_checkCoolantTemperatureSensorPerformance: loaded with protection_group29_coolant_temp_snapshot at the start of a run and raised by `if ((short)cssc_coolant_temp_max < (short)sensor_readings_t_0040baf2.coolant_temp) {` ... = coolant_temp; `cssc_coolant_temp_span = cssc_coolant_temp_max - cssc_coolant_temp_min;`; sth 2 / lha 1 (signed, i16 would fit); wave 13 bin 5 lead (the cssc family becomes coolant_temperature_sensor_performance_*)",
    quote="if ((short)cssc_coolant_temp_max < (short)sensor_readings_t_0040baf2.coolant_temp) {",
    comment="Highest coolant temperature (sensor_readings_t.coolant_temp, 1/64 degree F per count) seen by the coolant temperature sensor performance monitor (no e2m record at this address): cm848_checkCoolantTemperatureSensorPerformance (P0116, fault 401) loads it with the soak snapshot protection_group29_coolant_temp_snapshot when it starts watching and raises it whenever the coolant reads higher; cssc_coolant_temp_span = this - coolant_temperature_sensor_performance_temperature_minimum, and a span at or above the ROM constant DAT_000642d6 clears fault 401 (the coolant rose enough). Signed word (sth / lha).",
    old_comment_wrong=True,
)

A[15] = dict(
    new="coolant_temperature_sensor_performance_precheck_done_flag",
    evidence="cm848_checkCoolantTemperatureSensorPerformance: `if ((cssc_coolant_snapshot_taken_flag == 0) &&` is followed by the comma expression `cssc_coolant_snapshot_taken_flag = 1,` and the fault bit tests, so the flag is set in the first pass after the startup timer reaches 0 and only then tests the intake manifold / battery temperature sensor faults (faults 19 / 20 / 354 / 353 / 379 / 380 = P0113 / P0112 / P0111 / P0514 / P0517 / P0516 via ROM 0x5985a -> obd_dtc_code_table), abandoning the run (state 6) if one is set; the temperature snapshot comes later, after the dwell count; cm848_initialization_group22_state clears it; byte (lbz 1 / stb 2)",
    quote="if ((cssc_coolant_snapshot_taken_flag == 0) &&",
    comment="One-shot guard of the coolant temperature sensor performance monitor (no e2m record at this address): cm848_checkCoolantTemperatureSensorPerformance (P0116, fault 401) sets it to 1 in the first pass after its startup timer reaches 0 and only in that pass tests whether any intake manifold temperature sensor fault (faults 19 / 20 / 354 = P0113 / P0112 / P0111) or battery temperature sensor fault (faults 353 / 379 / 380 = P0514 / P0517 / P0516; ROM 0x5985a slot table -> obd_dtc_code_table) is set - if so the run is abandoned (monitor state 6, readiness bit cleared). The temperature snapshot is taken later, after coolant_temperature_sensor_performance_snapshot_dwell_count has counted up. cm848_initialization_group22_state clears it to 0. Byte (lbz / stb). Not a snapshot flag.",
    old_comment_wrong=True,
)

A[16] = dict(
    new="coolant_temperature_sensor_performance_soak_conditions_met_flag",
    evidence="cm848_checkCoolantTemperatureSensorPerformance sets it to 1 at the snapshot once the soak tests pass (the test DAT_000642de <= intake manifold temperature - battery temperature ends the run first, then the engine-off time tests) and `if (protection_group29_conditions_met_flag != 1) {` at the end of the watching window abandons the run (state 6) instead of setting the fault; cm848_initialization_group22_state clears it; byte (stb 2 / lbz 1); plate: after a soak (intake air under 10 F above the battery temperature, engine off 480 or more)",
    quote="if (protection_group29_conditions_met_flag != 1) {",
    comment="Set to 1 when the soak conditions of the coolant temperature sensor performance test (P0116, fault 401) are met (no e2m record at this address): at its temperature snapshot cm848_checkCoolantTemperatureSensorPerformance takes the intake manifold and battery temperatures and, when the intake manifold temperature is less than the ROM constant DAT_000642de above the battery temperature and the engine-off time is long enough (coolant_temperature_check_minimum_engine_off_time), sets this byte to 1; at the end of the watching window the monitor sets the fault only when it is 1 (else it abandons the run, state 6). cm848_initialization_group22_state clears it to 0. Byte (stb / lbz), 0 / 1. Not a protection group 29 flag.",
    old_comment_wrong=True,
)

A[17] = dict(
    new="coolant_temperature_sensor_performance_snapshot_dwell_count",
    evidence="cm848_checkCoolantTemperatureSensorPerformance: `if (cssc_coolant_precheck_dwell_count < DAT_000642e0) {` adds 1 per pass and returns, so the temperature snapshot (coolant, battery, intake manifold) and the soak tests run only once the count has reached the ROM constant DAT_000642e0, after the one-shot sensor precheck; cm848_initialization_group22_state clears it; word (lhz 1 / sth 2)",
    quote="if (cssc_coolant_precheck_dwell_count < DAT_000642e0) {",
    comment="Dwell counter of the coolant temperature sensor performance monitor before its temperature snapshot (no e2m record at this address): cm848_checkCoolantTemperatureSensorPerformance (P0116, fault 401) adds 1 per pass, after the one-shot sensor precheck coolant_temperature_sensor_performance_precheck_done_flag, until it reaches the ROM constant DAT_000642e0, and only then takes the snapshot of the coolant, battery and intake manifold temperatures and runs the soak tests. cm848_initialization_group22_state clears it to 0. Word (lhz / sth).",
    old_comment_wrong=True,
)

A[18] = dict(
    new="data_collector_address_table_cal",
    evidence="diag_dm1Buffer_circularFill reads each dword entry (4 lwz) and stores the byte it points at (`pdVar2 = &diag_dm1_fault_source_table;`, an address below 0x1000000, else 0); hpcr_exception_process stores its address in data_collector_table_address; cm848_phase_groupB_calculation counts the non-zero entries up to load_histogram_start_engine_hours_cal (0x3fde44 = 32 entries from 0x3fddc4); e2m 003B +0 Collector_Table 'Table to be collected by the data collector' (its first word, the length, is at 0x3fddc2); EEPROM mirror, so _cal",
    quote="data_collector_table_address = (dword)&diag_dm1_fault_source_table;",
    type_note="one dword row at the head of a 32-entry table of dword byte addresses (0x3fddc4-0x3fde43, ends at load_histogram_start_engine_hours_cal; 4 lwz in the two readers); the e2m record 003B +0 Collector_Table starts at 0x3fddc2 with a length word (128 in the dump = 0x80 bytes = 32 x 4) and covers the table, so the row should be dword[32] (and 0x3fddc2 a word row for the length)",
    comment="e2m 003B Collector_Table (HEX): 'Table to be collected by the data collector'. The table of up to 32 byte addresses the data collector samples (dword entries, a 0 ends the list), EEPROM mirror so _cal: the e2m record starts at 0x3fddc2 with the table length word (0x0080 = 32 x 4 bytes in the dump, see data_collector_table_address) and these entries start at 0x3fddc4 and end at load_histogram_start_engine_hours_cal (0x3fde44). cm848_phase_groupB_calculation counts the non-zero entries (data_collector_table_entry_count) and diag_dm1Buffer_circularFill stores the byte each entry points at (an address below 0x1000000, else 0) into the ring buffer once per sample; hpcr_exception_process stores the table address in data_collector_table_address. Row typed dword: the table is dword[32]. Not a DM1 fault source table.",
    old_comment_wrong=True,
)

A[19] = dict(
    new="logical_output_request_bits_40_to_47",
    evidence="byte 5 of the 80-bit array at 0x40c080 (cm848_setLogicalOutputRequest sets bit n & 7 of byte n >> 3): the tests `(protection_enable_byte_35 & 8)` / `& 0x10` in cm848_mainLoopMonitor, cm848_updateIntakeAirHeaterRunupPhase and diagnosticMainStateProcessor go with cm848_setLogicalOutputRequest(0x2b / 0x2c, 0) = requests 43 / 44, the intake air heater relays; 4 reads (lbz), no write; wave 13 bin 4 lead; siblings are logical_output_request_bits_48_to_55 / _64_to_71 / _72_to_79",
    quote="if ((protection_enable_byte_35 & 8) != 0) {",
    comment="Byte 5 of the 80-bit logical output request array at 0x40c080 (requests 40-47; cm848_setLogicalOutputRequest sets bit n & 7 of byte n >> 3), the same layout as logical_output_request_bits_48_to_55: bit 0x08 = request 43 and bit 0x10 = request 44, the two intake air heater (grid heater) relays (cm848_setLogicalOutputRequest(0x2b / 0x2c, 0) and cm848_clearLogicalOutputRequest in the intake air heater code). Read with lbz by cm848_updateIntakeAirHeaterRunupPhase (the run-up elapsed ticks count only while both bits are set), cm848_mainLoopMonitor (a set bit re-issues its request with cm848_clearLogicalOutputAndDriveLine / cm848_setLogicalOutputRequest) and diagnosticMainStateProcessor (system_switch_status_2 bits 2 / 3); written only through cm848_setLogicalOutputRequest. No e2m record at this address.",
    old_comment_wrong=False,
)

A[20] = dict(
    new="data_collector_buffer_end_address",
    evidence="e2m 0032 +4 Buffer_End 'Physical RAM address of the end of the data collector buffer': cm848_phase_groupB_calculation sets `diag_dm1_buffer_end_ptr = diag_dm1_buffer_start_ptr + (0x7fff - iVar4);` (iVar4 = the unused remainder of the 0x8000 byte buffer); diag_dm1Buffer_circularFill and j1939_dm1_diagnosticMessage_send wrap the write / read pointer from it back to the buffer start; 0 in the dump (collector idle); dword (lwz 5 / stw 1); the buffer start twin 0x40c270 is in another bin",
    quote="diag_dm1_buffer_end_ptr = diag_dm1_buffer_start_ptr + (0x7fff - iVar4);",
    comment="e2m 0032 +4 Buffer_End [HEX] 'Physical RAM address of the end of the data collector buffer' (4 bytes; 0 in the dump, the collector is idle): the last usable byte of the data collector ring buffer. cm848_phase_groupB_calculation sets it to the buffer start (diag_dm1_buffer_start_ptr, e2m 0031 Buffer_Start, storage from 0x40c28a) + 0x7fff - the unused remainder of the 0x8000 byte buffer (data_collector_sample_capacity x table entries bytes are used) when it starts the buffer; diag_dm1Buffer_circularFill wraps the write pointer data_collector_end_address and the read pointer data_collector_start_address back to the buffer start once they pass it, and j1939_dm1_diagnosticMessage_send wraps its read position the same way. Not a DM1 buffer.",
    old_comment_wrong=True,
)

A[21] = dict(
    new="alpha_state",
    evidence="e2m 104A +4 [APAPST] Alpha_State 'Indicate the source (base, user, altitude, epf, slave, esp) of alpha' (0-5): hpcr_calculateFuelTrimOutput stores 0 / 1 / 2 / 3 / 4 / 5 with combustion_alpha_input = alpha_base / fuel_blend_coefficient_startup_cal (governor_feature_flags bit 0) / altitude_derate_alpha / engine_protection_alpha / governor_startup_fuel_blend_coeff (master_slave_override_enable_flag) / fuel_blend_coefficient_run_cal (governor_feature_config_flags bit 0x8000 and governor_startup_threshold = 0x4000); 6 stores (sth), no read; 0 in the dump; wave 13 bin 6 lead",
    quote="governor_startup_state = 3;",
    comment="e2m 104A +4 [APAPST] Alpha_State (UNITLESS, 0-5): 'Indicate the source (base, user, altitude, epf, slave, esp) of alpha'. The source hpcr_calculateFuelTrimOutput picked for combustion_alpha_input in its last pass: 0 base (alpha_base), 1 user (fuel_blend_coefficient_startup_cal, governor_feature_flags bit 0), 2 altitude (altitude_derate_alpha, when cm848_checkPressureFuelState is true), 3 epf, the engine protection fault derate (engine_protection_alpha), 4 slave (master_slave_override_enable_flag set: governor_startup_fuel_blend_coeff), 5 esp (governor_feature_config_flags bit 0x8000 with governor_startup_threshold = 0x4000, e2m ESP_Tau: fuel_blend_coefficient_run_cal). Written by 6 sth, no reader. 0 in the dump. Not a governor start-up state.",
    old_comment_wrong=False,
)

A[22] = dict(
    new="alpha_low_ambient_air_pressure_result",
    evidence="e2m 104A +12 [APAAPRSS] Alpha_Low_Ambient_Air_Pressure 'Alpha based only on ambient air pressure logic': cm848_checkPressureHysteresis returns 1 below alpha_lock_on_barometric_pressure, 0 above alpha_lock_off_barometric_pressure and else `iVar1 = (int)(short)pressure_hysteresis_state;`; timingProtectionFlagsOrchestrator stores it (`pressure_hysteresis_state = cm848_checkPressureHysteresis();`) and ORs it into the alpha ramp condition; lha 1 / sth 1; 0 in the dump; wave 13 bin 6 lead",
    quote="pressure_hysteresis_state = cm848_checkPressureHysteresis();",
    comment="e2m 104A +12 [APAAPRSS] Alpha_Low_Ambient_Air_Pressure (UNITLESS): 'Alpha based only on ambient air pressure logic'. The result of the ambient air pressure condition of the alpha ramp: cm848_checkPressureHysteresis returns 1 while barometric_pressure_reference is below alpha_lock_on_barometric_pressure (e2m Alpha_Lock_On_Air_Pressure), 0 once it is above alpha_lock_off_barometric_pressure, and otherwise this word again (the hysteresis memory, read signed with lha); timingProtectionFlagsOrchestrator stores it when governor_fault_status_flags bit 0x8000 is set and ORs it into the condition that ramps alpha_base toward 1. 0 in the dump. A sibling result is alpha_fuel_rate_result (e2m +8 Alpha_Fuel_Rate).",
    old_comment_wrong=False,
)

A[23] = dict(
    new="alpha_low_speed_governor_timer",
    evidence="e2m 104A +16 [APLSTR] Alpha_LSG_Timer 'Trace the time since fueling state has left LSG state' (SEC 0.2): cm848_checkPressureFuelDelayA reloads it (`cold_start_timer_a = low_speed_governor_alpha_timeout;`, e2m LSG_Alpha_Timeout) while alpha_low_speed_governor_state_detected_flag is 1 and counts it down otherwise; hpcr_calculateFuelTrimOutput reloads it at engine stop / crank / jump start; sth 3; 1550 in the dump = 310 s; wave 13 bin 6 lead",
    quote="cold_start_timer_a = low_speed_governor_alpha_timeout;",
    comment="e2m 104A +16 [APLSTR] Alpha_LSG_Timer (SEC, 0.2 per count, 0-900): 'Trace the time since fueling state has left LSG state'. cm848_checkPressureFuelDelayA reloads it with low_speed_governor_alpha_timeout (e2m LSG_Alpha_Timeout) while alpha_low_speed_governor_state_detected_flag is 1 and counts it down (cold_start_timer_a_active_flag) once per alpha execution afterwards; when it reaches 0 the low speed governor alpha condition turns 1; hpcr_calculateFuelTrimOutput reloads it while engine_state is STOPPED, CRANKING or JUMP_START. 1550 in the dump = 310 s. Not a cold start timer.",
    old_comment_wrong=False,
)

A[24] = dict(
    new="alpha_air_fuel_control_timer",
    evidence="e2m 104A +18 [APAFTR] Alpha_AFC_Timer 'Trace the time since fueling state is not AFC or LSG.' (SEC 0.2): cm848_checkPressureFuelDelayB reloads it (`cold_start_timer_b = air_fuel_control_alpha_timeout;`, e2m AFC_Alpha_Timeout) while alpha_air_fuel_control_state_detected_flag or alpha_low_speed_governor_state_detected_flag is 1 and counts it down otherwise; hpcr_calculateFuelTrimOutput reloads it at engine stop / crank / jump start; sth 3; 1750 in the dump = 350 s; wave 13 bin 6 lead",
    quote="cold_start_timer_b = air_fuel_control_alpha_timeout;",
    comment="e2m 104A +18 [APAFTR] Alpha_AFC_Timer (SEC, 0.2 per count, 0-900): 'Trace the time since fueling state is not AFC or LSG.'. cm848_checkPressureFuelDelayB reloads it with air_fuel_control_alpha_timeout (e2m AFC_Alpha_Timeout) while alpha_air_fuel_control_state_detected_flag or alpha_low_speed_governor_state_detected_flag is 1 and counts it down (cold_start_timer_b_active_flag) once per alpha execution afterwards; when it reaches 0 the air fuel control alpha condition turns 1; hpcr_calculateFuelTrimOutput reloads it while engine_state is STOPPED, CRANKING or JUMP_START. 1750 in the dump = 350 s. Not a cold start timer.",
    old_comment_wrong=False,
)

A[25] = dict(
    new="cruise_top_droop_width_cal",
    evidence="governorCruiseStateMachine: `cruise_ramp_rate_b_computed = governor_cruise_tableLimit_calc(cruise_ramp_zone_b_fuel_demand_threshold, ...)` on `governor_cruise_rampRate_calc(cruise_fuel_demand_ramp_ceiling - cruise_ramp_zone_b_fuel_demand_threshold, rear_axle_ratio_low_cal)` (and the same with rear_axle_ratio_high_cal into DAT_003fcff2): the exact twin of road_speed_governor_top_droop_width_cal (e2m 1185 +8, wave 12, was cruise_ramp_zone_d_fuel_demand_threshold); e2m 1185 +4 Cruise_Top_Droop_Width (MPH, 1/256) fits; 4 lhz, never written; 0 in the dump; the name lacks _cal in the EEPROM mirror; wave 13 bin 2 lead",
    quote="(cruise_fuel_demand_ramp_ceiling - cruise_ramp_zone_b_fuel_demand_threshold,",
    comment="EEPROM 0x490 - e2m 1185 +4 Cruise_Top_Droop_Width 'TOP DROOP WIDTH FOR CRUISE CONTROL.' (MPH, 1/256 mph; 0 in the dump): the speed width of the upper droop line of the cruise governor: governorCruiseStateMachine turns it into cruise_ramp_rate_b_computed (governor_cruise_rampRate_calc on cruise_fuel_demand_ramp_ceiling - this width with rear_axle_ratio_low_cal, then governor_cruise_tableLimit_calc) and, with rear_axle_ratio_high_cal, into DAT_003fcff2; drivetrain_type DRIVETRAIN_MANUAL_VSS copies the first into cruise_ramp_rate_b_working (e2m 1187 +1A Cruise_Top_Droop_Gain). The road speed governor twin is road_speed_governor_top_droop_width_cal (e2m 1185 +8) and the lower line is cruise_bottom_droop_width_cal (+2). EEPROM mirror, so _cal. Not a fuel demand threshold.",
    old_comment_wrong=True,
)

A[26] = dict(
    new="j1708_link_fault_timeout_count_cal",
    evidence="e2m 11C1 +0 [JC17TMCU] J1708_Link_Fault_Timeout_Count: cm848_processGovernorModeTransition counts it up on the path where j1939_tsc1_override_state.etc1_active_state is not 1 (`if ((int)(uint)etc1_state_timeout_counter < (int)(j1939_link_fault_timeout_count_limit - 1)) {`) and sets fault_detected_bits_96_to_111 bit 0x4000 (fault 110, slot 170 = no OBD code) at the limit; the twin j1939_link_fault_timeout_count_cal (+2) is the state 1 (J1939 TSC1) path, and j1939_tsc1_override_state.etc1_active_state is stored only with 1 (accept_etc1_command in the J1939 TSC1 receive handler, no other store in the decompile), so this path is the state 0 one; the J1708 attribution is the record plus elimination (medium confidence; j1708 is the SAE designation like j1939); sth 3 / lhz 2; 0 in the dump; the name lacks _cal in the EEPROM mirror; wave 13 bin 5 lead",
    quote="if ((int)(uint)etc1_state_timeout_counter < (int)(j1939_link_fault_timeout_count_limit - 1)) {",
    comment="EEPROM 0x170a (mirror) - e2m 11C1 +0 [JC17TMCU] J1708_Link_Fault_Timeout_Count (CNTS, 0-1000): 'Current number of J1708 (J1922) time-outs since powerdown or fault set'. cm848_processGovernorModeTransition adds 1 per expired TSC1 / retarder request timer while j1939_tsc1_override_state.etc1_active_state is not 1 (the J1939 path, state 1, counts in the twin j1939_link_fault_timeout_count_cal; torqueControlModeHandler, the J1939 TSC1 receive handler, is the only writer of that state) and the count is below j1939_link_fault_timeout_count_limit - 1 (e2m Jcomm_Link_Fault_Timeout_Limit); at the limit it sets fault_detected_bits_96_to_111 bit 0x4000 (fault 110; slot 170 of ROM 0x5985a, no OBD code) and returns to 0. The J1708 reading rests on the record and on this twin (medium confidence). 0 in the dump. Word (lhz / sth). EEPROM mirror, so _cal.",
    old_comment_wrong=False,
)

A[27] = dict(
    new="pressure_sensor_check_delay_time",
    evidence="e2m 165C +6 Pressure_Check_Delay_Time 'Delay time since last shutdown before running pressure check algorithm' (SEC 0.005): cm848_processSensorDeviationOnKeyoff adds 1 to cold_start_deviation_delay_timer per pass while engine_state is STOPPED and, `if (cold_start_sensor_deviation_delay_cal < cold_start_deviation_delay_timer) {`, runs cm848_checkSensorDeviationFlags (the pressure sensor agreement check) and clears sensor_deviation_check_pending_flag; the timer restarts when the engine is not stopped; lhz 1, never written; 400 in the dump = 2.0 s; RAM outside the EEPROM mirror, so no _cal; wave 13 bin 5 lead",
    quote="if (cold_start_sensor_deviation_delay_cal < cold_start_deviation_delay_timer) {",
    comment="e2m 165C +6 Pressure_Check_Delay_Time (SEC, 0.005 per count, 0-327.675): 'Delay time since last shutdown before running pressure check algorithm'. cm848_processSensorDeviationOnKeyoff (runs only with algorithm_enable_flags_6_cal bit 0x20 set and sensor_deviation_check_pending_flag 1) adds 1 to cold_start_deviation_delay_timer per pass while engine_state is STOPPED and, once the timer exceeds this word, runs the pressure sensor agreement check cm848_checkSensorDeviationFlags (barometric pressure against the two other pressure readings, with the tolerances barometric_pressure_sensor_tolerance / boost_pressure_sensor_tolerance / oil_pressure_sensor_tolerance) and clears the pending flag; the timer restarts at 0 whenever the engine is not stopped. 400 in the dump = 2.0 s. ROM-copied constant in RAM, so no _cal.",
    old_comment_wrong=False,
)

A[28] = dict(
    keep=True,
    e2m_note="e2m 16A2 +C TGC_VT_Cmd 'Turbocharger position command to actuator controller' (% at 1/128, 0-100; the struct base: request_half_duty_counts, 12800 = 100 percent; 10896 in the dump = 85.1 percent) - the 11 words +C..+20 (TGC_Error, TGC_Turbo_Spd_Drt_Error, TGC_Turbo_Drt_SET_Gain, TGC_Final_LLim, TGC_LLim_Altitude_Offset, TGC_Max_Closing, TGC_Min_Closing, TGC_Final_ULim, TGC_ULim_Altitude_Offset, TGC_E_Brake_ULim) are its other fields; the name is more specific than the record",
)

A[29] = dict(
    new="wastegate_duty_compressor_outlet_temperature_derate_derivative_term",
    evidence="e2m 16A2 +26 TGC_COT_Deriv_Term 'COT limiter derivative term' (1/32, signed, -800..800): cm848_calculateWastegateDutyRequest sets `governor_rpm_correction_term = (word)lVar1;` = (compressor_outlet_temperature - fuel_flow_rate_prev_snapshot) x fuel_flow_rate_divisor_cal / 0x294 clamped to -0x6400 / +0x6400 (-800 / +800) on every second pass, then subtracts it from (charge_flow_compressor_outlet_temperature_derate_limit - compressor_outlet_temperature) x governor_trim_lookup_result x fuel_flow_rate_gain_cal >> 14 to form wastegate_duty_compressor_outlet_temperature_derate_error_term; sth 1 / lha 1 (signed, i16 would fit); 1 in the dump; wave 13 bin 1 suggested wastegate_duty_second_error_derivative_term, this keeps the wording of its +28 sibling",
    quote="governor_rpm_correction_term = (word)lVar1;",
    comment="e2m 16A2 +26 TGC_COT_Deriv_Term (UNITLESS, 1/32 per count, signed, -800..800): 'COT limiter derivative term'. The derivative term of the compressor outlet temperature limiter of the wastegate duty controller: cm848_calculateWastegateDutyRequest sets it, on every second pass (governor_first_iteration_flag alternates), to (compressor_outlet_temperature - its previous value) x fuel_flow_rate_divisor_cal / 660, clamped to +-0x6400 (+-800), and subtracts it from the temperature error x gain term to form wastegate_duty_compressor_outlet_temperature_derate_error_term (e2m +28 TGC_COT_Drt_Error). The turbocharger speed limiter's derivative term is governor_pid_adjustment_output (e2m +22 TGC_Turbo_Deriv_Term). Signed word (sth / lha). 1 in the dump. Not an rpm correction.",
    old_comment_wrong=False,
)

A[30] = dict(
    drift=True,
    evidence="e2m 1966 +94 TVA_Position_Sensor (DEG, signed) resolves here but the code holds the fault status of the barometric pressure sensor channel: cm848_sensorChannel0_init / _process pass `&barometric_pressure_sensor_fault_status);` as the fault status output (parameter 13) of sensorChannelTypeB_configInit / _update, and cm848_selectBarometricPressure / cm848_initializeBarometricPressureSelection test it for 0 / 1 / 2 (`if ((barometric_pressure_sensor_fault_status == 0) ||`); the 11.46.06 block 1966 ends its value / default pairs at +92 and its fault status words start at 0x40be14 (known drift 1966 +94 on, 0x40be16 is sensor_channel20_fault_status); name kept, lhz 1 / lha 1, 0 in the dump",
)
