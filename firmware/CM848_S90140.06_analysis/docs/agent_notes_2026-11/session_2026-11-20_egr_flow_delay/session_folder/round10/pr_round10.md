
**Round 10 (another "keep going"): types, the 48RE monitors, the transmission relay, the SCI actuator tests.**
- **Stage A (3be5a5e, label-only):** the 78 RE lookup caches (54 `DAT_` words and 24 `protection_*` names) take
  their table's name.
- **Stage B (b9df152, types):**
  - 26 RE calibrations are `i16`: their e2m record is signed, and every load is `lha`.
  - The 98 label-only rows of rounds 9 / 10 get types.
  - The learned 1-2 shift lag table `transmission_1_2_shift_lag_cal` (EEPROM, e2m `RE_One_Two_Lag`).
- **Stage C (c9e793d, label-only):**
  - **The cache suffix:** every lookup cache ends in `_cached_axis_offset` (127 `_interp_state` /
    `_interpolation_state` rows; "interp" is a short form, and the lookup's own parameter already had the name).
  - **Output 16 is the transmission relay:** its output check pairs P0883 / P0882 'TCM power input', and fault 137
    sets the e2m bit `RE_Trans_Relay_Circuit_Open`.
  - **The transmission controller's functions:** the relay request, the limp-home flag update, the input step,
    and the two phase-group-B phases (they were `protection_*` / `processCalibrationTablesMain`).
  - **The monitor words:** the P1762 / P1756 / P1757 monitor words, which had `j1939_*` / `protection_coldStart_*`
    names.
- **Stage E (4ff8174, label-only):**
  - **The P1740 converter clutch monitor's working words.**
  - **The SCI 0x13 actuator tests.** The DRB database names every test code the callback handles: A/C clutch
    relay, the intake heaters, fuel transfer pump, transmission relay (13-43, on output 16), wait to start lamp,
    exhaust brake, the cruise solenoids, fuel control and PWM radiator fan. The old `cold_start_protection_*` /
    `diag_protection_*` names were a cold-start guess.
- **Stage D (ee328b7):**
  - **`DIAGNOSTIC_MONITOR_STATE`:** the e2m NORUN / RUN / CMPPS / CMPFL / ABORT list, on six 48RE monitor states,
    checked by `check_enum_proof2.py`.
  - **The limp-home bit map:** each byte's comment maps the e2m 8C19 bit records, with each bit's fault / DTC
    setter.
  - **23 more lookup caches** named after their tables.
- **Stage F (types):**
  - `sci_output_test_timers_t`: one timer per actuator test.
  - The widths: 0x3fceee as a `dword` drops the overlap WARNING from the two P1756 / P1757 functions.
