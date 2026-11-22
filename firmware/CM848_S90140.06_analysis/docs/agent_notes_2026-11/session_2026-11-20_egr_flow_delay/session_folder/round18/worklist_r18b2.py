"""Round 18 stage B, part 2 (label-only): the main timing limits named by the e2m value labels of 103B +8
Final_Timing_State (shared with +4 SOI_State; hex keys 00 FOUR_D / 02 USERCOMD / 05 CRANK / 07 USEROVRD / 08 STOP / 0B
MISFIRE / 12 COMB_MGR / 17 EX_IDLE / 18 CTDRATE / 19 CBR_SOI ...), each checked at its store in
cm848_calculateMainInjectionTiming and its limit word's own record."""
GLOBALS = [
    ("0x0040aee8", "main_injection_timing_misfire_limit",
     "The misfire timing limit (e2m 8A3D +0 Misfire_Timing_Limit 'Output of the misfire timing limit table'): the main "
     "timing is not taken below it (source MAIN_INJECTION_TIMING_SOURCE_MISFIRE_LIMIT, e2m label 0B MISFIRE)"),
    ("0x00409e44", "main_injection_timing_extended_idle_minimum",
     "While low_speed_governor_extended_idle_active_flag is set the main timing is not taken below this (e2m 8085 +4: "
     "'Final_Timing max wins with this'; source label 17 EX_IDLE)"),
    ("0x0040b256", "coolant_overheat_derate_minimum_injection_timing",
     "The main timing minimum of the coolant overheat derate (source label 18 CTDRATE): "
     "cm848_rampCoolantOverheatDerateMinimumInjectionTiming starts it at main_injection_timing when the final fueling "
     "state enters FUELING_STATE_COOLANT_OVERHEAT_DERATE, ramps it toward the engine speed table by the step, and "
     "back down to -1024 (none) outside it; cm848_resetCoolantOverheatFuelDerate sets -1024"),
    ("0x0040876e", "coolant_overheat_derate_minimum_injection_timing_step",
     "ROM: the per-pass step of coolant_overheat_derate_minimum_injection_timing"),
    ("0x0005b096", "coolant_overheat_derate_minimum_injection_timing_axis",
     "The engine speed axis of the coolant overheat derate's main timing minimum (13 breakpoints)"),
    ("0x0005b0b2", "coolant_overheat_derate_minimum_injection_timing_values",
     "The coolant overheat derate's main timing minimum by engine speed"),
]
FUNCTIONS = [
    ("0x00513d08", "cm848_rampCoolantOverheatDerateMinimumInjectionTiming",
     "While the final fueling state is FUELING_STATE_COOLANT_OVERHEAT_DERATE: on entry (the previous state at "
     "0x3fcdc4 was not 46) coolant_overheat_derate_minimum_injection_timing starts at main_injection_timing, then "
     "rises toward the engine speed table (coolant_overheat_derate_minimum_injection_timing_values) by at most "
     "coolant_overheat_derate_minimum_injection_timing_step per pass; outside the derate it falls by the step to "
     "-1024 (no minimum). cm848_calculateMainInjectionTiming keeps the main timing at or above it"),
]
