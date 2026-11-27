"""Round 10 stage C (label-only), part 2: the 48RE monitors' j1939_ / protection_ leftovers and the transmission
controller's phase functions."""
GLOBALS = [
    ("0x0040b55c", "governor_pressure_rationality_monitor_state",
     "e2m 8C56 +2 RE_Governor_Pressure_Rationality_Status 'Status of transmission governor pressure rat monitor' (its "
     "neighbours +0 / +1 are governor_pressure_rationality_fail_count / _timer). State of the P1762 governor pressure "
     "sensor offset monitor (cm848_monitorGovernorPressureSensorOffset, its only writer): 1 running, 2 passed (fault "
     "149 cleared), 3 failed (fault 149 = P1762 set), 4 aborted while a related fault is active (P0868 / P0869 / "
     "P1756 / P1757 / ECM faults) - latched for the key cycle. cm848_updateTransmissionLimpHomeFlags sets the "
     "governor pressure sensor limp bit (limp_home_flags_3 0x01) when it is 3"),
    ("0x003fcee8", "governor_pressure_rationality_cycle_divider",
     "Byte: the mod-5 rate divider of cm848_monitorGovernorPressureSensorOffset (lbz / stb only there): the monitor "
     "body runs on every 5th call"),
    ("0x003fcee6", "governor_pressure_rationality_tested_in_park_neutral_flag",
     "Word (lhz / sth): 1 once the P1762 offset monitor reached a verdict (a pass, or a fail count step) in the current "
     "park / neutral period; the monitor runs only while it is 0, and it clears when switch 20 (park / neutral) reads "
     "0. Only cm848_monitorGovernorPressureSensorOffset uses it"),
    ("0x003fceea", "governor_pressure_tracking_cycle_divider",
     "Dword (lwz / stw): the 4-pass rate divider of cm848_monitorGovernorPressureTracking (the P1756 / P1757 checks run "
     "when it reaches 4, then it restarts at 0); cm848_initializeGovernorPressureTrackingMonitor zeroes it"),
    ("0x003fcef2", "governor_pressure_zero_check_window_tested_flag",
     "Byte: 1 once the P1757 zero check reached a verdict (a pass, or a fail count step) in the current zero-target "
     "window; the check runs only while it is 0, and it clears when the vehicle moves or governor_pressure_target "
     "rises above governor_pressure_zero_check_target_high_limit"),
    ("0x003fcef3", "governor_pressure_mid_range_check_window_tested_flag",
     "Byte: 1 once the P1756 mid-range check reached a verdict in the current 33-40 psi target window; the check runs "
     "only while it is 0, and it clears when governor_pressure_target leaves the window "
     "(governor_pressure_mid_range_check_target_low_limit .. _high_limit)"),
    ("0x003fb178", "transmission_normal_operation_flag",
     "1 = no actuator or service test owns the transmission outputs (transmission_shift_strategy_flags "
     "actuator_test_flags bit 0 and service_test_request_flags bits 0-2 all clear); 0 while a test runs. Written only "
     "by cm848_updateTransmissionControlInputs; cm848_updateTransmissionControlState and "
     "cm848_runTransmissionControlWhenEnabled run the transmission controller only while it is 1"),
]
FUNCTIONS = [
    ("0x00034a30", "cm848_updateTransmissionRelayRequest",
     "Requests logical output 16 (the transmission control relay: its read-back faults are P0883 / P0882 'TCM power "
     "input high / low') while the engine is not stopped and none of the relay / solenoid circuit limp bits is set "
     "(e2m RE_Trans_Relay_Circuit_Open, RE_Governor_Press_Sol_Circuit, RE_Overdrive_Solenoid_Circuit, "
     "RE_Lockup_Converter_Clutch_Solenoid_Circuit); otherwise drops the relay, which puts the 48RE in limp-home"),
    ("0x00034dd4", "cm848_updateTransmissionLimpHomeFlags",
     "Sets the e2m 8C19 limp-home bits from the fault bits: limp_home_flags_1 0x01 RE_Trans_Relay_Circuit_Open (fault "
     "137 P0882), 0x02 RE_TPS_Elect_Limp (the pedal faults P2121 / P2122 / P2123 / P2127 / P2128 and P0698); "
     "limp_home_flags_2 0x01 RE_Governor_Press_Sol_Circuit (351 P0748), 0x02 RE_Overdrive_Solenoid_Circuit (139 "
     "P0973); limp_home_flags_3 0x01 RE_Gov_Sensor_Limp_Circuit (299 / 300 P0868 / P0869, or the P1762 monitor "
     "failed); limp_home_flags_4 0x10 RE_Lockup_Converter_Clutch_Solenoid_Circuit (141 P2769)"),
    ("0x00033488", "cm848_updateTransmissionControlInputs",
     "Input step of the transmission controller: mirrors the converter clutch and overdrive solenoid requests "
     "(outputs 18 / 17) into the transmission flags, and while no actuator or service test runs sets "
     "transmission_normal_operation_flag, copies cruise engagement into mode_flags 0x10 and computes "
     "transmission_4th_gear_lockup_boost_pressure (gauge, or absolute minus barometric pressure); clears the flag "
     "while a test runs"),
    ("0x00034abc", "cm848_updateTransmissionControlState",
     "State phase of the transmission controller (phase group B, after cm848_selectTransmissionTemperatureInUse): when "
     "the transmission control is enabled (algorithm_enable_flags_6_cal bit 2) it updates the inputs, and in normal "
     "operation the timers, the current gear and lockup inhibit, the condition flags, the output shaft acceleration "
     "and the transmission relay request"),
    ("0x00035328", "cm848_runTransmissionControlWhenEnabled",
     "Control phase of the transmission controller (called right after cm848_updateTransmissionControlState): runs "
     "cm848_runTransmissionControl and cm848_selectGovernorPressureLockupBoost when the transmission control is enabled "
     "(algorithm_enable_flags_6_cal bit 2) and transmission_normal_operation_flag is set"),
    ("0x0051aecc", "cm848_initializeGovernorPressureTrackingMonitor",
     "Initializes the P1756 / P1757 governor pressure tracking monitor (cm848_monitorGovernorPressureTracking): both "
     "check states (e2m 8C58 +2 / +8) to not run, the mid-range fault reported flag and the rate divider to 0"),
    ("0x000384d0", "cm848_initializeAlternatorFieldControl",
     "Initializes the alternator field controller: the lookup caches, the regulator state, the duty / PID terms, the "
     "charging voltage condition timers, the field cut test (and its fault bits 368-370), then enables the field "
     "output driver from alternator_field_output_channel_cal"),
]
