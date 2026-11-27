"""Round 7 stage C (main session, label-only): the drivetrain ratio module (Bank 2 0x525e54-0x5267f4). Read in full:
cm848_updateDrivetrainRatio, initGovernorJ1939Bypass, etcTransmissionModeControl, cm848_output_shaft_speed_save, the
VSS interrupt handler's period average, cm848_calculateVehicleSpeedLimitFueling's gear-down branch. e2m 106D names
the drivetrain ratio cals; 1185 +A Top_Gear_Ratio and 8B8B Gear_Down_Gear_Ratio ('down from top gear', 1/2048) the
two gear ratios."""
GLOBALS = [
    ("0x0040b6e8", "drivetrain_ratio_filter_state",
     "the drivetrain_ratio low-pass filter (exponentialMovingAverage): accumulator = the ratio << 16, coefficient -> "
     "drivetrain_ratio_filter_coefficient (e2m 106D +6 Gear_Ratio_Filter_Constant) or the out of gear coefficient; "
     "used only by cm848_updateDrivetrainRatio and cm848_initializeDrivetrainRatio"),
    ("0x0040b702", "drivetrain_ratio_engine_period_valid_flag",
     "1 when the VSS interrupt has averaged the engine speed period between two VSS pulses "
     "(drivetrain_ratio_engine_period_average, main or backup sensor pulses counted), 0 when no engine pulse fell "
     "between them; cm848_updateDrivetrainRatio computes the period-based ratio only while it is 1"),
    ("0x0040b5c2", "drivetrain_gear_range",
     "the gear-down range of drivetrain_ratio: 1 = top gear (below top_gear_ratio_threshold), 2 = one gear down (below "
     "gear_down_ratio_threshold), 3 = lower. With the gear-down feature (j1939_governor_feature_cal bit 0x100) only top "
     "gear keeps the road speed governor's droops (cm848_calculateVehicleSpeedLimitFueling); "
     "cm848_selectCruiseControlGainZone and cm848_initializeFaultCruiseSpeedLimit test it too. Only 1 / not 1 is "
     "tested"),
    ("0x0040b6f0", "top_gear_ratio_threshold",
     "top_gear_ratio_cal (e2m 1185 +A Top_Gear_Ratio; 1638 = 0.8 in the EEPROM image) x (1 + the percent at "
     "0x408b78), at most the e2m 106D +4 Gear_Ratio_Max_Limit; drivetrain_ratio below it = top gear"),
    ("0x0040b6f2", "gear_down_ratio_threshold",
     "the gear down gear ratio at 0x3fd900 (2048 = 1.0 in the EEPROM image) x (1 + the percent at 0x408b78), at most "
     "Gear_Ratio_Max_Limit; drivetrain_ratio below it (and not top gear) = one gear down"),
]
FUNCTIONS = [
    ("0x005263a8", "cm848_initializeDrivetrainRatio",
     "Initializes the drivetrain ratio: clears the ETC1 out of gear flag, drivetrain_gear_range = 1 (top gear), "
     "drivetrain_ratio_raw / drivetrain_ratio / drivetrain_ratio_user_filtered (and its previous copy) = "
     "drivetrain_ratio_default, the filter state seeded with it and pointed at drivetrain_ratio_filter_coefficient, "
     "and drivetrain_ratio_engine_period_valid_flag = 1"),
    ("0x005264d4", "cm848_applyJ1939OutOfGearToDrivetrainRatio",
     "With a J1939 vehicle speed source (vehicle_speed_sensor_type_cal 4 / 5), the vehicle at or above "
     "vehicle_speed_minimum, the engine not stopped and valid ETC1 out of gear data, it copies the ETC1 out of gear flag "
     "into drivetrain_ratio_unsettled_flag and drivetrain_ratio_out_of_gear_cruise_disable_flag, and while out of gear "
     "holds drivetrain_ratio_user_filtered at drivetrain_ratio"),
    ("0x005267e0", "cm848_saveOutputShaftSpeed",
     "output_shaft_speed_saved = output_shaft_speed_current"),
]
