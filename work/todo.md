# Project Tasks

## Status Legend
- [ ] Todo
- [>] In Progress
- [?] Testing
- [X] Done

## Tasks

001 [>] [calterm-crc] Resolve CRC paradox - why legacy files have impossible CRC values
002 [X] [e2m-analysis] Decode e2m file format (100% complete - 521 base addresses mapped)
003 [X] [kuminz-cli] CLIP protocol implementation & session management (Service 0x4A dumps + CLIP auth working)
004 [X] [e2m-analysis] Validate e2m addresses against firmware memory maps (94.7% validated with extended RAM)
005 [X] [firmware] Document parameter lookup system (param_address_calc, param_lookup_1/2/3)
006 [ ] [e2m-db] Add parameter name extraction to importer
007 [ ] [firmware] Verify enum definitions via ApplyAndExport
008 [ ] [calterm-crc] Complete remaining 2 native DLL annotations (ToolLicensing, ErrorHandling)
009 [X] [insite9] Establish Insite reverse engineering process (decompilation 100% - 358 DLLs, 294MB)
010 [X] [firmware] Document ECU versions table (hardware, firmware, protocols) - protocol matrix added
011 [X] [firmware] RAM dump correlation - use 37KB RAM dump to enhance firmware RE
012 [X] [firmware] First live ECU firmware extraction - J90350.00 from CM550 ISB 195hp (2024-12-16)
013 [X] [firmware] Compare J90350.00 vs J90280.05 - identify shared code and calibration differences (J90280 removed from repo)
014 [X] [firmware] Import J90350.00 into Ghidra with MC68336 memory map
015 [X] [firmware] Cross-reference function names to J90350.00 (originally from J90280.05, now removed)
016 [X] [clip-core] CLIP command execution - GetDataByAddress (0x14) and SetDataByAddress (0x15) - already implemented
017 [X] [firmware] Cross-firmware name convergence - align CM550 and CM848D symbol names for side-by-side comparison (41 shared names, 68 renames)
018 [X] [firmware] Name CM848D Bank 2 utility functions using CM550 equivalents (844 functions complete)
019 [X] [firmware] Cross-firmware RAM variable naming campaign - CM550 Tier 1+2 (455 named), CM848 (8 named), 20 cross-firmware matches validated
020 [ ] [all] Test coverage implementation - Catch2 for C++, Vitest for TypeScript, 6 phases by priority
021 [?] [firmware/kuminz-cli] CM848D J1939 broadcast trigger - EF00 0x0a→0x07 (or 0x16 alone) — needs live truck test to verify broadcasts start
022 [>] [firmware/oct] CM848D J1939 drive-by-wire — trace j1939_governor_config_flags gate, enable TSC1 speed control
023 [?] [firmware/tools] CM848D odometer restore — update_odometer.sh RETARGETED (f2fc982) to lifetime 0x8ea + trip 0x19a6 + 8-mile ring 0x19ce (0xBD8 = DTC list, no longer written); --from-dash reads RAM 0x40B471; checksum self-heals at engine start. REMAINING: bench-test the EEPROM write + verify PGN 65248 reports it (PR #46)
027 [ ] [firmware] CM848D naming wave 3 — wave-2 open questions + skeptic "missed" lists (work/tasks/027-cm848-naming-wave-2-followups.md) (PR #47)
030 [>] [firmware] CM848D registration-table sweep — 92 names/cross-refs applied (PGN / scheduler-was-boot-SCI / QSPI / SCI / interrupt tables); the indirect-dispatch handlers now carry "dispatched via <table>" cross-refs (work/tasks/026, PR #47)
031 [X] [firmware] CM848D boot-delay callers renamed — cm848_waitForBusStable → cm848_waitForStableIgnitionKeyOn (0x24a0; 5 consecutive key-on samples of mios_mdasm30.SCRD bit 15) and mpc555_checkBusHardwareStatus → mpc555_areBootModeStrapPinsHigh (0x23b8; four QADC port pins - all high keeps the ECM in the boot service loop); register fixes MIOS_MCPSMSCR → mios_mdasm30 / mios_mdasm31 and qadc_b_mcr → QADC64A_MCR (PR #48)
032 [ ] [firmware] CM848D MIOS1 register map — 0x3060e0 (MIOS_MIOS1TPCR / MIOS_MPWMSM4_*) = MDASM28 and 0x3060e8 (MIOS_MPWMSM5_*) = MDASM29 (proved by the cm848_miosChannel28/29* wrappers); also check the rest of the 0x306080-0x3060df map and MMCSM6 in mpc555_registers.csv (0x306020 there - the firmware uses 0x306030) against the MPC555 MIOS1 map (submodule n at 0x306000 + 8n)
029 [ ] [firmware] CM848D sweep held proposals — 25 catch-all re-domainings + Low guesses held for focused review (output-channel / battery-voltage-regulator / USIU) (work/tasks/029, PR #47)
028 [?] [firmware/tools] CM848D engine hours — RESOLVED: EEPROM 0x30 is NOT wiped by HPT (no restore needed), 0x1C00 is static/dead; tools/read_engine_hours.sh reads 0x30 and prints the OCT seed (engineHoursTruckLifetime=<hrs>). REMAINING: one timed key cycle to confirm the 0.200/0.205/0.667 s/count scale, then --calibrate + seed OCT (PR #47)
026 [?] [firmware] CM848D naming wave 2 — 196 names applied + verified (output speed / fault arrays / governor pressure / fault healing / cold-start temp / cruise servo drivers / intake air heater); commit pending push (work/tasks/026, PR #47)
025 [X] [firmware] CM848D next-wave input captured — the 2026-11-13 wave's open questions + skeptic "missed" lists (work/tasks/025-cm848-naming-wave-followups.md) (PR #46)
024 [ ] [firmware/truck] CM848D TRANS TEMP lamp — likely the 48RE converter-slip warning (PCI 0x98 bit 1 = overheat OR slip), armed since the Allison ETC2 forward clears the park/neutral flag; with the lamp on live-read 0x40B614 (slip flag, expect 1) / 0x40AF54 (park-neutral, expect 0) / 0x40B409 (bit 1) / slot 103 0x40BBBE (PR #46)
