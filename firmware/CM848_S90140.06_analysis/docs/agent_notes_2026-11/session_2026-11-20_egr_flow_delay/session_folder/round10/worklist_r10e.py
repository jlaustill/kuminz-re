"""Round 10 stage E (label-only): the P1740 converter clutch / overdrive rationality monitor's protection_ leftovers
(cm848_monitorConverterClutchAndOverdrivePerformance) and its initializer. The e2m 8C34 records of the monitor are
already mapped at 0x40b57a; these words are its working copies with no e2m record."""
GLOBALS = [
    ("0x003fcefc", "converter_clutch_rationality_lockup_started_flag",
     "1 once the monitor took the first sample of the current lockup (or skipped it: unsteady throttle, overdrive "
     "request changed); 0 while the converter clutch solenoid (output 18) is off and the first lockup was not in third "
     "gear. The monitor starts a test (converter_clutch_rationality_monitor_state 1) only on a lockup with the flag 0"),
    ("0x003fcefe", "converter_clutch_rationality_previous_ratio",
     "The previous sample of the engine speed to transmission output speed ratio (cm848_calculateEngineToOutputSpeedRatio, "
     "1/256): taken every pass while unlocked and after each ratio sample; cm848_calculateConverterClutchRatioDelta "
     "subtracts the new sample (converter_clutch_rationality_ratio) from it"),
    ("0x003fcf00", "converter_clutch_rationality_previous_throttle",
     "A copy of converter_clutch_rationality_last_throttle (the previous pass's fuel demand): every exit path writes it "
     "(one sth after the compiler merged the stores), and no load of it exists in this build"),
    ("0x003fcf02", "converter_clutch_rationality_cycle_divider",
     "The 5-pass rate divider of the P1740 monitor: the body runs when it reaches 5, then it restarts at 0 (every "
     "abort path zeroes it too)"),
    ("0x003fcf04", "converter_clutch_rationality_last_throttle",
     "The previous pass's fuel demand (fuel_demand_control_t_0040a57a.calculated): the monitor compares it with the "
     "current one against converter_clutch_maximum_throttle_delta (e2m 8C33 TCC_Max_Delta_Throttle) to count steady "
     "throttle passes. 0xffff = no sample yet (cm848_initializeConverterClutchRationalityMonitor), which skips the pass"),
    ("0x003fcf06", "converter_clutch_rationality_overdrive_request_snapshot",
     "The overdrive solenoid request (output 17, logical_output_request_bits_16_to_23 mask 2) taken while the "
     "converter clutch is unlocked; a lockup is tested only while the request still equals it"),
]
SCI = ("The SCI command 0x13 actuator tests (DRB 'actuator test' codes, names from the DRB database mydb: 13-09 A/C "
       "clutch relay, 13-0C cruise vacuum + vent, 13-0F torque converter clutch, 13-16 overdrive solenoid, 13-1A / "
       "13-1B cruise vent / vacuum, 13-28 / 13-29 intake heater 1 / 2, 13-2C cruise 12 volt feed, 13-33 fuel transfer "
       "pump, 13-43 transmission relay, 13-49 wait to start lamp, 13-5D exhaust brake, 13-5E fuel control, 13-5F PWM "
       "radiator fan)")
GLOBALS += [
    ("0x003fcf3c", "sci_output_test_active_count",
     f"Byte: the number of running SCI actuator tests. {SCI}. cm848_sciStartTimedOutputTest and the 13-5E / 13-5F "
     "cases add one per test started, cm848_stepSciOutputTest / cm848_stopSciOutputTest / the 13-5E / 13-5F "
     "countdowns remove it; while it is non-zero transmission_shift_strategy_flags.actuator_test_flags bit 0 is set "
     "(which clears transmission_normal_operation_flag)"),
    ("0x003fcf3d", "sci_output_test_drive_phase_flag",
     "Byte: the on / off phase of the SCI actuator tests: cm848_updateSciOutputTests flips it every 141 passes (the "
     "0x8c reload of sci_output_test_phase_countdown), and each running test drives its output on (1) or off (0) with "
     "it - the DRB tests pulse the outputs"),
    ("0x003fcf3e", "sci_output_test_phase_countdown",
     "Word: passes left in the current phase of the SCI actuator tests (reload 0x8c = 140); at 0 "
     "cm848_updateSciOutputTests flips sci_output_test_drive_phase_flag and steps every test timer. Zeroed when the "
     "first test starts"),
    ("0x0040b890", "fuel_control_actuator_test_active_flag",
     "Byte: the 'fuel control' actuator test is running - SCI 13-5E (11 phases, cm848_sciCommand19OutputTestCallback) "
     "or the end-of-line test (end_of_line_test_enable_flags bit 6, engine_coldStart_protection_stateMachine). "
     "cm848_calculateFuelMeteringCommand reads it"),
    ("0x0040b2c2", "cooling_fan_actuator_test_active_flag",
     "Word: the 'PWM radiator fan' actuator test is running - SCI 13-5F (11 phases) or the end-of-line test "
     "(end_of_line_test_enable_flags bit 7). cm848_selectCoolingFanDutySource reads it"),
]
FUNCTIONS = [
    ("0x0051c2d0", "cm848_initializeConverterClutchRationalityMonitor",
     "Initializes the P1740 converter clutch / overdrive rationality monitor: converter_clutch_rationality_last_throttle "
     "= 0xffff (no throttle sample yet)"),
    ("0x0051e6e0", "cm848_updateSciOutputTests",
     f"Runs the SCI actuator tests while any is active: {SCI}. With the engine stopped, every 141 passes it flips "
     "sci_output_test_drive_phase_flag and steps each test timer (cm848_stepSciOutputTest) and the 13-5E / 13-5F "
     "countdowns; once the engine runs it stops every test (cm848_stopAllSciOutputTests). When none is left it clears "
     "the transmission actuator test flag (actuator_test_flags bit 0)"),
    ("0x0051e624", "cm848_stepSciOutputTest",
     "One phase step of one SCI actuator test (timer pointer, logical output): decrements the timer; at 0 the test "
     "ends (sci_output_test_active_count - 1, the output request at priority 5 is cleared and the priority released), "
     "otherwise the output is driven on or off by sci_output_test_drive_phase_flag"),
    ("0x0051e490", "cm848_stopSciOutputTest",
     "Stops one running SCI actuator test (timer pointer, logical output): sci_output_test_active_count - 1, clears "
     "the output request at priority 5, releases the priority and zeroes the timer"),
    ("0x0051e514", "cm848_stopAllSciOutputTests",
     "Stops every SCI actuator test: cm848_stopSciOutputTest for the 12 output tests, then the 13-5E fuel control and "
     "13-5F radiator fan tests (their flags and countdowns)"),
]
