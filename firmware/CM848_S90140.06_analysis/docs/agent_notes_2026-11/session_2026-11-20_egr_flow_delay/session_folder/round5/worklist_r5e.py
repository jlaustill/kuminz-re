"""Round 5 stage e: the cruise / vehicle speed limit governor functions in Bank 2 (wave 15 bins 3 and 6; profiled with
writes_of.py and read in the main session). None is shared with CM550."""
A = "cm848_controlAirConditioningClutchForDrTruck"
GLOBALS = [
    ("0x003fcd60", "air_conditioning_pressure_learn_count",
     f"{A}: counts passes with the raw A/C pressure inside the learn window (air_conditioning_pressure_learn_raw_minimum "
     "/ _maximum) up to air_conditioning_pressure_learn_time"),
    ("0x003fcd70", "air_conditioning_high_pressure_ok_flag",
     f"{A}: 1 below air_conditioning_high_pressure_on_threshold, 0 above the off threshold (hysteresis)"),
    ("0x003fcd72", "air_conditioning_low_pressure_ok_flag",
     f"{A}: 1 above air_conditioning_low_pressure_on_threshold, 0 below the off threshold"),
    ("0x003fcd74", "air_conditioning_high_engine_speed_ok_flag",
     f"{A}: 1 below air_conditioning_high_rpm_on_threshold, 0 above the off threshold"),
    ("0x003fcd68", "air_conditioning_low_engine_speed_on_count",
     f"{A}: counts passes above air_conditioning_low_rpm_on_threshold up to air_conditioning_low_rpm_on_time"),
    ("0x003fcd76", "air_conditioning_low_engine_speed_ok_flag",
     f"{A}: 1 after the low rpm on time above the low rpm on threshold, 0 below the low rpm off threshold"),
    ("0x003fcd78", "air_conditioning_coolant_temperature_ok_flag",
     f"{A}: 1 below air_conditioning_high_coolant_temperature_on_threshold, 0 above the off threshold"),
    ("0x003fcd6c", "air_conditioning_cycle_on_count",
     f"{A}: compared with air_conditioning_cycle_on_time (the A/C driver can turn on once every that long)"),
    ("0x003fcd6e", "air_conditioning_cycle_off_count",
     f"{A}: compared with air_conditioning_cycle_off_time (the minimum A/C driver off time)"),
    ("0x003fcd5e", "air_conditioning_shift_hold_off_count",
     "cm848_controlAirConditioningClutchForBrTruck: counts up to shift_in_process_hold_off_time_limit while a "
     "transmission shift is in process"),
    ("0x0040b1e7", "air_conditioning_condition_code",
     f"{A}: the reason code 1-15 of the A/C clutch decision (the e2m condition codes); 5 at initialization"),
    ("0x003fcd66", "air_conditioning_clutch_request_bit_6_previous",
     f"{A}: bit 0x40 of air_conditioning_clutch_request_byte on the previous pass (edge detection)"),
]
FUNCTIONS = [
    ("0x00510f34", "cm848_initializeAirConditioningClutchControl",
     "Initializes the A/C clutch control: releases logical output 0x26 (the A/C clutch request), resets the counts "
     "and the high fuel demand cutout, condition codes 5"),
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
