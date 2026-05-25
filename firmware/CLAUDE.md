# Firmware Analysis Guide

This directory contains reverse-engineered Cummins ECU firmware from different generations.

## Firmware Versions

| Directory | Source | ECU | Status | Purpose |
|-----------|--------|-----|--------|---------|
| `CM550_J90350.00_analysis/` | Live ECU dump (bench) | CM550 | Active | Full ROM + RAM extraction |
| `CM848_S90140.06_analysis/` | 2004.5 Dodge 5.9L | CM848D | Active | PowerPC MPC555 analysis |

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

`copyCalibrationToRam()` copies ROM 0x3C30-0x7F60 (17KB) to RAM 0x3F9800-0x3FDB30 at boot. ~50 functions execute from RAM for MPC555 performance. Formula: `ROM_addr = 0x3C30 + (RAM_addr - 0x3F9800)`.

Functions at `0x003Fxxxx` in decompilation (e.g. `BYTE_003fae3c()`) are ROM functions running from RAM — Ghidra already has them decompiled at their ROM source addresses. The RAM dump has these regions overwritten by CAN bus data at runtime; use the ROM binary to find the original code.

Key RAM-executed functions called from `mainLoopIteration`:
- `dispatchCanMessageHandlers` (ROM 0x526C → RAM 0x3FAE3C)
- `processJ1939QueueStatus` (ROM 0x64C4 → RAM 0x3FC094)

### CM848 ECU Version Info

| Location | Value | Description |
|----------|-------|-------------|
| EEPROM 0x0130 | V11.46.06 | Calibration version |
| EEPROM 0x0046 | 1504 2RSAO | Calibration ID |
| EEPROM 0x0217 | CC | Module ID (CM848) |
| EEPROM 0x0002 | ABCDEF | Security key |
| ROM 0x010C | 100902 | Build date |

**Note:** E2M file S90140.12 is V11.20.13.16 - different from ECU's V11.46.06. Use live dumps for analysis.

---

## Workflow

> **CM848 Pipeline Note:** CM848 has dual-bank Flash (ROM + Flash2). Flash2 must be
> loaded (`memmap`) and entry points seeded (`import`) *before* Ghidra auto-analysis
> runs — otherwise cross-bank `bl` calls into Flash2 produce fabricated decompilation.
> CM848's `analyze.sh full` uses: `init → memmap → import → analyze → export`.
> CM550's `analyze.sh full` uses: `init → analyze → memmap → import → export`.

```bash
cd [firmware]_analysis/ghidra

# Edit CSV files in ../output/
./analyze.sh import     # Apply CSV changes to Ghidra
./analyze.sh export     # Regenerate decompilation

# Verify: ../output/[firmware].ghidra.cpp
```

### Available Commands

```bash
./analyze.sh init       # Import firmware (no analysis)
./analyze.sh analyze    # Run Ghidra auto-analysis
./analyze.sh memmap     # Add RAM/EEPROM regions
./analyze.sh import     # Apply CSV changes
./analyze.sh export     # Export CSVs + decompilation
./analyze.sh structures # Apply structure definitions
./analyze.sh enums      # Apply enum definitions
./analyze.sh labels     # Apply code labels
./analyze.sh constants  # Apply constant definitions
./analyze.sh arrays     # Apply array definitions
./analyze.sh hwregs     # Apply hardware register names
./analyze.sh funcparams # Apply function parameter types
./analyze.sh localvars  # Apply local variable types
./analyze.sh decompile <addr|name>  # Decompile single function
./analyze.sh full       # Run complete pipeline
./analyze.sh status     # Show project status
```

---

## Common CSV Files

All firmwares use the same CSV structure in `output/`:

**Comment lines:** Lines starting with `#` are preserved through import/export cycles. Use them to document address mappings, function relationships, or other context.

| File | Purpose |
|------|---------|
| `function_renames.csv` | Function names by address |
| `global_variables.csv` | Typed global variables |
| `enums.csv` | Enum definitions for magic numbers |
| `labels.csv` | Code labels for control flow |
| `structure_definitions.csv` | C structure definitions |
| `constants.csv` | Magic number documentation |
| `arrays.csv` | Array/buffer definitions |
| `function_parameters.csv` | Function parameter types |
| `local_variables.csv` | Local variable names/types |

---

## Guidelines

- **CSV is source of truth** - Never edit Ghidra directly
- **Export overwrites CSVs** - `./analyze.sh export` regenerates CSVs from Ghidra, overwriting local edits. Edit CSVs, run `import`, then `export` only to get updated decompilation.
- **Verify before commit** - Check decompiled output after applying changes
- **Decimal in names** - Use decimal, not hex, in variable/function names
- **Function must exist in Ghidra** - CSV renames only work for addresses Ghidra recognizes as functions

### Fixing Underscore-Prefixed Variables

Variables with `_` prefix (e.g., `_speed_error_filtered`) indicate a wider memory access than the declared type:
- **Cause (simple)**: Variable declared as `byte`/`word` but Ghidra sees a wider load (`lhz`/`lwz`). Fix by widening the type to match the actual access width.
- **Cause (persistent — PowerPC bulk-clear)**: `stw r0, offset(r13)` stores 4 bytes in one instruction, zeroing 4 adjacent byte-typed variables at once. Ghidra emits `_` prefix for each because the 4-byte write exceeds every individual byte's declared size. Widening individual types does not fix this.
- **Fix for bulk-clear pattern**: Define a struct that groups those 4 adjacent bytes in `structure_definitions.csv`. Once Ghidra sees a single 4-byte struct instead of 4 separate bytes, the underscore disappears.

### RAM Must Be Loaded for Structure Application

Structures at RAM addresses (0x003FAxxxx - 0x0043xxxx) require RAM to be loaded:
```bash
./analyze.sh memmap      # Loads RAM dump at 0x003FA000 (279KB)
./analyze.sh structures  # Now applies 29+ structures instead of 1
```

### Proper Workflow Order (Critical)

Export regenerates CSVs from Ghidra, overwriting manual edits not applied to Ghidra:
```bash
# 1. Edit CSV files manually
# 2. Apply to Ghidra:
./analyze.sh import      # Apply names + types (vartypes behavior is built into import)
./analyze.sh structures  # Apply structures
# 3. Export (regenerates CSVs + decompilation):
./analyze.sh export
# 4. Commit
```

**Warning**: Running `export` before `import` loses your CSV edits!

### global_variables.csv Maintenance

Periodically clean garbage entries from `global_variables.csv`:
- **Switch tables** (`switchD`, `caseD_*`, `default`) - Ghidra jump table artifacts, not real variables
- **SUB_ entries** - Invalid addresses outside ROM/Flash ranges (e.g., 0x8a670005)
- **mpc555_registers.csv duplicates** - Untyped entries already defined in hardware register CSV

Use Python CSV module to batch-categorize and clean (see session history for script pattern).

---

## Common Code Patterns

### Sensor Channel Architecture
- Sensor channels use paired functions: `sensorChannelN_init()` calls a config init function, `sensorChannelN_process()` calls the update function
- Both functions take identical 13 parameters (calibration pointers, RAM buffers, ADC indices, output variables)
- CM848: `sensorChannelConfigInit` (0x00500234) + `updateSensorChannelWithConfig` (0x00500a4c)
- Two sensor types: Type A uses `sensorChannelConfigInit`, Type B uses `sensorChannelInit_typeB`
- Look for similar patterns in CM550 firmware

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
