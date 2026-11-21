# Leads for the final summary (bin 5) - final

## Function misnames (not applied automatically)
- 0x28670 cm848_processGovernorLoadCondition -> cm848_updateLowSpeedGovernorGainLogic (LSG aggressive gain logic; e2m 10EE settings, 10EF +0 LSG_Gain_Logic_Flag; no load involved)
- 0x27e4c cm848_updateSpeedProtectionLimits -> cm848_presetLowSpeedGovernorIntegrator (LSG integrator preset: e2m 1064 +4/+6/+22/+24/+26/+28, 1065 +E/+1A)
- 0xfe5c cm848_calculateFuelTimingTarget -> cm848_calculateAllSpeedGovernorThrottleReference (writes e2m 107A +0/+2/+14/+16, ASG reference from the pedal; no fuel timing)
- 0x23be0 cm848_sendJ1939ProprietaryStatus -> cm848_sendJ1939AntiTheftStatus (PGN 56360 byte of the four e2m 117F Jcomm_AT_* status fields)
- 0x233a0 cm848_j1939HandleProprietaryCommand -> e.g. cm848_j1939HandleServiceResetCommand (PGN 56832: byte 1 0x20 = OCM reset flag e2m 1094 +4, 0x30 = new tires e2m 117F +26)
- 0x51736c cm848_updateIntakeAirHeaterRunupPhase -> ...CrankPhase (e2m 8A35 +2 IAH_Phase 3 = crank)

## Out-of-bin siblings
LSG family (low speed governor; wrong governor_* names, wrong _cal outside the mirror). Proposed low_speed_governor_* names from the e2m records:
 1064: 0x4070b6 governor_speed_setpoint_integrated_init_cal (+0 Fueling_Clamp_Max_Offset); 0x4070ba governor_speed_reference_init_cal (+4 Integrator_Preset_Max_Offset);
 0x4070be governor_speed_pid_output_init_cal (+8 Integrator_Clamp_Max_Offset); 0x4070c0 governor_fuel_correction_threshold_cal (+A Integrator_Clamp_Min);
 0x4070c4 governor_integrator_offset_cal (+E Reset_RPM); 0x4070c6 governor_fuel_demand_reset_threshold_cal (+10 Reset_Fueling);
 0x4070c8 governor_speed_weight_b_scale_cal (+12 Derivative_Filter_Coefficient); 0x4070ca governor_derivative_deadband_cal (+14 Jerk_Deadband);
 0x4070cc governor_speed_derivative_scale_cal (+16 Jerk_Filter_Coefficient); 0x4070d0 governor_speed_weight_a_scale_cal (+1A Proportional_Filter_Coefficient);
 0x4070d2 governor_speed_debounce_limit_cal (+1C Reset_Delay_Time); 0x4070d6 governor_integrator_include_enable_cal (+20 No_Load_Fuel_Enable);
 0x4070dc cold_start_governor_speed_clamp_threshold_cal (+26 Preset_Accel_Limit); 0x4070de governor_fuel_demand_correction_maximum_vehicle_speed (+28 Preset_VSS_Limit).
 1065 (terms): 0x40ae96 governor_speed_weight_a = +2 LSG_Proportional_Term; 0x40ae98 governor_speed_weight_b = +4 LSG_Derivative_Term; 0x40ae9a governor_fuel_demand_correction = +6 LSG_Integral_Term;
 0x40ae9c governor_speed_error_derivative = +8 LSG_Jerk_Term (the jerk, not the derivative); 0x40ae9e governor_speed_setpoint_integrated = +A Fueling_Clamp_Max; 0x40aea0 governor_speed_pid_output_working = +C Integrator_Clamp_Max;
 0x40aea2 governor_speed_reference_computed = +E Integrator_Preset_Max; 0x40aea4 / 0x40aea6 / 0x40aea8 governor_pid_gain_factor_a / _b / governor_speed_pid_gain = +10 QD / +12 QI / +14 QP adjustment.
 Gain sets (4 words P, I, D, J read through governor_setpoint_table_ptr): default set 10EC: 0x4070e6 governor_setpoint_table_a (P), 0x4070e8 governor_j1939_d_gain_default_cal (is the I gain), 0x4070ea governor_j1939_p_gain_default_cal (is the D gain), 0x4070ec governor_j1939_i_gain_default_cal (is the J gain);
 working set 10ED: 0x40ae76 governor_speed_setpoint_raw (is the P gain), 0x40ae78 governor_d_gain_from_table (is the I gain), 0x40ae7a governor_p_gain_from_table (is the D gain), 0x40ae8a governor_j1939_gain_extra_working (is the J gain).
 10EE / 10EF: 0x4070b4 governor_cold_start_coolant_threshold_cal (= +1C Aggressive_Inhibit_Coolant_Temp, wrong _cal); 0x40ae74 governor_enabled_flag (= 10EF +0 LSG_Gain_Logic_Flag, 0 = ALLOW aggressive gains, so "enabled" reads backwards).
Comment fix: 0x40a034 cruise_driver_fault_match_debounce_threshold says "Other outputs: fault_match_debounce_threshold_std" -> auxiliary_driver_fault_match_debounce_threshold.
0x3fd51c j1939_pgn_priority_cal = e2m 1292 +0 Application_Identifier (EEPROM 0x9a holds ASCII "00"; field 6 of the PGN 65242 software ID message, next to the ECM identifier "C6").
0x408e6e fuel_demand_corrected_step_cal = e2m 1189 +22 Cruise_RSG_Min_Fuel_Ramp_Rate (twin of 0x3feff0, wrong _cal).
AT family (J1939 anti-theft, e2m 117F / 117D): 0x3fdd80 governor_prop_status_bits_1 (+14 Component_Status), 0x3fdd86 governor_prop_status_byte_b (+1A Encryption_Seed), 0x3fdd8e governor_prop_status_pending_flag (+22 Send_Status_Report), 0x3fdd90 governor_prop_status_bits_3 (+24 Status_Of_Request), 0x40a2c2 j1939_prop_status_tx_state (117D +5A Jcomm_AT_Transaction): all should read j1939_anti_theft_* (+ _cal in the mirror).
Wastegate duty controller (e2m 16A1 / 16A2): 0x3ffca2 governor_rpm_error_gain_cal (+A C_TGC_P_Gain_Rate_Lim, wrong _cal); 0x3ffcac (+14 C_TGC_E_Brake_LLim, no row, inside dword throttle_rate_pid_gain_cal); 0x3fa190 governor_rpm_band_rate_working (running P gain);
 0x3fa1a6 governor_rpm_band_rate_target; 0x3fa176 fuel_demand_delta_working (turbocharger speed change per pass); 0x3fa184 fuel_demand_quantity_snapshot (previous turbocharger speed); 0x3fa182 fuel_flow_rate_prev_snapshot (previous COT);
 0x40a3e0 governor_pid_adjustment_output (16A2 +22 TGC_Turbo_Deriv_Term); 0x40a3e2 governor_trim_lookup_result (16A2 +24 TGC_COT_Drt_SET_Gain).
IAH "runup" = the crank phase (e2m 8A35 +2 IAH_Phase 3): 0x3fce3f intake_air_heater_runup_holdoff_countdown, intake_air_heater_runup_elapsed_ticks, intake_air_heater_runup_rpm_below_count follow the old word; crank would match intake_air_heater_crank_time_limit.
PCI: 0x40b4d0 pci_transmit_message_19_byte_4 -> pci_transmit_message_19_engine_type_sales_code (source row renamed vehicle_engine_type_sales_code).
CM550 twin: 0x80a9e0 (unnamed _DAT_0080a9e0, written 0 by the shared initializeEngineSpeedLimitDefaults) = e2m 117D +18 PP_Active_Selection (names should agree: programmable_power_active_selection).

## Type issues
- 0x4070aa: byte, but the base of a 4-word signed record {P, I, D, J}; same layout at 0x4070e6 and 0x40ae76 -> i16[4] / one struct.
- 0x3ffcaa: dword, but e2m 16A1 +12 (2 bytes signed, lha) and 0x3ffcac is +14 C_TGC_E_Brake_LLim -> i16 + word.
- COT units (comment fix): the CSV comments call compressor_outlet_temperature (0x40a616) 1/64 F and charge_flow_compressor_outlet_temperature_derate_limit (0x3ff720) "14080 = 220 F at 1/64"; the code
  (cm848_estimateCompressorOutletTemperature: 1/2048 ratio x 1/64 F Rankine >> 12, floor 0xc680 = -460 x 32) and the e2m (C_CHL_COT_Drt_Limit, Compressor_Outlet_Tmptr, C_TPE_COT_Global_Default) agree on 1/32 F:
  the limit is 14080 / 32 = 440 F, the dump COT 1662 = 52 F, the default 3200 = 100 F.
- 0x6443c: the row is the word[8] axis (correct for the code); record 162A +18 has no storage in 11.46.
