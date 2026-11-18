import csv, json, re, sys

BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
OUT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W6_governor.jsonl'


def load(fn):
    with open(BASE + fn, newline='') as f:
        lines = [l for l in f if not l.startswith('#')]
    r = csv.reader(lines)
    next(r)
    return [row for row in r if row]


G = {}
for r in load('global_variables.csv'):
    try:
        G[int(r[0], 16)] = r
    except ValueError:
        pass
F = {}
for r in load('function_renames.csv'):
    try:
        F[int(r[0], 16)] = r
    except ValueError:
        pass
A = load('arrays.csv')
existing = set(r[1] for r in G.values()) | set(r[1] for r in F.values()) | set(r[1] for r in A)

out = []
new_names = []


def hx(a):
    return '0x%08x' % a


def g(addr, new, evidence, verdict='confirmed'):
    row = G[addr]
    old = row[1]
    d = {'kind': 'global', 'address': hx(addr), 'old': old, 'verdict': verdict}
    if new:
        d['new'] = new
        new_names.append(new)
    d['evidence'] = evidence
    out.append(d)


def f(addr, new, plate, evidence, verdict='confirmed'):
    old = F[addr][1]
    d = {'kind': 'function', 'address': hx(addr), 'old': old, 'verdict': verdict}
    if new:
        d['new'] = new
        new_names.append(new)
        d['plate_comment'] = plate
    d['evidence'] = evidence
    out.append(d)


def note(text):
    out.append({'kind': 'note', 'text': text})


TS = ('Time-shared window: xref_addr.py lists only application functions, and a raw displacement scan of ROM and Bank 2 finds no instruction below 0x7F60 (no boot user).')

# ---------------------------------------------------------------------------------------------------
# A. Engine retarder engage-delay chain (cm848_updateEngineRetarderActiveState)
# ---------------------------------------------------------------------------------------------------
CHAIN = ('Code: cm848_updateEngineRetarderActiveState chain (hold flag written here but cleared unconditionally before the shift block, '
         'so no effect in this build). ')
g(0x003fb540, 'engine_retarder_request_age_counter',
  CHAIN + 'Counts passes since the last new request (reset to 0 on the pass where engine_retarder_arbitrated_request_percent goes from 0 to nonzero, '
  'else +1, saturating at 65535); zeroed by cm848_initializeEngineRetarderRequestState. RAM dump (base 0x3fa000): 0xffff (no request since boot). ' + TS)
g(0x003fb54a, 'engine_retarder_fuel_demand_at_minimum_pass_counter',
  CHAIN + 'Reset to 0 while fuel_demand_computed is above fuel_demand_computed_min_cal, else +1 (saturating); only user is the engage delay chain, which compares it with 3 / 4 / 5 / 10 by engine speed range. '
  'RAM dump: 0xffff. ' + TS)
g(0x00408e9e, 'engine_retarder_boost_sensor_fault_hold_passes',
  CHAIN + 'Passes to hold a new retarder request while fault bit 8 / 9 / 64 (P0238 / P0237 / P0236 boost pressure sensor circuit high / low / range, decoded via ROM 0x5985a and obd_dtc_code_table) is detected: '
  '0 = no hold, otherwise hold = 1 on the request start and 0 once the request age counter exceeds it (2 reads, 0 writes). Dump value 0. ROM address, so the _cal goes.')
g(0x00408ea6, 'engine_retarder_engage_delay_speed_boundary_low',
  CHAIN + 'Lowest engine speed boundary (rpm x 8) of the delay selection: at or below it 10 passes of engine_retarder_fuel_demand_at_minimum_pass_counter are needed, above it 5 (1 read). Dump value 0. ROM address, no _cal.')
g(0x00408eac, 'engine_retarder_engage_delay_speed_boundary_middle',
  CHAIN + 'Middle boundary (rpm x 8): above it up to the high boundary the required delay is 4 passes, below it 5 (1 read). Dump value 32000 (4000 rpm), equal to the high boundary. ROM address, no _cal.')
g(0x00408eae, 'engine_retarder_engage_delay_speed_boundary_high',
  CHAIN + 'Highest boundary (rpm x 8): above it the required delay is 3 passes (1 read). Dump value 32000 (4000 rpm). ROM address, no _cal.')
g(0x00408ebc, 'engine_retarder_monitored_rpm_threshold_governor_mode_4',
  'Code: only user is cm848_updateEngineRetarderEnableState, in the governor fuel demand mode 4 branch: entry needs protection_monitored_rpm <= this, exit when this < protection_monitored_rpm. '
  'protection_monitored_rpm (0x40af40) is an rpm x 8 word that is current_rpm (cm848_setProtectionParamFromRpm) or, while governor_fuel_active_flag is 1, follows protection_rpm_reference inside a +-protection_rpm_hysteresis_cal band (cm848_smoothProtectionParamTransition, read in full); '
  'whether it is engine speed or a reference speed is not settled, so the name only says monitored rpm. Sibling of engine_retarder_fuel_demand_threshold_governor_mode_4. Dump value 9200 (1150 rpm). ROM address, so the _cal goes.')
g(0x0040a370, None,
  'UNCERTAIN, no name. Code: cm848_selectTemperatureTrimValue sets fuel_demand_rate_min to this while engine_retarder_active_flag is 1 and to mass_charge_flow_combustion_command otherwise; only the init writes it (0), dump 0. '
  'The consumer (.cpp 10140-10185) makes fuel_demand_rate_limited = min(fuel_demand_rate_min, fuel_quantity_ema_filtered - 2 x the rate filter term) while the threshold flags are set and = fuel_demand_rate_min otherwise, so fuel_demand_rate_min is a CAP of a mass charge flow quantity (wave 5 found fuel_quantity_ema_filtered is the charge flow), not a fuel minimum; with the retarder active the cap is 0. '
  'The fuel_demand_rate_* vocabulary itself is domain-suspect, so no name is proposed until that family is re-domained; the old fuel_mode_1 wording has no support in the code.', verdict='uncertain')
g(0x0040a35c, 'service_brake_active_governor_mode_config_bit_0_flag',
  'Code: cm848_updateEngineRetarderEnableState stores 1 when service_brake_delayed_active_flag is 1 and governor_mode_config_flags bit 0 is set, else 0 (word store of the upper half); the init stores 0; xref_addr.py (also 0x40a35e): 0 reads in the whole binary. '
  'Nothing idle- or calibration-related, so the old name is wrong. Type note only: typed dword but only the upper word is written.')
f(0x00010874, None, '',
  'UNCERTAIN, no name. The body is two stores and one test (fuel_demand_rate_min = fuel_demand_rate_minimum_fuel_mode_1_value while engine_retarder_active_flag is 1, else mass_charge_flow_combustion_command); it has no temperature input, so cm848_selectTemperatureTrimValue is wrong, but the role of fuel_demand_rate_min (a cap of a mass charge flow quantity, see 0x40a370) is not settled enough to name it.', verdict='uncertain')

# ---------------------------------------------------------------------------------------------------
# B. High speed governor PID (was fuel_ema_* / fuel_demand_filter_* / injection_timing_compensation_*)
# ---------------------------------------------------------------------------------------------------
HSG = ('Code: cm848_processTorqueLimitTiming is a speed error PID: error = (arbitrated engine speed limit torque_limit_arb_t.limit_source - governor_fuel_rate_tracking, a lead / lag filtered engine speed) x gain / 512, '
       'first order filtered, then proportional / integral / derivative terms clamped and summed into governor_fuel_demand_threshold_cal, which cm848_processProtectionRampControl uses as governor_fuel_demand_value when governor_fuel_demand_mode is 12. ')
E2M = ('e2m corroboration only: the HSG (high speed governor) block at 0x01106000 has proportional gain +0, derivative gain +2, integral gain +4, error filter constant +6, filter gain +8, with the same relative order as ROM 0x406fb4-0x406fbc. ')
ROLE = {'p': ('proportional', 'P term = filtered error x gain / 1113 clamped (injection_timing_max_cal_load)'),
        'i': ('integral', 'I term accumulates filtered error x gain / 17809 in the 32 bit accumulator timing_compensation_accumulator, clamped (injection_timing_compensation_b)'),
        'd': ('derivative', 'D term = (filtered error - its previous value) x gain x 100 / 3478 clamped (injection_timing_base_clamped)')}

# base set (ROM)
g(0x00406fb4, 'high_speed_governor_proportional_gain_base',
  HSG + ROLE['p'][1] + '. Base set coefficient 1 (copied to the selected set when the set code is 16). ' + E2M + 'Dump value 82. ROM address, so the _cal goes.')
g(0x00406fb8, 'high_speed_governor_integral_gain_base',
  HSG + ROLE['i'][1] + '. Base set coefficient 2. ' + E2M + 'Dump value 262. ROM address, so the _cal goes.')
g(0x00406fb6, 'high_speed_governor_derivative_gain_base',
  HSG + ROLE['d'][1] + '. Base set coefficient 3. ' + E2M + 'Dump value 2. ROM address, so the _cal goes.')
# selected set
g(0x0040a8cb, 'high_speed_governor_proportional_gain',
  'Selected set coefficient 1 = proportional gain: written by selectSensorRawChannels / cm848_initSensorRawChannels, read once by cm848_processTorqueLimitTiming where it is scaled by the adjustment table into injection_timing_scale_factor and used as P term = error x it / 1113. Dump 82 (= base set).')
g(0x0040a8cd, 'high_speed_governor_integral_gain',
  'Selected set coefficient 2 = integral gain (same writers / reader): scaled into injection_timing_ema_coeff_computed (cap 0x3d70) and used as I term increment = error x it / 17809. Dump 262.')
g(0x0040a8cf, 'high_speed_governor_derivative_gain',
  'Selected set coefficient 3 = derivative gain (same writers / reader): scaled into injection_timing_compensation_scale and used as D term = error change x it x 100 / 3478. Dump 2.')
# working set (RAM, 0x40a8ad block is packed halfwords at odd addresses)
WK = 'Working set coefficient written by cm848_processSystemStatusLimits (set code 20 / 21; xref_addr.py lists it as the only writer), read by selectSensorRawChannels. Packed halfword block 0x40a8ad-0x40a8b7: the odd-address accesses are real. Dump 0 (no working set loaded).'
g(0x0040a8b5, 'high_speed_governor_proportional_gain_working', WK.replace('coefficient', 'proportional gain (coefficient 1)', 1))
g(0x0040a8b3, 'high_speed_governor_integral_gain_working', WK.replace('coefficient', 'integral gain (coefficient 2)', 1))
g(0x0040a8ad, 'high_speed_governor_derivative_gain_working', WK.replace('coefficient', 'derivative gain (coefficient 3)', 1))
# alternate set (write-only)
AL = 'Alternate set value, write-only here (3 writes in selectSensorRawChannels from DAT_0005c3xx constants or the base set; nothing reads it). Dump 0.'
g(0x0040a8b9, 'high_speed_governor_proportional_gain_alternate', 'Proportional gain (coefficient 1). ' + AL)
g(0x0040a8bb, 'high_speed_governor_integral_gain_alternate', 'Integral gain (coefficient 2). ' + AL)
g(0x0040a8bd, 'high_speed_governor_derivative_gain_alternate', 'Derivative gain (coefficient 3). ' + AL)
# adjustment enables
g(0x00406fd6, 'high_speed_governor_proportional_gain_adjustment_enable',
  'Code: when nonzero cm848_processTorqueLimitTiming scales coefficient 1 by lookupTableInterpolation of |filtered error| through the 14 point axis / multiplier tables (multiplier / 256, result capped 0xf000) - 1 read. Dump 1 (the only adjustment that is on). ' + E2M + 'HSG_Proportional_Gain_Adjustment_Enable (HSPPAJEN) is +0x22 of the block and 0x406fd6 is +0x22 of 0x406fb4. ROM address, so the _cal goes.')
g(0x00406fd8, 'high_speed_governor_integral_gain_adjustment_enable',
  'Code: 0 uses coefficient 2 as is, nonzero scales it through the integral adjustment tables (result capped 0x3d70) - 1 read. Dump 0. e2m corroboration only: HSG_Integral_Gain_Adjustment_Enable (HSITAJEN) is +0x24, same offset as 0x406fd8 from 0x406fb4. ROM address, so the _cal goes.')
g(0x00406fd4, 'high_speed_governor_derivative_gain_adjustment_enable',
  'Code: when nonzero coefficient 3 is scaled through the derivative adjustment tables (result capped 0xffff) - 1 read. Dump 0. e2m corroboration only: HSG_Derivative_Gain_Adjustment_Enable (HSDVAJEN) is +0x20, same offset as 0x406fd4 from 0x406fb4. ROM address, so the _cal goes.')
# adjustment tables
TB = ('14 point lookup (lookupTableInterpolation flags 0) in cm848_processTorqueLimitTiming; input is |fuel_demand_filter_output| (the filtered speed error). e2m corroboration only: HSG gain adjustment tables, '
      'order derivative (0x0112E100 / E200), proportional (E300 / E400), integral (E500 / E600) matches ROM 0x406ff0 / 0x407028 / 0x407060 blocks. ROM address, no _cal. ')
g(0x00407028, 'high_speed_governor_proportional_gain_adjustment_error_axis', 'Axis (absolute filtered error) of the proportional gain adjustment. ' + TB)
g(0x00407044, 'high_speed_governor_proportional_gain_adjustment_multiplier_values', 'Values (multiplier / 256) of the proportional gain adjustment. ' + TB)
g(0x00407060, 'high_speed_governor_integral_gain_adjustment_error_axis', 'Axis of the integral gain adjustment (used only when the integral adjustment enable is nonzero). ' + TB)
g(0x0040707c, 'high_speed_governor_integral_gain_adjustment_multiplier_values', 'Values (multiplier / 256) of the integral gain adjustment. ' + TB)
g(0x00406ff0, 'high_speed_governor_derivative_gain_adjustment_error_axis', 'Axis of the derivative gain adjustment (used only when its enable is nonzero). ' + TB)
g(0x0040700c, 'high_speed_governor_derivative_gain_adjustment_multiplier_values', 'Values (multiplier / 256) of the derivative gain adjustment. ' + TB)
# lookup cache words (existing scheme <table>_cached_axis_offset)
CW = ('First argument (cached axis offset) of the lookupTableInterpolation call in cm848_processTorqueLimitTiming for the {w} gain adjustment tables; init value 2 from cm848_initSensorRawChannels{x}. ' + TS)
g(0x003fa898, 'high_speed_governor_proportional_gain_adjustment_cached_axis_offset', CW.format(w='proportional', x='; dump 26 because only the proportional adjustment is enabled'))
g(0x003fa89a, 'high_speed_governor_integral_gain_adjustment_cached_axis_offset', CW.format(w='integral', x='; dump 2 (adjustment off)'))
g(0x003fa896, 'high_speed_governor_derivative_gain_adjustment_cached_axis_offset', CW.format(w='derivative', x='; dump 2 (adjustment off)'))

# the error filter coefficient (coefficient 4) shares the set with coefficients 1-3: correction of wave 4 names, kept in one family
FIX = 'CORRECTION of the wave 4 name so the whole coefficient set shares one family: coefficient 4 is the error filter coefficient of the same selected set (written together with coefficients 1-3 by the same set selector). '
g(0x00406fba, 'high_speed_governor_error_filter_coefficient_base', FIX + 'Base set value (e2m HSG_Error_Filter_Constant, +6 of the HSG block, corroboration only). ROM address, no _cal.')
g(0x0040a8d1, 'high_speed_governor_error_filter_coefficient', FIX + 'Selected set value the filter coefficient pointer points at.')
g(0x0040a8af, 'high_speed_governor_error_filter_coefficient_working', FIX + 'Working set value.')
g(0x0040a8bf, 'high_speed_governor_error_filter_coefficient_alternate', FIX + 'Alternate set value (write-only).')
g(0x0040a8d3, 'high_speed_governor_error_filter_coefficient_pointer', FIX + 'Pointer to the selected coefficient, passed to cm848_signedFirstOrderFilter for the speed error.')
g(0x00406fbc, 'high_speed_governor_error_filter_gain',
  'CORRECTION of the wave 4 name fuel_demand_filter_input_gain: multiplier / 512 on the speed error (arbitrated engine speed limit minus governor_fuel_rate_tracking) before the first order filter (1 read). e2m corroboration only: HSG_Error_Filter_Gain (HSFTGN, 1/512 scale) at +8. ROM address, no _cal.')
g(0x0040a8c3, 'high_speed_governor_filtered_error',
  'CORRECTION of the wave 4 name fuel_demand_filter_output: the filtered speed error (arbitrated engine speed limit minus compensated engine speed), clamped between the limit words 0x406fbe / 0x406fc0 and used as the input of all three terms and of the gain adjustment tables; dump 8000 (the upper limit, i.e. 1000 rpm below the limit). e2m corroboration only: HSG_Filtered_Error_Term (HSER).')

# ---- functions of the block (outside the lead list, found while tracing the HSG; names follow from the above)
f(0x0001f40c, 'cm848_runHighSpeedGovernorPid',
  'Runs the high speed governor PID: the speed error (arbitrated engine speed limit minus governor_fuel_rate_tracking, times the error filter gain / 512) passes a first order filter; the proportional, integral and derivative terms (each gain scaled by a 14 point table of the absolute error when its adjustment enable is set) are clamped and summed into governor_fuel_demand_threshold_cal, the high speed governor fueling. The integrator is preset to the fuel demand while governor_mode_code (0x40a2d0) is not 12 (cm848_presetHighSpeedGovernorIntegrator) and reset when engine speed exceeds the limit plus an offset with governor_fuel_demand_mode (0x40a154) 12 and low fuel demand (was cm848_processTorqueLimitTiming).',
  'Code as described under the gain rows; e2m HSG block (HSPPGN / HSITGN / HSDVGN, gain adjustment tables, integrator preset / reset, fueling clamps HSMXFLLM / HSMNFLLM) matches term by term and by relative offset (corroboration only). Dump reproduces all three terms and the sum: P 2062 (= 8000 x 287 / 1113) + D 0 + I 117 (= 8000 x 262 / 17809) = 2179 = governor_fuel_demand_threshold_cal.')
f(0x0001f34c, 'cm848_presetHighSpeedGovernorIntegrator',
  'While governor_mode_code (0x40a2d0) is not 12 presets the integrator to fuel_demand_computed minus the part of the proportional term above the preset offset limit, clamped between the integrator preset minimum and maximum, so the governor takes over without a step; also copies the filtered error to its previous-value word (was cm848_calculateTimingCompensation).',
  'Read from the .cpp body; acc = fuel_demand_computed - max(P, 0) + min(max(P, 0), addend) with P = injection_timing_max_cal_load, clamped to injection_timing_compensation_calculation_lower / upper_limit; e2m HSG_Integrator_Preset_Minimum / Maximum / HSG_Integrator_Reset_Offset sit at the same relative offsets (+0x18 / +0x1A / +0x2E).')
f(0x0001fa20, 'cm848_selectHighSpeedGovernorGainSet',
  'Selects the high speed governor gain set - error filter coefficient plus proportional, integral and derivative gains - and records its code in fuel_demand_state_code: the base set (code 16) when system_feature_config_flags bit 0 is clear; otherwise a transient set (code 17, DAT_0005c32c-0x5c332) while engine acceleration is above DAT_0005c314 and governor_mode_code_prev is not 12, and once the transient time DAT_0005c316 has elapsed the working set (when loaded) or the low / high reference speed set (codes 18 / 19, chosen by torque_limit_load_working against DAT_0005c322 / DAT_0005c318; base set 16 between them); it also records the alternate set (was selectSensorRawChannels).',
  'Read from the .cpp body (all four coefficients are always written together with the code); nothing to do with sensor raw channels. The ROM constants DAT_0005c314 .. 0x5c332 line up offset by offset with the e2m HSG block 0x01129000 (acceleration threshold +0, acceleration time +2, high reference speed threshold +4 then derivative / filter / integral / proportional +6..+0xC, low threshold +0xE then +0x10..+0x16, transient +0x18..+0x1E): corroboration only, but it makes torque_limit_load_working a reference speed.')
f(0x0001f98c, 'cm848_initializeHighSpeedGovernorGainSet',
  'Start-up initialisation of the high speed governor: selects the base gain set (code 16), sets the integral term to its upper limit, clears the error filter accumulator, points the error filter coefficient pointer at the selected coefficient and sets the three gain adjustment cached axis offsets to 2 (was cm848_initSensorRawChannels).',
  'Read from the .cpp body.')
f(0x000422c0, 'cm848_calculateHighSpeedGovernorCompensatedEngineSpeed',
  'Calculates governor_fuel_rate_tracking, the engine speed after the lead / lag compensator of the high speed governor: y = (rpm x factor_a + previous y x offset - previous rpm x factor_b) >> 15, capped at 36000 (rpm x 8). The compensator is active (cruise_speed_override_flag 1) when the drivetrain ratio is below DAT_0005c94e with the ratio settled, when fault bit 29 or 30 is detected or for a standalone drivetrain; otherwise the factors make it pass the engine speed through (was cm848_processSpeedControlLimits).',
  'Code: only reader of the result is the speed error input of cm848_processTorqueLimitTiming. e2m corroboration only: HSG_Comp_Filter_Coefficient_1-3, HSG_Comp_Transition_Coefficient, HSG_Comp_Gear_Ratio_Threshold, HSG_Compensated_Engine_Speed (HSDCES) and HSG_Compensation_Active describe the same lead / lag compensator.')
f(0x00042438, 'cm848_initializeHighSpeedGovernorCompensatedEngineSpeed',
  'Initialises the compensated engine speed of the high speed governor: clears cruise_speed_override_flag, sets governor_fuel_rate_tracking and its previous-speed words to the current engine speed and the three compensator factors to cruise_speed_default_cal (was cm848_initEngineSpeedTracking).',
  'Read from the .cpp body.')
g(0x0040b706, 'high_speed_governor_compensated_engine_speed',
  'Written by cm848_processSpeedControlLimits (lead / lag compensator output, capped 36000) and cm848_initEngineSpeedTracking (current rpm); the only reader is cm848_processTorqueLimitTiming (1 read), where it is subtracted from the arbitrated engine speed limit. Nothing to do with fuel rate.')

# ---------------------------------------------------------------------------------------------------
# C. fuel_trim_* family: drivetrain ratio settle flags (verified) ; saved restore block (note)
# ---------------------------------------------------------------------------------------------------
g(0x0040a276, 'drivetrain_ratio_unsettled_flag',
  'Code: protectionTimeoutControl (the drivetrain ratio estimator) sets it to 1 when vehicle_speed is below vehicle_speed_minimum or during cranking, while the ratio settle counters / release timer run or etc1_disable_control is 1, and clears it only when all of them are 0; etcTransmissionModeControl copies etc1_disable_control into it on the J1939 automatic drivetrains. Read by cm848_runOperatingModeSpeedGovernor (mode 7 reference speed reduction needs 0 unless transmission_type_cal is nonzero) and cm848_processSpeedControlLimits (compensator needs 0). Dump 1. Not a fuel trim.')
g(0x0040b700, 'drivetrain_ratio_unsettled_release_timer',
  'Code: protectionTimeoutControl reloads it from DAT_0005c940 when fuel_flow_divisor_settle_counter reaches 1 and counts it down to 0; 0 is one of the conditions to clear drivetrain_ratio_unsettled_flag (2 reads / 2 writes, one function).')
g(0x003fd05a, 'drivetrain_ratio_save_pending_flag',
  'Code: protectionTimeoutControl sets it to 1 whenever drivetrain_ratio_unsettled_flag is set and clears it after storing fuel_flow_rpm_divisor into fuel_flow_rpm_divisor_saved once the divisor is unchanged, the flag is 0 and fuel_demand_computed exceeds DAT_0005c93e (1 read / 2 writes). '
  'Time-shared window: xref_addr.py lists only protectionTimeoutControl (0x525e54) and a raw displacement scan of ROM and Bank 2 finds no instruction below 0x7F60 (no boot user).')

# ---------------------------------------------------------------------------------------------------
# D. Sensor channel 75 deviation diagnostic (0x507214)
# ---------------------------------------------------------------------------------------------------
f(0x00507214, 'cm848_calculateSensorChannel75DeviationDiagnosticConditions',
  'Calculates governor_speed_stability_conditions_flag, the enable flag of the sensor channel 75 deviation diagnostic: cm848_calibrationGroup11_periodic flags a deviation of sensor_channel75_value_minus_reference from governor_speed_ramp_output (the boost pressure target ramp of cm848_selectSensorBlendOutput), and governor_speedStability_counter_syncDiag then counts it and sets diagnostic_status_bits bit 0x20, an input of cm848_selectBoostPressureFromSensorChannel75. The flag is 1 while that bit is already set, otherwise only when the governor operating mode is 0, fault bit 718 (no DTC slot) is clear, diagnostic_clear_condition_flag is set, sensor_channel75_fault_status is 0, the ramp output is within DAT_004067d8 of its average (DAT_0040a6be, DAT_0040a6b4) and governor_speed_ramp_pid_stable_gate is 1 (was governor_speedRamp_stabilityFlag_calc).',
  'Medium confidence on the exact fault the diagnostic detects, high on its place: the three functions of cm848_calibrationGroup11_periodic form one deviation diagnostic on channel 75 (the boost pressure channel of cm848_selectBoostPressureFromSensorChannel75); governor_speed_ramp_output is written once, by cm848_selectSensorBlendOutput (max of a rate limited ramp and a target, copied to boost_pressure_target_input when governor_operating_mode is 0 or 1). The governor_speed vocabulary has no support.')

# ---------------------------------------------------------------------------------------------------
# E. TSC1 ignored request list lookups
# ---------------------------------------------------------------------------------------------------
f(0x00053c68, 'cm848_refreshEngineTsc1IgnoredRequestEntry',
  'Searches the engine TSC1 ignored request list engine_tsc1_ignored_request_entries (8-byte entries: type word, source address, override control mode, countdown) for the entry with type param_1, source address param_2 and mode param_3; when found it reloads the entry countdown from etc1_torque_mode_timeout_cal and returns 1, otherwise 0. torqueControlModeHandler calls it for engine TSC1 requests that are not override mode 0 and drops the request when it returns nonzero (was cm848_findJ1939MessageEntry).',
  'Body read in the .cpp: compares word +0, byte +2, word +4 and writes the word at +6; caller role as traced in wave 4. Pair of cm848_refreshRetarderTsc1IgnoredRequestEntry (list B). The plate of 0x53cd8 already cites retarder_tsc1_ignored_request_entries (the stale fault_entry_data_array reference is gone).')
f(0x00053cd8, 'cm848_refreshRetarderTsc1IgnoredRequestEntry',
  'Searches the retarder TSC1 ignored request list retarder_tsc1_ignored_request_entries (6-byte entries: source address, override control mode, countdown) for source address param_1 and control mode param_2; when found it reloads the countdown from etc1_torque_mode_timeout_cal and returns 1, otherwise 0. cm848_processEngineRetarderTsc1Request calls it for every TSC1 request whose control mode is not 0 and drops the request when it returns nonzero (was cm848_refreshTsc1RequestEntry; the older plate said was cm848_addCoolantCalEntry).',
  'Body read in the .cpp. Keeps the facts of the old plate; the add / remove / expire functions of the two lists are already named cm848_add / remove*Tsc1IgnoredRequestEntry.')

# ---------------------------------------------------------------------------------------------------
# F. CAN queue pointer spelling
# ---------------------------------------------------------------------------------------------------
g(0x0040ad24, 'can_transmit_queue_enqueue_pointer',
  'Spelling only: its siblings are can_transmit_queue_dequeue_pointer (0x40ad28) and can_receive_queue_read_pointer (0x40ad30). Enqueue pointer of the 12-byte transmit records at can_transmit_queue_buffer (0x40ac34); mpc555_processJ1939TxBufferSend compares it with the dequeue pointer to detect an empty queue. The comment of 0x40ad28 cites the old name and needs a refresh.')

# ---------------------------------------------------------------------------------------------------
# G. Cache words with no user
# ---------------------------------------------------------------------------------------------------
UN = ('Only written (2) by cm848_initLookupTableParams, together with 0x3fa110 / 0x3fa112 (all_speed_governor_droop_blend_0 / _128 cached axis offsets, passed to lookupTableInterpolation by cm848_calculateGovernorCompensatorCoefficients); '
      '2 is the first axis segment the lookup starts from. Whole-binary scan of ROM and Bank 2 for loads, stores and lis+addi address builds finds no other user of this displacement (xref_addr.py: 0 reads / 1 write; RAM dump still 2). Time-shared window: no access below 0x7F60. '
      'Medium confidence that it is a lookup cache (adjacent group, init value 2), high that the application never reads or passes it.')
g(0x003fa114, None, 'UNCERTAIN, no name (candidate unused_lookup_cached_axis_offset_a if medium confidence is accepted). ' + UN, verdict='uncertain')
g(0x003fa116, None, 'UNCERTAIN, no name (candidate unused_lookup_cached_axis_offset_d if medium confidence is accepted). ' + UN, verdict='uncertain')

# ---------------------------------------------------------------------------------------------------
# H. Not settled
# ---------------------------------------------------------------------------------------------------
note('UNCERTAIN 0x003fd910 (no CSV row, word, EEPROM 0x48e = 0 in the dump): the earlier lead says it is the speed offset added to cruise_speed_command in both users, but the second user is governorCruiseStateMachine (.cpp ~80393), which passes it as param_1 of governor_cruise_rampScale_calc (result = param_1 x 1024 / the fuel demand span, capped 0x22c8) into cruise_ramp_rate_a_working; 0x3fd914 goes the same way into cruise_ramp_rate_c_working. So it reads as cruise ramp rate A, and the retarder permission function (cm848_calculateEngineRetarderCruisePermissionPercent, which adds it to cruise_speed_command) uses it in a different unit. No name proposed; settle the cruise side first.')
note('LABEL CHECK result for 0x3fb54c / 0x3fb54e (outcome of the wave 4 note): the CSV rows are right (0x3fb54c engine_retarder_request_on_delay_counter, 0x3fb54e tc_lockup_disengage_state) but the current .cpp still prints them crossed. Lines 41136 / 41139 / 41165 / 41204 (cm848_updateEngineRetarderEnableState, the torque converter lockup state at 0x3fb54e, disassembly sth at 0x41428) print the plain name engine_retarder_request_on_delay_counter, while the real on-delay counter accesses at 0x3fb54c (lines 41553-41577, cm848_driveEngineRetarderOutput) print the underscore name _engine_retarder_request_on_delay_counter, and the boot kernel call at line 1132 (function image cm848_validateDiagnosticRequestLengthAndAuthorization at RAM 0x3fb54c = ROM 0x597c) prints the plain name as a function call. tc_lockup_disengage_state is never printed. Reading the .cpp therefore misleads for this pair; the label mapping needs a fix before more names are applied in the 0x3fb54c window, the names themselves should stay.')
note('Engage delay chain facts (cm848_updateEngineRetarderActiveState, rows above): bVar1 = fault bit 8 / 9 / 64 = P0238 / P0237 / P0236 (boost pressure sensor circuit high / low / range). A new request is the pass where the arbitrated percent goes from 0 to nonzero. With bVar1 and the hold passes nonzero the hold flag is set on that pass and cleared once the age counter exceeds the hold passes; without bVar1 it is cleared once engine_retarder_fuel_demand_at_minimum_pass_counter exceeds 3 / 4 / 5 / 10 (above the high boundary / middle to high / low to middle / at or below low). The branch that sets the hold flag unconditionally on a new request needs governor_system_config_flags mask 4 (bit 2); the EEPROM value here is 0x10 (mask 0x10 only), so it is off. RAM dump (base 0x3fa000): both counters 65535, hold passes 0, boundaries 0 / 32000 / 32000, so only the delay greater than 5 passes release applies. The hold flag is cleared unconditionally (disassembly 0x41ea0 / 0x41eb0) before it is read, so the whole chain has no effect in this build; the names describe the intent the code shows. governor_system_config_flags (0x3fd5d2) and governor_mode_config_flags (0x3fd5ce) are EEPROM words (offsets 0x150 / 0x14c) without _cal: legacy naming debt, not renamed here.')
note('HIGH SPEED GOVERNOR (the answer to the fuel_ema coefficient 1-3 rows): cm848_processTorqueLimitTiming is a PID on the engine speed error, not a fuel demand filter and not injection timing compensation. Code: error = (arbitrated engine speed limit torque_limit_arb_t.limit_source, an rpm x 8 value capped at 36000 in cm848_selectTorqueLimit) minus governor_fuel_rate_tracking (a lead / lag filtered rpm), first order filtered; coefficient 1 / 2 / 3 are the proportional / integral / derivative gains (P: error x gain / 1113 clamped; I: accumulator += error x gain / 17809, preset by cm848_calculateTimingCompensation while governor_mode_code is not 12 and reset at overspeed; D: error change x gain x 100 / 3478 clamped), each optionally scaled by a 14 point table of |error| (multiplier / 256). The sum, clamped, is governor_fuel_demand_threshold_cal, which becomes governor_fuel_demand_value when governor_fuel_demand_mode is 12 (cm848_processProtectionRampControl); the integrator output also offsets the speed limit table in cm848_selectTorqueLimit. RAM dump check: the three terms and the sum are reproduced - P 2062 = error 8000 x adjusted gain 287 / 1113, D 0, I 117 = 8000 x 262 / 17809, sum 2179 = governor_fuel_demand_threshold_cal; gain set code 16, only the proportional adjustment enabled, so its cache word moved (26) and the other two stayed 2. The e2m HSG (high speed governor) group matches term by term and by relative offset (HSPPGN +0, HSDVGN +2, HSITGN +4, filter constant +6, filter gain +8, filtered error limits +0xA / +0xC, integrator limits +0xE / +0x10, reset value +0x12, reset speed / fuel +0x14 / +0x16, preset min / max +0x18 / +0x1A, fueling clamps +0x1C / +0x1E, adjustment enables +0x20 / +0x22 / +0x24, derivative / proportional clamps +0x26 .. +0x2C, preset offset +0x2E), so the family name high_speed_governor_ is e2m vocabulary and the roles are code. HSG = high speed governor, sibling of the all speed governor (ASG) and low speed governor (LSG) in the e2m; the repo already uses all_speed_governor_*. Remaining words of the block NOT in the rows above, proposed for a follow-up (current name -> new name; min / max are inverted in several old names, checked against the code and the dump): 0x40a8c1 governor_fuel_demand_threshold_cal -> high_speed_governor_fueling (a RAM output word, so the old _cal is wrong); 0x40a8c5 injection_timing_max_cal_load -> high_speed_governor_proportional_term; 0x40a8c7 injection_timing_base_clamped -> high_speed_governor_derivative_term; 0x40a8c9 injection_timing_compensation_b -> high_speed_governor_integral_term; 0x3fa890 timing_compensation_accumulator (dword) -> high_speed_governor_integrator; 0x40a8d7 injection_timing_compensation_int -> high_speed_governor_error_filter_accumulator; 0x40a8db injection_timing_scale_factor -> high_speed_governor_proportional_gain_adjusted; 0x40a8df injection_timing_ema_coeff_computed -> high_speed_governor_integral_gain_adjusted; 0x40a8dd injection_timing_compensation_scale -> high_speed_governor_derivative_gain_adjusted; 0x3fa894 fuel_demand_filter_output_snapshot -> high_speed_governor_filtered_error_previous; 0x40a8b7 fuel_demand_state_code -> high_speed_governor_gain_set_code; 0x40a8b1 fuel_demand_filter_coefficient_working_set_code -> high_speed_governor_working_gain_set_code; 0x406fbe fuel_demand_filter_output_upper_limit / 0x406fc0 _lower_limit -> high_speed_governor_filtered_error_maximum / _minimum; 0x406fc2 injection_timing_compensation_limit_upper / 0x406fc4 _lower -> high_speed_governor_integrator_maximum / _minimum; 0x406fc6 injection_timing_compensation_initial_value -> high_speed_governor_integrator_reset_value; 0x406fc8 governor_mode_c_rpm_offset_cal -> high_speed_governor_integrator_reset_speed_offset; 0x406fca governor_mode_c_fuel_demand_threshold_cal -> high_speed_governor_integrator_reset_fuel_demand_threshold; 0x406fcc injection_timing_compensation_calculation_lower_limit / 0x406fce _upper_limit -> high_speed_governor_integrator_preset_minimum / _maximum; 0x406fd0 governor_fuel_demand_threshold_lower_cal (really the MAXIMUM, dump 5888) / 0x406fd2 _upper_cal (the MINIMUM, dump 0) -> high_speed_governor_fueling_maximum / _minimum; 0x406fda injection_timing_base_lower_cal (MAXIMUM 2208) / 0x406fdc _upper_cal (MINIMUM -2206) -> high_speed_governor_derivative_term_maximum / _minimum; 0x406fde injection_timing_load_floor_cal (MAXIMUM 2208) / 0x406fe0 injection_timing_max_load_cal (MINIMUM -2206) -> high_speed_governor_proportional_term_maximum / _minimum; 0x406fe2 injection_timing_compensation_addend -> high_speed_governor_integrator_preset_offset_limit; 0x3fa89c injection_timing_step_counter / 0x3fa89e injection_timing_working are the transient gain set timer (counter x 20 compared with DAT_0005c316) - not renamed. Wave-4 plates and comments that say fuel demand filter / injection timing compensation in this block (and the 0x3fa88c / 0x3fa88e fuel_ema_slot_state_1 / 2 cache words of the same function pair) need the same refresh. The torque_limit_* arbitration (cm848_selectTorqueLimit, torque_limit_arb_t) is the high speed governor reference speed selection (e2m HSG_Ref_Speed_State / HSG_Indicated_Ref_Speed_State): not examined further here.')
note('fuel_trim_* family (lead of note 138): domain finding, no rename of the 0x40a20a-0x40a248 words proposed. Verified: (1) fuel_trim_speed_override_flag / fuel_trim_override_release_timer / fuel_trim_override_latch_flag are the drivetrain ratio settle state (rows above), not a fuel trim. (2) The fuel_trim_saved_* / fuel_trim_pid_coeff_* / fuel_trim_save_valid_flag words (0x40a216-0x40a248) are read ONLY by cm848_restoreEngineOperatingMode (0xfb28), which, when engine_operating_mode is 0 and fuel_trim_save_valid_flag is nonzero, sets engine_operating_mode 30 and copies them into the live governor state (speed_request_unfiltered, governor_pid_integral_gain / _proportional_gain, fuel_pid_shadow_coeff0-8 with fuel_demand_pid_coeffs repointed at fuel_trim_pid_coeff_0, governor_rpm_actual, governor_fuel_demand_tracking_limit, fuel_trim_speed_reference, fuel_trim_speed_request_working and the six fuel_trim_pid_* words that cm848_runOperatingModeSpeedGovernor consumes while fuel_trim_mode_active_flag is 1). (3) No write to the saved block is visible: xref_addr.py lists 0 writes and exactly one reader (the restore function) for each of the 26 words 0x40a216-0x40a246, and a lis+addi scan of ROM and Bank 2 finds no address build inside 0x40a216-0x40a248 other than the two in the restore function itself (0x40a232 and 0x40a21e); the RAM dump holds 0 in all of it. So either the restore path never runs in this build (flag stays 0) or something outside the visible application fills the block (for example a RAM image kept across a warm reset); in both cases the names must say saved / restored, not fuel trim. Suggested scheme once the writer is settled: <destination name>_saved, e.g. governor_pid_integral_gain_saved for fuel_trim_saved_integral_gain, speed_request_unfiltered_saved, governor_rpm_actual_saved, governor_fuel_demand_tracking_limit_saved; fuel_trim_pid_integral_gain_calc / _proportional_gain_calc (0x40a254 / 0x40a256) are duplicates of governor_pid_integral_gain / _proportional_gain written by cm848_calculateGovernorCompensatorCoefficients. The e2m ASG (all speed governor) group names the same compensator (ASG_Coefficient_1-3 compensation filter coefficients). The governor_reference_speed_reduction_* rows of wave 4 stay valid.')
note('NEAR 0x507214: the governor_speed_* words of the channel 75 deviation diagnostic carry the wrong vocabulary and are candidates for a follow-up: governor_speed_ramp_output (0x40a6c6, boost pressure target ramp output, copied to boost_pressure_target_input) with governor_speed_ramp_state / governor_speed_ramp_target_cal / governor_speed_target_input / governor_speed_ramp_at_target_flag (cm848_selectSensorBlendOutput 0x19900, itself misnamed: it is the boost pressure target ramp), governor_speed_b_pid_output (0x40a6ec, written by cm848_selectFuelDemandUpperLimit, read by cm848_calculateFuelDemandLimits and the stability gate), governor_speed_deviation_exceeds_threshold_flag (0x40a6bc), governor_speed_stability_conditions_flag (0x40a6b8), governor_speed_sync_stable_flag. Not renamed: the pairing of the PID output with the channel is not settled.')
note('Skipped leads (one line each): row 0 convention note and row 1 retarder domain proof are informational; the note on the confirm counters A / B is done (their inputs 0x40b060 / 0x40b09e became variable_geometry_turbocharger_closed_adjustment_enable_flag / _span_adjustment_active_flag in wave 5); the dual accelerator pedal note is a comment refresh only (0x3fee46, 0x40b556, 0x40b558 rows still cite the old cruise_speed_* names); row 195 skipped on purpose; the TSC1 element-field and array type notes (DAT_003fb918 / 3fb91a / 3fb91c, 3fb968 / 3fb96a) are informational; the CAN queue record sizes and the engine_data_log_buffer / 0x40ad28 type notes are type issues for a typing pass; the mode 7 reduction reason is still unsettled (the governor_reference_speed_reduction_* mechanism rows stand).')

out.insert(0, {'kind': 'note', 'text': 'SCOPE: seven rows override names applied in wave 4 (global 0x406fba, 0x40a8d1, 0x40a8af, 0x40a8bf, 0x40a8d3, 0x406fbc, 0x40a8c3, all marked CORRECTION: the fuel_demand_filter_* words are the error filter of the high speed governor PID, in the same coefficient set as the lead rows fuel_ema_coeff_1-3); six functions (0x1f40c, 0x1f34c, 0x1fa20, 0x1f98c, 0x422c0, 0x42438) and global 0x40b706 are outside the lead list and are the code and the input of that same block, so the family stays consistent; the rows for 0x40a370, function 0x10874 and 0x3fa114 / 0x3fa116 are uncertain with no new name.'})

# ---------------------------------------------------------------------------------------------------
# validation
# ---------------------------------------------------------------------------------------------------
errs = []
seen = {}
for r in out:
    if r['kind'] in ('global', 'function') and r.get('new'):
        n = r['new']
        if n in existing:
            errs.append('exists: ' + n)
        if n in seen:
            errs.append('dup new: ' + n)
        seen[n] = r['address']
        if re.search(r'0x|_cal$', n):
            errs.append('bad token: ' + n)
        if r['kind'] == 'global' and not re.fullmatch(r'[a-z0-9_]+', n):
            errs.append('bad chars: ' + n)
        if r['kind'] == 'function' and not re.fullmatch(r'cm848_[a-z][A-Za-z0-9]+', n):
            errs.append('bad function name: ' + n)
        if r['kind'] == 'function' and not n.startswith('cm848_'):
            errs.append('function prefix: ' + n)
        for a, b in (('cm848_', ''),):
            pass
        if len(n) > 90:
            errs.append('long: ' + n)
    if r['kind'] == 'global':
        addr = int(r['address'], 16)
        if not (0x3fd482 <= addr <= 0x3feec1) and r.get('new', '').endswith('_cal'):
            errs.append('_cal outside eeprom: ' + r['address'])
if errs:
    print('ERRORS'); print('\n'.join(errs)); sys.exit(1)

with open(OUT, 'w') as fh:
    for r in out:
        fh.write(json.dumps(r) + '\n')
from collections import Counter
print(Counter((r['kind'], r.get('verdict')) for r in out))
print('rows', len(out))
