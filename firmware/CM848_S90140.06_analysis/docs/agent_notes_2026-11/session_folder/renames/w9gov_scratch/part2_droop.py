ROWS = []

DROOP_EVIDENCE = (
    "CODE (settled): the pair is computed in one place, cm848_calculateGovernorCompensatorCoefficients "
    "(0xff04, runs when the variable speed governor starts, mode 7): gain 1 = 1024 x (K - u) / (K + u) with "
    "K = 40196217 and u = all_speed_governor_droop x (integral gain 1 + integral gain 2) x (compensation filter "
    "coefficient 1 - coefficient 2) / (256 - coefficient 3), gain 2 = (gain 1 + 1024) / 2; both are 1024 (Q10 1.0) when "
    "the droop is 0 or the coefficients disable the adjustment. cm848_engineMode_reset (TSC1 speed mode 2) sets both "
    "to 1024 and cm848_restoreEngineOperatingMode copies them from the restore record, so 1024 = no droop. "
    "cm848_runOperatingModeSpeedGovernor reads them as the pole and input gain of the droop compensation: at a mode start it seeds "
    "the reference speed offset with (1024 - gain 1) x (fuel demand - no-load fuel) x 128 / (gain 2 x (integral gain 1 + integral gain 2)) "
    "and every pass it updates the integrator state as accumulator x gain 2 / 2 + state x gain 1 + (gain 1 - 1024) x previous clamp value. "
    "They are not P / I terms of the PID (those are the nine compensator coefficients). Dump: 923 and 973 = (923 + 1024) / 2 for the droop "
    "14333 (0.0015 rpm per mm3 per stroke per count). E2M (corroboration by relative offset): ASG_Droop_Gain_1 / _2 "
    "(ASDPGN01 / ASDPGN02, 1/1024, 0x01107A04 / 06) follow ASG_Selected_Speed (0x01107A02 = 0x40a24e) in the same order, "
    "and ASG_Throttle_Droop_1 / _2 (0x01107A08 / 0A = 0x40a254 / 56) are the write-only copies the same function stores."
)

ROWS.append({
    "kind": "global", "address": "0x0040a250", "old": "governor_pid_integral_gain", "verdict": "confirmed",
    "new": "all_speed_governor_droop_gain_1",
    "evidence": "Droop gain 1 (Q10) of the all-speed governor, the pole of its droop compensation. " + DROOP_EVIDENCE,
})
ROWS.append({
    "kind": "global", "address": "0x0040a252", "old": "governor_pid_proportional_gain", "verdict": "confirmed",
    "new": "all_speed_governor_droop_gain_2",
    "evidence": "Droop gain 2 (Q10) of the all-speed governor, (droop gain 1 + 1024) / 2, the input gain of its droop compensation. " + DROOP_EVIDENCE,
})
ROWS.append({
    "kind": "global", "address": "0x0040a21a", "old": "engine_operating_mode_restore_integral_gain", "verdict": "confirmed",
    "new": "engine_operating_mode_restore_droop_gain_1",
    "evidence": "Code: copied to all_speed_governor_droop_gain_1 (0x40a250) by cm848_restoreEngineOperatingMode; only reader, no writer. E2M: ASG_Droop_Gain_1_As (ASAP01DP, 'application specific droop gain 1', 0x01117010) at the same relative offset in the restore block 0x40a216-0x40a246 = 0x0111700C-0x0111703E.",
})
ROWS.append({
    "kind": "global", "address": "0x0040a21c", "old": "engine_operating_mode_restore_proportional_gain", "verdict": "confirmed",
    "new": "engine_operating_mode_restore_droop_gain_2",
    "evidence": "Code: copied to all_speed_governor_droop_gain_2 (0x40a252) by cm848_restoreEngineOperatingMode; only reader, no writer. E2M: ASG_Droop_Gain_2_As (ASAP02DP, 'application specific droop gain 2', 0x01117012) at the same relative offset.",
})

# the nine compensator coefficients: the restore function copies each to a named *_selected word
COEFFS = [
    (0x40a232, 0, "proportional_gain_1", "all_speed_governor_proportional_gain_1_selected", "ASG_Proportional_Gain_1_As (ASAP01PP, 0x01117028)"),
    (0x40a234, 1, "proportional_gain_2", "all_speed_governor_proportional_gain_2_selected", "ASG_Proportional_Gain_2_As (ASAP02PP, 0x0111702A)"),
    (0x40a236, 2, "integral_gain_1", "all_speed_governor_integral_gain_1_selected", "ASG_Integral_Gain_1_As (ASAP01IT, 0x0111702C)"),
    (0x40a238, 3, "integral_gain_2", "all_speed_governor_integral_gain_2_selected", "ASG_Integral_Gain_2_As (ASAP02IT, 0x0111702E)"),
    (0x40a23a, 4, "derivative_gain_1", "all_speed_governor_derivative_gain_1_selected", "ASG_Derivative_Gain_1_As (ASAP01DV, 0x01117030)"),
    (0x40a23c, 5, "derivative_gain_2", "all_speed_governor_derivative_gain_2_selected", "ASG_Derivative_Gain_2_As (ASAP02DV, 0x01117032)"),
    (0x40a23e, 6, "compensation_filter_coefficient_1", "all_speed_governor_compensation_filter_coefficient_1_selected", "ASG_Coefficient_1_As (ASAP01CF, 0x01117034)"),
    (0x40a240, 7, "compensation_filter_coefficient_2", "all_speed_governor_compensation_filter_coefficient_2_selected", "ASG_Coefficient_2_As (ASAP02CF, 0x01117036)"),
    (0x40a242, 8, "compensation_filter_coefficient_3", "all_speed_governor_compensation_filter_coefficient_3_selected", "ASG_Coefficient_3_As (ASAP03CF, 0x01117038)"),
]
for addr, k, role, selected, e2m in COEFFS:
    ROWS.append({
        "kind": "global", "address": f"0x{addr:08x}", "old": f"engine_operating_mode_restore_compensator_coefficient_{k}",
        "verdict": "confirmed", "new": f"engine_operating_mode_restore_{role}",
        "evidence": (f"Code: cm848_restoreEngineOperatingMode copies coefficient {k} of the block 0x40a232-0x40a242 to {selected} "
                     f"and points fuel_demand_pid_coeffs at the block, so cm848_runOperatingModeSpeedGovernor reads the nine words in place "
                     f"in this order (proportional 1 / 2, integral 1 / 2, derivative 1 / 2, compensation filter 1 / 2 / 3). "
                     f"Only reader, no writer. E2M (relative offset): {e2m}."),
    })
