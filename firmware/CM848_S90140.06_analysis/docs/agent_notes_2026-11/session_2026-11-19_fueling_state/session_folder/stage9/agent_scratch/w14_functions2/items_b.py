"""Items 14-27 of the functions2 bin (0x255c0 .. 0x508ee0). Plain data, no logic."""

ITEMS_B = []

# ---------------------------------------------------------------- 0x000255c0
ITEMS_B.append({
    "address": "0x000255c0",
    "old": "cm848_j1939SendDm1ResponseMessage",
    "new": "cm848_sendPgn65232NonContinuousMonitorTestResultMessage",
    "code_quote": "sendJ1939Message(&j1939_pgn65232_tx_message);",
    "evidence": (
        "PGN proof in cm848_initJ1939EngineControlBuffer (0x2560c): j1939_pgn65232_tx_message.header.can_id is built from the "
        "constant 0xfed000 (PGN 65232), data_length 8, data pointer 0x3fad6e. This function stores param_1 as byte 1 (test "
        "identifier, SPN 1224), byte reverses the 16-bit param_2 into bytes 3-4 (test value, SPN 1226) with "
        "j1939_reverseByteOrder16 and sends the descriptor; byte 2 and the limit words stay 0xff / 0xffff from that init. The "
        "only caller cm848_j1939HandlePgn58112Dm7 (0x227a0) answers its command with test 0 = intake_air_heater_monitor_result "
        "(gated by supported_non_continuous_monitors_bits 0x100) and test 1 = misfire_monitor_result (0x200). The local j1939 "
        "database names PGN 65232 Test Results for Non-continuously Monitored Systems (SPN 1224 .. 1228); it is not a DM1 "
        "(PGN 65226). Name spells the PGN title out instead of the Dm8 abbreviation."),
    "plate_comment": (
        "Sends one test result of the non-continuously monitored systems, PGN 65232 (Test Results for Non-continuously Monitored "
        "Systems; transmit descriptor j1939_pgn65232_tx_message, 8 bytes, set by cm848_initJ1939EngineControlBuffer at 0x2560c). "
        "param_1 is the test identifier (SPN 1224, byte 1: 0 = the intake air heater monitor, 1 = the misfire monitor) and "
        "param_2 the 16-bit test value (SPN 1226, byte swapped with j1939_reverseByteOrder16 into bytes 3-4). The test type byte "
        "and the limit words keep their 0xff / 0xffff initial values (not available). The only caller is "
        "cm848_j1939HandlePgn58112Dm7 (0x227a0), the handler of the command for these tests (PGN 58112), which passes "
        "intake_air_heater_monitor_result for test 0 and misfire_monitor_result for test 1."),
})

# ---------------------------------------------------------------- 0x00026f80
ITEMS_B.append({
    "address": "0x00026f80",
    "old": "cm848_j1939FormatDm1Message",
    "new": "cm848_runTsc1LostManagement",
    "code_quote": "etc1_torque_limit_integrator = etc1_torque_limit_integrator + tsc1_lost_torque_ramp_rate;",
    "evidence": (
        "Called in three places of cm848_processGovernorModeTransition (0x2715c): with no override active (governor_mode 0 and "
        "etc1_speed_error_timeout below 2), when etc1_activation_confirm_timer expires (the sender then goes into the ignored "
        "request list with cm848_addEngineTsc1IgnoredRequestEntry) and when a request's etc1_speed_error_timeout runs out (modes "
        "1 / 2 / 3). Branch 1: "
        "fuel_demand_control_t_0040a57a.calculated above tsc1_lost_management_minimum_accelerator_pedal and below "
        "etc1_fuel_demand_high_limit (e2m 11C1 +4 TSC_Lost_Max_Throttle_Disable, 'Throttle % above which TSC lost management is "
        "disabled') with etc1_speed_error_timeout_flag = 1: while fuel_demand_timing_enable_flag is 1 it adds "
        "tsc1_lost_torque_ramp_rate to etc1_torque_limit_integrator (etc1_mode3_torque_limit = it >> 6) and "
        "tsc1_lost_speed_ramp_rate to etc1_torque_limit_value, then governor_mode = 3. Else: etc1_mode3_torque_limit = "
        "tsc1_lost_reset_torque_limit (0xffff at or above the maximum throttle), governor_mode = 0, "
        "_j1939_governor_source_index = 0, integrator = limit << 6, etc1_torque_limit_value = the current rpm. It always clears "
        "etc1_control_flags, etc1_speed_error_timeout and etc1_activation_confirm_timer. The e2m names this feature TSC lost "
        "management (10E7 +28 .. +30 TSC_Lost_*); the record 10E7 +2A TSC_Lost_Reset_Speed (ROM 0x5c3ac, no row) has no load "
        "in the disassembly (no -15444(rN) displacement read), so the speed limit restarts from the current rpm instead; no DM1 "
        "message is formatted (task 045 wave 12 lead)."),
    "plate_comment": (
        "Runs the J1939 TSC1 lost management (the e2m TSC_Lost_* records, 10E7 +28 .. +30 and 11C1 +4): it hands the engine back "
"to the accelerator pedal when a TSC1 control request has timed out. Called in three places of "
        "cm848_processGovernorModeTransition (0x2715c): with no override active (governor mode 0, etc1_speed_error_timeout below "
        "2), when the activation confirm timer etc1_activation_confirm_timer expires (the sender then goes into the ignored "
        "request list with cm848_addEngineTsc1IgnoredRequestEntry) and when a request's etc1_speed_error_timeout runs out (modes "
        "1 / 2 / 3). It keeps the governor mode in governor_mode_snapshot. While the accelerator pedal "
        "(fuel_demand_control_t_0040a57a.calculated, 400 = 100 percent) is above tsc1_lost_management_minimum_accelerator_pedal "
        "(TSC_Lost_Min_Throttle_Disable) and below etc1_fuel_demand_high_limit (11C1 +4 TSC_Lost_Max_Throttle_Disable) and "
        "etc1_speed_error_timeout_flag is 1, then, while fuel_demand_timing_enable_flag is 1, it adds tsc1_lost_torque_ramp_rate "
        "to etc1_torque_limit_integrator (the torque limit etc1_mode3_torque_limit is its value >> 6, at most 0xffff) and "
        "tsc1_lost_speed_ramp_rate to the speed limit j1939_tsc1_override_state.etc1_torque_limit_value, and sets governor mode "
        "3. Outside those throttle limits it resets: etc1_mode3_torque_limit = tsc1_lost_reset_torque_limit "
        "(TSC_Lost_Reset_Torque; 0xffff, no limit, at or above the maximum throttle), governor mode 0, "
        "_j1939_governor_source_index 0, the integrator = limit << 6 and the speed limit = the current engine speed. It always "
        "clears etc1_control_flags, etc1_speed_error_timeout and etc1_activation_confirm_timer. The e2m TSC_Lost_Reset_Speed "
        "(10E7 +2A, ROM 0x5c3ac) is not read: no load of that word was found in the disassembly. It formats no DM1 message."),
})

# ---------------------------------------------------------------- 0x0050be6c
ITEMS_B.append({
    "address": "0x0050be6c",
    "old": "governor_calibSnapshot_rollingBuffer_update",
    "new": "cm848_storeJ1939ControlSessionInHistoryTable",
    "code_quote": "pwVar4 = j1939_input_signal_timeouts + uVar3 * 0xc + 0x18;",
    "evidence": (
        "param_1 = 0 copies the 12 words at 0x3feb50 (e2m 10FE J1939_Active_Engine, length word 24 at 0x3feb4e), else those at "
        "0x3feb6a (10FF J1939_Active_Retarder), to j1939_input_signal_timeouts + index x 12 + 24 words = 0x3fead4 + 24 x index "
        "(first store at +2 after the pre-increment): the e2m 10FD J1939_History_Table (length word 0x78 at 0x3fead4, 5 entries x "
        "24 bytes; the RAM dump reads 120 there). The index is j1939_history_table_next_entry_index_cal (1100 +8 "
        "J1939_History_Table_Next_Entry): the copy uses the index value read before the increment (uVar3), and the stored index "
        "is then incremented and set to 0 when it exceeds 4. Only caller phase_group_a_setupETC1Controller (0x50bff4). Not a "
        "calibration snapshot."),
    "plate_comment": (
        "Files a finished J1939 control session in the J1939 history table (e2m 10FD J1939_History_Table: a length word 0x78 at "
        "0x3fead4, then 5 entries of 24 bytes from 0x3fead6). param_1 selects the session record: 0 is the engine control "
        "(TSC1) record at 0x3feb50 (e2m 10FE J1939_Active_Engine), any other value the retarder control record at 0x3feb6a (10FF "
        "J1939_Active_Retarder). Its 12 words are copied into the history entry number j1939_history_table_next_entry_index_cal "
        "(e2m 1100 +8 J1939_History_Table_Next_Entry), and that index is incremented and wraps from 4 to 0. The destination is "
        "written as j1939_input_signal_timeouts + index x 12 + 24 words, which is the table at 0x3fead4 behind that 25 word "
        "array. Called by phase_group_a_setupETC1Controller (0x50bff4) when a control session ends or its source changes."),
})

# ---------------------------------------------------------------- 0x0050beec
ITEMS_B.append({
    "address": "0x0050beec",
    "old": "governor_sourceData_init",
    "new": "cm848_startJ1939ControlSession",
    "code_quote": "etc1_governor_calib_session_start_time = key_on_hour_meter;",
    "evidence": (
        "param_1 = 0: j1939_engine_control_active_flag_cal = 1 (e2m 1100 +0 J1939_Engine_Control_Status), "
        "j1939_engine_control_source_index_cal = _j1939_governor_source_index (+4 J1939_Engine_Control_Source: 1 TRANS 2 ABS 3 "
        "ASR 4 UNKNOWN), and the record at 0x3feb50 (e2m 10FE J1939_Active_Engine) gets kind 0, "
        "j1939_tsc1_override_state.etc1_spn1482_source_address, the source index, a mode history with write index 1 and "
        "j1939_tsc1_override_state.governor_mode as first entry, four cleared entries and the start time key_on_hour_meter; any "
        "other value does the same for the retarder record at 0x3feb6a (kind 1, engine_retarder_controlling_source_address / "
        "_index, engine_retarder_override_control_mode, j1939_retarder_control_active_flag_cal, "
        "j1939_retarder_control_source_index_cal). Called by phase_group_a_setupETC1Controller (0x50bff4). It initializes no "
        "governor source data."),
    "plate_comment": (
        "Opens a J1939 control session record. param_1 = 0 starts an engine control (TSC1) session: "
        "j1939_engine_control_active_flag_cal = 1 (e2m 1100 +0 J1939_Engine_Control_Status), "
        "j1939_engine_control_source_index_cal (+4 J1939_Engine_Control_Source; 1 = transmission, 2 = ABS, 3 = ASR, 4 = unknown) "
        "takes _j1939_governor_source_index, and the active record at 0x3feb50 (e2m 10FE J1939_Active_Engine) gets kind 0, the "
        "controlling source address j1939_tsc1_override_state.etc1_spn1482_source_address, the source index, a mode history whose "
        "write index is 1 with j1939_tsc1_override_state.governor_mode as first entry and four cleared entries, and the start "
        "time key_on_hour_meter in etc1_governor_calib_session_start_time. Any other param_1 does the same for the retarder "
        "control session (record at 0x3feb6a, e2m 10FF J1939_Active_Retarder, kind 1; engine_retarder_controlling_source_address, "
        "engine_retarder_controlling_source_index, engine_retarder_override_control_mode, "
        "j1939_retarder_control_active_flag_cal, j1939_retarder_control_source_index_cal). Called by "
        "phase_group_a_setupETC1Controller (0x50bff4)."),
})

# ---------------------------------------------------------------- 0x0050bff4
ITEMS_B.append({
    "address": "0x0050bff4",
    "old": "phase_group_a_setupETC1Controller",
    "new": "cm848_trackJ1939ControlSessions",
    "code_quote": "DAT_003feb64 = key_on_hour_meter - etc1_governor_calib_session_start_time;",
    "evidence": (
        "Returns unless governor_feature_config_word & 0x800 (e2m 106B +6 J1939_Monitor_Enable; 15888 = 0x3e10 in the dump, bit "
        "set). Compares j1939_tsc1_override_state.governor_mode / etc1_active_state / etc1_spn1482_source_address and "
        "engine_retarder_override_control_mode / engine_retarder_controlling_source_address with the *_transition_snapshot "
        "words: starts a session (governor_sourceData_init 0x50beec) when a control begins, appends governor modes to the five "
        "entry mode history while the same source controls, and when it ends or the source changes stores the duration "
        "(key_on_hour_meter - session start time), clears j1939_engine_control_active_flag_cal / "
        "j1939_retarder_control_active_flag_cal and files the record with governor_calibSnapshot_rollingBuffer_update "
        "(0x50be6c). Called by cm848_phase_group_a_processing (0xb7b4); it sets up no ETC1 controller."),
    "plate_comment": (
        "J1939 monitor (enabled by bit 0x800 of governor_feature_config_word, e2m 106B +6 J1939_Monitor_Enable; set in this "
        "calibration, 15888 = 0x3e10 in the RAM dump): tracks the sessions in which another device controls the engine or the "
        "retarder over J1939. It compares the engine control (TSC1) state j1939_tsc1_override_state.governor_mode / "
        "etc1_active_state / etc1_spn1482_source_address and the retarder control state engine_retarder_override_control_mode / "
        "engine_retarder_controlling_source_address with the values kept in the *_transition_snapshot words "
        "(etc1_governor_mode_transition_snapshot and so on). When a control starts it opens a session record "
        "(governor_sourceData_init at 0x50beec; e2m 10FE J1939_Active_Engine at 0x3feb50 and 10FF J1939_Active_Retarder at "
        "0x3feb6a). While the same source keeps controlling it appends each new mode to the record's mode history of five entries "
        "(shifting it when full). When the control ends, or the controlling source changes, it stores the session duration "
        "(key_on_hour_meter minus the start time) in the record, clears the control active flag (e2m 1100 +0 / +2 "
        "J1939_Engine_Control_Status / J1939_Retarder_Control_Status) and files the record in the J1939 history table with "
        "governor_calibSnapshot_rollingBuffer_update (0x50be6c). Called by cm848_phase_group_a_processing (0xb7b4)."),
})

# ---------------------------------------------------------------- 0x00505c20
ITEMS_B.append({
    "address": "0x00505c20",
    "old": "diag_dm1Buffer_circularFill",
    "new": "cm848_fillDataCollectorRingBuffer",
    "code_quote": "data_collector_end_address = data_collector_end_address + 1;",
    "evidence": (
        "Reads one byte at each address of the collector table (diag_dm1_fault_source_table = e2m 003B Collector_Table, 32 "
        "entries from 0x3fddc4; addresses at or above 0x01000000 read as 0) and stores them at the write pointer "
        "data_collector_end_address (e2m 0035 Collector_End_Address), wrapping from diag_dm1_buffer_end_ptr to "
        "diag_dm1_buffer_start_ptr; at the read pointer data_collector_start_address (0033 Collector_Start_Address) it pushes the "
        "read pointer on, except in stop mode 3 (diag_dm1_fill_mode_config = e2m Collector_Stop_Mode) where it sets "
        "data_collector_trigger_active_cal = 1, data_collector_status = 2 and stops. Called by cm848_phase_groupB_calculation "
        "(0x505f98). No DM1 message is built; the bin 4 form (RingBuffer) keeps the circular fill of the old name."),
    "plate_comment": (
        "Stores one sample of the data collector in its ring buffer: the bytes at the addresses of the collector table (e2m 003B "
        "Collector_Table, up to 32 addresses at diag_dm1_fault_source_table, diag_dm1_active_fault_entry_count of them; an address "
        "at or above 0x01000000 reads as 0) go to consecutive buffer positions at the write pointer data_collector_end_address "
        "(e2m 0035 Collector_End_Address), which wraps from diag_dm1_buffer_end_ptr to diag_dm1_buffer_start_ptr. When the write "
        "pointer reaches the read pointer data_collector_start_address (e2m 0033 Collector_Start_Address) the oldest byte is "
        "overwritten (the read pointer moves on), except in stop mode 3 (diag_dm1_fill_mode_config, e2m Collector_Stop_Mode): "
        "there it sets the fill phase diag_dm1_buffer_fill_phase to 3, data_collector_trigger_active_cal to 1 and "
        "data_collector_status to 2 (full) and stops. The fill ends at diag_dm1_buffer_fill_end_ptr. Called by "
        "cm848_phase_groupB_calculation (0x505f98), the data collector pass."),
})

# ---------------------------------------------------------------- 0x00505d94
ITEMS_B.append({
    "address": "0x00505d94",
    "old": "hpcr_exception_process",
    "new": "cm848_resetDataCollector",
    "code_quote": "data_collector_table_address = (dword)&diag_dm1_fault_source_table;",
    "evidence": (
        "Sets data_collector_status = 0 (e2m 0036 Collector_Status), data_collector_trigger_active_cal = 0 (0039 "
        "Collector_Trigger), diag_dm1_buffer_start_ptr / data_collector_end_address / data_collector_start_address all to "
        "0x40c28a (the buffer base), data_collector_table_address (0037) = diag_dm1_fault_source_table, "
        "diag_dm1_buffer_fill_phase = 0 and diag_dm1_active_fault_entry_count = 0. Callers: cm848_applicationMain (0x544c4) at "
        "start-up and j1939_dm1_diagnosticMessage_send (0x505df0) when its transport session does not end in state 5, so reset "
        "(bin 4) rather than initialize (bin 6). The hpcr_ prefix does not fit: the collector is no rail pressure code."),
    "plate_comment": (
        "Resets the data collector to its empty state: data_collector_status 0 (e2m 0036 Collector_Status: not collecting), "
        "data_collector_trigger_active_cal 0 (e2m 0039 Collector_Trigger), the buffer start pointer diag_dm1_buffer_start_ptr and "
        "the write and read pointers data_collector_end_address / data_collector_start_address (e2m 0035 / 0033) all at the "
        "buffer base 0x40c28a, data_collector_table_address (e2m 0037 Collector_Table_Address) at the collector address table "
        "diag_dm1_fault_source_table, the fill phase diag_dm1_buffer_fill_phase 0 and the entry count "
        "diag_dm1_active_fault_entry_count 0. Called by cm848_applicationMain (0x544c4) at start-up and by "
        "j1939_dm1_diagnosticMessage_send (0x505df0) when its transport protocol session does not end in state 5."),
})

# ---------------------------------------------------------------- 0x00505df0
ITEMS_B.append({
    "address": "0x00505df0",
    "old": "j1939_dm1_diagnosticMessage_send",
    "new": "cm848_sendDataCollectorBuffer",
    "code_quote": "initiateJ1939TransportProtocol(pbVar2);",
    "evidence": (
        "Acts only when diag_dm1_fill_mode_config = 3 (Collector_Stop_Mode) and data_collector_start_address != "
        "data_collector_end_address: counts the buffered bytes (cut to whole samples within 32 bytes), takes a transport buffer "
        "with j1939_selectResponseBuffer, sets the can_id bytes 0x18 / 0xff / 0xff / j1939_source_address (priority 6, PF 0xff, "
        "PS 0xff: a broadcast), copies the bytes from the ring buffer, starts "
        "initiateJ1939TransportProtocol (its branch for PF 0xff, control byte 0x20) and runs j1939_transport_singleFrame_send while "
        "the state is 0x11; only when the session started (state 0x10) does data_collector_start_address move past the sent bytes, "
        "and a session that does not end in state 5 resets the collector with hpcr_exception_process (0x505d94). "
        "Called at the end of every cm848_phase_groupB_calculation (0x505f98) pass. No DM1 (PGN 65226) is built."),
    "plate_comment": (
        "Sends the collected data of the data collector over J1939. It acts only in stop mode 3 (diag_dm1_fill_mode_config, e2m "
        "Collector_Stop_Mode) and while the read pointer data_collector_start_address differs from the write pointer "
        "data_collector_end_address. It counts the buffered bytes (cut to a whole number of samples that fit into 32 bytes, "
        "that is 32 / diag_dm1_active_fault_entry_count x that count), takes a transport buffer with j1939_selectResponseBuffer, "
        "sets its can_id to priority 6, PF 0xff, PS 0xff and j1939_source_address (a broadcast that initiateJ1939TransportProtocol "
        "announces with the transport protocol) and copies the bytes out of the ring buffer (clearing "
        "diag_dm1_buffer_slot_started_flag when the copy reaches the write pointer). Only when the transport session started "
        "(state 0x10, then the packets go out with j1939_transport_singleFrame_send while the state is 0x11) is the read pointer "
        "data_collector_start_address moved past the sent bytes; without a started session it stays where it was, and a session "
        "that does not end in state 5 resets the collector with hpcr_exception_process (0x505d94). Called at the end of every "
        "cm848_phase_groupB_calculation (0x505f98) pass. It is not a DM1 message."),
})

# ---------------------------------------------------------------- 0x00505f98
ITEMS_B.append({
    "address": "0x00505f98",
    "old": "cm848_phase_groupB_calculation",
    "new": "cm848_runDataCollector",
    "code_quote": "sVar1 = cm848_readDiscreteInputLine(data_collector_trigger_input_line_cal);",
    "evidence": (
        "Sets the fill phase 0 and returns unless governor_fault_status_flags & 0x100 (e2m 106B +2 Collector_Enable, 'EEPROM "
        "indicator set by tools to enable data collector operation'; 39954 = 0x9c12 in the dump, bit clear, so the collector is "
        "off in this calibration); runs only when data_collector_schedule_cal (e2m 002F Collector_Schedule) equals param_1 (0 = "
        "cm848_phase_group_b_processing, 1 = hpcr_processEngineSyncPulses). Every data_collector_multiple_cal passes (e2m 003A "
        "Collector_Multiple) it reads cm848_readDiscreteInputLine(data_collector_trigger_input_line_cal), sets "
        "data_collector_trigger_active_cal and counts data_collector_trigger_count_cal; fill phase 0 sizes the 32768 byte ring "
        "(0x8000 / entries) and starts it, phases 1 / 2 call diag_dm1Buffer_circularFill (0x505c20), phase 3 holds; every pass ends "
        "with j1939_dm1_diagnosticMessage_send (0x505df0)."),
    "plate_comment": (
        "Runs one pass of the Cummins data collector (e2m records 002F .. 003B): a tool-controlled sampler of up to 32 addresses "
        "(the table e2m 003B Collector_Table at diag_dm1_fault_source_table) into a 32768 byte ring buffer, with an optional "
        "trigger. It sets the fill phase to 0 and returns unless the collector is enabled (governor_fault_status_flags bit 0x100, "
        "e2m 106B +2 Collector_Enable, 'EEPROM indicator set by tools to enable data collector operation'; clear in this "
        "calibration, 39954 = 0x9c12 in the RAM dump), and it runs only for the call selected by data_collector_schedule_cal "
        "(e2m 002F Collector_Schedule: 0 = cm848_phase_group_b_processing, 1 = hpcr_processEngineSyncPulses; param_1 is the call "
        "number). Every data_collector_multiple_cal passes (e2m 003A Collector_Multiple, a multiple of 20 ms) it reads the "
        "trigger input line data_collector_trigger_input_line_cal (e2m Data_Collector_Trigger_Map) with "
        "cm848_readDiscreteInputLine: an active line sets data_collector_trigger_active_cal (e2m 0039 Collector_Trigger) and "
        "counts data_collector_trigger_count_cal once per activation. Fill phase 0 counts the table entries, sizes the ring "
        "(diag_dm1_bytes_per_fault_slot = 0x8000 / entries, the buffer end and fill end pointers) and starts filling (phase 1, "
        "data_collector_status 1); phase 1 fills until the trigger and then continues as phase 2 by the stop mode "
        "(diag_dm1_fill_mode_config 1: half a buffer past data_collector_center_address, 2: from the buffer start to its end), "
        "phase 3 holds. The filling is diag_dm1Buffer_circularFill (0x505c20); every pass ends with "
        "j1939_dm1_diagnosticMessage_send (0x505df0)."),
})

# ---------------------------------------------------------------- 0x00027bc4
ITEMS_B.append({
    "address": "0x00027bc4",
    "old": "cm848_governorDroopCalculation",
    "new": "cm848_formatNumberAsDecimalText",
    "code_quote": "*pcVar3 = (char)uVar2 + (char)(uVar2 / 10) * -10 + '0';",
    "evidence": (
        "Each loop step writes (value mod 10) + '0' and divides by 10: for the dword at param_1 it writes param_3 zero padded "
        "digits backwards from param_2 + param_3; with param_3 = 1 it reads 4 bytes and writes each as two digits (8 "
        "characters; the bytes 11 46 6 0 give 11460600). Callers: cm848_j1939HandlePgn65259ComponentId (0x24870: the 8 digit "
        "text after the CMMNS make field, from the number at the string + 0x17), cm848_initPgn65242SoftwareIdHandler (0x268ac: "
        "two 8 digit numbers, then application_overlay_core_software_version with param_3 = 1), all star delimited ID strings. "
        "Wave 12 (task 045) had already read it as a number-to-text helper; nothing in it is a governor or a droop."),
    "plate_comment": (
        "Formats an unsigned number as zero padded decimal ASCII text. param_1 points at the number (a 4-byte value), param_2 is "
        "the text buffer and param_3 the digit count: the digits are written backwards, the last one at param_2 + param_3 - 1 "
        "(the callers use 8). param_3 = 1 is a special mode: param_1 is read as 4 bytes and each byte is written as two decimal "
        "digits, 8 characters in all (for example the bytes 11 46 6 0 give 11460600). Used for the star delimited ID strings of "
        "the J1939 component identification (cm848_j1939HandlePgn65259ComponentId, 0x24870) and software identification "
        "(cm848_initPgn65242SoftwareIdHandler, 0x268ac), whose last number is application_overlay_core_software_version (e2m "
        "0019 Calibration_Version_Number). It has nothing to do with a governor droop."),
})

# ---------------------------------------------------------------- 0x00508130
ITEMS_B.append({
    "address": "0x00508130",
    "old": "governor_coldStart_faultDerate_trigger",
    "new": "cm848_examineEngineProtectionBeforeCranking",
    "code_quote": "engine_protection_precrank_shutdown_command_flag = 1;",
    "evidence": (
        "Needs engine_state = ENGINE_STATE_CRANKING and governor_feature_config_word bits 0x10 / 0x1 / 0x20 (e2m 106B +6 "
        "Engine_Protection_Enable / Engine_Protection_Shutdown_Enable / Engine_Protection_Restart_Enable), "
        "governor_faultDerate_active_channel not 0xff and not 4, and DAT_0005c2f4 <= governor_faultDerate_consecutive_count "
        "(e2m 10B9 +0 Shutdown_Max_Limit, 'max number of shutdowns before restart is not allowed'; 65535 in the ROM) and the "
        "channel's shutdown and restart enable bits (bits 130 + 4n and 131 + 4n of the enable words at EEPROM 0x12a, e2m 106B "
        "+12); then protection_threshold_check (0x507ebc) on the channel's thresholds sets "
        "fuel_temperature_derate_precrank_error_flag (e2m 1152 +18 Fuel_Temperature_Precrank_Error) and "
        "engine_protection_precrank_shutdown_command_flag (10B1 +10 Precrank_Shutdown, 'EPF shutdown engine command from restart "
        "examine before cranking'). The dump reads 15888 = 0x3e10 in governor_feature_config_word, bit 0x1 clear, so it is "
        "inactive in this calibration. Called by cm848_runFaultDerateScheduler (0x507c44) on every pass. Wave 13 proposal "
        "taken; the name is the e2m phrase."),
    "plate_comment": (
        "Engine protection restart examination (e2m 10B1 +10 Precrank_Shutdown, 'EPF shutdown engine command from restart "
        "examine before cranking'). While the engine is CRANKING and the feature bits are set (governor_feature_config_word, "
        "e2m 106B +6: 0x10 Engine_Protection_Enable, 0x1 Engine_Protection_Shutdown_Enable, 0x20 Engine_Protection_Restart_Enable) "
        "it looks at the channel that caused the last shutdown (governor_faultDerate_active_channel, 0xff = none, channel 4 "
        "excluded) once that channel's consecutive shutdown count governor_faultDerate_consecutive_count has reached the ROM "
        "limit DAT_0005c2f4 (e2m 10B9 +0 Shutdown_Max_Limit, 'max number of shutdowns before restart is not allowed') and its "
        "shutdown and restart enable bits are set in the per channel enable words (e2m 106B +12, EEPROM 0x12a: bits 130 + 4n and "
        "131 + 4n). If a threshold of that channel is still exceeded (protection_threshold_check at 0x507ebc, for the thresholds "
        "selected by the masks 0x1 and 0x2 of the channel's configuration flags) it sets fuel_temperature_derate_precrank_error_flag for the "
        "channel (e2m 1152 +18 Fuel_Temperature_Precrank_Error) and engine_protection_precrank_shutdown_command_flag, which "
        "governor_faultDerate_mainLoop_update (0x508898) turns into engine_shutdown_command_flag. Called on every pass by "
        "cm848_runFaultDerateScheduler (0x507c44). The shutdown enable bit is clear in this calibration (15888 = 0x3e10 in "
        "governor_feature_config_word), so it does nothing here."),
})

# ---------------------------------------------------------------- 0x00508898
ITEMS_B.append({
    "address": "0x00508898",
    "old": "governor_faultDerate_mainLoop_update",
    "new": "cm848_updateEngineProtectionShutdown",
    "code_quote": "if ((uint)uVar3 + (uint)pwVar5[0xf] < (uint)*(ushort *)((int)ppuVar8 + 0x1a)) {",
    "evidence": (
        "(governor_feature_config_word & 1) == 0 (e2m 106B +6 Engine_Protection_Shutdown_Enable clear) or ENGINE_STATE_SHUTDOWN / "
        "STOPPED clears engine_protection_shutdown_approaching_flag, the two fuel_temperature_derate_*_shutdown_time_count words "
        "and governor_fuel_derate_j1939_latch; else, with governor_faultDerate_latch clear, for each channel whose shutdown enable "
        "bit (130 + 4n of the e2m 106B +12 words) is set it counts the time over each threshold with protection_event_timestamp "
        "(0x508834), sets engine_protection_shutdown_approaching_flag (e2m 10B1 +14 Shutdown_Approaching) when a time passes its "
        "start warning time and engine_shutdown_command_flag (10B1 +12 Shutdown, 'turn off all solenoids') when it exceeds the "
        "warning time plus the channel delay pwVar5[0xf], recording governor_faultDerate_active_channel; the override latch "
        "governor_fuel_derate_j1939_latch resets the timer to the warning time; restart results "
        "(engine_protection_precrank_shutdown_command_flag, governor_faultDerate_engine_sync_trigger = 10B1 +0 "
        "Restart_Oil_Pressure_Shutdown) also force the shutdown; governor_fuel_derate_state (10B1 +1E J1939_EP_Timer_State) is 3 "
        "when disabled (3 in the dump), 1 while timers run or the approach is set, else 0. Called by "
        "cm848_runFaultDerateScheduler (0x507c44) as task 4."),
    "plate_comment": (
        "Engine protection shutdown algorithm (e2m blocks 10B1 and 1152; enabled by bit 0 of governor_feature_config_word, e2m "
        "106B +6 Engine_Protection_Shutdown_Enable, clear in this calibration: 15888 = 0x3e10 in the RAM dump): the last of the "
        "five tasks of cm848_runFaultDerateScheduler (0x507c44). With the engine STOPPED it clears governor_faultDerate_latch; "
        "with the shutdown disabled, or in SHUTDOWN or STOPPED, it clears engine_protection_shutdown_approaching_flag, the two "
        "shutdown time counts (fuel_temperature_derate_fuel_shutdown_time_count / _rpm_) and the override latch "
        "governor_fuel_derate_j1939_latch. Otherwise, unless the latch governor_faultDerate_latch is set, it goes through the "
        "channels whose shutdown enable bit is set (bit 130 + 4n of the e2m 106B +12 enable words): it counts the time over each "
        "of the channel's two thresholds (protection_event_timestamp, 0x508834; e2m 1152 +1A / +1C), keeps the longest in "
        "governor_faultDerate_peak_value, sets engine_protection_shutdown_approaching_flag (e2m 10B1 +14 Shutdown_Approaching) "
        "when a time passes its start warning time, and sets engine_shutdown_command_flag (10B1 +12 Shutdown, 'turn off all "
        "solenoids') when it passes the warning time plus the channel's shutdown delay, recording the channel in "
        "governor_faultDerate_active_channel. An override request (the latch governor_fuel_derate_j1939_latch) sets the time back "
        "to the warning time and starts the override lamp flag at 0x40a78b (e2m 10B1 +19 EPF_Shutdown_Override_Lamp_Flag). The "
        "restart results engine_protection_precrank_shutdown_command_flag and governor_faultDerate_engine_sync_trigger (10B1 +0 "
        "Restart_Oil_Pressure_Shutdown) also force the shutdown. Each shutdown increments "
        "governor_faultDerate_total_event_count and, for the same channel, governor_faultDerate_consecutive_count, and is held in "
        "governor_faultDerate_latch. It ends by setting governor_fuel_derate_state (e2m 10B1 +1E J1939_EP_Timer_State): 3 when the "
        "shutdown is disabled, 1 while a timer runs or the approach flag is set, otherwise 0."),
})

# ---------------------------------------------------------------- 0x00508e78
ITEMS_B.append({
    "address": "0x00508e78",
    "old": "cm848_updateJ1939ReceptionControlFlag",
    "new": "cm848_detectEngineProtectionShutdownOverrideRequest",
    "code_quote": "governor_derate_j1939_trigger_pending = 1;",
    "evidence": (
        "Sets governor_derate_j1939_trigger_pending when j1939_feature_enable_flags_cal & 0x200 (e2m 106B +3C "
        "EPF_Shutdown_Override_Enable, 'algorithm enable for EPS shutdown override'; 0 in the dump), "
        "engine_protection_shutdown_approaching_flag is set and logical switch 31 (switch_input_state_bits[3] & 0x80) is on while "
        "governor_derate_j1939_protection_active_prev is 0 (a rising edge); the previous state is saved on every call. The "
        "request is the e2m 10B1 +18 EPF_Shutdown_Override_Flag 'EPS shutdown override request detected', latched by "
        "governor_derateTrigger_latch_clear (0x508ee0). Called by cm848_periodicTaskSet_auxiliaryControl; no J1939 message is "
        "received."),
    "plate_comment": (
        "Detects an engine protection shutdown override request (e2m 10B1 +18 EPF_Shutdown_Override_Flag, 'EPS shutdown override "
        "request detected'): when the override algorithm is enabled (bit 0x200 of j1939_feature_enable_flags_cal, e2m 106B +3C "
        "EPF_Shutdown_Override_Enable), engine_protection_shutdown_approaching_flag is set and logical switch 31 "
        "(switch_input_state_bits[3] bit 0x80) turns on (a rising edge against governor_derate_j1939_protection_active_prev) it "
        "sets governor_derate_j1939_trigger_pending. The previous switch state is saved on every call. "
        "governor_derateTrigger_latch_clear (0x508ee0) turns the pending request into the override latch. It receives no J1939 "
        "message. Called from cm848_periodicTaskSet_auxiliaryControl."),
})

# ---------------------------------------------------------------- 0x00508ee0
ITEMS_B.append({
    "address": "0x00508ee0",
    "old": "governor_derateTrigger_latch_clear",
    "new": "cm848_latchEngineProtectionShutdownOverride",
    "code_quote": "governor_fuel_derate_j1939_latch = 1;",
    "evidence": (
        "When governor_derate_j1939_trigger_pending is non-zero it sets governor_fuel_derate_j1939_latch (e2m 10B1 +18 "
        "EPF_Shutdown_Override_Flag) and clears the pending flag. The latch is read in governor_faultDerate_mainLoop_update "
        "(0x508898), which resets the shutdown timer to its warning time, sets the override lamp flag and clears the latch at the "
        "end of its channel loop. Called by cm848_runFaultDerateScheduler (0x507c44) in task 1, before "
        "governor_fault_derateCalc_channelIter. It latches a request; it clears none."),
    "plate_comment": (
        "Turns a pending engine protection shutdown override request into the override latch: when "
        "governor_derate_j1939_trigger_pending (set by cm848_updateJ1939ReceptionControlFlag at 0x508e78) is non-zero it sets "
        "governor_fuel_derate_j1939_latch (e2m 10B1 +18 EPF_Shutdown_Override_Flag) and clears the pending flag. "
        "governor_faultDerate_mainLoop_update (0x508898) consumes the latch: it sets the shutdown timers back to their warning "
        "time, starts the override lamp flag and clears the latch at the end of its channel loop. Called by "
        "cm848_runFaultDerateScheduler (0x507c44) in task 1, before governor_fault_derateCalc_channelIter."),
})
