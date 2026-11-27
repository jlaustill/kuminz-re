## Done, round 94 (2026-11-25, same PR): the judged naming batches, CM550's EEPROM image, the lookup records

Peer relays started and continued the round (23:00, 05:49, 06:19, 06:50, 07:19, 07:49, 08:20, 08:47). Scripts,
proofs, both workflows' scripts and results, and the agents' scratch folders are in `session_folder/round94/` (round
93's agent scratch in `round93/scratch/`). Six commits; every build verify DETERMINISTIC.
- **74d9789f, one sign rule:** a typed row's signedness is read from both renders (typed unsigned it shows its signed
  uses as casts, typed signed its unsigned ones). Casts that only pack bytes, build fixed-point values or truncate are
  not uses. Mixed uses, or none, take the Calterm S/U flag.
- **5e07d963:** `cm550_commanded_throttle_state_t` (e2m 1047, 13 words: CM848's `commanded_throttle_state_t` with
  CTIVIH at +0x14). The comment refresh tool (`r88/refresh_other_csvs.py`) had renamed a struct field; it now edits
  comment columns only.
- **9b467c63, round 93's workflow applied** (316 elements: 283 CONFIRMED, 32 AMENDED, 1 REFUTED). 96 CM550 functions
  (31 twins renamed in CM848 too), 194 globals, 127 rows inside the new types removed. New types:
  `j1939_periodic_transmit_entry_t`, `engine_tsc1_ignored_request_t`, `cm550_retarder_tsc1_ignored_request_t`,
  `table_lookup_2d_arguments_t` and the enums `IDLE_SHUTDOWN_STATE` / `EEPROM_BYTE_WRITE_STATE`. CM848's
  `j1939_control_session_t`, `J1939_CONTROL_DEVICE` and `TSC1_OVERRIDE_MODE` were copied as twins (the same Calterm
  labels). 0x801a8a is the serial EEPROM driver's write state, so `can_buffer_setup_t` is gone. The two lookup records
  it had covered are `maximum_torque_map_lookup` and `injection_timing_misfire_limit_lookup`.
- **f8ead481, CM550's EEPROM image is 0x148a bytes:** `mc68k_initializeSerialEepromDriverAndLoadMirror` (0x26854) sets
  the start-up load length (move.l #0x804f94 / subi.l #0x803b08 / addi.w #-2 = 0x148a) and, after the load, the refresh
  length 0x64c. So RAM 0x803b0a-0x804f93 is EEPROM 0x0-0x1489. The `_cal` window (`audit_cal_suffixes.py`), the
  address tool and kuminz-cli's `--dump-eeprom` (`CM550_EEPROM_SIZE`) follow. 71 CM550 rows and CM848's twin
  `j1939_input_signal_timeouts_cal` take `_cal` (CM848's window is its start-up load too).
- **SHA_E, the leads workflow** (L1-L4; 96 elements: 80 CONFIRMED, 16 AMENDED):
  - CM550: the engine warmup protection (`cm550_runEngineWarmupProtection`, e2m 11EA-11EF; was named high rpm
    protection), the torque derate torque-to-fuel conversion, and the twins `loadHourMetersFromEeprom` /
    `scheduleJ1939PeriodicMessage`.
  - All 19 `cm550_tableLookup2D` records, the duty cycle monitor axes in both firmwares, and
    `fault_processing_enable_flags` (DGFUIDEN).
  - CM848's 17 functions named with a bare 'protection' or 'init' (the four task sets by schedule slot,
    `cm848_runFuelLimitChains`, ...).
  - Both `HIGH_RPM_PROTECTION` enums removed (no user; FLAGS was the J1587 PID 71 idle shutdown timer status byte).
  - 0x2efd0 is the PGN 61442 receive handler.
- **SHA_F, cleanups:** the definition rows' function names (29 + 4 CM550 rows, 2 CM848 rows); the local rows of six
  functions re-derived from their own auto-names; 22 CM550 rows inside typed rows removed.
- **Lessons:**
  - Never read a .cpp while its verify runs: the second pass rewrites it function by function.
  - The comment refresh replaces an old row name that is itself an e2m mnemonic, even inside e2m citations
    (DCMNLGMP, DCMNLDTB). Check a map's mnemonic-like old labels.
  - An idempotent insert must test for the inserted text itself; testing "old text absent" fails when the old text is
    a prefix of the new.
- **Leads (round 95):**
  - `scheduleJ1939PeriodicMessage` needs a prototype row (queue dword, PGN word, interval / first-send offset words in
    ms, builder pointer; returns a byte; it fits the stack layout's 2-byte slots).
  - `cm550_tableLookup2D`'s parameter could be `table_lookup_2d_arguments_t *`, so its body shows field names.
  - The 1-D `table_interp_args_t` records are a backlog.
  - Five record-shaped RAM blocks (0x8036e4 / 0x8036fe / 0x803896 / 0x8038ac / 0x8039ae) have no reader in the dumped
    ROM. Revisit them with the 0x40000+ dump.
  - CM848's other task sets (`periodicTaskGroup<N>_calibration<M>`) could be named by schedule slot.
  - `cm848_calculateFuelDemandFilter` / `cm848_initFuelDemandFilterDimensions` compute the maximum torque at the
    current engine speed.
  - The uncalled leaf at CM848 0x29ecc; the `safety_*` fault blend globals 0x40b31e-0x40b326.
  - 0x801d44-0x801d58 could be one struct (CM848's `j1939_powertrain_messages_received_t`; the layout differs).
  - The outer rows `j1708_transmit_buffer_2_32_dc98` / `j1708_receive_buffer_pointer_2_32_dca2` (hex in the names)
    and `io_control_bit0_state` (a dword the code adds to and subtracts from).
  - 0x803036 / 0x80cc4e / 0x800f66 / 0x80d40c have no reference in the dumped ROM.
  - Re-dump CM550's EEPROM at 0x148a bytes on the bench; whether the device is 8 KB is open.
  - The 15 function rows after a return (round 93) remain.
