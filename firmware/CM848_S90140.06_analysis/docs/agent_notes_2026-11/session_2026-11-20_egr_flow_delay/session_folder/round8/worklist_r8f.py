"""Round 8 stage F (label-only): e2m 8C18, the 48RE ROM calibration block, aligned at 0x4082f4 (+00..+98; it drifts from
+9A, where a table axis starts), and the exhaust brake lockup aid that stage E misread as a converter clutch engagement
monitor.
- The 8C18 base is proved by rows named before from their code use: +0E RE_ERPM_WOT_Target (24600) = stage E's WOT upshift
  target, +16 RE_Lockup_Boost = the pressure state 0x10 target, +1E RE_Low_Range_Max = transfer_case_low_range_ratio_threshold,
  +20..+24 RE_Max_2 / 3 / 4_Ratio = the gear identification thresholds, +26..+54 the overdrive cold / hot and over temp
  light temperatures, +62 RE_Road_Speed_Filter_Constant, +70 RE_OSS_Accel_Method (the method switch of
  cm848_calculateOutputShaftAcceleration), +88..+92 the per-gear speed ratio windows, +96 RE_E_Brake_Inhibit_Timeout (300,
  the window function's time limit).
- The exhaust brake: e2m 8C17 +4A RE_E_Brake_Inhibit_Timer 'Used to time ebrake TCC inhibit timeout limit', 8C18
  +88..+92 RE_EB_Lockup_Range_* 'If ERPM/OSS > this ratio, Set RE_E_Brake_Inhibit_LU = FALSE', 8C18 +96
  RE_E_Brake_Inhibit_Timeout 'Limit for ebrake inhibit while waiting for TCC Lockup', 8C19 +16 RE_E_Brake_Inhibit_LU
  'Flag set to inhibit Exhaust Brake to allow TCC lockup'. In the code, cm848_updateEngineRetarderEnableState reads bit 0
  of 0x40b0fe as its torque converter lockup disengaged input, and the retarder (exhaust brake) sets bits 0 / 1 in 2nd gear
  and bit 0 again after a 4-3 downshift. So 8C17 drifts from +4C (RE_WOT_2LU_Delay_Timer lands on
  intake_manifold_pressure_in_use), not from +4A.
- 8C19 (the RE flag bytes) aligns at 0x40b0e8, the protection_condition_flags_t struct; its bits are a lead."""

EB = "e2m 8C18 +{} {} ('{}')"


def c(off, rec, desc, extra=""):
    return EB.format(off, rec, desc) + (": " + extra if extra else "")


GLOBALS = [
    ("0x004082f4", "transmission_output_shaft_acceleration_sample_period",
     c("00", "RE_Acc_Loop_Ctr_Max", "Time interval for OSS accel calculation",
       "27 passes; method 0 of cm848_calculateOutputShaftAcceleration samples the output speed this often")),
    ("0x004082f6", "converter_clutch_brake_release_relock_delay_time",
     c("02", "RE_Brake_Lock_Delay_Max", "Time relock is disabled after brake release", "200 = 2 s")),
    ("0x004082f8", "transmission_engine_acceleration_default",
     c("04", "RE_Engine_Accel_Default", "Engine accel set to this when ENGINE_ACCEL_MAX is exceeded",
       "200; cm848_updateTransmissionConditionFlags uses it when transmission_engine_acceleration_filtered is above "
       "transmission_engine_acceleration_maximum")),
    ("0x004082fa", "transmission_engine_acceleration_default_low_range",
     c("06", "RE_Engine_Accel_Default_Low_Range", "Engine accel set to this when ENGINE_ACCEL_MAX is exceeded",
       "256; the transfer-case low range value (condition_flags_1 bit 2)")),
    ("0x004082fc", "transmission_engine_acceleration_maximum",
     c("08", "RE_Engine_Accel_Max", "Max allowed calculated engine accel for WOT calculations", "200")),
    ("0x004082fe", "transmission_engine_acceleration_maximum_low_range",
     c("0A", "RE_Engine_Accel_Max_Low_Range", "Max allowed calculated engine accel for WOT calculations", "256")),
    ("0x00408300", "transmission_engine_acceleration_minimum",
     c("0C", "RE_Engine_Accel_Reset", "Calc accel reset to 0 when it exceeds this value",
       "8; in the code a filtered acceleration below it (or negative) gives 0")),
    ("0x00408304", "governor_pressure_wide_open_throttle_upshift_target_engine_speed_low",
     c("10", "RE_ERPM_WOT_Target_Low", "Min rpm for adj to be applied to learned shift lag value",
       "24200 = 3025 rpm; the learned shift delay is adjusted when the gear's maximum engine speed is outside low..high")),
    ("0x00408306", "governor_pressure_wide_open_throttle_upshift_target_engine_speed_high",
     c("12", "RE_ERPM_WOT_Target_High", "Max rpm for adj to be applied to learned shift lag value", "25000 = 3125 rpm")),
    ("0x00408308", "transmission_predicted_shift_delay_adjustment_step",
     c("14", "RE_Lag_Adjust_Term", "Upshift lag adjustment made when erpm is outside the target band",
       "1 = 10 ms per WOT upshift")),
    ("0x0040830a", "governor_pressure_lockup_boost",
     c("16", "RE_Lockup_Boost", "Gov pressure target during lockup, to prevent downshift",
       "16256 = 127 psi; pressure state 0x10 (cm848_selectGovernorPressureLockupBoost); cm848_runTransmissionControl "
       "also commands it on the fault / shutdown path")),
    ("0x0040830c", "transmission_lockup_off_time",
     c("18", "RE_Lockup_Off_Timer_Max", "Time lockup boost is held after unlock",
       "10 = 100 ms; reloads transmission_lockup_timers.lockup_off_timer")),
    ("0x0040830e", "transmission_lockup_delay_2_3_time",
     c("1A", "RE_Lockup_Delay_2_3_Max", "Time before lockup allowed after 3rd gear ID",
       "144 = 1.44 s; reloads transmission_lockup_timers.lockup_delay_2_3_timer")),
    ("0x00408310", "transmission_lockup_delay_3_4_time",
     c("1C", "RE_Lockup_Delay_3_4_Max", "Time before lockup allowd after 4th gear ID", "13 = 130 ms")),
    ("0x00408314", "transmission_2nd_gear_maximum_speed_ratio",
     c("20", "RE_Max_2_Ratio", "If ERPM/OSS < this ratio, current gear is 2nd or higher", "80 = 2.5 (x 32)")),
    ("0x00408316", "transmission_3rd_gear_maximum_speed_ratio",
     c("22", "RE_Max_3_Ratio", "If ERPM/OSS < this ratio, current gear is 3rd or higher", "46 = 1.44")),
    ("0x00408318", "transmission_4th_gear_maximum_speed_ratio",
     c("24", "RE_Max_4_Ratio", "If ERPM/OSS < this ratio, current gear is 4th", "30 = 0.94")),
    ("0x0040831e", "transmission_predicted_1_2_shift_delay_maximum",
     c("2A", "RE_One_Two_Delay_Max", "Max allowable lag term for 1-2", "33 = 330 ms")),
    ("0x00408320", "transmission_predicted_1_2_shift_delay_minimum",
     c("2C", "RE_One_Two_Delay_Min", "Min allowable lag term for 1-2", "0")),
    ("0x00408322", "converter_clutch_apply_delay_time",
     c("2E", "RE_Relock_Timer_Max", "Delay for relock after closed-throttle unlock",
       "10 = 100 ms; reloads converter_clutch_apply_delay_countdown (8C17 +2A RE_Relock_Timer)")),
    ("0x00408324", "transmission_throttle_detent_set_threshold",
     c("30", "RE_TPS_Detent_High", "Detent is true (WOT) when TPS exceeds this value",
       "322 = 80.5 %; sets protection_status_flags_t.flags[0] bit 4")),
    ("0x00408326", "transmission_throttle_detent_clear_threshold",
     c("32", "RE_TPS_Detent_Low", "Detent is false (not-WOT) when tps drops below this value", "303 = 75.75 %")),
    ("0x00408328", "converter_clutch_relock_maximum_throttle_rate",
     c("34", "RE_TPS_Rate_Unlock", "Delay relock if chg in TPS over one loop > this value", "600")),
    ("0x0040832a", "transmission_wide_open_throttle_set_threshold",
     c("36", "RE_TPS_WOT_High", "TPS considered WOT when > this value", "382 = 95.5 %")),
    ("0x0040832c", "transmission_wide_open_throttle_clear_threshold",
     c("38", "RE_TPS_WOT_Low", "TPS considered not-WOT when < this value", "364 = 91 %")),
    ("0x0040832e", "transmission_predicted_2_3_shift_delay_maximum",
     c("3A", "RE_Two_Three_Delay_Max", "Max allowable lag term for 2-3", "40 = 400 ms")),
    ("0x00408330", "transmission_predicted_2_3_shift_delay_minimum",
     c("3C", "RE_Two_Three_Delay_Min", "Min allowable lag term for 2-3", "0")),
    ("0x00408332", "governor_pressure_offset_calibration_maximum_transmission_temperature",
     c("3E", "RE_T_Cal_Disable", "Upper limit of trans temp range for pressure sensor auto-cal", "17280 = 270 F")),
    ("0x00408334", "governor_pressure_offset_calibration_minimum_transmission_temperature",
     c("40", "RE_T_Cal_Enable", "Lower limit of trans temp range for pressure sensor auto-cal", "2048 = 32 F")),
    ("0x00408336", "transmission_3rd_gear_lockup_minimum_temperature",
     c("42", "RE_T_Min_3rd_Gear_Lock", "Trans temp must be > this value to allow lockup in 3rd gear",
       "4467 = 69.8 F; cm848_applyConverterLockupSchedule")),
    ("0x0040834a", "transmission_engine_acceleration_filter_coefficient",
     c("56", "RE_Engine_Accel_Filter_Constant", "Engine acceleration first stage digital filter",
       "60293; the coefficient of transmission_engine_acceleration_filter")),
    ("0x0040834c", "governor_pressure_2nd_gear_lockup_boost",
     c("58", "RE_Lockup_Boost_2nd", "Gov pressure setpoint when in 2nd gear lockup", "7168 = 56 psi; pressure state 0x11")),
    ("0x0040834e", "transmission_lockup_delay_1_2_time",
     c("5A", "RE_Lockup_Delay_1_2_Max", "Min time after 1-2 upshift before lockup",
       "94 = 940 ms; reloads transmission_lockup_delay_1_2_timer")),
    ("0x00408350", "transmission_lockup_delay_3_2_time",
     c("5C", "RE_Lockup_Delay_3_2_Max", "Min time after 3-2 downshift before lockup is allowed",
       "94; reloads transmission_lockup_delay_3_2_timer")),
    ("0x00408352", "transmission_overheat_protection_set_temperature",
     c("5E", "RE_T_Ovr_Heat_Prot_High", "Over-temp lockup protection enabled above this temperature",
       "15040 = 235 F; sets transmission_overheat_protection_active_flag")),
    ("0x00408354", "transmission_overheat_protection_clear_temperature",
     c("60", "RE_T_Ovr_Heat_Prot_Low", "Over-temp lockup protection disabled below this temperature", "14080 = 220 F")),
    ("0x00408358", "transmission_overheat_protection_coolant_set_temperature",
     c("64", "RE_CT_Ovr_Heat_Prot_High", "Over-temp lockup protection enabled above this temperature",
       "15066 = 235 F coolant")),
    ("0x0040835a", "transmission_overheat_protection_coolant_clear_temperature",
     c("66", "RE_CT_Ovr_Heat_Prot_Low", "Over-temp lockup protection disabled below this temperature",
       "14374 = 225 F coolant")),
    ("0x0040835c", "transmission_2nd_gear_maximum_speed_ratio_locked",
     c("68", "RE_Max_2_Ratio_Lu", "If ERPM/OSS < this ratio, defines 2nd gear while in lockup", "80")),
    ("0x0040835e", "transmission_manual_2nd_4_3_downshift_maximum_output_speed",
     c("6A", "RE_OSS_Downshift_Limit_4_3_M2", "OSS < this value, limit from 4th to 3rd, when shifting from Drive to M2",
       "24800 = 3100 rpm; cm848_selectGovernorPressureLockupBoost requests the 4-3 below it with the lever in 1 / 2")),
    ("0x00408360", "governor_pressure_detent_2_3_shift_pressure",
     c("6C", "RE_Detent_2_3_Pressure", "Gov pressure target for 2-3 shift at detent", "16256 = 127 psi")),
    ("0x00408362", "transmission_output_shaft_acceleration_filter_coefficient",
     c("6E", "RE_OSS_Accel_Filter_Constant", "Filter Constant used for DCX Output Shaft Speed Acceleration",
       "64225; the coefficient of transmission_output_shaft_acceleration_filter")),
    ("0x00408364", "transmission_output_shaft_acceleration_method",
     c("70", "RE_OSS_Accel_Method", "Determines Method for Calculating RE_OSS_Accel",
       "1 here: the 27-sample ring and the filter; 0 = the plain sample-period difference")),
    ("0x00408366", "transmission_3rd_gear_maximum_speed_ratio_locked",
     c("72", "RE_Max_3_Ratio_Lu", "If ERPM/OSS < this ratio and TCC is on, current gear is 3rd or higher", "45")),
    ("0x00408368", "transmission_overheat_lockup_delay_1_2_time",
     c("74", "RE_Ovr_Heat_Lockup_Delay_1_2_Max", "Min time after 1-2 upshift to allow lockup in over heat mode", "100 = 1 s")),
    ("0x0040836a", "transmission_overheat_lockup_delay_2_3_time",
     c("76", "RE_Ovr_Heat_Lockup_Delay_2_3_Max", "Timer to delay lockup after 2-3 upshift in overheat mode", "35")),
    ("0x0040836c", "transmission_overheat_lockup_delay_3_2_time",
     c("78", "RE_Ovr_Heat_Lockup_Delay_3_2_Max", "Timer to delay lockup after 3-2 downshift in overheat mode", "100")),
    ("0x0040836e", "transmission_overheat_lockup_delay_3_4_time",
     c("7A", "RE_Ovr_Heat_Lockup_Delay_3_4_Max", "Timer to delay lockup after 3-4 upshift in overheat mode", "13")),
    ("0x00408374", "governor_pressure_override_enable",
     c("80", "RE_Governor_Set_Override_Enable", "Enables user override of transmission governor pressure setpoint",
       "0 here; pressure state 0x17")),
    ("0x00408376", "governor_pressure_override_value",
     c("82", "RE_Governor_Set_Override_Value", "User override value for transmission governor pressure setpoint",
       "16256 = 127 psi")),
    ("0x00408378", "exhaust_brake_transmission_features_inhibit",
     c("84", "RE_Ebrake_Inhibit", "Inhibits e_brake-transmission enhancements",
       "0 here; with it clear and switch 12 (the exhaust brake switch) on, cm848_protectionStateTransitionCheck uses "
       "the alternate _c 3-4 / 4-3 lines")),
    ("0x0040837a", "governor_pressure_manual_2nd_in_2nd_gear_maximum",
     c("86", "RE_Governor_Pressure_M2_In_2nd_Gear", "Maximum governor pressure in manual 2nd gear", "6400 = 50 psi")),
    ("0x0040837c", "exhaust_brake_lockup_speed_ratio_2nd_gear_minimum",
     c("88", "RE_EB_Lockup_Range_2nd_Low", "If ERPM/OSS > this ratio, Set RE_E_Brake_Inhibit_LU = FALSE",
       "43 = 1.34 (x 32); with the 2nd gear maximum it brackets the 2nd gear ratio 46 (transmission_gear_ratio_table[2]): "
       "the converter shows lock")),
    ("0x0040837e", "exhaust_brake_lockup_speed_ratio_2nd_gear_maximum",
     c("8A", "RE_EB_Lockup_Range_2nd_High", "If ERPM/OSS < this ratio, Set RE_E_Brake_Inhibit_LU = FALSE", "50 = 1.56")),
    ("0x00408380", "exhaust_brake_lockup_speed_ratio_3rd_gear_minimum",
     c("8C", "RE_EB_Lockup_Range_3rd_Low", "If ERPM/OSS > this ratio, Set RE_E_Brake_Inhibit_LU = FALSE",
       "28 = 0.88 around the 3rd gear ratio 32")),
    ("0x00408382", "exhaust_brake_lockup_speed_ratio_3rd_gear_maximum",
     c("8E", "RE_EB_Lockup_Range_3rd_High", "If ERPM/OSS < this ratio, Set RE_E_Brake_Inhibit_LU = FALSE", "35 = 1.09")),
    ("0x00408384", "exhaust_brake_lockup_speed_ratio_4th_gear_minimum",
     c("90", "RE_EB_Lockup_Range_4th_Low", "If ERPM/OSS > this ratio, Set RE_E_Brake_Inhibit_LU = FALSE",
       "19 = 0.59 around the 4th gear ratio 20")),
    ("0x00408386", "exhaust_brake_lockup_speed_ratio_4th_gear_maximum",
     c("92", "RE_EB_Lockup_Range_4th_High", "If ERPM/OSS < this ratio, Set RE_E_Brake_Inhibit_LU = FALSE", "25 = 0.78")),
    ("0x00408388", "converter_clutch_closed_throttle_lockup_enable",
     c("94", "RE_Closed_Throttle_Lu_Enable", "Flag to disable TCC lockup with brake transition",
       "1 here; cm848_determineCurrentGearAndLockupInhibit")),
    ("0x0040838a", "exhaust_brake_lockup_inhibit_timeout",
     c("96", "RE_E_Brake_Inhibit_Timeout", "Limit for ebrake inhibit while waiting for TCC Lockup",
       "300 = 3 s; reloads exhaust_brake_lockup_inhibit_timer")),
    ("0x0040838c", "converter_clutch_closed_throttle_relock_exhaust_brake_hysteresis",
     c("98", "RE_CT_Relock_Ebrake_Hyst", "OSS Hysteresis for CT relock with ebrake switch on", "1200 = 150 rpm")),
    ("0x0040b14c", "exhaust_brake_lockup_inhibit_timer",
     "e2m 8C17 +4A RE_E_Brake_Inhibit_Timer ('Used to time ebrake TCC inhibit timeout limit'): while bit 0 of "
     "exhaust_brake_lockup_flags (RE_E_Brake_Inhibit_LU) holds the exhaust brake off for a converter clutch lockup, it "
     "counts down from exhaust_brake_lockup_inhibit_timeout; at 0 it sets condition_eval bit 6 and bit 2 of the flags. "
     "300 in the RAM dump (no inhibit pending)"),
    ("0x003fb1cc", "exhaust_brake_lockup_inhibit_previous",
     "Last pass's exhaust_brake_lockup_flags bit 0 (RE_E_Brake_Inhibit_LU) as 0 / 1; cm848_updateExhaustBrakeLockupInhibit "
     "clears the inhibit at the converter clutch request's falling edge only when it has not changed since"),
    ("0x0040b0fe", "exhaust_brake_lockup_flags",
     "e2m 8C19 +16, the exhaust brake lockup aid flag byte (RE_EB_Lockup_Aid_Flag 'True indicates EB lockup aids are "
     "active', RE_E_Brake_Inhibit_LU 'Flag set to inhibit Exhaust Brake to allow TCC lockup', RE_E_Brake_Inhibit_LU_Flag); "
     "8C19 aligns at 0x40b0e8 (protection_condition_flags_t). 23 accesses, all lbz / stb. Bit 0 = RE_E_Brake_Inhibit_LU: "
     "set at the rising edge of the converter clutch solenoid request, by the exhaust brake (engine_retarder_active_flag) "
     "entering 2nd gear and after a 4-3 downshift with it; cleared when transmission_speed_ratio is inside the gear's "
     "exhaust_brake_lockup_speed_ratio window (lock confirmed), in 1st, at the request's falling edge or under "
     "condition_eval bit 6; cm848_updateEngineRetarderEnableState reads it as the torque converter lockup disengaged "
     "input (algorithm_enable_flags_6_cal bit 2). Bit 1: set with bit 0 when the exhaust brake is active as the gear is "
     "forced to 2nd (once per entry). Bit 2: set with condition_eval bit 6 when exhaust_brake_lockup_inhibit_timer runs "
     "out, cleared when that bit clears. Which of RE_EB_Lockup_Aid_Flag / RE_E_Brake_Inhibit_LU_Flag bits 1 / 2 are is not "
     "proved. The byte is updated with | / & masks, so no bitfield"),
    ("0x003fb190", "transmission_output_shaft_acceleration_sample_counter",
     "Pass counter of method 0 of cm848_calculateOutputShaftAcceleration: at transmission_output_shaft_acceleration_sample_period "
     "it resets and the output speed change since the last sample becomes the acceleration"),
    ("0x003fb1c8", "transmission_output_speed_history_index",
     "Write index of method 1's 27-word output speed ring at 0x3fb192 (cm848_calculateOutputShaftAcceleration, mod 27)"),
    ("0x003fb1ce", "transmission_output_shaft_acceleration_filter",
     "cm848_signedFirstOrderFilter record (ema_filter_state_t) of method 1 of cm848_calculateOutputShaftAcceleration: "
     "filters transmission_output_shaft_acceleration_unfiltered into transmission_output_shaft_acceleration (e2m "
     "RE_OSS_Accel); coefficient transmission_output_shaft_acceleration_filter_coefficient"),
    ("0x003fb1d6", "transmission_engine_acceleration_filter",
     "cm848_signedFirstOrderFilter record (ema_filter_state_t): filters half of engine_acceleration_unfiltered into "
     "transmission_engine_acceleration_filtered (e2m RE_Filtered_Engine_Accel); coefficient "
     "transmission_engine_acceleration_filter_coefficient"),
    ("0x0040780c", "transmission_3rd_gear_lockup_enable",
     "e2m 8BBC +0 RE_3rd_Gear_Lockup ('Indicates if lockup should be allowed in 3rd gear'; 1 in the RAM dump); tested "
     "by cm848_applyConverterLockupSchedule. The ordinal now matches the other round 8 names (3rd)"),
    ("0x00407860", "transmission_manual_1st_unlock_maximum_output_speed",
     "e2m 8BBC +54 RE_Unlock_2nd_In_M1 ('OSS must be < this threshold to unlock for manual 1st downshift'): 16800 = 2100 "
     "rpm; cm848_applyConverterUnlockConditions"),
    ("0x00407862", "transmission_manual_2nd_unlock_maximum_output_speed",
     "e2m 8BBC +56 RE_Unlock_3rd_In_M2 ('OSS must be < this threshold to unlock for manual 2nd downshift')"),
]
FUNCTIONS = [
    ("0x00034f4c", "cm848_updateExhaustBrakeLockupInhibit",
     "The exhaust brake lockup aid (e2m RE_E_Brake_Inhibit_LU / RE_EB_Lockup_Range_* / RE_E_Brake_Inhibit_Timeout). The "
     "rising edge of the converter clutch solenoid request (logical output 18) sets bit 0 of exhaust_brake_lockup_flags, "
     "which holds the exhaust brake off (cm848_updateEngineRetarderEnableState reads it as lockup disengaged) until the "
     "converter locks. exhaust_brake_lockup_inhibit_timer counts down from exhaust_brake_lockup_inhibit_timeout (3 s). "
     "While the request is on and transmission_speed_ratio is inside the gear's window "
     "(exhaust_brake_lockup_speed_ratio_2nd / 3rd / 4th_gear_minimum / _maximum, around the gear ratios), bits 0 and 2 "
     "clear: lock confirmed, the exhaust brake may apply. In 1st they clear too. If the timer runs out first, it sets "
     "condition_eval bit 6 (the lockup inhibit / converter unlock request) and bit 2. Called at the end of "
     "cm848_selectGovernorPressureLockupBoost (was cm848_monitorConverterClutchEngagement, stage E's misreading; "
     "originally cm848_processProtectionRateLimitFlags)"),
    ("0x00035154", "cm848_selectGovernorPressureLockupBoost",
     "The 48RE lockup boost governor pressure mode (pressure state 0x10, e2m RE_Lockup_Boost 'Gov pressure target during "
     "lockup, to prevent downshift'): in 3rd / 4th outside transfer-case low range, with the lever not in 1 / 2 "
     "(transmission_selected_gear 0x7e / 0x7f), condition_eval bit 6 clear, transmission_overheat_protection_active_flag "
     "clear and switch 12 (the exhaust brake switch) off, while the throttle is below the lockup curve (the tables it "
     "shares with cm848_applyConverterLockupSchedule; once in the mode the second curve, held by load_condition_flags bit "
     "2 = RE_High_Pressure), the target is governor_pressure_lockup_boost. The user override (governor_pressure_override_enable "
     "/ _value, state 0x17) follows. With the lever in 1 / 2 and the output speed below "
     "transmission_manual_2nd_4_3_downshift_maximum_output_speed it requests the 4-3 downshift (condition_eval bit 1, "
     "clearing the 3-4 bit 2) unless overdrive_control_flags bit 3 is set. Ends with cm848_updateExhaustBrakeLockupInhibit "
     "(was cm848_selectGovernorPressureHighGear in stage E; originally cm848_calculateProtectionThresholdLimit)"),
]
