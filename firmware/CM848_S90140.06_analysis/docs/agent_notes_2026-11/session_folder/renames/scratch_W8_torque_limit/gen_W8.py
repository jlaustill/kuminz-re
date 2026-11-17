"""Generate result_W8_torque_limit.jsonl (read-only research; nothing in the repo is touched)."""
import csv
import json
import sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
RESULT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W8_torque_limit.jsonl'

rows = []
warn = []


def a8(a):
    return '0x%08x' % a


SHORT = {
    0x40a304: 'Code (cm848_selectEngineSpeedLimit): the no load end of the droop line: slope = (this - engine_speed_limit_reference) '
              'x 4369 / (maximum fuel at the reference - friction fuel at this speed); also the speed key of that friction fuel '
              'lookup. Starts as engine_speed_limit_droop_no_load_speed_default_cal (28000 = 3500 rpm). e2m: HSG_Active_No_Load_RPM '
              '(droop line meets the no load fuel curve).',
    0x40a306: 'Code: FIRST half (big endian: lower address = high half) of the old dword, read as '
              'torque_limit_error_integrator._0_2_: droop slope, speed counts x 4369 per fuel count; recomputed by '
              'cm848_clampedDivisionWithBounds (0..32726) in the droop branch (source 10 zeroes it first; that sticks only while the '
              'bypass flag is set). e2m: HSG_Active_Slope. Type change dword -> i16: dword note.',
    0x40a89b: 'Code: cm848_calculateFuelDemandWithTrim stores cm848_lookupChiMaximumFuelAtSpeed(engine_speed_limit_ramped) + '
              'fuel_demand_offset_correction (dump 1438): the full load fuel of the '
              'droop line, used in cm848_selectEngineSpeedLimit, cm848_calculateEngineLoadPercentages, cm848_processJ1939RxMessage, '
              'governor_calculateIntegratorRpmOutput. Packed odd address, halfword.',
    0x40a89d: 'Code: cm848_calculateFuelDemandWithTrim stores cm848_lookupChiMaximumFuelAtSpeed(engine_speed_limit_reference) + '
              'fuel_demand_offset_correction (when operating_mode_flags_cal bit 0x1000 is set): the full load fuel at the reference '
              'speed - the droop slope denominator in cm848_selectEngineSpeedLimit, the start of the fuel fall in '
              'cm848_calculateEffectiveFuelLimit. Packed odd address, halfword.',
    0x40a2f0: 'Code: in cm848_periodicTaskSet_auxiliaryControl cm848_calculateInjectionTimingOffset stores '
              'injection_timing_offset_map_output here, then cm848_copyMainInjectionTiming overwrites it with main_injection_timing, '
              'then the only reader cm848_computeFuelRpmCompensatedOffset runs: '
              'the first store is dead and the reader sees main_injection_timing (dump 162 = 0x40a2e6).',
    0x3fdb84: 'EEPROM-backed (EEPROM 0x702), read as diagnostic_service_dispatch_table._84_2_ (0x3fdb30 + 84). '
              'Bit n = sensor slot 96 + n takes its forced value 0x40bc80 + 2 x slot instead of the QADC result: 0x80 = slot 103 '
              '(cm848_selectTransmissionTemperatureInUse, SCI 20), 0x02 = slot 97, 0x04 = slot 98 (SCI 20). Same scheme as the slot '
              '4 / 63 / 69 rows; dump 0. Hidden by the arrays.csv byte[100] overlay.',
    0x40bd4e: 'Slot 103 of the forced-reading array at 0x40bc80 (2 bytes per slot; slots 4 / 63 / 69 are battery_voltage / '
              'fuel_metering_feedback / battery_temperature_adc_forced_reading). Replaces the QADC result of '
              'transmission_temperature_qadc_channel_cal while bit 0x80 of the enable word 0x3fdb84 is set; read by '
              'cm848_selectTransmissionTemperatureInUse and cm848_sciCommand20Callback; never written, dump 0.',
    0x40b620: 'Code: cm848_selectTransmissionTemperatureInUse keeps the previous raw reading of the transmission temperature slot '
              '(QADC result or forced reading) here: while the new reading equals it fuel_flow_rate_counter counts to '
              'fuel_flow_rate_counter_threshold_cal and ORs 0x02 into rate_limit_flags, otherwise it is reloaded and the sensor value '
              'forced. cm848_resetEngineLoadTracker clears it.',
    0x5f8ac: 'Auxiliary quantity correction by the main pulse (cm848_calculateAuxiliaryInjectionPulseWidth: quantity = ((scale x '
             'correction) >> 4) + auxiliary_injection_quantity while the main pulse is on). x axis: '
             'main_to_auxiliary_injection_interval. e2m: HPCR_Aux_Fuelq_Corr_Map_Interval_Axis (3.2 us). Twin: '
             'main_quantity_pilot_correction_x_axis (188..1375); here a placeholder ramp 0..9 in an all-zero map.',
}


def G(a, old, new, ev, verdict='confirmed'):
    ev = SHORT.get(a, ev)
    r = {'kind': 'global', 'address': a8(a), 'old': old, 'verdict': verdict}
    if new:
        r['new'] = new
    r['evidence'] = ev
    if len(ev) > 400 and verdict == 'confirmed':
        warn.append(('evidence > 400 chars (clipped in the CSV comment)', hex(a), len(ev)))
    rows.append(r)


def F(a, old, new, plate, ev):
    rows.append({'kind': 'function', 'address': a8(a), 'old': old, 'verdict': 'confirmed', 'new': new,
                 'plate_comment': plate, 'evidence': ev})


def N(text):
    rows.append({'kind': 'note', 'text': text})


def fr_plate(addr):
    for l in open(OUT + 'function_renames.csv'):
        p = l.rstrip('\n').split(',', 2)
        if p[0] == a8(addr):
            return p[1], p[2]
    raise SystemExit('no function_renames row for ' + a8(addr))


def refresh_plate(addr, swaps, ev):
    """plate-only row: the current plate with exact substring swaps (each must occur)."""
    name, plate = fr_plate(addr)
    for old, new in swaps:
        if old not in plate:
            raise SystemExit('swap source not found in plate of %s: %r' % (name, old))
        plate = plate.replace(old, new)
    F(addr, name, name, plate, ev)


# ---------------------------------------------------------------------------------------------------------------
# 1. the droop line (HSG) words
# ---------------------------------------------------------------------------------------------------------------
G(0x3fd80c, 'torque_limit_offset_init', 'engine_speed_limit_droop_no_load_speed_default_cal',
  'EEPROM-backed (EEPROM 0x38a, inside 0x3fd482-0x3feec1), dump 28000 = 3500 rpm = engine_speed_limit_maximum and the '
  'last breakpoint of the friction fuel curve. Code: read once (xref_addr.py, raw scan of both banks) by '
  'cm848_initializeEngineSpeedLimitDefaults as the start value of engine_speed_limit_droop_no_load_speed. Window '
  'check: immediate scan of 0..0x7F5F for 0xd80c: 0 hits; no type change.')
G(0x40a304, 'torque_limit_offset_calc', 'engine_speed_limit_droop_no_load_speed',
  'Code (cm848_selectEngineSpeedLimit): the no load end of the droop line. slope = (this - engine_speed_limit_reference) '
  'x 4369 / (maximum fuel at the reference - friction fuel at this speed), and this word is the speed key of that '
  'friction fuel lookup. Starts as engine_speed_limit_droop_no_load_speed_default_cal (28000 = 3500 rpm). e2m: '
  'HSG_Active_No_Load_RPM (droop line meets the no load fuel curve), same relative offset.')
G(0x40a328, 'torque_limit_offset_stored', 'engine_speed_limit_droop_no_load_offset',
  'Code: with engine_speed_limit_droop_no_load_offset_enable_flag = 1, cm848_selectEngineSpeedLimit sets the no load '
  'speed to this + engine_speed_limit_reference. One read, NEVER WRITTEN (xref_addr.py; raw scan of both banks: no store, '
  'no 32-bit pointer), dump 0. e2m: HSG_Active_No_Load_Offset (active HSG droop offset), same relative offset.')
G(0x40a31c, 'torque_limit_offset_enable_flag', 'engine_speed_limit_droop_no_load_offset_enable_flag',
  'Code: 1 makes cm848_selectEngineSpeedLimit set the no load speed to engine_speed_limit_droop_no_load_offset + '
  'engine_speed_limit_reference. One read, NEVER WRITTEN (raw scan of both banks: no store, no pointer), dump 0, so the '
  'offset mode is off. e2m: HSG_Active_No_Load_Offset_Flag (active no load is offset based), same relative offset.')
G(0x40a32a, 'torque_limit_lookup_disable_flag', 'engine_speed_limit_droop_slope_bypass_flag',
  'Code: while 0, the droop branch of cm848_selectEngineSpeedLimit recomputes engine_speed_limit_droop_slope every pass '
  '(friction fuel lookups + clamped division); nonzero would freeze it. One read, NEVER WRITTEN (raw scan of both banks: '
  'no store, no pointer), dump 0. e2m: HSG_Droop_Slope_Bypass, same relative offset.')
G(0x40a306, 'torque_limit_error_integrator', 'engine_speed_limit_droop_slope',
  'Code: FIRST half (big endian: lower address = high half) of the old dword, read as '
  'torque_limit_error_integrator._0_2_: droop slope, speed counts x 4369 per fuel count; recomputed by '
  'cm848_clampedDivisionWithBounds (0..32726) in the droop branch (source 10 zeroes it first, which sticks only while the '
  'bypass flag is set). e2m: HSG_Active_Slope. Needs type dword -> i16 (5 lha, 1 lhz, 2 sth): dword note.')
G(0x40a308, 'torque_limit_fuel_cal_input', 'engine_speed_limit_ramped',
  'Code: SECOND half of the old dword, read as torque_limit_error_integrator._2_2_: the ramped limit - starts at '
  'engine_speed_limit_reference_default_cal (dump 25600 = 3200 rpm), rises by engine_speed_limit_ramp_up_step per pass '
  'toward the arbitrated minimum, drops to it at once. All loads lhz, stores sth. e2m: HSG_Before_Droop_Speed. This row '
  'has no type: set word (dword note).')
G(0x406fe6, 'torque_limit_fuel_upper_cal', 'engine_speed_limit_droop_fuel_clamp_maximum',
  'Code: upper clamp of high_speed_governor_integral_term, the fuel the droop term of cm848_selectEngineSpeedLimit uses '
  '(dump 5888 = 0x1700, the maximum fuel quantity). ROM word, outside the EEPROM mirror, so no _cal. e2m: '
  'HSG_Adj_Fueling_Clamp_Max (maximum fuel that may be used to determine the HSG droop reference), same relative offset.')
G(0x406fe8, 'torque_limit_fuel_lower_cal', 'engine_speed_limit_droop_fuel_clamp_minimum',
  'Code: lower clamp of high_speed_governor_integral_term in the droop term of cm848_selectEngineSpeedLimit (dump 0). '
  'ROM word, outside the EEPROM mirror, so no _cal. e2m: HSG_Adj_Fueling_Clamp_Min (minimum fuel that may be used to '
  'determine the HSG droop reference), same relative offset.')
G(0x406fee, 'torque_limit_source_d_f_disable_cal', 'engine_speed_limit_torque_converter_droop_enable',
  'Code: cm848_selectEngineSpeedLimit gives sources 13 (converter slip) and 15 (park / neutral exit) the direct ramped '
  'limit with no droop while this is 0 (dump 0) and the droop branch otherwise, so the old "disable" has the sense '
  'reversed. ROM word, no _cal. e2m: HSG_TC_Droop_On (1 = HSG droop on for stall torque management), same offset.')
G(0x408d76, 'torque_limit_override_source_cal', 'engine_speed_limit_source_16',
  'Code: while governor_active_flag_b648 is set, cm848_selectEngineSpeedLimit returns early with this word (dump 12800 = '
  '1600 rpm) as applied_speed_limit and source number 16; one read. The flag is set by initGovernorSpeedControl and '
  'cleared by governorSpeedCompensation after a table-driven step count (own reading needed, see the note). Outside the '
  'EEPROM range, no _cal.')
G(0x40a2fe, 'torque_limit_source_working', 'engine_speed_limit_after_droop',
  'Code: WRITE-ONLY (0 reads): ramped limit + droop term clamped to 0..65535 in the droop branch of '
  'cm848_selectEngineSpeedLimit, before the maximum with the ramped limit and the minimum with engine_speed_limit_droop_cap. '
  'e2m: HSG_Droop_Speed (HSG reference speed after droop has been calculated), same relative offset.')
G(0x40a314, 'torque_limit_fuel_demand_snapshot', 'engine_speed_limit_droop_cap_snapshot',
  'Code: WRITE-ONLY (0 reads) copy of engine_speed_limit_droop_cap taken near the end of cm848_selectEngineSpeedLimit '
  'before the cap is reset to the default. e2m: HSG_Indicated_Isochronous_Speed (winning isochronous speed), same '
  'relative offset.')
G(0x40a316, 'torque_limit_state_machine_snapshot', 'engine_speed_limit_droop_cap_source_code_snapshot',
  'Code: WRITE-ONLY (0 reads) copy of engine_speed_limit_droop_cap_source_code taken near the end of '
  'cm848_selectEngineSpeedLimit before it is reset to 0. e2m: HSG_Indicated_Isochronous_Speed_State (winning isochronous '
  'speed state), same relative offset.')
G(0x40a318, 'torque_limit_source_code', 'engine_speed_limit_limiting_source_number_snapshot',
  'Code: WRITE-ONLY (0 reads) copy of limiting_source_number, also stored in the two early returns (16 and 8) and at '
  'the end of cm848_selectEngineSpeedLimit (dump 16). e2m: HSG_Indicated_Ref_Speed_State (which algorithm controls the '
  'HSG), same relative offset.')
G(0x40a32e, 'torque_limit_load_snapshot', 'engine_speed_limit_arbitrated_snapshot',
  'Code: WRITE-ONLY (0 reads): engine_speed_limit_arbitrated as it stood at the start of the pass (the previous pass '
  'result), stored at the top of cm848_selectEngineSpeedLimit and again in the source 8 early return. No e2m parameter '
  'at this offset.')
G(0x40a89b, 'torque_limit_table_output', 'engine_speed_limit_ramped_maximum_fuel_quantity',
  'Code: cm848_calculateFuelDemandWithTrim stores cm848_lookupChiMaximumFuelAtSpeed(engine_speed_limit_ramped) + '
  'fuel_demand_offset_correction (when operating_mode_flags_cal bit 0x1000 is set; dump 1438). It is the full load fuel of '
  'the droop line in cm848_selectEngineSpeedLimit, cm848_calculateEngineLoadPercentages, cm848_processJ1939RxMessage and '
  'governor_calculateIntegratorRpmOutput. Packed odd address, halfword access.')
G(0x40a89d, 'fuel_demand_torque_table_output', 'engine_speed_limit_reference_maximum_fuel_quantity',
  'Code: cm848_calculateFuelDemandWithTrim stores cm848_lookupChiMaximumFuelAtSpeed(engine_speed_limit_reference) + '
  'fuel_demand_offset_correction (when operating_mode_flags_cal bit 0x1000 is set). Read as the full load fuel at the '
  'reference speed: the droop slope denominator in cm848_selectEngineSpeedLimit and the start of the fuel fall in '
  'cm848_calculateEffectiveFuelLimit. Packed odd address, halfword access.')
G(0x40aeee, 'torque_demand_integral_term', 'engine_speed_limit_droop_no_load_fuel_quantity',
  'Code: write-only scratch of cm848_selectEngineSpeedLimit: the friction fuel at engine_speed_limit_droop_no_load_speed '
  '(friction fuel by engine speed table) plus the coolant temperature friction term; subtracted from the reference '
  'maximum fuel as the droop slope denominator. e2m calls this fuel "no load fuel" (ASG_No_Load_Fuel, fuel required to '
  'overcome friction).')
G(0x3fdd38, 'torque_source_count', None,
  'EEPROM-backed (EEPROM 0x8b6), dump 1, one read, never written. Code: cm848_applySwitchSelectedEngineSpeedLimit takes '
  'engine_speed_limit_droop_cap_alternate_cal instead of engine_speed_limit_droop_cap_cal only when this is above 1, '
  'engine_speed_limit_droop_cap_alternate_disable is 0 and switch 31 (switch_input_state_bits[3] bit 0x80) is on. Reading, '
  'not proof: only "above 1 allows the alternate cap" is certain. Candidate if confirmed (the number of selectable limit sets): '
  'engine_speed_limit_droop_cap_set_count_cal.', verdict='uncertain')
G(0x407266, 'torque_limit_multi_source_enable_cal', 'engine_speed_limit_droop_cap_alternate_disable',
  'Code: cm848_applySwitchSelectedEngineSpeedLimit takes the alternate droop cap only while this is 0 (dump 0), so a '
  'nonzero value disables it and the old "enable" has the sense reversed. One read, never written; ROM word outside the '
  'EEPROM mirror, so no _cal.')

# ---------------------------------------------------------------------------------------------------------------
# 2. 0x40a2f0 and its function
# ---------------------------------------------------------------------------------------------------------------
G(0x40a2f0, 'governor_rpm_offset_cached', 'main_injection_timing_copy',
  'Code: cm848_periodicTaskSet_auxiliaryControl runs cm848_calculateInjectionTimingOffset (stores '
  'injection_timing_offset_map_output here), then cm848_updateMainInjectionTimingByDeliveryMode, then '
  'cm848_copyProtectionAccumulator, which overwrites it with main_injection_timing, then the only reader '
  'cm848_computeFuelRpmCompensatedOffset. The first store is dead; the reader sees main_injection_timing (dump 162 = '
  '0x40a2e6).')
F(0x42784, 'cm848_copyProtectionAccumulator', 'cm848_copyMainInjectionTiming',
  'Copies main_injection_timing into main_injection_timing_copy, the base of cm848_computeFuelRpmCompensatedOffset. '
  'Runs after cm848_updateMainInjectionTimingByDeliveryMode and cm848_calculateAuxiliaryInjectionTiming in '
  'cm848_periodicTaskSet_auxiliaryControl and overwrites the injection timing offset map copy stored there earlier by '
  'cm848_calculateInjectionTimingOffset. (was cm848_copyProtectionAccumulator)',
  'One store of main_injection_timing into 0x40a2f0; nothing protection-related and no accumulator.')

# ---------------------------------------------------------------------------------------------------------------
# 3. adc forced reading family (0x3fdb84, 0x40bd4e, 0x40b620)
# ---------------------------------------------------------------------------------------------------------------
G(0x3fdb84, 'torque_limit_control_flags', 'adc_forced_reading_enable_bits_96_to_111_cal',
  'EEPROM-backed (EEPROM 0x702), read as diagnostic_service_dispatch_table._84_2_ (0x3fdb30 + 84), so not "indirect '
  'only". Bit n = sensor slot 96 + n takes its forced value 0x40bc80 + 2 x slot instead of the QADC result: bit 0x80 = slot '
  '103 (cm848_selectTransmissionTemperatureInUse, cm848_sciCommand20Callback), 0x02 = slot 97, 0x04 = slot 98 (SCI 20). Same '
  'scheme as the slot 4 / 63 / 69 rows; dump 0. Hidden by the arrays.csv byte[100] overlay.')
G(0x40bd4e, 'torque_limit_setpoint_working', 'transmission_temperature_adc_forced_reading',
  'Slot 103 of the forced-reading array at 0x40bc80 (2 bytes per slot: 0x40bc80 + 206; slots 4 / 63 / 69 are '
  'battery_voltage / fuel_metering_feedback / battery_temperature_adc_forced_reading). Replaces the QADC result of '
  'transmission_temperature_qadc_channel_cal while bit 0x80 of the enable word 0x3fdb84 is set; read by '
  'cm848_selectTransmissionTemperatureInUse and cm848_sciCommand20Callback; never written, dump 0.')
G(0x40b620, 'torque_limit_setpoint_active', 'transmission_temperature_adc_previous_reading',
  'Code: cm848_selectTransmissionTemperatureInUse keeps the previous raw reading of the transmission temperature slot '
  '(QADC result or forced reading) here; while the new reading equals it fuel_flow_rate_counter counts up to '
  'fuel_flow_rate_counter_threshold_cal and then sets bit 2 of rate_limit_flags, otherwise it is reloaded and the sensor '
  'value is forced. cm848_resetEngineLoadTracker clears it (that reset is this validation, not an engine load tracker).')

# ---------------------------------------------------------------------------------------------------------------
# 4. the 16 interpolation state words of cm848_calculateMainInjectionTiming
# ---------------------------------------------------------------------------------------------------------------
STATE = [
    ('cold_start', '2-D: x = engine_rpm_state_t.current_rpm, y = coolant_temp'),
    ('coolant_factor', '2-D: x = coolant_temp_snapshot, y = intake_manifold_temperature_sensor_filtered'),
    ('intake_temperature_factor', '1-D: x = timing_intake_manifold_temperature_snapshot'),
    ('barometric_pressure_factor', '1-D: x = timing_barometric_pressure_snapshot'),
    ('coolant_angle', '2-D: x = current_rpm, y = fuel_demand_computed'),
    ('intake_temperature_angle', '2-D: x = current_rpm, y = fuel_demand_computed'),
    ('barometric_pressure_angle', '2-D: x = current_rpm, y = fuel_demand_computed'),
    ('boost_angle', '2-D: x = current_rpm, y = fuel_demand_computed'),
    ('boost_factor', '2-D: x = current_rpm, y = the boost pressure of cm848_calculateBoostPressure'),
]
addr = 0x3fb708
k = 0
for base, how in STATE:
    two_d = how.startswith('2-D')
    nm = 'injection_timing_main_%s_interpolation_state' % base
    G(addr, 'torque_limit_init_state_%d' % k, nm,
      'Lookup cache (%s) of the injection_timing_main_%s lookup in cm848_calculateMainInjectionTiming (%s). Set to 2 by '
      'cm848_initTimingFilterStates; only these two functions use it. Time-shared window: no boot-ROM user (< 0x7F60, immediate scan). Label '
      'only.' % ('x segment offset, the next row is y' if two_d else 'one word', base, how))
    addr += 2
    k += 1
    if two_d:
        G(addr, 'torque_limit_init_state_%d' % k, nm + '_y',
          'Second word (y segment offset) of the 2-D lookup cache of injection_timing_main_%s '
          '(cm848_dualAxisTableInterpolation uses the pair starting at the previous row); set to 2 by '
          'cm848_initTimingFilterStates. Time-shared window: no boot-ROM user (< 0x7F60, immediate scan). Label only.' % base)
        addr += 2
        k += 1
assert k == 16 and addr == 0x3fb728, (k, hex(addr))

# ---------------------------------------------------------------------------------------------------------------
# 5. the six auxiliary interaction tables (type-only rows, old = "") and their three cache words
# ---------------------------------------------------------------------------------------------------------------
CORR = ('cm848_calculateAuxiliaryInjectionPulseWidth: while the main pulse is on, auxiliary quantity = ((scale lookup x '
        'correction lookup) >> 4) + auxiliary_injection_quantity')
G(0x5f8ac, '', 'auxiliary_quantity_main_correction_x_axis',
  CORR + '. x axis: main_to_auxiliary_injection_interval (3.2 us counts). e2m: HPCR_Aux_Fuelq_Corr_Map_Interval_Axis '
  '(USEC 3.2, interval between main and aux). Twin of main_quantity_pilot_correction_x_axis (188..1375); here a placeholder '
  'ramp 0..9 in an all-zero map, which does not change the role.')
G(0x5f8e0, '', 'auxiliary_quantity_main_correction_y_axis',
  'Correction y axis (cm848_calculateAuxiliaryInjectionPulseWidth): main_injection_pulse_width_before_minimum_check in '
  '0.4 us ticks; 6 breakpoints 0..10238 that fit. e2m: HPCR_Aux_Fuelq_Corr_Map_Main_Axis (uSEC 0.4, main injection axis). '
  'Twin: main_quantity_pilot_correction_y_axis (0..1250, pilot pulse).')
G(0x5f8ee, '', 'auxiliary_quantity_main_correction_grid',
  'Correction grid, 6 rows x 25 columns (cm848_calculateAuxiliaryInjectionPulseWidth, read unsigned: flags 0; the main twin '
  'is flags 4 signed); all 150 words are 0 in this calibration, so the correction is off. e2m: '
  'HPCR_Aux_Fuelq_Corr_Map_Fuelq_Table (aux fuel quantity correction map). Twin: main_quantity_pilot_correction_grid.')
G(0x5fa1a, '', 'auxiliary_quantity_main_correction_scale_x_axis',
  'Scale x axis (cm848_calculateAuxiliaryInjectionPulseWidth): x = auxiliary_injection_quantity; 8 breakpoints 0..4416 (0..375 '
  'mm3 at 11.776 counts per mm3), wider than the main twin (0..1766). e2m: HPCR_Aux_Scalingfactor_Map_Fuelq_Axis (MM3S). '
  'Twin: main_quantity_pilot_correction_scale_x_axis.')
G(0x5fa2c, '', 'auxiliary_quantity_main_correction_scale_y_axis',
  'Scale y axis: fuel_pressure_sensor; 0, 614, 1023, 1433, 1842, 2252, 2866, 3276 = 0..160 MPa, almost the twin axis '
  '(0, 614, 1023, 1433, 1639, 2252, 2866, 3276). e2m: HPCR_Aux_Scalingfactor_Map_Fuelpr_Axis (MPa). Twin: '
  'main_quantity_pilot_correction_scale_y_axis.')
G(0x5fa3e, '', 'auxiliary_quantity_main_correction_scale_grid',
  'Scale grid 8 x 8, read with flags 6 like the main scale; all 64 words are 0 here (the twin holds 16 / 12 / 8 / 4 / 3, '
  'Q4 factors), multiplied with the correction grid and shifted >> 4. e2m: HPCR_Aux_Scalingfactor_Map_SF_Table. Twin: '
  'main_quantity_pilot_correction_scale_grid.')
G(0x3fb624, 'injection_fault_timing_axis2_interp_state', 'auxiliary_quantity_main_correction_interpolation_state',
  'Lookup cache (2-D: two words, the second untyped) of the auxiliary_quantity_main_correction lookup in '
  'cm848_calculateAuxiliaryInjectionPulseWidth; the old "fault timing" domain was wrong. Time-shared window: immediate '
  'scan of both banks, no boot-ROM user (< 0x7F60, immediate scan); label only.')
G(0x3fb628, 'injection_fault_timing_scale_interp_state', 'auxiliary_quantity_main_correction_scale_interpolation_state',
  'Lookup cache (2-D: two words, the second untyped) of the auxiliary_quantity_main_correction_scale lookup in '
  'cm848_calculateAuxiliaryInjectionPulseWidth. Time-shared window: no boot-ROM user (< 0x7F60, immediate scan); label only.')
G(0x3fb62c, 'injection_fault_timing_output_interp_state', 'auxiliary_injection_pulse_width_interpolation_state',
  'Lookup cache (2-D: two words, the second untyped) of the auxiliary_injection_pulse_width_grid lookup (the final on-time '
  'by quantity and rail pressure) in cm848_calculateAuxiliaryInjectionPulseWidth. Time-shared window: no boot-ROM user '
  '(< 0x7F60); label only.')

# ---------------------------------------------------------------------------------------------------------------
# 6. the friction fuel curve the droop uses (found while verifying the no load fuel)
# ---------------------------------------------------------------------------------------------------------------
FRIC = ('Fuel by engine speed: 397 147 88 100 177 216 311 427 618 at 450 550 610 1600 2000 2400 2800 3200 3500 rpm (no load '
        'fuel). It is the speed term of fuel_demand_base_offset (the zero torque fuel of the load percent in '
        'cm848_calculateEngineLoadPercentages); 10 lookup sites in 6 functions. ')
G(0x5a77c, 'calibration_table_base', 'friction_fuel_by_engine_speed_axis',
  'x axis, 9 breakpoints 3600..28000 (450..3500 rpm). ' + FRIC + 'e2m, name match only: ASG_Alt_Friction_Fuel_Bkpt / _Table.')
G(0x5a790, 'calibration_table_offset', 'friction_fuel_by_engine_speed_values',
  'Data, 9 values after the byte-length word (0.0679 mm3 counts). ' + FRIC)
G(0x40aef8, 'governor_torque_interp_state', 'friction_fuel_by_engine_speed_interpolation_state',
  'Lookup cache word shared by every lookup of the friction fuel by engine speed table (10 call sites, 6 functions, '
  'cm848_selectEngineSpeedLimit among them); nothing torque related. Label only.')

# ---------------------------------------------------------------------------------------------------------------
# 7. uncertain rows
# ---------------------------------------------------------------------------------------------------------------
G(0x3fa8a4, 'torque_limit_working_reference', None,
  'Written by cm848_updateProtectionStateMachine (engine_speed_limit_arbitrated when limiting_source_number is 1 / 2 / 4 / '
  '5 / 12, else engine_speed_limit_reference) and read by cm848_processJ1939RxMessage (a fuel-to-speed conversion on the '
  'droop line, not J1939) when the slope is 0, and as the speed compared with DAT_0005c35e. Dump 0; time-shared window, '
  'no boot-ROM user by immediate scan. The protection threshold cluster around it needs its own reading. Candidate if '
  'confirmed: engine_speed_limit_droop_start_speed.', verdict='uncertain')
G(0x40a280, 'torque_limit_init_flag', None,
  'Dword, WRITE-ONLY: cm848_initializeEngineSpeedLimitDefaults stores 0 into its high half, nothing reads either half (raw '
  'scan of both banks); no e2m parameter found at the matching offset. No role to name.', verdict='uncertain')

# ---------------------------------------------------------------------------------------------------------------
# 8. plates (functions whose own name stays) and refreshed plates
# ---------------------------------------------------------------------------------------------------------------
_, sel_old = fr_plate(0x1fd94)
F(0x1fd94, 'cm848_selectEngineSpeedLimit', 'cm848_selectEngineSpeedLimit',
  'Lowest-wins arbitration of the engine speed limit, the e2m high speed governor (HSG) reference speed (engine speed in '
  '0.125 rpm counts; engine_speed_limit_default_cal = 30000 = 3750 rpm): each active source lowers lowest_source_speed_limit '
  'and records its number in limiting_source_number - 2 / 4 / 10 engine_speed_limit_source_2 / _4 / _10, 5 '
  'engine_speed_limit_fault_derate, 6 engine_speed_limit_reference, 7 fuel_pressure_fault_engine_speed_limit_working, '
  '8 the TSC1 override mode select 1 request (DAT_0005c39a), 9 j1939_tsc1_override_state.etc1_torque_limit_value (governor '
  'mode 3), 11 governor_fuel_idle_limit, 13 engine_speed_limit_converter_slip, 14 engine_speed_limit_pedal_fault_mode, 15 '
  'engine_speed_limit_park_neutral_exit, 16 engine_speed_limit_source_16 (governor_active_flag_b648 set). Sources 16 and 8 '
  'return early with their own value as applied_speed_limit. Otherwise the result is held between '
  'engine_speed_limit_minimum (850 rpm) and engine_speed_limit_maximum (3500 rpm) and stored in '
  'engine_speed_limit_arbitrated; engine_speed_limit_ramped follows it (up by engine_speed_limit_ramp_up_step per pass, down '
  'at once). Sources 9 (with ETC1 active), 11 and, while engine_speed_limit_torque_converter_droop_enable is 0, 13 and 15 '
  'apply the ramped limit directly; every other pass applies the droop line unless the slope is 0: '
  'engine_speed_limit_droop_slope = (engine_speed_limit_droop_no_load_speed - engine_speed_limit_reference) x 4369 / '
  '(engine_speed_limit_reference_maximum_fuel_quantity - engine_speed_limit_droop_no_load_fuel_quantity) is recomputed '
  'unless engine_speed_limit_droop_slope_bypass_flag is set (source 10 zeroes the slope first, which sticks only while that '
  'flag is set), and applied_speed_limit = engine_speed_limit_ramped + slope x '
  '(engine_speed_limit_ramped_maximum_fuel_quantity - the clamped high_speed_governor_integral_term) / 4369, never below the '
  'ramped limit and capped at engine_speed_limit_droop_cap. cm848_calculateEffectiveFuelLimit and '
  'cm848_calculateEngineLoadPercentages read the same line as a fuel limit. (was cm848_selectTorqueLimit)',
  'Plate rewritten after the HSG block was read word by word (code) and matched to e2m HSG_* parameters by relative '
  'offset (corroboration); the old plate cited names retired by wave 8 and had no droop description.')

F(0x20554, 'cm848_calculateEffectiveFuelLimit', 'cm848_calculateEffectiveFuelLimit',
  'Name kept. Effective fuel limit with the engine speed limiter, in fuel quantity counts: the speed limit is '
  'engine_speed_limit_reference with engine_speed_limit_droop_slope while engine_speed_limit_droop_active_flag is 1 and the '
  'engine is still below lowest_source_speed_limit (or source 9 limits), otherwise lowest_source_speed_limit with the slope '
  'forced to 0. Below that speed the limit is injection_quantity_combustion_maximum_limit; above it it falls from '
  'engine_speed_limit_reference_maximum_fuel_quantity by the speed excess x 0x3ae1 / (slope x 8), floored at 0 and capped at '
  'protection_fuel_limit_cal_active (a zero slope cuts the fuel at once). The result is then lowered to the other fuel limits '
  'and, for the all-speed governor, to the droop fuel demand.',
  'The old plate said "the ramped engine_speed_limit_reference ... slope in the low word of torque_limit_error_integrator": '
  'the code (lhz 0x40a2xx, cpp 20363-20371) uses the clamped reference itself, not the ramped limit, and the slope is the '
  'word at 0x40a306 (first half of the dword), read as _0_2_.')

refresh_plate(0x1e870, [('governor_rpm_offset_cached', 'main_injection_timing_copy'),
                        ('cm848_copyProtectionAccumulator', 'cm848_copyMainInjectionTiming')],
              'Plain name swaps in the current plate (the sentences stay true).')
refresh_plate(0x3866c, [('governor_rpm_offset_cached', 'main_injection_timing_copy')],
              'Plain name swap in the current plate.')
refresh_plate(0x2c114, [('torque_limit_multi_source_enable_cal is 0', 'engine_speed_limit_droop_cap_alternate_disable is 0')],
              'Name swap in the current plate; torque_source_count keeps its name (its row is uncertain).')
refresh_plate(0x4ae20, [('torque_limit_arb_t.main_injection_timing_source_code', 'main_injection_timing_source_code'),
                        ('DAT_0005a48a', 'injection_timing_top_dead_center_offset (minus the top dead center position, 171 counts)')],
              'The struct-qualified name disappears with the struct split; DAT_0005a48a has a row (i16 -171).')
refresh_plate(0x5279d8, [('DAT_0005a48a', 'injection_timing_top_dead_center_offset (minus the top dead center position, 171 counts)')],
              'DAT_0005a48a has a row (injection_timing_top_dead_center_offset, i16 -171).')

# ---------------------------------------------------------------------------------------------------------------
# 9. notes
# ---------------------------------------------------------------------------------------------------------------
N('[W8 struct split and type rename - exact rows] torque_limit_arb_t -> engine_speed_limit_arbitration_t, 6 bytes at '
  '0x40a2f8; the first word 0x40a2f6 becomes a flat global. VERIFIED: xref_addr.py and a raw scan of both banks (16-bit '
  'displacement match) show only word accesses (sth / lha / lhz, no lwz / stw) to 0x40a2f6 (4 functions) and to 0x40a2f8 / fa / fc, so '
  'no access straddles two words. e2m (corroboration '
  'only): the HSG state block starts at HSG_Ref_Speed_State 0x01106300 = 0x40a2f8 + 0xCFC008, with limiting_source_number = '
  'HSG_Ref_Speed_State, applied_speed_limit = HSG_Reference_Speed, lowest_source_speed_limit = HSG_Ref_Speed_Before_Droop; '
  'nothing is defined at 0x011062FE. structure_definitions.csv: replace lines 238-244 (the three # lines and the four rows, the '
  'first of which is the field row already renamed in wave 7) by: '
  '"# Engine Speed Limit Arbitration - lowest-wins selection of the engine speed limit (the e2m HSG reference speed state '
  'block)" / "# Written by cm848_selectEngineSpeedLimit and the source functions - read by the fuel limit and governor code" / '
  '"# Total size: 6 bytes (0x0040a2f8-0x0040a2fd)" / '
  '"engine_speed_limit_arbitration_t,0x0040a2f8,limiting_source_number,word,2,Number of the engine speed limit source that wins '
  'the arbitration (e2m HSG_Ref_Speed_State),,verified" / '
  '"engine_speed_limit_arbitration_t,0x0040a2f8,applied_speed_limit,word,2,Engine speed limit applied by the governor in 0.125 rpm '
  'counts - the ramped limit or the ramped limit plus the droop term capped by the droop cap (e2m HSG_Reference_Speed),,verified" / '
  '"engine_speed_limit_arbitration_t,0x0040a2f8,lowest_source_speed_limit,word,2,Lowest engine speed limit of the sources in the '
  'current pass in 0.125 rpm counts - reset to engine_speed_limit_default_cal at the end of cm848_selectEngineSpeedLimit (e2m '
  'HSG_Ref_Speed_Before_Droop),,verified" (comment cells have no commas: the file is parsed quote-aware). '
  'global_variables.csv: replace rows 4417-4420 (0x40a2f6 instance + three member labels) by: '
  '"0x0040a2f6,main_injection_timing_source_code,word,Winning source code of the main injection timing (5 / 7 / 8 / 11 / 18-24 / '
  '29-31) written by cm848_calculateMainInjectionTiming and cm848_updateMainInjectionTimingByDeliveryMode - not part of the '
  'engine speed limit arbitration (was torque_limit_arb_t.source_priority)" / '
  '"0x0040a2f8,engine_speed_limit_arbitration,engine_speed_limit_arbitration_t," / '
  '"0x0040a2fa,engine_speed_limit_arbitration.applied_speed_limit,," / '
  '"0x0040a2fc,engine_speed_limit_arbitration.lowest_source_speed_limit,,". The instance has a real name; if the caller prefers the '
  'default label the rows are the same with engine_speed_limit_arbitration_t_0040a2f8 (and its .field labels). The old struct_field '
  'row of wave 7 (source_priority -> main_injection_timing_source_code) is subsumed. Types stay word (label-only); report '
  'separately that limiting_source_number and the main timing source code are loaded with lha (signed), applied_speed_limit and '
  'lowest_source_speed_limit with lhz. Reverse mapping for the label-only proof: torque_limit_arb_t_0040a2f6.main_injection_timing_'
  'source_code -> main_injection_timing_source_code; torque_limit_arb_t_0040a2f6.limiting_source_number / .applied_speed_limit / '
  '.lowest_source_speed_limit -> engine_speed_limit_arbitration.<same field>. main_injection_timing_source_code is a free global name '
  '(only the struct field used it); the siblings are injection_timing_pilot_source_code, injection_quantity_pilot_source_code and '
  'fuel_pressure_setpoint_winning_term_code, so injection_timing_main_source_code would be the parallel spelling - left to the caller. '
  'Prose that cites the old type: global_variables.csv rows 3113 / 3114 / 3115 (torque_limit_arb_t.applied_speed_limit -> '
  'engine_speed_limit_arbitration.applied_speed_limit), row 4873 (torque_limit_arb_t.main_injection_timing_source_code == 0x12 -> '
  'main_injection_timing_source_code == 0x12), and function row 1387 (done by the plate-only row of this file). Generated or '
  'historical text to regenerate or leave: firmware_types.hpp, firmware_globals.hpp, bank2_functions.cpp, '
  'docs/memory-mappings/ram.txt, work/tasks/042-*.md, the worklist_* batches.')

N('[W8 dword 0x40a306 torque_limit_error_integrator - the split] The dword is two independent words: 0x40a306 = droop slope (the '
  'cpp renders it _0_2_), 0x40a308 = ramped limit (_2_2_) - big endian, the LOWER address is the high half, so the wave 6 wording '
  '"high word = ramped, low word = slope" is inverted. No dword access exists: raw scan of both banks finds only 16-bit accesses to '
  '0x40a306 (lha x5: cm848_selectEngineSpeedLimit, faultTimerHandler, cm848_processJ1939RxMessage, '
  'governor_calculateIntegratorRpmOutput, cm848_calculateEngineLoadPercentages; lhz x1: cm848_calculateEffectiveFuelLimit; sth x2: '
  'cm848_selectEngineSpeedLimit) and to 0x40a308 (lhz: cm848_calculateFuelDemandWithTrim, cm848_updateProtectionThresholdsIfLow, '
  'cm848_calculateEngineLoadPercentages and 5 in cm848_selectEngineSpeedLimit through a pointer; sth: cm848_selectEngineSpeedLimit '
  'x2, cm848_initializeEngineSpeedLimitDefaults), so the split is safe. Both rows have rename rows in this file; the TYPE edits are '
  'the caller\'s, apply them together with the renames: global_variables.csv 4425 -> "0x0040a306,engine_speed_limit_droop_slope,i16,'
  '<comment>" (majority lha; the single lhz reader is sign-agnostic, the clamp bound is 32726) and 4426 -> '
  '"0x0040a308,engine_speed_limit_ramped,word,<comment>" (all lhz; the row has no type today). No DELETE row is needed. Reverse mapping '
  'for the proof is NOT a plain label: torque_limit_error_integrator._0_2_ -> engine_speed_limit_droop_slope and '
  'torque_limit_error_integrator._2_2_ -> engine_speed_limit_ramped (casts appear at the five lha readers). Prose to fix by hand '
  '(a swap makes a false sentence): global_variables.csv row 3137 (engine_speed_limit_ramp_up_step): "The ramped applied limit '
  '(torque_limit_error_integrator high word) rises by this per pass" -> "The ramped limit engine_speed_limit_ramped rises by this per '
  'pass".')

N('[W8 e2m corroboration of the whole block - relative offsets] The HSG (high speed governor) parameter block of e2m matches our '
  'RAM block at e2m = address + 0xCFC008 and our ROM words at e2m = address + 0xCFF21C (corroboration only; every name above also '
  'rests on the code): 0x40a2f8 HSG_Ref_Speed_State, 0x40a2fa HSG_Reference_Speed, 0x40a2fc HSG_Ref_Speed_Before_Droop, 0x40a2fe '
  'HSG_Droop_Speed, 0x40a300 FSS_RPM_Derate (RPM derate supplied by the application group = fuel_pressure_fault_engine_speed_limit_working, '
  'source 7), 0x40a302 '
  'HSG_Active_Breakpoint, 0x40a304 HSG_Active_No_Load_RPM, 0x40a306 HSG_Active_Slope, 0x40a308 HSG_Before_Droop_Speed, 0x40a30a '
  'HSG_Droop_Flag, 0x40a30c HSG_Ref_Speed_To_Gain_Sched (= engine_speed_limit_arbitrated, which cm848_selectHighSpeedGovernorGainSet '
  'reads), 0x40a30e HSG_Active_Isochronous_Speed (= the droop cap), 0x40a310 TSG_Derate_RPM (tailshaft governor derate: this is '
  'engine_speed_limit_source_10; the code zeroes the droop slope when source 10 wins, but the droop branch recomputes it in the same '
  'pass unless engine_speed_limit_droop_slope_bypass_flag is set, so with the bypass flag 0 of this calibration the zero never reaches '
  'cm848_calculateEffectiveFuelLimit - the comment of row 4430 engine_speed_limit_source_10 ("the limit then cuts the fuel at once") '
  'holds only with the bypass flag set), 0x40a312 HSG_Active_Isochronous_Speed_State, '
  '0x40a314 / 316 / 318 the three HSG_Indicated_* words, 0x40a31a HSG_Active_Breakpoint_State, 0x40a31c HSG_Active_No_Load_Offset_Flag, '
  '0x40a31e HSG_Intermediate_Desired_Active_Breakpoint (the stored reference), 0x40a320 / 322 the intermediate max / min breakpoint, 0x40a324 / '
  '326 HSG_Max / Min_Active_Breakpoint, 0x40a328 HSG_Active_No_Load_Offset, 0x40a32a HSG_Droop_Slope_Bypass, 0x40a32c '
  'TC_Rock_Cycle_Derate_RPM (the park / neutral exit limit, source 15). ROM: 0x406fe4 HSG_Ramp_Step, 0x406fe6 / e8 HSG_Adj_Fueling_Clamp_Max / '
  'Min, 0x406fea / ec HSG_Min / Max_Derate_Speed, 0x406fee HSG_TC_Droop_On. The wave 7 names of the neighbours all agree with this block.')

N('[W8 forced-reading family and the arrays.csv overlay] Check of the formula on all six known sites: enable word = 0x3fdb78 + 2 x '
  '(slot >> 4), bit = slot & 15, forced value = 0x40bc80 + 2 x slot, QADC index word = 0x3fda78 + 2 x slot. Slot 4 -> word 0x3fdb78 bit 4 '
  '(battery_voltage_adc_forced_reading 0x40bc88), slot 63 -> 0x3fdb7e bit 15 (0x40bcfe), slot 69 -> 0x3fdb80 bit 5 (0x40bd0a), slots 97 / 98 '
  '/ 103 -> 0x3fdb84 bits 1 / 2 / 7 (0x40bd42 / 44 / 4e; QADC index words 0x3fdb3a / 3c / 46) - the three SCI command 20 tests and the '
  'transmission temperature check read exactly these. The other enable words keep junk rows (0x3fdb78 diag_feature_flags, 0x3fdb7c '
  'diag_cam_sync_config_flags, 0x3fdb7e diag_cam_sync_fault_config_flags; 0x3fdb7a / 80 / 82 have none): a later wave can name them '
  'adc_forced_reading_enable_bits_<first>_to_<last>_cal. The new name of 0x3fdb84 will NOT render: arrays.csv row 64 '
  '(0x003fdb30,diagnostic_service_dispatch_table,byte,100) covers 0x3fdb30-0x3fdb93 and the cpp prints diagnostic_service_dispatch_table.'
  '_84_2_ (and ._22_2_ for transmission_temperature_qadc_channel_cal 0x3fdb46). That byte[100] is the boot reflash kernel\'s table of 20 '
  'packed 5-byte entries, so cutting it is a type change that needs the kernel users (cm848_registerDiagnosticService / '
  'cm848_dispatchDiagnosticService) checked first - not proposed here.')

N('[W8 thermal cluster - no renames proposed, own wave] 0x3fb4f0 torque_limit_enable_flag, 0x3fb4f6 _active_flag_b, 0x3fb4f8 _stable_flag, '
  '0x3fb4fa _entry_timer, 0x408d26 _entry_timer_cal, 0x40b61e _active_flag are the state of ONE fuel limit state machine '
  '(cm848_processThermalProtection and its helpers), not torque limits, and the "thermal" label does not fit either: the condition flag comes from drivetrain_ratio '
  'against thresholds, transmission_type_cal and transmission_current_gear (cm848_evaluateThermalProtectionActive), enable_flag is the '
  'previous pass copy of it, entry_timer is a release hold timer loaded from the _cal word on the falling edge, active_flag_b is the '
  'recovery flag (limit = raw + 0x408d2c torque_limit_fuel_min_offset_cal, 75 in the dump, until demand + 0x408d2e '
  'torque_limit_fuel_demand_offset_cal, 74, falls below it) and stable_flag the entry ramp (limit = last demand - '
  'deadband until it reaches the table limit); the limit goes to protection_fuel_min_source and cm848_applyThermalFuelLimit applies it '
  'with source code 0x2d. e2m has Gear_Down_Active (0x018B8906) and Gear_Down_Gear_Ratio (scale 1/2048, like drivetrain_ratio), which fits a '
  'gear down limit; the cluster\'s own names (cm848_*ThermalProtection*, engine_temp_protection_*_cal, protection_fuel_*, '
  'fuel_injection_state) are the same wrong domain, so renaming only the torque_limit_* words would mix two vocabularies. Related '
  'transmission temperature validation leftovers in the same files: fuel_flow_rate_working (0x40b622), fuel_flow_rate_counter (0x3fb504, '
  'time-shared), fuel_flow_rate_counter_threshold_cal (0x408d3a, ROM so no _cal), fuel_flow_rate_protection_cap_cal (0x408d3c) and '
  'cm848_resetEngineLoadTracker (0x3f6fc).')

N('[W8 source 16 subsystem and the protection threshold cluster - own readings] (1) 0x40b648 governor_active_flag_b648 is set by '
  'initGovernorSpeedControl (0x523858: copies sensor_channelGeneric_ram.value into governor_speed_compensation_initial_ref and loads '
  'governor_speed_compensation_steps from a table keyed by it, or DAT_00408d7a under fault bits 16 / 17 / 400+) and cleared by '
  'governorSpeedCompensation (0x523798, periodic) when governor_feature_config_flags bit 8 is 0, the reference is above DAT_00408d78, '
  'fault bit 0x2000 of fault_detected_bits_16_to_31 is set, transmission_park_or_neutral_flag is 0, vehicle_speed_copy is above DAT_00408d7c '
  'or the steps run out; while it is set the arbitration applies engine_speed_limit_source_16 (1600 rpm). It reads as a timed engine speed '
  'limit while in park or neutral; the channel behind sensor_channelGeneric_ram is not identified, so the flag and both functions keep '
  'their names. (2) cm848_processJ1939RxMessage (0x20c64, no J1939 in it) converts a fuel quantity into the engine speed on the droop line '
  '(slope x (engine_speed_limit_ramped_maximum_fuel_quantity - fuel) / 4369 + arbitrated limit, capped at 40000), and '
  'cm848_updateProtectionStateMachine / cm848_updateProtectionThresholdsIfLow / governor_calculateIntegratorRpmOutput build the '
  'protection_* thresholds from it: that cluster (and torque_limit_working_reference 0x3fa8a4) needs one reading of its own. (3) '
  'rpm_governor_offset_table_a_dims / _b_dims (dual_axis_table_dims_t, 0x3fa878 / 0x3fa87c, both words initialised to 2) are the '
  'interpolation caches of injection_timing_offset_map_a / _b, not table dimensions - a type / name note for a later wave.')

N('[W8 stale text - rows to fix by swap or by hand] Handled by the plate-only function rows of this file: function_renames.csv 844 '
  '(cm848_selectEngineSpeedLimit, rewritten), 848 (cm848_calculateEffectiveFuelLimit, two false statements), 828 / 1176 / 1038 (name swaps), '
  '1387 (struct-qualified name, DAT_0005a48a) and 2133 (DAT_0005a48a). W7 rows 844 / 845 / 848 were partly refreshed already; row 845 needs '
  'nothing. By swap with refresh_references.py after the renames (every sentence stays true): global_variables.csv 4423 '
  '(torque_limit_offset_calc -> engine_speed_limit_droop_no_load_speed), 4427 (torque_limit_source_d_f_disable_cal -> '
  'engine_speed_limit_torque_converter_droop_enable), 4431 (torque_limit_state_machine_snapshot -> '
  'engine_speed_limit_droop_cap_source_code_snapshot), 4885 (torque_limit_fuel_upper_cal / _lower_cal -> '
  'engine_speed_limit_droop_fuel_clamp_maximum / _minimum). By hand: 3113 / 3114 / 3115 and 4873 (struct note), 3137 (dword note), '
  '4430 (engine_speed_limit_source_10: "the limit then cuts the fuel at once" holds only while engine_speed_limit_droop_slope_bypass_flag '
  'is nonzero; here it is 0, so the slope is recomputed in the same pass). '
  'Suggested comment for the existing row 0x5a48a injection_timing_top_dead_center_offset (i16 -171): add "minus the top dead center '
  'position in timing counts (171): the TDC-relative angle in counts is timing - 171; the EEPROM injection_timing_offset_cal (171 in the '
  'dump) is an absolute value whose default equals the TDC position, so the net trim is 0". Names in these notes are not seen by the gate.')

# ---------------------------------------------------------------------------------------------------------------
N('[W8 leads not taken - closed with this note, informational / own wave] W7 note 87 leftovers that need their own reading and got '
  'none here: protection_fuel_limit_active (0x40afac) / governor_fuel_mode_command (0x40afae) and their 12 writers, timing_limit_lower '
  '(0x5c306) / timing_limit_upper (0x5c30c), cm848_resetGovernorStartupReadyFlag (0x507c44, the fault derate scheduler), '
  'governor_cruise_speedError_torqueAdj (0x525134), the governor_pid_t fields proportional_gain / integral_term (0x40af5a / 0x40af5c), '
  'j1939_dm1_spn_a_word / j1939_dm1_spn_fmi_byte and cm848_protection_init (0x5031b4). W7 notes 86 / 88-90 were informational or are '
  'answered above (the torque_limit_* family is now: renamed, uncertain 0x3fa8a4 / 0x40a280 / 0x3fdd38, or the thermal note). '
  'Convention of this file (as in W7): plates and evidence use the PROPOSED new names, so apply the function rows, the global rows '
  'and the plates together; a global that is skipped needs the plates that cite it regenerated with its old name. The repo gate '
  'apply_renames.py was not run (the classifier denied the call); scratch_W8_torque_limit/check_W8.py replicates its checks (no '
  'register-address check) and finds no problem.')

with open(RESULT, 'w') as f:
    for r in rows:
        f.write(json.dumps(r, ensure_ascii=True) + '\n')
print('rows written:', len(rows))
for w in warn:
    print('WARN', w)
from collections import Counter
print(Counter((r['kind'], r.get('verdict')) for r in rows))
