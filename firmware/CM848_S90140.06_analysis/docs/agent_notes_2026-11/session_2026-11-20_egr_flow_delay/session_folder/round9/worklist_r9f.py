"""Round 9 stage F (label-only, the review fixes): e2m 8BB6 (the governor pressure controller's RAM, aligned at 0x40b58c by
its records' descriptions and the code: +00 RE_Deriv_Term ... +16 RE_VFS_PWM_On_Time) confirms stage A's controller names
and renames two; RE_Normal_Curve's tables match the enum's NORMAL_CURVE; the overdrive switch power-on delay counter."""

GLOBALS = [
    ("0x0040b58c", "governor_pressure_derivative_term",
     "e2m 8BB6 +00 RE_Deriv_Term ('RE governor pressure control derivative term'): "
     "cm848_calculateGovernorPressureDerivativeTerm writes it (error slope x RE_K_D_Num / RE_K_D_Den, clamped to "
     "+-0x6400). An older note put e2m 8C34 +12 TCC_Function_Timer here; 8BB6 and the code say otherwise"),
    ("0x0040b596", "governor_pressure_error_slope",
     "e2m 8BB6 +0A RE_PID_Error_Slope ('RE gov pres control error slope (prev_RE_Governor_Delta-RE_Governor_Delta)'): "
     "the derivative term's input (signed dword)"),
    ("0x00407c96", "governor_pressure_normal_curve_axis",
     "e2m 8BF0 RE_Normal_OSS_Axis (walk 0B75): output shaft speed"),
    ("0x00407cb2", "governor_pressure_normal_curve_values",
     "e2m 8BF1 RE_Normal_Curve ('Gov press vs OSS for normal operating conditions'): pressure state "
     "TRANSMISSION_PRESSURE_STATE_NORMAL_CURVE (cm848_selectGovernorPressureBaseCurve, cm848_selectGovernorPressureAntiHunt)"),
    ("0x003fb0ee", "governor_pressure_normal_curve_interp_state",
     "Lookup cache of governor_pressure_normal_curve (e2m RE_Normal_Curve); cm848_initializeTransmissionShiftLogic sets it to 2"),
    ("0x003fcd2a", "overdrive_switch_power_on_delay_counter",
     "Counts the passes after power-on up to overdrive_switch_power_on_delay_time (e2m 8BBB +08 RE_OD_Delay, "
     "'Poweron Delay Time used to test Transmission_Overdrive_Switch') before cm848_processOverdriveSwitchAndShift "
     "reads the overdrive off switch (switch 21)"),
]
FUNCTIONS = []
