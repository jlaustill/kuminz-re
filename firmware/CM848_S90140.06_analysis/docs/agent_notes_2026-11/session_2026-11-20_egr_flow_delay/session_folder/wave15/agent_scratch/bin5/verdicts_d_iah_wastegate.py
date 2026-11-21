from helpers import drift, keep, rename

ENTRIES = [
    # ---- block 162A: the intake air heater performance monitor settings (names carry the proved code roles) -----
    keep(
        "0x00064426", "intake_air_heater_performance_test_preheat_end_remaining_ticks",
        "e2m 162A +2 IAH_Band_Check_Stop_Time 'Value of IAH_Preheat_Timer when band check stops'"),
    keep(
        "0x0006442a", "intake_air_heater_performance_test_loaded_sample_delay_ticks",
        "e2m 162A +6 IAH_Grid_On_Voltage_Check_Delay 'Delay between grid-on and taking voltage sample'"),
    keep(
        "0x0006442c", "intake_air_heater_performance_test_baseline_sample_delay_ticks",
        "e2m 162A +8 IAH_Initial_Voltage_Check_Delay 'Delay between key on and taking first voltage sample'"),
    keep(
        "0x0006442e", "intake_air_heater_performance_test_loaded_voltage_lower_window_adc",
        "e2m 162A +A IAH_Lower_Battery_Counts_Band_Limit 'Allowable negative delta from initial grid-on voltage'"),
    keep(
        "0x00064430", "intake_air_heater_performance_test_drop_recovery_agreement_window_adc",
        "e2m 162A +C IAH_Max_Delta_Counts_Difference 'Max Allowable difference between grid-on and grid-off Voltage'"),
    keep(
        "0x00064438", "intake_air_heater_performance_test_loaded_voltage_upper_window_adc",
        "e2m 162A +14 IAH_Upper_Battery_Counts_Band_Limit 'Allowable positive delta from initial grid-on voltage'"),
    keep(
        "0x0006443a", "intake_air_heater_performance_test_arming_temperature_difference_limit",
        "e2m 162A +16 IAH_Max_Start_Delta_Temperature 'Max allowable temp difference between IMT and battery temp'"),
    drift(
        "0x0006443c", "intake_air_heater_performance_threshold_axis",
        "e2m 162A +18 IAH_On_Max_Time (SEC scalar, 0.1 per count) resolves to 0x6443c, but block 162C +0 IAH_Delta_Counts_X (the "
        "DEG_F x vector of the IAH threshold lookup) resolves to the same address: the ROM holds the length word 14, then the 7 "
        "breakpoints 0 / 704 / ... / 4224 (0-66 F in 1/64 F) there, and the y vector (162D, 0x6444c) follows; "
        "cm848_monitorIntakeAirHeaterPerformance passes it as the axis of lookupTableInterpolation with "
        "intake_manifold_temperature_sensor_filtered. The 11.46 block 162A ends at +16; the 11.45 record +18 has no storage of "
        "its own (dump value 14 is the length word, not 1.4 s). The name matches the code; no change"),
    # ---- block 16A1: the wastegate duty controller calibration (e2m "turbo geometry controller", C_TGC_*) --------
    rename(
        "0x003ffc98", "throttle_rate_scale_factor_cal", "wastegate_duty_integral_base_gain",
        "e2m 16A1 +0 C_TGC_I_Gain 'Turbo Control Integral Gain' (1/4096; 3072 = 0.75): cm848_calculateWastegateDutyRequest "
        "multiplies the integrator gain looked up from the charge system error (wastegate_integrator_gain_by_error_*) by it "
        ">> 12 into wastegate_duty_integral_gain (e2m 16A2 +6 TGC_Adjusted_I_Gain, 'Turbo control integral gain after "
        "adjustment'); no throttle rate is involved; _cal is wrong outside the EEPROM mirror",
        "cm848_calculateWastegateDutyRequest: uVar5 = (uint)wVar4 * (uint)throttle_rate_scale_factor_cal >> 0xc;",
        "e2m 16A1 +0 C_TGC_I_Gain 'Turbo Control Integral Gain' (UNITLESS, 1/4096 per count, 0-4; 3072 in the dump = 0.75): "
        "read-only; the base integral gain of the wastegate duty controller. cm848_calculateWastegateDutyRequest multiplies "
        "the integrator gain that wastegate_integrator_gain_by_error_axis / _values give for "
        "charge_system_error_for_turbocharger by it and shifts right 12 (0 if the product passes 0x10000000) into "
        "wastegate_duty_integral_gain (e2m 16A2 +6 TGC_Adjusted_I_Gain, 'Turbo control integral gain after adjustment'), "
        "which scales the control term fed to the integrator"),
    keep(
        "0x003ffc9e", "wastegate_duty_floor_fixed",
        "e2m 16A1 +6 C_TGC_LLim 'Low position limit for turbocharger control device'"),
    rename(
        "0x003ffca0", "governor_rpm_band_rate_current_cal", "wastegate_duty_proportional_base_gain",
        "e2m 16A1 +8 C_TGC_P_Gain 'Base proportional gain for Turbo Geometry Controller' (1/4096; 4096 = 1.0): "
        "cm848_calculateWastegateDutyRequest passes it to cm848_calculateRateLimitedValue as the gain to move to (the running "
        "gain is governor_rpm_band_rate_working, the step limit comes from e2m +A C_TGC_P_Gain_Rate_Lim = "
        "governor_rpm_error_gain_cal) and the result x the control term is wastegate_duty_proportional_term; no governor "
        "rpm band is involved; _cal is wrong outside the EEPROM mirror",
        "cm848_calculateWastegateDutyRequest: (governor_rpm_band_rate_current_cal,governor_rpm_band_rate_working,",
        "e2m 16A1 +8 C_TGC_P_Gain 'Base proportional gain for Turbo Geometry Controller' (UNITLESS, 1/4096 per count, 0-8; "
        "4096 in the dump = 1.0): read-only; the base (target) proportional gain of the wastegate duty controller. "
        "cm848_calculateWastegateDutyRequest hands it to cm848_calculateRateLimitedValue as the gain to move to: the running "
        "gain (governor_rpm_band_rate_working) approaches it by at most (ceiling - floor) x governor_rpm_error_gain_cal (e2m "
        "+A C_TGC_P_Gain_Rate_Lim) / 8 / |control term| / 100 per pass, and the gain x the control term >> 10 is "
        "wastegate_duty_proportional_term (e2m 16A2 +4 TGC_Proportional_Term)"),
    keep(
        "0x003ffca4", "wastegate_duty_ceiling_fixed",
        "e2m 16A1 +C C_TGC_ULim 'High position limit for turbocharger control device'"),
    rename(
        "0x003ffcaa", "throttle_rate_pid_gain_cal", "wastegate_duty_turbocharger_speed_derate_scale_gain",
        "e2m 16A1 +12 C_TGC_Turbo_Drt_Scale_Gain 'Turbo speed control scale gain' (signed, 1/256; 128 = 0.5): "
        "cm848_calculateWastegateDutyRequest multiplies (turbocharger speed derate error x first_error_gain) by its low half "
        "(._0_2_, lha) and / 64000, then subtracts the derivative term into first_error_proportional_derivative_term; TYPE: the "
        "row is a dword but the record is 2 bytes (signed), and ._2_2_ at 0x3ffcac is the separate e2m 16A1 +14 "
        "C_TGC_E_Brake_LLim (the floor while the engine retarder is active), so it should be split into i16 + word; _cal is "
        "wrong outside the EEPROM mirror",
        "cm848_calculateWastegateDutyRequest: (int)throttle_rate_pid_gain_cal._0_2_) / 64000) -",
        "e2m 16A1 +12 C_TGC_Turbo_Drt_Scale_Gain 'Turbo speed control scale gain' (UNITLESS, signed, 1/256 per count, 0-100; "
        "128 in the dump = 0.5): read-only; the scale gain of the turbocharger speed derate (limiter) term of the wastegate "
        "duty controller. cm848_calculateWastegateDutyRequest multiplies the turbocharger speed derate error "
        "(charge_flow_turbocharger_speed_derate_limit - turbocharger_speed) x first_error_gain by it, divides by 64000 and "
        "subtracts the derivative term (governor_pid_adjustment_output) to get first_error_proportional_derivative_term "
        "(e2m 16A2 +10). TYPE: the CSV row is a dword; this is the 2-byte word at +12 and the word at 0x3ffcac (+14 "
        "C_TGC_E_Brake_LLim, the floor while the engine retarder is active, read as ._2_2_) is another record"),
    rename(
        "0x003ffcae", "fuel_demand_delta_scale_cal", "wastegate_duty_turbocharger_speed_derate_derivative_gain",
        "e2m 16A1 +16 C_TGC_Turbo_Drt_Deriv_Gain 'Turbo speed limiter derivative gain (SEC/KRPM)' (1/2560; 17920 = 7.0): "
        "cm848_calculateWastegateDutyRequest multiplies the change of turbocharger_speed per pass (fuel_demand_delta_working) "
        "by it x 0x20 / 320000, clamps to +-0x6400 and stores governor_pid_adjustment_output = e2m 16A2 +22 "
        "TGC_Turbo_Deriv_Term; no fuel demand is involved; _cal is wrong outside the EEPROM mirror",
        "cm848_calculateWastegateDutyRequest: ((longlong)(int)((uint)fuel_demand_delta_scale_cal * 0x20) *",
        "e2m 16A1 +16 C_TGC_Turbo_Drt_Deriv_Gain 'Turbo speed limiter derivative gain (SEC/KRPM)' (UNITLESS, 1/2560 per "
        "count, 0-25; 17920 in the dump = 7.0): read-only; the derivative gain of the turbocharger speed derate (limiter) "
        "term of the wastegate duty controller. cm848_calculateWastegateDutyRequest multiplies the change of "
        "turbocharger_speed since the last pass (fuel_demand_delta_working, from the previous speed "
        "fuel_demand_quantity_snapshot) by it x 0x20 / 320000, clamps the result to +-0x6400 and stores it as "
        "governor_pid_adjustment_output (e2m 16A2 +22 TGC_Turbo_Deriv_Term, 'Turbo speed limiter derivative term')"),
    rename(
        "0x003ffcb0", "fuel_flow_rate_divisor_cal", "wastegate_duty_compressor_outlet_temperature_derate_derivative_gain",
        "e2m 16A1 +18 C_TGC_COT_Drt_Deriv_Gain 'COT limiter derivative gain (SEC/DEG_F)' (1/660; 660 = 1.0): "
        "cm848_calculateWastegateDutyRequest multiplies the change of compressor_outlet_temperature per pass by it and "
        "divides by 0x294 (= 660, the record's scale) into wastegate_duty_compressor_outlet_temperature_derate_derivative_term "
        "(e2m 16A2 +26 TGC_COT_Deriv_Term); no fuel flow is involved; _cal is wrong outside the EEPROM mirror",
        "cm848_calculateWastegateDutyRequest: uVar5 = (uint)fuel_flow_rate_divisor_cal;",
        "e2m 16A1 +18 C_TGC_COT_Drt_Deriv_Gain 'COT limiter derivative gain (SEC/DEG_F)' (UNITLESS, 1/660 per count, 0-90; "
        "660 in the dump = 1.0): read-only; the derivative gain of the compressor outlet temperature (COT) derate term of "
        "the wastegate duty controller. cm848_calculateWastegateDutyRequest multiplies the change of "
        "compressor_outlet_temperature since the last pass (fuel_flow_rate_prev_snapshot holds the previous value) by it, "
        "divides by 0x294 (= 660) and clamps to +-0x6400 into "
        "wastegate_duty_compressor_outlet_temperature_derate_derivative_term (e2m 16A2 +26 TGC_COT_Deriv_Term)"),
    rename(
        "0x003ffcb2", "fuel_flow_rate_gain_cal", "wastegate_duty_compressor_outlet_temperature_derate_scale_gain",
        "e2m 16A1 +1A C_TGC_COT_Drt_Scale_Gain 'COT limiter scale gain' (1/256; 26 = 0.10): "
        "cm848_calculateWastegateDutyRequest multiplies (compressor outlet temperature derate error x "
        "governor_trim_lookup_result = e2m 16A2 +24 TGC_COT_Drt_SET_Gain) by it, divides by 0x4000 and subtracts the "
        "derivative term into wastegate_duty_compressor_outlet_temperature_derate_error_term (e2m 16A2 +28 TGC_COT_Drt_Error); "
        "no fuel flow is involved; _cal is wrong outside the EEPROM mirror",
        "cm848_calculateWastegateDutyRequest: uVar5 = (uint)fuel_flow_rate_gain_cal;",
        "e2m 16A1 +1A C_TGC_COT_Drt_Scale_Gain 'COT limiter scale gain' (UNITLESS, 1/256 per count, 0-100; 26 in the dump = "
        "0.10): read-only; the scale gain of the compressor outlet temperature (COT) derate term of the wastegate duty "
        "controller. cm848_calculateWastegateDutyRequest multiplies the COT derate error "
        "(charge_flow_compressor_outlet_temperature_derate_limit - compressor_outlet_temperature) x "
        "governor_trim_lookup_result (the error based gain, e2m 16A2 +24 TGC_COT_Drt_SET_Gain) by it, divides by 0x4000, "
        "subtracts wastegate_duty_compressor_outlet_temperature_derate_derivative_term and clamps to +-0x6400 into "
        "wastegate_duty_compressor_outlet_temperature_derate_error_term (e2m 16A2 +28 TGC_COT_Drt_Error)"),
]
