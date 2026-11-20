"""Wave 14 globals4: items 27-62 of the bin (spec part B)."""

B = []


def rename(address, old, new, quote, evidence, comment, **extra):
    d = {"kind": "global", "verdict": "confirmed", "address": address, "old": old, "new": new,
         "evidence": evidence, "code_quote": quote, "comment": comment}
    d.update(extra)
    B.append(d)


# 27 -------------------------------------------------------------------------------------------------------------
rename(
    "0x003fddba", "diag_dm1_fill_mode_config", "data_collector_stop_mode_cal",
    "if (diag_dm1_fill_mode_config == 3) {",
    "cm848_phase_groupB_calculation (the data collector pass) tests ==1 (end = start + count x bytes / 2 - 1) and ==2 "
    "(end = buffer end) once the trigger fired, anything else stops at once; diag_dm1Buffer_circularFill stops when the "
    "write pointer catches the start pointer in mode 3 (data_collector_status 2) and j1939_dm1_diagnosticMessage_send sends "
    "the buffer only in mode 3; EEPROM mirror (0x3fddba - 0x3fd482 = EEPROM 0x938) so _cal; e2m 0030 +4 Collector_Stop_Mode "
    "'data collector stop flag' (e2m range 0-2, the code tests 1-3).",
    "EEPROM 0x938 - e2m 0030 +4 Collector_Stop_Mode 'data collector stop flag' (UNITLESS, signed, 2 B; the e2m range is 0-2 "
    "but the code tests 1, 2 and 3; 0 in the dump): data collector stop mode. After the trigger, 1 records half a buffer "
    "more and 2 records to the buffer end (cm848_phase_groupB_calculation); in mode 3 the circular fill stops when it "
    "catches its start (collector status 2) and only then does j1939_dm1_diagnosticMessage_send send the buffer by "
    "transport protocol; any other value stops at once. Never written by the application. Not a DM1 fill mode.",
    old_comment_wrong=True)

# 28 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b6f6", "fuel_flow_rpm_divisor", "drivetrain_ratio_user_filtered",
    "fuel_flow_rpm_divisor = drivetrain_ratio;",
    "protectionTimeoutControl copies drivetrain_ratio into it only while the ratio is inside its window "
    "(drivetrain_ratio_minimum_limit < raw < DAT_0005c932, within the filter and fraction tolerances) and keeps it "
    "otherwise; reset to drivetrain_ratio_default below vehicle_speed_minimum or with the engine stopped; read by "
    "cm848_loadHighSpeedGovernorWorkingGainSet, cm848_calculateRiseLimitedVehicleSpeed and governor_cruise_setpoint_calc "
    "as the gear ratio; e2m 106C +2 User_Filtered_Gear_Ratio 'MAY BE FROZEN UPON GEAR SHIFT', 2 B, 1/2048 per count.",
    "e2m 106C +2 User_Filtered_Gear_Ratio 'FILTERED GEAR RATIO USED BY THE SYSTEM -MAY BE FROZEN UPON GEAR SHIFT' "
    "(UNITLESS, 1/2048 per count; 32768 in the dump = 16.0, the stopped default): the filtered drivetrain ratio the other "
    "code reads. protectionTimeoutControl copies the filtered ratio into it only while the ratio is inside its tolerance "
    "window and keeps it otherwise (frozen during a shift); below the minimum vehicle speed or with the engine stopped it "
    "is drivetrain_ratio_default. A drivetrain ratio, not a fuel flow divisor.")

# 29 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b6f8", "fuel_flow_divisor_invalid_flag", "drivetrain_ratio_out_of_gear_cruise_disable_flag",
    "fuel_flow_divisor_invalid_flag = 1;",
    "protectionTimeoutControl writes 0 while the ratio is inside its window and 1 when it is outside (and reloads "
    "drivetrain_ratio_change_settle_counter); etcTransmissionModeControl writes j1939_tsc1_override_state."
    "etc1_disable_control; three sth writes (-18696(r12) at 0x5260ec / 0x52613c / 0x526558) and no load anywhere; "
    "e2m 106C +4 Out_Of_Gear_Cruise_Disable_Flag 'Flag that can be used to disable cruise when out of gear.', 2 B.",
    "e2m 106C +4 Out_Of_Gear_Cruise_Disable_Flag 'Flag that can be used to disable cruise when out of gear.' (UNITLESS, "
    "0 / 1; 0 in the dump): 1 while the drivetrain ratio is outside its tolerance window (shift, clutch in or out of "
    "gear), 0 while it is inside; protectionTimeoutControl writes it and etcTransmissionModeControl sets it from "
    "j1939_tsc1_override_state.etc1_disable_control. Only written in this build: no decompiled reader.")

# 30 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a1aa", "governor_demand_rate_limited", "all_speed_governor_derivative_term",
    "governor_demand_rate_limited = wStack_2e - governor_demand_rate_limit_window;",
    "cm848_runOperatingModeSpeedGovernor: wStack_2e = (QD adjustment + error difference x fuel_demand_pid_coeffs[+8] / 4 - feedback "
    "difference x fuel_demand_pid_coeffs[+10] / 4) >> 11 clamped +-0x7fff, then cut by the dead window governor_demand_rate_limit_window "
    "and limited by governor_demand_rate_limit_max into this word, which times droop gain 2 feeds state X4; e2m 107C +0 "
    "ASG_Derivative_Term '[ASDV]', 2 B signed (row typed word; read through (short) casts, i16 would fit).",
    "e2m 107C +0 ASG_Derivative_Term '[ASDV] ASG derivative term' (MM3S, 0.0679 per count, signed; 0 in the dump): the "
    "derivative term of the all-speed governor PID in cm848_runOperatingModeSpeedGovernor: (the derivative adjustment + "
    "error difference x coefficient 8 / 4 - feedback difference x coefficient 10 / 4) >> 11, clamped +-0x7fff, then cut by "
    "the dead window governor_demand_rate_limit_window and the limit governor_demand_rate_limit_max; scaled by droop gain 2 "
    "it feeds state X4.")

# 31 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a1b8", "governor_pid_integral_saved", "all_speed_governor_state_integral",
    "governor_pid_integral_saved = governor_pid_integral_state._0_2_;",
    "cm848_runOperatingModeSpeedGovernor copies the high word of the 32-bit integrator governor_pid_integral_state "
    "(0x3fa0e8) here every pass (one sth, no reader); a reset seeds that high word from "
    "all_speed_governor_reset_state_integral (e2m 1170 +2 ASG_Reset_State_X2), the same state X2; wave 13 gave the X1 / X6 "
    "twins all_speed_governor_state_speed_error / _fuel_demand_correction and the reset twins the same suffixes; e2m 107C "
    "+E ASG_State_X2 '[ASSTX2]', 2 B signed.",
    "e2m 107C +E ASG_State_X2 '[ASSTX2] ASG state X2' (MM3S, 0.0679 per count, signed; -116 in the dump = -7.88 mm3): "
    "state 2 of the all-speed governor, the integrator: cm848_runOperatingModeSpeedGovernor copies the high word of the "
    "32-bit integrator governor_pid_integral_state (0x3fa0e8) here every pass (write-only copy); a reset seeds that "
    "integrator from all_speed_governor_reset_state_integral (e2m 1170 +2 ASG_Reset_State_X2).")

# 32 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a1ba", "governor_pid_integral_clamp_value", "all_speed_governor_state_pid_clamp_value",
    "governor_pid_integral_clamp_value = 0x1700;",
    "cm848_runOperatingModeSpeedGovernor: = clamp((governor_demand_rate_limited x all_speed_governor_droop_gain_2 >> 10) "
    "+ (previous value x governor_pid_derivative_gain >> 10), +-0x1700) (the 0x1700 / 0xe900 stores); the previous value "
    "is seeded from all_speed_governor_reset_state_pid_clamp_value (e2m 1170 +6 ASG_Reset_State_X4); X5 adds the "
    "integrator high word to it; e2m 107C +10 ASG_State_X4, 2 B signed (i16 would fit).",
    "e2m 107C +10 ASG_State_X4 '[ASSTX4] ASG state X4' (MM3S, 0.0679 per count, signed; 0 in the dump): state 4 of the "
    "all-speed governor, the clamped derivative output: cm848_runOperatingModeSpeedGovernor stores (derivative term x "
    "droop gain 2 >> 10) + (its previous value x the derivative gain >> 10) limited to +-0x1700; X5 adds the integrator "
    "to it; a reset seeds the previous value from all_speed_governor_reset_state_pid_clamp_value (e2m 1170 +6).")

# 33 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a1bc", "governor_pid_integral_clamped", "all_speed_governor_state_pid_integral_clamped",
    "if ((short)governor_pid_integral_clamped < -0x16ff) {",
    "cm848_runOperatingModeSpeedGovernor: = integrator high word + governor_pid_integral_clamp_value limited to "
    "+-0x1700 (the -0x16ff / 0x1700 compares); state X6 = (X5 x coefficient 12 - previous X5 x coefficient 14 + X6 x "
    "coefficient 16) >> 8; the previous X5 is seeded from all_speed_governor_reset_state_pid_integral_clamped (e2m 1170 +8 "
    "ASG_Reset_State_X5); e2m 107C +12 ASG_State_X5 '[ASSTX5]', 2 B signed (i16 would fit).",
    "e2m 107C +12 ASG_State_X5 '[ASSTX5] ASG state X5' (MM3S, 0.0679 per count, signed; -116 in the dump = -7.88 mm3): "
    "state 5 of the all-speed governor, the integrator plus the clamped derivative state X4 limited to +-0x1700; the fuel "
    "correction state X6 filters it ((x5 x gain - previous x5 x gain + x6 x gain) >> 8); a reset seeds the previous value "
    "from all_speed_governor_reset_state_pid_integral_clamped (e2m 1170 +8).")

# 34 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a1c4", "governor_demand_filter_accumulator", "all_speed_governor_derivative_adjustment",
    "iVar16 = (int)(governor_demand_filter_accumulator +",
    "cm848_runOperatingModeSpeedGovernor: (this + error difference x coefficient 8 / 4 - feedback difference x coefficient "
    "10 / 4) >> 11 is the derivative term before its limits; the only store is the zero in cm848_initFuelDemandVariables "
    "(lwz / stw, 4 B = row = e2m); twins at +22 / +2A (0x40a1cc / 0x40a1d4, fuel_demand_pid_accum_hi / _lo) are the "
    "QI / QP adjustments of the proportional-integral sum; e2m 107C +1A ASG_QD_Adjustment '[ASQDAJ]'.",
    "e2m 107C +1A ASG_QD_Adjustment '[ASQDAJ] ASG Quadratic Derivative Adjustment' (MM3S, 4 B, 0.0000332 per count, "
    "signed; 0 in the dump): the QD adjustment added to the derivative difference equation of "
    "cm848_runOperatingModeSpeedGovernor, (adjustment + error difference x coefficient 8 / 4 - feedback difference x "
    "coefficient 10 / 4) >> 11; the only store is the zero in cm848_initFuelDemandVariables, so it stays 0. Not a fuel "
    "timing blend or filter accumulator.")

# 35 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040ad90", "j1939_engine_torque_output_b", "j1939_nominal_friction_percent_torque_times_256",
    "j1939_eec3_nominal_friction_percent_torque = (char)(j1939_engine_torque_output_b >> 8) + 0x7d;",
    "cm848_calculateNominalFrictionPercentTorque (plate: SPN 514): = (fuel_demand_base_offset - fuel_demand_norm_zero_cal) "
    "x 25600 / (j1939_reference_engine_fueling - zero) clamped at 32000 (125 percent x 256); "
    "cm848_buildPgn65247ElectronicEngineController3Message stores its high byte + 125 (0x7d) as the EEC3 nominal friction "
    "percent torque; e2m 1102 +6 Jcomm_Ind_Friction_Torque, 2 B.",
    "e2m 1102 +6 Jcomm_Ind_Friction_Torque '[JCINFCTQ] Jcomm Ind Friction Torque amount of torque required by base engine' "
    "(%, 1/256 percent, 0-125): the nominal friction percent torque x 256 = (fuel_demand_base_offset - zero) x 100 x 256 "
    "/ (j1939_reference_engine_fueling - zero), clamped at 125 percent (cm848_calculateNominalFrictionPercentTorque, "
    "plate: SPN 514); cm848_buildPgn65247ElectronicEngineController3Message sends its high byte + 125 in EEC3 byte 1. "
    "Not an engine torque output.")

# 36 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040ada0", "governor_integrator_rpm_output_cached", "j1939_determined_engine_speed_at_point_1",
    "governor_integrator_rpm_output_cached = governor_integrator_rpm_output;",
    "cm848_updateProtectionStateMachine ends by snapshotting the torque curve speed at point 1 into this word next to "
    "j1939_determined_engine_speed_at_point_2 / _4 / _5 and the point 3 snapshot (0x40ada2); faultTimerHandler packs it "
    "into the 28-byte payload sent by cm848_sendFaultTimerMessage with header 0xfee300 = PGN 65251 (set in "
    "initFaultTimerMessage); e2m 1102 +16 Jcomm_Determined_RPM_Point_1, 2 B.",
    "e2m 1102 +16 Jcomm_Determined_RPM_Point_1 '[JCEVRPP1] Jcomm determined RPM at engine configuration idle speed.' (RPM, "
    "0.125 per count; 0 in the dump): the engine configuration speed at point 1 (idle) for PGN 65251: "
    "cm848_updateProtectionStateMachine copies the torque curve speed at point 1 into it with the other determined speeds, "
    "and faultTimerHandler packs it into the 28-byte message (transmit header 0xfee300). Not an integrator output.")

# 37 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040ada2", "protection_threshold_rpm_cached", "j1939_determined_engine_speed_at_point_3",
    "protection_threshold_rpm_cached = protection_threshold_lookup_rpm;",
    "cm848_updateProtectionStateMachine copies the torque curve speed at point 3 into it (the e2m's 'determined' speeds "
    "are the snapshots of the curve speeds); faultTimerHandler packs it into the PGN 65251 payload (header 0xfee300 in "
    "initFaultTimerMessage); e2m 1102 +18 Jcomm_Determined_RPM_Point_3, 2 B.",
    "e2m 1102 +18 Jcomm_Determined_RPM_Point_3 '[JCEVRPP3] Jcomm determine rpm at engine configuration point 3.' (RPM, "
    "0.125 per count; 0 in the dump): the engine configuration speed at point 3 for PGN 65251: snapshot of the torque curve "
    "speed at point 3 taken at the end of cm848_updateProtectionStateMachine and packed into the 28-byte message by "
    "faultTimerHandler (transmit header 0xfee300). Not a protection threshold.")

# 38 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040adac", "governor_integrator_rpm_output", "j1939_torque_curve_speed_at_point_1",
    "governor_integrator_rpm_output = governor_output_t_0040aec2.idle_reference_speed;",
    "cm848_updateProtectionParameters: = governor_output_t_0040aec2.idle_reference_speed (less a droop correction when "
    "algorithm_enable_flags_12_cal.low_speed_governor_droop_enable and the correction term are set); "
    "cm848_calculateChiMaximumFuelAtSpeedPoints looks up the chi maximum fuel at it as point 1 next to "
    "j1939_torque_curve_speed_at_point_2 / _4 / _5, and cm848_updateProtectionDiagnostics the reference fueling; e2m 1102 "
    "+22 Jcomm_RPM_At_Point_1, 2 B.",
    "e2m 1102 +22 Jcomm_RPM_At_Point_1 '[JCTQRPP1] Torque curve speed at breakpoint 1 (LSG Reference).' (RPM, 0.125 per "
    "count; 6000 in the dump = 750 rpm): the speed of torque curve point 1, the low speed governor idle reference "
    "(governor_output_t_0040aec2.idle_reference_speed, less a droop correction with "
    "algorithm_enable_flags_12_cal.low_speed_governor_droop_enable): written by cm848_updateProtectionParameters, read by "
    "the point 1 fuel and torque lookups. Not an integrator output.")

# 39 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040adb0", "protection_threshold_lookup_rpm", "j1939_torque_curve_speed_at_point_3",
    "protection_threshold_lookup_rpm = j1939_engine_speed_at_point_3;",
    "cm848_updateProtectionStateMachine / cm848_updateProtectionInputs: = j1939_engine_speed_at_point_3 (ROM, e2m 1104 +4 "
    "Jcomm_Engine_Speed_at_Point_3) or the point 1 speed when that is higher (with the point 1 fueling); the matching "
    "fueling is j1939_torque_curve_fueling_at_point_3; cm848_calculateChiMaximumFuelAtSpeedPoints uses it as point 3; e2m "
    "1102 +26 Jcomm_RPM_At_Point_3, 2 B.",
    "e2m 1102 +26 Jcomm_RPM_At_Point_3 '[JCTQRPP3] Torque curve speed at breakpoint 3.' (RPM, 0.125 per count; 11200 in the "
    "dump = 1400 rpm): the speed of torque curve point 3: cm848_updateProtectionStateMachine and "
    "cm848_updateProtectionInputs load it from j1939_engine_speed_at_point_3 (e2m 1104 +4), or from the point 1 speed when "
    "that is higher; read by the point 3 fuel and torque lookups. Not a protection threshold.")

# 40 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040adb6", "protection_cal_level1_working", "j1939_torque_curve_fueling_at_point_1",
    "protection_cal_level1_working = j1939_derated_fueling_at_idle;",
    "cm848_updateProtectionParameters loads j1939_derated_fueling_at_idle; j1939_torque_curve_fueling_at_point_3 copies it "
    "when the point 1 speed is the higher; cm848_updateProtectionStateMachine divides (it - fuel_demand_norm_zero_cal) x "
    "25600 by the point 1 reference fueling for the idle percent torque, snapshots it to the calculated fueling (0x40adc0) "
    "and resets it to fuel_demand_maximum; e2m 1102 +2C Jcomm_Fueling_At_Point_1, 2 B.",
    "e2m 1102 +2C Jcomm_Fueling_At_Point_1 '[JCTQFLP1] Torque curve fueling at idle speed breakpoint.' (MM3S, 0.0679 per "
    "count; 0 in the dump): the fueling of torque curve point 1: cm848_updateProtectionParameters loads "
    "j1939_derated_fueling_at_idle, cm848_updateProtectionStateMachine divides it by the point 1 reference fueling for the "
    "idle percent torque, copies it to the calculated-fueling snapshot (0x40adc0) and resets it to fuel_demand_maximum. Not "
    "a protection calibration level.")

# 41-45 ------------------------------------------------------------------------------------------------------------
for n, (address, old, source, off, desc) in enumerate([
        ("0x0040adc0", "protection_cal_level1_cached", "protection_cal_level1_working", "36",
         "Calculated value of Jcomm_Fueling_At_Point_1 before reseting to Maximum_Fueling"),
        ("0x0040adc2", "protection_cal_numerator_b_cached", "j1939_torque_curve_fueling_at_point_2", "38",
         "Calculated value of Jcomm_Fueling_At_Point_2 before reseting to Maximum_Fueling"),
        ("0x0040adc4", "protection_cal_numerator_c_cached", "j1939_torque_curve_fueling_at_point_3", "3A",
         "Calculated value of Jcomm_Fueling_At_Point_3 before reseting to Maximum_Fueling"),
        ("0x0040adc6", "protection_output_cal_cached", "j1939_torque_curve_fueling_at_point_4", "3C",
         "Calculated value of Jcomm_Fueling_At_Point_4 before reseting to Maximum_Fueling"),
        ("0x0040adc8", "protection_derate_numerator_cached", "j1939_torque_curve_fueling_at_point_5", "3E",
         "Calculated value of Jcomm_Fueling_At_Point_5 before reseting to Maximum_Fueling")], start=1):
    new = f"j1939_torque_curve_calculated_fueling_at_point_{n}"
    rename(
        address, old, new, f"{old} = {source};",
        f"cm848_updateProtectionStateMachine copies the point {n} torque curve fueling here at its end, just before "
        f"resetting the working fueling to fuel_demand_maximum (one sth, no reader); e2m 1102 +{off} "
        f"Jcomm_Calc_Fueling_At_Point_{n} '{desc}', 2 B.",
        f"e2m 1102 +{off} Jcomm_Calc_Fueling_At_Point_{n} '{desc}' (MM3S, 0.0679 per count; 0 in the dump): snapshot of the "
        f"point {n} torque curve fueling taken at the end of cm848_updateProtectionStateMachine, just before the working "
        f"fueling is reset to fuel_demand_maximum; only written, no decompiled reader.")

# 46-50 ------------------------------------------------------------------------------------------------------------
refs = [
    ("0x0040adca", "governor_speed_ref_channel_a", "a", 1, "40", "Torque curve fueling reference idle speed breakpoint."),
    ("0x0040adcc", "governor_speed_ref_channel_b", "b", 2, "42", "Torque curve fueling reference HSG speed breakpoint."),
    ("0x0040adce", "governor_speed_ref_channel_c", "c", 3, "44",
     "1st Torque curve fueling reference between idle and hsg speed breakpoint."),
    ("0x0040add0", "governor_speed_ref_channel_d", "d", 4, "46",
     "2nd Torque curve fueling reference between idle and hsg speed breakpoint."),
    ("0x0040add2", "governor_speed_ref_channel_e", "e", 5, "48",
     "3rd Torque curve fueling reference between idle and hsg speed breakpoint.")]
for address, old, letter, n, off, desc in refs:
    new = f"j1939_torque_curve_reference_fueling_at_point_{n}"
    rename(
        address, old, new, f"{old} = j1939_reference_engine_fueling;",
        f"cm848_updateProtectionDiagnostics: {old} = j1939_reference_engine_fueling (algorithm_enable_flags_41_cal."
        f"reserved_bit_11 clear), else the chi maximum fuel at the point {n} speed divided by a speed-scaled torque ratio; "
        f"cm848_updateProtectionStateMachine divides (point {n} fueling - fuel_demand_norm_zero_cal) x 25600 by "
        f"({old} - zero) for the point {n} percent torque; e2m 1102 +{off} Jcomm_Reference_Fueling_At_Point_{n}, 2 B.",
        f"e2m 1102 +{off} Jcomm_Reference_Fueling_At_Point_{n} '{desc}' (MM3S, 0.0679 per count; 0 in the dump): the "
        f"reference (100 percent torque) fueling at torque curve point {n}: cm848_updateProtectionDiagnostics sets it to "
        f"j1939_reference_engine_fueling, or from the chi maximum fuel at the point speed when "
        f"algorithm_enable_flags_41_cal.reserved_bit_11 is set; cm848_updateProtectionStateMachine divides the point "
        f"fueling by it for the indicated percent torque. Not a governor speed reference.")

# 51 keep --------------------------------------------------------------------------------------------------------------
B.append({"kind": "global", "verdict": "keep", "address": "0x0040af54", "old": "transmission_park_or_neutral_flag",
          "new": "transmission_park_or_neutral_flag",
          "e2m_note": "e2m 109E +8 Chrysler_Park_Neutral_Flag 'True indicates auto trans in park or neutral'",
          "evidence": "two records resolve here: 109E +8 Chrysler_Park_Neutral_Flag matches the proved code use "
                      "(cm848_j1939ProcessPgn61445Etc2, the cruise denial and the converter slip check), at the offset "
                      "that lines up with the PTO words 0x40af4c-0x40af52; 1226 +56 CANC_Requested_MIL is a drift alias "
                      "that lands inside the power take-off words."})

# 52 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040a1a2", "boost_fuel_pressure_offset_lookup", "compressor_inlet_pressure_drop",
    "compressor_inlet_pressure = barometric_pressure_selected - boost_fuel_pressure_offset_lookup;",
    "hpcr_fuelFinal_exponentialAverage: = lookupTableInterpolation(&DAT_003fb9dc, the filtered fresh air mass flow, "
    "WORD_ARRAY_003ff0c4, WORD_ARRAY_003ff0e6), then compressor_inlet_pressure = barometric_pressure_selected - it "
    "(barometric_pressure_sensor_senses_ambient_air_flag_cal set) or barometric_pressure_reference = "
    "barometric_pressure_selected + it (clear); e2m 1921 +E Compressor_Inlet_Pressure_Drop 'Pressure drop from ambient to "
    "compressor inlet' (IN_HG), 2 B; the same name exists only in the reference list e2m_variables.csv.",
    "e2m 1921 +E Compressor_Inlet_Pressure_Drop 'Pressure drop from ambient to compressor inlet' (IN_HG, 0.0159 per count; "
    "0 in the dump): the inlet restriction looked up on the filtered fresh air mass flow in "
    "hpcr_fuelFinal_exponentialAverage; the compressor inlet pressure is the barometric pressure minus it when the "
    "barometric sensor senses ambient air (barometric_pressure_sensor_senses_ambient_air_flag_cal set), and the ambient "
    "pressure reference is the sensor plus it when it does not. Not a boost fuel offset.",
    old_comment_wrong=True)

# 53 -------------------------------------------------------------------------------------------------------------
rename(
    "0x004051e0", "fuel_demand_step_min_threshold_cal", "charge_pressure_in_range_fault_clear_threshold",
    "if ((uint)charge_pressure_in_range_fault_count <= (uint)fuel_demand_step_min_threshold_cal) {",
    "cm848_processBoostControlState: while charge_pressure_in_range_fault_count < the set threshold (+6, "
    "charge_pressure_in_range_fault_set_threshold) a count at or below this clears the fault 527 bits in "
    "fault_detected_bits_512_to_527 / fault_registered_bits_512_to_527 (fail to pass), at or above the set threshold it "
    "sets bit 0x8000; ROM-copied (0x4051e0, not in the EEPROM mirror) so no _cal; e2m 1A2C +0 C_Charge_Press_Fault_Clear, "
    "2 B.",
    "e2m 1A2C +0 C_Charge_Press_Fault_Clear 'Calibration for fail to pass threshold' (CNTS; 2 in the dump): the charge "
    "pressure in range fault clears once its up / down count is at or below this: cm848_processBoostControlState compares "
    "the count with it while the count is under charge_pressure_in_range_fault_set_threshold (e2m +6). ROM-copied "
    "constant, so no _cal. Not a fuel demand step threshold.")

# 54 -------------------------------------------------------------------------------------------------------------
rename(
    "0x004051e2", "fuel_demand_step_decrement_cal", "charge_pressure_in_range_fault_count_decrement",
    "wVar4 = charge_pressure_in_range_fault_count - fuel_demand_step_decrement_cal;",
    "cm848_processBoostControlState: on a good pass the count is reduced by it (0 when the count is not above it), on a "
    "suspect pass raised by charge_pressure_in_range_fault_count_increment (e2m +4, wave 13); ROM copy so no _cal; e2m 1A2C "
    "+2 C_Charge_Press_Fault_Cnt_Decrt 'Charge pressure in range fault count decrement amount', 2 B.",
    "e2m 1A2C +2 C_Charge_Press_Fault_Cnt_Decrt 'Charge pressure in range fault count decrement amount' (UNITLESS; 1 in the "
    "dump): the amount cm848_processBoostControlState subtracts from charge_pressure_in_range_fault_count on each good "
    "pass (the count goes to 0 when it is not above this); the increment is "
    "charge_pressure_in_range_fault_count_increment (e2m +4). ROM-copied constant, so no _cal.")

# 55 -------------------------------------------------------------------------------------------------------------
rename(
    "0x00406776", "throttle_trim_predictor_output_min", "egr_orifice_temperature_estimate_minimum_limit",
    "uVar1 = (uint)throttle_trim_predictor_output_min;",
    "sensor_channel108_filter: egr_orifice_temperature_after_lead = the channel 108 value + the lead term, limited to "
    "egr_orifice_temperature_estimate_maximum_limit above and, when ((int)uVar2 <= this), set to this value below; e2m "
    "1A2E +4 C_INM_EGRT_Min 'Minimum limit for estimated EGR orifice temperature' (DEG_F), the +2 twin 0x406774 was named "
    "egr_orifice_temperature_estimate_maximum_limit in wave 13; ROM copy so no _cal; 2 B.",
    "e2m 1A2E +4 C_INM_EGRT_Min 'Minimum limit for estimated EGR orifice temperature' (DEG_F, 1/64 deg F per count; 0 in "
    "the dump): lower clamp of the lead-compensated sensor channel 108 value (the EGR orifice temperature sensor) in "
    "sensor_channel108_filter, the counterpart of the maximum limit at 0x406774. ROM-copied constant, so no _cal. Not a "
    "throttle trim predictor output.",
    old_comment_wrong=True)

# 56 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b9c4", "cam_sync_validation_abort_reason", "fuel_pressure_sensor_pre_start_check_abort_code",
    "cam_sync_validation_abort_reason = 5;",
    "hpcr_checkRailPressureSensorBeforeStart stores 1 (engine off time below rail_pressure_check_minimum_engine_off_time, "
    "a PCI status or fault bit 0x10), 2 (rail pressure sensor faults 304 / 305 = P0193 / P0192 via ROM 0x5985a -> "
    "obd_dtc_code_table), 3 / 4 (low / high volts sample counts, then a sample in range) and 5 (engine_state is not "
    "STOPPED while the key-on sample ticks are below the minimum): the e2m's 'keyon too long' for 5 disagrees with the "
    "code, where the engine left STOPPED before enough samples were counted; five sth writes, no load; e2m 1B2D +0 "
    "Fuel_Pressure_Keyon_Rat_Abort_Code, 2 B.",
    "e2m 1B2D +0 Fuel_Pressure_Keyon_Rat_Abort_Code '1 not cold soaked, 2 pressure error, 3,4 unstable pressure, 5 keyon too "
    "long' (UNITLESS, 0-5): why hpcr_checkRailPressureSensorBeforeStart aborted the rail pressure sensor key-on check: 1 "
    "short engine-off time / PCI status / fault, 2 sensor faults P0193 / P0192, 3 / 4 low / high volts samples then in "
    "range, 5 the engine left STOPPED before the minimum number of samples (the code's reading of 'keyon too long'). Only "
    "written; not a cam sync.")

# 57 -------------------------------------------------------------------------------------------------------------
rename(
    "0x0040b87f", "engine_sync_state_t_0040b87f", "fuel_pressure_governor_state",
    "engine_sync_state_t_0040b87f.fuel_pressure_governor_mode = FUEL_PRESSURE_GOVERNOR_OPEN_LOOP_START;",
    "e2m 8019 +0 HPCR_Fuelpr_Operating_Mode_N (1 B) / +1 HPCR_Dutycycle_Monitoring (2 B) / +3 HPCR_Dutycycle_Output (2 B) / "
    "+5 HPCR_Filtered_Battery_Voltage (2 B) at 0x40b87f-0x40b885 is the fuel pressure controller (fuel metering valve) "
    "state read and written by cm848_calculateFuelMeteringCommand, not an engine sync state; its fields are already "
    "fuel_pressure_governor_mode / _demand and fuel_metering_command; the struct ends in a 1-byte reserved_05 but 0x40b884 "
    "is a word (lhz at 0x48d14, sth at 0x49250).",
    "e2m 8019 +0 .. +5 (HPCR_Fuelpr_Operating_Mode_N byte, HPCR_Dutycycle_Monitoring, HPCR_Dutycycle_Output, "
    "HPCR_Filtered_Battery_Voltage): the fuel pressure governor state record of cm848_calculateFuelMeteringCommand: "
    "fuel_pressure_governor_mode (FUEL_PRESSURE_GOVERNOR_MODE), fuel_pressure_governor_demand, fuel_metering_command "
    "(0-4095) and the filtered battery voltage word at 0x40b884 that the struct does not cover. Not an engine sync state.",
    type_note="struct engine_sync_state_t is 6 bytes (byte mode, word demand, word command, byte reserved_05) but the e2m "
              "8019 +5 HPCR_Filtered_Battery_Voltage record at 0x40b884 is a word (cm848_filterEngineSensorValue stores the "
              "average of sensor_channel2_ram.value there as ram0x0040b884 with sth at 0x49250; "
              "cm848_calculateFuelMeteringCommand reads it with lhz at 0x48d14 for its voltage lookup), so the last field "
              "should be a 2-byte word and the struct 7 bytes (0x40b87f-0x40b885); the decompile renders ram0x0040b884 "
              "outside the struct. The type and its field labels (engine_sync_state_t_0040b87f.*) want the matching "
              "fuel_pressure_governor_state_t rename in the same change.")

# 58 -------------------------------------------------------------------------------------------------------------
rename(
    "0x00408a9c", "protection_coldStart_channelA_rpm_min_threshold", "governor_pressure_zero_check_target_high_limit",
    "(protection_coldStart_channelA_rpm_min_threshold < governor_pressure_target)) {",
    "cm848_monitorGovernorPressureTracking: the zero check runs only while vehicle_speed == 0 and "
    "(governor_pressure_target <= this) and re-arms its window flag when the target is above it; P1757 = fault 391 and "
    "P1756 = fault 392 via ROM 0x5985a -> obd_dtc_code_table; e2m 8C59 +6 RE_Governor_Pr_Zero_Set_High_Limit [PSI] "
    "'Governor pressure below this will allow monitor to run' is compared with the pressure TARGET, not an rpm; ROM copy "
    "so no _cal.",
    "e2m 8C59 +6 RE_Governor_Pr_Zero_Set_High_Limit 'Governor pressure below this will allow monitor to run' (PSI, 1/128 psi "
    "per count; 0 in the dump): upper limit of the governor pressure TARGET for the zero check of "
    "cm848_monitorGovernorPressureTracking (P1757): the check runs only at 0 mph with governor_pressure_target at or below "
    "it (a zero target) and re-arms its window above it. A pressure limit, not an rpm threshold.",
    old_comment_wrong=True)

# 59 -------------------------------------------------------------------------------------------------------------
rename(
    "0x00408aa4", "protection_coldStart_channelB_rpm_lower_threshold", "governor_pressure_mid_range_check_target_low_limit",
    "(governor_pressure_target < protection_coldStart_channelB_rpm_lower_threshold)) {",
    "cm848_monitorGovernorPressureTracking: the mid range check runs only while lower <= governor_pressure_target <= upper "
    "(the compare (protection_coldStart_channelB_rpm_lower_threshold <= governor_pressure_target)) and re-arms its window "
    "outside; the dump holds 4224 for this row and 5120 for the upper one, so this is the low limit; e2m 8C59 +E "
    "RE_Governor_Pr_Mid_Set_Low_Limit [PSI] 'Governor pressure below this will disable the monitor' is a pressure target "
    "limit, not an rpm.",
    "e2m 8C59 +E RE_Governor_Pr_Mid_Set_Low_Limit 'Governor pressure below this will disable the monitor' (PSI, 1/128 psi "
    "per count; 4224 in the dump = 33.0 psi): lower limit of the governor pressure TARGET for the mid range check of "
    "cm848_monitorGovernorPressureTracking (P1756): the check runs only with this at or below governor_pressure_target (33 "
    "to 40 psi here) and re-arms its window outside. A pressure limit, not an rpm threshold.",
    old_comment_wrong=True)

# 60 -------------------------------------------------------------------------------------------------------------
rename(
    "0x00408aa8", "protection_coldStart_channelB_rpm_upper_threshold", "governor_pressure_mid_range_check_target_high_limit",
    "if ((protection_coldStart_channelB_rpm_upper_threshold < governor_pressure_target) ||",
    "cm848_monitorGovernorPressureTracking: a target above this (or below the low limit) re-arms the mid range window, the "
    "check itself needs (governor_pressure_target <= this); the dump holds 5120 for this row and 4224 for the low limit; e2m 8C59 +12 "
    "RE_Governor_Pr_Mid_Set_High_Limit [PSI] 'Governor pressure above this will disable the monitor', a pressure target "
    "limit, not an rpm.",
    "e2m 8C59 +12 RE_Governor_Pr_Mid_Set_High_Limit 'Governor pressure above this will disable the monitor' (PSI, 1/128 psi "
    "per count; 5120 in the dump = 40.0 psi): upper limit of the governor pressure TARGET for the mid range check of "
    "cm848_monitorGovernorPressureTracking (P1756): above it the check is off and its window re-arms. A pressure limit, not "
    "an rpm threshold.",
    old_comment_wrong=True)

# 61 -------------------------------------------------------------------------------------------------------------
rename(
    "0x00408aac", "protection_load_upper_threshold", "governor_pressure_check_maximum_transmission_temperature",
    "(int)(uint)protection_load_upper_threshold)) &&",
    "cm848_monitorGovernorPressureTracking runs only while (int)(short)transmission_temperature_sensor_filtered <= this "
    "and cm848_monitorGovernorPressureSensorOffset while it is < this; the dump holds 14080 for this row and 8512 for the lower one, "
    "so this is the maximum; e2m 8C59 +16 RE_Governor_Pr_Control_Rat_Max_Oil_Temp [DEG_F, signed] 'Transmission oil temp "
    "above this will disable monitor' (row typed word, read through a (uint) cast: i16 would fit); sibling "
    "governor_pressure_check_maximum_accelerator_position (+14).",
    "e2m 8C59 +16 RE_Governor_Pr_Control_Rat_Max_Oil_Temp 'Transmission oil temp above this will disable monitor' (DEG_F, "
    "signed, 1/64 deg F per count; 14080 in the dump = 220 deg F): highest transmission temperature at which the governor "
    "pressure monitors run: cm848_monitorGovernorPressureTracking (<=) and cm848_monitorGovernorPressureSensorOffset (<) "
    "compare transmission_temperature_sensor_filtered with it. Not a load threshold.")

# 62 -------------------------------------------------------------------------------------------------------------
rename(
    "0x00408aae", "protection_load_lower_threshold", "governor_pressure_check_minimum_transmission_temperature",
    "(((int)(uint)protection_load_lower_threshold <=",
    "cm848_monitorGovernorPressureTracking runs only while this <= (int)(short)transmission_temperature_sensor_filtered "
    "and cm848_monitorGovernorPressureSensorOffset while this < it; the dump holds 8512 for this row and 14080 for the upper one, so "
    "this is the minimum; e2m 8C59 +18 RE_Governor_Pr_Control_Rat_Min_Oil_Temp [DEG_F, signed] 'Transmission oil temp below "
    "this will disable monitor' (row typed word, read through a (uint) cast: i16 would fit).",
    "e2m 8C59 +18 RE_Governor_Pr_Control_Rat_Min_Oil_Temp 'Transmission oil temp below this will disable monitor' (DEG_F, "
    "signed, 1/64 deg F per count; 8512 in the dump = 133 deg F): lowest transmission temperature at which the governor "
    "pressure monitors run: cm848_monitorGovernorPressureTracking (<=) and cm848_monitorGovernorPressureSensorOffset (<) "
    "compare transmission_temperature_sensor_filtered with it. Not a load threshold.")
