"""Stage 10b-2: the HSG compensator (bins 1 and 6), the all speed governor leftovers (bins 1 and 6), the net torque
fuel limit (bin 1) and the engine speed filter (bin 1). Read in the main session:
cm848_calculateHighSpeedGovernorCompensatedEngineSpeed, cm848_calculateNetTorqueFuelLimit, the 107D / 8C68-8C6C
blocks, cm848_initFuelDemandVariables, cm848_calculateFuelTimingTarget, cm848_calculateFuelDemandWithConditions."""
H = "cm848_calculateHighSpeedGovernorCompensatedEngineSpeed"
N = "cm848_calculateNetTorqueFuelLimit"
GLOBALS = [
    # the HSG lead / lag compensator (e2m 13AB / 13B4): output = (previous output x c3 + speed x c1 - previous speed
    # x c2) >> 15; the working coefficients are the calibrated set (compensation active) or 1.0 / the transition one
    ("0x003fb55c", "high_speed_governor_compensator_working_filter_coefficient_1",
     f"{H}: the multiplier of the filtered engine speed - high_speed_governor_compensator_filter_coefficient_1 while "
     "compensating, else 0x8000 (1.0)"),
    ("0x003fb55e", "high_speed_governor_compensator_working_filter_coefficient_2",
     f"{H}: the multiplier of the previous engine speed - high_speed_governor_compensator_filter_coefficient_2 while "
     "compensating, else the transition coefficient"),
    ("0x003fb560", "high_speed_governor_compensator_working_filter_coefficient_3",
     f"{H}: the multiplier of the previous output - coefficient 2 - coefficient 1 + 0x8000 while compensating, else "
     "the transition coefficient; copied to high_speed_governor_compensator_filter_coefficient_3 (e2m 13AB +4)"),
    ("0x003fb55a", "high_speed_governor_compensator_engine_speed_previous",
     f"{H}: engine_speed_state.filtered_engine_speed of the previous pass"),
    ("0x0040b704", "high_speed_governor_compensator_output_previous",
     f"{H}: the compensated engine speed of the previous pass (capped at 0x8ca0)"),
    # the all speed governor (e2m 107D, ROM-copied constants)
    ("0x003ff686", "all_speed_governor_derivative_deadband_limit", "the ASG derivative term's dead band"),
    ("0x003ff688", "all_speed_governor_derivative_filter_coefficient", "filter coefficient of the ASG derivative term"),
    ("0x003ff68a", "all_speed_governor_derivative_limit", "limit of the ASG derivative term"),
    ("0x003ff68c", "all_speed_governor_throttle_reference_rate_limit", "rate limit of the ASG throttle reference speed"),
    ("0x003ff6b0", "rpm_deceleration_limit_target_rate",
     "the ASG fueling is controlled to keep the engine deceleration within it (the low zone; "
     "rpm_deceleration_limit_target_rate_high_zone above rpm_deceleration_limit_high_zone_engine_speed)"),
    ("0x003ff6b2", "rpm_deceleration_limit_integral_gain", "integral gain of the rpm deceleration limit control"),
    ("0x003ff6b6", "rpm_deceleration_limit_proportional_gain",
     "proportional gain of the rpm deceleration limit control"),
    ("0x003ff6bc", "rpm_deceleration_limit_high_zone_engine_speed",
     "the engine speed that selects the high zone deceleration target"),
    ("0x003ff6c6", "all_speed_governor_delta_droop", "droop of the ASG delta from all_speed_governor_delta_upper_limit"),
    ("0x003fa0e4", "all_speed_governor_pid_accumulator",
     "cm848_runOperatingModeSpeedGovernor: the ASG PID accumulator, clamped to +-0xe6000"),
    ("0x0040a1fc", "all_speed_governor_gain_set_pointer",
     "points to the selected 9-word ASG gain set (proportional 1 / 2, integral 1 / 2, derivative 1 / 2, compensation "
     "filter coefficients 1-3; cm848_runOperatingModeSpeedGovernor reads +0..+0x10); "
     "cm848_selectAllSpeedGovernorApplicationMode points it at all_speed_governor_application_proportional_gain_1"),
    # the net torque fuel limit (e2m 8C68 / 8C6A / 8C6B / 8C6C)
    ("0x00408996", "net_torque_fuel_limit_override_value",
     f"{N}: the limit while net_torque_fuel_limit_override_enable is set"),
    ("0x00408998", "net_torque_fuel_limit_negative_slew_rate", f"{N}: the most the limit may fall per pass"),
    ("0x0040899a", "net_torque_fuel_limit_positive_slew_rate", f"{N}: the most the limit may rise per pass"),
    ("0x0040899c", "net_torque_fuel_limit_engine_speed_axis",
     f"{N}: engine speed axis (15) of the net torque fueling limit table"),
    ("0x004089ba", "net_torque_fuel_limit_alpha_axis", f"{N}: second axis (6) of the table"),
    ("0x004089c6", "net_torque_fuel_limit_grid", f"{N}: the 15 x 6 limit table (MM3S)"),
    ("0x003fb41c", "net_torque_fuel_limit_lookup_state", f"{N}: the dual-axis lookup state of the table"),
    ("0x003fb420", "net_torque_fuel_limit_previous", f"{N}: the limit of the previous pass, for the slew limits"),
    ("0x003fb422", "net_torque_fuel_limit_base_map_output", f"{N}: the table at second axis 0"),
    ("0x003fb424", "net_torque_fuel_limit_chi_lower_map_output",
     f"{N}: the table at the lower chi map number (x 0x4000)"),
    ("0x003fb426", "net_torque_fuel_limit_chi_upper_map_output",
     f"{N}: the table at the upper chi map number (x 0x4000); the three blend through cm848_interpolateAlphaChiValue"),
    # the engine speed filter
    ("0x003fb5c6", "engine_speed_filter_state",
     "the EMA filter record of the engine speed (coefficient engine_speed_filter_coefficient, e2m 8194 +1C): "
     "average_engine_speed in, engine_speed_state.filtered_engine_speed out"),
]
FUNCTIONS = [
    ("0x0000fabc", "cm848_initializeAllSpeedGovernorVariables",
     "Zeroes the ASG proportional / integral / derivative adjustments and the rpm deceleration limit integral "
     "term, loads the variable speed governor default selection and seeds the fuel ramp state (0x1700)"),
    ("0x0000fe5c", "cm848_calculateAllSpeedGovernorThrottleReference",
     "The ASG throttle reference speed: interpolates between the governor's low and high speeds by the throttle "
     "(fuel_demand_control_t_0040a57a.calculated - 0..400 = 0..100 %) into speed_request_base / "
     "speed_request_unfiltered and copies the filtered engine speed as the governor feedback"),
    ("0x00045ecc", "cm848_calculateAllSpeedGovernorEquivalentThrottle",
     "Writes all_speed_governor_equivalent_throttle (e2m 81AA +0) from the throttle with the cruise control and "
     "power take-off equivalent throttle adjustments"),
]
