# Firmware Analysis Guide

This directory contains reverse-engineered Cummins CM550 ECU firmware from different sources.

## Firmware Versions

| Directory | Source | Status | Purpose |
|-----------|--------|--------|---------|
| `J90280.05_analysis/` | Static binary | Reference (789 functions) | Reference firmware |
| `J90350.00_analysis/` | Live ECU dump | Active (787 functions) | Live bench ECU |

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
├── J90280.05_analysis/
│   ├── ghidra/
│   │   ├── analyze.sh            # Thin wrapper (firmware-specific config)
│   │   └── project/              # Ghidra project files
│   └── output/*.csv              # CSVs + decompilation
└── J90350.00_analysis/
    ├── ghidra/
    │   ├── analyze.sh            # Thin wrapper (firmware-specific config)
    │   └── project/              # Ghidra project files
    └── output/*.csv              # CSVs + decompilation
```

### Adding a New Firmware

To add a new firmware, just create:
1. A thin `ghidra/analyze.sh` wrapper with firmware-specific config
2. An `output/` directory with your CSVs

The thin wrapper sets variables like `FIRMWARE_NAME`, `PROJECT_NAME`, and `FIRMWARE_FILE`, then sources the shared `common.sh`.

---

## Workflow (Both Firmwares)

Both firmwares now use the same CLI workflow:

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
./analyze.sh hwregs     # Apply MC68336 hardware register names
./analyze.sh funcparams # Apply function parameter types
./analyze.sh localvars  # Apply local variable types
./analyze.sh decompile <addr|name>  # Decompile single function
./analyze.sh full       # Run complete pipeline
./analyze.sh status     # Show project status
```

### J90280.05-Specific Commands

J90280.05 is the **reference firmware** - other firmwares bootstrap from it:

- `./analyze.sh full` runs: init -> analyze -> memmap -> import -> export

### J90350.00-Specific Commands

J90350.00 was **bootstrapped from J90280.05**:

- `./analyze.sh ramvars` - Apply RAM variables from J90280.05
- `./analyze.sh bootstrap` - Apply function names via relocation map
- `./analyze.sh full` runs: init -> analyze -> memmap -> ramvars -> bootstrap -> export

---

## Cross-Firmware Analysis

J90350.00 was bootstrapped from J90280.05 using function matching:

1. **Relocation Map** (`J90350.00_analysis/output/relocation_map.csv`)
   - Maps function addresses between firmware versions
   - Status: `matched` (identical), `similar` (code differs), `not_found`

2. **Shared Data**
   - RAM variables are identical (same memory layout)
   - Hardware registers are identical (same MC68336 CPU)
   - Enums/structures can be shared

3. **Updating from Reference**
   - Discoveries in J90280.05 can be propagated to J90350.00
   - Use `./analyze.sh bootstrap` to re-apply relocation map

---

## Common CSV Files

Both firmwares use the same CSV structure in `output/`:

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
- **Verify before commit** - Check decompiled output after applying changes
- **Decimal in names** - Use decimal, not hex, in variable/function names
