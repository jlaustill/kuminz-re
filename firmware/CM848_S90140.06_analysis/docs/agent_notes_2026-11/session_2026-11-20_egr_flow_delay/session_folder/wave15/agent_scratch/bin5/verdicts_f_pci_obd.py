from helpers import keep, rename

ENTRIES = [
    # ---- block 8A0D: PCI (J1850) / OBD-II (J1979) calibration constants ------------------------------------------
    keep(
        "0x0005c7b0", "pci_link_error_limit",
        "e2m 8A0D +2 J1850_Bus_Fault_Limit 'Number of J1850 Data-link Bus resets allowed before no more resets'"),
    rename(
        "0x0005c7b8", "pci_vehicle_information_byte_4", "vehicle_engine_type_sales_code",
        "e2m 8A0D +A Chry_J1850_Engine_Type_Sales ('Calibration for J1850 message $ED byte 5 information', 0x2F): "
        "cm848_initPciMessagePayloads copies it into PCI TX[19] header 0xED payload byte 4, which is byte 5 of the message "
        "when the $ED header counts as byte 1 - the same counting that puts vehicle_body_style_code (e2m +B "
        "Chry_J1850_Body_Style, 'byte 6') at payload byte 5; the old name was positional (meaning unknown)",
        "cm848_initPciMessagePayloads: pci_transmit_message_19_byte_4 = pci_vehicle_information_byte_4;",
        "e2m 8A0D +A Chry_J1850_Engine_Type_Sales 'Calibration for J1850 message $ED byte 5 information.' (HEX, 1 byte; 0x2F = "
        "47 in the ROM): read-only; the engine type (sales) code of the Chrysler vehicle information message. "
        "cm848_initPciMessagePayloads (the only reader) copies it once at power-up into PCI TX[19] header 0xED payload byte 4 "
        "(pci_transmit_message_19_byte_4), byte 5 of J1850 message $ED when the header counts as byte 1; payload byte 5 is "
        "vehicle_body_style_code (e2m +B Chry_J1850_Body_Style, 'byte 6'). The DRB database decodes only payload bytes 1 and 5 "
        "of 0xED, so what 0x2F stands for is not decoded"),
    keep(
        "0x0005c7ba", "obd_mode_1_supported_pids",
        "e2m 8A0D +C J1979_Mode01_PID00_Support 'Bit mapped def for PID 00 mode 01 J1979 msg response'"),
    keep(
        "0x0005c7c1", "obd_requirements_standard",
        "e2m 8A0D +13 J1979_Mode01_PID1C_Support 'Bit mapped def for PID 1C mode 01 J1979 msg response'"),
    keep(
        "0x0005c7c2", "obd_mode_2_supported_pids",
        "e2m 8A0D +14 J1979_Mode02_PID00_Support 'Bit mapped def for PID 00 mode 02 J1979 msg response'"),
    keep(
        "0x0005c7c6", "obd_mode_9_supported_info_types",
        "e2m 8A0D +18 J1979_Mode09_PID00_Support 'Bit mapped def for PID 00 mode 09 J1979 msg response'"),
    keep(
        "0x0005c7ca", "obd_mode_9_message_counts",
        "e2m 8A0D +1C J1979_Mode09_PID03_Support 'Bit mapped def for PID 03 mode 09 J1979 msg response'"),
    keep(
        "0x0005c7cc", "cluster_lamp_status_error_set_threshold",
        "e2m 8A0D +1E J1850_OC_No_Message_Set_Limit 'Calib. for set fault debounce if J1850 common message is not in error.'"),
    keep(
        "0x0005c7cd", "cluster_lamp_status_error_clear_threshold",
        "e2m 8A0D +1F J1850_OC_No_Message_Clear_Limit 'Calib. for clear fault debounce if J1850 common message is not in error.'"),
    keep(
        "0x0005c7ce", "pci_in_frame_response_wait_limit",
        "e2m 8A0D +20 J1850_No_IFR_Too_Long_Time 'Maximum time to wait for an IFR before flushing buffers'"),
    keep(
        "0x0005c7d1", "engine_off_time_unchanged_delta",
        "e2m 8A0D +23 Chry_Dat42_Stuck_Threshold 'Minimum changes in Chry_Dat42 for not claiming message stuck'"),
    # ---- block 8A2B: intake air heater settings --------------------------------------------------------------
    rename(
        "0x0005c788", "intake_air_heater_runup_holdoff_preset", "intake_air_heater_crank_time_limit",
        "e2m 8A2B +0 IAH_Crank_Time_Limit ('Disable IAH if cranking longer than this time', 0.1 s; 100 = 10 s): "
        "cm848_countDownIntakeAirHeaterPreheat reloads intake_air_heater_runup_holdoff_countdown with it on every preheat pass, "
        "the crank phase (control state 3 = crank per e2m 8A35 +2 IAH_Phase; the handler also reads +1C Crank_Heat_Time, +1E "
        "Crank_Low_Time, +20 Crank_Off_RPM, +22 Crank_On_RPM) counts it down, and cm848_updateIntakeAirHeaterControl shuts the "
        "heater down (reason 4) when it reaches 0 in state 3: a time limit, not a holdoff; the known 8A2B / 8A37 drift is the "
        "+24 tail, +0 agrees with the code",
        "cm848_countDownIntakeAirHeaterPreheat: intake_air_heater_runup_holdoff_countdown = "
        "intake_air_heater_runup_holdoff_preset;",
        "e2m 8A2B +0 IAH_Crank_Time_Limit 'Disable IAH if cranking longer than this time' (SEC, 0.1 s per count, 0-300; 100 in "
        "the ROM = 10.0 s): read-only; the longest time the intake air heater stays in its crank phase (intake_air_heater_"
        "control_state 3 = crank, e2m 8A35 +2 IAH_Phase). cm848_countDownIntakeAirHeaterPreheat reloads "
        "intake_air_heater_runup_holdoff_countdown with it on every preheat pass, cm848_updateIntakeAirHeaterRunupPhase counts "
        "that countdown down every crank pass, and cm848_updateIntakeAirHeaterControl shuts the heater down (shutdown reason 4, "
        "control state 5) when it reaches 0 while the state is still 3. The 8A2B tail record +24 is the known drift (e2m 8A37 "
        "+0 sits at 0x5c7ac); +0 agrees with the code"),
    # ---- block 8C60: transfer case N/V low range monitor -----------------------------------------------------------
    keep(
        "0x0040b540", "engine_to_vehicle_speed_ratio_deviation_filtered",
        "e2m 8C60 +0 Tcase_NV_Inst_Percent_Change 'filtered (ENGRPM/Vehicle_Speed), N/V, percent change'"),
]
