"""Round 23 stage A (label-only), part 1: the ambient conditions module's misnamed words and its initializer, and the
PGN 65269 (Ambient Conditions) payload's named rows. The unnamed rows, the new rows and their map rows are
apply_r23a2.py's."""
GLOBALS = [
    ("0x003fb9ea", "ambient_air_flow_filter",
     "First order filter of the fresh air mass flow (charge_flow_estimate_terms.fresh_air_mass_flow_filtered) with "
     "ambient_air_flow_filter_coefficient (e2m 1977 +6 C_AMB_Air_Flow_Fil_Cnst): its output ambient_air_flow_filtered "
     "is the X input of the compressor inlet temperature rise table (cm848_calculateAmbientAndCompressorInletConditions, "
     "cm848_initializeAmbientConditions). It is no boost pressure or timing filter"),
    ("0x003fb9d8", "ambient_air_flow_filtered",
     "The fresh air mass flow after ambient_air_flow_filter: the X input of the compressor inlet temperature rise table"),
    ("0x003fb9d6", "ambient_air_temperature_estimate",
     "The ambient air temperature before the user override: compressor_inlet_temperature minus "
     "compressor_inlet_temperature_rise through ambient_air_temperature_filter, or the default value while "
     "ambient_air_temperature_source is DEFAULT; it keeps its value while the user override is on (then "
     "ambient_air_temperature is the override value). It is no boost fuel timing demand"),
    ("0x003faac2", "j1939_pgn65269_barometric_pressure",
     "PGN 65269 (Ambient Conditions) byte 1: barometric pressure (SPN 108, 0.5 kPa/bit), 0xFE on error"),
    ("0x003faac3", "j1939_pgn65269_cab_interior_temperature",
     "PGN 65269 bytes 2-3: cab interior temperature (SPN 170); 0xFFFF (not available) from "
     "cm848_initJ1939AmbientConditionsBuffer, never built"),
    ("0x003faac8", "j1939_pgn65269_road_surface_temperature",
     "PGN 65269 bytes 7-8: road surface temperature (SPN 79); 0xFFFF (not available) from "
     "cm848_initJ1939AmbientConditionsBuffer, never built"),
]
FUNCTIONS = [
    ("0x00502eb8", "cm848_initializeAmbientConditions",
     "Boot initialization of the ambient conditions module (e2m 1921 / 1977): presets the lookup caches, starts the "
     "ambient air flow and ambient air temperature filters from the current values, sets the first "
     "compressor_inlet_temperature_rise, ambient_air_temperature_estimate, ambient air temperature and its source, "
     "the barometric pressure reference and the compressor inlet pressure, the relative humidity and the altitude"),
]
