"""Round 18 stage B (label-only): the main injection timing selection and the 4D / user commanded timing, from e2m 8085,
125C, 103B and 106B (placed by the ECU's parameter ID table) and the code of cm848_selectMainInjectionTiming /
cm848_calculateFourDimensionalInjectionTiming (round 15 lead: 'user commanded timing ... read the 125C enable first')."""
GLOBALS = [
    ("0x00409e40", "main_injection_timing_selection",
     "How main_injection_timing is produced (e2m value labels 0 NOADJUST / 1 HPCRTMNG / 2 USEROVRD / 3 HPCRINCR): 0 "
     "leaves it, 1 calculates it (cm848_calculateMainInjectionTiming), 2 takes user_commanded_injection_timing_cal, 3 "
     "calculates it and adds user_commanded_injection_timing_cal and the top dead center offset (1 in the dump)"),
    ("0x003fd808", "user_commanded_injection_timing_cal",
     "The user commanded timing: the main injection timing while main_injection_timing_selection is 2, an increment "
     "to the calculated timing while it is 3, and the 4D timing while algorithm_enable_flags_4_cal bit 8 "
     "(User_Commanded_Timing_Enable) is set"),
    ("0x003fd806", "user_commanded_injection_timing_increment_cal",
     "Added to four_dimensional_injection_timing while governor_feature_config_word bit 0x4000 is set "
     "(cm848_calculateFourDimensionalInjectionTiming)"),
    ("0x0040a2ee", "four_dimensional_injection_timing",
     "The 4D timing: four_dimensional_injection_timing_map_a / _b (engine speed x final_fueling) blended by the "
     "combustion alpha, or user_commanded_injection_timing_cal while algorithm_enable_flags_4_cal bit 8 is set; plus "
     "the increment"),
    ("0x00406a5e", "four_dimensional_injection_timing_map_a_x_axis",
     "The engine speed axis of 4D timing map a (alpha 16384 = map a only); flat 171 counts (20 degrees) in the dump"),
    ("0x00406a86", "four_dimensional_injection_timing_map_a_y_axis", "The final_fueling axis of 4D timing map a"),
    ("0x00406aa8", "four_dimensional_injection_timing_map_a_grid", "4D timing map a (engine speed x final_fueling)"),
    ("0x00406d08", "four_dimensional_injection_timing_map_b_x_axis",
     "The engine speed axis of 4D timing map b (alpha 0 = map b only)"),
    ("0x00406d30", "four_dimensional_injection_timing_map_b_y_axis", "The final_fueling axis of 4D timing map b"),
    ("0x00406d52", "four_dimensional_injection_timing_map_b_grid", "4D timing map b (engine speed x final_fueling)"),
    ("0x003fd5a4", "algorithm_enable_flags_4_cal",
     "Algorithm enable flags word 4 (EEPROM 0x122, in the CRC-guarded block): bit 0 User_Commanded_Fueling_Enable "
     "(cm848_selectUserCommandedFueling), bit 8 User_Commanded_Timing_Enable "
     "(cm848_calculateFourDimensionalInjectionTiming)"),
]
FUNCTIONS = [
    ("0x0001e870", "cm848_calculateFourDimensionalInjectionTiming",
     "Calculates the 4D timing four_dimensional_injection_timing (e2m 103B +0 Four_D_Timing; 0.1171875 degree counts): "
     "four_dimensional_injection_timing_map_a / _b (engine speed x final_fueling) blended by the combustion alpha (Q14, "
     "16384 = map a only, 0 = map b only), or user_commanded_injection_timing_cal while algorithm_enable_flags_4_cal bit "
     "8 (User_Commanded_Timing_Enable) is set (injection_timing_intermediate_source_code 0 for the maps, 2 for the user "
     "timing). Adds user_commanded_injection_timing_increment_cal and sets injection_timing_increment_flags to 1 when "
     "governor_feature_config_word bit 0x4000 is set, and copies the result to main_injection_timing_copy (103B +2 "
     "SOI), which cm848_copyMainInjectionTiming overwrites with main_injection_timing before its only reader "
     "cm848_computeFuelRpmCompensatedOffset runs. Both maps are flat 171 counts (20 degrees) in the dump. Task of "
     "cm848_periodicTaskSet_auxiliaryControl"),
    ("0x0004b5b8", "cm848_selectMainInjectionTiming",
     "Once per pass of cm848_periodicTaskSet_auxiliaryControl: packs the winning-source codes of the pilot timing, "
     "pilot quantity, rail pressure setpoint and main timing into combined_emissions_state, rebuilds bits 1 / 2 / 4 of "
     "injection_timing_adjustment_flags, then produces main_injection_timing by main_injection_timing_selection (e2m "
     "8085 +0 Main_SOI_Selection_Switch): 2 = user_commanded_injection_timing_cal (source code 7), 1 and 3 = "
     "cm848_calculateMainInjectionTiming, 0 = no change"),
]
