"""Round 16 stage A (label-only): the cruise control / road speed governor family (e2m 117D / 117F / 1180 / 1184-1191,
11A4). Each row is placed by the ECU's parameter ID table (e2m_block_addresses.py) and checked against its code use.
Vocabulary decisions (task 046):
- The road speed governor is road_speed_governor_*: the e2m calls it RSG / Road_Speed_Governor_Enable, and its siblings
  in FUELING_STATE are the low / high / variable / all speed governors. vehicle_speed_limit_* is retired.
- The shared cruise / RSG PID keeps cruise_pid_* for its terms and gains; its other words are cruise_governor_*.
- The three PID gain sets are gain sets (e2m 'Switch to Cruise/RSG gain set 2 ...'), not zones.
- The 'sump' (e2m Cruise_RSG_Sump_*): fuel held outside the integrator that drains to 0 at the sump decrement /
  increment rates; a preset fills it with the step between the present and the preset fueling, the trigger with
  Sump_Fuel_Init_Gain x the road speed change.
- The maximum road speeds pair with their trims: Max_Road_Speed / Max_Road_Speed_Trim, Cruise_Max_Road_Speed /
  Cruise_Max_Road_Speed_Trim."""
RSG = "the road speed governor (e2m RSG)"
GLOBALS = [
    # the maximum road speeds and their trims (e2m 117D / 117F / 1180)
    ("0x003fd52a", "cruise_maximum_road_speed_trim_cal",
     "The customer trim of cruise_maximum_road_speed_cal: cm848_calculateMaximumRoadSpeeds copies it there each pass "
     "(or the lower road_speed_governor_reference_speed while cruise_maximum_road_speed_clamp_enable is set)"),
    ("0x003fd52c", "maximum_road_speed_trim_cal",
     "The customer trim of the maximum road speed: the reference speed of " + RSG + " "
     "(road_speed_governor_reference_speed, lowered by the fault ramp) and the power-up maximum_road_speed"),
    ("0x0040a27e", "maximum_road_speed",
     "Set from maximum_road_speed_trim_cal at power-up (cm848_initializeMaximumRoadSpeeds); "
     "j1939HandlePgn65261CruiseControlSetup sends it in km/h as SPN 74 Maximum Vehicle Speed Limit"),
    ("0x0040a2c6", "electronic_smart_power_tau_state",
     "No writer in this code; cm848_updateCruiseAndRoadSpeedGovernorDroops reads it: 0 / 1 / 2 pick the top droop "
     "offset for tau 0 / an intermediate tau / tau 1 (cruise_top_droop_offset_tau_0 / _intermediate_tau / _tau_1), any "
     "other value keeps cruise_top_droop_offset"),
    # e2m 1186: the droop and gain set calibrations
    ("0x00408e00", "cruise_droops_allowed_speed_tolerance",
     "cm848_selectCruiseGovernorGainSet sets cruise_droops_allowed_flag while the road speed is within this of the "
     "cruise speed command and the filtered fueling is between the bottom and top droop offsets"),
    ("0x00408e0c", "cruise_top_droop_offset_tau_0",
     "The top droop offset for tau 0 (cm848_updateCruiseAndRoadSpeedGovernorDroops: electronic_smart_power_tau_state "
     "0); also the fueling the top droop gains are measured from (cm848_calculateTopDroopGain)"),
    ("0x00408e20", "cruise_governor_gain_set_2_speed_error_threshold",
     "cm848_selectCruiseGovernorGainSet picks gain set 2 when the absolute speed error after droop is above this (plus "
     "the hysteresis) and the fueling is above the bottom droop offset (plus its hysteresis)"),
    ("0x00408e22", "cruise_governor_gain_set_speed_error_hysteresis",
     "The hysteresis on both gain set speed error thresholds (cm848_selectCruiseGovernorGainSet)"),
    ("0x00408e24", "cruise_governor_gain_set_bottom_droop_offset_hysteresis",
     "The fueling hysteresis above cruise_bottom_droop_offset in the gain set choice (cm848_selectCruiseGovernorGainSet)"),
    ("0x00408e2e", "cruise_governor_gain_set_3_speed_error_threshold",
     "cm848_selectCruiseGovernorGainSet picks gain set 3 when the speed error after droop is below this (minus the "
     "hysteresis) and the fueling is at or below the bottom droop offset"),
    # e2m 1187: the working droop gains and PID gains
    ("0x0040b696", "cruise_droops_allowed_flag",
     "Set by cm848_selectCruiseGovernorGainSet (see cruise_droops_allowed_speed_tolerance), cleared in SET / COAST / "
     "RESUME / ACCELERATE; while it and cruise_control_engaged_flag are 1 the droop gains go to the cruise control "
     "fueling"),
    ("0x0040b69e", "cruise_governor_bumpless_transfer_flag",
     "1 on the pass the gain set changes (cm848_selectCruiseGovernorGainSet): the governor then recomputes the "
     "integrator and the sump fuel so its output does not step"),
    ("0x0040b6a0", "cruise_pid_derivative_gain",
     "The derivative gain of the selected gain set (cruise_governor_gain_set_pointer +4)"),
    ("0x0040b6a4", "cruise_governor_gear_ratio_gain",
     "The gear ratio gain: e2m 11A5 / 11A6 Cruise_RSG_Gain_Adj_X / _Y looked up at drivetrain_ratio_user_filtered "
     "(cm848_selectCruiseGovernorGainSet; 100 = 1.00); multiplies the speed error and its rate"),
    ("0x0040b6a6", "cruise_pid_integral_gain",
     "The integral gain of the selected gain set (cruise_governor_gain_set_pointer +2)"),
    ("0x0040b6a8", "cruise_pid_integral_acceleration_gain",
     "The integral acceleration gain of the selected gain set (cruise_governor_gain_set_pointer +6): weighs the "
     "differential path into the integrator"),
    ("0x0040b6aa", "cruise_pid_proportional_gain",
     "The proportional gain of the selected gain set (cruise_governor_gain_set_pointer +0)"),
    ("0x0040b6b2", "road_speed_governor_fueling_bottom_droop_gain",
     "The bottom droop gain cm848_calculateRoadSpeedGovernorFueling uses (road_speed_governor_bottom_droop_gain)"),
    ("0x0040b6b4", "road_speed_governor_fueling_bottom_droop_offset",
     "The bottom droop offset cm848_calculateRoadSpeedGovernorFueling uses"),
    ("0x0040b6b8", "road_speed_governor_fueling_top_droop_gain",
     "The top droop gain cm848_calculateRoadSpeedGovernorFueling uses (road_speed_governor_top_droop_gain)"),
    ("0x0040b6ba", "road_speed_governor_fueling_top_droop_offset",
     "The top droop offset cm848_calculateRoadSpeedGovernorFueling uses"),
    ("0x0040b6c0", "cruise_governor_gain_set_pointer",
     "The selected PID gain set: cm848_selectCruiseGovernorGainSet points it at gain set 1 / 2 / 3 (0x408e02 / "
     "0x408e18 / 0x408e26) and copies its four gains into cruise_pid_*_gain (0 in the RAM dump: cruise had not run)"),
    # e2m 118A: the governor terms
    ("0x0040b6c4", "cruise_governor_fueling",
     "The output of the cruise / road speed governor (also written to adjusted_user_fueling): the PID sum clamped to "
     "cruise_governor_fueling_minimum and the fueling maximum"),
    ("0x0040b6c8", "cruise_governor_speed_error",
     "cruise_governor_reference_speed - vehicle_speed_rise_limited, clamped to cruise_governor_speed_error_minimum / "
     "_maximum"),
    ("0x0040b6ca", "cruise_governor_speed_error_after_droop",
     "cruise_governor_speed_error - cruise_droop_speed_error_delta, clamped to +-0xa00 (10 mph)"),
    ("0x0040b6cc", "cruise_governor_external_reset_flag",
     "Set on RESUME (cm848_cruiseSpeedCommandStateMachine); the next governor pass presets the governor, which clears it"),
    ("0x0040b6d2", "cruise_pid_proportional_fuel",
     "The proportional term: the filtered engine speed error x cruise_pid_proportional_gain >> 12, saturated to 16 bits"),
    ("0x0040b6d6", "cruise_governor_speed_error_gain",
     "e2m Cruise_RSG_Gain_Auto (the Cruise_RSG_Gain computed from the axle ratio): driveshaft rpm per mph "
     "(tire_revolutions_per_mile_cal x rear_axle_ratio / 60) x 100 >> 7 x cruise_governor_speed_error_gain_multiplier "
     ">> 10, capped at cruise_governor_speed_error_gain_tool_upper_limit; turns the mph speed error into engine speed "
     "units (cm848_calculateCruiseGovernorEngineSpeedError)"),
    ("0x0040b6d8", "cruise_reference_rate_limit_preset_flag",
     "Set on SET: the next governor pass starts the rate-limited reference at the road speed plus the droop error delta "
     "(cruise_rate_limited_reference_speed_previous) and clears it"),
    ("0x0040b6dc", "cruise_governor_preset_fueling",
     "The fueling a governor preset starts from: final_fueling, or once the speed has been steady for "
     "cruise_governor_preset_fueling_time the filtered fueling of that steady window"),
    ("0x0040b6de", "cruise_governor_sump_fuel",
     "The sump: fuel held outside the integrator and added to the PID sum; drains toward 0 by "
     "cruise_governor_sump_decrement_rate / _increment_rate each pass. A preset fills it with final_fueling - the "
     "preset fueling, a sump trigger with cruise_governor_sump_trigger_fuel, a gain set change with the step that "
     "keeps the output"),
    # e2m 118C / 118D / 118F / 1190 / 1191
    ("0x00408e86", "cruise_road_speed_maximum_change",
     "The largest rise of vehicle_speed_rise_limited per pass (cm848_calculateRiseLimitedVehicleSpeed limits rises only)"),
    ("0x0040b6e2", "engine_speed_to_vehicle_speed_ratio",
     "tire_revolutions_per_mile_cal x rear_axle_ratio / 60 (driveshaft rpm per mph): with the gear ratio it turns the "
     "engine speed into the predicted vehicle speed (cm848_calculateRiseLimitedVehicleSpeed)"),
    ("0x00408e88", "cruise_accelerate_ramp",
     "The cruise_speed_command step per pass while ACCELERATE is held (cm848_increaseCruiseSpeedCommand)"),
    ("0x00408e8a", "cruise_bump_down_step",
     "The cruise_speed_command step for a BUMP DOWN (cm848_decreaseCruiseSpeedCommand)"),
    ("0x00408e8c", "cruise_bump_up_step",
     "The cruise_speed_command step for a BUMP UP, taken only while the command is below the road speed plus one "
     "step; SET caps the command at the maximum when the road speed plus one step is above it; cm848_selectCruiseOrUserFueling "
     "scales it by cruise_bump_up_step_margin_scale"),
    ("0x00408e8e", "cruise_coast_ramp",
     "The cruise_speed_command step per pass while COAST is held (cm848_decreaseCruiseSpeedCommand)"),
    ("0x00408e90", "cruise_minimum_coast_speed",
     "COAST and BUMP DOWN do not take cruise_speed_command below this (cm848_decreaseCruiseSpeedCommand)"),
    ("0x00408e92", "cruise_minimum_set_speed",
     "The lowest cruise set speed: SET, the resume speed check and the preset fueling window need the road speed or "
     "the set speed above it"),
    ("0x00408e98", "cruise_bump_up_step_margin_scale",
     "ROM (no e2m record): cm848_selectCruiseOrUserFueling uses the cruise fueling only while "
     "cruise_governor_reference_speed is above the road speed + cruise_bump_up_step x this / 256"),
    ("0x0040b6e4", "cruise_resume_speed",
     "The remembered set speed: SET and HOLD store cruise_speed_command (capped at cruise_maximum_road_speed_cal), "
     "RESUME restores it, power-up restores it from cruise_saved_set_speed_cal"),
    ("0x0040b6e6", "cruise_resume_speed_valid_flag",
     "1 while cruise_resume_speed is between cruise_minimum_set_speed and cruise_maximum_road_speed_cal; cleared in OFF"),
    ("0x003fee78", "cruise_saved_set_speed_cal",
     "cm848_saveCruiseSetSpeedForPowerDown stores cruise_speed_command here on the power-down path (0 while "
     "j1939_governor_feature_cal bit 0x8000 is clear); cm848_restoreSavedCruiseSetSpeed restores it at power-up"),
    # e2m 1189: the governor calibrations
    ("0x00408e4c", "cruise_reference_speed_rate_limit_increase",
     "The largest rise per pass of cruise_rate_limited_reference_speed toward cruise_speed_command"),
    ("0x00408e4e", "cruise_reference_speed_rate_limit_decrease",
     "The largest fall per pass of cruise_rate_limited_reference_speed toward cruise_speed_command"),
    ("0x00408e5c", "cruise_governor_fueling_maximum",
     "The governor's fueling maximum while programmable power is off (cruise_governor_fueling_maximum_pointer points "
     "here, else at current_horsepower_peak_fueling_cal)"),
    ("0x00408e5e", "cruise_governor_fueling_minimum",
     "The governor output is not taken below this"),
    ("0x00408e60", "cruise_governor_speed_error_gain_multiplier",
     "The multiplier (1/1024) in cruise_governor_speed_error_gain"),
    ("0x00408e64", "cruise_governor_speed_error_maximum", "The upper clamp of cruise_governor_speed_error"),
    ("0x00408e66", "cruise_governor_speed_error_minimum", "The lower clamp of cruise_governor_speed_error"),
    ("0x00408e68", "cruise_governor_no_fuel_fueling",
     "The floor of the integrator and of the bumpless integrator preset"),
    ("0x00408e6a", "cruise_governor_speed_error_gain_tool_upper_limit",
     "The cap of cruise_governor_speed_error_gain (cm848_calculateCruiseGovernorSpeedErrorGain)"),
    ("0x00408e6c", "road_speed_governor_integrator_preset_fuel_offset",
     "A preset of " + RSG + " after variable speed governor / cruise / dual axis fueling starts the integrator at "
     "final_fueling - this"),
    ("0x00408e72", "cruise_governor_preset_fueling_acceleration_threshold",
     "The steady speed window of the preset fueling restarts while the road speed change per pass is outside +- this"),
    ("0x00408e74", "cruise_governor_preset_fueling_time",
     "The pass count of the steady speed window (reload of cruise_governor_preset_fueling_countdown)"),
    ("0x00408e76", "cruise_governor_sump_fuel_initial_gain",
     "A sump trigger fills the sump with this x the road speed change per pass (cruise_governor_sump_trigger_fuel)"),
    ("0x00408e78", "cruise_governor_sump_prevent_time",
     "After a sump trigger or a preset the sump cannot trigger again for this many passes"),
    ("0x00408e80", "cruise_governor_sump_threshold_gain",
     "The speed error weight of the sump activation value (cruise_governor_sump_activation)"),
    ("0x00408e82", "cruise_governor_sump_decrement_rate", "The drain per pass of a positive sump"),
    ("0x00408e84", "cruise_governor_sump_increment_rate", "The drain per pass of a negative sump"),
    # the governor's working words (no e2m records: the ROM-to-RAM window)
    ("0x003fcff8", "cruise_governor_gain_set_number",
     "The selected PID gain set: 1 / 2 / 3 (cm848_selectCruiseGovernorGainSet; 1 at power-up)"),
    ("0x003fd000", "cruise_rate_limited_reference_speed_previous",
     "cruise_rate_limited_reference_speed of the previous pass (or the road speed plus the droop error delta after SET)"),
    ("0x003fd002", "cruise_governor_pid_fueling",
     "The PID sum (proportional + integral - derivative + sump, clamped to -0x24b..0x2e00) before the fueling clamps; "
     "the integral adjustment uses the previous pass's value"),
    ("0x003fd004", "cruise_rate_limited_reference_speed",
     "cruise_speed_command rate limited by cruise_reference_speed_rate_limit_increase / _decrease: the cruise "
     "reference of the governor (e2m 'rate_limited_cc_ref_speed')"),
    ("0x003fd006", "cruise_governor_filtered_road_speed",
     "vehicle_speed_rise_limited through the derivative filter (cm848_secondOrderFilterUnsigned); its change per pass "
     "is the road speed change the sump and the preset fueling window use. That filter returns 0 in this build (asm: "
     "two srwi 16), so this is 0 except right after a preset"),
    ("0x003fd008", "cruise_droop_fueling_filtered",
     "final_fueling through the droop fueling filter (coefficient e2m 1186 +E Cruise_RSG_Droop_Fueling_Filter_Constant): "
     "the fueling cm848_selectCruiseGovernorGainSet compares with the droop offsets"),
    ("0x003fd048", "cruise_governor_fueling_state_previous",
     "adjusted_user_fueling_state at the end of the previous governor pass: a preset reads it to pick the integrator "
     "start"),
    ("0x003fd04a", "cruise_governor_sump_holdoff_countdown",
     "Counts cruise_governor_sump_prevent_time down after a sump trigger or a preset; the sump cannot trigger before 0"),
    ("0x003fd04c", "cruise_governor_preset_fueling_countdown",
     "Counts the steady speed window of the preset fueling down from cruise_governor_preset_fueling_time"),
    ("0x003fd04f", "cruise_governor_sump_activation_countdown",
     "The sump triggers after the activation condition holds for 4 passes (reset to 4)"),
    ("0x003fd053", "cruise_governor_sump_trigger_fuel",
     "cruise_governor_sump_fuel_initial_gain x the road speed change, clamped to +-0xb80: what a sump trigger moves out "
     "of the integrator into the sump"),
    ("0x003fd055", "cruise_governor_sump_trigger_flag", "1 on the pass the sump triggers"),
    ("0x003fb52e", "cruise_speed_command_previous_state",
     "cruise_control_state at the end of the previous cm848_cruiseSpeedCommandStateMachine pass (OFF at power-up)"),
    # the road speed governor reference (no e2m records)
    ("0x0040b5bc", "road_speed_governor_reference_speed",
     "The lower of maximum_road_speed_trim_cal and fault_vehicle_speed_limit: the reference speed of " + RSG + " "
     "(cm848_calculateRoadSpeedGovernorFueling, cm848_runCruiseAndRoadSpeedGovernor)"),
    ("0x0040b5be", "road_speed_governor_reference_speed_copy",
     "A copy of road_speed_governor_reference_speed taken each pass (no reader in this code)"),
    ("0x00408b7a", "cruise_maximum_road_speed_clamp_enable",
     "While nonzero cm848_calculateMaximumRoadSpeeds lowers cruise_maximum_road_speed_cal to "
     "road_speed_governor_reference_speed when that is lower (1 in the RAM dump)"),
    ("0x0040b674", "road_speed_governor_fueling",
     "The fueling of " + RSG + " (cm848_calculateRoadSpeedGovernorFueling; 0x1700 = no limit)"),
]
# 0x003fd038 (cruise_speed_upper_limit_ptr) renders _-prefixed (a word row read as a pointer): stage B renames
# and retypes it together.
FUNCTIONS = [
    ("0x00040978", "cm848_increaseCruiseSpeedCommand",
     "Adds the step to cruise_speed_command, at most up to cruise_maximum_road_speed_cal (ACCELERATE: cruise_accelerate_ramp, "
     "BUMP UP: cruise_bump_up_step)"),
    ("0x00040938", "cm848_decreaseCruiseSpeedCommand",
     "Takes the step from cruise_speed_command, not below cruise_minimum_coast_speed (COAST: cruise_coast_ramp, BUMP DOWN: "
     "cruise_bump_down_step)"),
    ("0x0004091c", "cm848_minimumSignedWord",
     "Returns the lower of its two arguments (a signed compare), as a word"),
    ("0x00040d40", "cm848_saveCruiseSetSpeedForPowerDown",
     "On the power-down path (before cm848_runPowerDownSequence): cruise_saved_set_speed_cal = cruise_speed_command, or 0 "
     "while j1939_governor_feature_cal bit 0x8000 is clear"),
    ("0x00040d74", "cm848_restoreSavedCruiseSetSpeed",
     "Power-up (cm848_applicationMain): when cruise_saved_set_speed_cal is between cruise_minimum_set_speed and "
     "cruise_maximum_road_speed_cal it becomes cruise_speed_command and cruise_resume_speed (valid flag set)"),
    ("0x00040f80", "cm848_calculateRoadSpeedGovernorFueling",
     "Sets road_speed_governor_fueling (FUELING_STATE_ROAD_SPEED_GOVERNOR when it wins the arbitration) from the error "
     "between vehicle_speed_rise_limited and road_speed_governor_reference_speed through the RSG droop gains / offsets "
     "(0x1700 = no limit while j1939_governor_feature_cal bit 0x80 is clear, fault 29 (P0500 vehicle speed sensor) is "
     "set or TSC1 controls the engine); capped at adjusted_user_fueling + 58 while it governs"),
    ("0x005251e4", "cm848_presetCruiseAndRoadSpeedGovernor",
     "The bumpless start of the cruise / road speed governor (also from cm848_arbitrateGovernedFueling): selects the "
     "gain set, sets the reference speed (road_speed_governor_reference_speed in state 10, else cruise_speed_command, or "
     "the road speed on RESUME / an external reset, plus the droop error delta), the clamped speed errors, the filter "
     "states, the fueling maximum pointer and the integrator / sump from the present fueling"),
    ("0x00525504", "cm848_runCruiseAndRoadSpeedGovernor",
     "The cruise control / road speed governor PID, every pass from cm848_periodicTaskSet_outputs: the droop and preset "
     "fueling filters, the preset fueling window, the rate-limited reference, the speed error and its engine speed "
     "form, the proportional / integral (Q16) / derivative terms, the sump, and cruise_governor_fueling into "
     "adjusted_user_fueling; presets the governor on an external reset or an ACCELERATE / COAST release"),
    ("0x0052470c", "cm848_selectCruiseGovernorGainSet",
     "Looks up cruise_governor_gear_ratio_gain, sets cruise_droops_allowed_flag and cruise_droop_speed_error_delta, picks "
     "gain set 1 / 2 / 3 from the speed error after droop and the filtered fueling (with hysteresis) and loads its gains "
     "into cruise_pid_*_gain; a set change raises cruise_governor_bumpless_transfer_flag"),
    ("0x00524aec", "cm848_updateCruiseAndRoadSpeedGovernorDroops",
     "Passes the droop gains / offsets to the cruise and road speed governor fueling: the top droop gains for the "
     "selected rear axle ratio (two-speed axle), the cruise ones only while droops are allowed and cruise is engaged, "
     "and the top droop offset for the electronic smart power tau state (or from the peak fueling with programmable "
     "power)"),
    ("0x00524c6c", "cm848_calculateEngineSpeedAtVehicleSpeed",
     "The engine speed (1/8 rpm, clamped to 8000..36000 = 1000..4500 rpm) at vehicle speed argument 1 with rear axle "
     "ratio argument 2 in top gear (tire_revolutions_per_mile_cal x top_gear_ratio_cal / 60)"),
    ("0x00524d34", "cm848_calculateTopDroopGain",
     "A top droop gain: the droop width << 10 / (the 4D transient fueling at 100 % throttle and the given engine speed "
     "- cruise_top_droop_offset_tau_0), capped at 0x22c8; 0 when that fueling is not above the offset"),
    ("0x00524dd0", "cm848_calculateBottomDroopGain",
     "A bottom droop gain: the droop width << 10 / the fueling span, or 0x22c8 when width << 10 is not below the span x "
     "0x22c8"),
    ("0x00524df4", "cm848_initializeCruiseAndRoadSpeedGovernorDroops",
     "Power-up (cm848_applicationMain): the cruise and road speed governor top droop gains for both rear axle ratios "
     "(4D fueling at cruise_droop_reference_speed - the droop width), the bottom droop gains, the droop gains / offsets "
     "passed to the fueling, gain set 1 and the droop / bumpless flags"),
    ("0x005250c0", "cm848_calculateCruiseGovernorSpeedErrorGain",
     "Calculates cruise_governor_speed_error_gain = ((tire_revolutions_per_mile_cal x rear_axle_ratio / 60) x 100 >> 7) "
     "x cruise_governor_speed_error_gain_multiplier >> 10, capped at cruise_governor_speed_error_gain_tool_upper_limit"),
    ("0x00525134", "cm848_calculateCruiseGovernorEngineSpeedError",
     "The speed error after droop in engine speed units: x cruise_governor_gear_ratio_gain / 1000 (at least +-1 while "
     "the error is not 0), x cruise_governor_speed_error_gain >> 7, clamped to +-10000"),
    ("0x00525de4", "cm848_initializeCruiseGovernorFilters",
     "Clears cruise_governor_external_reset_flag and points the driveline / derivative second order filters and the "
     "droop / preset fueling EMA filters at their e2m 1186 / 1189 coefficients"),
    ("0x0003e42c", "cm848_calculateMaximumRoadSpeeds",
     "While fault_reaction_request_bits is nonzero, ramps fault_vehicle_speed_limit down from the vehicle speed at the "
     "first pass by fault_vehicle_speed_limit_ramp_step to fault_vehicle_speed_limit_floor (else it is "
     "maximum_road_speed_trim_cal); road_speed_governor_reference_speed = the lower of that and "
     "maximum_road_speed_trim_cal; cruise_maximum_road_speed_cal = cruise_maximum_road_speed_trim_cal, or the lower "
     "road_speed_governor_reference_speed while cruise_maximum_road_speed_clamp_enable is set"),
    ("0x0003e520", "cm848_initializeMaximumRoadSpeeds",
     "Power-up: road_speed_governor_reference_speed, maximum_road_speed and the 0x40b5c0 copy = "
     "maximum_road_speed_trim_cal, cruise_maximum_road_speed_cal = cruise_maximum_road_speed_trim_cal, "
     "drivetrain_gear_range = top gear, the previous fault reaction request = 0"),
    ("0x00056608", "cm848_secondOrderFilterUnsigned",
     "A second order filter on an unsigned input with 32-bit products: output = (c1 x input << 16 - c3 x output_previous "
     "+ (c3 - c1 + 0x10000) x output) >> 16 into its record (coefficient pointers +0 / +4, outputs +8 / +C). Its return "
     "value is (output >> 16) & 0xffff after output was already shifted down 16 (asm 0x56640 / 0x5664c), so it returns "
     "0 in this build (cruise_governor_filtered_road_speed)"),
]
