"""Round 24 stage B: the commanded throttle record (e2m 1047, the ECU's parameter ID table maps it to 0x40a57a)."""
TYPES = {"fuel_demand_control_t": "commanded_throttle_state_t"}
INSTANCES = {"fuel_demand_control_t_0040a57a": ("0x0040a57a", "commanded_throttle_state", "fuel_demand_control_t")}
E = "e2m 1047"
FIELDS = {"fuel_demand_control_t": {
    "calculated": ("commanded_throttle",
                   f"{E} +0 Commanded_Throttle 'VALIDATED PERCENT THROTTLE COMMANDED BY DRIVER' (0-400 = 0-100 %): the "
                   "calculated commanded throttle, or the alternate throttle while a claim holds "
                   "(cm848_selectCommandedThrottle); read by the governors, cruise and the transmission logic"),
    "rate_limiter_state": ("throttle_transition_state",
                           f"{E} +6 Transition_State 'state of potentiometer and idle validation switch readings': 0-3, "
                           "advanced by cm848_updateThrottleTransitionState; cm848_monitorAcceleratorPedalIdleValidation"
                           "Faults acts in state 3. No rate limiter"),
    "rate_delta": ("throttle_minimum_confidence_counter",
                   f"{E} +8 Current_Confidence_Counter (MSEC) 'CURRENT TIME OF COUNTER THAT MUST TIME OUT BEFORE A NEW "
                   "THROTTLE_MIN IS SET': loaded with accelerator_pedal_minimum_learning_confidence_count_limit when a "
                   "lower pedal reading starts a candidate (throttle_minimum_candidate), counted down by readings within "
                   "the confidence band - the candidate becomes the Throttle_Min at 0 - and up by readings above it"),
    "throttle_based": ("throttle_minimum",
                       f"{E} +A Throttle_Min 'minimum Sampled_Throttle detected' (pedal counts): the learned closed "
                       "pedal reading (cm848_learnAcceleratorPedalAutozero; accelerator_pedal_autozero_cal = it + "
                       "accelerator_pedal_autozero_offset); accelerator_pedal_highest_valid_minimum + 4 at boot and "
                       "while the pedal has a fault"),
    "override_value": ("alternate_throttle",
                       f"{E} +C Alternate_Throttle 'Percent throttle overriden by other algorithm': the throttle a "
                       "claimer sets with its priority (remote_accelerator_pedal_sensor_filtered from "
                       "cm848_claimRemoteThrottleOverride, 0 from cm848_claimAcceleratorInterlockThrottleOverride)"),
    "override_priority": ("alternate_throttle_priority",
                          f"{E} +E Throttle_Selection 'Alternate throttle priority #, 0=normal, 9=high priority': each "
                          "claimer takes the alternate throttle only above the priority already set; "
                          "cm848_selectCommandedThrottle uses alternate_throttle while it is non-zero and clears it "
                          "every pass"),
    "rate_limited": ("calculated_commanded_throttle",
                     f"{E} +10 Calculated_Commanded_Throttle 'Intermediate calculated value of commanded throttle based "
                     "on standard input' (0-400): from cm848_calculateCommandedThrottleFromPedal, "
                     "accelerator_pedal_dual_channel_validated_demand or channel 13 (cm848_selectCommandedThrottle). "
                     "Not rate limited"),
    "override_countdown": ("selected_alternate_throttle_priority",
                           f"{E} +12 Alternate_Throttle_Selection_State 'State of selected alternate throttle "
                           "priority': the alternate_throttle_priority that set the commanded throttle this pass, 0 when "
                           "none did (cm848_selectCommandedThrottle). It never counts down"),
    "reserved_14": ("sampled_frequency_throttle",
                    f"{E} +14 Sampled_Frequency_Throttle 'requested throttle after being lin. and fil. via freq. thr. "
                    "algorithm' (%THROTTLE); no access in the .cpp"),
    "reserved_16": ("frequency_throttle_active_flag",
                    f"{E} +16 Frequency_Throttle_Active 'indicates frequency throttle has been enabled'; no access in "
                    "the .cpp"),
    "delta": ("commanded_throttle_delta",
              f"{E} +18 Delta_Throttle 'Percent Throttle change per execution': commanded_throttle minus the previous "
              "pass's, kept in the high word of throttle_fuel_enable_flag (cm848_selectCommandedThrottle)"),
    "delta_filtered": ("commanded_throttle_delta_filtered",
                       f"{E} +1A Filtered_Delta_Throttle 'Percent Throttle change per execution with filter applied': "
                       "commanded_throttle_delta through commanded_throttle_delta_filter (e2m 1048 +1C "
                       "Delta_Throttle_Filter_Constant)"),
}}
FIELD_NOTES = {"fuel_demand_control_t": {
    "idle_validation_state": f"{E} +2 Throttle_ID 'identifies different combinations of the throttle pot and "
                             "switches'",
    "accelerator_off_idle": f"{E} +4 Throttle_Status 'Status of the idle validation switch IDLE = 0; NOT_IDLE = 1'",
}}
