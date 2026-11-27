"""Round 5 stage b: the two other ASG mode selectors (the family of cm848_selectAllSpeedGovernorApplicationMode)."""
GLOBALS = []
FUNCTIONS = [
    ("0x00010110", "cm848_selectVariableSpeedGovernorMode",
     "If no fueling state is selected and the variable speed governor is (variable_speed_governor_selected_flag): "
     "blends the governor tuning sets, selects FUELING_STATE_VARIABLE_SPEED_GOVERNOR (7), computes the ASG throttle "
     "reference and the compensator coefficients, and when it comes from another state loads "
     "all_speed_governor_throttle_mode_gain_set (e2m 107B) and its limits into the working governor selection"),
    ("0x00503074", "cm848_selectTsc1SpeedControlMode",
     "If no fueling state is selected and TSC1 requests speed control (j1939_tsc1_override_state.governor_mode 1): "
     "selects FUELING_STATE_TSC1_SPEED_CONTROL with the TSC1 capped speed target and loads the gain set of the "
     "requested speed control condition (j1939_tsc1_speed_control_condition_gain_sets) and the J1939 limits and "
     "reference filter"),
]
