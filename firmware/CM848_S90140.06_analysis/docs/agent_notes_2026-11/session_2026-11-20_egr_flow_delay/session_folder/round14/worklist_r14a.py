"""Round 14 stage A (label-only): the low speed governor (LSG) reference speed chain, from the Cummins e2m blocks
aligned by relative offset (they lie past the end of the dumped parameter ID table):
- 14EE (ROM settings) at 0x4070ee: all 32 records +0..+3E match their code use and the dump values, and 8C76 follows
  at 0x40712e (11.46 has no +40 / +42);
- 1496 (RAM) at 0x40aeb2: all 16 records match (+14 LSG_Reference_Speed_State is the source code, +1A
  SCI_Cmd19_Status the 0xE5C1 key);
- 14EF (ROM) at 0x5c4ae, ending where 8A51 starts (0x5c4b6), and 14F0 (RAM) at 0x40aede: the LSG error terms.
Widths match the e2m sizes (14EE +28 and 1496 +16 are the 4-byte records). The three *_PN_Enable flags read
backwards (0 restricts the feature to park / neutral at rest), so they are named for what 1 does. Switch 13 is e2m 1612
AC_On_Off_Switch, 11 Brake_Switch, 2 Not_Brake_Switch."""
A, R, EF, F0 = "e2m 14EE", "e2m 1496", "e2m 14EF", "e2m 14F0"
PN = "in park or neutral with the vehicle at rest"
GLOBALS = [
    # 14EE: the ROM settings
    ("0x004070ee", "low_speed_governor_cold_idle_coolant_temperature",
     f"{A} +0 Cold_Idle_Coolant_Temperature (DEG_F; 0 in the dump): below it, while the LSG runs, "
     "low_speed_governor_cold_idle_timer counts; at low_speed_governor_cold_idle_time the coolant temperature speed "
     "request drops to 0"),
    ("0x004070f0", "low_speed_governor_cold_idle_time",
     f"{A} +2 Cold_Idle_Time (SEC; 0 = off here): the cold idle timer's limit"),
    ("0x004070f2", "low_speed_governor_hot_idle_coolant_temperature",
     f"{A} +4 Hot_Idle_Coolant_Temperature (DEG_F; 12800 = 200 F): at or above it the hot idle inhibit and hot idle "
     "timers run (they reset below it minus low_speed_governor_coolant_temperature_hysteresis)"),
    ("0x004070f4", "low_speed_governor_hot_idle_inhibit_time",
     f"{A} +6 Hot_Idle_Inhibit_Time (SEC; 0 = off): while hot, the coolant temperature speed request stays 0 until "
     "low_speed_governor_hot_idle_inhibit_timer reaches it"),
    ("0x004070f6", "low_speed_governor_hot_idle_time",
     f"{A} +8 Hot_Idle_Time (SEC; 0 = off): while hot and at the coolant speed, low_speed_governor_hot_idle_timer "
     "counts; at this the coolant temperature speed request drops to 0"),
    ("0x004070f8", "low_speed_governor_air_conditioning_idle_speed",
     f"{A} +A LSG_AC_Idle_Speed 'LSG_AC_Speed set to this when AC switch is ON' (6000 = 750 rpm): "
     "low_speed_governor_air_conditioning_speed_request while switch 13 (e2m 1612 AC_On_Off_Switch) is on"),
    ("0x004070fa", "low_speed_governor_drive_idle_speed",
     f"{A} +C LSG_Drive_Speed (6000 = 750 rpm): the park / drive speed request when not {PN}"),
    ("0x004070fc", "low_speed_governor_extended_idle_coolant_temperature",
     f"{A} +E LSG_Extended_Idle_Coolant_Temp (12800 = 200 F): the extended idle needs the coolant below it"),
    ("0x004070fe", "low_speed_governor_extended_idle_intake_manifold_temperature",
     f"{A} +10 LSG_Extended_Idle_IMT (6400 = 100 F): the extended idle needs the intake manifold temperature at or "
     "below it"),
    ("0x00407100", "low_speed_governor_extended_idle_road_speed",
     f"{A} +12 LSG_Extended_Idle_Road_Speed (0 here): the extended idle needs the vehicle speed at or below it"),
    ("0x00407102", "low_speed_governor_extended_idle_speed",
     f"{A} +14 LSG_Extended_Idle_Speed 'LSG_Extended_Speed set to this when extended idle conditions true' (8000 = "
     "1000 rpm)"),
    ("0x00407104", "low_speed_governor_extended_idle_time",
     f"{A} +16 LSG_Extended_Idle_Time (6000 passes): the extended idle conditions must hold this long "
     "(low_speed_governor_extended_idle_timer)"),
    ("0x00407106", "low_speed_governor_idle_decrement_rate",
     f"{A} +18 LSG_Idle_Decrement_Rate (8 per pass): how fast cm848_slewLowSpeedGovernorReferenceSpeed lowers the "
     "reference speed toward the desired speed (plus low_speed_governor_extra_decrement_rate)"),
    ("0x00407108", "low_speed_governor_idle_increment_rate",
     f"{A} +1A LSG_Idle_Increment_Rate (8 per pass): how fast the slew raises the reference speed"),
    ("0x0040710a", "low_speed_governor_maximum_idle_speed",
     f"{A} +1C LSG_Max_Idle_Speed '[LSMXRF] Maximum allowable LSG reference speed' (9600 = 1200 rpm): above it the "
     "reference speed is clamped (reference speed state 8 MAX), except for the tool speed"),
    ("0x0040710c", "low_speed_governor_minimum_idle_speed",
     f"{A} +1E LSG_Min_Idle_Speed '[LSMNRF] Minimum allowable LSG reference speed' (6000 = 750 rpm): below it the "
     "reference speed is clamped (state 7 MIN); the desired speed under a J1939 TSC1 override (state 6) and the "
     "J1939 engine configuration's idle speed (/ 80)"),
    ("0x0040710e", "low_speed_governor_park_idle_speed",
     f"{A} +20 LSG_Park_Speed (6000 = 750 rpm): the park / drive speed request {PN}"),
    ("0x00407110", "low_speed_governor_j1850_request_enable",
     f"{A} +22 LSG_J1850_Enable (0 here): 1 lets pci_requested_idle_speed (PCI / J1850) through as "
     "low_speed_governor_j1850_speed_request"),
    ("0x00407112", "low_speed_governor_coolant_speed_outside_park_neutral_enable",
     f"{A} +24 LSG_Coolant_PN_Enable (0 here): with 0 the coolant temperature speed applies only {PN}; 1 applies "
     "it always"),
    ("0x00407114", "low_speed_governor_j1939_override_enable",
     f"{A} +26 LSG_Jcomm_Enable (0 here): 1 makes a J1939 TSC1 override set the desired speed to "
     "low_speed_governor_minimum_idle_speed (state 6 JCOMM)"),
    ("0x00407116", "low_speed_governor_altitude_slew_rate",
     f"{A} +28 LSG_Altitude_Slew_Rate (4 bytes; 205 here, in the altitude speed's 1/8 rpm x 256 units): while the "
     "altitude speed controls (state 9) it moves at most this per pass"),
    ("0x0040711a", "low_speed_governor_altitude_speed_outside_park_neutral_enable",
     f"{A} +2C LSG_Altitude_PN_Enable (0 here): with 0 the altitude speed applies only {PN}"),
    ("0x0040711c", "low_speed_governor_altitude_hysteresis",
     f"{A} +2E LSG_Altitude_Hyst (IN_HG; 126 here): 0 selects the interpolated altitude speed table; otherwise a "
     "step lookup that keeps the higher step until the barometric pressure is this far past it"),
    ("0x0040711e", "low_speed_governor_coolant_temperature_hysteresis",
     f"{A} +30 LSG_Coolant_Temp_Hyst (320 = 5 F): 0 selects the interpolated coolant speed table; otherwise a step "
     "lookup with this hysteresis; also the hot idle timers' reset band"),
    ("0x00407120", "low_speed_governor_moving_road_speed",
     f"{A} +32 LSG_Ref_Road_Speed 'Road speed threshold for lsg ref to determine vehicle in motion' (64000 = 250 mph "
     "here, so never): above it the vehicle counts as moving for the park / neutral speeds and the slew"),
    ("0x00407122", "low_speed_governor_extended_idle_battery_temperature",
     f"{A} +34 LSG_Extended_Idle_Battery_Temp (2560 = 40 F): the extended idle needs the battery temperature below "
     "it"),
    ("0x00407124", "low_speed_governor_slew_outside_park_neutral_enable",
     f"{A} +36 LSG_Slew_PN_Enable (0 here): with 0 the reference speed slews only {PN} (elsewhere it jumps to the "
     "desired speed)"),
    ("0x00407126", "low_speed_governor_maximum_tool_idle_speed",
     f"{A} +38 LSG_Max_Tool_Idle_Speed 'Maximum allowable LSG reference speed when the tool is commanding speed' "
     "(16800 = 2100 rpm): the clamp of the tool speed (state 11)"),
    ("0x00407128", "low_speed_governor_extended_idle_coolant_state_enable",
     f"{A} +3A LSG_Extended_Idle_Coolant_State_Enable (1 here): 1 also grants the extended idle at once when the "
     "coolant speed controls (state 0) and the LSG output is 0"),
    ("0x0040712a", "low_speed_governor_moving_extra_decrement_rate",
     f"{A} +3C LSG_Moving_Extra_Decrement_Rate (0 here): low_speed_governor_extra_decrement_rate while the moving "
     "speed controls (state 12)"),
    ("0x0040712c", "low_speed_governor_moving_extra_increment_rate",
     f"{A} +3E LSG_Moving_Extra_Increment_Rate (0 here): low_speed_governor_extra_increment_rate in state 12"),
    # 1496: the RAM speeds
    ("0x0040aeb2", "low_speed_governor_adjusted_reference_before_droop",
     f"{R} +0 LSG_Adjusted_Ref_Before_Droop '[LSRFBFDP] LSG reference speed before droop': the slewed reference "
     "speed that cm848_calculateLowSpeedGovernorErrorTerms starts from (also the friction fuel lookup input)"),
    ("0x0040aeb4", "low_speed_governor_desired_reference_speed",
     f"{R} +2 Desired_Low_Idle_Ref_Speed: the largest speed request, chosen by "
     "cm848_selectLowSpeedGovernorDesiredReferenceSpeed (its source is the reference speed state); the slew moves "
     "the reference speed toward it; also read by cm848_calculateAllSpeedGovernorThrottleReference"),
    ("0x0040aeb6", "low_speed_governor_air_conditioning_speed_request",
     f"{R} +4 LSG_AC_Speed: low_speed_governor_air_conditioning_idle_speed while switch 13 (the A/C switch) is on, "
     "else 0 (state 3 AC)"),
    ("0x0040aeb8", "low_speed_governor_coolant_temperature_speed_request",
     f"{R} +6 LSG_Coolant_Temp_Speed: the coolant temperature speed table result, zeroed by the cold / hot idle "
     "timers and outside park / neutral (state 0 COOLANT)"),
    ("0x0040aeba", "low_speed_governor_extended_idle_speed_request",
     f"{R} +8 LSG_Extended_Speed: low_speed_governor_extended_idle_speed once the extended idle conditions held for "
     "low_speed_governor_extended_idle_time, else 0 (state 2 EXTENDED)"),
    ("0x0040aebc", "low_speed_governor_extended_idle_active_flag",
     f"{R} +A LSG_Extended_Idle_Status 'Status of LSG extended idle (1=on)': set by the slew when the reference "
     "speed sits at the extended idle speed; read by the retarder and injection timing logic"),
    ("0x0040aebe", "low_speed_governor_j1850_speed_request",
     f"{R} +C LSG_J1850_Speed: pci_requested_idle_speed when low_speed_governor_j1850_request_enable is 1, else 0 "
     "(state 4 J1850)"),
    ("0x0040aec0", "low_speed_governor_park_or_drive_speed_request",
     f"{R} +E LSG_PN_Speed: low_speed_governor_park_idle_speed {PN}, else low_speed_governor_drive_idle_speed "
     "(state 1 PARK_NEU)"),
    ("0x0040aece", "low_speed_governor_tool_speed_request",
     f"{R} +1C LSG_Tool_Speed 'Output of Chrysler LSG tool override speed logic': sci_set_engine_speed_request "
     "under its conditions, high_pressure_safety_valve_test_engine_speed_setpoint while that test runs, else 0 "
     "(state 11 TOOL)"),
    ("0x0040aed2", "low_speed_governor_moving_speed_request",
     f"{R} +20 LSG_Moving_Speed: the moving speed table by vehicle speed, 0 while the brake switch (11) or switch 2 "
     "is on (state 12 MOVING)"),
    # 14EF / 14F0: the error terms
    ("0x0005c4ae", "low_speed_governor_error_filter_coefficient",
     f"{EF} +0 LSG_Error_Filter_Constant (0 = no filtering here): the coefficient of low_speed_governor_error_filter"),
    ("0x003faf66", "low_speed_governor_error_filter",
     "The cm848_signedFirstOrderFilter record of the LSG speed error (coefficient "
     "low_speed_governor_error_filter_coefficient); cm848_calculateLowSpeedGovernorErrorTerms presets its "
     "accumulator when the filtered error hits a clamp"),
    ("0x0040aee0", "low_speed_governor_adjusted_reference_speed",
     f"{F0} +2 LSG_Adjusted_Reference_Speed: the reference before droop minus the droop offset (0x40aedc), clamped "
     "to the minimum / maximum idle speeds (the tool clamp in state 11)"),
    ("0x0040aee2", "low_speed_governor_derivative_error_term",
     f"{F0} +4 LSG_Derivative_Error_Term: the pass-to-pass change of low_speed_governor_filtered_speed_error, "
     "clamped to +-0x640"),
    ("0x0040aee4", "low_speed_governor_jerk_error_term",
     f"{F0} +6 LSG_Jerk_Error_Term: the pass-to-pass change of the derivative term"),
    # the working words
    ("0x003faf6e", "low_speed_governor_coolant_temperature_speed_cached_axis_offset",
     "Lookup cache of the low_speed_governor_coolant_temperature_speed table"),
    ("0x003faf70", "low_speed_governor_cold_idle_timer",
     "Counts while the coolant is below low_speed_governor_cold_idle_coolant_temperature and the LSG runs; 0 when "
     "warmer; at low_speed_governor_cold_idle_time the coolant speed request drops to 0"),
    ("0x003faf72", "low_speed_governor_hot_idle_inhibit_timer",
     "Counts while hot (low_speed_governor_hot_idle_coolant_temperature) and the LSG runs; the coolant speed request "
     "stays 0 until it reaches low_speed_governor_hot_idle_inhibit_time"),
    ("0x003faf74", "low_speed_governor_hot_idle_timer",
     "Counts while hot with the reference speed at the coolant speed; at low_speed_governor_hot_idle_time the "
     "coolant speed request drops to 0"),
    ("0x003faf76", "low_speed_governor_shift_in_process_timer",
     "Counts while ETC1 reports a shift in process (SPN 574), up to low_speed_governor_shift_in_process_hold_passes; "
     "while it is below that the desired speed holds (state 10 SIP)"),
    ("0x003faf78", "low_speed_governor_extended_idle_timer",
     "Counts while the extended idle conditions hold; at low_speed_governor_extended_idle_time the extended idle "
     "speed request turns on"),
    ("0x003faf80", "low_speed_governor_altitude_speed_target",
     "Dword: the altitude speed table result x 256 (1/8 rpm x 256) before the slew"),
    ("0x003faf84", "low_speed_governor_altitude_speed_cached_axis_offset",
     "Lookup cache of the low_speed_governor_altitude_speed table"),
    ("0x003faf86", "low_speed_governor_altitude_speed_previous",
     "Dword: the altitude speed of the previous pass, the base of its slew clamp (low_speed_governor_altitude_slew_"
     "rate)"),
    ("0x003faf8a", "low_speed_governor_shift_in_process_hold_passes",
     "shift_in_process_hold_off_time_limit x 5, set each pass by cm848_updateLowSpeedGovernorReferenceSpeed: how long "
     "a shift in process holds the desired speed"),
    ("0x003faf8c", "low_speed_governor_coolant_speed_first_pass_done_flag",
     "Set after the first pass of the coolant speed step lookup; the hysteresis applies from the second pass on"),
    ("0x003faf8e", "low_speed_governor_altitude_speed_first_pass_done_flag",
     "Set after the first pass of the altitude speed step lookup; the hysteresis applies from the second pass on"),
    ("0x003faf90", "low_speed_governor_reference_speed_state_previous",
     "The reference speed state of the previous pass; the slew skips the pass after the tool speed (state 11)"),
    ("0x003faf92", "low_speed_governor_moving_speed_cached_axis_offset",
     "Lookup cache of the low_speed_governor_moving_speed table"),
    ("0x003faf94", "low_speed_governor_extra_decrement_rate",
     "low_speed_governor_moving_extra_decrement_rate while the moving speed controls (state 12), else 0; added to "
     "the slew's decrement rate"),
    ("0x003faf96", "low_speed_governor_extra_increment_rate",
     "low_speed_governor_moving_extra_increment_rate in state 12, else 0; added to the slew's increment rate"),
    # the tables
    ("0x0005c4b6", "low_speed_governor_coolant_temperature_speed_axis",
     "e2m 8A51 LSG_Coolant_Temp_Axis: the coolant temperature axis of the coolant speed table"),
    ("0x0005c4c8", "low_speed_governor_coolant_temperature_speed_values",
     "e2m 8A52 LSG_Coolant_Speed_Table: the coolant temperature speed (the step lookup of the altitude speed reads "
     "past it as [index + 8], which is the next table)"),
    ("0x0005c4da", "low_speed_governor_altitude_speed_axis",
     "The barometric pressure axis of the altitude speed table (by role e2m 8B16 LSG_Altitude_Axis; the dumped "
     "parameter table does not reach it)"),
    ("0x0005c4e6", "low_speed_governor_altitude_speed_values",
     "The altitude speed by barometric pressure (by role e2m 8B17 LSG_Altitude_Speed_Table)"),
    ("0x00407172", "low_speed_governor_moving_speed_axis",
     "e2m 8C52 LSG_Moving_VSS_Table: the vehicle speed axis of the moving speed table"),
    ("0x0040715e", "low_speed_governor_moving_speed_values",
     "e2m 8C51 LSG_Moving_LSG_Table 'LSG Vehicle Speed Based Idle Speed Table'"),
]
STEPS = "cm848_updateLowSpeedGovernorReferenceSpeed"
FUNCTIONS = [
    ("0x00029afc", STEPS,
     "The LSG reference speed task (cm848_periodicTaskSet_sensorProcessing): sets "
     "low_speed_governor_shift_in_process_hold_passes, then runs cm848_calculateLowSpeedGovernorCoolantTemperatureSpeed, "
     "cm848_selectLowSpeedGovernorDesiredReferenceSpeed and cm848_slewLowSpeedGovernorReferenceSpeed (e2m 14EE / "
     "1496)"),
    ("0x00028d44", "cm848_calculateLowSpeedGovernorCoolantTemperatureSpeed",
     "low_speed_governor_coolant_temperature_speed_request from the coolant temperature table (or a step lookup with "
     "hysteresis), zeroed outside park / neutral unless enabled, after low_speed_governor_cold_idle_time of cold "
     "idling, during the hot idle inhibit time and after low_speed_governor_hot_idle_time at that speed (e2m 14EE "
     "+0..+8)"),
    ("0x0002906c", "cm848_selectLowSpeedGovernorDesiredReferenceSpeed",
     "Picks low_speed_governor_desired_reference_speed as the largest of the LSG speed requests and records the "
     "winner in low_speed_governor_reference.reference_speed_state (e2m 1496 +14: 5 BASE "
     "low_speed_governor_base_reference_speed_cal / 0 COOLANT / 1 PARK_NEU / 2 EXTENDED / 3 AC / 4 J1850 / 9 ALTITUDE "
     "/ 11 TOOL / 12 MOVING; 10 SIP holds the speed during a shift; 6 JCOMM = a J1939 TSC1 override). It also "
     "computes the park or drive, A/C, J1850, extended idle, altitude, tool and moving requests, and the high "
     "pressure safety valve test state"),
    ("0x000298a0", "cm848_slewLowSpeedGovernorReferenceSpeed",
     "Moves low_speed_governor_reference.reference_speed toward the desired speed by the increment / decrement rates "
     "(only in park or neutral at rest unless enabled, and not around the tool speed), then clamps it to "
     "low_speed_governor_minimum_idle_speed (state 7) and _maximum_idle_speed (state 8; the tool speed to "
     "low_speed_governor_maximum_tool_idle_speed). Writes the reference before droop, the extended idle status and "
     "the shift in process timer"),
    ("0x00028ba4", "cm848_calculateLowSpeedGovernorErrorTerms",
     "The LSG error terms (e2m 14EF / 14F0): the adjusted reference speed (the reference before droop minus 0x40aedc, "
     "clamped), the speed error x low_speed_governor_error_filter_gain >> 9 through low_speed_governor_error_filter "
     "and its +-8000 clamps into low_speed_governor_filtered_speed_error, then its derivative and jerk terms"),
    ("0x00029bf8", "cm848_initializeLowSpeedGovernorReferenceSpeed",
     "Boot initializer (cm848_applicationMain) of the LSG reference speed chain: the lookup caches, the timers and "
     "first-pass flags, the base reference copy at 0x3faf7c, the state 5 (BASE), and the J1939 TSC1 override "
     "control mode (off)"),
    ("0x00029b38", "cm848_calculateLowSpeedGovernorNoLoadFuel",
     "low_speed_governor_reference.no_load_fuel (e2m 1496 +12 No_Load_Fuel_At_LSG_Ref): fuel_demand_base_offset, or "
     "(outside low speed governor final gain states 0 / 1) the friction fuel at the reference before droop + the "
     "fuel by throttle table + the coolant friction adjustment + governor_speed_target_trim"),
]
