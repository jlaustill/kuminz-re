"""Blocks 1071, 10ED, 10FC, 117E, 11BF (bin records 0-13)."""
ENTRIES = []

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x00408ea8",
    "old": "fuel_demand_computed_min_cal", "new": "engine_retarder_fuel_demand_threshold",
    "evidence": "e2m 1071 +E EB_Max_Fuel_Threshold 'Fueling threshold above which engine brakes may not be enabled': "
                "cm848_updateEngineRetarderEnableState needs final_fueling at or below it to enter (governor states other than "
                "the low speed governor and power take-off) and exits when adjusted_user_fueling is above it; the old name said "
                "computed fuel demand minimum and carried a _cal on a ROM copy",
    "code_quote": "cm848_updateEngineRetarderEnableState: (final_fueling <= fuel_demand_computed_min_cal)) ||",
    "comment": "e2m 1071 +E EB_Max_Fuel_Threshold 'Fueling threshold above which engine brakes may not be enabled' (address from "
               "the ECU's parameter ID table) (MM3S, 0.0679 mm3 per count; 59 = 4.0 mm3 in the dump): the fuel limit of the "
               "engine retarder (exhaust brake). In cm848_updateEngineRetarderEnableState, outside the low speed governor and "
               "power take-off states, the enter condition needs final_fueling at or below it and the exit condition fires "
               "when adjusted_user_fueling is above it with vehicle_speed at or below "
               "engine_retarder_exit_maximum_vehicle_speed_cal; the low speed governor branch also accepts it next to "
               "engine_retarder_fuel_demand_threshold_governor_mode_11 + fuel_demand_offset_correction. "
               "cm848_updateEngineRetarderActiveState resets engine_retarder_fuel_demand_at_minimum_pass_counter while "
               "final_fueling is above it. ROM copy, not EEPROM: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0040ae7c",
    "old": "governor_operational_mode_request", "new": "low_speed_governor_user_gain_state",
    "evidence": "e2m 10ED +6 LSG_User_Gain_State 'IDENTIFIES THE CURRENT LSG PID GAIN SET': the request written by "
                "cm848_processGovernorLoadCondition (1 / 0) and cm848_processGovernorSpeedSetpoint (0 / 2 / 3, only in the low "
                "speed governor state); cm848_updateGovernorSetpointParameters copies it into the final state when no override "
                "applies and loads the four words of the selected gain table into the LSG gain words at e2m 10ED +0 / +2 / +4 / "
                "+14; the old name said operational mode",
    "code_quote": "cm848_updateGovernorSetpointParameters: (governor_operational_mode = governor_operational_mode_request,",
    "comment": "e2m 10ED +6 LSG_User_Gain_State '[LSUSGNST] IDENTIFIES THE CURRENT LSG PID GAIN SET' (address from the ECU's "
               "parameter ID table) (0-7; 0 in the dump): the low speed governor's requested PID gain set. "
               "cm848_processGovernorLoadCondition sets 1 (governor_active_flag, the speed error is beyond its thresholds; table "
               "governor_setpoint_table_cal) or 0; cm848_processGovernorSpeedSetpoint, only while adjusted_user_fueling_state is "
               "FUELING_STATE_LOW_SPEED_GOVERNOR, sets 0 / 2 / 3 from the speed error and the drivetrain ratio window (tables "
               "governor_setpoint_table_mode2_cal / _mode3_cal) and 0 otherwise. cm848_updateGovernorSetpointParameters copies it "
               "into low_speed_governor_final_gain_state (0x40ae7e) when neither override applies (a J1939 TSC1 override or "
               "governor_j1939_mode_override take priority there) and loads the four words of the selected table "
               "(governor_setpoint_table_a for 0) through governor_setpoint_table_ptr into the gain words at e2m 10ED +0 / +2 / +4 "
               "/ +14 (0x40ae76 / 78 / 7a / 8a, the LSG P / I / D / jerk gains; 164 / 164 / 77 in the dump, the same as the FSS "
               "copies at +C / +E / +10). Word, written by sth.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0040ae7e",
    "old": "governor_operational_mode", "new": "low_speed_governor_final_gain_state",
    "evidence": "e2m 10ED +8 LSG_Final_Gain_State 'Indicator of the lsg gain set currently being used': "
                "cm848_updateGovernorSetpointParameters decides it in priority order: cm848_getGovernorOverrideSource sets 4 when "
                "the J1939 TSC1 governor mode is nonzero and governor_feature_flags bit 0x8000 is set; otherwise "
                "cm848_selectGovernorSetpointSource uses governor_j1939_mode_override (e2m +A FSS_LSG_Override_Gain_State) when it "
                "is nonzero; otherwise the user gain state is copied; cm848_calculateGovernorCompensation adds its feed forward "
                "terms only for states other than 0 and 1; the old name said operational mode",
    "code_quote": "cm848_updateGovernorSetpointParameters: (governor_operational_mode = governor_operational_mode_request,",
    "comment": "e2m 10ED +8 LSG_Final_Gain_State '[LSFNGNST] Indicator of the lsg gain set currently being used' (address from the "
               "ECU's parameter ID table) (0-9; 0 in the dump): the low speed governor gain set in use. "
               "cm848_updateGovernorSetpointParameters decides it in this priority order: (1) cm848_getGovernorOverrideSource sets "
               "4 (table at j1939_low_speed_governor_proportional_gain) when the J1939 TSC1 governor mode "
               "(j1939_tsc1_override_state.governor_mode) is nonzero and bit 0x8000 of governor_feature_flags is set; (2) otherwise "
               "cm848_selectGovernorSetpointSource uses governor_j1939_mode_override (0x40ae80, e2m +A FSS_LSG_Override_Gain_State, "
               "table at governor_j1939_speed_target) when that word is nonzero (0 in the dump; the application never writes it "
               "directly); (3) otherwise it copies low_speed_governor_user_gain_state (0x40ae7c). "
               "cm848_calculateGovernorCompensation adds the friction and fuel demand feed forward terms only when it is neither 0 "
               "nor 1. Word, written by sth.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0005c36a",
    "old": "j1939_protocol_mode_speed_cal", "new": "engine_retarder_configuration_reference_torque",
    "evidence": "e2m 10FC +0 Jcomm_Reference_Retarder_Torque (N*m): cm848_buildPgn65249RetarderConfigurationMessage copies it "
                "unscaled into payload bytes 17-18 (0x3fae60 / 61) of the 19 byte PGN 65249 Retarder Configuration message; the "
                "old name said protocol mode speed, with a _cal on a ROM constant",
    "code_quote": "cm848_buildPgn65249RetarderConfigurationMessage: uStack_7 = (undefined1)j1939_protocol_mode_speed_cal;",
    "comment": "e2m 10FC +0 Jcomm_Reference_Retarder_Torque '[JCRFRDTQ] Jcomm Reference Retarder Torque reference ret torque that "
               "corresponds to Jcomm_' (address from the ECU's parameter ID table) (N*m, 1 per count; 350 here): the reference "
               "retarder torque of the engine retarder configuration. cm848_buildPgn65249RetarderConfigurationMessage sends the "
               "word as it is, low byte first, in payload bytes 17-18 (0x3fae60 / 61) of the 19 byte PGN 65249 (Retarder "
               "Configuration) message. ROM constant: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0005c36e",
    "old": "j1939_pgn65249_cal_a", "new": "engine_retarder_configuration_idle_speed",
    "evidence": "e2m 10FC +4 Jcomm_Retarder_Speed_at_Idle (RPM x 8): cm848_buildPgn65249RetarderConfigurationMessage copies it "
                "unscaled into payload bytes 3-4 (0x3fae52 / 53), the speed of point 1 of the retarder torque map in PGN 65249; "
                "the old name was a generic j1939 pgn65249 cal with a _cal on a ROM constant",
    "code_quote": "cm848_buildPgn65249RetarderConfigurationMessage: uStack_7 = (undefined1)j1939_pgn65249_cal_a;",
    "comment": "e2m 10FC +4 Jcomm_Retarder_Speed_at_Idle '[JCRDISRP] Jcomm Retarder Speed at Idle - RPM at idle of retarder config "
               "map' (address from the ECU's parameter ID table) (RPM, 0.125 rpm per count; 8000 = 1000 rpm here): the engine "
               "speed of the idle point of the retarder torque map. cm848_buildPgn65249RetarderConfigurationMessage sends the word "
               "as it is, low byte first, in payload bytes 3-4 (0x3fae52 / 53) of the 19 byte PGN 65249 (Retarder Configuration) "
               "message; its torque is engine_retarder_configuration_idle_torque_percent (e2m +C). ROM constant: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0005c370",
    "old": "j1939_protocol_mode_fuel_cal_b", "new": "engine_retarder_configuration_peak_torque_speed",
    "evidence": "e2m 10FC +6 Jcomm_Retarder_Speed_at_Peak_Torque (RPM x 8): cm848_buildPgn65249RetarderConfigurationMessage "
                "copies it unscaled into payload bytes 15-16 (0x3fae5e / 5f) of PGN 65249; 24000 = 3000 rpm, where the point 5 "
                "torque (e2m +16) is 100 percent; the old name said protocol mode fuel, with a _cal on a ROM constant",
    "code_quote": "cm848_buildPgn65249RetarderConfigurationMessage: uStack_7 = (undefined1)j1939_protocol_mode_fuel_cal_b;",
    "comment": "e2m 10FC +6 Jcomm_Retarder_Speed_at_Peak_Torque '[JCRDPTRP] Jcomm Retarder Speed at Peak Torque - RPM at peak "
               "torque of retarder config ma' (address from the ECU's parameter ID table) (RPM, 0.125 rpm per count; 24000 = 3000 "
               "rpm here): the engine speed at the peak torque point (point 5) of the retarder torque map. "
               "cm848_buildPgn65249RetarderConfigurationMessage sends the word as it is, low byte first, in payload bytes 15-16 "
               "(0x3fae5e / 5f) of the 19 byte PGN 65249 (Retarder Configuration) message; its torque is "
               "engine_retarder_configuration_point_5_torque_percent (e2m +16, 100 percent here). ROM constant: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0005c372",
    "old": "j1939_protocol_mode_fuel_cal_c", "new": "engine_retarder_configuration_point_3_speed",
    "evidence": "e2m 10FC +8 Jcomm_Retarder_Speed_at_Point_3 (RPM x 8): cm848_buildPgn65249RetarderConfigurationMessage copies it "
                "unscaled into payload bytes 9-10 (0x3fae58 / 59) of PGN 65249, point 3 of the retarder torque map; the old name "
                "said protocol mode fuel, with a _cal on a ROM constant",
    "code_quote": "cm848_buildPgn65249RetarderConfigurationMessage: uStack_7 = (undefined1)j1939_protocol_mode_fuel_cal_c;",
    "comment": "e2m 10FC +8 Jcomm_Retarder_Speed_at_Point_3 '[JCRDP3RP] Jcomm Retarder Speed at Pt 3 - RPM at pt 3 of retarder "
               "config map' (address from the ECU's parameter ID table) (RPM, 0.125 rpm per count; 9200 = 1150 rpm here): the "
               "engine speed of point 3 of the retarder torque map. cm848_buildPgn65249RetarderConfigurationMessage sends the word "
               "as it is, low byte first, in payload bytes 9-10 (0x3fae58 / 59) of the 19 byte PGN 65249 (Retarder Configuration) "
               "message; its torque is engine_retarder_configuration_point_3_torque_percent (e2m +10). ROM constant: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0005c374",
    "old": "j1939_protocol_mode_fuel_cal_d", "new": "engine_retarder_configuration_point_4_speed",
    "evidence": "e2m 10FC +A Jcomm_Retarder_Speed_at_Point_4 (RPM x 8): cm848_buildPgn65249RetarderConfigurationMessage copies it "
                "unscaled into payload bytes 12-13 (0x3fae5b / 5c) of PGN 65249, point 4 of the retarder torque map; the old name "
                "said protocol mode fuel, with a _cal on a ROM constant",
    "code_quote": "cm848_buildPgn65249RetarderConfigurationMessage: uStack_7 = (undefined1)j1939_protocol_mode_fuel_cal_d;",
    "comment": "e2m 10FC +A Jcomm_Retarder_Speed_at_Point_4 '[JCRDP4RP] Jcomm Retarder Speed at Pt 4 - RPM at pt 4 of retarder "
               "config map' (address from the ECU's parameter ID table) (RPM, 0.125 rpm per count; 14000 = 1750 rpm here): the "
               "engine speed of point 4 of the retarder torque map. cm848_buildPgn65249RetarderConfigurationMessage sends the word "
               "as it is, low byte first, in payload bytes 12-13 (0x3fae5b / 5c) of the 19 byte PGN 65249 (Retarder "
               "Configuration) message; its torque is engine_retarder_configuration_point_4_torque_percent (e2m +12). ROM "
               "constant: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0005c378",
    "old": "j1939_dtc_spn_cal_a", "new": "engine_retarder_configuration_maximum_speed_torque_percent",
    "evidence": "e2m 10FC +E Jcomm_Retarder_Torque_at_Max_Speed (percent, 1/256 per count): "
                "cm848_buildPgn65249RetarderConfigurationMessage sends 125 minus its high byte (the whole percent) as payload byte "
                "8 (0x3fae57) of PGN 65249, the torque at the maximum retarder speed; 23552 = 92 percent; the old name said dtc "
                "spn, with a _cal on a ROM constant",
    "code_quote": "cm848_buildPgn65249RetarderConfigurationMessage: DAT_003fae57 = '}' - (char)(j1939_dtc_spn_cal_a >> 8);",
    "comment": "e2m 10FC +E Jcomm_Retarder_Torque_at_Max_Speed '[JCRDMSTQ] Jcomm Retarder Torque at Max Speed available torque that "
               "retarder can provide a' (address from the ECU's parameter ID table) (percent, 1/256 percent per count; 23552 = 92 "
               "percent here): the retarder torque at the maximum retarder speed (the speed is e2m +14, "
               "Jcomm_Maximum_Retarder_Speed). cm848_buildPgn65249RetarderConfigurationMessage sends 125 minus the word's high byte "
               "(the whole percent, J1939 percent torque offset 125) as payload byte 8 (0x3fae57) of the 19 byte PGN 65249 "
               "(Retarder Configuration) message. ROM constant: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0005c37a",
    "old": "j1939_dtc_spn_cal_b", "new": "engine_retarder_configuration_point_3_torque_percent",
    "evidence": "e2m 10FC +10 Jcomm_Retarder_Torque_at_Point_3 (percent, 1/256 per count): "
                "cm848_buildPgn65249RetarderConfigurationMessage sends 125 minus its high byte as payload byte 11 (0x3fae5a) of "
                "PGN 65249, the torque of point 3; 16640 = 65 percent; the old name said dtc spn, with a _cal on a ROM constant",
    "code_quote": "cm848_buildPgn65249RetarderConfigurationMessage: DAT_003fae5a = '}' - (char)(j1939_dtc_spn_cal_b >> 8);",
    "comment": "e2m 10FC +10 Jcomm_Retarder_Torque_at_Point_3 '[JCRDP3TQ] Jcomm Retarder Torque at Pt 3 available torque that "
               "retarder can provide at p' (address from the ECU's parameter ID table) (percent, 1/256 percent per count; 16640 = "
               "65 percent here): the retarder torque at point 3 of the retarder torque map (speed: "
               "engine_retarder_configuration_point_3_speed, e2m +8). cm848_buildPgn65249RetarderConfigurationMessage sends 125 "
               "minus the word's high byte (the whole percent) as payload byte 11 (0x3fae5a) of the 19 byte PGN 65249 (Retarder "
               "Configuration) message. ROM constant: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0005c37c",
    "old": "j1939_dtc_spn_cal_c", "new": "engine_retarder_configuration_point_4_torque_percent",
    "evidence": "e2m 10FC +12 Jcomm_Retarder_Torque_at_Point_4 (percent, 1/256 per count): "
                "cm848_buildPgn65249RetarderConfigurationMessage sends 125 minus its high byte as payload byte 14 (0x3fae5d) of "
                "PGN 65249, the torque of point 4; 21504 = 84 percent; the old name said dtc spn, with a _cal on a ROM constant",
    "code_quote": "cm848_buildPgn65249RetarderConfigurationMessage: DAT_003fae5d = '}' - (char)(j1939_dtc_spn_cal_c >> 8);",
    "comment": "e2m 10FC +12 Jcomm_Retarder_Torque_at_Point_4 '[JCRDP4TQ] Jcomm Retarder Torque at Pt 4 available torque that "
               "retarder can provide at p' (address from the ECU's parameter ID table) (percent, 1/256 percent per count; 21504 = "
               "84 percent here): the retarder torque at point 4 of the retarder torque map (speed: "
               "engine_retarder_configuration_point_4_speed, e2m +A). cm848_buildPgn65249RetarderConfigurationMessage sends 125 "
               "minus the word's high byte (the whole percent) as payload byte 14 (0x3fae5d) of the 19 byte PGN 65249 (Retarder "
               "Configuration) message. ROM constant: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0005c380",
    "old": "j1939_dtc_spn_cal_d", "new": "engine_retarder_configuration_point_5_torque_percent",
    "evidence": "e2m 10FC +16 Jcomm_Retarder_Torque_at_Point_5 (percent, 1/256 per count): "
                "cm848_buildPgn65249RetarderConfigurationMessage sends 125 minus its high byte as the last payload byte 19 "
                "(0x3fae62) of PGN 65249, the torque of point 5, the peak torque point whose speed is e2m +6; 25600 = 100 "
                "percent; the old name said dtc spn, with a _cal on a ROM constant",
    "code_quote": "cm848_buildPgn65249RetarderConfigurationMessage: DAT_003fae62 = '}' - (char)(j1939_dtc_spn_cal_d >> 8);",
    "comment": "e2m 10FC +16 Jcomm_Retarder_Torque_at_Point_5 '[JCRDP5TQ] Available torque that retarder can provide at pt 5' "
               "(address from the ECU's parameter ID table) (percent, 1/256 percent per count; 25600 = 100 percent here): the "
               "retarder torque at point 5 of the retarder torque map, the peak torque point (speed: "
               "engine_retarder_configuration_peak_torque_speed, e2m +6, 3000 rpm). "
               "cm848_buildPgn65249RetarderConfigurationMessage sends 125 minus the word's high byte (the whole percent) as the "
               "last payload byte 19 (0x3fae62) of the 19 byte PGN 65249 (Retarder Configuration) message. ROM constant: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "keep", "address": "0x0005c28c",
    "old": "switch_31_on_time_fault_enable", "new": "switch_31_on_time_fault_enable",
    "e2m_note": "e2m 117E +2 Inc_Dec_Separate_Switch_Select 'Indicates sep. inc/dec sw.(TRUE) or inc/dec from multi-purp. "
                "sw.(FALSE)' (0 in the dump = inc/dec from the multi-purpose switch; in this build the code reads it as the "
                "enable of the switch 31 handling and its on-time fault, which has no DTC slot; the neighbour +0 "
                "Cruise_Min_Road_Speed = cruise_speed_low_limit, 7680 = 30 mph, matches the cruise code)",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x003fddac",
    "old": "protection_mode_80_enable_flag",
    "new": "idle_validation_switch_state_at_throttle_validation_process_error_cal",
    "evidence": "e2m 11BF +0 Industrial_Idle_Switch_Save_State 'IVS switch status when Throttle_Validation_Process_Error became "
                "active': cm848_fuelDemandSmoothingController stores switch 7 (accelerator at idle, switch_input_state_bits[0] "
                "bit 0x80) in the block that sets fault 63 (P2121, 0x8000 of fault_detected_bits_48_to_63, the e2m ADTHPDER "
                "process error); write-only EEPROM mirror word (EEPROM 0x92a) so _cal; the old name said protection mode 80 "
                "enable flag",
    "code_quote": "cm848_fuelDemandSmoothingController: protection_mode_80_enable_flag = (word)((switch_input_state_bits[0] & 0x80) != 0);",
    "comment": "e2m 11BF +0 Industrial_Idle_Switch_Save_State '[CTIVSWSS] IVS switch status when "
               "Throttle_Validation_Process_Error became active' (address from the ECU's parameter ID table) (EEPROM 0x92a; 0 in "
               "the dump): the idle validation switch (IVS) state saved when the throttle validation process error is set "
               "(e2m ADTHPDER 'Error set when throttle pot does not agree with throttle switches'). In "
               "cm848_fuelDemandSmoothingController, when fuel_demand_control_t.idle_validation_state stays 2 or 3 (a switch "
               "contradicts the pedal band) past its debounce, it sets fault 63 (P2121, bit 0x8000 of "
               "fault_detected_bits_48_to_63) and stores switch 7 (accelerator at idle, switch_input_state_bits[0] & 0x80) here as "
               "0 / 1. xref_addr.py finds this one store and no read; EEPROM mirror, so _cal.",
})
