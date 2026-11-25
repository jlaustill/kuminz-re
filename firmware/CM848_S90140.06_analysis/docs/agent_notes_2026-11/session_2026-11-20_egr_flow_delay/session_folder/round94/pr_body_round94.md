**Round 94.**
- **Naming workflows applied (9b467c63, SHA_E):** round 93's workflow (an investigator, an independent describer and an
  adversarial judge per call-graph family; 316 elements, 283 CONFIRMED / 32 AMENDED / 1 REFUTED) and round 94's leads
  workflow (96 elements, 80 / 16 / 0). Together:
  - 110 CM550 function names, 33 of them twins that share one name with CM848; 17 more CM848 functions that were
    named with a bare 'protection' or 'init';
  - 257 globals and 19 `cm550_tableLookup2D` argument records (`table_lookup_2d_arguments_t`, each named from the
    Calterm tables its pointers point at);
  - the CM550 structs `j1939_periodic_transmit_entry_t`, `engine_tsc1_ignored_request_t` and
    `cm550_retarder_tsc1_ignored_request_t`, plus CM848's `j1939_control_session_t` and its two enums as twins;
  - the enums `IDLE_SHUTDOWN_STATE` and `EEPROM_BYTE_WRITE_STATE`.
  `can_buffer_setup_t` and both `HIGH_RPM_PROTECTION` enums are gone (wrong), and 231 rows that sat inside the new
  types or were bogus are removed.
- **CM550's EEPROM image is 0x148a bytes (f8ead481):** `mc68k_initializeSerialEepromDriverAndLoadMirror` loads EEPROM
  0x0-0x1489 into RAM 0x803b0a-0x804f93 at start-up and then refreshes 0x0-0x64b. The `_cal` window, the address tool
  and `kuminz-cli --dump-eeprom` (CM550_EEPROM_SIZE) follow; 71 CM550 rows and CM848's twin
  `j1939_input_signal_timeouts_cal` take `_cal`.
- **The commanded throttle block (5e07d963):** `cm550_commanded_throttle_state_t` (e2m 1047), CM848's
  `commanded_throttle_state_t` with CTIVIH inserted.
- **One sign rule (74d9789f):** a typed row's signedness comes from both renders, and mixed uses take Calterm's flag.
- **Cleanups (SHA_F):** the definition rows' function names, six functions' local rows re-derived, 22 rows inside
  typed rows.
