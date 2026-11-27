"""Round 17 stage A (label-only): the engine retarder (exhaust brake) request chain, from e2m 1070 / 1071 / 1192 and
117D (placed by the ECU's parameter ID table) and the code of cm848_processEngineRetarderRequest's seven steps.
Vocabulary (task 046): the e2m's override / non-override commands. The override command is the TSC1 request
(source 1 J1939 override or 6 no override); the non-override command is the lowest of the cruise permission (2), the
operator switch selection (3) and the TSC1 limit (4); the allowed state (0 none / 1 override only / 2 override or
non-override) picks between them, and the command level is the result. 'Driver' in these names is the human (pedal /
clutch / brake conditions); the e2m's brake hardware 'driver' words take 'output' names instead. The e2m 1070 +10 /
+20 descriptions (a 0-255 switch sum, a 0-1 fraction in 1/8192) do not explain the code's 0 / 100 values, so those two
words keep their code-derived names."""
CMD = "the engine retarder command"
GLOBALS = [
    # e2m 1070 (RAM 0x40a352..): the arbitration
    ("0x0040a352", "engine_retarder_command_percent",
     "The engine retarder command level (0-101 %): cm848_selectEngineRetarderCommand takes the override command, the "
     "non-override command (allowed state OVERRIDE_OR_NON_OVERRIDE) or 0; the output stage and the allowed state read it"),
    ("0x0040a354", "engine_retarder_override_command_source",
     "The source of the override command: 1 (J1939 override, a TSC1 torque control request) or 6 (no override); 5 "
     "(not set) at power-up (6 in the RAM dump)"),
    ("0x0040a356", "engine_retarder_override_command_percent",
     "The override command: the TSC1 retarder torque request (engine_retarder_torque_request_percent) while TSC1 "
     "torque control is active, else 0"),
    ("0x0040a35c", "engine_retarder_immediate_brake_flag",
     "1 while service_brake_recently_applied_flag is 1 and governor_mode_config_flags bit 0 is set, else 0 (the e2m: "
     "engage the brake without rate limiting); a dword row whose stores are words (stage B splits it)"),
    ("0x0040a360", "service_brake_recently_applied_flag",
     "1 while the brake switch is on and for service_brake_release_delay_passes passes after it is released "
     "(service_brake_release_delay_counter): the e2m's 'service brake pedal has been tapped recently'; the allowed "
     "state needs it (with algorithm_enable_flags_18_cal bit 14) unless cruise asks for the brake"),
    ("0x0040a364", "engine_retarder_engage_inhibit_flag",
     "Holds the output level (cm848_driveEngineRetarderOutput keeps the previous level while it is set): set during a "
     "transmission shift (ETC1 SPN 574) for up to engine_retarder_shift_hold_passes passes. The engine speed "
     "dependent engage delay above it writes the flag, but the shift block clears it first, so that delay has no "
     "effect"),
    ("0x0040a366", "engine_retarder_allowed_state",
     "Which commands may brake (e2m value list 0 NONE / 1 OVERRIDE / 2 OVER_OR_NON): 0 when the brake is not wanted or "
     "an exit condition holds, 1 (override only) while the driver conditions (pedal, clutch, service brake) hold it "
     "off, 2 (override or non-override; the non-override command then restarts at 101 = none)"),
    ("0x0040a368", "engine_retarder_non_override_command_source",
     "The source of the non-override command: 2 cruise permission, 3 operator switch selection, 4 TSC1 limit"),
    ("0x0040a36a", "engine_retarder_non_override_command_percent",
     "The non-override command: restarts at 101 (none) when the allowed state is 2, then is lowered to the cruise "
     "permission, the operator selection and the TSC1 limit, each recording its source"),
    ("0x0040a36c", "engine_retarder_tool_override_control_mode",
     "A service tool test point (e2m 'Test override for Jcomm Retarder Control Mode'; never written in this build): "
     "1 / 2 / 3 force the no-request / torque control / torque limit cases of cm848_applyEngineRetarderTsc1Request. "
     "Not the SPN 695 numbering (there 1 is speed control)"),
    ("0x0040a36e", "engine_retarder_command_tool_override_flag",
     "A service tool test point (e2m 'allows override of EB_Command_Level and E_Brake_Command_Source'; 0 in this "
     "build): while nonzero cm848_selectEngineRetarderCommand leaves the command and its source to the tool"),
    ("0x0040a374", "variable_geometry_turbocharger_brake_active_flag",
     "1 while the output level is at least 50 % for engine_retarder_request_on_delay_passes passes and "
     "engine_retarder_brake_type has the VG brake bit (bit 1): the VGT is used for braking (no reader in this code; "
     "the VGT is not fitted on this truck)"),
    # e2m 1071 (ROM 0x408e9a..)
    ("0x00408ea8", "engine_retarder_maximum_fueling",
     "Above this fueling the brake may not engage, and above it at or below engine_retarder_minimum_road_speed_cal it "
     "exits (outside the low speed and power take-off governors)"),
    ("0x00408eb4", "engine_retarder_cold_oil_temperature",
     "Below this oil temperature the cold-oil engage / disengage engine speeds apply"),
    ("0x00408eb8", "engine_retarder_idle_maximum_fueling",
     "The fueling limit for braking while the low speed governor (idle) has the fueling, plus "
     "fuel_demand_offset_correction"),
    ("0x00408eba", "engine_retarder_power_take_off_maximum_fueling",
     "The fueling limit for braking while the power take-off governor has the fueling, plus "
     "fuel_demand_offset_correction"),
    ("0x00408ebc", "engine_retarder_power_take_off_maximum_reference_speed",
     "The power take-off reference speed at or below which the exhaust brake may run in PTO (the e2m: 'for cab heat')"),
    ("0x00408ebe", "engine_retarder_idle_power_take_off_maximum_coolant_temperature",
     "At idle or in PTO the brake may engage only while the coolant is 5 °F below this (0x140 = 5 x 64), and it exits "
     "above it"),
    ("0x00408ec2", "engine_retarder_brake_type",
     "The brake hardware (e2m value list 0 NONE / 1 EXHAUST / 2 VG / 3 BOTH), tested as bits by "
     "cm848_driveEngineRetarderOutput: bit 0 the exhaust brake (logical output 11), bit 1 the VG brake "
     "(variable_geometry_turbocharger_brake_active_flag); 1 on this truck"),
    ("0x00408ec4", "engine_retarder_dual_brake_maximum_engine_speed",
     "With both brake types the exhaust brake output is cleared above this engine speed"),
    # e2m 1192 (EEPROM)
    ("0x003fd92c", "engine_retarder_minimum_road_speed_cal",
     "The e2m: 'speed above which the engine brake may be engaged'; the code uses it in the exit condition: fueling "
     "above engine_retarder_maximum_fueling at or below this road speed exits"),
    # e2m 117D
    ("0x0040a270", "engine_retarder_command_source",
     "The source of engine_retarder_command_percent (e2m value labels 0 NONE / 1 JCOMMOVD / 2 CRUISE / 3 SWITCH / 4 "
     "JCOMMLMT / 5 NOT_SET / 6 NOOVERDE); the ERC1 builder maps it to SPN 900 by compares"),
    ("0x0040a27c", "engine_retarder_j1939_control_device",
     "The J1939 device of the TSC1 override or limit (e2m 0 NODEVICE / 1 TRANSMIS / 2 ABS / 3 ASR / 4 UNKNOWN): 0 with "
     "no TSC1 request, else engine_retarder_control_device_indicator (e2m 10E6 +2); the ERC1 builder maps it to SPN 900"),
    ("0x0040a2b2", "engine_retarder_output_level_percent",
     "The level the output stage acts on: engine_retarder_command_percent, held while the engage inhibit flag is set "
     "(no rate limit in this build: the 1192 dwell / step records have no reader); 50 % or more engages the outputs; "
     "the ERC1 builder reads it"),
    # no e2m record
    ("0x003fb53c", "engine_retarder_command_percent_previous",
     "engine_retarder_command_percent of the previous pass (written at the end of the allowed state step, before the "
     "selection): the active state step compares the two"),
    ("0x003fb53e", "engine_retarder_command_percent_previous_2",
     "engine_retarder_command_percent two passes back (write-only)"),
    ("0x003fb542", "engine_retarder_output_level_percent_previous",
     "engine_retarder_output_level_percent of the previous pass: a fall to 0 starts the release delay"),
    ("0x003fb54e", "torque_converter_lockup_disengaged_flag",
     "j1939_powertrain_control_state.etc1_spn573_torque_converter_lockup_disengaged_flag, or bit 0 of "
     "transmission_exhaust_brake_flags (the 48RE lockup aid) while algorithm_enable_flags_6_cal bit 2 is set; with "
     "the transmission out of park / neutral it blocks the engine retarder (an exit condition)"),
]
FUNCTIONS = [
    ("0x00041368", "cm848_updateEngineRetarderAllowedState",
     "Sets engine_retarder_allowed_state once per pass from the enter / exit conditions (oil temperature, engine speed, "
     "boost, fueling by governor, the coolant at idle / PTO, the torque converter lockup) and the driver conditions "
     "(pedal, clutch, service_brake_recently_applied_flag): NONE, OVERRIDE_ONLY, or OVERRIDE_OR_NON_OVERRIDE (then "
     "engine_retarder_non_override_command_percent restarts at 101); also engine_retarder_immediate_brake_flag and "
     "the command level of the two previous passes"),
    ("0x00041b24", "cm848_selectEngineRetarderCommand",
     "Sets engine_retarder_command_percent and engine_retarder_command_source: 0 / NONE when the allowed state is "
     "NONE, or OVERRIDE_ONLY without an override; the override command with an override; the non-override command when "
     "the allowed state is OVERRIDE_OR_NON_OVERRIDE without one. Skipped while "
     "engine_retarder_command_tool_override_flag is set"),
]
