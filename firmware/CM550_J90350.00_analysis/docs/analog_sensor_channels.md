# CM550 analog sensor channels (J90350.00)

The A/D channel loop `mc68k_processAnalogSensorChannels` (0xb7bc) and its start-up routine `cm550_initializeAnalogSensorChannels` (0xbcf0) walk two arrays of 25 records in step, one record per channel:

| Array | Type | First record | Stride | e2m block |
|---|---|---|---|---|
| Configuration | `sensor_config_t` | 0x806ae2 | 24 bytes | 1003 |
| Runtime state | `sensor_state_t` | 0x80a2aa | 22 bytes | 1004 |

The Calterm names come from `e2m-analysis/originals/v64t6_s.e2m`. Its block 1003 / 1004 layout agrees with every J90350.00 global that carried an e2m name before PR #53 round 89 (410 of 447 rows). The other 37: the 25 filter constants that round 88 had renamed, ambient air temperature's older mnemonics (ADTTFT / ADTTUF / ADTTMU) and nine throttle position sensor supply voltage config rows that carried boost pressure table names (ADBSPRXA / ADBSPRYA entries) that do not belong there. The ECU's parameter ID table gives the two blocks' addresses (`output/parameter_id_lookup_table.csv`: 0x1003 -> 0x806ae2 and 0x1004 -> 0x80a2aa; `firmware/scripts/e2m_block_addresses.py` resolves CM848 only).

CM848 is a counterpart, not a twin: `sensor_channel_config_t` holds the same parameter family in another order, and its filter records are standalone `ema_filter_state_t` globals outside its 12-byte `sensor_channel_state_t` records.

## Fields and their Calterm suffixes

A Calterm name is the channel's stem plus the suffix (ADIMTP + CS = ADIMTPCS). The default value, a few channels' runtime values and one low limit use other names; the channel table lists every exception.

| Record | Offset | Field | Suffixes | e2m description (channel 0) |
|---|---|---|---|---|
| config | +0 | `filter_coefficient` | CS; 1 other name | A/D DIGITAL FILTER CONSTANT FOR INTAKE MANIFOLD TEMPERATURE |
| config | +2 | `default_value` | GD; 9 other names | GLOBAL DEFAULT VALUE FOR INTAKE MANIFOLD TEMPERATURE |
| config | +4 | `fault_clear_threshold` | CC (13) / FC (12) | A/D FAULT CLEAR COUNTS FOR INTAKE MANIFOLD TEMPERATURE |
| config | +6 | `debounce_counter_decrement` | FD (13) / DT (12) | A/D FAULT DECREMENT FOR INTAKE MANIFOLD TEMPERATURE |
| config | +8 | `debounce_counter_increment` | FI (13) / IC (12) | A/D FAULT INCREMENT FOR INTAKE MANIFOLD TEMPERATURE |
| config | +10 | `fault_set_threshold` | FS (13) / SE (12) | A/D FAULT SET FOR INTAKE MANIFOLD TEMPERATURE |
| config | +12 | `high_error_limit` | HL | A/D HIGH ERROR LIMIT FOR INTAKE MANIFOLD TEMPERATURE |
| config | +14 | `low_error_limit` | LL; 1 other name | A/D LOW ERROR LIMIT FOR INTAKE MANIFOLD TEMPERATURE |
| config | +16 | `qadc_result_register_index` | CA | INTAKE_MANIFOLD_TEMPERATURE_CHANNEL_ADDRESS |
| config | +18 | `multiplexer_setting` | MU | CHANNEL MUX SETTING |
| config | +19 | `tri_state_error_enable` | TS | TRI STATE FLAG - INTAKE MANIFOLD TEMPERATURE |
| config | +20 | `high_error_fault_number` | HE | ERROR NUMBER STORAGE FOR INTAKE_MANIFOLD_TEMPERATURE_HIGH_ERRO |
| config | +21 | `low_error_fault_number` | LE | ERROR NUMBER STORAGE FOR INTAKE_MANIFOLD_TEMPERATURE_LOW_ERROR |
| config | +22 | `tri_state_error_fault_number` | TE | ERROR NUMBER STORAGE FOR IN_RANGE_ERROR - INTAKE MANIFOLD TEMPERA |
| config | +23 | `sample_period` | SR (13) / SA (12) | A/D SAMPLE PERIOD FOR INTAKE MANIFOLD TEMPERATURE |
| state | +8 | `filtered_value` | FT; 2 other names | FILTERED AND LINEARIZED INTAKE MANIFOLD TEMPERATURE |
| state | +10 | `unfiltered_value` | UF; 2 other names | UNFILTERED AND LINEARIZED INTAKE MANIFOLD TEMPERATURE |
| state | +16 | `adc_raw_value` | RC; 2 other names | RAW COUNTS FOR INTAKE MANIFOLD TEMPERATURE |

## Channels

Units, scale and minimum are the e2m columns of the filtered value (FT); the range is the one its e2m comment gives.

| Channel | Runtime record | Config record | Calterm stem | Filtered value | Unit | e2m scale | e2m minimum | Range | Other names |
|---|---|---|---|---|---|---|---|---|---|
| 0 | `intake_manifold_temperature_sensor_state` 0x80a2aa | `intake_manifold_temperature_sensor_config` 0x806ae2 | ADIMTP | ADIMTPFT | DEGF | 0.0078125 | -50 | -50 to 293 | config +2 ADDFIMTP |
| 1 | `fuel_temperature_sensor_state` 0x80a2c0 | `fuel_temperature_sensor_config` 0x806afa | ADFLTP | ADFLTPFT | DEGF | 0.0078125 | -50 | -50 to 293 | config +2 ADDFFLTP |
| 2 | `coolant_level_sensor_state` 0x80a2d6 | `coolant_level_sensor_config` 0x806b12 | ADCV | ADCVFT | NONE | 1 | 0 | 0 to 2 | - |
| 3 | `fuel_pressure_sensor_state` 0x80a2ec | `fuel_pressure_sensor_config` 0x806b2a | ADSYFP | ADSYFPFT | - | 1 | 0 | - | - |
| 4 | `oil_pressure_sensor_state` 0x80a302 | `oil_pressure_sensor_config` 0x806b42 | ADOLPR | ADOLPRFT | PSIG | 0.0078125 | 0 | 0 to 100 | config +2 ADDFOLPR |
| 5 | `boost_pressure_sensor_state` 0x80a318 | `boost_pressure_sensor_config` 0x806b5a | ADBSPR | BSTPRS | INHG | 0.0159062501 | 0 | 0 to 100 | config +2 ADDFBSPR, state +8 BSTPRS, state +10 ADUFBSPR, state +16 ADRWBSPR |
| 6 | `coolant_temperature_sensor_state` 0x80a32e | `coolant_temperature_sensor_config` 0x806b72 | ADCLTP | ADCLTPFT | DEGF | 0.0078125 | -50 | -50 to 293 | state +16 ADRWCLTP |
| 7 | `ambient_air_temperature_sensor_state` 0x80a344 | `ambient_air_temperature_sensor_config` 0x806b8a | ADAATP | ADFTAATP | DEGF | 0.0078125 | 0 | -100 to 255 | config +2 ADDFAATP, config +14 ADAATPLR, state +8 ADFTAATP, state +10 ADUFAATP |
| 8 | `power_steering_temperature_sensor_state` 0x80a35a | `power_steering_temperature_sensor_config` 0x806ba2 | ADPOTP | ADPOTPFT | DEGF | 0.0078125 | -50 | -50 to 293 | - |
| 9 | `exhaust_pressure_sensor_state` 0x80a370 | `exhaust_pressure_sensor_config` 0x806bba | ADSYEP | ADSYEPFT | NONE | 1 | 0 | - | - |
| 10 | `sampled_throttle_sensor_state` 0x80a386 | `sampled_throttle_sensor_config` 0x806bd2 | ADSATH | ADSATHFT | % | 0.25 | 0 | 0 to 100 | config +2 ADDFSATH |
| 11 | `remote_throttle_sensor_state` 0x80a39c | `remote_throttle_sensor_config` 0x806bea | ADROTH | ADROTHFT | PERC | 0.25 | 0 | 0 to 100 | config +2 ADDFROTH |
| 12 | `ambient_air_pressure_sensor_state` 0x80a3b2 | `ambient_air_pressure_sensor_config` 0x806c02 | ADAAPR | ADAAPRFT | INHG | 0.015906434 | 0 | 0 to 15 | config +2 ADDFAAPR |
| 13 | `battery_voltage_sensor_state` 0x80a3c8 | `battery_voltage_sensor_config` 0x806c1a | ADBTVT | ADBTVTFT | VOLT | 0.125 | 0 | 0 to 40 | config +2 ADDFBTVT |
| 14 | `engine_speed_sensor_supply_voltage_sensor_state` 0x80a3de | `engine_speed_sensor_supply_voltage_sensor_config` 0x806c32 | ADESSV | ADESSVFT | NONE | 1 | 0 | - | - |
| 15 | `throttle_position_sensor_supply_voltage_sensor_state` 0x80a3f4 | `throttle_position_sensor_supply_voltage_sensor_config` 0x806c4a | ADTHSV | ADTHSVFT | NONE | 1 | 0 | - | - |
| 16 | `vehicle_connector_sensor_supply_voltage_sensor_state` 0x80a40a | `vehicle_connector_sensor_supply_voltage_sensor_config` 0x806c62 | ADVHSV | ADVHSVFT | - | 1 | 0 | - | - |
| 17 | `engine_connector_sensor_supply_voltage_sensor_state` 0x80a420 | `engine_connector_sensor_supply_voltage_sensor_config` 0x806c7a | ADECSV | ADECSVFT | NONE | 1 | 0 | 0 to 6 | - |
| 18 | `frequency_throttle_input_supply_voltage_sensor_state` 0x80a436 | `frequency_throttle_input_supply_voltage_sensor_config` 0x806c92 | ADFTSV | ADFTSVFT | - | 1 | 0 | - | - |
| 19 | `cruise_control_switch_multiplexer_sensor_state` 0x80a44c | `cruise_control_switch_multiplexer_sensor_config` 0x806caa | ADCR | ADCRFT | NONE | 1 | 0 | 0 to 5 | config +0 ADCRFTCS |
| 20 | `water_in_fuel_sensor_state` 0x80a462 | `water_in_fuel_sensor_config` 0x806cc2 | ADWF | ADWFFT | NONE | 1 | 0 | 0 to 3 | - |
| 21 | `egr_current_feedback_sensor_state` 0x80a478 | `egr_current_feedback_sensor_config` 0x806cda | ADEGCF | ADEGCFFT | NONE | 1 | 0 | - | - |
| 22 | `programming_pulse_supply_voltage_sensor_state` 0x80a48e | `programming_pulse_supply_voltage_sensor_config` 0x806cf2 | ADPSSV | ADPSSVFT | NONE | 1 | 0 | - | - |
| 23 | `high_side_gate_bias_supply_voltage_sensor_state` 0x80a4a4 | `high_side_gate_bias_supply_voltage_sensor_config` 0x806d0a | ADHBSV | ADHBSVFT | NONE | 1 | 0 | - | - |
| 24 | `operational_amplifier_and_comparator_supply_voltage_sensor_state` 0x80a4ba | `operational_amplifier_and_comparator_supply_voltage_sensor_config` 0x806d22 | ADOCSV | ADOCSVFT | NONE | 1 | 0 | - | - |
