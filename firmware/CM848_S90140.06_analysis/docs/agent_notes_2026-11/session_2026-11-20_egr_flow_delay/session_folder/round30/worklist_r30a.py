"""Round 30 stage A (label-only): the watchdog fueling monitor (fault 388 Watchdog_Fueling_Error, 'fueling is high when
it should not be'), named from the Chrysler e2m blocks 8A70 (0x40894c-0x408953: duration threshold / error debounce /
speed threshold / minimum duration offset), 8B3B (Watchdog_Coolant_Axis) and 8B3D (Watchdog_Coolant_Duration_Table).
8A70 is not in the parameter ID table: it is aligned by offset, and each of its four words matches its code use
(the on-time sum limit, the pass limit, the engine speed gate, the per-event offset). The new rows are in
add_rows_r30a.py."""
M = "cm848_monitorWatchdogFueling"
GLOBALS = [
    ("0x00408952", "watchdog_fueling_minimum_duration_offset",
     f"e2m 8A70 +6 Watchdog_Min_Duration_Offset 'Duration subtracted from each Pilot1, Main, Aux duration, if each "
     f"duration > 0' (0.4 us per count): {M} adds it to watchdog_fueling_duration_offset_sum once per non-zero pulse "
     "width"),
    ("0x00408954", "watchdog_coolant_duration_adjustment_axis",
     "e2m 8B3B Watchdog_Coolant_Axis (DEG_F): the coolant temperature axis of the watchdog duration allowance"),
    ("0x0040895a", "watchdog_coolant_duration_adjustment_values",
     "e2m 8B3D Watchdog_Coolant_Duration_Table (0.4 us per count): the on-time allowance added to "
     "watchdog_fueling_duration_threshold by coolant temperature"),
    ("0x003fce2e", "watchdog_fueling_duration_offset_sum",
     "watchdog_fueling_minimum_duration_offset times the number of non-zero pilot / main / auxiliary pulse widths; "
     "subtracted from their sum"),
    ("0x003fce2c", "watchdog_fueling_debounce_count",
     f"{M}: passes in a row with the excess on-time; fault 388 and logical output request 54 at "
     "watchdog_fueling_error_debounce_limit"),
]
FUNCTIONS = [
    ("0x00516c18", M,
     "The watchdog fueling monitor (e2m 8A70, fault 388 Watchdog_Fueling_Error 'fueling is high when it should not "
     "be'): with nothing demanding fuel (no TSC1 speed / torque control, power take-off governor, cruise, commanded "
     "throttle or accelerator off idle) and average_engine_speed above watchdog_fueling_minimum_engine_speed, the "
     "pilot + main + auxiliary on-time minus the per-event offsets above watchdog_fueling_duration_threshold + the "
     "coolant allowance for watchdog_fueling_error_debounce_limit passes sets fault 388 and logical output request 54"),
    ("0x00516df8", "cm848_initializeWatchdogFueling",
     "Clears fault 388 (detected and registered), logical output request 54 and the coolant allowance lookup cache "
     "(2)"),
]
