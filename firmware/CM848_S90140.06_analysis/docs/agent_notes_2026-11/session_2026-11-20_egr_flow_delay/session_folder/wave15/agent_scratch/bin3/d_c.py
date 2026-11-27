"""Rows 47-59: e2m blocks 804A, 8A0E, 8A14, 8C33, 8C5B, 8C73, 8C75."""

ROWS = {}

RETYPED = " | retyped word -> i16 2026-11-20 (e2m signed, every load lha)"


def rename(address, new, evidence, code_quote, comment):
    ROWS[address] = {"verdict": "confirmed", "new": new, "evidence": evidence, "code_quote": code_quote, "comment": comment}


def keep(address, e2m_note):
    ROWS[address] = {"verdict": "keep", "e2m_note": e2m_note}


# ---- 804A ----
rename(
    "0x004090cc",
    "injection_end_limit_exceeded_count_threshold",
    "e2m 804A +0 EOI_Limit_Threshold (UNITLESS, 0 in the dump): cm848_updateEngineStatusTimers sets fault bit 325 (fault_detected_bits_320_to_335 | 0x20, no DTC slot) when the persistence counter injection_timing_count_a (e2m 804B +0 EOI_Limit_Count, counted while TPUA_CH2 / CH7 PARAM4 bit 15 flags the end of injection limit) reaches it; 0x4090cc is RAM, so the old _cal was wrong; the old name had no injection end limit wording",
    "cm848_updateEngineStatusTimers: if (injection_timing_count_a_max_cal <= injection_timing_count_a) {",
    "e2m 804A +0 EOI_Limit_Threshold 'Threshold where EOI limit counter causes error.' (UNITLESS, 0..65535; 0 in the dump): the count at which the end of injection (EOI) limit violation counter sets its fault. "
    "cm848_updateEngineStatusTimers counts injection_timing_count_a (e2m 804B +0 EOI_Limit_Count 'Persistence counter for EOI limit exceeded') up by 1 on each pass where bit 15 of TPUA_CH2_PARAM4 / TPUA_CH7_PARAM4 flags a violation (it clears both flags) and down by 1 otherwise; "
    "when the count reaches this threshold it sets fault bit 325 (fault_detected_bits_320_to_335 bit 0x20, no DTC slot). Read-only cal in working RAM, so no _cal.",
)

# ---- 8A0E ----
rename(
    "0x00408728",
    "cruise_rpm_ratio_integral_limit",
    "e2m 8A0E +A Cruise_N_V_Ratio_Int_Tolerance (RPM/SEC, 11 in the dump): governor_cruise_deniedStatus_update denies cruise with status 11 (clutch) when |cruise_speed_error_integral| reaches it on a manual transmission (transmission_type_cal < 1); that integral accumulates the change of cruise_rpm_ratio_ema (governor_cruise_speedError_integrate), the engine speed / vehicle speed (N/V) ratio, not a speed error; the neighbours are cruise_rpm_ratio_*",
    "governor_cruise_deniedStatus_update: if ((uint)cruise_speed_error_integral_limit <= (uVar2 & 0xffff)) {",
    "e2m 8A0E +A Cruise_N_V_Ratio_Int_Tolerance 'Level at which N_V Ratio integrator will cause a kick out' (RPM/SEC 0.125 per count, 0..100; 11 in the dump): magnitude limit of the engine speed / vehicle speed ratio integrator (e2m 8A0F +0 Cruise_N_V_Ratio_Int = cruise_speed_error_integral: "
    "governor_cruise_speedError_integrate adds the change of cruise_rpm_ratio_ema to it and clears it after cruise_steady_debounce_count steady passes). governor_cruise_deniedStatus_update denies cruise with cruise_control_denied_status 0xb (11 = clutch in the DRB S/C denied status list; the ratio window cruise_rpm_ratio_min / _max is status 10) when |integral| >= this on a manual transmission (transmission_type_cal < 1). "
    "ROM-initialized cal in working RAM, so no _cal.",
)

# ---- 8A14 ----
rename(
    "0x0040869e",
    "air_conditioning_control_configuration",
    "e2m 8A14 +4 AC_Control_Configuration 'Defines which AC control algorithm runs; 0=BR truck, 1=DR truck' (1 in the dump): hpcr_fuel_mode_state_transition runs engine_protection_fuelMass_rpmCheck for 0 and engine_protection_conditionCode_evaluate for 1, and both set / clear logical output request 0x26 (38, the A/C clutch request) from the A/C pressure and engine speed; the old name hpcr_protection_eval_mode is the wrong domain",
    "hpcr_fuel_mode_state_transition: if (hpcr_protection_eval_mode == 0) {",
    "e2m 8A14 +4 AC_Control_Configuration 'Defines which AC control algorithm runs; 0=BR truck, 1=DR truck' (UNITLESS 0..2; 1 in the dump = the DR truck algorithm): hpcr_fuel_mode_state_transition (the A/C clutch control dispatcher) runs engine_protection_fuelMass_rpmCheck for 0 "
    "(a short gate on engine speed, the A/C switch and the A/C pressure) and engine_protection_conditionCode_evaluate for 1 (the full gate logic with condition codes 1-15); both set / clear logical output request 0x26 (38), the A/C clutch request. Read-only ROM-copied cal.",
)
rename(
    "0x004086a0",
    "air_conditioning_cycle_off_time",
    "e2m 8A14 +6 AC_Cycle_Off_Time (SEC 0.1, 0 in the dump): engine_protection_conditionCode_evaluate (the A/C clutch request, logical output 0x26) restarts protection_event26_post_fault_holdoff_count_b when the clutch request drops and refuses a new request (condition code 13) until the count reaches this limit; the old name said protection event 26 holdoff, but the block is the A/C control",
    "engine_protection_conditionCode_evaluate: if (protection_event26_post_fault_holdoff_count_b < protection_event26_holdoff_limit_b) {",
    "e2m 8A14 +6 AC_Cycle_Off_Time 'Minimum amount of time ac driver will be in off state' (SEC 0.1 per count, 0..255; 0 in the dump): after the A/C clutch request drops, engine_protection_conditionCode_evaluate (the DR truck A/C algorithm, logical output 0x26) restarts the pass counter protection_event26_post_fault_holdoff_count_b "
    "and refuses a new request (condition code 13) until the count reaches this limit. Read-only ROM-copied cal.",
)
rename(
    "0x004086a2",
    "air_conditioning_cycle_on_time",
    "e2m 8A14 +8 AC_Cycle_On_Time (SEC 0.1, 70 = 7.0 s in the dump): engine_protection_conditionCode_evaluate (the A/C clutch request, logical output 0x26) restarts protection_event26_post_fault_holdoff_count_a when the clutch request rises and refuses a new request (condition code 12) until the count reaches this limit; the old name said protection event 26 holdoff, but the block is the A/C control",
    "engine_protection_conditionCode_evaluate: if (protection_event26_post_fault_holdoff_count_a < protection_event26_holdoff_limit_a) {",
    "e2m 8A14 +8 AC_Cycle_On_Time 'AC driver can be turned on once every AC_Cycle_On_Time seconds' (SEC 0.1 per count, 0..255; 70 = 7.0 s in the dump): after the A/C clutch request rises, engine_protection_conditionCode_evaluate (the DR truck A/C algorithm, logical output 0x26) restarts the pass counter protection_event26_post_fault_holdoff_count_a "
    "and refuses a new request (condition code 12) until the count reaches this limit. Read-only ROM-copied cal.",
)
rename(
    "0x004086a8",
    "air_conditioning_high_pressure_off_threshold",
    "e2m 8A14 +E AC_High_Pressure_Off (PSI 1/128, 60928 = 476.0 psi in the dump): engine_protection_conditionCode_evaluate clears its pressure gate (condition code 4) when air_conditioning_pressure_sensor_filtered rises above it, and engine_protection_fuelMass_rpmCheck compares the pressure with it for the A/C clutch request; the neighbours are air_conditioning_*_threshold",
    "engine_protection_conditionCode_evaluate: if (protection_event26_fuel_qty_gate_upper < air_conditioning_pressure_sensor_filtered) {",
    "e2m 8A14 +E AC_High_Pressure_Off 'If AC_Pressure greater than this value, ac driver will be turned off' (PSI 1/128 per count, 0..500; 60928 = 476.0 psi in the dump): the A/C pressure above which the clutch request is dropped. "
    "engine_protection_conditionCode_evaluate clears its pressure gate (protection_event26_fuel_qty_gate_flag, condition code 4) when air_conditioning_pressure_sensor_filtered rises above it and sets the gate again below air_conditioning_high_pressure_on_threshold; "
    "engine_protection_fuelMass_rpmCheck (the BR truck algorithm) requests the clutch while the A/C switch is on or the pressure is below it. Read-only ROM-copied cal.",
)

# ---- 8C33 ----
rename(
    "0x00408ad2",
    "converter_clutch_rationality_fail_count_limit",
    "e2m 8C33 +6 TCC_Rationality_Fail_Count_Limit (CNTS, 1 byte, 3 in the dump): cm848_monitorConverterClutchAndOverdrivePerformance (P1740) caps converter_clutch_rationality_fail_count at it and sets fault bit 319 (fault_detected_bits_304_to_319 | 0x8000 = P1740) when the count reaches it; the sibling is converter_clutch_rationality_pass_count_limit; the old name said protection fuel derate",
    "cm848_monitorConverterClutchAndOverdrivePerformance: if (protection_fuel_derate_increment_counter_max <= converter_clutch_rationality_fail_count) {",
    "e2m 8C33 +6 TCC_Rationality_Fail_Count_Limit 'Count limit when TCC rationality error will be set' (CNTS, 1 byte, 0..255; 3 in the dump): cm848_monitorConverterClutchAndOverdrivePerformance (P1740, converter clutch / overdrive performance) caps converter_clutch_rationality_fail_count at it "
    "and, when the count reaches it, sets fault bit 319 (fault_detected_bits_304_to_319 bit 0x8000 = P1740) and monitor state 3. Read-only ROM-copied cal.",
)
rename(
    "0x00408ad3",
    "converter_clutch_rationality_minimum_ratio_delta_sum",
    "e2m 8C33 +7 TCC_Rationality_Min_Ratio_Delta (UNITLESS, signed word at the odd address 0x408ad3, 1/256, 13 in the dump): cm848_monitorConverterClutchAndOverdrivePerformance compares converter_clutch_rationality_ratio_delta_sum (the running sum of ratio deltas, cm848_accumulateConverterClutchRatioDeltaSum, 'a plain running sum, not a PID integrator') with it to count a failure and to skip the overdrive lockup check; the old name said protection PID integrator",
    "cm848_monitorConverterClutchAndOverdrivePerformance: if ((converter_clutch_rationality_ratio_delta_sum < protection_pid_integrator_threshold) ||",
    "e2m 8C33 +7 TCC_Rationality_Min_Ratio_Delta 'Min RPM/OSS ratio sum to pass TCC rationality Monitor' (UNITLESS 1/256 per count, signed 2 bytes at the odd address 0x408ad3, 0..128; 13 in the dump = 0.05): the minimum sum of the engine speed / output shaft speed ratio deltas. "
    "cm848_monitorConverterClutchAndOverdrivePerformance counts a failure (converter_clutch_rationality_fail_count) when converter_clutch_rationality_timer has reached converter_clutch_rationality_maximum_engagement_time and converter_clutch_rationality_ratio_delta_sum (accumulated by cm848_accumulateConverterClutchRatioDeltaSum) is still below it, "
    "and skips the lockup gear ratio check while the sum is below it. A threshold on a plain running sum, not a PID integrator. Read-only ROM-copied cal." + RETYPED,
)
rename(
    "0x00408ade",
    "converter_clutch_overdrive_rationality_time",
    "e2m 8C33 +12 TCC_OD_Rationality_Time (CNTS, 1 byte, 23 in the dump): cm848_monitorConverterClutchAndOverdrivePerformance keeps converter_clutch_rationality_timer counting up to it and, with the overdrive solenoid request on, runs the lockup gear ratio check (converter_clutch_lockup_gear_ratio against the fourth gear limit) only once the timer has reached it; the old name said protection PID step count",
    "cm848_monitorConverterClutchAndOverdrivePerformance: (converter_clutch_rationality_timer < protection_pid_step_count_threshold_b)) {",
    "e2m 8C33 +12 TCC_OD_Rationality_Time 'Time after lockup to perform OD rationality check' (CNTS, 1 byte, 0..255; 23 in the dump): cm848_monitorConverterClutchAndOverdrivePerformance keeps converter_clutch_rationality_timer counting up to it (past converter_clutch_rationality_maximum_engagement_time) "
    "and, with the overdrive solenoid request on, runs the overdrive lockup gear ratio check (converter_clutch_lockup_gear_ratio against converter_clutch_lockup_fourth_gear_ratio_limit) only once the timer has reached it; with the request off the third gear check (converter_clutch_lockup_third_gear_minimum_ratio / _maximum_ratio) already runs at converter_clutch_rationality_maximum_engagement_time. Read-only ROM-copied cal.",
)

# ---- 8C5B ----
keep(
    "0x0040b576",
    "e2m 8C5B +6 RE_PN_Crank_Park_Timer 'Crank in Park timer for PN diagnostics'",
)

# ---- 8C73 ----
rename(
    "0x00408f28",
    "cylinder_balance_service_coolant_temperature_maximum",
    "e2m 8C73 +0 CBD_Service_Max_Coolant_Temp (DEG_F, signed, 16000 = 250.0 F in the dump): cm848_runCylinderContributionTest sets cylinder_contribution_test_status 2 (requested but conditions fail) when the coolant temperature is at or above it; engine_sync_* is the wrong domain, and 0x408f28 is RAM, so the old _cal was wrong; the neighbours are cylinder_balance_service_*",
    "cm848_runCylinderContributionTest: (engine_sync_coolant_upper_threshold_cal <=",
    "e2m 8C73 +0 CBD_Service_Max_Coolant_Temp 'Cylinder performance test disabled above this coolant temp' (DEG_F 1/64 signed, -50..300; 16000 = 250.0 F in the dump): the upper edge of the coolant temperature window of the cylinder contribution test: "
    "cm848_runCylinderContributionTest sets cylinder_contribution_test_status 2 (requested but its conditions fail) when the coolant temperature is at or above it. Read-only ROM-copied cal in working RAM, so no _cal." + RETYPED,
)
rename(
    "0x00408f2a",
    "cylinder_balance_service_coolant_temperature_minimum",
    "e2m 8C73 +2 CBD_Service_Min_Coolant_Temp (DEG_F, signed, 5120 = 80.0 F in the dump): cm848_runCylinderContributionTest sets cylinder_contribution_test_status 2 (requested but conditions fail) when the coolant temperature is at or below it; engine_sync_* is the wrong domain, and 0x408f2a is RAM, so the old _cal was wrong; the neighbours are cylinder_balance_service_*",
    "cm848_runCylinderContributionTest: engine_sync_coolant_lower_threshold_cal ||",
    "e2m 8C73 +2 CBD_Service_Min_Coolant_Temp 'Cylinder performance test disabled below this coolant temp' (DEG_F 1/64 signed, -50..300; 5120 = 80.0 F in the dump): the lower edge of the coolant temperature window of the cylinder contribution test: "
    "cm848_runCylinderContributionTest sets cylinder_contribution_test_status 2 (requested but its conditions fail) when the coolant temperature is at or below it. Read-only ROM-copied cal in working RAM, so no _cal." + RETYPED,
)

# ---- 8C75 ----
keep(
    "0x0040b66a",
    "e2m 8C75 +2 Wastegate_Pressure_Control_Driver_Inhibit_Timer 'Timer value of Wastegate Off cycle time when short or open circuit.'",
)
