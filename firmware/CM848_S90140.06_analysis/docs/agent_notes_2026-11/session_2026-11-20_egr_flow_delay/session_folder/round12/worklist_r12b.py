"""Round 12 stage B (label-only): the fuel metering (CP3 M-PROP) names of cm848_calculateFuelMeteringCommand from the
e2m HPCR_* records - the 8B3C calibration block (aligned at 0x40913a: every record lands on a row, and the coil
temperature estimate gain / offset / sample count match their use), the pump control tables at 0x40915e-0x40948b
(each placed by how the code uses it), their lookup caches, and the coil temperature state. They were cam_sync_* /
engine_sync_* guesses (the function's own plate says so); ROM words lose the _cal suffix (the memory-map rule)."""
B = "e2m 8B3C"
GLOBALS = [
    ("0x0040913a", "fuel_metering_cold_start_temperature",
     f"{B} +0 HPCR_Cold_MPROP_Temperature 'Cold start dutycycle table is used at this temperature' (-40 F in the dump): "
     "the lower bound of the coil temperature blend between the start and hot start duty cycle curves"),
    ("0x0040913c", "fuel_metering_hot_start_temperature",
     f"{B} +2 HPCR_Hot_MPROP_Temperature 'Hot start dutycycle table is used at this temperature': the upper bound of "
     "the coil temperature blend"),
    ("0x0040913e", "fuel_metering_outer_loop_preset_temperature_source",
     f"{B} +4 HPCR_MPROP_Temperature_Flag 'Selects temperature source for current loop int reset' (1 in the dump): the "
     "governor integrator preset from the start duty curves runs when it is 5 (the coil temperature)"),
    ("0x00409142", "fuel_metering_tool_override_command",
     f"{B} +8 HPCR_Dutycycle_Output_Tool_Value: the M-PROP command used for the service tool override"),
    ("0x00409146", "fuel_metering_tool_override_while_running_enable",
     f"{B} +C HPCR_Dutycycle_Output_Tool_State_Flag ('0=Allow CP3 driver override for tool in' engine stopped only): "
     "with 1 the tool override also applies while the engine runs"),
    ("0x00409148", "fuel_metering_coil_resistance_filter_coefficient",
     f"{B} +E HPCR_Coil_Resistance_Filter_Coeff 'Filter applied to calculated coil resistance': the coefficient of "
     "fuel_metering_coil_resistance_filter"),
    ("0x0040914a", "fuel_metering_coil_resistance_minimum_samples",
     f"{B} +10 HPCR_Current_Sample_Minimum_Counts 'Estimated coil temp considered good with this many samples'"),
    ("0x0040914c", "fuel_metering_inner_loop_preset_temperature_source",
     f"{B} +12 HPCR_MPROP_Inner_Loop_Temperature_Flag: the current loop integrator preset runs when it is 5"),
    ("0x00409150", "fuel_metering_coil_initial_resistance",
     f"{B} +16 HPCR_MPROP_Coil_Initial_Resistance 'Initial value at power-up' (0.005 ohm; 620 = 3.1 ohm): "
     "cm848_initializeFuelPressureGovernorState loads fuel_metering_coil_resistance_filtered with it"),
    ("0x00409152", "fuel_metering_startup_pulse_duty_cycle",
     f"{B} +18 HPCR_MPROP_Startup_Pulse_Dutycycle 'Temporary output dutycycle at startup while RPM is zero'"),
    ("0x00409154", "fuel_metering_startup_pulse_time",
     f"{B} +1A HPCR_MPROP_Startup_Pulse_Time 'Duration of temporary dutycycle command at power-up at 0 RPM' (0.01 s; "
     "100 = 1 s)"),
    ("0x00409156", "fuel_metering_coil_temperature_gain",
     f"{B} +1C HPCR_MPROP_Temperature_Gain 'Slope for resistance to temperature calculation': fuel_metering_coil_"
     "temperature = gain x fuel_metering_coil_resistance_filtered / 0x138 + fuel_metering_coil_temperature_offset"),
    ("0x00409158", "fuel_metering_coil_temperature_offset",
     f"{B} +1E HPCR_MPROP_Temperature_Offset 'Offset for resistance to temperature calculation'"),
    ("0x0040915a", "fuel_metering_resistance_minimum_current",
     f"{B} +20 HPCR_Resistance_Current_Threshold 'Min current to allow resistance calculation' (900 mA)"),
    ("0x0040915c", "fuel_metering_resistance_minimum_duty_cycle",
     f"{B} +22 HPCR_Resistance_PWM_Threshold: the minimum duty cycle for a coil resistance sample"),
    ("0x0040915e", "fuel_metering_current_by_duty_cycle_axis",
     "e2m HPCR_Current_Scaling_Dutycycle_Axis ('Norm. curve to calculate current equivalent of duty cycle'): the "
     "governor duty cycle demand axis of the M-PROP current target lookup"),
    ("0x00409174", "fuel_metering_current_by_duty_cycle_values",
     "e2m HPCR_Current_Scaling_Current_Axis: the current target for the duty cycle demand; it feeds the base command "
     "and the current loop reference (fuel_metering_feedback_error = filtered target - filtered feedback)"),
    ("0x0040936e", "fuel_metering_start_duty_cycle_engine_speed_axis",
     "e2m HPCR_Start_Dutycycle_Speed_Axis: the engine speed axis of the start duty cycle curve"),
    ("0x00409380", "fuel_metering_start_duty_cycle_values",
     "e2m HPCR_Start_Dutycycle_Axis: the start duty cycle used at fuel_metering_cold_start_temperature (blended "
     "toward the hot start curve by the coil temperature) to preset the governor integrator"),
    ("0x00409392", "fuel_pressure_governor_feed_forward_engine_speed_axis",
     "e2m HPCR_Dutycycle_Precontrol_Map_RPM_Axis: the engine speed axis of the duty cycle pre-control map"),
    ("0x004093a4", "fuel_pressure_governor_feed_forward_fuel_axis",
     "e2m HPCR_Dutycycle_Precontrol_Map_Fuel_Axis: the injection quantity axis (total_injection_quantity)"),
    ("0x004093b6", "fuel_pressure_governor_feed_forward_grid",
     "e2m HPCR_Dutycycle_Precontrol_Map_Dutycycle_Axis: the duty cycle pre-control (8 x 8), "
     "fuel_pressure_governor_feed_forward"),
    ("0x00409436", "fuel_pressure_governor_maximum_duty_cycle_engine_speed_axis",
     "e2m HPCR_Max_Dutycycle_RPM_Axis ('Engine speed dependent maximum duty cycle curve')"),
    ("0x00409442", "fuel_pressure_governor_maximum_duty_cycle_values",
     "e2m HPCR_Max_Dutycycle_Axis: the upper clamp of fuel_pressure_governor_demand by engine speed (the lower clamp "
     "is fuel_pressure_governor_demand_minimum_when_running / _not_running)"),
    ("0x0040944e", "fuel_metering_hot_start_duty_cycle_engine_speed_axis",
     "e2m HPCR_Hot_Start_Dutycycle_Speed_Axis ('Hot start MPROP dutycycle speed axis')"),
    ("0x00409460", "fuel_metering_hot_start_duty_cycle_values",
     "e2m HPCR_Hot_Start_Dutycycle_Axis: the start duty cycle used at fuel_metering_hot_start_temperature"),
    ("0x00409472", "fuel_metering_battery_correction_voltage_axis",
     "e2m HPCR_Battery_Correction_Voltage_Axis ('Battery voltage axis for voltage based dutycycle correction')"),
    ("0x0040947e", "fuel_metering_battery_correction_factor_values",
     "e2m HPCR_Battery_Correction_Scaling_Factor_Axis: fuel_metering_command x factor / 4096 by the filtered battery "
     "voltage"),
    ("0x003fb640", "fuel_metering_current_by_duty_cycle_cached_axis_offset",
     "Lookup cache of the fuel_metering_current_by_duty_cycle table (cm848_calculateFuelMeteringCommand)"),
    ("0x003fb642", "fuel_pressure_governor_maximum_duty_cycle_cached_axis_offset",
     "Lookup cache of the fuel_pressure_governor_maximum_duty_cycle table (cm848_calculateFuelMeteringCommand)"),
    ("0x003fb658", "fuel_metering_battery_correction_cached_axis_offset",
     "Lookup cache of the fuel_metering_battery_correction table (cm848_calculateFuelMeteringCommand)"),
    ("0x003fb65a", "fuel_metering_start_duty_cycle_cached_axis_offset",
     "Lookup cache of the fuel_metering_start_duty_cycle table (cm848_calculateFuelMeteringCommand)"),
    ("0x003fb65c", "fuel_metering_hot_start_duty_cycle_cached_axis_offset",
     "Lookup cache of the fuel_metering_hot_start_duty_cycle table (cm848_calculateFuelMeteringCommand)"),
    ("0x003fb662", "fuel_pressure_governor_feed_forward_cached_axis_offset",
     "The x word of the fuel_pressure_governor_feed_forward 2-D lookup cache (cm848_calculateFuelMeteringCommand)"),
    ("0x003fb664", "fuel_pressure_governor_feed_forward_cached_axis_offset_y",
     "The y word of the fuel_pressure_governor_feed_forward 2-D lookup cache (only the initializer touches it "
     "directly)"),
    ("0x003fb666", "fuel_metering_unused_cached_axis_offset_1",
     "Set to 2 by cm848_initializeFuelPressureGovernorState with the other fuel metering caches; no lookup uses it in "
     "this build"),
    ("0x003fb668", "fuel_metering_unused_cached_axis_offset_2",
     "Set to 2 by cm848_initializeFuelPressureGovernorState with the other fuel metering caches; no lookup uses it in "
     "this build"),
    ("0x003fb6c3", "fuel_metering_coil_resistance_sample_count",
     "Counts valid coil resistance samples; the coil temperature estimate counts once it reaches "
     "fuel_metering_coil_resistance_minimum_samples (zeroed when a sample is not valid)"),
    ("0x003fb6c5", "fuel_metering_outer_loop_coil_temperature_ready_flag",
     "Set to 1 once the coil temperature estimate is good (and no preset was done); the governor integrator preset "
     "from the start duty curves consumes it when fuel_metering_outer_loop_preset_temperature_source is 5"),
    ("0x003fb6c6", "fuel_metering_inner_loop_coil_temperature_ready_flag",
     "Set to 1 with the outer loop flag; the current loop integrator preset consumes it when "
     "fuel_metering_inner_loop_preset_temperature_source is 5"),
    ("0x0040b899", "fuel_metering_integrator_preset_done_flag",
     "Word: 1 after an integrator preset from the coil temperature (two sites in cm848_calculateFuelMeteringCommand); "
     "while it is 1 the ready flags are not armed again (cm848_initializeFuelPressureGovernorState clears it)"),
    ("0x003fb6b7", "fuel_metering_coil_resistance_filter",
     "The EMA filter of the coil resistance estimate (coefficient fuel_metering_coil_resistance_filter_coefficient) "
     "into fuel_metering_coil_resistance_filtered"),
    ("0x003fb697", "fuel_metering_battery_voltage_filter",
     "The EMA filter of the battery voltage for the M-PROP battery correction (coefficient "
     "fuel_metering_battery_voltage_filter_coefficient)"),
]
FUNCTIONS = []
