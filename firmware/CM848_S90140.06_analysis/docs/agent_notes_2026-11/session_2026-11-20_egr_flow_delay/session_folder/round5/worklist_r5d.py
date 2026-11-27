"""Round 5 stage d: quick label renames verified in the main session (evidence_W15.py rows; the function heads read)."""
GLOBALS = [
    ("0x00408722", "cruise_maximum_engine_speed",
     "governor_cruise_deniedStatus_update denies cruise above it (compared with engine_speed_state.engine_speed)"),
    ("0x00408730", "cruise_minimum_engine_speed",
     "governor_cruise_deniedStatus_update denies cruise below it (compared with engine_speed_state.engine_speed)"),
    ("0x003fb3ae", "engine_acceleration_engine_speed_previous",
     "cm848_processEngineRpmDerivative: engine_speed_state.engine_speed of the previous pass, for the acceleration"),
    ("0x003fb590", "cylinder_balance_engine_speed_previous",
     "hpcr_cbdCalculateCylinderTrims: engine_speed_state.engine_speed of the previous pass"),
    ("0x003fce41", "intake_air_heater_crank_elapsed_ticks",
     "cm848_updateIntakeAirHeaterCrankPhase: passes in the crank phase (e2m 8A35 +2 phase 3 = crank), against "
     "intake_air_heater_crank_heat_time_limit"),
    ("0x003fce43", "intake_air_heater_crank_low_engine_speed_count",
     "cm848_updateIntakeAirHeaterCrankPhase: passes with the engine speed below the crank threshold, against "
     "intake_air_heater_crank_low_engine_speed_time_limit"),
    ("0x003fce3f", "intake_air_heater_crank_time_countdown",
     "counts down from intake_air_heater_crank_time_limit (e2m 8A2B +0 IAH_Crank_Time_Limit)"),
]
FUNCTIONS = [
    ("0x000403e4", "cm848_claimAcceleratorInterlockThrottleOverride",
     "With the accelerator interlock enabled and switch 26 on: claims the throttle override with "
     "accelerator_interlock_throttle_priority (when it beats the current one) and value 0"),
    ("0x0050e610", "cm848_claimRemoteThrottleOverride",
     "With the remote throttle enabled: mirrors its two fault bits (64-79 0x4000 / 0x2000 -> 160-175 0x800 / 0x1000) "
     "and - with switch 31 on or the rate limit check active - claims the throttle override with "
     "remote_throttle_priority and the remote throttle value"),
    ("0x0001bb30", "cm848_initializeCrankTimingOutputs",
     "Seeds crank_four_dimensional_timing and crank_exit_advance with -1024 (0xfc00)"),
    ("0x0051736c", "cm848_updateIntakeAirHeaterCrankPhase",
     "The intake air heater crank phase (e2m 8A35 +2 IAH_Phase 3 = crank): clears relays 43 / 44 on entry, then by "
     "the start temperature heats until the low engine speed count or the crank heat time runs out"),
    ("0x00512a60", "cm848_updateCruiseControlDeniedStatus",
     "Returns 1 when cruise is denied and stores the reason code 1-12 in cruise_control_denied_status (and the cutout "
     "reason while engaged)"),
]
