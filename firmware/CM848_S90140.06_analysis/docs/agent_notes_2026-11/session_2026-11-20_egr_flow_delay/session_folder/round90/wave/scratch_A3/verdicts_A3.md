Batch A3 skeptic verdicts (draft saved before StructuredOutput)

CONFIRMED (21): 0x80a760 intake_manifold_temperature_raw_override_value word; 0x80a72e intake_manifold_temperature_override_value word;
0x809284 cylinder_balance_acceleration_buffer_1 i32; 0x8091ee cylinder_balance_speed_buffer_2 dword; 0x809252 cylinder_balance_trim_adjustment_1 word;
0x807ecc primary_speed_sensor_teeth_per_period_measurement byte; 0x803ba0 engine_speed_limit_reference_default_cal word; 0x808144 engine_speed_limit_maximum word;
0x808196 tsc1_source_configuration_1_data_link word; 0x60fa8 supported_non_continuous_monitors_bits word; 0x80820c fault_flash_automatic_mode_enable byte;
0x808314 low_speed_governor_default_proportional_gain word; 0x80dc24 power_take_off_requested_engine_speed word; 0x8000 smart_boot_indicator dword;
0x80d65c engine_speed_limit_source_10 word; 0x803da4 datalogger_data_1_length_cal word; 0x803da6 datalogger_data_1_parameter_id_cal word;
0x803d65 datalogger_trigger_1_disable_cal byte; 0x803d66 datalogger_trigger_1_fault_code_flag_cal word; 0x803d95 datalogger_trigger_4_disable_cal byte;
0x80a9d6 engine_speed_limit_source_2 word.

AMENDED (2): 0x8062 flash_operational_code_entry_pointer dword -> pointer (code pointer, CM848 twin typed pointer);
0x803d6a datalogger_trigger_1_parameter_or_fault_code_cal -> datalogger_trigger_1_parameter_id_or_fault_code_cal (it is the ID passed to cm550_lookupParameterIdAddress).

REFUTED: none.

Key checks: every address resolves to the claimed e2m record (e2m_block_addresses.py); every width hand-decoded from ROM bytes;
ROM literal scan: extra hits are parameter_id_table (0x35224) entries only; dump values match; names unique in global_variables.csv.
Extra evidence: 24 measurements per cam x 3 (ESTTIP) = 72 teeth (ESCMTT); 4 measurements per average = 120 crank degrees = one cylinder;
0x80a760 writer cm550_FUN_00020fac uses priority 12D1 ADIMTPPR and default 0x806d3c (inside 101B ADIMTPXA, IMT linearization x-axis).
