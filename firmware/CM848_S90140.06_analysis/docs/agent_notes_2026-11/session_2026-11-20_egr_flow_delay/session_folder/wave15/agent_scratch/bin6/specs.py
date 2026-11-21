# specs for bin6: renames, uncertain, drift. Keeps are listed in KEEP_NOTES (the e2m note is built from the bin).
FAMILY_1170 = ("family rename: the e2m descriptions of block 1170 +C .. +3C (the 25 words 0x40a216-0x40a246) say 'application "
               "specific' (+3C 'application defined'), FUELING_STATE 30 has the e2m label ASG_APPL, and nothing stores to these words "
               "(xref_addr.py finds no store in either bank; the .cpp uses them only in cm848_restoreEngineOperatingMode), so 'restore' "
               "has no saving code behind it")

FAMILY_SHORT = ("family rename with the 0x40a216 row (block 1170 +C .. +3C is the e2m 'application specific' ASG record, mode 30 = "
                "ASG_APPL, no store to it)")

SPECS = {
    1: dict(
        verdict='rename', new='accelerator_pedal_fault_delay',
        fn='cm848_fuelDemandSmoothingController', sub='uVar1 = fuel_demand_rate_limit_debounce_low_cal;',
        evidence="e2m 1048 +C Throttle_Fault_Delay (MSEC): cm848_fuelDemandSmoothingController uses it as the debounce count of the "
                 "idle validation fault counters while accelerator_pedal_autozero_cal <= accelerator_pedal_sensor_counts; the old "
                 "name said fuel demand rate limit and carried _cal on a ROM constant",
        comment="e2m 1048 +C Throttle_Fault_Delay '[CTTHFTDY] time fault conditions must exist before logging a throttle fault' "
                "(MSEC, 100 ms per count; 8 here): the debounce count cm848_fuelDemandSmoothingController lets the idle validation "
                "fault counters (fuel_demand_cal_increment_a / _b / _c) reach before a fault bit latches (fault_detected_bits_64_to_79 "
                "0x10, fault_detected_bits_48_to_63 0x4000 / 0x8000), used while accelerator_pedal_autozero_cal <= "
                "accelerator_pedal_sensor_counts; below it e2m 1048 +16 Throttle_Fault_Delay_At_Idle (0x5c2a4) applies. ROM constant, "
                "so no _cal."),
    3: dict(
        verdict='rename', new='alpha_air_fuel_control_result',
        fn='calculateAlphaBase', sub='pressure_fuel_delay_b_status = calculateAlphaAirFuelControlResult();',
        evidence="e2m 104A +6 Alpha_AFC (UNITLESS): calculateAlphaBase stores the return value of calculateAlphaAirFuelControlResult "
                 "here and ORs it into the alpha ramp enable; the old name said pressure fuel delay b",
        comment="e2m 104A +6 Alpha_AFC '[APAFSS] result of AFC algorithm' (UNITLESS): the value calculateAlphaAirFuelControlResult "
                "returns (1 once alpha_air_fuel_control_timer ran out with no air fuel control or low speed governor limiting, else 0); "
                "calculateAlphaBase stores it when bit 0x800 of governor_fault_status_flags is set and ORs it into the alpha ramp "
                "enable, a 1 lets alpha_base ramp toward 1.0."),
    4: dict(
        verdict='rename', new='alpha_on_governor_result',
        fn='calculateAlphaBase', sub='fuel_rate_condition_status = calculateAlphaOnGovernorResult();',
        evidence="e2m 104A +A Alpha_Governor (UNITLESS): calculateAlphaBase stores the return value of calculateAlphaOnGovernorResult "
                 "here and ORs it into the alpha ramp enable; the old name said fuel rate condition",
        comment="e2m 104A +A Alpha_Governor '[APGVAP] result of On Governor' (UNITLESS): the value calculateAlphaOnGovernorResult "
                "returns (1 while final_fueling_state is FUELING_STATE_VEHICLE_SPEED_LIMIT or cruise_control_engaged_flag is 1, "
                "else 0); calculateAlphaBase stores it when bit 0x2000 of governor_fault_status_flags is set and ORs it into the alpha "
                "ramp enable, a 1 lets alpha_base ramp toward 1.0."),
    5: dict(
        verdict='rename', new='alpha_low_speed_governor_result',
        fn='calculateAlphaBase', sub='pressure_fuel_delay_a_status = calculateAlphaLowSpeedGovernorResult();',
        evidence="e2m 104A +C Alpha_LSG (UNITLESS): calculateAlphaBase stores the return value of calculateAlphaLowSpeedGovernorResult "
                 "here and uses it as the start of the alpha ramp enable; the old name said pressure fuel delay a",
        comment="e2m 104A +C Alpha_LSG '[APLSAP] result of LSG algorithm' (UNITLESS): the value calculateAlphaLowSpeedGovernorResult "
                "returns (1 once alpha_low_speed_governor_timer ran out without the low speed governor acting, else 0); "
                "calculateAlphaBase stores it when bit 0x400 of governor_fault_status_flags is set and uses it as the start of the "
                "alpha ramp enable, a 1 lets alpha_base ramp toward 1.0."),
    13: dict(
        verdict='rename', new='all_speed_governor_switch_droop_fueling_offset',
        fn='cm848_updateVariableSpeedGovernorSelection', sub='(uint)fuel_demand_speed_deadband_cal',
        evidence="e2m 107D +8 ASG_Switch_Droop_Fueling_Offset (MM3S): added to the no-load fuel in the final_fueling <= no-load fuel + "
                 "offset test of cm848_updateVariableSpeedGovernorSelection (and the friction fuel variant in "
                 "cm848_blendGovernorTuningSets); the old name said speed deadband and carried _cal on a RAM copy",
        comment="e2m 107D +8 ASG_Switch_Droop_Fueling_Offset '[ASSDFUOF] Offset added to NLFL and compared with FSFNFL for throttle gov. "
                "switch' (MM3S, 0.0679 mm3 per count; 736 = 50 mm3 here): cm848_updateVariableSpeedGovernorSelection allows the "
                "governor type switch only while final_fueling <= fuel_demand_base_offset (e2m 109C No_Load_Fuel) + this; "
                "cm848_blendGovernorTuningSets uses it the same way on friction_fuel_adjustment_for_coolant_temperature. ROM copy, "
                "no _cal."),
    14: dict(
        verdict='rename', new='all_speed_governor_delta_offset',
        fn='cm848_runOperatingModeSpeedGovernor', sub='fuel_demand_integrator_offset_cal;',
        evidence="e2m 107D +1A ASG_Delta_Offset (MM3S): subtracted from all_speed_governor_delta in cm848_runOperatingModeSpeedGovernor; "
                 "the old name said fuel demand integrator and carried _cal on a RAM copy",
        comment="e2m 107D +1A ASG_Delta_Offset 'ASG deadband delta reduced by this amount, to add back some deadband' (MM3S, 0.0679 mm3 "
                "per count; 0 here): cm848_runOperatingModeSpeedGovernor subtracts it when it integrates final_fueling minus "
                "all_speed_governor_fueling into all_speed_governor_delta in the low speed governor state (floored at 0). ROM copy, "
                "no _cal."),
    17: dict(
        verdict='rename', new='rpm_deceleration_limit_target_rate_high_zone',
        fn='cm848_runOperatingModeSpeedGovernor', sub='sVar12 = engine_rpm_delta - engine_rpm_delta_high_offset_cal;',
        evidence="e2m 107D +32 Target_RPM_Decel_Rate_Hi (RPM): the engine speed drop per pass tolerated above engine_rpm_high_zone_threshold, "
                 "subtracted from engine_rpm_delta in the rpm deceleration limit control of cm848_runOperatingModeSpeedGovernor; the old "
                 "name carried _cal on a RAM copy; type: the row is word but its one load is lha (signed) while the e2m is unsigned",
        comment="e2m 107D +32 Target_RPM_Decel_Rate_Hi 'ASG decel target at high engine speeds (>Decel_Limit_RPM_Threshold)' (RPM, 0.125 rpm "
                "per count; 600 = 75 rpm here): the engine speed drop per pass the rpm deceleration limit control tolerates above "
                "engine_rpm_high_zone_threshold; cm848_runOperatingModeSpeedGovernor subtracts it from engine_rpm_delta before the "
                "integral and proportional terms. ROM copy, no _cal. Type: word, its one load is lha (signed) while the e2m is unsigned."),
    21: dict(
        verdict='rename', new='fuel_demand_ramp_drivetrain_ratio_threshold',
        fn='cm848_runOperatingModeSpeedGovernor', sub='if ((engine_temp_protection_threshold < drivetrain_ratio) ||',
        evidence="e2m 107D +3E ASG_Fuel_Slew_Inc_Ratio_Thd (UNITLESS, 1/2048): compared with drivetrain_ratio in "
                 "cm848_runOperatingModeSpeedGovernor to switch the positive fuel slew ramp off; the old name said engine temperature "
                 "protection (an abbreviation and a different quantity)",
        comment="e2m 107D +3E ASG_Fuel_Slew_Inc_Ratio_Thd 'Apply pos ASG fuel slew inc limits when ratio < this thd' (UNITLESS, 1/2048; 0 "
                "here): cm848_runOperatingModeSpeedGovernor holds fuel_demand_ramp_state at 0x1700 (no positive fuel slew limit) while "
                "drivetrain_ratio is above it or both ramp increments (fuel_demand_ramp_rate / fuel_demand_ramp_step) are 0. A drivetrain "
                "ratio threshold, not a temperature."),
    22: dict(
        verdict='rename', new='all_speed_governor_delta_upper_limit',
        fn='cm848_runOperatingModeSpeedGovernor', sub='all_speed_governor_delta = fuel_demand_integrator_upper_limit;',
        evidence="e2m 107D +42 ASG_Delta_Max_Limit (MM3S): upper clamp of all_speed_governor_delta in cm848_runOperatingModeSpeedGovernor; "
                 "the old name kept the pre-ASG_Delta fuel demand integrator wording",
        comment="e2m 107D +42 ASG_Delta_Max_Limit 'ASG_Delta maximum allowable value, start droop value' (MM3S, 0.0679 mm3 per count; "
                "442 = 30 mm3 here): the upper clamp of all_speed_governor_delta and the value its upper bound droops from above the idle "
                "reference speed, in cm848_runOperatingModeSpeedGovernor."),
    23: dict(
        verdict='uncertain',
        evidence="e2m 1080 +0 Software_FLT2ERAS '[FLT2ERAS] FAULT TO ERASE' (HEX): the only access is the store of 0 in "
                 "cm848_clearDiagnosticState (0 reads, 1 write, nothing in either bank), next to the clear of "
                 "fault_list_state.total_emission_faults, so no code line shows a role; the current name emission_fault_overflow_flag has "
                 "no support either; the +2 neighbour DL_to_Fault_Handler_Command matches diagnostic_clear_request_state, which fits a "
                 "fault to erase / clear command pair; diagnostic_fault_to_erase is the likely name but unproven"),
    24: dict(
        verdict='rename', new='j1939_indicated_percent_torque_at_point_3_times_256',
        fn='buildPgn65251EngineConfiguration1Payload', sub='(protection_speed_ratio_c >> 8)',
        evidence="e2m 1102 +C Jcomm_Ind_Torque_at_Point_3 (%): cm848_updateJ1939EngineConfigurationTorqueCurve stores the percent torque at "
                 "curve point 3 here and buildPgn65251EngineConfiguration1Payload sends its high byte + 125; the old name said protection "
                 "speed ratio",
        comment="e2m 1102 +C Jcomm_Ind_Torque_at_Point_3 '[JCINP3TQ] Jcomm Ind Torque at Point 3 available torque that engine can provide "
                "at pt 3' (%, 1/256 % per count; 0 here): cm848_updateJ1939EngineConfigurationTorqueCurve = (curve fueling at point 3 - "
                "fuel_demand_norm_zero_cal) x 0x6400 / (reference fueling at point 3 - zero), clamped; "
                "buildPgn65251EngineConfiguration1Payload sends its high byte + 125 as the PGN 65251 torque at point 3."),
    25: dict(
        verdict='rename', new='j1939_indicated_percent_torque_at_point_4_times_256',
        fn='buildPgn65251EngineConfiguration1Payload', sub='(protection_speed_ratio_d >> 8)',
        evidence="e2m 1102 +E Jcomm_Ind_Torque_at_Point_4 (%): cm848_updateJ1939EngineConfigurationTorqueCurve stores the percent torque at "
                 "curve point 4 here and buildPgn65251EngineConfiguration1Payload sends its high byte + 125; the old name said protection "
                 "speed ratio",
        comment="e2m 1102 +E Jcomm_Ind_Torque_at_Point_4 '[JCINP4TQ] Jcomm Ind Torque at Point 4 available torque that engine can provide "
                "at pt 4' (%, 1/256 % per count; 0 here): cm848_updateJ1939EngineConfigurationTorqueCurve = (curve fueling at point 4 - "
                "fuel_demand_norm_zero_cal) x 0x6400 / (reference fueling at point 4 - zero), clamped; "
                "buildPgn65251EngineConfiguration1Payload sends its high byte + 125 as the PGN 65251 torque at point 4."),
    26: dict(
        verdict='rename', new='all_speed_governor_application_override_mode',
        fn='cm848_restoreEngineOperatingMode', sub='(engine_operating_mode_restore_valid_flag != 0)',
        evidence="e2m 1170 +C ASG_As_Override_Mode (ASG application specific reference override mode): the gate of "
                 "cm848_restoreEngineOperatingMode that selects mode 30 (e2m ASG_APPL) and loads the application specific ASG record; "
                 + FAMILY_1170,
        comment="e2m 1170 +C ASG_As_Override_Mode '[ASAPODMD] ASG application specific reference override mode' (UNITLESS; 0 here, RAM "
                "zeroed at every start): the gate of cm848_restoreEngineOperatingMode - with engine_operating_mode 0 and this nonzero it "
                "selects mode 30 (e2m ASG_APPL) and copies the application specific ASG record 0x40a216-0x40a246 into the governor, as "
                "cm848_initEngineOperatingMode does with the all_speed_governor_throttle_mode_* set for mode 7. Only reader, no writer "
                "in either bank."),
    27: dict(
        verdict='rename', new='all_speed_governor_application_reference_speed',
        fn='cm848_restoreEngineOperatingMode', sub='speed_request_unfiltered = engine_operating_mode_restore_speed_request;',
        evidence="e2m 1170 +E ASG_As_Reference_RPM (ASG application specific reference speed): copied to speed_request_unfiltered when "
                 "mode 30 is selected; " + FAMILY_SHORT,
        comment="e2m 1170 +E ASG_As_Reference_RPM '[ASAPRF] ASG application specific reference speed' (RPM, 0.125 rpm per count; 0 here): "
                "cm848_restoreEngineOperatingMode copies it to speed_request_unfiltered (0x40a24e) when it selects mode 30. Only reader, "
                "no writer."),
    28: dict(
        verdict='rename', new='all_speed_governor_application_fuel_demand_tracking_floor',
        fn='cm848_restoreEngineOperatingMode',
        sub='governor_fuel_demand_tracking_floor = engine_operating_mode_restore_fuel_demand_tracking_floor;',
        evidence="e2m 1170 +18 ASG_Lower_Fuel_Limit_As (ASG application specific fueling lower limit): copied to "
                 "governor_fuel_demand_tracking_floor when mode 30 is selected; " + FAMILY_SHORT,
        comment="e2m 1170 +18 ASG_Lower_Fuel_Limit_As '[ASAPLOLM] ASG application specific fueling lower limit' (MM3S, 0.0679 mm3 per "
                "count; 0 here): copied by cm848_restoreEngineOperatingMode to governor_fuel_demand_tracking_floor, the lower clamp of "
                "governor_fuel_demand_tracking (all_speed_governor_fueling = clamp(tracking, floor, limit)), not a speed reference. Only "
                "reader, no writer."),
    29: dict(
        verdict='rename', new='all_speed_governor_application_reset_state_speed_error_previous',
        fn='cm848_restoreEngineOperatingMode', sub='engine_operating_mode_restore_speed_error_previous;',
        evidence="e2m 1170 +1C ASG_State_X1_As (ASG application specific state X1 reset value): copied to "
                 "all_speed_governor_reset_state_speed_error_previous; " + FAMILY_SHORT,
        comment="e2m 1170 +1C ASG_State_X1_As '[ASAPSTX1] ASG application specific state X1 reset value' (RPM, 0.125 rpm per count, "
                "signed; 0 here): cm848_restoreEngineOperatingMode copies it to all_speed_governor_reset_state_speed_error_previous, "
                "which the governor loads as the previous speed error (reference minus engine speed, clamped to +-32000) while "
                "all_speed_governor_external_reset_flag is set. Signed word, read with lha. Only reader, no writer."),
    30: dict(
        verdict='rename', new='all_speed_governor_application_reset_state_integral',
        fn='cm848_restoreEngineOperatingMode',
        sub='all_speed_governor_reset_state_integral = engine_operating_mode_restore_integral_state;',
        evidence="e2m 1170 +1E ASG_State_X2_As (ASG application specific state X2 reset value): copied to "
                 "all_speed_governor_reset_state_integral; " + FAMILY_SHORT,
        comment="e2m 1170 +1E ASG_State_X2_As '[ASAPSTX2] ASG application specific state X2 reset value' (MM3S, 0.0679 mm3 per count, "
                "signed; 0 here): copied to all_speed_governor_reset_state_integral and then governor_pid_integral_state = value << 16 "
                "(the high word of the governor integrator) while all_speed_governor_external_reset_flag is set. Only reader, no writer."),
    31: dict(
        verdict='rename', new='all_speed_governor_application_reset_state_engine_speed_previous',
        fn='cm848_restoreEngineOperatingMode', sub='engine_operating_mode_restore_engine_speed_previous;',
        evidence="e2m 1170 +20 ASG_State_X3_As (ASG application specific state X3 reset value): copied to "
                 "all_speed_governor_reset_state_engine_speed_previous; " + FAMILY_SHORT,
        comment="e2m 1170 +20 ASG_State_X3_As '[ASAPSTX3] ASG application specific state X3 reset value' (RPM, 0.125 rpm per count; 0 "
                "here): copied to all_speed_governor_reset_state_engine_speed_previous and then fuel_trim_pid_ema_snapshot, the engine "
                "speed the governor subtracts from governor_rpm_actual (the engine speed change per pass). Only reader, no writer."),
    32: dict(
        verdict='rename', new='all_speed_governor_application_reset_state_pid_clamp_value',
        fn='cm848_restoreEngineOperatingMode',
        sub='all_speed_governor_reset_state_pid_clamp_value = engine_operating_mode_restore_pid_clamp_value;',
        evidence="e2m 1170 +22 ASG_State_X4_As (ASG application specific state X4 reset value): copied to "
                 "all_speed_governor_reset_state_pid_clamp_value; " + FAMILY_SHORT,
        comment="e2m 1170 +22 ASG_State_X4_As '[ASAPSTX4] ASG application specific state X4 reset value' (MM3S, 0.0679 mm3 per count, "
                "signed; 0 here): copied to all_speed_governor_reset_state_pid_clamp_value, which seeds the previous "
                "all_speed_governor_state_pid_clamp_value (the clamped proportional + derivative output). Signed word, read with lha. "
                "Only reader, no writer."),
    33: dict(
        verdict='rename', new='all_speed_governor_application_reset_state_pid_integral_clamped',
        fn='cm848_restoreEngineOperatingMode', sub='engine_operating_mode_restore_pid_integral_clamped;',
        evidence="e2m 1170 +24 ASG_State_X5_As (ASG application specific state X5 reset value): copied to "
                 "all_speed_governor_reset_state_pid_integral_clamped; " + FAMILY_SHORT,
        comment="e2m 1170 +24 ASG_State_X5_As '[ASAPSTX5] ASG application specific state X5 reset value' (MM3S, 0.0679 mm3 per count, "
                "signed; 0 here): copied to all_speed_governor_reset_state_pid_integral_clamped, which seeds the previous "
                "all_speed_governor_state_pid_integral_clamped (integral plus clamp value, clamped). Signed word, read with lha. Only "
                "reader, no writer."),
    34: dict(
        verdict='rename', new='all_speed_governor_application_reset_state_fuel_demand_correction',
        fn='cm848_restoreEngineOperatingMode', sub='engine_operating_mode_restore_fuel_demand_correction;',
        evidence="e2m 1170 +26 ASG_State_X6_As (ASG application specific state X6 reset value): copied to "
                 "all_speed_governor_reset_state_fuel_demand_correction; " + FAMILY_SHORT,
        comment="e2m 1170 +26 ASG_State_X6_As '[ASAPSTX6] ASG application specific state X6 reset value' (MM3S, 0.0679 mm3 per count, "
                "signed; 0 here): copied to all_speed_governor_reset_state_fuel_demand_correction, which seeds "
                "all_speed_governor_state_fuel_demand_correction. Signed word, read with lha. Only reader, no writer."),
    35: dict(
        verdict='rename', new='all_speed_governor_application_feedback_speed',
        fn='cm848_restoreEngineOperatingMode', sub='governor_rpm_actual = engine_operating_mode_restore_engine_speed;',
        evidence="e2m 1170 +3A ASG_As_Feedback_Speed (Application specific feedback variable for ASG): copied to governor_rpm_actual, the "
                 "speed the governor regulates on; " + FAMILY_SHORT,
        comment="e2m 1170 +3A ASG_As_Feedback_Speed '[ASAPFBES] Application specific feedback variable for ASG' (RPM, 0.125 rpm per "
                "count; 0 here): copied by cm848_restoreEngineOperatingMode to governor_rpm_actual, the engine speed the governor "
                "regulates on. Only reader, no writer."),
    37: dict(
        verdict='rename', new='cruise_road_speed_governor_minimum_fuel_ramp_rate',
        fn='cm848_arbitrateGovernedFueling',
        sub='fuel_demand_corrected_working = fuel_demand_corrected_working - fuel_demand_corrected_step_cal;',
        evidence="e2m 1189 +22 Cruise_RSG_Min_Fuel_Ramp_Rate (MM3S/SEC): the per-pass step cm848_arbitrateGovernedFueling subtracts from "
                 "fuel_demand_corrected_working after the cruise control cuts out; the old name carried _cal on a ROM copy and did not "
                 "say cruise / road speed governor",
        comment="e2m 1189 +22 Cruise_RSG_Min_Fuel_Ramp_Rate 'cc/rsg min fuel transition ramp rate' (MM3S/SEC, 3.397 mm3/s per count; 44 "
                "here): the per-pass step cm848_arbitrateGovernedFueling subtracts from fuel_demand_corrected_working (set to "
                "final_fueling when the cruise control disengages), which keeps adjusted_user_fueling from falling faster than the ramp "
                "unless a TSC1 (or mode 37 / 38) governor output is active; a clutch / neutral cut-out uses e2m 1046 +6 "
                "Cruise_RSG_Neutral_Fuel_Ramp_Rate (0x3feff0) instead. ROM copy, no _cal."),
    40: dict(
        verdict='rename', new='cruise_feedback_uses_road_speed_flag_cal',
        fn='cm848_calculateRiseLimitedVehicleSpeed', sub='if (fuel_flow_rpm_mode_flag == 0) {',
        evidence="e2m 118B +2 Cruise_RSG_Feedback_Parameter (1=ROAD_SPEED, 0=PREDICTED_VEHICLE_SPEED used in the feedback loop): "
                 "cm848_calculateRiseLimitedVehicleSpeed takes vehicle_speed for a nonzero value and the engine speed prediction for 0; "
                 "the old name said fuel flow rpm mode and lacked _cal on an EEPROM mirror row",
        comment="e2m 118B +2 Cruise_RSG_Feedback_Parameter '1=ROAD_SPEED, 0=PREDICTED_VEHICLE_SPEED USED IN FEEDBACK LOOP' (UNITLESS; "
                "EEPROM 0x49e, 1 here): cm848_calculateRiseLimitedVehicleSpeed takes vehicle_speed when it is nonzero and, when it is 0, "
                "the speed predicted from engine speed (engine speed / (fuel_flow_rpm_numerator x drivetrain_ratio_user_filtered)), each "
                "rise limited per pass; vehicle_speed_rise_limited is the speed the cruise control and vehicle speed limit fueling work "
                "on."),
    41: dict(
        verdict='rename', new='master_slave_final_override_alpha',
        fn='calculateAlpha', sub='combustion_alpha_input = governor_startup_fuel_blend_coeff;',
        evidence="e2m 11D4 +A MS_Final_Override_Alpha (UNITLESS, 1/16384): calculateAlpha loads it into combustion_alpha_input as alpha "
                 "source 4 (slave override) while master_slave_override_enable_flag is set; the old name said governor startup fuel blend",
        comment="e2m 11D4 +A MS_Final_Override_Alpha '[MSFNAP] Alpha value used to override SLAVE ECM.' (UNITLESS, 1/16384 per count; 0 "
                "here): calculateAlpha loads it into combustion_alpha_input (alpha_state 4, slave override) while "
                "master_slave_override_enable_flag (e2m 11D4 +2 MS_Override_Enable) is nonzero, then limits it to 16384 (= 1.0)."),
    42: dict(
        verdict='rename', new='application_identifier_cal',
        fn='cm848_initPgn65242SoftwareIdHandler', sub='local_10 = (undefined1)(j1939_pgn_priority_cal >> 8);',
        evidence="e2m 1292 +0 Application_Identifier (HEX, 0x3030 = ASCII 00 here): cm848_initPgn65242SoftwareIdHandler copies its two "
                 "bytes into the PGN 65242 software identification string; the old name said PGN priority",
        comment="e2m 1292 +0 Application_Identifier '[APPL_ID] Descriptor of the project or fuel system.' (HEX; EEPROM 0x9a; 12336 = "
                "0x3030, the ASCII characters 00, here): cm848_initPgn65242SoftwareIdHandler copies its high and low byte into the "
                "last of the six '*'-delimited fields of the PGN 65242 software identification string."),
    45: dict(
        verdict='rename', new='high_speed_governor_compensator_transition_coefficient',
        fn='cm848_calculateHighSpeedGovernorCompensatedEngineSpeed', sub='cruise_speed_factor_b = cruise_speed_default_cal;',
        evidence="e2m 13B4 +4 HSG_Comp_Transition_Coefficient (UNITLESS, 1/32768): "
                 "cm848_calculateHighSpeedGovernorCompensatedEngineSpeed loads it as compensator factor b and offset for the "
                 "no-filtering case; the old name said cruise speed and carried _cal on a ROM constant",
        comment="e2m 13B4 +4 HSG_Comp_Transition_Coefficient 'Filter coefficient used by HSG lead/lag compensator for no-filtering case' "
                "(UNITLESS, 1/32768 per count; 0 here): cm848_calculateHighSpeedGovernorCompensatedEngineSpeed loads it as factor b and "
                "offset (factor a = 0x8000) while the lead / lag compensator is inactive, so the engine speed passes through; "
                "cm848_initializeHighSpeedGovernorCompensatedEngineSpeed loads all three factors with it. ROM constant, no _cal."),
    50: dict(
        verdict='rename', new='boost_pressure_sensor_high_reading_idle_reference_speed_offset',
        fn='cm848_monitorBoostPressureSensorAndUnderboost',
        sub='(uint)boost_pressure_sensor_high_reading_target_speed_margin <',
        evidence="e2m 1631 +6 BIR_LSG_Ref_Speed_Offset (RPM): added to governor_output_t_0040aec2.idle_reference_speed (the low speed "
                 "governor reference) to give the engine speed limit of the high reading test; the old name inherited target_rpm wording "
                 "for engine_speed_state.engine_speed and does not say what the offset is added to (same pattern as "
                 "misfire_monitor_idle_reference_speed_offset, e2m Misfire_LSG_Ref_Speed_Offset)",
        comment="e2m 1631 +6 BIR_LSG_Ref_Speed_Offset '[DGLSRSOF] Offset added to LSG Ref Spd resulting in RPM limit for BIRH test' (RPM, "
                "0.125 rpm per count; ROM word 15600 = 1950 rpm): cm848_monitorBoostPressureSensorAndUnderboost keeps the boost pressure "
                "sensor high reading check running only while engine_speed_state.engine_speed is at most "
                "governor_output_t_0040aec2.idle_reference_speed (the low speed governor reference) plus this offset (lhz @ 0x52db04)."),
    54: dict(
        verdict='rename', new='underboost_minimum_engine_speed',
        fn='cm848_monitorBoostPressureSensorAndUnderboost',
        sub='(underboost_minimum_target_speed <= engine_speed_state.engine_speed)',
        evidence="e2m 1631 +10 BIR_High_Engine_Speed_Threshold (RPM): compared with engine_speed_state.engine_speed (the measured engine "
                 "speed, e2m 819B +1E) in cm848_monitorBoostPressureSensorAndUnderboost, so it is a minimum engine speed, not a target "
                 "speed (cf. misfire_monitor_maximum_engine_speed); the old name inherited target_rpm for that variable",
        comment="e2m 1631 +10 BIR_High_Engine_Speed_Threshold 'RPM limit for BIRL test' (RPM, 0.125 rpm per count; ROM word 16000 = 2000 "
                "rpm): the underboost check (fault 729, P0299) only runs while engine_speed_state.engine_speed (e2m 819B +1E "
                "Engine_Speed, the measured speed) is at least this (lhz @ 0x52d924)."),
    59: dict(
        verdict='rename', new='ambient_air_flow_filter_coefficient',
        fn='cm848_initialization_step_3',
        sub='boost_pressure_timing_filter_state.coefficient = &boost_pressure_timing_filter_coefficient;',
        evidence="e2m 1977 +6 C_AMB_Air_Flow_Fil_Cnst (UNITLESS): the coefficient of the EMA that "
                 "cm848_calculateAmbientAndCompressorInletConditions runs on charge_flow_estimate_terms.fresh_air_mass_flow_filtered; the "
                 "old name said boost pressure timing for an ambient fresh air flow filter",
        comment="e2m 1977 +6 C_AMB_Air_Flow_Fil_Cnst 'First order filter constant used for Ambient Air flow' (UNITLESS, 1/65536 per count; "
                "64881 = 0.990 here): the weight of the previous value of the EMA boost_pressure_timing_filter_state, which "
                "cm848_calculateAmbientAndCompressorInletConditions (e2m 1921) runs on charge_flow_estimate_terms.fresh_air_mass_flow_"
                "filtered before the compressor_inlet_temperature_rise lookup; cm848_initialization_step_3 points the filter at it."),
    64: dict(
        verdict='rename', new='fuel_system_hardware_shutdown_error_count_cal',
        fn='cm848_tpu_interrupt_flag_init', sub='tpu_init_retry_count) &&',
        evidence="e2m 8C61 +0 FS_HW_Shutdown_Error_Count (UNITLESS): cm848_tpu_interrupt_flag_init counts each injection TPU "
                 "initialization in it and compares it with fuel_system_hardware_shutdown_fail_count_threshold; "
                 "cm848_protection_timer_init clears it when the shutdown check of QADC slots 54 / 55 passes; the old name lacked _cal on "
                 "an EEPROM mirror row and used init",
        comment="e2m 8C61 +0 FS_HW_Shutdown_Error_Count 'Saved number of powerdown fuel system hardware failures for valid test.' "
                "(UNITLESS; EEPROM mirror; 0 here): cm848_tpu_interrupt_flag_init counts each injection TPU channel set initialization "
                "in it (cap 255) and sets fault 399 (P0607) once it exceeds fuel_system_hardware_shutdown_fail_count_threshold "
                "(0xffff = never); cm848_protection_timer_init clears it when the engine shutdown check of QADC slots 54 / 55 against "
                "fuel_system_hardware_shutdown_error_threshold passes and decrements it after a pending restart."),
}

KEEP_NOTES = {0: None, 2: None, 6: None, 7: None, 8: None, 9: None, 10: None, 11: None, 12: None, 15: None, 16: None,
              18: None, 19: None, 20: None, 36: None, 38: None, 39: None, 43: None, 44: None, 46: None, 47: None,
              48: None, 49: None, 51: None, 52: None, 53: None, 55: None, 56: None, 57: None, 58: None, 60: None,
              61: None, 62: None, 63: None}
