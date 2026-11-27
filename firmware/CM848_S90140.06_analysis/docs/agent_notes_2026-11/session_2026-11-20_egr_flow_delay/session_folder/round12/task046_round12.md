## Done, round 12 (2026-11-21, same PR; the relayed "keep going"): arrays and the CP3 fuel metering vocabulary

Scripts are in `session_folder/round12/`.
- **Stage A (9448e53, types): scalar rows typed as the arrays their comments describe.** `array_candidates.py` checks
  that no other row sits inside each range; the `DAT_` words inside are the elements.
  - The arrays: the switch debounce history `byte[16]`, the fuel demand timing ring `word[150]`, the cold start
    coolant thresholds, the J1939 source-address whitelist, the intake heater durations, the fuel pressure
    plausibility table, and the misfire per-slot counts and flags.
  - **The 16 words at 0x3fd0ca are eight 2-D lookup caches, one per fuel pressure setpoint table.** `word[16]` was
    tried first and rendered `x + 8`. The maps' cache is `word[2]`, and seven new `word[2]` rows are named after their
    tables. Stage 11A's comment was wrong.
  - **Not done:** `switch_input_hardware_line_cal`'s "32 words" overlap the boot kernel's time-shared words.
  - **The proof:** `array_normalize.py` + `cast_normalized_diff.py`.
- **Stage B (3588241, label-only): the CP3 M-PROP fuel metering names of `cm848_calculateFuelMeteringCommand`, from the e2m
  `HPCR_*` records.** The function's own plate called its `cam_sync_*` / `engine_sync_*` names older guesses.
  - **e2m 8B3C** aligns at 0x40913a: all 18 records land on rows, and the coil temperature estimate (gain x filtered
    resistance / 0x138 + offset, once the sample count reaches its minimum) matches three of them. It gives the
    cold / hot start temperatures, the temperature-source selectors, the tool override, and the coil resistance
    and temperature constants.
  - **The tables at 0x40915e-0x40948b**, each placed by its use: the duty-to-current curve
    (`HPCR_Current_Scaling`), the start / hot start duty curves blended by the coil temperature to preset the
    integrator, the duty pre-control map (the governor feed-forward), the maximum duty by engine speed, and the
    battery correction. The 11.45 column-5 order does not reach this layout, so it could not be walked.
  - **Also:** their lookup caches (the `engine_sync_init_state_*` words), the coil temperature ready / preset-done
    flags, and the two filters. ROM words lose the `_cal` suffix.
- **Round 12 leads:**
  - **The fault status records** (`fault_status_array` / `fault_status_word_array`, 170 x 3 bytes from 0x3feb92)
    would be a packed record array, but the range overlaps the reflash kernel's data-transfer rows from 0x3fec7a
    (time-shared RAM).
  - **`HPCR_Current_Integrator_Preset_*`** (8B49 / 8B4A) and the other `HPCR_*` tables (the leak response, the
    monitor duty curves) have no row yet.
- **Closing:** the function's plate no longer calls its names older guesses.
