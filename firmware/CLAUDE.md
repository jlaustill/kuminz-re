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
- **CM848:** `init → memmap → enums → import → analyze → deletions → import → callingconv → hwregs → labels → constants → arrays → export`
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
ROM-to-RAM thunking (`func_0x003fxxxx` → ROM source) is a **deferred** build step (the map is
`ROM = 0x3C30 + (RAM − 0x3F9800)`; re-add it as a deterministic stage when needed).

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
| `deleted_functions.csv` | Addresses of spurious functions to remove after `analyze` (the deletion delta) |
| `function_definitions.csv` | Function parameter types and return types |
| `local_variables.csv` | Local variable names/types |

---

## Guidelines

- **CSV is source of truth** - Never edit Ghidra directly
- **The `.rep` is disposable; `build` is the only producer** — every `build` starts from a fresh binary (`init -overwrite`) and applies every CSV. There is no persistent state to drift, and no standalone `import`/`export`/`memmap`/`analyze` to half-mutate it. (Historically, re-running `memmap` on a populated `.rep` wiped Bank-2/RAM analysis — that footgun no longer exists.)
- **`function_renames.csv` + `global_variables.csv` are build OUTPUTS** — `build`'s export regenerates them from the `.rep` each run (reformatting, dropping non-curated `DAT_`/`uRam` names). Edit them to rename/retype, but expect `build` to rewrite them; the other CSVs (enums, structures, labels, constants, arrays, function_definitions, local_variables, deleted_functions) are hand-maintained INPUTS that `build` never overwrites.
- **Verify before commit** - Check decompiled output after applying changes
- **Decimal in names** - Use decimal, not hex, in variable/function names
- **Major concept first in names** - prefix with the dominant domain noun first: `rpm_governor_offset_*` not `governor_offset_rpm_*`; `fuel_demand_*` not `demand_fuel_*`
- **Function must exist in Ghidra** - CSV renames only work for addresses Ghidra recognizes as functions
- **import force-creates functions** — `function_renames.csv` entries at addresses with no function get disassembled + created (not just renamed). This reproduces Bank2 (force-analyzed) functions; their names ARE in `function_renames.csv` (~567 entries), not a side file.
- **funcdefs / r4-return gotcha** — declare the FULL prototype (return + all param rows); a return-only row is auto-handled (import preserves Ghidra-recovered params, warns on count mismatch) but yields generic `param_N` names. NEVER declare a return for an r4-return function whose r4 is NOT a parameter (no-arg/globals-only helpers like diag handlers) — the decompiler then assumes r4 is preserved and swaps the wrong operand at call sites. To undo a bad prototype, fix/remove the row in `function_definitions.csv` and rebuild.
- **Reproducibility: PROVEN** — `build` is a deterministic fixed point. Two independent `build`s from a fresh binary produce byte-identical `.cpp` + CSVs (`verify` asserts this). Auto-analysis is deterministic; `import` force-creates functions from `function_renames.csv`; `deleted_functions.csv` removes spurious splits; the new baseline preserves all curated names and *surfaces* 90 real functions the old hand-curated baseline was missing (func_0x 75→29). The apparent "~2965 extra DAT_" gap from earlier was a measurement artifact — unnamed RAM vars render `DAT_` (initialized RAM) vs `uRam` (uninitialized); both are default names, no curation lost.
- **deleted_functions.csv** — vet candidates with `classifyfuncs` before adding: an entry with incoming CALL refs is a REAL function (do NOT delete — add to `function_renames.csv` instead); only no-ref / jump-only entries are true mid-function splits. The bootstrap found 39 "spurious" Bank-2 candidates were actually real functions the campaign missed.
- **Type width must match hardware access** - `bool` (1B), `byte` (1B), `word` (2B), `dword` (4B) must match the actual load instruction (`lbz`=1B, `lhz`=2B, `lwz`=4B). Wrong width is silently reverted to `word` on export. This also prevents enum substitution for byte-width variables.
- **Plate comments round-trip via function_renames.csv** - 3rd column is preserved through import/export since 2026-05-25 fix. If export drops a plate comment, it indicates `ExportAnalysis.java` failed to compile (check for missing imports).
- **Enum round-trip order** — when assigning a new enum type name to variables, run `./analyze.sh enums` BEFORE `./analyze.sh import`. Import silently skips type names not yet in Ghidra's DTM.
- **Named types preserved through export (since 2026-05-26)** — `ExportAnalysis.java` reads existing CSV before overwriting and applies priority: named Ghidra type > named CSV type > primitive Ghidra type. Enum types set via CSV survive `./analyze.sh export` cycles.
- **Ghidra masked-comparison limitation** — symbolic enum names appear for `var == ENUM_VALUE` but NOT for `(var & MASK) == VALUE`. Bitfield structs and enum types don't help when all downstream uses are masked comparisons — document with a `#` comment block in `global_variables.csv` instead.

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
4. **Apply** → `./analyze.sh import` → `./analyze.sh export`
5. **Check `_` prefix remaining**: `grep -oE '\b_[a-z][a-z0-9_]{3,}\b' cm848_rom.ghidra.cpp | sort | uniq -c | sort -rn`
6. **Widen types** for new `_` prefix: check gap to next named var in CSV; gap≥2 → widen to `word`, gap≥4 → widen to `dword`

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
