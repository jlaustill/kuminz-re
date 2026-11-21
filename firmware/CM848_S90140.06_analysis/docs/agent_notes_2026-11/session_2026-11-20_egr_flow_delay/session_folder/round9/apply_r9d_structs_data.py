R = "e2m 8C19 +{} {} ({})"
STRUCTS = [
    ("protection_condition_flags_t", "transmission_control_flags_t", "protection_condition_flags_t_0040b0e8",
     "transmission_control_flags", "0x0040b0e8", {
         "condition_eval": ("request_flags", R.format("0", "RE_Trans_Flag1", "RE_Request_4_3 / RE_Request_3_4 / RE_CT_Unlock / RE_In_Cal / RE_Init_Timer_Complete / RE_Lockup_OD_Off_Flag / RE_Lockup_TC_Mimic / RE_Offset_Learning_Enable") +
                            ": bit 1 = the 4-3 request and bit 2 = the 3-4 request (set by the cruise / normal / low range shift lines, cleared by cm848_processOverdriveSwitchAndShift); bit 6 = the converter unlock request that blocks lockup (set by the exhaust brake inhibit timeout, the closed-throttle unlock and a brake transition)"),
         "condition_flags_1": ("mode_flags", R.format("1", "RE_Trans_Flag2", "RE_Cruise_Active / RE_Decel_Mode_Active / RE_Low_Range / RE_Relock / RE_Previous_Brake_Switch / RE_Init_Cal_Complete / RE_Prev_Calc_Neg") +
                               ": bit 0 = cruise decel mode (set with the cruise decel 4-3, cleared with its 3-4), bit 2 = transfer-case low range, bit 4 = cruise active (follows cruise_control_engaged_flag); bits 3 / 5 are set by the brake-transition unlock"),
         "load_condition_flags": ("state_flags", R.format("2", "RE_Trans_Flag3", "RE_Forced_2nd_Gear_ID / RE_High_Pressure / RE_Upshift_3_4 / RE_Service_Lockup_Switch / RE_Force_4_Gear_Identification / RE_Launch_NV / RE_Low_Range_NV") +
                                  ": bit 1 = the gear forced to 2nd (cm848_determineCurrentGearAndLockupInhibit), bit 2 = the lockup boost hold (RE_High_Pressure; cm848_selectGovernorPressureLockupBoost), bit 5 = service lockup (with the lockup / unlock service output speed limits), bit 7 = a 3-4 upshift in progress"),
         "overdrive_control_flags": ("overdrive_flags", R.format("3", "RE_OD_Flags", "RE_OD_Inhibit / RE_OD_Toggle / RE_OD_Mimic / RE_OD_Disable_Cold / RE_OD_Disable_Hot / RE_Inhibit_3_4_Cruise / RE_Quick_Key_On_Toggle / RE_T_Cool_BP_Kit")),
         "reserved_04": ("axle_ratio_learning_flags", R.format("4", "RE_Nvratio_Learn_Flags", "the N / V (engine speed / vehicle speed) ratio learning flags") +
                         ": only cm848_learnOutputSpeedToVehicleSpeedRatio uses it (bit 0 set / tested)"),
         "condition_flags_3": ("limp_home_flags_1", R.format("5", "RE_Limp_Flags1", "RE_TPS_Elect_Limp / RE_Cltemp_Elect_Limp / RE_Trans_Relay_Circuit_Open")),
         "condition_flags_2": ("limp_home_flags_2", R.format("6", "RE_Limp_Flags2", "RE_Governor_Press_Sol_Circuit / RE_Overdrive_Solenoid_Circuit / RE_TPS_Rat_Limp")),
         "reserved_07": ("limp_home_flags_3", R.format("7", "RE_Limp_Flags3", "RE_Gov_Sensor_Limp_Circuit / RE_Trans_Sump_Temp_Rationality") +
                         ": bit 0 blocks lockup in cm848_determineCurrentGearAndLockupInhibit (with limp_home_flags_4 bit 0)"),
         "fault_state_flags": ("limp_home_flags_4", R.format("8", "RE_Limp_Flags4", "RE_OSS_Limp / RE_Spd_Rat_Limp / RE_Lockup_Converter_Clutch_Solenoid_Circuit / RE_Gov_Sensor_Limp_Offset / RE_Trans_Sump_Temp_Circuit / RE_GCST_Limp")),
         "action_flags": ("low_range_boost_flags", R.format("9", "RE_Low_Range_Boost_1_2 / RE_Low_Range_Boost_2_3", "the governor pressure is being raised to cause the 1-2 / 2-3 shift in low range") +
                          ": bits 0 / 1, cleared by cm848_initializeTransmissionShiftLogic (& 0xfc)"),
     }),
    ("protection_status_flags_t", "transmission_shift_strategy_flags_t", "protection_status_flags_t_0040b0f2",
     "transmission_shift_strategy_flags", "0x0040b0f2", {
         "status_flags": ("wide_open_throttle_flags", R.format("A", "WOT flags", "RE_Trans_WOT / RE_WOT_Anti_Hang_Flag / RE_WOT_Boost_1_2 / RE_WOT_Boost_2_3 / RE_WOT_2LU_Flag / RE_WOT_2LU_Init_Flag / RE_WOT_Hung_Shift") +
                          ": bit 4 = the anti-hang timer is armed (RE_WOT_Anti_Hang_Flag), bits 3 / 5 go with the WOT 1-2 / 2-3 boosts (cm848_selectGovernorPressureWideOpenThrottle)"),
         "reserved_01": ("run_fuel_mode_flags", R.format("B", "RE_Run_Fuel_Mode", "Indicates run fuel mode is active") + ": no access found"),
         "output_flags": ("service_test_request_flags", R.format("F", "RE_Cmd25_3_4_Shift / RE_Cmd25_Gov_Press / RE_Cmd25_TCC", "service tool requests to test the OD solenoid / the pressure control / the lockup solenoid") +
                          ": bits 0-2; set by cm848_sciCommand37Callback; the shift and lockup logic skip their work while any is set"),
         "rate_limit_flags": ("limp_home_and_temperature_flags", R.format("11", "RE_Governor_3rd_Gear_Default / RE_Trans_Temp_Initial_Obtained", "limp-home 3rd gear mode / the first transmission temperature reading obtained") +
                              ": cm848_selectTransmissionTemperatureInUse / cm848_resetTransmissionTemperatureValidation, cm848_controlGovernorPressureSolenoid, cm848_calibrateGovernorPressureSensorOffset"),
     }),
]
SPLIT = [("anti_hunt_flags", R.format("C", "anti-hunt / detent flags", "RE_AH_Boost_1_2 / RE_AH_Boost_2_3 / RE_Anti_Hunt / RE_Detent / RE_Detent_2_3 / RE_Rollstest") +
          ": bit 7 = the anti-hunt 1-2 boost and bit 6 = the 2-3 boost (cm848_selectGovernorPressureNormal), bit 4 = throttle past the detent (transmission_throttle_detent_set_threshold)"),
         ("output_shaft_speed_flags", R.format("D", "RE_OSS_Too_Slow", "Indicates output shaft speed too slow") + ": no access found"),
         ("actuator_test_flags", R.format("E", "RE_Act_Test_Running", "Indicates service tool request for trans solenoid test") +
          ": bit 0, set and cleared by cm848_sciCommand19OutputTestCallback")]


