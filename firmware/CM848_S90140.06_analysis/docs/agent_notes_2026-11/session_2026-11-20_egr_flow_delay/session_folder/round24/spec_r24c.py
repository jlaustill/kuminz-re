"""Round 24 stage C: the cam / crank sync record (e2m 819C, the ECU's parameter ID table maps it to 0x40b80a)."""
TYPES = {"engine_crank_state_t": "cam_crank_sync_state_t"}
INSTANCES = {"engine_crank_state_t_0040b80a": ("0x0040b80a", "cam_crank_sync_state", "engine_crank_state_t")}
E = "e2m 819C"
FIELDS = {"engine_crank_state_t": {
    "start_counter": ("cam_sync_error_count",
                      f"{E} +0 Cam_Sync_Error_Count 'TOTAL NUMBER OF SYNC LOSSES': +1 per crank signal interrupt while "
                      "cam_sync_state is not 4 above engine_position_sensor_error_detection_minimum_engine_speed "
                      "(mpc555_updateCrankSyncState); cm848_updateEngineSpeedFromCrankSignal compares it with "
                      "cam_sync_error_count_limit. No engine start counter"),
    "crank_state": ("cam_sync_state",
                    f"{E} +2 Cam_Sync_State: the cam signal handler's state, 4 = in sync, 1 = lost "
                    "(cm848_enterCamSyncLost); the e2m value labels (0 no sync / 1 have sync / 2 lost on cam / 3 start "
                    "sync) do not match this firmware's numbering. No crank state"),
    "cranking_flag": ("crank_sync_error_count",
                      f"{E} +4 Crank_Sync_Error_Count 'Incremented 6/cam when crank not synched' (CNTS): counted up "
                      "and down by mpc555_updateCrankSyncState from the TPU-A channel 0 status; "
                      "cm848_updateEngineSpeedFromCrankSignal compares it with crank_sync_error_count_limit. No "
                      "cranking flag"),
    "run_state": ("crank_sync_state",
                  f"{E} +6 Crank_Sync_State: 0 no sync / 2 start sync / 3 preliminary sync / 4 in sync / 1 lost "
                  "(mpc555_updateCrankSyncState and its setters); the e2m value labels (0 no sync / 1 have sync / 2 "
                  "lost on crank / 3 start sync) do not match this firmware's numbering. State 4 gates the cylinder "
                  "balance and the fuel pressure feedback filter. No engine run state"),
}}
