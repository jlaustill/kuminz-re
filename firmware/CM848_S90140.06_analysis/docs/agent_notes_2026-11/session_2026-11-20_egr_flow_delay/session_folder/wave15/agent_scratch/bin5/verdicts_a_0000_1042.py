from helpers import rename

ENTRIES = [
    rename(
        "0x003fd4b8", "sensor_channel_index_working", "ecm_hardware_type_identifier_cal",
        "e2m 0000 +0 ECM_Identifier (HEX, 2 bytes): cm848_initPgn65242SoftwareIdHandler copies its two bytes into the "
        "PGN 65242 software identification message as field 5 of 6; the dump holds 0x4336 = ASCII 'C6'; the old name "
        "(a sensor channel index) fits no use; EEPROM 0x36 is in the mirror, so _cal; the three Software_CAL_E2 / _RAM / _ROM "
        "records share the block 0000 table entry but are size 0 text markers (type A), so ECM_Identifier is the real "
        "storage",
        "cm848_initPgn65242SoftwareIdHandler: local_10 = (undefined1)(sensor_channel_index_working >> 8);",
        "EEPROM 0x36 (mirror): e2m 0000 +0 ECM_Identifier 'Identifier of the ECM hardware type.' (HEX, 2 bytes; 0x4336 = "
        "ASCII 'C6' in the dump): read-only; cm848_initPgn65242SoftwareIdHandler copies its two bytes (high byte first) into "
        "the PGN 65242 software identification message, field 5 of 6, between two '*' delimiters. Field 6 is "
        "j1939_pgn_priority_cal = e2m 1292 Application_Identifier."),
    rename(
        "0x0040a02c", "fault_match_debounce_threshold_std", "auxiliary_driver_fault_match_debounce_threshold",
        "e2m 1042 +0 Aux_Driver_Error_Count (CNTS): diag_faultMatch_outputCheck_update counts the scans where the output "
        "feedback disagrees with the request against it before toggling the driver, for every checked output except 19 / 20 "
        "(those use Cruise_Driver_Error_Count = cruise_driver_fault_match_debounce_threshold); 'std' is an invented "
        "abbreviation, the record says auxiliary driver",
        "diag_faultMatch_outputCheck_update: if (*param_5 < fault_match_debounce_threshold_std) {",
        "e2m 1042 +0 Aux_Driver_Error_Count '[DAAUCTMX] NUMBER OF AUX. DRIVER ERRORS THAT MUST BE SEEN BEFORE THE DRIVER IS "
        "TOGGLED' (CNTS; 4 in the dump): read-only; the fault-match debounce threshold of the auxiliary output drivers in "
        "diag_faultMatch_outputCheck_update. An output requested on whose feedback line reads off must disagree this many "
        "scans in a row before the driver is toggled (the request is cleared and the toggle counted against "
        "auxiliary_driver_toggle_count_limit); an output requested off whose line reads on needs it before the fault bit is "
        "set. Every checked logical output except 19 and 20 (the cruise servo vent / vacuum drivers), which use "
        "cruise_driver_fault_match_debounce_threshold. ROM fault-match debounce threshold (standard channels)"),
    rename(
        "0x0040a02e", "fault_active_recovery_threshold_std", "auxiliary_driver_fault_active_recovery_threshold",
        "e2m 1042 +2 Auxiliary_Driver_Recover_Count (CNTS): diag_faultMatch_outputCheck_update counts good feedback samples "
        "of an active output fault against it and then clears the detected and active bits, for every checked output except "
        "19 / 20 (those use cruise_driver_fault_active_recovery_threshold); 'std' is an invented abbreviation",
        "diag_faultMatch_outputCheck_update: if (fault_active_recovery_threshold_std <= *param_8) {",
        "e2m 1042 +2 Auxiliary_Driver_Recover_Count '[DRDRRVCU] Enhanced Diag: number good samples before recovery of aux "
        "driver error' (CNTS; 4 in the dump): read-only; the recovery threshold of the auxiliary output drivers in "
        "diag_faultMatch_outputCheck_update. While an output fault is active and the feedback line agrees with the request "
        "again, a counter runs; at this many good samples the fault-detected and fault-active bits are cleared. Every "
        "checked logical output except 19 and 20, which use cruise_driver_fault_active_recovery_threshold. ROM "
        "fault-active recovery threshold (standard channels)"),
    rename(
        "0x0040a036", "fault_active_recovery_threshold_ch19_20", "cruise_driver_fault_active_recovery_threshold",
        "e2m 1042 +A Cruise_Driver_Recover_Count (CNTS): diag_faultMatch_outputCheck_update uses it as the recovery "
        "threshold only when param_1 is 19 or 20 (the cruise servo vent / vacuum outputs); 'ch19_20' is an abbreviation of "
        "the same fact; sibling of cruise_driver_fault_match_debounce_threshold",
        "diag_faultMatch_outputCheck_update: if (fault_active_recovery_threshold_ch19_20 <= *param_8) {",
        "e2m 1042 +A Cruise_Driver_Recover_Count 'Enhanced Diag: number good samples before recovery of aux driver error' "
        "(CNTS; 1 in the dump): read-only; the recovery threshold of the cruise servo drivers (logical outputs 19 vent and "
        "20 vacuum) in diag_faultMatch_outputCheck_update: good feedback samples of an active output fault before the "
        "fault-detected and fault-active bits are cleared. The other outputs use "
        "auxiliary_driver_fault_active_recovery_threshold. ROM fault-active recovery threshold (channels 19 / 20)"),
]
