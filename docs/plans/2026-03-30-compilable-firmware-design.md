# CM848D Compilable Firmware Design

**Date:** 2026-03-30
**Status:** Approved
**Goal:** Make the reverse-engineered CM848D decompiled C output compilable as a forcing function for RE quality, enabling modification/reflashing, hardware emulation, and deeper understanding.

## Motivation

Compilation acts as a quality gate: every compiler error is a gap in RE understanding that must be resolved. Smaller per-module files are easier to reason about (both for humans and AI agents), accelerating continued reverse engineering.

## Goals

1. **Recompilable for ECU** — functionally equivalent firmware that works with Insite and Calterm (preserving memory map, diagnostic service handlers, CLIP protocol behavior)
2. **Cross-architecture** — compiles for PowerPC (MPC555 original target) and ARM (forward-looking for NXP S32K-series automotive MCUs)
3. **Simulation** — run subsystems under QEMU or native execution for analysis
4. **Documentation baseline** — "it compiles" forces resolution of every ambiguous type

## Non-Goals

- Byte-exact binary reproduction of the original ROM
- Full hardware emulation (peripheral stubs are sufficient initially)
- Band-aid type substitutions to force compilation — every fix must come from genuine RE understanding via Ghidra and CSV updates

## Design

### 1. Module Classification System

**CSV Extension:** Add a `module` column to `function_renames.csv`:

```csv
address,name,module
0x00000100,mpc555_reset_vector,bootstrap
0x00500004,cm848_sensorChannel0_init,sensors
0x00532654,cm848_resetFaultCounters,faults
```

**Auto-classifier** (Python script): assigns modules based on:

1. **Name prefix** — `cm848_diagService*` -> `diagnostics`, `cm848_sensor*` -> `sensors`, etc.
2. **Address range** — Bank 2 functions (0x005xxxxx) grouped by sub-range
3. **Existing prefixes** — `mpc555_*` -> `mcu`, `vp44_*`/`hpcr_*` -> own modules
4. **Fallback** — unclassifiable functions go to `uncategorized`

**Initial module list** (expected to evolve):

| Module | Description |
|--------|-------------|
| `bootstrap` | Reset vector, init, memory copy |
| `scheduler` | 40-phase cooperative scheduler |
| `sensors` | ADC channels, sensor processing |
| `fuel_injection` | Fuel demand, timing, VP44/HPCR control |
| `protection` | Protection system, derates |
| `faults` | Fault detection, J1939 DTC management |
| `diagnostics` | CLIP/UDS service handlers |
| `j1939_comms` | CAN message tx/rx, PGN handlers |
| `eeprom` | EEPROM read/write, calibration storage |
| `mcu` | MPC555 hardware init, timer, interrupts (swappable per target) |
| `math_utils` | Interpolation, division, CRC routines |
| `uncategorized` | Everything else (shrinks over time) |

**Ghidra workflow preserved:**

- `ExportAnalysis.java` modified to read/preserve the module column on export (same pattern used for comment preservation)
- `ImportAnalysis.java` ignores the module column (it doesn't affect Ghidra state)
- CSV remains the single source of truth

### 2. Module Splitter

A Python script that runs after Ghidra export. Reads `cm848_rom.ghidra.cpp` + `function_renames.csv` (with module column) and produces:

```
output/
  cm848_rom.ghidra.cpp          # Original monolithic (preserved)
  modules/
    bootstrap.c
    scheduler.c
    sensors.c
    fuel_injection.c
    diagnostics.c
    j1939_comms.c
    faults.c
    protection.c
    eeprom.c
    mcu.c
    math_utils.c
    uncategorized.c
  firmware_types.hpp            # Existing shared header
  firmware_globals.hpp          # Existing shared header
  firmware_functions.hpp        # Existing shared header
```

Each module `.c` file includes the three shared headers and contains only the functions assigned to that module.

### 3. Build System

**CMake** with cross-compilation toolchain files:

- `powerpc-eabi-gcc` — original MPC555 target
- `aarch64-none-elf-gcc` (or `arm-none-eabi-gcc`) — ARM target
- Native `gcc`/`clang` — x64 for quick iteration (if useful alongside QEMU)

**Key build features:**

- Each module is a separate source file in the build
- Modules can be individually included/excluded from the build
- `mcu` module has per-target implementations (stub registers for non-PowerPC)
- PowerPC target gets a linker script mapping memory regions to MPC555 layout:
  - ROM: 0x00000000 (448KB)
  - RAM: 0x00400000 (40KB)
  - Hardware registers: 0x002Fxxxx, 0x003xxxxx
  - EEPROM: per MPC555 memory map
- Startup assembly (`crt0.S`) for stack init, BSS clear, `.data` copy (the one required assembly file)

### 4. Iterative Compilation Workflow

**The cycle:**

```
1. Pick a module (start with fewest dependencies)
2. Try to compile it
3. Compiler errors reveal RE gaps
4. Investigate in Ghidra, resolve the issue
5. Update CSVs
6. Ghidra import/export -> module splitter -> recompile
7. Repeat until module compiles clean
8. Move to next module
```

**Module ordering** (fewest dependencies first):

| Phase | Modules | Rationale |
|-------|---------|-----------|
| 1 | `math_utils`, `eeprom` | Pure computation, table lookups, CRC |
| 2 | `faults`, `protection` | State machines, minimal I/O |
| 3 | `scheduler`, `j1939_comms` | Core infrastructure |
| 4 | `sensors`, `fuel_injection` | Heavy hardware interaction |
| 5 | `diagnostics` | CLIP/UDS handlers, need comms |
| 6 | `mcu`, `bootstrap` | Hardware init, most platform-specific |
| 7 | `uncategorized` | Whatever remains |

**Tracking:** `modules/BUILD_STATUS.md` records per-module compilation status and remaining error counts.

### 5. Insite/Calterm Compatibility

The compiled firmware must preserve:

- **Memory map** — calibration tables and RAM variables at original addresses so e2m parameter downloads land correctly
- **Diagnostic service handlers** — CLIP services (0x4A read, 0x14/0x15 get/set, 0x16 GetAddressByParameterID) with correct request/response formats
- **J1939 PGN behavior** — same CAN message IDs and transport protocol handling

This is enforced by the linker script (address placement) and validated through RE of the diagnostic modules.

### 6. QEMU / Emulation

QEMU has MPC555 CPU core support (instruction execution). Peripheral emulation (QADC, TPU3, CAN, EEPROM controller) would need stubs. This is a future enhancement once modules compile — not part of the initial plan.

ARM emulation via QEMU supports Cortex-M profiles. Cortex-R52 (NXP S32K target) may require future QEMU updates.

## Pipeline Summary

```
CSV edits -> Ghidra import/export -> module splitter -> per-module .c files -> compile -> fix errors via RE -> repeat
```

## New Files

| File | Purpose |
|------|---------|
| `firmware/scripts/classify_modules.py` | Auto-classify functions into modules |
| `firmware/scripts/split_modules.py` | Split monolithic .cpp into per-module .c files |
| `firmware/CM848_S90140.06_analysis/output/modules/` | Per-module source files (generated) |
| `firmware/CM848_S90140.06_analysis/output/modules/BUILD_STATUS.md` | Compilation progress tracker |
| `firmware/CM848_S90140.06_analysis/CMakeLists.txt` | Build system |
| `firmware/CM848_S90140.06_analysis/cmake/` | Toolchain files for PowerPC, ARM |
| `firmware/CM848_S90140.06_analysis/mcu/mpc555/` | MPC555-specific startup + linker script |
| `firmware/CM848_S90140.06_analysis/mcu/stub/` | Stub hardware implementation for x64 |

## Modified Files

| File | Change |
|------|--------|
| `firmware/scripts/ExportAnalysis.java` | Preserve module column in function_renames.csv |
| `firmware/CM848_S90140.06_analysis/output/function_renames.csv` | Add module column |
