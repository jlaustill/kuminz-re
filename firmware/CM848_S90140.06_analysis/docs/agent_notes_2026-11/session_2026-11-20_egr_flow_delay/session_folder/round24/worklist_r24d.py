"""Round 24 stage D (label-only): the struct instances still named with their Ghidra labels - the J1587 fault counts
(EEPROM), the boot SCI session, the reflash transfer state, the boot J1939 transport session, the QSPI receive RAM,
the boot initialization flags - and the active fault list's code array."""
GLOBALS = [
    ("0x003fe11a", "j1587_fault_count_data_cal",
     "The fault counts the J1587 link and the fault handler keep (j1587_fault_count_data_t, EEPROM mirror): the "
     "active and previously active fault counts (they move with active_dtc_list_cal.count / "
     "previously_active_dtc_list_cal.count) and the same two counts for the faults whose definition flag 0x2000 is "
     "clear"),
    ("0x003fe09a", "active_dtc_cummins_fault_codes_cal",
     "Cummins fault codes of the active DTC list (word[32], EEPROM mirror): [0] counts with active_dtc_list_cal.count "
     "and [n] holds the fault_definition_table cummins_fault_code of active_dtc_list_cal.slots[n - 1] (the list "
     "updates in cm848_processFaultScanGroup and its removers); the twin of "
     "previously_active_dtc_cummins_fault_codes_cal. No pending fault counter"),
    ("0x003fecbe", "boot_sci_session_state",
     "The boot ROM's SCI diagnostic session (boot_sci_session_state_t): session flags, the response write index and "
     "the cursor into the serial response buffer. Every user is boot ROM (below 0x3c30) or boot kernel code, so this "
     "RAM is their working state, not an EEPROM-backed value (no _cal)"),
    ("0x003fec82", "reflash_transfer_state",
     "The reflash download state of the boot ROM and the boot reflash kernel (reflash_transfer_state_t): the transfer "
     "buffer's byte count and write enable, the largest write, the pending write's transport (1 CAN / 2 serial), the "
     "finish request, the flash program step (cm848_runFlashProgramStateMachine) and the Bank 2 erase state. Boot "
     "and kernel working state, no _cal"),
    ("0x00302905", "boot_j1939_transport_transmit_session",
     "The boot reflash kernel's outbound J1939 transport session (j1939_transport_transmit_session_t): "
     "mpc555_sendJ1939TransportRequestToSend opens it (TP.CM request-to-send), "
     "mpc555_handleJ1939TransportClearToSend records each granted window and mpc555_sendJ1939TransportDataPackets "
     "sends up to 15 TP.DT frames per call"),
    ("0x00305140", "qsmcm_recram",
     "QSMCM RECRAM, the QSPI receive RAM (qsmcm_recram_t): the replies of the boot EEPROM driver "
     "(mpc555_eepromReadWords / WriteWords) and of the supervisor chip watchdog (cm848_initSupervisorWatchdog / "
     "cm848_serviceSupervisorWatchdog / cm848_forceSupervisorWatchdogReset)"),
    ("0x00302736", "system_initialization_flags",
     "Set by the boot service loop mpc555_systemInitialization: initialization_sentinel = 0xBBBB and "
     "initialization_counter = 0 (no reader in the .cpp)"),
]
FUNCTIONS = []
# Inside the EEPROM mirror's range but used only by the boot ROM (below 0x3c30) and the boot reflash kernel, which run
# before / instead of the application: their RAM is the boot code's working state, like the neighbours
# boot_sci_security_state / diag_request_pending_flag / serial_response_crc_expected (0x3fecc4-0x3fecc7, no _cal). No
# e2m record names these bytes for the application, so they get the boot names and no _cal.
NOT_CAL = {"0x003fecbe", "0x003fec82"}
