# batch C1 draft (scratch)

All 28 rows are working RAM 0x805xxx-0x807xxx: no _cal (EEPROM mirror is 0x803b0a-0x804155).

| addr | row | proposal | type | key evidence |
|---|---|---|---|---|
| 0x80539c | DCMNMP01 | duty_cycle_monitor_stored_short_term_map_1 | word[52] | af70: header word x2 -> 0x80bad8; loop words 0x80539e+2r (r=1..50) x600 -> dwords 0x80bada+4r; b130 writes back; dump header 102 |
| 0x805404 | DCMNMP02 | duty_cycle_monitor_stored_short_term_map_2 | word[52] | same, 0x805406 / 0x80bba8; header 102 |
| 0x805562 | DGCLLVLF | coolant_level_engine_protection_fueling_fault_log | word[20] | 1873e move.l #0x805562,(38,a2) a2=0x80d0dc only (no +42 store) |
| 0x80558a | DGCLTPLF | coolant_temperature_engine_protection_fault_log | word[20] | (38,a2) and (42,a2), a2=0x80d10a |
| 0x8055da | DGLOPRLF | oil_pressure_engine_protection_fueling_fault_log | word[20] | (38,a2) a2=0x80d166 |
| 0x805602 | DGVYPRLF | oil_pressure_engine_protection_engine_speed_fault_log | word[20] | (42,a2) a2=0x80d166 |
| 0x8058d4 | DGAEFUBF | active_dtc_list | byte[32] | cmpi.b #31 / addq.b / subq.b; CM848 active_dtc_list_cal |
| 0x8058f4 | DGIEFUBF | previously_active_dtc_list | byte[32] | same; CM848 previously_active_dtc_list_cal |
| 0x805914 | DGAEFOBF | active_dtc_cummins_fault_codes | word[32] | addq.w/subq.w; [n] = fault def word 0x8067c4+6i |
| 0x805954 | DGIEFOBF | previously_active_dtc_cummins_fault_codes | word[32] | same |
| 0x805a1c | DGFUCUBF | ? fault_count_table / status change time | dword | 125 x 10 B; +0 dword time, +4 dword aging time, +8 status (row), +9 count (row) |
| 0x806ed0 | ADAATXA | ambient_air_temperature_linearization_values | word[9] | descriptor 7 y_axis_ptr; e2m 8020 ADAATYA; x axis 0x806ebe |
| 0x806ee8 | ADPOTPXA | power_steering_temperature_linearization_values | word[3] | descriptor 8 y_axis_ptr; e2m 8022 ADPOTPYA; x axis 0x806ee2 |
| 0x807114 | EPFPMNTD | fuel_pressure_engine_protection_fueling_minimum_threshold | word | config 0x80710a +10; move.w via (10,a2) ptr; cmp.w bcs |
| 0x807116 | EPFPMXTD | fuel_pressure_engine_protection_fueling_maximum_threshold | word | config +12; move.w via (14,a3) -> percentage calc |
| 0x80721e | WSCLTATB | wet_stack_timing_by_coolant_temperature_values | word[9] | 0x8036d4 descriptor y ptr; x 0x80720c; input coolant temp |
| 0x80794e | BSTATBZA | injection_timing_misfire_limit_grid | word[16] | 0x801aaa 2-D descriptor +16; 4x4 no header |
| 0x807abe | ASDVDELM | all_speed_governor_derivative_deadband_limit | i16 | cmp.w blt, ext.l neg.l |
| 0x807ac0 | ASDVFTCF | all_speed_governor_derivative_filter_coefficient | i16 | muls.w |
| 0x807ac2 | ASDVLM | all_speed_governor_derivative_limit | i16 | cmp.w blt, ext.l |
| 0x807ac6 | ASTHPFRL | all_speed_governor_throttle_reference_rate_limit | word | moveq #0; move.w; neg.l |
| 0x807b8e | ASJCFLMX | governor_fuel_demand_tracking_limit_j1939 | word | move.w -> 0x80a99c |
| 0x807b90 | ASJCFLMN | governor_fuel_demand_tracking_floor_j1939 | word | move.w -> 0x80a99e |
| 0x807b92 | ASJ100PP | j1939_tsc1_speed_control_condition_gain_sets | i16[36]? | move.l #0x807b92 + mode*18 -> 0x80a9a8 |
| 0x807bdc | ASCNHILM | governor_fuel_demand_tracking_limit_throttle_mode | word | move.w -> 0x80a99c |
| 0x807bde | ASCNLOLM | governor_fuel_demand_tracking_floor_throttle_mode | word | move.w -> 0x80a99e |
| 0x807d18 | DCMNHIES | duty_cycle_monitor_high_cutoff_engine_speed | word | cmp.w bcc; 20000 |
| 0x807d1a | DCMNLOES | duty_cycle_monitor_low_cutoff_engine_speed | word | cmp.w bcc; 6400 |
