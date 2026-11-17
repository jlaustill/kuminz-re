"""Add the two sensor configs that had no row (their interior labels were dropped)."""
import sys

sys.path.insert(0, sys.argv[1])
import lookup_tables as L

changes = {
    0x000592a2: ("barometric_pressure_sensor_config", "sensor_channel_config_t",
                 "Calibration block of sensor channel 3 (barometric pressure - AMB SPN 108); its default_value is the "
                 "fixed reference cm848_calculateBoostPressure subtracts when it uses no barometer (was the interior "
                 "label boost_pressure_fixed_reference)"),
    0x003fefba: ("accelerator_pedal_sensor_config", "sensor_channel_config_t",
                 "Calibration block of sensor channel 13 (accelerator pedal); its default_value is the J1939 pedal "
                 "fallback position cm848_processJ1939AcceleratorPedalPosition loads on a timeout (was the interior "
                 "label j1939_accelerator_pedal_default_position)"),
}
print(L.write_rows(f"{sys.argv[1]}/../CM848_S90140.06_analysis/output/global_variables.csv", changes))
