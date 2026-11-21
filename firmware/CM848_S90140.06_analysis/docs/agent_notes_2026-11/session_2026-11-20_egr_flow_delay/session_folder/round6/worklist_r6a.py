"""Round 6 stage A (main session): the TSC1 / ETC1 vocabulary, label-only.

Read in full: processEngineTsc1Request (was torqueControlModeHandler, 0x22d60), cm848_j1939ProcessPgn61442Etc1
(0x22870), cm848_runTsc1LostManagement (0x26f80), cm848_runJ1939PowertrainControlTimeouts (was
cm848_processGovernorModeTransition, 0x2715c), cm848_findTsc1SourceConfiguration (was cm848_governorSpeedControl,
0x27cc4) and the TSC1 dispatcher (0x23b38). The counters are named for the e2m 10E7 ("Jcomm") cals they load."""
S = "j1939_powertrain_control_state"
GLOBALS = [
    ("0x003faf42", "j1939_link_fault_clear_request_flag",
     "set by cm848_runJ1939PowertrainControlTimeouts when a J1939 control request starts or changes (the engine TSC1 "
     f"with {S}.tsc1_controlling_data_link = 1, or the engine retarder TSC1); in a pass without a J1939 timeout it "
     "clears the J1939 link fault (fault bit 112) once that is registered, then the flag"),
    ("0x003faf43", "j1708_link_fault_clear_request_flag",
     "the J1708 (J1922) twin of j1939_link_fault_clear_request_flag: set when a control request on another data link "
     f"than J1939 starts or changes ({S}.tsc1_controlling_data_link not 1); clears the J1708 link fault (fault word "
     "96-111 bit 0x4000)"),
    ("0x003faf3b", "engine_retarder_override_control_mode_previous",
     "engine_retarder_override_control_mode at the end of the last cm848_runJ1939PowertrainControlTimeouts pass; a "
     "change restarts the retarder TSC1 time limit"),
    ("0x003faf3d", "engine_retarder_controlling_source_address_previous",
     "the low byte of engine_retarder_controlling_source_address at the end of the last "
     "cm848_runJ1939PowertrainControlTimeouts pass"),
    ("0x003faf39", "high_idle_override_active_flag_previous",
     f"{S}.high_idle_override_active_flag at the end of the last cm848_runJ1939PowertrainControlTimeouts pass (a rise "
     "to 1 counts as a new control request)"),
    ("0x003faf3e", "etc1_progressive_shift_disable_previous",
     f"{S}.etc1_spn607_progressive_shift_disable at the end of the last cm848_runJ1939PowertrainControlTimeouts pass"),
    ("0x003faf40", "etc1_out_of_gear_flag_previous",
     f"{S}.etc1_out_of_gear_flag at the end of the last cm848_runJ1939PowertrainControlTimeouts pass"),
    ("0x003faf36", "tsc1_controlling_data_link_previous",
     f"{S}.tsc1_controlling_data_link at the end of the last cm848_runJ1939PowertrainControlTimeouts pass"),
    ("0x003faf38", "tsc1_controlling_source_address_previous",
     f"{S}.tsc1_controlling_source_address at the end of the last cm848_runJ1939PowertrainControlTimeouts pass; with "
     "the mode and the data link it tells whether the engine TSC1 request changed"),
    ("0x003faf34", "tsc1_override_control_mode_previous",
     f"{S}.tsc1_override_control_mode at the end of the last cm848_runJ1939PowertrainControlTimeouts pass (and at the "
     "start of cm848_runTsc1LostManagement)"),
    ("0x003faf44", "tsc1_torque_limit_ramp_integrator",
     f"cm848_runTsc1LostManagement's torque limit ramp: + tsc1_lost_torque_ramp_rate per pass, {S}."
     "tsc1_torque_limit_fueling = integrator >> 6 (at most 0xffff); reset to the limit << 6"),
    ("0x0005c38c", "j1939_time_limited_node_recovery_time",
     f"the high idle override reloads {S}.high_idle_override_timeout_timer with it (+ 1) while "
     f"{S}.high_idle_override_recovery_flag is set; the ignored request list uses it too. Bank 2 flash, so no _cal"),
    ("0x0005c3b4", "tsc1_source_configuration_table",
     "ten tsc1_source_configuration_t entries (20 bytes): the data link, the source address (0xff = any J1939 "
     "sender) and the request timeouts / time limits per TSC1 mode, for the engine and the engine retarder. "
     "cm848_findTsc1SourceConfiguration walks it; a sender without an entry is rejected. No e2m record. The "
     "instance covers the first entry only"),
    ("0x003fa982", "j1939_powertrain_messages_received",
     "the received ETC1 (PGN 61442, cm848_j1939ProcessPgn61442Etc1), ETC2 (PGN 61445, +0x10) and engine TSC1 (PGN 0, "
     "processEngineTsc1Request) bytes"),
    ("0x0040adf8", "j1939_powertrain_control_state",
     "the J1939 powertrain control state: the engine TSC1 override (mode, limits, request timeouts / time limits), "
     "the engine retarder TSC1 timers, the ETC1 status flags with their timers (out of gear, torque converter "
     "lockup, shift in process, progressive shift disable, the high idle override of SPN 606), the ETC2 selected "
     "gear and the output shaft speed fault hold-off"),
    ("0x0040adf4", "tsc1_accepted_control_byte",
     "processEngineTsc1Request stores the accepted request's TSC1 byte 1 here (sth); no reader in the decompile. "
     "Typed undefined"),
]
FUNCTIONS = [
    ("0x00023b38", "cm848_dispatchTsc1ByDestinationAddress",
     "Routes a received TSC1 (PGN 0) by its destination address: to processEngineTsc1Request when it is the "
     "engine's own source address or global (0xff), and to cm848_processEngineRetarderTsc1Request when it is the "
     "engine retarder's source address or global"),
    ("0x00027cc4", "cm848_findTsc1SourceConfiguration",
     "Looks up the tsc1_source_configuration_table entry for (data link, source address); on J1939 (data link 1) an "
     "entry with source address 0xff matches any sender. Stores the match in j1939_powertrain_control_state."
     "tsc1_matched_source_configuration_ptr and returns 0, or returns 1 when none of the ten entries matches (the "
     "caller then rejects the request)"),
    ("0x0002715c", "cm848_runJ1939PowertrainControlTimeouts",
     "Runs the J1939 powertrain control timers each pass: the high idle override (time limit, timeout, recovery), "
     "the progressive shift disable, out of gear, ETC1 message, ETC2 gear, torque converter lockup and out of gear "
     "data timers; the J1939 output shaft speed fault (with its power-up hold-off); the engine TSC1 request "
     "timeout and time limit (cm848_runTsc1LostManagement, the ignored request list); the engine retarder TSC1 "
     "timeout and time limit; and the J1939 / J1708 link fault counts and clears"),
]
