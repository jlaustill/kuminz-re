"""Round 9 stage A (label-only): the e2m RE ROM blocks and tables in their memory order.
- e2m column 5 numbers every ROM calibration block in memory order (RAM blocks have 0000). Walking the RE tables from the
  stage A anchor 0x407876 (0B43 = 8BBE, RE_AH_Boost_Curve_1_2_OSS_Axis) and sizing each from its length word in the RAM
  dump lands on an existing word[N] row of exactly that size for every table through 0B98 (RE_WOT_Curve at 0x407f0c):
  58 tables, plus the two 2-D grids whose boost axis 11.45 keeps in another block (8CA3 / 8D07) but 11.46 puts inline.
  Each table's users in the code are the mode its record names (walk_tables.py, walk_0b43.csv). 11.46 then inserts
  tables 11.45 does not have: the manual low curve at 0x407f22 and the exhaust brake versions at 0x4080b0-0x4082f3.
- 8BBB at 0x4077f6 (+00..+14; from +16 it would overlap 8BBC, so 11.46 lacks its tow / brake / exhaust brake 4-3 tail),
  8BB5 at 0x408ae0 (+00..+4E: every word's user is the function its record names), 8BBD at 0x40b0ae (+00..+38, which also
  confirms round 8 stage A's code names).
- The cm848_throttle* family is the governor pressure solenoid controller (8BB5's PID and VFS words)."""

GLOBALS = [
    # 8BB5 (rows that exist)
    ("0x00408aec", "governor_pressure_sensor_offset_maximum",
     "e2m 8BB5 +0C RE_Transducer_Offset_Max ('Max transducer offset possible'): 2048 = 16 psi; "
     "cm848_learnGovernorPressureSensorOffset uses it when the reading is above it (the old name said low)"),
    ("0x00408af0", "governor_pressure_derivative_gain_numerator",
     "e2m 8BB5 +10 RE_K_D_Num ('PID constant - numerator for the derivative term in gov pres control'): 24"),
    ("0x00408b1c", "governor_pressure_integral_period",
     "e2m 8BB5 +3C RE_PID_Loop_Limit ('Number of loops the gov pres error is summed before int action is taken'): 35; "
     "reloads governor_pressure_integral_period_counter"),
    ("0x00408b27", "governor_pressure_solenoid_duty_inversion",
     "e2m 8BB5 +47 RE_VFS_PWM_Driver_Inversion ('1=invert RE_VFS_PWM_On_Time before command duty cycle'): 1 here, so "
     "the duty sent is 0x6400 - governor_pressure_controller_output"),
    ("0x00408b28", "governor_pressure_sensor_offset_minimum",
     "e2m 8BB5 +48 RE_Transducer_Offset_Min ('Min transducer offset possible'): 13; the old name said high"),
    ("0x00408b2a", "governor_pressure_solenoid_frequency",
     "e2m 8BB5 +4A RE_VFS_PWM_Driver_Frequncy ('Frequency of the VFS PWM Driver'): 671 Hz"),
    # 8BBB (rows that exist)
    ("0x004077fe", "overdrive_switch_power_on_delay_time",
     "e2m 8BBB +08 RE_OD_Delay ('Poweron Delay Time used to test Transmission_Overdrive_Switch'): 50 = 0.5 s; "
     "cm848_processOverdriveSwitchAndShift"),
    # 8BBD
    ("0x0040b0d6", "transmission_anti_hunt_minimum_throttle_interpolated",
     "e2m 8BBD +28 RE_Min_AH_Throttle ('interpolated throttle for anti-hunt determination'): the RE_TPS_Min_* curve value "
     "for the gear (cm848_selectGovernorPressureNormal)"),
    ("0x0040b0d8", "transmission_anti_hunt_maximum_throttle_interpolated",
     "e2m 8BBD +2A RE_Max_AH_Throttle ('interpolated throttle for anti-hunt determination'): the RE_TPS_Max_* curve value"),
    ("0x0040b0e2", "transmission_4th_gear_lockup_boost_pressure",
     "e2m 8BBD +34 RE_Lockup_4th_Boost_Pressure ('Value used for boost pressure axis of 4th lockup curve'): the y input "
     "of the 4th gear and cruise lockup grids; cm848_initializeTransmissionShiftLogic sets it to the intake manifold "
     "pressure"),
    ("0x0040b0e4", "transmission_3_4_shift_after_3rd_gear_lockup_flag",
     "e2m 8BBD +36 RE_Transition_3_4_Lockup ('Flag indicates 3-4 shift occurred after 3rd-gear lockup'): "
     "cm848_applyConverterLockupSchedule / cm848_applyConverterUnlockConditions"),
    # the 8C17 transition timer
    ("0x0040b132", "transmission_3_4_transition_timer",
     "e2m 8C17 +30 RE_Transition_3_4_Timer: reloaded from transmission_3_4_transition_time (8BBB +04 "
     "RE_Transition_3_4_Timer_Max, 'Timer value used to delay ratio calc after engaging overdrive') when the "
     "overdrive solenoid turns on; counted down in cm848_decrementTransmissionTimers"),
    # the governor pressure controller's RAM
    ("0x0040b596", "governor_pressure_error_change",
     "The governor pressure error change for the derivative term (cm848_calculateGovernorPressureDerivativeTerm)"),
    ("0x0040b59a", "governor_pressure_error_sum",
     "Sum of the governor pressure error over governor_pressure_integral_period passes; "
     "cm848_applyGovernorPressureIntegralTerm turns it into governor_pressure_integral_term and clears it"),
    ("0x003fcf0c", "governor_pressure_integral_period_counter",
     "Passes left in the integral period: cm848_applyGovernorPressureIntegralTerm counts it down and reloads it from "
     "governor_pressure_integral_period; cm848_initializeGovernorPressureControl sets it"),
    ("0x0040b0fa", "governor_pressure_sensor_calibration_flags",
     "e2m 8C19 +12 (RE_Transducer_Cal_Complete 'Indicates trans oil pressure sensor offset has been learned', "
     "RE_Transducer_Out_Of_Range 'Indicates trans oil pressure sensor is OOR'): cm848_learnGovernorPressureSensorOffset "
     "sets bit 0 and clears bit 1 when the reading is inside the offset limits, sets both when it is not"),
    # the walked tables
    ("0x004078b6", "governor_pressure_cold_curve_axis", "e2m 8BC2 RE_Cold_OSS_Axis: output shaft speed (walk 0B47)"),
    ("0x004078d0", "governor_pressure_cold_curve_values",
     "e2m 8BC3 RE_Cold_Curve ('Governor pressure vs OSS when cold (Trans temp < RE_T_Trans_Cold)'): cm848_selectGovernorPressureCold"),
    ("0x004078ea", "transmission_cruise_3_4_upshift_throttle_axis", "e2m 8BC4 RE_Cruise_3_4_OSS_Axis (walk 0B49)"),
    ("0x004078fc", "transmission_cruise_3_4_upshift_throttle_values",
     "e2m 8BC5 RE_Cruise_3_4 ('TPS vs OSS which defines 3-4 upshift point in cruise mode'): below it the cruise mode "
     "requests the 3-4 (cm848_selectGovernorPressureCruise)"),
    ("0x0040790e", "transmission_cruise_4_3_downshift_throttle_axis", "e2m 8BC6 RE_Cruise_4_3_OSS_Axis (walk 0B4B)"),
    ("0x00407920", "transmission_cruise_4_3_downshift_throttle_values",
     "e2m 8BC7 RE_Cruise_4_3 ('TPS vs OSS which defines the 4-3 downshift point in cruise mode'): at or above it the "
     "cruise mode requests the 4-3"),
    ("0x00407932", "governor_pressure_cruise_curve_axis", "e2m 8BC8 RE_Cruise_OSS_Axis (walk 0B4D)"),
    ("0x00407950", "governor_pressure_cruise_curve_values",
     "e2m 8BC9 RE_Cruise_Curve ('Governor press vs OSS in cruise mode'): pressure state 3"),
    ("0x0040796e", "transmission_low_range_upshift_target_engine_speed_axis",
     "e2m 8BCA RE_ERPM_Low_Range_Target_Throttle_Axis (walk 0B4F)"),
    ("0x00407980", "transmission_low_range_upshift_target_engine_speed_values",
     "e2m 8BCB RE_ERPM_Low_Range_Target ('Low range upshift target erpm as function of throttle'): "
     "cm848_selectGovernorPressureLowRange"),
    ("0x00407992", "governor_pressure_fuel_economy_curve_axis", "e2m 8BCC RE_Fuel_Economy_OSS_Axis (walk 0B51)"),
    ("0x004079ac", "governor_pressure_fuel_economy_curve_values",
     "e2m 8BCD RE_Fuel_Economy_Curve ('Governor Press vs OSS when TPS < RE_TPS_Fuel_Economy'): "
     "cm848_selectGovernorPressureBaseCurve"),
    ("0x00407a0e", "transmission_3rd_gear_lockup_minimum_output_speed_axis",
     "e2m 8BD2 RE_Lockup_Cltemp_3_Temp_Axis: coolant temperature (walk 0B57)"),
    ("0x00407a20", "transmission_3rd_gear_lockup_minimum_output_speed_values",
     "e2m 8BD3 RE_Lockup_Cltemp_3 ('Min OSS for lockup vs coolant temp in 3rd gear'): cm848_applyConverterLockupSchedule"),
    ("0x00407a32", "transmission_4th_gear_lockup_minimum_output_speed_axis",
     "e2m 8BD4 RE_Lockup_Cltemp_4_Temp_Axis: coolant temperature (walk 0B59)"),
    ("0x00407a44", "transmission_4th_gear_lockup_minimum_output_speed_values",
     "e2m 8BD5 RE_Lockup_Cltemp_4 ('Min OSS for lockup vs coolant temp in 4th gear')"),
    ("0x00407a56", "transmission_3rd_gear_low_range_lockup_maximum_throttle_axis",
     "e2m 8BD6 RE_Lockup_Curve_3_Low_Range_OSS_Axis (walk 0B5B)"),
    ("0x00407a66", "transmission_3rd_gear_low_range_lockup_maximum_throttle_values",
     "e2m 8BD7 RE_Lockup_Curve_3_Low_Range ('Max throttle for lockup in 3rd gear vs OSS in low range mode'): "
     "cm848_applyConverterLockupScheduleLowRange"),
    ("0x00407a76", "transmission_4th_gear_lockup_maximum_throttle_x_axis",
     "e2m 8BD8 RE_Lockup_Curve_4_OSS_Axis: output shaft speed (walk 0B5D)"),
    ("0x00407a88", "transmission_4th_gear_lockup_maximum_throttle_y_axis",
     "e2m 8CA3 RE_Lockup_Curve_4_Boost_Axis: the intake manifold pressure (transmission_4th_gear_lockup_boost_pressure); "
     "11.45 keeps this axis in its own block, 11.46 puts it before the grid"),
    ("0x00407a92", "transmission_4th_gear_lockup_maximum_throttle_grid",
     "e2m 8BD9 RE_Lockup_Curve_4 ('Max throttle for lockup in 4th gear vs OSS'): 8 x 4; cm848_applyConverterLockupSchedule"),
    ("0x00407ad2", "transmission_4th_gear_low_range_lockup_maximum_throttle_axis",
     "e2m 8BDA RE_Lockup_Curve_4_Low_Range_OSS_Axis (walk 0B5F)"),
    ("0x00407ae4", "transmission_4th_gear_low_range_lockup_maximum_throttle_values",
     "e2m 8BDB RE_Lockup_Curve_4_Low_Range ('Max throttle for lockup in 4th gear vs OSS in low-range mode')"),
    ("0x00407af6", "transmission_cruise_lockup_maximum_throttle_x_axis",
     "e2m 8BDC RE_Lockup_Curve_Cruise_OSS_Axis (walk 0B61)"),
    ("0x00407b08", "transmission_cruise_lockup_maximum_throttle_y_axis",
     "e2m 8D07 RE_Lockup_Curve_Cruise_Boost_Axis (inline in 11.46, its own block in 11.45)"),
    ("0x00407b12", "transmission_cruise_lockup_maximum_throttle_grid",
     "e2m 8BDD RE_Lockup_Curve_Cruise ('Max throttle for lockup vs OSS in cruise mode'): 8 x 4"),
    ("0x00407b52", "transmission_low_range_3_4_upshift_maximum_throttle_axis", "e2m 8BDE RE_Low_Range_3_4_OSS_Axis (walk 0B63)"),
    ("0x00407b64", "transmission_low_range_3_4_upshift_maximum_throttle_values",
     "e2m 8BDF RE_Low_Range_3_4 ('Max throttle for 3-4 upshift vs OSS in low range mode'): "
     "cm848_requestOverdriveShiftsLowRange"),
    ("0x00407b76", "transmission_low_range_4_3_downshift_minimum_throttle_axis", "e2m 8BE0 RE_Low_Range_4_3_OSS_Axis (walk 0B65)"),
    ("0x00407b88", "transmission_low_range_4_3_downshift_minimum_throttle_values",
     "e2m 8BE1 RE_Low_Range_4_3 ('Min throttle for 4-3 downshift vs OSS in low range mode')"),
    ("0x00407b9a", "transmission_low_range_1_2_boost_pressure_axis",
     "e2m 8BE2 RE_Low_Range_Boost_Pressure_1_2_Throttle_Axis (walk 0B67)"),
    ("0x00407bac", "transmission_low_range_1_2_boost_pressure_values",
     "e2m 8BE3 RE_Low_Range_Boost_Pressure_1_2 ('Gov press vs TPS to force 1-2 upshift in low range mode')"),
    ("0x00407bbe", "transmission_low_range_2_3_boost_pressure_axis",
     "e2m 8BE4 RE_Low_Range_Boost_Pressure_2_3_Throttle_Axis (walk 0B69)"),
    ("0x00407bd0", "transmission_low_range_2_3_boost_pressure_values",
     "e2m 8BE5 RE_Low_Range_Boost_Pressure_2_3 ('Gov press vs TPS to force 2-3 upshift in low range mode')"),
    ("0x00407be2", "governor_pressure_low_range_curve_axis", "e2m 8BE6 RE_Low_Range_OSS_Axis (walk 0B6B)"),
    ("0x00407bf4", "governor_pressure_low_range_curve_values",
     "e2m 8BE7 RE_Low_Range_Curve ('Gov press vs OSS in low range mode')"),
    ("0x00407c06", "transmission_low_range_1_2_hold_pressure_axis",
     "e2m 8BE8 RE_Low_Range_Hold_Pressure_1_2_Throttle_Axis (walk 0B6D)"),
    ("0x00407c18", "transmission_low_range_1_2_hold_pressure_values",
     "e2m 8BE9 RE_Low_Range_Hold_Pressure_1_2 ('Gov press to prevent 1-2 upshift vs TPS in low range mode')"),
    ("0x00407c2a", "transmission_low_range_2_3_hold_pressure_axis",
     "e2m 8BEA RE_Low_Range_Hold_Pressure_2_3_Throttle_Axis (walk 0B6F)"),
    ("0x00407c3c", "transmission_low_range_2_3_hold_pressure_values",
     "e2m 8BEB RE_Low_Range_Hold_Pressure_2_3 ('Gov press to prevent 2-3 upshift vs TPS in low range mode')"),
    ("0x00407c4e", "transmission_normal_3_4_upshift_throttle_axis", "e2m 8BEC RE_Normal_3_4_OSS_Axis (walk 0B71)"),
    ("0x00407c60", "transmission_normal_3_4_upshift_throttle_values",
     "e2m 8BED RE_Normal_3_4 ('TPS for 3-4 upshift vs OSS when not in cruise mode'): cm848_requestOverdriveShiftsNormal"),
    ("0x00407c72", "transmission_normal_4_3_downshift_throttle_axis", "e2m 8BEE RE_Normal_4_3_OSS_Axis (walk 0B73)"),
    ("0x00407c84", "transmission_normal_4_3_downshift_throttle_values",
     "e2m 8BEF RE_Normal_4_3 ('TPS for 4-3 downshift vs OSS when not in cruise mode')"),
    ("0x00407d22", "transmission_anti_hunt_1_2_maximum_throttle_axis", "e2m 8BF8 RE_TPS_Max_1_2_OSS_Axis (walk 0B7D)"),
    ("0x00407d30", "transmission_anti_hunt_1_2_maximum_throttle_values",
     "e2m 8BF9 RE_TPS_Max_1_2 ('Lower boundary TPS for 1-2 antihunt envelope vs OSS'; the record name says Max): "
     "cm848_selectGovernorPressureNormal"),
    ("0x00407d3e", "transmission_anti_hunt_2_3_maximum_throttle_axis", "e2m 8BFA RE_TPS_Max_2_3_OSS_Axis (walk 0B7F)"),
    ("0x00407d4c", "transmission_anti_hunt_2_3_maximum_throttle_values",
     "e2m 8BFB RE_TPS_Max_2_3 ('Lower boundary TPS for 2-3 antihunt envelope vs OSS')"),
    ("0x00407d5a", "transmission_anti_hunt_3_4_maximum_throttle_axis", "e2m 8BFC RE_TPS_Max_3_4_OSS_Axis (walk 0B81)"),
    ("0x00407d68", "transmission_anti_hunt_3_4_maximum_throttle_values",
     "e2m 8BFD RE_TPS_Max_3_4 ('Lower boundary TPS for 3-4 antihunt envelope vs OSS')"),
    ("0x00407d76", "transmission_anti_hunt_1_2_minimum_throttle_axis", "e2m 8BFE RE_TPS_Min_1_2_OSS_Axis (walk 0B83)"),
    ("0x00407d84", "transmission_anti_hunt_1_2_minimum_throttle_values",
     "e2m 8BFF RE_TPS_Min_1_2 ('Upper boundary TPS for 1-2 antihunt envelope vs OSS'; the record name says Min)"),
    ("0x00407d92", "transmission_anti_hunt_2_3_minimum_throttle_axis", "e2m 8C00 RE_TPS_Min_2_3_OSS_Axis (walk 0B85)"),
    ("0x00407da0", "transmission_anti_hunt_2_3_minimum_throttle_values",
     "e2m 8C01 RE_TPS_Min_2_3 ('Upper boundary TPS for 2-3 antihunt envelope vs OSS')"),
    ("0x00407dae", "transmission_anti_hunt_3_4_minimum_throttle_axis", "e2m 8C02 RE_TPS_Min_3_4_OSS_Axis (walk 0B87)"),
    ("0x00407dbc", "transmission_anti_hunt_3_4_minimum_throttle_values",
     "e2m 8C03 RE_TPS_Min_3_4 ('Upper boundary TPS for 3-4 antihunt envelope vs OSS')"),
    ("0x00407e3a", "transmission_3rd_gear_low_range_unlock_maximum_throttle_axis",
     "e2m 8C08 RE_Unlock_Curve_3_Low_Range_OSS_Axis (walk 0B8D)"),
    ("0x00407e4c", "transmission_3rd_gear_low_range_unlock_maximum_throttle_values",
     "e2m 8C09 RE_Unlock_Curve_3_Low_Range ('Max TPS for unlock vs OSS while in 3rd gear low range'): "
     "cm848_applyConverterLockupScheduleLowRange / cm848_applyConverterUnlockConditionsLowRange"),
    ("0x00407e5e", "transmission_4th_gear_unlock_maximum_throttle_axis", "e2m 8C0A RE_Unlock_Curve_4_OSS_Axis (walk 0B8F)"),
    ("0x00407e70", "transmission_4th_gear_unlock_maximum_throttle_values",
     "e2m 8C0B RE_Unlock_Curve_4 ('Max TPS for unlock vs OSS in 4th gear'): cm848_applyConverterLockupSchedule / "
     "cm848_applyConverterUnlockConditions"),
    ("0x00407e82", "transmission_4th_gear_low_range_unlock_maximum_throttle_axis",
     "e2m 8C0C RE_Unlock_Curve_4_Low_Range_OSS_Axis (walk 0B91)"),
    ("0x00407e94", "transmission_4th_gear_low_range_unlock_maximum_throttle_values",
     "e2m 8C0D RE_Unlock_Curve_4_Low_Range ('Max TPS for unlock vs OSS in 4th gear low range')"),
    ("0x00407ea6", "transmission_cruise_unlock_maximum_throttle_axis", "e2m 8C0E RE_Unlock_Curve_Cruise_OSS_Axis (walk 0B93)"),
    ("0x00407eb8", "transmission_cruise_unlock_maximum_throttle_values",
     "e2m 8C0F RE_Unlock_Curve_Cruise ('Max TPS for unlock vs OSS in cruise mode')"),
    ("0x00407eca", "governor_pressure_wide_open_throttle_cold_curve_axis", "e2m 8C10 RE_WOT_Cold_OSS_Axis (walk 0B95)"),
    ("0x00407ee0", "governor_pressure_wide_open_throttle_cold_curve_values",
     "e2m 8C11 RE_WOT_Cold_Curve ('Gov press vs OSS with WOT and cold temperatures'): cm848_selectGovernorPressureCold"),
    ("0x00407ef6", "governor_pressure_wide_open_throttle_curve_axis", "e2m 8C12 RE_WOT_OSS_Axis (walk 0B97)"),
    ("0x00407f0c", "governor_pressure_wide_open_throttle_curve_values",
     "e2m 8C13 RE_WOT_Curve ('Gov press vs OSS with WOT and normal temperatures'): pressure state 5"),
    ("0x00407f22", "governor_pressure_manual_low_curve_axis",
     "Output shaft speed axis of the manual low curve: a table 11.46 adds after RE_WOT_Curve (no 11.45 record)"),
    ("0x00407f34", "governor_pressure_manual_low_curve_values",
     "Governor pressure vs output shaft speed with the lever in 1 or 2 (transmission_selected_gear 0x7e / 0x7f): "
     "pressure state 0x16 in cm848_selectGovernorPressureBaseCurve, cm848_selectGovernorPressureCold and "
     "cm848_selectGovernorPressureCruise. A table 11.46 adds (no 11.45 record)"),
    ("0x004080f8", "transmission_4th_gear_exhaust_brake_lockup_maximum_throttle_x_axis",
     "Output shaft speed axis of the exhaust brake (switch 12) copy of RE_Lockup_Curve_4; an 11.46 table"),
    ("0x0040810a", "transmission_4th_gear_exhaust_brake_lockup_maximum_throttle_y_axis",
     "Boost axis of the exhaust brake copy of RE_Lockup_Curve_4"),
    ("0x00408114", "transmission_4th_gear_exhaust_brake_lockup_maximum_throttle_grid",
     "The exhaust brake (switch 12) copy of RE_Lockup_Curve_4: cm848_applyConverterLockupSchedule uses it while the "
     "exhaust brake switch is on; an 11.46 table"),
    ("0x00408154", "transmission_cruise_exhaust_brake_lockup_maximum_throttle_x_axis",
     "Output shaft speed axis of the exhaust brake copy of RE_Lockup_Curve_Cruise; an 11.46 table"),
    ("0x00408166", "transmission_cruise_exhaust_brake_lockup_maximum_throttle_y_axis",
     "Boost axis of the exhaust brake copy of RE_Lockup_Curve_Cruise"),
    ("0x00408170", "transmission_cruise_exhaust_brake_lockup_maximum_throttle_grid",
     "The exhaust brake (switch 12) copy of RE_Lockup_Curve_Cruise; an 11.46 table"),
    ("0x004081b0", "transmission_normal_exhaust_brake_3_4_upshift_throttle_axis",
     "Output shaft speed axis of the exhaust brake (switch 12) copy of RE_Normal_3_4; an 11.46 table"),
    ("0x004081c2", "transmission_normal_exhaust_brake_3_4_upshift_throttle_values",
     "The exhaust brake copy of RE_Normal_3_4: with switch 12 on and exhaust_brake_transmission_features_inhibit clear, "
     "cm848_requestOverdriveShiftsNormal requests the 3-4 below it"),
    ("0x004081d4", "transmission_normal_exhaust_brake_4_3_downshift_throttle_axis",
     "Output shaft speed axis of the exhaust brake copy of RE_Normal_4_3; an 11.46 table"),
    ("0x004081e6", "transmission_normal_exhaust_brake_4_3_downshift_throttle_values",
     "The exhaust brake copy of RE_Normal_4_3: with switch 12 on, cm848_requestOverdriveShiftsNormal requests the 4-3 "
     "at or above it"),
    ("0x004080b0", "transmission_cruise_exhaust_brake_3_4_upshift_throttle_axis",
     "Output shaft speed axis of the exhaust brake (switch 12) copy of RE_Cruise_3_4; an 11.46 table"),
    ("0x004080c2", "transmission_cruise_exhaust_brake_3_4_upshift_throttle_values",
     "The exhaust brake copy of RE_Cruise_3_4: with switch 12 on and exhaust_brake_transmission_features_inhibit clear, "
     "cm848_selectGovernorPressureCruise requests the 3-4 below it"),
    ("0x004080d4", "transmission_cruise_exhaust_brake_4_3_downshift_throttle_axis",
     "Output shaft speed axis of the exhaust brake copy of RE_Cruise_4_3; an 11.46 table"),
    ("0x004080e6", "transmission_cruise_exhaust_brake_4_3_downshift_throttle_values",
     "The exhaust brake copy of RE_Cruise_4_3: with switch 12 on, cm848_selectGovernorPressureCruise requests the 4-3 at "
     "or above it"),
]
FUNCTIONS = [
    ("0x0051c6c8", "cm848_calculateGovernorPressureProportionalTerm",
     "The governor pressure controller's proportional term: the error x a numerator / denominator gain stepped by "
     "error breakpoints (e2m 8BB5 RE_PID_Error_Brkpt_0..2 above RE_PID_Switch_Temperature, 3..5 below it), added to "
     "governor_pressure_controller_output through cm848_limitGovernorPressureSolenoidDuty"),
    ("0x0051c948", "cm848_calculateGovernorPressureDerivativeTerm",
     "The governor pressure controller's derivative term: governor_pressure_error_change x RE_K_D_Num / RE_K_D_Den, "
     "clamped to +-0x6400, into governor_pressure_controller_error_delta_term and added to the output"),
    ("0x0051c9f0", "cm848_applyGovernorPressureIntegralTerm",
     "The governor pressure controller's integral term: every governor_pressure_integral_period passes "
     "(RE_PID_Loop_Limit) the error sum / RE_PID_Error_Sum_Den, clamped to +-0x6400, becomes "
     "governor_pressure_integral_term and is added to the output; the sum is cleared"),
    ("0x0051c68c", "cm848_limitGovernorPressureSolenoidDuty",
     "Clamps the controller output to governor_pressure_solenoid_duty_minimum .. _maximum (e2m RE_VFS_PWM_Minimum / "
     "Maximum) into governor_pressure_controller_output"),
    ("0x0051c2e4", "cm848_learnGovernorPressureSensorOffset",
     "End of the governor pressure sensor offset calibration: governor_pressure_sensor_zero_offset = the filtered sensor "
     "reading, or the limit it is beyond (governor_pressure_sensor_offset_minimum / _maximum, e2m "
     "RE_Transducer_Offset_Min / Max), with governor_pressure_sensor_calibration_flags; then drives the solenoid duty "
     "(inverted by governor_pressure_solenoid_duty_inversion) through the output driver table"),
    ("0x0051cd88", "cm848_initializeGovernorPressureControl",
     "Boot initialization of the governor pressure control: two lookup caches to 2, the solenoid output channel enabled, "
     "governor_pressure_integral_period_counter loaded, governor_pressure_controller_output set to its start value"),
    ("0x00031d98", "cm848_selectGovernorPressureCruise",
     "The 48RE cruise governor pressure mode, run while condition_flags_1 bit 4 (e2m RE_Cruise_Active) follows "
     "cruise_control_engaged_flag: the target is RE_Cruise_Curve (pressure state 3), or the manual low curve (0x16) with "
     "the lever in 1 / 2. The 3-4 / 4-3 requests come from the RE_Cruise_3_4 / RE_Cruise_4_3 lines, or their exhaust "
     "brake copies with switch 12 on; then the cruise decel 4-3 / 3-4 requests "
     "(transmission_cruise_downshift_delay_timer / _upshift_)"),
    ("0x0002fe48", "cm848_applyConverterLockupScheduleLowRange",
     "The low range converter lockup schedule: the 3rd / 4th gear low range lockup curves (e2m RE_Lockup_Curve_3 / "
     "4_Low_Range, RE_Unlock_Curve_3_Low_Range) decide the lockup request (logical output 18)"),
    ("0x0003004c", "cm848_applyConverterUnlockConditionsLowRange",
     "The low range converter unlock conditions: above the low range unlock curves (e2m RE_Unlock_Curve_3 / "
     "4_Low_Range) it releases the converter clutch request and reloads converter_clutch_apply_delay_countdown"),
    ("0x0002f860", "cm848_requestOverdriveShiftsLowRange",
     "The low range 3-4 / 4-3 requests (condition_eval bits 2 / 1) from e2m RE_Low_Range_3_4 / RE_Low_Range_4_3"),
    ("0x00031320", "cm848_requestOverdriveShiftsNormal",
     "The normal (not cruise) 3-4 / 4-3 requests (condition_eval bits 2 / 1) from e2m RE_Normal_3_4 / RE_Normal_4_3, "
     "or their exhaust brake copies with switch 12 on"),
]
