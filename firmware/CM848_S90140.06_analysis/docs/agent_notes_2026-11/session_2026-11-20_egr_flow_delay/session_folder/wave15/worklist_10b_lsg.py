"""Stage 10b-1: the low speed governor family the wave split (bins 2, 4 and 5 agree on the P / I / D / jerk roles).
Read in the main session: cm848_runLowSpeedGovernor, cm848_updateGovernorSetpointParameters,
cm848_processGovernorLoadCondition, cm848_processGovernorSpeedSetpoint, cm848_selectGovernorSetpointSource,
cm848_getGovernorOverrideSource, cm848_resetGovernorLoadState, cm848_enableProtectionRateLimit,
cm848_initSpeedProtectionParameters. The four-word gain sets themselves (and their member rows) are typed in 10c."""
L = "cm848_runLowSpeedGovernor"
A = "cm848_updateLowSpeedGovernorAggressiveGainLogic"
G = "cm848_selectLowSpeedGovernorGearGainSet"
GLOBALS = [
    # e2m 10ED: the working gains, loaded from the selected 4-word set by cm848_loadLowSpeedGovernorGainSet
    ("0x0040ae76", "low_speed_governor_proportional_gain",
     f"word +0 of the selected gain set; {L} multiplies it by low_speed_governor_proportional_gain_adjustment and "
     "the speed error for the proportional term"),
    ("0x0040ae78", "low_speed_governor_integral_gain",
     f"word +2 of the selected gain set; {L} uses it in the low_speed_governor_integral_accumulator update"),
    ("0x0040ae7a", "low_speed_governor_derivative_gain",
     f"word +4 of the selected gain set; {L} uses it with low_speed_governor_derivative_gain_adjustment for the "
     "derivative term"),
    ("0x0040ae8a", "low_speed_governor_jerk_gain", "word +6 of the selected gain set, the jerk term's gain"),
    ("0x0040ae80", "low_speed_governor_override_gain_state",
     "cm848_selectLowSpeedGovernorOverrideGainSet: when it is non-zero (and no TSC1 set is active) it becomes "
     "low_speed_governor_final_gain_state and the override gain set at 0x40ae82 is loaded; nothing in the "
     "application writes it"),
    ("0x0040ae74", "low_speed_governor_aggressive_gain_inhibit_flag",
     f"0 = allow the aggressive gains, 1 = inhibit (the e2m values ALLOW_AGGRESSIVE_LOGIC = 0 / INHIBIT); {A} clears "
     "it once the idle speed error has settled with the vehicle below the low mph, the coolant above the minimum "
     "and the engine run long enough, and sets it again above the high mph; "
     "cm848_resetLowSpeedGovernorAggressiveGainLogic and cm848_inhibitLowSpeedGovernorAggressiveGains set it; "
     f"{G} runs the gear gain sets only while it is 1"),
    ("0x0040ae8c", "low_speed_governor_requested_gain_set_pointer",
     f"the gain set the user gain state asks for: {A} points it at low_speed_governor_aggressive_gain_set (state 1), "
     f"{G} at the middle / high gear sets (states 2 / 3); cm848_loadLowSpeedGovernorGainSet takes it when no "
     "override or TSC1 set is active"),
    ("0x0040ae90", "low_speed_governor_gain_set_pointer",
     "the gain set cm848_loadLowSpeedGovernorGainSet loads the four working gains from: the TSC1 set (state 4), "
     "the override set, the requested set or low_speed_governor_default_gain_set (state 0)"),
    # e2m 1065: the PID terms, clamps and adjustments
    ("0x0040ae96", "low_speed_governor_proportional_term",
     f"{L}: proportional gain x adjustment x speed error, filtered by low_speed_governor_proportional_filter_coefficient "
     "and clamped to +-0x2280"),
    ("0x0040ae98", "low_speed_governor_derivative_term",
     f"{L}: the derivative fueling contribution, filtered by low_speed_governor_derivative_filter_coefficient and "
     "limited by low_speed_governor_derivative_term_maximum"),
    ("0x0040ae9c", "low_speed_governor_jerk_term",
     f"{L}: the jerk fueling contribution, limited to +-low_speed_governor_jerk_term_limit"),
    ("0x0040ae9e", "low_speed_governor_fueling_clamp_maximum",
     f"{L}: low_speed_governor_fueling_clamp_maximum_offset plus the 4D fueling (floored at 0), the ceiling of the "
     "LSG fueling; cm848_initializeLowSpeedGovernorParameters seeds 0x1700"),
    ("0x0040aea0", "low_speed_governor_integrator_clamp_maximum",
     f"{L}: the integral accumulator is clamped to it"),
    ("0x0040aea2", "low_speed_governor_integrator_preset_maximum",
     "the ceiling of the integrator preset (cm848_presetLowSpeedGovernorIntegrator), the twin of "
     "low_speed_governor_integrator_preset_minimum"),
    ("0x0040aea8", "low_speed_governor_proportional_gain_adjustment",
     f"0x80 = 1.0; {L} multiplies the proportional gain by it; cm848_initializeLowSpeedGovernorParameters seeds 0x80"),
    ("0x0040aeaa", "low_speed_governor_reset_delay_timer",
     f"{L} counts it up to low_speed_governor_reset_delay_time and resets the governor when it gets there"),
    ("0x0040aeac", "low_speed_governor_gain_adjustment_inhibit_flag",
     f"{G} sets it to 1 while a gear gain set is in use (user gain state 2 / 3), else 0"),
    # e2m 1064: calibration constants (ROM-copied RAM, no _cal)
    ("0x004070b6", "low_speed_governor_fueling_clamp_maximum_offset",
     f"added to the 4D fueling for low_speed_governor_fueling_clamp_maximum ({L})"),
    ("0x004070ba", "low_speed_governor_integrator_preset_maximum_offset",
     "added to the 4D fueling for low_speed_governor_integrator_preset_maximum"),
    ("0x004070be", "low_speed_governor_integrator_clamp_maximum_offset",
     "added to the 4D fueling for low_speed_governor_integrator_clamp_maximum"),
    ("0x004070c0", "low_speed_governor_integrator_clamp_minimum", "the floor of the integral accumulator"),
    ("0x004070c4", "low_speed_governor_reset_speed_offset",
     "offset over the LSG reference speed above which the governor resets"),
    ("0x004070c6", "low_speed_governor_reset_fueling", "engine fueling below which the governor resets"),
    ("0x004070c8", "low_speed_governor_derivative_filter_coefficient",
     f"{L} multiplies the derivative term by it (first-order filter)"),
    ("0x004070ca", "low_speed_governor_jerk_deadband", "deadband of the jerk fueling"),
    ("0x004070cc", "low_speed_governor_jerk_filter_coefficient", "filter coefficient of the jerk term"),
    ("0x004070d0", "low_speed_governor_proportional_filter_coefficient",
     f"{L} multiplies the proportional term by it (first-order filter)"),
    ("0x004070d2", "low_speed_governor_reset_delay_time",
     f"{L} resets the governor once low_speed_governor_reset_delay_timer reaches it"),
    ("0x004070d6", "low_speed_governor_no_load_fuel_enable", "enables the no load fuel in the LSG fueling"),
    ("0x004070dc", "low_speed_governor_integrator_preset_acceleration_limit",
     "the integrator preset is used only below this unfiltered engine acceleration"),
    ("0x004070de", "low_speed_governor_integrator_preset_vehicle_speed_limit",
     "the integrator preset is used only below this road speed"),
    # e2m 10EE: the aggressive gain logic
    ("0x00407098", "low_speed_governor_gain_logic_transition_time",
     f"{A}: the settled counts (idle speed error inside the maximum, and that while stopped) count up to it"),
    ("0x0040709a", "low_speed_governor_engine_speed_delta_threshold",
     f"{A}: the aggressive gains switch on when the speed error passes offset 1 while the unfiltered engine "
     "acceleration plus this is negative, and off again when the acceleration rises above it"),
    ("0x0040709c", "low_speed_governor_maximum_idle_speed_error",
     f"{A}: a larger absolute speed error restarts both settled counts"),
    ("0x0040709e", "low_speed_governor_aggressive_gain_high_vehicle_speed",
     f"{A}: above this vehicle speed the aggressive gains are inhibited"),
    ("0x004070a0", "low_speed_governor_aggressive_gain_low_vehicle_speed",
     f"{A}: the stopped settled count runs only below this vehicle speed"),
    ("0x004070a2", "low_speed_governor_aggressive_gain_speed_offset_1",
     f"{A}: speed error offset 1 of the aggressive gain switch-on (with the acceleration condition)"),
    ("0x004070a4", "low_speed_governor_aggressive_gain_speed_offset_2",
     f"{A}: speed error offset 2, above which the aggressive gains switch on"),
    ("0x004070a6", "low_speed_governor_aggressive_gain_speed_offset_3",
     f"{A}: speed error offset 3 of the inhibit test (with switch input bit 0x80 of byte 1)"),
    ("0x004070a8", "low_speed_governor_aggressive_gain_speed_hysteresis",
     f"{A}: hysteresis under offset 1 when the aggressive gains switch off"),
    ("0x004070b4", "low_speed_governor_aggressive_gain_minimum_coolant_temperature",
     f"{A}: the aggressive gains are allowed only with the coolant temperature above it"),
    # e2m 10EA: the gear gain logic
    ("0x00408ec6", "low_speed_governor_gear_breakpoint_1",
     f"{G}: drivetrain_ratio x rear_axle_ratio above it keeps the default gains (mid gear / default breakpoint)"),
    ("0x00408ec8", "low_speed_governor_gear_breakpoint_2",
     f"{G}: the middle gear / high gear breakpoint"),
    ("0x00408eca", "low_speed_governor_gear_gain_speed_error_maximum",
     f"{G}: the gear gains are not used with low_speed_governor_filtered_speed_error above it"),
    ("0x00408ecc", "low_speed_governor_gear_gain_speed_error_minimum",
     f"{G}: the gear gains are not used with low_speed_governor_filtered_speed_error below it"),
    ("0x00408ece", "low_speed_governor_gear_gain_transition_time",
     f"{G}: the gear gain conditions must hold this long (low_speed_governor_gear_gain_transition_timer)"),
    ("0x00408ed0", "low_speed_governor_gear_hysteresis", f"{G}: hysteresis on both breakpoints"),
    # working words without an e2m record
    ("0x003faf48", "low_speed_governor_integral_accumulator",
     f"Q16.16 accumulator of the integral term ({L}); its upper half is low_speed_governor_integral_term"),
    ("0x003faf4e", "low_speed_governor_proportional_gain_previous",
     f"{L}: the proportional gain of the previous pass; the gain change times the speed error keeps the output "
     "bumpless"),
    ("0x003faf5e", "low_speed_governor_aggressive_gain_run_timer",
     f"{A}: counts running passes up to low_speed_governor_aggressive_gain_minimum_run_time, 0 when stopped"),
    ("0x003faf60", "low_speed_governor_aggressive_gains_active_flag",
     f"{A}: 1 = the aggressive gains are in use (user gain state 1, low_speed_governor_aggressive_gain_set)"),
    ("0x003faf62", "low_speed_governor_idle_error_settled_count",
     f"{A}: passes with the absolute speed error inside low_speed_governor_maximum_idle_speed_error, up to the "
     "transition time"),
    ("0x003faf64", "low_speed_governor_stopped_vehicle_settled_count",
     f"{A}: like the settled count, but only below the low mph; reaching the transition time allows the "
     "aggressive gains"),
    ("0x003fb562", "low_speed_governor_gear_gain_transition_timer",
     f"{G}: counts up to low_speed_governor_gear_gain_transition_time while the gear gain conditions hold"),
    ("0x0040aede", "low_speed_governor_filtered_speed_error",
     "the LSG filtered speed error (LSFTER in the e2m text of 10EA +4 / +6): the aggressive and gear gain logic "
     "compare it with their offsets and window"),
]
FUNCTIONS = [
    ("0x00028670", "cm848_updateLowSpeedGovernorAggressiveGainLogic",
     "The LSG aggressive gain logic (e2m 10EE / 10EF): in the LSG fueling state it runs the minimum run time, the "
     "settled counts and the coolant / vehicle speed conditions that clear or set "
     "low_speed_governor_aggressive_gain_inhibit_flag, switches the aggressive gains on and off by the speed error "
     "offsets and requests low_speed_governor_aggressive_gain_set (user gain state 1)"),
    ("0x000289ac", "cm848_resetLowSpeedGovernorAggressiveGainLogic",
     "Resets the aggressive gain logic: gains off, inhibit flag set, run timer 0"),
    ("0x0004271c", "cm848_inhibitLowSpeedGovernorAggressiveGains",
     "Sets low_speed_governor_aggressive_gain_inhibit_flag"),
    ("0x000289d0", "cm848_selectLowSpeedGovernorOverrideGainSet",
     "If no TSC1 gain set is active and low_speed_governor_override_gain_state is set: final gain state = it and the "
     "override gain set at 0x40ae82 is selected; returns 1 when a set is selected"),
    ("0x00028b38", "cm848_selectLowSpeedGovernorTsc1GainSet",
     "With a TSC1 governor mode request (j1939_tsc1_override_state.governor_mode) and governor_feature_flags bit "
     "0x8000: final gain state 4 and the TSC1 gain set; returns 1 when selected"),
    ("0x00028a14", "cm848_loadLowSpeedGovernorGainSet",
     "Picks the gain set (TSC1 - override - the requested set - the default set for user state 0) and loads its four "
     "words into the working proportional / integral / derivative / jerk gains (e2m 10ED +0 / +2 / +4 / +14)"),
    ("0x00027e4c", "cm848_presetLowSpeedGovernorIntegrator",
     "Presets the LSG integrator accumulator (between the preset minimum - in drive or not - and maximum - or the "
     "previous value) and clears the proportional / derivative / jerk terms"),
    ("0x00028618", "cm848_initializeLowSpeedGovernorParameters",
     "Initializes the LSG: the aggressive gain logic, the three gain adjustments = 0x80 (1.0), the fueling clamp "
     "maximum = 0x1700 and the alternator load filter"),
    ("0x0004256c", "cm848_selectLowSpeedGovernorGearGainSet",
     "The LSG gear gain logic (e2m 10EA): while the aggressive gains are inhibited and the filtered speed error is "
     "inside the gear window, after the transition time it requests the middle or high gear gain set by "
     "drivetrain_ratio x rear_axle_ratio against the two breakpoints (with hysteresis), and sets the gain "
     "adjustment inhibit flag while a gear set is in use"),
]
