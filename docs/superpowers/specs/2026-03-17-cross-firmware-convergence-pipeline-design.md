# Design: Cross-Firmware Convergence Pipeline

## Goal

Create a unified, eventually-compilable representation of the Cummins ECU firmware that spans both CM550 (MC68336, VP44) and CM848D (MPC555, HPCR). The end state is a single codebase where:

- **Common code** has no prefix (shared algorithms, J1939 handling, diagnostics, governor, etc.)
- **VP44-specific code** is prefixed `vp44_`
- **HPCR-specific code** is prefixed `hpcr_`
- **MC68336-specific code** is prefixed `mc68k_`
- **MPC555-specific code** is prefixed `mpc555_`

This enables future retargeting to a modern NXP MCU supporting VP44, HPCR, or mechanical engine configurations.

## Current State

| Metric | CM550 (J90350.00) | CM848D (S90140.06) |
|--------|-------------------|---------------------|
| Total functions | 772 | 2,219 |
| Named functions | 496 | 2,218 |
| Unnamed (FUN_) | 276 | 1 |
| Global variables | 6,158 | 5,477 |
| Struct types | ~35 | ~40+ |
| Enum types | shared pool | shared pool |
| Decompiled lines | 37,480 | 96,290 |
| Shared function names | 12 | 12 |
| Shared variable names | 20 | 20 |

The decompiled `.cpp` files contain raw function bodies with no type declarations, forward declarations, or global variable definitions. Functions reference globals that are "assumed" to exist.

## Phase 1: Compilable Output Structure

### What

Modify the Ghidra export pipeline to produce a structured C output per firmware:

```
output/
├── firmware_types.hpp       # Ghidra type aliases + struct + enum definitions
├── firmware_globals.hpp     # extern declarations for all named global variables
├── firmware_functions.hpp   # Forward declarations for all functions
├── <firmware>.ghidra.cpp    # Function bodies (existing, now with #includes)
```

### firmware_types.hpp

```c
#pragma once

// Ghidra primitive type aliases
typedef unsigned char      undefined1;
typedef unsigned short     undefined2;
typedef unsigned int       undefined4;
typedef unsigned char      undefined;  // Ghidra default (unknown size)
typedef unsigned char      byte;
typedef unsigned short     ushort;
typedef unsigned int       uint;
typedef unsigned short     word;
typedef unsigned int       dword;
typedef int                bool;       // Ghidra uses int-sized bool

// Structure definitions (from structure_definitions.csv)
typedef struct {
    byte source_address;
    // ... fields from CSV
} uds_response_t;

// Enum definitions (from enums.csv)
typedef enum {
    BASIC_DELAY = 0,
    ALT_TRANSMIT = 1,
    DIVIDED_TRANSMIT = 2
} CAN_TIMER_INIT_MODE;
```

### firmware_globals.hpp

```c
#pragma once
#include "firmware_types.hpp"

// Generated from global_variables.csv
// Variables with type "undefined" use uint8_t placeholder
extern undefined current_engine_rpm;          // 0x0080c408
extern undefined2 boost_pressure_sensor_raw;  // 0x0080974a
extern undefined4 main_loop_phase_index;      // 0x00800358
// ... all ~6000 variables
```

### firmware_functions.hpp

```c
#pragma once
#include "firmware_types.hpp"

// Generated from function_renames.csv + decompiled signatures
short huffmanTreeBuilder(int param_1);
void huffmanDecompress(int param_1, undefined4 param_2);
short lookupTableInterpolation(short *param_1);
// ... all ~500-2200 functions
```

### Modified .ghidra.cpp

```c
// Ghidra C++ Decompilation Export - J90350.00 Firmware
// Generated: ...

#include "firmware_types.hpp"
#include "firmware_globals.hpp"
#include "firmware_functions.hpp"

// Function: huffmanTreeBuilder @ 0x00003640
short huffmanTreeBuilder(int param_1)
{
    // ... existing body unchanged
}
```

### Implementation

**Option A: Extend ExportAnalysis.java** to emit the three `.hpp` files during the existing `export` command. This keeps everything in one pipeline run.

**Option B: New Python/TypeScript script** that post-processes the existing `.csv` files and `.ghidra.cpp` to generate the headers. Decoupled from Ghidra — can iterate faster.

**Recommendation: Option B.** The CSVs already contain all the data. A Python script is faster to iterate on, doesn't require Ghidra headless runs, and can handle both firmwares identically. The script reads:
- `global_variables.csv` → `firmware_globals.hpp`
- `structure_definitions.csv` + `enums.csv` → `firmware_types.hpp`
- `function_renames.csv` + function signatures parsed from `.ghidra.cpp` → `firmware_functions.hpp`
- Prepends `#include` lines to a copy of `.ghidra.cpp` (or modifies in-place)

### Type Mapping

| Ghidra Type | C Type in .hpp | Notes |
|-------------|---------------|-------|
| `undefined` | `undefined` | typedef'd to `uint8_t` — placeholder |
| `undefined1` | `undefined1` | `uint8_t` |
| `undefined2` | `undefined2` | `uint16_t` |
| `undefined4` | `undefined4` | `uint32_t` |
| `byte` | `byte` | `uint8_t` |
| `short` | `short` | |
| `ushort` | `ushort` | `uint16_t` |
| `int` | `int` | |
| `uint` | `uint` | `uint32_t` |
| `word` | `word` | `uint16_t` |
| `dword` | `dword` | `uint32_t` |
| `pointer` | `void*` | |
| (empty) | `undefined` | Missing type defaults to undefined |
| struct types | as-defined | From structure_definitions.csv |

### Function Signature Extraction

Parse each function header from the `.ghidra.cpp`:
```
<return_type> <name>(<params>)
```

The decompiled output always has the signature on its own line(s) between the `//` comment and the `{`. Regex: capture everything between the `//\n\n` and the first `\n{` as the signature.

### Handling Duplicates and Conflicts

- Variables with `_` prefix (overlapping symbols) are included with a comment noting the overlap
- `switchD`/`caseD_`/`default` entries are excluded from `firmware_globals.hpp` (Ghidra artifacts)
- Hardware register names (e.g., `USIU_PLPRCR`, `Ram002fc280`) are included as-is — they'll eventually get proper `#define` mappings in `firmware_types.hpp`

---

## Phase 2: Automated Fingerprinting

### What

A Python script that compares every function in CM550 against every function in CM848D and produces a ranked list of likely matches.

### Matching Signals (combined scoring)

**Signal 1: Rare constant fingerprinting (highest weight)**
- Extract all hex/decimal constants from each function body
- Build a frequency map: how many functions use each constant in each firmware
- "Rare" = appears in fewer than 5 functions per firmware
- Two functions sharing 3+ rare constants are almost certainly the same function
- Cummins-specific values: scaling factors, PGN IDs, timer presets, table sizes

**Signal 2: Shared callee names (high weight)**
- Extract all function calls from each body
- Functions that call the same set of named (non-FUN_) callees are likely equivalent
- Weight by callee rarity: calling `lookupTableInterpolation` is weak signal (used everywhere), but calling `processThrottleSensorCalibration` is strong signal
- Exclude ultra-common callees (called by >20 functions) from matching

**Signal 3: Structural similarity (medium weight)**
- Parameter count and types
- Approximate body size (line count, within 50% tolerance)
- Control flow shape: number of if/else, loops, switch statements
- Local variable count

**Signal 4: Variable name overlap (medium weight)**
- If both functions reference the same named global variables (from the 20 already shared + any new ones), that's a matching signal

### Scoring Formula

```
score = (rare_constants_shared * 10) +
        (rare_callees_shared * 8) +
        (common_callees_shared * 2) +
        (shared_variables * 5) +
        (structural_similarity * 3)
```

Thresholds:
- **High confidence** (score >= 30): Auto-accept, generate CSV update
- **Medium confidence** (score 15-29): Present for human review with evidence
- **Low confidence** (score < 15): Discard

### Output

```
output/cross_firmware_matches.csv:
cm550_addr,cm550_name,cm848_addr,cm848_name,score,evidence,action
0x0000bcf0,initADCChannelConfiguration,0x00052abc,initQadcModule,45,"rare_const:0x1100+0x81f7 callees:initQADC",rename_cm550
0x00032c76,FUN_00032c76,0x00041234,j1939GetEngineStateCode,32,"rare_const:0xf2+0xf4 structure:similar",name_cm550
```

### Script Location

`firmware/scripts/cross_firmware_fingerprint.py` — operates on the `.ghidra.cpp` files directly, no Ghidra dependency.

---

## Phase 3: Iterative Bootstrapping

### What

After applying Phase 2 matches, the decompiled output has more shared names. Re-running the fingerprint script finds additional matches because:

1. **Call graph expansion**: Previously, CM550's `FUN_0000b688` called `FUN_0000b7bc`. After Phase 2 names both of them, the next iteration sees that CM550's `someParentFunction` calls `initFuelPump` and `readThrottleSensor` — matching it to a CM848 function that calls the same named functions.

2. **Variable name propagation**: Each round of matched functions reveals variable names that can be cross-referenced.

### Process

```
Round 0: 12 shared function names, 20 shared variable names
         ↓ Run fingerprint script
Round 1: Apply high-confidence matches, re-export both firmwares
         ↓ Run fingerprint script again
Round 2: More matches found (call graph is richer)
         ↓ Apply, re-export
Round N: Diminishing returns → stop
```

### Convergence Criteria

Stop iterating when a round produces fewer than 5 new high-confidence matches or when all high-confidence matches fall below the threshold.

### Automation

```bash
# Proposed workflow
cd firmware/scripts
python3 cross_firmware_fingerprint.py          # Generate matches
python3 apply_cross_firmware_matches.py --dry-run  # Preview CSV changes
python3 apply_cross_firmware_matches.py            # Apply to both CSVs

# Re-export both firmwares
cd ../CM550_J90350.00_analysis/ghidra && ./analyze.sh import && ./analyze.sh export
cd ../../CM848_S90140.06_analysis/ghidra && ./analyze.sh import && ./analyze.sh export

# Re-run fingerprinting (next round)
cd ../../scripts
python3 cross_firmware_fingerprint.py
```

---

## Phase 4: Prefix Classification

### What

After convergence plateaus, classify all remaining unmatched functions and variables with architecture/fuel-system prefixes.

### Classification Rules

| Condition | Prefix | Example |
|-----------|--------|---------|
| CM550-only, VP44-related | `vp44_` | `vp44_canMessageDispatcher` |
| CM848-only, HPCR-related | `hpcr_` | `hpcr_calculateRailPressure` |
| CM550-only, MC68336 hardware | `mc68k_` | `mc68k_tpuChannelInit` |
| CM848-only, MPC555 hardware | `mpc555_` | `mpc555_qadcConversionTrigger` |
| CM550-only, generic/unknown | `vp44_` | Default for CM550-unique code |
| CM848-only, generic/unknown | `hpcr_` | Default for CM848-unique code |
| Bank 2 utility functions | (no prefix) | These are shared utilities, just in a different flash bank |

### Detection Heuristics

**VP44 indicators:** References to VP44 CAN messages (PGN patterns), injection pump timing, VP44 fault codes
**HPCR indicators:** References to rail pressure, injector pulse width, cylinder balance
**MC68336 indicators:** References to TPU, QSM, SIM registers at 0xFFxxxx
**MPC555 indicators:** References to USIU, QADC, TouCAN registers at 0x002xxxxx/0x003xxxxx

### Process

1. Script analyzes each unmatched function's body for hardware register references and fuel-system keywords
2. Outputs a classification CSV for human review
3. After review, applies prefix renames to both firmware CSVs
4. Final re-export produces the cleanly-prefixed codebase

---

## Expected Outcomes

| Phase | Estimated New Matches | Time |
|-------|----------------------|------|
| Phase 1 (compilable output) | 0 (infrastructure) | 1 session |
| Phase 2 (fingerprinting) | 50-150 function pairs | 1-2 sessions |
| Phase 3 (bootstrapping) | 50-100 more per round, 2-4 rounds | 2-3 sessions |
| Phase 4 (prefix classification) | 0 (classification, not matching) | 1-2 sessions |

**End state estimate:**
- 200-400 shared function names (from current 12)
- 100-300 shared variable names (from current 20)
- All remaining functions prefixed by fuel system or MCU
- Both `.cpp` files compilable with their respective `.hpp` headers

## Files Created/Modified

### New Files
| File | Purpose |
|------|---------|
| `firmware/scripts/generate_headers.py` | Phase 1: Generate .hpp files from CSVs |
| `firmware/scripts/cross_firmware_fingerprint.py` | Phase 2-3: Automated matching |
| `firmware/scripts/apply_cross_firmware_matches.py` | Phase 2-3: Apply matches to CSVs |
| `firmware/scripts/classify_unmatched.py` | Phase 4: Prefix classification |
| `output/firmware_types.hpp` | Per-firmware type definitions |
| `output/firmware_globals.hpp` | Per-firmware global declarations |
| `output/firmware_functions.hpp` | Per-firmware function forward decls |
| `output/cross_firmware_matches.csv` | Match results (in firmware/ root) |

### Modified Files
| File | Change |
|------|--------|
| `output/<firmware>.ghidra.cpp` | Add `#include` preamble |
| `output/function_renames.csv` | Converged names (phases 2-4) |
| `output/global_variables.csv` | Converged names (phases 2-4) |
| `firmware/feature_comparison.csv` | Filled in from match data |

## Risks

- **False positive matches**: Mitigated by confidence scoring and human review for medium-confidence matches
- **Ghidra decompiler quirks**: MC68336 and PowerPC decompilers produce different idioms for the same patterns. Constants are reliable; structural features less so.
- **Address constants as false fingerprints**: Constants in the 0x10000-0x30000 range could be either algorithm constants or relocated addresses. The script must filter aggressively.
- **Type incompatibility**: The `.hpp` won't compile initially due to `undefined` types and missing pointer information. This is expected and will resolve as typing progresses.
