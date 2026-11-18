# 044 — CM848D: names that clash with the DTC a function sets (P0500 monitor fixed)

## Problem Statement

A fault bit fixes what a monitor checks: fault n → ROM `0x5985a[n]` (slot) → `obd_dtc_code_table[slot]` (an SAE
P-code). A function whose name disagrees with the P-code it sets is misnamed. On 2026-11-17 a scan of every function
that sets a fault bit turned up one confirmed misname and several leads.

## Method (the DTC-code check)

`fault_setters.py` (in `firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-17_p0500/`) lists,
for each function in a `.cpp`, the fault bits it sets (`fault_detected_bits_<first>_to_<last> = ... | mask`) and their
P-codes. It reproduces every documented mapping (407 → P0483, 396 → P0622, 121 → P0480, 333 → P0251, 351 → P0748,
403 → P0243, 82 / 89 → P2509, 91 → P0606, 304 → P0193, 305 → P0192). `slot170` means the fault has no DTC slot
(an internal fault). It only sees setters written as `|= mask`; indexed or table-driven setters need their own look.

## Done (branch `cm848/vehicle-speed-sensor-p0500-monitor`)

- `diag_boostLoad_overtemp_monitor` (0x5269c0) sets only fault 29 = P0500. It is the vehicle speed sensor
  zero-under-load check: 10 events (30 passes each with boost above baro over 94.8 kPa and filtered load over 40 %)
  plus 10 accelerator off-idle entries while the sensor reads 0. Renamed
  `cm848_detectVehicleSpeedSensorZeroUnderLoad`, together with its group:
  - `cm848_clearHealedVehicleSpeedSensorFault` (0x526bc8, was `diag_boostLoad_overtemp_clear`);
  - `cm848_runVehicleSpeedSensorMonitors` (0x526c80, was `cm848_calibration_group30_execute`);
  - `cm848_initializeVehicleSpeedSensorZeroUnderLoadMonitor` (0x526cb8, was `cm848_state_variables_reset`);
  - the state: `vehicle_speed_zero_under_load_*` (pass count, the two EEPROM-backed `_cal` counts, the filtered
    load, the previous accelerator off-idle state) and the `ema_filter_state_t` at 0x3fd070 (was a flat dword
    `engine_load_ema_filter_pointer`);
  - the eight ROM limits at 0x5c964-0x5c974 (two of them belong to `cm848_detectVehicleSpeedSensorSignalLoss`).
- `cm848_buildPgn65213FanDrive1Message` (0x2641c): the invented `dest_address` / `status_type` parameters are gone
  (`void (void)`; r3 / r4 are written before they are read).

## Open leads (unverified: the P-code each function sets vs its name)

| Function | Address | Fault → P-code | SAE meaning |
|---|---|---|---|
| `diag_eepromFault_pendingStatus_update` | 0x522a30 | 298 → P0711 | transmission fluid temperature sensor A range / performance |
| `protection_enable_state_machine` | 0x512130 | 394 / 395 → P0573 / P0572 | brake switch A circuit high / low |
| `sensorValidationTimeout` | 0x5227ac | 406 → P0837 | four-wheel-drive switch circuit range / performance |
| `cm848_main_loop_protection_eval` | 0x53064c | 398 → P0461 (397: no slot) | fuel level sensor A range / performance |
| `hpcr_coldBurndownControl` | 0x532fac | 367 → P0300 | random / multiple cylinder misfire |
| `governorSpeedLimitTable` | 0x524360 | 357 → P0602 | control module programming error |
| `mpc555_processColdStartMainLoop` | 0x1c28c | 27 → P0219 | engine overspeed condition |
| `cm848_processEngineConditionFlags` | 0x3dd98 | 320 → P0720 | output speed sensor circuit |
| `hpcr_calibration_group36_load` | 0x52d40c | 340 → P0106 | MAP / barometric pressure range / performance |
| `cm848_calibration_group21_load` | 0x52d6a8 | 64 / 729 / 778 → P0236 / P0299 / P0069 | boost sensor range / underboost / MAP-baro correlation |
| `cm848_calibration_group22_load` / `_group37_load` | 0x52e29c / 0x530428 | 774-776 / 402 (no slot) | - |

Also suspect, not renamed: the three gate words of the P0500 monitors. `protection_feature_status_flags` (0x40b9d0)
bits 0 / 1, `boost_fuel_bypass_flags` (0x40b9d4) bits 0 / 1 and `fault_management_status_flags` (0x3fd5b4 = EEPROM
0x132, so it should be `_cal`) bits 0x100 / 0x200 enable / suspend paths 1 / 2. Each word is shared by 30+
unrelated monitors, so they need their own review.

## Investigation Log

- 2026-11-17: the first find was on a checkout 36 commits behind main (the PGN 65213 Fan Drive builder, already
  renamed by PR #50); every claim above was rechecked on 809fd25. Notes, scripts, the sweep output and the build logs
  are in the session folder named above.
