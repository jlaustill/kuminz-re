"""Round 8 stage E (main session, label-only): the 48RE timers the timer tick still counted under protection_* names,
the converter clutch engagement monitor and the high gear governor pressure mode. Each timer is named by the cal it
reloads from; the engagement windows are proved against the gear ratio table (speed ratio = engine / output speed x 32:
2nd 43-50 around 46, 3rd 28-35 around 32, 4th 19-25 around 20)."""

GLOBALS = [
    ("0x0040b0dc", "transmission_cruise_downshift_delay_timer",
     "Cruise decel 4-3 downshift delay (cm848_protectionStateTransitionCheck): reloaded from "
     "transmission_cruise_downshift_delay_time (e2m 8BBC +4E RE_Cruise_Downshift_Timer_Max) until, in 4th below "
     "transmission_cruise_downshift_maximum_throttle, the vehicle speed is above the cruise command + "
     "cruise_set_speed_overspeed_margin and the output shaft accelerates; at 0 (and the output speed below "
     "overdrive_downshift_maximum_output_speed) the 4-3 request (condition_eval bit 1) is set"),
    ("0x0040b0de", "transmission_cruise_upshift_delay_timer",
     "Cruise decel 3-4 upshift delay: reloaded from transmission_cruise_upshift_delay_time (e2m 8BBC +50 "
     "RE_Cruise_Upshift_Timer_Max) while the vehicle speed stays above the cruise command + margin after a cruise decel "
     "downshift; at 0, in 3rd above transmission_cruise_downshift_maximum_throttle, the 3-4 request (condition_eval bit 2) "
     "is set"),
    ("0x0040b0e6", "governor_pressure_wide_open_throttle_anti_hang_timer",
     "WOT anti-hang timer (cm848_selectGovernorPressureWideOpenThrottle): loaded from "
     "governor_pressure_wide_open_throttle_anti_hang_time (e2m 8BBC +5A RE_WOT_Anti_Hang_Timer_Max, 700 = 7 s) when the "
     "engine speed first sits above governor_pressure_wide_open_throttle_anti_hang_engine_speed (3000 rpm) but below "
     "governor_pressure_wide_open_throttle_upshift_command_engine_speed (status_flags bit 4 arms it). While it runs the "
     "WOT hold pressure stays (pressure states 7 / 9); at 0 the boost pressure forces the upshift (states 8 / 10), "
     "e2m: 'Used to allow WOT upshift at lowered RPM target'. Counted down by cm848_decrementTransmissionTimers"),
    ("0x00408302", "governor_pressure_wide_open_throttle_upshift_target_engine_speed",
     "Engine speed the WOT 1-2 / 2-3 upshifts aim to finish at: 24600 = 3075 rpm (x 8). "
     "cm848_selectGovernorPressureWideOpenThrottle commands the upshift this far ahead of it: engine acceleration x "
     "the predicted shift delay"),
    ("0x0040b0be", "governor_pressure_wide_open_throttle_upshift_command_engine_speed",
     "Engine speed at which the WOT upshift is commanded: governor_pressure_wide_open_throttle_upshift_target_engine_speed "
     "- transmission_engine_acceleration x transmission_predicted_1_2_shift_delay (or _2_3_) x 1000 / 100, floored at 0; "
     "above it the boost pressure forces the upshift (pressure states 8 / 10). Stored for the record only: the compare "
     "uses the register"),
    ("0x0040b14c", "converter_clutch_engagement_timer",
     "Converter clutch engagement timeout (cm848_monitorConverterClutchEngagement): reloaded from "
     "converter_clutch_engagement_time_limit while no engagement is pending; at 0 it sets the lockup inhibit "
     "(condition_eval bit 6). 300 in the RAM dump (no engagement pending). The e2m 8C17 record at this offset (+4A "
     "RE_E_Brake_Inhibit_Timer) does not fit the code, so 8C17 drifts from +4A in 11.46"),
    ("0x0040838a", "converter_clutch_engagement_time_limit",
     "Time a converter clutch engagement has to show lock (transmission_speed_ratio inside the gear's locked window) "
     "before the lockup inhibit is set: 300 = 3 s (10 ms passes)"),
    ("0x003fb1ca", "converter_clutch_solenoid_request_previous",
     "Last pass's converter clutch solenoid request (logical_output_request_bits_16_to_23 byte & 4 = logical output 18); "
     "cm848_monitorConverterClutchEngagement detects the request's edges with it"),
    ("0x003fb1cc", "converter_clutch_engagement_pending_previous",
     "Last pass's converter_clutch_transition_state bit 0 (engagement pending) as 0 / 1; "
     "cm848_monitorConverterClutchEngagement clears the pending bit at the request's falling edge only when it has not "
     "changed since"),
    ("0x0040837c", "transmission_2nd_gear_locked_speed_ratio_minimum",
     "Lower edge of the 2nd gear locked-converter window of transmission_speed_ratio (x 32): 43 = 1.34; the 2nd gear "
     "ratio is 46 = 1.44 (transmission_gear_ratio_table[2])"),
    ("0x0040837e", "transmission_2nd_gear_locked_speed_ratio_maximum",
     "Upper edge of the 2nd gear locked-converter window: 50 = 1.56"),
    ("0x00408380", "transmission_3rd_gear_locked_speed_ratio_minimum",
     "Lower edge of the 3rd gear locked-converter window: 28 = 0.88; the 3rd gear ratio is 32 = 1.00"),
    ("0x00408382", "transmission_3rd_gear_locked_speed_ratio_maximum",
     "Upper edge of the 3rd gear locked-converter window: 35 = 1.09"),
    ("0x00408384", "transmission_4th_gear_locked_speed_ratio_minimum",
     "Lower edge of the 4th gear locked-converter window: 19 = 0.59; the 4th gear ratio is 20 = 0.63"),
    ("0x00408386", "transmission_4th_gear_locked_speed_ratio_maximum",
     "Upper edge of the 4th gear locked-converter window: 25 = 0.78"),
]
FUNCTIONS = [
    ("0x00034f4c", "cm848_monitorConverterClutchEngagement",
     "Confirms each converter clutch engagement. The rising edge of the converter clutch solenoid request (logical "
     "output 18) sets bit 0 of converter_clutch_transition_state (engagement pending), and converter_clutch_engagement_timer "
     "counts down from converter_clutch_engagement_time_limit (3 s). While the request is on and transmission_speed_ratio "
     "is inside the gear's locked window (transmission_2nd / 3rd / 4th_gear_locked_speed_ratio_minimum / _maximum, "
     "around the gear ratios: no converter slip), bits 0 and 2 clear: the engagement is confirmed. In 1st they clear "
     "too. If the timer runs out first, it sets the lockup inhibit (condition_eval bit 6) and bit 2 (engagement timed "
     "out), and bit 2 clears again when the inhibit clears"),
    ("0x00035154", "cm848_selectGovernorPressureHighGear",
     "The 48RE high gear governor pressure mode (pressure state 0x10): in 3rd / 4th outside transfer-case low range, "
     "with the lever not in 1 / 2 (transmission_selected_gear 0x7e / 0x7f), lockup not inhibited (condition_eval bit "
     "6), transmission_overheat_protection_active_flag clear and switch 12 off, while the throttle is below the "
     "output-speed curve (or the second curve once in the mode, held by load_condition_flags bit 2), the target is "
     "governor_pressure_high_gear_target. With the lever in 1 / 2 and the output speed below "
     "protection_derate_ramp_exit_threshold_cal it requests the 4-3 downshift (condition_eval bit 1, clearing the 3-4 "
     "bit 2) unless overdrive_control_flags bit 3 is set"),
]
