import json

OUT = '/home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_06.jsonl'

FAMILY = ('cam_timing_* is the old wrong domain: engine_camTiming_positionCorrection_calc compares '
          'fuel_metering_feedback_input with a table of the fuel pressure governor demand and sets fault bit 60 '
          '(fault_detected_bits_48_to_63 0x1000); firmware/CLAUDE.md lists the camTiming / cam_sync names around the '
          'fuel pressure governor as fuel pressure names still to re-domain.')

SUM_NOTE = ('DAT_0040b8ea = cam_timing_position_correction_scaled + coolant component + rpm component + DAT_00409abc '
            'is an unnamed sum; its only consumer is the L176 lookup.')

QUANTITY_NOTE = ('engine_timing_reference is a fuel quantity, not a timing: it is (injection_timing_demand_working x '
                 'fuel_demand_computed_snapshot / 51200) + a cylinder_diag_output_array offset, clamped 0..5888, and it '
                 'is copied to injection_fuel_quantity_snapshot; its fuel axes elsewhere run 0..2061 '
                 '(the feed-forward fuel axis at 0x4093a4, cam_sync_timing_axis_*).')

rows = []

rows.append({
    'lookup': 'L170',
    'base': 'fuel_pressure_governor_demand_residual_divisor',
    'input': 'fuel_pressure_feedback_filtered (filtered rail pressure, 0.0488 MPa per count)',
    'output': ('cam_timing_correction_time_constant -> times 100 (minimum 1) is the divisor of the demand residual: '
               'cam_timing_position_correction_term = (fuel_pressure_governor_demand - cam_timing_correction_coolant_offset '
               '- cam_timing_correction_rpm_offset) x 41 / value. Runs only when DAT_00409aba (a word) is 0; it is 41 in '
               'this calibration, so this lookup is never reached here.'),
    'units_check': ('breakpoints 511..3276 counts x 0.0488 MPa = 25, 50, 80, 90, 100, 110, 120, 130, 140, 160 MPa: fits '
                    'the rail pressure input (the monitor only runs for 820..2869 = 40..140 MPa). Values are all 0 in the '
                    'RAM dump and in the ROM calibration image (ROM 0x6f75c), so the output units cannot be checked; with 0 '
                    'the divisor would clamp to 1. Role comes from the code and the breakpoints only.'),
    'confidence': 'medium',
    'evidence': ('The result x 100 (minimum 1) is the divisor of the 64-bit division that turns the demand residual into '
                 'cam_timing_position_correction_term (disassembly 0x52b644-0x52b714). The block is skipped because '
                 'DAT_00409aba = 41, so the table is unused in this calibration.'),
    'naming_concern': (FAMILY + ' Also nothing accumulates: the term is assigned each pass, never integrated, so the value '
                       'divides the residual and "time constant" is not shown.'),
})

rows.append({
    'lookup': 'L171',
    'base': 'fuel_pressure_governor_demand_threshold_gain',
    'input': 'fuel_pressure_feedback_filtered (filtered rail pressure, 0.0488 MPa per count)',
    'output': ('cam_timing_position_correction_gain -> cam_timing_position_correction_scaled = '
               'cam_timing_position_correction_effective x gain / 41; effective is DAT_00409aba = 41 in this calibration '
               'so the table value passes straight into the sum DAT_0040b8ea (the x input of the L176 lookup).'),
    'units_check': ('breakpoints 1025..2869 = 50..140 MPa in 10 MPa steps (x 0.0488), fits the rail pressure input and ends '
                    'exactly at the monitor window top fuel_pressure_feedback_maximum (2869). Values 316..516 rise with '
                    'pressure and are in governor demand counts (the L176 axis spans 0..2869; 316..516 = 7.7..12.6 % of '
                    '4095): they equal the path-A required-demand curve of engine_camSync_referenceCheck_update (0x409aea, '
                    '255..434) plus 82 (2 % of 4095) from the third breakpoint on.'),
    'confidence': 'medium',
    'evidence': ('The sum that this value enters goes through a decreasing demand-to-feedback table (lookup L176, 0x409e14 / '
                 '0x409e2a) and the fault '
                 'counts when measured feedback is below the result, so the sum is an upper bound on demand, and this '
                 'curve is the path-A demand limit plus 2 %. ' + SUM_NOTE),
    'naming_concern': (FAMILY + ' "gain" is the multiplier of the correction term, not a PID gain (those are the '
                       'fuel_pressure_governor_*_term words). "demand threshold" is my reading from the L176 link; the '
                       'alternative reading is an expected (nominal) demand.'),
})

rows.append({
    'lookup': 'L172',
    'base': 'fuel_pressure_governor_demand_offset_coolant',
    'input': ('x: sensor_readings_t_0040baf2.coolant_temp (coolant temperature, 1/64 deg F per count); '
              'y: fuel_pressure_feedback_filtered (rail pressure, 0.0488 MPa per count)'),
    'output': ('cam_timing_correction_coolant_offset -> subtracted from fuel_pressure_governor_demand together with the '
               'rpm offset to form the demand residual (then x 41 / divisor -> cam_timing_position_correction_term). '
               'Reached only when DAT_00409aba = 0 (it is 41 here) and the speed gate flag is set.'),
    'units_check': ('x 2560..11520 / 64 = 40..180 deg F in 20 deg steps; y 0, 205, 615, 1230, 1844, 2459, 3074, 3689 = '
                    '0, 10, 30, 60, 90, 120, 150, 180 MPa. The monitor needs coolant 11520..13120 (180..205 deg F), so '
                    'inside it the grid sits on its last x column (the interpolator clamps at the axis ends). Grid all 0 '
                    'in the RAM dump and ROM image (ROM 0x6f7c2): output units cannot be checked; role from the code only.'),
    'confidence': 'medium',
    'evidence': ('It is subtracted from the governor demand (disassembly 0x52b6cc-0x52b6dc), so by construction it is in '
                 'demand counts. It is inactive in this calibration because the block is skipped.'),
    'naming_concern': (FAMILY + ' "offset" is kept because the value is subtracted from the demand; it pairs with the '
                       'L173 coolant part of the threshold.'),
})

rows.append({
    'lookup': 'L173',
    'base': 'fuel_pressure_governor_demand_threshold_coolant',
    'input': ('x: sensor_readings_t_0040baf2.coolant_temp (coolant temperature, 1/64 deg F per count); '
              'y: fuel_pressure_feedback_filtered (rail pressure, 0.0488 MPa per count)'),
    'output': ('cam_timing_correction_coolant_component -> added into DAT_0040b8ea (the x input of the L176 lookup). '
               'Not gated by DAT_00409aba, so it runs whenever the monitor is enabled.'),
    'units_check': ('x 0..8960 / 64 = 0..140 deg F in 20 deg steps: the monitor window (180..205 deg F) lies beyond the last '
                    'breakpoint, so only the last column is ever used; y 409..3276 = 20..160 MPa in 20 MPa steps (x 0.0488), '
                    'fits the rail pressure input. Grid all 0 in the RAM dump and ROM image (ROM 0x6f866): it adds nothing '
                    'in this calibration; the unit is demand counts by the sum it enters.'),
    'confidence': 'medium',
    'evidence': ('Its result is one of the three terms of the sum that feeds L176, whose axis equals the demand axis of the '
                 'loop-2 feedback target pair cam_sync_ref_output_axis_* / _values_* (0x40915e / 0x409174), so it is '
                 'demand-valued. ' + SUM_NOTE),
    'naming_concern': (FAMILY + ' Named for the coolant part of the demand threshold; "threshold" (upper bound on demand) '
                       'is my reading, an expected-demand reading is the alternative (see L171).'),
})

rows.append({
    'lookup': 'L174',
    'base': 'fuel_pressure_governor_demand_offset_rpm',
    'input': ('x: engine_rpm_state_t_0040b7ac.current_rpm (0.125 rpm per count); '
              'y: engine_timing_reference (per-injection fuel quantity, 0.0679 mm3 per stroke per count)'),
    'output': ('cam_timing_correction_rpm_offset -> subtracted from fuel_pressure_governor_demand together with the '
               'coolant offset to form the demand residual. Reached only when DAT_00409aba = 0 (41 here) and the speed '
               'gate flag is set.'),
    'units_check': ('x 800..28000 counts = 100..3500 rpm (100, 600, 1200, 1700, 2200, 2700, 3150, 3500); y 0..2060 counts x '
                    '0.0679 = 0, 20, 40, 60, 80, 100, 120, 140 mm3 per stroke (the CM848 MM3S scale, same as the fuel axes '
                    'of the feed-forward map at 0x4093a4). Grid all 0 in the RAM dump and ROM image (ROM 0x6f90a): output units '
                    'cannot be checked; role from the code only.'),
    'confidence': 'medium',
    'evidence': ('It is subtracted from the governor demand beside the coolant offset (disassembly 0x52b6c4-0x52b6dc), so it '
                 'is in demand counts by construction; inactive here because the block is skipped.'),
    'naming_concern': (FAMILY + ' ' + QUANTITY_NOTE),
})

rows.append({
    'lookup': 'L175',
    'base': 'fuel_pressure_governor_demand_threshold_rpm',
    'input': ('x: engine_rpm_state_t_0040b7ac.current_rpm (0.125 rpm per count); '
              'y: engine_timing_reference (per-injection fuel quantity, 0.0679 mm3 per stroke per count)'),
    'output': ('cam_timing_correction_rpm_component -> added into DAT_0040b8ea (the x input of the L176 lookup). '
               'Not gated by DAT_00409aba, so it runs whenever the monitor is enabled and is the main non-zero term here.'),
    'units_check': ('x 0..27200 counts = 0, 1000, 1400, 1700, 2000, 2400, 2800, 3400 rpm; y 0..2060 counts = 0..140 mm3 '
                    'per stroke in 20 mm3 steps. Grid 557..2077 (13.6..50.7 % of 4095; first row 557..845, '
                    'last row 1152..2077) stays inside the governor demand range 0..2869; '
                    'like the governor feed-forward map cam_sync_values_* (0x4093b6, 0..1512) it rises with fuel quantity '
                    'and rpm over the same kind of axes, with a base of about 557 at idle.'),
    'confidence': 'medium',
    'evidence': ('Its result is the largest term of the sum that feeds L176, whose axis equals the demand axis of the '
                 'loop-2 feedback target pair cam_sync_ref_output_axis_* / _values_* (0x40915e / 0x409174), so it is '
                 'demand-valued and rises like the feed-forward demand. '
                 + SUM_NOTE),
    'naming_concern': (FAMILY + ' ' + QUANTITY_NOTE + ' "threshold" (upper bound on demand) is my reading; an '
                       'expected-demand reading is the alternative (see L171).'),
})

rows.append({
    'lookup': 'L176',
    'base': 'fuel_metering_feedback_min_by_demand_threshold',
    'input': ('DAT_0040b8ea (unnamed sum: cam_timing_position_correction_scaled + cam_timing_correction_coolant_component + '
              'cam_timing_correction_rpm_component + DAT_00409abc; written once, only consumer is this lookup)'),
    'output': ('cam_timing_fault_activation_threshold -> (short)fuel_metering_feedback_input < value ramps '
               'cam_timing_fault_activation_counter up (else down) to cam_timing_fault_activation_threshold_count (150), '
               'which sets fault_detected_bits_48_to_63 0x1000 (fault bit 60; ROM 0x5985a maps it to slot 164 = P1223) and '
               'DAT_0040b90c.'),
    'units_check': ('x 0, 41, 205, 410, 820, 2049, 2459, 2664, 2828, 2869 are governor demand counts (4095 = 100 %: 0, 1, 5, '
                    '10, 20, 50, 60, 65, 69, 70 %); the RAM dump (engine off, governor mode 1) shows fuel_pressure_governor_demand = '
                    '2869, equal to the top breakpoint, and the sensor-fault command is 2865 (70 %). y 1391..0 falls with demand and is in fuel_metering_feedback_input counts '
                    '(0..4092; 16 in the dump with command 0). Near-copy of cam_sync_ref_output_axis_* (0x40915e) / '
                    'cam_sync_ref_output_values_* (0x409174): the axis differs only in [0] (0 vs -122) and the values '
                    'only in [1] (1207 vs 1224). Values are non-zero, so unlike L170/L172/L174 this one is live.'),
    'confidence': 'medium',
    'evidence': ('cm848_calculateFuelMeteringCommand feeds the clamped fuel_pressure_governor_demand through the near-identical '
                 'pair cam_sync_ref_output_axis_* / _values_* (0x40915e / 0x409174) to get the target for fuel_metering_feedback_input, so this x axis is in demand counts and the '
                 'output in feedback counts. The fault counts when the measured feedback is below the value, so the value '
                 'is a minimum for the feedback.'),
    'naming_concern': (FAMILY + ' "min" is the compare direction (fault when fuel_metering_feedback_input is below the '
                       'value); the base names the input by the demand threshold sum (see L171, medium). The physical '
                       'signal behind fuel_metering_feedback_input is not identified in the repo, and the meaning of '
                       'P1223 is not established.'),
})

with open(OUT, 'w') as handle:
    for row in rows:
        handle.write(json.dumps(row, ensure_ascii=True) + '\n')

print('wrote', len(rows), 'lines to', OUT)
