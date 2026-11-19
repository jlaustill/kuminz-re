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
| CM550 | MC68336 / CPU32 | **12.2** PUBLIC, language `68000:BE:32:CPU32` | `$HOME/code/ghidra-12.2/ghidra_12.2_PUBLIC` | 12.2 is the first release with the CPU32 language (issue [#1244](https://github.com/NationalSecurityAgency/ghidra/issues/1244), `CPU32.slaspec`). The MC68336's core is a CPU32 |

- Override the install path with `GHIDRA_DIR=...`, but its `application.version` must still match
  the firmware's pin or the build fails gracefully (telling you which version is needed and where).
- **Ghidra 12.2 needs JDK 25** (`application.java.min=25`); 12.1 runs on the system JDK 21. On this machine a user-local
  Eclipse Temurin JDK 25 lives at `$HOME/code/jdk-25/jdk-25.0.5+8`. The 12.2 install points at it with
  `JAVA_HOME_OVERRIDE` in its own `support/launch.properties`, so neither the repo nor the system Java changes.
- **CM550 history:** until 2026-11-15 CM550 was built on a from-source "12.0 DEV" build (`$HOME/code/ghidra`).
  That build had no CPU32 language, so CM550 was really decoded as the default 68000 language (68040), and
  the build was not a precise pin: two checkouts both report `12.0` yet decompile differently. The
  re-baseline on 12.2 + CPU32 (PR #48) made CM550 a pinned PUBLIC build like CM848.
  - **The language makes no difference to the output (measured 2026-11-15):** a 12.2 build with the 68040 language
    (`68000:BE:32:default`) is byte-identical to the CPU32 build. The re-baseline's ~4300 changed lines are all
    Ghidra-version churn (12.0 DEV → 12.2). CPU32 is set because it is the MC68336's real core; TBL / LPSTOP /
    BGND would only decode with it.

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

**Script test suite:** `cd firmware/script_tests && ./run_tests.sh` — 89 JUnit 5 tests covering ScriptUtils and CsvCommentIndex. Tests live in `firmware/script_tests/` (NOT inside `firmware/scripts/`) because Ghidra's `GhidraSourceBundle` recurses into subdirectories when compiling the bundle. Any `.java` file with imports not on Ghidra's classpath (e.g. JUnit) inside `firmware/scripts/` will break ALL script compilation with "class not found" errors.

---

## CM550 (J90350.00) Analysis Notes

**Source:** Live ECU extraction from bench — complete ROM, RAM, and EEPROM dumps.

- **MCU:** Motorola MC68336 (CPU32 core: a 68020 subset without bit-field, CAS / CAS2, CALLM / RTM, PACK / UNPK, coprocessor instructions or memory-indirect addressing, plus TBL / LPSTOP / BGND; Ghidra language `68000:BE:32:CPU32`)
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
- **Supervisor chip (external, QSPI) — question/answer watchdog:** `cm848_initSupervisorWatchdog` (0x7b08, first call after the kernel copy) + `cm848_serviceSupervisorWatchdog` (0x7974, answers from four 16-entry tables at ROM 0x3c9c-0x3ccc) + `cm848_forceSupervisorWatchdogReset` (0x7dc4, wrong answers on purpose before every software reset). The same chip (QSPI PCS1, command byte 0x5D) is the application's **supervisor chip**: `cm848_initSupervisorChip` (0x37334, was initPeriodicTimerSystem) sets up 7 `qspi_job_t` jobs (watchdog / configuration write 0x94-0xA4 / output write 0x92 / register reads 0x24 0x2E 0xA2 / status read 0x4E 0x5A 0x5C) scheduled by `cm848_runSupervisorChipSchedule`; the application watchdog is `cm848_startSupervisorWatchdog` / `cm848_runSupervisorWatchdogCycle` / `cm848_answerSupervisorWatchdog` (answer tables at ROM 0x576e4 identical to the kernel's). The whole 0x367a4-0x37580 family was J1939-named; its reply globals are now named by register (2026-11-13): `supervisor_register_36_bit_1_low_flag` / `_low_held_flag` (register 0x24 bit 1), `supervisor_register_162_status` (0xA2), `supervisor_register_146_output_value` (0x92 output write) and `supervisor_input_lines_130_to_135_state` / `_136_to_143_state` / `_144_to_151_state` — what each register bit means electrically is still open (bench: log them while cranking / at key-off). A **serial output driver** on QSPI PCS2 (SPI mode 3, 8-bit; `serial_output_driver_job`) carries output lines 152-159: `mpc555_driveOutputLineHigh/Low` for lines 152-159 and `cm848_refreshOutputPortsAndReadback` (0x529b8, was the misnamed injectorTimingCalculation) queue it; its reply is `serial_output_driver_status_byte`. QSPI chip-select map: PCS0 = SPI EEPROM, PCS1 = supervisor chip, PCS2 = serial output driver, PCS3 = J1850 PCI controller.
- **Runtime counter = `ecu_power_state_flags.runtime_counter` (RAM 0x302012):** loaded from EEPROM 0x1000030 at boot (`mpc555_loadRuntimeCounterFromEepromShadow`), +1 every 41 PIT ticks in `mpc555_tickTransferTimeoutAndRuntimeCounter` (~0.205 s/count if the PIT runs at 1 MHz), saved back at key-off by `mpc555_keyOnStateMachine`; also the auth-token freshness clock. This is the boot ROM's copy.
  - **The application keeps two hour meters (2026-11-15, PR #48):** `cm848_advanceHourMeters` runs once per 40-phase main-loop cycle, i.e. 40 PIT ticks of 5 ms = **0.200 s per count**.
    - `key_on_hour_meter` (RAM 0x40a64c, EEPROM 0x30): +1 every cycle.
    - `engine_hour_meter` (RAM 0x40a794, EEPROM 0x42): +1 unless `cold_start_phase` is 1, which makes it **engine-running hours**. During the HP Tuners flash sessions (key on, engine off) it did not move while the key-on meter did.
    - Neither is wiped by HP Tuners. EEPROM 0x42 / 18000 = engine hours (9,819.5 h in the last dump). `tools/read_engine_hours.sh` reads both; see `docs/engine_hours_and_odometer.md`.
- **Reset path (2026-11-13, PR #48):** `mpc555_reset_vector` (and its copies `mpc555_initSystemRegisters` / `cm848_initClockAndTimers`) writes MDASM mode 3 to `mios_mdasm30.SCRD`, then `cm848_waitForStableIgnitionKeyOn` (0x24a0) waits for 5 consecutive key-on samples of its bit 15 (the ignition key line). `mpc555_hardwareInitialization` then calls `mpc555_areBootModeStrapPinsHigh` (0x23b8; QADC-B PQB0 / PQA4 and QADC-A PQA2 / PQA3): all four high (or EEPROM magic != 0x600d) → the boot service loop `mpc555_systemInitialization` (never returns) instead of the application, and the kernel's watchdog init leaves the supervisor watchdog unarmed (0x1400). Boot delays use `cm848_busyWaitDelay` (passes of 2222 spins, at least 0.22 ms each at 40 MHz). `qadc_b_mcr` (0x304800) is now `QADC64A_MCR`.
- **MIOS1 register map (2026-11-13, PR #48):** submodule n sits at 0x306000 + 8n, proved by the firmware's own drivers — MPWMSM0-3 (0x306000-0x30601f) and MPWMSM16-19 (0x306080-0x30609f, were mislabeled MDASM0-3) share the PWM helpers `mpc555_miosEnablePwmSubmodule` / `mpc555_miosSetPwmSubmoduleDuty` / `mpc555_miosSetPwmSubmodulePeriodMicroseconds`; MDASM11-15 and MDASM27-31 (0x3060d8-0x3060ff) share the `cm848_miosChannel{N}*` wrappers over the generic MDASM driver; MMCSM6 = `mios_mmcsm_cnt` (0x306030, the boot time base) and MMCSM22 = `mios_mmcsm22` (0x3060b0, its ML is the shared PWM period); the MIOS1 interrupt registers are at 0x306c00 (`mios1_isr`, read by the MIOS interrupt dispatcher). By the same layout MPIOSM (submodule 32, the 16-bit parallel port) is `mios_mpiosm32` (0x306100: `.data` / `.data_direction`; was `mios1_ext_ctrl.ctrl_a` / `.ctrl_b`), and the reset code's 0x8000 (prescaler enable) write to 0x306816 fits MCPSMSCR there. **One type per submodule kind (2026-11-15, todo 035):** every MDASM is a `mios_mdasm_t` instance (`AR_BR` dword - nothing reads AR or BR apart, the drivers move the pair with one 32-bit access - / `XR` / `SCRD`) and every PWM submodule a `mios_mpwmsm_t` (`PERR` / `PULR` / `CNTR` / `SCR`), named `mios_mdasmN` / `mios_mpwmsmN` (the per-channel copies `mios_mpwmsm1_t` ... / `mios_mdasm12_t` ... and the `MIOS_MDASM11_AR`-style instance names are gone); the eight `mpc555_mios*` drivers take `mios_mdasm_t *` / `mios_mpwmsm_t *`, so they read `channel_registers->SCRD` / `pwm_registers->PULR` instead of raw `+ 6` / `[1]`. The register label rows inside each instance (`MIOS_MDASM11_BR` ...) must stay: without a label, the register-CSV stage (`ApplyMPC555Registers`) creates u16 data there and splits the struct. Renamed: `MIOS_MCPSMSCR` → `mios_mdasm30`, `MIOS_MIOS1RPR` → `mios_mdasm31`, `MIOS_MIOS1TPCR` / `MIOS_MPWMSM4_*` → `mios_mdasm28`, `MIOS_MPWMSM5_*` → `mios_mdasm29`, `MIOS_MDASM0-3_AR` → `MIOS_MPWMSM16-19_PERR`, `MIOS_MDASM6_BR` → `mios_mmcsm22.ML`. Discrete input lines 124-128 = the pin bits (SCRD bit 15) of MDASM15 / 27 / 28 / 29 / 30. 
- **MIOS output drivers (2026-11-13, PR #48, todo 033):** a flash2 **output channel driver table** (16-byte records: enable / read feedback — a shared stub at 0x53a108 that returns 0 unless the channel has a read-back / set period / set duty; MIOS records start at 0x53ae56) is the only path to most wrappers — the decompile shows no direct caller for them (only the PWM 16-19 wrappers are also called directly, from `cm848_tpuMiosOutput_loadCalibration` / `cm848_tpu_interrupt_flag_init`). MDASM11-15 / 27-31 go through `cm848_miosChannel{N}EnablePwm` / `SetPwmPeriod` / `SetPwmDuty` → `mpc555_miosEnableChannelPwm` (SCRD mode 9) / `mpc555_miosSetChannelPwmPeriod` (ignores the channel: one MMCSM22 period for every MDASM output) / `mpc555_miosSetChannelPwmDuty` (AR:BR edges; duty 1/256 % per count, 25600 = 100 %). PWM submodules 0-3 / 16-19 go through `cm848_miosPwm{N}Enable` / `SetPeriodMicroseconds` / `SetDuty` → `mpc555_miosEnablePwmSubmodule` / `mpc555_miosSetPwmSubmodulePeriodMicroseconds` (both prescaler branches are microseconds on a 2.5 MHz MIOS clock; PWM 16-19 run at 50 us = 20 kHz in the RAM dump) / `mpc555_miosSetPwmSubmoduleDuty`. MDASM11 / 12 / 13 / 14 look like read-back inputs for TPU outputs 4 / 7 / 6 / 10 (each is put in input mode by the read-back enable `cm848_tpuBReadBackChannel4 / 7 / 6 / 10EnablePwm` before it starts that TPU-B channel): `mpc555_miosSetChannelInputMode` (SCRD mode 1) + `mpc555_miosCheckChannelFeedback` (0 agree / 1 reads high or toggling / 2 reads low or toggling). 
- **Output channel driver table (2026-11-13, PR #48, todo 034):** flash2 0x53ac46-0x53af75, **51 records** — record 0 = no output (`blr` / return-0 stubs), TPU-B channels 0-15 = 1-16 (`cm848_tpuBChannel{N}EnablePwm` / `SetPwmPeriodMicroseconds` / `SetPwmDuty`; channels 4 / 6 / 7 / 10 / 11 use the `cm848_tpuBReadBackChannel{N}*` records, whose read-feedback slot checks an MDASM pin), TPU-A channels 0-15 = 17-32 (`cm848_tpuAChannel{N}*`), the generic drivers being `mpc555_tpu{A,B}EnablePwmChannel` / `SetPwmPeriodMicroseconds` / `SetPwmDuty` (todo 035: identical code per module; TPU-A ticks at 0.4 us and TPU-B at 3.2 us - TPUMCR 0x4460 / 0x4430 differ in bits 0x40 and 0x10, and reading 0x40 as PSCK (system clock / 4 instead of / 32, per the MPC555 manual) gives that factor of 8), MDASM11-15 / 27-31 = 33-42, PWM submodules 0-3 / 16-19 = 43-50. The slot labels at the base are `output_channel_driver_table_enable` / `_read_feedback` / `_set_period` / `_set_duty` (were `j1939_pgn_handler_table*`), so consumers render `(&output_channel_driver_table_set_duty + channel * 0x10)`. 19 consumer functions pick the record with an EEPROM output channel word (EEPROM 0x814-0x868, were `j1939_pgn_handler_index*`) after checking 0 < channel < 51; most set-period arguments are 1000000 / frequency = microseconds (the e / g paths pass a calibration word directly). This calibration: `governor_pressure_solenoid_output_channel_cal` = 5 (TPU-B 4 with MDASM11 read-back), `alternator_field_output_channel_cal` = 11 (TPU-B 10 / MDASM14; the ECM's C1-7 K20 Generator Field Control pin, driven by the PI loop on `charging_voltage_error` (was `battery_voltage_delta`; the target is `charging_voltage_target` from `cm848_calculateChargingVoltageTarget`) in `cm848_calculateAlternatorFieldDutyByPid`), `fuel_metering_output_channel_cal` = 12 (TPU-B 11 / MDASM29), `wastegate_solenoid_output_channel_cal` = 8 (TPU-B 7 / MDASM12) and `cooling_fan_output_channel_cal` = 7 (TPU-B 6 / MDASM13) - these three were actuators a / b / h, identified 2026-11-14 by their read-back DTCs (next bullet) - `actuator_output_channel_d_cal` = 16 (identity open), `_c/_e/_g` = 0 (unassigned). `cm848_updateOutputReadBackFaultBits` polls the read-feedback slots. Record 0's stubs are `cm848_outputChannelNone{Enable,SetPeriod,SetDuty}` and `cm848_outputChannelReadFeedbackNone` (the return-0 read-feedback stub of all 46 records without a read-back); record 12's read-feedback function `cm848_tpuBReadBackChannel11ReadFeedback` (0x4dfd4) had never been made a function. Still open (todo 035): the per-channel last-command caches (`j1939_calib_handler_*`) and actuators c / d / e / g. (`hpcr_injectorPulseWidthCalc` at 0x533e0 was the discrete input snapshot: `cm848_refreshInputLineImage`, see the discrete line images below.)
- **Output read-back faults (2026-11-14, PR #48, todo 035):** the nine EEPROM output channel words are entries of one 48-word **output channel assignment table** (0x3fdc94-0x3fdcf3 = EEPROM 0x812-0x871; entry N = the driver-table record for output function N - 1 cooling fan / 10 governor pressure solenoid / 11 wastegate solenoid / 20 fuel metering / 25-26 actuators c-d / 27 alternator field / 39 g / 43 e). `cm848_updateOutputReadBackFaultBits` (0x53a110, was `hpcr_protectionTimerMonitor`) calls each assigned record's read-feedback slot and keeps bit N of `output_read_back_fault_bits` (0x40c258, 3 words). That is the first bitfield struct in the CM848 CSVs: consumers render `output_read_back_fault_bits.wastegate_solenoid == 0`, while the monitor's indexed write renders `*(ushort *)(&output_read_back_fault_bits.field_0x0 + (fault_word_index + ...) * 2)`. `cm848_debounceOutputReadBackFaults` (0x50e0a0, was `main_loop_resetGovernorDiagnosticFlags`) turns entries 27 / 1 / 20 / 10 / 11 into P0622 / P0480 / P0251 / P0748 / P0243 (faults 396 / 121 / 333 / 351 / 403 via the 0x5985a slot table) and sets the output's retest flag. The output's own control function then drives 0 % for `*_retest_off_passes` and 100 % for 2 x `*_retest_fault_confirm_passes`, and clears the flag. The governor pressure solenoid has no retest (its latch is never cleared). So the consumers are the real output stages: `cm848_applyCoolingFanDuty` (was `fuel_coldStart_demandFinal_apply`), `cm848_applyWastegateSolenoidDuty` (was `cm848_processFuelRateConfig`) and `cm848_applyAlternatorFieldDuty` (was `cm848_applyProtectionOutputDemand`), with their clamp / invert / frequency / hold settings renamed; `cm848_calculateFuelMeteringCommand` (was `cm848_calculateEngineTimingOffset`) computes the fuel metering command (`engine_sync_state_t_0040b87f.fuel_metering_command`, 0x40b882, 0-4095; it was `speed_raw`, and docs/service_0x4a_protocol.md listed it as engine RPM). `cm848_setFuelMeteringPwm` (was `mpc555_calculateTpuTimingPeriod`) writes it straight into TPU-B 11's on-time / period, so fuel metering bypasses the driver table's set-duty slot. The read-back check skips commands below `fuel_metering_read_back_minimum_command` (245) and returns `fuel_metering_read_back_last_verdict`. The command controller is the fuel (rail) pressure governor. Flash2 SCI table 253 (0x53a5ec: one byte address per DRB FD index, FD n -> entry n - 1) names the words, using the DRB labels from mydb `v_transaction`: FD-21-22 FUEL PRESS REG OUTPUT = 0x40b882, FD-23-24 FUEL PRESSURE SENSOR = `fuel_pressure_sensor` (0x40b8b0, was `cam_sync_position`), FD-27-28 FUEL PRESS SETPOINT = `fuel_pressure_setpoint` (0x40b8b6, was `cam_timing_measured`), FD-29-2A FUEL PRESSURE VOLTS = `fuel_pressure_sensor_volts` (0x40b8ae), FD-80-81 RAD FAN SPEED = `radiator_fan_speed` (0x40b2f4, x 0.125 rpm). The `cam_sync_*` / `engine_position*` / `camTiming` names around them are fuel pressure names still to re-domain. The full table walk (34 labelled FD reads) also gave the cylinder contribution test: `cm848_runCylinderContributionTest` (was `hpcr_processTimingCalibration`), whose `cylinder_N_contribution_percent` bytes are in firing-order slots 1-5-3-6-2-4. It also gave the EEPROM load histogram `percent_time_at_load_cal`[10] (0x3fdf98). DRB labels can disagree with the users (FD-99 ECM LRN STAT points at an SCI scratch byte), so check the users before renaming. The upstream controllers keep their old names: the `fuel_coldStart_*` family is the fan controller. Its source code 8 runs the fan speed PID `cm848_runCoolingFanSpeedPid` (was `governor_fuel_demand_calc`) on `cooling_fan_speed_target` (was `governor_speed_reference`) - `radiator_fan_speed`. The fan speed is measured from the sensor on TPU-B channel 9: `cm848_measureRadiatorFanSpeed` / `cm848_radiatorFanSpeedInterruptHandler` / `cm848_configureRadiatorFanSpeedInput` (were `tpu_rpm_*` / `mpc555_tpuBChannel9InterruptHandler`). P0483 (fault 407) is `cm848_checkRadiatorFanSpeedRationality` (was `cm848_calibration_group13_load`). At the governor setpoint, a fan speed outside 75-4000 rpm for `radiator_fan_speed_out_of_range_limit` passes sets it; the truck's dump has it active. The fan speed target is `cm848_selectCoolingFanSpeedTarget` (was `engine_egrFuel_stateMachine_update`; this ECM has no EGR, the `egr_*` names were wrong). It is the largest of the base / coolant (ramp + PI) / A/C / intake air / transmission temperature requests, then a high-engine-rpm ramp, the engine-driven cap, the ceiling, the thermostat-monitor hold and an override (`cooling_fan_speed_target_source`). The duty source selector is `cm848_selectCoolingFanDutySource` (was `fuel_coldStart_modeCode_select`); `cooling_fan_fixed_duty_enable` is 0 in the RAM dump, so the PID / engage-boost / idle sources are live (an earlier note read the neighbouring byte and called it 99). `cooling_fan_engine_idle_flag` (was `cold_start_mode_active_flag`) is an idle condition, not a cold-start flag. The `fuel_coldStart_*` helpers at 0x5139b8-0x513ba4 and `governor_fuel_limit_*` are unidentified (nothing ties them to the fan yet), the PI loop in `cm848_calculateAlternatorFieldDutyByPid` is the charging-voltage regulator, and `wastegate_duty_controller_state.request_half_duty_counts` x 2 is the wastegate duty request. The last-command caches follow the table entry: duty words at 0x40c138 + 2 x entry (`<output>_duty_command`) and period dwords at 0x40c198 + 4 x entry (`<output>_period_microseconds` / `_period_command`), ending at `output_read_back_fault_bits`.
- **Fuel pressure governor (2026-11-15, PR #48, todo 038):** `cm848_calculateFuelMeteringCommand` is a cascade of two loops.
  - **The rail pressure sensor (re-domained 2026-11-15; were `engine_position*` / `cam_sync_*` / `engine_sync_*` names):**
    - `cm848_processFuelPressureSensor` reads QADC slot 34: `fuel_pressure_sensor_volts` = raw × 4.
    - Above 4.80 V is code 4 = fault 304 = P0193; below 0.20 V is code 8 = fault 305 = P0192. Each code has a 40-sample debounce (`cm848_countFuelPressureSensorCodeChanges`).
    - In range, the 0.5-4.5 V table maps the volts to `fuel_pressure_sensor`, 0-3689 counts (DRB 7.078 per count: psi fits a 1800 bar sensor).
    - `cm848_sampleFuelPressureSensor` samples it periodically. While cranking, the injection-angle events do instead, into `fuel_pressure_at_injection_scheduling` / `_at_other_angle_events`.
    - `cm848_filterFuelPressureFeedback` filters the sample `fuel_pressure_feedback_source_select` picks (2 = the plain sensor) into `fuel_pressure_feedback_filtered`.
    - Governor mode 0x40 is the open-loop fallback for P0193 / P0192 / P0653 / P0652 (the sensor's 5 V reference B).
  - **The mode machine (`FUEL_PRESSURE_GOVERNOR_MODE`, on `engine_sync_state_t.fuel_pressure_governor_mode`):**
    - `OPEN_LOOP_START` (1, a temperature-table start command) → `CLOSED_LOOP_AFTER_START` (2) above 50 rpm or `fuel_pressure_governor_closed_loop_entry_pressure`.
    - After 1000 revolutions (`fuel_pressure_governor_start_revolutions`, counted by `cm848_countFuelPressureGovernorStartRevolutions`) → `CLOSED_LOOP` (4).
    - Both closed-loop modes fall back to 1 below 40 rpm and `_closed_loop_exit_pressure`.
    - Fixed-command modes: `LOW_PRESSURE_FIXED` (8; impossible in this calibration), `KEY_OFF` (0x10, command 0), `DISABLED` (0x20, 0), and `SENSOR_FAULT` (0x40, 2865 = 70 %).
    - `fuel_pressure_governor_feed_forward` is the rpm-table feed-forward.
  - **Loop 1, pressure PID:** error = `fuel_pressure_setpoint` - `fuel_pressure_feedback_filtered`. Its outputs:
    - `fuel_pressure_governor_proportional_term` / `_integral_term` / `_derivative_term`
    - `fuel_pressure_governor_accelerator_feed_forward`
    - their sum, `engine_sync_state_t_0040b87f.fuel_pressure_governor_demand` (was `reference_count`). It is clamped to a lower limit and an rpm table, and the integrator is put back while the demand is outside them.
  - **Loop 2, feedback trim:** a table turns the clamped demand into a target for `fuel_metering_feedback_input` (QADC index slot 63 x 4; the physical signal is not identified). The command is base + PI trim x base / 4096.
  - **Shared helpers:** `cm848_applyPiecewiseLinearGain`, `cm848_integrateWithZoneGain` and `cm848_calculateFilteredDerivative`.
  - **Stale-register quirk (confirmed 2026-11-16):** only governor mode 1 (OPEN_LOOP_START) sets r29 - the start temperature chosen by engine_sync_state_b; modes 2 / 4 and the fixed-command modes 8 / 16 / 32 / 64 jump past it, so the integrator-preset lookup at 0x48ba8 (taken while engine_rpm_measured is 0) reads the caller's r29 (the unaff_r29 argument). Likely harmless: it only runs with the engine stopped and mode 1 recomputes the preset before a start.
  - **State:** four Q16.16 states, typed as `q16_fixed_point_t` globals (`.integer_part` / `.fractional_part`), at 0x3fb66a / 66e / 672 / 676. A struct-typed global made the raw `0x3fb672`-style call arguments render as `&name`. `cm848_resetEngineSyncState` never clears 0x3fb676: its fourth store pair repeats 0x3fb66e.
- **Serial reflash hand-off (2026-11-15, PR #48, todo 038):** a serial (SCI) reflash goes through the boot ROM; the application only hands the session over.
  - **SCI command 49 (0x31, `cm848_sciCommand49Callback`):** needs byte 1, `sci_security_state` 1 (unlocked) and `cold_start_phase` 1 (or `end_of_line_test_settings_cal.field_mode_register` 5100). It writes `serial_reflash_unlock_request_cal` = 1 (EEPROM 0x56) and the boot-kernel magic 0x1d0a (EEPROM 0x00) with `cm848_writeEepromBytes` (was `cm848_memoryBlock_checksum_validate`), then calls `cm848_restartThroughBootRomAfterSciRequest`.
  - **`cm848_restartThroughBootRom` (0x216fc, was `mpc555_processJ1939RxQueue`):** saves two EEPROM dwords, acknowledges on SCI or J1939, sets chip-select 0, then jumps through the ROM 0x104 vector to `mpc555_hardwareInitialization`. J1939 PGN 61184 diagnostic service 11 (`cm848_handleJ1939RestartService`) uses it too.
  - **The boot ROM side:** it loads EEPROM 0x56 into `eeprom_shadow_header.serial_reflash_unlock_request`. `mpc555_initDiagnosticSession` then clears it and starts its SCI session at high speed (SCC1R0 0x14) with `boot_sci_security_state` (0x3fecc4) = 1, unlocked, so the seed is 0.
  - **Otherwise** the boot SCI security is locked (0). `cm848_bootSciCheckSecurityKey` answers 0 unlocked / 1 wrong key / 2 retry delay (`boot_sci_key_retry_delay` 1000) / 3 locked out (`boot_sci_failed_key_count` 3 → state 2).
  - **The two dwords saved before the restart** are the hour meters `key_on_hour_meter` → EEPROM 0x30 and `engine_hour_meter` → EEPROM 0x42 (see the runtime counter bullet above).
- **Power-down bookkeeping (2026-11-14, PR #48, todo 037):** EEPROM 0x7fe-0x810. Each start numbers the power cycle: `power_cycle_sequence_number_cal` = `completed_power_down_count_cal` + `incomplete_power_down_count_cal`. The power-down EEPROM save (`cm848_saveEepromForPowerDown`, was `engine_start_completion_sequence`) copies that number into `completed_power_down_sequence_number_cal`. At the next reset, `cm848_applicationMain (was hpcr_exceptionHandler)` compares the two:
  - **equal:** the completed count +1, and the consecutive count goes to 0;
  - **different:** the incomplete and consecutive counts +1, with fault 82 = P2509; above `consecutive_incomplete_power_down_limit` (3), fault 89 = P2509.
  RAM dump: 333 / 332 / 333 / 0. `cm848_runPowerDownSequence` (was `cm848_initProtectionTimers`) runs after the main run loop ends. It saves the EEPROM, releases logical output 27 (it looks like the ECM's power hold), and sets `power_down_left_ecm_powered_flag_cal` if the ECM is still running afterwards (fault 91 = P0606 at the next start). A key-on during the power-down goes to `cm848_restartOnKeyOnDuringPowerDown` (was `engine_protection_timer_sync`) → `cm848_restartApplicationWithoutReset` (was `cm848_engineStartCompletionB`), which resets the stack and re-enters the run loop without a hardware reset. The old names (`qadc_scan_*`, `sensor_diag_*`, the EEPROM copies of `protection_timer_a/b`) were guesses. The real protection timers are the RAM pair at 0x40b10a / 0x40b10c, which keep their names.
- **TIME-SHARED RAM caution:** 0x3fdba4-0x3fdc38 holds the kernel's CMF erase/program parameters during boot/reflash, but some of the same addresses are read by application code at runtime (e.g. 0x3fdba4 / 0x3fdba8 / 0x3fdbb2 / 0x3fdbd1 / 0x3fdbd2 / 0x3fdbdc / 0x3fdbfe by protection + J1939 builders). One Ghidra name per address — run an app-user check (`xref_addr.py`, caller ≥ 0x7F60) before renaming anything here; dual-use addresses keep their app-side name and document both roles.

Calls to `0x003Fxxxx` in the decompilation are calls from the boot ROM into the kernel's RAM copy — Ghidra already has them decompiled at their ROM source addresses, and since 2026-11-16 they render with the function's name (`mpc555_dispatchCanMessageHandlers()`, was `BYTE_003fae3c()`): the auto-label rows (`BYTE_` / `PTR_DAT_` / ...) that hid those names are type-only rows now. Three addresses keep a `BYTE_` data label on purpose because the application uses them as data: 0x3fd1ac / 0x3fd284 / 0x3fd298 (time-shared with the kernel image). Give them application names before dropping the labels. Since todo 043 (2026-11-17) a named row at a called image address no longer hides the call: the thunk stage uses call overrides there, so the boot calls render with the function names (`cm848_sendDiagResponsePending()`, was `BYTE_003fd1ac()`) and the data keeps its row.

**Declaring data in this window:** an array/struct's boundary is usually the copy-window EDGE (0x3FDB30), not the next named global — post-copy working RAM (handler tables etc.) begins at 0x3FDB30. Size arrays to 0x3FDB30, not to the next symbol (it may belong to a different structure). Array typing DOES apply over this code-overlap region (verified deterministic via `analyze.sh verify`) — the "types revert on export" caution is about scalar WIDTH, not array creation.

**Flat globals alias function bodies here (only inside a thunk's 4 bytes since todo 043, and only for unnamed rows - name the row):** a flat global declared in the slice overlapping a RAM-executed function gets a permanent `_` prefix (the function-image symbol wins) — declare it via `arrays.csv`/`structure_definitions.csv`, which survive. Hottest zone: `dispatchCanMessageHandlers` at RAM **0x3FAE3C–0x3FAFD0** (e.g. the PGN-65249 TX payload 0x3FAE51–0x3FAE62 must be an array, not 18 flat bytes).

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
- `link_event_code` setters: 1 = controller word bit 0x800, 2 = own echo differs from what was sent, 3 = non-data status mid-frame, 4 = TX-echo frame completed with error, 5 = RX in-frame response error, 6 = RX frame completed with error, 7 = every scheduled TX overdue. `cm848_handlePciLinkEvent` (0x3a290) applies `pci_link_event_action_mask_cal`; 255 counted errors latch `fault_detected_bits_368_to_383` 0x8000 (fault bit 383) + `mpc555_driveOutputLineLow(124)` (output line 124 — likely the controller's reset line; the old names `updateEngineSyncStatus` / `clearModuleSyncFlag` were the generic output-line drivers).
- **QSPI job driver (PR #45):** `cm848_registerQspiDeviceSlot` (0x3d68c, up to 4 device slots: SPI mode / kHz / delays), `cm848_queueQspiJob` (0x3da60, two 16-deep `qspi_job_queues`; queue 0 serviced first — PCI in-frame response bytes use it), `mpc555_qspiStartJob` (0x3d904), `cm848_completeQspiJob` (0x3dbc0, run by `cm848_onQspiFinished` on SPIF). Every `qspi_job_t` caller is a QSPI device driver — the `cm848_j1939Queue*` family @ 0x367xx and the `cm848_protection*` callers @ 0x4bxxx are NOT J1939/protection code and need their own review.
- **QSMCM register map corrected:** 0x305015 = PORTQS low byte, 0x305016 = PQSPAR, 0x305017 = DDRQS, 0x305018-0x30501f = SPCR0 / SPCR1 (SPE) / SPCR2 / SPCR3 / SPSR (`qsmcm_qspi`). 0x305010-0x305013 are unused.

**EEPROM RAM mirror CONFIRMED (2026-11-11, PR #46):** the application's SPI serial-EEPROM driver (`cm848_initEepromDriverAndLoadMirror` @ 0x4cb64, QSPI PCS0) reads EEPROM offsets 0x0-0x1a3f into RAM **0x3fd482-0x3feec1** (`eeprom_mirror`; RAM = 0x3fd482 + EEPROM offset), checksums EEPROM 0x8ea-0x1a3d against `eeprom_block_checksum_expected_cal` (EEPROM 0x5c; fault bit 0x40), and `cm848_startEepromMirrorSave` writes that block back with page writes. So every value in that RAM range is EEPROM-backed (`_cal`), not just 0x3feexx.

**J1939 input layer (2026-11-12, PR #46):** Bank-2 receive handlers `j1939_receivePgn{57344,61441,61443,65252,65264,65265}Handler` (registered by `j1939_handlerInitializer`) accept each signal only from `j1939_input_source_address_filter_cal[slot]` (0xFF = any; all 0xFF in this cal), reload `j1939_input_signal_timeouts[slot]` and store `j1939_received_*`. Two tasks process them: `cm848_processJ1939SwitchAndRequestInputs` (0x50aba8 — the 17-entry `j1939_input_signal_descriptor_table` @ 0x53a278 via `cm848_evaluateJ1939InputSignalFault`, CM1 fan request = input 0, EBC1 retarder selection = input 5) and `cm848_processJ1939AcceleratorInputs` (0x50ad1c — EEC2 low idle switch = input 6, pedal position = input 7); per-input bitmaps `j1939_input_timeout_bitmap` / `j1939_input_data_error_bitmap` / `j1939_pedal_input_timeout_bitmap`. **The whole layer is OFF in this calibration** (`j1939_input_processing_enable_cal` bit 0x400 = 0, and every per-input enable is 0 too).
- **Consumers (whole-binary scan of both banks + 32-bit pointer search, 2026-11-12):** only EEC2 pedal position 1, the EEC2 low idle switch, EBC1 retarder selection (→ `j1939_engine_retarder_selection_percent`, read by `cm848_calculateEngineRetarderSelectionPercent`) and CM1 fan request have processors. The **CCVS1 cruise / brake / clutch / idle increment-decrement / test-mode switches, the EBC1 switches, pedal position 2 and the remote pedal position are received and supervised but read by NOTHING else** — J1939 cruise switches cannot drive cruise in S90140.06.
- **J1939 pedal path (task 022 - CORRECTED 2026-11-16, was "drive-by-wire dead end"):**
  - `cm848_processJ1939AcceleratorPedalPosition` writes EEC2 SPN 91 (x 16 / 10 = 0.25 % per count, 400 = 100 %) into the accelerator pedal channel's state, `sensor_channel13_ram.held_value`, with its source priority in `.held_value_source_priority`.
  - It runs only when bit 13 (0x2000) of `sensor_channel_held_value_enable_bits_cal` is set and switch 7 is datalink-sourced (`switch_input_datalink_source_bits_cal` bit 7). That flag word is 0x3fda68 = EEPROM 0x5e6. It is really a per-channel bitmap: bit n makes channel n output its held value.
  - With that same bit set, the sensor-channel functions output `held_value` in place of the pedal sensor. So the J1939 pedal DOES reach `sensor_channel_filtered_output[13]` (`accelerator_pedal_sensor_filtered`).
  - The 2026-11-12 "has no reader" conclusion came from a name search. The channel reads the value through `state_ptr` + 6, which never names the address.
  - Bit 0x2000 also switches `cm848_fuelDemandFinalCalculation` / `cm848_fuelDemandCoordinator` to their J1939-pedal branches.
  - **Into fueling:** `cm848_fuelDemandFinalCalculation` then sets `fuel_demand_control_t.calculated` from `accelerator_pedal_sensor_filtered` (directly while the J1939 source wins the priority check, else through `rate_limited`). That word is channel 13's output, which in this mode is the J1939 value. The old note's "copies raw pedal-sensor counts" read it as the analog sensor.
  - **Same scale:** the pedal channel's own table maps ADC 39..839 to 0..400. That is 0.25 % per count, exactly what the J1939 writer produces (SPN 91 x 16 / 10), so the J1939 pedal is a drop-in substitute for the analog pedal.
  - In this calibration the bitmap is 0 and the J1939 input layer is off (`j1939_input_processing_enable_cal` bit 0x400 = 0), so using it means EEPROM changes: the bitmap bit, the switch-7 datalink bit and the input-layer enables. Bench-test them before driving. TSC1 remains the other J1939 fueling path.
  - The CM1 fan request output is write-only.
- Positions: EBC1/EEC2 from the j1939 Mongo DB; CCVS1 and CM1 from standard J1939-71 (the DB docs for those have no positions). SHUTDN / PTO values are still unnamed.
- The ROM `j1939HandlePgn65265CruiseVehicleSpeed` (0x24178) and `j1939HandlePgn61443Eec2` (0x25b10) are the ECM's own CCVS1 / EEC2 **transmit** builders (they end in `sendJ1939Message`), not receive handlers — names not yet fixed.

**Switch-input layer (2026-11-12, PR #46):** 32 logical switches, scanned by `cm848_scanAndDebounceSwitchInputs` (0x4eb48). Each switch comes from (a) `switch_input_datalink_state_bits` when its `switch_input_datalink_source_bits_cal` bit is set (EEPROM 0x74c; the J1939 input layer writes it through `cm848_set/clearDatalinkSwitchStateIfPriority`, arbitrated by `switch_input_source_priority`), (b) its hardware line `switch_input_hardware_line_cal[n]` (EEPROM 0x70c) read from `input_line_image` @ 0x40c0f8 (filled by `cm848_refreshInputLineImage` in one pass and by `cm848_readDiscreteInputLine`, 0x4f2ec) XOR `switch_input_polarity_bits_cal`, or (c) its software-set value when it has no line (e.g. switch 31). A 4-sample debounce writes `switch_input_state_bits` @ 0x40c050 (switch n = byte n/8, bit n%8).
- Identified: **7 = accelerator at idle, 8 = accelerator off idle** (idle validation pair; `cm848_evaluateIdleValidationSwitches` cross-checks them against the pedal sensor into `fuel_demand_control_t.idle_validation_state` 0-8). The ECM's CCVS1 broadcast reports **15 as the clutch switch and 11 as the brake switch**. **0** = the ignition key switch (line 128 = `mios_mdasm30.SCRD` bit 15, the MDA30 pin, 1 = key on; its falling edges count `ignition_key_off_count`). **31** has no hardware line: every switch function this Dodge build leaves unwired compiles to it (CCVS1 cruise / idle / test-mode fields, PTO set-resume, two-speed axle, derate override, governor type, torque limit). Its only direct writer, `cm848_updateSwitch31FromAcceleratorPedal` (0x2c3c8, 2026-11-13): with key on, engine stopped and `j1939_feature_enable_flags_cal` bit 10 set (0 here = off), three accelerator presses past 70 % and back below 30 % within 5 s pulse it for one pass; an accelerator sensor fault holds it on. `cm848_calculateVehicleSpeedFromOutputShaft` uses it (with `two_speed_axle_enable_cal`) to pick the second axle-ratio divisor, and the CCVS1 builder derives almost every switch field from it (byte 1 two-speed axle, byte 4 cruise enable, all of bytes 5 and 8) — so the ECM does not broadcast real per-switch states there.
- This calibration's line map: 0:128 1:132 3:148 5:138 6:137 7:144 8:145 9:130 10:131 11:147 12:149 14:150 19:148 20:13 21:18 22:154 23:153 24:156 25:152 27:155 28:22 (no line: 2 4 13 15-18 26 29-31).
- The old `protection_enable_t_0040c050` struct (`mode_bits` / `system_enable_bits` / `protection_active`) WAS this array. `protection_active` was a 1-bit field on byte 3 and Ghidra 12.1 drops bitfield masks, so it rendered for ANY bit of byte 3 — pre-PR-46 readings of "protection active" are suspect. The `protection_*` functions that test these bits (bit 31 is written by the 0x2c2xx-0x2c6xx accelerator-press cluster) need review.

**Vehicle speed (2026-11-12, PR #46) — the old "fuel temperature trim" family IS the vehicle speed chain.** `vehicle_speed` @ 0x40a272 (was `fuel_temperature_trim`, 50+ readers) = 1/256 mph per bit. Source 1: the speed sensor on **TPU-B channel 2** (`cm848_initVehicleSpeedSensorChannel`, period-measurement function 0xD; `cm848_vehicleSpeedSensorInterruptHandler` copies the period and reloads `vehicle_speed_pulse_timeout`); `cm848_calculateVehicleSpeed` = 921600 x 40e6 / (pulses_per_mile x 128 x period) with `vehicle_speed_sensor_pulses_per_mile_cal` = **8000** (EEPROM 0x46e; the Chrysler standard), 3.2 us TPU ticks, 2-150 mph clamps, jump rejection, EMA. Source 2 (J1939 automatic drivetrain): `cm848_calculateVehicleSpeedFromOutputShaft` from the transmission output shaft speed with an axle divisor chosen by switch 31 + `two_speed_axle_enable_cal` (two-speed axle). The CCVS1 broadcast sends it x 412/256 (mph -> km/h). On this truck it reads 0 (no sensor wired; period still at its 0x5e7fb044 start value). `drivetrain_ratio(_raw)` = engine speed over vehicle / output-shaft speed x 2048. Fault freeze frames store it (`fault_entry_t.vehicle_speed`, was `temperature_trim`). Most other `fuel_temp*` / `fuelTemp*` names were re-domained on 2026-11-13 (e.g. `governor_minimum_speed_by_vehicle_speed_table` / `_axis`, `output_speed_sensor_check_minimum_vehicle_speed`, `governor_park_neutral_maximum_vehicle_speed`, the `engine_to_vehicle_speed_ratio_*` monitor). Odometer: `vehicle_speed_sensor_pulse_total` deltas go out in PCI transmit message 11 (header 0x5D) with two fuel totals (built by `cm848_buildPciTransmitMessage11DistanceAndFuelUsed`). **The dash odometer itself comes back in on PCI RX[11] header 0x72: `pci_receive_message_11_odometer` @ 0x40b471 (u32 big-endian, 1/8000 mile — 0x8B633FCC = 292,317.2 mi in the RAM dump), so a CLIP 0x4A read of 4 bytes at 0x40B471 returns the cluster's odometer.** It has the same 8000-per-mile unit as `lifetime_distance_pulses`; the ECM only tests it for zero (fault bit 345 in `cm848_runImmobilizerTask`).
- **P0500 = fault 29 (2026-11-17, todo 044).** `cm848_runVehicleSpeedSensorMonitors` (0x526c80) runs three functions:
  - `cm848_detectVehicleSpeedSensorSignalLoss`: the sensor drops to 0 while the filtered `vehicle_speed` is still above 10 mph. Enabled by EEPROM 0x132 bit 0x100, which is clear in this calibration.
  - `cm848_detectVehicleSpeedSensorZeroUnderLoad` (was `diag_boostLoad_overtemp_monitor`): 10 boost / load events (30 passes each: boost above baro over 94.8 kPa, filtered load over 40 %) plus 10 accelerator off-idle entries, all with the sensor at 0. Enabled by bit 0x200, which is set here.
  - `cm848_clearHealedVehicleSpeedSensorFault`: heals P0500 whichever source set it.
  - A third source is in `cm848_processGovernorModeTransition` (0x2715c). On the J1939 automatic drivetrain (`DRIVETRAIN_AUTO_J1939_FULL`), when the ETC1 output shaft speed times out (`j1939_tsc1_override_state.etc1_speed_cmd_timeout` reaches 0), it zeroes `output_shaft_speed_current` and sets fault 29. This only happens with the key on and the engine cranking or past ROM 0x5c3a8 passes running.

  Function names that disagree with the P-code they set are misname leads. `docs/agent_notes_2026-11/session_2026-11-17_p0500/session_folder/fault_setters.py` lists the P-code each function sets. The open leads are in `work/tasks/044`.

**Trip / lifetime counters (2026-11-12, PR #46 — renamed):** `cm848_updateTripAndLifetimeCounters` (0x523148, was `j1939FuelDemandProcessing`) runs in 2 of the 40 main-loop phases (~100 ms if a phase is one 5 ms PIT tick — unconfirmed) when bit 13 of `engine_feature_enable_flags_cal` (0x3fd5ec, EEPROM 0x16a = 0x27EF here; was a second `governor_system_config_flags`) is set. SCI command 35 (`cm848_sciCommand35Callback` -> `trip_counters_reset_pending_flag`) clears the trip set. Lifetime / trip pairs (EEPROM offset): distance pulses `lifetime_distance_pulses` 0x8ea / the trip dword at 0x3fee28 = 0x19a6; engine-run passes `lifetime_engine_run_time` 0x19de / `trip_engine_run_time` 0x19f2; passes at governed speed (governor mode 11 within +/-400 rpm of its target — probably idle) `lifetime_time_at_governed_speed` 0x19da / `trip_time_at_governed_speed` 0x19ee; fuel `lifetime_fuel_used` 0x19d6 / `trip_fuel_used` 0x19e6; fuel at governed speed `lifetime_fuel_used_at_governed_speed` 0x8f4 / `trip_fuel_used_at_governed_speed` 0x19ea; `trip_average_fuel_economy` 0x8f2 (distance x 13603 x 8 / (trip_fuel_used x 8000) — reproduces the stored 94 / 90 = 9.4 / 9.0 mpg, so one fuel count is about 1/10882 gallon). Fuel source: `injected_fuel_running_total` (was `crank_period_running_total`) gets every injection's quantity added from the TPU-A channel 6 injection interrupt; the counters take its delta >> 12 at each PCI 0x5D send. **HP Tuners zeroes all of them** (older dump: 13,044,913 pulses = 1,631 mi, 3,196,806 engine-run passes; before-HPT dump: 1,448,503 = 181 mi; after HPT: 0). **PGN 65248 Vehicle Distance (on-request responder `cm848_j1939HandlePgn65248VehicleDistance`) reports `lifetime_distance_pulses` / 8000 x 12.874752 as total vehicle distance** — the decompiler shows its 64-bit divisor 8,000,000,000 truncated to 0xdcd65000 — so a J1939 ELD sees this wiped ECM counter, not the cluster odometer; the trip field source (0x3fdd70) is never written. PCI 0xDF byte 1 = `lifetime_distance_pulses` >> 22. No responder is registered for PGN 65253 (hours), 65244 (idle) or 65257 (fuel). **Still mis-typed:** RAM 0x3fee08-0x3fee2f is time-shared — during boot it is the boot ROM's own EEPROM-header shadow (`eeprom_shadow_header`, whose `config_dword` holds the runtime counter loaded from EEPROM 0x30), afterwards the app's mirror of EEPROM 0x1986-0x19ad — so the trip distance dword still renders as `ram0x003fee28`. The boot-time use goes on past 0x3fee2f: `mpc555_eepromValidationCycle` counts in the dword at 0x3fee34, `cm848_lookupEepromParameterAddress` returns 0x3fee38 and `cm848_bootSciCheckSecurityKey` reads the bytes 0x3fee3a-0x3fee3d, while the application keeps its oil change monitor there (EEPROM 0x19b2-0x19bb) - retyping those words for the application made the boot code worse (2026-11-16), so they keep their types.

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

**Regenerate the headers after any rename** (user rule, 2026-11-15). `output/firmware_types.hpp` / `firmware_globals.hpp` / `firmware_functions.hpp` come from `scripts/generate_headers.py`; commit them in the same PR.
- Call its `generate_types_header` / `generate_globals_header` / `generate_functions_header` functions directly. Don't run its `main()`: `main()` also prepends an `#include` block to `.ghidra.cpp`, which the build never writes, so the `.cpp` would stop matching the build output.
- Check: `g++ -fsyntax-only -std=c++17 -I output` on a file that includes all three headers. Each remaining error is a CSV problem to fix, not something to patch in the generator (see `docs/plans/2026-03-30-compilable-firmware-design.md`):
  - an enum member name used in two enums;
  - one global name at two addresses with different types;
  - a repeated struct field name.

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
- **NO invented abbreviations** - spell words out in ALL names (vars, functions, enum members AND enum prefixes). Banned: made-up initialisms like `CCS_SET`, `CSR_IDLE`, `GSR_*`. The ONLY allowed abbreviations are universal industry standards (~99% recognize instantly): RPM, J1939, CAN, ADC, PWM, VSS, EGT, PID, TPU, QADC, kPa. An enum must read `cruise_control_state == CRUISE_SET`, not `== CCS_SET`. Use a fully-spelled domain prefix on enum members (`DRIVETRAIN_STANDALONE`, `CRUISE_SWITCH_SET`). A short disambiguator suffix (`_2`, `_B`, `_PREV`) is fine — it is not an abbreviation. **`initialize`, not `init`** (the user's decision, 2026-11-17: new names use `initialize`). For a data name, pick `initial_` or `initialization_` by meaning. The rename gate (`scripts/rename_waves/apply_renames.py`) rejects `init`; older `init` names stay until a rename touches them.
- **Verify legacy/auto names against behavior** - generated names often borrow the wrong domain (the data's UNIT, the caller task-set's name, or a sibling channel), not what the code does; confirm against the body's actual writes/consumers + asm width before trusting (one session found 6 symbols misnamed this way)
- **No NAME ≠ no code; hardware/FSM is ground truth** - a missing symbol means UNDISCOVERED, not absent (the `.cpp` is only partially named). If the schematic/FSM/wiring says a pin/bus/feature exists, it IS there — go find it; never conclude "not present" from a failed grep. (Burned 3× in one session: trans-temp sensor C2-29, J1850, the entire SCI datalink stack.)
- **`_cal` = EEPROM-backed only, by the MEMORY MAP (not e2m)** - ROM / ROM→RAM copy (0x3F9800–0x3FDB30) / flash = fixed constant → no `_cal`; EEPROM-loaded → `_cal`; computed/working RAM → never. e2m uses Calterm *virtual* addresses, so a RAM-address grep is blind. **CM848: the EEPROM RAM mirror is `0x3fd482`-`0x3feec1` (RAM = 0x3fd482 + EEPROM offset; verified 2026-11-11)** — values there are EEPROM-backed → `_cal`; other `0x40xxxx`/`0x3fxxxx` cals are ROM/flash → no `_cal`. (grep `mpc555_eepromReadWords(` to settle a specific address.) **Bulk sweep:** `python3 scripts/audit_cal_suffixes.py <fw>/output/global_variables.csv` reports every `_cal` name whose region contradicts this rule (read-only). ~1352 CM848 HARD hits are **legacy campaign debt**, not new bugs — fix opportunistically. See the **`auditing-cal-suffixes`** skill.
- **Name locals via `local_variables.csv`** (`addr,fn,old_name,new_name,type,comment`). Rows match the decompiler's AUTO-names (`iVar7`), so a change that renumbers a function's temporaries (a retype, a cut array) makes them land on the wrong variables WITHOUT a warning for most rows (wave 9: the Type B sensor-channel rows put `low_fault_word_index` on `channel_index >> 4`). After a type change, re-check the functions with local rows: build once without their rows to read the new auto-names. Don't reuse a global's name for a local — it creates a confusing shadow (used `fuel_temp_trim_uncapped`, not the global `fuel_temp_trim_working`).
- **Function must exist in Ghidra** - CSV renames only work for addresses Ghidra recognizes as functions
- **import force-creates functions** — `function_renames.csv` entries at addresses with no function get disassembled + created (not just renamed). This reproduces Bank2 (force-analyzed) functions; their names ARE in `function_renames.csv` (~567 entries), not a side file.
- **funcdefs / r4-return gotcha** — declare the FULL prototype (return + all param rows); a return-only row is auto-handled (import preserves Ghidra-recovered params, warns on count mismatch) but yields generic `param_N` names. NEVER declare a return for an r4-return function whose r4 is NOT a parameter (no-arg/globals-only helpers like diag handlers) — the decompiler then assumes r4 is preserved and swaps the wrong operand at call sites. To undo a bad prototype, fix/remove the row in `function_definitions.csv` and rebuild.
- **Prototype / local type keywords (2026-11-14, PR #48)** — in `function_definitions.csv` and `local_variables.csv`, `int` means **unsigned** `dword`; use **`int32_t`** for a signed 32-bit value (it renders `int`). `short` / `ushort` / `word` are all unsigned `word`, and prototypes / locals have no signed 16-bit keyword yet. `undefined4` locks a name and keeps the inferred type; a 2-byte parameter needs `ushort` (as `undefined4` it renders `x._2_2_`). Locked pointer types, and committed parameters on one-line wrappers, add casts at call sites. These two mappers (`ApplyFunctionDefinitions` / `ApplyLocalVariables`) are separate copies, and the others differ: struct fields (`ApplyStructures`) map `int` / `short` to signed types, and globals (`ImportAnalysis`) use `i8` / `i16` / `i32` with no `int` case — see the `editing-firmware-csvs` type reference.
- **Call-fixups: fold compiler-RTL division into operators (CM848, Ghidra 12.1+)** — the MPC555 has no 64-bit hardware divide, so the compiler emits calls to runtime helpers (`cm848_unsignedDivision32`/`signedDivision32` + workers) with the 64-bit dividend split into an `r3:r4` register pair. `call_fixups.csv` + `ApplyCallFixups.java` register a program-stored compiler-spec extension (`firmware/scripts/callfixups/<name>.xml`) and `setCallFixup` it onto each helper, so the decompiler renders a real `/` (or signed `/` via `s/`) instead of an opaque call. Applied as the `callfixups` build stage (after `import`, before `export`). Validated 2026-06-03: 124 caller functions, **zero collateral** (only callers change), zero dropped divisions, byte-identical `verify`.
  - **Two hard-won rules:** (1) The helper returns 64-bit in the `r3:r4` pair (proven by its `/0` epilogue `li r3,-1; addi r4,r3,0`); the fixup p-code must write **only `r4`** (the killed-by-call low word callers consume) — writing `r3` (the EABI return reg) makes leaf callers inherit a spurious `undefined4` return. (2) Only fold **pure** division helpers. `saturatingDivision16`, `clampedDivisionWithBounds`, `signedDivisionWithSaturation`, `extendedDivisionWithRemainder` carry extra semantics (saturation/clamp/remainder) — folding them to a bare operator would *hide* that = semantic drift, so they stay named calls.
- **`.cpp` has a wall-clock `Generated:` header timestamp** — every rebuild yields a 1-line diff on that line even when the decompilation is identical; `verify` normalizes it (the body is the deterministic part). Don't commit timestamp-only churn — `git checkout` the file.
- **"1 function import failed" build warning is benign/long-standing** — it is NOT caused by your edit. Verify YOUR specific CSV additions rendered in the `.cpp` (grep the new names) rather than chasing the warning.
- **Shared-script edits affect BOTH firmwares** — after changing `firmware/scripts/*.java`, rebuild CM848 *and* CM550; a CM848-only change should leave CM550's `.cpp` byte-identical except the timestamp (e.g. the bitfield/`clearAtOffset` change never touched CM550, which has zero bitfield rows).
- **Decompiler wraps long lines** — `grep 'name('` undercounts call sites (the `(` wraps to the next line). Count refs with name-only `grep -c 'name'` minus the definition / `// Function:` / injection-comment lines (a `name(` grep once showed 44 division calls; the true count was 115 across 77 functions).
- **`.cpp`-text ref counts OVER-count data globals** — one asm access can render as 2+ `.cpp` lines (CONCAT44 64-bit-multiply, register-reuse without reload, a conditional split across lines), inflating a 1-ref var into the "2-ref" tier. Trust `xref_addr.py`'s access count, not `.cpp` grep, when tiering symbols for a naming pass.
- **Reproducibility: PROVEN** — `build` is a deterministic fixed point. Two independent `build`s from a fresh binary produce byte-identical `.cpp` + CSVs (`verify` asserts this). Auto-analysis is deterministic; `import` force-creates functions from `function_renames.csv`; `deleted_functions.csv` removes spurious splits; the new baseline preserves all curated names and *surfaces* 90 real functions the old hand-curated baseline was missing (func_0x 75→29). The apparent "~2965 extra DAT_" gap from earlier was a measurement artifact — unnamed RAM vars render `DAT_` (initialized RAM) vs `uRam` (uninitialized); both are default names, no curation lost.
- **deleted_functions.csv** — vet candidates with `classifyfuncs` before adding: an entry with incoming CALL refs is a REAL function (do NOT delete — add to `function_renames.csv` instead); only no-ref / jump-only entries are true mid-function splits. **`classifyfuncs` is BLIND to untyped pointer tables** (2026-11-11, PR #46): 19 "no-ref" deletions were real functions reached only through tables — 15 `cm848_fuelDemand*` handlers in the 0x53a9a0 dispatch table and 4 TPU/MIOS interrupt handlers incl. the TPU-A channel 6 injection handler, which every build silently dropped. Before deleting, also search ROM + flash2 for a big-endian 32-bit pointer to the address. A deletion only takes effect if the address has NO `function_renames.csv` row (the second `import` recreates it). Never leave a named function in `deleted_functions.csv`: the delete + recreate drops its plate comment and its stack frame, so its locals render as `uStack_` / `auStack_` (32 such rows were removed 2026-11-15, PR #48; 31 plate comments had never rendered).
- **Interrupt handler tables (typed as pointer[16] arrays):** `mios_interrupt_handler_table` @ 0x582da (MIOS1 flag bit), `tpu_b_channel_interrupt_handler_table` @ 0x583ae, `tpu_a_channel_interrupt_handler_table` @ 0x583ee (TPU channel 0-15). TPU-A ch6 = `engine_injectionAngle_tpuChannel6EventHandler` (per-cylinder injection scheduling), ch10 = `engine_injectionAngle_tpuChannel10CylinderEventHandler`. The bootstrap found 39 "spurious" Bank-2 candidates were actually real functions the campaign missed.
- **Type width must match hardware access** - `bool` (1B), `byte` (1B), `word` (2B), `dword` (4B) must match the actual load instruction (`lbz`=1B, `lhz`=2B, `lwz`=4B). Wrong width is silently reverted to `word` on export. This also prevents enum substitution for byte-width variables.
- **Plate comments round-trip via function_renames.csv** - 3rd column is preserved through a `build` cycle since the 2026-05-25 fix. If `build` drops a plate comment, it indicates `ExportAnalysis.java` failed to compile (check for missing imports).
- **CSV comment commas — which columns are safe** - `function_renames.csv` (`split ,×3`) and `global_variables.csv` (`split ,×4`) absorb commas into the LAST column, so review prose with commas is fine there. `structure_definitions.csv` / `call_fixups.csv` use the quote-aware `parseCSVLine` — keep those comments comma-free or quoted.
- **A checked bit ≠ a live trigger** - when a gate ORs in flag bits, grep for a SETTER (`| 0xNN`, masked/whole-word assignment, BOTH banks) before treating the condition as reachable. Checked-but-never-set bits are shared-firmware / excluded-feature artifacts (e.g. the protection gate's `safety_bits_1 0x10/0x20`, dormant in this calibration).
- **Enum types just need to be in `enums.csv`** — `build` runs the `enums` stage before `import`, so a new enum type is always registered in Ghidra's DTM before globals reference it. (Ordering is automatic; there is no separate `enums`/`import` step to sequence by hand.) **Struct fields can be enum-typed too** (since 2026-11-15, PR #48: `ApplyStructures` used to fall back to `byte` for every type name that wasn't a built-in or one of its own structs, so enum-typed fields such as `J1939_ACK_TYPE` never rendered member names; it now looks enums up by name). Example: `engine_sync_state_t.fuel_pressure_governor_mode` is `FUEL_PRESSURE_GOVERNOR_MODE`.
- **Named types preserved through the export stage (since 2026-05-26)** — `ExportAnalysis.java` reads existing CSV before overwriting and applies priority: named Ghidra type > named CSV type > primitive Ghidra type. Enum types set via CSV survive `build` cycles.
- **Masked flag access → declare a bitfield (Ghidra 12.1+)** — for a flag tested as `(var & MASK)`, declaring the field as a structure bitfield now renders it symbolically. Verified end-to-end on `protection_enable_t.protection_active` (the bit7 `0x80` boolean) 2026-06-03: reads `... .protection_active & 0x80` became `... .protection_active != 0`, and the set/clear writes `| 0x80` / `& 0x7f` became `protection_active = 1` / `= 0`. **Requires Ghidra ≥ 12.1** ([issue #647](https://github.com/NationalSecurityAgency/ghidra/issues/647) / GP-2493 — *"the Decompiler now recovers and displays the names of bitfield components… when analyzing code that manipulates them"*). On the old from-source **12.0** build the opposite happens — the mask survives **and** the field name is lost (renders raw `struct._N_1_ & MASK`, the closed-as-known [#2462](https://github.com/NationalSecurityAgency/ghidra/issues/2462) on PPC), so this is strictly gated on the toolchain. CM848 is pinned to 12.1 (which has this fix); see the **Ghidra version pinning** section above for how each firmware's version is enforced.
  - **CSV syntax** (`structure_definitions.csv`): set the `type` column to `bitfield:<bitSize>@<bitOffset>` (bitOffset is from the LSB; bit7 = the `0x80` bit of a byte) and the `size` column to the storage byte-width. For several flags packed in one byte/word, give the first member the byte-width and each additional member `size=0` (continuation — shares the opener's storage unit). `ApplyStructures.java` places these via `insertBitFieldAt`.
  - **Enum caveat still stands:** symbolic *enum* names appear for `var == ENUM_VALUE` but NOT for `(var & MASK) == VALUE`. Use a bitfield for packed flags; an enum type only for whole-value compares.
- **Byte edits on a stack copy of a 32-bit register: type the register AND the copy as a byte struct (2026-11-15).** The pattern: `lwz` the register, `stw` it to the stack, `lbz`/`stb` one byte of the copy, `lwz`/`stw` the copy back. Untyped, it renders as `local_4._1_1_ = (byte)(dVar1 >> 0x10)` plus `CONCAT12(...)` pieces.
  - Example: `siu_gpio_data_register_t` (`byte_0`..`byte_3`, a type-only template) on `SIU_SGPIODT1` / `SIU_SGPIODT2` in `global_variables.csv`, and the `gpio_register_copy` rows in `local_variables.csv` (`ApplyLocalVariables` finds struct types by name). The edit now reads `gpio_register_copy.byte_1 = gpio_register_copy.byte_1 & bVar9`, and the register rebuild in `cm848_refreshOutputPortsAndReadback` is four named byte stores.
  - Typing only the local leaves the `(byte)(dVar1 >> 0x10)` shifts and a `(dword)` cast at every store. Typing the register too costs casts only where code does whole-word mask arithmetic on it (`mpc555_updatePowerStateOutputs`). A union of `dword` + the bytes read worse (mixed `.bytes` / `.value._2_2_`).
  - Bytes the code never touches still render as one `_N_M_` piece (`gpio_register_copy._2_2_ = sVar1._2_2_`). That comes from the decompiler splitting the partially stored stack slot, not from the type.
  - The MIOS port halfword gets the same treatment: `mios_port_data_register_t` (`byte_0` = bits 15-8, `byte_1` = bits 7-0) on the `mios_port_copy` / `input_port_copy` locals; the register itself stays `word` because the output line drivers do whole-word bit arithmetic on it.
- **Discrete line images (2026-11-15, todo 040):** line N is byte N/8 bit N%8 of three 20-byte `discrete_line_image_t` instances (fields `lines_0_to_7` .. `lines_152_to_159`):
  - `output_line_read_back` (0x40c0e4): every output port read back by `cm848_refreshOutputPortsAndReadback` before it rewrites them (were `j1939_dm1_prev_b*` / `j1939_lamp_status_*`).
  - `input_line_image` (0x40c0f8): `cm848_refreshInputLineImage` (0x533e0, was `hpcr_injectorPulseWidthCalc`) fills it in one pass, `cm848_readDiscreteInputLine` one line; the switch scan reads it (were 15 `j1939_dm1_*` / `j1939_*` bytes).
  - `output_line_state` (0x40c10c): the command shadow written by `cm848_applyLogicalOutputRequests` and `mpc555_driveOutputLineHigh` / `Low` (were `output_lines_N_to_M_state` and a bogus `injector_control_t` over lines 88-143).
  - Port map: MIOS port lines 8-23 / SIU_SGPIODT1-2 24-87 / TPU channels used as discrete outputs 88-119 (output only) / MDASM pins 120-128 / supervisor chip 130-151 / serial output driver 152-159. Bytes 0 and 11-14 of the input and read-back images have no port.
  - **MIOS port byte order disagreement (from the disassembly):** the refresh and the input image put lines 8-15 in port bits 7-0 and lines 16-23 in bits 15-8, but `mpc555_driveOutputLineHigh` / `Low` set bit (line mod 16), with the bytes swapped, until the next refresh rewrites the port. Which one matches the harness is a bench question.
- **Array globals (2026-11-15):** a `T[N]` type in `global_variables.csv` (`word[10]`, `byte[17]`, `my_struct_t[4]`) is applied by the importer. It used to be dropped without a word (only `arrays.csv` applied arrays), so 3 rows never took effect. An empty name types the address without naming it (the default label stays). Every type the importer cannot map is listed with a WARNING in the build log.

### CM848 `_DAT_` Naming Campaign — Status

All 3+, 2+, and 1-occurrence unnamed `_DAT_003Fxxxx` variables have been named (batches 1-5,
~1,049 entries added 2026-05-25). 67 WARNINGs remain — all permanently stuck:

| Variable | Why Stuck |
|----------|-----------|
| `engine_retarder_override_control_mode` (was `_governor_mode_state` (12×); no underscore since its 2026-11-16 rename), `_fuel_temp_trim_scale_cal` (8×), `_engine_sync_prot_gain_b_cal` | `stw` pair-clear: single `stw` writes 4B across two gap=2 `word` vars — cannot widen either individually |
| `_oil_change_monitor_distance_pulses_cal` (was `_sensor_validation_delta`; 0x3fee3a is also time-shared with the boot ROM), `_fault_counter_slot3_target`, `_fault_counter_slot3_shadow` | gap=1 to next named var — widening would overlap neighbor |
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

**Yield is range-dependent — measure one wave before committing a whole tier.** Working-RAM `0x0040xxxx` is mostly flat scalars (2-ref ≈ 63% nameable). ROM-shadow `0x003fxxxx` low-ref is dominated by lookup cache words (`*_interp_state`, pointer-passed - typed `word` / `word[2]` since 2026-11-15), J1939 struct buffers, and sensor-channel config bases (2-ref ≈ 14%) → route to `structure_definitions.csv`/`arrays.csv`, not flat globals. INSUFFICIENT clusters as: pointer-passed (address-taken, never directly loaded) · write-only (no real reader) · array element / struct member · single-real-access.

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

The same applies when the fields live in a type-only template (rows with an empty address). An instance row that repeats a field appends a second copy of it. CM550 had seven such structs (`mc68336_reg16_t` was 14 bytes instead of 2).
All seven now use markers (PR #48).
- **The five 0xfffxxx register structs** never applied (no memory block when `ApplyStructures` runs), so their fix left the `.cpp` unchanged.
- **The two RAM structs:** `j1708_multipacket_msg_t` (260 → 256 bytes) and `can_buffer_setup_t` (20 → 16) had covered `fuel_limit_shutdown_minimum` and `ambient_conditions_msg_header`.
- **When a struct changes size, diff the build:** the change can uncover an instance the old size was blocking. Shrinking `j1708_multipacket_msg_t` let a guessed `j1708_rx_buffer_t` apply over 11 fuel-limit globals, so that row was removed.

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
- Sensor channels use paired wrappers: `sensorChannelN_init()` calls the periodic pass, `sensorChannelN_process()` the boot pass (the suffixes are inverted - see the memory note in PR #39).
- **Four channel functions, one prototype (2026-11-16):** Type A `sensorChannelConfigInit` (0x500234, periodic) / `updateSensorChannelWithConfig` (0x500a4c, boot) and Type B `sensorChannelTypeB_configInit` (0x5012dc) / `sensorChannelTypeB_update` (0x501b4c) run the same algorithm and take the same 13 parameters:
  `(sensor_channel_config_t *config_ptr, sensor_channel_state_t *state_ptr, word *cached_axis_offset, word *x_axis, word *y_data, int flags, ema_filter_state_t *filter_state_ptr, uint channel_index, uint high_fault_bit, uint low_fault_bit, word *value_output_ptr, word *default_value_output_ptr, word *fault_status_output_ptr)`.
  The old Type A prototype was misaligned. Its `adc_index_*` / `output_raw` / `output_filtered` / `param_11-13` were really the filter state, channel, fault bits and outputs, so the 22 Type A call sites passed 16-bit-truncated pointers (`0xbd90`) and the body read the outputs as `in_stack_` slots.
- **The blocks:** each channel has a ROM / RAM block laid out as config (16 bytes) + x axis + y data, a 12-byte RAM state and an 8-byte EMA filter state (with the lookup cache word after it).
  - `sensor_channel_config_t`: `filter_coefficient` (was `config_word0`) / `default_value` / `high_threshold` / `low_threshold` / `debounce_step` / `recovery_decrement` / `debounce_limit` / `debounce_clear_threshold`.
  - `sensor_channel_state_t`: `raw_adc_counts` / `value` (the lookup result) / `debounce_count` / `held_value` (output while the channel's `sensor_channel_held_value_enable_bits_cal` bit is set; for the accelerator pedal channel 13 the J1939 input layer writes `sensor_channel13_ram.held_value` there and its source priority in `spare`) / `spare` / `lookup_input` (ratiometric reading, capped at 0x3ff).
  - `ema_filter_state_t` (`exponentialMovingAverage`'s state, 45 callers): `coefficient` points at a `filter_coefficient`, and `accumulator` is Q16.16. Each pass moves the value (65536 - coefficient) / 65536 of the way, and 0 means no filtering.
- **Outputs (renamed 2026-11-16):** `value_output_ptr` receives `sensor_channel_filtered_output[channel]`, the filtered engineering value, into the `<channel>_value` globals (were `*_raw`: `sensor_channelN_value`, `boost_pressure_sensor_value` 0x40bd8e = channel 1 intake manifold pressure, `fuel_timing_sensor_value`). `default_value_output_ptr` receives the config default into the `<channel>_default_value` globals (were `*_filtered`; e.g. `map_fuel_correction_factor` falls back to `boost_pressure_sensor_default_value`). Verified in the disassembly: the last stores are `lhzx` of the filtered output and `lhz 2(config)`. The status is 0 in range / 1 debouncing (value held) / 2 fault confirmed (default used) / 0x100 channel not enabled.
- **Blocks with named fields (typed 2026-11-16):** 24 blocks used to keep a named row inside, and those rows are now struct fields:
  - the barometric channel's default `barometric_pressure_sensor_config.default_value` (was `boost_pressure_fixed_reference`), which `cm848_calculateBoostPressure` subtracts when it uses no barometer;
  - the cruise switch validity window `cruise_switch_sensor_config.high_threshold` / `.low_threshold` (were `cruise_engage_adc_valid_upper` / `_lower`);
  - `fuel_level_sensor_channel_state.value` (was `fuel_level_unfiltered`);
  - the J1939 pedal pair on `sensor_channel13_ram`, and filter accumulators.
  - Filter states are named `<x>_filter_state` (were `*_ptr` / `*_pointer`), and the words their coefficient points at are `<x>_filter_coefficient` (36, typed `word`).
- Look for similar patterns in CM550 firmware

### Table lookups (CM848, PR #48)
- `lookupTableInterpolation(cached_axis_offset, input, x_axis, y_data, flags)` (0x55ef4) takes five register arguments (r3-r7).
- **The arguments:**
  - `x_axis` / `y_data` each start with a byte-length word.
  - `cached_axis_offset` is a word that keeps the last segment found (2 x index); the `*_interp_state` / `*_interp_index` / `engine_sync_init_state_*` globals are these words.
  - `flags`: bit 0 = signed axis, bit 1 = signed data, bit 3 = step lookup.
- **The old prototype:** its one-argument row in `function_definitions.csv` (`table_interp_args_t *`, ported from CM550) hid the input and both tables at ~310 call sites. Any table's input and data are now readable at the call.
- **2-D tables:** `cm848_dualAxisTableInterpolation(cached_axis_offsets, x_input, x_axis, y_input, y_axis, z_data, flags)` (0x566cc) takes seven register arguments (r3-r9).
  - `cached_axis_offsets` is two words (x / y segment offsets).
  - `flags`: bit 0 signed x / bit 1 signed y / bit 2 signed z / bit 3 step.
  - Its old three-argument row hid both axes and the y input; ~230 references now render.
- **Stateless lookup:** `cm848_interpolateTableWithoutCache(input, x_axis, y_data)` (0x15d2c).
- **Type B sensor channels (2026-11-15):** `sensorChannelTypeB_configInit` / `_update` pass their parameters 2-5 straight to `lookupTableInterpolation(cached_axis_offset, state_ptr[5], x_axis, y_data, flags)`. The old prototype called them `table_interp_args_t *` / "unused" table / axes / mode pointers; the struct (ported from CM550) is gone.
- **Every table is a `word[N]` array (2026-11-15, todo 039):** 920 tables (918 in `global_variables.csv`, 2 in `arrays.csv`; 564 were unnamed before the 2026-11-16 campaign, 45 now), so the calls read `lookupTableInterpolation(&cache, rpm, injection_quantity_combustion_maximum_curve_axis, ..., 0)` with no `(word *)&` cast (966 cast lines -> 75; what is left are sensor-channel state / EEPROM buffer pointers).
  - **Sizes:** an axis is 1 + (its byte-length word) / 2 words, and its breakpoints are monotonic; 1-D data is one value per axis point after its own byte-length word; a 2-D grid is nx x ny words with no header, indexed `z[(y - 1) x nx + x - 1]`. All 515 axes and 263 data headers checked out against the dumps (142 grids). The callers are the four interpolators plus the Type A and Type B sensor channels (`sensorChannelConfigInit` / `updateSensorChannelWithConfig` take the same `cached_axis_offset, x_axis, y_data, flags` in parameters 2-5; all 13 parameters are typed since the 2026-11-16 sensor-channel pass).
  - **Unnamed tables are type-only rows** (empty name): they render with Ghidra's default label `WORD_ARRAY_<address>` (cache words `WORD_<address>`), not `DAT_`, so a naming pass must look for those prefixes too. Each row's comment gives the role, size and readers.
  - **Table names (naming campaign 2026-11-16, PR #50):** 524 of the 564 unnamed tables are named (5 more on a retry after the rename waves); 40 stay `WORD_ARRAY_` because their input or output could not be traced (the evidence rule: the input and output trace to named symbols and the breakpoints fit the input's units).
    - **Grammar:** one base per lookup plus a role suffix: `<base>_axis` / `<base>_values` (1-D), `<base>_x_axis` / `<base>_y_axis` / `<base>_grid` (2-D). An axis that several lookups share is named for its input (`fuel_limit_barometric_engine_speed_x_axis`). No `_cal`: none of these tables is EEPROM-backed (the older `_cal` table names are legacy).
    - **Sensor conversion tables:** `<sensor>_linearization_*` (`coolant_temperature_linearization_axis`), or `sensor_channel<N>_linearization_*` when the sensor is not identified. N is the `channel_index` argument (the `sensor_channel_filtered_output` slot), not the number in the `cm848_sensorChannelN_*` wrapper name - those differ (`cm848_sensorChannel2_init` serves slot 4, the battery voltage). Fault bits identify a channel: ROM 0x5985a[bit] -> slot -> `obd_dtc_code_table`.
    - **Sibling families share words:** `injection_timing_main_*`, `injection_timing_pilot_offset_*`, `injection_timing_auxiliary_*`, `injection_quantity_pilot_*`, `injection_quantity_auxiliary_*` and `fuel_pressure_setpoint_*` (tables and their working variables) have one structure - a `base_map` plus `map_1`..`map_4` blended by `cm848_interpolateAlphaChiValue` (the blend table numbers are `combustion_chi_lower_map_number` / `combustion_chi_upper_map_number`, were `boost_map_index_current` / `_target`), and `coolant` (coolant x intake manifold temperature) / `ambient` (intake manifold temperature x barometric pressure) / `boost` Q12 `_factor` tables, each multiplying an rpm x fuel `_angle` / `_limit` / `_map` table into a `_component` / `_correction`.
    - **Injection events (verified 2026-11-16, todo 042):** three per cylinder, written to TPU-A **channel 5** parameter RAM slots 4 / 8 / 12 (0x304154 / 0x304158 / 0x30415c) and scheduled by the channel 6 interrupt handler: `pilot` (slot 4), `main` (slot 8), `auxiliary` (slot 12). The crank-angle order pilot -> main -> auxiliary is backed by the code: `cm848_calculateAuxiliaryInjectionPulseWidth` gives the third event an on-time only when it starts after main, and `pilot_injection_timing` = `main_injection_timing` + a positive offset. Timing counts are 0.1171875 deg (x -5 = 0.0234375 deg per TPU count; 0x7800 = 720 deg); on-times are 0.4 us per count.
      - Timing: `cm848_calculateMainInjectionTiming` (was `cm848_calculateEngineTimingData`) -> `main_injection_timing` (0x40a2e6, was `torque_limit_fault_snapshot`); `cm848_calculatePilotInjectionTimingOffset` + `cm848_calculatePilotInjectionTiming` -> `pilot_injection_timing`; `cm848_calculateAuxiliaryInjectionTiming` (was `cm848_auxiliary_boundary_condition_eval`) -> `auxiliary_injection_timing`.
      - Quantity: `cm848_calculatePilotInjectionQuantity` (was `cm848_torque_limit_state_update`) -> `pilot_injection_quantity`; `cm848_calculateAuxiliaryInjectionQuantityLimit` (was `cm848_calculateGovernorOutput`) -> `auxiliary_injection_quantity`; the cylinder's `total_injection_quantity` (was `engine_timing_reference`).
      - On-time: `cm848_calculate{Pilot,Main,Auxiliary}InjectionPulseWidth` -> `pilot_` / `main_` / `auxiliary_injection_pulse_width` (0x40b85e / 0x40b85c / 0x40b860, were `fuel_quantity_trim` / `fuel_quantity_active` / `injection_timing_active_flag`), through the on-time maps (fuel quantity x rail pressure) of the same names.
    - **Provenance:** every table's evidence, confidence (40 % medium) or skip reason is in `CM848_S90140.06_analysis/docs/table_naming_campaign_2026-11-16.csv`. Bin 10's domain words (all-speed governor friction fuel, air-fuel-control fuel limit, wastegate monitor) came from the repo's e2m name lists; their traces stand on the code.
    - **A table name is not always the table:** a loop-end pointer one past an array, or a copy source address, that lands on a table's first word renders with the table's name (`while (p < fault_derate_fuel_limit_by_engine_speed_axis)` in the fault-derate loops, `fuel_limit_by_rpm_and_demand_blend_map_4_grid + 0x7c` in `cm848_copyRomToRamBuffer`). It rendered `WORD_ARRAY_` there before.
    - The agents' rename leads for the functions and variables around these tables (many are wrong-domain) are in `work/tasks/042-table-campaign-rename-leads.md`.
  - **Lookup cache words** are `word` (1-D) / `word[2]` (2-D, or two 1-D caches side by side).
  - **Watch for:** `protection_fuel_limit_l2/l3/l4_axis_cal` used to name two tables each (the copies at 0x40853e / 0x408566 / 0x40858e are the converter lockup axes, now `..._values_axis_cal`); a scalar inside a table becomes an element (`fuel_demand_rpm_limit_low_cal[3]` was `fuel_demand_ema_lower_threshold_cal`).
  - **The audit tool:** `python3 firmware/scripts/lookup_tables.py` re-derives every table from the last build (the `.cpp` call arguments plus the call-site disassembly, sized from the dumps) and checks the CSVs. It exits 1 when a table is untyped or typed with another size, when a row sits inside a table, or when a table overlaps a struct, an `arrays.csv` row, a function or another table. It also flags a cache argument that still renders with a cast. Run it after a build that touches tables or lookup prototypes.
    - `--apply` writes the rows only for the untyped, conflict-free tables and cast cache words (a named scalar row keeps its name; a missing or junk-labelled row becomes type-only). It never deletes a row, so conflicts stay for review. Build and re-audit afterwards.
    - `--plan FILE` dumps every table with its size, roles and readers.
    - Tests: `python3 firmware/scripts/test_lookup_tables.py` (synthetic cases plus ground truth; the committed state must audit clean).
    - A new interpolator or a new sensor-channel kind needs its own `LOOKUPS` entry (C argument index and register per role).

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
- MAP sensor → `boost_pressure_sensor_value` (0x40bd8e) → `selectLoadNormalizer()` → `boost_denominator_min128` → fuel calculations
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
| 15 | 0x40bb0e | `water_in_fuel_sensor_filtered` | — | P2269; 999 < value <= 1300 = wet (PR #47) |
| 19 | 0x40bb16 | `coolant_pressure_sensor_filtered` | `fuel_quantity_mode_raw` | EFL/P1 SPN 109 |
| 20 | 0x40bb18 | `ambient_air_temperature_sensor_filtered` | `j1939_coolant_temp_raw` | AMB SPN 171; faults P0071-P0073 (2026-11-13) |
| 68 | 0x40bb78 | `fuel_level_sensor_filtered` | — | PCI 0xA4 fuel level (1/2.55 %) |
| 69 | 0x40bb7a | `battery_temperature_sensor_filtered` | `protection_oilTemp_proxy` | P0514 / P0516 / P0517; PCI 0xC0 byte 4; sets the charging voltage target |
| 71 | 0x40bb7e | `air_conditioning_pressure_sensor_filtered` | `fuel_quantity_stroke_raw` | A/C high-side pressure, P0532 / P0533; PCI 0xD2 byte 3 |
| 102 | 0x40bbbc | `governor_pressure_sensor_filtered` | `protection_throttle_position_received` | 48RE governor pressure (P1756 / P1757 / P1762) |
| 103 | 0x40bbbe | `transmission_temperature_sensor_filtered` | — | 48RE fluid temperature (P0711-P0713); PCI 0xEA |

- The "oil pressure" functions/globals that read slot 1 are **boost**: `cm848_calculateBoostPressure` (was `cm848_oilPressureDeltaCalculation`). Other `*oil_pressure*` names in the 0x407xxx/0x408xxx protection tables are still unverified — check which slot they read before trusting them.
- Real oil pressure: `cm848_processEngineOilPressure` (0x51a0a8) → `engine_oil_pressure` (0x40b538, gauge). On this truck `oil_pressure_switch_only_cal` (EEPROM 0x466) = 1, so the dash oil-pressure value is an **RPM-indexed model**, and only the low-oil-pressure switch (switch 14, line 150) can drop it to 0.
- `cm848_selectSensorValuesInUse` substitutes a low/high value per fault direction into `intake_manifold_pressure_in_use` / `coolant_temperature_in_use` / `intake_manifold_temperature_in_use` (what protection, PCI 0x10/0xC0, OBD-II and the freeze frame use).
- **Transmission fluid temperature (2026-11-12, strong inference):** slot 103 (`transmission_temperature_sensor_filtered`, 0x40bbbe) → `transmission_temperature_in_use` (coolant-model / 180 °F substitutes while its fault bits are set). Thresholds are the RE-transmission strategy: `transmission_overheat_flag` 284 °F on / 250 °F off, `hot_mode_flag` 235 / 220 °F or coolant 235 / 225 °F, ranges at 98.6 / 149 / 200 / 250 °F, cold flag below 19.4 °F; above 270 °F (`overdrive_off_set_transmission_temperature`) overdrive is forced off. PCI 0xEA byte 1 sends the temperature (°C + 40).
- **PCI 0x98 byte 1 (corrected 2026-11-13):** bit 0 = `overdrive_off_flag` (was `transmission_hot_flag`) = the cluster **O/D OFF lamp** — each press of the O/D OFF button (switch 21) toggles it, 270 °F forces it on; bit 1 = `transmission_overheat_flag` **OR** `torque_converter_slip_warning_flag` (0x40b614, was `engine_run_mode_flag`) — most likely the **TRANS TEMP lamp**; bit 4 = high range (cleared while transfer-case low range is detected). The slip warning (`cm848_monitorConverterSlipAndEngineSpeedLimit` 0x3e96c) counts up to 1000 while the transmission is in gear and engine speed is over 800 rpm above the output speed and above 1.95 x output + 1300 rpm — with no output-speed signal that is simply "engine above ~1300 rpm". Its entry gate is open on this truck (`protection_feature_flags` EEPROM 0x16e = 0x67BE has bit 0x20 in all four dumps; `transmission_type_cal` = 3). It only runs while `transmission_park_or_neutral_flag` (0x40af54, was `fuel_correction_mode_flag`) is 0, and that flag comes from the J1939 ETC2 selected gear (`cm848_j1939ProcessPgn61445Etc2` 0x22c5c, PGN 61445 SPN 524) when one arrives. **Lead for the TRANS TEMP lamp after the Allison forward:** forwarding the Allison's ETC2 tells the 48RE logic it is in gear, the 48RE output speed sensor is gone, so driving above ~1300 rpm trips the slip warning — not a temperature at all (slot 103 read 41 °F on a ~32 °F day in the dump, far from 284 °F). Confirm live: with the lamp on read RAM 0x40B614 (expect 1), 0x40AF54 (expect 0) and 0x40B409 (bit 1 set).
- **This ECM runs the 48RE (2026-11-13, transmission-control unit):** output speed from the TPU-B channel 14 period (rpm = 2 x 60e6 / 23 / period in us; P0720 substitutes vehicle_speed x the learned `diag_clear_flags_t.learned_output_speed_to_vehicle_speed_ratio`) → `transmission_output_speed_in_use` (1/8 rpm); gear 1-4 from the engine / output ratio; PCI 0x37 shift lever → `transmission_selected_gear` (J1939 SPN 524 coding); governor pressure PID on slot 102 (`cm848_controlGovernorPressureSolenoid`); converter clutch lockup (`cm848_applyConverterLockupSchedule`, the `fourth_gear_tcc_lockup_*` tables); overdrive 3-4 and the O/D OFF switch (`cm848_processOverdriveSwitchAndShift`); transfer-case low range = output speed x 256 / vehicle speed above `transfer_case_low_range_ratio_threshold` (80 rpm per mph).
### Rename waves 1-9 (2026-11-16/17, PR #50) - what the code turned out to be
Read-only agents verified each lead against the code (RAM-dump reproductions, decoded DTCs; e2m parameter blocks only
as corroboration by relative offset); every rename was proven label-only. Leads and leftovers: `work/tasks/042-*.md`.
Toolchain (gate, apply, build, label-only proof, reference refresh, checks): `scripts/rename_waves/` (README; tests
`scripts/test_rename_waves.py`). The agents' briefs, full results and applied mappings:
`CM848_S90140.06_analysis/docs/agent_notes_2026-11/`.
- **Injection:** three events per cylinder on TPU-A channel 5 (pilot / main / auxiliary), with timing, quantity and
  on-time chains (`cm848_calculate{Main,Pilot,Auxiliary}InjectionTiming`, `...InjectionQuantity(Limit)`,
  `...InjectionPulseWidth`); `main_injection_timing` was `torque_limit_fault_snapshot`.
- **Combustion manager (Cummins CBR / CBO / CBL / CBP):** `cm848_runCombustionReference` / `cm848_runOffNominalCompensation`
  / `cm848_runCombustionLimits`; `cm848_interpolateAlphaChiValue` (was `cm848_filterInputValue`, 18 users) blends the
  alpha / chi maps (`combustion_chi_lower_map_number` / `_upper_map_number`; the dump selects chi 4, the EGR-off map); the
  cylinder oxygen balance, net combustion torque and ambient air density in Bank 2. The old `fuel_demand_*` / `engine_load_*`
  / `fuel_blend_*` / `load_rate_cap` words there were these terms (the "load rate cap" is the mass charge flow limit).
- **Variable geometry turbocharger position servo (was "engine load protection", 2026-06-27, commit 7c997eb):** sensor
  channel 101 is the position feedback of a two-direction valve servo; the 0x2e17c-0x2f6a0 cluster is its key-on stop
  seek and position learning (faults 670 / 671 adjustment, 682 / 683 sensor), and wave 4's "actuator E" loop drives it
  from the boost controller's duty request. The code proves the servo; the turbocharger label is from the e2m VGT group.
  Not fitted on this truck (output unassigned, sensor at its floor).
- **Rail pressure:** `cm848_calculateFuelPressureSetpoint`, the P1223 / P0088 / P1222 / P0148 / P1221 / P0191 monitors,
  the rail-pressure-shortfall fuel limiter, per-injector diagnostic bitmaps (P0201-P0206, P2146 / P2149).
- **Others:** `torque_limit_*` = engine SPEED limits (rpm x 8); `engine_speed_limp_home_active_flag` (was
  `crank_position_valid_flag`, polarity reversed; P0336); the exhaust-brake request chain (P0478 / P0477) and the
  ERC1 / TSC1 / PGN 65213 / 65249 messages; the dual accelerator pedal (was the `cruise_speed_*` block); the charging
  regulator (P2504 / P2503) with its four state handlers (created from the pointer table at ROM 0x57730); the wastegate
  duty controller (`wastegate_duty_controller_state_t`, was `rpm_governor_state_t`); the all-speed governor droop.
- **Wave 6:** the "actuator E" loop is the VGT valve position servo itself (PID with setpoint prefilter, direction on
  logical output 71 + PWM on output channel entry 43, enable on output 72; H-bridge fault, driver over-current, motor
  thermal model and current estimate in Bank 2 - all `variable_geometry_turbocharger_*`); the `fuel_ema_coeff_*` /
  `injection_timing_compensation_*` words are the high speed governor's speed-error PID (`high_speed_governor_*`, dump:
  P 2062 + I 117 + D 0 = 2179); the engine speed limit chain (`selectEngineSpeedLimit`, the park / neutral exit
  limit, the fault derate limit) and a cruise vehicle speed limit (`cm848_calculateFaultCruiseSpeedLimit`); the
  combustion maps (20 `word[304]` grids reached through pointer words), the mass flows (`fuel_mass_flow`,
  `charge_mass_flow_filtered`, `egr_mass_flow_delayed_filtered`), `ambient_air_density`, `injection_quantity_oxygen_limit`.
- **Wave 7:** the VGT loop's twin is the EGR valve position servo (`egr_valve_*`): feedback = sensor channel 75 (the
  unidentified 0.5-4.5 V channel) through a learned zero offset (fault 718), direction on logical output 68 + PWM on
  output channel entry 39, enable on output 67, setpoint = the EGR fraction PI command - compiled in and running, but not
  fitted on this truck (no output assigned; its faults have no DTC slot). `battery_voltage_selected` /
  `battery_voltage_nominal` / `coolant_temperature_selected` (the fault-substituted channel values); the pedal fault
  engine operating mode (mode 6); the driver demand percent torque for EEC1 (SPN 512); the charge flow command chain
  (`mass_charge_flow_*_command`); the all-speed governor restore record (`engine_operating_mode_restore_*`).
- **Wave 8:** the engine speed limit droop block (e2m HSG: `engine_speed_limit_droop_*`; the 6-byte
  `engine_speed_limit_arbitration_t` is split from the `main_injection_timing_source_code` word, and the old
  `torque_limit_error_integrator` dword is the `i16` droop slope + `engine_speed_limit_ramped`); the auxiliary injection
  quantity correction / scale maps (`auxiliary_quantity_main_correction_*` / `_scale_*`, e2m HPCR_Aux_*); the main
  injection timing lookup caches (were `torque_limit_init_state_N`); the EGR delta pressure sensor autozero (channel 105,
  fault 719), the EGR cooler fouling monitor (off in this calibration) and condensation model, the charge manager
  (limiters, charge system errors, EGR / assist controller); the all-speed governor override record (e2m ASG); enums:
  `ENGINE_OPERATING_MODE` corrected from every store of 0x40b000 (0 not selected / 1 TSC1 torque / 2 TSC1 speed / 5 / 6
  pedal fault / 7 variable speed governor / 8 dual-axis fuel table / 30 restore - the old MODE_CRANK / MODE_RUN /
  MODE_SHUTDOWN contradicted the code), `EGR_VALVE_CONTROL_STATE`, `COMBUSTION_CHI_SOURCE`; `selectHighSpeedGovernorGainSet`
  is shared with CM550 0x1d392 (the same function).
- **Wave 9:** torque management (e2m `Torque_Mgmt_*`, off in this calibration - was read as a gear-down / thermal
  cluster); the turbocharger speed limiter (engine speed limit source 16) and the turbocharger speed chain (TPU-B channel 1
  sensor - not fitted on this truck - plus an estimate, chosen by `cm848_selectTurbochargerSpeedSource`; P2579 / P2580 /
  P2581); the charge manager tables (limiter derates, the charge system transform angle and cosine, the EGR / assist
  controller gains); the condensation protection model (the intake twin of the EGR cooler model, the dew points); the
  all-speed governor droop gains and negative reference slew limiter; enums `INJECTION_TIMING_INTERMEDIATE_SOURCE` and
  `MAIN_INJECTION_TIMING_SOURCE`. The whole high speed governor block is shared with CM550 (`runHighSpeedGovernorPid`,
  `presetHighSpeedGovernorIntegrator`, `initializeHighSpeedGovernorGainSet`, `selectHighSpeedGovernorGainSet`,
  `selectEngineSpeedLimit`, `initializeEngineSpeedLimitDefaults`). The boot kernel's `diagnostic_service_dispatch_table`
  (`arrays.csv`) is cut from byte[100] to byte[10]: the kernel indexes it at run time, and the application's EEPROM-mirror
  words share that RAM (`switch_input_polarity_bits_cal`, `switch_input_hardware_line_cal` and the ADC forced-reading enable
  words used to print as `diagnostic_service_dispatch_table + ...`).
- **ROM-to-RAM thunks and application data (fixed 2026-11-17, todo 043):** the `romramthunks` build stage
  (`ApplyRomToRamThunks.java`) puts a 4-byte thunk on every kernel-image address the boot ROM calls. Where the
  application keeps a named row in those 4 bytes, the thunk used to clear the data, take the data row's name (the boot
  call rendered as a call to the variable) and swallow the next word's row (0x3fb54c / 0x3fb54e printed the lockup
  state with the on-delay counter's name). There the stage now makes no thunk: each boot call gets a primary
  `CALL_OVERRIDE_UNCONDITIONAL` reference to the ROM function, so the call renders with the function's name and the
  data rows stay (10 addresses; build log `Call override: ... data <name> kept`; 8 fewer underscore warnings).
  **Since 2026-11-18 a named struct or array that covers those bytes counts too.** The build log then reads
  `data <name> (covering) kept`. Before, an instance with no label of its own at the called address got a thunk that
  split it.
  - The case that needed it: the PGN 65270 transmit descriptor at 0x3fae38 covers the boot-called RAM copy of
    `dispatchCanMessageHandlers` at 0x3fae3c.
  - Wave 11 added a second case: `sensor_channel_ratiometric_reference_channel_cal` (word[128] at 0x3fd948) covers the
    5 boot calls to the RAM copy of `cm848_forceSupervisorWatchdogReset` at 0x3fd994. The build log now reads
    21 thunks / 11 call overrides.
  - **J1939 transmit descriptors:** every one is now a 14-byte `j1939_tx_msg_t` instance (`header.can_id` /
    `header.data_length` / `data_pointer` / `data_end_pointer`): `j1939_pgn<N>_tx_message`, `j1939_dm1_tx_message`, and
    so on (30 of them).
  - The ACK message keeps `j1939_ackm_msg` and its payload is `j1939_ack_payload` (`j1939_acknowledgement_payload_t`).
  - `sendJ1939Message(&j1939_pgn65262_tx_message)` now carries no cast (it carried one at 30 call sites).
- **Wave 10 (2026-11-18, PR #51, todo 044): names checked against the DTC each function sets.** The P-code comes from
  fault n → ROM 0x5985a slot → `obd_dtc_code_table`. The monitors found, with the full table in `work/tasks/044`:
  - P0711: `cm848_checkTransmissionTemperatureSensorPerformance` / `cm848_updateTransmissionTemperatureSensorPerformanceFault`.
  - P0837: `cm848_monitorFourWheelDriveSwitch` (sensor channel 76).
  - P0720: `cm848_monitorTransmissionOutputSpeedSensor`.
  - P0573 / P0572: `cm848_monitorBrakeSwitchPairAgreement` and `cm848_deriveSecondBrakeSwitchSignal`.
  - P0461: `cm848_monitorFuelLevelLowDistance`.
  - P0602: `cm848_verifyCalibrationAndCodeCrc`.
  - P0300-P0306: `cm848_runMisfireMonitor`.
  - P0219: inside `mpc555_processColdStartMainLoop`.
  - P0106: `cm848_detectBarometricPressureSensorAboveMaximum`.
  - P0236 / P0299 / P0069: `cm848_monitorBoostPressureSensorAndUnderboost`.
  - Faults 774-777: `cm848_checkEgrDeltaPressureSensorPerformance`.
  - Fault 402: `cm848_checkFuelTemperatureSensorAfterColdSoak`.

  **P0602 guards EEPROM 0x118-0x171** with a CRC16 whose expected value is the word at EEPROM 0x482
  (`rom_crc_stored_results_cal`[0]). Any tool that writes that block must update the word as well, or P0602 sets.
  The high speed governor's ROM gain sets (codes 17-21) are `high_speed_governor_gain_set_t` instances.
- **Wave 11 (2026-11-18, PR #51, todo 044): structs, arrays and bitfields.** The agents proposed shapes. Each one was
  checked against the asm and its users before it was applied; the deferred ones are listed in `work/tasks/044`.
  - **Record arrays:**
    - `fault_definition_table` (`fault_definition_t[170]`, ROM 0x59e9a).
    - `fault_state_records_cal` (`fault_state_t[170]` at 0x3fe1ce): 7-byte records, and every user multiplies the
      fault slot by 7.
    - `fault_freeze_frame_entries_cal` (`fault_entry_t[16]`): records 8-15 are the shadow copy that the DM4 builder
      indexes as part of one array. `fault_entry_pointer_queue_cal` holds 8 pointers into it.
    - Also `fault_monitor_group_table`, `qadc_channel_dispatch_table`, the PCI message tables,
      `j1939_dm13_requester_slots` and `engine_overspeed_log_cal` (`engine_overspeed_event_t[5]`).
  - **Bitfields:**
    - `monitor_condition_bits_t`: one bit per OBD monitor, on `monitor_enabling_conditions_met` and
      `monitor_battery_voltage_error_latch`.
    - `algorithm_enable_flags_12_t`, `algorithm_enable_flags_18_t` and `algorithm_enable_flags_41_t`, with the
      e2m AENBLFLG bit names. Bits 8 / 9 of word 12 enable the two
      P0500 detectors.
    - `logical_output_request_bits_16_to_23_t`.
    - A bit that nobody proved is `reserved_bit_N`, with the guess kept in its comment.
    - **Use a bitfield only for a word that the code tests.** If the code updates the byte with `|` / `&` masks, keep
      it a byte field and put the bit meanings in its comment. Ghidra 12.1 does not fold those read-modify-writes
      into bitfield stores, so it prints them as `._8_1_` pieces of the struct. Wave 11 reverted two bitfields for
      this reason: `protection_status_flags_t.status_flags` and `protection_condition_flags_t.fault_state_flags`.
      The two bitfields had given 18 named tests but 31 pieces.
    - Check a shape change with `piece_census.py` (in the session folder), which lists each symbol whose piece count
      went up.
  - **`end_of_line_test_settings_cal`** (0x3fd938 = EEPROM 0x4b6) is the Chrysler in-plant test block. The old names
    of its bytes were `engine_sync_type_code`, `cold_start_protection_state_flags` and so on, all guesses.
    - The in-plant mode ends after `maximum_miles` × 8000 distance pulses.
    - `field_mode_register` = 5100 keeps the in-plant paths active.
  - **The sensor channel configuration in 0x3fd948-0x3fdb88** is one block, in this order:
    - `sensor_channel_ratiometric_reference_channel_cal` (word[128])
    - `sensor_channel_enable_bits_cal` (word[8])
    - an 8-word block that has no users
    - `sensor_channel_held_value_enable_bits_cal` (word[8])
    - `qadc_channel_index_table`
    - `adc_forced_reading_enable_bits_cal` (word[8])
  - **`qadc_channel_index_table` stays word[92]** (it ends at the 0x3fdb30 edge). Its users index 0-127, but words
    92-127 also hold the boot kernel's `diagnostic_service_dispatch_table` and the named slot
    `transmission_temperature_qadc_channel_cal` (word 103).
  - **A `global_variables.csv` type can now be an array of pointers, `T *[N]`.** The first use is
    `fault_entry_pointer_queue_cal` (`fault_entry_t *[8]`).
  - **One expected boot-ROM render:** `mpc555_cmfEraseBlocks` stores the erase interlock word to flash block 0x58000.
    That address is inside `qadc_channel_dispatch_table`, so the store renders as
    `qadc_channel_dispatch_table._558_4_`.
- **Fueling state enum (2026-11-19, PR #52, todo 045).** `ENGINE_OPERATING_MODE` is now `FUELING_STATE` (members
  `FUELING_STATE_*`). It is one numbering for every fueling stage. The Cummins e2m lists number them the same way:
  FSDSFLST user fueling state 1-8 / 38, FSGVFLST governed state 1-12, FSLMFLST limited state 13-41, FSFNFLST final
  state 1-41. An e2m state parameter's description ends with its value range (`~1-12`).
  - **The chain:** `engine_operating_mode` → `operating_mode_governor_output.mode_code` (adds 4, power take-off,
    e2m-derived) → `governor_fuel_demand_working_mode` (0x40b67c, was `governor_pid_integral_snapshot`; adds 9, cruise
    control) → `governor_fuel_demand_mode` (0x40a154; adds 10 vehicle speed limit, 11 low speed governor, 12 high
    speed governor).
  - **The arbitration:** `cm848_processProtectionRampControl` sets `governor_fuel_demand_mode` to the smallest of the
    user demand, the high speed governor fuel and the vehicle speed limit fuel. Then the low speed governor wins as a
    max select at or below its speed.
  - **One numbering, proved in the code:** `cm848_processProtectionSelection` writes either `governor_fuel_demand_mode`
    or `torque_derate_fuel_source_code` (13, 20, ...) into `governor_fuel_mode_arbitrated`, as CM550 does into FSLMDSST.
    The 13-41 codes have no members yet.
  - **e2m blocks that line up by offset:** block 1045 FSGVFL / FSGVFLST / LSLOFG = 0x40a152 / 0x40a154 / 0x40a156;
    block 1265 PTTHDQRP / PTTHOV / PTSLFL / PTSLFLST = 0x40af56 / 0x40af58 / 0x40af5a / 0x40af5c.
  - The dword at 0x3fb526 was two words: `governor_fuel_demand_working_mode_prev` (`sth` @ 0x40474) and
    `fuel_demand_enable_sync_flag_shadow` (`lhz` @ 0x4064c / `sth` @ 0x406b8).
  - The 37 / 38 compares and the `(int)(short)` temporary compare in `protectionRampRateControl` still render as numbers.

### Naming wave 2 (2026-11-13, PR #47)
- **48RE output-speed sensor chain re-domained** (was the `fuel_flow_*` family): `transmission_output_speed_period_microseconds` (0x40b62c, the TPU-B ch14 period) / `transmission_output_speed_numerator` (0x40b632 = 5217391 = 2 x 60e6 / 23) / `transmission_output_speed_sensor_filtered` (0x40b636, the raw-only EMA the P0720 detector watches, trips below 60 rpm) / `transmission_output_speed_sensor_unfiltered` (0x3fb508 word; the old dword was mis-sized - 0x3fb50a is a separate pointer); clamps `transmission_output_speed_maximum` 40000 (5000 rpm) / `_floor` 320 (40 rpm); `output_speed_sensor_pulses_per_revolution` = 23.
- **The three fault bitmaps are named by fault-bit range** (fault n = word n/16 bit n%16 → slot via ROM 0x5985a → `obd_dtc_code_table`): `system_status_flags_t` @0x3fe974 fields and the loose words after it are `fault_detected_bits_<first>_to_<last>`; the parallel array @0x3fe9d8 is `fault_registered_bits_*` (processed/registered copy); the snapshot array @0x3fea3c is `fault_previous_*`. So the old `*_shadow_flags` / `safety_bits_*` / `power_state_status_flags` guesses are gone - to find what a fault bit is, `peek.py` ROM 0x5985a[bit] → slot → `obd_dtc_code_table` P-code.
- **Governor-pressure mode handlers (48RE):** `cm848_selectGovernorPressureCold` (0x3148c) / `cm848_selectGovernorPressureBaseCurve` (0x31584) / `cm848_selectGovernorPressureNormal` (0x32b00) / `cm848_selectGovernorPressureWideOpenThrottle` (0x316cc) pick the target; `governor_pressure_gear{1,2}_*_target` / `governor_pressure_learned_gain_*` tables (were `protection_derate_rpm_limit_*` / `protection_status_*`).
- **Logical output-request system + the cruise servo drivers (the open hardware lead - resolved):** `cm848_setLogicalOutputRequest` / `cm848_clearLogicalOutputRequest` / `cm848_applyLogicalOutputRequests` (0x4f190) drive the 80-bit `logical_output_request_bits` (0x40c080) to physical lines; requests 19/20/21 = cruise vent / vacuum / servo-supply (P0588 / P0584 / P0596). `cm848_controlCruiseVacuumServo` (0x3fc24) with `cruise_servo_vent_duty` (0x40b65e) / `cruise_servo_vacuum_duty` (0x40b65c) is the servo PWM control (was `cm848_processEngineLoadCalculation` / `engine_load_*`). Physical line → MIOS MDASM channel is still a bench task.
- **Cruise-switch state machine named:** `cruise_switch_request` (0x3fcda2, was governor_speed_request_state_b) / `cruise_switch_button_code` (0x40bb4e, the resistor-ladder code, previously an unattributable indexed write) / `cm848_encodeCruiseControlStatusByte` (0x51ef20). ETC2 timeouts: `etc2_selected_gear_timeout` (0x40ae50) / `etc2_gear_ratio_timeout` (0x40a266).
- **Fault healing:** `cm848_removeHealedFaults` (0x534994, was initUdsServer) / `cm848_clearMilForHealedFaults` (0x53473c, was initJ1939Stack) / `cm848_latchNewlyActiveFault` (0x534b68) / the `cm848_complete*MonitorReport` family (per-monitor OBD readiness).
- **Key-on temperature rationality** (the `engine_camSync_*` family was never cam sync): `cm848_confirmIntakeManifoldTemperatureKeyOnRationality` (0x535868, P0111) and `cm848_checkSensorStuckOverDistance` (0x535d34, a per-sensor stuck-value check, not per cylinder); `temperature_rationality_*` / `battery_temperature_*` / `intake_manifold_temperature_*` state and thresholds.
- **Intake air (grid) heater** fully named (`intake_air_heater_*`, was `iat_protection_*` / `iat_solenoid_*` / `diag_iat_*`): preheat / run-up / post-heat phases, the PWM pulse control, relay drivers, and `cm848_updateIntakeAirHeater*` functions. IAT = intake air temperature, not the heater.

- **OBD-II (SAE J1979) runs on the PCI bus**, not J1939: `cm848_processPciObdRequest` (0x518680, was `j1939_dm_message_processor`) answers PCI RX[0] (68 6A) with TX[8] (48 6B) — modes 1/2/3/4/7/9 (VIN, calibration ID, CVN). Its mode-1 PIDs are a second, independent check on the slots above (PID 0x0B = intake manifold pressure in kPa, 0x05 coolant, 0x0F = intake manifold temperature, 0x04 = `engine_load_percent`, 0x11 = `accelerator_pedal_position_in_use`). `obd_dtc_code_table` (ROM 0x5b57c, 170 BCD words, one per fault slot: 0x0524 = P0524 low oil pressure, 0x0108/0x0107 MAP, 0x0113/0x0112 intake temperature...) maps fault slots to P-codes — a quick way to identify what a fault slot monitors.

### Live Data Reading (CM848 Service 0x4A)

Verified memory addresses for live ECU queries:

| Address | Variable | Scale | Verified |
|---------|----------|-------|----------|
| 0x0040B7BA | `current_engine_rpm` | × 0.125 RPM | ✓ 2026-01-31 |
| 0x0040BD8E | `boost_pressure_sensor_value` | × 0.0159 IN_HG | ✓ 2026-01-31 |
| 0x00408EF6 | `cbd_enable_flag` | 1=enabled | ✓ (prior session) |

See `CM848_S90140.06_analysis/docs/service_0x4a_protocol.md` for complete protocol documentation.

**Tools:** `tools/poll_rpm.sh` polls RPM via kuminz-cli every 0.5s.

**Polling Limits:** Minimum 50ms between Service 0x4A requests - faster polling may cause ECU to throttle responses.
