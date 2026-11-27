"""Round 7 stage A (main session, label-only): the J1939 monitor's working words (e2m 1100), the retarder half of its
previous-value copies, the engine retarder TSC1 handler's received bytes, and the two TSC1-path functions that reset
or end the engine retarder request. Read in full: cm848_trackJ1939ControlSessions, cm848_startJ1939ControlSession,
cm848_storeJ1939ControlSessionInHistoryTable, cm848_processEngineRetarderTsc1Request, cm848_resetGovernorState,
governor_resetModeStateOnCondition."""
GLOBALS = [
    ("0x003fbd6e", "j1939_monitor_retarder_override_control_mode_previous",
     "cm848_trackJ1939ControlSessions' copy of engine_retarder_override_control_mode from its last pass: a change "
     "starts or ends a J1939 retarder control session record"),
    ("0x003fbd73", "j1939_monitor_retarder_controlling_source_address_previous",
     "cm848_trackJ1939ControlSessions' copy of the low byte of engine_retarder_controlling_source_address from its last "
     "pass: a new sender closes the retarder session and opens another"),
    ("0x003feb86", "j1939_engine_control_source_cal",
     "the control device of the open engine control session (0 none / 1 transmission / 2 ABS / 3 ASR / 4 unknown): "
     "cm848_startJ1939ControlSession copies engine_control_device_indicator"),
    ("0x003feb88", "j1939_retarder_control_source_cal",
     "the control device of the open retarder control session (0 none / 1 transmission / 2 ABS / 3 ASR / 4 unknown): "
     "cm848_startJ1939ControlSession copies engine_retarder_control_device_indicator"),
    ("0x003feb8a", "j1939_control_session_history_next_entry_cal",
     "the history entry cm848_storeJ1939ControlSessionInHistoryTable writes next (0-4, wraps)"),
    ("0x003faa68", "engine_retarder_received_tsc1_control_byte",
     "TSC1 byte 1 as cm848_processEngineRetarderTsc1Request received it: bits 1-2 the override control mode (speed "
     "control = 1 is rejected), bits 5-6 the priority"),
    ("0x003faa6b", "engine_retarder_received_tsc1_torque_byte",
     "TSC1 byte 4 (SPN 518 requested torque / torque limit, percent + 125) as cm848_processEngineRetarderTsc1Request "
     "received it; decoded by cm848_decodeRetarderTorqueRequestPercent"),
]
FUNCTIONS = [
    ("0x00027118", "cm848_resetEngineRetarderTsc1Request",
     "Ends the engine retarder TSC1 request: override control mode off, control device none, the torque limit 125 "
     "(no limit), and the retarder request timeout, time limit, zero torque timer and speed control flag cleared"),
    ("0x0050aec0", "cm848_endRetarderShiftAssistAboveFuelDemandLimit",
     "When governor_feature_config_word bit 0x1000 is set, the transmission holds both an engine retarder torque "
     "control request and an engine speed control request, and engine_operating_mode_fuel_demand has reached "
     "engine_retarder_shift_assist_fuel_demand_limit, it ends the retarder request (mode off, torque limit 125, the zero "
     "torque timer and the speed control flag cleared)"),
]
