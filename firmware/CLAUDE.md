# Firmware Analysis Guide

This directory contains reverse-engineered Cummins ECU firmware from different generations.

## Firmware Versions

| Directory | Source | ECU | Status | Purpose |
|-----------|--------|-----|--------|---------|
| `CM550_J90350.00_analysis/` | Live ECU dump (bench) | CM550 | Active | Full ROM + RAM extraction |
| `CM848_S90140.06_analysis/` | 2004.5 Dodge 5.9L | CM848D | Active | PowerPC MPC555 analysis |

---

## Ghidra version pinning (per-firmware — DO NOT mix)

The decompiler's output is **version-specific**: the same binary + CSVs analyzed with a
different Ghidra version produces thousands of lines of spurious diff (placeholder-local
renaming, cast/loop rendering, `undefined`↔`undefined1`). Each firmware is therefore pinned to
exactly one version, set as `REQUIRED_GHIDRA_VERSION` in its `analyze.sh`, and the build refuses
to run against any other (`check_ghidra` in `scripts/common.sh` validates `application.version`).

| Firmware | CPU | Required Ghidra | Install | Why |
|----------|-----|-----------------|---------|-----|
| CM848 | MPC555 / PowerPC | **12.1** PUBLIC | `$HOME/code/ghidra-12.1/ghidra_12.1_PUBLIC` | mainline supports MPC555; 12.1 also renders struct bitfields (GP-2493) |
| CM550 | MC68336 / 68k | **12.0** DEV (from source) | `$HOME/code/ghidra` | the 68k/CM550 CPU support is on an **unmerged** Ghidra branch, not in any release |

- Override the install path with `GHIDRA_DIR=...`, but its `application.version` must still match
  the firmware's pin or the build fails gracefully (telling you which version is needed and where).
- **CM550 reproducibility caveat:** "12.0 DEV" is *not* a precise pin — the from-source build tracks
  a moving branch, so two checkouts both report `12.0` yet decompile differently (newer builds
  recover more, e.g. masked-flag expressions the older committed baseline rendered as `0`). Until
  the 68k support merges to a release, a CM550 `.cpp` is only reproducible against the *exact* Ghidra
  commit it was built from.
  - **Status (checked 2026-06-12):** CPU32 / 683xx support (the MC68336 family CM550 uses) was
    **merged to Ghidra `master` ~2026-06-10** — issue [#1244](https://github.com/NationalSecurityAgency/ghidra/issues/1244)
    closed as completed (impl via PR #9084; the old 2021 PR #2617 was superseded/closed unmerged).
    It is **not yet in a tagged release** (latest is 12.1.2, 2026-06-05, before the merge). When the
    next release ships it, CM550 can move off the from-source DEV build to a **pinned PUBLIC release**
    (like CM848) and become reproducible — at which point bump CM550's `REQUIRED_GHIDRA_VERSION`.

---

## Shared Scripts Infrastructure

All Ghidra analysis scripts are shared in `firmware/scripts/`:

```
firmware/
├── scripts/                      # SHARED: All Ghidra Java scripts
│   ├── common.sh                 # Shared bash functions
│   ├── ImportAnalysis.java
│   ├── ExportAnalysis.java
│   ├── ApplyEnums.java
│   ├── ApplyStructures.java
│   ├── ApplyLabels.java
│   ├── ApplyConstants.java
│   ├── ApplyArrays.java
│   └── ... (16 total scripts)
├── CM550_J90350.00_analysis/
│   ├── ghidra/
│   │   ├── analyze.sh            # Thin wrapper (firmware-specific config)
│   │   └── project/              # Ghidra project files
│   └── output/*.csv              # CSVs + decompilation
└── CM848_S90140.06_analysis/
    ├── ghidra/
    │   ├── analyze.sh            # Thin wrapper (firmware-specific config)
    │   └── project/              # Ghidra project files
    └── output/*.csv              # CSVs + decompilation
```

**Script utilities:** `firmware/scripts/ScriptUtils.java` and `CsvCommentIndex.java` contain all pure (non-Ghidra) logic — CSV parsing, address parsing, type classification, comment preservation. New scripts should use these rather than copy-pasting. No Ghidra JARs needed to compile or test them.

**Script test suite:** `cd firmware/script_tests && ./run_tests.sh` — 61 JUnit 5 tests covering ScriptUtils and CsvCommentIndex. Tests live in `firmware/script_tests/` (NOT inside `firmware/scripts/`) because Ghidra's `GhidraSourceBundle` recurses into subdirectories when compiling the bundle. Any `.java` file with imports not on Ghidra's classpath (e.g. JUnit) inside `firmware/scripts/` will break ALL script compilation with "class not found" errors.

---

## CM550 (J90350.00) Analysis Notes

**Source:** Live ECU extraction from bench — complete ROM, RAM, and EEPROM dumps.

- **MCU:** Motorola MC68336 (68020 core)
- **ROM:** 256KB (0x00000000 - 0x0003FFFF)
- **RAM:** 37KB at 0x00800000 (live dump available)
- **Extended RAM:** 28KB at 0x008091C2
- **EEPROM:** 4KB at 0x01000000

---

## CM848 (S90140.06) Analysis

### Dual-Bank Flash Architecture

| Bank | Address Range | Size | File |
|------|---------------|------|------|
| Bank 1 (ROM) | 0x00000000 - 0x0006FFFF | 448KB | `cm848_rom.bin` |
| Bank 2 (FLASH2) | 0x00500000 - 0x0053DFFF | 248KB | `cm848_flash2_live.bin` |

Bank 2 contains utility functions called from Bank 1 (sensor processing, math routines).

**Completed (2026-01-31):** Bank 2 dumped from live ECU. See `CM848_S90140.06_analysis/docs/TASK_dump_bank2.md`.

### ROM-to-RAM Code Execution (CM848)

`copyCalibrationToRam()` copies ROM 0x3C30-0x7F60 (17KB) to RAM 0x3F9800-0x3FDB30 at boot. Formula: `ROM_addr = 0x3C30 + (RAM_addr - 0x3F9800)`.

**That image is the BOOT REFLASH KERNEL, not application code (verified 2026-11-11, PR #46).** It runs from RAM so flash can be erased/programmed underneath it — not "for performance". Evidence: (1) all 75 branches into the RAM window come from the low boot ROM 0x0-0x3C2F (reset / key-on / EEPROM calibration load+download / flash init); ZERO from application ROM (>= 0x7F60); (2) in the runtime RAM dump NONE of the 67 dump-covered image functions is intact (4-28% byte match = chance), because the running application reuses that RAM for its own variables (PCI timers, QSPI job queues, ...). Contents: its own CAN driver, J1939 transport (RTS/CTS/abort), diagnostic dispatcher with memory-WRITE services 68/69/75/77 (0x44/0x45/0x4B/0x4D), EEPROM/flash transfer, auth-token descramble + write-auth check, transfer CRC, SCI driver, watchdog and its own main loop.
- Consequences: (a) a global in 0x3F9800-0x3FDB30 and the image function at the same address are BOTH real — they just live at different times (boot vs running app); (b) the runtime RAM dump is useless for reading image code — use the ROM; (c) many image function names were guessed from app-like patterns (`processAdc*`, `processSensor*`, `sensorFaultThresholdCheck`) and are suspect — e.g. 0x5728-0x58e8 were "ADC sensor" names but are the kernel's memory-write services.
- **Kernel flash driver = MPC555 CMF (PR #46):** the old `mbar_qadc64*` registers at 0x2FC800/04/08 and 0x2FC840/44/48 are **CMFMCR/CMFTST/CMFCTL** for flash modules A and B (not QADC). `mpc555_cmfEraseBlocks` (0x49d0), `mpc555_cmfSelectBlockAndStartSequence` / `mpc555_cmfLoadProgramPage` / `mpc555_cmfApplyHighVoltagePulse` / `mpc555_cmfEndHighVoltagePulse` / `mpc555_cmfRestoreNormalMode` (0x4320-0x46dc). Download path: `cm848_writeDiagMemory` (0x5400) → `cm848_lookupMemoryRegionType` over `memory_region_table` @ RAM 0x3f9830 (main flash 0x0-0x6FFFF type 4 / Bank-2 0x500000-0x5FFFFF type 2 only when `flash2_writes_enabled` / RAM 0x302000-0x3FFFFF type 0 / EEPROM 0x1000000-0x1003FFF type 5 auth / registers 0x2FC000-0x307FFF type 3 auth) → `cm848_trackDownloadBlock` + CRC16 `cm848_updateDownloadCrc` → `cm848_finishDownloadBlock`; responses via `cm848_sendDiagServiceResponse` (PGN 61184: 0x0C ok / 0x0D + code / 0x0E pending).
- **Kernel structure (PR #46):** the boot loop enters `cm848_runBootKernelLoop` (0x6ca4) when a reflash mode is set (`eeprom_service_mode_flags` 0x81 = CAN / 0x82 = serial) and the EEPROM magic is 0x1d0a. Each pass: `cm848_runFlashProgramStateMachine` (0x4720) + serial service-0x34 download handlers (`mpc555_sciHandleDownloadStart` / `...DataBlock`) + `cm848_serviceSupervisorWatchdog` + `mpc555_runPeriodicInterruptTimerTick` (CAN dispatcher + J1939 transport: `mpc555_dispatchJ1939TransportConnectionManagement`, request-to-send / clear-to-send / data packets / end-of-message acknowledge / abort - inbound accepts only PGN 61184, up to 1040 bytes).
- **Supervisor chip (external, QSPI) — question/answer watchdog:** `cm848_initSupervisorWatchdog` (0x7b08, first call after the kernel copy) + `cm848_serviceSupervisorWatchdog` (0x7974, answers from four 16-entry tables at ROM 0x3c9c-0x3ccc) + `cm848_forceSupervisorWatchdogReset` (0x7dc4, wrong answers on purpose before every software reset). The same chip (QSPI PCS1, command byte 0x5D) is the application's **supervisor chip**: `cm848_initSupervisorChip` (0x37334, was initPeriodicTimerSystem) sets up 7 `qspi_job_t` jobs (watchdog / configuration write 0x94-0xA4 / output write 0x92 / register reads 0x24 0x2E 0xA2 / status read 0x4E 0x5A 0x5C) scheduled by `cm848_runSupervisorChipSchedule`; the application watchdog is `cm848_startSupervisorWatchdog` / `cm848_runSupervisorWatchdogCycle` / `cm848_answerSupervisorWatchdog` (answer tables at ROM 0x576e4 identical to the kernel's). The whole 0x367a4-0x37580 family was J1939-named; the application meaning of the reply globals it fills (protection_inhibit_flag / engine_idle_mode_flags / j1939_lamp_status_cache ...) is not yet reviewed. A **serial output driver** on QSPI PCS2 (SPI mode 3, 8-bit; `serial_output_driver_job`) carries output lines 152-159: `mpc555_driveOutputLineHigh/Low` for lines 152-159 and `cm848_refreshOutputPortsAndReadback` (0x529b8, was the misnamed injectorTimingCalculation) queue it; its reply is `serial_output_driver_status_byte`. QSPI chip-select map: PCS0 = SPI EEPROM, PCS1 = supervisor chip, PCS2 = serial output driver, PCS3 = J1850 PCI controller.
- **Runtime counter = `ecu_power_state_flags.runtime_counter` (RAM 0x302012):** loaded from EEPROM 0x1000030 at boot (`mpc555_loadRuntimeCounterFromEepromShadow`), +1 every 41 PIT ticks in `mpc555_tickTransferTimeoutAndRuntimeCounter` (~0.205 s/count if the PIT runs at 1 MHz), saved back at key-off by `mpc555_keyOnStateMachine`; also the auth-token freshness clock. Engine-hours lead — see `docs/engine_hours_and_odometer.md`.
- **TIME-SHARED RAM caution:** 0x3fdba4-0x3fdc38 holds the kernel's CMF erase/program parameters during boot/reflash, but some of the same addresses are read by application code at runtime (e.g. 0x3fdba4 / 0x3fdba8 / 0x3fdbb2 / 0x3fdbd1 / 0x3fdbd2 / 0x3fdbdc / 0x3fdbfe by protection + J1939 builders). One Ghidra name per address — run an app-user check (`xref_addr.py`, caller ≥ 0x7F60) before renaming anything here; dual-use addresses keep their app-side name and document both roles.

Functions at `0x003Fxxxx` in decompilation (e.g. `BYTE_003fae3c()`) are calls from the boot ROM into the kernel's RAM copy — Ghidra already has them decompiled at their ROM source addresses.

**Declaring data in this window:** an array/struct's boundary is usually the copy-window EDGE (0x3FDB30), not the next named global — post-copy working RAM (handler tables etc.) begins at 0x3FDB30. Size arrays to 0x3FDB30, not to the next symbol (it may belong to a different structure). Array typing DOES apply over this code-overlap region (verified deterministic via `analyze.sh verify`) — the "types revert on export" caution is about scalar WIDTH, not array creation.

**Flat globals alias function bodies here:** a flat global declared in the slice overlapping a RAM-executed function gets a permanent `_` prefix (the function-image symbol wins) — declare it via `arrays.csv`/`structure_definitions.csv`, which survive. Hottest zone: `dispatchCanMessageHandlers` at RAM **0x3FAE3C–0x3FAFD0** (e.g. the PGN-65249 TX payload 0x3FAE51–0x3FAE62 must be an array, not 18 flat bytes).

Key RAM-executed functions called from `mainLoopIteration`:
- `dispatchCanMessageHandlers` (ROM 0x526C → RAM 0x3FAE3C)
- `mpc555_serviceJ1939TransportSessions` (ROM 0x64C4 → RAM 0x3FC094)

### CM848 ECU Version Info

| Location | Value | Description |
|----------|-------|-------------|
| EEPROM 0x0130 | V11.46.06 | Calibration version |
| EEPROM 0x0046 | 1504 2RSAO | Calibration ID |
| EEPROM 0x0217 | CC | Module ID (CM848) |
| EEPROM 0x0002 | ABCDEF | Security key |
| ROM 0x010C | 100902 | Build date |

**Note:** E2M file S90140.12 is V11.20.13.16 - different from ECU's V11.46.06. Use live dumps for analysis.

### CM848 External Datalinks (per 2004 Dodge FSM)

The ECM speaks J1939/CAN **plus CCD (C1 pins 4/5), SCI (C2 pins 16/19 → PCM + DRB), and PCI/J1850 VPW (C2 pin 28)**. The MPC555 **QSMCM = QSPI + 2 SCIs** — don't dismiss it as QSPI-only. **SCI1** (`qsmcm_sccr1` @ 0x305008) is the ECM↔PCM/DRB serial link: a DRB-style diagnostic protocol (`mpc555_sci*`, boot side) **and** the application's SCI command protocol `cm848_sci*` (19-entry dispatch table @ 0x53a9a0; **was misnamed `cm848_fuelDemand*` — re-domained 2026-11-12, PR #46**: command 18 = high-speed mode (SCC1R0 0xa0 -> 0x14) with 0xF5-0xFD table reads / 0xFE exit, 23 = clear diagnostics, 39/40 = EEPROM setting write/read, 43/44 = security seed/key (`cm848_sciValidateSecurityKey`), 50/51/52 = fault SPN reports). The real fuel-demand math (`cm848_fuelDemand*` at 0xdcdc-0x17980) is unrelated and keeps its names. SCI2 is unused; the **CCD driver is still undiscovered** (external transceiver/bit-bang — not SCI2, not MIOS).

**PCI/J1850 message layer FOUND (2026-11-11, PR #43):** two contiguous ROM tables of 28-byte `pci_message_descriptor_t` — `pci_receive_message_table` @ 0x5774b (15) then `pci_transmit_message_table` @ 0x578ef (25), counts @ 0x57bab/0x57bad. Each record = up-to-3-byte header (zero-terminated) + payload/length pointers + `interval` + RAM `timer`/`status` pointers. Proof: headers `68 6A`/`48 6B` = SAE J1850 OBD-II request/response; TX has 0x10/0xC0/D1 03/F0 xx VIN, RX has 0x37 (48RE shift lever). `cm848_checkPciMessageTimeouts` (0x38ac8) ages the timers.

**The PHY is an external J1850 controller on the QSPI (2026-11-11, PR #44)** — that is why no on-chip PCI peripheral exists. Two `qspi_job_t` jobs talk to it: `pci_controller_command_job` (0x40b357, sends command words) and `pci_controller_receive_job` (0x40b36d, polls a status+byte word). Flow:
- `cm848_onPciControllerReceiveWord` (0x39f54, receive-job callback) splits the word: top 3 bits `0x20/0x40/0x80` = data byte → `cm848_matchPciReceiveHeader` (0x38cf0, per-byte header match vs both tables); `0xa0/0xc0/0xe0` = end of frame → `cm848_completePciFrame` (0x39004).
- `cm848_schedulePciTransmit` (0x3adcc) builds the first overdue TX entry into `pci_transmit_frame_buffer`; `cm848_servicePciTransmit` (0x39e30, command-job callback) feeds the controller (frame bytes / in-frame response bytes via `cm848_sendPciInFrameResponseByte` / `0xaf8` after a link event).
- J1850 **in-frame response (IFR)** is supported per message (`in_frame_response_enabled` / `in_frame_response_bytes`); only TX 0xB0 uses it in this calibration.
- `link_event_code` setters: 1 = controller word bit 0x800, 2 = own echo differs from what was sent, 3 = non-data status mid-frame, 4 = TX-echo frame completed with error, 5 = RX in-frame response error, 6 = RX frame completed with error, 7 = every scheduled TX overdue. `cm848_handlePciLinkEvent` (0x3a290) applies `pci_link_event_action_mask_cal`; 255 counted errors latch `power_state_status_flags` 0x8000 + `mpc555_driveOutputLineLow(124)` (output line 124 — likely the controller's reset line; the old names `updateEngineSyncStatus` / `clearModuleSyncFlag` were the generic output-line drivers).
- **QSPI job driver (PR #45):** `cm848_registerQspiDeviceSlot` (0x3d68c, up to 4 device slots: SPI mode / kHz / delays), `cm848_queueQspiJob` (0x3da60, two 16-deep `qspi_job_queues`; queue 0 serviced first — PCI in-frame response bytes use it), `mpc555_qspiStartJob` (0x3d904), `cm848_completeQspiJob` (0x3dbc0, run by `cm848_onQspiFinished` on SPIF). Every `qspi_job_t` caller is a QSPI device driver — the `cm848_j1939Queue*` family @ 0x367xx and the `cm848_protection*` callers @ 0x4bxxx are NOT J1939/protection code and need their own review.
- **QSMCM register map corrected:** 0x305015 = PORTQS low byte, 0x305016 = PQSPAR, 0x305017 = DDRQS, 0x305018-0x30501f = SPCR0 / SPCR1 (SPE) / SPCR2 / SPCR3 / SPSR (`qsmcm_qspi`). 0x305010-0x305013 are unused.

**EEPROM RAM mirror CONFIRMED (2026-11-11, PR #46):** the application's SPI serial-EEPROM driver (`cm848_initEepromDriverAndLoadMirror` @ 0x4cb64, QSPI PCS0) reads EEPROM offsets 0x0-0x1a3f into RAM **0x3fd482-0x3feec1** (`eeprom_mirror`; RAM = 0x3fd482 + EEPROM offset), checksums EEPROM 0x8ea-0x1a3d against `eeprom_block_checksum_expected_cal` (EEPROM 0x5c; fault bit 0x40), and `cm848_startEepromMirrorSave` writes that block back with page writes. So every value in that RAM range is EEPROM-backed (`_cal`), not just 0x3feexx.

**J1939 input layer (2026-11-12, PR #46):** Bank-2 receive handlers `j1939_receivePgn{57344,61441,61443,65252,65264,65265}Handler` (registered by `j1939_handlerInitializer`) accept each signal only from `j1939_input_source_address_filter_cal[slot]` (0xFF = any; all 0xFF in this cal), reload `j1939_input_signal_timeouts[slot]` and store `j1939_received_*`. Two tasks process them: `cm848_processJ1939SwitchAndRequestInputs` (0x50aba8 — the 17-entry `j1939_input_signal_descriptor_table` @ 0x53a278 via `cm848_evaluateJ1939InputSignalFault`, CM1 fan request = input 0, EBC1 retarder selection = input 5) and `cm848_processJ1939AcceleratorInputs` (0x50ad1c — EEC2 low idle switch = input 6, pedal position = input 7); per-input bitmaps `j1939_input_timeout_bitmap` / `j1939_input_data_error_bitmap` / `j1939_pedal_input_timeout_bitmap`. **The whole layer is OFF in this calibration** (`j1939_input_processing_enable_cal` bit 0x400 = 0, and every per-input enable is 0 too).
- **Consumers (whole-binary scan of both banks + 32-bit pointer search, 2026-11-12):** only EEC2 pedal position 1, the EEC2 low idle switch, EBC1 retarder selection (→ `j1939_engine_retarder_selection_percent`, read by `cm848_processProtectionSystemBit4`) and CM1 fan request have processors. The **CCVS1 cruise / brake / clutch / idle increment-decrement / test-mode switches, the EBC1 switches, pedal position 2 and the remote pedal position are received and supervised but read by NOTHING else** — J1939 cruise switches cannot drive cruise in S90140.06.
- **Drive-by-wire dead end (task 022):** `cm848_processJ1939AcceleratorPedalPosition` scales EEC2 SPN 91 into `j1939_accelerator_pedal_position` (0.25 %/bit) which **has no reader**; setting `fuel_demand_feature_flags` bit 0x2000 only makes `cm848_fuelDemandFinalCalculation` copy the raw pedal-sensor counts unscaled. A J1939 pedal never reaches fueling — **TSC1 is the only J1939 fueling path**. The CM1 fan request output is write-only as well.
- Positions: EBC1/EEC2 from the j1939 Mongo DB; CCVS1 and CM1 from standard J1939-71 (the DB docs for those have no positions). SHUTDN / PTO values are still unnamed.
- The ROM `j1939HandlePgn65265CruiseVehicleSpeed` (0x24178) and `j1939HandlePgn61443Eec2` (0x25b10) are the ECM's own CCVS1 / EEC2 **transmit** builders (they end in `sendJ1939Message`), not receive handlers — names not yet fixed.

**Switch-input layer (2026-11-12, PR #46):** 32 logical switches, scanned by `cm848_scanAndDebounceSwitchInputs` (0x4eb48). Each switch comes from (a) `switch_input_datalink_state_bits` when its `switch_input_datalink_source_bits_cal` bit is set (EEPROM 0x74c; the J1939 input layer writes it through `cm848_set/clearDatalinkSwitchStateIfPriority`, arbitrated by `switch_input_source_priority`), (b) its hardware line `switch_input_hardware_line_cal[n]` (EEPROM 0x70c) read from the input-line image @ 0x40c0f8 (filled by `cm848_readDiscreteInputLine`, 0x4f2ec) XOR `switch_input_polarity_bits_cal`, or (c) its software-set value when it has no line (e.g. switch 31). A 4-sample debounce writes `switch_input_state_bits` @ 0x40c050 (switch n = byte n/8, bit n%8).
- Identified: **7 = accelerator at idle, 8 = accelerator off idle** (idle validation pair; `cm848_evaluateIdleValidationSwitches` cross-checks them against the pedal sensor into `fuel_demand_control_t.idle_validation_state` 0-8). The ECM's CCVS1 broadcast reports **15 as the clutch switch and 11 as the brake switch**. **31** is software-maintained (set by the 0x2c2xx-0x2c6xx cluster from presses of switch 0); `cm848_fuelTrimFromOutputShaftSpeed` uses it (with `protection_control_licensed`) to pick the second axle-ratio divisor, and the CCVS1 builder derives almost every switch field from it (byte 1 two-speed axle, byte 4 cruise enable, all of bytes 5 and 8) — so the ECM does not broadcast real per-switch states there; its meaning is not yet settled.
- This calibration's line map: 0:128 1:132 3:148 5:138 6:137 7:144 8:145 9:130 10:131 11:147 12:149 14:150 19:148 20:13 21:18 22:154 23:153 24:156 25:152 27:155 28:22 (no line: 2 4 13 15-18 26 29-31).
- The old `protection_enable_t_0040c050` struct (`mode_bits` / `system_enable_bits` / `protection_active`) WAS this array. `protection_active` was a 1-bit field on byte 3 and Ghidra 12.1 drops bitfield masks, so it rendered for ANY bit of byte 3 — pre-PR-46 readings of "protection active" are suspect. The `protection_*` functions that test these bits (bit 31 is written by the 0x2c2xx-0x2c6xx cluster from presses of switch 0) need review.

**Vehicle speed (2026-11-12, PR #46) — the old "fuel temperature trim" family IS the vehicle speed chain.** `vehicle_speed` @ 0x40a272 (was `fuel_temperature_trim`, 50+ readers) = 1/256 mph per bit. Source 1: the speed sensor on **TPU-B channel 2** (`cm848_initVehicleSpeedSensorChannel`, period-measurement function 0xD; `cm848_vehicleSpeedSensorInterruptHandler` copies the period and reloads `vehicle_speed_pulse_timeout`); `cm848_calculateVehicleSpeed` = 921600 x 40e6 / (pulses_per_mile x 128 x period) with `vehicle_speed_sensor_pulses_per_mile_cal` = **8000** (EEPROM 0x46e; the Chrysler standard), 3.2 us TPU ticks, 2-150 mph clamps, jump rejection, EMA. Source 2 (J1939 automatic drivetrain): `cm848_calculateVehicleSpeedFromOutputShaft` from the transmission output shaft speed with an axle divisor chosen by switch 31 + `protection_control_licensed` (two-speed axle). The CCVS1 broadcast sends it x 412/256 (mph -> km/h). On this truck it reads 0 (no sensor wired; period still at its 0x5e7fb044 start value). `drivetrain_ratio(_raw)` = engine speed over vehicle / output-shaft speed x 2048. Fault freeze frames store it (`fault_entry_t.vehicle_speed`, was `temperature_trim`). Many other `fuel_temp*` / `fuelTemp*` names (`governor_speed_limit_fuel_temp_*`, `cruise_fuel_temp_trim_threshold_cal`, `fuel_temp_governor_switch_cal`, ...) are vehicle-speed thresholds still to re-domain. Odometer lead: `vehicle_speed_sensor_pulse_total` deltas go out in PCI transmit message 11 (header 0x5D) with two fuel totals (built by `cm848_buildPciTransmitMessage11DistanceAndFuelUsed`).

**Trip / lifetime counters (2026-11-12, PR #46 — renamed):** `cm848_updateTripAndLifetimeCounters` (0x523148, was `j1939FuelDemandProcessing`) runs in 2 of the 40 main-loop phases (~100 ms if a phase is one 5 ms PIT tick — unconfirmed) when bit 13 of `engine_feature_enable_flags_cal` (0x3fd5ec, EEPROM 0x16a = 0x27EF here; was a second `governor_system_config_flags`) is set. SCI command 35 (`cm848_sciCommand35Callback` -> `trip_counters_reset_pending_flag`) clears the trip set. Lifetime / trip pairs (EEPROM offset): distance pulses `lifetime_distance_pulses` 0x8ea / the trip dword at 0x3fee28 = 0x19a6; engine-run passes `lifetime_engine_run_time` 0x19de / `trip_engine_run_time` 0x19f2; passes at governed speed (governor mode 11 within +/-400 rpm of its target — probably idle) `lifetime_time_at_governed_speed` 0x19da / `trip_time_at_governed_speed` 0x19ee; fuel `lifetime_fuel_used` 0x19d6 / `trip_fuel_used` 0x19e6; fuel at governed speed `lifetime_fuel_used_at_governed_speed` 0x8f4 / `trip_fuel_used_at_governed_speed` 0x19ea; `trip_average_fuel_economy` 0x8f2 (distance x 13603 x 8 / (trip_fuel_used x 8000) — reproduces the stored 94 / 90 = 9.4 / 9.0 mpg, so one fuel count is about 1/10882 gallon). Fuel source: `injected_fuel_running_total` (was `crank_period_running_total`) gets every injection's quantity added from the TPU-A channel 6 injection interrupt; the counters take its delta >> 12 at each PCI 0x5D send. **HP Tuners zeroes all of them** (older dump: 13,044,913 pulses = 1,631 mi, 3,196,806 engine-run passes; before-HPT dump: 1,448,503 = 181 mi; after HPT: 0). **PGN 65248 Vehicle Distance (on-request responder `cm848_j1939HandlePgn65248VehicleDistance`) reports `lifetime_distance_pulses` / 8000 x 12.874752 as total vehicle distance** — the decompiler shows its 64-bit divisor 8,000,000,000 truncated to 0xdcd65000 — so a J1939 ELD sees this wiped ECM counter, not the cluster odometer; the trip field source (0x3fdd70) is never written. PCI 0xDF byte 1 = `lifetime_distance_pulses` >> 22. No responder is registered for PGN 65253 (hours), 65244 (idle) or 65257 (fuel). **Still mis-typed:** RAM 0x3fee08-0x3fee2f is time-shared — during boot it is the boot ROM's own EEPROM-header shadow (`eeprom_shadow_header`, whose `config_dword` holds the runtime counter loaded from EEPROM 0x30), afterwards the app's mirror of EEPROM 0x1986-0x19ad — so the trip distance dword still renders as `ram0x003fee28`.

**PCI/J1850 RE resource (local PostgreSQL):** DB `mydb` = Chrysler DRBIII-style J1850 VPW diagnostic DB (`all_message_bytes` denormalized, `decoded_transactions` for byte-level decode, `research.pci_message_structures` for broadcasts); DB `automotive` = j1939 + obd2. Connect: `PGPASSWORD=postgres psql -h localhost -U postgres -d mydb`. Note `pg_stat` `n_live_tup` is stale — use real `COUNT(*)`.

---

## Workflow — ONE deterministic build, no partials

The Ghidra `.rep` is a **disposable build artifact**, rebuilt from scratch every time. The
CSVs in `output/` (+ the binary/dumps) are the ONLY source of truth. There is exactly one
way to produce output — `build` — and it always applies *every* CSV. Partial commands
(`import`/`export`/`analyze`/…) were removed: incrementally mutating a persistent `.rep` is
what caused drift (a silently-lost-43-functions baseline that couldn't reproduce itself).

```bash
cd [firmware]_analysis/ghidra

./analyze.sh build      # Edit CSVs in ../output/, then rebuild — always from scratch
./analyze.sh verify     # Prove the build is a reproducible fixed point (build x2, 0 diff)

# Output: ../output/[firmware].ghidra.cpp  (+ regenerated function_renames.csv, global_variables.csv)
```

`build` internally runs, in dependency order (firmware-specific):
- **CM848:** `init → memmap → enums → import → analyze → deletions → import → romramthunks → callingconv → hwregs → labels → constants → arrays → callfixups → export`
- **CM550:** `init → analyze → memmap → enums → import → deletions → import → hwregs → labels → constants → arrays → export`

(`import` = ApplyStructures + ImportAnalysis, which force-creates functions from
`function_renames.csv`; `export` re-applies funcdefs+localvars then ExportAnalysis. CM848 seeds
functions before `analyze` so cross-bank Bank-2 `bl` calls resolve.)

### Available Commands

```bash
./analyze.sh build      # The one build: fresh binary → apply every CSV → .cpp + CSVs
./analyze.sh verify     # Build twice, assert byte-identical (determinism contract)
./analyze.sh deletefuncs <addr>...  # Record spurious-function addr(s) to deleted_functions.csv (CSV-only)
./analyze.sh status     # Project status (read-only)
./analyze.sh decompile <addr|name>  # Decompile single function (read-only, against last build)
./analyze.sh listfuncs <outfile>    # Dump ALL function entry addrs incl FUN_ (read-only, repro diffs)
./analyze.sh classifyfuncs <addrs> <out>  # Classify addrs by incoming refs: call-target vs split (read-only)
```

To name/type/delete: edit the CSV, run `build`. To find spurious splits to record with
`deletefuncs`: `build`, then `classifyfuncs` on suspects (no incoming call ref = split).
ROM-to-RAM thunking (`func_0x003fxxxx` → ROM source) is the CM848 `romramthunks` build stage
(the map is `ROM = 0x3C30 + (RAM − 0x3F9800)`).

> **Editing CSVs?** Use the **`editing-firmware-csvs`** skill — it has the full per-type workflow
> (which CSV, column formats, the edit → `build` → verify-in-`.cpp` loop, and the type-specific
> gotchas for globals/enums/structs/funcdefs). It is the authoritative source; this file's notes
> below are supporting detail.
>
> **Naming an unknown symbol?** Use **`investigate-firmware-symbol`** (read-only research → name + type
> recommendation; includes the mandatory asm width-check). **CM848 width-check shortcut:**
> `python3 scripts/disasm_func.py <func_name|0xADDR> 0x<DATA_ADDR>` auto-resolves the window/binary and
> prints a byte/word/dword verdict (handles both displacement and `lis;addi;0(rN)` forms). Manual fallback:
> `powerpc-linux-gnu-objdump -D -b binary -m powerpc -EB --adjust-vma=<base>` for CM848 [big-endian!],
> `llvm-mc-18 --disassemble --triple=m68k` for CM550.
> For J1939 SPN/PGN meanings use **`j1939-lookup`** (local `mongodb://localhost:27017/j1939`, collection `pgns`, query by `number`).

---

## Common CSV Files

All firmwares use the same CSV structure in `output/`:

**Comment lines:** Lines starting with `#` are preserved through a `build`. Use them to document address mappings, function relationships, or other context.

| File | Purpose |
|------|---------|
| `function_renames.csv` | Function names by address |
| `global_variables.csv` | Typed global variables |
| `enums.csv` | Enum definitions for magic numbers |
| `labels.csv` | Code labels for control flow |
| `structure_definitions.csv` | C structure definitions |
| `constants.csv` | Magic number documentation |
| `arrays.csv` | Array/buffer definitions |
| `deleted_functions.csv` | Addresses of spurious functions to remove after `analyze` (the deletion delta) |
| `function_definitions.csv` | Function parameter types and return types |
| `local_variables.csv` | Local variable names/types |
| `call_fixups.csv` | Maps a runtime-helper address → a call-fixup (folds the opaque call into inline p-code, e.g. division → `/`). CM848 only; p-code bodies in `firmware/scripts/callfixups/*.xml` |

---

## Guidelines

- **CSV is source of truth** - Never edit Ghidra directly
- **The `.rep` is disposable; `build` is the only producer** — every `build` starts from a fresh binary (`init -overwrite`) and applies every CSV. There is no persistent state to drift, and no standalone `import`/`export`/`memmap`/`analyze` to half-mutate it. (Historically, re-running `memmap` on a populated `.rep` wiped Bank-2/RAM analysis — that footgun no longer exists.)
- **ALL CSVs are read-only INPUTS; `build` writes only the `.cpp`** — `build` is a pure function `(binary + CSVs) → .cpp`. `ExportAnalysis` emits ONLY the decompilation; it never writes `function_renames.csv` or `global_variables.csv` (that old behavior is what laundered Ghidra's `switchD`/`default`/`BYTE_`/`uRam` junk INTO the curated CSVs). To name/type a function or global, edit its CSV by hand — use the `.cpp` to spot the `FUN_`/`DAT_` symbol you want — then `build`. There is no "name it in Ghidra" step; the CSV is the only truth.
- **Verify before commit** - Check decompiled output after applying changes
- **Decimal in names** - Use decimal, not hex, in variable/function names
- **Major concept first in names** - prefix with the dominant domain noun first: `rpm_governor_offset_*` not `governor_offset_rpm_*`; `fuel_demand_*` not `demand_fuel_*`
- **NO invented abbreviations** - spell words out in ALL names (vars, functions, enum members AND enum prefixes). Banned: made-up initialisms like `CCS_SET`, `CSR_IDLE`, `GSR_*`. The ONLY allowed abbreviations are universal industry standards (~99% recognize instantly): RPM, J1939, CAN, ADC, PWM, VSS, EGT, PID, TPU, QADC, kPa. An enum must read `cruise_control_state == CRUISE_SET`, not `== CCS_SET`. Use a fully-spelled domain prefix on enum members (`DRIVETRAIN_STANDALONE`, `CRUISE_SWITCH_SET`). A short disambiguator suffix (`_2`, `_B`, `_PREV`) is fine — it is not an abbreviation.
- **Verify legacy/auto names against behavior** - generated names often borrow the wrong domain (the data's UNIT, the caller task-set's name, or a sibling channel), not what the code does; confirm against the body's actual writes/consumers + asm width before trusting (one session found 6 symbols misnamed this way)
- **No NAME ≠ no code; hardware/FSM is ground truth** - a missing symbol means UNDISCOVERED, not absent (the `.cpp` is only partially named). If the schematic/FSM/wiring says a pin/bus/feature exists, it IS there — go find it; never conclude "not present" from a failed grep. (Burned 3× in one session: trans-temp sensor C2-29, J1850, the entire SCI datalink stack.)
- **`_cal` = EEPROM-backed only, by the MEMORY MAP (not e2m)** - ROM / ROM→RAM copy (0x3F9800–0x3FDB30) / flash = fixed constant → no `_cal`; EEPROM-loaded → `_cal`; computed/working RAM → never. e2m uses Calterm *virtual* addresses, so a RAM-address grep is blind. **CM848: the EEPROM RAM mirror is `0x3fd482`-`0x3feec1` (RAM = 0x3fd482 + EEPROM offset; verified 2026-11-11)** — values there are EEPROM-backed → `_cal`; other `0x40xxxx`/`0x3fxxxx` cals are ROM/flash → no `_cal`. (grep `mpc555_eepromReadWords(` to settle a specific address.) **Bulk sweep:** `python3 scripts/audit_cal_suffixes.py <fw>/output/global_variables.csv` reports every `_cal` name whose region contradicts this rule (read-only). ~1352 CM848 HARD hits are **legacy campaign debt**, not new bugs — fix opportunistically. See the **`auditing-cal-suffixes`** skill.
- **Name locals via `local_variables.csv`** (`addr,fn,old_name,new_name,type,comment`); don't reuse a global's name for a local — it creates a confusing shadow (used `fuel_temp_trim_uncapped`, not the global `fuel_temp_trim_working`).
- **Function must exist in Ghidra** - CSV renames only work for addresses Ghidra recognizes as functions
- **import force-creates functions** — `function_renames.csv` entries at addresses with no function get disassembled + created (not just renamed). This reproduces Bank2 (force-analyzed) functions; their names ARE in `function_renames.csv` (~567 entries), not a side file.
- **funcdefs / r4-return gotcha** — declare the FULL prototype (return + all param rows); a return-only row is auto-handled (import preserves Ghidra-recovered params, warns on count mismatch) but yields generic `param_N` names. NEVER declare a return for an r4-return function whose r4 is NOT a parameter (no-arg/globals-only helpers like diag handlers) — the decompiler then assumes r4 is preserved and swaps the wrong operand at call sites. To undo a bad prototype, fix/remove the row in `function_definitions.csv` and rebuild.
- **Call-fixups: fold compiler-RTL division into operators (CM848, Ghidra 12.1+)** — the MPC555 has no 64-bit hardware divide, so the compiler emits calls to runtime helpers (`cm848_unsignedDivision32`/`signedDivision32` + workers) with the 64-bit dividend split into an `r3:r4` register pair. `call_fixups.csv` + `ApplyCallFixups.java` register a program-stored compiler-spec extension (`firmware/scripts/callfixups/<name>.xml`) and `setCallFixup` it onto each helper, so the decompiler renders a real `/` (or signed `/` via `s/`) instead of an opaque call. Applied as the `callfixups` build stage (after `import`, before `export`). Validated 2026-06-03: 124 caller functions, **zero collateral** (only callers change), zero dropped divisions, byte-identical `verify`.
  - **Two hard-won rules:** (1) The helper returns 64-bit in the `r3:r4` pair (proven by its `/0` epilogue `li r3,-1; addi r4,r3,0`); the fixup p-code must write **only `r4`** (the killed-by-call low word callers consume) — writing `r3` (the EABI return reg) makes leaf callers inherit a spurious `undefined4` return. (2) Only fold **pure** division helpers. `saturatingDivision16`, `clampedDivisionWithBounds`, `signedDivisionWithSaturation`, `extendedDivisionWithRemainder` carry extra semantics (saturation/clamp/remainder) — folding them to a bare operator would *hide* that = semantic drift, so they stay named calls.
- **`.cpp` has a wall-clock `Generated:` header timestamp** — every rebuild yields a 1-line diff on that line even when the decompilation is identical; `verify` normalizes it (the body is the deterministic part). Don't commit timestamp-only churn — `git checkout` the file.
- **"1 function import failed" build warning is benign/long-standing** — it is NOT caused by your edit. Verify YOUR specific CSV additions rendered in the `.cpp` (grep the new names) rather than chasing the warning.
- **Shared-script edits affect BOTH firmwares** — after changing `firmware/scripts/*.java`, rebuild CM848 *and* CM550; a CM848-only change should leave CM550's `.cpp` byte-identical except the timestamp (e.g. the bitfield/`clearAtOffset` change never touched CM550, which has zero bitfield rows).
- **Decompiler wraps long lines** — `grep 'name('` undercounts call sites (the `(` wraps to the next line). Count refs with name-only `grep -c 'name'` minus the definition / `// Function:` / injection-comment lines (a `name(` grep once showed 44 division calls; the true count was 115 across 77 functions).
- **`.cpp`-text ref counts OVER-count data globals** — one asm access can render as 2+ `.cpp` lines (CONCAT44 64-bit-multiply, register-reuse without reload, a conditional split across lines), inflating a 1-ref var into the "2-ref" tier. Trust `xref_addr.py`'s access count, not `.cpp` grep, when tiering symbols for a naming pass.
- **Reproducibility: PROVEN** — `build` is a deterministic fixed point. Two independent `build`s from a fresh binary produce byte-identical `.cpp` + CSVs (`verify` asserts this). Auto-analysis is deterministic; `import` force-creates functions from `function_renames.csv`; `deleted_functions.csv` removes spurious splits; the new baseline preserves all curated names and *surfaces* 90 real functions the old hand-curated baseline was missing (func_0x 75→29). The apparent "~2965 extra DAT_" gap from earlier was a measurement artifact — unnamed RAM vars render `DAT_` (initialized RAM) vs `uRam` (uninitialized); both are default names, no curation lost.
- **deleted_functions.csv** — vet candidates with `classifyfuncs` before adding: an entry with incoming CALL refs is a REAL function (do NOT delete — add to `function_renames.csv` instead); only no-ref / jump-only entries are true mid-function splits. **`classifyfuncs` is BLIND to untyped pointer tables** (2026-11-11, PR #46): 19 "no-ref" deletions were real functions reached only through tables — 15 `cm848_fuelDemand*` handlers in the 0x53a9a0 dispatch table and 4 TPU/MIOS interrupt handlers incl. the TPU-A channel 6 injection handler, which every build silently dropped. Before deleting, also search ROM + flash2 for a big-endian 32-bit pointer to the address. A deletion only takes effect if the address has NO `function_renames.csv` row (the second `import` recreates it).
- **Interrupt handler tables (typed as pointer[16] arrays):** `mios_interrupt_handler_table` @ 0x582da (MIOS1 flag bit), `tpu_b_channel_interrupt_handler_table` @ 0x583ae, `tpu_a_channel_interrupt_handler_table` @ 0x583ee (TPU channel 0-15). TPU-A ch6 = `engine_injectionAngle_tpuChannel6EventHandler` (per-cylinder injection scheduling), ch10 = `engine_injectionAngle_tpuChannel10CylinderEventHandler`. The bootstrap found 39 "spurious" Bank-2 candidates were actually real functions the campaign missed.
- **Type width must match hardware access** - `bool` (1B), `byte` (1B), `word` (2B), `dword` (4B) must match the actual load instruction (`lbz`=1B, `lhz`=2B, `lwz`=4B). Wrong width is silently reverted to `word` on export. This also prevents enum substitution for byte-width variables.
- **Plate comments round-trip via function_renames.csv** - 3rd column is preserved through a `build` cycle since the 2026-05-25 fix. If `build` drops a plate comment, it indicates `ExportAnalysis.java` failed to compile (check for missing imports).
- **CSV comment commas — which columns are safe** - `function_renames.csv` (`split ,×3`) and `global_variables.csv` (`split ,×4`) absorb commas into the LAST column, so review prose with commas is fine there. `structure_definitions.csv` / `call_fixups.csv` use the quote-aware `parseCSVLine` — keep those comments comma-free or quoted.
- **A checked bit ≠ a live trigger** - when a gate ORs in flag bits, grep for a SETTER (`| 0xNN`, masked/whole-word assignment, BOTH banks) before treating the condition as reachable. Checked-but-never-set bits are shared-firmware / excluded-feature artifacts (e.g. the protection gate's `safety_bits_1 0x10/0x20`, dormant in this calibration).
- **Enum types just need to be in `enums.csv`** — `build` runs the `enums` stage before `import`, so a new enum type is always registered in Ghidra's DTM before globals reference it. (Ordering is automatic; there is no separate `enums`/`import` step to sequence by hand.)
- **Named types preserved through the export stage (since 2026-05-26)** — `ExportAnalysis.java` reads existing CSV before overwriting and applies priority: named Ghidra type > named CSV type > primitive Ghidra type. Enum types set via CSV survive `build` cycles.
- **Masked flag access → declare a bitfield (Ghidra 12.1+)** — for a flag tested as `(var & MASK)`, declaring the field as a structure bitfield now renders it symbolically. Verified end-to-end on `protection_enable_t.protection_active` (the bit7 `0x80` boolean) 2026-06-03: reads `... .protection_active & 0x80` became `... .protection_active != 0`, and the set/clear writes `| 0x80` / `& 0x7f` became `protection_active = 1` / `= 0`. **Requires Ghidra ≥ 12.1** ([issue #647](https://github.com/NationalSecurityAgency/ghidra/issues/647) / GP-2493 — *"the Decompiler now recovers and displays the names of bitfield components… when analyzing code that manipulates them"*). On the old from-source **12.0** build the opposite happens — the mask survives **and** the field name is lost (renders raw `struct._N_1_ & MASK`, the closed-as-known [#2462](https://github.com/NationalSecurityAgency/ghidra/issues/2462) on PPC), so this is strictly gated on the toolchain. CM848 is pinned to 12.1 (which has this fix); see the **Ghidra version pinning** section above for how each firmware's version is enforced.
  - **CSV syntax** (`structure_definitions.csv`): set the `type` column to `bitfield:<bitSize>@<bitOffset>` (bitOffset is from the LSB; bit7 = the `0x80` bit of a byte) and the `size` column to the storage byte-width. For several flags packed in one byte/word, give the first member the byte-width and each additional member `size=0` (continuation — shares the opener's storage unit). `ApplyStructures.java` places these via `insertBitFieldAt`.
  - **Enum caveat still stands:** symbolic *enum* names appear for `var == ENUM_VALUE` but NOT for `(var & MASK) == VALUE`. Use a bitfield for packed flags; an enum type only for whole-value compares.

### CM848 `_DAT_` Naming Campaign — Status

All 3+, 2+, and 1-occurrence unnamed `_DAT_003Fxxxx` variables have been named (batches 1-5,
~1,049 entries added 2026-05-25). 67 WARNINGs remain — all permanently stuck:

| Variable | Why Stuck |
|----------|-----------|
| `_governor_mode_state` (12×), `_fuel_temp_trim_scale_cal` (8×), `_engine_sync_prot_gain_b_cal` | `stw` pair-clear: single `stw` writes 4B across two gap=2 `word` vars — cannot widen either individually |
| `_sensor_validation_delta`, `_fault_counter_slot3_target`, `_fault_counter_slot3_shadow` | gap=1 to next named var — widening would overlap neighbor |
| `_qadc_channel_control_working` | gap=2, machine access is `lwz` (4B) — needs gap≥4 to widen |
| `_param_id_lookup_table` | ROM-to-RAM code region (0x003F9800–0x003FDB30) — Ghidra reverts type on export |
| `_pad2`, `_pad5`, `_pad16` | Structure padding fields — Ghidra internal, not fixable via CSV |

**Remaining unnamed:** ~5 Bank-2 ROM constants (`_DAT_0005xxxx`, `_DAT_00008104`, `_DAT_00022c86`) with no RAM neighbor context — low value to name.

### Batch `_DAT_` Naming Workflow

To name unnamed `_DAT_` globals in future (e.g., if a new firmware export reveals new ones):

1. **Extract context** to JSON chunks (addr, prev/next named neighbors + byte gap, ≤3 usage snippets with 1 line before/after)
2. **Dispatch parallel Haiku agents** (~70 entries/chunk, 8 chunks in parallel)
3. **Validate** before applying — check addr conflicts, name conflicts with existing CSV, intra-batch duplicates, dword proposals with gap<4
4. **Apply** → `./analyze.sh build`
5. **Check `_` prefix remaining**: `grep -oE '\b_[a-z][a-z0-9_]{3,}\b' cm848_rom.ghidra.cpp | sort | uniq -c | sort -rn`
6. **Widen types** for new `_` prefix: check gap to next named var in CSV; gap≥2 → widen to `word`, gap≥4 → widen to `dword`

**Yield is range-dependent — measure one wave before committing a whole tier.** Working-RAM `0x0040xxxx` is mostly flat scalars (2-ref ≈ 63% nameable). ROM-shadow `0x003fxxxx` low-ref is dominated by `table_interp_args_t` interp-states (pointer-passed), J1939 struct buffers, and sensor-channel config bases (2-ref ≈ 14%) → route to `structure_definitions.csv`/`arrays.csv`, not flat globals. INSUFFICIENT clusters as: pointer-passed (address-taken, never directly loaded) · write-only (no real reader) · array element / struct member · single-real-access.

**WARNING semantics:** Each WARNING is function-level — a function gets one WARNING if ANY global in it has `_` prefix. Fixing one variable in a function does NOT clear the WARNING if other `_` vars remain.

**Name conflict resolution (003f vs 0040):** When a new 003f address conflicts with an existing 0040 RAM name, the 003f var is typically the ROM calibration source — append `_cal` (if ROM const), `_b_` (if parallel working copy), or `_prev_` (if snapshot).

### Fixing Underscore-Prefixed Variables

Variables with `_` prefix (e.g., `_speed_error_filtered`) indicate a wider memory access than the declared type:
- **Cause (simple)**: Variable declared as `byte`/`word` but Ghidra sees a wider load (`lhz`/`lwz`). Fix by widening the type to match the actual access width.
- **Cause (persistent — PowerPC pair-clear)**: `sth r0, offset(r13)` stores 2 bytes in one instruction, zeroing 2 adjacent byte-typed variables at once. `stw` does the same for 4 bytes. Ghidra emits `_` prefix for each because the write exceeds every individual byte's declared size. Widening individual types does not fix this.
- **Fix for pair-clear pattern**: Declare a single `word` variable (or struct) spanning both bytes in `global_variables.csv`. Once Ghidra sees one N-byte type instead of N separate bytes, the underscore disappears.

#### WARNING: Do not use byte-pair structs for sth-paired variables

When `sth` stores a flag value like `0x0001`, naming the two bytes as separate fields will produce **backwards names** due to PowerPC big-endian byte ordering:
- `sth` with `r = 0x0001` → byte 0 (lower address, MSB) = `0x00`, byte 1 (higher address, LSB) = `0x01`
- A struct with `byte flag` at offset 0 and `byte pad` at offset 1 will show `flag = 0` always and `pad = 1` when active — exactly wrong

**Correct fix**: declare the address as a single `word` variable. `sth` storing `0x0001` will decompile cleanly as `var = 1`, and all comparisons read naturally. Do not use two-field byte structs for sth-paired locations.

**Struct candidate signal**: a cluster of consecutive same-width variables all initialized to the same value in one function, AND passed as pointers to the same function at separate call sites, almost always means multiple instances of the same struct type — not a flat array.

### Multiple Instances of the Same Struct Type

`ApplyStructures.java` builds ONE type from ALL rows sharing a struct name. Listing fields for the same struct name at two addresses creates one oversize type with duplicate fields applied only at the first address — the second address falls inside the first's range and is silently swallowed.

**Correct pattern**: define fields once (first instance's address), then add a zero-size instance-marker row for each additional address:
```
my_struct_t,0x003fa878,row_count,word,2,First field,,verified
my_struct_t,0x003fa878,col_count,word,2,Second field,,verified
my_struct_t,0x003fa87c,,,,second instance - marker only,,verified
```
The marker row's empty `field_name`/`type`/`size` registers the address for application without adding duplicate fields to the type.

### global_variables.csv Maintenance

Periodically clean garbage entries from `global_variables.csv`:
- **Switch tables** (`switchD`, `caseD_*`, `default`) - Ghidra jump table artifacts, not real variables
- **SUB_ entries** - Invalid addresses outside ROM/Flash ranges (e.g., 0x8a670005)
- **mpc555_registers.csv duplicates** - Untyped entries already defined in hardware register CSV

Use Python CSV module to batch-categorize and clean (see session history for script pattern).

---

## Common Code Patterns

### Rolling 2-bit Edge Detector
- `(flags & 0x55555) * 2` shifts current-state even bits to previous-state odd positions, creating a "previous state" snapshot in one instruction
- Downstream `(flags & 0xc0) == 0x80` checks are falling-edge detectors (was 1, now 0)
- `protection_control_state_flags` (0x003fafd4) uses this for 10 channels; look for `& 0x55555` in other status registers

### Sensor Channel Architecture
- Sensor channels use paired functions: `sensorChannelN_init()` calls a config init function, `sensorChannelN_process()` calls the update function
- Both functions take identical 13 parameters (calibration pointers, RAM buffers, ADC indices, output variables)
- CM848: `sensorChannelConfigInit` (0x00500234) + `updateSensorChannelWithConfig` (0x00500a4c)
- Two sensor types: Type A uses `sensorChannelConfigInit`, Type B uses `sensorChannelInit_typeB`
- Look for similar patterns in CM550 firmware

### QADC Analog Sensor Read (two-table dispatch)
- Raw analog read = two-table indirection: `idx = qadc_channel_index_table[k]` (0x3fda78, ROM-copied channel-index array, each elem clamped `< 0x81`) → `qadc_channel_dispatch_table[idx]` (0x57dd2, 129×8-byte ptr entries → MPC555 QADC result regs QADC-A 0x304A80.. / QADC-B 0x304E80..) → deref = live 10-bit value. Asm: `lhz <off>(0x3fda78); cmpwi 0x80; slwi r,3; lwzx 0x57dd2; lhz 0(ptr)` (~58 sites)
- The index picks WHICH sensor and is runtime-populated in the ROM→RAM window (not in the static dump) → the physical sensor per slot is a live-bench-read target, not statically resolvable
- `lower < value < upper` on this read is a sensor-VALIDITY gate (e.g. 92..976 = 9–95% of 10-bit FS), NOT a speed/RPM window — don't conflate

### CM848 Bank 2 Status

Bank 2 (0x005xxxxx) naming is **complete** as of 2026-05-24 — all 562 functions named across 4 rounds.
Scripts used: `BatchForceAnalyze.java`, `BatchForceAnalyzeNamed.java`, `ExportBank2Functions.java`.

**Key Bank 2 patterns documented:**
- Command dispatch table at 0x00539508 (19 entries, 6 bytes each: command + function pointer)
- State machine: `initiateStateTransition` → `dispatchByCommandCode` → command handlers
- Utility functions: `addWithMask16` (pointer math), `enqueueDataRecord` (dual-queue)

### Boost/MAP Sensor Data Flow (CM848)
- MAP sensor → `boost_pressure_sensor_raw` (0x40bd8e) → `selectLoadNormalizer()` → `boost_denominator_min128` → fuel calculations
- No single "max boost" parameter - boost limited indirectly via AFC tables (AFFLLMZA) and BIR diagnostics
- Pressure scale factor: 0.0159064138077 IN_HG per raw count (16-bit range = ~35 bar max)
- See `CM848_S90140.06_analysis/output/10bar_map_conversion.md` for complete parameter documentation

### CM848 sensor channel identities (proved by the ECM's own broadcasts, 2026-11-12)
`sensor_channel_filtered_output[]` (0x40baf0, words) slots are identified by the J1939 SPN or PCI byte each one is
broadcast as — the SPN fixes both the signal and the unit. Pressures are all **1/18.56 kPa per count** (= the
0.0159 inHg above); temperatures are **1/64 °F per count** (`(raw >> 6)` = °F). Older names were wrong for most slots.

| Slot | Address | Name now | Was | Proof |
|---|---|---|---|---|
| 1 | 0x40baf2 | `sensor_readings_t.intake_manifold_pressure` | `.oil_pressure` | IC1 SPN 102, OBD-II MAP, PCI 0x10 byte 5 (kPa); boost = this − slot 3 |
| 2 | 0x40baf4 | `sensor_readings_t.coolant_temp` | (right) | ET1 SPN 110 |
| 3 | 0x40baf6 | `sensor_readings_t.barometric_pressure` | `.intake_air_temp` | AMB SPN 108 (0.5 kPa/bit math matches) |
| 4 | 0x40baf8 | `sensor_readings_t.battery_voltage` | (right) | PCI 0xC0 byte 1, 1/16 V |
| 6 | 0x40bafc | `fuel_delivery_pressure_sensor_filtered` | `engine_load_demand_raw` | EFL/P1 SPN 94 |
| 7 | 0x40bafe | `fuel_temperature_sensor_filtered` | `fuel_temp_raw` | ET1 SPN 174 |
| 9 | 0x40bb02 | `intake_manifold_temperature_sensor_filtered` | `engine_load_output_value` | IC1 SPN 105 |
| 10 | 0x40bb04 | `oil_pressure_sensor_filtered` | `fuel_quantity_demand_input` | EFL/P1 SPN 100, PCI 0xC0 byte 2 |
| 11 | 0x40bb06 | `oil_temperature_sensor_filtered` | `intercooler_temp_raw` | ET1 SPN 175 |
| 13 | 0x40bb0a | `accelerator_pedal_sensor_filtered` | — | (PR #46 earlier) |
| 19 | 0x40bb16 | `coolant_pressure_sensor_filtered` | `fuel_quantity_mode_raw` | EFL/P1 SPN 109 |

- The "oil pressure" functions/globals that read slot 1 are **boost**: `cm848_calculateBoostPressure` (was `cm848_oilPressureDeltaCalculation`). Other `*oil_pressure*` names in the 0x407xxx/0x408xxx protection tables are still unverified — check which slot they read before trusting them.
- Real oil pressure: `cm848_processEngineOilPressure` (0x51a0a8) → `engine_oil_pressure` (0x40b538, gauge). On this truck `oil_pressure_switch_only_cal` (EEPROM 0x466) = 1, so the dash oil-pressure value is an **RPM-indexed model**, and only the low-oil-pressure switch (switch 14, line 150) can drop it to 0.
- `cm848_selectSensorValuesInUse` substitutes a low/high value per fault direction into `intake_manifold_pressure_in_use` / `coolant_temperature_in_use` / `intake_manifold_temperature_in_use` (what protection, PCI 0x10/0xC0, OBD-II and the freeze frame use).

### Live Data Reading (CM848 Service 0x4A)

Verified memory addresses for live ECU queries:

| Address | Variable | Scale | Verified |
|---------|----------|-------|----------|
| 0x0040B7BA | `current_engine_rpm` | × 0.125 RPM | ✓ 2026-01-31 |
| 0x0040BD8E | `boost_pressure_sensor_raw` | × 0.0159 IN_HG | ✓ 2026-01-31 |
| 0x00408EF6 | `cbd_enable_flag` | 1=enabled | ✓ (prior session) |

See `CM848_S90140.06_analysis/docs/service_0x4a_protocol.md` for complete protocol documentation.

**Tools:** `tools/poll_rpm.sh` polls RPM via kuminz-cli every 0.5s.

**Polling Limits:** Minimum 50ms between Service 0x4A requests - faster polling may cause ECU to throttle responses.
