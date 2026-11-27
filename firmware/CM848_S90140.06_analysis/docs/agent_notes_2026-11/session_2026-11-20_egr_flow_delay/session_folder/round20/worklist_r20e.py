"""Round 20 stage E (label-only): stage D's cache typing showed mpc555_initFuelDemandOffsetFilter only presets
cold_delta_fuel_cached_axis_offsets; named like its sibling cache initializers (cm848_initialize<table>LookupCache)."""
GLOBALS = []
FUNCTIONS = [
    ("0x0003744c", "cm848_initializeColdDeltaFuelLookupCache",
     "Sets both words of cold_delta_fuel_cached_axis_offsets to 2 (the first segment): the 2-D lookup cache of "
     "cm848_calculateColdDeltaFuel (e2m 8AA2 Cold_Delta_Fuel_Table); it touches no filter"),
]
