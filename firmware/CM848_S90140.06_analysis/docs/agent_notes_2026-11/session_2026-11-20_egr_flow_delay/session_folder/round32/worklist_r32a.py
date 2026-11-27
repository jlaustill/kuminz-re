"""Round 32 stage A: the discrete output read-back checks (named rows and functions; the struct instances, retry
words and the prototype are in apply_r32a.py)."""
C = "cm848_checkDiscreteOutputReadBack"
GLOBALS = [
    ("0x003fd27e", "discrete_output_read_back_pass_count",
     f"cm848_monitorDiscreteOutputReadBack: counts passes and runs the {C} batch on every fifth (key on, no driver "
     "ASIC shutoff); cleared at a key-off"),
    ("0x003fd293", "ignition_key_off_count_previous",
     "cm848_monitorDiscreteOutputReadBack's copy of ignition_key_off_count: a change (a key-off) turns the intake air "
     "heater and lift pump outputs off and restarts the pass count"),
]
FUNCTIONS = [
    ("0x00537c64", C,
     "The read-back check of one discrete output: when the read-back line disagrees with the commanded logical output "
     "it debounces (commanded on, reads off: on_mismatch_count, then up to auxiliary_driver_toggle_count_limit retries "
     "of the output in retry_count, then the high fault bit; commanded off, reads on: off_mismatch_count, then the low "
     "fault bit); while they agree a registered fault clears after its recovery count. Outputs 19 / 20 (the cruise "
     "vent / vacuum solenoids) use the cruise thresholds and the vacuum throttle actuator state"),
    ("0x00538278", "cm848_monitorDiscreteOutputReadBack",
     f"Runs {C} for 11 discrete outputs (A/C, engine brake 1, intake air heaters 1 / 2, lift pump, transmission relay / "
     "overdrive / converter clutch, cruise vent / vacuum / servo supply) every fifth pass with the key on; at a key-off "
     "it turns the heater and lift pump outputs off"),
    ("0x00538748", "cm848_initializeDiscreteOutputReadBackChecks",
     "Clears the 11 outputs' read-back counters and retry counts"),
]
