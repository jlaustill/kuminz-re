## Done, round 96 (2026-11-25, same PR): types spelled out, TPU channel blocks, the J1939 builders by PGN, seven CM550 functions that never decompiled

Peer relays started and continued the round (11:53, 12:23, 12:53, 13:23, 13:53). Scripts, proofs, the workflow script and results and the
agents' scratch folders are in `session_folder/round96/`. Every build verify DETERMINISTIC.
- **8bbdb24c, 19 peripheral struct types spelled out** (`tpu3_ch_params_t` -> `tpu3_channel_parameters_t`,
  `qadc64_regs_t` -> `qadc64_registers_t`, `usiu_memc_t` -> `usiu_memory_controller_t`, `eeprom_xfer_state_t` ->
  `eeprom_transfer_state_t` ...; the manual's module names stay). None renders, so the .cpp did not change.
- **db9bfe59, every TPU3 channel parameter block is a struct instance:** 24 more blocks (`tpu_a_channel_<n>_parameters`
  / `tpu_b_channel_<n>_parameters`), so 30 DAT_ words became fields. Two layouts with a dword for the 32-bit accesses
  (a first build showed 9 new pieces): `tpu3_period_accumulator_parameters_t` (TPU-B 1 / 2 / 9 / 14, the speed
  sensors: `accumulated_period`) and `tpu_a_channel_4_parameters_t` (`injector_driver_recharge_interval`). Pieces
  1379 -> 1378. Eight documentation rows that named renamed rows (`stale_doc_rows_r96.py` finds them) are gone.
- **7b3c9fd3, the J1939 / CAN types spelled out in both firmwares:** `j1939_rx_msg_t` -> `j1939_received_message_t` (91
  rendered lines), `j1939_tx_msg_t` -> `j1939_transmit_message_t`, `j1939_msg_hdr_t` -> `j1939_message_header_t`,
  `can_rx_channel_t` -> `can_receive_channel_t`, `j1939_ccss_tx_payload_t` -> `j1939_pgn65261_payload_t`, and that
  payload's instance, which rendered as a default label, is `j1939_pgn65261_payload`. Label-only in both.
- **0d4cafee, seven unnamed EMA filter states and their coefficients** (default labels `ema_filter_state_t_<address>` /
  `WORD_<address>`), named from their users and five e2m records, and the two cascaded EGR orifice temperature stages.
- **fb4b434c, the boot kernel's CMF tables in the time-shared RAM 0x3fdba4-0x3fdc38 (workflow batch Q5):** the kernel's
  rows are named by their CMF erase / program role (`cmf_program_control_step_bits` dword[8], `cmf_program_step_pulse_limits`
  word[8], the flash2 poll / retry limits; 14 array-entry rows go) and keep no `_cal`; the rows the application reads keep
  their `_cal` names (switch input hardware lines 11 / 13 / 19 / 20, the logical output lines). firmware/CLAUDE.md's
  TIME-SHARED caution listed 0x3fdbb2 as an application read; it now gives the judge's read set.
- **07f7a70e, the J1939 periodic builders by PGN, CM550's PGN 59904 request responders and CM550 placeholders (batches Q1 / Q2
  / Q4):** 87 CM550 functions, 10 CM848 functions, 117 globals; five builder twins (EEC1 / EEC2 / EEC3 / EC1 / VEP1); seven
  new CM550 function rows (four builders reached only through the scheduler, the registrar 0x2f47e, DM10, VI). New types:
  CM550 copies of the RC / PGN handler entry / CCSS payloads, DM5 `j1939_pgn65230_payload_t` in both, CM550's
  `j1708_memory_write_record_t`; CM848's `j1939_pgn_dispatch_table` is [32] like its twin. The registrar's prototype makes its
  24 call sites show the PGN and the handler. Cleanups: 55 plates that said their twin twice (the apply no longer appends the
  note), CM848's parameter ID table (its 8 'MPC555_REG' rows are the DPTRAM array, not QADC registers), 3 enum members
  spelled out.
- **2be5a272, CM550's placeholders 0x10e06-0x1f4e8 (batch Q3):** cylinder balancing (its state typed as arrays; 25 stale rows
  inside go), four twins (`calculateJ1939PercentPeakTorqueAtSpeed`, `calculateJ1939FrictionLoadFuelingAtBreakpoints`,
  `initializeFaultDerateJ1939TorqueCurvePriority`, `initializeFourDimensionalFuelingAndFrictionFuelLookups`), the speed input
  set-ups; the four empty functions are named by their call site.
- **SHA_H, seven CM550 functions that never exported a body:** the decompiler failed on each ('Cannot properly adjust input
  varnodes': 2-byte-slot stack arguments with no prototype row). Full prototypes let all seven decompile, and their callers
  show the arguments. The serial EEPROM write queue is one family (two rings typed; the 175 rows inside them, never
  referenced, go). The '1 function imports failed' warning was each `function_renames.csv` header sitting below comment lines;
  the header is line 1 now and the warning is gone (firmware/CLAUDE.md corrected).

### Leads after round 96
- **The abbreviation sweep (ready: `spell_names_stage_h_r96.py` + `abbreviation_renames_r96.csv`):** 139 parameter / local /
  field names (`rx_msg`, `config_ptr`, `handler_func`, `dividend_hi` ...) and 11 struct types (`can_std_rx_desc_t`,
  `diag_tp_state_t`, `sensor_channel_config_t` ...) in both firmwares; then ~48 enum types and their members (`DIAG_*`,
  `*_CMD`, `PARAM_*`) and the `init` / `diag` / `tx` / `cbd` / `temp` function names (~180, twins in both firmwares).
- CM550: the engine protection cluster 0x18c1c-0x18dae (`cm550_diagnosticProtectionProcessor` /
  `cm550_protectionState1DiagnosticValidator`: bare 'protection' names); the J1939 diagnostic request chain typed as
  `can_std_rx_desc_t *` (dispatcher, handlers, `writeJ1939DiagnosticMemory`); the cylinder balance projection words
  (`load_trending_table_2_ptr`, `fuel_timing_blend_rpm_input_2`, 0x8002b4); the numbered empty stubs; the judges' leads (Q2:
  set-ups 0x32244 / 0x323be / 0x33aea / 0x33064, prefixes of 0x33ce2 / 0x343d2, 0x31b22 the PGN 59392 sender, 0x32b38 DM8;
  Q3: twins 0x143b6 / 0x1c640, misnamed 0x19ac2 / 0x1b39a / 0x1af32 / 0x1a6e8 / 0x17a8e / 0x17b8a / 0xfa06 / 0xfb26; Q4: the
  `J1939_DIAGNOSTIC_SERVICE` members 0x43-0x4c, the pulse 0 line records, the ANC inhibit timers, STUOTHGV / LSCIRF).
- CM848: 0x3fedfc (`diag_clear_flags_t_003fedfc`, a name copied from its default label) is time-shared by the boot SCI
  receive counter and application bytes (the A/C clutch logic, the SCI status byte) with the learned axle ratio (e2m
  8BB3) at +2; `j1939_input_signal_descriptor_t_0053a2dc` is a header length table that the descriptor table's
  typing covers (`getJ1939MemoryServiceHeaderLength`); TPU-A channels 1 / 14 and TPU-B 11 still read two parameters
  as one dword (pieces); TPU-A channel 5's PARAM2 / 4 / 6 are the pilot / main / auxiliary injection angles (a role
  layout); 51 unnamed working-RAM / EEPROM-mirror globals (one resolves to an e2m record) and 172 in the boot image RAM.
- CM550: 817 distinct unnamed globals (1933 uses; the 0x810xxx ones are stack writes) - a DAT_ naming campaign.
