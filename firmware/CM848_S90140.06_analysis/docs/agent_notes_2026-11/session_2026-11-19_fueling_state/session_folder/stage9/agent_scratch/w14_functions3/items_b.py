"""Wave 14, functions3: items 12-23 (name, deciding quote, evidence, plate). Items 19-21 get the owner's review note
appended by the build script, taken from the bin's user_review_note field."""

ITEMS_B = [
    # 12  0x0002bf44
    dict(
        new="cm848_updateNotSafeToProgramFlag",
        quote="not_safe_to_program_flag = engine_state != ENGINE_STATE_STOPPED;",
        evidence=(
            "The whole body is not_safe_to_program_flag = engine_state != ENGINE_STATE_STOPPED; (e2m 000D +0 SAFE2PRG / "
            "Safe_To_Program: 0 safe, 1 not safe); it reads and writes no fault and no key-off state. Caller: "
            "cm848_periodicTaskSet_auxiliaryControl, every pass. Readers: cm848_forceActivateDiagnosticSession "
            "(DIAG_NACK_PROTECTED), cm848_commitEepromMirrorToEeprom, j1939_writeDiagMemory, "
            "cm848_processPciDiagnosticRequest and cm848_lookupParameterIdAddress. Dump (byte): 0 with engine_state 1 "
            "(STOPPED)."
        ),
        plate=(
            "Updates not_safe_to_program_flag (e2m 000D +0 SAFE2PRG / Safe_To_Program: 'Indicator to tools (0 = safe for "
            "program, 1 = not safe)'): 1 while engine_state is not ENGINE_STATE_STOPPED, else 0. Runs every pass of "
            "cm848_periodicTaskSet_auxiliaryControl. Input: engine_state. Output: not_safe_to_program_flag. While it is 1 "
            "the force-activate diagnostic service answers DIAG_NACK_PROTECTED, cm848_commitEepromMirrorToEeprom refuses, "
            "the diagnostic EEPROM writes (j1939_writeDiagMemory, the PCI write service) answer 7 unless "
            "diagnostic_session_state is INACTIVE, and cm848_lookupParameterIdAddress maps EEPROM parameter addresses to "
            "the RAM mirror. It handles no fault and no key-off event."
        ),
    ),
    # 13  0x0050ddb4
    dict(
        new="cm848_controlEndOfLineTestMalfunctionIndicatorLampOverride",
        quote="end_of_line_test_malfunction_indicator_lamp_override_state = diag_suppress_saved_flag;",
        evidence=(
            "param_1 is a step code, not the e2m EOL_Mil_State coding (its 3 turns the lamp on): 0 clears "
            "diag_suppress_saved_flag and the override; 1 saves the override into diag_suppress_saved_flag, sets "
            "end_of_line_test_malfunction_indicator_lamp_flash_request_flag = 1 and clears the override; 2 restores it "
            "(the quote) and clears the flash request; 3 sets the saved flag and the override to 1 (lamp on; "
            "cm848_updateMilOnRequest forces the MIL request on while the override is 1). Called by "
            "cm848_runEndOfLineTestSequence, cm848_runEndOfLineMisfireTestStep, the cold start / deviation / battery "
            "voltage / bit check steps and cm848_initialization_group21_state_cont (step 3 when the failed-test power-down "
            "flag is 1). e2m 1226 +C EOL_Mil_State, +D EOL_Mil_Flash; 'MalfunctionIndicatorLamp' is spelled out because "
            "mil is not on the allow-list."
        ),
        plate=(
            "Controls the malfunction indicator lamp (MIL) override of the Chrysler in-plant end-of-line test. param_1 is "
            "a step code, not the e2m EOL_Mil_State coding: 0 = clear the saved override (diag_suppress_saved_flag) and "
            "the override; 1 = save the current override into diag_suppress_saved_flag, request the lamp flash "
            "(end_of_line_test_malfunction_indicator_lamp_flash_request_flag = 1) and clear the override while the step "
            "runs; 2 = restore the saved override and clear the flash request; 3 = lamp on: save 1, override = 1, no "
            "flash request. Outputs: end_of_line_test_malfunction_indicator_lamp_override_state (e2m 1226 +C EOL_Mil_State; "
            "cm848_updateMilOnRequest forces the MIL request on while it is 1) and the flash request (e2m 1226 +D "
            "EOL_Mil_Flash, sent in bit 5 of PCI TX[3] byte 1 by cm848_buildPciTransmitMessage3MilAndDtcDisplay while the "
            "field mode register is 5100). Called by the end-of-line test sequencer and its steps "
            "(cm848_runEndOfLineTestSequence, cm848_runEndOfLineMisfireTestStep and the cold start, deviation, battery "
            "voltage and bit check steps) and, with step 3, by cm848_initialization_group21_state_cont at start-up when "
            "the failed-test power-down flag (e2m 1981 +1 EOL_MIL_Powerdown_State) is 1."
        ),
    ),
    # 14  0x005341a8
    dict(
        new="cm848_monitorWarmUpCycle",
        quote="if (warm_up_cycle_condition_flags == 3) {",
        evidence=(
            "Direction checks: mask 1 is set when 0x9ff < coolant_temp - warm_up_cycle_start_coolant_temperature (a RISE "
            "of about 40 degrees F, 1/64 degree per count); mask 2 when warm_up_cycle_minimum_coolant_temperature < "
            "coolant_temp (coolant ABOVE 8960 = 140 degrees F, e2m 11F9 +2 Warm_Up_Temp_Max). At 3 it adds 1 to "
            "fault_auto_clear_warm_up_cycle_count_cal (< 0x27 then +1, else 0) and calls "
            "fault_ring_buffer_auto_clear_emission; there is no overheat compare. e2m 1226 +9 Warm_Up_Cycle_Flag. Caller: "
            "cm848_mainLoopServiceMonitor. Dump (byte): flags 0."
        ),
        plate=(
            "OBD warm-up cycle monitor (e2m 1226 +9 Warm_Up_Cycle_Flag, '[DGWUCYFL] Indicates whether warm up cycle has "
            "occurred'; it makes no coolant overheat check). Sets bit 0 of warm_up_cycle_condition_flags when coolant_temp "
            "has risen more than 0x9ff (about 40 degrees F; 1/64 degree per count) above "
            "warm_up_cycle_start_coolant_temperature (the sample taken after the startup delay) and bit 1 when coolant_temp "
            "is above warm_up_cycle_minimum_coolant_temperature (e2m 11F9 +2 Warm_Up_Temp_Max, 8960 = 140 degrees F). With "
            "both set (3) a warm-up cycle has occurred: it stops evaluating, adds 1 to "
            "fault_auto_clear_warm_up_cycle_count_cal (counts 0..39, then 0) and calls fault_ring_buffer_auto_clear_emission, "
            "which clears the fault ring. Called by cm848_mainLoopServiceMonitor. 0 in the dump (engine off)."
        ),
    ),
    # 15  0x00533b18
    dict(
        new="cm848_incrementEngineStartCountsSinceFaultLogged",
        quote="if (engine_start_count_since_fault_logged_cal[uVar1] < 0xff) {",
        evidence=(
            "Loops i = 0..7 and adds 1 to each engine_start_count_since_fault_logged_cal[i] (word[8], e2m 138F +2 "
            "Number_Of_Starts_1..8 'Number of engine starts since most recent fault logged') while it is below 255. Its "
            "only caller cm848_auxiliaryControlTask calls it once, on the first pass after engine_state is RUNNING / "
            "ENGINE_BRAKE / OVERSPEED, behind the once-flag DAT_003fd22b (its only access in the decompile sets it to 1). "
            "Dump (word): all eight 255."
        ),
        plate=(
            "Increments the engine start counts since a fault was logged: each of the eight words of "
            "engine_start_count_since_fault_logged_cal (EEPROM 0x194c, e2m 138F +2 Number_Of_Starts_1..8: starts since the "
            "1st..8th most recent fault was logged; index 0 = newest, parallel to protection_event_spn_history) gets +1 "
            "while it is below 255. Called once per engine start by cm848_auxiliaryControlTask, on the first pass after "
            "engine_state is RUNNING, ENGINE_BRAKE or OVERSPEED, behind the once-flag DAT_003fd22b and "
            "fault_aging_triggered_flag = 0. 255 in all eight words in the dump."
        ),
    ),
    # 16  0x00533b5c
    dict(
        new="cm848_removeEngineStartCountSinceFaultLogged",
        quote="engine_start_count_since_fault_logged_cal[param_1 + 1];",
        evidence=(
            "for (i = param_1; i < 7; i++) engine_start_count_since_fault_logged_cal[i] = [i + 1]: every older entry moves "
            "one slot toward index 0 and closes the gap at param_1 (index 7 keeps its value). Its only caller "
            "fault_clearFromRing finds the cleared fault's code in protection_event_spn_history, calls this with that index "
            "and then closes the code list the same way ([i] = [i + 1], last = 0). The opposite direction of 0x533b94 "
            "([i] = [i - 1]); 'shift in' named neither, so the name says remove."
        ),
        plate=(
            "Removes one entry from the engine start counts since a fault was logged "
            "(engine_start_count_since_fault_logged_cal, word[8], e2m 138F +2 Number_Of_Starts_1..8): for i = param_1 .. 6 it "
            "copies count[i] = count[i + 1], so every older entry moves one slot toward index 0 and closes the gap "
            "(index 7 keeps its value). Called by fault_clearFromRing with the index of a cleared fault's code in "
            "protection_event_spn_history, which fault_clearFromRing then closes the same way. Opposite direction of "
            "0x533b94, which opens index 0 for a new fault."
        ),
    ),
    # 17  0x00533b94
    dict(
        new="cm848_shiftEngineStartCountsSinceFaultLogged",
        quote="engine_start_count_since_fault_logged_cal[uVar1] = *(word *)(uVar1 * 2 + 0x3fedcc);",
        evidence=(
            "for (i = 7; i != 0; i--) count[i] = *(word *)(i * 2 + 0x3fedcc), and 0x3fedcc + 2 i is count[i - 1] (the array "
            "starts at 0x3fedce): every entry ages one slot toward index 7 and the oldest (index 7) is dropped, which "
            "opens index 0. Its only caller cm848_latchNewlyActiveFault runs it on the first activation of a fault, right "
            "after shifting protection_event_spn_history the same way and writing the new code at index 0, then sets "
            "count[0] = 0. The opposite direction of 0x533b5c ([i] = [i + 1])."
        ),
        plate=(
            "Opens index 0 of the engine start counts since a fault was logged (engine_start_count_since_fault_logged_cal, "
            "word[8], e2m 138F +2 Number_Of_Starts_1..8): for i = 7 down to 1 it copies count[i] = count[i - 1] (read at "
            "0x3fedcc + 2 i), so every entry ages one slot toward index 7 and the oldest (index 7) is dropped. Called by "
            "cm848_latchNewlyActiveFault when a fault latches for the first time, right after it has shifted "
            "protection_event_spn_history the same way and written the new code at index 0; the caller then sets "
            "count[0] = 0. Opposite direction of 0x533b5c, which closes a gap."
        ),
    ),
    # 18  0x0050638c
    dict(
        new="cm848_updateDutyCycleMonitorLoadHistogram",
        quote="percent_time_at_load_cal[uVar9] =",
        evidence=(
            "The sums feed the DRB '% OF TIME @ x LOAD' words: percent_time_at_load_cal[n] = (sum of the 8 fine counters of "
            "load band n) x 0x6400 / load_histogram_total_sample_count_cal (25600 = 100 percent); the 82 dwords from "
            "0x3fde4e sum to the total in the dump (3203448 = dword at 0x3fde48). e2m: DC_Mon_Enable 106B +26 bit 0x0008 "
            "(the lhz mask 8 on algorithm_enable_flags_18_cal), DC_Mon_Load_Factor 111F +0, DC_Mon_Operating_Region 111F +2 "
            "(DAT_0040a64a, 81 in the dump), DC_Mon_Map_Reset 111F +3, DC_Mon_Low / High_Cutoff_RPM 111C, axes 111D / 111E "
            "(ROM 0x5c2c0 / 0x5c2d4), DC_Mon_Long_Map_Total 1122 +4. The sibling rows split between duty_cycle_monitor_* "
            "(the e2m DC_Mon records) and load_histogram_* (the EEPROM data), so the name carries both: it updates the "
            "monitor and fills the histogram. Cutoffs: current_rpm < duty_cycle_monitor_low_cutoff_engine_speed -> the maximum "
            "fueling is looked up at the low cutoff, current_rpm not below DAT_0005c2bc (the high cutoff) -> at the high "
            "cutoff. e2m 1125 DC_Mon_Long_Term_Map resolves to 0x3fde4c, 2 bytes before the "
            "counters the code uses (drift). Caller: cm848_periodicTaskSet_outputs2."
        ),
        plate=(
            "Duty cycle monitor load histogram (e2m group DC_Mon; enable 106B +26 DC_Mon_Enable = bit 3 of "
            "algorithm_enable_flags_18_cal), one sample per call of cm848_periodicTaskSet_outputs2 (1 count = 0.1 s in the "
            "e2m). While the monitor is enabled and the engine is not stopped: when "
            "load_histogram_total_sample_count_cal is 0 it first stores engine_hour_meter in "
            "load_histogram_start_engine_hours_cal; fuel_demand_histogram_load_ratio = (final_fueling - "
            "fuel_demand_base_offset) x 10000 / (the maximum fueling at the engine speed, from "
            "cm848_lookupChiMaximumFuelAtSpeed with the speed limited by the e2m 111C DC_Mon_Low / High_Cutoff_RPM, minus "
            "fuel_demand_base_offset), clamped at 13000 and copied to duty_cycle_monitor_load_factor (e2m 111F +0 "
            "DC_Mon_Load_Factor, 0.01 percent; 0 when the ratio is negative); the engine speed is binned against the 8 "
            "breakpoints of e2m 111D DC_Mon_RPM_Axis (ROM 0x5c2c0) "
            "and the load against the 10 of 111E DC_Mon_Load_Axis (0x5c2d4) into one of 80 fine counters, a negative load "
            "into counter 81 or 82, and the counter number is stored in DAT_0040a64a (e2m 111F +2 DC_Mon_Operating_Region); "
            "that fine counter and load_histogram_total_sample_count_cal (e2m 1122 +4 DC_Mon_Long_Map_Total, up to "
            "3,600,000,000 = 100,000 h) get +1; percent_time_at_load_cal[0..9] (25600 = 100 percent, the DRB '% OF TIME @ x "
            "LOAD' words) are recomputed as each load band's 8 counters x 25600 / total, plus the two out-of-range "
            "percentages in 0x3fdfac / 0x3fdfae. The counters are the 82 dwords from 0x3fde4e (their sum equals the total in "
            "the dump, 3203448; e2m 1125 DC_Mon_Long_Term_Map resolves 2 bytes earlier, to 0x3fde4c). When the monitor is off "
            "or the engine is stopped it only acts on duty_cycle_monitor_map_reset_pending_flag (e2m 111F +3 DC_Mon_Map_Reset): "
            "it zeroes the total, the counters and the percent words and clears the flag."
        ),
    ),
    # 19  0x00021624  (owner note appended by the build script)
    dict(
        new="cm848_exitDevelopmentMode",
        quote="if (j1939_standby_flag == STANDING_BY) {",
        evidence=(
            "Accepts only while j1939_standby_flag == STANDING_BY (1) (else DIAG_NACK_NOT_READY); then "
            "j1939_standby_flag = SESSION_ACTIVE (0), diagnostic_session_state = ACTIVE (1) and cal_write_mode = 0xee, "
            "DIAG_ACK. The rows are e2m 1328 +0 Development_Mode, 10C7 +0 RAM_Refresh_Enable and 0010 +0 RUN_LOC; 0 / 1 / "
            "0xee is also the start-up (cal_write_mode = 0xee in the boot list), power-down "
            "(cm848_runPowerDownSequence) and dump state, so this LEAVES development mode and turns the RAM refresh on. "
            "Registered as J1939 diagnostic service 7 (cm848_registerJ1939DiagnosticHandlers). The owner's review note is "
            "kept at the end of the plate; the main session shows the rename to the owner."
        ),
        plate=(
            "Leaves development mode and turns the RAM refresh back on (J1939 diagnostic service 7): accepted only while "
            "j1939_standby_flag is STANDING_BY (e2m 1328 +0 Development_Mode = 1), otherwise it returns "
            "DIAG_NACK_NOT_READY. Then it sets j1939_standby_flag = SESSION_ACTIVE (development mode 0), "
            "diagnostic_session_state = ACTIVE (e2m 10C7 +0 RAM_Refresh_Enable = 1) and cal_write_mode = 0xee (e2m 0010 +0 "
            "RUN_LOC; 0xee is also the start-up value) and returns DIAG_ACK. There is no engine state check; the force "
            "variant (service 22, 0x21694) requires the engine to be stopped but not development mode."
        ),
    ),
    # 20  0x00021668  (owner note appended by the build script)
    dict(
        new="cm848_enterDevelopmentMode",
        quote="j1939_standby_flag = STANDING_BY;",
        evidence=(
            "Stores diagnostic_session_state = INACTIVE (RAM_Refresh_Enable 0), j1939_standby_flag = STANDING_BY "
            "(Development_Mode 1) and cal_write_mode = 0xea (RUN_LOC), returns DIAG_ACK: the opposite of the "
            "boot / power-down / dump state, so it ENTERS development mode. Called as diagnostic service 10 and by "
            "cm848_processPciDiagnosticRequest right after pci_security_unlocked_flag = 1 (the security key was accepted). "
            "With the refresh disabled cm848_onEepromBlockRead stops reloading the mirror, j1939_writeDiagMemory writes "
            "EEPROM addresses only to the RAM mirror (its queue branch needs diagnostic_session_state == ACTIVE) and "
            "cm848_lookupApplicationMemoryRegionType gives the register ranges type 3 instead of 10 (table 0x53a33a, "
            "STANDING_BY column). The owner's review note is kept at the end of the plate; the main session shows the "
            "rename to the owner."
        ),
        plate=(
            "Enters development mode (J1939 diagnostic service 10, also called by cm848_processPciDiagnosticRequest right "
            "after the PCI security key has been accepted): disables the RAM refresh (diagnostic_session_state = INACTIVE, "
            "e2m 10C7 +0 RAM_Refresh_Enable = 0), sets j1939_standby_flag = STANDING_BY (e2m 1328 +0 Development_Mode = 1) "
            "and cal_write_mode = 0xea (e2m 0010 +0 RUN_LOC), and returns DIAG_ACK. With the refresh off, RAM calibration "
            "edits are not overwritten (the refresh pass and the periodic EEPROM mirror reload, cm848_onEepromBlockRead, stop), "
            "diagnostic writes to EEPROM addresses and EEPROM parameter ID writes go to the RAM mirror only "
            "(cm848_lookupParameterIdAddress, j1939_writeDiagMemory), and the two register address ranges of the "
            "diagnostic memory services open (cm848_lookupApplicationMemoryRegionType). The way back is service 7 "
            "(0x21624) or, with the engine stopped, service 22 (0x21694)."
        ),
    ),
    # 21  0x00021694  (owner note appended by the build script)
    dict(
        new="cm848_forceExitDevelopmentMode",
        quote="if (not_safe_to_program_flag != 1) {",
        evidence=(
            "Refuses with DIAG_NACK_PROTECTED while not_safe_to_program_flag == 1 (engine_state != STOPPED, 0x2bf44); "
            "otherwise it always stores diagnostic_session_state = ACTIVE (refresh on) and, only if cal_write_mode == "
            "0xea (development), cal_write_mode = 0xee and j1939_standby_flag = SESSION_ACTIVE, so it LEAVES development "
            "mode without requiring it (service 7 requires it); the only unconditional store is the refresh enable, so "
            "cm848_forceEnableRamRefresh is the alternative name if the owner prefers that half. Registered as diagnostic "
            "service 22 (0x16). The owner's "
            "note is about != 1 and == 0xea / 0xee not rendering as enums: cal_write_mode is e2m 0010 +0 RUN_LOC (0xee "
            "normal / 0xea development here) and not_safe_to_program_flag is e2m 000D SAFE2PRG, both enum candidates. The "
            "note is kept at the end of the plate; the main session shows the rename to the owner."
        ),
        plate=(
            "Forces an exit from development mode when it is safe to program (J1939 diagnostic service 22): with "
            "not_safe_to_program_flag clear (engine stopped) it always turns the RAM refresh on (diagnostic_session_state = "
            "ACTIVE, e2m 10C7 +0 RAM_Refresh_Enable = 1) and, only if cal_write_mode is 0xea (development mode), also "
            "restores cal_write_mode = 0xee and j1939_standby_flag = SESSION_ACTIVE (e2m 1328 +0 Development_Mode = 0); it "
            "returns DIAG_ACK. With the engine not stopped it returns DIAG_NACK_PROTECTED and changes nothing. Unlike "
            "service 7 (0x21624) it does not require development mode to be on."
        ),
    ),
    # 22  0x005389c4
    dict(
        new="cm848_initializeRamRefresh",
        quote="sensor_cal_ram_write_ptr = (undefined *)&sensor_channel_cal_block_start;",
        evidence=(
            "Writes the one 12-byte block descriptor at 0x3fd2c4 (RAM start sensor_channel_cal_block_start, RAM end "
            "sensor_channel_ram_start, source ROM 0x64aea), points the cursor 0x3fd2d0 at it, restarts "
            "sensor_cal_ram_write_ptr / sensor_cal_rom_read_ptr, clears sensor_cal_write_dirty_flag and sets "
            "diagnostic_session_state = ACTIVE (e2m 10C7 +0 RAM_Refresh_Enable), sensor_validation_result = 1 (10C7 +2 "
            "Powerdown_Refresh_Enable) and sensor_cal_session_state_prev = 1. Its only caller, the refresh pass "
            "cm848_initProtectionModule, calls it when sensor_cal_session_state_prev == 0 and diagnostic_session_state != "
            "INACTIVE, i.e. on the first pass and when the refresh is enabled again."
        ),
        plate=(
            "RAM refresh initializer: fills the one block descriptor of the refresh table (12-byte entries at 0x3fd2c4: RAM "
            "start sensor_channel_cal_block_start 0x3feed0, RAM end sensor_channel_ram_start 0x40a046, source ROM 0x64aea), "
            "points the current-descriptor cursor at 0x3fd2d0 at it, restarts the compare cursors "
            "(sensor_cal_ram_write_ptr = the RAM start, sensor_cal_rom_read_ptr = the ROM source), clears "
            "sensor_cal_write_dirty_flag, sets diagnostic_session_state = ACTIVE (e2m 10C7 +0 RAM_Refresh_Enable = 1), "
            "sensor_validation_result = 1 (e2m 10C7 +2 Powerdown_Refresh_Enable) and sensor_cal_session_state_prev = 1. "
            "Called only by cm848_initProtectionModule (the refresh pass) on its first pass and whenever the refresh has just "
            "been enabled again (sensor_cal_session_state_prev = 0 while diagnostic_session_state is not INACTIVE)."
        ),
    ),
    # 23  0x00538a84
    dict(
        new="cm848_refreshRamCalibration",
        quote="*(short *)sensor_cal_ram_write_ptr = *(short *)sensor_cal_rom_read_ptr;",
        evidence=(
            "Called in a loop, do { cm848_initProtectionModule(...); } while (power_down_start_flag == 0), by "
            "cm848_applicationMain and cm848_restartApplicationWithoutReset, so each call is one background pass. While "
            "diagnostic_session_state != INACTIVE (e2m 10C7 +0 RAM_Refresh_Enable) it compares up to 100 bytes (50 words) "
            "per call between sensor_cal_ram_write_ptr and sensor_cal_rom_read_ptr and rewrites each differing RAM word "
            "(the quote), setting sensor_cal_write_dirty_flag. At the end of a cycle it sets mask 1 of "
            "fault_detected_bits_0_to_15 if anything was rewritten, else clears it (e2m 1036 +0 RAM_Image_Word_Error 'RAM "
            "refresh generated error'; fault 0 -> ROM slot table 0x5985a -> obd_dtc_code_table = P0606). The block is "
            "0x3feed0-0x40a046 against ROM 0x64aea (a flash parameter block; the EEPROM mirror ends at 0x3feec1). The "
            "e2m text 'COMPARE RAM TO EEPROM' fits the other half of the refresh: cm848_periodicTaskSet_protection2 "
            "-> cm848_startEepromBlockRead re-reads the EEPROM 30 words at a time and cm848_onEepromBlockRead copies "
            "them into the mirror only while diagnostic_session_state != INACTIVE."
        ),
        plate=(
            "RAM refresh pass - the body of the background loop of cm848_applicationMain and "
            "cm848_restartApplicationWithoutReset (do { ... } while (power_down_start_flag == 0)). While "
            "diagnostic_session_state is not INACTIVE (e2m 10C7 +0 RAM_Refresh_Enable = 1) each call compares up to 100 bytes "
            "(50 words) of the current block of the refresh table with its source and rewrites every RAM word that differs "
            "(sensor_cal_write_dirty_flag = 1). The one block is the sensor channel calibration block "
            "(sensor_channel_cal_block_start .. sensor_channel_ram_start, 0x3feed0-0x40a046) against ROM 0x64aea (the EEPROM "
            "mirror ends before it, at 0x3feec1); the EEPROM side of the refresh is the periodic mirror reload "
            "(cm848_periodicTaskSet_protection2 -> cm848_startEepromBlockRead, 30 words per read, copied in by "
            "cm848_onEepromBlockRead only while diagnostic_session_state is not INACTIVE). When a cycle "
            "through all blocks ends it sets fault bit 0 (fault_detected_bits_0_to_15 |= 1, e2m 1036 +0 RAM_Image_Word_Error "
            "'RAM refresh generated error'; fault 0 -> ROM slot table 0x5985a -> obd_dtc_code_table = P0606) if any word was "
            "rewritten during the cycle, else clears it; it counts cycles in sensor_cal_ring_cycle_count. It calls "
            "uds_session_state_init when the refresh has just been enabled (sensor_cal_session_state_prev = 0) and clears "
            "fault bit 0 on that edge. It does nothing while the refresh is disabled (development mode)."
        ),
    ),
]
