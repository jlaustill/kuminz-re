"""Round 24 stage C (label-only): the cam / crank sync record (e2m 819C) and its state machine's functions. 'enter'
functions also re-run engine_injectionTiming_crankSyncDispatch; the 'set ... FromCam' ones are the cam handler's
minimal versions."""
GLOBALS = [
    ("0x0040b80a", "cam_crank_sync_state",
     "The cam / crank sync record (cam_crank_sync_state_t, e2m 819C: Cam_Sync_Error_Count / Cam_Sync_State / "
     "Crank_Sync_Error_Count / Crank_Sync_State): the two error counts and the two sync state machines of the TPU-A "
     "crank and cam signal handlers (mpc555_updateCrankSyncState, mpc555_handleCamSignalInterrupt); state 4 is in "
     "sync for both. No engine crank or run state"),
]
FUNCTIONS = [
    ("0x00045478", "mpc555_updateCrankSyncState",
     "TPU-A channel 0 interrupt handler (tpu_a_channel_interrupt_handler_table; no direct caller): runs the crank sync "
     "state machine cam_crank_sync_state.crank_sync_state from the channel's status - 0 no sync -> 2 start sync "
     "(start_sync_count up to crank_sync_attempt_limit) -> 3 preliminary sync (crank_preliminary_sync_count, then "
     "enough firing detections) -> 4 in sync (crank_have_sync_time_ticks, speed limp home ends); 1 = crank sync lost, "
     "back to 4 through the cam when the cam is in sync with enough good cam pulses, else to 3. It also counts "
     "crank_sync_error_count and, while the cam is not in sync above "
     "engine_position_sensor_error_detection_minimum_engine_speed, cam_sync_error_count"),
    ("0x00044d20", "cm848_enterCrankSyncLost",
     "Crank sync lost (from mpc555_updateCrankSyncState): crank_sync_state = 1; with the cam in sync (cam_sync_state "
     "4) and speed limp home not active, enters speed limp home (cm848_enterSpeedLimpHome) and re-runs "
     "engine_injectionTiming_crankSyncDispatch"),
    ("0x00044cc8", "cm848_enterCamSyncLost",
     "Cam sync lost (from mpc555_handleCamSignalInterrupt): cam_sync_state = 1; when speed limp home is active it "
     "ends it (cm848_exitSpeedLimpHome) and re-runs engine_injectionTiming_crankSyncDispatch"),
    ("0x00044f0c", "cm848_enterCrankPreliminarySync",
     "crank_sync_state = 3 (preliminary sync) from start sync (mpc555_updateCrankSyncState) and from "
     "hpcr_processEngineSyncPulses: snapshots average_pulse_period, restarts crank_preliminary_sync_count from "
     "crank_preliminary_sync_evaluation_count, ends speed limp home when it is active, re-runs "
     "engine_injectionTiming_crankSyncDispatch and latches crank_preliminary_sync_time_ticks the first time"),
    ("0x00044dd0", "cm848_reenterCrankPreliminarySync",
     "crank_sync_state = 3 again after crank sync was lost with no usable cam (mpc555_updateCrankSyncState in state "
     "1): cm848_enterCrankPreliminarySync without the time latch"),
    ("0x00044aa4", "cm848_setCrankPreliminarySyncFromCam",
     "The cam signal handler's crank_sync_state = 3: snapshots average_pulse_period and restarts "
     "crank_preliminary_sync_count; no speed limp home change, no dispatch"),
    ("0x00044d70", "cm848_enterCrankInSync",
     "crank_sync_state = 4 (in sync) when crank sync lost recovers through the cam (mpc555_updateCrankSyncState): "
     "ends speed limp home, re-runs engine_injectionTiming_crankSyncDispatch and latches crank_have_sync_time_ticks "
     "the first time"),
    ("0x00044eac", "cm848_enterCrankInSyncFromCam",
     "The cam signal handler's crank_sync_state = 4: the same body as cm848_enterCrankInSync"),
    ("0x00044e3c", "cm848_setCrankInSyncFromCam",
     "The cam signal handler's other crank_sync_state = 4: ends speed limp home and re-runs "
     "engine_injectionTiming_crankSyncDispatch only when speed limp home is active; latches "
     "crank_have_sync_time_ticks the first time"),
]
