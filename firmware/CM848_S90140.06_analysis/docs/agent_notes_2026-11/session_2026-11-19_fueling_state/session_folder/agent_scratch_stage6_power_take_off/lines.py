"""Find each cited statement inside its function in both the snapshot and the live .cpp.
usage: lines.py <live cpp>"""
import re
import sys

LIVE = sys.argv[1]
SNAP = "/tmp/pto_research/snap.cpp"


def load(path):
    lines = open(path, errors="replace").read().split("\n")
    funcs = {}
    cur = None
    for i, line in enumerate(lines, 1):
        m = re.match(r"^// Function: (\S+) @", line)
        if m:
            cur = m.group(1)
            funcs[cur] = [i, None]
        if cur:
            funcs[cur][1] = i
    return lines, funcs


S, SF = load(SNAP)
L, LF = load(LIVE)


def find(lines, funcs, fn, pattern, nth=1):
    lo, hi = funcs[fn]
    pat = re.compile(pattern)
    count = 0
    for i in range(lo, hi + 1):
        if pat.search(lines[i - 1]):
            count += 1
            if count == nth:
                return i
    return None


CASES = [
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"iVar[23] = uVar[34] - engine_rpm_state", 1, "error = smoothed - engine rpm"),
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"if \(protection_monitored_rpm_snapshot != ", 1, "snapshot compare"),
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"if \(uVar[34] < 0x7ccd\)", 1, "clamp start"),
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"governor_speed_gain_factor = 0x7ccc;", 1, "clamp end"),
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"\(&governor_pid_interp_state_d,", 1, "lookup cache arg"),
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"protection_rpm_axis_cal,protection_rpm_values_cal", 1, "lookup tables"),
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"protection_monitored_rpm_snapshot = power_take_off", 1, "snapshot store"),
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"\* \(int\)\(short\)governor_speed_gain_factor >> 0xe", 1, "error x factor"),
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"cm848_signedFirstOrderFilter\(", 1, "signed filter call"),
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"power_take_off_speed_error_filter.accumulator = ", 1, "anti-windup"),
    ("cm848_calculatePowerTakeOffGovernorSpeedError", r"power_take_off_governor_no_load_fuel = ", 1, "no load fuel"),
    ("cm848_runPowerTakeOffGovernorPid", r"\(uint\)governor_speed_gain_factor;", 1, "PID gain factor use"),
    ("cm848_runPowerTakeOffGovernorPid", r"governor_integrator_prev_snapshot\) \*", 1, "derivative prev error"),
    ("cm848_runPowerTakeOffGovernorPid", r"cruise_speed_blend_working \* ", 1, "upper clamp"),
    ("cm848_runPowerTakeOffGovernorPid", r"if \(final_fueling_state != FUELING_STATE_POWER_TAKE_OFF\)", 1, "tracking branch"),
    ("cm848_runPowerTakeOffGovernorPid", r"governor_speed_product =$", 1, "tracking assign"),
    ("cm848_runPowerTakeOffGovernorPid", r"governor_speed_product =$", 2, "integral assign"),
    ("cm848_runPowerTakeOffGovernorPid", r"governor_speed_product = dVar11;", 1, "clamp assign"),
    ("cm848_runPowerTakeOffGovernorPid", r"power_take_off_governor_integral_fueling = governor_speed_product;", 1, "publish integral"),
    ("cm848_presetPowerTakeOffGovernorOnEngagement", r"cm848_setProtectionParamFromRpm\(\);", 1, "call setParam"),
    ("cm848_presetPowerTakeOffGovernorOnEngagement", r"\(&governor_pid_interp_state_d,", 1, "preset lookup cache arg"),
    ("cm848_presetPowerTakeOffGovernorOnEngagement", r"governor_speed_gain_factor = \(word\)uVar4;", 1, "preset factor store"),
    ("cm848_presetPowerTakeOffGovernorOnEngagement", r"governor_speed_product = ", 1, "preset integral"),
    ("cm848_runPowerTakeOffGovernor", r"governor_fuel_active_prev_flag == 0", 1, "prev flag test"),
    ("cm848_runPowerTakeOffGovernor", r"governor_pid_derivative_snapshot = ", 1, "pd snapshot store"),
    ("cm848_runPowerTakeOffGovernor", r"governor_integrator_prev_snapshot = ", 1, "error snapshot store"),
    ("cm848_runPowerTakeOffGovernor", r"governor_fuel_active_prev_flag = ", 1, "prev flag store"),
    ("cm848_initProtectionFilterState", r"cm848_initProtectionSmoothingPointer\(\);", 1, "call smoothing init"),
    ("cm848_initProtectionFilterState", r"governor_pid_interp_state_a = 2;", 1, "cache a"),
    ("cm848_initProtectionFilterState", r"governor_pid_interp_state_c = 2;", 1, "cache c"),
    ("cm848_smoothPowerTakeOffReferenceEngineSpeed", r"power_take_off_reference_step_limit < \(uVar4", 1, "step compare"),
    ("cm848_smoothPowerTakeOffReferenceEngineSpeed", r"protection_smoothing_filter_state.accumulator =", 1, "smoothing acc load"),
    ("cm848_smoothPowerTakeOffReferenceEngineSpeed", r"exponentialMovingAverage\(", 1, "EMA call"),
    ("cm848_runPowerTakeOffGovernorStateMachine", r"\(protection_control_state_flags & 0x55555\) \* 2", 1, "edge shift"),
    ("cm848_runPowerTakeOffGovernorStateMachine", r"governor_rpm_integrator_high == 0\)\) \|\|", 1, "saved==0 test"),
    ("cm848_runPowerTakeOffGovernorStateMachine", r"wVar3 = governor_rpm_integrator_high;", 1, "restore saved"),
    ("cm848_runPowerTakeOffGovernorStateMachine", r"governor_rpm_integrator_high = governor_rpm_reference_target;", 1, "save cab target"),
    ("cm848_runPowerTakeOffGovernorStateMachine", r"governor_rpm_transition_flag = 0;", 1, "WAIT clear flag"),
    ("cm848_runPowerTakeOffGovernorStateMachine", r"governor_rpm_integrator_high = 0;", 1, "WAIT clear saved"),
    ("cm848_runPowerTakeOffGovernorStateMachine", r"protection_eval_step_index = protection_eval_step_index \+ 1;", 1, "step++"),
    ("cm848_runPowerTakeOffGovernorStateMachine", r"wVar3 = governor_rpm_reference_snapshot;", 1, "max clamp"),
    ("cm848_runPowerTakeOffGovernorStateMachine", r"governor_rpm_reference_target = wVar3;", 3, "target := clamp"),
    ("cm848_runPowerTakeOffGovernorStateMachine", r"\(&protection_rpm_reference_snapshot\)\[protection_eval_step_index\]", 1, "array index"),
    ("cm848_rampPowerTakeOffReferenceEngineSpeed", r"governor_rpm_reference_ramped \+ power_take_off_engagement_slew_rate_cal\) <", 1, "ramp compare"),
    ("cm848_rampPowerTakeOffReferenceEngineSpeed", r"governor_rpm_transition_flag = 1;", 1, "flag set"),
    ("cm848_rampPowerTakeOffReferenceEngineSpeed", r"governor_rpm_reference_ramped = power_take_off_requested_engine_speed;", 1, "ramped reload"),
    ("cm848_initializePowerTakeOffGovernorState", r"protection_rpm_reference_snapshot = governor_rpm_reference_working;", 1, "array init first"),
    ("cm848_initializePowerTakeOffGovernorState", r"governor_rpm_ref_target_3_snapshot = ", 1, "array init last"),
    ("cm848_initializePowerTakeOffGovernorState", r"governor_rpm_integrator_high = 0;", 1, "init saved"),
    ("cm848_initializePowerTakeOffGovernorState", r"protection_control_state_flags \| 0x2000;", 1, "init 0x2000"),
    ("cm848_resetProtectionBypass", r"power_take_off_throttle_override_flag = 0;", 1, "bypass flag"),
    ("cm848_j1939HandlePgn65264Pto", r"j1939_reverseByteOrder16", 1, "speed bytes"),
    ("cm848_j1939HandlePgn65264Pto", r"sendJ1939Message\(", 1, "send"),
    ("cm848_initJ1939PtoBuffer", r"CONCAT13", 1, "can id"),
    ("cm848_dispatchModeHandlers", r"cm848_initProtectionFilterState\(\);", 1, "call initFilter"),
    ("cm848_applicationMain", r"cm848_dispatchModeHandlers\(\);", 1, "call dispatch"),
    ("cm848_applicationMain", r"cm848_resetProtectionBypass\(\);", 1, "call bypass"),
    ("cm848_initJ1939ProtocolHandlers", r"cm848_j1939RegisterPgnHandler\(0xfef0,", 1, "register"),
    ("cm848_j1939_system_init", r"cm848_initJ1939PtoBuffer\(\);", 1, "call init buffer"),
    ("cm848_j1939_system_init", r"diag_record_queue_add_entry\(0,0xfef0,", 1, "queue add"),
]
for fn, pat, nth, label in CASES:
    s = find(S, SF, fn, pat, nth)
    l = find(L, LF, fn, pat, nth)
    print(f"{label:28s} {fn}: snap={s} live={l}")
