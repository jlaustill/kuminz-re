## Done, round 10 (2026-11-21, same PR; the user's next "keep going"): types, the monitors, the relay and the SCI tests

Scripts are in `session_folder/round10/`.
- **Stage A (3be5a5e, label-only): the 78 RE lookup caches** (54 `DAT_` words, 24 `protection_*` names) take their
  table's name (`gen_r10a.py`). A second cache of the same table gets `_2`. The 3rd / 4th gear exhaust brake unlock
  lookups share one cache.
- **Stage B (b9df152, types):**
  - 26 RE calibrations become `i16`: their e2m record is signed 2-byte and every load is `lha` (`re_audit.py` +
    `classify_signed_loads.py`).
  - The 98 label-only rows of rounds 9 / 10 get types, e.g. `RE_Max_Pressure_Delta` `i32` and the five 2-D grid
    caches `word[2]`.
  - The learned 1-2 shift lag table `transmission_1_2_shift_lag_cal` `word[6]` at 0x3fede2 (e2m `RE_One_Two_Lag`,
    EEPROM, trimmed by `cm848_updateTransmissionConditionFlags`). Its 2-3 twin at 0x3fedee lies under the boot
    kernel's diagnostic rows.
- **Stage C (c9e793d, label-only):**
  - **The cache suffix:** every lookup cache ends in `_cached_axis_offset` (127 `_interp_state` /
    `_interpolation_state` rows; "interp" is a short form). `word[2]` grids end in `_cached_axis_offsets`.
  - **Output 16 is the transmission relay** (`transmission_relay_request`). Its output check pairs faults 136 / 137
    = P0883 / P0882 'TCM power input', and fault 137 sets the e2m 8C19 bit `RE_Trans_Relay_Circuit_Open`. Outputs
    17 / 18 have the same kind of pairs (P0974 / P0973 shift solenoid A = overdrive, P2770 / P2769 converter
    clutch).
  - **The transmission controller's functions:**
    - `cm848_updateTransmissionRelayRequest`
    - `cm848_updateTransmissionLimpHomeFlags`
    - `cm848_updateTransmissionControlInputs`
    - the two phase-group-B phases `cm848_updateTransmissionControlState` / `cm848_runTransmissionControlWhenEnabled`
    - `cm848_initializeGovernorPressureTrackingMonitor`
    - `cm848_initializeAlternatorFieldControl`
  - **The monitor words:** the P1762 monitor words (e2m 8C56: `governor_pressure_rationality_monitor_state`, was
    `j1939_fault_state`), the P1756 / P1757 monitor's `protection_coldStart_*` words, and
    `transmission_normal_operation_flag`.
- **Stage E (4ff8174, label-only):**
  - **The P1740 monitor's working words** (`converter_clutch_rationality_*`, were `protection_*`).
  - **The SCI 0x13 actuator tests.** The DRB database (mydb, SCI 13-xx transactions) names every code:
    | Code | Test | Output |
    |---|---|---|
    | 13-09 | A/C clutch relay | 38 |
    | 13-28 / 13-29 | intake heaters | 43 / 44 |
    | 13-33 | fuel transfer pump | 53 |
    | 13-43 | transmission relay | 16 |
    | 13-49 | wait to start lamp | 4 |
    | 13-5D | exhaust brake | 11 |
    | 13-5E / 13-5F | fuel control / PWM radiator fan | the two flag tests |
  - **SCI names:** `cm848_updateSciOutputTests` / `cm848_stepSciOutputTest` / `cm848_stopSciOutputTest` /
    `cm848_stopAllSciOutputTests`, `sci_output_test_*`, `fuel_control_actuator_test_active_flag` and
    `cooling_fan_actuator_test_active_flag` (were the `cold_start_protection_*` / `diag_protection_*` family).
- **Stage D (ee328b7, types + renames):**
  - **`DIAGNOSTIC_MONITOR_STATE`** (the e2m NORUN / RUN / CMPPS / CMPFL / ABORT list) on six monitor states.
  - **The limp-home bit map:** each 8C19 bit with its setter. The bytes stay byte fields (the wave 11 rule).
  - **23 more caches** named after their tables.
- **Stage F (types):**
  - `sci_output_test_timers_t` (0x3fcf40, one word per test).
  - The widths: 0x3fceee as a `dword` removes the overlap WARNING from the two P1756 / P1757 functions (27 -> 25 in the .cpp); the new rows get their types.
- **Round 10 leads:**
  - **The `cam_sync_*_cal` tables** of `cm848_calculateFuelMeteringCommand` are fuel metering tables (by battery
    voltage, by engine speed). Give them an e2m pass, then name their caches (`engine_sync_init_state_a` / `b` /
    `j` / `k` / `l` / `n`). The same applies to `fuel_demand_interp_state_a`..`f` (`j1939_fuel_table_*_cal`),
    `governor_interp_table_state_b` and `cruise_switch_interp_index`.
  - **The end-of-line test sequencer** `engine_coldStart_protection_stateMachine` (0x52fa34) and its
    `cold_start_protection_*` words, `fault_event_queue_clear_active` and `protection_voltage_active_flag`.
  - **The logical outputs** 4 / 11 / 38 / 43 / 44 / 53 have DRB names now. Bitfield structs for their bytes of
    `logical_output_request_bits` are possible: the code reads them, and the set / clear functions write them.
  - **e2m 8C80** (the TVA auto zero monitor, `TVA_*`) and 8C2D (TTSR) have no row or block address yet.
  - **0x3fcf16-0x3fcf2e:** the SCI high-speed table words, and `DAT_003fcf5c` / `5d` (`cm848_countdown_timer_update`).
  - 8BB1 / 8BB3 / 8BB9 / 8BBA and 8BBB's tail are still not located.
