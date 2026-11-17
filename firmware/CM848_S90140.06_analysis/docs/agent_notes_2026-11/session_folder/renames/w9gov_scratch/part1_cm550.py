ROWS = []

# ---- (1) CM550 neighbours of the high speed governor: six pairs in the same order in both firmwares ----
# CM848 (address, old, new, plate, evidence); CM550 rows go into one note (the CM550 CSV is not the gate's input)

PAIRS = [
    dict(
        cm848=("0x0001f98c", "cm848_initializeHighSpeedGovernorGainSet", "initializeHighSpeedGovernorGainSet"),
        cm550=("0x0001d2e4", "cm550_update_engine_protection_thresholds"),
        tier="A: same body",
        plate848=("Start-up initialisation of the high speed governor: selects the base gain set (code 16), sets the integral term to its upper limit, "
                  "clears the error filter accumulator, points the error filter coefficient pointer at the selected coefficient and sets the three gain "
                  "adjustment cached axis offsets to 2. Shared with CM550 0x1d2e4 (same function: the same assignments; CM550 also loads the axis and "
                  "value pointers of its three table descriptors and keeps the filter accumulator offset by 0x80000000) "
                  "(was cm848_initializeHighSpeedGovernorGainSet, cm848_initSensorRawChannels)."),
        plate550=("Start-up initialisation of the high speed governor, the same function as CM848 0x1f98c: loads the base proportional, integral and "
                  "derivative gains and the error filter coefficient into the live set, selects gain set code 16, starts the integrator at its maximum, "
                  "clears the error filter state (0x80000000 = 0 in the offset binary the filter uses), points the filter coefficient pointer at the "
                  "selected coefficient and sets the three gain adjustment table descriptors (axis and value pointers, size 2) "
                  "(was cm550_update_engine_protection_thresholds)."),
        evidence=("CODE (both bodies read in full): CM550 0x1d2e4 assigns the live P / I / D gains and the filter coefficient from the base set "
                  "DAT_00808036 / 3a / 38 / 3c, gain set code 0x10, hsg_pid_fuel_output_previous (the integral term) = the integrator maximum, filter "
                  "state 0x80000000, filter pointer = the live coefficient and size 2 in the three gain adjustment descriptors; CM848 0x1f98c does the same "
                  "with the same constants (0x10, 2). The only differences are representation: CM550 descriptors carry the axis / value pointers, CM848 "
                  "passes them to lookupTableInterpolation; the CM550 EMA state is offset binary (0x80000000 = 0)."),
    ),
    dict(
        cm848=("0x0001f34c", "cm848_presetHighSpeedGovernorIntegrator", "presetHighSpeedGovernorIntegrator"),
        cm550=("0x0001d252", "cm550_FUN_0001d252"),
        tier="B: same algorithm, revised fixed point",
        plate848=("While governor_mode_code (0x40a2d0) is not 12 presets the integrator to fuel_demand_computed minus the part of the proportional term "
                  "above the preset offset limit, clamped between the integrator preset minimum and maximum, so the governor takes over without a step; "
                  "also copies the filtered error to its previous-value word. Shared with CM550 0x1d252 (same algorithm and clamps; the CM550 integral "
                  "term is kept as a plain word) (was cm848_presetHighSpeedGovernorIntegrator, cm848_calculateTimingCompensation)."),
        plate550=("Integrator preset of the high speed governor, the same algorithm as CM848 0x1f34c: while the fueling state is not 12 the integrator is "
                  "set to the current fuel demand minus the positive part of the proportional term, plus the smaller of that term and the preset offset "
                  "limit, clamped between the integrator preset minimum and maximum; keeps the previous integral output and filtered error "
                  "(was cm550_FUN_0001d252)."),
        evidence=("CODE: both functions test 'fueling state != 12', start from fuel demand - max(proportional term, 0), add min(proportional term, "
                  "offset limit) when the term is positive, clamp to the preset minimum / maximum and keep the previous filtered error; CM848 then stores "
                  "the integrator as the integral term in the high word (Q16); the CM550 decompilation shows the plain value."),
    ),
    dict(
        cm848=("0x0001f40c", "cm848_runHighSpeedGovernorPid", "runHighSpeedGovernorPid"),
        cm550=("0x0001ce7c", "cm550_initDiagnosticProtocol"),
        tier="B: same structure, different fuel scale constants",
        plate848=("Runs the high speed governor PID: the speed error (arbitrated engine speed limit minus high_speed_governor_compensated_engine_speed, "
                  "times the error filter gain / 512) passes a first order filter; the proportional, integral and derivative terms (each gain scaled by a "
                  "14 point table of the absolute error when its adjustment enable is set) are clamped and summed into high_speed_governor_fueling, the "
                  "high speed governor fueling. The integrator is preset to the fuel demand while governor_mode_code (0x40a2d0) is not 12 "
                  "(presetHighSpeedGovernorIntegrator) and reset when engine speed exceeds the limit plus an offset with governor_fuel_demand_mode "
                  "(0x40a154) 12 and low fuel demand. Shared with CM550 0x1ce7c (same structure and clamps; the term divisors are 960 / 240 / 15360 there "
                  "against 1113 / 3478 / 17809 here, and the gain adjustment caps are 0x1e00 / 0x7ae against 0xf000 / 0x3d70, the two firmwares' fuel "
                  "scales) (was cm848_runHighSpeedGovernorPid, cm848_processTorqueLimitTiming)."),
        plate550=("Runs the high speed governor PID, the same structure as CM848 0x1f40c: the speed error (hsg_reference_speed_after_droop minus the "
                  "compensated engine speed, times the error filter gain / 512) passes the first order filter into hsg_filtered_engine_speed_error and "
                  "is clamped to its minimum / maximum; the integrator is preset by cm550_FUN_0001d252 (later presetHighSpeedGovernorIntegrator) and "
                  "reset to its reset value when engine speed exceeds the reference plus the reset offset with fueling state 12 and low fuel demand; "
                  "otherwise the proportional (error x gain / 960), derivative (error change x gain / 240) and integral (error x gain / 15360) terms, "
                  "each gain optionally scaled by a table of the absolute error (caps 0x1e00 / 0xffff / 0x7ae), are clamped and summed into the HSG "
                  "fueling output (was cm550_initDiagnosticProtocol)."),
        evidence=("CODE: the error filter (x gain / 0x200, first order filter, clamp), the reset condition (reference + reset offset < engine speed, fuel "
                  "demand below its threshold, fueling state 12), the three optional |error| gain tables and the clamp-and-sum are the same sequence in "
                  "both. NOT the same body: the divisors (CM550 960 / 240 / 15360, CM848 1113 / 3478 with x 100 / 17809) and the gain caps differ, so "
                  "the pair is the same function in two fuel scales (method versioning), not identical code."),
    ),
    dict(
        cm848=("0x0001fd94", "cm848_selectEngineSpeedLimit", "selectEngineSpeedLimit"),
        cm550=("0x0001d5a0", "cm550_FUN_0001d5a0"),
        tier="B: same arbitration, CM848 is the later revision",
        plate848=None,   # the plate is long: only a sentence is appended (see the note)
        plate550=("Lowest-wins arbitration of the high speed governor (HSG) reference speed, the same function as CM848 0x1fd94: the J1939 high idle "
                  "override (JCHII1OD, speed JCHSODES, source 8), otherwise the lowest of the engine protection derate limit EPESLM (5), the base "
                  "reference (6), the datalink speed control mode 3 limit (9), the VSS tamper derate (4), anc_speed_limit_ramp_value (3), DAT_0080a9d6 (2, "
                  "or the isochronous cap in modes 2 / 3), the application group rpm derate (7), the throttle fueling override limit (11) and DAT_0080d65c "
                  "(10, slope 0), limited by DAT_00808144 and a minimum; the winner is recorded in hsg_reference_speed_winning_source_indicator (e2m "
                  "HSINRFST). The ramped reference (the derate speed used in the droop) follows it, then the droop line (slope recomputed only when its "
                  "inputs change) gives hsg_reference_speed_after_droop, capped by the isochronous speed (was cm550_FUN_0001d5a0)."),
        evidence=("CODE (both bodies read in full): same ordered lowest-wins chain with the same source numbers (8 high idle override, 5 / 6 / 9 / 4 / 2 / "
                  "7 / 11 / 10 line up with CM848 5 fault derate, 6 reference, 9 TSC1 mode 3 limit, 4, 2, 7 fuel pressure fault limit, 11 idle limit, "
                  "10), the same 0x1111 / 0x7fd6 droop slope (clampedDivision), the same ramp (up by a step, down at once), the same droop line "
                  "(slope x (full fuel - integral term) / 0x1111, never below the ramped limit) and the same J1939 exceptions (9 with the network "
                  "active and 11 apply the ramped limit without droop). E2M: JCHII1OD 'Jcomm High Idle Override' / JCHSODES 'speed to which HSG ref "
                  "should be set when Jcomm High Idle override commanded' = CM848 torque_limit_mode_select 1 and ROM word DAT_0005c39a; HSINRFST "
                  "'indicates which alg. controls the HSG' = CM848 engine_speed_limit_limiting_source_number_snapshot. DIFFERENCES: CM848 adds the "
                  "sources 13 / 14 / 15 / 16 and a lower / upper bound on the base reference, has no source 3 (CM550 anc_speed_limit_ramp_value), and "
                  "recomputes the droop slope every pass unless the bypass flag is set (CM550 only when its inputs changed). A revised version of the "
                  "same function, so the shared name follows the selectHighSpeedGovernorGainSet precedent; drop the sharing if 'same body' is meant "
                  "strictly."),
    ),
    dict(
        cm848=("0x00020410", "cm848_initializeEngineSpeedLimitDefaults", "initializeEngineSpeedLimitDefaults"),
        cm550=("0x0001d94e", "cm550_FUN_0001d94e"),
        tier="A: same body (CM848 adds one source)",
        plate848=("Resets the engine speed limit arbitration: the applied limit and the stored reference to engine_speed_limit_reference_default_cal "
                  "(3200 rpm), and the lowest source limit plus the source words fuel_pressure_fault_engine_speed_limit_working (7), "
                  "engine_speed_limit_pedal_fault_mode (14), engine_speed_limit_source_10 (10) and engine_speed_limit_source_4 (4) to "
                  "engine_speed_limit_default_cal (3750 rpm); the limiting source number is set to 6. Shared with CM550 0x1d94e (same function; CM550 has "
                  "no source 14 and points its base reference pointer at the calibration word) "
                  "(was cm848_initializeEngineSpeedLimitDefaults, cm848_initTorqueLimitDefaults)."),
        plate550=("Resets the HSG reference speed arbitration, the same function as CM848 0x20410: points the base reference pointer at the calibrated "
                  "reference, starts the ramped reference (the derate speed used in the droop) there, sets the winning source indicator and its HSINRFST "
                  "copy to 6, the droop no-load intercept speed to its default, the lowest-wins reference and the source 7 / 10 / 4 limits to the maximum "
                  "rated engine speed, and forces a droop slope recompute (was cm550_FUN_0001d94e)."),
        evidence=("CODE: both set the winning source number and its snapshot to 6, the ramped limit and base reference to the default reference, the droop "
                  "no-load speed to its default and the lowest-wins limit plus sources 7 / 10 / 4 to the maximum speed (CM550 DAT_0080d65c = source "
                  "10, vss_tamper_derate = 4, rpm_derate_supplied_by_application_group = 7). CM848 also resets source 14 (pedal fault mode, a CM848 "
                  "only source)."),
    ),
]

for p in PAIRS:
    a848, old848, new = p["cm848"]
    row = {
        "kind": "function", "address": a848, "old": old848, "verdict": "confirmed", "new": new,
        "evidence": f"Tier {p['tier']}. CM550 counterpart {p['cm550'][0]} ({p['cm550'][1]}). " + p["evidence"],
    }
    if p["plate848"]:
        row["plate_comment"] = p["plate848"]
    ROWS.append(row)

# selectEngineSpeedLimit: the CM848 plate is long, so give the exact sentence to insert instead of repeating it
ROWS[-2]["plate_comment"] = (
    "Lowest-wins arbitration of the engine speed limit, the e2m high speed governor (HSG) reference speed (engine speed in 0.125 rpm counts; "
    "engine_speed_limit_default_cal = 30000 = 3750 rpm): each active source lowers lowest_source_speed_limit and records its number in "
    "limiting_source_number - 2 / 4 / 10 engine_speed_limit_source_2 / _4 / _10, 5 engine_speed_limit_fault_derate, 6 engine_speed_limit_reference, 7 "
    "fuel_pressure_fault_engine_speed_limit_working, 8 the TSC1 override mode select 1 request (the e2m Jcomm high idle override speed, DAT_0005c39a), 9 "
    "j1939_tsc1_override_state.etc1_torque_limit_value (governor mode 3), 11 governor_fuel_idle_limit, 13 engine_speed_limit_converter_slip, 14 "
    "engine_speed_limit_pedal_fault_mode, 15 engine_speed_limit_park_neutral_exit, 16 engine_speed_limit_source_16 (governor_active_flag_b648 set). "
    "Sources 16 and 8 return early with their own value as applied_speed_limit. Otherwise the result is held between engine_speed_limit_minimum (850 "
    "rpm) and engine_speed_limit_maximum (3500 rpm) and stored in engine_speed_limit_arbitrated; engine_speed_limit_ramped follows it (up by "
    "engine_speed_limit_ramp_up_step per pass, down at once). Sources 9 (with ETC1 active), 11 and, while "
    "engine_speed_limit_torque_converter_droop_enable is 0, 13 and 15 apply the ramped limit directly; every other pass applies the droop line unless "
    "the slope is 0: engine_speed_limit_droop_slope = (engine_speed_limit_droop_no_load_speed - engine_speed_limit_reference) x 4369 / "
    "(engine_speed_limit_reference_maximum_fuel_quantity - engine_speed_limit_droop_no_load_fuel_quantity) is recomputed unless "
    "engine_speed_limit_droop_slope_bypass_flag is set (source 10 zeroes the slope first, which sticks only while that flag is set), and "
    "applied_speed_limit = engine_speed_limit_ramped + slope x (engine_speed_limit_ramped_maximum_fuel_quantity - the clamped "
    "high_speed_governor_integral_term) / 4369, never below the ramped limit and capped at engine_speed_limit_droop_cap. "
    "cm848_calculateEffectiveFuelLimit and cm848_calculateEngineLoadPercentages read the same line as a fuel limit. Shared with CM550 0x1d5a0 (the same "
    "arbitration with the same source numbers 2 / 4 / 5 / 6 / 7 / 8 / 9 / 10 / 11; CM550 lacks sources 13-16, has its own source 3 and recomputes "
    "the droop slope only when its inputs change) (was cm848_selectEngineSpeedLimit, cm848_selectTorqueLimit)."
)

# the CM550 rows, exact (function_renames.csv: address,name,comment)
CM550_ROWS = []
for p in PAIRS:
    CM550_ROWS.append(f"{p['cm550'][0]},{p['cm848'][2]},{p['plate550']}")

ROWS.append({
    "kind": "note",
    "text": (
        "CROSS-FIRMWARE, lead (1). The high speed governor is the same six-function block in both firmwares and in the same order (CM550 0x1ce7c PID, "
        "0x1d252 preset, 0x1d2e4 init, 0x1d392 gain set (done), 0x1d5a0 arbitration, 0x1d94e defaults; CM848 0x1f40c, 0x1f34c, 0x1f98c, 0x1fa20, "
        "0x1fd94, 0x20410), and the three CM550 names cm550_initDiagnosticProtocol / cm550_update_engine_protection_thresholds / cm550_FUN_* are wrong "
        "for the code. cm550_FUN_0001d5a0 IS the counterpart of cm848_selectEngineSpeedLimit (one lowest-wins chain, same source numbers, same droop "
        "line; differences listed in the function row). Tiers: A = same body (init 0x1d2e4 / 0x1f98c, defaults 0x1d94e / 0x20410); B = same function "
        "revised (preset 0x1d252 / 0x1f34c, PID 0x1ce7c / 0x1f40c with different fuel scale divisors, arbitration 0x1d5a0 / 0x1fd94 with extra CM848 "
        "sources). The CM848 rows are the function rows of this file (unprefixed names, all free in both CSVs). If tier B is NOT to be shared under the "
        "'same body' rule, give its CM550 rows the cm550_ prefix instead (cm550_presetHighSpeedGovernorIntegrator, cm550_runHighSpeedGovernorPid, "
        "cm550_selectEngineSpeedLimit) and keep the CM848 names; the CM550 rows below then take the same plates. EXACT CM550 function_renames.csv rows "
        "(replace lines 368 / 369 / 370 / 372 / 373; the 0x0001d392 row is already done): " + " | ".join(CM550_ROWS)
    ),
})

ROWS.append({
    "kind": "note",
    "text": (
        "CROSS-FIRMWARE, more candidates not proposed as names (CM848 side still says 'protection'): CM550 cm550_FUN_0001ce58 (0x1ce58) = CM848 "
        "cm848_initProtectionStateWithFuelDemand (0x1f318): both store the same constants 0x13 and 0x28 into the fueling state words (CM550 "
        "indicator ..._13_41 and FSLMAHST, CM848 governor_fuel_mode_command 0x40afae and governor_fuel_mode_input 0x40afb4, 6 apart in both: e2m "
        "Torque_Derate_Fueling_State FSLMFLST 0x01105D02 'which algorithm is controlling fuel after it has been limited' and "
        "Torque_Derate_Fueling_State_2 FSLMAHST 0x01105D08 'group 2 (AH)', 6 apart) and the fuel limit minimum from the 100 percent throttle fueling "
        "value; same function. CM550 cm550_FUN_0001cdf8 vs CM848 cm848_initFuelDemandTableDimensions (0x1f300): NOT the same (CM550 sets five table "
        "descriptors, CM848 two cached offsets). fuelDemandProportionalCalculationSlowCycle40Coordinator is already shared by name (0x1c9d2 / 0x1ef88). "
        "The CM550 droop line users (calculateSpeedRatioComponent 0x26cc8 reads the droop slope and flag like cm848_calculateEffectiveFuelLimit / "
        "cm848_calculateEngineLoadPercentages; cm550_calculateGovernorDroopSpeed) were not compared."
    ),
})
