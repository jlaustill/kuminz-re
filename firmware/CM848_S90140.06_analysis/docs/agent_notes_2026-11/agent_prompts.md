# Agent prompts (PR #50 session, 2026-11-16/17)

All 51 subagents this session started, in order, with the exact prompt each was given. Most prompts point at a brief in `rename_waves/briefs/` or `table_campaign/` (paths name the session's scratch folder, kept as `session_folder/`).

## 1. Name tables bin 02 (A) (2026-11-16T15:05:28.798Z, general-purpose, sonnet)

```
Read the whole brief first and follow it exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_02.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_02_a.jsonl

Work independently: do not read any other result_*.jsonl file in that directory. This is read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Write one JSON line per lookup that holds one of the bin's assigned_tables (a base name or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. When finished, reply with a short summary: lookups named, lookups skipped, and any naming concerns.
```

## 2. Name tables bin 02 (B) (2026-11-16T15:05:31.702Z, general-purpose, sonnet)

```
Read the whole brief first and follow it exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_02.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_02_b.jsonl

Work independently: do not read any other result_*.jsonl file in that directory. This is read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Write one JSON line per lookup that holds one of the bin's assigned_tables (a base name or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. When finished, reply with a short summary: lookups named, lookups skipped, and any naming concerns.
```

## 3. Name tables bin 06 (2026-11-16T15:05:35.387Z, general-purpose, sonnet)

```
Read the whole brief first and follow it exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_06.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_06.jsonl

Note for this bin: its tables sit in RAM (0x409xxx), read from a RAM dump of the running engine controller, so values that are all zero may simply be an unused table in this calibration; name from the code and the breakpoints, and say so in units_check.

Work independently: do not read any other result_*.jsonl file in that directory. This is read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Write one JSON line per lookup that holds one of the bin's assigned_tables (a base name or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. When finished, reply with a short summary: lookups named, lookups skipped, and any naming concerns.
```

## 4. Name tables bin 09 (2026-11-16T15:05:38.639Z, general-purpose, sonnet)

```
Read the whole brief first and follow it exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_09.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_09.jsonl

Note for this bin: some assigned tables are shared by several lookups with different partner tables (their shared_by_lookups lists more than one id). Give each of those a shared_base line that names its input quantity and subsystem, not one consumer.

Work independently: do not read any other result_*.jsonl file in that directory. This is read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Write one JSON line per lookup that holds one of the bin's assigned_tables (a base name or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. When finished, reply with a short summary: lookups named, lookups skipped, and any naming concerns.
```

## 5. Name tables bin 00 (2026-11-16T15:35:46.556Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_00.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_00.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 6. Name tables bin 01 (2026-11-16T15:35:50.028Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_01.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_01.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 7. Name tables bin 03 (2026-11-16T15:35:53.483Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_03.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_03.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 8. Name tables bin 04 (2026-11-16T15:35:56.931Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_04.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_04.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 9. Name tables bin 05 (2026-11-16T15:36:00.383Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_05.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_05.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 10. Name tables bin 07 (2026-11-16T15:36:03.963Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_07.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_07.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 11. Name tables bin 08 (2026-11-16T15:36:07.333Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_08.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_08.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 12. Name tables bin 10 (2026-11-16T15:36:10.784Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_10.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_10.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 13. Name tables bin 11 (2026-11-16T15:36:14.235Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_11.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_11.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 14. Name tables bin 12 (2026-11-16T15:36:18.534Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_12.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_12.jsonl

Note for this bin: lookup L237 is a synthetic entry for 0x0005a462, the mode-6 member of the six-table family of L225..L229 (selected by fuel_operation_mode_index 1..6 in cm848_calculateSpeedControlError); read its "note" and name all six consistently, the mode number the only difference.

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 15. Name tables bin 13 (2026-11-16T15:36:22.435Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_13.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_13.jsonl

Note for this bin: some assigned tables are shared by several lookups with different partner tables (their shared_by_lookups lists more than one id); give each a shared_base line naming its input quantity and subsystem.

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 16. Name tables bin 14 (2026-11-16T15:36:25.886Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_14.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_14.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 17. Name tables bin 15 (2026-11-16T15:36:29.385Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_15.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_15.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 18. Name tables bin 16 (2026-11-16T15:36:33.585Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_16.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_16.jsonl

Note for this bin: most lookups are sensor-channel ADC conversions; follow the addendum's `<sensor>_linearization` grammar, and fall back to `sensor_channel<N>_linearization` when the sensor is not certain from the code and the transfer curve.

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 19. Name tables bin 17 (2026-11-16T15:36:37.586Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_17.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_17.jsonl

Note for this bin: sensor-channel ADC conversions follow the addendum's `<sensor>_linearization` grammar, falling back to `sensor_channel<N>_linearization` when the sensor is not certain.

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 20. Name tables bin 18 (2026-11-16T15:36:40.973Z, general-purpose, sonnet)

```
Read both files fully first and follow them exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (pilot facts, grammar reminders, a 50-tool-call budget).

Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_18.json
Your result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_18.jsonl

The .cpp was rebuilt after the bin JSON was written: some tables that show as WORD_ARRAY_ in the JSON statements now have names in the .cpp; the .cpp is current. Work independently: do not read other result_*.jsonl files. Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. One JSON line per lookup that holds one of the bin's assigned_tables (a base or a skip), plus a shared_base line for any assigned table shared by lookups with different partner tables. Finish with a short summary: lookups named, skipped, naming concerns.
```

## 21. Verify injection timing leads (2026-11-16T16:37:15.866Z, general-purpose, sonnet)

```
Read the brief fully first and follow it exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G1a.jsonl

Your leads (injection TIMING):
Functions:
- 0x005279d8 cm848_auxiliary_boundary_condition_eval: claimed to compute the timing of the auxiliary (third) injection event; two independent agents agreed. Its result injection_timing_aux_offset = main timing - auxiliary distance, scaled by -5 into the TPU-A channel 6 slot 12 angle.
- 0x0004ae20 cm848_calculateEngineTimingData: claimed to compute the MAIN injection timing (result torque_limit_fault_snapshot, sent in PGN 65504); RAM dump reproduced 213 x 3128 / 4096 = 162.
- 0x0052c780 engine_injectionTiming_arbitration_calc: claimed to compute an injection timing offset added to the main timing (which event is open; result injection_timing_offset_arbitrated, used via injection_timing_offset_rpm_corrected by cm848_pressure_control_state_load).
Variables to check:
- torque_limit_fault_snapshot = the main injection timing.
- injection_timing_aux_rpm_factor (0x40b84a) = the coolant angle, not a factor; injection_timing_auxiliary_fuel_demand_factor (0x40b850) = the boost angle; injection_timing_aux_load_limit (0x40b844) = the ambient correction; injection_timing_aux_combined_clamp = the coolant correction; injection_timing_aux_boost_blend = the map blend result (no boost); injection_timing_aux_output (0x40b840) / injection_timing_aux_offset (0x40b830) roles.
- boost_map_index_current / boost_map_index_target (0x40a4a6 / 0x40a4a8) = the lower / upper blend table numbers 1..4, not boost.
- injection_timing_factor_cyl2/3/4_a/_b, injection_timing_factor_base_a/_b, injection_timing_demand_cyl2/3/4/_calc = the intake-temperature / coolant / boost / barometric components of the main timing, not cylinders.
- injection_timing_arb_component_3/4/5 (bin 01: intake temperature, barometric pressure, rpm x boost terms) and the *_rpm_factor destinations in engine_injectionTiming_arbitration_calc that hold angles.
Work independently; read-only.
```

## 22. Verify injection quantity leads (2026-11-16T16:37:22.719Z, general-purpose, sonnet)

```
Read the brief fully first and follow it exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G1b.jsonl

Your leads (injection QUANTITY and on-time):
Functions:
- 0x0052ba30 cm848_torque_limit_state_update: claimed to compute the PILOT injection quantity (capped at fuel_demand_computed x 2048/4096; snapshotted by cm848_fuel_demand_state_capture into 0x3fd07e; RAM dump reproduced several table outputs).
- 0x000466a8 cm848_calculateGovernorOutput: claimed to compute the auxiliary (third event) injection QUANTITY limit; output crank_sync_threshold, copied to 0x3fd080 by cm848_fuel_demand_state_capture and used to cap engine_timing_delta.
- 0x00046f7c cm848_calculateTimingWithTables: claimed = main injector on-time (pulse width) from main quantity x rail pressure (table main_injection_pulse_width_*).
- 0x00047394 cm848_calculateEngineFaultTiming: claimed = auxiliary injector on-time (table auxiliary_injection_pulse_width_*), not a fault.
- 0x00047140 cm848_calculateEngineTimingInterpolation: claimed = pilot injector on-time (table pilot_injection_pulse_width_*).
Variables to check:
- torque_limit_demand_output = the pilot quantity; the torque_limit_timing_* terms in cm848_torque_limit_state_update (e.g. torque_limit_timing_load_base_factor = boost factor, torque_limit_timing_load_scale_factor = a quantity, torque_limit_timing_warmup_correction, torque_limit_timing_fuel_slew_correction).
- crank_sync_threshold = the auxiliary quantity limit.
- engine_timing_reference*, engine_timing_delta, cam_timing_reference_offset = fuel quantities; fuel_quantity_active, fuel_quantity_table_result, fuel_quantity_trim, injection_timing_active_flag = on-times (ticks); cruise_speed_rate_of_change / cruise_speed_demand_limit (0x003fb636) = on-time caps.
Work independently; read-only.
```

## 23. Verify rail pressure leads (2026-11-16T16:37:29.569Z, general-purpose, sonnet)

```
Read the brief fully first and follow it exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G2.jsonl

Your leads (rail / fuel pressure):
Functions:
- 0x00529f58 cm848_sensor_channel_state_load: claimed = the rail pressure SETPOINT calculator (output fuel_pressure_setpoint; tables fuel_pressure_setpoint_*; RAM dump: setpoint 1000 with arbitration byte 6).
- 0x0052b32c engine_camTiming_positionCorrection_calc: claimed = a fuel-metering feedback monitor (compares fuel_metering_feedback_input with a table of the governor demand sum; fault bit 60 = P1223), not cam timing.
- 0x00049264 cm848_processEnginePositionDiagnostics: claimed = rail pressure diagnostics (fault bit 303 = P0088 and others).
- 0x0052acfc engine_camSync_referenceCheck_update: claimed = a rail pressure monitor (cam_sync_refA_required_count is a limit on the pressure governor demand).
- 0x00519e2c protection_fuel_demand_limiting: claimed = a rail-pressure-shortfall fuel quantity limiter (arms when fuel_demand_computed exceeds an rpm table while setpoint - sensor is above a threshold).
Variables to check:
- the cam_timing_* variables in the setpoint calculator and the feedback monitor (cam_timing_advance_target is a pressure offset x 100; cam_timing_correction_*, cam_timing_position_correction_*, cam_timing_fault_activation_*), engine_timing_arb_byte_8_15 (which setpoint term won), DAT_0040b8ea (the monitor's sum), DAT_0040b8b8 / DAT_0040b8be.
- in the diagnostics: cam_sync_* / engine_position_* names; cam_sync_reference / cam_sync_reference_prev = a modelled rail pressure.
- protection_fuel_demand_* family (bare protection).
firmware/CLAUDE.md "Fuel pressure governor" has the confirmed rail-pressure names; stay consistent with them.
Work independently; read-only.
```

## 24. Verify air and charging leads (2026-11-16T16:37:36.270Z, general-purpose, sonnet)

```
Read the brief fully first and follow it exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G3.jsonl

Your leads (wastegate, charging, intake air heater):
Functions:
- 0x00011ab4 cm848_boostCompensatedRpmGovernor: claimed = wastegate duty control; rpm_governor_state_t fields desired_rpm / lower_rpm_limit / commanded_rpm (0..12800) are wastegate duty / 2 (12800 = 100 %), cm848_applyWastegateSolenoidDuty sends 2 x commanded_rpm; commanded = clamp(feedback, lower_rpm_limit, desired_rpm). Tables wastegate_duty_ceiling_* / wastegate_duty_floor_*. (Struct fields: report as note lines only.)
- 0x00537584 hpcr_fuelDemandProc: claimed = the electronic wastegate monitor (pass window by ambient pressure; tables wastegate_monitor_*); its hpcr_fuel_demand_* variables and _fault_upper_limit / _fault_lower_limit are the pass window edges.
- 0x00037744 cm848_filterProtectionOutput: claimed = the 4-state charging-voltage (alternator field) regulator driving alternator_field_duty_target (tables alternator_field_*).
- 0x00532418 hpcr_injectPressureTuning: claimed = the intake air heater performance test (fault bit 411 = P2609; table intake_air_heater_performance_threshold_*).
Variables to check:
- alternator regulator: cruise_state_machine_index / cruise_prev_state_index (regulator state), cruise_voltage_debounce_timer (load-response hold counter), cruise_voltage_fault_state (load-response stage), battery_voltage_scan_index (ramp-age pass counter), cold_start_fuel_ema / cold_start_fuel_ema_snapshot (slow average of the duty), can_subsystem_init_state_b .. _g (interpolator caches).
- hpcr_fuel_demand_* in the wastegate monitor; hpcr_pressure_diag_* and iat_protection_state in the heater test.
- battery_voltage_prev (0x40b26e) = the charging voltage target (check where it is written).
Work independently; read-only.
```

## 25. Verify governor and J1939 leads (2026-11-16T16:37:44.076Z, general-purpose, sonnet)

```
Read the brief fully first and follow it exactly: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G4.jsonl

Your leads (governor, J1939 retarder, blends, misc):
Functions:
- 0x000234a4 j1939FormatMultiFrameResponse: claimed = a TSC1 retarder request quantizer (steps governor_output_percentage 0/17/33/50/67/83/100 over the engine_retarder_torque_stage_* tables).
- 0x00021314 cm848_calculateSpeedControlError: claimed = the ERC1 byte 2 (SPN 520 retarder percent torque) builder; it selects engine_retarder_torque_stage_1..6_values by fuel_operation_mode_index.
- 0x0000ff04 cm848_calculateFuelTrimValues: claimed = computes governor PID gains, not a fuel trim.
- 0x0000fcd0 cm848_calculateFuelTimingBlend: claimed = a drivetrain-ratio (gear) blend of two governor tuning sets; fuel_timing_blend_factor (0..128) is set from drivetrain_ratio thresholds.
- 0x0000e8dc cm848_fuelTimingRateLimitedBlend: claimed = an engine-speed blend, not injection timing (speed_timing_blend_weight, fuel_trim_speed_filtered, fuel_trim_speed_floor).
- 0x0051a878 governorCruiseTimerManagement: claimed = accumulates weighted injected fuel, distance since a J1939-commanded reset and a power-weighted timer, then sets DAT_0040ae5e; maybe a service-interval monitor (unverified - say uncertain unless the code proves it).
- 0x000375c8 cm848_processProtectionCoolantLookup: claimed to read the battery temperature, not coolant.
Variables to check:
- retarder chain: fuel_operation_mode_index, fuel_operation_mode_count, j1939_engine_torque_encoded, governor_speed_request_maximum, governor_speed_percentage_cal, j1939_transfer_frame_count, governor_output_percentage.
- fuel_timing_blend_factor; speed_timing_blend_weight / fuel_trim_speed_filtered / fuel_trim_speed_floor.
- the governor_cruise_* variables in governorCruiseTimerManagement, sensor_init_retry_timer, governor_cruise_speed_adjusted.
- DUPLICATE NAMES (each name is on two addresses; propose a distinct correct name for at least one of each pair): fuel_demand_offset_correction at 0x0040a550 and 0x0040b22a; sensor_channel7_fault_status at 0x0040be18 and 0x0040be3a.
Work independently; read-only.
```

## 26. Wave 3: injection leads (2026-11-16T17:53:52.094Z, general-purpose, sonnet)

```
Read fully and follow: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave3.md.
Your leads: the notes tagged [G1a] and [G1b] (injection timing / quantity / on-time) in the "Further leads" section of /home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/work/tasks/042-table-campaign-rename-leads.md. Also verify injection_timing_timing_mode_cal (0x004090f6, left uncertain in wave 1: the TPU-A channel 6 handler states 2 and 4 test it with opposite polarity) from the disassembly.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W3_injection.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary (counts, anything uncertain).
```

## 27. Wave 3: rail pressure leads (2026-11-16T17:53:56.646Z, general-purpose, sonnet)

```
Read fully and follow: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave3.md.
Your leads: the notes tagged [G2] (rail / fuel pressure) in the "Further leads" section of /home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/work/tasks/042-table-campaign-rename-leads.md - e.g. the sibling functions (hpcr_register_state_save, the group 28 load / init, engine_camTiming_speedWindow_update = a P1221 speed-window monitor, hpcr_camTimingMonitor = a rail pressure tracking monitor, fault 408 / 409 = P0148), the support functions around 0x49264, and the setpoint / monitor / limiter constants without rows. Also the wave-1 uncertain rows 0x0040b8cc (engine_position_diag_flags, written by cm848_updateProtectionBitFlags) and 0x0040951e (cam_sync_position_lower_threshold_cal, 30738).
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W3_rail.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 28. Wave 3: air and charging leads (2026-11-16T17:54:01.948Z, general-purpose, sonnet)

```
Read fully and follow: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave3.md.
Your leads: the notes tagged [G3] (wastegate, charging regulator, intake air heater) in the "Further leads" section of /home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/work/tasks/042-table-campaign-rename-leads.md - e.g. hpcr_throttlePositionDiagnostic (arms the heater test), engine_protection_batteryLoad_check, the charging chain functions (charging voltage error / regulator state update / field duty PID: find which functions those are), cm848_turboCompensationWrapper and mpc555_initTurboCompensationVariables (the wastegate wrapper and init). Also propose struct_field renames for rpm_governor_state_t (desired_rpm / lower_rpm_limit / commanded_rpm are wastegate duty / 2, 12800 = 100 %; check every field) and a better struct name if the evidence supports one (as a note). Also 0x004087fa protection_fuel_output_idle_cal (wave-1 uncertain).
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W3_air.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 29. Wave 3: governor and J1939 leads (2026-11-16T17:54:07.185Z, general-purpose, sonnet)

```
Read fully and follow: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave3.md.
Your leads: the notes tagged [G4] (governor, J1939 retarder, blends, oil change monitor) in the "Further leads" section of /home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/work/tasks/042-table-campaign-rename-leads.md - e.g. cm848_j1939BuildVehicleOperatingStatus (0x26238, builds ERC1 PGN 61440), j1939_pgn61440_engine_load_byte (0x3fae09, SPN 520), cm848_j1939SetupMultiFrameTransfer (0x2346c, decodes TSC1 requested torque), cm848_j1939ProcessGovernorRequest (0x236f0, TSC1 handler for the retarder source address), cm848_initJ1939BrakeRetarderBuffer (0x26480, serves PGN 65213 fan drive), fuel_demand_config_flags (0x40c081, byte 1 of logical_output_request_bits), governor_speed_scale_factor (ASG droop?), the oil change monitor words without rows. Use the j1939 MongoDB (mongodb://localhost:27017/j1939, collection pgns, query by number) for PGN / SPN meanings if needed.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W3_governor.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 30. Wave 3: retry skipped tables (2026-11-16T17:54:12.702Z, general-purpose, sonnet)

```
Read both files fully and follow them: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief.md, then /home/linux/.claude/jobs/d55ae3c6/tmp/tables/brief_addendum.md (table naming grammar, evidence rule, bans, budget).
Your bin: /home/linux/.claude/jobs/d55ae3c6/tmp/tables/bin_retry.json - the 45 tables (19 lookups) that the first campaign SKIPPED. Since then 27 functions and 237 globals around them were renamed (CSV comments end with "(was <old>)"), so inputs / outputs that were unclear may now be traceable. The JSON statements are from before those renames: find each call in the current .cpp by its WORD_ARRAY_<address> labels. Each lookup's earlier skip reason is in /home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/docs/table_naming_campaign_2026-11-16.csv (status unnamed). Name a lookup only if the evidence rule now holds; skipping again is fine. Note the table families already named (injection_timing_main_*, injection_quantity_pilot_*, fuel_pressure_setpoint_*, ...) and stay consistent with them.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_retry.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 31. Wave 3: resolve duplicate names (2026-11-16T17:54:17.904Z, general-purpose, sonnet)

```
Read fully and follow: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md (rules, result format), then /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave3.md.
Your task is different from the leads: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/duplicates.json lists every NAME that is used at more than one address in the CM848 global_variables.csv (16) or function_renames.csv (5), with each address, type and comment start. For each duplicate: read how each address is used (xref_addr.py for globals, the decompiled body for functions), decide which address the name fits (keep it there) and propose a distinct, correct name for the other address(es) as "global" / "function" rows with verdict confirmed. If the name fits none, rename all. If a row is junk (a Ghidra artifact like switchD, or a duplicate register label that mpc555_registers.csv already defines), write a {"kind": "note", "text": "DELETE 0x... <name>: reason"} line instead of a rename. Struct-member label rows (names with a '.') are not in scope.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W3_duplicates.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 32. Wave 4: injection leftovers (2026-11-16T20:01:27.371Z, general-purpose, sonnet)

```
Read fully and follow, in order: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave3.md, /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave4.md.
Your group tag: [W3 injection] (12 notes and 2 uncertain items: injection_timing_advance 0x40a46e, engine_load_normalized_prev 0x40b31c) in /home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/work/tasks/042-table-campaign-rename-leads.md.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_injection.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 33. Wave 4: rail pressure leftovers (2026-11-16T20:01:32.148Z, general-purpose, sonnet)

```
Read fully and follow, in order: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave3.md, /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave4.md.
Your group tag: [W3 rail] (16 notes and 5 uncertain items: engine_protection_fuelCorrection_stateMachine 0x530d08 (fault 7 = P0191), the four second-limit rows 0x409534 / 0x409536 / 0x409540 / 0x409548, cam_sync_position_lower_threshold_cal 0x40951e) in /home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/work/tasks/042-table-campaign-rename-leads.md. Also the injector-diagnostic chain noted in wave 3 (mpc555_evaluateProtectionSyncFaults, cm848_getProtectionSyncState, cm848_updateProtectionBitFlags, cm848_protectionFaultEvaluator and their bit bytes / debounce limits) if no earlier wave renamed it.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_rail.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 34. Wave 4: air and charging leftovers (2026-11-16T20:01:36.973Z, general-purpose, sonnet)

```
Read fully and follow, in order: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave3.md, /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave4.md.
Your group tag: [W3 air] (16 notes and 1 uncertain item: cm848_calculateSpeedControlLimit 0x2ca14, the second reader of wastegate_duty_controller_state.request_half_duty_counts - settle what its speed-control chain is) in /home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/work/tasks/042-table-campaign-rename-leads.md. Also: the four alternator regulator state handlers at ROM 0x38338-0x3844c are not Ghidra functions; if they are real functions (called / branched to), propose them as "function" rows with old = "" and the address, and say how they are reached (they may be created by adding a function_renames.csv row).
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_air.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 35. Wave 4: governor and duplicates leftovers (2026-11-16T20:01:42.451Z, general-purpose, sonnet)

```
Read fully and follow, in order: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave3.md, /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief_wave4.md.
Your group tags: [W3 governor] and [W3 duplicates] (14 notes) in /home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/work/tasks/042-table-campaign-rename-leads.md - e.g. the retarder request-arbitration cluster (cm848_processProtectionSystemBit4 through cm848_processFuelEfficiencyTrim and governorOverrideSpeedControl), the fuel_trim_* mode-7 reference-speed limiter, the protection confirm counter family's crossed a / b / c suffixes, the coolant_cal_entry family (the TSC1 override request tracker), the dual analog accelerator pedal block (the cruise_speed_* names at 0x3fee46 / 0x40b554 / 0x40bbb2), the J1939 CAN receive / transmit queue names (engine_data_log_*), and the fuel_ema_coeff_* / fuel_demand_ema_* abbreviations. Use the j1939 MongoDB (mongodb://localhost:27017/j1939, collection pgns) for PGN / SPN meanings.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W4_governor.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 36. Wave 5: re-review load-protection cluster (2026-11-17T01:17:49.715Z, general-purpose, sonnet)

```
Read fully and follow, in order: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md (same directory).
Task: re-review the "engine load protection" cluster that a 2026-06-27 rename created: the 18 functions at ROM 0x2e17c-0x2f6a0 (e.g. cm848_processLoadProtectionStatus), the ENGINE_LOAD_PROTECTION_STATE enum in firmware/CM848_S90140.06_analysis/output/enums.csv, and the protection_* / load_protection_* globals they use. Wave 4 found the cluster filters protection_channel_filtered_output (0x40bdb6) = the value output of ADC sensor channel 101 (0x65), NOT engine_load_percent (0x40af24, which none of the 18 functions read). Facts already gathered: channel 101's table maps ADC 0..102 -> 1693, linear to ADC 921 -> 16940, flat above (a 0.5-4.5 V sensor); its config default is 9216, written to protection_derate_fallback_speed (0x40bdb4); its fault bits 682 / 683 map to the shared no-DTC slot; the RAM dump (engine off) has 1693. At 0.125 rpm per count that is 211..2117 rpm with a 1152 rpm default - possibly an analog speed-setpoint input (remote / PTO speed control) - but check it against every consumer (the cluster, and the "actuator E" loop cm848_calculateActuatorESetpoint, which wave 4 says uses channel 101 as feedback on a 12800 = 100 % scale). Decide what channel 101 is (or say unknown), what the cluster does with it, and whether the "engine load protection" reading holds in whole or part. Propose corrected function / global / enum names where the code proves the old ones wrong; keep correct parts; use neutral sensor_channel101_* names if the sensor is still unknown.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W5_load.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary with your verdict on the old reading.
```

## 37. Wave 5: combustion manager ROM part (2026-11-17T01:17:55.209Z, general-purpose, sonnet)

```
Read fully and follow, in order: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md (same directory).
Task: the combustion-manager cluster, ROM part. Functions in ROM 0x14000-0x17000 that use the fuel_demand_* / engine_load_* / fuel_blend_* / load_rate_cap words. Your GLOBALS are only the CBR block (around 0x40a480-0x40a4ff, e.g. CBR_SOI_Ref = 0x40a488, the Alpha0 / Alpha1 / Chi2 / Chi3 / Chi4 map values 0x40a4d2-0x40a4da) and the CBL block (0x40a466-0x40a47f and its calibrations 0x405234-0x40523f); for words outside those blocks write a note instead of a rename (another agent owns the CBO / CBP / FSS blocks). Start from the full lead note (first "note" row of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W4_injection.jsonl). Name what the code proves (start-of-injection reference / combustion limits / mass charge flow / fuel command ...), in a family consistent with the existing injection_timing_main_* names where it is the main timing chain.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W5_combustion_rom.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 38. Wave 5: combustion manager flash2 part (2026-11-17T01:17:59.663Z, general-purpose, sonnet)

```
Read fully and follow, in order: /home/linux/.claude/jobs/d55ae3c6/tmp/renames/brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md (same directory).
Task: the combustion-manager cluster, Bank 2 (flash2) part. Functions in 0x503000-0x507000 that use the fuel_demand_* / engine_load_* / fuel_blend_* / load_rate_cap words. Your GLOBALS are only the CBO block (around 0x40a518-0x40a53f, e.g. CBO_SOI_Ref_Adj +1C = 0x40a534), the CBP block (0x40a54e-0x40a55f) and the FSS block (from 0x40b30a, e.g. FSS_Total_Fueling = engine_load_input_b); for words outside those blocks write a note instead of a rename (another agent owns the CBR / CBL blocks). Start from the full lead note (first "note" row of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W4_injection.jsonl). Name what the code proves (off-nominal compensation, combustion torque, total fueling ...), consistent with the existing families.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W5_combustion_flash2.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 39. Wave 6: injection and rail leftovers (2026-11-17T04:22:59.389Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md.
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W4_injection.jsonl and aligned_W4_rail.jsonl (except the combustion-manager lead note, which wave 5 handled).
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W6_injection_rail.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 40. Wave 6: air, VGT and actuator E leftovers (2026-11-17T04:23:03.894Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md.
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W4_air.jsonl and aligned_W5_load.jsonl. In particular: wave 4's "actuator E" loop (cm848_calculateActuatorESetpoint and the cm848_*ActuatorE* / actuator_e_* names) is the variable geometry turbocharger position servo that wave 5 named (variable_geometry_turbocharger_*): re-domain the actuator E family to that prefix where the code ties it to sensor channel 101 / the servo, plus the bank-2 siblings 0x50f834-0x5102d4, cm848_initProtectionControlState (0x2dc40) and cm848_clearDiagnosticConditionFlags (0x2e02c) noted by wave 5.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W6_air_vgt.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 41. Wave 6: governor leftovers (2026-11-17T04:23:07.692Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md.
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W4_governor.jsonl (about 40: the retarder rpm engage-delay words, the fuel_ema coefficient 1-3 rows, the fuel_trim_* limiter rows, slot-75 ramp stability 0x507214, the diag_state_group4 cache words, ...). Use the j1939 MongoDB (mongodb://localhost:27017/j1939, collection pgns) for PGN / SPN meanings.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W6_governor.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 42. Wave 6: combustion manager leftovers (2026-11-17T04:23:13.027Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md.
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W5_combustion_rom.jsonl and aligned_W5_combustion_flash2.jsonl - e.g. the CBL lookup tables (0x40523e ... 0x4057d6), the CBR calibration scalars (0x4059d6-0x4059fa), the CBO calibration tables (0x405a10-0x405a9e), the Bank-1 CBO chain functions, the chi source code enum (values 1 / 3 / 10 / 12 / 13 / 14 - propose enum rows as notes with the values), engine_feature_enable_flags (0x3fd5a6, EEPROM-backed: _cal), the misnamed mass-flow words (fuel_rate_rpm_factor, fuel_quantity_ema(_filtered), throttle_fuel_trim_t fields), and the two uncertain functions. Lookup tables are rows in global_variables.csv: a table rename is a "global" row with the table's address and its full new name ending in _axis / _values / _x_axis / _y_axis / _grid.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W6_combustion.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 43. Wave 7: injection and rail leftovers (2026-11-17T13:39:15.759Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md (six waves are done now: firmware/CLAUDE.md "Rename waves 1-6" summarises them).
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W6_injection_rail.jsonl (e.g. the ~14 unverified torque_* functions and source globals, the auxiliary interaction tables 0x5f8ac / 0x5f8e0 / 0x5f8ee / 0x5fa1a / 0x5fa2c / 0x5fa3e, the injector debounce counters 0x3fb6fc-0x3fb702, the torque_limit_arb_t type rename to engine_speed_limit_arbitration_t - give it as a note with the exact struct and instance names).
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W7_injection_rail.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 44. Wave 7: VGT leftovers and EGR twin (2026-11-17T13:39:21.147Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md (six waves are done now: firmware/CLAUDE.md "Rename waves 1-6" summarises them).
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W6_air_vgt.jsonl - above all the twin of the VGT valve loop, cm848_calculateFuelDemandLimits, which shares fuel_timing_error_scale and boost_fuel_scale_cal with it and is probably the EGR valve position servo. Settle from the code (sensor channel, outputs, setpoint source, fault bits decoded through ROM 0x5985a -> obd_dtc_code_table at 0x5b57c) what that twin drives, and name its module consistently with variable_geometry_turbocharger_* (e.g. exhaust_gas_recirculation_valve_* only if the code / DTCs support EGR). This ECM's calibration has no EGR (the EGR tables are zero): say whether the module is fitted.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W7_vgt_egr.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 45. Wave 7: governor, combustion and labels (2026-11-17T13:39:27.537Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md (six waves are done now: firmware/CLAUDE.md "Rename waves 1-6" summarises them).
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W6_governor.jsonl and aligned_W6_combustion.jsonl (e.g. the high speed governor block's remaining words, the saved block 0x40a216-0x40a248, 0x3fd910, 0x40a370 / function 0x10874, the cache words 0x3fa114 / 0x3fa116, the COMBUSTION_CHI_SOURCE enum proposal - give enum rows as notes with the exact values -, 0x4059da / 0x4059f0, 0x40a61c). Also diagnose the label problem at the time-shared pair 0x3fb54c / 0x3fb54e: the CSV rows are engine_retarder_request_on_delay_counter (0x3fb54c) and tc_lockup_disengage_state (0x3fb54e, check its current name), but the .cpp prints the 0x3fb54e accesses in cm848_processProtectionSystemBit3 (check its current name) with the 0x3fb54c name and the real counter with an underscore. Read the disassembly and the .cpp, explain the cause (e.g. the kernel-image function at RAM 0x3fb54c that the boot ROM calls, or a wider type), and propose the CSV fix as a note (exact rows), without type changes on time-shared words unless the disassembly proves the width and no boot user conflicts.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W7_governor_combustion.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 46. Wave 8: torque_limit family leftovers (2026-11-17T19:57:32.160Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md, brief_wave8.md.
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W7_injection_rail.jsonl - the rest of the old torque_limit_* family: the uncertain 0x3fd80c / 0x3fdb84 / 0x406fe6 / 0x406fe8 / 0x40a2f0 and the six auxiliary interaction tables (0x5f8ac / 0x5f8e0 / 0x5f8ee / 0x5fa1a / 0x5fa2c / 0x5fa3e - the campaign objection is in /home/linux/.claude/jobs/d55ae3c6/tmp/tables/result_09.jsonl and result_retry.jsonl, lookups L022 / L023); the struct note (torque_limit_arb_t -> engine_speed_limit_arbitration_t and the 6-byte split with the main_injection_timing_source_code word at 0x40a2f6: give the exact structure_definitions.csv / global_variables.csv rows); the torque_limit_error_integrator dword at 0x40a306 / 0x40a308 (droop slope / ramped limit); torque_limit_init_state_0..15 (the main injection timing interpolation states); torque_limit_offset_calc / _stored / _enable_flag / the lookup disable word; the stale-text rows the W7 note lists.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W8_torque_limit.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 47. Wave 8: EGR and charge flow leftovers (2026-11-17T19:57:38.019Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md, brief_wave8.md.
Your leads: the note rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W7_vgt_egr.jsonl (the module is applied as egr_valve_*; the notes keep the spelled-out wording): the EGR delta pressure chain on sensor channel 105 (faults 690 / 691) with its boost_correction_* functions (0x18384 / 0x5033a0) and globals; the charge manager pieces it names (the EAC controller, cm848_calculateTurboBlendOutput and the throttle_* / fuel_demand_rate_* words); the EGR valve control state enum (write it as EGR_VALVE_CONTROL_STATE with EGR_VALVE_* members, exact enums.csv rows); the ~25 H-bridge state words and merged dwords left unrenamed; the type notes (0x4067f2 typed byte but read as a word; egr_valve_position_autozeroed 0x40a666 is signed in the code - give the i16 row only if every user agrees; the sensor_channel105_fault_combined dword 0x40a662 whose low word 0x40a664 cm848_updateEgrValvePositionAutozero stores with sth - propose the split rows); the 19 stale citations.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W8_egr_charge.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 48. Wave 8: governor, combustion, CM550 link (2026-11-17T19:57:45.025Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md, brief_wave8.md.
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W7_governor_combustion.jsonl, except the 0x3fb54c / 0x3fb54e label problem (the build fix is being done separately; skip it): the saved block (0x40a224 / 0x40a226 and the rest of the engine_operating_mode_restore_* record), 0x3fa114 / 0x3fa116, 0x3fd910 (EEPROM 0x48e, so a name needs _cal), the ENGINE_OPERATING_MODE enum members that contradict the code (give corrected enums.csv rows with the evidence for every value), the COMBUSTION_CHI_SOURCE enum proposal (exact rows, and which globals / locals must take the type), the fuel_mode_status_flags (0x40a5ee) bit sources (propose a bitfield struct only if every bit is settled), the old fuel_demand_boost_* / boost_correction_* names of the 0x40a61c consumers.
Also one cross-firmware lead: wave 6 renamed CM848's shared (unprefixed) selectSensorRawChannels to cm848_selectHighSpeedGovernorGainSet (find it in firmware/CM848_S90140.06_analysis/output/function_renames.csv), but CM550 still has selectSensorRawChannels at 0x1d392 (firmware/CM550_J90350.00_analysis/output/function_renames.csv and J90350.00.ghidra.cpp). Compare the two bodies and say whether they are the same function. If they are, propose one unprefixed name for both (give the CM550 function_renames.csv row as a note); if not, propose a CM550 name for the CM550 one from its own body (also a note).
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W8_governor_combustion.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 49. Wave 9: gear-down cluster, torque leftovers (2026-11-17T22:51:05.347Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md, brief_wave8.md, brief_wave9.md.
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W8_torque_limit.jsonl that wave 8 did not apply: (1) the thermal / gear-down cluster the W8 note says needs its own wave (0x3fb4f0 torque_limit_enable_flag, 0x3fb4f6 / 0x3fb4f8 / 0x3fb4fa, 0x40b61e, 0x408d26-0x408d2e: a fuel-limit state machine keyed on drivetrain ratio, gear and transmission type; e2m has Gear_Down_* - settle it from the code, the e2m only corroborates); (2) the uncertain 0x3fdd38 torque_source_count, 0x3fa8a4 torque_limit_working_reference, 0x40a280 torque_limit_init_flag; (3) the source-16 subsystem / protection threshold cluster note (0x40b648 governor_active_flag_b648 and its family) and the W7 note-87 leftovers the last W8 note closed as "own wave"; (4) the ADC forced-reading enable words 0x3fdb78 / 0x3fdb7a / 0x3fdb7c / 0x3fdb7e / 0x3fdb80 / 0x3fdb82 (adc_forced_reading_enable_bits_<first>_to_<last>_cal; 0x3fdb84 is done) and the arrays.csv row 0x003fdb30 diagnostic_service_dispatch_table byte[100] that hides them: check its boot-kernel users (cm848_registerDiagnosticService / cm848_dispatchDiagnosticService, and anything below 0x7F60) and say exactly how far the kernel table really reaches, with the exact arrays.csv / structure_definitions.csv rows to shrink or replace it (20 packed 5-byte entries) so the application words render.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W9_gear_down.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 50. Wave 9: charge manager tables, turbo speed (2026-11-17T22:51:13.447Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md, brief_wave8.md, brief_wave9.md.
Your leads: the note and uncertain rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W8_egr_charge.jsonl that wave 8 did not apply: (1) the charge manager table arrays the CHARGE MANAGER note lists (throttle_load_gain_angle_* / throttle_load_gain_half_angle_cosine_* / throttle_fuel_demand_deviation_gain_*, the EAC gain tables WORD_ARRAY_003ffaf6 / 003ffb1e / 003ffbfa / 003ffc1c / 003ffb46-003ffb62, the C_CHL derate tables 003ff78a-003ff834): exact global_variables.csv AND arrays.csv rows (charge_system_transform_angle_*, charge_system_transform_half_angle_cosine_*, charge_system_transient_gain_*, egr_assist_controller_*_gain_*); (2) the uncertain 0x40afe6 fuel_demand_quantity (the strong lead: the filtered TURBOCHARGER SPEED) together with its source selector fuel_demandSource_modeSelect 0x50ecc4 and its three sources (governor_speed_reference_raw / governor_temperature_correction / egr_smoke_speed_demand_working, modes 0 / 1 / 2) and boost_control_mode 0x40afd6 - settle the turbocharger speed chain from the code (sensor channel, DTCs through ROM 0x5985a -> obd_dtc_code_table 0x5b57c); (3) the other uncertain rows: 0x3fa7ae / 0x3fa7b0, 0x4002ea boost_correction_alt_mode_cal, 0x3fd7f0 cold_start_inhibit_cal (five users), 0x40a686 boost_fuel_input_value; (4) the 0x52d524 monitor-completion conflict (DTC names say boost, the compared word is the EGR delta pressure); (5) one lead of mine: 0x3fae3c is a type-only byte row inside the kernel-image window that the application writes as a word (cm848_initJ1939InletExhaustConditionsBuffer stores 8 there, rendering `_BYTE_003fae3c = 8`; 0x3fae3e is j1939_tx_buf_data_ptr): name and type it from the code, with the boot-user check.
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W9_charge_turbo.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```

## 51. Wave 9: governor leftovers, CM550 pair (2026-11-17T22:51:21.792Z, general-purpose, sonnet)

```
Read fully and follow, in order, from /home/linux/.claude/jobs/d55ae3c6/tmp/renames/: brief.md, brief_wave3.md, brief_wave4.md, brief_wave5.md, brief_wave6.md, brief_wave8.md, brief_wave9.md.
Your leads: the note rows of /home/linux/.claude/jobs/d55ae3c6/tmp/renames/aligned_W8_governor_combustion.jsonl that wave 8 did not apply: (1) the cross-firmware side finding: CM550 cm550_FUN_0001d5a0 (the function after selectHighSpeedGovernorGainSet) as the counterpart of a CM848 function - compare the bodies (CM550: firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp and function_renames.csv) and, if the same, give one unprefixed name with BOTH function_renames.csv rows; while there, check the CM550 neighbours of the high speed governor for more shared pairs; (2) the droop gains 0x40a250 / 0x40a252 (governor_pid_integral_gain / governor_pid_proportional_gain = e2m ASG_Droop_Gain_1 / _2; the note left the vocabulary to the owner: settle it - all_speed_governor_droop_gain_1 / _2 and the restore rows - from the code); (3) the values only compared or not examined: engine operating modes 37 / 38, the reference source code word 0x40a4f0 (23 / 52-58) and fuel_demand_mode_code (27 / 28) - propose enums with exact enums.csv rows only where every value is proven by a store; (4) the still-unsettled fuel_mode_status_flags / combustion status bits (0x04 / 0x08 / 0x10 / 0x200 / 0x400+); (5) the 0x40a61c consumers left unrenamed (fuel_demand_compensation_base_setpoint and the others the note names); (6) the SKIPPED list: the high speed governor text refresh (rows 0x406fb4 / b6 / b8 / c2 / c4 / e2 and 0x40a8cb / cd / cf, the plates of 0x1f40c / 0x1fa20), the '+2' label row 0x3fa892, the row-75 list (governor_speed_* / channel 75 deviation words near 0x507214, the mode 7 reduction reason, the combustion_chi_maximum_torque_at_point_N i16 note).
Result file (JSONL, create it): /home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W9_governor.jsonl
Read-only research: no CSV or repo edits, no ./analyze.sh, no git changes. Final message: short summary.
```
