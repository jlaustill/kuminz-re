"""Rows 0-12: e2m blocks 106C, 10EA, 1171, 1186, 1199, 11D5, 122A. Keyed by address; `old` comes from the bin."""

ROWS = {}


def rename(address, new, evidence, code_quote, comment):
    ROWS[address] = {"verdict": "confirmed", "new": new, "evidence": evidence, "code_quote": code_quote, "comment": comment}


def keep(address, e2m_note):
    ROWS[address] = {"verdict": "keep", "e2m_note": e2m_note}


# ---- 106C ----
rename(
    "0x0040b6fe",
    "drivetrain_ratio_when_loaded",
    "e2m 106C +A Gear_Ratio_When_Loaded (UNITLESS, 1/2048): cm848_updateDrivetrainRatio commits drivetrain_ratio_user_filtered into it only once the ratio is unchanged since the last pass, the unsettled flag is 0 and final_fueling is above its threshold (in gear at high load), and reseeds it with drivetrain_ratio_default while stopped; the old name said fuel flow rpm divisor, the block's other rows are drivetrain_ratio_*",
    "cm848_updateDrivetrainRatio: fuel_flow_rpm_divisor_saved = drivetrain_ratio_user_filtered;",
    "e2m 106C +A Gear_Ratio_When_Loaded 'Gear Ratio determined when in gear and at high load' (UNITLESS, 1/2048 per count; 32768 in the dump = 16.0, the stopped default): the saved snapshot of drivetrain_ratio_user_filtered. "
    "cm848_updateDrivetrainRatio commits it once the ratio is stable (fuel_flow_rpm_divisor_prev equals drivetrain_ratio_user_filtered, drivetrain_ratio_unsettled_flag is 0 and drivetrain_ratio_save_pending_flag is 1) and final_fueling is above DAT_0005c93e, i.e. in gear at high load; "
    "it is seeded with drivetrain_ratio_default while vehicle_speed is below vehicle_speed_minimum or the engine is stopped.",
)

# ---- 10EA ----
rename(
    "0x00408ed2",
    "low_speed_governor_high_gear_proportional_gain",
    "e2m 10EA +C LSG_High_Gear_Proportional_Gain (MM3S/RPM, signed): first word of the 4-word high gear gain set P / I / D / jerk (61 / 85 / 77 / 0 in the dump); cm848_processGovernorSpeedSetpoint points governor_setpoint_table_requested_ptr at it for mode 3 (overall gear ratio below LSG_Gear_Breakpoint2); the old name said setpoint table and carried _cal in the RAM region; typed byte, but the record and the dump words are signed 16-bit (a 4 x i16 retype is open)",
    "cm848_processGovernorSpeedSetpoint: governor_setpoint_table_requested_ptr = &governor_setpoint_table_mode3_cal;",
    "e2m 10EA +C LSG_High_Gear_Proportional_Gain 'Low speed governor proportional gain when in high gears' (MM3S/RPM 1/2048, signed): first word of the 4-word high gear gain set at 0x408ed2-0x408ed9 (P / I / D / jerk = e2m +C / +E / +10 / +12; 61 / 85 / 77 / 0 in the dump). "
    "cm848_processGovernorSpeedSetpoint selects it (governor_operational_mode_request 3, governor_setpoint_table_requested_ptr = its address) when the overall gear ratio (drivetrain_ratio x rear_axle_ratio >> 11) is below governor_speed_mode_rpm_upper_b_cal minus governor_speed_mode_hysteresis_cal and governor_feature_flags bits 0x4000 and 0x2000 are set; the low speed governor then reads the set through governor_setpoint_table_ptr. "
    "Typed byte: every user takes the address and the e2m record is a signed word (the row is the first word of a 4-word set).",
)
rename(
    "0x00408eda",
    "low_speed_governor_middle_gear_proportional_gain",
    "e2m 10EA +14 LSG_Mid_Gear_Proportional_Gain (MM3S/RPM, signed): first word of the 4-word middle gear gain set P / I / D / jerk (61 / 85 / 77 / 0 in the dump); cm848_processGovernorSpeedSetpoint points governor_setpoint_table_requested_ptr at it for mode 2 (overall gear ratio below LSG_Gear_Breakpoint1); the old name said setpoint table and carried _cal in the RAM region; typed byte, but the record and the dump words are signed 16-bit (a 4 x i16 retype is open)",
    "cm848_processGovernorSpeedSetpoint: governor_setpoint_table_requested_ptr = &governor_setpoint_table_mode2_cal;",
    "e2m 10EA +14 LSG_Mid_Gear_Proportional_Gain 'Low speed governor proportional gain used when in middle gears for in gear stab' (MM3S/RPM 1/2048, signed): first word of the 4-word middle gear gain set at 0x408eda-0x408ee1 (P / I / D / jerk = e2m +14 / +16 / +18 / +1A; 61 / 85 / 77 / 0 in the dump). "
    "cm848_processGovernorSpeedSetpoint selects it (governor_operational_mode_request 2, governor_setpoint_table_requested_ptr = its address) when the overall gear ratio (drivetrain_ratio x rear_axle_ratio >> 11) is below governor_speed_mode_rpm_upper_cal minus governor_speed_mode_hysteresis_cal (governor_feature_flags bit 0x4000 set) and is not in the high gear range; the low speed governor then reads the set through governor_setpoint_table_ptr. "
    "Typed byte: every user takes the address and the e2m record is a signed word (the row is the first word of a 4-word set).",
)

# ---- 1171 ----
rename(
    "0x004071de",
    "remote_throttle_priority",
    "e2m 1171 +0 Remote_Throttle_Calibrated_Priority (HEX, 5 in the dump): with algorithm_enable_flags_18_cal.remote_throttle_enable set, cm848_periodicControlLoopFaultHandling raises fuel_demand_control_t_0040a57a.override_active to at least it and loads override_value; override_active is a per-pass priority that cm848_fuelDemandFinalCalculation applies and clears (the accelerator interlock priority at 0x408de2 holds 9, e2m 1210 Accelerator_Throttle_Priority)",
    "cm848_periodicControlLoopFaultHandling: fuel_demand_control_t_0040a57a.override_active = fuel_demand_override_active_min;",
    "e2m 1171 +0 Remote_Throttle_Calibrated_Priority 'Remote Throttle priority in the alternate throttle selection logic.' (HEX; 5 in the dump): the priority the remote throttle claims. "
    "With algorithm_enable_flags_18_cal.remote_throttle_enable set and its select condition true (switch 31, or the fuel demand rate limit output when reserved_bit_13 is set), cm848_periodicControlLoopFaultHandling raises fuel_demand_control_t_0040a57a.override_active to at least this value and loads override_value (governor_torque_output); "
    "cm848_fuelDemandFinalCalculation then uses override_value as the fuel demand, copies the winning override_active into override_countdown and clears it. The other throttle features use the same field (fuel_demand_override_min_cal = e2m 1210 +0 Accelerator_Throttle_Priority holds 9). ROM-copied cal, no _cal.",
)

# ---- 1186 ----
rename(
    "0x00408dfc",
    "cruise_bottom_droop_offset",
    "e2m 1186 +0 Cruise_RSG_Bottom_Droop_Offset (MM3S, 353 = 24.0 mm3 in the dump): governor_cruise_setpoint_calc applies the bottom droop to the fueling below it, treats the fueling between it and the latched top droop offset as the deadband and uses it as the fueling edge of the gain zones; governorCruiseStateMachine copies it into the cruise and road speed governor bottom droop offsets; the old name said setpoint",
    "governor_cruise_setpoint_calc: wStack_e = (word)(((int)(short)param_1 - (int)(short)governor_cruise_fuel_demand_setpoint) *",
    "e2m 1186 +0 Cruise_RSG_Bottom_Droop_Offset 'CRUISE/RSG BOTTOM DROOP OFFSET.' (MM3S 0.0679 mm3 per count; 353 = 24.0 mm3 in the dump): the fueling below which the bottom droop applies, shared by cruise control and the road speed governor. "
    "governor_cruise_setpoint_calc sets cruise_speed_setpoint_active to 0 (deadband) while the fueling is between it and cruise_speed_offset_latched (the top droop offset), turns the shortfall below it into a speed delta with the bottom droop gain ((fueling - it) x gain >> 10), and uses it plus cruise_zone_fuel_demand_hysteresis as the fueling edge that selects the cruise gain zones; "
    "governorCruiseStateMachine copies it into cruise_control_fueling_bottom_droop_offset and cruise_speed_setpoint_c (the two bottom droop offsets passed on). Read-only working RAM (ROM-copied cal, no _cal).",
)
rename(
    "0x00408e12",
    "cruise_droop_reference_speed",
    "e2m 1186 +16 Cruise_RSG_Droop_Reference_Speed (MPH, 21760 = 85.0 mph in the dump): governorCruiseStateMachine (power-up droop gain setup) subtracts cruise_top_droop_width_cal / road_speed_governor_top_droop_width_cal (e2m 1185 +4 / +8, mph) from it and passes the speed with the rear axle ratio to governor_cruise_rampRate_calc, whose result governor_cruise_tableLimit_calc uses as a table input for the top droop slope; it is a speed, not a fuel demand",
    "governorCruiseStateMachine: (cruise_fuel_demand_ramp_ceiling - cruise_top_droop_width_cal,",
    "e2m 1186 +16 Cruise_RSG_Droop_Reference_Speed 'Reference speed used when calculating CC and RSG upper droops on power-up' (MPH 1/256 per count; 21760 = 85.0 mph in the dump): governorCruiseStateMachine (the power-up droop gain setup) subtracts cruise_top_droop_width_cal and road_speed_governor_top_droop_width_cal (e2m 1185 +4 / +8, mph) from it "
    "and passes that speed with rear_axle_ratio_low_cal / rear_axle_ratio_high_cal to governor_cruise_rampRate_calc, which scales it by top_gear_ratio_cal and the axle ratio into a 16-bit value clamped to 8000..36000 (apparently the engine speed at that road speed in 1/8 rpm, 1000-4500 rpm); governor_cruise_tableLimit_calc takes that value as the x input of the governor_fuel_table_*_cal grid and divides the droop width by the fueling it finds minus cruise_speed_offset_default, "
    "which gives the top droop slopes (cruise_top_droop_gain_for_rear_axle_ratio_low, road_speed_governor_top_droop_gain_for_rear_axle_ratio_low). A speed in mph, not a fuel demand. Read-only ROM-copied cal.",
)
rename(
    "0x00408e14",
    "cruise_droop_speed_error_delta_maximum",
    "e2m 1186 +18 Cruise_RSG_Error_Delta_HL (MPH, 0 in the dump): governor_cruise_setpoint_calc clamps the top droop speed delta to it before storing it in cruise_speed_setpoint_active (= e2m 1187 +C Cruise_RSG_Error_Delta, the amount the speed error is modified to form the droop curves, added to cruise_ramp_target_speed by protectionRampRateControl); the old name read as a limit of a speed setpoint",
    "governor_cruise_setpoint_calc: cruise_speed_setpoint_active = cruise_speed_setpoint_active_max;",
    "e2m 1186 +18 Cruise_RSG_Error_Delta_HL 'High limit for Cruise_RSG_Error_Delta' (MPH 1/256 per count; 0 in the dump, so the droop speed delta cannot rise above 0 here): governor_cruise_setpoint_calc computes the top droop speed delta ((fueling - cruise_speed_offset_latched) x top droop gain >> 10) and clamps it to this ceiling before storing it in cruise_speed_setpoint_active "
    "(e2m 1187 +C Cruise_RSG_Error_Delta, 'amount the cruise/RSG MPH error signal is modified to form the droop curves'; protectionRampRateControl adds it to cruise_ramp_target_speed and subtracts it from the net speed error). Read-only ROM-copied cal.",
)
rename(
    "0x00408e16",
    "cruise_droop_speed_error_delta_minimum",
    "e2m 1186 +1A Cruise_RSG_Error_Delta_LL (MPH, signed, 0 in the dump): governor_cruise_setpoint_calc clamps the bottom droop speed delta to it from below before storing it in cruise_speed_setpoint_active (= e2m 1187 +C Cruise_RSG_Error_Delta); the old name read as a limit of a speed setpoint; type i16 already matches the record",
    "governor_cruise_setpoint_calc: cruise_speed_setpoint_active = cruise_speed_setpoint_active_min;",
    "e2m 1186 +1A Cruise_RSG_Error_Delta_LL 'Low limit for Cruise_RSG_Error_Delta' (MPH 1/256 per count, signed, -128..0; 0 in the dump, so the droop speed delta cannot fall below 0 here): governor_cruise_setpoint_calc computes the bottom droop speed delta ((fueling - cruise_bottom_droop_offset) x bottom droop gain >> 10, negative) and clamps it to this floor before storing it in cruise_speed_setpoint_active "
    "(e2m 1187 +C Cruise_RSG_Error_Delta). Read-only ROM-copied cal. | retyped word -> i16 2026-11-20 (e2m signed, every load lha)",
)
rename(
    "0x00408e2e",
    "cruise_zone_3_speed_error_threshold",
    "e2m 1186 +32 Cruise_RSG_Gain_Thres2 (MPH, 1280 = 5.0 mph in the dump): governor_cruise_setpoint_calc selects gain zone 3 (cruise_zone_3_proportional_gain) when the fueling is at or below the bottom droop offset and the net speed error is below it minus cruise_zone_boundary_hysteresis, and uses it plus the hysteresis in the zone 2 entry test at low fueling; the value is positive so neg limit misdescribes it, and neg is an invented abbreviation",
    "governor_cruise_setpoint_calc: (int)((uint)cruise_zone_speed_error_neg_limit - (uint)cruise_zone_boundary_hysteresis))) {",
    "e2m 1186 +32 Cruise_RSG_Gain_Thres2 'Switch to Cruise/RSG gain set 3 when tracking error is < this calibration' (MPH 1/256 per count, 0..10; 1280 = 5.0 mph in the dump): the signed speed-error threshold of cruise gain zone 3. "
    "governor_cruise_setpoint_calc picks zone 3 (cruise_speed_zone_code 3: cruise_zone_3_proportional_gain and the integral / derivative / acceleration gains, e2m 1186 +2A..+30) when final_fueling is at or below the bottom droop offset (cruise_bottom_droop_offset) and the net speed error is below it minus cruise_zone_boundary_hysteresis; "
    "at low fueling it plus the hysteresis is also the zone 2 entry test (the high fueling counterpart is cruise_zone_speed_error_abs_limit, e2m 1186 +24 Gain_Thres). Read-only ROM-copied cal.",
)

# ---- 1199 ----
rename(
    "0x0040adf2",
    "can_last_message_object_used",
    "e2m 1199 +0 CAN_Last_Msg_Object_Used [SSCNLTOB] (0..15, 15 in the dump): cm848_j1939_system_init takes the J1939 transmit message objects as this + 1 .. this + 15 and stores the end index back; the old name abbreviated allocation and transmit (alloc, tx)",
    "cm848_j1939_system_init: can_tx_mailbox_end_index = can_j1939_tx_mailbox_alloc_index + 0xf;",
    "e2m 1199 +0 CAN_Last_Msg_Object_Used '[SSCNLTOB] CAN's last message object used' (UNITLESS, 0..15; 15 in the dump): the index of the last CAN (TouCAN) message object handed out so far. "
    "cm848_j1939_system_init reads it as the base of the J1939 transmit mailboxes (can_tx_mailbox_start_index = this + 1, can_tx_mailbox_end_index = this + 15) and stores the end index back into it; no other function accesses it. Working RAM, no _cal.",
)

# ---- 11D5 ----
rename(
    "0x003feff2",
    "air_fuel_control_fueling_override_value",
    "e2m 11D5 +0 AFC_Fueling_Override_Value [AFFLMAN] (MM3S, 0 in the dump): cm848_calculateAirFuelControlFuelLimit sets air_fuel_control_fuel_limit to it (and seeds governor_demand_accumulator with it x 50) while algorithm_enable_flags_12_cal.air_fuel_control_override_enable is set; 0x3feff2 is above the EEPROM mirror end 0x3feec1, so the old _cal was wrong, and fuel_demand_load_* is the wrong domain",
    "cm848_calculateAirFuelControlFuelLimit: air_fuel_control_fuel_limit = fuel_demand_load_base_cal;",
    "e2m 11D5 +0 AFC_Fueling_Override_Value '[AFFLMAN] AFC fueling derate value when AFC override is enabled' (MM3S 0.0679 mm3 per count; 0 in the dump): cm848_calculateAirFuelControlFuelLimit (the air fuel control, e2m AFCDERAT, fuel limit) sets air_fuel_control_fuel_limit to it, and seeds governor_demand_accumulator with it x 50, "
    "while algorithm_enable_flags_12_cal.air_fuel_control_override_enable is set; otherwise the limit comes from the engine speed x boost grids. ROM-copied cal at 0x3feff2, above the EEPROM mirror end 0x3feec1, so no _cal.",
)
keep(
    "0x003feff4",
    "e2m 11D5 +2 Ambient_Air_Pressure_Sensor_Present '[AAPRSNST] enable flag that indicates presence of an ambient air pressure sensor'",
)

# ---- 122A ----
keep(
    "0x000645ba",
    "e2m 122A +0 Powerdown_Data_Lost_Error_Limit '[SDDLERLM] Number of consecutive occurances of powerdown data lost to set system error'",
)
