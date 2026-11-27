"""Blocks 8A0F, 8C35, 8C5D, 8C5F, 8D37 (bin records 52-63)."""
ENTRIES = []


def keep(address, name, note):
    ENTRIES.append({"kind": "global", "verdict": "keep", "address": address, "old": name, "new": name, "e2m_note": note})


ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0040b204",
    "old": "cruise_speed_error_integral", "new": "cruise_rpm_ratio_integral",
    "evidence": "e2m 8A0F +0 Cruise_N_V_Ratio_Int 'Engine Speed/Vehicle Speed ratio integrator for cruise control': "
                "governor_cruise_speedError_integrate adds (cruise_rpm_ratio_ema_prev - cruise_rpm_ratio_ema) to it while the engine "
                "speed / vehicle speed ratio moves and zeroes it after cruise_steady_debounce_count steady passes; "
                "governor_cruise_deniedStatus_update denies cruise with code 11 (CLU, the clutch cutout) when its magnitude reaches "
                "cruise_speed_error_integral_limit, only for transmission_type_cal below 1; it integrates a ratio change, not a "
                "speed error",
    "code_quote": "governor_cruise_speedError_integrate: cruise_speed_error_integral + (cruise_rpm_ratio_ema_prev - cruise_rpm_ratio_ema);",
    "comment": "e2m 8A0F +0 Cruise_N_V_Ratio_Int 'Engine Speed/Vehicle Speed ratio integrator for cruise control' (address from the "
               "ECU's parameter ID table) (signed, 0.125 per count, -100..100; 0 in the dump): the running sum of the change of the "
               "engine speed to vehicle speed (N/V) ratio. governor_cruise_speedError_integrate adds (cruise_rpm_ratio_ema_prev - "
               "cruise_rpm_ratio_ema) while the ratio is moving (change at or above cruise_ratio_steady_threshold) and zeroes it "
               "once the ratio has been steady for cruise_steady_debounce_count passes; "
               "governor_fuel_mode_initialization zeroes it too. governor_cruise_deniedStatus_update denies cruise with code 11 "
               "(CLU, the clutch entry of the DRB cutout / denied status order RD / DIS / MUX / VSS / BKER / OFF / BK / CAN / RS / "
               "RPM / NV / CLU / PN) when its magnitude reaches cruise_speed_error_integral_limit (e2m 8A0E +A "
               "Cruise_N_V_Ratio_Int_Tolerance 'Level at which N_V Ratio integrator will cause a kick out'), only for manual "
               "transmissions (transmission_type_cal below 1): a clutch slip detector, not a speed error. Working RAM, never _cal; "
               "retyped word -> i16 2026-11-20 (e2m signed, every load lha).",
})

keep("0x00409e92", "egr_delta_pressure_high_reading_check_dwell_limit",
     "e2m 8C35 +E EGR_DP_Low_Stabilized_Time_Threshold 'Time required for high error conditions to exist before in range test' "
     "(the e2m 'Low' records are the low speed / load / valve position conditions that test for a HIGH reading; 100 counts of "
     "0.1 s = 10 s)")
keep("0x00409e94", "egr_delta_pressure_low_reading_check_dwell_limit",
     "e2m 8C35 +10 EGR_DP_High_Stabilized_Time_Threshold 'Time required for low error conditions to exist before in range test' "
     "(the e2m 'High' records are the high speed / load / valve position conditions that test for a LOW reading; 100 counts of "
     "0.1 s = 10 s)")
keep("0x00409e9c", "egr_delta_pressure_high_reading_check_recovery_limit",
     "e2m 8C35 +18 EGR_DP_Low_Pass_Time 'Time required for low side DP rationality test to pass' (the low side test is the high "
     "reading check; 100 counts of 0.1 s = 10 s)")
keep("0x00409ea6", "egr_delta_pressure_low_reading_check_recovery_limit",
     "e2m 8C35 +22 EGR_DP_High_Pass_Time 'Time required for high side DP rationality test to pass' (the high side test is the low "
     "reading check; 100 counts of 0.1 s = 10 s)")
keep("0x00409eaa", "egr_delta_pressure_pre_start_check_dwell_limit_a",
     "e2m 8C35 +26 EGR_DP_Startup_Stabilized_Time_Threshold 'Time required for EGR delta pressure to stabilize before startup test' "
     "(100 counts of 0.1 s = 10 s; the other half of the pre-start dwell is +16 EGR_DP_Wait_Time, "
     "egr_delta_pressure_pre_start_check_dwell_limit_b)")
keep("0x0005c668", "wastegate_solenoid_read_back_fault_debounce_limit",
     "e2m 8C5D +0 Wastegate_Pressure_Control_Driver_Error_Count 'Nnumber of consecutive errors for error bit set.' (100 passes; the "
     "wastegate pressure control driver is the wastegate solenoid output)")
keep("0x00408a52", "engine_to_vehicle_speed_ratio_invalid_maximum_vehicle_speed",
     "e2m 8C5F +0 Tcase_NV_Launch_MPH 'Tcase_Launch_Flag may get set if vehicle speed > this' (1280 = 5 mph; the code sets the "
     "invalid / launch flag only BELOW it (with a ratio deviation above +A; also at zero speed) and clears it above it, so the "
     "e2m text has the direction reversed; the other 8C5F rows match)")
keep("0x00408a5a", "engine_to_vehicle_speed_ratio_stable_maximum_deviation",
     "e2m 8C5F +8 Tcase_NV_Avg_Change_Max 'Tcase_NV_Inst_Percent_Change < this, clear Tcase_Launch_Flag' (5120 = 20 percent at 1/256 "
     "percent per count)")
keep("0x00408a60", "engine_to_vehicle_speed_ratio_high_threshold",
     "e2m 8C5F +E Tcase_NV_Low 'if Tcase_NV_Average > this, set Tcase_Low_range_Flag' (2400 = 300 rpm per mph; the low range flag "
     "is engine_to_vehicle_speed_ratio_high_flag)")
keep("0x00408982", "fuel_quantity_limit_rail_pressure_shortfall_ramp_step",
     "e2m 8D37 +2 Low_Fuelpr_Neg_Slew_Rate 'Amount by which fuel will be reduced every 40 ms when low fuelpr active' (1 count = "
     "0.068 mm3 per pass; type note: the load is lha, a signed halfword, while the record is unsigned and the row is word; the "
     "value is 1 so it makes no difference)")
keep("0x00408984", "fuel_quantity_limit_rail_pressure_shortfall_threshold",
     "e2m 8D37 +4 Low_Fuelpr_Offset_For_Derate 'Fuel Pressure delta setpoint minus measure where low fuelpr derate activates' (512 "
     "counts = 25 MPa at 0.0488 MPa per count)")
