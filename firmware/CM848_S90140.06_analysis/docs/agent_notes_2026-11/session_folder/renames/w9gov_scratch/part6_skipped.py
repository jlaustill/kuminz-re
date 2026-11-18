ROWS = []

# ---------------------------------------------------------------- the mode 7 "reduction" = the e2m ASG negative reference slew limiter
SLEW = [
    ("0x003ff692", "governor_reference_speed_reduction_decay", "all_speed_governor_reference_negative_slew_rate_above_threshold",
     "ASG_Negative_Slew_Rate_1 0x01107D0C 'ASG ref neg slew limit above ASG_Slew_Rate_Threshold' (RPM 0.125)",
     "subtracted from governor_reference_speed_filtered per pass while it is above the threshold"),
    ("0x003ff694", "governor_reference_speed_reduction_low_range_step", "all_speed_governor_reference_negative_slew_rate_below_threshold",
     "ASG_Negative_Slew_Rate_2 0x01107D0E 'ASG ref neg slew limit below ASG_Slew_Rate_Threshold'",
     "subtracted per pass when the reference is at or below the threshold"),
    ("0x003ff696", "governor_reference_speed_reduction_upper_threshold", "all_speed_governor_reference_slew_rate_threshold",
     "ASG_Slew_Rate_Threshold 0x01107D10 'Use ASG slew rate 1 when above this, slew rate 2 below'",
     "the breakpoint between the two negative slew rates"),
    ("0x003ff698", "governor_reference_speed_reduction_minimum_vehicle_speed", "all_speed_governor_reference_slew_vehicle_speed_threshold",
     "ASG_Slew_Limit_VSS_Threshold 0x01107D12 'ASG Ref slew limits disabled below this VS' (MPH)",
     "vehicle_speed_copy must be at or above it for the limiter to be active"),
    ("0x003ff69a", "governor_reference_speed_reduction_switch_cancel_enable_flag", "all_speed_governor_reference_slew_brake_inhibit_flag",
     "ASG_Slew_On_Brake_Inhibit_Flag 0x01107D14 'If true ASG slew limits disabled when brake is ON'",
     "when nonzero a pressed brake / clutch switch (switch_input_state_bits[1] bit 8, [0] bit 4) switches the limiter off"),
    ("0x003ff6ac", "governor_reference_speed_lead_offset", "all_speed_governor_reference_slew_maximum_delta",
     "ASG_Slew_Max_Delta 0x01107D26 'Added to actual RPM to calculate max slewed ASG ref spd'",
     "the signed offset added to current_rpm in the ceiling of the slewed reference"),
    ("0x003ff6ae", "governor_reference_speed_lead_manifold_pressure_gain", "all_speed_governor_reference_slew_maximum_gain",
     "ASG_Slew_Max_Gain 0x01107D28 'Mult by final fuel to add offset to calc max asg slewed ref spd'",
     "the gain applied to the intake manifold pressure (>> 7) in the same ceiling; the e2m says final fuel, the code uses the manifold pressure"),
    ("0x0040a1f2", "governor_reference_speed_reduction_active_flag", "all_speed_governor_reference_negative_slew_active_flag",
     "ASG_Ref_Negative_Slew_Active 0x01107C48 'Flag that indicates conditions permit ASG ref slew limiting'",
     "set in mode 7 when no brake / clutch switch cancels (or the inhibit option is off), the vehicle speed is at or above the threshold, the drivetrain ratio is settled (or a transmission type is set) and the gear is not park / neutral"),
]
for addr, old, new, e2m, what in SLEW:
    ROWS.append({
        "kind": "global", "address": addr, "old": old, "verdict": "confirmed", "new": new,
        "evidence": (f"The mode 7 'reduction' of the all-speed governor reference IS the ASG negative reference slew limiter: {what}. CODE "
                     f"(cm848_runOperatingModeSpeedGovernor, mode 7 branch): while the limiter is active the filtered reference falls by the above-threshold rate, "
                     f"or by the below-threshold rate once at or below the threshold, is capped at current_rpm + maximum delta + gain x intake manifold pressure >> 7, "
                     f"and never goes below governor_reference_speed_floor (the e2m non-linear filter output). E2M (relative offset, all nine at consistent "
                     f"spacing: 0x3ff692 -> 0x01107D0C and 0x3ff6ac -> 0x01107D26 are both 0x1a apart): {e2m}. ROM-copied calibration, no _cal."),
    })
ROWS.append({
    "kind": "global", "address": "0x0040a1f0", "old": "governor_reference_speed_floor", "verdict": "confirmed",
    "new": "all_speed_governor_reference_non_linear_filter_output",
    "evidence": ("Written only by cm848_calculateGovernorReferenceSpeedBlend = speed request x (1 - w) + filtered reference x w with the weight w from the "
                 "speed-difference table (the non-linear filter), the lower bound of the slewed reference in mode 7. E2M: ASG_Non_Linear_Filt_Out 0x01107C46 "
                 "'Output of non-linear filtered reference, before slew limits'; 0x40a1f2 - 0x40a1f0 = 2 = 0x01107C48 - 0x01107C46."),
})

# ---------------------------------------------------------------- high speed governor text refresh (rows still saying wrong or cut-off things)
ROWS.append({
    "kind": "note",
    "text": (
        "HIGH SPEED GOVERNOR TEXT REFRESH (lead 6): after the wave 8 refresh pass NO old identifier is left in these rows or in the plates of 0x1f40c / "
        "0x1fa20 (checked with a token scan against every CSV name; rows 0x40a8cb / cd / cf and the plate of 0x1fa20 are clean, only '(was ...)' history "
        "remains). What is still wrong is prose: rows 0x406fb4 / b6 / b8 all carry the same cut-off PID description ('which cm848_processProtectionRampControl "
        "uses as ...') instead of saying which gain they are, and 0x406fc2 / c4 / e2 still say 'Row comment still cites old names'. EXACT REPLACEMENT "
        "ROWS (global_variables.csv): 0x00406fb4,high_speed_governor_proportional_gain_base,word,Code: base set proportional gain (coefficient 1), ROM-copied "
        "calibration (no _cal): selectHighSpeedGovernorGainSet / cm848_initializeHighSpeedGovernorGainSet load it into "
        "high_speed_governor_proportional_gain (0x40a8cb) for gain set code 16 and as the alternate set; cm848_runHighSpeedGovernorPid scales it by the "
        "absolute filtered error table and uses P term = filtered error x gain / 1113. Dump 82. (was fuel_ema_coeff_1_cal) | "
        "0x00406fb6,high_speed_governor_derivative_gain_base,word,Code: base set derivative gain (coefficient 3), ROM-copied calibration: loaded like the "
        "proportional gain into high_speed_governor_derivative_gain (0x40a8cf); D term = change of the filtered error x gain x 100 / 3478. Dump 2. (was "
        "fuel_ema_coeff_3_cal) | 0x00406fb8,high_speed_governor_integral_gain_base,word,Code: base set integral gain (coefficient 2), ROM-copied calibration: "
        "loaded into high_speed_governor_integral_gain (0x40a8cd); the integrator increment is filtered error x gain / 17809. Dump 262. (was "
        "fuel_ema_coeff_2_cal) | 0x00406fc2,high_speed_governor_integrator_maximum,word,Code: cm848_runHighSpeedGovernorPid sets the integrator to this << 16 "
        "when its high word is at or above it; also the initial integral term (cm848_initializeHighSpeedGovernorGainSet). Dump 1766. ROM address, so no "
        "_cal. (was injection_timing_compensation_limit_upper, injection_timing_compensation_limit_cal) | 0x00406fc4,high_speed_governor_integrator_minimum,"
        "word,Code: the lower clamp of the same test (load at 0x1f908): below it the integrator becomes this << 16. Dump 0. Not the pair of "
        "high_speed_governor_integrator_preset_minimum (0x406fcc), which clamps the preset function. ROM address, so no _cal. (was "
        "injection_timing_compensation_limit_lower, injection_timing_compensation_lower_cal) | 0x00406fe2,high_speed_governor_integrator_preset_offset_limit,"
        "word,Code: in cm848_presetHighSpeedGovernorIntegrator the integrator is fuel_demand_computed minus the positive proportional term, plus the smaller "
        "of the proportional term and this. Dump 221. ROM address, so no _cal. (was injection_timing_compensation_addend, "
        "injection_timing_compensation_addend_cal). If the function renames of this file are applied, the names in these rows follow through the "
        "reference refresh. The plate of 0x1f40c needs only the CM550 sentence given in its function row."
    ),
})
ROWS.append({
    "kind": "note",
    "text": (
        "'+2' LABEL ROW (lead 6): global_variables.csv line 1291 0x003fa892,timing_compensation_accumulator+2,, must follow the rename of 0x3fa890: "
        "EXACT ROW 0x003fa892,high_speed_governor_integrator+2,,  (a label-only sub-row like 0x40a206 fuel_demand_integrator_b+2; no type, no comment). "
        "align_results.py drops '+N' rows from the results, so it has to be edited by hand or by a DELETE / replace note."
    ),
})
ROWS.append({
    "kind": "note",
    "text": (
        "ROW-75 LIST (lead 6), item by item. (1) governor_speed_* / channel 75 deviation words near 0x507214: DONE by wave 8 - 0x507214 is "
        "cm848_evaluateEgrValvePositionControlDiagnosticConditions (was cm848_calculateSensorChannel75DeviationDiagnosticConditions) and its body now uses "
        "only egr_valve_* words; the 'PID output' it pairs with the channel 75 feedback is egr_valve_drive_duty_selected (compared with "
        "egr_valve_control_strong_drive_duty_threshold in the direction of the command error), settling the open pairing. The remaining governor_speed_* "
        "names elsewhere (governor_speed_output_snapshot 0x3fa6fe, governor_speed_range_prev_snapshot 0x3fa79a, governor_speed_correction 0x3faf4c, "
        "governor_speed_lower_limit) were not examined. (2) the mode 7 'reduction reason': see the nine rows above - it is the e2m ASG negative reference "
        "slew limiter. (3) combustion_chi_maximum_torque_at_point_1-5 (0x40a50c-0x40a514): the type note stays unproposed - the rows are WRITE-ONLY "
        "(no load anywhere, so no lha / lhz proves a sign); the e2m CBR_Max_Chi_Torque_At_Point_N (FT*LB 0.5) says nothing about the sign either. Keep word. (4) "
        "the TSC1 / array type notes of waves 6 / 7: their text is not in the wave 7 file (only the one-line summary), so there is nothing to check; if "
        "they are about j1939_tsc1_override_state fields or the 0x5c1d6 record, the record layout is settled in the all-speed governor rows (stride 18, "
        "nine coefficients in the order proportional 1 / 2, integral 1 / 2, derivative 1 / 2, compensation filter 1 / 2 / 3 = e2m ASG_Jcomm_*_00 / 01 / 10 / 11)."
    ),
})

# ---------------------------------------------------------------- stale prose around the renamed droop gains
ROWS.append({
    "kind": "note",
    "text": (
        "DROOP GAIN PROSE (lead 2): after the renames the comments of 0x40a254 / 0x40a256 and the plates of 0xff04 / 0xea00 still call the pair the integral / "
        "proportional gains. EXACT ROWS: 0x0040a254,all_speed_governor_throttle_droop_gain_1,word,CODE: write-only (0 reads, both banks) copy of "
        "all_speed_governor_droop_gain_1: cm848_calculateGovernorCompensatorCoefficients stores the droop gain it computes (1024 x (K - u) / (K + u), Q10) here "
        "and to 0x40a250 when the variable speed governor starts. E2M: ASG_Throttle_Droop_1 'ASG throttle droop gain 1' (0x01107A08, 1/1024) at this offset. "
        "(was fuel_trim_pid_integral_gain_calc) | 0x0040a256,all_speed_governor_throttle_droop_gain_2,word,CODE: write-only (0 reads) copy of "
        "all_speed_governor_droop_gain_2, (droop gain 1 + 1024) / 2. E2M: ASG_Throttle_Droop_2 (0x01107A0A, Q10). (was fuel_trim_pid_proportional_gain_calc). PLATE "
        "0x0000ff04 cm848_calculateGovernorCompensatorCoefficients: Calculates the all-speed governor's two droop gains (Q10, 1024 = 1.0 = no droop; e2m "
        "ASG_Droop_Gain_1 / _2) from the throttle mode coefficient calibrations (all_speed_governor_throttle_mode_integral_gain_1 / _2 and "
        "..._compensation_filter_coefficient_1 / 2 / 3) and the droop all_speed_governor_droop, which is the blend (weighted by the gear-ratio blend weight "
        "0..128) of the all_speed_governor_droop_blend_0 and _128 tables at speed_request_base. Droop gain 1 = 1024 x (K - u) / (K + u) with K = 40196217 and "
        "u = droop x (integral gain 1 + integral gain 2) x (coefficient 1 - coefficient 2) / (256 - coefficient 3); droop gain 2 = (droop gain 1 + 1024) / 2; "
        "both are 1024 when the droop is 0 or the coefficients disable the adjustment. Stored to all_speed_governor_droop_gain_1 / _2 and their throttle copies. "
        "Called by cm848_initEngineOperatingMode when the speed governor starts; cm848_runOperatingModeSpeedGovernor reads them (was "
        "cm848_calculateFuelTrimValues)."
    ),
})
