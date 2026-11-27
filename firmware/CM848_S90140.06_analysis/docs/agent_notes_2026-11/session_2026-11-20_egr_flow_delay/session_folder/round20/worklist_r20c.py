"""Round 20 stage C (label-only), part 1: the cold delta fuel (e2m 8A9F Cold_Delta_Fuel / 8AA0-8AA2 Cold_Delta_Fuel_Table)
and the misfire timing limit function. fuel_demand_offset_correction is Cold_Delta_Fuel: it is looked up from coolant
temperature x engine speed (the 8AA0 X axis is Coolant_Temperature, the 8AA1 Y axis ENGRPM), and each of its nine gated
additions sits behind an algorithm enable bit whose e2m record says 'add Cold_Delta_Fuel to <that limit>'."""
GLOBALS = [
    ("0x0040b22a", "cold_delta_fuel",
     "Cold delta fuel (e2m 8A9F +0 Cold_Delta_Fuel, mm3/stroke: 'Amount of fuel to add to AFC, torque curve based on RPM "
     "and coolant temperature'): cm848_calculateColdDeltaFuel looks it up from coolant temperature and engine speed (0 "
     "while fault 16, 17 or 401 is detected). The cold increment bits add it to a limit each: "
     "algorithm_enable_flags_41_cal throttle_100 / air_fuel_control, algorithm_enable_flags_42_cal 0x8 fuel pressure "
     "fault / 0x80 altitude derate / 0x100 hybrid governor / 0x200 torque management, algorithm_enable_flags_43_cal 0x40 "
     "chi / 0x80 density / 0x100 net torque; cm848_updateEngineRetarderAllowedState adds it to "
     "engine_retarder_idle_maximum_fueling"),
    ("0x0005c67c", "cold_delta_fuel_x_axis",
     "Cold delta fuel table X axis (e2m 8AA0 Cold_Delta_Fuel_Temp_Axis, coolant temperature, 1/64 deg F)"),
    ("0x0005c690", "cold_delta_fuel_y_axis",
     "Cold delta fuel table Y axis (e2m 8AA1 Cold_Delta_Fuel_Speed_Axis, engine speed, 0.125 rpm)"),
    ("0x0005c69c", "cold_delta_fuel_grid",
     "Cold delta fuel table (e2m 8AA2 Cold_Delta_Fuel_Table, mm3/stroke, over 8AA0 x 8AA1)"),
]
FUNCTIONS = [
    ("0x000373b0", "cm848_calculateColdDeltaFuel",
     "Sets cold_delta_fuel (e2m 8A9F Cold_Delta_Fuel) from the e2m 8AA2 Cold_Delta_Fuel_Table by coolant temperature "
     "and filtered engine speed, or 0 while fault 16, 17 or 401 is detected"),
    ("0x00029e50", "cm848_calculateInjectionTimingMainMisfireLimit",
     "While algorithm_enable_flags_40_cal bit 8 (e2m Misfire_Timing_Limit_Enable) is set, looks up "
     "injection_timing_main_misfire_limit (e2m 8A3D Misfire_Timing_Limit) from the misfire timing table (8A40 "
     "Misfire_Timing_Table) by boost pressure and filtered engine speed; it does no speed control"),
]
