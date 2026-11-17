exec(open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w7/gen_W7.py').read())

# ---------------- corrections after re-reading the code (later fn() calls replace earlier ones) ----------------
fn(0x19900, 'cm848_calculateExhaustGasRecirculationValveStagedPositionCommand',
   "Staged closing of the EGR valve position command: when the command is below exhaust_gas_recirculation_valve_closed_stage_command_threshold the staged command (governor_speed_ramp_state) is moved by the ramp rate per pass "
   "(0 while the position is at or above the stage position threshold) and never below 0; at or above the threshold it is reset to the threshold. The result is the larger of the staged command and the command, "
   "exhaust_gas_recirculation_valve_position_command_final (governor_speed_ramp_output). The loop reference (boost_pressure_target_input) is that value in control states 0 and 1 and the measured position in the other states.")
fn(0x19ac0, 'cm848_updateExhaustGasRecirculationValveIntegralEnable',
   "Anti-windup of the EGR valve loop: sets exhaust_gas_recirculation_valve_integral_enable_flag (governor_speed_range_active_flag) to 0 while the battery compensated duty is at its upper working limit with a positive error "
   "or at its lower working limit with a negative error (the error then pushes further into the limit), otherwise to 1.")
fn(0x19fe0, 'cm848_outputExhaustGasRecirculationValveDirectionAndDuty',
   "Output stage of the EGR valve loop: the sign of exhaust_gas_recirculation_valve_drive_duty_clamped sets (duty at or above 0) or clears logical output 68, the direction request, driving its line immediately - inverted when "
   "exhaust_gas_recirculation_valve_motor_direction_reversal is 1 - and |duty| x 2 (25600 minus it when the polarity reversal is set) is the PWM duty (25600 = 100 percent), forced to 0 for one pass after a direction change or below the zero threshold; "
   "the duty goes to the output channel record of entry 39 (exhaust_gas_recirculation_valve_motor_pwm_output_channel_cal), which is 0 (unassigned) in this calibration.")
fn(0x18cfc, 'cm848_updateExhaustGasRecirculationValveDriverOverCurrentFault',
   "Over-current check of the EGR valve motor driver: while the estimated motor current is at or above exhaust_gas_recirculation_valve_driver_over_current_threshold the set timer rises by the time increment up to the set time "
   "(it falls by the time decrement otherwise) and the over-current is flagged at the set time; a clear timer counts the passes without over-current, the retry counter of cm848_updateExhaustGasRecirculationValveDriverOverCurrentRetryCounter decides retry or give-up, "
   "and fault 727 (mask 0x80 of diagnostic_status_bits) is set while the over-current is flagged and the clear conditions are not met, and cleared when they are.")
fn(0x1af94, 'cm848_updateExhaustGasRecirculationValveAutozeroConditions',
   "Autozero conditions of the EGR valve: a hysteresis counter counts up to exhaust_gas_recirculation_valve_autozero_retry_time while the enable-timeout timer and fault 718 (mask 0x4000 of fault_detected_bits_704_to_719, position autozero error) are clear; "
   "exhaust_gas_recirculation_valve_ready_for_autozero_flag is set when |sensor_channel75_value| is below the autozero tolerance or the counter has reached its limit (cleared while the enable-timeout timer is set); the hold counter (cold_start_fuel_confirm_counter) is reset by the timer or fault 718 "
   "and otherwise counts up to exhaust_gas_recirculation_valve_autozero_active_time while ready; governor_speed_b_mode_select_flag (diagnostic drive, control state 3) is set while the hold counter is below that time, and the holding duty is copied to governor_mode3_speed_param.")
fn(0x1b120, 'cm848_updateExhaustGasRecirculationValveEnableAndDiagnosticConditions',
   "Enable and diagnostic conditions of the EGR valve loop: exhaust_gas_recirculation_valve_motor_ok_flag (diagnostic_clear_condition_flag) is set when no driver fault is pending and faults 726 / 727 / 728 are clear; "
   "the enable-timeout timer follows the electrical fault, the position sensor status (2 or more) and the control error 725; the position diagnostic override (governor_speed_target_mode_flag, command forced to 0) is set while over-current or over-temperature is present or the diagnostic drive runs; "
   "logical output request 67 (the PWM enable) is set unless the driver fault is pending or the position sensor / control error problem has lasted fewer than 200 passes, and the autozero enable flag follows it.")
fn(0x507214, 'cm848_evaluateExhaustGasRecirculationValvePositionControlDiagnosticConditions',
   "Enable flag of the EGR valve position control diagnostic (exhaust_gas_recirculation_valve_control_diagnostic_enable_flag, governor_speed_stability_conditions_flag): 1 while control error bit 0x20 of diagnostic_status_bits is set, otherwise only in closed-loop state 0 "
   "with fault 718 clear, the motor ok flag set, the position sensor fault status 0, the final position command within the steady-state deviation threshold of its filtered average and, when the position deviates, the PID output at or above the strong-drive duty threshold toward the command.")
fn(0x199f4, 'cm848_updateExhaustGasRecirculationValvePositionCommandAndControlState',
   "Position command stage of the EGR valve loop: the command is the calibrated override value when bit 0 of exhaust_gas_recirculation_valve_user_override_flags_cal is set, 0 when exhaust_gas_recirculation_valve_position_diagnostic_override_flag is set, otherwise "
   "throttle_fuel_demand_limit (the EGR valve command of the EGR / assist controller, 12800 = 100 percent, 0 in the dump); while boost_decel_mode_flag is set (engine speed 0, bit 0 of switch_input_state_bits[0] clear, coolant above boost_decel_input_threshold_cal) it is 12800, or 0 when boost_correction_alt_mode_cal is non-zero; "
   "it is capped at throttle_fuel_rate_cal (12800) and stored in exhaust_gas_recirculation_valve_position_command (governor_speed_target_input). Then runs the closed-hold check, the control state selection, the staged command and the gain set selection.")

# ---------------- extra spec rows found while re-reading ----------------
SPEC3 = [
 (0x40a6b6, 'EGA_Control_Diag_Count_Enabled', 'control_diagnostic_count_enabled_flag', 'set when the conditions flag has held for the enable time; the fault counter may then count'),
 (0x40a6b8, 'EGA_Control_Diag_Enable', 'control_diagnostic_enable_flag', 'enable flag of the position control diagnostic (cm848_evaluateExhaustGasRecirculationValvePositionControlDiagnosticConditions)'),
 (0x40a6ba, 'EGA_Control_Diag_Fault_Count', 'control_diagnostic_fault_counter', 'fault counter of the position control diagnostic: fault 725 at the fail threshold'),
 (0x40a6bc, 'EGA_Control_Error_Condition', 'control_error_condition_flag', 'set when the autozeroed position differs from the final position command by more than the control error threshold (deviation detected, not confirmed)'),
 (0x40a6c0, 'EGA_PWM_Is_Strongly_Commanded', 'drive_strongly_commanded_flag', 'gate of the diagnostic conditions: 0 when the position deviates and the PID output toward the command is below the strong-drive duty threshold'),
]
for a, p, suf, code in SPEC3:
    gl(a, V(suf), code, e2m_text(p))
for a, p, suf, code in [(0x4067b2, 'C_EGA_Current_Avg_Fil_Cnst', 'mean_squared_current_filter_coefficient', 'EMA coefficient of the mean-squared current filter (the ema_filter_state_t at 0x3fa758 points at it)'),
                        (0x4067cc, 'C_EGA_Tmptr_Fil_Cnst_1', 'motor_winding_temperature_filter_coefficient', 'EMA coefficient of the winding temperature filter (the state at 0x3fa760 points at it)'),
                        (0x4067ce, 'C_EGA_Tmptr_Fil_Cnst_2', 'motor_iron_core_temperature_filter_coefficient', 'EMA coefficient of the iron core temperature filter (the state at 0x3fa768 points at it)')]:
    gl(a, V(suf), code, e2m_text(p))
for a, suf, code in [(0x3fa758, 'motor_mean_squared_current_filter_state', 'ema_filter_state_t of the mean-squared current: the filtered input is current x current >> 13 (cm848_updateExhaustGasRecirculationValveMeanSquaredCurrent); its coefficient points at exhaust_gas_recirculation_valve_mean_squared_current_filter_coefficient'),
                     (0x3fa760, 'motor_winding_temperature_filter_state', 'ema_filter_state_t of the winding temperature (cm848_updateExhaustGasRecirculationValveMotorTemperature); coefficient word 0x4067cc'),
                     (0x3fa768, 'motor_iron_core_temperature_filter_state', 'ema_filter_state_t of the iron core temperature (cm848_updateExhaustGasRecirculationValveMotorTemperature); coefficient word 0x4067ce')]:
    gl(a, V(suf), code, None)
G = [g for g in G if g[0] not in (0x3fa744, 0x3fa746)]
gl(0x40a698, V('driver_over_current_retry_trigger_flag'), 'set when the clear timer (governor_speed_rate_d, first word) has reached the clear time; an input of the clear-conditions flag', e2m_text('EGA_Driver_OC_Fault_Retry'))
gl(0x40a69a, V('driver_over_current_clear_conditions_met_flag'), 'retry allowed and the clear timer at its limit; its absence while the over-current is flagged sets fault 727, its presence clears it', e2m_text('EGA_Driver_OC_Fault_Clear'))
gl(0x40a69c, V('driver_over_current_detected_flag'), 'set when the set timer has reached the set time', e2m_text('EGA_Driver_OC_Fault_Bit'))
gl(0x3fa748, V('driver_over_current_retry_active_flag'), '1 when the clear-conditions flag has been set for three passes and the over-current is not detected; gates the retry counter', None)
gl(0x3fa744, V('driver_over_current_clear_conditions_met_previous_flag'), 'clear-conditions flag of the previous pass (history for the retry-active flag)', None)
gl(0x3fa746, V('driver_over_current_clear_conditions_met_previous_2_flag'), 'clear-conditions flag two passes ago', None)
gl(0x3fa73c, V('driver_over_current_set_timer'), 'set timer of the over-current check (word): + the time increment up to the set time while the current is at or above the threshold, - the time decrement otherwise', None)
gl(0x3fa742, V('driver_over_current_retry_allowed_flag'), '1 unless the give-up enable word is set and the retry counter has reached its maximum count', None)
# drop spec items that duplicate or contradict the corrected plan
G = [g for g in G if g[0] not in (0x3fa790,)]

# ---------------- new_global rows (no row in global_variables.csv; widths from xref_addr.py) ----------------
NEW = [
 (0x4067d8, 'steady_state_command_deviation_threshold', 'word', 1, 0, 'only reader cm848_evaluateExhaustGasRecirculationValvePositionControlDiagnosticConditions: the diagnostic runs only while |final position command - its filtered average| is below it (DAT_004067d8). e2m: C_EGA_Cmd_Rate_Thd (0x0117AE00) is +0x00 of the block that anchors 0x4067d8.'),
 (0x4067da, 'control_error_threshold', 'word', 1, 0, 'only reader cm848_runExhaustGasRecirculationValvePositionControlDiagnostic: the control error condition is set when |autozeroed position - final command| is above it. e2m: C_EGA_Control_Error_Thd (0x0117AE02) is +0x02 of the block that anchors 0x4067d8.'),
 (0x4067dc, 'control_diagnostic_enable_time', 'word', 1, 0, 'only reader cm848_updateExhaustGasRecirculationValvePositionControlFaultCounter: the pass count of stable conditions before the counter may count. e2m: C_EGA_Control_Diag_Enable_Time (0x0117AE04) is +0x04 of the block that anchors 0x4067d8.'),
 (0x4067e6, 'control_fault_time_pass_threshold', 'word', 1, 0, 'only reader cm848_updateExhaustGasRecirculationValvePositionControlFaultCounter: control error fault 725 is cleared at or below it. e2m: C_EGA_Pass_Time_Thd (0x0117AE0E) is +0x0e of the block that anchors 0x4067d8.'),
 (0x4067e8, 'control_strong_drive_duty_threshold', 'word', 1, 0, 'only reader cm848_evaluateExhaustGasRecirculationValvePositionControlDiagnosticConditions: the PID output toward the command must reach it for the diagnostic to run while the position deviates. e2m: C_EGA_Control_PWM_Threshold (0x0117AE10) is +0x10 of the block that anchors 0x4067d8.'),
 (0x40a6b4, 'position_command_deviation', 'word', 0, 2, 'written by cm848_evaluateExhaustGasRecirculationValvePositionControlDiagnosticConditions (|final position command - its filtered average|) and the diagnostic init, never read by name. e2m: EGA_Position_Cmd_Diff (0x0117AF00) is +0x00 of the block that anchors 0x40a6b4.'),
 (0x40a6be, 'position_command_diagnostic_filtered', 'word', 0, 1, 'written by cm848_evaluateExhaustGasRecirculationValvePositionControlDiagnosticConditions: the EMA of the final position command (coefficient 0x4067e2). e2m: EGA_Filtered_Diag_Cmd (0x0117AF0A) is +0x0a of the block that anchors 0x40a6b4.'),
 (0x40a670, 'autozero_enabled_flag', 'word', 0, 1, 'written by cm848_updateExhaustGasRecirculationValveAutozeroActiveFlag as a copy of exhaust_gas_recirculation_valve_autozero_active_flag; never read by name. e2m: EGR_Valve_Autozero_Enabled (0x01179D0C) is +0x0c of the block that anchors 0x40a664.'),
 (0x40674e, 'position_autozero_enable_time', 'word', 1, 0, 'only reader cm848_updateExhaustGasRecirculationValvePositionAutozero: copied into the autozero filter block (DAT_003fbcd0). e2m: C_EGR_Position_AZ_Enable_Time (0x01179C00) is +0x00 of the block that anchors 0x40674e.'),
 (0x406750, 'position_autozero_fault_time', 'word', 1, 0, 'only reader cm848_updateExhaustGasRecirculationValvePositionAutozero: copied into the autozero filter block (DAT_003fbcd2). e2m: C_EGR_Position_AZ_Fault_Time (0x01179C02) is +0x02 of the block that anchors 0x40674e.'),
 (0x406756, 'position_autozero_override_value', 'word', 1, 0, 'only reader cm848_updateExhaustGasRecirculationValvePositionAutozero: the zero offset used instead of the learned one when the autozero override enable word is non-zero. e2m: C_EGR_Pos_AZ_Override_Value (0x01179C08) is +0x08 of the block that anchors 0x40674e.'),
 (0x406758, 'closed_position_tolerance', 'word', 1, 0, 'only reader cm848_selectExhaustGasRecirculationValvePositionSource: the valve counts as closed when the position is at or below it and the closed hold flag is clear. e2m: C_EGR_Valve_Is_Closed_Thd (0x01179C0A) is +0x0a of the block that anchors 0x40674e.'),
 (0x3fd7f2, 'position_autozero_error_count_clear_cal', 'word', 1, 0, 'read by cm848_updateExhaustGasRecirculationValvePositionAutozero and copied into the autozero filter block (DAT_003fbcd8) as its clear input. e2m: T_EGR_Clr_Autozero_Error_Count (0x01196C00) is the first of three words that continue with 0x3fd7f4 and 0x3fd7f6. EEPROM mirror, so _cal.'),
 (0x3fd7f4, 'position_autozero_enable_cal', 'word', 1, 0, 'only reader cm848_updateExhaustGasRecirculationValveAutozeroActiveFlag: the autozero active flag needs it non-zero. e2m: T_EGR_Pos_AZ_Logic_Enable (0x01196C02) is +2 of the word that anchors 0x3fd7f2. EEPROM mirror, so _cal.'),
 (0x3fd7f6, 'position_autozero_override_enable_cal', 'word', 1, 0, 'only reader cm848_updateExhaustGasRecirculationValvePositionAutozero: non-zero selects the override value instead of the learned offset. e2m: T_EGR_Pos_AZ_User_Override (0x01196C04) is +4 of the word that anchors 0x3fd7f2. EEPROM mirror, so _cal.'),
 (0x3fd7fa, 'control_fault_counter_clear_cal', 'word', 1, 0, 'only reader cm848_updateExhaustGasRecirculationValvePositionControlFaultCounter: non-zero holds the fault counter at 0. e2m: T_EGA_Clear_Inrange_Error_Count (0x0117AD02, resets the counter of EGA_Control_Diag_Fault_Count) is +2 of the word that anchors 0x3fd7f8. EEPROM mirror, so _cal.'),
]

# ---------------- evidence for function rows ----------------
FE = {
 0x18f8c: "code: gates on logical output request 67 and fault 744, uses the previous pass duty (fuel_timing_error_working) and sensor_channel75_value; disassembly 0x1905c-0x19064 reads 0x3fe9d0 mask 0x100 (the VGT electrical fault word), not diagnostic_status_bits 0x40. e2m: EGA_Back_EMF / EGA_Circuit_Resistance / C_EGA_Speed_EMF_Factor etc. sit at the matching offsets of the 0x0117A900 and 0x0117BF00 blocks.",
 0x191a0: "code: calls the current estimate and filters its square into boost_fuel_correction_squared_ema, the same structure as cm848_updateVariableGeometryTurbochargerMeanSquaredCurrent. e2m: EGA_Mean_Squared_Current (0x0117A904).",
 0x191e8: "code: disassembly 0x19340-0x19360 (rlwinm mask 0x100, cmpwi 1, beq) shows the clear always runs. e2m: EGA_Valve_Fault_Over_Tmptr (0x01103664 mask 0x1000, .12 file; relative order after the VGT bit only).",
 0x19390: "code: reads the mean-squared current, the coolant temperature and the thermal calibration words at 0x4067c0-0x4067d0, sets mask 0x100 of diagnostic_status_bits. e2m: EGA_Over_Temperature (0x0110365A mask 0x100) and C_EGA_Tmptr_* (0x0117BF10-0x0117BF20).",
 0x1956c: "code: initialises exactly the words the estimate and thermal model use (previous position / direction / duty and the three filter states). e2m: C_EGA_Tmptr_Fil_Cnst_1 / _2, C_EGA_Current_Avg_Fil_Cnst.",
 0x196a4: "code: counter limit is 0x40682c and threshold 0x406824, which are C_EGA_Max_Time_To_Zero_Hold (+0x42) and C_EGA_Zero_Position_Thd (+0x3a) of the block that anchors 0x4067ea. e2m: EGA_Zero_Hold_Status (0x0117AC06).",
 0x197b4: "code: five states, 4 when request 67 is clear. e2m: EGA_Control_State (0x0117AC08) is documented as 0 closed-loop, 1 OL hold, 2 user pwm OD, 3 diagnostic pwm OD, 4 disabled - the same five states.",
 0x19830: "code: the two gain sets are the _state_1 / _state_0 calibration words 0x4067ee-0x406808 and 0x40680a / 0x40680c. e2m: C_EGA_*_Normal / C_EGA_*_Zero pairs (+0x04 to +0x22 of the block that anchors 0x4067ea).",
 0x19900: "code: thresholds 0x40681c-0x406820 are C_EGA_Stage_Cmd_Thd / _Position_Thd / _Ramp_Rate (+0x32 to +0x36). e2m: EGA_Position_Cmd_Final (0x0117AC04).",
 0x199f4: "code: the setpoint is throttle_fuel_demand_limit, +0x06 (EAC_EGR_Valve_Cmd) of the block 0x40a3a2 that cm848_calculateLoadIntegral fills; its assist throttle sibling (+0x00, throttle_fuel_rate_reference) has no reader in the binary, this word has exactly one. e2m: EAC_EGR_Valve_Cmd (0x01169F06), EGA_Position_Cmd (0x0117AC20), C_EGA_Cmd_Override_Value (0x0117AB02).",
 0x19ac0: "code: the flag gates the integral input of cm848_calculateExhaustGasRecirculationValvePidDuty. e2m: EGA_Error_I_Term_Input (0x0117AC10) description: I term error after deadband and anti-windup.",
 0x19b20: "code: read in full; the integral accumulates only after a pass in control state 0 (governor_operating_mode_prev_snapshot = 0). e2m: EGA_P_Gain / EGA_D_Gain / EGA_I_Gain / EGA_FF_Term / EGA_Governor_PWM (0x0117AC0A-0x0117AC20).",
 0x19e08: "code: governor_operating_mode selects the source: 0 PID, 1 governor_mode1_param_cal, 2 governor_speed_mode2_param_cal, 3 governor_mode3_speed_param, 4 zero, then the clamp. e2m: EGA_PWM_Selected (0x0117AC2A).",
 0x19ea4: "code: shares battery_voltage_nominal / battery_voltage_selected with the VGT stage cm848_limitVariableGeometryTurbochargerBatteryCompensatedDuty (224 / 192 in the dump). e2m: EGA_PWM_Battery_Compensated / EGA_PWM_Clamped (0x0117AC28 / 0x0117AC2C), C_EGA_Compensated_PWM_Lim.",
 0x19fe0: "code: logical output 68 is driven through cm848_setLogicalOutputAndDriveLine(0x44); its line (protection_event_output_line_cal[68]) is 0 in the dump. e2m: EGA_Motor_Cmd_Opening_Direction (0x01157708 mask 0x10) and EGA_PWM_Abs (duty / period / map).",
 0x1a1b4: "code: calls the three stages in order, as cm848_driveVariableGeometryTurbochargerMotor does for the VGT. e2m: none.",
 0x1a1dc: "code: runs the position command stage, the PID stage and the motor stage. e2m: none.",
 0x1a204: "code: calls the enable / set-duty / set-period slots of output_channel_driver_table for the entry 39 record only when 0 < record < 51; the record word is 0 in this calibration. e2m: EGA_PWM_Abs_Map / EGA_PWM_Abs_PWM_Period_Cal.",
 0x18cfc: "code: thresholds 0x4067a8-0x4067ae and 0x4067aa are C_EGA_Driver_OC_* (+0x08 to +0x0e of the block 0x01190800 that anchors 0x4067a0). e2m: EGA_Driver_Over_Current (0x0110365A mask 0x80).",
 0x18bc0: "code: reads the retry-allowed state and the give-up enable word (0x3fd7fe, e2m T_EGA_Enable_Driver_OC_Give_Up); calibration words 0x4067a2-0x4067a6 are C_EGA_Driver_OC_Fail_Incrt / Max_Count / Pass_Decrt. e2m: EGA_Driver_OC_Fault_Clear (0x01190902).",
 0x18f1c: "code: clears exactly the words of the over-current check and mask 0x80. e2m: EGA_Driver_Over_Current (0x0110365A mask 0x80).",
 0x1a340: "code: same scheme as cm848_updateVariableGeometryTurbochargerHBridgeFaultRetryTimer; limit 0x406834 and step 0x40684a are C_EGA_HB1_Retry_Time (+0x00) and C_EGA_HB1_Retry_Increment (+0x16). e2m: EGA_Fault_HB1_Retry (0x0117C202).",
 0x1a47c: "code: counter limit 0x406836, decrement 0x406838, increment 0x406840, set threshold 0x406844 are C_EGA_Fault_HB1_Max_Count / Pass_Decrt / Fail_Incrt / HB1_Fault_Set. e2m: EGA_HB1_Fault_Clear / EGA_Fault_HB1_Fault_Set (0x0117C200 / 0x0117C20C).",
 0x1a608: "code: limit 0x40683a and step 0x406846 are C_EGA_HB1_Inrush_Retry_Time / _Retry_Incrt. e2m: EGA_Fault_HB1_Inrush_Retry (0x0117C204).",
 0x1a754: "code: limit 0x40683c, decrement 0x40683e, increment 0x406842, set threshold 0x406848 are C_EGA_HB1_OC_Max_Count / Pass_Decrt / Fail_Incrt / HB1_OC_Fault_Set; sets mask 0x10. e2m: EGA_Fault_HB1_Inrush (0x0110365A mask 0x10), EGA_HB1_Inrush_Fault_Clear.",
 0x1a9a8: "code: masks 1 / 2 / 4 / 8 / 0x10 / 0x40 of diagnostic_status_bits are the e2m masks of EGA_Fault_HB1A / HB1B / HB1_OC_HI / HB1_OC_LO / HB1_Inrush / EGA_Electrical_Fault (0x0110365A). All have no DTC slot in the 0x5985a table.",
 0x1ae2c: "code: clears the words of both fault paths and masks 0x01-0x1f and 0x40. e2m: EGA_Fault_HB1* masks at 0x0110365A.",
 0x1af94: "code: calibration limits 0x40684c / 0x406850 are C_EGA_Autozero_Active_Time / _Retry_Time and 0x40684e the holding duty C_EGA_Autozero_PWM_Value (+0x00 to +0x04 of the block 0x0117C000). e2m: EGA_Ready_For_Autozero (0x0117AA0C).",
 0x1b120: "code: sets / clears logical output requests 67 (0x43) with cm848_setLogicalOutputRequest(0x43, 0); line of request 67 is 0 in the dump. e2m: EGA_Motor_OK / EGA_Pos_Diagnostic_Override / EGA_PWM_Enable (0x0117AA04 / 06, 0x01157708 mask 8).",
 0x1b35c: "code: clears the three words of the autozero conditions only. e2m: none.",
 0x1b37c: "code: the two calls in order; the enable and diagnostic conditions come first. e2m: none.",
 0x506840: "code: the filter block 0x3fbcc6 holds the learned offset, the thresholds are the position autozero words at 0x40674e-0x406758 (C_EGR_Position_AZ_*), and fault 718 is the mask 0x4000 of fault word 704-719. e2m: EGR_Position_AP (0x01179D02), EGR_Valve_Autozero_Error (0x01103658 mask 0x4000 = fault 718).",
 0x506964: "code: the combined status is the channel 75 fault status | 8 (fault 718) | 0x20 (control error 725); in the dump fault 718 is set (0x3fe9cc = 0x4000), so the source is the default. e2m: EGR_Position, EGR_Position_Source (0 primary, 1 backup, 2 default), EGR_Valve_Is_Closed (0x01179D04-0x01179D08).",
 0x506a3c: "code: the three calls. e2m: none.",
 0x506a64: "code: same word set as the source selection. e2m: EGR_Position_Source.",
 0x5067e0: "code: the written word 0x40a670 is EGR_Valve_Autozero_Enabled (+0x0c of the position block that anchors 0x40a664). e2m: EGR_Valve_Autozero_Enabled (0x01179D0C).",
 0x507214: "code: DAT_004067d8 / DAT_004067e8 are C_EGA_Cmd_Rate_Thd / C_EGA_Control_PWM_Threshold. e2m: EGA_Control_Diag_Enable (0x0117AF04), EGA_PWM_Is_Strongly_Commanded (0x0117AF0C).",
 0x507394: "code: DAT_004067dc / DAT_004067e6 and the words 0x4067de / 0x4067e0 / 0x4067e4 are the C_EGA_Control_* diagnostic calibration (+0x04 to +0x0e of the block that anchors 0x4067d8); DAT_003fd7fa is T_EGA_Clear_Inrange_Error_Count. e2m: EGA_Control_Error (0x0110365A mask 0x20).",
 0x507548: "code: DAT_004067da is C_EGA_Control_Error_Thd. e2m: EGA_Control_Error_Condition (0x0117AF08).",
 0x5075b8: "code: clears the diagnostic words and mask 0x20. e2m: none.",
 0x507644: "code: DAT_003fdfb4 (dword, 1 read / 1 write) is incremented on each rising edge of the closed-hold flag. e2m: T_EGA_Cycle_Counter (0x01192D00, number of EGR valve closings over its lifetime).",
 0x507684: "code: only writes the previous flag. e2m: none.",
 0x107ec: "code: sensor channel 4 init (cm848_sensorChannel2_init) passes the battery_voltage_linearization tables and fault bits 0x43 / 0x42 = faults 67 / 66, which the ROM slot table 0x5985a and obd_dtc_code_table 0x5b57c decode to P0563 / P0562 (system voltage high / low). e2m: Battery_Voltage_High_Error / _Low_Error (0x01103608 masks 8 / 4).",
 0x1083c: "code: reads the same fault status and writes the source flag only. e2m: none.",
 0x505b84: "code: the generic channel (cm848_sensorChannelGeneric_update_configBundle) passes coolant_temperature_linearization_axis / _values and fault bits 0x10 / 0x11 = faults 16 / 17, decoded to P0118 / P0117 (coolant temperature circuit high / low). e2m: Coolant_Temperature_High_Error / _Low_Error (0x01103602 masks 1 / 2).",
 0x505bd8: "code: the init counterpart of cm848_selectCoolantTemperature. e2m: none.",
}
FE[0x191a0] = FE[0x191a0]

# ---------------- assemble ----------------
out = []
problems = []
renamed_old = {}
for addr in sorted(F):
    if addr not in frows:
        problems.append(('no function row', hex(addr)))
        continue
    new, plate = F[addr]
    old = frows[addr][1]
    renamed_old[old] = new
    ev = FE.get(addr, 'code: see the plate. e2m: none.')
    out.append({'kind': 'function', 'address': '0x%08x' % addr, 'old': old, 'verdict': 'confirmed', 'new': new,
                'plate_comment': plate + ' ' + was(addr), 'evidence': ev})
for addr in (0x1a980, 0x2c9bc):
    pass
seen = set()
for g in G:
    addr, new, code, e2 = g
    if addr in seen:
        problems.append(('duplicate global spec', hex(addr)))
        continue
    seen.add(addr)
    if addr not in grows:
        problems.append(('no global row (use new_global)', hex(addr), new))
        continue
    old = grows[addr][1]
    renamed_old[old] = new
    if addr == 0x40a6a0:
        e2 = 'EGR motor current is not among the EGA_ parameter names; EGA_Temperature_Warning (+0x00) and EGA_Mean_Squared_Current (+0x04) of the block that anchors 0x40a69e bracket it.'
    ev = 'code: ' + ('row exists with an empty name. ' if old == '' else '') + users_text(old) + code.rstrip('.') + '.'
    if e2:
        ev += ' e2m: ' + e2
    ev += ts_sentence(addr)
    out.append({'kind': 'global', 'address': '0x%08x' % addr, 'old': old, 'verdict': 'confirmed', 'new': new, 'evidence': ev})
for addr, suf, typ, rd, wr, code in NEW:
    if addr in grows:
        problems.append(('new_global row exists', hex(addr), grows[addr][1]))
        continue
    pl = lambda n, w: '%d %s' % (n, w if n == 1 else w + 's')
    ev = f"code: xref_addr.py says {typ} ({rd} {'read' if rd == 1 else 'reads'} / {wr} {'write' if wr == 1 else 'writes'}): {code}" + ts_sentence(addr)
    out.append({'kind': 'new_global', 'address': '0x%08x' % addr, 'new': V(suf), 'type': typ, 'evidence': ev})

json.dump(problems, open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w7/problems.json', 'w'))
json.dump(renamed_old, open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w7/renamed_old.json', 'w'))
json.dump(out, open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w7/rows_part1.json', 'w'))
print('rows', len(out), 'problems', problems)
print('functions', sum(1 for r in out if r['kind'] == 'function'), 'globals', sum(1 for r in out if r['kind'] == 'global'), 'new_global', sum(1 for r in out if r['kind'] == 'new_global'))
