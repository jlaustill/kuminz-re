"""Stage 10b-3: the TPE vocabulary and leftovers. The ECU's own parameter table names the channel 20 sensor
Compressor_Inlet_Tmptr_Sensor (1966 +10), its selected value Compressor_Inlet_Tmptr (1A0C +0) and the density
Compressor_Inlet_Density (18E8 +0); the ambient air temperature Ambient_Air_Tmptr (1921 +6) is computed from the
compressor inlet temperature minus compressor_inlet_temperature_rise. So the sensor-based values are compressor
inlet ones; the sensor diagnostics (1901 / 1902) and the overrides / default (1977 / 197E) keep their e2m ambient
names. Plus the IMT estimate words (bin 1), the charge temperature estimate (bin 3) and the compressor map tables
(bin 4). Read in the main session: cm848_calculateIntakeManifoldTemperatureLeadCompensation, the IMT filter
initialization, cm848_estimateCompressorOutletTemperature, cm848_calculateAmbientAndCompressorInletConditions."""
GLOBALS = [
    ("0x0040a608", "compressor_inlet_temperature",
     "the selected compressor inlet temperature: cm848_selectCompressorInletTemperature copies the channel 20 sensor "
     "(compressor_inlet_temperature_sensor_value) or its default; cm848_calculateCompressorInletDensity divides by "
     "it, the compressor outlet / charge temperature estimates read it, and ambient_air_temperature is it minus "
     "compressor_inlet_temperature_rise"),
    ("0x0040a60a", "compressor_inlet_temperature_source",
     "the source of compressor_inlet_temperature (0 = primary, 1 = backup, 2 = default); round 3 of this PR had named "
     "it after its sibling's old ambient name"),
    ("0x0040a604", "compressor_inlet_density",
     "cm848_calculateCompressorInletDensity: compressor inlet pressure x 2936512 / the absolute compressor inlet "
     "temperature, slew limited by compressor_inlet_density_negative / positive_rate_limit"),
    ("0x0040a19a", "ambient_air_temperature",
     "cm848_calculateAmbientAndCompressorInletConditions: compressor_inlet_temperature minus the filtered "
     "compressor_inlet_temperature_rise (or the override / default by its source)"),
    ("0x0040a19c", "ambient_air_temperature_source", "the source of ambient_air_temperature"),
    ("0x0040bd90", "compressor_inlet_temperature_sensor_value",
     "sensor channel 20, linearized and filtered (the e2m text says ambient air temperature raw value)"),
    ("0x0040bd9c", "compressor_inlet_temperature_sensor_default_value", "the default of sensor channel 20"),
    ("0x0040bd86", "intake_manifold_temperature_sensor_value",
     "sensor channel 9, the intake manifold (charge) temperature sensor; the e2m names it the charge temperature "
     "sensor and 18D9 calls the selected value Charge_Tmptr (intake_manifold_temperature_filtered)"),
    ("0x0040bd9e", "intake_manifold_temperature_sensor_default_value", "the default of sensor channel 9"),
    ("0x003fa61a", "intake_manifold_temperature_sensor_value_previous",
     "the channel 9 value of the previous pass; the lead compensation uses the difference"),
    ("0x0040520c", "intake_manifold_temperature_lead_charge_flow_axis",
     "charge flow axis of the IMT sensor lag time constant table"),
    ("0x00405220", "intake_manifold_temperature_lead_time_constant_values",
     "the IMT sensor lag time constants over the charge flow axis"),
    ("0x003fa616", "intake_manifold_temperature_lead_time_constant_table_output",
     "the time constant table at charge_mass_flow_filtered; becomes intake_manifold_temperature_lead_time_constant"),
    ("0x003fa624", "intake_manifold_temperature_lag_first_filter",
     "EMA record of the first lag filter (coefficient intake_manifold_temperature_lag_filter_coefficient), input "
     "intake_manifold_temperature_after_lead"),
    ("0x003fa620", "intake_manifold_temperature_lag_first_filter_output", "output of the first lag filter"),
    ("0x003fa62c", "intake_manifold_temperature_lag_second_filter",
     "EMA record of the second lag filter, input the first one's output"),
    ("0x003fa622", "intake_manifold_temperature_lag_second_filter_output", "output of the second lag filter"),
    ("0x0040a456", "charge_temperature_estimate_status", "the quality of charge_temperature_estimate"),
    ("0x003fa60e", "charge_temperature_estimate_filter",
     "EMA record of the charge temperature estimate (coefficient charge_temperature_estimate_filter_coefficient)"),
    ("0x004065c6", "compressor_map_grid",
     "cm848_estimateCompressorOutletTemperature: the 11 x 11 temperature ratio table over the corrected air flow and "
     "the corrected turbocharger speed; output compressor_outlet_temperature_to_inlet_temperature_ratio"),
    ("0x004066b8", "compressor_map_corrected_air_flow_axis", "the corrected air flow axis of compressor_map_grid"),
    ("0x004066d0", "compressor_map_corrected_turbocharger_speed_axis",
     "the corrected turbocharger speed axis of compressor_map_grid"),
    ("0x004066e8", "compressor_inlet_temperature_square_root_axis",
     "compressor inlet temperature axis of the square root table"),
    ("0x00406712", "compressor_inlet_temperature_square_root_values",
     "square root of the absolute compressor inlet temperature over its axis; output "
     "compressor_inlet_temperature_square_root"),
]
FUNCTIONS = [
    ("0x00013aec", "cm848_estimateChargeTemperature",
     "The TPE charge temperature estimate (e2m 1A1A / 1A1B): the compressor inlet temperature reference from the "
     "alpha / chi maps; charge_temperature_estimate = filtered (compressor inlet temperature - reference) x gain + "
     "offset terms; its status"),
    ("0x00013ca4", "cm848_initializeChargeTemperatureEstimate",
     "Seeds the charge temperature estimate filter and its status byte"),
    ("0x005058a8", "cm848_calculateCompressorInletDensity",
     "compressor_inlet_density (e2m 18E8 +0 Compressor_Inlet_Density): compressor inlet pressure x 2936512 / the "
     "absolute compressor inlet temperature, slew limited; the density-based limit tables read it"),
    ("0x005059ec", "cm848_selectCompressorInletTemperature",
     "Chooses compressor_inlet_temperature (e2m 1A0C +0): the channel 20 sensor or its default by the sensor "
     "fault status, with compressor_inlet_temperature_source"),
    ("0x00505b3c", "cm848_initializeCompressorInletTemperature",
     "Boot pass of the compressor inlet temperature input: the source from the channel 20 fault status and the "
     "first value"),
]
