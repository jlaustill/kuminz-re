"""Round 5 stage e: the cruise / vehicle speed limit governor functions in Bank 2 (wave 15 bins 3 and 6; profiled with
writes_of.py and read in the main session). None is shared with CM550."""
GLOBALS = []
FUNCTIONS = [
    ("0x00525504", "cm848_runCruiseAndVehicleSpeedLimitGovernor",
     "The cruise control / vehicle speed limit (road speed governor) PID, run every pass from "
     "cm848_periodicTaskSet_outputs: the reference and ramp target speeds, the speed error and its rate term, the "
     "proportional and integral (Q16) terms, the fuel demand delta into adjusted_user_fueling, the stable-speed and "
     "rate-correction timers; it presets the governor (cm848_presetCruiseAndVehicleSpeedLimitGovernor) when needed"),
    ("0x005251e4", "cm848_presetCruiseAndVehicleSpeedLimitGovernor",
     "The bumpless start of the cruise / vehicle speed limit governor (also from cm848_arbitrateGovernedFueling): "
     "selects the gain zone (cm848_selectCruiseControlGainZone), sets the ramp target and reference speed (the vehicle "
     "speed limit in state 10, else the cruise command or the vehicle speed plus the droop error delta), the clamped "
     "speed error, and presets the integrator from the present fueling"),
    ("0x00524df4", "cm848_initializeCruiseControlDroopGains",
     "Boot pass (cm848_applicationMain): the power-up cruise and road speed governor droop gains and offsets "
     "(e2m 1187), the zone code and the deadband / zone transition flags"),
    ("0x0052470c", "cm848_selectCruiseControlGainZone",
     "Computes the cruise droop speed error delta and picks the cruise gain zone (cruise_speed_zone_code, with "
     "hysteresis on the zone thresholds) and its PID gains into cruise_pid_kp / ki / kd / rate gain working"),
]
