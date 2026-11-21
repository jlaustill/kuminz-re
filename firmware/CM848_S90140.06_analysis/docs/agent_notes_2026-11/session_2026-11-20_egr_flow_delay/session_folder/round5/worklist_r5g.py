"""Round 5 stage g: the two leftovers next to round 5's renames (the final review)."""
GLOBALS = [
    ("0x0040b1e6", "air_conditioning_condition_code_2",
     "cm848_controlAirConditioningClutchForDrTruck writes it beside air_conditioning_condition_code in every branch "
     "(1-15; 5 at initialization); no reader in the decompile (a diagnostic table may read it)"),
    ("0x003fd051", "cruise_governor_preset_this_pass_flag",
     "cm848_presetCruiseAndVehicleSpeedLimitGovernor sets it; cm848_runCruiseAndVehicleSpeedLimitGovernor presets the "
     "governor again on a zone transition only when it is 0, then clears it"),
]
FUNCTIONS = []
