"""Round 26 stage A (label-only): the cruise vacuum throttle actuator (cm848_controlCruiseVacuumServo), named from the
Chrysler e2m blocks 8C2E (17 calibrations, 0x408daa-0x408dc9) and 8C2F (10 working words, 0x40b64e-0x40b665). Neither
block is in the parameter ID table: they are aligned by relative offset, and every word's code use matches its record
(the clamps clamp, the override enables pick the override values, the integrator resets to Int_Reset, the threshold /
time pair sets the disabled latch...). The peer session's read-only cruise review of 69d6f68 proposed the family; each
name here was checked in the code. 0x408xxx is ROM / flash, so the wrong _cal suffixes go."""
S = "cm848_controlCruiseVacuumServo"
E1, E2 = "e2m 8C2E", "e2m 8C2F"
GLOBALS = [
    ("0x00408daa", "vacuum_throttle_derivative_gain", f"{E1} +0 Vac_Throttle_Deriv_Gain: the servo PID's D gain ({S})"),
    ("0x00408dac", "vacuum_throttle_duty_cycle_maximum",
     f"{E1} +2 Vac_Throttle_Duty_Cycle_Max: upper clamp of vacuum_throttle_duty_cycle"),
    ("0x00408dae", "vacuum_throttle_duty_cycle_minimum",
     f"{E1} +4 Vac_Throttle_Duty_Cycle_Min: lower clamp of vacuum_throttle_duty_cycle"),
    ("0x00408db0", "vacuum_throttle_duty_cycle_override_value",
     f"{E1} +6 Vac_Throttle_Duty_Cycle_Override_Value: the duty cycle while vacuum_throttle_duty_cycle_override_enable "
     "is set (the PID is skipped)"),
    ("0x00408db2", "vacuum_throttle_error_deadband",
     f"{E1} +8 Vac_Throttle_Error_Deadband 'If ABS(throt pos error) < this, pneumatically lock actuator pos': below it "
     "the error, the integral term and the previous error are zeroed"),
    ("0x00408db4", "vacuum_throttle_integral_gain", f"{E1} +A Vac_Throttle_Int_Gain: the servo PID's I gain"),
    ("0x00408db6", "vacuum_throttle_integral_reset_value",
     f"{E1} +C Vac_Throttle_Int_Reset: vacuum_throttle_integral_term while cruise is not engaged"),
    ("0x00408db8", "vacuum_throttle_integral_maximum",
     f"{E1} +E Vac_Throttle_Max_Int_Clamp: upper clamp of the integral term (no fuel timing limit)"),
    ("0x00408dba", "vacuum_throttle_integral_minimum",
     f"{E1} +10 Vac_Throttle_Min_Int_Clamp: lower clamp of the integral term"),
    ("0x00408dbc", "vacuum_throttle_pwm_period",
     f"{E1} +12 Vac_Throttle_PWM_Period 'Number of 10 msec periods for 100% on-time of vac and vent sol': the software "
     "PWM period of vacuum_throttle_pwm_counter"),
    ("0x00408dbe", "vacuum_throttle_position_override_value",
     f"{E1} +14 Vac_Throttle_Pos_Override_Value: the target position while vacuum_throttle_position_override_enable is "
     "set"),
    ("0x00408dc0", "vacuum_throttle_proportional_gain", f"{E1} +16 Vac_Throttle_Prop_Gain: the servo PID's P gain"),
    ("0x00408dc2", "vacuum_throttle_position_override_enable",
     f"{E1} +18 Vac_Throttle_Pos_Override_Enable: runs the servo on vacuum_throttle_position_override_value in or out "
     "of cruise"),
    ("0x00408dc3", "vacuum_throttle_duty_cycle_override_enable",
     f"{E1} +19 Vac_Throttle_Duty_Cycle_Override_Enable: the duty cycle is vacuum_throttle_duty_cycle_override_value"),
    ("0x00408dc4", "vacuum_throttle_cruise_actuator_disable_mode",
     f"{E1} +1A Vac_Throttle_CC_Actuator_Disable_Mode 'If equal to 1, inoperative actuator will disable cruise': with "
     "vacuum_throttle_actuator_disabled_flag set, cm848_updateCruiseControlDeniedStatus gives denied status 4"),
    ("0x00408dc6", "vacuum_throttle_disabled_error_threshold",
     f"{E1} +1C Vac_Throttle_Disabled_Error_Threshold: a position error above it (brake off) counts "
     "vacuum_throttle_disabled_counter"),
    ("0x00408dc8", "vacuum_throttle_maximum_error_time",
     f"{E1} +1E Vac_Throttle_Max_Error_Time (MSEC): vacuum_throttle_disabled_counter reaching it sets "
     "vacuum_throttle_actuator_disabled_flag"),
    ("0x0040b64e", "vacuum_throttle_derivative_term", f"{E2} +0 Vac_Throttle_Deriv_Term: D gain x the error change / 4"),
    ("0x0040b652", "vacuum_throttle_duty_cycle",
     f"{E2} +4 Vac_Throttle_Duty_Cycle 'Output of cruise throttle position controller': P + I + D clamped, or the "
     "override value; positive = vacuum, negative = vent (-100 % = 0xffff9c00 drops the supply output 21)"),
    ("0x0040b656", "vacuum_throttle_integral_term", f"{E2} +8 Vac_Throttle_Integral_Term"),
    ("0x0040b658", "vacuum_throttle_position_error",
     f"{E2} +A Vac_Throttle_Position_Error: vacuum_throttle_target_position - commanded_throttle_state."
     "commanded_throttle"),
    ("0x0040b65a", "vacuum_throttle_target_position",
     f"{E2} +C Vac_Throttle_Target_Position 'Equal to equivalent throttle in cruise mode, unless overidden': "
     "all_speed_governor_equivalent_throttle while cruise is engaged, the override value with the override enable, "
     "else 0"),
    ("0x0040b65c", "vacuum_throttle_vacuum_pwm",
     f"{E2} +E Vac_Throttle_Vac_PWM: the vacuum valve on-time (logical output 20)"),
    ("0x0040b65e", "vacuum_throttle_vent_pwm", f"{E2} +10 Vac_Throttle_Vent_PWM: the vent valve on-time (logical output 19)"),
    ("0x0040b660", "vacuum_throttle_actuator_disabled_flag",
     f"{E2} +12 Vac_Throttle_Actuator_Disabled 'TRUE indicates throttle cannot be positioned with vac actuator': set "
     "on an accelerator pedal fault or after vacuum_throttle_maximum_error_time of large errors; only "
     "cm848_initCruiseServoControl clears it; read by the cruise denied status and standby logic"),
    ("0x0040b662", "vacuum_throttle_disabled_counter",
     f"{E2} +14 Vac_Throttle_Disabled_Counter: consecutive passes with the error above "
     "vacuum_throttle_disabled_error_threshold and the brake off"),
    ("0x0040b664", "vacuum_throttle_proportional_term", f"{E2} +16 Vac_Throttle_Prop_Term: P gain x the error / 4"),
    ("0x003fb51a", "vacuum_throttle_pwm_counter",
     f"The software PWM phase of {S}: 1 .. vacuum_throttle_pwm_period; each valve is on while its PWM share is above it"),
    ("0x003fb51c", "vacuum_throttle_previous_position_error",
     f"The position error of the previous pass, for the D term of {S}"),
    ("0x003fb530", "cruise_control_engaged_previous_flag",
     "cruise_control_engaged_flag at the end of the previous cm848_calculateCruiseControlFueling pass (its only "
     "writer)"),
]
FUNCTIONS = [
    ("0x00512e70", "cm848_checkCruiseSwitchLearnCondition",
     "Returns 1 for a fresh cruise ON / OFF press (cruise_switch_request CRUISE_SWITCH_ON_OFF after IDLE) while the "
     "cruise switch ADC (channel 47, or its forced reading) is inside cruise_switch_sensor_config's window; "
     "cm848_cruiseControlPeriodicUpdate then sets cruise_control_switches_learned_flag. No engage decision"),
]
