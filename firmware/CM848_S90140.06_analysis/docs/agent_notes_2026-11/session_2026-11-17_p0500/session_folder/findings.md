# CM848 S90140.06 naming finding (2026-11-17)

Read-only investigation (investigate-firmware-symbol skill). Nothing was changed in the repo.

**Applied afterwards** on branch `cm848/vehicle-speed-sensor-p0500-monitor` (see `work/tasks/044-cm848-dtc-code-name-clashes.md`).
The final names differ from the proposals below in three places:
- the pedal count is an "accelerator off-idle entry" count, because `press` is a banned abbreviation in the rename gate;
- the filter follows the `<x>_filter_state` / `<x>_filter_coefficient` convention, with 0x3fd070 typed `ema_filter_state_t`;
- the eight ROM limits at 0x5c964-0x5c974 got rows too.

**The local checkout (~/code/kuminz-re, HEAD 3996350 = PR #49 merge) is 36 commits behind origin/main (809fd25 =
PR #50 merge).** The first finding below was made on that stale `.cpp` and is already fixed on origin/main. The
second finding was checked against origin/main (`git show origin/main:...` copies).

## Finding 1 (stale checkout only): PGN 65213 Fan Drive builder, fixed upstream by PR #50

On the local checkout, `cm848_j1939SendDiagnosticStatusMessage` (0x2641c) / `cm848_initJ1939BrakeRetarderBuffer`
(0x26480) are the PGN 65213 FD1 builder / descriptor setup. origin/main already has
`cm848_buildPgn65213FanDrive1Message` / `cm848_initializePgn65213FanDrive1Buffer` and the FD1 globals renamed.

**Still wrong on origin/main:** `function_definitions.csv` keeps two invented parameters on 0x2641c
(`0,dest_address,byte` / `1,status_type,byte`). The asm writes r3 (`addi r3,r3,-20960` @ 0x2642c) and r4
(`lis r4,65` @ 0x26444) before any read, and its own plate comment on main says the two parameters are unused.
Fix: delete both rows. This makes the prototype `void (void)`, like the other periodic builders.

Evidence kept for the record:
- Header 0xfebd00, byte count 2, data -> 0x3fae20. RAM dump (base 0x3FA000): 0x3fae28 = `18 fe bd 00`.
- `diag_record_queue_add_entry(0,0xfebd,1000,...)`: queue 0 at 1000 ms.
- Builder asm: `lhz` 0x40a2a8 -> `mulli 5` -> `srwi 9` -> `stb` byte 1. `lha` 0x40a292 -> `cmpwi 15` -> `ori 0xF0` or
  `li 0xFE` -> `stb` byte 2.
- J1939-71 positions come from the local Mongo `j1939.pgns` doc filed under number **65212** ("TFI") with
  `pgn_references: [65213]`. The doc filed under 65213 ("Fan Drive #1", ISOBUS) has no byte positions. Byte 1 = SPN 975
  at 0.4 %/bit, byte 2 bits 1-4 = SPN 977. The firmware evidence carries the claim on its own.
- Whole-binary sweep: 0x40a2a8 / 0x40a292 have no store in any form `disasm_func.find_accesses` tracks. That does not
  rule out a 32-bit pointer to them held in a data table or passed to a callee, or a block write. The "1/256 % per
  count" input unit is inferred from the x5>>9 scale only.

## Finding 2 (current on origin/main): `diag_boostLoad_overtemp_monitor` is the P0500 vehicle speed sensor rationality monitor

| Address | Name on origin/main | What it is | Proposed |
|---|---|---|---|
| 0x5269c0 | `diag_boostLoad_overtemp_monitor` | P0500 detector, path 2: speed sensor reads 0 while the engine is clearly driving | `cm848_detectVehicleSpeedSensorZeroUnderLoad` |
| 0x526bc8 | `diag_boostLoad_overtemp_clear` | heals P0500 (clears fault 29 + the counters) | `cm848_clearHealedVehicleSpeedSensorFault` |
| 0x526c80 | `cm848_calibration_group30_execute` | the task that runs the P0500 monitors | `cm848_runVehicleSpeedSensorMonitors` |

Evidence (origin/main `.cpp` lines 83048-83170; asm from `originals/cm848_flash2_live.bin`):
- The only fault it sets is `fault_detected_bits_16_to_31 | 0x2000` = fault 29. ROM 0x5985a[29] = slot 24 and
  `obd_dtc_code_table[24]` = **P0500 (Vehicle Speed Sensor A)**. The same mapping reproduces the documented
  407 -> P0483, 304 -> P0193 and 82 -> P2509.
- Asm @ 0x526b70-0x526b88: `cmpwi r12,2; bne`, `mtspr 81` (EID), `lhz r12,2(r31)`, `ori r12,r12,8192`,
  `sth r12,2(r31)`, `mtspr 80` (EIE): an interrupt-safe set of bit 13 of the word at 0x3fe976.
- Present in the local (stale) file too: `diag_boostLoad_overtemp_monitor` at line 79588 (fault set at 79636),
  `diag_boostLoad_overtemp_clear` at 79646, `cm848_calibration_group30_execute` at 79669. The repo itself calls bit 13
  the vehicle speed sensor fault (the sibling's plate comment and `vehicle_speed_sensor_ok_flag`'s CSV comment).
- Logic: runs only while `vehicle_speed_unfiltered` (`lhz` @ 0x526a10) is 0 and faults 8 / 9 are clear. Those are
  P0238 / P0237, boost sensor circuit high / low, so the monitor is skipped while the boost sensor itself is faulted. It EMA-filters `engine_load_percent` (1/256 %). A pass with boost above baro over 1760 counts (ROM 0x5c966,
  1/18.56 kPa, so about 95 kPa) and filtered load over 10240 (0x5c96e, 40 %) adds 1. 30 passes (0x5c974) make one
  event. Separately it counts accelerator tip-ins at the governor setpoint: `accelerator_off_idle` is 1 while the
  caller's previous-pass copy (`fuel_demand_enable_snapshot`) is 0. P0500 sets at 10 events (0x5c964) and 10 tip-ins
  (0x5c96a). In plain terms: the engine has pulled hard 10 times and the pedal was pressed 10 times, yet the speed
  sensor never read anything. No temperature is involved anywhere.
- Siblings: `cm848_detectVehicleSpeedSensorSignalLoss` (0x526924, already correctly named) sets the same fault 29
  (path 1: the sensor reads 0 while the filtered vehicle_speed is still above 2560 = 10 mph and load is at least 3840 =
  15 %). Path 1 is enabled by bit 0x100 of `fault_management_status_flags`, path 2 by bit 0x200.
  `diag_boostLoad_overtemp_clear` clears fault 29 and all three counters when both paths are disabled, or when the
  sensor reads non-zero at the governor setpoint. The caller `cm848_calibration_group30_execute` runs
  `bl 0x526924`, `bl 0x5269c0`, `bl 0x526bc8`, then `sth` of `accelerator_off_idle` into 0x3fd06c.
- Likely root cause (a hypothesis): the sibling's plate says it "was diag_fuelTempTrim_overtemp_check", so the
  "overtemp" names probably come from the time `vehicle_speed` was misread as `fuel_temperature_trim` (re-domained
  2026-11-12, PR #46). The sibling was renamed. These two kept their old names.
- RAM dump: `fault_management_status_flags` (0x3fd5b4, EEPROM mirror) = 0x2e06, so path 2 is enabled (bit 0x200) and
  path 1 is not (bit 0x100). The run gate `protection_feature_status_flags` (0x40b9d0, `lwz` @ 0x5269d4) = 0x06ff4040,
  bit 1 clear, so the monitor was not running at the moment of the dump. Fault 29 and the counters are 0.
- Not logged on origin/main: `git grep 'boostLoad_overtemp|0x5269c0'` in work/ + docs finds nothing that questions the
  name. `result_W4_air.jsonl` only lists it as an `engine_load_percent` reader.
- Cross-firmware analogue: not checked.

The globals it uses are misnamed the same way (medium confidence on the exact wording):
- 0x3fd06e `diag_boostLoad_overtemp_qualifying_cycle_count` -> `vehicle_speed_zero_under_load_pass_count` (copy
  window, time-shared app RAM, no _cal)
- 0x3fee7e `diag_boostLoad_overtemp_event_count` -> `vehicle_speed_zero_under_load_event_count_cal` (EEPROM mirror)
- 0x3fee80 `diag_boostLoad_overtemp_demand_qualify_count` -> `vehicle_speed_zero_tip_in_count_cal` (EEPROM mirror)
- 0x3fd06a `protection_channel_load_snapshot` -> `vehicle_speed_monitor_engine_load_filtered`
- 0x3fd06c `fuel_demand_enable_snapshot` -> `accelerator_off_idle_previous`. Its comment says it is a copy of
  `fuel_demand_control_t.enable_flag`, but `xref_addr.py 0x3fd06c` finds 1 write (`sth` @ 0x526ca4 in the caller,
  storing `.accelerator_off_idle`) and 1 read (`lha` @ 0x526a7c in the monitor). Nothing else touches it.

## Other P-code / name clashes from the same scan (not verified, leads only)

The scan is `fault_setters.py` (output in `fault_setters_origin_main.txt`):
- `diag_eepromFault_pendingStatus_update` (0x522a30) sets fault 298 = P0711 (transmission fluid temperature sensor
  range/performance).
- `protection_enable_state_machine` (0x512130) sets P0572 / P0573 (brake switch circuit low / high).
- `sensorValidationTimeout` (0x5227ac) sets P0837 (4WD switch range/performance).
- `cm848_main_loop_protection_eval` (0x53064c) sets P0461 (fuel level sensor range/performance).
- `hpcr_coldBurndownControl` (0x532fac) sets P0300 (random / multiple cylinder misfire).
- `governorSpeedLimitTable` (0x524360) sets P0602 (control module programming error).
- `mpc555_processColdStartMainLoop` (0x1c28c) sets P0219 (engine overspeed condition).
- `cm848_processEngineConditionFlags` (0x3dd98) sets P0720 (output speed sensor circuit).
- `hpcr_calibration_group36_load` sets P0106, and `cm848_calibration_group21_load` sets P0236 / P0299 / P0069.

## Reproduce

```
cd firmware/CM848_S90140.06_analysis
git show origin/main:firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp > /tmp/main.cpp
python3 -I fault_setters.py /tmp/main.cpp originals/cm848_rom.bin
python3 ../scripts/disasm_func.py 0x5269c0 0x3fe976
```
