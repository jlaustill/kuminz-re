import json
import re

RES = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_injection.jsonl'
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/'
text = open(RES).read()

pairs = [
    (
        "Written by cm848_processEngineRpmDerivative as engine_rpm_state.target_rpm - governor_target_rpm_snapshot (change of target rpm per call), no governor involved. e2m Unfiltered_Engine_Acceleration 0x018A4304 = +4 from 0x40b28c.",
        "Written only by cm848_processEngineRpmDerivative as engine_rpm_state.target_rpm - governor_target_rpm_snapshot (change of target rpm per call). e2m Unfiltered_Engine_Acceleration 0x018A4304 = +4 from 0x40b28c. Other readers (4 reads): cm848_processGovernorLoadCondition, cm848_processSpeedGovernorControl and cm848_updateTransmissionConditionFlags; they add it to a previous-snapshot copy and compare it with governor_speed_error_offset_cal, i.e. they use it as a rate of change (that cal and governor_speed_error_prev_snapshot are probably misnamed the same way; not checked).",
    ),
    (
        "Read by cm848_setFuelStatusFlags (bit 0x10 of fuel_demand_mode_flags), which cm848_updateMainInjectionTimingByDeliveryMode turns into mask 4 of injection_timing_adjustment_flags (e2m Final_Timing_Adjustments_Flag order",
        "Read by cm848_setFuelStatusFlags (sets 0x10 of fuel_demand_mode_flags) and by cm848_updateMainInjectionTimingByDeliveryMode (rebuilds mask 4 of injection_timing_adjustment_flags; e2m Final_Timing_Adjustments_Flag order",
    ),
    (
        "Read by cm848_setFuelStatusFlags (0x20 of fuel_demand_mode_flags -> mask 2 of injection_timing_adjustment_flags = e2m CBO).",
        "Read by cm848_setFuelStatusFlags (sets 0x20 of fuel_demand_mode_flags) and by cm848_updateMainInjectionTimingByDeliveryMode (rebuilds mask 2 of injection_timing_adjustment_flags = e2m CBO).",
    ),
    (
        "Readers choose the matching period (crank_tooth_period_raw when 1, crank_period_accumulator when 0) in cm848_calculateAuxiliaryInjectionPulseWidth, the pilot pulse width, cm848_setMainQuantityAndPulseWidthLimits and cm848_vehicleSpeedSensorInterruptHandler (0x526f98), which picks engine_rpm_state.reserved_0a or reserved_0c by the flag.",
        "crank_tooth_period_raw is the sum of the tooth periods captured in the channel 1 handler mpc555_updateEngineCrankState, so the flag reads as a speed source choice. Other readers: cm848_calculatePilotInjectionPulseWidth, cm848_calculateAuxiliaryInjectionPulseWidth (the wave-3 note says it chooses crank_tooth_period_raw or crank_period_accumulator; not re-checked), cm848_setMainQuantityAndPulseWidthLimits and cm848_vehicleSpeedSensorInterruptHandler (0x526f98, picks engine_rpm_state.reserved_0a or reserved_0c by the flag).",
    ),
    (
        "Blend of four engine speed x fuel timing maps in cm848_calculateFuelDemandTimingOffset (stores at 0x15044 / 0x15054; maps in fuel_demand_calc_c / _b / _a / _boost5_lookup 0x40a4d4-0x40a4da), then clamped to +-0x400 counts after adding a table adjustment (the same clamp as the main timing) and used as the timing floor in cm848_applyCombustionTimingLimits.",
        "Written at 0x15044 / 0x15054 in cm848_calculateFuelDemandTimingOffset, which looks up four engine speed x fuel_demand_limit maps (fuel_demand_calc_c / _b / _a / _boost5_lookup 0x40a4d4-0x40a4da) and picks / blends them by fuel_blend_lower / upper_map_number (the tail of that function was not read). cm848_applyFuelDemandOffset adds a table adjustment to it and clamps the sum to -1023..1024 counts (the same clamp as the main timing); the result is the timing reference that cm848_applyCombustionTimingLimits clamps.",
    ),
]
for old, new in pairs:
    n = text.count(old)
    print(n, old[:70])
    if n == 1:
        text = text.replace(old, new)

six = {'0x0005fa1a', '0x0005fa2c', '0x0005fa3e', '0x0005f8ac', '0x0005f8e0', '0x0005f8ee'}
rows = []
for line in text.splitlines():
    if not line.strip():
        continue
    r = json.loads(line)
    if r['kind'] == 'global' and r['address'] in six:
        continue
    rows.append(r)

rows.append({
    "kind": "note",
    "text": "Auxiliary pulse interaction tables (six rows in global_variables.csv without a name, rendered WORD_ARRAY_0005xxxx; campaign status 'retry'): NOT given as rows because the first-pass objection of the campaign could not be recovered (the docs CSV cuts its text at 427 characters and the full text is not in the job files). Code, read in cm848_calculateAuxiliaryInjectionPulseWidth (lines 43818-43835): when main_injection_pulse_width_before_minimum_check != 0 the auxiliary quantity becomes auxiliary_injection_quantity + ((scale x correction) >> 4), with scale = dualAxis(x = auxiliary_injection_quantity on 0x5fa1a, y = fuel_pressure_sensor on 0x5fa2c, grid 0x5fa3e, 8 x 8) and correction = dualAxis(x = main_to_auxiliary_injection_interval on 0x5f8ac, y = main_injection_pulse_width_before_minimum_check on 0x5f8e0, grid 0x5f8ee, 6 x 25); the sum is then clamped to 0..0x1700. It mirrors the main_quantity_pilot_correction_* family exactly (x_axis / y_axis / grid and scale_x_axis / scale_y_axis / scale_grid exist at 0x5f69a-0x5f82c in global_variables.csv). Proposed names if the objection is not substantive: 0x5fa1a injection_quantity_auxiliary_main_correction_scale_x_axis, 0x5fa2c injection_quantity_auxiliary_main_correction_scale_y_axis, 0x5fa3e injection_quantity_auxiliary_main_correction_scale_grid, 0x5f8ac injection_quantity_auxiliary_main_correction_x_axis, 0x5f8e0 injection_quantity_auxiliary_main_correction_y_axis, 0x5f8ee injection_quantity_auxiliary_main_correction_grid (rename only; types word[9] / word[9] / word[64] and word[26] / word[7] / word[150]). The first-wave G1b note found both grids zero in their first rows in the RAM dump (engine off)."
})

# cross-firmware check of every old name
files = [
    FW + 'CM550_J90350.00_analysis/output/global_variables.csv',
    FW + 'CM550_J90350.00_analysis/output/function_renames.csv',
    FW + '../docs/cross_firmware_variable_map.csv',
    FW + 'cross_firmware_matches.csv',
]
blobs = {}
for f in files:
    try:
        blobs[f] = open(f).read()
    except Exception as exc:
        print('cannot read', f, exc)
hits = []
for r in rows:
    old = r.get('old')
    if not old or old == r.get('new'):
        continue
    for f, b in blobs.items():
        if re.search(r'(?<![A-Za-z0-9_])' + re.escape(old) + r'(?![A-Za-z0-9_])', b):
            hits.append((old, f.split('/')[-1]))
print('cross-firmware hits:', hits)
if hits:
    rows.append({
        "kind": "note",
        "text": "Cross-firmware link check: these old names also occur in the CM550 or cross-firmware files and need a look on that side when the renames are applied: " + '; '.join(sorted(set(o + ' in ' + f for o, f in hits))) + "."
    })
else:
    rows.append({
        "kind": "note",
        "text": "Cross-firmware link check: none of the old function or global names of this file occurs in the CM550 global_variables.csv / function_renames.csv, docs/cross_firmware_variable_map.csv or firmware/cross_firmware_matches.csv, so no cross-firmware link breaks."
    })

with open(RES, 'w') as out:
    for r in rows:
        out.write(json.dumps(r, ensure_ascii=True) + '\n')
print('rows written', len(rows))
