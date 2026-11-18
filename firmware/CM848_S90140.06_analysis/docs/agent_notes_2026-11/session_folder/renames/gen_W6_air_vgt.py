import csv
import json
import re
import sys

ROOT = sys.argv[1]
OUT = sys.argv[2]
B = ROOT + '/firmware/CM848_S90140.06_analysis/output/'
P = 'variable_geometry_turbocharger_'


def rd(name):
    with open(B + name, newline='') as f:
        return list(csv.reader(f))


gv_rows = [r for r in rd('global_variables.csv')[1:] if len(r) >= 2 and r[0].startswith('0x')]
fr_rows = [r for r in rd('function_renames.csv')[1:] if len(r) >= 2 and r[0].startswith('0x')]
ar_rows = [r for r in rd('arrays.csv')[1:] if len(r) >= 2 and r[0].startswith('0x')]
e2 = {}
for r in rd('e2m_parameters.csv')[1:]:
    if len(r) > 2 and r[2].startswith('0x'):
        e2.setdefault(r[0], int(r[2], 16))
GV = {}
for r in gv_rows:
    GV.setdefault(int(r[0], 16), []).append(r)
FR = {int(r[0], 16): r for r in fr_rows}
EXISTING = set()
for r in gv_rows + fr_rows + ar_rows:
    if r[1]:
        EXISTING.add(r[1])

# block anchors: (e2m base, cm848 base)
BLK = {
    'CAL': (0x01183000, 0x40771a), 'RAM': (0x01183100, 0x40b002), 'DIAG': (0x01183700, 0x40b042),
    'THERM': (0x01183800, 0x40b07e), 'HB': (0x01183900, 0x40b050), 'OCR': (0x01190C00, 0x40b078),
    'DIAGCAL': (0x01183B00, 0x407770), 'HBCAL': (0x01183C00, 0x407782), 'OCCAL': (0x01190B00, 0x4077a8),
    'THERMCAL': (0x01183A00, 0x4077b8), 'POS': (0x0119D200, 0x40b094), 'TOVR': (0x01183200, 0x3fd8cc),
}

rows = []
renamed_old = []      # (kind, old) for the stale-cite scan
new_names = []


def in_window(a):
    return 0x3f9800 <= a <= 0x3fdb30 or 0x3fee08 <= a <= 0x3fee3d


TS = (' Time-shared window (0x3F9800-0x3FDB30): xref_addr.py lists no access below 0x7F60, and scans of the boot ROM '
      '0x0-0x7F5F (load / store / addi / ori with the low halfword of the address; 32-bit words equal to it) find none.')


def e2ref(addr, name, key):
    eb, cb = BLK[key]
    off = e2[name] - eb
    assert cb + off == addr, (hex(addr), name, key, hex(cb + off))
    return 'e2m: %s (0x%08x) is +0x%02x of the block that anchors 0x%x.' % (name, e2[name], off, cb)


def evid(addr, code, e2name=None, key=None, extra=''):
    s = 'code: ' + code
    if not s.endswith('.'):
        s += '.'
    if e2name:
        s += ' ' + e2ref(addr, e2name, key)
    if extra:
        s += ' ' + extra
    if in_window(addr):
        s += TS
    return s


def check_new(name, addr, kind):
    if kind == 'function':
        toks = [t.lower() for t in re.findall(r'[A-Z]?[a-z0-9]+', name)]
    else:
        assert re.match(r'^[a-z][a-z0-9_]*(\+2)?$', name), name
        toks = re.split(r'[_+]', name)
    assert not re.search(r'0x|(^|_)[0-9a-f]{5,}(_|$)', name), ('hex in name', name)
    for bad in ('ema', 'emf', 'hb0', 'oc', 'ss', 'vga', 'vgt', 'dat', 'ptr', 'cfg', 'tmp', 'cnt', 'val', 'calc', 'sp', 'hb'):
        assert bad not in toks, (name, bad)
    if kind != 'function':
        has_cal = 'cal' in toks
        eeprom = 0x3fd482 <= addr <= 0x3feec1
        assert not has_cal or eeprom, ('cal outside the EEPROM mirror', name)
        assert eeprom or not has_cal
    assert name not in EXISTING, ('exists', name)
    assert name not in new_names, ('duplicate', name)
    new_names.append(name)


def gl(addr, old, newfull, code, e2name=None, key=None, extra='', verdict='confirmed'):
    cur = [r[1] for r in GV.get(addr, [])]
    assert old in cur, (hex(addr), old, cur)
    if newfull:
        check_new(newfull, addr, 'global')
    r = {'kind': 'global', 'address': '0x%08x' % addr, 'old': old, 'verdict': verdict}
    if newfull:
        r['new'] = newfull
    r['evidence'] = evid(addr, code, e2name, key, extra)
    rows.append(r)
    if newfull and old:
        renamed_old.append(('global', old))


def ng(addr, newfull, typ, code, e2name=None, key=None, extra=''):
    assert addr not in GV, ('has a row', hex(addr))
    check_new(newfull, addr, 'global')
    rows.append({'kind': 'new_global', 'address': '0x%08x' % addr, 'new': newfull, 'type': typ,
                 'evidence': evid(addr, code, e2name, key, extra)})


def fn(addr, old, newfull, plate, evidence, verdict='confirmed'):
    assert addr in FR and FR[addr][1] == old, (hex(addr), old, FR.get(addr, ['', ''])[1])
    r = {'kind': 'function', 'address': '0x%08x' % addr, 'old': old, 'verdict': verdict}
    if newfull:
        assert re.match(r'^cm848_[a-z][A-Za-z0-9]*$', newfull), newfull
        check_new(newfull, addr, 'function')
        r['new'] = newfull
    if plate:
        r['plate_comment'] = plate
    r['evidence'] = evidence
    rows.append(r)
    if newfull:
        renamed_old.append(('function', old))


def note(text):
    rows.append({'kind': 'note', 'text': text})


# =============================================================================================
# 1. FUNCTIONS: the position control loop (0x2ca14-0x2d638)
# =============================================================================================
LOOPEV = ('Caller order in cm848_phase_common_processing: cm848_readVariableGeometryTurbochargerPositionSensor, '
          'cm848_runActuatorEControlLoop, cm848_sequenceVariableGeometryTurbochargerPositionAdjustment, '
          'cm848_updateVariableGeometryTurbochargerPosition; the boot init sequence calls the loop init (0x2d638), the diagnostic init, '
          'the H-bridge clear, wave 5 stop-seek clear, the over-current clear, the thermal init and wave 5 adjustment filter init back to back.')

fn(0x2ca14, 'cm848_calculateActuatorESetpoint', 'cm848_calculateVariableGeometryTurbochargerPositionCommand',
   'Position command stage of the variable geometry turbocharger valve control loop: takes the boost controller request '
   '(wastegate_duty_controller_state.request_half_duty_counts, 12800 = 100 percent), replaces it with '
   'variable_geometry_turbocharger_position_command_override_value when bit 0 of variable_geometry_turbocharger_user_override_flags_cal is set, '
   'caps it at variable_geometry_turbocharger_position_command_upper_limit and, while fault 670 (mask 0x4000 of fault_detected_bits_656_to_671) is set, '
   'limits it to the range from variable_geometry_turbocharger_closed_position_tolerance to 12800 minus that tolerance; the result is '
   'variable_geometry_turbocharger_position_command (10896 in the dump). Called by '
   'cm848_updateVariableGeometryTurbochargerPositionCommandAndControlState. '
   '(was cm848_calculateActuatorESetpoint, before that cm848_calculateSpeedControlLimit)',
   'code: the request is the setpoint of a closed loop whose feedback is variable_geometry_turbocharger_position (sensor channel 101, wave 5); '
   'the wastegate solenoid reads the same request directly (cm848_applyWastegateSolenoidDuty), nothing writes it back. ' + e2ref(0x40b020, 'VGA_Position_Cmd', 'RAM')
   + ' The three calibration words it reads are C_VGA_Cmd_Override_Value / C_VGA_Cmd_ULim / C_VGT_Closed_Position_Tolerance (+0x00 / +0x3C / +0x4C of the 0x40771a block). ' + LOOPEV)

fn(0x2caa0, 'cm848_checkSpeedZeroCondition', 'cm848_checkVariableGeometryTurbochargerHoldOpenCondition',
   'Sets variable_geometry_turbocharger_hold_open_flag (open-loop hold of the valve at its open end) when the position command is 0 and either it has been 0 for '
   'variable_geometry_turbocharger_open_hold_maximum_time passes (variable_geometry_turbocharger_hold_open_confirm_counter) or both the position and the staged '
   'position command are at or below variable_geometry_turbocharger_open_position_threshold. (was cm848_checkSpeedZeroCondition)',
   'code: counter limit = 0x407764 (xref: this function only), the near-open test compares variable_geometry_turbocharger_position and the staged command with 0x407752; '
   'the flag selects control state 1. ' + e2ref(0x40b006, 'VGA_Hold_Open_Status', 'RAM') + ' C_VGA_Max_Time_To_Open_Hold (+0x4A) and C_VGA_Open_Position_Thd (+0x38) are the two calibration words.')

fn(0x2cb54, 'cm848_selectActuatorEControlMode', 'cm848_selectVariableGeometryTurbochargerControlState',
   'Selects the control state of the valve loop in variable_geometry_turbocharger_control_state: 5 (driver disabled, duty 0) when logical output request 72 '
   '(the valve driver enable, bit 0 of logical_output_request_bits_72_to_79) is clear, 4 while the closed-stop diagnostic drive is on, 3 while the open-stop '
   'diagnostic drive is on, 2 when bit 1 of variable_geometry_turbocharger_user_override_flags_cal is set (fixed override duty), 1 when '
   'variable_geometry_turbocharger_hold_open_flag is set (open-loop hold), otherwise 0 (closed loop on the PID result). '
   '(was cm848_selectActuatorEControlMode, before that cm848_selectFuelControlMode)',
   'code: the priority chain as read in the decompile; the states are consumed by cm848_selectVariableGeometryTurbochargerDutyByControlState and by the PID integrator '
   '(it accumulates only after a pass in state 0). ' + e2ref(0x40b008, 'VGA_Control_State', 'RAM') + ' e2m lists five states (0 closed loop, 1 open-loop hold, 2 user duty, '
   '3 diagnostic duty, 4 disabled); the code has six (the diagnostic duty is split into open stop 3 and closed stop 4, disabled is 5): code wins.')

fn(0x2cbe8, 'cm848_calculateSpeedControlRampUp', 'cm848_calculateVariableGeometryTurbochargerOpenStagedPositionCommand',
   'Open staging of the position command: while the position is below variable_geometry_turbocharger_open_stage_position_threshold the ramp '
   'variable_geometry_turbocharger_open_stage_ramp moves by variable_geometry_turbocharger_open_stage_ramp_rate per pass (signed, -32 in the dump) from '
   'variable_geometry_turbocharger_open_stage_command_threshold (never below 0), and the larger of the ramp and the position command becomes '
   'variable_geometry_turbocharger_position_command_open_staged. (was cm848_calculateSpeedControlRampUp)',
   'code: reads only the three open-stage calibration words (0x40774a / 0x40774c / 0x40774e), the position and the position command; the dump step 65504 = -32 as a signed word. '
   + e2ref(0x40b02c, 'VGA_Open_Staged_Position_Cmd', 'RAM') + ' C_VGA_Open_Stage_Cmd_Thd / Position_Thd / Ramp_Rate are +0x30 / +0x32 / +0x34 of the 0x40771a block.')

fn(0x2cc90, 'cm848_calculateSpeedControlRampDown', 'cm848_calculateVariableGeometryTurbochargerClosedStagedPositionCommand',
   'Closed staging of the position command: while the position is above variable_geometry_turbocharger_closed_stage_position_threshold the ramp '
   'variable_geometry_turbocharger_closed_stage_ramp rises by variable_geometry_turbocharger_closed_stage_ramp_rate per pass (+32 in the dump), is limited to 12800 '
   'and to at least variable_geometry_turbocharger_closed_stage_command_threshold, and the smaller of the ramp and the open staged command becomes '
   'variable_geometry_turbocharger_position_command_closed_staged. (was cm848_calculateSpeedControlRampDown)',
   'code: reads the three closed-stage calibration words (0x40775c / 0x40775e / 0x407760), the position and the open staged command. '
   + e2ref(0x40b004, 'VGA_Position_Cmd_Final', 'RAM') + ' (its copy; this function writes 0x3fb034). C_VGA_Closed_Stage_Cmd_Thd / Position_Thd / Ramp_Rate are +0x42 / +0x44 / +0x46.')

fn(0x2cd38, 'cm848_updateSpeedControlOutputs', 'cm848_updateVariableGeometryTurbochargerStagedPositionCommand',
   'Runs the open and the closed staging stages, then sets variable_geometry_turbocharger_position_reference_unfiltered to the closed staged command in control states 0 and 1 '
   '(otherwise to the measured position, so the reference follows the valve) and variable_geometry_turbocharger_position_command_final to the closed staged command '
   '(0 in state 3). (was cm848_updateSpeedControlOutputs)',
   'code: the body as read; both outputs feed the PID stage and the hold-open check. ' + e2ref(0x40b024, 'VGA_Position_Ref_Unfiltered', 'RAM'))

fn(0x2cdb4, 'cm848_selectSpeedControlGains', 'cm848_selectVariableGeometryTurbochargerGainSet',
   'Selects the gain set from the position command: above variable_geometry_turbocharger_gain_scheduling_position_threshold the normal set, otherwise the open set; '
   'it copies the proportional gain, integral gain, derivative gain, integral term lower limit, feedforward load offset and position reference filter coefficient '
   'to their working words. (was cm848_selectSpeedControlGains)',
   'code: the six working words (0x40b00a / 0x40b012 / 0x40b016 / 0x40b01a / 0x40b01c / 0x40b026) are filled from the high / low calibration pairs at 0x40771c-0x40773a; the '
   'old names called the gain that multiplies the error change an i gain and the gain that is accumulated a proportional gain, the arithmetic in '
   'cm848_calculateVariableGeometryTurbochargerPidDuty says the opposite. ' + e2ref(0x407762, 'C_VGA_Gain_Scheduling_Pos_Thd', 'CAL')
   + ' ("Thresh used to decide gain set above use NORMAL").')

fn(0x2ce8c, 'cm848_updateActuatorESetpointAndMode', 'cm848_updateVariableGeometryTurbochargerPositionCommandAndControlState',
   'Stage 1 of the valve position control loop: calculates the position command, the hold-open condition, the control state, the staged position command and the gain set, '
   'in that order; called by cm848_runVariableGeometryTurbochargerPositionControlLoop. '
   '(was cm848_updateActuatorESetpointAndMode, before that cm848_processSpeedControlModeLogic)',
   'code: five-call body as read. ' + LOOPEV)

fn(0x2cebc, 'cm848_calculateActuatorEDriveCommand', 'cm848_calculateVariableGeometryTurbochargerPidDuty',
   'Stage 2 of the valve position control loop: a PID controller on the error between the filtered position reference and variable_geometry_turbocharger_position; the '
   'proportional term (gain / 128 x error), the derivative term (filtered error change x gain >> 3, off below the noise band), the feedforward load offset and the '
   'integral term (accumulator >> 14) are summed and limited to +-32767 into variable_geometry_turbocharger_pid_duty (12800 = 100 percent). The integral accumulates the '
   'error x integral gain only after a pass in control state 0 and while the error is outside the steady-state band, and is reduced by the friction avoidance term while the '
   'motor current is at or above variable_geometry_turbocharger_steady_state_current_maximum. '
   '(was cm848_calculateActuatorEDriveCommand, before that cm848_calculateSpeedControlFiltered)',
   'code: dump (wave 4) setpoint 10896, position 1991, error 8905, P gain 128 -> PID duty 8905, all other terms 0. The accumulated gain is the integral gain and the gain on the '
   'error change is the derivative gain; the filter whose coefficient pointer is governor_derivative_gain_working is the setpoint prefilter. '
   + e2ref(0x40b014, 'VGA_Governor_PWM', 'RAM') + ' Every PID word (P / I / D gain and term, I term input and lower limit, FF term, prefilter constant, friction avoidance) '
   'has its e2m counterpart at the same offset in the 0x40b002 block.')

fn(0x2d208, 'cm848_selectActuatorEDriveByMode', 'cm848_selectVariableGeometryTurbochargerDutyByControlState',
   'Picks the drive duty from the control state: state 0 takes variable_geometry_turbocharger_pid_duty, state 1 the open hold duty, state 2 the override duty, states 3 and 4 the '
   'open-stop and closed-stop diagnostic drive duties, state 5 gives 0; states 1 to 5 are bounded by variable_geometry_turbocharger_drive_duty_override_lower_limit / _upper_limit. '
   'The result is variable_geometry_turbocharger_drive_duty_selected. '
   '(was cm848_selectActuatorEDriveByMode, before that cm848_selectFuelControlModeOutput)',
   'code: read in full; dump state 0, selected duty = PID duty 8905. ' + e2ref(0x40b02a, 'VGA_PWM_Selected', 'RAM') + ' The unbounded / bounded override words are VGA_PWM_Selected_Override / '
   'VGA_PWM_Limited_Override (+0x34 / +0x32 of the block that anchors 0x40b002).')

fn(0x2d2f8, 'cm848_calculateActuatorEDriveLimits', 'cm848_limitVariableGeometryTurbochargerBatteryCompensatedDuty',
   'Compensates the selected drive duty and the working duty limit for the supply voltage (x boost_fuel_scale_cal / fuel_timing_error_scale, 224 / 192 in the dump: 8905 -> 10389), '
   'derives the lower and upper duty limits from the calibrated limits and the working limit, and stores the limited signed duty in '
   'variable_geometry_turbocharger_drive_duty_clamped. (was cm848_calculateActuatorEDriveLimits, before that cm848_calculateFuelControlLimits)',
   'code: dump battery compensated duty 10389 = 8905 x 224 / 192; the lower bound is the calibration word the old name called fuel_control_upper_limit_cal '
   '(max of it and minus the limit). e2m: VGA_PWM_Battery_Compensated (+0x26), VGA_PWM_Clamped (+0x2C), VGA_PWM_LLim / VGA_PWM_ULim (+0x3A / +0x3C) are at the same offsets of the block that anchors 0x40b002, and '
   'C_VGA_Compensated_PWM_Lim ("limits of VGA PWM duty cycle adjustable based on battery voltage", +0x4E = variable_geometry_turbocharger_drive_duty_limit_normal) is compensated the same way here. '
   'The scale words are shared with cm848_calculateFuelDemandLimits (see the twin module note); that the divisor is a battery voltage is an inference (192 / 224 = 12.0 / 14.0 V at 1/16 V).')

fn(0x2d428, 'cm848_outputActuatorEDirectionAndDuty', 'cm848_outputVariableGeometryTurbochargerDirectionAndDuty',
   'Output stage of the valve loop: the sign of variable_geometry_turbocharger_drive_duty_clamped sets or clears logical output 71 (the direction request) immediately '
   '(inverted when variable_geometry_turbocharger_motor_direction_reversal is non-zero), the magnitude (12800 minus it when variable_geometry_turbocharger_drive_duty_polarity_reversal is set) '
   'x 2 is the PWM duty (25600 = 100 percent), forced to 0 for one pass after a direction change (while variable_geometry_turbocharger_direction_change_zero_duty_enable is non-zero) '
   'or below variable_geometry_turbocharger_drive_duty_zero_threshold (640); the duty goes to the output channel record of variable_geometry_turbocharger_motor_pwm_output_channel_cal, '
   'which is 0 (unassigned) in this calibration. '
   '(was cm848_outputActuatorEDirectionAndDuty, before that cm848_processFuelControlProtectionFlags)',
   'code: wave 4 reading kept (signed command split into a direction line and a PWM magnitude with a dead band and a zero-duty pass on reversal). '
   + e2ref(0x40b032, 'VGA_PWM_Direction_Change', 'RAM') + ' e2m VGA_Motor_Cmd_Closing_Direction (0x01157708 mask 0x80) is logical output 71 and VGA_PWM_Enable (0x01157709 mask 0x01) is 72 '
   '(see logical_output_request_bits_64_to_71). On this truck the duty is computed (20778 in the dump) but drives nothing.')

fn(0x2d5d8, 'cm848_driveActuatorE', 'cm848_driveVariableGeometryTurbochargerMotor',
   'Stage 3 of the valve position control loop: cm848_selectVariableGeometryTurbochargerDutyByControlState, cm848_limitVariableGeometryTurbochargerBatteryCompensatedDuty and '
   'cm848_outputVariableGeometryTurbochargerDirectionAndDuty in that order; called by cm848_runVariableGeometryTurbochargerPositionControlLoop. '
   '(was cm848_driveActuatorE, before that cm848_processFuelControlOutput)',
   'code: three-call wrapper, read.')

fn(0x2d600, 'cm848_runActuatorEControlLoop', 'cm848_runVariableGeometryTurbochargerPositionControlLoop',
   'Per-pass runner of the valve position control loop, called once per pass by cm848_phase_common_processing: when variable_geometry_turbocharger_enable_flag is set '
   '(1 in the dump) it runs cm848_updateVariableGeometryTurbochargerPositionCommandAndControlState, cm848_calculateVariableGeometryTurbochargerPidDuty and '
   'cm848_driveVariableGeometryTurbochargerMotor in that order. (was cm848_runActuatorEControlLoop, before that cm848_initProtectionModeDefaults)',
   'code: body as read. ' + LOOPEV)

fn(0x2d638, 'cm848_initializeActuatorEControlLoop', 'cm848_initializeVariableGeometryTurbochargerPositionControlLoop',
   'Boot init of the valve position control loop: sets the previous control state to 3, zeroes the staging ramps, the integral accumulator and the output duty, points the '
   'two filter states at their coefficient words and, when variable_geometry_turbocharger_motor_pwm_output_channel_cal is 1 to 50, enables that output channel record, sets its duty '
   'to 0 and its period to variable_geometry_turbocharger_motor_pwm_period (2857 microseconds in the dump). '
   '(was cm848_initializeActuatorEControlLoop, before that cm848_initFuelControlStateVariables)',
   'code: the three driver table calls are enable / set_duty / set_period of the record picked by the output channel word. ' + LOOPEV)

# =============================================================================================
# 2. FUNCTIONS: H-bridge fault path (0x2d7a4-0x2e02c)
# =============================================================================================
HBEV = ('e2m: the masks it sets (4 / 8 / 16 / 32 / 64 / 256 of fault_detected_bits_736_to_751) are the e2m masks 0x0004 / 0x0008 / 0x0010 / 0x0020 / 0x0040 / 0x0100 of VGA_Fault_HB0A / '
        'VGA_Fault_HB0B / VGA_Fault_HB0_OC_HI / VGA_Fault_HB0_OC_LO / VGA_Fault_HB0_Inrush / VGA_Electrical_Fault (0x0110365C), and its timers and counters are the C_VGA_HB0_* / C_VGA_Fault_HB0_* '
        'calibration words at the same offsets of the 0x407782 block. The wording H-bridge / bridge for this driver fault path comes from those e2m names (HB0 = H-bridge 0); the code itself shows '
        'supervisor register status bits, two retry-timer / fault-counter pairs and faults 738-744, and a signed duty split into a direction line and a PWM magnitude.')

fn(0x2d7a4, 'cm848_updateSpeedControlCounter1', 'cm848_updateVariableGeometryTurbochargerHBridgeFaultRetryTimer',
   'Retry timer of the valve H-bridge fault path: while the fault input (the argument) is present the count in the first word of variable_geometry_turbocharger_h_bridge_fault_retry_timer '
   'rises by variable_geometry_turbocharger_h_bridge_fault_retry_increment up to variable_geometry_turbocharger_h_bridge_fault_retry_time, otherwise it falls by 1 to 0; the second word latches 1 at the '
   'limit and 0 at 0, and variable_geometry_turbocharger_h_bridge_fault_retry_trigger_flag is set when the input is absent and the latch is 0. (was cm848_updateSpeedControlCounter1)',
   'code: called only by cm848_processVariableGeometryTurbochargerHBridgeFaults with (bit 0x20 of supervisor_register_162_status | bit 0x80 | the over-current input); reads 0x407782 and 0x407798 only. ' + HBEV)

fn(0x2d88c, 'cm848_processSpeedControlFilter1', 'cm848_updateVariableGeometryTurbochargerHBridgeFaultCounter',
   'Fault counter of the valve H-bridge fault path: keeps a three-pass history of variable_geometry_turbocharger_h_bridge_fault_retry_active_flag, raises '
   'variable_geometry_turbocharger_h_bridge_fault_counter by variable_geometry_turbocharger_h_bridge_fault_fail_increment up to variable_geometry_turbocharger_h_bridge_fault_maximum_count while the fault input is present, '
   'lowers it by variable_geometry_turbocharger_h_bridge_fault_pass_decrement when the input is absent and the retry has been active for three passes, sets '
   'variable_geometry_turbocharger_h_bridge_fault_set_flag at variable_geometry_turbocharger_h_bridge_fault_set_threshold and the clear flag at 0, and recomputes the retry-active flag (retry trigger set and not given up). '
   '(was cm848_processSpeedControlFilter1)',
   'code: the give-up test uses variable_geometry_turbocharger_h_bridge_fault_give_up_enable_cal (0x3fd8d0). ' + HBEV)

fn(0x2d9f4, 'cm848_updateSpeedControlCounter2', 'cm848_updateVariableGeometryTurbochargerHBridgeInrushRetryTimer',
   'Retry timer of the valve H-bridge inrush fault path, same scheme as the fault retry timer: the count in the first word of variable_geometry_turbocharger_h_bridge_inrush_retry_timer rises by '
   'variable_geometry_turbocharger_h_bridge_inrush_retry_increment up to variable_geometry_turbocharger_h_bridge_inrush_retry_time while the inrush input (bit 0x100 of supervisor_register_162_status) is present, '
   'and variable_geometry_turbocharger_h_bridge_inrush_retry_trigger_flag is set when the input is absent and the latch is 0. (was cm848_updateSpeedControlCounter2)',
   'code: called only by cm848_processVariableGeometryTurbochargerHBridgeFaults; reads 0x407788 and 0x407794 only. The input bit 0x100 is outside the low byte the supervisor chip register read stores '
   '(CSV comment of supervisor_register_162_status: bit 8 never set), so on this hardware path the inrush input is always 0. ' + HBEV
   + ' e2m names this path HB0_Inrush_Retry; the sibling counter words carry the e2m names C_VGA_HB0_OC_*, but the code uses them for the inrush fault (mask 64), so the names here follow the code.')

fn(0x2dadc, 'cm848_processSpeedControlFilter2', 'cm848_updateVariableGeometryTurbochargerHBridgeInrushFaultCounter',
   'Fault counter of the valve H-bridge inrush fault path (same scheme as the fault counter, on variable_geometry_turbocharger_h_bridge_inrush_fault_counter): returns whether the count has reached '
   'variable_geometry_turbocharger_h_bridge_inrush_fault_set_threshold, and sets the clear flag variable_geometry_turbocharger_h_bridge_inrush_fault_clear_flag when it is 0. '
   '(was cm848_processSpeedControlFilter2)',
   'code: its return value is the condition that sets fault 742 (mask 64) in cm848_processVariableGeometryTurbochargerHBridgeFaults. ' + HBEV)

fn(0x2dc40, 'cm848_initProtectionControlState', 'cm848_processVariableGeometryTurbochargerHBridgeFaults',
   'Valve driver (H-bridge) fault handler, run each pass of cm848_periodicTaskSet_controlLoop when variable_geometry_turbocharger_enable_flag is set: reads and clears bits 0x20 / 0x80 / 0x100 of '
   'supervisor_register_162_status (the over-current input comes from bit 1 of switch_input_state_bits[2] instead when bit 0 of fuel_feature_control_flags is set), runs the inrush and the general '
   'fault timers and counters, sets or clears faults 738 to 741 (masks 4 / 8 / 16 / 32), the inrush fault 742 (mask 64) and the electrical fault 744 (mask 256) of fault_detected_bits_736_to_751, and writes '
   'variable_geometry_turbocharger_driver_fault_pending_flag (1 when either retry-active flag is 0). (was cm848_initProtectionControlState)',
   'code: the function is not an init: it runs every pass; the dump 0x40b224 low byte is the supervisor chip register 0xA2 reply (CSV comment, read job supervisor_register_162_read_job). '
   + HBEV + ' e2m also lists VGT_ASIC_Feedback (0x01161202, mask 0x02) as a switch input, which matches the switch_input_state_bits[2] & 2 alternative (e2m only, not shown by the code).')

fn(0x2e02c, 'cm848_clearDiagnosticConditionFlags', 'cm848_clearVariableGeometryTurbochargerHBridgeFaultState',
   'Boot-time reset of the valve H-bridge fault path: clears masks 4 / 8 / 16 / 32 / 64 and 256 of the detected and registered fault words 736 to 751, both retry-active flags with their histories, '
   'both fault counters and both retry timers. (was cm848_clearDiagnosticConditionFlags)',
   'code: called once from the boot init sequence next to the loop init; it clears only the governor_fuel_rate_* words (now h_bridge) and the fault masks (0xfe83), not the over-current words '
   '(those are cleared by cm848_clearVariableGeometryTurbochargerDriverOverCurrentState). ' + HBEV)

# =============================================================================================
# 3. FUNCTIONS: bank-2 siblings (0x50f834-0x5102d4)
# =============================================================================================
fn(0x50f834, 'engine_protection_speedTracking_calc', 'cm848_evaluateVariableGeometryTurbochargerPositionControlDiagnosticConditions',
   'Conditions of the valve position control diagnostic: enabled while the control error fault is already set or the control state is 0, with no span adjustment error (fault 671), '
   'variable_geometry_turbocharger_motor_ok_flag set and no position sensor fault; it also needs the staged position command to be steady (its deviation from the filtered command, '
   'variable_geometry_turbocharger_position_command_deviation, below variable_geometry_turbocharger_steady_state_command_deviation_threshold) and the duty, signed toward the error, not below '
   'variable_geometry_turbocharger_control_strong_drive_duty_threshold while the error exceeds variable_geometry_turbocharger_control_error_threshold. Outputs '
   'variable_geometry_turbocharger_control_diagnostic_enable_flag and variable_geometry_turbocharger_control_error_condition_flag. (was engine_protection_speedTracking_calc)',
   'code: the position compared is variable_geometry_turbocharger_position_adjusted; the old protection_* / speedTracking names were a speed-tracking guess. '
   'e2m: VGA_Control_Diag_Enable / VGA_PWM_Is_Strongly_Commanded / VGA_Control_Error_Condition / VGA_Filtered_Diag_Cmd / VGA_Position_Cmd_Diff are +0x04 / +0x00 / +0x08 / +0x0A / +0x0C of the block that anchors 0x40b042, '
   'and the calibration words are C_VGA_Cmd_Rate_Thd / C_VGA_Control_Error_Thd / C_VGA_Control_PWM_Threshold at +0x00 / +0x02 / +0x10 of the block that anchors 0x407770.')

fn(0x50fa7c, 'engine_protection_speedTracking_rampUpdate', 'cm848_updateVariableGeometryTurbochargerPositionControlFaultCounter',
   'Position control fault timer: counts passes of variable_geometry_turbocharger_control_diagnostic_enable_flag up to variable_geometry_turbocharger_control_diagnostic_enable_time '
   '(variable_geometry_turbocharger_control_diagnostic_count_enabled_flag), then raises variable_geometry_turbocharger_control_diagnostic_fault_counter by '
   'variable_geometry_turbocharger_control_fault_time_increment while the error condition is present and lowers it by variable_geometry_turbocharger_control_fault_time_decrement otherwise '
   '(held while the count is not enabled, forced to 0 when variable_geometry_turbocharger_control_fault_counter_clear_cal is set); variable_geometry_turbocharger_control_error_latched_flag is '
   'set at variable_geometry_turbocharger_control_fault_time_fail_threshold and cleared at or below variable_geometry_turbocharger_control_fault_time_pass_threshold. '
   '(was engine_protection_speedTracking_rampUpdate)',
   'code: the dump has 0x3fd8ce = 1, so the counter is held at 0 on this truck. e2m: C_VGA_Control_Diag_Enable_Time / C_VGA_Control_Fault_Time_Incrt / Decrt / C_VGA_Fail_Time_Thd / C_VGA_Pass_Time_Thd are +0x04 / +0x06 / +0x08 / +0x0C / +0x0E '
   'of the 0x407770 block; the e2m descriptions of Incrt and Decrt are swapped against the code (the word at +0x06 is added, the one at +0x08 subtracted), code wins.')

fn(0x50fbf8, 'phase_group_b_updateGovernorModeDiagnostics', 'cm848_updateVariableGeometryTurbochargerPositionControlErrorFault',
   'Per-pass entry of the valve position control diagnostic, run when variable_geometry_turbocharger_enable_flag is set: runs the condition and fault-timer stages and sets fault 743 '
   '(mask 128 of fault_detected_bits_736_to_751) while variable_geometry_turbocharger_control_error_latched_flag is set, clearing it in the detected and registered words otherwise. '
   '(was phase_group_b_updateGovernorModeDiagnostics)',
   'code: body as read. e2m: VGA_Control_Error is mask 0x0080 of 0x0110365C. The position control error also drives the position status bit 32 and the fallback position (wave 5, cm848_selectVariableGeometryTurbochargerPositionSource).')

fn(0x50fc8c, 'cm848_initializeGovernorFuelDemandArray', 'cm848_initializeVariableGeometryTurbochargerPositionControlDiagnostic',
   'Boot init of the valve position control diagnostic: clears its flags, counters, the filtered position command and the deviation and fault 743 in the detected and registered words, '
   'and points the filtered-command filter state at its coefficient word. (was cm848_initializeGovernorFuelDemandArray)',
   'code: no array and no fuel demand is touched; it is called in the init group next to cm848_initializeVariableGeometryTurbochargerPositionControlLoop.')

fn(0x50fd40, 'boost_demand_diagBit_counter', 'cm848_updateVariableGeometryTurbochargerValveOverTemperatureFault',
   'Valve over-temperature timer: counts passes while the coolant temperature (fuel_demand_boost_input) is below variable_geometry_turbocharger_coolant_temperature_default and '
   'boost_correction_inhibit_flag is 0, i.e. nothing else explains a hot motor, up to variable_geometry_turbocharger_valve_over_temperature_inhibit_time; once reached while fault 746 '
   '(motor over-temperature) is set it sets mask 0x400 (fault 794) of fault_detected_bits_784_to_799, and the bit is cleared when fault 746 is clear. (was boost_demand_diagBit_counter)',
   'code: the bit is set and cleared in diagnostic_status_flags_b / _shadow (renamed to the fault array names below). e2m: C_VGA_Inhibit_Over_Temp_Time (+0x24 of the 0x4077b8 block = 0x4077dc, '
   '"time inhibit conditions false before VGA_Valve_Fault set"); VGA_Valve_Fault_Over_Tmptr sits 8 bytes after the 736 word with mask 0x0800 in e2m but 6 bytes after with mask 0x400 in the code, so that part is code only.')

fn(0x50fe54, 'phase_group_b_computeGovernorFuelDemandOutput', 'cm848_updateVariableGeometryTurbochargerMotorTemperature',
   'Thermal model of the valve motor, run when variable_geometry_turbocharger_enable_flag is set: heats the winding temperature (variable_geometry_turbocharger_motor_winding_temperature, '
   '1/8 degree F) from the mean-squared current times variable_geometry_turbocharger_normalized_resistance above the iron core temperature, derives the iron core temperature '
   '(1/64 degree F) from the winding temperature, the ambient temperature (coolant temperature plus variable_geometry_turbocharger_housing_temperature_offset) and '
   'variable_geometry_turbocharger_motor_temperature_fraction, both through first-order filters; sets the warning flag at variable_geometry_turbocharger_motor_temperature_warning_threshold and fault 746 '
   '(mask 1024) at variable_geometry_turbocharger_motor_temperature_high_threshold (cleared below the low threshold), then runs the valve over-temperature timer. '
   '(was phase_group_b_computeGovernorFuelDemandOutput)',
   'code: dump thresholds 4000 / 3200 / 3160 counts of 0.125 degree F = 500 / 400 / 395 degrees F, coolant default 14080 = 220 degrees F at 1/64 F. e2m: VGA_Temperature / VGA_Temperature_1 / VGA_Tmptr_Fil_Input / VGA_Tmptr_1_Fil_Input / '
   'VGA_Temperature_Warning / VGA_Ambient_Temperature / VGA_Coolant_Temperature are +0x06 / +0x0C / +0x10 / +0x0E / +0x00 / +0x08 / +0x14 of the block that anchors 0x40b07e, and the C_VGA_Tmptr_* / Normalized_Resistance / '
   'Housing_Tmptr_Offset / Tmptr_Fraction words are at the same offsets of the 0x4077b8 block. The e2m texts also say VGR / EGR motor (copy-paste), the structure is a two-node thermal model.')

fn(0x51008c, 'governor_rpm_monitor_calc', 'cm848_estimateVariableGeometryTurbochargerMotorCurrent',
   'Estimates the valve motor current into variable_geometry_turbocharger_motor_current (0.000976562 A per count): the applied voltage is (|variable_geometry_turbocharger_drive_duty_limited| '
   'plus variable_geometry_turbocharger_drive_duty_offset) x fuel_timing_error_scale >> 7 while logical output request 72 is set and fault 744 is clear, the back electromotive force is the change of the position '
   'sensor value x variable_geometry_turbocharger_speed_back_electromotive_force_factor (sign from the previous direction request, limited to +-64000), and the current is the difference divided by the circuit '
   'resistance (variable_geometry_turbocharger_reference_resistance plus the winding temperature x variable_geometry_turbocharger_resistance_temperature_coefficient, limited to 16000), limited to '
   'variable_geometry_turbocharger_motor_current_maximum. (was governor_rpm_monitor_calc)',
   'code: it is a current estimate, not an rpm: the result is compared with variable_geometry_turbocharger_driver_over_current_threshold and variable_geometry_turbocharger_steady_state_current_maximum. '
   'e2m: VGA_Motor_Current / VGA_Circuit_Resistance / VGA_Back_EMF are +0x02 / +0x0A / +0x12 of the block that anchors 0x40b07e; C_VGA_PWM_Offset / C_VGA_Speed_EMF_Factor / C_VGA_Max_Current / '
   'C_VGA_Ref_Resistance / C_VGA_Resistance_Tmptr_Coeff are +0x0A / +0x0C / +0x08 / +0x18 / +0x1A of the 0x4077b8 block.')

fn(0x51027c, 'phase_group_b_filterGovernorRpmSquaredMovingAverage', 'cm848_updateVariableGeometryTurbochargerMeanSquaredCurrent',
   'Per-pass motor current update, run when variable_geometry_turbocharger_enable_flag is set: estimates the motor current and filters its square (current x current >> 13) into '
   'variable_geometry_turbocharger_motor_mean_squared_current. (was phase_group_b_filterGovernorRpmSquaredMovingAverage)',
   'code: called from the phase group B sequence; the filter coefficient word is 0x4077ba. e2m: VGA_Mean_Squared_Current is +0x04 of the block that anchors 0x40b07e, C_VGA_Current_Avg_Fil_Cnst +0x02 of the 0x4077b8 block.')

fn(0x5102d4, 'fuel_demand_boost_initialize', 'cm848_initializeVariableGeometryTurbochargerMotorThermalModel',
   'Boot init of the valve motor thermal model and current filter: clears the mean-squared current filter, loads the previous direction request and position sensor value, starts the winding '
   'temperature filter at the coolant temperature / 8 and the iron core temperature filter at the coolant temperature (not below 0), and clears fault 746 in the detected and registered words. '
   '(was fuel_demand_boost_initialize)',
   'code: body as read; it is in the boot init group with the loop init (lines 54427-54433 of the decompile).')

fn(0x2c9bc, 'mpc555_initFuelControlModeVariables', None, None,
   'Not part of the valve loop (the wave 4 lead listed it with the chain): it initialises the words 0x3fb018-0x3fb026 (map_fuel_correction_prev_snapshot, two words set to 2, a word and a pointer to 0x40729e, '
   'an EMA state with coefficient 0x4072a0) that are shared with cm848_processProtectionEntry, and the boot init sequence calls it between mpc555_initManifoldPressureFilter and cm848_initSensorRetryCounters, '
   'far from the valve init group; its words lie outside the 0x40771a-0x4077dc calibration range and the 0x3fb02e-0x3fb0a2 state range of the loop. Name kept.',
   verdict='rejected')

# =============================================================================================
# 4. GLOBALS - runtime control block 0x40b002-0x40b040 (RAM block anchor 0x01183100 -> 0x40b002)
# =============================================================================================
RAMROWS = [
    (0x40b002, 'governor_fuel_control_limit_active', 'drive_duty_limited', 'signed limited drive duty after the dead band and the direction change zeroing: = variable_geometry_turbocharger_drive_duty_clamped unless forced to 0 (cm848_outputVariableGeometryTurbochargerDirectionAndDuty); read by the current estimate as the duty', 'VGA_PWM_Limited'),
    (0x40b004, 'governor_output_prev_snapshot', 'position_command_final', 'copy of the closed staged position command, 0 in control state 3 (written by cm848_updateVariableGeometryTurbochargerStagedPositionCommand); read by the hold-open check and the position control diagnostic', 'VGA_Position_Cmd_Final'),
    (0x40b006, 'throttle_rate_enable_flag', 'hold_open_flag', 'set by cm848_checkVariableGeometryTurbochargerHoldOpenCondition when the position command is 0 and the valve is at its open end; selects control state 1 (open-loop hold)', 'VGA_Hold_Open_Status'),
    (0x40b008, 'governor_fuel_mode_state', 'control_state', '0 closed loop, 1 open-loop hold, 2 override duty, 3 open-stop diagnostic drive, 4 closed-stop diagnostic drive, 5 driver disabled (cm848_selectVariableGeometryTurbochargerControlState); the position control diagnostic is enabled in state 0', 'VGA_Control_State'),
    (0x40b00a, 'governor_speed_i_gain_b_working', 'derivative_gain', 'the gain that multiplies the change of the filtered position error (>> 3) in the PID stage; filled by the gain set selection', 'VGA_D_Gain'),
    (0x40b00c, 'governor_speed_i_term', 'derivative_term', 'derivative gain x filtered error change >> 3, limited to +-32767, zero below the derivative noise band', 'VGA_D_Term'),
    (0x40b00e, 'governor_speed_error_filtered_change', 'position_error_derivative', 'change of the filtered position error between two passes (the first-order filter output minus the previous one)', 'VGA_Error_Derivative'),
    (0x40b010, 'governor_speed_proportional_input', 'integral_error_input', 'the position error when it exceeds the steady-state band and the output is not saturated against it, else 0; the input of the integral accumulator', 'VGA_Error_I_Term_Input'),
    (0x40b012, 'governor_fuel_bias_working', 'feedforward_term', 'load offset added to the PID sum, picked by the gain set', 'VGA_FF_Term'),
    (0x40b014, 'actuator_e_drive_command_raw', 'pid_duty', 'PID result, +-32767, 12800 = 100 percent; dump 8905 = setpoint minus position (the other terms are 0)', 'VGA_Governor_PWM'),
    (0x40b016, 'governor_proportional_gain_working', 'integral_gain', 'the gain that multiplies the error before it is added to the integral accumulator; filled by the gain set selection', 'VGA_I_Gain'),
    (0x40b018, 'governor_fuel_integral_b_scaled', 'integral_term', 'integral accumulator >> 14', 'VGA_I_Term'),
    (0x40b01a, 'governor_integral_limit_working', 'integral_term_lower_limit', 'lower limit of the integral accumulator (<< 14), picked by the gain set', 'VGA_I_Term_LLim'),
    (0x40b01c, 'governor_speed_p_gain_b_working', 'proportional_gain', 'proportional gain, 128 = 1.0 (error x gain >> 7); dump 128', 'VGA_P_Gain'),
    (0x40b01e, 'governor_speed_p_term', 'proportional_term', 'proportional gain x position error >> 7, limited to +-32767', 'VGA_P_Term'),
    (0x40b020, 'actuator_e_setpoint_working', 'position_command', 'written only by cm848_calculateVariableGeometryTurbochargerPositionCommand: the boost controller request after the override, the cap and the fault 670 clamp; dump 10896 = the wastegate request', 'VGA_Position_Cmd'),
    (0x40b022, 'governor_speed_filtered', 'position_reference_filtered', 'first-order filter (coefficient = the prefilter word) of the unfiltered position reference; the PID error is this minus the position', 'VGA_Position_Ref_Filtered'),
    (0x40b024, 'governor_speed_raw_input', 'position_reference_unfiltered', 'the closed staged command in control states 0 and 1, otherwise the measured position (cm848_updateVariableGeometryTurbochargerStagedPositionCommand)', 'VGA_Position_Ref_Unfiltered'),
    (0x40b026, 'governor_derivative_gain_working', 'position_reference_filter_coefficient', 'coefficient word of the first-order filter on the position reference (the filter state variable_geometry_turbocharger_position_reference_filter_state points here), picked by the gain set: a filter coefficient, not a derivative gain', 'VGA_Prefilter_Cnst'),
    (0x40b028, 'governor_fuel_output_prev', 'drive_duty_battery_compensated', 'selected duty x boost_fuel_scale_cal / fuel_timing_error_scale, limited to +-32767 (cm848_limitVariableGeometryTurbochargerBatteryCompensatedDuty); dump 10389', 'VGA_PWM_Battery_Compensated'),
    (0x40b02a, 'governor_fuel_output_a_working', 'drive_duty_selected', 'drive duty picked by the control state (PID duty in state 0); dump 8905', 'VGA_PWM_Selected'),
    (0x40b02c, 'throttle_speed_rate_current', 'position_command_open_staged', 'larger of the open staging ramp and the position command (cm848_calculateVariableGeometryTurbochargerOpenStagedPositionCommand)', 'VGA_Open_Staged_Position_Cmd'),
    (0x40b02e, 'actuator_e_drive_command', 'drive_duty_clamped', 'signed battery compensated duty limited to the lower and upper duty limits; the sign selects logical output 71 and the magnitude x 2 is the PWM duty (dump 10389)', 'VGA_PWM_Clamped'),
    (0x40b030, 'governor_speed_error_a', 'position_error', 'filtered position reference minus the position, the PID error (dump 8905 = 10896 - 1991)', 'VGA_Position_Error'),
    (0x40b032, 'governor_output_updated_flag', 'direction_change_flag', 'set when the direction request changed since the previous pass and the zero-duty-on-reversal enable is non-zero; forces the duty to 0 for that pass', 'VGA_PWM_Direction_Change'),
    (0x40b034, 'governor_fuel_output_a_prev', 'drive_duty_override_bounded', 'the override duty (states 1 to 5) after the override lower / upper limits; 0 in state 0', 'VGA_PWM_Limited_Override'),
    (0x40b036, 'governor_fuel_output_a', 'drive_duty_override_unbounded', 'the override duty (states 1 to 5) before the bounds; 0 in state 0', 'VGA_PWM_Selected_Override'),
    (0x40b038, 'governor_fuel_output_magnitude', 'drive_duty_magnitude', 'absolute value of the clamped duty (12800 minus it when the polarity reversal is set)', 'VGA_PWM_Valid_Abs_Duty_Cycle'),
    (0x40b03a, 'governor_fuel_output_zero_flag', 'drive_duty_within_dead_band_flag', 'set when the duty magnitude is below the zero threshold calibration', 'VGA_PWM_Within_Driver_Deadband'),
    (0x40b03c, 'fuel_control_limit_upper_working', 'drive_duty_lower_limit_working', 'the larger of the lower duty limit calibration and minus the working duty limit: the LOWER bound of the limited duty (the old name said upper)', 'VGA_PWM_LLim'),
    (0x40b03e, 'governor_fuel_upper_limit', 'drive_duty_upper_limit_working', 'the smaller of the upper duty limit calibration and the working duty limit (compensated, clamped to 12800)', 'VGA_PWM_ULim'),
    (0x40b040, 'governor_derivative_term', 'friction_avoidance_term', '+-friction avoidance decrement (sign of the PID duty) while the motor current is at or above variable_geometry_turbocharger_steady_state_current_maximum, else 0; x -64 is added to the integral accumulator step, i.e. it reduces the integral', 'VGA_Friction_Avoidance_Decrt'),
]
for a, old, suf, code, e in RAMROWS:
    gl(a, old, P + suf, code, e, 'RAM')

gl(0x40b094, 'actuator_e_feedback', P + 'position',
   'the position fed to the control loop: variable_geometry_turbocharger_position_adjusted (sensor channel 101 normalised to 12800 = 100 percent) or, with a sensor / span / position control fault, the position default value (wave 5 plate of cm848_selectVariableGeometryTurbochargerPositionSource); read by the PID error, the staging stages and the hold-open check',
   'VGT_Position', 'POS')

# =============================================================================================
# 5. GLOBALS - time-shared state of the loop 0x3fb02e-0x3fb050
# =============================================================================================
STATE = [
    (0x3fb02e, 'throttle_zero_confirm_counter', 'hold_open_confirm_counter', 'passes the position command has been 0, counted up to the open hold maximum time (cm848_checkVariableGeometryTurbochargerHoldOpenCondition)'),
    (0x3fb030, 'throttle_speed_rate_lower', 'open_stage_ramp', 'state of the open staging ramp, stepped by the open stage ramp rate (3 reads / 4 writes in cm848_calculateVariableGeometryTurbochargerOpenStagedPositionCommand and the loop init)'),
    (0x3fb032, 'throttle_speed_rate_upper', 'closed_stage_ramp', 'state of the closed staging ramp, stepped by the closed stage ramp rate'),
    (0x3fb034, 'governor_output_prev_working', 'position_command_closed_staged', 'smaller of the closed staging ramp and the open staged command: the position command after both staging stages (copied to variable_geometry_turbocharger_position_command_final)'),
    (0x3fb036, 'governor_derivative_gain_filter_state', 'position_reference_filter_state', 'first-order filter state (accumulator + coefficient pointer) of the position reference; its coefficient pointer is variable_geometry_turbocharger_position_reference_filter_coefficient'),
    (0x3fb03e, 'governor_ema_filter_state_ptr', 'derivative_filter_coefficient_pointer', 'pointer to the coefficient word of the first-order filter on the position error (cm848_signedFirstOrderFilter takes the address of this word and the accumulator 0x3fb042 as one filter state)'),
    (0x3fb042, 'governor_speed_error_filter_accum', 'derivative_filter_accumulator', 'accumulator of the first-order filter on the position error (zeroed by the loop init)'),
    (0x3fb046, 'governor_speed_error_filtered_snapshot', 'position_error_filtered_previous', 'filtered position error of the previous pass; the difference to the new one is the error change of the derivative term'),
    (0x3fb048, 'governor_fuel_mode_prev_snapshot', 'control_state_previous', 'control state of the previous pass (3 after init); the integral accumulates only when it is 0'),
    (0x3fb04a, 'governor_fuel_integral_b', 'integral_accumulator', 'PID integral accumulator, limited by the integral term limits << 14; the integral term is this >> 14'),
    (0x3fb04e, 'governor_fuel_output_snapshot', 'direction_output_previous_flag', 'direction line state (logical output 71 value) of the previous pass, compared with the new one to detect a direction change'),
    (0x3fb050, 'governor_fuel_output_scaled', 'motor_pwm_duty_scaled', 'PWM duty on the 25600 = 100 percent scale (magnitude x 2, 0 on a direction change or inside the dead band) passed to the output channel set-duty call; dump 20778'),
]
for a, old, suf, code in STATE:
    gl(a, old, P + suf, code)

# H-bridge words
HB = [
    (0x3fb052, 'governor_fuel_rate_a_active', 'h_bridge_fault_retry_active_flag', 'retry active: the retry trigger is set and the fault was not given up (written by cm848_updateVariableGeometryTurbochargerHBridgeFaultCounter); when it or the inrush counterpart is 0 the driver fault pending flag is set', None),
    (0x3fb054, 'governor_fuel_rate_a_active_prev', 'h_bridge_fault_retry_active_previous_flag', 'retry-active flag one pass ago (history shift in the fault counter)', None),
    (0x3fb056, 'governor_fuel_rate_a_active_prev_b', 'h_bridge_fault_retry_active_previous_2_flag', 'retry-active flag two passes ago', None),
    (0x3fb058, 'governor_fuel_rate_a_active_prev_c', 'h_bridge_fault_retry_active_previous_3_flag', 'retry-active flag three passes ago (written only)', None),
    (0x3fb05a, 'governor_fuel_rate_b_active', 'h_bridge_inrush_retry_active_flag', 'inrush retry active: the inrush retry trigger is set and the inrush fault was not given up', None),
    (0x3fb05c, 'governor_fuel_rate_b_underspeed_flag', 'h_bridge_inrush_retry_active_previous_flag', 'inrush retry-active flag one pass ago (history shift in the inrush fault counter)', None),
    (0x3fb05e, 'governor_fuel_rate_c_underspeed_flag', 'h_bridge_inrush_retry_active_previous_2_flag', 'inrush retry-active flag two passes ago', None),
    (0x3fb060, 'governor_fuel_rate_d_underspeed_flag', 'h_bridge_inrush_retry_active_previous_3_flag', 'inrush retry-active flag three passes ago (written only)', None),
    (0x3fb062, 'governor_fuel_rate_a', 'h_bridge_fault_counter', 'fault counter, rising by the fail increment while the fault input is present up to the maximum count and falling by the pass decrement', None),
    (0x3fb064, 'governor_speed_below_flag', 'h_bridge_fault_latched_flag', 'set when the counter reaches the fault set threshold, cleared when it is back to 0; it sets fault 744 (mask 256, electrical fault) together with the inrush fault', None),
    (0x3fb066, 'governor_fuel_rate_b', 'h_bridge_inrush_fault_counter', 'inrush fault counter (same scheme as the fault counter)', None),
    (0x3fb068, 'governor_fuel_rate_d', 'h_bridge_fault_retry_timer', 'dword used as two words: word 0 = retry timer count, word 1 = latch (1 at the retry time, 0 at 0)', None),
    (0x3fb06a, 'governor_fuel_rate_d+2', 'h_bridge_fault_retry_timer+2', 'second word of the dword before it: the retry timer latch (the row exists only because the dword is used as two words)', None),
    (0x3fb06c, 'governor_fuel_rate_c', 'h_bridge_inrush_retry_timer', 'dword used as two words: word 0 = inrush retry timer count, word 1 = latch', None),
    (0x3fb06e, 'governor_fuel_rate_c+2', 'h_bridge_inrush_retry_timer+2', 'second word of the dword before it: the inrush retry timer latch', None),
]
for a, old, suf, code, _ in HB:
    gl(a, old, P + suf, code)

# companions of wave 5 dwords
gl(0x3fb076, 'protection_fault_condition_flag+2', P + 'position_fault_flags+2',
   'second word of the dword variable_geometry_turbocharger_position_fault_flags (wave 5 renamed the dword, its +2 row kept the old name)')
gl(0x3fb07e, 'protection_governor_active_flag+2', P + 'fault_holdoff_flags+2',
   'second word of the dword variable_geometry_turbocharger_fault_holdoff_flags (wave 5 renamed the dword, its +2 row kept the old name)')

# H-bridge runtime flags (block anchor 0x01183900 -> 0x40b050)
HBR = [
    (0x40b050, 'protection_overflow_flag', 'h_bridge_fault_clear_flag', '1 when the fault counter is 0 (the expression ~(-count >> 16) >> 15 in cm848_updateVariableGeometryTurbochargerHBridgeFaultCounter)', 'VGA_HB0_Fault_Clear'),
    (0x40b052, 'protection_confirm_b_flag', 'h_bridge_fault_retry_trigger_flag', 'set by the retry timer when the fault input is absent and the timer latch is 0', 'VGA_Fault_HB0_Retry'),
    (0x40b054, 'protection_confirm_c_flag', 'h_bridge_inrush_retry_trigger_flag', 'set by the inrush retry timer under the same condition', 'VGA_Fault_HB0_Inrush_Retry'),
    (0x40b056, 'governor_output_limit_flag', 'h_bridge_inrush_fault_clear_flag', '1 when the inrush fault counter is 0', 'VGA_HB0_Inrush_Fault_Clear'),
    (0x40b05a, 'governor_speed_below_threshold_flag', 'h_bridge_fault_set_flag', '1 when the fault counter is at or above the fault set threshold', 'VGA_HB0_Fault_Set'),
]
for a, old, suf, code, e in HBR:
    gl(a, old, P + suf, code, e, 'HB')

# H-bridge calibrations (block 0x01183C00 -> 0x407782)
HBC = [
    (0x407782, 'governor_fuel_rate_d_cal', 'h_bridge_fault_retry_time', 'limit of the retry timer count (dump 5)', 'C_VGA_HB0_Retry_Time'),
    (0x407784, 'governor_fuel_rate_a_threshold_cal', 'h_bridge_fault_maximum_count', 'upper clamp of the fault counter and the give-up test (dump 250)', 'C_VGA_Fault_HB0_Max_Count'),
    (0x407786, 'governor_fuel_rate_a_decay_step_cal', 'h_bridge_fault_pass_decrement', 'amount subtracted from the fault counter per passing pass (dump 5)', 'C_VGA_Fault_HB0_Pass_Decrt'),
    (0x407788, 'governor_fuel_rate_c_cal', 'h_bridge_inrush_retry_time', 'limit of the inrush retry timer count (dump 5)', 'C_VGA_HB0_Inrush_Retry_Time'),
    (0x40778a, 'governor_fuel_rate_b_threshold_cal', 'h_bridge_inrush_fault_maximum_count', 'upper clamp of the inrush fault counter and the give-up test (dump 50)', 'C_VGA_HB0_OC_Max_Count'),
    (0x40778c, 'governor_fuel_rate_b_decay_step_cal', 'h_bridge_inrush_fault_pass_decrement', 'amount subtracted from the inrush fault counter per passing pass (dump 50)', 'C_VGA_HB0_OC_Pass_Decrt'),
    (0x40778e, 'governor_fuel_rate_a_step_cal', 'h_bridge_fault_fail_increment', 'amount added to the fault counter per failing pass (dump 300)', 'C_VGA_Fault_HB0_Fail_Incrt'),
    (0x407790, 'governor_fuel_rate_b_step_cal', 'h_bridge_inrush_fault_fail_increment', 'amount added to the inrush fault counter per failing pass (dump 50)', 'C_VGA_HB0_OC_Fail_Incrt'),
    (0x407792, 'governor_fuel_rate_a_threshold_b_cal', 'h_bridge_fault_set_threshold', 'fault counter value at which the fault set flag is set (dump 300)', 'C_VGA_HB0_Fault_Set'),
    (0x407794, 'governor_fuel_rate_c_step_cal', 'h_bridge_inrush_retry_increment', 'inrush retry timer step while the input is present (dump 300)', 'C_VGA_HB0_Inrush_Retry_Incrt'),
    (0x407796, 'governor_fuel_rate_a_active_threshold_cal', 'h_bridge_inrush_fault_set_threshold', 'inrush fault counter value at which cm848_updateVariableGeometryTurbochargerHBridgeInrushFaultCounter returns true (dump 300); the old name sounded like the fault counter A but the single reader compares it with the inrush counter', 'C_VGA_HB0_OC_Fault_Set'),
    (0x407798, 'governor_fuel_rate_d_step_cal', 'h_bridge_fault_retry_increment', 'retry timer step while the fault input is present (dump 5)', 'C_VGA_HB0_Retry_Increment'),
]
for a, old, suf, code, e in HBC:
    gl(a, old, P + suf, code + '; xref: 1-2 reads / 0 writes, no user outside the H-bridge functions', e, 'HBCAL')

gl(0x3fd8d0, 'governor_fuel_rate_protection_enable_flag', P + 'h_bridge_fault_give_up_enable_cal',
   'EEPROM mirror word (dump 0): when non-zero the fault counter at its maximum count ends the retry (retry-active flag 0) for both the fault and the inrush counters (cm848_updateVariableGeometryTurbochargerHBridgeFaultCounter / ...InrushFaultCounter, the only readers). '
   'e2m: T_VGA_Enable_HB0_Give_Up (0x0119CB00) sits before T_VGT_Closed_Adjustment_Enable (0x0119CC00 = variable_geometry_turbocharger_closed_adjustment_enable_cal 0x3fd8d2) in both layouts (order only).')

# =============================================================================================
# 6. GLOBALS - position control diagnostic (bank 2), block 0x01183700 -> 0x40b042
# =============================================================================================
DG = [
    (0x40b042, 'protection_speed_track_criterion_met', 'drive_strongly_commanded_flag', '0 when the duty (signed toward the error) is below the strong drive threshold while the error exceeds the control error threshold, else 1', 'VGA_PWM_Is_Strongly_Commanded'),
    (0x40b044, 'protection_speedTracking_ramp_step_max_reached_flag', 'control_diagnostic_count_enabled_flag', '1 when the enable counter has reached the enable time (the fault counter may then count)', 'VGA_Control_Diag_Count_Enabled'),
    (0x40b046, 'protection_speed_track_active_flag', 'control_diagnostic_enable_flag', 'all conditions of the position control diagnostic are met (control state, no span error, motor ok, no sensor fault, steady command, strong drive)', 'VGA_Control_Diag_Enable'),
    (0x40b04a, 'protection_speed_error_over_threshold_flag', 'control_error_condition_flag', '1 when |position error| exceeds the control error threshold (position control fault present but not confirmed)', 'VGA_Control_Error_Condition'),
    (0x40b04c, 'protection_governor_output_ema', 'position_command_diagnostic_filtered', 'first-order filter of the staged position command (variable_geometry_turbocharger_position_command_final)', 'VGA_Filtered_Diag_Cmd'),
    (0x40b04e, 'protection_governor_output_deviation', 'position_command_deviation', 'staged position command minus its filtered value; the steady-state test uses its magnitude', 'VGA_Position_Cmd_Diff'),
]
for a, old, suf, code, e in DG:
    gl(a, old, P + suf, code, e, 'DIAG')
ng(0x40b048, P + 'control_diagnostic_fault_count_monitor', 'word',
   'xref_addr.py says word (0 reads / 2 writes): written by cm848_updateVariableGeometryTurbochargerPositionControlFaultCounter (copy of the fault counter) and the diagnostic init, never read; a monitoring copy',
   'VGA_Control_Diag_Fault_Count', 'DIAG')
gl(0x3fccf0, 'protection_speedTracking_ramp_step_counter', P + 'control_diagnostic_enable_counter',
   'counts passes of the diagnostic enable flag up to the enable time (reset to 0 when the flag drops)')
gl(0x3fccf2, 'protection_speedTracking_speed_error_ramp', P + 'control_diagnostic_fault_counter',
   'position control fault counter: + increment while the error condition is present and the count is enabled, - decrement otherwise, held while the count is not enabled, forced to 0 by variable_geometry_turbocharger_control_fault_counter_clear_cal; clamped at the fail threshold')
gl(0x3fccf4, 'protection_speedTracking_ramp_at_max_flag', P + 'control_error_latched_flag',
   'latched at the fail threshold, cleared when the counter falls to the pass threshold or below; sets / clears fault 743 (mask 128)')
def blank(addr, newfull, code, e2name=None, key=None, extra=''):
    cur = [r[1] for r in GV.get(addr, [])]
    assert cur == [''], (hex(addr), cur)
    check_new(newfull, addr, 'global')
    rows.append({'kind': 'global', 'address': '0x%08x' % addr, 'old': '', 'verdict': 'confirmed', 'new': newfull,
                 'evidence': 'row exists with an empty name. ' + evid(addr, code, e2name, key, extra)})


blank(0x3fcce8, P + 'position_command_diagnostic_filter_state',
      'ema_filter_state_t instance used by cm848_evaluateVariableGeometryTurbochargerPositionControlDiagnosticConditions (filters the staged position command) and initialised by the diagnostic init; its coefficient pointer is variable_geometry_turbocharger_position_command_diagnostic_filter_coefficient (xref_addr.py lists no load / store: reached by address)')

DGCAL = [
    (0x407772, 'protection_speedTracking_speed_error_threshold', 'control_error_threshold', '|position error| above it sets the control error condition; also used in the strong drive test (dump 12800)', 'C_VGA_Control_Error_Thd'),
    (0x407774, 'protection_speedTracking_ramp_step_count_max', 'control_diagnostic_enable_time', 'limit of the diagnostic enable counter (dump 300)', 'C_VGA_Control_Diag_Enable_Time'),
    (0x407776, 'protection_speedTracking_speed_error_ramp_step', 'control_fault_time_increment', 'added to the fault counter per pass with the error condition (dump 300)', 'C_VGA_Control_Fault_Time_Incrt'),
    (0x407778, 'protection_speedTracking_speed_error_ramp_decay', 'control_fault_time_decrement', 'subtracted from the fault counter per pass without the error condition (dump 300)', 'C_VGA_Control_Fault_Time_Decrt'),
    (0x40777c, 'protection_speedTracking_speed_error_ramp_max', 'control_fault_time_fail_threshold', 'clamp of the fault counter and the value at which the control error latches (dump 600)', 'C_VGA_Fail_Time_Thd'),
]
for a, old, suf, code, e in DGCAL:
    gl(a, old, P + suf, code + '; xref: 1 read / 0 writes', e, 'DIAGCAL')
ng(0x407770, P + 'steady_state_command_deviation_threshold', 'word',
   'xref_addr.py says word (1 read / 0 writes, lhz): the staged position command counts as steady while its deviation from the filtered value is below it (dump 0)',
   'C_VGA_Cmd_Rate_Thd', 'DIAGCAL')
ng(0x40777e, P + 'control_fault_time_pass_threshold', 'word',
   'xref_addr.py says word (1 read / 0 writes, lhz): the control error latch is cleared when the fault counter is at or below it (dump 300)',
   'C_VGA_Pass_Time_Thd', 'DIAGCAL')
ng(0x407780, P + 'control_strong_drive_duty_threshold', 'i16',
   'xref_addr.py says i16 (1 read / 0 writes, lha): signed threshold on the selected duty (signed toward the error) below which a large error does not count as strongly commanded (dump 12800)',
   'C_VGA_Control_PWM_Threshold', 'DIAGCAL')
blank(0x40777a, P + 'position_command_diagnostic_filter_coefficient',
      'EMA coefficient word (1/65536, dump 0) of the filter on the staged position command (the filter state 0x3fcce8 points here, set by the diagnostic init)',
      'C_VGA_Diag_Cmd_Fil_Cnst', 'DIAGCAL')
gl(0x3fd7de, 'throttle_rate_filter_active_flag', 'throttle_rate_filter_active_flag_cal',
   'wave 4 lead (note 56): the word is read-only (xref_addr.py: 2 reads / 0 writes, cm848_calculateTurboBlendOutput and cm848_calculateWastegateDutyRequest), lies in the EEPROM mirror 0x3fd482-0x3feec1 (dump 1) and so needs _cal; the domain part of the name stays open (it is read by two functions)')
ng(0x3fd8ce, P + 'control_fault_counter_clear_cal', 'word',
   'xref_addr.py says word (1 read / 0 writes, lhz): cm848_updateVariableGeometryTurbochargerPositionControlFaultCounter forces the fault counter to 0 when it is non-zero (dump 1, so the position control diagnostic cannot latch on this truck); EEPROM mirror word, hence _cal. '
   'e2m: T_VGA_Clear_Inrange_Error_Count (0x0119DA00) has the matching name only (its address does not sit in the packed T_ order), so the e2m part is name-level corroboration.')

# =============================================================================================
# 7. GLOBALS - thermal / current (bank 2), block 0x01183800 -> 0x40b07e
# =============================================================================================
ng(0x40b07e, P + 'motor_temperature_warning_flag', 'word',
   'xref_addr.py says word (0 reads / 1 write): set when the winding temperature is at or above the warning threshold (cm848_updateVariableGeometryTurbochargerMotorTemperature), never read',
   'VGA_Temperature_Warning', 'THERM')
THR = [
    (0x40b080, 'governor_rpm_monitored', 'motor_current', 'estimated valve motor current, 0.000976562 A per count (cm848_estimateVariableGeometryTurbochargerMotorCurrent); compared with the driver over-current threshold and with the steady-state current limit; not an rpm', 'VGA_Motor_Current'),
    (0x40b082, 'governor_b_rpm_squared_ema', 'motor_mean_squared_current', 'first-order filter of current x current >> 13', 'VGA_Mean_Squared_Current'),
    (0x40b084, 'governor_b_boost_demand_ema_eighth', 'motor_winding_temperature', 'filtered winding temperature in 1/8 degree F, limited to 4800; compared with the high / low / warning thresholds', 'VGA_Temperature'),
    (0x40b086, 'governor_b_boost_demand_floor', 'motor_ambient_temperature', 'coolant temperature plus the housing offset, limited to 20480 (1/64 degree F)', 'VGA_Ambient_Temperature'),
    (0x40b08a, 'governor_b_fuel_demand_ema', 'motor_iron_core_temperature', 'filtered iron core temperature in 1/64 degree F, limited to 38400', 'VGA_Temperature_1'),
    (0x40b092, 'governor_b_boost_demand_input', 'coolant_temperature', 'fuel_demand_boost_input (coolant temperature, 1/64 degree F) or the coolant default when sensor_generic_fault_status is above 1', 'VGA_Coolant_Temperature'),
]
for a, old, suf, code, e in THR:
    gl(a, old, P + suf, code, e, 'THERM')
ng(0x40b088, P + 'circuit_resistance', 'word',
   'xref_addr.py says word (0 reads / 1 write): the circuit resistance used by the current estimate (reference resistance + winding temperature x coefficient, limited to 16000), stored as a word',
   'VGA_Circuit_Resistance', 'THERM')
ng(0x40b08c, P + 'motor_iron_core_temperature_filter_input', 'word',
   'xref_addr.py says word (0 reads / 1 write): ambient + (winding - ambient) x temperature fraction, limited to 0..38400; input of the iron core temperature filter',
   'VGA_Tmptr_1_Fil_Input', 'THERM')
ng(0x40b08e, P + 'motor_winding_temperature_filter_input', 'word',
   'xref_addr.py says word (0 reads / 1 write): mean-squared current x normalized resistance >> 11 + iron core temperature >> 3, limited to 65535; input of the winding temperature filter',
   'VGA_Tmptr_Fil_Input', 'THERM')
ng(0x40b090, P + 'back_electromotive_force', 'word',
   'xref_addr.py says word (0 reads / 1 write): the working back electromotive force >> 1, written as a (short)',
   'VGA_Back_EMF', 'THERM')
TS_STATE = [
    (0x3fccfe, 'governor_b_fuel_limit_biased', 'drive_duty_biased', '|drive duty limited| plus the drive duty offset'),
    (0x3fcd00, 'governor_b_timing_error_scaled', 'motor_applied_voltage', 'biased duty x fuel_timing_error_scale >> 7 while logical output request 72 is set and fault 744 is clear, else 0: the voltage applied to the motor'),
    (0x3fcd04, 'governor_b_ema_offset_delta_scaled', 'motor_back_electromotive_force_working', 'change of the position sensor value x the speed back electromotive force factor >> 10, limited to +-64000, sign flipped when the previous direction request was clear'),
    (0x3fcd08, 'governor_b_timing_ema_deviation', 'motor_voltage_across_resistance', '|applied voltage - back electromotive force|'),
    (0x3fcd0c, 'governor_b_boost_normalization_factor', 'circuit_resistance_working', 'reference resistance + winding temperature x coefficient >> 10, limited to 16000: the divisor of the current estimate'),
    (0x3fcd10, 'governor_b_timing_deviation_normalized', 'motor_current_working', 'voltage across the resistance x 1024 / resistance, limited to the current maximum; copied to variable_geometry_turbocharger_motor_current'),
    (0x3fcd14, 'governor_b_ema_offset_prev', 'position_sensor_value_previous', 'variable_geometry_turbocharger_position_sensor_value of the previous pass (the back electromotive force follows its change); set by the thermal init'),
    (0x3fcd16, 'governor_b_engine_flag_80_prev', 'direction_request_previous_flag', 'bit 0x80 of logical_output_request_bits_64_to_71 (request 71, the valve direction request) of the previous pass'),
    (0x3fcd28, 'boost_demand_diag_debounce_count', 'valve_over_temperature_inhibit_counter', 'passes with no other explanation of a hot motor, counted up to the inhibit time (cm848_updateVariableGeometryTurbochargerValveOverTemperatureFault)'),
]
for a, old, suf, code in TS_STATE:
    gl(a, old, P + suf, code)
blank(0x3fccf6, P + 'motor_mean_squared_current_filter_state',
      'ema_filter_state_t instance used by cm848_updateVariableGeometryTurbochargerMeanSquaredCurrent (xref_addr.py lists no load / store: reached by address); coefficient pointer variable_geometry_turbocharger_mean_squared_current_filter_coefficient')
blank(0x3fcd18, P + 'motor_winding_temperature_filter_state',
      'ema_filter_state_t instance of the winding temperature filter in cm848_updateVariableGeometryTurbochargerMotorTemperature (reached by address); coefficient pointer variable_geometry_turbocharger_motor_winding_temperature_filter_coefficient')
blank(0x3fcd20, P + 'motor_iron_core_temperature_filter_state',
      'ema_filter_state_t instance of the iron core temperature filter in cm848_updateVariableGeometryTurbochargerMotorTemperature (reached by address); coefficient pointer variable_geometry_turbocharger_motor_iron_core_temperature_filter_coefficient')

# thermal calibration block 0x01183A00 -> 0x4077b8
THC = [
    (0x4077c0, 'governor_b_timing_deviation_max', 'motor_current_maximum', 'ceiling of the current estimate (dump 10240 = 10 A); the old name was a timing deviation guess', 'C_VGA_Max_Current'),
    (0x4077ce, None, 'normalized_resistance', 'multiplies the mean-squared current in the winding temperature filter input (dump 518)', 'C_VGA_Normalized_Resistance'),
    (0x4077d0, None, 'reference_resistance', 'added to the temperature term of the circuit resistance (dump 4859)', 'C_VGA_Ref_Resistance'),
    (0x4077d2, None, 'resistance_temperature_coefficient', 'multiplies the winding temperature in the circuit resistance (dump 399)', 'C_VGA_Resistance_Tmptr_Coeff'),
    (0x4077d8, None, 'motor_temperature_fraction', 'fraction of (winding - ambient) added to the ambient temperature for the iron core node, x 1/1024 (dump 732)', 'C_VGA_Tmptr_Fraction'),
    (0x4077dc, None, 'valve_over_temperature_inhibit_time', 'limit of the inhibit counter (dump 50)', 'C_VGA_Inhibit_Over_Temp_Time'),
    (0x4077be, None, 'housing_temperature_offset', 'added to the coolant temperature to get the ambient temperature (dump 2304 = 36 degrees F at 1/64)', 'C_VGA_Housing_Tmptr_Offset'),
    (0x4077c4, None, 'speed_back_electromotive_force_factor', 'multiplies the change of the position sensor value (>> 10) to give the back electromotive force (dump 6400)', 'C_VGA_Speed_EMF_Factor'),
    (0x4077c8, None, 'motor_temperature_high_threshold', 'winding temperature (1/8 degree F) at or above which fault 746 is set (dump 4000 = 500 degrees F)', 'C_VGA_Tmptr_High_Threshold'),
    (0x4077ca, None, 'motor_temperature_low_threshold', 'winding temperature at or below which fault 746 is cleared (dump 3200 = 400 degrees F)', 'C_VGA_Tmptr_Low_Threshold'),
    (0x4077cc, None, 'motor_temperature_warning_threshold', 'winding temperature at or above which the warning flag is set (dump 3160)', 'C_VGA_Tmptr_Warning_Threshold'),
]
for a, old, suf, code, e in THC:
    if old:
        gl(a, old, P + suf, code, e, 'THERMCAL')
    else:
        ng(a, P + suf, 'word', 'xref_addr.py says word (1 read / 0 writes, lhz): ' + code, e, 'THERMCAL')
ng(0x4077c2, P + 'drive_duty_offset', 'i16',
   'xref_addr.py says i16 (1 read / 0 writes, lha): added to |drive duty limited| before the voltage scaling (dump 64896 = -640, i.e. -5 percent)',
   'C_VGA_PWM_Offset', 'THERMCAL')
gl(0x4077da, 'governor_b_boost_demand_minimum', P + 'coolant_temperature_default',
   'substituted for the coolant temperature when sensor_generic_fault_status is above 1, and the limit under which the valve over-temperature timer counts (dump 14080 = 220 degrees F at 1/64 F); xref: 2 reads / 0 writes, lha',
   'C_VGA_Coolant_Tmptr_Default', 'THERMCAL')
blank(0x4077ba, P + 'mean_squared_current_filter_coefficient',
      'EMA coefficient word (dump 52428 = 0.8) of the mean-squared current filter (the filter state 0x3fccf6 points here); xref lists only the address-of in the thermal init',
      'C_VGA_Current_Avg_Fil_Cnst', 'THERMCAL')
blank(0x4077d4, P + 'motor_winding_temperature_filter_coefficient',
      'EMA coefficient word (dump 65372) of the winding temperature filter (state 0x3fcd18 points here)', 'C_VGA_Tmptr_Fil_Cnst_1', 'THERMCAL')
blank(0x4077d6, P + 'motor_iron_core_temperature_filter_coefficient',
      'EMA coefficient word (dump 65317) of the iron core temperature filter (state 0x3fcd20 points here)', 'C_VGA_Tmptr_Fil_Cnst_2', 'THERMCAL')

# =============================================================================================
# 8. GLOBALS - driver over-current (block 0x01190B00 -> 0x4077a8 and 0x01190C00 -> 0x40b078)
# =============================================================================================
OCS = [
    (0x3fb098, 'governor_protection_active', 'driver_over_current_retry_active_flag', 'clear / retry active: the retry trigger is set and the fault was not given up (cm848_updateVariableGeometryTurbochargerDriverOverCurrentFault); 0 while the over-current is flagged and not yet retriable, which sets fault 745'),
    (0x3fb09a, 'governor_high_mode_state_flag', 'driver_over_current_retry_active_previous_flag', 'retry-active flag of the previous pass (history for the fail counter decay)'),
    (0x3fb09c, 'governor_high_mode_prev_flag', 'driver_over_current_retry_active_previous_2_flag', 'retry-active flag two passes ago (written only)'),
    (0x3fb09e, 'governor_demand_rate_a', 'driver_over_current_set_timer', 'time over the current threshold: +time increment per pass over the threshold up to the set time, - time decrement otherwise'),
    (0x3fb0a0, 'governor_demand_rate_minimum', 'driver_over_current_clear_timer', 'passes without the over-current flag, counted up to the clear time (reset to 0 while flagged)'),
    (0x3fb0a2, 'governor_demand_rate_b', 'driver_over_current_fault_counter', 'give-up accumulator: + fail increment per flagged retry cycle up to the maximum count, - pass decrement while retrying'),
]
for a, old, suf, code in OCS:
    gl(a, old, P + suf, code)
OCR = [
    (0x40b078, 'governor_rate_limit_flag', 'driver_over_current_retry_trigger_flag', '1 when the clear timer has reached the clear time', 'VGA_Driver_OC_Fault_Retry'),
    (0x40b07a, 'governor_protection_active_prev', 'driver_over_current_clear_conditions_met_flag', 'copy of the retry-active flag after the update', 'VGA_Driver_OC_Fault_Clear'),
    (0x40b07c, 'governor_demand_rate_a_flag', 'driver_over_current_detected_flag', '1 when the set timer has reached the set time: the motor current was over the threshold for the set time', 'VGA_Driver_OC_Fault_Bit'),
]
for a, old, suf, code, e in OCR:
    gl(a, old, P + suf, code, e, 'OCR')
OCC = [
    (0x4077a8, 'governor_demand_rate_confirm_count_cal', 'driver_over_current_clear_time', 'limit of the clear timer (dump 192)', 'C_VGA_Driver_OC_Clear_Time'),
    (0x4077aa, 'governor_demand_rate_b_step_cal', 'driver_over_current_fail_increment', 'added to the give-up accumulator per failing retry cycle (dump 2000)', 'C_VGA_Driver_OC_Fail_Incrt'),
    (0x4077ac, 'governor_demand_rate_b_limit_cal', 'driver_over_current_maximum_count', 'upper clamp of the give-up accumulator and the give-up level (dump 30000)', 'C_VGA_Driver_OC_Max_Count'),
    (0x4077ae, 'governor_demand_rate_b_decay_step_cal', 'driver_over_current_pass_decrement', 'subtracted from the give-up accumulator while retrying without a new over-current (dump 1)', 'C_VGA_Driver_OC_Pass_Decrt'),
    (0x4077b0, 'governor_demand_rate_a_limit_cal', 'driver_over_current_set_time', 'limit of the set timer: the over-current is flagged at it (dump 4000)', 'C_VGA_Driver_OC_Set_Time'),
    (0x4077b2, 'governor_rpm_monitor_threshold', 'driver_over_current_threshold', 'motor current threshold, 0.000976562 A per count (dump 14336 = 14 A); compared with variable_geometry_turbocharger_motor_current, not an rpm', 'C_VGA_Driver_OC_Threshold'),
    (0x4077b4, 'governor_demand_rate_a_decay_step_cal', 'driver_over_current_time_decrement', 'subtracted from the set timer per pass under the threshold (dump 3)', 'C_VGA_Driver_OC_Time_Decrt'),
    (0x4077b6, 'governor_demand_rate_a_step_cal', 'driver_over_current_time_increment', 'added to the set timer per pass over the threshold (dump 10)', 'C_VGA_Driver_OC_Time_Incrt'),
]
for a, old, suf, code, e in OCC:
    gl(a, old, P + suf, code + '; xref: 1 read / 0 writes in cm848_updateVariableGeometryTurbochargerDriverOverCurrentFault', e, 'OCCAL')

# =============================================================================================
# 9. GLOBALS - calibration block 0x40771a-0x40776c (block anchor 0x01183000 -> 0x40771a)
# =============================================================================================
CALROWS = [
    (0x40771a, 'actuator_e_setpoint_override', 'position_command_override_value', 'single reader cm848_calculateVariableGeometryTurbochargerPositionCommand uses it as the position command when bit 0 of the user override flags is set (dump 0)', 'C_VGA_Cmd_Override_Value'),
    (0x40771c, 'governor_speed_i_gain_b_high_cal', 'derivative_gain_normal', 'copied to the derivative gain when the position command is above the gain scheduling threshold (dump 0)', 'C_VGA_D_Gain_Normal'),
    (0x40771e, 'governor_speed_i_gain_b_low_cal', 'derivative_gain_open', 'copied to the derivative gain at or below the gain scheduling threshold (dump 0)', 'C_VGA_D_Gain_Open'),
    (0x407720, 'governor_ema_filter_state_cal', 'derivative_filter_coefficient', 'coefficient word of the first-order filter on the position error (the pointer variable_geometry_turbocharger_derivative_filter_coefficient_pointer is set to its address by the loop init; dump 32768 = 0.5); the row is typed byte, the filter reads it as a word; xref_addr.py lists no load / store (reached by address in the loop init)', 'C_VGA_Der_Dtime_Cnst'),
    (0x407722, 'governor_speed_i_gain_deadzone_cal', 'derivative_noise_band', 'the derivative term is 0 while the magnitude of the filtered error change is below it (dump 0)', 'C_VGA_Der_Noise_Band'),
    (0x407724, 'governor_proportional_gain_high_cal', 'integral_gain_normal', 'copied to the integral gain in the normal gain set (dump 0)', 'C_VGA_I_Gain_Normal'),
    (0x407726, 'governor_proportional_gain_low_cal', 'integral_gain_open', 'copied to the integral gain in the open gain set (dump 0)', 'C_VGA_I_Gain_Open'),
    (0x407728, 'governor_integral_limit_high_cal', 'integral_term_lower_limit_normal', 'lower limit of the integral accumulator (<< 14) in the normal gain set (dump 0)', 'C_VGA_I_Term_LLim_Normal'),
    (0x40772a, 'governor_integral_limit_low_cal', 'integral_term_lower_limit_open', 'lower limit of the integral accumulator in the open gain set (dump 62336 = -3200 as a signed word)', 'C_VGA_I_Term_LLim_Open'),
    (0x40772c, 'governor_fuel_integral_b_upper_limit_cal', 'integral_term_upper_limit', 'upper limit of the integral accumulator (<< 14) (dump 0)', 'C_VGA_I_Term_ULim'),
    (0x40772e, 'governor_fuel_bias_high_cal', 'load_offset_normal', 'feedforward load offset of the normal gain set (dump 0)', 'C_VGA_Load_Offset_Normal'),
    (0x407730, 'governor_fuel_bias_low_cal', 'load_offset_open', 'feedforward load offset of the open gain set (dump 0)', 'C_VGA_Load_Offset_Open'),
    (0x407732, 'governor_fuel_limit_disable_cal', 'motor_direction_reversal', 'direction invert flag of the output stage (dump 1); the wave 4 agent already noted it is not a limit disable', 'C_VGA_Motor_Direction_Reversal'),
    (0x407734, 'governor_speed_p_gain_b_high_cal', 'proportional_gain_normal', 'proportional gain of the normal gain set (dump 128 = 1.0)', 'C_VGA_P_Gain_Normal'),
    (0x407736, 'governor_speed_p_gain_b_low_cal', 'proportional_gain_open', 'proportional gain of the open gain set (dump 128)', 'C_VGA_P_Gain_Open'),
    (0x407738, 'governor_derivative_gain_high_cal', 'position_reference_filter_coefficient_normal', 'coefficient of the position reference filter in the normal gain set (dump 0)', 'C_VGA_Prefilter_Cnst_Normal'),
    (0x40773a, 'governor_derivative_gain_low_cal', 'position_reference_filter_coefficient_open', 'coefficient of the position reference filter in the open gain set (dump 55476 = 0.847)', 'C_VGA_Prefilter_Cnst_Open'),
    (0x40773c, 'fuel_control_upper_limit_cal', 'drive_duty_lower_limit', 'the larger of it and minus the working duty limit is the LOWER bound of the limited duty (cm848_limitVariableGeometryTurbochargerBatteryCompensatedDuty); the old name said upper (dump 0)', 'C_VGA_PWM_LLim'),
    (0x40773e, 'governor_fuel_output_a_lower_limit_cal', 'drive_duty_override_lower_limit', 'lower bound of the override duties of control states 1 to 5 (dump 0)', 'C_VGA_PWM_Override_LLim'),
    (0x407740, 'governor_fuel_output_mode1_cal', 'drive_duty_override_value', 'duty output in control state 2 (user override) (dump 0)', 'C_VGA_PWM_Override_Value'),
    (0x407742, 'governor_fuel_output_a_upper_limit_cal', 'drive_duty_override_upper_limit', 'upper bound of the override duties (dump 12800); xref: 2 reads (lha and lhz)', 'C_VGA_PWM_Override_ULim'),
    (0x407744, 'governor_fuel_output_invert_cal', 'drive_duty_polarity_reversal', 'when non-zero the duty magnitude is replaced by 12800 minus it (dump 0)', 'C_VGA_PWM_Polarity_Reversal'),
    (0x407746, 'governor_fuel_upper_limit_cal', 'drive_duty_upper_limit', 'upper bound of the limited duty, the smaller of it and the working limit applies (dump 11648)', 'C_VGA_PWM_ULim'),
    (0x407748, 'governor_proportional_gain_threshold_cal', 'steady_state_error_band', 'the integral input is the error only while its magnitude exceeds it (dump 64)', 'C_VGA_SS_Error_Band'),
    (0x40774a, 'throttle_speed_rate_lower_cal', 'open_stage_command_threshold', 'upper limit and restart value of the open staging ramp (dump 0)', 'C_VGA_Open_Stage_Cmd_Thd'),
    (0x40774c, 'governor_speed_tracking_lower_threshold_cal', 'open_stage_position_threshold', 'the open staging ramp steps only while the position is below it (dump 0)', 'C_VGA_Open_Stage_Position_Thd'),
    (0x40774e, 'governor_speed_tracking_offset_cal', 'open_stage_ramp_rate', 'open staging ramp step per pass, signed (dump 65504 = -32)', 'C_VGA_Open_Stage_Ramp_Rate'),
    (0x407750, 'governor_fuel_output_mode0_cal', 'open_hold_drive_duty', 'duty output in control state 1, the open-loop hold (dump 0)', 'C_VGA_Open_Hold_PWM'),
    (0x407752, 'governor_output_zero_threshold_cal', 'open_position_threshold', 'position and staged command at or below it count as fully open in the hold-open check (dump 0)', 'C_VGA_Open_Position_Thd'),
    (0x407754, 'j1939_governor_output_param_cal', 'motor_pwm_period', 'PWM period set on the output channel record at boot (dump 2857 microseconds); nothing j1939', 'C_VGA_PWM_Abs_PWM_Period_Cal'),
    (0x407756, 'actuator_e_setpoint_upper_limit', 'position_command_upper_limit', 'caps the position command (dump 12800 = 100 percent)', 'C_VGA_Cmd_ULim'),
    (0x407758, 'governor_output_update_enable_cal', 'direction_change_zero_duty_enable', 'when non-zero the duty is forced to 0 for one pass after a direction change (dump 1)', 'C_VGA_Dir_Chg_PWM_Delay_Enable'),
    (0x40775a, 'governor_fuel_output_zero_threshold_cal', 'drive_duty_zero_threshold', 'a duty magnitude below it is forced to 0 (dump 640)', 'C_VGA_PWM_Zero_Thd'),
    (0x40775c, 'throttle_speed_rate_upper_cal', 'closed_stage_command_threshold', 'lower limit and restart value of the closed staging ramp (dump 12800)', 'C_VGA_Closed_Stage_Cmd_Thd'),
    (0x40775e, 'governor_speed_tracking_upper_threshold_cal', 'closed_stage_position_threshold', 'the closed staging ramp steps only while the position is above it (dump 12800)', 'C_VGA_Closed_Stage_Position_Thd'),
    (0x407760, 'governor_speed_tracking_upper_offset_cal', 'closed_stage_ramp_rate', 'closed staging ramp step per pass (dump 32)', 'C_VGA_Closed_Stage_Ramp_Rate'),
    (0x407762, 'governor_gain_select_fuel_threshold_cal', 'gain_scheduling_position_threshold', 'position command above it selects the normal gain set, otherwise the open set (dump 0)', 'C_VGA_Gain_Scheduling_Pos_Thd'),
    (0x407764, 'throttle_zero_confirm_count_cal', 'open_hold_maximum_time', 'passes the position command must stay 0 before the hold-open condition is met without the near-open test (dump 0); xref: 2 reads', 'C_VGA_Max_Time_To_Open_Hold'),
    (0x407766, 'actuator_e_end_margin', 'closed_position_tolerance', 'margin of the position command clamp while fault 670 is set, of the closed-stop seek and of the closed adjustment out-of-tolerance test: the closed position tolerance (dump 1856 = 14.5 percent); xref: 3 reads / 0 writes', 'C_VGT_Closed_Position_Tolerance'),
    (0x40776a, 'governor_derivative_rpm_threshold_cal', 'steady_state_current_maximum', 'motor current at or above it switches on the friction avoidance term (dump 2765 = 2.7 A); compared with variable_geometry_turbocharger_motor_current, not an rpm', 'C_VGA_Max_SS_Current'),
    (0x40776c, 'governor_derivative_limit_cal', 'friction_avoidance_decrement', 'magnitude of the friction avoidance term (dump 33); xref: 2 reads', 'C_VGA_Friction_Avoidance_Decrt'),
]
for a, old, suf, code, e in CALROWS:
    gl(a, old, P + suf, code + ('; xref: 1 read / 0 writes' if 'xref' not in code else ''), e, 'CAL',
       extra='Outside the EEPROM mirror, so no _cal.' if '_cal' in old else '')

# EEPROM mirror and output words
gl(0x3fd8cc, 'actuator_e_override_flags_cal', P + 'user_override_flags_cal',
   'bit 0 = position command override (cm848_calculateVariableGeometryTurbochargerPositionCommand), bit 1 = fixed override duty, control state 2 (cm848_selectVariableGeometryTurbochargerControlState); dump 0; EEPROM mirror, so _cal stays. '
   'e2m: T_VGA_Cmd_User_Override (0x01183200 mask 0x0001) / T_VGA_PWM_User_Override (mask 0x0002) are bits 0 / 1 of the word that anchors 0x3fd8cc.')
gl(0x3fdcea, 'actuator_output_channel_e_cal', P + 'motor_pwm_output_channel_cal',
   'EEPROM 0x868 = output channel assignment entry 43 (record 1-50, 0 = none; 0 in this calibration): the PWM channel of the valve motor, enabled and set up by cm848_initializeVariableGeometryTurbochargerPositionControlLoop and driven by cm848_outputVariableGeometryTurbochargerDirectionAndDuty (the only two users, 9 + 3 reads). '
   'e2m (name level only, no offset anchor): VGA_PWM_Abs_Map (0x01156556, "mapping index to HW_id") is the hardware assignment of the valve motor PWM output.')
gl(0x40c18e, 'actuator_e_duty_command', P + 'motor_pwm_duty_command',
   'last duty 0-25600 sent to the output channel of entry 43 (per-entry duty cache 0x40c138 + 2 x entry), written next to each set-duty call of the loop output stage and init (xref_addr.py lists only those two valve functions, 0 reads / 2 writes; an indexed access to the per-entry cache by generic output channel code would not show there). e2m (name level only): VGA_PWM_Abs_Duty_Cycle (0x01151C56) is the monitored duty of the valve motor PWM output.')
gl(0x40c244, 'actuator_e_period_command', P + 'motor_pwm_period_command',
   'last PWM period sent to the output channel of entry 43 (per-entry period cache), written by the loop init from variable_geometry_turbocharger_motor_pwm_period (xref_addr.py lists only that function, 0 reads / 1 write, dword; indexed accesses by generic output channel code would not show there). e2m (name level only): VGA_PWM_Abs_Period (0x011527AC) is the monitored period of the valve motor PWM output.')

# logical output request bytes
gl(0x40c088, 'engine_feature_status_flags', 'logical_output_request_bits_64_to_71',
   'byte 8 of the 80-bit logical output request array at 0x40c080 (cm848_setLogicalOutputRequest sets bit n & 7 of byte n >> 3, so requests 64-71): bit 0x80 = request 71, the valve direction request '
   '(set / cleared by cm848_outputVariableGeometryTurbochargerDirectionAndDuty with cm848_setLogicalOutputAndDriveLine(0x47)); read by the motor current estimate and the thermal init (mask 0x80) and by four outside readers '
   'that test masks 0x08 / 0x10 (requests 67 / 68). e2m: VGA_Motor_Cmd_Closing_Direction (0x01157708) has mask 0x80; the byte was never written directly because the setter indexes the array, hence xref "never written".')
gl(0x40c089, 'engine_feature_status_flags_2', 'logical_output_request_bits_72_to_79',
   'byte 9 of the logical output request array at 0x40c080: bit 0x01 = request 72, the valve driver enable (requested by cm848_sequenceVariableGeometryTurbochargerPositionAdjustment); tested by cm848_selectVariableGeometryTurbochargerControlState (clear = control state 5, driver disabled) '
   'and by the motor current estimate. e2m: VGA_PWM_Enable (0x01157709) has mask 0x01, the byte right after the direction byte.')

# fault words
gl(0x3fe9d6, 'diagnostic_status_flags_b', 'fault_detected_bits_784_to_799',
   'word 49 of the 50-word fault-detected array that starts at 0x3fe974 ((0x3fe9d6 - 0x3fe974) / 2 = 49, faults 784-799); mask 0x400 (fault 794) is set by cm848_updateVariableGeometryTurbochargerValveOverTemperatureFault, other users cm848_processSensorMonitoringLogic and cm848_calibration_group21_load_cont '
   '(8 reads / 4 writes in all); named like the other array words (wave 5). Not a valve word, so no turbocharger prefix. e2m places the valve over-temperature fault 8 bytes after the 736 word with mask 0x0800, the code 6 bytes after with 0x400: code only.')
gl(0x3fea3a, 'diagnostic_status_flags_b_shadow', 'fault_registered_bits_784_to_799',
   'word 49 of the registered array that starts at 0x3fe9d8 ((0x3fea3a - 0x3fe9d8) / 2 = 49), the registered copy of fault_detected_bits_784_to_799 (cleared with mask 0xfbff by the valve over-temperature timer; other user cm848_processSensorMonitoringLogic).')

# channel 101 struct rows (wave 5 lead)
blank(0x59656, P + 'position_sensor_config',
      'sensor_channel_config_t calibration block of sensor channel 101, passed by cm848_readVariableGeometryTurbochargerPositionSensor / cm848_initializeVariableGeometryTurbochargerPositionSensor; follows the barometric_pressure_sensor_config precedent (0x592a2). '
      'It holds the default value 0x2400 = 9216 and the linearization tables wave 5 named')
blank(0x40a12e, P + 'position_sensor_state',
      'sensor_channel_state_t RAM state of sensor channel 101 passed by the same two functions; follows the barometric_pressure_sensor_state precedent (0x40a062)')

# uncertain / shared words: no name proposed
gl(0x40a34c, 'fuel_timing_error_scale', None,
   'shared word, no VGT prefix: written by cm848_selectTurboModeParameters from fuel_timing_sensor_value (sensor channel 4) or its default when sensor_channel4_fault_status is 2; read by cm848_calculateSensorDiagnosticValue, cm848_calculateFuelDemandLimits, '
   'cm848_limitVariableGeometryTurbochargerBatteryCompensatedDuty and the motor current estimate (as the supply voltage). The value reads like the battery voltage in 1/16 V (dump 192 = 12.0 V) and boost_fuel_scale_cal (0x4067ea, 224 = 14.0 V) like its reference, '
   'and e2m calls the compensated duty VGA_PWM_Battery_Compensated, but the identity of sensor channel 4 is not settled here and the words are shared with the actuator g module: name kept, a battery voltage pass is the right place.',
   verdict='uncertain')
gl(0x40a61c, 'fuel_demand_boost_input', None,
   'shared word (17 referencing functions), no VGT prefix: cm848_mainLoop_step_3 copies a generic sensor channel output (0x40bd88, default 0x40bdae) into it; the valve thermal model uses it as the coolant temperature in 1/64 degree F '
   '(it is compared with the 220 degrees F default and offset by the housing temperature). Its identity (engine coolant temperature) is likely but not settled from this module alone: name kept.',
   verdict='uncertain')

# =============================================================================================
# 10. NOTES
# =============================================================================================
note('RESULT (answers the wave 4 / wave 5 lead): the wave 4 "actuator E" loop is the position servo of the variable geometry turbocharger valve, the same module wave 5 named variable_geometry_turbocharger_*. '
     '@COUNTS@ are proposed below (every row cites the proposed names, so apply them together with wave 5 as it stands in the CSVs). '
     'CODE (proven): the loop feedback is variable_geometry_turbocharger_position (sensor channel 101, wave 5), its setpoint is the boost controller request '
     '(wastegate_duty_controller_state.request_half_duty_counts, same 12800 scale, the wastegate solenoid reads that request directly), it drives a signed duty as logical output 71 (direction) plus a PWM on output channel entry 43 and is enabled by logical output 72, '
     'and wave 5 key-on stop-seek stages force its control states 3 / 4; cm848_phase_common_processing runs sensor read, loop, position adjustment sequencer and position update in that order, and the boot init sequence (lines 54427-54433 of the decompile) calls the loop init, '
     'the position control diagnostic init, the H-bridge clear, wave 5 stop-seek clear, the over-current clear, the thermal init and wave 5 adjustment filter init back to back. xref_addr.py on every renamed word shows no user outside this module '
     '(exceptions are named in rows and notes: logical_output_request_bits_64_to_71 and fault_detected_bits_784_to_799). '
     'E2M (corroboration only; e2m is the .12 file, the ECU is .06): the layouts agree word for word at equal relative offsets, checked by the generator with arithmetic for every row: calibration block 0x01183000 -> 0x40771a (43 words +0x00..+0x54), '
     'RAM block 0x01183100 -> 0x40b002 (32 words +0x00..+0x3E: control state, D / I / P gains and terms, feedforward, PID duty, position command and references, battery compensated / selected / clamped duty, direction change, dead band, duty limits, friction avoidance), '
     'diagnostics 0x01183700 -> 0x40b042, thermal and current 0x01183800 -> 0x40b07e, H-bridge flags 0x01183900 -> 0x40b050, H-bridge calibration 0x01183C00 -> 0x407782, diagnostic calibration 0x01183B00 -> 0x407770, driver over-current 0x01190B00 / 0x01190C00 -> 0x4077a8 / 0x40b078, '
     'thermal calibration 0x01183A00 -> 0x4077b8; the fault masks 4 / 8 / 16 / 32 / 64 / 128 / 256 / 512 / 1024 of fault_detected_bits_736_to_751 are the e2m masks of VGA_Fault_HB0A / HB0B / HB0_OC_HI / HB0_OC_LO / HB0_Inrush / VGA_Control_Error / VGA_Electrical_Fault / VGA_Driver_Over_Current / VGA_Over_Temperature. '
     'NOT PROVEN BY CODE: the turbocharger label and the presence of the part; on this truck output channel entry 43 is 0 and logical output 71 maps to no line, so the loop computes (duty 20778 in the dump) and drives nothing, the position control diagnostic is held off (0x3fd8ce = 1). '
     'Where e2m and code disagree the code wins (five e2m control states against six in the code; the e2m descriptions of C_VGA_Control_Fault_Time_Incrt / Decrt swapped; e2m calls the inrush counter words C_VGA_HB0_OC_* while the code uses them for the inrush fault).')

note('TWIN MODULE (not renamed here): cm848_calculateFuelDemandLimits (0x19ea4) and cm848_applyFuelDemandProtection have the same structure as cm848_limitVariableGeometryTurbochargerBatteryCompensatedDuty / the output stage '
     '(duty x boost_fuel_scale_cal / fuel_timing_error_scale, limits of +-12800 = 0x3200, magnitude x 2 as the PWM duty; the output channel word actuator_output_channel_g_cal = entry 39, driven by cm848_applyFuelDemandProtection). It looks like a second instance of the same motor control code, '
     'possibly the EGR valve (the e2m C_VGA texts mention an EGR motor and VGR), with governor_speed_b_* / governor_speed_range_* words. It shares fuel_timing_error_scale / boost_fuel_scale_cal with the VGT loop, which is why those two words carry no turbocharger prefix. '
     'Only the start of cm848_applyFuelDemandProtection was read here; its re-domaining is a separate lead.')

note('CONTROL STATE ENUM (suggestion, not a row): variable_geometry_turbocharger_control_state (0x40b008) takes 0 closed loop, 1 hold open (open-loop), 2 user duty override, 3 open-stop diagnostic drive, 4 closed-stop diagnostic drive, 5 driver disabled '
     '(logical output 72 clear); a VARIABLE_GEOMETRY_TURBOCHARGER_CONTROL_STATE enum with CLOSED_LOOP / HOLD_OPEN / DUTY_OVERRIDE / OPEN_STOP_DIAGNOSTIC_DRIVE / CLOSED_STOP_DIAGNOSTIC_DRIVE / DRIVER_DISABLED would also type variable_geometry_turbocharger_control_state_previous.')

note('TYPE NOTES (no change proposed): 0x407720 (variable_geometry_turbocharger_derivative_filter_coefficient) is typed byte but the filter reads a word; the dwords 0x3fb068 / 0x3fb06c are used as {count word, latch word} (rows +2 exist); '
     '0x3fb03e + 0x3fb042 are one filter state (coefficient pointer + accumulator) read through the address of 0x3fb03e; 0x3fb036 and the instances 0x3fcce8 / 0x3fccf6 / 0x3fcd18 / 0x3fcd20 are ema_filter_state_t reached by address; '
     '0x407780 and 0x4077c2 are loaded signed (lha), as are the gain, limit, ramp and duty calibration words 0x40771c-0x407740 / 0x40774a / 0x40774e / 0x407750 / 0x40775c-0x407762 (they stay word in the CSV, wave 5 left the same kind of word alone); '
     '0x40b090 holds a signed value written as a (short). The wave 4 type notes (row 57: 0x4087c4, 0x3ffc9a / 0x3ffc9c, 0x3ffcaa) are alternator / wastegate words outside this module and still unsettled here: skipped.')

note('NOT PART OF THE LOOP: mpc555_initFuelControlModeVariables (0x2c9bc) stays as is, see its function row. The words 0x3fb018-0x3fb026 it writes are shared with cm848_processProtectionEntry. '
     'Also unchanged and shared with other modules: supervisor_register_162_status (0x40b224; its comment cites cm848_initProtectionControlState, which is now cm848_processVariableGeometryTurbochargerHBridgeFaults, and cm848_processFuelDemandFaultConditions), '
     'fuel_feature_control_flags bit 0 and switch_input_state_bits[2] bit 0x02 (e2m VGT_ASIC_Feedback, mask 0x02 of 0x01161202; e2m only, the code just reads the bit), boost_correction_inhibit_flag (0x40a61e, 7 users) and sensor_generic_fault_status (0x40be28).')

note('POLICY: like wave 5, the brief cap of 10 globals per function was read as binding unrelated extras only; the valve cluster is renamed as a whole state set because the wave 4 / 5 leads ask for one pass and the plates cite the new names. '
     'Time-shared words (0x3fb02e-0x3fb0a2, 0x3fcce8-0x3fcd28, 0x3fd7de, 0x3fd8cc-0x3fd8d0) were checked: xref_addr.py lists no access below 0x7F60 for any of them and the extra scans of the boot ROM 0x0-0x7F5F (instructions with the low halfword of the address, 32-bit words equal to it) found none; '
     'no type of a time-shared word is changed. Names of 0x4077xx words carry no _cal (outside the EEPROM mirror); 0x3fd8cc / 0x3fd8ce / 0x3fd8d0 / 0x3fdcea / 0x3fd7de keep or gain _cal. '
     'Plates keep the earlier "(was ...)" names so lookups of the actuator E and original names still resolve.')

note('WAVE 4 NOTES (aligned_W4_air.jsonl) not covered by a row above: row 4 (alternator handler prototypes "word <name>(void)" in function_definitions.csv) is optional and informational, skipped; rows 23 / 25 are answered by the function and global rows here '
     '(throttle_speed_rate_cal was already renamed by wave 5); row 24 (engine-load-protection conflict) was applied by wave 5 (commit 40a41e7); rows 64 / 65 / 66 informational. '
     'Row 50 (alternator_field_duty_target 0x40b266) is still not applied in global_variables.csv; the comment should read: "Alternator field duty target (25600 = 100 percent): set per regulator state by cm848_calculateAlternatorFieldDutyByRegulatorState (clamped to 25600) and, in states 2 and 3 when bit 0x20 of operating_mode_flags_cal is set, replaced by cm848_calculateAlternatorFieldDutyByPid; '
     'cm848_applyAlternatorFieldDuty overrides, inverts and snaps it and sends it to the field." (the state function only keeps alternator_field_duty_slow_average as a filter of the target). Row 56: throttle_rate_filter_active_flag is the _cal row above; throttle_rate_integrator_prev, governor_rpm_band_rate_working / _target, throttle_rate_integrator_cal, fuel_pressure_demand_reference, '
     'fuel_demand_quantity, fuel_flow_rate_reference, fuel_flow_rate stay open (wastegate controller, not this module). Row 63 stale citations are all still present at HEAD: function 0x532418 DAT_00064430 -> intake_air_heater_performance_test_drop_recovery_agreement_window_adc; function 0x537584 DAT_003fd270 -> wastegate_monitor_armed_flag; '
     'global 0x3fd1e8 DAT_0006442a -> intake_air_heater_performance_test_loaded_sample_delay_ticks (DAT_00064424 / DAT_00064428 have no row and stay); 0x3fd1f2 DAT_0006442e / DAT_00064438 -> intake_air_heater_performance_test_loaded_voltage_lower_window_adc / ..._upper_window_adc; '
     '0x3fd26e DAT_00409fe4 -> wastegate_monitor_pass_high_load_threshold; 0x3fd1f4 DAT_0040b9e6 -> intake_air_heater_performance_test_recovery_voltage_rise_adc; 0x40bc88 DAT_0040bd0a -> battery_temperature_adc_forced_reading; 0x40bd0a cites its own old DAT_0040bd0a, which should read "this word".')

note('WAVE 5 NOTES (aligned_W5_load.jsonl): rows 124-127 and 131-133 are the applied verdict, the survivors list, the truck state, the time-shared check and the scope statement: informational. Row 128 / 129 are answered by this file (actuator E family, bank-2 siblings, cm848_initProtectionControlState, cm848_clearDiagnosticConditionFlags). '
     'Row 132 caveat (a) (logical output 72 as the valve driver enable) is settled by code: engine_feature_status_flags_2 is byte 9 of the logical output request array, and cm848_selectVariableGeometryTurbochargerControlState forces control state 5 (duty 0) when its bit 0 (request 72) is clear, '
     'the current estimate also needs it set; e2m gives the same adjacency (VGA_PWM_Enable 0x01157709 mask 0x01 right after the direction byte). '
     'The note that cm848_clearDiagnosticConditionFlags clears the governor_demand_rate_* words is imprecise: it clears the H-bridge words only, the over-current words are cleared by cm848_clearVariableGeometryTurbochargerDriverOverCurrentState. '
     'Row 130: the channel 101 config / state rows are the two blank-name rows 0x59656 / 0x40a12e above (the lookup cache 0x3fb9c0 and the filter state 0x3fb9c2 are left unnamed); the local variable engineLoadProtection of cm848_evaluateVariableGeometryTurbochargerPositionAdjustments (local_variables.csv, 0x2f5a4) should become spanAdjustmentState '
     '(its type is already VARIABLE_GEOMETRY_TURBOCHARGER_SPAN_ADJUSTMENT_STATE and its comment still says engine-load derate); enums.csv rows for VARIABLE_GEOMETRY_TURBOCHARGER_SPAN_ADJUSTMENT_NORMAL (0) / _ERROR (8) still carry the comments "engine-load protection not derating / actively derating" and should say span adjustment normal / error (fault 671); '
     'the comment of fault_detected_bits_656_to_671 (0x3fe9c6, still quoting the old engine-load note and "actuator E setpoint clamp") and the "actuator E" wording of the channel 101 linearization rows are listed in the stale citation note below.')

note('REFERENCES TO THE OLD NAMES outside the two CSV comment columns (every renamed old name, 208 of them, searched as a whole word in the csv / md / txt / json / py / sh / java files under firmware/, docs/, work/, clip-core/, kuminz-cli/, tools/): '
     'no hit in the other CM848 CSVs (function_definitions, local_variables, labels, constants, enums, arrays, call_fixups; structure_definitions has one comment line about an unrelated governor_derivative_term struct access), none in the CM550 function_renames.csv / global_variables.csv, '
     'none in docs/cross_firmware_variable_map.csv and firmware/cross_firmware_matches.csv, so no cross-firmware link breaks; the int / bool prototypes of the retry timer and counter helpers are therefore not keyed by name in function_definitions.csv. '
     'Hits remain only in generated or historical files that the earlier waves did not maintain either: firmware/classification.csv (11 of the helper function names, keyed by address with a suggested name), the Ghidra memory map dumps firmware/CM848_S90140.06_analysis/docs/memory-mappings/bank1.txt and ram.txt, '
     'the worklist_* batches and proposed_names_wave*.csv of the naming campaigns, and the prose of work/tasks/021, 025 and 042. The generated headers (firmware_functions.hpp / firmware_globals.hpp) follow from the CSVs and must be regenerated after applying.')

note('FOR THE APPLIER: (1) 10 global rows carry "old": "" because the CSV row exists with an empty name (0x3fcce8, 0x3fccf6, 0x3fcd18, 0x3fcd20 filter states; 0x40777a, 0x4077ba, 0x4077d4, 0x4077d6 filter coefficients; 0x59656 / 0x40a12e channel 101 config / state): fill in the name and keep type and comment. '
     '(2) Four rows are "+2" sub-rows of dwords (0x3fb06a, 0x3fb06e here; 0x3fb076, 0x3fb07e, whose dwords wave 5 renamed and which kept their old names): they are renamed as "<dword name>+2"; whether the importer keys them independently of the dword row is not verified, so look at them in the first build. '
     '(3) Two new_global rows are typed i16 (0x407780 and 0x4077c2, both loaded with lha); the other 19 are word. '
     '(4) The tokens h_bridge (the e2m wording for the driver fault path) and config (precedent barometric_pressure_sensor_config) are deliberate. '
     '(5) Five rows have no turbocharger prefix and may overlap other wave-6 files: 0x40c088 / 0x40c089 (logical_output_request_bits_64_to_71 / _72_to_79, other readers are sensor and fault code), 0x3fe9d6 / 0x3fea3a (fault_detected_bits_784_to_799 / fault_registered_bits_784_to_799, other users cm848_processSensorMonitoringLogic and cm848_calibration_group21_load_cont) and 0x3fd7de (throttle_rate_filter_active_flag_cal). '
     '(6) The project memory entry about the load-protection cluster (cm848_load_protection_cluster_rename.md) is stale: the cluster is the valve position servo and the actuator E loop is the same module. '
     '(7) Nothing was run: no CSV, build or git change; the generator is gen_W6_air_vgt.py in the same directory.')

# stale-citation scan -----------------------------------------------------------------------
renamed_set = {o for k, o in renamed_old if o}
mine_addrs = {int(r['address'], 16) for r in rows if r.get('address')}
PAT = {}
w5 = set()
for line in open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W5_load.jsonl'):
    line = line.strip()
    if line:
        o = json.loads(line)
        if o.get('old'):
            w5.add(o['old'])
w5 |= {'cm848_protection_init_configBundle', 'cm848_protection_update_configBundle', 'sensor_channel101'}
cites = {}
phr = re.compile(r'engine[ -]load protection|engine-load derate|engine-load \(fuel-demand', re.I)
phr2 = re.compile(r'actuator[ _]e(?![A-Za-z])|ActuatorE', re.I)
allnames = sorted(renamed_set | {'w5:' + n for n in w5})
for n in allnames:
    PAT[n] = re.compile(r'(?<![A-Za-z0-9_])' + re.escape(n.replace('w5:', '')) + r'(?![A-Za-z0-9_+])')
tokidx = re.compile(r'[A-Za-z_][A-Za-z0-9_+]*')


def scan(label, rowlist, col):
    for r in rowlist:
        a = int(r[0], 16)
        if a in mine_addrs or len(r) <= col:
            continue
        txt = re.sub(r'\(was [^)]*\)', '', ','.join(r[col:]))
        words = set(tokidx.findall(txt))
        hit = []
        for n in allnames:
            base = n.replace('w5:', '')
            if base in words and PAT[n].search(txt):
                hit.append(n)
        if phr.search(txt):
            hit.append('engine-load wording')
        if phr2.search(txt):
            hit.append('actuator E wording')
        if hit:
            cites.setdefault(label, []).append('0x%x %s [%s]' % (a, r[1], ', '.join(hit)))


scan('function_renames.csv', fr_rows, 2)
scan('global_variables.csv', gv_rows, 3)
txt = 'STALE CITATIONS (rows not renamed here whose comment still cites a name renamed here or in wave 5, or engine-load wording; refresh when the rows are applied): '
for lab in ('function_renames.csv', 'global_variables.csv'):
    txt += lab + ' (%d): ' % len(cites.get(lab, [])) + '; '.join(cites.get(lab, [])) + '. '
note(txt)

cnt = {}
for r in rows:
    key = r['kind'] + '/' + r.get('verdict', '-')
    cnt[key] = cnt.get(key, 0) + 1
counts_text = ('%d functions confirmed (+%d rejected), %d global rows confirmed (+%d uncertain, no new name) and %d new_global rows'
               % (cnt.get('function/confirmed', 0), cnt.get('function/rejected', 0), cnt.get('global/confirmed', 0),
                  cnt.get('global/uncertain', 0), cnt.get('new_global/-', 0)))
for r in rows:
    if r['kind'] == 'note' and '@COUNTS@' in r['text']:
        r['text'] = r['text'].replace('@COUNTS@', counts_text)

with open(OUT, 'w') as f:
    for r in rows:
        f.write(json.dumps(r, ensure_ascii=True) + '\n')

kinds = {}
for r in rows:
    k = r['kind'] + ('/' + r['verdict'] if 'verdict' in r else '')
    kinds[k] = kinds.get(k, 0) + 1
print(kinds)
print('names', len(new_names))
