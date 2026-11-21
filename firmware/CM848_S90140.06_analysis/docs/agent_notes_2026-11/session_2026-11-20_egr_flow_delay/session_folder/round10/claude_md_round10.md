- **Round 10 (2026-11-21, PR #53): lookup caches, the 48RE monitors, the transmission relay, the SCI actuator tests.**
  - **Lookup cache names:** a lookup's first argument (the word that keeps the last axis segment offset) is
    `<table base>_cached_axis_offset`. The second word of a 2-D lookup is `..._cached_axis_offset_y`, and a `word[2]`
    grid cache is `..._cached_axis_offsets`. A second cache of the same table takes `_2`. Never `_interp_state`:
    "interp" is a short form (127 rows were renamed).
  - **Signed RE calibrations:** an RE record with column 10 `S` whose loads are all `lha` is `i16`
    (`round10/re_audit.py` builds the audit `classify_signed_loads.py` reads).
  - **Output check fault pairs name outputs:** `cm848_mainLoopMonitor` checks a logical output with
    `diag_faultMatch_outputCheck_update(output, ?, high fault, low fault, ...)`. The two fault bits' DTCs name the
    part:
    - output 16: P0883 / P0882 'TCM power input', so `transmission_relay_request`;
    - output 17: P0974 / P0973 shift solenoid A, the overdrive solenoid;
    - output 18: P2770 / P2769, the converter clutch.
  - **The DRB database names the SCI 0x13 actuator tests:** `mydb` `v_transaction`, protocol `SAE J2610 SCI`,
    request `13-xx`. Codes and outputs:
    | Code | Test | Output |
    |---|---|---|
    | 13-09 | A/C clutch relay | 38 |
    | 13-0F | torque converter clutch | 18 |
    | 13-16 | overdrive solenoid | 17 |
    | 13-1A / 13-1B | cruise vent / vacuum | 19 / 20 |
    | 13-28 / 13-29 | intake heaters | 43 / 44 |
    | 13-2C | cruise 12 volt feed | 21 |
    | 13-33 | fuel transfer pump | 53 |
    | 13-43 | transmission relay | 16 |
    | 13-49 | wait to start lamp | 4 |
    | 13-5D | exhaust brake | 11 |
    | 13-5E | fuel control | `fuel_control_actuator_test_active_flag` |
    | 13-5F | PWM radiator fan | `cooling_fan_actuator_test_active_flag` |

    `sci_output_test_timers_t` (0x3fcf40) holds one timer per test. The tests run only while the engine is stopped.
  - **`DIAGNOSTIC_MONITOR_STATE`:** the e2m value list NORUN / RUN / CMPPS / CMPFL / ABORT (0-4). Several RE monitor
    records list it. It types the six monitor state words that store these values:
    - P1762 (e2m 8C56 +2)
    - P1756 / P1757 (8C58 +2 / +8)
    - P0720 (8C4E +4)
    - P0850 (8C5B +0)
    - P1740 (8C34 +5)

    A monitor with more states (P0711, 0-6) keeps `word`.
  - **The limp-home bytes** (`limp_home_flags_1`..`4`, e2m 8C19 +5..+8): the e2m names each bit, and each byte's
    comment maps bit, record and setter. They stay byte fields, because their writers are read-modify-writes.
