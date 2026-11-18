import sys, json, re, csv
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W3_rail')
import ctx

OUT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W3_rail.jsonl'
R = ctx.R
recs = []
problems = []

def A(a):
    return '0x%08x' % a

# ---------------------------------------------------------------- functions
FUNCS = [
 ('hpcr_register_state_save', 'cm848_initializeFuelPressureSetpointState',
  'Start-up initialization of cm848_calculateFuelPressureSetpoint: sets fuel_pressure_setpoint_transition_state and fuel_pressure_setpoint_winning_term_code to 1 and the 16 lookup interpolation state words 0x3fd0ca-0x3fd0e8 (first argument of its table lookups) to 2. Called once from cm848_applicationMain. (was hpcr_register_state_save)',
  'Body only stores 1 / 1 / 2 x 16 to variables whose only users are the setpoint calculator and this function (xref: 0 reads, 1 write each).'),
 ('engine_camTiming_speedWindow_update', 'cm848_checkFuelPressureGovernorDemandAtGovernedSpeed',
  'Third rail pressure governor monitor, switched off in this calibration (byte 0x409aa0 = 0): when the engine speed is within 160 counts (20 rpm) of governor_speed_limit_output with the vehicle stopped, cold_start_phase at the governor setpoint, coolant 180-205 F and no injector, rail pressure or related fault, it debounces (80 net passes) fuel_pressure_governor_demand above 283 and sets fault 57 (P1221), clearing it when the count returns to 0. (was engine_camTiming_speedWindow_update; not cam timing)',
  'Read in full: the only compare is engine_sync_state_t.fuel_pressure_governor_demand against the 283 threshold; fault 57 = word 3 mask 0x200 = slot 162 = P1221 by the 0x5985a / obd_dtc_code_table decode; RAM dump byte 0x409aa0 = 0 so it returns at once.'),
 ('cm848_calibration_group28_load', 'cm848_runFuelPressureGovernorMonitors',
  'Runs the three rail pressure governor monitors in order: cm848_checkFuelPressureGovernorDemandAtGovernedSpeed (disabled here), cm848_checkFuelPressureWithoutInjection and cm848_monitorFuelMeteringFeedbackAgainstGovernorDemand. Called from cm848_periodicTaskGroup28_calibration10. (was cm848_calibration_group28_load)',
  'Body is exactly those three calls; no calibration is loaded.'),
 ('cm848_initialization_group28_state', 'cm848_initializeFuelPressureGovernorMonitorState',
  'Start-up initialization of the three rail pressure governor monitors: sets their 13 lookup interpolation state words 0x3fd0ea-0x3fd102 (first argument of lookupTableInterpolation) to 2. Called once from cm848_applicationMain. (was cm848_initialization_group28_state)',
  'Body stores 2 to 13 consecutive words; a scan of the C shows 9 of them referenced only by checks A / B and the feedback monitor (the others are reached by offset from those bases), none by any other function.'),
 ('hpcr_camTimingMonitor', 'cm848_monitorFuelPressureTrackingError',
  'Rail pressure tracking monitor, enabled by protection_feature_flags bit 0x4000: each pass it integrates (fuel_pressure_setpoint - fuel_pressure_feedback_previous) / ROM divisor 1 into fuel_pressure_shortfall_accumulator and, negated, fuel_pressure_excess_accumulator (both clamped at 0); above the ROM limits 245902 / 204918 it sets fault 408 / 409 (both P0148) and monitor state 3, and after a window of 6000 passes with both below the limits it clears them (state 2). It runs only with no related fault and within the coolant, fuel temperature and target_rpm (at least 600 rpm) windows. (was hpcr_camTimingMonitor; not cam timing)',
  'Read in full: fuel_pressure_feedback_previous is the previous filtered rail pressure (CSV comment), faults 408 / 409 decode to slot 91 = P0148; ROM dwords at 0x6440e / 0x64412 = 245902 / 204918, window 0x64416 = 6000, divisor 0x64420 = 1; nothing in it touches cam timing.'),
 ('hpcr_camTimingReset', 'cm848_resetFuelPressureTrackingErrorMonitor',
  'Start-up reset of the rail pressure tracking monitor: monitor state 0, accumulators and pass count zeroed, monitor inactive; when protection_feature_flags bit 0x4000 is clear it also marks the monitor complete (clears bit 7 of fault_pending_flags, sets bit 7 of diagnostic_monitor_complete_bits). Called once from cm848_applicationMain. (was hpcr_camTimingReset)',
  'Read in full (18 lines); same variables as the monitor.'),
 ('engine_protection_counters_reset', 'cm848_resetFuelPressureTrackingErrorAccumulators',
  'Zeroes the shortfall and excess accumulators and the pass count of the rail pressure tracking monitor (0x40b9d8, 0x40b9dc, 0x3fd1e4). Called by cm848_monitorFuelPressureTrackingError and cm848_resetFuelPressureTrackingErrorMonitor. (was engine_protection_counters_reset)',
  'xref_addr.py: the only stores to 0x40b9d8 / 0x40b9dc / 0x3fd1e4 outside the monitor are the three in this function (0x531d18 / 0x531d20 / 0x531d2c); its 3 callers are the monitor (twice) and its reset.'),
 ('hpcr_injectSystemDiagnostic', 'cm848_monitorFuelPressureSetpointNotReached',
  'One-sided sibling of cm848_monitorFuelPressureTrackingError, enabled by protection_feature_flags bit 0x8000: it integrates (fuel_pressure_setpoint - fuel_pressure_feedback_previous) / DAT_00409fdc into fuel_pressure_setpoint_not_reached_accumulator, which is clamped at 0 and zeroed whenever fuel_pressure_sensor has reached the setpoint; above DAT_00409fce (18443) it sets fault 352 (no OBD slot) and monitor state 3, and the window ends after 300 passes (state 2). It runs only with no rail pressure or fuel metering fault, wide coolant and fuel temperature windows and target_rpm of at least 600 rpm. (was hpcr_injectSystemDiagnostic)',
  'Read in full (86 lines): same structure as hpcr_camTimingMonitor, the accumulator is reset by "setpoint <= fuel_pressure_sensor"; fault 352 = word 22 bit 0 = slot 170 (no OBD code) and is one of the five faults that cm848_protectionInputValidator turns into reaction bits; nothing in it is an injection diagnostic.'),
 ('engine_cssc_counters_reset', 'cm848_resetFuelPressureSetpointNotReachedAccumulator',
  'Zeroes the accumulator and the pass count of the rail pressure setpoint-not-reached monitor (0x40ba62, 0x3fd266). Called by cm848_monitorFuelPressureSetpointNotReached and by cm848_initTimerInterrupts. (was engine_cssc_counters_reset)',
  'Read in full: two stores; callers are hpcr_injectSystemDiagnostic (2 calls) and cm848_initTimerInterrupts.'),
 ('cm848_updateEngineDiagnosticCounters', 'cm848_updateFuelPressureDiagnosticCountersAndCheckFeedbackCircuit',
  'Run each phase group B pass before cm848_diagnoseFuelPressureGovernor: counts the passes for which fuel_pressure_diagnostic_flags has differed from fuel_pressure_diagnostic_snapshot (set / clear debounce counters), and checks the fuel metering feedback circuit: it reads the feedback (QADC slot 63 or its forced reading) through the linearization table into fuel_metering_feedback_input and, after 200 passes with the feedback above the high threshold and the command below its limit (fault 265, code 1) or below the low threshold and the command above its limit (fault 264, code 2), sets the fault bit; both circuit checks are inactive in this calibration. (was cm848_updateEngineDiagnosticCounters)',
  'Read in full; the RAM dump has the high threshold 4092, low threshold 0, command limits 0 / 0, debounce 200, so neither circuit check can trigger; slot 63 = 0x40bc80 + 2 x 63 = 0x40bcfe (forced reading, override bit 15 of the word at +78 of diagnostic_service_dispatch_table).'),
 ('cm848_initEngineDiagnosticData', 'cm848_initializeFuelPressureDiagnosticState',
  'Start-up initialization of the rail pressure diagnostics: clears fuel_pressure_diagnostic_snapshot / _flags, fuel_metering_feedback_input, the too-high pending flag, count and recovery count, the two debounce counters and the two feedback circuit counters, and sets the eight lookup interpolation state words 0x3fb6cc and 0x3fb6ce-0x3fb6da to 2. Called once from cm848_applicationMain. (was cm848_initEngineDiagnosticData)',
  'Read in full (29 lines): it clears the rail pressure diagnostic state (flags, snapshot, pending flag, counters, feedback input) and sets the interpolation state words; the snapshot and the feedback input are shared with other readers, the interpolation words and counters are not.'),
 ('cm848_protectionInputValidator', 'cm848_updateFuelPressureFaultReactionRequests',
  'Builds fault_reaction_request_bits from the registered faults 317, 290, 324, 408 and 352 (each ORs in its own fault_NNN_reaction_request_mask; bit 3 of the previous value is kept) and requests logical output 54 while bit 3 is set. Runs before cm848_applyFuelLimitsForFuelPressureFaults in cm848_periodicTaskSet_protection3. (was cm848_protectionInputValidator)',
  'Read in full; 317 / 290 / 324 are set by cm848_diagnoseFuelPressureGovernor, 408 by the tracking monitor, 352 by the setpoint-not-reached monitor; reaction bits are consumed by the fuel limit function, the setpoint calculator (bit 2) and the limp home flag.'),
 ('cm848_protectionSensorFaultHandler', 'cm848_applyFuelLimitsForFuelPressureFaults',
  'Sets the fuel limit governor_fuel_limit_source and the second limit torque_fuel_minimum_working (an input of cm848_selectTorqueLimit, default 30000) for the rail pressure faults: P0193 / P0192 (304 / 305) use the sensor fault limits, fault 264 and P0251 (333) cap them at the fuel metering fault limits, fault reaction bits 0 / 1 cap them at the reaction limits and P0088 (303) at the too-high limits; with none of these the limit is 0x1700 (the maximum). It adds fuel_demand_offset_correction when protection_feature_flags bit 3 is set and requests logical output 54 while a too-high bit of fuel_pressure_diagnostic_snapshot is set and the enable word is non-zero. (was cm848_protectionSensorFaultHandler)',
  'Read in full; fault numbers decoded with the ROM slot table (304 = P0193, 305 = P0192, 333 = P0251, 303 = P0088, 264 = no slot); limit values from the RAM dump (883 / 20000 / 5888 / 30400); torque_fuel_minimum_working is compared with torque_limit_arb_t.fuel_minimum in cm848_selectTorqueLimit (source 7) and starts at torque_limit_fuel_minimum = 30000, so its unit is not that of the 0x1700 fuel limit.'),
 ('cm848_checkProtectionFaultConditions', 'cm848_updateFuelPressureLimpHomeActiveFlag',
  'Sets fuel_pressure_limp_home_active_flag while any trigger enabled by fuel_pressure_limp_home_trigger_enable_mask is present: bit 0 / 1 = registered faults 264 / 265, bit 2 = fault 333 (P0251), bit 3 / 4 = faults 304 / 305 (P0193 / P0192), bit 5 / 6 = fault reaction request bits 0 / 1, bit 7 = fault 303 (P0088); the mask is 156 here (bits 2, 3, 4 and 7). Called each phase group B pass. (was cm848_checkProtectionFaultConditions)',
  'Read in full (28 lines); bit-to-fault pairing taken from the masks in the code, mask value 0x9c from the RAM dump.'),
 ('cm848_updateProtectionBitFlags', 'cm848_updateInjectorDiagnosticBits',
  'Decodes one injector row (param_2 = 1 to cylinder_event_count_max) of the 24-bit diagnostic word param_1 read by cm848_readInjectorDiagnosticWord: the row\'s 2-bit code sets that injector\'s bit in injector_diagnostic_bits_b / _a / _c for codes 0 / 1 / 2 and clears it in all four bytes for code 3, and a separate flag bit sets (when 0) or clears the injector\'s bit in injector_diagnostic_bits_d. Masks come from the tables at 0x57d2e and 0x57d76. (was cm848_updateProtectionBitFlags)',
  'Read in full; the per-row fault tables at 0x57d76 decode (ROM slot table) to P0201-P0206 for class a and P2146 / P2149 (injector group supply voltage) for classes b / c, so the rows are injectors.'),
 ('cm848_protectionFaultEvaluator', 'cm848_evaluateInjectorDiagnosticFault',
  'Debounces one class of injector diagnostic bits (param_1): a counter at param_2 counts up while any bit is set and down while none is set (unless param_5 blocks healing); for each injector row it sets the fault bit given by the row\'s entry at offset param_4 of the table at 0x57d76 when the counter is above the limit param_3 and the row\'s bit is set, and clears it when the counter is 0 and the bit is clear. (was cm848_protectionFaultEvaluator)',
  'Read in full; called four times by cm848_evaluateInjectorDiagnostics with offsets 2 / 4 / 6 / 8 for classes a / c / b / d (a text search finds no other reference than its definition and these four calls).'),
 ('mpc555_evaluateProtectionSyncFaults', 'cm848_evaluateInjectorDiagnostics',
  'Injector diagnostics, called from the TPU-A channel 10 cylinder event handler once per full cycle: when MIOS MDASM30 status bit 15 is set and protection_config_flags bit 0x40 and supervisor_register_36_bit_1_low_held_flag are clear it reads the diagnostic word with cm848_readInjectorDiagnosticWord, updates the four injector diagnostic bit bytes for each injector with cm848_updateInjectorDiagnosticBits and debounces each class with cm848_evaluateInjectorDiagnosticFault. (was mpc555_evaluateProtectionSyncFaults)',
  'Read in full; its fault outputs are the injector circuit faults P0201-P0206 and P2146 / P2149 plus six faults without OBD slot; the old plate of the channel 10 handler names it as the wrap-around call.'),
 ('cm848_getProtectionSyncState', 'cm848_readInjectorDiagnosticWord',
  'Reads a 24-bit diagnostic word serially, most significant bit first: drives output line 0x2d low, then 24 times samples discrete input line 0x30 and pulses output line 0x2c high and low with software delay loops, releases line 0x2d and returns the word shifted left by 8. Its bit fields become the per-injector diagnostic bits in cm848_updateInjectorDiagnosticBits. (was cm848_getProtectionSyncState)',
  'Read in full (51 lines); the "injector" part is inferred from its only consumer chain (see cm848_updateInjectorDiagnosticBits), the serial protocol itself is read directly.'),
]
for old, new, plate, ev in FUNCS:
    fn = ctx.funcs.get(old)
    if not fn:
        problems.append('no function ' + old); continue
    recs.append({'kind': 'function', 'address': fn[0], 'old': old, 'verdict': 'confirmed', 'new': new, 'plate_comment': plate, 'evidence': ev})

fn = ctx.funcs['engine_protection_fuelCorrection_stateMachine']
recs.append({'kind': 'function', 'address': fn[0], 'old': 'engine_protection_fuelCorrection_stateMachine', 'verdict': 'uncertain',
 'evidence': 'Read in full (162 lines). It is neither protection nor a correction: with the engine warm, no governor fuel active and the rail pressure within 82 counts of fuel_pressure_setpoint it ramps a weighted average of fuel_demand_computed (fuel_correction_ramp_demand) and compares it with a table target (fuel_correction_timing_table 8 / 249 / 311 / 342 / 371 = 0.5 / 16.9 / 21.1 / 23.2 / 25.2 mm3, chosen by the A/C clutch request, alternator duty and automatic transmission in gear - quantities, not timing), then sets (demand not below the target, state 3) or clears (state 2) fault bit 7 = P0191. I could not settle the name: P0191 is the rail pressure sensor range / performance code, but whether this is an idle fuel demand rationality test (the governor output and vehicle speed gates did not read as plain idle) needs the callers of fuel_correction_ramp_state. Candidate if accepted: cm848_checkFuelPressureSensorPerformance.'})

# ---------------------------------------------------------------- globals (existing rows)
G = []
def g(addr, old, new, ev): G.append((addr, old, new, ev))

# tracking error monitor
g(0x40b9d8, 'cam_timing_advance_accumulator', 'fuel_pressure_shortfall_accumulator', 'dword, only used by the tracking error monitor and its counters reset: += (fuel_pressure_setpoint - fuel_pressure_feedback_previous) / divisor each pass, clamped at 0; above 245902 it sets fault 408 (rail pressure below its setpoint).')
g(0x40b9dc, 'cam_timing_retard_accumulator', 'fuel_pressure_excess_accumulator', 'dword, same users: the negated error, clamped at 0; above 204918 it sets fault 409 (rail pressure above its setpoint).')
g(0x40b9e0, 'cam_timing_delta_per_cycle', 'fuel_pressure_tracking_error_per_pass', 'word, one store in the monitor: (fuel_pressure_setpoint - fuel_pressure_feedback_previous) / ROM divisor; added to the accumulators.')
g(0x40b9e2, 'cam_timing_monitor_state', 'fuel_pressure_tracking_error_monitor_state', 'word, 7 stores and no reader: 0 off, 1 armed, 2 window passed, 3 limit exceeded.')
g(0x3fd1e6, 'cam_timing_monitor_active_flag', 'fuel_pressure_tracking_error_monitor_active_flag', 'byte, set when the enable bits are present, cleared when the switch input bit 0 is clear; only the monitor and its reset use it.')
g(0x3fd1e4, 'cam_timing_monitor_eval_cycle_count', 'fuel_pressure_tracking_error_monitor_pass_count', 'word, counts passes up to the ROM window 6000, then the window is evaluated and the counters reset.')
g(0x3fd1e7, 'cam_timing_monitor_inhibit_flag', 'fuel_pressure_tracking_error_monitor_inhibited_flag', 'byte, set while the enabling conditions fail (state 0), cleared when they return and state 1 restarts the monitor.')
# setpoint-not-reached monitor
g(0x40ba62, 'cssc_injection_timing_accumulator', 'fuel_pressure_setpoint_not_reached_accumulator', 'dword used only by hpcr_injectSystemDiagnostic and its counters reset: += (setpoint - previous feedback) / divisor, clamped at 0 and zeroed when fuel_pressure_setpoint <= fuel_pressure_sensor; above 18443 it sets fault 352.')
g(0x40ba68, 'cssc_injection_diag_state', 'fuel_pressure_setpoint_not_reached_monitor_state', 'word 0 / 1 / 2 / 3 exactly like the tracking monitor state (3 = limit exceeded); users: the monitor and cm848_initTimerInterrupts.')
g(0x3fd266, 'cssc_injection_diag_cycle_count', 'fuel_pressure_setpoint_not_reached_monitor_pass_count', 'word, counts passes up to DAT_00409fd2 = 300; zeroed by the accumulator reset.')
g(0x3fd264, 'hpcr_cam_diag_active_flag', 'fuel_pressure_setpoint_not_reached_monitor_active_flag', 'byte set by the enable bits of the setpoint-not-reached monitor (protection_feature_flags bit 0x8000); users: the monitor and cm848_initTimerInterrupts.')
# governed speed monitor
g(0x40b8d4, 'cam_timing_speed_window_debounce_count', 'fuel_pressure_governed_speed_check_debounce_count', 'word, +1 / -1 on fuel_pressure_governor_demand above / not above the limit, fault 57 at the debounce limit, cleared at 0; only the governed speed monitor uses it.')
g(0x409aac, 'cam_timing_speed_window_debounce_max', 'fuel_pressure_governed_speed_check_debounce_limit', 'ROM copy, value 80 in the RAM dump; the count that sets fault 57.')
g(0x409ad0, 'cam_timing_speed_window_reference_count_threshold', 'fuel_pressure_governed_speed_check_demand_limit', 'ROM copy, value 283; compared with engine_sync_state_t.fuel_pressure_governor_demand (the same value 283 as fuel_pressure_governor_demand_limit_at_governed_speed at 0x409522 in the diagnostics).')
g(0x40b906, 'cam_timing_speed_window_in_range_flag', 'fuel_pressure_governed_speed_check_speed_in_window_flag', 'byte: engine_rpm_measured within the halfwidth of governor_speed_limit_output.')
g(0x40b907, 'cam_timing_speed_window_enable_flag', 'fuel_pressure_governed_speed_check_enabled_flag', 'byte: all conditions met (or the ROM override value), gate for the debounce.')
g(0x409ad2, 'cam_timing_governor_speed_window_halfwidth', 'fuel_pressure_monitor_governed_speed_window_halfwidth', 'ROM copy, value 160 counts (20 rpm); read by the governed speed monitor and by the feedback monitor, both as a window around governor_speed_limit_output.')
g(0x409aa6, 'cam_timing_coolant_temp_min', 'fuel_pressure_monitor_coolant_temperature_minimum', 'ROM copy, 11520 = 180 F (1/64 F); read as the coolant window by all three governor monitors.')
g(0x409aa8, 'cam_timing_coolant_temp_max', 'fuel_pressure_monitor_coolant_temperature_maximum', 'ROM copy, 13120 = 205 F; same three users.')
# check A / B
g(0x40b8d8, 'cam_sync_reference_b_debounce_count', 'fuel_pressure_allowed_decay_check_enable_debounce_count', 'word, counts the passes the check B conditions hold, up to the limit; only check B uses it.')
g(0x409ab0, 'cam_sync_reference_b_debounce_threshold', 'fuel_pressure_allowed_decay_check_enable_debounce_limit', 'ROM copy, 0 in the dump; the count above is compared with it to set the reached flag.')
g(0x40b8da, 'cam_timing_correction_base', 'fuel_pressure_allowed_decay_step_lookup_pressure', 'word: the pressure the allowed decay step is looked up at (fuel_pressure_allowed_decay_start_pressure on the first pass, the previous model value afterwards).')
g(0x40b8e2, 'cam_timing_correction_convergence_count', 'fuel_pressure_allowed_decay_below_model_debounce_count', 'word, +1 while fuel_pressure_feedback_filtered is below the allowed decay model, -1 otherwise; fault 59 at the limit, cleared at 0.')
g(0x409ab4, 'cam_timing_correction_convergence_threshold', 'fuel_pressure_allowed_decay_below_model_debounce_limit', 'ROM copy, value 10; limit of the count above.')
g(0x40b904, 'cam_sync_reference_b_threshold_reached_flag', 'fuel_pressure_allowed_decay_check_debounce_reached_flag', 'byte = (debounce limit <= debounce count), or the ROM override value; while 0 the start pressure follows the measured pressure.')
g(0x40b905, 'cam_sync_reference_b_threshold_prev_flag', 'fuel_pressure_allowed_decay_check_debounce_reached_previous_flag', 'byte, copy of the reached flag from the previous pass (selects the model value as the lookup pressure).')
g(0x40b909, 'cam_sync_reference_check_enable_flag', 'fuel_pressure_governor_demand_plausibility_check_enabled_flag', 'byte: check A switched on, injection quantity at most the limit and all conditions met (or the ROM override value).')
g(0x40b900, 'cam_sync_reference_check_enable_count', 'fuel_pressure_governor_demand_plausibility_check_enabled_pass_count', 'word, counts the passes the flag above has been set, up to the limit; check A evaluates once it reaches the limit.')
g(0x409ac2, 'cam_sync_reference_check_enable_count_threshold', 'fuel_pressure_governor_demand_plausibility_check_enabled_pass_limit', 'ROM copy, value 15.')
# feedback monitor
g(0x40b8e6, 'cam_timing_position_correction_effective', 'fuel_pressure_governor_demand_residual_effective', 'word: DAT_00409aba (41) when that is non-zero, otherwise the live residual; then scaled by the gain / 41.')
g(0x40b8e8, 'cam_timing_position_correction_scaled', 'fuel_pressure_governor_demand_threshold_residual_term', 'word = effective residual x fuel_pressure_governor_demand_threshold_gain / 41, clamped to +/-32767; first term of fuel_pressure_governor_demand_threshold.')
# fuel metering feedback circuit check
g(0x3fb6e2, 'engine_sync_event_counter_a', 'fuel_metering_feedback_circuit_high_debounce_count', 'word, +1 while the feedback is above the high threshold with the command below its limit (up to the debounce limit), -1 otherwise; at the limit fault 265 / code 1.')
g(0x3fb6e4, 'engine_sync_event_counter_b', 'fuel_metering_feedback_circuit_low_debounce_count', 'word, same for the low side: fault 264 / code 2.')
g(0x40952c, 'engine_sync_event_target', 'fuel_metering_feedback_circuit_debounce_limit', 'ROM copy, value 200; limit of both counters.')
g(0x409518, 'engine_sync_fault_word_threshold_hi_cal', 'fuel_metering_feedback_circuit_high_threshold', 'ROM copy (0x409518 is not in the EEPROM range, so no _cal), value 4092; fuel_metering_feedback_input above it is the high condition.')
g(0x40952a, 'engine_sync_fault_word_threshold_lo_cal', 'fuel_metering_feedback_circuit_low_threshold', 'ROM copy, value 0; fuel_metering_feedback_input below it is the low condition.')
g(0x40953a, 'engine_sync_speed_fault_upper_cal', 'fuel_metering_feedback_circuit_high_check_command_limit', 'ROM copy, value 0; the high check needs engine_sync_state_t.fuel_metering_command below it (a command, not a speed).')
g(0x409538, 'engine_sync_speed_fault_lower_cal', 'fuel_metering_feedback_circuit_low_check_command_limit', 'ROM copy, value 0; the low check needs fuel_metering_command above it.')
g(0x40bcfe, 'cam_sync_position_fault_input', 'fuel_metering_feedback_adc_forced_reading', 'the forced reading of sensor slot 63 (0x40bc80 + 2 x 63, override bit 15 of the word at +78 of diagnostic_service_dispatch_table); its only user is cm848_updateFuelPressureDiagnosticCountersAndCheckFeedbackCircuit, in the same pattern as battery_voltage_adc_forced_reading (slot 4).')
# reaction masks
g(0x40954b, 'cold_start_diag_timer_mask_cal', 'fault_317_reaction_request_mask', 'byte (ROM copy, not EEPROM): ORed into fault_reaction_request_bits when fault 317 is registered (317 is set by cm848_diagnoseFuelPressureGovernor); 0 in the dump.')
g(0x40954c, 'cold_start_pending_fault_mask_cal', 'fault_290_reaction_request_mask', 'byte: ORed in when fault 290 is registered; 0 in the dump.')
g(0x40954d, 'cold_start_crank_sync_mask_cal', 'fault_324_reaction_request_mask', 'byte: ORed in when fault 324 is registered; 0 in the dump.')
g(0x40954e, 'cold_start_j1939_mask_cal', 'fault_408_reaction_request_mask', 'byte: ORed in when fault 408 (tracking monitor, P0148) is registered; 0 in the dump.')
g(0x40954f, 'cold_start_ecu_flag_mask_cal', 'fault_352_reaction_request_mask', 'byte: ORed in when fault 352 (setpoint-not-reached monitor) is registered; 5 in the dump = reaction bits 0 and 2.')
# fuel limits in the fault handler
g(0x40952e, 'governor_fuel_limit_max_cal', 'fuel_metering_fault_fuel_limit', 'ROM copy (883): caps governor_fuel_limit_source for fault 264 or fault 333 (P0251).')
g(0x409536, 'torque_fuel_min_max_cal', 'fuel_metering_fault_minimum_fuel_limit', 'ROM copy (20000): caps torque_fuel_minimum_working for fault 264 or 333.')
g(0x409532, 'sensor_fault_fuel_limit_cal', 'fuel_pressure_sensor_fault_fuel_limit', 'ROM copy (883): the limit for P0193 / P0192 (faults 304 / 305).')
g(0x409534, 'sensor_fault_torque_fuel_min_cal', 'fuel_pressure_sensor_fault_minimum_fuel_limit', 'ROM copy (20000): the minimum fuel limit for P0193 / P0192.')
g(0x40953c, 'cold_start_fuel_limit_a_cal', 'fault_reaction_fuel_limit', 'ROM copy (5888 = 0x1700, no effect): caps governor_fuel_limit_source while fault_reaction_request_bits bit 0 is set.')
g(0x409540, 'cold_start_fuel_min_limit_cal', 'fault_reaction_minimum_fuel_limit', 'ROM copy (30400): caps torque_fuel_minimum_working while fault_reaction_request_bits bit 1 is set.')
g(0x409546, 'governor_fuel_limit_override_cal', 'fuel_pressure_too_high_fuel_limit', 'ROM copy (883): caps governor_fuel_limit_source while P0088 (fault 303) is registered.')
g(0x409548, 'torque_fuel_min_threshold_cal', 'fuel_pressure_too_high_minimum_fuel_limit', 'ROM copy (20000): caps torque_fuel_minimum_working while P0088 is registered.')
g(0x409542, 'engine_position_fault_enable_cal', 'fuel_pressure_too_high_logical_output_request_enable', 'ROM copy (0 here): when non-zero, a too-high bit (1 or 2) of fuel_pressure_diagnostic_snapshot requests logical output 54.')
g(0x409544, 'engine_sync_enable_mask', 'fuel_pressure_limp_home_trigger_enable_mask', 'ROM copy (156): bit n enables trigger n of fuel_pressure_limp_home_active_flag; its only user is cm848_updateFuelPressureLimpHomeActiveFlag.')
# injector diagnostic bits
g(0x40b8cc, 'engine_position_diag_flags', 'injector_diagnostic_bits_d', 'byte, one bit per injector: set from a separate flag bit of the 24-bit word (cm848_updateInjectorDiagnosticBits), debounced into six faults without OBD slot (270 / 276 / 273 / 282 / 285 / 279); read for the injector selection in engine_injectionAngle_selectCylinderInjector. Nothing in it concerns engine position. Its debounce limit (0x409a8a, loaded with lhz, so it stays 65535) is 65535 here, so its faults cannot set.')
g(0x40b8cd, 'protection_fault_status_a', 'injector_diagnostic_bits_a', 'byte, one bit per injector, set for 2-bit code 1; its faults are P0201-P0206 (injector circuit per cylinder).')
g(0x40b8ce, 'protection_fault_status_b', 'injector_diagnostic_bits_b', 'byte, one bit per injector, set for code 0; its faults are P2146 / P2149 (injector group supply voltage).')
g(0x40b8cf, 'protection_fault_status_c', 'injector_diagnostic_bits_c', 'byte, one bit per injector, set for code 2; its faults are P2146 / P2149.')
g(0x409a8a, 'engine_pos_fault_eval_threshold_cal', 'injector_diagnostic_bits_d_debounce_limit', 'ROM copy (65535), not EEPROM: limit passed to cm848_evaluateInjectorDiagnosticFault for class d; zero-extending lhz load at 0x4ad68, so the counter never exceeds it.')
g(0x409a8c, 'prot_fault_status_a_threshold_cal', 'injector_diagnostic_bits_a_debounce_limit', 'ROM copy (2): limit for class a.')
g(0x409a8e, 'prot_fault_status_b_threshold_cal', 'injector_diagnostic_bits_b_debounce_limit', 'ROM copy (1): limit for class b.')
g(0x409a90, 'prot_fault_status_c_threshold_cal', 'injector_diagnostic_bits_c_debounce_limit', 'ROM copy (1): limit for class c.')
# diagnostics misc
g(0x40951e, 'cam_sync_position_lower_threshold_cal', 'fuel_pressure_sensor_second_too_high_threshold', 'Only reader is cm848_diagnoseFuelPressureGovernor: fuel_pressure_sensor above it sets diagnostic flag bit 1 (value 2), which the fuel limit function counts as a too-high bit with bit 0 (the 150-pass too-high threshold 3688 at 0x409516). The value 30738 is far above any rail pressure count (setpoint cap 3279, too-high threshold 3688), so it is an unreachable second limit here; "lower" was wrong and it is not EEPROM.')
g(0x3fd0ca, 'cam_timing_advance_table_interp_states', 'fuel_pressure_setpoint_interpolation_states', 'First of 16 consecutive interpolation state words 0x3fd0ca-0x3fd0e8, used only as the first argument of the setpoint calculator\'s table lookups and set to 2 by its init.')
for k in range(7):
    g(0x3fb6ce + 2 * k, 'cam_sync_filter_init_state_%d' % k, 'fuel_pressure_diagnostic_interpolation_state_%d' % k, 'word used only as the first argument of lookupTableInterpolation in cm848_diagnoseFuelPressureGovernor and set to 2 by cm848_initializeFuelPressureDiagnosticState.')

for addr, old, new, ev in G:
    row = ctx.byaddr.get(A(addr))
    if not row:
        problems.append('no row at ' + A(addr)); continue
    if row[1] != old:
        problems.append('name mismatch at %s: csv %s, mine %s' % (A(addr), row[1], old))
    recs.append({'kind': 'global', 'address': A(addr), 'old': old, 'verdict': 'confirmed', 'new': new, 'evidence': ev})

# ---------------------------------------------------------------- new globals (no row yet)
N = []
def n(addr, new, typ, ev): N.append((addr, new, typ, ev))
n(0x409aa0, 'fuel_pressure_governed_speed_check_enable', 'byte', 'ROM switch of the governed speed monitor (0 in the dump = off); read once, returns when 0. xref_addr.py says byte (1 read / 0 writes).')
n(0x409ac8, 'fuel_pressure_governed_speed_check_enable_override', 'byte', 'non-zero makes the enable flag take the override value instead of the computed conditions. xref: byte (1 read / 0 writes).')
n(0x409acc, 'fuel_pressure_governed_speed_check_enable_override_value', 'byte', 'value used for the enable flag while the override byte is set (1 in the dump). xref: byte (1 read).')
n(0x409aaa, 'fuel_pressure_governed_speed_check_injection_quantity_maximum', 'word', 'total_injection_quantity must be below it (736 = 50 mm3 per stroke); same role as fuel_pressure_check_injection_quantity_maximum for the other checks. xref: word (1 read).')
n(0x409ac9, 'fuel_pressure_governor_demand_plausibility_check_enable_override', 'byte', 'check A: non-zero (with the check enabled) makes the enabled flag take the override value. xref: byte (1 read).')
n(0x409acd, 'fuel_pressure_governor_demand_plausibility_check_enable_override_value', 'byte', 'check A override value. xref: byte (1 read).')
n(0x409aca, 'fuel_pressure_allowed_decay_check_enable_override', 'byte', 'check B: non-zero (with the check enabled) makes the debounce reached flag take the override value. xref: byte (1 read).')
n(0x409ace, 'fuel_pressure_allowed_decay_check_enable_override_value', 'byte', 'check B override value. xref: byte (1 read).')
n(0x40b908, 'fuel_pressure_governed_speed_check_above_limit_flag', 'byte', 'write-only copy of (limit < fuel_pressure_governor_demand) at the end of the governed speed monitor. xref: byte (0 reads / 1 write).')
n(0x40b902, 'fuel_pressure_allowed_decay_below_model_flag', 'byte', 'write-only copy of (fuel_pressure_feedback_filtered < allowed decay model) at the end of check B. xref: byte (0 reads / 1 write).')
n(0x40b8dc, 'fuel_pressure_allowed_decay_model_copy', 'word', 'write-only copy of fuel_pressure_allowed_decay_model at the end of check B. xref: word (0 reads / 1 write).')
n(0x40b90c, 'fuel_metering_feedback_below_minimum_flag', 'byte', 'write-only copy of (fuel_metering_feedback_input < fuel_metering_feedback_minimum_expected) at the end of the feedback monitor. xref: byte (0 reads / 1 write).')
n(0x409aba, 'fuel_pressure_governor_demand_residual_override', 'word', 'non-zero (41 in the dump) replaces the live residual in fuel_pressure_governor_demand_residual_effective. xref: word (1 read).')
n(0x409abc, 'fuel_pressure_governor_demand_threshold_addend', 'word', 'constant added to fuel_pressure_governor_demand_threshold (0 in the dump). xref: word (1 read).')
n(0x409aa3, 'fuel_metering_feedback_monitor_enable', 'byte', 'ROM switch of the feedback monitor (1 in the dump); the function returns when it is 0. xref: byte (1 read).')
n(0x409ab6, 'fuel_metering_feedback_monitor_pressure_error_upper_limit', 'i16', 'the monitor runs only while (fuel_pressure_setpoint - fuel_pressure_feedback_filtered) is below it (+61 counts, signed compare). xref: word (1 read).')
n(0x409ab8, 'fuel_metering_feedback_monitor_pressure_error_lower_limit', 'i16', 'the same error must be above it (-61 counts, signed compare). xref: word (1 read).')
n(0x40b8c4, 'fuel_pressure_setpoint_deadband_active_flag', 'word', '1 while engine_rpm_measured is below DAT_00409a82 (12000 = 1500 rpm) and fuel_demand_computed below DAT_00409a80 (736 = 50 mm3), i.e. the dead band result is used; write-only. xref: word (0 reads / 1 write).')
n(0x40b8c6, 'fuel_pressure_setpoint_rise_limited_flag', 'word', 'written with (previous setpoint + rise limit < new value), i.e. the rise limit clipped the setpoint; write-only. xref: word (0 reads / 1 write).')
n(0x40b8c8, 'fuel_pressure_setpoint_override_additive_flag', 'word', 'written with (fuel_pressure_setpoint_override_mode = 2), the mode in which the override value is added; write-only. xref: word (0 reads / 1 write).')
n(0x409a78, 'fuel_pressure_setpoint_rise_limit', 'word', 'added to the previous setpoint to give the highest allowed new value (3893 counts per pass: no practical limit). xref: word (1 read).')
n(0x409a80, 'fuel_pressure_setpoint_deadband_fuel_quantity_limit', 'word', 'fuel_demand_computed must be below it (736 = 50 mm3) for the dead band. xref: word (1 read).')
n(0x409a82, 'fuel_pressure_setpoint_deadband_engine_speed_limit', 'word', 'engine_rpm_measured must be below it (12000 = 1500 rpm) for the dead band. xref: word (1 read).')
n(0x409a86, 'fuel_pressure_setpoint_cranking_minimum', 'word', 'setpoint (307 counts) used in the cranking / below-trigger cold start phases when the computed value is below it. xref: word (1 read).')
n(0x409a6a, 'fuel_pressure_setpoint_running_minimum', 'word', 'the minimum setpoint (512 counts) in the other phases. xref: word (1 read).')
n(0x409a7a, 'fuel_pressure_setpoint_maximum', 'word', 'clamp of the setpoint (3279 counts = 160 MPa), sets winning term code 14. xref: word (1 read).')
n(0x409a88, 'fuel_pressure_setpoint_governor_speed_limit_value', 'word', 'setpoint (2869 counts) returned at once while governor_speed_limit_mode is 1. xref: word (1 read).')
n(0x409a71, 'fuel_pressure_setpoint_term_combination_mode', 'byte', '0 = sum of the terms (winning term code 7), 1 = lower of the map and the limit terms (1 in the dump). xref: byte (1 read).')
n(0x409a7c, 'fuel_pressure_setpoint_offset_minimum_coolant_temperature', 'i16', 'the offset table term applies only above it (11520 = 180 F, signed compare against coolant_temp) in governor modes 16 / 50 / 58. xref: word (1 read).')
n(0x409a7e, 'fuel_pressure_setpoint_offset_minimum_intake_manifold_temperature', 'i16', 'same gate on intake_manifold_temperature_sensor_filtered (4480 = 70 F). xref: word (1 read).')
n(0x40953e, 'fuel_pressure_setpoint_fault_reaction_cap', 'i16', 'cap of fuel_pressure_setpoint while fault_reaction_request_bits bit 2 is set (4095 = no cap here); winning term code 15. xref: word (1 read, signed compare).')
n(0x408980, 'fuel_quantity_limit_rail_pressure_shortfall_debounce_limit', 'word', 'passes of shortfall before the limit arms (2500). xref: word (1 read; used only by cm848_limitFuelQuantityOnRailPressureShortfall).')
n(0x408982, 'fuel_quantity_limit_rail_pressure_shortfall_ramp_step', 'word', 'ramp decrement per pass (1). xref: word (1 read).')
n(0x408984, 'fuel_quantity_limit_rail_pressure_shortfall_threshold', 'word', 'setpoint minus sensor pressure that counts as a shortfall (512 counts = 25 MPa). xref: word (1 read).')
n(0x40ba66, 'fuel_pressure_setpoint_not_reached_error_per_pass', 'i16', '(fuel_pressure_setpoint - fuel_pressure_feedback_previous) / DAT_00409fdc per pass, signed, added to the accumulator. xref: word (0 reads / 1 write).')
n(0x3fb6cc, 'fuel_metering_feedback_interpolation_state', 'word', 'first argument of the feedback linearization lookup in cm848_updateFuelPressureDiagnosticCountersAndCheckFeedbackCircuit, set to 2 by cm848_initializeFuelPressureDiagnosticState. xref: word (0 reads / 1 write, address also taken by the lookup).')
for addr, new, typ, ev in N:
    if ctx.byaddr.get(A(addr)):
        problems.append('new_global has a row already: ' + A(addr) + ' ' + ctx.byaddr[A(addr)][1]); continue
    recs.append({'kind': 'new_global', 'address': A(addr), 'new': new, 'type': typ, 'evidence': ev})

# ---------------------------------------------------------------- struct fields
for old, new, src in [
    ('diagnostic_word_1', 'fuel_metering_feedback', 'fuel_metering_feedback_input'),
    ('diagnostic_byte_3', 'fuel_metering_feedback_fault', 'fuel_metering_feedback_fault_code'),
    ('diagnostic_byte_4', 'fuel_pressure_diagnostic', 'fuel_pressure_diagnostic_snapshot'),
    ('diagnostic_word_2', 'fuel_pressure_sensor_voltage', 'fuel_pressure_sensor_volts'),
    ('diagnostic_word_3', 'fuel_pressure_setpoint', 'fuel_pressure_setpoint')]:
    recs.append({'kind': 'struct_field', 'struct': 'fault_entry_t', 'old': old, 'new': new,
                 'evidence': 'hpcr_setFaultActiveStatus stores %s into this field when it captures the freeze frame (both the ring copy at DAT_003fe818.. and the fault entry copy).' % src})

# ---------------------------------------------------------------- notes
NOTES = [
 'Fault decode (checked against the ROM image): the slot table at 0x5985a holds 16-bit slot numbers (one word per fault bit n), obd_dtc_code_table (0x5b57c) holds the code word per slot. Fault 57 = slot 162 = P1221, 58 = 163 = P1222, 60 = 164 = P1223, 59 = slot 158 (code word 0000); faults 69 / 70 / 71 (word 4 bits 5 / 6 / 7) decode to the same three codes but no direct writer of masks 0x20 / 0x40 / 0x80 of fault_detected_bits_64_to_79 exists in the decompiled C. 303 = P0088, 304 = P0193, 305 = P0192, 333 = P0251, 408 / 409 = slot 91 = P0148 (the SAE fuel delivery error code, consistent with a rail pressure tracking monitor); faults 264, 265, 290, 315, 316, 317, 323, 324 and 352 have slot 170 (no OBD code). What the code shows for the three codes: P1221 = governor demand above 283 at governed speed (monitor disabled here), P1222 = demand above the pressure-based plausibility limit with no fuel injected (check A), P1223 = fuel metering feedback below the minimum expected for the demand; their official titles are not established from the code.',
 'Comment fix for fault_reaction_request_bits (0x40b8a0): bit 2 caps fuel_pressure_setpoint at fuel_pressure_setpoint_fault_reaction_cap (4095 = no cap here), not cam_timing_measured; bits 0 / 1 cap governor_fuel_limit_source / torque_fuel_minimum_working (cm848_applyFuelLimitsForFuelPressureFaults), bit 3 requests logical output 54. In this calibration only fault 352 has a reaction mask (5 = bits 0 and 2) and its caps (5888 and 4095) are inactive, so the reaction path has no effect.',
 'Calibration state of this ECM (RAM dump): the governed speed monitor is off (0x409aa0 = 0), check B is off, both feedback circuit checks cannot trigger (high threshold 4092 with command limit 0, low threshold 0), injector class d cannot set faults (debounce limit 65535), and engine_sync_enable_mask = 156 enables only faults 333 / 304 / 305 / 303 as limp home triggers.',
 'Injector diagnostic family (resolves the wave 1 uncertain row 0x0040b8cc): cm848_readInjectorDiagnosticWord clocks in 24 bits, cm848_updateInjectorDiagnosticBits turns them into four per-injector bit bytes at 0x40b8cc-0x40b8cf, and cm848_evaluateInjectorDiagnosticFault debounces them into fault bits listed in the table at 0x57d76 (rows of 10 bytes: mask, class a, c, b, d fault): a = P0201-P0206, b / c = P2146 (injectors 1, 3, 5 group) / P2149 (2, 4, 6 group), d = faults 270 / 273 / 276 / 279 / 282 / 285 with no OBD slot. The monitors\' "no related fault" gate is the four bytes being zero. The class debounce counters are the words 0x3fb6fc (a), 0x3fb6fe (c), 0x3fb700 (b), 0x3fb702 (d), reached only through the pointer argument, so xref cannot confirm them; suggested injector_diagnostic_bits_a_debounce_count and so on.',
 'cm848_runOperatingModeSpeedGovernor (reads fuel_pressure_setpoint at 0xf75c): name kept, not verified in full (565 lines). Its rows cam_timing_correction_high_cal (0x3ff6a2 = 4), cam_timing_correction_low_cal (0x3ff6a4 = 2), cam_timing_correction_high_b_cal (0x3ff6a6 = 44) and cam_timing_correction_low_b_cal (0x3ff6a8 = 29) are not cam timing: they are a per-pass step by which fuel_demand_integrator_max is lowered and an offset subtracted from fuel_demand_base_offset to form its ceiling, the high pair chosen while (fuel_pressure_setpoint - fuel_pressure_feedback_filtered) is above fuel_pressure_error_threshold (0xfecd = -307, signed), the low pair otherwise. They lie at 0x3ff6xx, outside the EEPROM range, so the _cal suffix is wrong. Not renamed: the integrator role needs a pass over the governor.',
 'hpcr_setFaultActiveStatus (0x1df64, reads fuel_pressure_setpoint at 0x1e098 / 0x1e1ac): the name fits (it sets a fault active and captures the freeze frame). Its capture also shows more wrong fault_entry_t field names, all direct assignments: torque_limit = main_injection_timing, load_throttle = fuel_demand_computed, pressure_adj = governor_mode_code (byte), timing_snapshot (dword) = key_on_hour_meter, sensor_scale_1 / sensor_scale_2 = diagnostic_fault_flags_a / _b.',
 'Support relations: cm848_initTimerInterrupts (0x5371f4) also clears fault 352 and initializes the setpoint-not-reached monitor variables (hpcr_cam_diag_active_flag, cssc_injection_diag_state), so it is the sibling of cm848_resetFuelPressureTrackingErrorMonitor for that monitor; its name was not checked. The engine speed gate of both tracking monitors reads engine_rpm_state_t.target_rpm (>= 4800 counts = 600 rpm), not current_rpm.',
 'Type notes: 0x409530 fuel_pressure_too_high_count_limit is typed word but xref_addr.py reports a byte read (value 150): it should be a byte. 0x409a6d fuel_pressure_setpoint_override_value is read as a word at an odd address (mode byte at 0x409a6c, value word at 0x409a6d), which is how the ROM block is packed. The 16 + 13 interpolation state words (0x3fd0ca-0x3fd0e8 for the setpoint calculator, 0x3fd0ea-0x3fd102 for the monitors) would be better as two arrays (word[16] and word[13]); the 7 + 1 words at 0x3fb6cc-0x3fb6da likewise.',
 'protection_fuel_demand_* family: only 0x40b52c / 0x40b52e / 0x40b530 / 0x3fcea8 (already renamed) belong to the limiter; the limiter constants 0x408980 / 0x408982 / 0x408984 are in the new_global rows. fuel_demand_load_axis (0x40a4ea) is the ramp start but is also read elsewhere, so it stays. protection_config_flags_b (0x3fd5a8, bit 1 enables the limiter) is in the EEPROM mirror and would need _cal and a subject once its other bits are known.',
]
for t in NOTES:
    recs.append({'kind': 'note', 'text': t})


# ---- advisor fixes: uncertain rows
UNC = {
 'fuel_metering_fault_minimum_fuel_limit': ('0x00409536', 'ROM copy (20000), not EEPROM so no _cal: the second limit for fault 264 / 333 that cm848_applyFuelLimitsForFuelPressureFaults applies to torque_fuel_minimum_working (lowest wins; cm848_selectTorqueLimit compares it with torque_limit_arb_t.fuel_minimum as source 7; default torque_limit_fuel_minimum = 30000). Its unit is not the fuel limit unit (5888 maximum), so "minimum fuel limit" is not supported. Candidate once the unit is settled: fuel_metering_fault_torque_limit.'),
 'fuel_pressure_sensor_fault_minimum_fuel_limit': ('0x00409534', 'ROM copy (20000): same second limit for P0193 / P0192 (faults 304 / 305); see 0x409536. Candidate: fuel_pressure_sensor_fault_torque_limit.'),
 'fault_reaction_minimum_fuel_limit': ('0x00409540', 'ROM copy (30400, above the 30000 default, so inactive): same second limit while fault_reaction_request_bits bit 1 is set; see 0x409536. Candidate: fault_reaction_torque_limit.'),
 'fuel_pressure_too_high_minimum_fuel_limit': ('0x00409548', 'ROM copy (20000): same second limit while P0088 (fault 303) is registered; see 0x409536. Candidate: fuel_pressure_too_high_torque_limit.'),
}
for r in recs:
    if r.get('new') in UNC:
        a, ev = UNC[r['new']]
        r['verdict'] = 'uncertain'; r['evidence'] = ev; r.pop('new')
for r in recs:
    if r.get('address') == '0x0040951e':
        r['verdict'] = 'uncertain'; r.pop('new', None)
        r['evidence'] = 'Same finding as wave 1 plus one fact: diagnostic flag value 2 (set when fuel_pressure_sensor is above this word, 30738 in the dump) is counted like bit 0 as a too-high bit by cm848_applyFuelLimitsForFuelPressureFaults (logical output 54 request when its enable word is non-zero). The limit cannot be reached (setpoint cap 3279, too-high threshold 3688), so why the calibration carries it is still open. RAM copy of ROM: no _cal. Candidate if accepted: fuel_pressure_sensor_second_too_high_threshold.'
recs.append({'kind': 'note', 'text': 'Spelled initialize (not the repo usual init) in cm848_initializeFuelPressureSetpointState / cm848_initializeFuelPressureGovernorMonitorState / cm848_initializeFuelPressureDiagnosticState to follow the no-abbreviation rule; rename them to init if the repo convention wins.'})

# ---------------------------------------------------------------- validation
existing = set(ctx.rows) | set(ctx.frows)
try:
    for r in csv.reader(open(R + 'arrays.csv')):
        for c in r[:3]:
            if re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', c): existing.add(c)
except Exception as e:
    problems.append('arrays.csv not read: %s' % e)
names = {}
bad_abbrev = {'diag', 'prot', 'temp', 'pres', 'qty', 'corr', 'cfg', 'ctrl', 'mgr', 'cnt', 'val', 'idx', 'tmp', 'req', 'thr', 'dly', 'lim', 'cal', 'ref', 'num', 'sel', 'cmd', 'misc', 'init'}
for r in recs:
    nm = r.get('new')
    if r['kind'] in ('function', 'global', 'new_global') and nm:
        if nm in names: problems.append('duplicate proposal ' + nm)
        names[nm] = 1
        if nm in existing: problems.append('exists already: ' + nm)
        if r['kind'] == 'function':
            if not re.match(r'^cm848_[a-z][A-Za-z0-9]*$', nm): problems.append('bad function shape ' + nm)
        else:
            if not re.match(r'^[a-z][a-z0-9]*(_[a-z0-9]+)*$', nm): problems.append('bad global shape ' + nm)
            if any(t in bad_abbrev for t in nm.split('_')): problems.append('abbreviation token in ' + nm)
            if '0x' in nm: problems.append('hex in ' + nm)
            if re.search(r'(^|_)protection(_|$)', nm): problems.append('bare protection ' + nm)
        # all-caps words or camel tokens in function: check tokens for abbreviations
        if r['kind'] == 'function':
            toks = re.findall(r'[A-Z][a-z0-9]*|[a-z0-9]+', nm[6:])
            for t in toks:
                if t.lower() in bad_abbrev: problems.append('abbreviation token %s in %s' % (t, nm))

with open(OUT, 'w') as f:
    for r in recs:
        f.write(json.dumps(r) + '\n')
from collections import Counter
print(Counter(r['kind'] for r in recs))
print('verdicts', Counter(r.get('verdict') for r in recs if r['kind'] in ('function', 'global')))
print('PROBLEMS:', len(problems))
for p in problems: print('  ', p)
# each line parses
for l in open(OUT):
    json.loads(l)
print('lines ok')
