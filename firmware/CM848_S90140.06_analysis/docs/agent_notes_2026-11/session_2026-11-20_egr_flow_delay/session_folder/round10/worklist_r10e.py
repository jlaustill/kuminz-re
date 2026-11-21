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
FUNCTIONS = [
    ("0x0051c2d0", "cm848_initializeConverterClutchRationalityMonitor",
     "Initializes the P1740 converter clutch / overdrive rationality monitor: converter_clutch_rationality_last_throttle "
     "= 0xffff (no throttle sample yet)"),
]
