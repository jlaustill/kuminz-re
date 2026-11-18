import csv, json, re, struct, sys
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w7')
import peek

ROOT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/'
OUT = ROOT + 'firmware/CM848_S90140.06_analysis/output/'
RESULT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W7_vgt_egr.jsonl'
P = 'exhaust_gas_recirculation_valve_'

grows = {}
for r in csv.reader(open(OUT + 'global_variables.csv')):
    if len(r) >= 3 and r[0].startswith('0x'):
        grows.setdefault(int(r[0], 16), r)
frows = {}
for r in csv.reader(open(OUT + 'function_renames.csv')):
    if len(r) >= 2 and r[0].startswith('0x'):
        frows.setdefault(int(r[0], 16), r)
e2m = {}
for r in csv.reader(open(OUT + 'e2m_parameters.csv')):
    if r and r[0] not in ('parameter',):
        try:
            e2m.setdefault(r[0], (int(r[2], 16), r[6] if len(r) > 6 else ''))
        except ValueError:
            pass
ROM = peek.ROM

# ---------- boot ROM scan for time-shared words ----------
def in_window(a):
    return 0x3F9800 <= a <= 0x3FDB30 or 0x3FEE08 <= a <= 0x3FEE3D

def boot_scan(a):
    hits = []
    lo = a & 0xFFFF
    for off in range(0, 0x7F60, 4):
        w = struct.unpack('>I', ROM[off:off + 4])[0]
        op = w >> 26
        if op in (14, 24, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47) and (w & 0xFFFF) == lo:
            hits.append(off)
        elif w == a:
            hits.append(off)
    return hits

TS_CACHE = {}
def ts_sentence(a):
    if not in_window(a):
        return ''
    if a not in TS_CACHE:
        TS_CACHE[a] = boot_scan(a)
    h = TS_CACHE[a]
    if not h:
        return (' Time-shared window (0x3F9800-0x3FDB30): xref_addr.py lists no access below 0x7F60 and a scan of the boot ROM 0x0-0x7F5F '
                '(instructions with the low halfword of the address, 32-bit words equal to it) finds none; no type is changed.')
    return (' Time-shared window (0x3F9800-0x3FDB30): the boot ROM scan 0x0-0x7F5F lists candidate hits at ' +
            ', '.join('0x%x' % x for x in h[:6]) + ' (instruction low-halfword matches, not proven accesses); no type is changed.')

# ---------- function plan ----------
F = {}   # address -> (new, plate)
def fn(addr, new, plate):
    F[addr] = (new, plate)

def was(addr):
    old = frows[addr][1]
    older = ''
    c = frows[addr][2] if len(frows[addr]) > 2 else ''
    m = re.search(r'\(was ([^)]+)\)', c)
    if m:
        older = ', before that ' + m.group(1)
    return f"(was {old}{older})"

V = lambda n: P + n
dump = lambda a, w='w', s=False: peek.peek(a, w, s)

# (plates are written from the twin's own code; the VGT plates were only used for the structure)
fn(0x18f8c, 'cm848_estimateExhaustGasRecirculationValveMotorCurrent',
   "Estimates the EGR valve motor current into exhaust_gas_recirculation_valve_motor_current (0.000976562 A per count): the applied voltage is "
   "(|the previous pass drive duty| + exhaust_gas_recirculation_valve_drive_duty_offset) x battery_voltage_selected >> 8 while logical output request 67 is set "
   "and fault 744 (mask 256 of fault_detected_bits_736_to_751, the variable geometry turbocharger electrical fault - not this valve's own fault 726) is clear; the back "
   "electromotive force is the change of the position sensor value x exhaust_gas_recirculation_valve_speed_back_electromotive_force_factor / 2048 (limited to +-32000, sign from the previous direction request, request 68); "
   "the current is |voltage - back EMF| / the circuit resistance (reference resistance + winding temperature x temperature coefficient), limited to exhaust_gas_recirculation_valve_motor_current_maximum.")
fn(0x191a0, 'cm848_updateExhaustGasRecirculationValveMeanSquaredCurrent',
   "Per-pass current update of the EGR valve motor: runs the current estimate, then filters the square of the current (current x current >> 13) into exhaust_gas_recirculation_valve_motor_mean_squared_current; "
   "called from cm848_phase_group_b_processing.")
fn(0x191e8, 'cm848_updateExhaustGasRecirculationValveOverTemperatureFault',
   "Valve over-temperature timer of the EGR valve: counts up to exhaust_gas_recirculation_valve_over_temperature_inhibit_time (boost_fuel_correction_limit_cal) while the coolant temperature is below its default, the coolant source is the sensor, "
   "and the filtered boost_fuel_correction is below boost_correction_threshold_cal; when the count is reached while motor over-temperature fault 728 (mask 0x100 of diagnostic_status_bits) is set it sets mask 0x800 (fault 795) of fault_detected_bits_784_to_799. "
   "A test (diagnostic_status_bits & 0x100) != 1 is always true, so the bit is cleared again on every pass and fault 795 cannot stay set (disassembly 0x19340-0x19360).")
fn(0x19390, 'cm848_updateExhaustGasRecirculationValveMotorTemperature',
   "Thermal model of the EGR valve motor: heats the winding temperature (engine_boost_load_ema, 1/8 degree F) from the mean-squared current x exhaust_gas_recirculation_valve_normalized_resistance above the iron core temperature, "
   "derives the iron core temperature (1/64 degree F) from the winding temperature, the ambient temperature (coolant temperature, or its default when the coolant source is not the sensor, plus the housing offset) and the temperature fraction, both through first-order filters; "
   "sets the warning flag at the warning threshold and fault 728 (mask 0x100 of diagnostic_status_bits) at the high threshold (cleared below the low threshold), then runs the valve over-temperature timer.")
fn(0x1956c, 'cm848_initializeExhaustGasRecirculationValveMotorThermalModel',
   "Boot init of the EGR valve motor thermal model and current estimate: clears fault 728 (mask 0x100) in the detected and registered fault words, zeroes the mean-squared current filter, loads the previous position sensor value, "
   "the previous direction request (request 68) and the previous drive duty, and starts the winding temperature filter at the coolant temperature / 8 and the iron core temperature filter at the coolant temperature (0 when it is below 1).")
fn(0x196a4, 'cm848_checkExhaustGasRecirculationValveClosedHoldCondition',
   "Closed-hold condition of the EGR valve loop: while the position command is 0 a counter (boost_pressure_governor_ramp_working) rises to exhaust_gas_recirculation_valve_closed_hold_maximum_time (reset when the command is non-zero); "
   "exhaust_gas_recirculation_valve_closed_hold_flag (governor_speed_at_target_flag) is set when the command is 0 and either the counter has reached that time or the position (or the staged command) is at or below exhaust_gas_recirculation_valve_closed_hold_position_threshold. It selects control state 1.")
fn(0x197b4, 'cm848_selectExhaustGasRecirculationValveControlState',
   "Selects exhaust_gas_recirculation_valve_control_state (governor_operating_mode): 4 (disabled) while logical output request 67 is clear, otherwise 3 (diagnostic drive: autozero holding duty) when governor_speed_b_mode_select_flag is set, 2 (user duty override) when bit 1 of "
   "exhaust_gas_recirculation_valve_user_override_flags_cal is set, 1 (closed hold) when exhaust_gas_recirculation_valve_closed_hold_flag is set, else 0 (closed loop).")
fn(0x19830, 'cm848_selectExhaustGasRecirculationValveGainSet',
   "Gain scheduling of the EGR valve loop: loads the working derivative gain, proportional gain, integral gain, feedforward load offset, integral lower limit and position reference filter coefficient from the zero-command (valve closing) set when the position command is 0 and from the normal set otherwise.")
fn(0x19900, 'cm848_calculateExhaustGasRecirculationValveStagedPositionCommand',
   "Staged closing of the EGR valve position command: below exhaust_gas_recirculation_valve_closed_stage_command_threshold the staged command (governor_speed_ramp_state) ramps down by the ramp rate (0 when the position is above the stage position threshold) and never below the command; "
   "the result is exhaust_gas_recirculation_valve_position_command_final (governor_speed_ramp_output). In control states other than 0 and 1 the reference is the measured position instead (boost_pressure_target_input).")
fn(0x199f4, 'cm848_updateExhaustGasRecirculationValvePositionCommandAndControlState',
   "Position command stage of the EGR valve loop: the command is the calibrated override value when bit 0 of exhaust_gas_recirculation_valve_user_override_flags_cal is set, 0 when exhaust_gas_recirculation_valve_position_diagnostic_override_flag is set, otherwise "
   "throttle_fuel_demand_limit (the EGR valve command of the EGR / assist controller, 12800 = 100 percent; 0 in the dump); while the key-off autozero precondition boost_decel_mode_flag is set it is 12800 (0 when boost_correction_alt_mode_cal is non-zero); "
   "it is capped at throttle_fuel_rate_cal (12800) and stored in exhaust_gas_recirculation_valve_position_command (governor_speed_target_input). Then runs the closed-hold check, the control state selection, the staged command and the gain set selection.")
fn(0x19ac0, 'cm848_updateExhaustGasRecirculationValveIntegralEnable',
   "Anti-windup of the EGR valve loop: sets exhaust_gas_recirculation_valve_integral_enable_flag (governor_speed_range_active_flag) to 1 unless the battery compensated duty is pinned at its upper limit with a negative error or at its lower limit with a positive error (the error then pushes further into the limit).")
fn(0x19b20, 'cm848_calculateExhaustGasRecirculationValvePidDuty',
   "PID stage of the EGR valve position loop: filters the reference (exhaust_gas_recirculation_valve_position_reference_filtered), forms the position error against exhaust_gas_recirculation_valve_position (boost_pressure_filtered), and sums the proportional term, "
   "the derivative term (filtered error change x gain >> 3, off below the noise band), the feedforward load offset, the friction avoidance term while the motor current is at or above the steady-state limit, and the integral term (accumulator >> 14, only outside the steady-state error band and not wound up) into "
   "exhaust_gas_recirculation_valve_pid_duty (governor_speed_derivative_value, limited to +-32767; 12800 = 100 percent). The code's p / d gain names are swapped: governor_speed_b_p_gain_active is the derivative gain and governor_speed_b_d_gain_active the proportional gain.")
fn(0x19e08, 'cm848_selectExhaustGasRecirculationValveDutyByControlState',
   "Picks the drive duty from the control state: state 0 takes exhaust_gas_recirculation_valve_pid_duty, state 1 the closed hold duty, state 2 the user override duty, state 3 the autozero holding duty and state 4 gives 0; states 1 to 4 are bounded by the override lower and upper duty limits. "
   "The result is exhaust_gas_recirculation_valve_drive_duty_selected (governor_speed_b_pid_output).")
fn(0x19ea4, 'cm848_limitExhaustGasRecirculationValveBatteryCompensatedDuty',
   "Compensates the selected drive duty and the upper duty limit for the supply voltage (x battery_voltage_nominal / battery_voltage_selected, 224 / 192 in the dump), limits the duty to the lower and upper limit and to +-32767 and stores it in "
   "exhaust_gas_recirculation_valve_drive_duty_clamped (governor_speed_range_output); the compensated duty limit is capped at +-12800.")
fn(0x19fe0, 'cm848_outputExhaustGasRecirculationValveDirectionAndDuty',
   "Output stage of the EGR valve loop: the sign of exhaust_gas_recirculation_valve_drive_duty_clamped sets or clears logical output 68 (direction, immediately driving its line) - inverted when exhaust_gas_recirculation_valve_motor_direction_reversal is 1 - and the magnitude x 2 "
   "(12800 minus it x 2 when the polarity reversal is set) is the PWM duty (25600 = 100 percent), forced to 0 on a direction change or below the zero threshold; the duty goes to the output channel record of actuator_output_channel_g_cal (entry 39), which is 0 (unassigned) in this calibration.")
fn(0x1a1b4, 'cm848_driveExhaustGasRecirculationValveMotor',
   "Stage 3 of the EGR valve position loop: cm848_selectExhaustGasRecirculationValveDutyByControlState, cm848_limitExhaustGasRecirculationValveBatteryCompensatedDuty and cm848_outputExhaustGasRecirculationValveDirectionAndDuty in that order; called by cm848_runExhaustGasRecirculationValvePositionControlLoop.")
fn(0x1a1dc, 'cm848_runExhaustGasRecirculationValvePositionControlLoop',
   "Per-pass runner of the EGR valve position loop: cm848_updateExhaustGasRecirculationValvePositionCommandAndControlState, cm848_calculateExhaustGasRecirculationValvePidDuty and cm848_driveExhaustGasRecirculationValveMotor in that order; called by cm848_runExhaustGasRecirculationValveFaultAndPositionControl.")
fn(0x1a204, 'cm848_initializeExhaustGasRecirculationValvePositionControlLoop',
   "Boot init of the EGR valve position loop: clears the previous error and duty state, sets the previous control state to 3, points the reference filter and the derivative filter at their coefficients and, when actuator_output_channel_g_cal is 1 to 50, enables that output channel record, "
   "sets its duty to 0 and its period to exhaust_gas_recirculation_valve_motor_pwm_period.")
fn(0x18cfc, 'cm848_updateExhaustGasRecirculationValveDriverOverCurrentFault',
   "Over-current check of the EGR valve motor driver: while the estimated motor current is at or above exhaust_gas_recirculation_valve_driver_over_current_threshold a set timer (governor_speed_rate_b) rises by the time increment up to the set time (it falls by the time decrement otherwise); "
   "a clear timer and the retry counter of cm848_updateExhaustGasRecirculationValveDriverOverCurrentRetryCounter decide retry or give-up, and fault 727 (mask 0x80 of diagnostic_status_bits) is set when the set time is reached without a retry and cleared with the retry.")
fn(0x18bc0, 'cm848_updateExhaustGasRecirculationValveDriverOverCurrentRetryCounter',
   "Second stage of the driver over-current check: raises the retry counter (governor_speed_rate_d, second word) by exhaust_gas_recirculation_valve_driver_over_current_fail_increment up to the maximum count while the over-current is flagged and no retry is active, "
   "lowers it by the pass decrement when it is flagged no more, resets it when the give-up enable word is set, and derives the retry-allowed flag and the clear-conditions flag (boost_correction_enable_flag).")
fn(0x18f1c, 'cm848_clearExhaustGasRecirculationValveDriverOverCurrentState',
   "Boot reset of the EGR valve driver over-current check: zeroes the set timer, the clear timer and the retry counter and the flags and clears fault 727 (mask 0x80) in the detected and registered fault words.")
fn(0x1a340, 'cm848_updateExhaustGasRecirculationValveHBridgeFaultRetryTimer',
   "Retry timer of the EGR valve H-bridge fault path: while the fault input (the argument) is present the count rises by exhaust_gas_recirculation_valve_h_bridge_fault_retry_increment up to the retry time, otherwise it falls by 1 to 0; a latch is set at the limit and cleared at 0, "
   "and exhaust_gas_recirculation_valve_h_bridge_fault_retry_trigger_flag is set when the input is absent and the latch is 0.")
fn(0x1a47c, 'cm848_updateExhaustGasRecirculationValveHBridgeFaultCounter',
   "Fault counter of the EGR valve H-bridge fault path: keeps a short history of the retry-active flag, raises the counter by exhaust_gas_recirculation_valve_h_bridge_fault_fail_increment up to the maximum count while the fault input is present, lowers it by the pass decrement when the input is absent "
   "and the retry has been active, sets exhaust_gas_recirculation_valve_h_bridge_fault_set_flag at the set threshold and the clear flag at 0, and recomputes the retry-active flag.")
fn(0x1a608, 'cm848_updateExhaustGasRecirculationValveHBridgeInrushRetryTimer',
   "Retry timer of the EGR valve H-bridge inrush fault path, same scheme as the fault retry timer, on the inrush input (bit 0x100 of supervisor_register_162_status): the count rises by exhaust_gas_recirculation_valve_h_bridge_inrush_retry_increment up to the inrush retry time, "
   "and exhaust_gas_recirculation_valve_h_bridge_inrush_retry_trigger_flag is set when the input is absent and the latch is 0.")
fn(0x1a754, 'cm848_updateExhaustGasRecirculationValveHBridgeInrushFaultCounter',
   "Fault counter of the EGR valve H-bridge inrush fault path (same scheme as the fault counter): raises the counter by the inrush fail increment up to its maximum count while the inrush input is present, lowers it otherwise, "
   "and sets fault 724 (mask 0x10 of diagnostic_status_bits) at the inrush fault set threshold (cleared when the flag at 0 is reached).")
fn(0x1a9a8, 'cm848_processExhaustGasRecirculationValveHBridgeFaults',
   "EGR valve driver (H-bridge) fault handler: reads and clears bits 0x10 / 0x40 / 0x100 of supervisor_register_162_status (the fourth input comes from bit 0 of switch_input_state_bits[2] instead when bit 0 of fuel_feature_control_flags is set), "
   "runs the retry timers and counters and sets or clears faults 720 to 723 (masks 1 / 2 / 4 / 8), the inrush fault 724 (mask 0x10) and the electrical fault 726 (mask 0x40) of diagnostic_status_bits, and writes exhaust_gas_recirculation_valve_driver_fault_pending_flag (diagnostic_mode_active_flag).")
fn(0x1ae2c, 'cm848_clearExhaustGasRecirculationValveHBridgeFaultState',
   "Boot-time reset of the EGR valve H-bridge fault path: clears masks 1 to 0x40 (except the control error bit 0x20) of the detected and registered fault words 720 to 735, the retry timers, the fault counters, the latches and the history flags.")
fn(0x1af94, 'cm848_updateExhaustGasRecirculationValveAutozeroConditions',
   "Autozero conditions of the EGR valve: counts passes (governor_speed_hysteresis_counter) while the position autozero fault 718 (mask 0x4000 of fault_detected_bits_704_to_719) and the enable-timeout timer are clear, sets exhaust_gas_recirculation_valve_ready_for_autozero_flag when the position is below "
   "the autozero tolerance (|sensor value| < engine_feature_activation_threshold_cal) or the count is reached, runs the autozero hold counter up to exhaust_gas_recirculation_valve_autozero_active_time and sets governor_speed_b_mode_select_flag (control state 3, holding duty "
   "exhaust_gas_recirculation_valve_autozero_drive_duty) while it runs.")
fn(0x1b120, 'cm848_updateExhaustGasRecirculationValveEnableAndDiagnosticConditions',
   "Enable and diagnostic conditions of the EGR valve loop: derives exhaust_gas_recirculation_valve_motor_ok_flag (diagnostic_clear_condition_flag) from the driver faults 726 / 727, the enable-timeout timer from the electrical fault and the position source, "
   "the position diagnostic override, a 200-pass counter on the position sensor and the control error, and sets or clears logical output request 67 (the PWM enable, with the previous driver fault pending flag clear).")
fn(0x1b35c, 'cm848_initializeExhaustGasRecirculationValveAutozeroConditions',
   "Boot init of the EGR valve autozero conditions: clears the ready-for-autozero flag, the hysteresis counter and the hold counter.")
fn(0x1b37c, 'cm848_runExhaustGasRecirculationValveFaultAndPositionControl',
   "Per-pass runner of the EGR valve module: cm848_updateExhaustGasRecirculationValveEnableAndDiagnosticConditions, then cm848_runExhaustGasRecirculationValvePositionControlLoop.")
# Bank 2 position chain
fn(0x506840, 'cm848_updateExhaustGasRecirculationValvePositionAutozero',
   "Autozero of the EGR valve position: copies sensor_channel75_value and its tolerance into the fault state filter block at 0x3fbcc6 (the learned zero offset), runs cm848_processFaultStateWithFilter on it, sets or clears fault 718 (mask 0x4000 of fault_detected_bits_704_to_719, e2m EGR_Valve_Autozero_Error), "
   "and computes exhaust_gas_recirculation_valve_position_autozeroed = sensor value - the learned offset (or the override value 0x406756 when the position autozero override word is non-zero).")
fn(0x506964, 'cm848_selectExhaustGasRecirculationValvePositionSource',
   "Selects exhaust_gas_recirculation_valve_position (boost_pressure_filtered): the autozeroed sensor value when the combined status is 0 (sensor fault status, bit 8 from fault 718, bit 0x20 from control error fault 725), otherwise sensor_channel75_default_value (9216 = 72 percent); "
   "sets exhaust_gas_recirculation_valve_position_source (boost_correction_block_flag: 0 sensor, 2 default) and exhaust_gas_recirculation_valve_closed_flag (boost_fuel_mode_active: position at or below the closed tolerance, or the closed hold flag set).")
fn(0x506a3c, 'cm848_updateExhaustGasRecirculationValvePosition',
   "Per-pass position chain of the EGR valve: cm848_updateExhaustGasRecirculationValveAutozeroActiveFlag, cm848_updateExhaustGasRecirculationValvePositionAutozero and cm848_selectExhaustGasRecirculationValvePositionSource in that order.")
fn(0x506a64, 'cm848_initializeExhaustGasRecirculationValvePosition',
   "Boot init of the EGR valve position chain: clears the autozero filter block and fault 718, starts the filter on the sensor value, copies the sensor value into exhaust_gas_recirculation_valve_position and sets exhaust_gas_recirculation_valve_position_source from the sensor fault status (0 or 1 sensor, 2 default).")
fn(0x5067e0, 'cm848_updateExhaustGasRecirculationValveAutozeroActiveFlag',
   "Sets exhaust_gas_recirculation_valve_autozero_active_flag (governor_speed_mode_b_active_flag) when the valve is in closed hold or the autozero holding drive is running, the autozero enable flag is set and the autozero logic enable word is non-zero; "
   "copies it to exhaust_gas_recirculation_valve_autozero_enabled_flag (0x40a670).")
fn(0x507214, 'cm848_evaluateExhaustGasRecirculationValvePositionControlDiagnosticConditions',
   "Enable flag of the EGR valve position control diagnostic (exhaust_gas_recirculation_valve_control_diagnostic_enable_flag, governor_speed_stability_conditions_flag): 1 while the control error bit 0x20 of diagnostic_status_bits is set, otherwise only in closed-loop state 0 with "
   "fault 718 clear, the motor ok flag set, the position sensor fault status 0, the position command within the steady-state deviation threshold of its filtered value and the PID output not strongly driving against the error.")
fn(0x507394, 'cm848_updateExhaustGasRecirculationValvePositionControlFaultCounter',
   "Fault counter of the EGR valve position control diagnostic: after exhaust_gas_recirculation_valve_control_diagnostic_enable_time passes of stable conditions it raises the counter by the time increment up to the fail threshold while the position deviates from the command and lowers it by the time decrement while it does not "
   "(held at 0 when the control fault counter clear word is set); sets control error fault 725 (mask 0x20 of diagnostic_status_bits) at the fail threshold and clears it at or below the pass threshold.")
fn(0x507548, 'cm848_runExhaustGasRecirculationValvePositionControlDiagnostic',
   "Per-pass EGR valve position control diagnostic: flags a deviation of the autozeroed position from the final position command above exhaust_gas_recirculation_valve_control_error_threshold, then runs the diagnostic condition evaluation and the fault counter update.")
fn(0x5075b8, 'cm848_initializeExhaustGasRecirculationValvePositionControlDiagnostic',
   "Boot init of the EGR valve position control diagnostic: clears the command filter, the fault counter, the stable flags and the sample counter and clears control error fault 725 (mask 0x20) in the detected and registered fault words.")
fn(0x507644, 'cm848_countExhaustGasRecirculationValveClosings',
   "Adds 1 to the lifetime closing cycle count (DAT_003fdfb4, e2m T_EGA_Cycle_Counter) on each rising edge of exhaust_gas_recirculation_valve_closed_hold_flag.")
fn(0x507684, 'cm848_initializeExhaustGasRecirculationValveClosedHoldPreviousFlag',
   "Boot init: sets the previous closed hold flag of the closing counter to 1 so that the first pass after reset does not count a closing.")
# shared words: battery voltage and coolant temperature
fn(0x107ec, 'cm848_selectBatteryVoltage',
   "Selects battery_voltage_selected: the battery voltage sensor value (sensor channel 4: the battery voltage tables, faults 66 / 67 = P0562 / P0563), or its default value when the sensor fault status is 2; "
   "sets battery_voltage_source to 2 in that case and 0 otherwise. Read by the EGR valve and VGT valve duty compensation and the motor current estimates.")
fn(0x1083c, 'cm848_updateBatteryVoltageSource',
   "Sets battery_voltage_source from the battery voltage sensor fault status: 0 for status 0 or 1, 2 for status 2; the value itself is selected by cm848_selectBatteryVoltage.")
fn(0x505b84, 'cm848_selectCoolantTemperature',
   "Selects coolant_temperature_selected (1/64 degree F): the generic sensor channel 2 value (coolant temperature tables, faults 16 / 17 = P0118 / P0117) or its default when bit 1 of its fault status is set; sets coolant_temperature_source to 2 in that case and 0 otherwise.")
fn(0x505bd8, 'cm848_initializeCoolantTemperatureSource',
   "Boot init of the coolant temperature source: sets coolant_temperature_source from the fault status (0 or 1 sensor, 2 default) and loads coolant_temperature_selected from the sensor value.")

# ---------- global plan ----------
G = []   # (address, new, code_text, e2m_text, kind)
def gl(addr, new, code, e2m=None):
    G.append((addr, new, code, e2m))

FN = {a: v[0] for a, v in F.items()}
fname = {}
for a, v in F.items():
    fname[a] = v[0]
# helper to name users of a word from the twin scan
USERS = json.load(open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w7/users.json'))
def users_text(old):
    us = USERS.get(old, [])
    names = []
    for u in us:
        a = int(u, 16)
        if a in fname:
            names.append(fname[a])
        elif a in frows:
            names.append(frows[a][1])
    names = sorted(set(names))
    if not names:
        return ''
    return 'users: ' + ', '.join(names[:5]) + ('' if len(names) <= 5 else ' and %d more' % (len(names) - 5)) + '. '

# anchors for the e2m offset statement
ANCH = {
    0x0117AB00: 0x4067ea, 0x0117AE00: 0x4067d8, 0x0117BF00: 0x4067b0, 0x0117CD00: 0x406834,
    0x01190800: 0x4067a0, 0x0117C000: 0x40684c, 0x0117AC00: 0x40a6c2, 0x0117A900: 0x40a69e,
    0x0117AA00: 0x40a70a, 0x0117AF00: 0x40a6b4, 0x0117C200: 0x40a6fc, 0x01190900: 0x40a698,
    0x01179C00: 0x40674e, 0x01179D00: 0x40a664,
}
def e2m_text(param):
    ad = e2m[param][0]
    base = ad & ~0xFF
    return f"{param} (0x{ad:08x}) is +0x{ad - base:02x} of the block that anchors 0x{ANCH[base]:x}."

# ---- list: (code address, e2m param, new suffix, extra code text)
SPEC = [
 # main calibration block (0x4067ea)
 (0x4067ec, 'C_EGA_Cmd_Override_Value', 'position_command_override_value', 'single reader of the position command stage: the command when bit 0 of the user override flags is set (0 in the dump)'),
 (0x4067ee, 'C_EGA_D_Gain_Normal', 'derivative_gain_normal', 'derivative gain of the normal gain set; it multiplies the filtered error change (the code calls it a p gain)'),
 (0x4067f0, 'C_EGA_D_Gain_Zero', 'derivative_gain_closed', 'derivative gain used while the position command is 0 (the valve is closing; e2m calls that the zero set)'),
 (0x4067f2, 'C_EGA_Der_Dtime_Cnst', 'derivative_filter_coefficient', 'coefficient of the first-order filter on the error (its address is stored in j1939_handler_param_table_pointer); typed byte but the filter reads a word'),
 (0x4067f4, 'C_EGA_Der_Noise_Band', 'derivative_noise_band', 'the derivative term is 0 while |error change| is below it'),
 (0x4067f6, 'C_EGA_I_Gain_Normal', 'integral_gain_normal', 'integral gain of the normal set; it multiplies the error into the integral accumulator (the code calls it a p gain)'),
 (0x4067f8, 'C_EGA_I_Gain_Zero', 'integral_gain_closed', 'integral gain of the zero-command set'),
 (0x4067fa, 'C_EGA_I_Term_LLim_Normal', 'integral_term_lower_limit_normal', 'lower limit of the integral accumulator, normal set'),
 (0x4067fc, 'C_EGA_I_Term_LLim_Zero', 'integral_term_lower_limit_closed', 'lower limit of the integral accumulator, zero-command set'),
 (0x4067fe, 'C_EGA_I_Term_ULim', 'integral_term_upper_limit', 'upper limit of the integral accumulator'),
 (0x406800, 'C_EGA_Load_Offset_Normal', 'load_offset_normal', 'feedforward offset added to the PID sum, normal set'),
 (0x406802, 'C_EGA_Load_Offset_Zero', 'load_offset_closed', 'feedforward offset, zero-command set'),
 (0x406804, 'C_EGA_Motor_Direction_Reversal', 'motor_direction_reversal', 'compared with 1 in the output stage to invert the direction request (logical output 68)'),
 (0x406806, 'C_EGA_P_Gain_Normal', 'proportional_gain_normal', 'proportional gain of the normal set; it multiplies the position error directly (>> 7; the code calls it a d gain)'),
 (0x406808, 'C_EGA_P_Gain_Zero', 'proportional_gain_closed', 'proportional gain of the zero-command set'),
 (0x40680a, 'C_EGA_Prefilter_Cnst_Normal', 'position_reference_filter_coefficient_normal', 'coefficient of the position reference first-order filter, normal set (the code calls it an integral limit b)'),
 (0x40680c, 'C_EGA_Prefilter_Cnst_Zero', 'position_reference_filter_coefficient_closed', 'coefficient of the position reference filter, zero-command set'),
 (0x40680e, 'C_EGA_PWM_LLim', 'drive_duty_lower_limit', 'lower duty limit; the working limit is the larger of it and the negated compensated limit'),
 (0x406810, 'C_EGA_PWM_Override_LLim', 'drive_duty_override_lower_limit', 'lower bound of the duty in control states 1 to 4'),
 (0x406812, 'C_EGA_PWM_Override_Value', 'drive_duty_override_value', 'duty of control state 2 (user duty override)'),
 (0x406814, 'C_EGA_PWM_Override_ULim', 'drive_duty_override_upper_limit', 'upper bound of the duty in control states 1 to 4'),
 (0x406816, 'C_EGA_PWM_Polarity_Reversal', 'drive_duty_polarity_reversal', 'non-zero: the output stage sends 12800 minus the magnitude'),
 (0x406818, 'C_EGA_PWM_ULim', 'drive_duty_upper_limit', 'upper duty limit; the working upper limit is the smaller of it and the compensated limit (the code calls it a range lower limit)'),
 (0x40681a, 'C_EGA_SS_Error_Band', 'steady_state_error_band', 'the integral accumulates only while |position error| is above it'),
 (0x40681c, 'C_EGA_Stage_Cmd_Thd', 'closed_stage_command_threshold', 'staged closing runs while the command is below it'),
 (0x40681e, 'C_EGA_Stage_Position_Thd', 'closed_stage_position_threshold', 'staged closing ramps only while the position is below it'),
 (0x406820, 'C_EGA_Stage_Ramp_Rate', 'closed_stage_ramp_rate', 'rate added to the staged command per pass (a negative value: the command ramps down)'),
 (0x406822, 'C_EGA_Zero_Hold_PWM', 'closed_hold_drive_duty', 'duty of control state 1 (closed hold)'),
 (0x406824, 'C_EGA_Zero_Position_Thd', 'closed_hold_position_threshold', 'position at or below which a zero command holds the valve closed'),
 (0x406826, 'EGA_PWM_Abs_PWM_Period_Cal', 'motor_pwm_period', 'passed as the PWM period to the output channel record of entry 39 by the loop init'),
 (0x406828, 'C_EGA_Dir_Chg_PWM_Delay_Enable', 'direction_change_zero_duty_enable', 'compared with 1: the duty is 0 for one pass after a direction change'),
 (0x40682a, 'C_EGA_PWM_Zero_Thd', 'drive_duty_zero_threshold', 'the PWM duty is 0 below it'),
 (0x40682c, 'C_EGA_Max_Time_To_Zero_Hold', 'closed_hold_maximum_time', 'pass count a 0 command must last before the closed hold flag is set'),
 (0x40682e, 'C_EGA_Compensated_PWM_Lim', 'drive_duty_limit_normal', 'duty limit before the battery compensation (limited to 12800)'),
 (0x406830, 'C_EGA_Friction_Avoidance_Decrt', 'friction_avoidance_decrement', 'added to the PID sum (sign of the PID output) while the motor current is at or above the steady-state limit'),
 (0x406832, 'C_EGA_Max_SS_Current', 'steady_state_current_maximum', 'motor current at or above which the friction avoidance term is added'),
 # driver over-current calibration (0x4067a0)
 (0x4067a0, 'C_EGA_Driver_OC_Clear_Time', 'driver_over_current_clear_time', 'clear timer limit of the driver over-current retry'),
 (0x4067a2, 'C_EGA_Driver_OC_Fail_Incrt', 'driver_over_current_fail_increment', 'retry counter increment per flagged pass'),
 (0x4067a4, 'C_EGA_Driver_OC_Max_Count', 'driver_over_current_maximum_count', 'retry counter limit'),
 (0x4067a6, 'C_EGA_Driver_OC_Pass_Decrt', 'driver_over_current_pass_decrement', 'retry counter decrement'),
 (0x4067a8, 'C_EGA_Driver_OC_Set_Time', 'driver_over_current_set_time', 'set timer limit: the over-current is flagged when the set timer reaches it'),
 (0x4067aa, 'C_EGA_Driver_OC_Threshold', 'driver_over_current_threshold', 'motor current threshold of the over-current check'),
 (0x4067ac, 'C_EGA_Driver_OC_Time_Decrt', 'driver_over_current_time_decrement', 'set timer decrement while the current is below the threshold'),
 (0x4067ae, 'C_EGA_Driver_OC_Time_Incrt', 'driver_over_current_time_increment', 'set timer increment while the current is at or above the threshold'),
 # thermal / current calibration (0x4067b0)
 (0x4067b6, 'C_EGA_Housing_Tmptr_Offset', 'housing_temperature_offset', 'added to the coolant temperature to form the ambient temperature of the motor model'),
 (0x4067b8, 'C_EGA_Max_Current', 'motor_current_maximum', 'upper clamp of the estimated motor current'),
 (0x4067ba, 'C_EGA_PWM_Offset', 'drive_duty_offset', 'added to the duty magnitude before the voltage scaling of the current estimate'),
 (0x4067bc, 'C_EGA_Speed_EMF_Factor', 'speed_back_electromotive_force_factor', 'multiplies the position change into the back electromotive force'),
 (0x4067c0, 'C_EGA_Tmptr_High_Threshold', 'motor_temperature_high_threshold', 'winding temperature at or above which fault 728 is set'),
 (0x4067c2, 'C_EGA_Tmptr_Low_Threshold', 'motor_temperature_low_threshold', 'winding temperature at or below which fault 728 is cleared'),
 (0x4067c4, 'C_EGA_Tmptr_Warning_Threshold', 'motor_temperature_warning_threshold', 'winding temperature at or above which the warning flag is set'),
 (0x4067c6, 'C_EGA_Normalized_Resistance', 'normalized_resistance', 'multiplies the mean-squared current (>> 11) into the winding temperature rise'),
 (0x4067c8, 'C_EGA_Ref_Resistance', 'reference_resistance', 'circuit resistance at 0 degrees (the code calls it boost_load_calc_offset_cal)'),
 (0x4067ca, 'C_EGA_Resistance_Tmptr_Coeff', 'resistance_temperature_coefficient', 'resistance increase per winding temperature count (>> 10)'),
 (0x4067d0, 'C_EGA_Tmptr_Fraction', 'motor_temperature_fraction', 'fraction of the winding-to-ambient difference that heats the iron core (>> 10)'),
 (0x4067d2, 'C_EGA_Coolant_Tmptr_Default', 'coolant_temperature_default', 'coolant temperature substituted when the coolant source is not the sensor, and the limit under which the over-temperature timer counts'),
 (0x4067d4, 'C_EGA_Delta_Press_Threshold', 'over_temperature_delta_pressure_threshold', 'the over-temperature timer counts only while the filtered boost_fuel_correction is below it (e2m: valve over-temperature is not logged above this delta pressure)'),
 (0x4067d6, 'C_EGA_Inhibit_Over_Temp_Time', 'over_temperature_inhibit_time', 'pass count of the over-temperature timer before fault 795 is set'),
 # autozero calibration
 (0x40684c, 'C_EGA_Autozero_Active_Time', 'autozero_active_time', 'limit of the autozero hold counter (cold_start_fuel_confirm_counter)'),
 (0x40684e, 'C_EGA_Autozero_PWM_Value', 'autozero_drive_duty', 'holding duty of control state 3 (loaded into governor_mode3_speed_param)'),
 (0x406850, 'C_EGA_Autozero_Retry_Time', 'autozero_retry_time', 'limit of the hysteresis counter that gates the autozero conditions'),
 # H-bridge calibration (0x406834)
 (0x406834, 'C_EGA_HB1_Retry_Time', 'h_bridge_fault_retry_time', 'limit of the fault retry timer'),
 (0x406836, 'C_EGA_Fault_HB1_Max_Count', 'h_bridge_fault_maximum_count', 'limit of the fault counter'),
 (0x406838, 'C_EGA_Fault_HB1_Pass_Decrt', 'h_bridge_fault_pass_decrement', 'fault counter decrement'),
 (0x40683a, 'C_EGA_HB1_Inrush_Retry_Time', 'h_bridge_inrush_retry_time', 'limit of the inrush retry timer'),
 (0x40683c, 'C_EGA_HB1_OC_Max_Count', 'h_bridge_inrush_fault_maximum_count', 'limit of the inrush fault counter'),
 (0x40683e, 'C_EGA_HB1_OC_Pass_Decrt', 'h_bridge_inrush_fault_pass_decrement', 'inrush fault counter decrement'),
 (0x406840, 'C_EGA_Fault_HB1_Fail_Incrt', 'h_bridge_fault_fail_increment', 'fault counter increment'),
 (0x406842, 'C_EGA_HB1_OC_Fail_Incrt', 'h_bridge_inrush_fault_fail_increment', 'inrush fault counter increment'),
 (0x406844, 'C_EGA_HB1_Fault_Set', 'h_bridge_fault_set_threshold', 'fault counter value at which the fault set flag is set'),
 (0x406846, 'C_EGA_HB1_Inrush_Retry_Incrt', 'h_bridge_inrush_retry_increment', 'inrush retry timer increment'),
 (0x406848, 'C_EGA_HB1_OC_Fault_Set', 'h_bridge_inrush_fault_set_threshold', 'inrush counter value at which fault 724 is set'),
 (0x40684a, 'C_EGA_HB1_Retry_Increment', 'h_bridge_fault_retry_increment', 'fault retry timer increment'),
 # diagnostic calibration rows that exist
 (0x4067de, 'C_EGA_Control_Fault_Time_Incrt', 'control_fault_time_increment', 'fault counter increment of the position control diagnostic'),
 (0x4067e0, 'C_EGA_Control_Fault_Time_Decrt', 'control_fault_time_decrement', 'fault counter decrement of the position control diagnostic'),
 (0x4067e4, 'C_EGA_Fail_Time_Thd', 'control_fault_time_fail_threshold', 'fault counter value at which fault 725 is set'),
 # state block 0x40a6c2
 (0x40a6c2, 'EGA_PWM_Limited', 'drive_duty_limited', 'signed duty after the output stage (the clamped duty, or 0 when the duty is forced to 0 or the output is disabled); copied to fuel_timing_error_working for the next pass of the current estimate; dump 0'),
 (0x40a6c4, 'EGA_Position_Error', 'position_error', 'filtered reference minus position (boost_pressure_target_ema - boost_pressure_filtered)'),
 (0x40a6c6, 'EGA_Position_Cmd_Final', 'position_command_final', 'staged closing command; the loop reference'),
 (0x40a6c8, 'EGA_Zero_Hold_Status', 'closed_hold_flag', 'set by the closed-hold check; selects control state 1 and forces exhaust_gas_recirculation_valve_closed_flag; the closing counter counts its rising edges'),
 (0x40a6ca, 'EGA_Control_State', 'control_state', '0 closed loop, 1 closed hold, 2 user duty override, 3 diagnostic (autozero) drive, 4 disabled (e2m lists the same five states); dump 3'),
 (0x40a6cc, 'EGA_D_Gain', 'derivative_gain', 'the gain that multiplies the filtered error change (selected by the gain set)'),
 (0x40a6ce, 'EGA_D_Term', 'derivative_term', 'derivative gain x error change >> 3, limited to +-32767, 0 inside the noise band'),
 (0x40a6d0, 'EGA_Error_Derivative', 'position_error_derivative', 'change of the filtered position error between passes'),
 (0x40a6d2, 'EGA_Error_I_Term_Input', 'integral_error_input', 'the position error when it is outside the steady-state band and the integral is enabled, else 0'),
 (0x40a6d4, 'EGA_FF_Term', 'feedforward_term', 'load offset (bias) of the active gain set'),
 (0x40a6d6, 'EGA_Governor_PWM', 'pid_duty', 'PID result, +-32767, 12800 = 100 percent'),
 (0x40a6d8, 'EGA_I_Gain', 'integral_gain', 'integral gain of the active set'),
 (0x40a6da, 'EGA_I_Term', 'integral_term', 'integral accumulator >> 14'),
 (0x40a6dc, 'EGA_I_Term_LLim', 'integral_term_lower_limit', 'integral lower limit of the active set'),
 (0x40a6de, 'EGA_P_Gain', 'proportional_gain', 'the gain that multiplies the position error (selected by the gain set)'),
 (0x40a6e0, 'EGA_P_Term', 'proportional_term', 'proportional gain x position error >> 7, limited to +-32767'),
 (0x40a6e2, 'EGA_Position_Cmd', 'position_command', 'the position command of the EGR valve loop: override, 0, or the EGR valve command of the EGR / assist controller (throttle_fuel_demand_limit), capped at 12800; dump 0'),
 (0x40a6e4, 'EGA_Position_Ref_Filtered', 'position_reference_filtered', 'first-order filtered reference (coefficient pointer is governor_speed_integral_limit_working); dump 9216'),
 (0x40a6e6, 'EGA_Position_Ref_Unfiltered', 'position_reference_unfiltered', 'the staged command in control states 0 and 1, the measured position otherwise; dump 9216'),
 (0x40a6e8, 'EGA_Prefilter_Cnst', 'position_reference_filter_coefficient', 'reference filter coefficient of the active set'),
 (0x40a6ea, 'EGA_PWM_Battery_Compensated', 'drive_duty_battery_compensated', 'selected duty x battery_voltage_nominal / battery_voltage_selected, limited to +-32767 (also copied to governor_speed_range_output before the limits)'),
 (0x40a6ec, 'EGA_PWM_Selected', 'drive_duty_selected', 'duty picked by the control state (PID, hold, override, autozero or 0); dump 0'),
 (0x40a6ee, 'EGA_PWM_Clamped', 'drive_duty_clamped', 'signed compensated duty after the lower and upper limits; its sign is the direction request'),
 (0x40a6f0, 'EGA_PWM_LLim', 'drive_duty_lower_limit_working', 'working lower duty limit (lower limit or the negated compensated limit)'),
 (0x40a6f2, 'EGA_PWM_ULim', 'drive_duty_upper_limit_working', 'working upper duty limit (upper limit or the compensated limit; the code calls it a range minimum)'),
 (0x40a6f4, 'EGA_PWM_Direction_Change', 'direction_change_flag', 'set when the direction request differs from the previous pass'),
 (0x40a6f6, 'EGA_PWM_Valid_Abs_Duty_Cycle', 'drive_duty_magnitude', '|clamped duty| x 2 (12800 minus it x 2 with the polarity reversal): the PWM duty, 25600 = 100 percent'),
 (0x40a6f8, 'EGA_PWM_Within_Driver_Deadband', 'drive_duty_within_dead_band_flag', 'set when the magnitude is below the zero threshold'),
 (0x40a6fa, 'EGA_Friction_Avoidance_Decrt', 'friction_avoidance_term', 'friction avoidance addend (the calibrated decrement with the sign of the PID output) while the current is at or above the steady-state limit'),
 # thermal / current state block 0x40a69e
 (0x40a69e, 'EGA_Temperature_Warning', 'motor_temperature_warning_flag', 'set when the winding temperature reaches the warning threshold'),
 (0x40a6a0, 'EGA_Mean_Squared_Current', 'motor_current', 'the estimated motor current, 0.000976562 A per count; dump 0'),
 (0x40a6a2, 'EGA_Mean_Squared_Current', 'motor_mean_squared_current', 'EMA of current x current >> 13'),
 (0x40a6a4, 'EGA_Temperature', 'motor_winding_temperature', 'winding temperature, 1/8 degree F: EMA of the filter input; compared with the high / low / warning thresholds'),
 (0x40a6a6, 'EGA_Ambient_Temperature', 'motor_ambient_temperature', 'coolant temperature (or its default) plus the housing offset'),
 (0x40a6a8, 'EGA_Circuit_Resistance', 'circuit_resistance', 'reference resistance + winding temperature x coefficient >> 10 (at least 1); divides the voltage across the resistance'),
 (0x40a6aa, 'EGA_Temperature_1', 'motor_iron_core_temperature', 'iron core temperature, 1/64 degree F: EMA of the iron core filter input'),
 (0x40a6ac, 'EGA_Tmptr_1_Fil_Input', 'motor_iron_core_temperature_filter_input', 'ambient + (winding x 8 - ambient) x fraction >> 10'),
 (0x40a6ae, 'EGA_Tmptr_Fil_Input', 'motor_winding_temperature_filter_input', 'mean-squared current x normalized resistance / 2048 + iron core temperature / 8'),
 (0x40a6b0, 'EGA_Back_EMF', 'back_electromotive_force', 'position change x speed factor / 2048 (sign from the previous direction)'),
 (0x40a6b2, 'EGA_Coolant_Temperature', 'coolant_temperature', 'coolant_temperature_selected, or the coolant default when the coolant source is not the sensor (code name fuel_demand_boost_input_limited)'),
 # flag block 0x40a70a
 (0x40a70e, 'EGA_Motor_OK', 'motor_ok_flag', 'set when the driver is not pending a fault and faults 726 / 727 are clear'),
 (0x40a710, 'EGA_Pos_Diagnostic_Override', 'position_diagnostic_override_flag', 'forces the position command to 0 (set from the driver fault flag or the autozero hold flag)'),
 (0x40a712, 'EGA_PWM_Diagnostic_Override', 'drive_diagnostic_override_flag', 'selects control state 3 (diagnostic drive); set while the autozero hold counter runs'),
 (0x40a714, 'EGA_PWM_Diagnostic_Override_Val', 'drive_diagnostic_override_value', 'copy of the autozero drive duty used as the duty in control state 3'),
 # H-bridge state flags
 (0x40a6fc, 'EGA_HB1_Fault_Clear', 'h_bridge_fault_clear_flag', 'set when the fault counter is at 0'),
 (0x40a6fe, 'EGA_Fault_HB1_Retry', 'h_bridge_fault_retry_trigger_flag', 'retry trigger of the fault retry timer'),
 (0x40a700, 'EGA_Fault_HB1_Inrush_Retry', 'h_bridge_inrush_retry_trigger_flag', 'retry trigger of the inrush retry timer'),
 (0x40a702, 'EGA_HB1_Inrush_Fault_Clear', 'h_bridge_inrush_fault_clear_flag', 'set when the inrush fault counter is at 0'),
 (0x40a706, 'EGA_Electrical_Error', 'driver_fault_pending_flag', '1 when either retry-active flag is 0 (a driver fault without retry)'),
 (0x40a708, 'EGA_Fault_HB1_Fault_Set', 'h_bridge_fault_set_flag', 'set when the fault counter is at or above the set threshold'),
]
for a, p, suf, code in SPEC:
    gl(a, V(suf), code, e2m_text(p))
# the two words typed dword
gl(0x40a70a, V('autozero_enable_flag'), 'low word is 1 when the ready-for-autozero flag and logical output request 67 are both set (dump 1); dword row, only the low word is used', e2m_text('EGA_Autozero_Enable'))
gl(0x40a716, V('ready_for_autozero_flag'), 'low word is set by cm848_updateExhaustGasRecirculationValveAutozeroConditions when the position is below the autozero tolerance or the hysteresis count is reached (dump 1); dword row, only the low word is used', e2m_text('EGA_Ready_For_Autozero'))

# retry / over-current / timers in RAM state (time-shared)
SPEC2 = [
 (0x3fa7a4, 'h_bridge_fault_retry_timer', 'count word of the fault retry timer: + the retry increment up to the retry time while the fault input is present, -1 to 0 otherwise'),
 (0x3fa7b6, 'h_bridge_fault_retry_latch_flag', 'latch of the fault retry timer: 1 at the limit, 0 at count 0'),
 (0x3fa7b2, 'h_bridge_fault_retry_timer_at_limit_flag', 'written by the fault retry timer when the count is at its limit; no reader found'),
 (0x3fa7b4, 'h_bridge_fault_retry_timer_zero_flag', 'written by the fault retry timer when the count is 0; no reader found'),
 (0x3fa7a6, 'h_bridge_fault_counter', 'fault counter of the H-bridge fault path (up by the fail increment, down by the pass decrement)'),
 (0x3fa7a8, 'h_bridge_inrush_retry_timer', 'count word of the inrush retry timer'),
 (0x3fa7aa, 'h_bridge_inrush_fault_counter', 'counter of the inrush fault path; fault 724 at the set threshold'),
 (0x3fa7ac, 'h_bridge_inrush_input_flag', 'bit 0x100 of supervisor_register_162_status as read each pass by the H-bridge fault handler: the inrush input of the inrush timer'),
 (0x3fa746, 'driver_over_current_retry_active_previous_flag', 'previous value of the clear-conditions flag (history of the driver over-current retry)'),
 (0x3fa744, 'driver_over_current_retry_active_flag', 'copy of the clear-conditions flag (boost_correction_enable_flag) of the previous pass'),
 (0x3fa74c, 'direction_request_previous_flag', 'logical output request 68 (mask 0x10 of logical_output_request_bits_64_to_71) of the previous pass: sign of the back electromotive force'),
 (0x3fa74a, 'position_sensor_value_previous', 'sensor_channel75_value of the previous pass (position change into the back electromotive force)'),
 (0x3fa74e, 'drive_duty_limited_previous', 'exhaust_gas_recirculation_valve_drive_duty_limited of the previous pass (the duty the current estimate uses)'),
 (0x3fa770, 'back_electromotive_force_working', 'position change x speed factor / 2048 before the sign, limited to +-32000 (dword)'),
 (0x3fa77a, 'over_temperature_inhibit_counter', 'counter of the valve over-temperature timer: up to the inhibit time while the conditions hold, 0 otherwise'),
 (0x3fa774, 'coolant_temperature_at_default_flag', 'set when the coolant temperature is at or above exhaust_gas_recirculation_valve_coolant_temperature_default'),
 (0x3fa784, 'position_error_filtered_previous', 'the filtered position error of the previous pass (derivative)'),
 (0x3fa78e, 'control_state_previous', 'control state of the previous pass; the integral is reset or held on a state change'),
 (0x3fa786, 'position_reference_filter_state', 'ema_filter_state_t of the position reference filter (coefficient pointer governor_speed_integral_limit_working)'),
 (0x3fa780, 'integral_accumulator', 'integral accumulator (dword): limited to the integral limits << 14; the integral term is its value >> 14'),
]
for a, suf, code in SPEC2:
    gl(a, V(suf), code, None)

# shared words (battery voltage, coolant temperature)
SHARED = [
 (0x4067ea, 'battery_voltage_nominal', 'nominal battery voltage in 1/16 V (224 = 14.0 V in the dump): the numerator of the battery compensation of the VGT and EGR valve duties; the address is outside the EEPROM mirror, so no _cal. e2m: C_Battery_Voltage_Nominal (0x0117AB00) is +0x00 of the EGR actuator calibration block.'),
 (0x40a34c, 'battery_voltage_selected', 'battery voltage in 1/16 V (192 = 12.0 V in the dump): cm848_selectBatteryVoltage copies the battery sensor value (sensor channel 4: battery_voltage_linearization tables, fault bits 67 / 66 = P0563 / P0562) or its default when the sensor fault status is 2; read by the EGR valve and VGT valve duty compensation and the motor current estimates. Settles the wave 6 uncertain row.'),
 (0x40bda2, 'battery_voltage_sensor_value', 'value output of sensor channel 4 (cm848_sensorChannel2_init: battery_voltage_linearization_axis / _values, fault bits 0x43 / 0x42 = faults 67 / 66 = P0563 / P0562); only reader cm848_selectBatteryVoltage; dump 192.'),
 (0x40bda4, 'battery_voltage_sensor_default_value', 'default value output of sensor channel 4; only reader cm848_selectBatteryVoltage.'),
 (0x40a34e, 'battery_voltage_source', '0 or 2 written by cm848_selectBatteryVoltage / cm848_updateBatteryVoltageSource from the battery sensor fault status (0 sensor, 2 default); no reader found.'),
 (0x40a61c, 'coolant_temperature_selected', 'engine coolant temperature in 1/64 degree F: cm848_selectCoolantTemperature copies the generic sensor channel 2 value (coolant_temperature_linearization tables, fault bits 0x10 / 0x11 = faults 16 / 17 = P0118 / P0117) or its default when bit 1 of the fault status is set. Readers use it as a coolant temperature: the combustion chi coolant axis (combustion_protective_chi_by_coolant_temperature_axis), combustion_egr_off_coolant_temperature_limit, the cold start axes, the VGT and EGR motor models. Settles the wave 6 uncertain row.'),
 (0x40a61e, 'coolant_temperature_source', '0 or 2 written only by cm848_selectCoolantTemperature / cm848_initializeCoolantTemperatureSource from sensor_generic_fault_status (0 sensor, 2 default substituted); read as no coolant sensor fault by the EGR and VGT valve over-temperature timers and the EGR delta pressure enable check.'),
 (0x40bd88, 'coolant_temperature_sensor_value', 'value output of the generic sensor channel 2 (coolant temperature tables, faults 16 / 17); only reader cm848_selectCoolantTemperature / cm848_initializeCoolantTemperatureSource.'),
 (0x40bdae, 'coolant_temperature_sensor_default_value', 'default value output of the generic sensor channel 2; only reader cm848_selectCoolantTemperature.'),
 (0x40be28, 'coolant_temperature_sensor_fault_status', 'fault status of the generic sensor channel 2 (coolant temperature tables, faults 16 / 17): 0 / 1 / 2.'),
]
for a, new, code in SHARED:
    gl(a, new, code, None)

# position / autozero chain (Bank 2) and EEPROM words
POS = [
 (0x40a666, 'position_autozeroed', 'sensor value minus the learned zero offset (or the override value): written by cm848_updateExhaustGasRecirculationValvePositionAutozero, read by the position source selection and the control diagnostic; dump 0. e2m: EGR_Position_AP (0x01179D02) is +0x02 of the block that anchors 0x40a664.'),
 (0x40a668, 'closed_flag', '1 when the position is at or below the closed tolerance (0x406758) or the closed hold flag is set (cm848_selectExhaustGasRecirculationValvePositionSource); readers: the EGR fraction limiter cm848_calculateTurboBlendOutput (command passed only while the valve is not closed or boost_fuel_correction is below boost_fuel_correction_threshold), cm848_limitMassChargeFlowReference (density limit while it is set) and the delta pressure enable check; dump 1. e2m: EGR_Valve_Is_Closed (0x01179D04) is +0x04 of the block that anchors 0x40a664.'),
 (0x40a66a, 'position', 'the valve position of the loop: the autozeroed sensor value (sensor channel 75, 0.5-4.5 V, faults 642 / 643) or, with a sensor fault, fault 718 or the control error, sensor_channel75_default_value (9216 = 72 percent; the dump holds it); 12800 = 100 percent; read by the PID error, the staging, the synthetic boost model and the EGR trims. e2m: EGR_Position (0x01179D06) is +0x06 of the block that anchors 0x40a664.'),
 (0x40a66c, 'position_source', '0 when the position is the autozeroed sensor value, 2 when the default is used (dump 2 because fault 718 is set); written by the source selection and the init. e2m: EGR_Position_Source (0x01179D08, 0 = primary, 1 = backup, 2 = default) is +0x08 of the block that anchors 0x40a664.'),
 (0x40a66e, 'position_status', 'combined status of the position source: the sensor fault status | 8 (fault 718) | 0x20 (control error 725); 0 selects the sensor value. e2m: EGR_Position_State (0x01179D0A) is +0x0a of the block that anchors 0x40a664.'),
 (0x3fbccc, 'autozero_active_flag', 'closed hold or autozero drive running, with the autozero enable flag and the logic enable word set; copied to 0x40a670 and to DAT_0040a670. e2m: EGR_Valve_Autozero_Enabled (0x01179D0C) is +0x0c of the block that anchors 0x40a664.'),
 (0x40bd96, None, None),
]
for a, suf, code in POS[:-1]:
    gl(a, V(suf), code, None)

# EEPROM-mirror words
EEP = [
 (0x3fd7f8, 'user_override_flags_cal', 'bit 0 = position command override (cm848_updateExhaustGasRecirculationValvePositionCommandAndControlState), bit 1 = fixed override duty, control state 2; dump 0. e2m: T_EGA_Cmd_User_Override / T_EGA_PWM_User_Override (0x0117AD00 masks 1 / 2) are bits 0 / 1 of the word that anchors 0x3fd7f8. EEPROM mirror, so _cal.'),
 (0x3fd7fe, 'driver_over_current_give_up_enable_cal', 'read by cm848_updateExhaustGasRecirculationValveDriverOverCurrentRetryCounter: when non-zero the retry counter is reset (give up). e2m: T_EGA_Enable_Driver_OC_Give_Up (0x01183D02, resets counter / timer / latch of the over-current logic) is the word before 0x3fd800 (T_EGA_Enable_HB1_Give_Up, 0x01183D04). EEPROM mirror, so _cal. (was governor_speed_rate_d_init_flag)'),
 (0x3fd800, 'h_bridge_fault_give_up_enable_cal', 'read by the H-bridge fault counter and the inrush fault counter (0x1a47c / 0x1a754): the retry-active flag is dropped at the maximum count only when it is non-zero (give up). e2m: T_EGA_Enable_HB1_Give_Up (0x01183D04, resets counter / timer / latch of the electrical fault logic) is the word after T_EGA_Enable_Driver_OC_Give_Up. (was cold_start_speed_at_limit_flag) EEPROM mirror, so _cal.'),
]
for a, suf, code in EEP:
    gl(a, V(suf), code, None)
gl(0x3fdce2, V('motor_pwm_output_channel_cal'), 'EEPROM 0x860 = output channel assignment table entry 39: the record of the PWM output of the EGR valve motor (0 = no output / 1-50; 0 in this calibration). Enabled and set up by cm848_initializeExhaustGasRecirculationValvePositionControlLoop and driven by cm848_outputExhaustGasRecirculationValveDirectionAndDuty (the only two users). e2m (name level only, no offset anchor): EGA_PWM_Abs_Map (0x0115654E). EEPROM mirror, so _cal.', None)
gl(0x40c186, V('motor_pwm_duty_command'), 'last duty 0-25600 sent to the output channel of entry 39 (per-entry duty cache 0x40c138 + 2 x entry): written next to each set-duty call of the output stage and the init. e2m (name level only): EGA_PWM_Abs_Duty_Cycle (0x01151C4E).', None)
gl(0x40c234, V('motor_pwm_period_command'), 'last PWM period sent to the output channel of entry 39 (per-entry period cache 0x40c198 + 4 x entry): written by the loop init from exhaust_gas_recirculation_valve_motor_pwm_period (dword). e2m (name level only): EGA_PWM_Abs_Period (0x0115279C).', None)
gl(0x40bd96, V('position_sensor_value'), 'value output of sensor channel 75 (cm848_sensorChannel7_init: 0.5-4.5 V, ADC 102 -> -6, ADC 921 -> 15988; the dump reads -2001 = ADC 0, i.e. the input is at its floor): faults 642 / 643 are the channel high / low bits (e2m EGR_Position_Before_Autozero_High_Error 0x01103650 mask 4 / Low_Error mask 8 are the same fault numbers); read by the autozero, the current estimate (position change) and the autozero conditions.', None)
gl(0x40bda0, V('position_sensor_default_value'), 'default value output of sensor channel 75 (9216 = 72 percent at 12800 = 100 percent, the config word at 0x59448): only reader cm848_selectExhaustGasRecirculationValvePositionSource.', None)
gl(0x40be18, V('position_sensor_fault_status'), 'fault status output of sensor channel 75 (cm848_sensorChannel7_init passes 0x40be18; the other 0x40be18 label is a duplicate name): 0 in the dump because the ROM config thresholds are 1023 / 0, which a 10-bit reading cannot cross.', None)
gl(0x406754, V('position_autozero_tolerance'), 'tolerance of the position autozero filter (copied to DAT_003fbcca) and the |sensor value| limit of the autozero conditions. e2m: C_EGR_Position_AZ_Tolerance (0x01179C06) is +0x06 of the block that anchors 0x40674e.', None)
