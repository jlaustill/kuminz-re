"""Round 13 stage C (label-only): the record-anchored pieces of the low speed and all-speed governor reference speeds.
- DRB SCI 0x19 'SET RPM' / 'SET_ENG_RPM' (19-7D 'SET ECM RPM 1000' = 125 x 8): cm848_sciCommand25Callback stores the
  byte x 64 (1/8 rpm) with a 0xe5c1 key and a 72-pass timeout; the LSG target selection uses it as a speed floor.
- e2m block 0008, checked in the RAM and EEPROM dumps (11.46 keeps the 11.45 offsets here): +2 LSG_Breakpoint_Speed
  (6000 = 750 rpm, the dump's idle reference), +20 / +22 ASG_Minimum / _Maximum (740 / 4650 rpm, below the LSG base and
  above the 3200 rpm HSG breakpoint), +2E / +30 the set 2 copies. cm848_blendGovernorTuningSets blends set 1 and set 2
  into the two reference speeds that cm848_calculateAllSpeedGovernorThrottleReference spans from 0 % to 100 % throttle;
  the old names called the minimum 'high' and the maximum 'low'. Set 3 (+3C / +3E) has no reader."""
GLOBALS = [
    ("0x0040aed0", "sci_set_engine_speed_request",
     "Word (1/8 rpm): the engine speed of the service tool's SCI command 0x19 (DRB 'SET RPM', 19-7D 'SET ECM RPM "
     "1000' = 125 x 8): cm848_sciCommand25Callback stores the request byte x 64. With sci_set_engine_speed_request_key "
     "0xe5c1 and the engine idling in park or neutral (low speed governor in control, brake switch and switch 2 off, "
     "accelerator at idle, vehicle stopped) the LSG target selection takes it as low_speed_governor_service_speed_floor"),
    ("0x0040aecc", "sci_set_engine_speed_request_key",
     "Word: 0xe5c1 while sci_set_engine_speed_request is valid - cm848_sciCommand25Callback sets it with each "
     "request, cm848_expireSciSetEngineSpeedRequest clears it when sci_set_engine_speed_request_timeout_count runs out"),
    ("0x003fcf5e", "sci_set_engine_speed_request_timeout_count",
     "Word: 72 passes from each SCI command 0x19 request; at 0 cm848_expireSciSetEngineSpeedRequest clears the "
     "request and its key, so the tool must keep repeating it"),
    ("0x0040aece", "low_speed_governor_service_speed_floor",
     "Word (1/8 rpm): the service tool speed floor of the LSG target selection (cm848_calculateProtectionSpeedLimits, "
     "source code 11): sci_set_engine_speed_request under its conditions, high_pressure_safety_valve_test_engine_speed"
     "_setpoint while the high pressure safety valve test runs, else 0"),
    ("0x003fdcf6", "low_speed_governor_base_reference_speed_cal",
     "EEPROM 0x874 (1/8 rpm; 6000 = 750 rpm in the RAM and EEPROM dumps): the LSG base reference speed - the target "
     "the LSG target selection starts from (source code 5), the J1939 engine configuration's idle point, and the "
     "speed the fuel pressure governor demand checks compare with"),
    ("0x003fdd14", "all_speed_governor_minimum_reference_speed_1_cal",
     "EEPROM 0x892 (5920 = 740 rpm in the dumps): set 1 of the all-speed governor's 0 % throttle reference speed; "
     "cm848_blendGovernorTuningSets blends it with all_speed_governor_minimum_reference_speed_2_cal"),
    ("0x003fdd16", "all_speed_governor_maximum_reference_speed_1_cal",
     "EEPROM 0x894 (37200 = 4650 rpm in the dumps): set 1 of the all-speed governor's 100 % throttle reference speed"),
    ("0x003fdd22", "all_speed_governor_minimum_reference_speed_2_cal",
     "EEPROM 0x8a0 (5920 = 740 rpm): set 2 of the 0 % throttle reference speed (the alternate droop selection)"),
    ("0x003fdd24", "all_speed_governor_maximum_reference_speed_2_cal",
     "EEPROM 0x8a2 (37200 = 4650 rpm): set 2 of the 100 % throttle reference speed"),
    ("0x0040af80", "all_speed_governor_minimum_reference_speed",
     "Word (1/8 rpm): the 0 % throttle reference speed of the all-speed governor - cm848_blendGovernorTuningSets "
     "blends the set 1 and set 2 values by governor_tuning_set_blend_weight; cm848_calculateAllSpeedGovernorThrottle"
     "Reference starts its throttle span here (unless governor_speed_lower_limit_enable_flag puts the LSG target "
     "minus an offset there)"),
    ("0x0040af7e", "all_speed_governor_maximum_reference_speed",
     "Word (1/8 rpm): the 100 % throttle reference speed of the all-speed governor, blended the same way; the "
     "throttle span ends here"),
]
FUNCTIONS = [
    ("0x00520684", "cm848_expireSciSetEngineSpeedRequest",
     "Counts down sci_set_engine_speed_request_timeout_count; at 0 it clears sci_set_engine_speed_request and its key, "
     "ending the service tool's SCI command 0x19 'SET RPM' request"),
    ("0x0002bf6c", "cm848_blendAllSpeedGovernorReferenceSpeeds",
     "Blends the all-speed governor's 0 % / 100 % throttle reference speeds (e2m ASG_Minimum / ASG_Maximum, sets 1 and "
     "2) into all_speed_governor_minimum_reference_speed / _maximum_reference_speed. The weight "
     "governor_tuning_set_blend_weight (0 = set 1, 128 = set 2) comes from drivetrain_ratio through the six-entry "
     "tables at ROM 0x5a9c4 / 0x5a9d2 (all 128 in this ROM), or from governor_tuning_set_default_blend_weight_cal (e2m "
     "1387 +8 ASG_Droop_Flag_Trim 'select droop source') when governor_system_config_flags bit 0x08 is set. It runs "
     "only when the computed fuel demand is 0 and the final fueling is below the friction fuel plus a deadband, or at "
     "the high idle override reset"),
]
