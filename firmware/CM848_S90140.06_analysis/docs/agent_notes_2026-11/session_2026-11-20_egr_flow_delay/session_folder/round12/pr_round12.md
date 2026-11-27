
**Round 12 (the relayed "keep going"): arrays and the CP3 fuel metering vocabulary.**
- **Stage A (9448e53, types): nine scalar rows typed as the arrays their comments describe.**
  - The arrays: the switch debounce history, the fuel demand timing ring, the J1939 source-address whitelist, the
    misfire per-slot counts and flags, and others.
  - The 16 words at 0x3fd0ca are eight 2-D lookup caches, one per fuel pressure setpoint table. They are split into
    eight named `word[2]` rows, where a `word[16]` attempt rendered `x + 8`.
- **Stage B (3588241, label-only): `cm848_calculateFuelMeteringCommand`'s `cam_sync_*` / `engine_sync_*` guesses**
  are re-domained from the e2m `HPCR_*` records (43 rows).
  - **e2m 8B3C** aligns at 0x40913a, and the code confirms its records (the coil temperature = gain x resistance /
    0x138 + offset).
  - **The pump tables:** duty to current, the start / hot start duty presets, the duty pre-control map (the
    feed-forward), the maximum duty, and the battery correction.
  - **Also:** their caches and the coil temperature flags. The ROM tables lose `_cal`.
