"""Round 24 stage B (label-only), part 1: the commanded throttle record (e2m 1047 / 1048), the remote and dual channel
pedals, the DTC code lookup. apply_hand_worklist.py adds the e2m part, '(was <old>)' and the earlier note."""
GLOBALS = [
    ("0x0040a57a", "commanded_throttle_state",
     "The commanded throttle record (commanded_throttle_state_t, e2m 1047 Commanded_Throttle ... "
     "Filtered_Delta_Throttle, 14 words): the commanded throttle the governors read (0-400 = 0-100 %), the idle "
     "validation and transition states, the Throttle_Min learning, the alternate throttle selection and the per-pass "
     "change"),
    ("0x003fa6e8", "throttle_minimum_candidate",
     "The candidate Throttle_Min of cm848_learnAcceleratorPedalAutozero: a pedal reading below "
     "commanded_throttle_state.throttle_minimum starts it (with the confidence counter at "
     "accelerator_pedal_minimum_learning_confidence_count_limit); it becomes the Throttle_Min when the counter "
     "reaches 0, and it is reset to the Throttle_Min when learning is not allowed or readings above the confidence "
     "band count the counter back up to its limit"),
    ("0x003fa6fc", "accelerator_pedal_autozero_elapsed_time",
     "Passes of cm848_learnAcceleratorPedalAutozero with learning allowed (idle switch on, off-idle switch off); "
     "learning stops once it exceeds accelerator_pedal_autozero_time_limit (e2m 1048 +18 TPS_AZ_Time_Limit). Its "
     "only writer is that increment"),
    ("0x003fa6fe", "accelerator_pedal_autozero_update_count",
     "Throttle_Min updates accepted by cm848_learnAcceleratorPedalAutozero (each also stores "
     "accelerator_pedal_autozero_cal); learning stops once it exceeds accelerator_pedal_autozero_update_count_limit "
     "(e2m 1048 +1A TPS_AZ_Update_Limit), and while it is non-zero a Throttle_Min at or above "
     "accelerator_pedal_highest_valid_minimum falls back to accelerator_pedal_autozero_cal - "
     "accelerator_pedal_autozero_offset"),
    ("0x003fa6ec", "idle_validation_off_idle_threshold",
     "Throttle_Min + accelerator_pedal_off_idle_deadband (e2m 1048 Throttle_Deadband: above it the switches must "
     "indicate off idle), set by cm848_evaluateIdleValidationSwitches; a pedal above it with the idle switch on is "
     "idle validation state 2"),
    ("0x003fa6ea", "idle_validation_idle_threshold",
     "Throttle_Min + accelerator_pedal_idle_hysteresis (e2m 1048 Throttle_Hysteresis: below it the switches must "
     "indicate idle), set by cm848_evaluateIdleValidationSwitches; a pedal below it with the off-idle switch on is "
     "idle validation state 3"),
    ("0x003fa6f4", "commanded_throttle_delta_filter",
     "First order filter record (ema_filter_state_t) of commanded_throttle_state.commanded_throttle_delta, with "
     "commanded_throttle_delta_filter_coefficient; its output is commanded_throttle_delta_filtered"),
    ("0x0005c2aa", "commanded_throttle_delta_filter_coefficient",
     "The coefficient of commanded_throttle_delta_filter (cm848_initializeCommandedThrottleState points the record "
     "at it)"),
    ("0x0040b54e", "accelerator_pedal_dual_channel_demand",
     "The dual channel pedal's demand, 0-400 (0.25 % per count): the idle-corrected reading of channel 97 (98 when "
     "97 has a circuit fault, the lower of the two during a disagreement) x 400 / accelerator_pedal_travel_span, "
     "from cm848_calculateAcceleratorPedalDemandFromChannels; no governor speed limit"),
    ("0x0040b54c", "accelerator_pedal_dual_channel_validated_demand",
     "accelerator_pedal_dual_channel_demand, or 0 while accelerator_pedal_input_fault_flag is set: with the dual "
     "channel pedal fitted, cm848_selectCommandedThrottle takes it as the calculated commanded throttle; SCI command "
     "20 reports it x 0.6375 (0-255)"),
    ("0x0040bb00", "remote_accelerator_pedal_sensor_filtered",
     "sensor_channel_filtered_output[8], the remote accelerator pedal (0.25 % per count, 400 = 100 %): EEC2 byte 4 "
     "(SPN 974 Remote Accelerator Pedal Position, 0.4 %/bit) sends it x 0.625 when remote throttle is enabled; "
     "cm848_claimRemoteThrottleOverride takes it as the alternate throttle and cm848_verifyRemoteThrottleTransition "
     "compares it with the calculated commanded throttle; bit 8 (0x100) of sensor_channel_held_value_enable_bits_cal "
     "makes the channel output its held value (the EEC2 byte is then 0xFF); no governor torque"),
    ("0x003fcbf2", "remote_throttle_transition_verified_flag",
     "1 once the remote throttle switch is on and the remote pedal has come down to the calculated commanded throttle "
     "(cm848_verifyRemoteThrottleTransition); with transition verification enabled the remote throttle claim needs "
     "it; cleared at boot by cm848_initializeRemoteThrottle; no rate limit"),
    ("0x003fadab", "j1939_eec2_remote_accelerator_pedal_byte",
     "EEC2 (PGN 61443) byte 4, SPN 974 Remote Accelerator Pedal Position (0.4 %/bit): "
     "remote_accelerator_pedal_sensor_filtered x 0.625; 0xFF when remote throttle is disabled or channel 8 takes its "
     "held value, 0xFE on a remote pedal fault (fault bits 77 / 78)"),
]
FUNCTIONS = [
    ("0x0001782c", "cm848_selectCommandedThrottle",
     "Sets the commanded throttle (e2m 1047 Commanded_Throttle, 0-400 = 0-100 %). The calculated commanded throttle "
     "comes from cm848_calculateCommandedThrottleFromPedal, from accelerator_pedal_dual_channel_validated_demand "
     "with the dual channel pedal, or from channel 13 while its held value (the J1939 pedal) is enabled - that case "
     "sets the commanded throttle straight from channel 13 and returns when j1939_input_source_priority is below the "
     "channel's held value source priority. While a claimer holds alternate_throttle_priority the commanded "
     "throttle is the alternate throttle (selected_alternate_throttle_priority keeps the priority; the claim is "
     "cleared every pass); then the per-pass change commanded_throttle_delta and its first order filter"),
    ("0x0001702c", "cm848_calculateCommandedThrottleFromPedal",
     "Calculated_Commanded_Throttle (e2m 1047 +10) from the analog pedal: (accelerator_pedal_sensor_counts - the "
     "autozero) x 400 / accelerator_pedal_throttle_range (e2m 1048 Throttle_Range), at most 400; 0 while a pedal "
     "fault holds (registered fault bits 10 / 11 set the low word of throttle_fuel_enable_flag, or detected fault "
     "bits 63 / 68) or the pedal is at or below the autozero. The autozero is accelerator_pedal_autozero_cal, or "
     "accelerator_pedal_test_cell_autozero with the test cell override, which also sets accelerator_off_idle"),
    ("0x00017980", "cm848_runThrottleValidation",
     "The throttle validation pass (analog pedal: no held value, no dual channel). Idle validation "
     "(cm848_evaluateIdleValidationSwitches, cm848_updateOffIdleFromIdleValidation); then, with no pedal fault, the "
     "transition state (cm848_updateThrottleTransitionState) and the Throttle_Min learning "
     "(cm848_learnAcceleratorPedalAutozero), else Throttle_Min = accelerator_pedal_highest_valid_minimum + 4; then "
     "cm848_monitorAcceleratorPedalIdleValidationFaults. Fault bit 197 also sets the pedal fault flag. With the test "
     "cell throttle switch override it only clears fault bits 62 / 63 / 68 when they are registered"),
    ("0x000172e8", "cm848_updateThrottleTransitionState",
     "The throttle transition state (e2m 1047 +6 Transition_State, 'state of potentiometer and idle validation "
     "switch readings'): 0 -> 1 and 2 -> 3 once the idle switch is on, the off-idle switch off and the pedal at or "
     "below Throttle_Min + accelerator_pedal_autozero_offset; 1 -> 2 when idle validation state 1 holds and the "
     "pedal is above Throttle_Min + accelerator_pedal_above_idle_transition_range (e2m 1048 "
     "Throttle_Transition_Range). cm848_monitorAcceleratorPedalIdleValidationFaults acts in state 3. No rate limiter"),
    ("0x00017af4", "cm848_initializeCommandedThrottleState",
     "Boot initialization of the commanded throttle record: the confidence counter, idle validation state, "
     "transition state and off-idle flag to 0, Throttle_Min = accelerator_pedal_highest_valid_minimum + 4, the "
     "previous commanded throttle (high word of throttle_fuel_enable_flag) to 0, and the delta filter (accumulator 0, "
     "coefficient commanded_throttle_delta_filter_coefficient)"),
    ("0x0050e534", "cm848_verifyRemoteThrottleTransition",
     "The remote throttle hand-over latch (algorithm_enable_flags_18_cal.remote_throttle_transition_verification_"
     "enable): with the remote throttle switch on (switch 31, switch_input_state_bits.unwired_switch in this build) "
     "and the remote pedal sound, sets remote_throttle_transition_verified_flag once "
     "remote_accelerator_pedal_sensor_filtered is at or below the calculated commanded throttle; with the switch off "
     "or a remote pedal fault (fault bit 78; with channel 8's held value enabled, a J1939 pedal timeout or fault bit "
     "129) it clears it once the calculated commanded throttle is at or below the remote pedal. So the hand-over "
     "between the pedals never jumps"),
    ("0x0050e768", "cm848_initializeRemoteThrottle",
     "Boot initialization of the remote throttle (cm848_applicationMain): clears "
     "remote_throttle_transition_verified_flag and, with algorithm_enable_flags_18_cal.remote_throttle_enable off, "
     "the remote throttle fault bits 171 / 172 (detected and registered). It clears no engine protection fault"),
    ("0x00522468", "cm848_lookupFaultIndexByDtcCode",
     "Searches obd_dtc_code_table (170 fault slots) for the 2-byte OBD DTC code and returns 1 with its slot index, "
     "or 0 (also for code 0). The table holds P-codes (0x0606 = P0606), not SPNs"),
    ("0x0052252c", "cm848_sciCommand52ReportFaultStatusByDtcCallback",
     "SCI diagnostic link next-byte callback of command 52 (cm848_sciCommand52ReportFaultStatusByDtc): collects the "
     "2-byte DTC code, finds its fault slot with cm848_lookupFaultIndexByDtcCode and reports that slot's status"),
]
