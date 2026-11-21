"""Blocks 801A (+E rename, rest keeps), 801E, 805C (bin records 39-51)."""
ENTRIES = []


def keep(address, name, note):
    ENTRIES.append({"kind": "global", "verdict": "keep", "address": address, "old": name, "new": name, "e2m_note": note})


ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x00409524",
    "old": "governor_integrator_hysteresis_cal", "new": "fuel_pressure_governor_demand_check_low_idle_speed_window",
    "evidence": "e2m 801A +E HPCR_Lowidle_Window 'RPM window for monitoring defect during low idle': "
                "cm848_diagnoseFuelPressureGovernor sets diagnostic flag 0x40 only with average_engine_speed strictly inside this "
                "window around governor_output_t.idle_reference_speed (the low speed governor idle reference) while "
                "final_fueling_state is FUELING_STATE_LOW_SPEED_GOVERNOR; 0 in the dump, so the window is empty and the flag cannot "
                "set in this calibration; the old name said governor integrator hysteresis, with a _cal on a ROM copy",
    "code_quote": "cm848_diagnoseFuelPressureGovernor: (uint)governor_integrator_hysteresis_cal) < (int)(uint)average_engine_speed) &&",
    "comment": "e2m 801A +E HPCR_Lowidle_Window 'RPM window for monitoring defect during low idle' (address from the ECU's "
               "parameter ID table) (RPM, 0.125 rpm per count; 0 in the dump): the half width of the speed window of the low idle "
               "check in cm848_diagnoseFuelPressureGovernor. Flag 0x40 of fuel_pressure_diagnostic_flags (fuel_pressure_governor_demand "
               "above fuel_pressure_governor_demand_limit_at_governed_speed, e2m +C) needs average_engine_speed strictly between "
               "governor_output_t.idle_reference_speed (the low speed governor's idle reference speed) minus and plus this word, "
               "vehicle_speed_sensor_ok_flag = 1 with vehicle_speed_copy = 0, the coolant above "
               "fuel_pressure_governor_demand_check_minimum_coolant_temperature (e2m +10) and final_fueling_state = "
               "FUELING_STATE_LOW_SPEED_GOVERNOR. With 0 in the dump the window is empty, so that flag can never set in this "
               "calibration. Not a governor integrator hysteresis. ROM copy, not EEPROM: no _cal.",
})

keep("0x00409528", "fuel_pressure_too_high_recovery_limit",
     "e2m 801A +12 HPCR_Fuelpr_OK_Test_Samples 'Number of OK pressure readings before Complete_Pass' (500 passes below the too "
     "high threshold before the pending flag clears)")
keep("0x0040952a", "fuel_metering_feedback_circuit_low_threshold",
     "e2m 801A +14 HPCR_Current_Min 'Current level at which open-circuit is declared.' (0 in the dump; fuel_metering_feedback_input "
     "below it is the low condition)")
keep("0x00409530", "fuel_pressure_too_high_count_limit",
     "e2m 801A +1A HPCR_Fuelpr_Test_Samples 'Number of overpressure readings before shutdown' (150 passes; type note: the record is "
     "1 byte (+1B is padding) and the only load is lbz, but the row is typed word)")
keep("0x00409538", "fuel_metering_feedback_circuit_low_check_command_limit",
     "e2m 801A +22 HPCR_CP3_Min_Dutycycle_Limit 'Min Dutycycle output to enable CP3 low current diagnostics' (0 in the dump; the low "
     "check needs fuel_metering_command above it)")
keep("0x0040953a", "fuel_metering_feedback_circuit_high_check_command_limit",
     "e2m 801A +24 HPCR_CP3_Max_Dutycycle_Limit 'Max Dutycycle output to enable CP3 high current diagnostics' (0 in the dump; the "
     "high check needs fuel_metering_command below it)")
keep("0x0040953e", "fuel_pressure_setpoint_fault_reaction_cap",
     "e2m 801A +28 HPCR_Leak_Fuelpr_Limit 'Fuel pressure limit during leak detection' (4095 counts = no cap in the dump; it applies "
     "while fault_reaction_request_bits & 4 is set (bit number 2), the same reaction family as +26 fault_reaction_fuel_limit and "
     "+2A fault_reaction_engine_speed_limit)")
keep("0x00409542", "fuel_pressure_too_high_logical_output_request_enable",
     "e2m 801A +2C HPCR_High_Fuelpr_Shutdown_N 'Enable for high fuelpr engine shutdown' (0 in the dump; when set, a too-high bit of "
     "fuel_pressure_diagnostic_snapshot requests logical output 54, which makes the injector diagnostics and the output read-back "
     "debounce skip their checks)")
keep("0x00409598", "fuel_pressure_sensor_volts_high_limit",
     "e2m 801E +0 HPCR_MAX_Fuelpr_Voltage 'Maximum allowed ADC voltage for fuel pressure sensor' (3929 counts = 4.80 V; above it is "
     "sensor code 4, fault 304, P0193)")
keep("0x0040959a", "fuel_pressure_sensor_volts_low_limit",
     "e2m 801E +2 HPCR_MIN_Fuelpr_Voltage 'Minimum allowed ADC voltage for fuel pressure sensor' (164 counts = 0.20 V; below it is "
     "sensor code 8, fault 305, P0192)")
keep("0x0040959c", "fuel_pressure_sensor_recovery_debounce_limit",
     "e2m 801E +4 HPCR_Fuelpr_Time_Intact 'Time for intact classification of fuel pressure sensor' (40 samples = 2 s in the e2m's "
     "50 ms units)")
keep("0x0040959e", "fuel_pressure_sensor_fault_debounce_limit",
     "e2m 801E +6 HPCR_Fuelpr_Time_Defect 'Time for defect classification of fuel pressure sensor' (40 samples = 2 s in the e2m's "
     "50 ms units)")
keep("0x004090f1", "injection_timing_sequence_speed_threshold",
     "e2m 805C +9 HPCR_TPU_RPM_To_Skip_Cylinder 'RPM threshold to skip cylinder while switching to cam based injection' (3200 = 400 "
     "rpm; below it cm848_scheduleInjectionAnglesInSpeedLimpHome steps to the next cylinder (its local index is incremented) and "
     "goes to sequence state 4)")
