"""Blocks 1966 (+7C..+82) and 1B2C (bin records 22-27)."""
ENTRIES = []

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0040bdfc",
    "old": "sensor_channel54_value", "new": "injector_driver_booster_capacitor_1_voltage_sensor_value",
    "evidence": "e2m 1966 +7C Booster_Cap_1_Volt_Sensor 'Booster_Cap_1_Voltage linearized and filtered value': the value output of "
                "sensor channel 54 (0x36), whose tables are injector_group_a_supply_voltage_linearization_* and whose low fault bit "
                "329 gives P2146 (fuel injector group A supply voltage); cm848_protection_timer_init tests slots 54 / 55 against "
                "fuel_system_hardware_shutdown_error_threshold (e2m 8041 +2A, the booster capacitor voltage level); the old name "
                "was the unidentified channel placeholder; the row is written through a pointer argument, no direct access",
    "code_quote": "cm848_processProtectionParameter1: 0x36,0x148,0x149,&sensor_channel54_value,&sensor_channel54_default_value,",
    "comment": "e2m 1966 +7C Booster_Cap_1_Volt_Sensor 'Booster_Cap_1_Voltage linearized and filtered value' (address from the "
               "ECU's parameter ID table) (VOLT, 0.000976525 V per count; 640 = 0.625 V in the dump): the filtered value of sensor "
               "channel 54, the voltage of the injector driver's first booster capacitor. The channel's tables are "
               "injector_group_a_supply_voltage_linearization_axis / _values and its low fault bit 329 (0x149) gives P2146 (fuel "
               "injector group A supply voltage), so this is the same signal; cm848_protection_timer_init compares the QADC "
               "results of slots 54 and 55 with fuel_system_hardware_shutdown_error_threshold (e2m 8041 +2A, the booster capacitor "
               "voltage level). Written through the value output pointer of sensorChannelTypeB_configInit / _update by "
               "cm848_initProtectionParameter1 / cm848_processProtectionParameter1 (no direct displacement access). Working RAM, "
               "never _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0040bdfe",
    "old": "sensor_channel54_default_value",
    "new": "injector_driver_booster_capacitor_1_voltage_sensor_default_value",
    "evidence": "e2m 1966 +7E Booster_Cap_1_Volt_Default 'Booster_Cap_1_Voltage Default value': the default output of sensor channel "
                "54 (the channel configuration's default word, used while the channel fault is confirmed), the same channel as "
                "e2m +7C; the old name was the unidentified channel placeholder; written through a pointer argument",
    "code_quote": "cm848_processProtectionParameter1: 0x36,0x148,0x149,&sensor_channel54_value,&sensor_channel54_default_value,",
    "comment": "e2m 1966 +7E Booster_Cap_1_Volt_Default 'Booster_Cap_1_Voltage Default value' (address from the ECU's parameter ID "
               "table) (VOLT, 0.000976525 V per count; 640 = 0.625 V in the dump): the default of sensor channel 54, the injector "
               "driver's first booster capacitor voltage (see injector_driver_booster_capacitor_1_voltage_sensor_value, e2m +7C). "
               "The sensor channel function copies the channel configuration's default word (the config block at 0x5b55c) into it "
               "and the channel substitutes it while its fault is confirmed. Written through the default value output pointer of "
               "sensorChannelTypeB_configInit / _update by cm848_initProtectionParameter1 / cm848_processProtectionParameter1. "
               "Working RAM, never _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0040be00",
    "old": "sensor_channel55_value", "new": "injector_driver_booster_capacitor_2_voltage_sensor_value",
    "evidence": "e2m 1966 +80 Booster_Cap_2_Volt_Sensor 'Booster_Cap_2_Voltage linearized and filtered value': the value output of "
                "sensor channel 55 (0x37), whose tables are injector_group_b_supply_voltage_linearization_* and whose low fault bit "
                "331 gives P2149 (fuel injector group B supply voltage); cm848_protection_timer_init tests slots 54 / 55 against "
                "fuel_system_hardware_shutdown_error_threshold (e2m 8041 +2A, the booster capacitor voltage level); the old name "
                "was the unidentified channel placeholder; written through a pointer argument",
    "code_quote": "cm848_processProtectionParameter2: 0x37,0x14a,0x14b,&sensor_channel55_value,&sensor_channel55_default_value,",
    "comment": "e2m 1966 +80 Booster_Cap_2_Volt_Sensor 'Booster_Cap_2_Voltage linearized and filtered value' (address from the "
               "ECU's parameter ID table) (VOLT, 0.000976525 V per count; 640 = 0.625 V in the dump): the filtered value of sensor "
               "channel 55, the voltage of the injector driver's second booster capacitor. The channel's tables are "
               "injector_group_b_supply_voltage_linearization_axis / _values and its low fault bit 331 (0x14b) gives P2149 (fuel "
               "injector group B supply voltage), so this is the same signal; cm848_protection_timer_init compares the QADC "
               "results of slots 54 and 55 with fuel_system_hardware_shutdown_error_threshold (e2m 8041 +2A, the booster capacitor "
               "voltage level). Written through the value output pointer of sensorChannelTypeB_configInit / _update by "
               "cm848_initProtectionParameter2 / cm848_processProtectionParameter2 (no direct displacement access). Working RAM, "
               "never _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0040be02",
    "old": "sensor_channel55_default_value",
    "new": "injector_driver_booster_capacitor_2_voltage_sensor_default_value",
    "evidence": "e2m 1966 +82 Booster_Cap_2_Volt_Default 'Booster_Cap_2_Voltage Default value': the default output of sensor channel "
                "55 (the channel configuration's default word, used while the channel fault is confirmed), the same channel as "
                "e2m +80; the old name was the unidentified channel placeholder; written through a pointer argument",
    "code_quote": "cm848_processProtectionParameter2: 0x37,0x14a,0x14b,&sensor_channel55_value,&sensor_channel55_default_value,",
    "comment": "e2m 1966 +82 Booster_Cap_2_Volt_Default 'Booster_Cap_2_Voltage Default value' (address from the ECU's parameter ID "
               "table) (VOLT, 0.000976525 V per count; 640 = 0.625 V in the dump): the default of sensor channel 55, the injector "
               "driver's second booster capacitor voltage (see injector_driver_booster_capacitor_2_voltage_sensor_value, e2m +80). "
               "The sensor channel function copies the channel configuration's default word (the config block at 0x5b56c) into it "
               "and the channel substitutes it while its fault is confirmed. Written through the default value output pointer of "
               "sensorChannelTypeB_configInit / _update by cm848_initProtectionParameter2 / cm848_processProtectionParameter2. "
               "Working RAM, never _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x00409ef4",
    "old": "cam_sync_validation_crank_tick_min", "new": "fuel_pressure_sensor_pre_start_check_minimum_run_time",
    "evidence": "e2m 1B2C +8 Fuel_Pressure_Keyon_Rat_Run_Time 'Maximum amount of time allowed between keyon and engine start': "
                "hpcr_checkRailPressureSensorBeforeStart counts passes in ENGINE_STATE_STOPPED (cam_sync_validation_crank_tick_count) "
                "and needs the count at or above it before the engine leaves STOPPED (else abort code 5) and before it takes the "
                "pass / fail verdict, so the code uses it as a minimum while the e2m text reads maximum; the old name said cam sync",
    "code_quote": "hpcr_checkRailPressureSensorBeforeStart: else if (cam_sync_validation_crank_tick_count < cam_sync_validation_crank_tick_min) {",
    "comment": "e2m 1B2C +8 Fuel_Pressure_Keyon_Rat_Run_Time 'Maximum amount of time allowed between keyon and engine start' "
               "(address from the ECU's parameter ID table) (CNTS; 20 in the dump): the number of key-on passes the rail pressure "
               "sensor key-on check (P0191, fault 414) must have counted with the engine stopped. "
               "hpcr_checkRailPressureSensorBeforeStart counts passes in ENGINE_STATE_STOPPED in "
               "cam_sync_validation_crank_tick_count (0x3fd1de); once the engine has left STOPPED a count below this aborts the "
               "check (fuel_pressure_sensor_pre_start_check_abort_code 5, the e2m's 'keyon too long') and the pass / fail verdict "
               "is only taken with the count at or above it. The code compares count < this word, so it acts as a minimum although "
               "the e2m text says maximum. Not a cam sync. ROM copy, not EEPROM: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x00409ef8",
    "old": "cam_sync_validation_dwell_limit", "new": "fuel_pressure_sensor_pre_start_check_start_delay",
    "evidence": "e2m 1B2C +C Fuel_Pressure_Rationality_Start_Delay 'Delay after keyon before reading Chry_Dat42 from cluster': "
                "hpcr_checkRailPressureSensorBeforeStart counts cam_sync_validation_dwell_counter up each pass and waits while it "
                "is at or below this word before it reads the cluster's engine off time (pci_receive_message_14_engine_off_time) "
                "and runs the check; the old name said cam sync",
    "code_quote": "hpcr_checkRailPressureSensorBeforeStart: if (cam_sync_validation_dwell_counter <= cam_sync_validation_dwell_limit) {",
    "comment": "e2m 1B2C +C Fuel_Pressure_Rationality_Start_Delay 'Delay after keyon before reading Chry_Dat42 from cluster' "
               "(address from the ECU's parameter ID table) (CNTS; 30 in the dump): the start delay of the rail pressure sensor "
               "key-on check (P0191, fault 414). While the check is armed (fuel_pressure_sensor_pre_start_check_state 1) "
               "hpcr_checkRailPressureSensorBeforeStart counts cam_sync_validation_dwell_counter (0x3fd1dc) up each pass until it "
               "exceeds this word; only then does it read the cluster's engine off time (pci_receive_message_14_engine_off_time) "
               "and start sampling the sensor volts, and the verdict also needs the counter past it. Not a cam sync. ROM copy, not "
               "EEPROM: no _cal.",
})
