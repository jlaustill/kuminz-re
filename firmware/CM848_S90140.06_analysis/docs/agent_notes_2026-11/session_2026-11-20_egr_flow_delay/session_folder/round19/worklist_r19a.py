"""Round 19 stage A (label-only): tables named by the ECU's parameter ID table.
- The main timing's cranking map (e2m 8091 / 8092 / 8093 Main_SOI_Cranking_Speed_Axis / _Cool_Temp_Axis / _SOI_Axis,
  'Main SOI Cranking Map'), which cm848_calculateMainInjectionTiming reads while cranking (round 18 lead; was
  injection_timing_main_cold_start_*).
- The ambient humidity table (e2m 1A98 / 1A99 / 1A9A C_AMB_Humidity_Speed_Axis / _Fuel_Axis / _Table) that gives
  ambient_relative_humidity (1921 +14) in cm848_calculateAmbientAndCompressorInletConditions (was
  boost_fuel_rpm_blend_scale_*).
- The altitude lookup's cache (was governor_adjustment_input_table_row_count, a 'dims' name)."""
GLOBALS = [
    ("0x00060df0", "injection_timing_main_cranking_x_axis",
     "e2m 8091 Main_SOI_Cranking_Speed_Axis 'Speed axis for Main SOI Cranking Map' (engine speed, 9 breakpoints 0-7200 "
     "= 0-900 rpm)"),
    ("0x00060e04", "injection_timing_main_cranking_y_axis",
     "e2m 8092 Main_SOI_Cranking_Cool_Temp_Axis 'Cool Temp axis for Main SOI Cranking Map' (coolant temperature)"),
    ("0x00060e18", "injection_timing_main_cranking_grid",
     "e2m 8093 Main_SOI_Cranking_SOI_Axis 'SOI axis for SOI Cranking Map': the main timing while the engine state is "
     "CRANKING / JUMP_START / REENTRY (source MAIN_INJECTION_TIMING_SOURCE_CRANK)"),
    ("0x003fb708", "injection_timing_main_cranking_cached_axis_offset",
     "Lookup cache (the x segment offset) of the main timing cranking map"),
    ("0x003fb70a", "injection_timing_main_cranking_cached_axis_offset_y",
     "The y segment offset of the main timing cranking map's lookup cache"),
    ("0x003ff3dc", "ambient_relative_humidity_x_axis",
     "e2m 1A98 C_AMB_Humidity_Speed_Axis 'Engine speed axis for ambient humidity table'"),
    ("0x003ff404", "ambient_relative_humidity_y_axis",
     "e2m 1A99 C_AMB_Humidity_Fuel_Axis 'Fueling axis for ambient humidity table' (injection_quantity_combustion_reference)"),
    ("0x003ff426", "ambient_relative_humidity_grid",
     "e2m 1A9A C_AMB_Humidity_Table 'Table for relative humidity of ambient air (0 = dry air, 1 = saturated air)': "
     "ambient_relative_humidity by engine speed x the combustion reference fueling"),
    ("0x003fb9da", "altitude_from_barometric_pressure_cached_axis_offset",
     "Lookup cache of altitude_from_barometric_pressure_axis (barometric_altitude_feet; 2 at power-up)"),
]
FUNCTIONS = []
