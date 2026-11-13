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
025 [ ] [firmware] CM848D next naming wave — the 2026-11-13 wave's open questions + skeptic "missed" lists (work/tasks/025-cm848-naming-wave-followups.md) (PR #46)
024 [ ] [firmware/truck] CM848D TRANS TEMP lamp — likely the 48RE converter-slip warning (PCI 0x98 bit 1 = overheat OR slip), armed since the Allison ETC2 forward clears the park/neutral flag; with the lamp on live-read 0x40B614 (slip flag, expect 1) / 0x40AF54 (park-neutral, expect 0) / 0x40B409 (bit 1) / slot 103 0x40BBBE (PR #46)
