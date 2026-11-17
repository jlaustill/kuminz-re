import csv
import json
import re
import sys

sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/scratch_W5_load')
import cluster_globals as C  # noqa: E402

FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/'
OUT = FW + 'output/'
RESULT = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W5_load.jsonl'
P = 'variable_geometry_turbocharger_'

# ---------------------------------------------------------------- globals: key, address, old, new suffix, evidence
G = [
    # sensor channel 101 words
    ('pos_value', 0x40bdb6, 'protection_channel_filtered_output', 'position_sensor_value',
     'code: value output (arg 11) of sensor channel 101 in cm848_protection_init/update_configBundle, 8 reads / 0 writes, only ever compared with 12800 or learned references, never with engine speed; with the dump overrides 1693 x 12800 / (12800 - 1920) = 1991 = adjusted position and actuator_e_feedback. e2m: VGT_Position_Sensor (0x01196636, vgt position sensor output) is the word after VGT_Position_Default at the same +2 as 0x40bdb6 after 0x40bdb4; the offset map is validated by the independent boost pair (0x0119660E / 0x01196626 = Charge_Press_Sensor / Default = 0x40bd8e / 0x40bda6).'),
    ('pos_default', 0x40bdb4, 'protection_derate_fallback_speed', 'position_sensor_default_value',
     'code: default value output (arg 12, copy of the channel config word 0x2400 = 9216 = 72 percent at 12800 = 100 percent) substituted for the position when the sensor status, a span adjustment error or the position control error is set; read only by cm848_calculateDiagnosticStatusBits; not a speed. e2m: VGT_Position_Default (0x01196634, VGT_Postion AD global default value).'),
    ('pos_status', 0x40be2e, 'protection_fault_condition_value', 'position_sensor_fault_status',
     'code: status output (arg 13) of sensorChannelConfigInit: 0 valid, 1 fault clearing (value held), 2 fault active (default substituted), 256 channel disabled; same word as the other <sensor>_fault_status words. e2m: none, offset-independent.'),
    # fault words
    ('fd656', 0x3fe9c6, 'governor_status_flags', None,
     'code: word 41 of the fault-detected array 0x3fe974 (0x3fe9c6 - 0x3fe974 = 82 = 41 words); its mask 16384 / 32768 are faults 670 / 671, the closed / span adjustment errors set and cleared by the adjustment stages and read by the actuator E setpoint clamp and the position-source check; the old engine-load comment is wrong. e2m: 0x01103652 holds VGT_Closed_Adjustment_Error / VGT_Span_Adjustment_Error at those masks.'),
    ('fd672', 0x3fe9c8, 'governor_diag_status_bits_b', None,
     'code: word 42 of the fault-detected array; the position sensor passes fault 682 (mask 1024) and 683 (mask 2048) as high_fault_bit / low_fault_bit (index >> 4 = 42, bit & 15 = 10 / 11); never written directly, read by cm848_updateLoadProtectionStatusAndDerate. e2m: none needed.'),
    ('fd704', 0x3fe9cc, 'diagnostic_status_bits_b', None,
     'code: word 44 of the fault-detected array (0x3fe9cc - 0x3fe974 = 88); masks 32 / 64 (faults 709 / 710) are set from sensor faults 682 / 683 by cm848_updateLoadProtectionStatusAndDerate and cleared when the module is disabled. e2m: 0x01103658 VGT_Position_PP_High_Error / PP_Low_Error at masks 32 / 64.'),
    ('fd736', 0x3fe9d0, 'diagnostic_status_flags', None,
     'code: word 46 of the fault-detected array (92 bytes from 0x3fe974); written by the bridge fault handler (masks 4 to 64 and 256), the position control monitor (128), the driver over-current check (512) and the temperature estimate (1024), read by 15 functions. e2m: 0x0110365C holds VGA_Fault_HB0A.. / VGA_Control_Error / VGA_Electrical_Fault / VGA_Driver_Over_Current / VGA_Over_Temperature at exactly these masks.'),
    ('fr656', 0x3fea2a, 'governor_status_flags_shadow', None,
     'code: word 41 of the registered array 0x3fe9d8 (0x3fe9d8 + 82); cleared together with the detected bit by the generic sensor channel code and by the two adjustment stages.'),
    ('fr704', 0x3fea30, 'protection_condition_shadow_flags', None,
     'code: word 44 of the registered array (0x3fe9d8 + 88); cleared with masks 32 / 64 of the detected word in the same functions.'),
    ('fr736', 0x3fea34, 'j1939_comm_status_flags', None,
     'code: word 46 of the registered array (0x3fe9d8 + 92), cleared with the detected word 736 to 751 at every site (e.g. cm848_clearDiagnosticConditionFlags, the over-current check).'),
    # ROM-copied calibration words (no _cal outside the EEPROM mirror)
    ('gap', 0x4077de, 'protection_ema_base_offset_cal', 'closed_stop_gap',
     'code: subtracted from the span in the divisor of the position calculation; dump 1920 = 15 percent of 12800 and 1693 x 12800 / (12800 - 1920) = 1991 reproduces the dump position. e2m: C_VGT_Closed_Stop_Gap (0x011A3900, percentage of nominal span from the closed stop where 100 percent position occurs) is +0x00 of the nine-word block that maps to 0x4077de.'),
    ('span_decrement', 0x4077e2, 'protection_load_filter_offset_cal', 'span_key_on_decrement',
     'code: subtracted once from the held span on the first pass after boot (the key-on pending flag is set by init), dump 0. e2m: C_VGT_Span_Fail_Decrement (0x011A3904, decreased value of span at key on) is +0x04.'),
    ('span_override_value', 0x4077e4, 'protection_load_filtered_override_cal', 'span_override_value',
     'code: replaces the adjusted span when the span override flag is set (it is, in the dump: 12800). e2m: C_VGT_Span_User_Override_Val (0x011A3906) is +0x06.'),
    ('span_tolerance', 0x4077e6, 'protection_rpm_confirm_cal', 'span_tolerance',
     'code: half-width of the accepted span window around 12800 (span out of tolerance test), floor of the span filter (12800 - 3200 = 9600, the value held in EEPROM) and the open-stop reading window; not an rpm. e2m: C_VGT_Span_Adjustment_Tolerance (0x011A3908, max span tolerance before a span adjust error) is +0x08.'),
    ('closed_override_value', 0x4077e8, 'protection_ema_output_override_cal', 'closed_position_override_value',
     'code: replaces the closed position when the closed-position override flag is set (it is: 12800). e2m: C_VGT_Closed_Pos_Override_Val (0x011A390A) is +0x0A.'),
    ('adjust_enable_time', 0x4077ea, 'load_protection_confirm_delay_limit', 'adjustment_delay_time',
     'code: limit of both delay counters (closed and span adjustment); dump 0. e2m: C_VGT_Pos_Adjust_Enable_Time (0x011A390C, time delay between adjust enable and start of error counting, 0.005 s) is +0x0C.'),
    ('adjust_fault_time', 0x4077ec, 'load_protection_confirm_hysteresis_limit', 'adjustment_fault_time',
     'code: limit of both adjustment error counters (up while out of tolerance, down while inside); reaching it latches the error; dump 200. e2m: C_VGT_Pos_Adjustment_Fault_Time (0x011A390E) is +0x0E.'),
    ('filter_coefficient', 0x4077ee, 'load_protection_filter_coefficient', 'adjustment_filter_coefficient',
     'code: coefficient word pointed to by both the closed-position filter state and the span filter state (init sets both pointers to it); dump 55784. e2m: C_VGT_Pos_Adjustment_Fil_Cnst (0x011A3910) is +0x10.'),
    ('reset_speed', 0x40779a, 'governor_startup_rpm_threshold_cal', 'mission_reset_speed_threshold',
     'code: engine speed (x 0.125 rpm) the first 60 passes must reach to flag a mission reset: dump 4800 = 600 rpm; read by cm848_updateLoadProtectionWarmupTrigger (the only reader in the cluster). e2m: C_VGA_Mission_Reset_Speed (0x01183600, RPM 0.125, reset during mission detected if rpm above this shortly after key on) is the first word of the block that maps to 0x40779a. 0x40779a is ROM-copied, so no _cal.'),
    ('closed_drive_duty', 0x40779c, 'protection_confirm_mode3_fuel_output_cal', 'closed_stop_diagnostic_drive_duty',
     'code: copied each pass to the working word that actuator E mode 4 outputs; dump 3840 = +30 percent, a non-negative command sets logical output 71 (checked in the body; that 71 is the closing direction is e2m only). e2m: C_VGA_PWM_Closed_Diag_Value (0x01183602, PWM commanded at key on to force the valve against the closed stop) is +0x02. Not fuel.'),
    ('open_drive_duty', 0x40779e, 'protection_confirm_mode4_fuel_output_cal', 'open_stop_diagnostic_drive_duty',
     'code: copied each pass to the working word that cm848_selectActuatorEDriveByMode outputs in mode 3 (checked in the body); dump 61696 = -3840 as a signed word = -30 percent before the mode output limits (the type is unsigned, a type change is not proposed). e2m: C_VGA_PWM_Open_Diag_Value (0x01183604, PWM commanded at key on to force the valve against the open stop) is +0x04.'),
    ('active_time', 0x4077a0, 'fault_threshold_count_cal', 'adjustment_active_time',
     'code: limit of the two dwell counters that keep the closed-stop and open-stop drives on after the stop is reached; dump 0. e2m: C_VGA_Pos_Adjust_Active_Time (0x01183606, time allowed for adjustments after adjustment is enabled) is +0x06.'),
    ('retry_time', 0x4077a2, 'protection_confirm_limit_cal', 'stop_seek_retry_time',
     'code: limit of the two wait counters that end the closed-stop and open-stop seek by time-out when the sensor never reads near the stop; dump 2000. e2m: C_VGA_Pos_Adjustment_Retry_Time (0x01183608, max time the diagnostic hold PWMs are applied before adjustment is enabled) is +0x08.'),
    ('limit_over_temperature', 0x4077a4, 'governor_rpm_limit_fuel_b_default_cal', 'drive_duty_limit_over_temperature',
     'code: cm848_updateLoadProtectionArming selects it for the working duty limit while fault 746 (mask 1024 of fault_detected_bits_736_to_751, set by the winding temperature estimate) is set; dump 12800. e2m: C_VGA_Over_Tmptr_PWM_Limit (0x0118360A) is +0x0A of the block mapped to 0x40779a and VGA_Over_Temperature is mask 1024. Not an rpm limit.'),
    ('limit_over_current', 0x4077a6, 'governor_rpm_limit_fuel_b_diag_b_cal', 'drive_duty_limit_over_current',
     'code: selected for the working duty limit while fault 745 (mask 512, the driver over-current check) is set and 746 is clear; dump 12800. e2m: C_VGA_Over_Current_PWM_Limit (0x0118360C) is +0x0C and VGA_Driver_Over_Current is mask 512.'),
    ('limit_normal', 0x407768, 'governor_rpm_limit_diag_b_cal', 'drive_duty_limit_normal',
     'code: selected when neither fault 745 nor 746 is set; dump 12800. e2m: C_VGA_Compensated_PWM_Lim (0x0118304E) is +0x4E of the block whose +0x00 / +0x3C / +0x4C anchors are actuator_e_setpoint_override (0x40771a) / actuator_e_setpoint_upper_limit / actuator_e_end_margin.'),
    ('enable_flag', 0x40776e, 'governor_fuel_b_mode_flag', 'enable_flag',
     'code: xref: 9 reads, 0 writes, in the actuator E loop runner, the bridge fault handler, the adjustment sequencer / status / init functions, the over-current check and the three bank-2 monitors; nothing else reads it, so it enables the whole position-servo module (dump 1). e2m: C_VGA_Swingvane_Enable (0x01183054) is +0x54 of the same block.'),
    ('limit_working', 0x40b076, 'governor_rpm_limit_working', 'drive_duty_limit_working',
     'code: written by cm848_updateLoadProtectionArming from the three duty limits, read by cm848_calculateActuatorEDriveLimits to bound the drive command (12800 = 100 percent); not an rpm limit. e2m: VGA_PWM_Diagnostic_Limit (0x01183418) is +0x18 of the block that puts the mission-reset word at 0x40b05e + 4.'),
    # EEPROM-backed enables and saved values (_cal required)
    ('en_closed_adjust', 0x3fd8d2, 'fault_confirm_enable_flag', 'closed_adjustment_enable_cal',
     'code: the only reader (cm848_evaluateLoadProtectionFuelLowStage) uses it as the enable of the closed-stop drive; dump 0 (EEPROM 0x450). Inside the EEPROM mirror, so _cal; time-shared window, three boot ROM scans found no user. e2m: T_VGT_Closed_Adjustment_Enable (0x0119CC00, enables closed adjustment logic); the six T_ flags keep the e2m order.'),
    ('en_span_adjust', 0x3fd8d4, 'protection_confirm_overspeed_enable_flag', 'span_adjustment_enable_cal',
     'code: ANDed into the open-stop drive request and into ready-for-span-adjustment; dump 1 (EEPROM 0x452). _cal (EEPROM mirror); no boot ROM user. e2m: T_VGT_Span_Adjustment_Enable (0x0119CC02).'),
    ('en_give_up', 0x3fd8d6, 'governor_rate_limit_bypass_flag', 'driver_over_current_give_up_enable_cal',
     'code: in cm848_updateGovernorDemandRateProtection it keeps the clear / retry condition off once the second accumulator has reached its limit, i.e. gives up retrying; dump 0 (EEPROM 0x454). _cal (EEPROM mirror); no boot ROM user. e2m: T_VGA_Enable_Driver_OC_Give_Up (0x0119CD00, enables give up input to fault processing).'),
    ('en_span_override', 0x3fd8d8, 'protection_load_override_enable_flag', 'span_override_enable_cal',
     'code: selects variable_geometry_turbocharger_span_override_value as the working span; dump 1 (EEPROM 0x456). _cal (EEPROM mirror); no boot ROM user. e2m: T_VGT_Span_User_Override (0x011A3C00, override VGT_Adjusted_Span when TRUE).'),
    ('en_clear_error', 0x3fd8da, 'protection_confirm_mode_flag', 'adjustment_error_counter_clear_cal',
     'code: when set both adjustment error counters are forced to 0 each pass (two readers, the two latch functions); dump 0 (EEPROM 0x458). _cal (EEPROM mirror); no boot ROM user. e2m: T_VGT_Clr_Adjustment_Error_Cnt (0x011A3C02, clears span and closed adjustment error counters when set).'),
    ('en_closed_override', 0x3fd8dc, 'protection_ema_override_enable_flag', 'closed_position_override_enable_cal',
     'code: selects variable_geometry_turbocharger_closed_position_override_value as the closed position; dump 1 (EEPROM 0x45a). _cal (EEPROM mirror); no boot ROM user. e2m: T_VGT_Closed_Pos_User_Override (0x011A3C04).'),
    ('saved_span', 0x3fedde, 'protection_load_filtered', 'saved_span_cal',
     'code: written every pass by the span filter (floor value while fault 670 is set), read back as the filter start value by init and as the held span; EEPROM 0x195c = 9600 in all four EEPROM dumps and in the RAM dump. Inside the EEPROM mirror, so _cal; not in a time-shared window. e2m: T_VGT_Adjusted_Span (0x011A3B00, measured span saved at power down).'),
    ('saved_closed', 0x3fede0, 'protection_ema_output_snapshot', 'saved_closed_position_cal',
     'code: written every pass by the closed-position filter (12800 while fault 670 is set), read back by init to start the filter; EEPROM 0x195e = 12800 in all four dumps and the RAM dump. _cal (EEPROM mirror). e2m: T_VGT_Closed_Position (0x011A3B02, measured position saved at power down).'),
    # time-shared state words 0x3fb0xx
    ('t_motor_fault', 0x3fb070, 'protection_diagnostic_fault_flag', 'motor_fault_flag',
     'code: cm848_updateLoadProtectionArming sets it when any of faults 744 / 745 / 746 (masks 256 / 512 / 1024 of fault_detected_bits_736_to_751) is set; read by the same function to form the motor-ok flag. e2m: VGA_Electrical_Fault / Driver_Over_Current / Over_Temperature at those masks.'),
    ('t_spinning', 0x3fb072, 'fault_threshold_active_flag', 'engine_spinning_flag',
     'code: = (current_rpm != 0), computed in cm848_updateLoadProtectionArming ((-rpm) >> 31); read by the two stop-seek stages. e2m: see VGA_Transition_To_Not_Spinning.'),
    ('t_spinning_prev', 0x3fb082, 'fault_threshold_prev_flag', 'engine_spinning_previous_flag',
     'code: previous-pass copy of the engine-spinning flag, written at the end of the closed-stop stage.'),
    ('o_engine_stopped', 0x40b074, 'protection_threshold_exceeded_flag', 'engine_stopped_transition_flag',
     'code: set for one pass when the previous pass was spinning and this one is not; it clears the stop-seek latches and counters. e2m: VGA_Transition_To_Not_Spinning (0x01183416) is +0x16 of the block that anchors 0x40b05e.'),
    ('t_pos_fault_flags', 0x3fb074, 'protection_fault_condition_flag', 'position_fault_flags',
     'code: dword used as two words: word 0 = sensor fault status >= 2 or position control error (fault 743), word 1 = span adjustment error (fault 671); set in cm848_updateLoadProtectionArming, read by the open-stop stage and the position-source check. Typing (two words) is a note, not a type change.'),
    ('t_closed_err_snapshot', 0x3fb078, 'load_protection_confirm_a_snapshot', 'closed_adjustment_error_snapshot',
     'code: = fault 670 (mask 16384) of fault_detected_bits_656_to_671 sampled each pass; 2 writes, no read found by name-grep xref.'),
    ('t_fault_present', 0x3fb07a, 'protection_fault_sign_flag', 'position_sensor_fault_present_flag',
     'code: (-x & ~x) >> 31 of the sensor status word is 1 when the status is above 0 (fault clearing or active), not a sign test; gates the closed adjustment enable.'),
    ('t_holdoff_flags', 0x3fb07c, 'protection_governor_active_flag', 'fault_holdoff_flags',
     'code: dword used as two words: word 0 = sensor status above 0 or position control error, word 1 = 0 only while that fault has lasted fewer than 200 passes. Word 1 and the driver fault pending flag decide whether logical output 72 is requested (set in the normal state, dropped during the hold-off and while a bridge fault retry is pending). Typing is a note.'),
    ('t_holdoff_counter', 0x3fb080, 'protection_startup_counter', 'fault_holdoff_counter',
     'code: counts passes up to 200 while word 0 of the fault hold-off flags is set, else 0.'),
    ('t_closed_wait', 0x3fb084, 'protection_confirm_startup_counter', 'closed_stop_wait_counter',
     'code: counts passes since boot or the last engine stop up to the stop-seek retry time (2000 in the dump); the closed-stop seek ends by time-out when it reaches it.'),
    ('t_closed_dwell', 0x3fb086, 'fault_confirm_counter_a', 'closed_stop_dwell_counter',
     'code: counts passes after the closed stop is reached up to the adjustment active time; closed-stop drive stays on while it is below that limit.'),
    ('t_closed_reached', 0x3fb088, 'governor_startup_fuel_low_flag', 'closed_stop_reached_flag',
     'code: latched when |sensor value - 12800| < the closed position tolerance or the wait counter is at its limit; cleared at the engine stop transition. Not fuel.'),
    ('t_reset_latched', 0x3fb08a, 'protection_confirm_trigger_flag_b', 'mission_reset_latched_flag',
     'code: latches the mission reset flag (set once the 60-pass window saw 600 rpm), cleared at the engine stop transition; it switches the closed-stop drive off.'),
    ('t_reset_window', 0x3fb08c, 'governor_startup_warmup_timer', 'mission_reset_window_counter',
     'code: counts passes after boot up to 60; the mission reset can only be detected while it is below 60. Not a warm-up.'),
    ('t_open_wait', 0x3fb08e, 'load_protection_condition_absent_counter', 'open_stop_wait_counter',
     'code: counts passes up to the stop-seek retry time while there is no position fault and no closed-stop drive, reset otherwise; time-out of the open-stop seek.'),
    ('t_open_dwell', 0x3fb090, 'fault_confirm_counter_b', 'open_stop_dwell_counter',
     'code: counts passes after the open stop is reached up to the adjustment active time; keeps the open-stop drive on while below it.'),
    ('t_open_hold', 0x3fb092, 'fault_threshold_exception_flag', 'fault_open_hold_request_flag',
     'code: set while the closed-stop drive is off and a position fault or span error is present, cleared while the closed-stop drive runs; it requests the open-stop drive (the valve is held open after a fault). e2m: VGA_PWM_Open_Diag_Override (TRUE when fault processing requests hold open PWM).'),
    ('t_open_reached', 0x3fb094, 'governor_overspeed_threshold_flag', 'open_stop_reached_flag',
     'code: latched when the sensor is near the open stop or the wait counter is at its limit, cleared while a fault or the closed-stop drive is active. Not an overspeed.'),
    ('t_near_open', 0x3fb096, 'protection_rpm_below_confirm_flag', 'position_near_open_stop_flag',
     'code: |(closed position - sensor value) - 12800| < span tolerance, set by cm848_calculateLoadProtectionDeviationFlag; not an rpm test.'),
    ('t_status_intermediate', 0x3fb0a4, 'protection_diagnostic_status_intermediate', 'position_status_intermediate',
     'code: sensor fault status OR 8 when fault 671 (span adjustment error) is set (the typed local of the enum); read by the position-source check.'),
    ('t_span_delay_counter', 0x3fb0a6, 'load_protection_confirm_b_delay_counter', 'span_adjustment_delay_counter',
     'code: counts up while the span adjustment is active, limit = adjustment delay time.'),
    ('t_span_error_counter', 0x3fb0a8, 'load_protection_confirm_b_hysteresis_counter', 'span_adjustment_error_counter',
     'code: +1 per pass while the span is out of tolerance and the delay has elapsed, -1 otherwise, limit = adjustment fault time (200); forced to 0 by the clear-error calibration.'),
    ('t_span_out', 0x3fb0aa, 'protection_condition_active_flag', 'span_out_of_tolerance_flag',
     'code: |(closed position - sensor value) - 12800| >= span tolerance, set by cm848_evaluateLoadProtectionLiveStage.'),
    ('t_span_latched', 0x3fb0ac, 'load_protection_confirm_b_latched_flag', 'span_adjustment_error_latched_flag',
     'code: set when the span error counter reaches its limit, cleared when it returns to 0; drives fault 671.'),
    ('t_span_delay_elapsed', 0x3fb0ae, 'load_protection_confirm_b_delay_elapsed_flag', 'span_adjustment_delay_elapsed_flag',
     'code: delay limit == delay counter; with the dump limit 0 it is 1 even while the adjustment is not active.'),
    ('t_span_error_snapshot', 0x3fb0b0, 'load_protection_confirm_b_hysteresis_counter_snapshot', 'span_adjustment_error_counter_snapshot',
     'code: copy of the span error counter written each pass; no reader found by name-grep xref.'),
    ('t_span_meas', 0x3fb0b2, 'protection_ema_delta_working', 'span_measurement',
     'code: closed position minus sensor value (dump 12800 - 1693 = 11107); feeds the span filter while valid.'),
    ('t_span_valid', 0x3fb0b4, 'protection_ema_exceeded_flag', 'span_measurement_valid_flag',
     'code: span inside the tolerance window and the span delay elapsed; selects the filter input in cm848_updateLoadProtectionLoadFilter.'),
    ('t_span_filter_state', 0x3fb0b6, 'load_protection_filter_state', 'span_filter_state',
     'code: ema_filter_state_t of the span filter; init sets accumulator = saved span << 16 and the coefficient pointer.'),
    ('t_span_decrement_pending', 0x3fb0be, 'protection_load_filter_active_flag', 'span_key_on_decrement_pending_flag',
     'code: set by init, cleared on the first pass of the span filter; makes the key-on decrement apply once.'),
    ('t_closed_unsettled', 0x3fb0c0, 'protection_condition_b_active_flag', 'closed_stop_unsettled_flag',
     'code: closed-stop drive on and the closed reading not valid.'),
    ('t_closed_timeout', 0x3fb0c2, 'protection_confirm_active_flag', 'closed_adjustment_timeout_error_flag',
     'code: latched when the closed-stop drive ends while the closed reading is still not valid; cleared when the drive starts again; with the latch it sets fault 670.'),
    ('t_closed_delay_counter', 0x3fb0c4, 'load_protection_confirm_a_delay_counter', 'closed_adjustment_delay_counter',
     'code: counts up while the closed adjustment is enabled, limit = adjustment delay time.'),
    ('t_closed_error_counter', 0x3fb0c6, 'load_protection_confirm_a_hysteresis_counter', 'closed_adjustment_error_counter',
     'code: +1 per pass while the sensor is outside the closed position tolerance and the delay has elapsed, -1 otherwise, limit 200; the dump has 200 with the adjustment disabled (delay limit 0).'),
    ('t_closed_out', 0x3fb0c8, 'fuel_control_setpoint_exceeded_flag', 'closed_position_out_of_tolerance_flag',
     'code: |12800 - sensor value| >= actuator_e_end_margin; not a setpoint test.'),
    ('t_closed_latched', 0x3fb0ca, 'load_protection_confirm_a_latched_flag', 'closed_adjustment_error_latched_flag',
     'code: set when the closed error counter reaches 200, cleared at 0; with the time-out flag drives fault 670.'),
    ('t_closed_delay_elapsed', 0x3fb0cc, 'load_protection_confirm_a_delay_elapsed_flag', 'closed_adjustment_delay_elapsed_flag',
     'code: delay limit == delay counter (true at 0 == 0 in the dump).'),
    ('t_closed_error_snapshot', 0x3fb0ce, 'load_protection_confirm_a_hysteresis_counter_snapshot', 'closed_adjustment_error_counter_snapshot',
     'code: copy of the closed error counter; no reader found by name-grep xref.'),
    ('t_closed_valid', 0x3fb0d0, 'protection_ema_condition_flag', 'closed_position_valid_flag',
     'code: sensor inside the closed tolerance window and the delay elapsed; the closed-position filter follows the sensor only while it is set.'),
    ('t_closed_coeff_ptr', 0x3fb0d2, 'fault_status_filter_coeff_b_ptr', 'closed_position_filter_coefficient_pointer',
     'code: first half of the closed-position filter state passed to cm848_signedFirstOrderFilter (coefficient pointer set by init). Typing (ema_filter_state_t split in two globals) is a note.'),
    ('t_closed_acc', 0x3fb0d6, 'protection_ema_output_shifted', 'closed_position_filter_accumulator',
     'code: second half of that filter state; init loads it from the saved closed position << 16. Dump 0x2a8f5000 = 10895.3, not explained by the hold logic (the saved word is 12800, and the filter can only follow the sensor inside 10944..14656).'),
    # output words 0x40b0xx
    ('o_closed_adjust_enable', 0x40b060, 'protection_confirm_active_a', 'closed_adjustment_enable_flag',
     'code: (feature bit set) and no sensor fault above 0 and ready-for-closed-adjustment; enables the closed delay counter. e2m: VGA_Closed_Adjustment_Enable (0x01183402) is +0x02 of the block that anchors 0x40b05e.'),
    ('o_reset_detected', 0x40b062, 'protection_confirm_trigger_flag', 'mission_reset_detected_flag',
     'code: warm-up window below 60 passes and current_rpm >= the mission reset speed. e2m: VGA_Mission_Reset_Detected (0x01183404) is +0x04.'),
    ('o_motor_ok', 0x40b064, 'protection_confirm_active_b2', 'motor_ok_flag',
     'code: no motor fault flag and no pending bridge fault; gates the span adjustment. e2m: VGA_Motor_OK (0x01183406) is +0x06.'),
    ('o_closed_drive', 0x40b066, 'fault_threshold_condition_flag', 'closed_stop_diagnostic_drive_flag',
     'code: dwell counter below the active time, no mission reset latched and the closed adjustment enabled; actuator E mode 4 (fixed +30 percent) while it is set. e2m: VGA_PWM_Closed_Diag_Override (0x01183408) is +0x08.'),
    ('o_closed_duty_w', 0x40b068, 'governor_fuel_output_mode4_working', 'closed_stop_diagnostic_drive_duty_working',
     'code: copy of the closed-stop drive duty calibration written each pass (3840 in the dump). e2m: VGA_PWM_Closed_Diag_Value (0x0118340A) is +0x0A.'),
    ('o_open_drive', 0x40b06a, 'throttle_speed_rate_cal', 'open_stop_diagnostic_drive_flag',
     'code: written every pass by the open-stop stage and selecting actuator E mode 3 (duty -3840 before the mode output limits); RAM word, so the _cal suffix was wrong. e2m: VGA_PWM_Open_Diag_Override (0x0118340C) is +0x0C.'),
    ('o_open_duty_w', 0x40b06c, 'governor_fuel_output_mode3_working', 'open_stop_diagnostic_drive_duty_working',
     'code: copy of the open-stop drive duty calibration (-3840 as a signed word). e2m: VGA_PWM_Open_Diag_Value (0x0118340E) is +0x0E.'),
    ('o_ready_closed', 0x40b06e, 'protection_confirm_enable_a', 'ready_for_closed_adjustment_flag',
     'code: closed stop reached and the closed-stop drive still on. e2m: VGA_Ready_For_Closed_Adjust (0x01183410) is +0x10.'),
    ('o_ready_span', 0x40b070, 'protection_confirm_enable_b', 'ready_for_span_adjustment_flag',
     'code: span adjustment enabled and the open stop reached. e2m: VGA_Ready_For_Span_Adjust (0x01183412) is +0x12.'),
    ('o_span_enable', 0x40b072, 'throttle_rate_active_flag', 'span_adjustment_enable_flag',
     'code: feature bit, no closed adjustment error (fault 670 clear), ready for span adjustment and motor ok; enables the span adjustment stage. e2m: VGA_Span_Adjustment_Enable (0x01183414) is +0x14. Not a throttle flag.'),
    ('o_source', 0x40b096, 'governor_speed_tracking_mode', 'position_source',
     'code: 0 when the adjusted position is used, 2 when the sensor default is used (written only by cm848_calculateDiagnosticStatusBits). e2m: VGT_Position_Source (0x0119D202; 0 primary, 2 default).'),
    ('o_adjusted', 0x40b098, 'protection_speed_tracking_target', 'position_adjusted',
     'code: ((sensor value - closed position) + span) x 12800 / (max(span, 12800 - tolerance) - gap) clamped to +-12800, dump 1991; the position, not a speed. e2m: VGT_Position_AP (0x0119D204, VGT position autozeroed).'),
    ('o_span_adjusted', 0x40b09a, 'protection_load_filtered_working', 'span_adjusted',
     'code: filtered span or the span override value; the span used by the position calculation (dump 12800). e2m: VGT_Adjusted_Span (0x0119D206).'),
    ('o_span_filtered', 0x40b09c, 'protection_load_filtered_prev', 'span_filtered',
     'code: output of the span filter before the fault-670 floor and the override (dump 11107 = 12800 - 1693). e2m: VGT_Filtered_Span (0x0119D208).'),
    ('o_span_active', 0x40b09e, 'protection_confirm_active_b', 'span_adjustment_active_flag',
     'code: span adjustment enabled and (open-stop drive on or zero-setpoint hold); arms the span delay counter.'),
    ('o_status', 0x40b0a0, 'protection_diagnostic_status', 'position_status',
     'code: sensor fault status | 8 (span or closed adjustment error) | 32 (position control error), built by cm848_calculateDiagnosticStatusBits (dump 8). e2m: VGT_Position_Status (0x0119631A).'),
    ('o_closed_pos', 0x40b0a2, 'protection_ema_output', 'closed_position',
     'code: filtered closed position, forced to 12800 while fault 670 is set, replaced by the override value when the override flag is set (dump 12800). e2m: VGT_Closed_Position (0x0119D20E).'),
    ('o_closed_filtered', 0x40b0a4, 'protection_ema_output_prev', 'closed_position_filtered',
     'code: output of the closed-position filter before the fault-670 and override substitutions (dump 10895, not explained by the hold logic). e2m: VGT_Filtered_Closed_Position (0x0119D210).'),
    ('o_driver_pending', 0x40b05c, 'protection_fault_pending_flag', 'driver_fault_pending_flag',
     'code: dword read as its first word; written at the end of cm848_initProtectionControlState: 1 when either H-bridge fault retry flag (governor_fuel_rate_a_active / _b_active) is 0; its set state drops the logical output 72 request and the motor-ok flag. Typing is a note.'),
    # channel 101 tables
    ('tbl_axis', 0x59666, 'sensor_channel101_linearization_axis', 'position_sensor_linearization_axis',
     'code: x axis (ADC counts) of the channel 101 transfer function, read only by the two wrapper functions; the identity of the sensor follows from its consumers (position feedback of actuator E).'),
    ('tbl_values', 0x5967c, 'sensor_channel101_linearization_values', 'position_sensor_linearization_values',
     'code: y values of the channel 101 transfer function (1693 floor, linear to 16940 at ADC 921, flat above); output in 1/128 percent of position (12800 = 100 percent) before the adjustments.'),
]
FKEY = {k: P + (s if s else None) for k, a, o, s, e in G if s}
# fault words get their own names
FKEY.update({'fd656': 'fault_detected_bits_656_to_671', 'fd672': 'fault_detected_bits_672_to_687',
             'fd704': 'fault_detected_bits_704_to_719', 'fd736': 'fault_detected_bits_736_to_751',
             'fr656': 'fault_registered_bits_656_to_671', 'fr704': 'fault_registered_bits_704_to_719',
             'fr736': 'fault_registered_bits_736_to_751'})
NM = dict(FKEY)
NM['end_margin'] = 'actuator_e_end_margin'

# ---------------------------------------------------------------- functions
F = [
    (0x2e17c, 'cm848_updateLoadProtectionStartupCounter', 'cm848_updateVariableGeometryTurbochargerFaultHoldoff',
     'Counts passes (limit 200) while the position sensor status is above 0 or the position control error is set, and clears the count otherwise; the second word of {t_holdoff_flags} is 0 only during the first 200 passes of such a fault and 1 otherwise. Read by cm848_updateLoadProtectionArming, which drops the logical output 72 request during that hold-off. (was cm848_updateLoadProtectionStartupCounter)',
     'code: body read; xref: the hold-off flags (0x3fb07c) are read only by cm848_updateLoadProtectionArming and the counter (0x3fb080) is private to this function; request 72 is set in the normal state and cleared during the 200-pass window, so this is an enable being dropped, not an event raised.'),
    (0x2e1f0, 'cm848_updateLoadProtectionWarmupTrigger', 'cm848_detectVariableGeometryTurbochargerMissionReset',
     'Counts the first 60 passes after boot ({t_reset_window}) and sets {o_reset_detected} when engine speed in that window is at or above {reset_speed} (4800 = 600 rpm), i.e. the ECM restarted while the engine was running. (was cm848_updateLoadProtectionWarmupTrigger)',
     'code: timer saturates at 60 and the flag is (timer < 60 && current_rpm >= word); its only consumer latches it in the closed-stop stage, which then switches the key-on drives off. e2m: C_VGA_Mission_Reset_Speed / VGA_Mission_Reset_Detected have the same roles.'),
    (0x2e250, 'cm848_evaluateLoadProtectionFuelLowStage', 'cm848_runVariableGeometryTurbochargerClosedStopSeek',
     'Key-on stage that drives the valve to its closed stop: latches the mission reset, tracks the engine stop transition, waits until the sensor reads within actuator_e_end_margin of 12800 or {retry_time} passes, then keeps {o_closed_drive} on for {active_time} passes and sets {o_ready_closed}; it also copies the closed-stop drive duty (+30 percent) to {o_closed_duty_w}. (was cm848_evaluateLoadProtectionFuelLowStage)',
     'code: not a fuel stage - it reads no fuel word; the 2000-pass time-out, the 12800 end test and the mode 4 output (+3840) were checked in the body and in cm848_selectActuatorEControlMode. e2m: C_VGA_PWM_Closed_Diag_Value / VGA_PWM_Closed_Diag_Override / VGA_Ready_For_Closed_Adjust.'),
    (0x2e488, 'cm848_calculateLoadProtectionDeviationFlag', 'cm848_checkVariableGeometryTurbochargerPositionNearOpenStop',
     'Sets {t_near_open} when the sensor value is within {span_tolerance} (3200) of the expected open-stop reading, i.e. |(closed position - sensor value) - 12800| < tolerance. (was cm848_calculateLoadProtectionDeviationFlag)',
     'code: body read; dump 1693: |(12800 - 1693) - 12800| = 1693 < 3200 gives 1 as in the dump; the flag is used only as the open stop reached test. No e2m used.'),
    (0x2e4cc, 'cm848_evaluateLoadProtectionOverspeedStage', 'cm848_runVariableGeometryTurbochargerOpenStopSeek',
     'Stage that drives the valve to its open stop: latches {t_open_hold} when the sensor or span is faulty, sets {o_open_drive} (actuator E mode 3, duty -3840 before the mode output limits) while the engine is not spinning or the hold is latched and {t_open_dwell} is below {active_time}, latches {t_open_reached} when the sensor is near the open stop or {retry_time} passes have elapsed, and sets {o_ready_span}. (was cm848_evaluateLoadProtectionOverspeedStage)',
     'code: disassembly checked (r4 after the call is protection_confirm_limit_cal, the retry time); no speed is compared. e2m: VGA_PWM_Open_Diag_Override / VGA_Ready_For_Span_Adjust.'),
    (0x2e74c, 'cm848_updateLoadProtectionArming', 'cm848_sequenceVariableGeometryTurbochargerPositionAdjustment',
     'Per-pass sequencer of the position adjustment, run when {enable_flag} is set: selects the drive duty limit ({limit_over_temperature} / {limit_over_current} / {limit_normal}), derives the motor and position fault flags, requests logical output 72 unless the fault hold-off or a pending driver fault is present, runs the closed-stop and open-stop seek stages and sets the closed and span adjustment enables. (was cm848_updateLoadProtectionArming)',
     'code: body read; called per pass from cm848_phase_common_processing before cm848_updateLoadProtectionStatusAndDerate. It arms nothing about load. Logical output 72 is the neighbour of the direction output 71 of the actuator E loop (e2m: VGA_PWM_Enable follows VGA_Motor_Cmd_Closing_Direction); the identity of 72 is e2m / adjacency only.'),
    (0x2e9c8, 'cm848_clearLoadProtectionConfirmState', 'cm848_clearVariableGeometryTurbochargerStopSeekState',
     'Boot-time reset of the stop-seek sequencing state: clears the fault flags, engine-spinning flags, wait / dwell / mission-reset counters and the closed-stop, open-stop and fault-open-hold latches; the adjustment error counters and latches are not touched. (was cm848_clearLoadProtectionConfirmState)',
     'code: body read (17 stores); called from the init sequence next to cm848_initFaultStatusFilterState.'),
    (0x2ea58, 'cm848_updateGovernorDemandRateProtection', 'cm848_updateVariableGeometryTurbochargerDriverOverCurrentFault',
     'Over-current check of the valve motor driver, run when the module is enabled: while governor_rpm_monitored (the estimated motor current) is at or above governor_rpm_monitor_threshold (14336 = 14 A at 0.000976562 A per count) an accumulator grows by 10 per pass (falls by 3 otherwise) and flags the over-current at 4000; a second accumulator (+2000 per flagged pass, limit 30000) and a 192-pass clear timer decide retry or give-up, and fault 745 (mask 512) of fault_detected_bits_736_to_751 is set or cleared accordingly. (was cm848_updateGovernorDemandRateProtection)',
     'code: body read; it never reads channel 101; the eight words 0x4077a8-0x4077b6 (192, 2000, 30000, 1, 4000, 14336, 3, 10) are the accumulator limits and steps in the order of e2m C_VGA_Driver_OC_Clear_Time .. Time_Incrt (0x01190B00-0E); 14336 x 0.000976562 = 14.0 A. governor_rpm_monitored is the |applied voltage - back-EMF| / resistance estimate of governor_rpm_monitor_calc (EMF factor and current clamp words sit at the e2m C_VGA_Speed_EMF_Factor / Max_Current offsets; its square is filtered with the Current_Avg_Fil_Cnst word).'),
    (0x2ed30, 'cm848_clearGovernorDemandRateProtectionState', 'cm848_clearVariableGeometryTurbochargerDriverOverCurrentState',
     'Boot-time reset of the driver over-current check: zeroes both accumulators, the clear timer and the flags and clears fault 745 (mask 512) in the detected and registered fault words. (was cm848_clearGovernorDemandRateProtectionState)',
     'code: body read; the cleared flags are exactly the ones cm848_updateVariableGeometryTurbochargerDriverOverCurrentFault writes.'),
    (0x2edc0, 'cm848_updateLoadProtectionConfirmCounterA', 'cm848_updateVariableGeometryTurbochargerClosedAdjustmentErrorLatch',
     'Debounce and latch of the closed adjustment error: the delay counter runs to {adjust_enable_time} while the closed adjustment is enabled; once elapsed, the error counter rises each pass the sensor is outside the closed position tolerance and falls each pass it is inside; at {adjust_fault_time} (200) the error is latched, released at 0, and {en_clear_error} forces 0. (was cm848_updateLoadProtectionConfirmCounterA)',
     'code: body read; with the dump delay limit 0 the elapsed flag is 1 even while the adjustment is disabled, which is why the counter sits at 200. e2m: C_VGT_Pos_Adjust_Enable_Time / C_VGT_Pos_Adjustment_Fault_Time / T_VGT_Clr_Adjustment_Error_Cnt.'),
    (0x2ef34, 'cm848_updateLoadProtectionEmaOutput', 'cm848_filterVariableGeometryTurbochargerClosedPosition',
     'First-order filter of the closed-stop reading: follows {pos_value} only while {t_closed_valid} is set, otherwise holds; stores {o_closed_filtered} and {saved_closed}, forces 12800 while fault 670 is set and substitutes {closed_override_value} when {en_closed_override} is set, giving {o_closed_pos}. (was cm848_updateLoadProtectionEmaOutput)',
     'code: body read; the old reading filtered engine_load_percent, but the filter input is 0x40bdb6 (xref: 8 reads, 0 writes) and engine_load_percent (0x40af24) is read by none of the cluster functions. e2m: VGT_Filtered_Closed_Position / VGT_Closed_Position / T_VGT_Closed_Position.'),
    (0x2efe4, 'cm848_evaluateLoadProtectionSteadyStage', 'cm848_evaluateVariableGeometryTurbochargerClosedAdjustment',
     'Closed position adjustment: flags {t_closed_out} (|12800 - sensor value| >= actuator_e_end_margin), runs the closed error latch, marks the closed reading valid when it is inside the tolerance with the delay elapsed, latches a time-out error when the closed-stop drive ends without a valid reading, sets or clears fault 670 (mask 16384 of {fd656}) and its registered copy, then updates the filtered closed position. (was cm848_evaluateLoadProtectionSteadyStage)',
     'code: body read; fault 670 is the confirm-A bit of the old reading and is also the clamp condition of cm848_calculateActuatorESetpoint. e2m: VGT_Closed_Adjustment_Error is mask 16384 of 0x01103652.'),
    (0x2f154, 'cm848_updateLoadProtectionConfirmCounterB', 'cm848_updateVariableGeometryTurbochargerSpanAdjustmentErrorLatch',
     'Debounce and latch of the span adjustment error, same scheme as the closed adjustment latch but on the span out-of-tolerance flag and the span delay and error counters; the latched flag drives fault 671. (was cm848_updateLoadProtectionConfirmCounterB)',
     'code: body read; mirror of cm848_updateLoadProtectionConfirmCounterA with the span words.'),
    (0x2f2c8, 'cm848_updateLoadProtectionLoadFilter', 'cm848_filterVariableGeometryTurbochargerSpan',
     'First-order filter of the span (closed position minus sensor value): follows {t_span_meas} while {t_span_valid} is set, otherwise holds the saved span minus {span_decrement} (applied once after boot) with a floor of 12800 - {span_tolerance}; stores {o_span_filtered} and {saved_span}, forcing the floor while fault 670 is set. (was cm848_updateLoadProtectionLoadFilter)',
     'code: body read; not a load filter - its input is A - x, not a load. e2m: VGT_Filtered_Span / T_VGT_Adjusted_Span / C_VGT_Span_Fail_Decrement.'),
    (0x2f3a0, 'cm848_evaluateLoadProtectionLiveStage', 'cm848_evaluateVariableGeometryTurbochargerSpanAdjustment',
     'Span adjustment: measures the span ({t_span_meas}), flags it outside {span_tolerance} around 12800, arms the adjustment while the open-stop drive or the zero-setpoint hold is active, runs the span error latch (fault 671, mask 32768 of {fd656}), marks the measurement valid inside the tolerance with the delay elapsed, then filters the span; the working span {o_span_adjusted} is {span_override_value} when {en_span_override} is set. (was cm848_evaluateLoadProtectionLiveStage)',
     'code: body read; fault 671 is the confirm-B bit of the old reading. e2m: VGT_Span_Adjustment_Error is mask 32768 of 0x01103652.'),
    (0x2f524, 'cm848_calculateLoadProtectionDerateTarget', 'cm848_calculateVariableGeometryTurbochargerAdjustedPosition',
     'Normalises the sensor value to a position with 12800 = 100 percent: ((sensor value - closed position) + span) x 12800 / (max(span, 12800 - span tolerance) - closed stop gap), clamped to +-12800, into {o_adjusted}. With the dump overrides (closed position 12800, span 12800, gap 1920) this is sensor value x 12800 / 10880, so 1693 gives 1991. (was cm848_calculateLoadProtectionDerateTarget)',
     'code: dump check 1693 x 12800 / 10880 = 1991.8 and both 0x40b098 and actuator_e_feedback read 1991; nothing derates engine speed - the result is the feedback of the actuator E loop. e2m: VGT_Position_AP.'),
    (0x2f5a4, 'cm848_processLoadProtectionStatus', 'cm848_evaluateVariableGeometryTurbochargerPositionAdjustments',
     'Runs the closed position adjustment and the span adjustment, forms the intermediate position status (sensor fault status OR 8 when fault 671 is set) and then calculates the adjusted position; called by cm848_updateLoadProtectionStatusAndDerate. Replaces the engine-load-protection reading: nothing here reads engine_load_percent or derates speed. (was cm848_processLoadProtectionStatus)',
     'code: body read; its typed local holds 8 from fault 671 only. Kept from the old plate: the call order and the caller; dropped: monitored quantity (engine load), derate, fuel-mode-B, SPN 0x48 event.'),
    (0x2f604, 'cm848_calculateDiagnosticStatusBits', 'cm848_selectVariableGeometryTurbochargerPositionSource',
     'Chooses the position fed to the actuator E loop: actuator_e_feedback is {o_adjusted} with source 0 when the status is clear (sensor status 0, no span adjustment error, no position control error), otherwise {pos_default} (9216 = 72 percent) with source 2; also builds {o_status} = status | 8 for a span or closed adjustment error | 32 for the position control error (fault 743). (was cm848_calculateDiagnosticStatusBits)',
     'code: body read; the 9216 default is the channel config word. e2m: VGT_Position_Source 0 primary / 2 default, VGT_Position_Status.'),
    (0x2f6a0, 'cm848_updateLoadProtectionStatusAndDerate', 'cm848_updateVariableGeometryTurbochargerPosition',
     'Per-pass entry of the position processing, run when {enable_flag} is set: copies the sensor high / low faults 682 / 683 of {fd672} to faults 709 / 710 of {fd704} (and clears the registered copies), then runs cm848_evaluateVariableGeometryTurbochargerPositionAdjustments and cm848_selectVariableGeometryTurbochargerPositionSource. (was cm848_updateLoadProtectionStatusAndDerate)',
     'code: body read; high_fault_bit 682 / low_fault_bit 683 are the 8th / 9th arguments of the channel 101 call, 682 = word 42 bit 10 (mask 1024), 683 = bit 11 (mask 2048). e2m: VGT_Position_PP_High_Error / PP_Low_Error at masks 32 / 64.'),
    (0x2f784, 'cm848_initFaultStatusFilterState', 'cm848_initializeVariableGeometryTurbochargerAdjustmentFilters',
     'Boot init: sets {t_span_decrement_pending}, starts the span filter from {saved_span} and the closed-position filter from {saved_closed}, points both filters at {filter_coefficient}, clears the two closed-adjustment latch flags and, when {enable_flag} is 0, clears the position error faults 709 / 710. (was cm848_initFaultStatusFilterState)',
     'code: body read; called from the init sequence after cm848_clearVariableGeometryTurbochargerStopSeekState.'),
    (0x5011c4, 'cm848_protection_init_configBundle', 'cm848_readVariableGeometryTurbochargerPositionSensor',
     'Periodic read of sensor channel 101 (called once per pass from cm848_phase_common_processing): linearises the ADC value through the channel table, debounces the high / low faults 682 / 683 and filters it into {pos_value}, with {pos_default} and {pos_status} as the other outputs. (was cm848_protection_init_configBundle)',
     'code: sensorChannelConfigInit call with index 101, fault bits 682 / 683 and the three output words; periodic caller checked. The matching boot call is cm848_protection_update_configBundle (init sequence).'),
    (0x501250, 'cm848_protection_update_configBundle', 'cm848_initializeVariableGeometryTurbochargerPositionSensor',
     'Boot-time first pass of sensor channel 101 (called from the init sequence): loads the first position sensor value, default and status through updateSensorChannelWithConfig with the same arguments as the periodic read. (was cm848_protection_update_configBundle)',
     'code: caller at the init sequence line 53968; same 13 arguments as the periodic wrapper.'),
]

ENUM_TYPE = ('ENGINE_LOAD_PROTECTION_STATE', 'VARIABLE_GEOMETRY_TURBOCHARGER_SPAN_ADJUSTMENT_STATE')
ENUM_MEMBERS = [
    ('ENGINE_LOAD_PROTECTION_INACTIVE', 'VARIABLE_GEOMETRY_TURBOCHARGER_SPAN_ADJUSTMENT_NORMAL'),
    ('ENGINE_LOAD_PROTECTION_ACTIVE', 'VARIABLE_GEOMETRY_TURBOCHARGER_SPAN_ADJUSTMENT_ERROR'),
]

NOTES = [
    'VERDICT (old reading: partly kept, mostly wrong). Sensor channel 101 is the position sensor of the valve actuator of a variable-geometry turbocharger, and the 18 cluster functions are its key-on stop-seek and position adjustment, not engine-load protection. CODE: the value (0x40bdb6) is only ever compared with 12800 or with the learned closed position and span, never with engine speed or load; cm848_calculateVariableGeometryTurbochargerAdjustedPosition normalises it to a position, 1693 x 12800 / (12800 - 1920) = 1991 = both 0x40b098 and actuator_e_feedback in the dump; the sensor is the feedback of the actuator E servo (sign = direction output 71, magnitude = duty); the key-on stages drive that actuator with the mode 4 / mode 3 outputs (+3840 / -3840, subject to the mode output limits) until the sensor reads near 12800 (closed stop) or near the open stop and learn the reading and span there; fault bits 670 / 671 are the closed / span adjustment errors; fault 682 / 683 are the sensor high / low faults. E2M (corroboration only, e2m is the .12 file and the ECU is .06): the group Group_VGT has VGT_Position_Sensor / VGT_Position_Default (0x01196636 / 34), VGT_Closed_Position / VGT_Adjusted_Span / T_VGT_* saved values, VGT_Closed_Adjustment_Error / VGT_Span_Adjustment_Error at masks 16384 / 32768, VGT_Position_Source, and the C_VGT_* / C_VGA_* / T_VGT_* blocks match the CM848 words word for word at the same relative offsets (map validated by the independent pair boost value / default 0x0119660E / 0x01196626 = Charge_Press_Sensor / Default = 0x40bd8e / 0x40bda6). The unit is 1/128 percent (12800 = 100 percent, scale 0.0078125).',
    'WHAT SURVIVES OF THE OLD READING: two debounced, latched adjustment error conditions (confirm-A / confirm-B = faults 670 / 671), their EMA filters and the substitution of a fixed fallback value (the channel default 9216) when the status is bad. WHAT DOES NOT: the monitored quantity (engine_load_percent 0x40af24 is read by none of the cluster functions: xref lists 9 other functions), any derate of engine speed or fuel (the derate target is the normalised position; nothing writes a governor limit), fuel-mode-B (the flag, was governor_fuel_b_mode_flag, is the enable of the whole position-servo module, 9 readers, all in it), the SPN 72 / 0x48 protection event (logical output request 72 is the neighbour of the direction output 71), and every speed name (all values are position x 128). The ENGINE_LOAD_PROTECTION_STATE enum is renamed for what the typed local holds (8 from fault 671); the same bit 8 is OR-ed untyped from fault 670 in cm848_selectVariableGeometryTurbochargerPositionSource.',
    'RPM / PTO SPEED SETPOINT HYPOTHESIS (211..2117 rpm, 1152 rpm default): rejected. Consumers: (1) the cluster compares the value only with 12800 +- actuator_e_end_margin (1856), with the learned closed position and with the span tolerance 3200; (2) the actuator E loop subtracts it from the wastegate duty request on the same 12800 = 100 percent scale; (3) the 9216 default is the position default (72 percent); (4) the only rpm test in the cluster is current_rpm >= 4800 (600 rpm) for the mission reset, on a different word. No consumer treats it as 0.125 rpm per count.',
    'THIS TRUCK (RAM dump, engine off, plus the four EEPROM dumps): the sensor value equals the table floor 1693; actuator_output_channel_e_cal = 0 (unassigned) and logical output 71 maps to no line, yet the module enable is 1, so the loop and the position code run; closed adjustment enable (EEPROM 0x450) 0, span adjustment enable 1, span / closed-position user overrides 1 / 1, so the position is sensor value x 12800 / 10880 and the learned values are bypassed; EEPROM 0x195c / 0x195e hold 9600 / 12800 in all four dumps. Fault 670 reads set (mask 16384 in fault_detected_bits_656_to_671): the error counter is 200 with the adjustment disabled because the delay limit is 0, so the elapsed flag (limit == counter == 0) is true even when the adjustment is off, and the sensor reads 1693 at dump time, outside 12800 +- 1856. Not checked here: whether 670 / 671 map to a DTC slot (682 / 683 map to the shared no-DTC slot per wave 4). Effects seen in code: cm848_calculateActuatorESetpoint clamps its setpoint while 670 is set, and cm848_fuelDemand_periodic sets 0x40a450 (below).',
    'FOLLOW-UP, wave 4 actuator E names (not re-proposed here): the loop is the position servo of the same valve. By offset anchors (block 0x01183000 -> 0x40771a: +0x00 C_VGA_Cmd_Override_Value = actuator_e_setpoint_override, +0x3C C_VGA_Cmd_ULim = actuator_e_setpoint_upper_limit, +0x4C C_VGT_Closed_Position_Tolerance = actuator_e_end_margin, +0x54 enable = governor_fuel_b_mode_flag; 0x3fd8cc = T_VGA_Cmd_User_Override / T_VGA_PWM_User_Override) and the code (feedback = adjusted position, setpoint = turbo request, sign = direction, magnitude = duty) the actuator_e_* family, actuator_output_channel_e_cal and cm848_*ActuatorE* functions can be re-domained to variable_geometry_turbocharger_* (for example actuator_e_feedback = VGT_Position, actuator_e_end_margin = closed position tolerance, cm848_runActuatorEControlLoop = position control loop runner). If the VGT label should wait for a bench check, the neutral fallbacks are the existing actuator_e_* names for the loop and sensor_channel101_* for the sensor words; the code facts above hold either way.',
    'FOLLOW-UP, same module, not renamed here (comments cite the current names): bank-2 monitors engine_protection_speedTracking_calc 0x50f834 / _rampUpdate 0x50fa7c / phase_group_b_updateGovernorModeDiagnostics 0x50fbf8 = position control error (fault 743, mask 128); governor_rpm_monitor_calc 0x51008c = motor current estimate (words 0x4077b8.. at the e2m C_VGA_Circuit_Resistance .. Speed_EMF_Factor offsets); phase_group_b_filterGovernorRpmSquaredMovingAverage 0x51027c = mean-squared current filter; phase_group_b_computeGovernorFuelDemandOutput 0x50fe54 = winding temperature estimate that sets fault 746 (mask 1024) (its fuel_demand_boost_input is a coolant temperature, default word 0x4077da = 14080 = 220 F at 1/64 F); boost_demand_diagBit_counter 0x50fd40 = over-temperature inhibit timer (0x4077dc = 50 x 0.2 s). Also cm848_initProtectionControlState 0x2dc40 = H-bridge driver fault handler (reads supervisor_register_162_status, sets masks 4 / 8 / 16 / 32 / 64 and 256 of fault_detected_bits_736_to_751, writes the driver fault pending flag), cm848_clearDiagnosticConditionFlags 0x2e02c = clears those fault masks and the retry flags governor_fuel_rate_*, and the governor_demand_rate_* words of the over-current check (limits and steps = e2m C_VGA_Driver_OC_Clear_Time, Fail_Incrt, Max_Count, Pass_Decrt, Set_Time, Threshold, Time_Decrt, Time_Incrt at 0x4077a8..0x4077b6; their cal-suffix names are wrong outside the EEPROM mirror). Local variable engineLoadProtection in 0x2f5a4 (local_variables.csv) should become spanAdjustmentState.',
    'TYPING NOTES (no type change proposed): 0x3fb074 and 0x3fb07c are dwords used as two words (first / second word), 0x40b05c is a dword read as its first word; 0x3fb0d2 + 0x3fb0d6 are one ema_filter_state_t split into two globals; 0x40779e holds -3840 as an unsigned word; the saved span / closed position (0x3fedde / 0x3fede0) are signed positions stored as words. The config / state structs of channel 101 (0x59656 sensor_channel_config_t, 0x40a12e sensor_channel_state_t, 0x3fb9c0 / 0x3fb9c2) have type-only rows with no name; follow the barometric_pressure_sensor_config precedent (variable_geometry_turbocharger_position_sensor_config / _state). The CSV comments of sensor_channel101_linearization_* cite the old wrapper names and the comment of 0x3fe9c6 / the enum rows still say engine-load protection: refresh them. The project memory entry about the load-protection cluster is stale.',
    'TIME-SHARED WORDS (0x3fb050-0x3fb0e0, 0x3fd8cc-0x3fd8e0): three scans of the boot ROM 0x0-0x7F5F found no user: (1) every load / store / addi / ori whose low halfword matches an address of these ranges (0 hits), (2) every direct b / bl / ba / bla whose target lies in the ranges (0 hits), (3) every 32-bit data word equal to an address in the ranges (0 hits); xref_addr.py shows no access below 0x7F60 for any of the renamed words. 0x3fedde / 0x3fede0 are outside the time-shared windows. No type is changed.',
    'CAVEATS ON NAMES: (a) logical output 72 as the valve driver enable rests on adjacency to output 71 and the e2m order (VGA_Motor_Cmd_Closing_Direction, VGA_PWM_Enable); the code only shows it is requested in the normal state and dropped during the 200-pass hold-off and while the driver fault pending flag is set. (b) the over-temperature meaning of fault 746 and its duty limit rests on the thermal-model structure of its producer plus five anchors of the e2m C_VGA_* block; the over-current meaning of fault 745 is supported by the eight-word anchor match and the accumulator code. (c) the fault-array names fault_detected_bits_N_to_M / fault_registered_bits_N_to_M follow the existing naming; the other words of the arrays (0x3fe9ce, 0x3fe9d4, 0x3fe9d6, 0x3fea32 ...) can be renamed the same way mechanically.',
    'APPLY AND SCOPE. PROVEN BY CODE: channel 101 is the position feedback of a two-direction valve servo (the actuator E loop) with key-on stop seeking and closed / span adjustment, and no engine load, engine speed or derate is involved. NOT PROVEN BY CODE: the turbocharger label (it comes from the .12 e2m, group Group_VGT) and the presence of the part - on this truck the loop output is unassigned. Rows whose meaning leans on e2m, to drop first if code-only names are wanted: the two drive duty limits for faults 746 / 745, driver_over_current_give_up_enable_cal, driver_fault_pending_flag, and logical output 72 as the driver enable (sequencer plate). The 98 global rows are the cluster whole state set on purpose (the cap of 10 globals per function in brief.md was read as binding only unrelated extras); apply the rows together because plates and evidence cite the proposed names. confirmed means the wave-4 lead (this is not engine-load protection) holds and a corrected name is proposed. Left alone on purpose: the actuator_e_* family and the cm848_*ActuatorE* functions, the bank-2 siblings 0x50f834-0x5102d4, cm848_initProtectionControlState 0x2dc40 and cm848_clearDiagnosticConditionFlags 0x2e02c. Overlap: the new_global 0x40a450 and cm848_fuelDemand_periodic 0x50370c lie in the combustion-manager range, so reconcile this file with the other wave-5 result file before applying.',
]
NEW_GLOBAL = (0x40a450, 'variable_geometry_turbocharger_failure_flag', 'word')

# ---------------------------------------------------------------- build and validate
fn_old = {}
for r in csv.reader(open(OUT + 'function_renames.csv')):
    if r and r[0].startswith('0x'):
        fn_old[int(r[0], 16)] = r[1].strip()
existing = set(fn_old.values())
for a, v in C.byaddr.items():
    existing.add(v[0])
for fn in ('arrays.csv', 'enums.csv'):
    for r in csv.reader(open(OUT + fn)):
        existing.update(x.strip() for x in r[:4])

rows = []
problems = []
new_names = []


def fmt(s):
    return s.format(**NM)


for a, old, new, plate, ev in F:
    if fn_old.get(a) != old:
        problems.append(('function old mismatch', hex(a), old, fn_old.get(a)))
    rows.append({'kind': 'function', 'address': '0x%08x' % a, 'old': old, 'verdict': 'confirmed', 'new': new,
                 'plate_comment': fmt(plate), 'evidence': ev})
    new_names.append(new)

for key, a, old, suf, ev in G:
    cur = C.byaddr.get(a, ('',))[0]
    if cur != old:
        problems.append(('global old mismatch', hex(a), old, cur))
    new = NM[key]
    rows.append({'kind': 'global', 'address': '0x%08x' % a, 'old': old, 'verdict': 'confirmed', 'new': new, 'evidence': ev})
    new_names.append(new)

dump_flag = C.peek(NEW_GLOBAL[0], 'word')
rows.append({'kind': 'new_global', 'address': '0x%08x' % NEW_GLOBAL[0], 'new': NEW_GLOBAL[1], 'type': NEW_GLOBAL[2],
             'evidence': 'code: written once per pass at the end of cm848_fuelDemand_periodic (store at 0x503788): 1 unless the position source is 0 and faults 746 / 745 / 744 (masks 1024 / 512 / 256) and 671 / 670 (masks 32768 / 16384) are all clear, else 0; no direct reader found by name-grep xref (0 reads / 1 write, width: word per xref_addr.py). Dump value %d. e2m: VGA_Charge_Flow_Derate (fault flag passed to the combustion manager that the valve has failed) has this role, but its offset in the 0x01183400 block lands on 0x40b05e, so the name rests on the code.' % dump_flag[0]})
new_names.append(NEW_GLOBAL[1])

rows.append({'kind': 'enum_type', 'old': ENUM_TYPE[0], 'new': ENUM_TYPE[1],
             'evidence': 'code: the only typed use is the local of cm848_processLoadProtectionStatus, which holds 8 when fault 671 (span adjustment error, mask 32768) is set and is ORed into the position status; renamed for what the local holds. The suggested CSV comment for value 8: span adjustment error, bit 3 of the position status word, mirrors fault 671 of fault_detected_bits_656_to_671.'})
for old, new in ENUM_MEMBERS:
    rows.append({'kind': 'enum_member', 'enum': ENUM_TYPE[0], 'old': old, 'new': new,
                 'evidence': 'code: value %s of the typed local = fault 671 clear / set; the enum row is renamed by the enum_type row, members keep their values.' % ('0' if 'NORMAL' in new else '8')})
    new_names.append(new)
new_names.append(ENUM_TYPE[1])

for t in NOTES:
    rows.append({'kind': 'note', 'text': t})

# validation
seen = {}
for n in new_names:
    seen[n] = seen.get(n, 0) + 1
for n, c in seen.items():
    if c > 1:
        problems.append(('duplicate new name', n))
    if n in existing:
        problems.append(('collides with an existing name', n))
    if re.search(r'0x|protection|governor|engine_load|derate|fuel_b', n, re.I):
        problems.append(('banned token', n))
    if re.search(r'(^|_)[0-9a-f]{4,}(_|$)', n) and not re.search(r'_\d+_to_\d+', n):
        problems.append(('hex-looking token', n))
    if n.endswith('_cal') and True:
        pass

# _cal only inside the EEPROM mirror
EEPROM_KEYS = {'en_closed_adjust', 'en_span_adjust', 'en_give_up', 'en_span_override', 'en_clear_error',
               'en_closed_override', 'saved_span', 'saved_closed'}
for key, a, old, suf, ev in G:
    inside = 0x3fd482 <= a <= 0x3feec1
    if NM[key].endswith('_cal') and not inside:
        problems.append(('_cal outside the EEPROM mirror', hex(a), NM[key]))
    if key in EEPROM_KEYS and not NM[key].endswith('_cal'):
        problems.append(('EEPROM-backed word without _cal', hex(a), NM[key]))
    if key not in EEPROM_KEYS and NM[key].endswith('_cal'):
        problems.append(('unexpected _cal', hex(a), NM[key]))

# ---- post-process: batch old -> new names in plates / evidence / notes (not in the (was ...) tail), boot-ROM sentence
old2new = {}
for a, old, new, plate, ev in F:
    old2new[old] = new
for key, a, old, suf, ev in G:
    old2new[old] = NM[key]
old2new[ENUM_TYPE[0]] = ENUM_TYPE[1]
for o, n in ENUM_MEMBERS:
    old2new[o] = n


def word_re(name, skip_was=True):
    return re.compile(('(?<!was )' if skip_was else '') + '(?<![A-Za-z0-9_])' + re.escape(name) + '(?![A-Za-z0-9_])')


pats = [(word_re(o), n) for o, n in sorted(old2new.items(), key=lambda kv: -len(kv[0]))]


def swap(text):
    for p, n in pats:
        text = p.sub(n, text)
    return text


for r in rows:
    if r['kind'] == 'function':
        head, sep, tail = r['plate_comment'].rpartition('(was ')
        r['plate_comment'] = swap(head) + sep + tail
        r['evidence'] = swap(r['evidence'])
    elif r['kind'] in ('global', 'new_global', 'enum_type', 'enum_member'):
        r['evidence'] = swap(r['evidence'])
    elif r['kind'] == 'note':
        r['text'] = swap(r['text'])
    if r['kind'] == 'global':
        addr = int(r['address'], 16)
        if 0x3F9800 <= addr <= 0x3FDB30 and 'boot' not in r['evidence']:
            r['evidence'] += ' Time-shared window (0x3F9800-0x3FDB30): no boot-ROM user (xref_addr.py plus three scans of the boot ROM).'

# leftover old names outside (was ...) and the old fields
for r in rows:
    if r['kind'] == 'function':
        texts = [r['plate_comment'].rpartition('(was ')[0], r['evidence']]
    elif r['kind'] in ('global', 'new_global', 'enum_type', 'enum_member'):
        texts = [r['evidence']]
    else:
        texts = [r['text']]
    for t in texts:
        for o in old2new:
            if word_re(o).search(t):
                problems.append(('old name left outside (was', r.get('address') or r['kind'], o))
    if r['kind'] == 'function':
        n_was = r['plate_comment'].count('(was ')
        if n_was != 1 or not r['plate_comment'].rstrip().endswith(')'):
            problems.append(('plate tail', r['address']))

with open(RESULT, 'w') as fh:
    for r in rows:
        fh.write(json.dumps(r, ensure_ascii=True) + '\n')

toks = set()
for n in new_names:
    toks.update(re.split(r'[_]|(?<=[a-z])(?=[A-Z])', n))
print('rows', len(rows), 'functions', len(F), 'globals', len(G), 'names', len(new_names))
print('problems', problems)
print(sorted(t.lower() for t in toks if t))
print('dump 0x40a450 =', dump_flag)
