"""Round 8 stage B (main session, label-only): the rest of the two aligned e2m blocks.
- 8BBC (ROM, base 0x40780c): +16..+5C. Every row's only users are the subsystem its record describes (lockup /
  unlock / low range / anti-hunt / WOT / cruise decel); three rows already carried the e2m meaning
  (lockup_minimum_transmission_temperature, overdrive_off_set_transmission_temperature,
  governor_pressure_cold_mode_temperature_threshold). From +5E the 11.45 layout drifts: 0x40786a is the gear ratio
  table in the code.
- 8C17 (RAM, base 0x40b102): +8..+48. Already-right names confirm it: governor_pressure_target = RE_Governor_Set,
  overdrive_off_flag = Transmission_OD_Lamp, transmission_overheat_flag = Transmission_Over_Temp_Light,
  transmission_speed_ratio = RE_Current_Ratio, transmission_vehicle_speed_filtered = RE_Road_Speed,
  overdrive_upshift_timer = RE_Transition_3_4_Timer, fuel_demand_rate_abs = RE_TPS_Rate. From +4C it drifts
  (0x40b14e is intake_manifold_pressure_in_use).
- The protection_* functions here are the 48RE controller's: the low range strategy (all its cals are RE_Low_Range_*;
  runTransmissionControl calls it in transfer-case low range above RE_TPS_Min_Low_Range), the timer tick, the
  initialization, the output shaft acceleration and the governor pressure sensor offset calibration."""


def r(block, off, rec, desc, extra=""):
    return f"e2m {block} +{off} {rec} ('{desc}'){'; ' + extra if extra else ''}"


B = "8BBC"
C = "8C17"
GLOBALS = [
    ("0x00407822", "transmission_lockup_service_minimum_output_speed_3rd",
     r(B, "16", "RE_Lockup_Service_OSS_3", "Min OSS at which lockup is allowed in 3rd gear service lockup mode",
       "cm848_applyConverterLockupSchedule")),
    ("0x00407824", "transmission_lockup_service_minimum_output_speed_4th",
     r(B, "18", "RE_Lockup_Service_OSS_4", "Min OSS at which lockup is allowed in 4th gear service lockup mode",
       "cm848_applyConverterLockupSchedule")),
    ("0x00407826", "transmission_low_range_1_2_boost_time",
     r(B, "1A", "RE_Low_Range_1_2_Timer_Max", "Time boost pressure held after 1-2 shift",
       "251 = 2.51 s; reloads transmission_lockup_timers.low_range_shift_timer in cm848_selectGovernorPressureLowRange")),
    ("0x00407828", "transmission_low_range_2_3_boost_time",
     r(B, "1C", "RE_Low_Range_2_3_Timer_Max", "Time boost pressure held after 2-3 shift", "cm848_selectGovernorPressureLowRange")),
    ("0x0040782a", "transmission_low_range_2nd_gear_boost_maximum_engine_acceleration",
     r(B, "1E", "RE_Low_Range_Eng_Accel_2", "Stop gov pressure boost when eng accel > this value in 2nd gr",
       "compared with transmission_engine_acceleration")),
    ("0x0040782c", "transmission_low_range_3rd_gear_boost_maximum_engine_acceleration",
     r(B, "20", "RE_Low_Range_Eng_Accel_3", "Stop gov pressure boost when eng accel > this value in 3rd gr")),
    ("0x0040782e", "transmission_low_range_2nd_gear_minimum_hold_time",
     r(B, "22", "RE_Low_Range_Hold_Time_2", "Min time to maintain gov hold press in 2nd before boosting for 3rd")),
    ("0x00407830", "transmission_low_range_3rd_gear_minimum_hold_time",
     r(B, "24", "RE_Low_Range_Hold_Time_3", "Min time to maintain gov hold press in 3rd before boosting for 4th")),
    ("0x00407834", "transmission_low_range_1_2_shift_detection_minimum_engine_speed",
     r(B, "28", "RE_Scaled_ERPM_Low_Range_1_2_Min", "Min spd to use eng spd accel to detect start of 1-2 shift",
       "16000 = 2000 rpm")),
    ("0x00407836", "transmission_3rd_gear_lockup_minimum_throttle",
     r(B, "2A", "RE_TPS_Min_3rd_Gear_Lock", "Min throttle to allow 3rd gear lockup", "cm848_applyConverterLockupSchedule")),
    ("0x00407838", "transmission_anti_hunt_minimum_throttle",
     r(B, "2C", "RE_TPS_Min_Anti_Hunt", "Min throttle for which anti-hunt strategy is allowed",
       "82 = 20.5 %; tested in cm848_selectGovernorPressureNormal")),
    ("0x0040783a", "transmission_low_range_minimum_throttle",
     r(B, "2E", "RE_TPS_Min_Low_Range", "Min TPS to allow low-range strategy",
       "126 = 31.5 %; cm848_runTransmissionControl runs cm848_selectGovernorPressureLowRange above it")),
    ("0x0040783e", "governor_pressure_fuel_economy_maximum_throttle",
     r(B, "32", "RE_TPS_Fuel_Economy", "TPS must be < this threshold to allow fuel economy shift curves",
       "cm848_selectGovernorPressureBaseCurve")),
    ("0x00407842", "transmission_unlock_service_minimum_output_speed_3rd",
     r(B, "36", "RE_Unlock_Service_OSS_3", "Min OSS at which unlock is allowed in 3rd gear service lockup mode",
       "cm848_applyConverterUnlockConditions")),
    ("0x00407844", "transmission_unlock_service_minimum_output_speed_4th",
     r(B, "38", "RE_Unlock_Service_OSS_4", "Min OSS at which unlock is allowed in 4th gear service lockup mode")),
    ("0x00407846", "governor_pressure_wide_open_throttle_1_2_boost_pressure",
     r(B, "3A", "RE_WOT_Boost_Pressure_1_2", "Gov pressure required to force 1-2 shift with WOT",
       "7168 = 56 psi; cm848_selectGovernorPressureWideOpenThrottle")),
    ("0x00407848", "governor_pressure_wide_open_throttle_2_3_boost_pressure",
     r(B, "3C", "RE_WOT_Boost_Pressure_2_3", "Gov pressure required to force 2-3 shift with WOT", "16256 = 127 psi")),
    ("0x0040784a", "governor_pressure_wide_open_throttle_boost_time",
     r(B, "3E", "RE_WOT_Boost_Timer_Max", "Time shift boost pressure will be held after WOT upshift occurs",
       "50 = 500 ms; reloads governor_pressure_wide_open_throttle_boost_timer")),
    ("0x0040784c", "governor_pressure_wide_open_throttle_1_2_hold_pressure",
     r(B, "40", "RE_WOT_Hold_Pressure_1_2", "Gov press required to prevent a WOT 1-2 upshift", "2880 = 22.5 psi")),
    ("0x0040784e", "governor_pressure_wide_open_throttle_2_3_hold_pressure",
     r(B, "42", "RE_WOT_Hold_Pressure_2_3", "Gov press required to prevent a WOT 2-3 upshift", "7168 = 56 psi")),
    ("0x00407852", "transmission_2nd_gear_lockup_minimum_throttle",
     r(B, "46", "RE_TPS_Min_2nd_Gear_Lock", "Min throttle to allow 2nd gear lockup", "cm848_applyConverterLockupSchedule")),
    ("0x00407854", "transmission_2_3_unlock_engine_speed_drop",
     r(B, "48", "RE_Delta_RPM_To_Unlock_2nd", "Engine speed drop from 2nd gear to unlock for 2-3 shift",
       "cm848_applyConverterUnlockConditions")),
    ("0x00407858", "transmission_cruise_downshift_maximum_throttle",
     r(B, "4C", "RE_Cruise_Downshift_Throttle", "Used to allow a 4-3 downshift in cruise decel mode",
       "cm848_protectionStateTransitionCheck")),
    ("0x0040785a", "transmission_cruise_downshift_delay_time",
     r(B, "4E", "RE_Cruise_Downshift_Timer_Max", "Time used to delay a downshift in cruise decel mode", "150 = 1.5 s")),
    ("0x0040785c", "transmission_cruise_upshift_delay_time",
     r(B, "50", "RE_Cruise_Upshift_Timer_Max", "Time used to delay a upshift in cruise decel mode", "150 = 1.5 s")),
    ("0x00407860", "transmission_manual_first_unlock_maximum_output_speed",
     r(B, "54", "RE_Unlock_2nd_In_M1", "OSS must be < this threshold to unlock for manual 1st downshift",
       "16800 = 2100 rpm; cm848_applyConverterUnlockConditions")),
    ("0x00407862", "transmission_manual_second_unlock_maximum_output_speed",
     r(B, "56", "RE_Unlock_3rd_In_M2", "OSS must be < this threshold to unlock for manual 2nd downshift")),
    ("0x00407864", "governor_pressure_wide_open_throttle_anti_hang_engine_speed",
     r(B, "58", "RE_WOT_Anti_Hang_RPM", "Engine RPM threshold to use lowered WOT shift target",
       "24000 = 3000 rpm; cm848_selectGovernorPressureWideOpenThrottle")),
    ("0x00407866", "governor_pressure_wide_open_throttle_anti_hang_time",
     r(B, "5A", "RE_WOT_Anti_Hang_Timer_Max", "Used to allow WOT upshift at lowered RPM target", "700 = 7 s")),
    ("0x00407868", "transmission_manual_low_lockup_off_time",
     r(B, "5C", "RE_Lockup_Off_Timer_M2_M1", "Lockup off timer set value & TCC off; when locked and M1 or M2 is "
       "selected", "cm848_applyConverterUnlockConditions")),
    ("0x0040b10a", "transmission_output_speed_fault_debounce_timer",
     r(C, "8", "RE_Bad_OSS_Loops", "Counter to debounce trans output shaft spd diagnostics",
       "only the timer tick and the initialization use it in the decompile")),
    ("0x0040b10c", "governor_pressure_offset_calibration_interval_timer",
     r(C, "A", "RE_Between_Cal_Timer", "Timer used in trans gov press offset calibration",
       "1152 = 11.52 s in the RAM dump; cm848_calibrateGovernorPressureSensorOffset")),
    ("0x0040b10e", "governor_pressure_offset_calibration_timer",
     r(C, "C", "RE_Cal_Timer", "Timer used in trans gov press offset calibration")),
    ("0x0040b110", "transmission_engine_acceleration",
     r(C, "E", "RE_Engine_Accel", "Measured engine acceleration used in trans control algorithms",
       "the low range and WOT strategies")),
    ("0x0040b112", "transmission_1st_gear_maximum_engine_speed",
     r(C, "10", "RE_ERPM_Max_1_2", "Max engine speed observed while in 1st gear")),
    ("0x0040b114", "transmission_2nd_gear_maximum_engine_speed",
     r(C, "12", "RE_ERPM_Max_2_3", "Max engine speed observed while in 2nd gear")),
    ("0x0040b118", "governor_pressure_offset_calibration_initial_delay_timer",
     r(C, "16", "RE_Init_Cal_Delay", "Timer counter for delaying trans press sensor offset estimation")),
    ("0x0040b11a", "transmission_engine_speed_previous", r(C, "18", "RE_Last_ERPM", "Previous engine speed")),
    ("0x0040b11c", "transmission_lockup_timers",
     "e2m 8C17 +1A..+24: the lockup delay timers and the low range timers (transmission_lockup_timers_t)"),
    ("0x0040b128", "transmission_predicted_1_2_shift_delay",
     r(C, "26", "RE_One_Two_Delay", "Predicted 1-2 shift delay",
       "the low range and WOT strategies load it from the adaptive delay table at 0x3fede2 by "
       "transmission_temperature_range (e2m RE_WOT_Temp_Range: 'Temperature range index for adaptive shift delay table')")),
    ("0x0040b12e", "transmission_throttle_previous", r(C, "2C", "RE_TPS_Last", "Previous throttle; used in trans control logic")),
    ("0x0040b134", "transmission_predicted_2_3_shift_delay", r(C, "32", "RE_Two_Three_Delay", "Predicted 2-3 shift delay")),
    ("0x0040b136", "transmission_overdrive_upshift_inhibit_timer",
     r(C, "34", "RE_Upshift_3_4_Inhibit_Timer", "Timer used to delay OD upshifts")),
    ("0x0040b138", "governor_pressure_wide_open_throttle_boost_timer",
     r(C, "36", "RE_WOT_Boost_Timer", "Timer used to control duration of WOT upshift boost pressure")),
    ("0x0040b13e", "transmission_engine_acceleration_filtered",
     r(C, "3C", "RE_Filtered_Engine_Accel", "Filtered Engine acceleration for determining RE_Engine_Accel")),
    ("0x0040b140", "transmission_lockup_delay_1_2_timer", r(C, "3E", "RE_Lockup_Delay_1_2", "Timer for 1-2 lockup delay")),
    ("0x0040b142", "transmission_lockup_delay_3_2_timer", r(C, "40", "RE_Lockup_Delay_3_2", "Timer for 3-2 lockup delay")),
    ("0x0040b144", "transmission_overheat_protection_active_flag",
     r(C, "42", "RE_Ovr_Heat_Prot_On", "Indicates trans temp high enough for overheat lockup",
       "set at 235 F (or coolant 235 F), cleared at 220 F (225 F coolant)")),
    ("0x0040b14a", "transmission_output_shaft_acceleration_unfiltered",
     r(C, "48", "RE_OSS_Accel_Unfiltered", "Unfiltered tailshaft acceleration", "cm848_calculateOutputShaftAcceleration")),
]
FUNCTIONS = [
    ("0x0002f920", "cm848_selectGovernorPressureLowRange",
     "The 48RE low range (transfer case in low) governor pressure strategy: cm848_runTransmissionControl runs it in low "
     "range above transmission_low_range_minimum_throttle. Every cal it reads is an e2m RE_Low_Range_* record: the "
     "boost times after the 1-2 / 2-3 shift, the engine acceleration limits that stop the boost, the minimum hold times, "
     "the 1-2 shift detection speed; it predicts the shift engine speed from transmission_engine_acceleration and "
     "transmission_predicted_1_2_shift_delay. Pressure states 0xb-0xf"),
    ("0x000335e4", "cm848_decrementTransmissionTimers",
     "Counts down the 48RE controller's timers each pass (the anti-hunt, lockup delay, low range, WOT boost and "
     "overdrive inhibit timers of e2m 8C17)"),
    ("0x00034b14", "cm848_initializeTransmissionControl",
     "Initializes the 48RE controller: transmission_current_gear = 1, the maximum engine speeds and previous values "
     "cleared, the overdrive off flag cleared, and the other e2m 8C17 working words"),
    ("0x0003491c", "cm848_calculateOutputShaftAcceleration",
     "Every scan period: the output shaft speed change into transmission_output_shaft_acceleration_unfiltered (e2m "
     "RE_OSS_Accel_Unfiltered) and its filtered value transmission_output_shaft_acceleration (RE_OSS_Accel)"),
    ("0x0051c3d8", "cm848_calibrateGovernorPressureSensorOffset",
     "The governor pressure sensor offset calibration (e2m 8C17 RE_Init_Cal_Delay / RE_Cal_Timer / RE_Between_Cal_Timer: "
     "'Timer used in trans gov press offset calibration'): under algorithm_enable_flags_6_cal bit 2 it sets "
     "governor_pressure_sensor_zero_offset"),
]
