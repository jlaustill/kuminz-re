# J90280.05 Firmware Analysis (Reference Firmware)

## Quick Workflow Reference

```bash
cd ghidra

# 1. Edit CSV files in ../output/
#    - function_renames.csv, global_variables.csv, enums.csv, etc.

# 2. Apply changes via CLI
./analyze.sh import

# 3. Export updated decompilation
./analyze.sh export

# 4. Verify output
#    Check: ../output/J90280.05.ghidra.cpp

# 5. Commit changes
```

**CSV Location:** `output/`
**Ghidra Project:** `ghidra/project/J90280/`
**Apply Command:** `./analyze.sh import` then `./analyze.sh export`

---

## Full Command Reference

The `ghidra/analyze.sh` script provides all analysis commands:

```bash
./analyze.sh init       # Import firmware (no analysis)
./analyze.sh analyze    # Run Ghidra auto-analysis
./analyze.sh memmap     # Add RAM/EEPROM regions
./analyze.sh export     # Export to CSVs + decompiled C
./analyze.sh import     # Import CSV changes back into Ghidra
./analyze.sh structures # Apply structure definitions
./analyze.sh enums      # Apply enum definitions
./analyze.sh hwregs     # Apply MC68336 hardware register names
./analyze.sh labels     # Apply code labels
./analyze.sh funcparams # Apply function parameter types
./analyze.sh localvars  # Apply local variable types
./analyze.sh constants  # Apply constant definitions
./analyze.sh arrays     # Apply array definitions
./analyze.sh decompile <addr|name>  # Decompile single function
./analyze.sh full       # Run complete pipeline from scratch
./analyze.sh status     # Show project status
```

---

## Typical Workflows

### Initial Setup (from scratch)
```bash
cd ghidra
./analyze.sh full    # Runs: init -> analyze -> memmap -> import -> export
```

### After Editing CSVs
```bash
cd ghidra
./analyze.sh import  # Apply CSV changes to Ghidra
./analyze.sh export  # Regenerate decompilation
```

### Quick Decompile (single function)
```bash
cd ghidra
./analyze.sh decompile 0xa5c0            # By address
./analyze.sh decompile initFuelSystem    # By name
```

---

## CSV Files

All CSV files are in `output/`:

| File | Purpose |
|------|---------|
| `function_renames.csv` | Function names by address |
| `global_variables.csv` | Typed global variables |
| `enums.csv` | Enum definitions |
| `labels.csv` | Code labels |
| `structure_definitions.csv` | C structure definitions |
| `function_parameters.csv` | Function parameter types |
| `local_variables.csv` | Local variable names/types |
| `constants.csv` | Magic number documentation |
| `arrays.csv` | Array/buffer definitions |

---

## Reference Firmware Role

This is the **reference firmware** - other firmwares (J90350.00, etc.) bootstrap their analysis from this one:

- J90350.00 uses `relocation_map.csv` to map function addresses from J90280.05
- RAM variables are shared between firmwares (same memory layout)
- Discoveries here propagate to bootstrapped firmwares via `./analyze.sh bootstrap`

---

## General Guidelines

- Please never tell me to go try something again, this project is about reverse engineering the firmware, NOT manual testing.
- docs/common_parameters.json contains a reverse engineered set of calterm parameters from e2m files, reference it for parameter names and descriptions
  * **WARNING**: Memory addresses in common_parameters.json may be INCORRECT - they were extracted from e2m files and have not been verified against the actual firmware
  * One goal of this reverse engineering effort is to verify these addresses or identify which ones are wrong
  * When you find a verified address mapping, note it in the CSV comment field
- NEVER make assumptions, ZERO exceptions! If definitive proof isn't available, ask the user for more data!
- the playbook should only contain steps the user should take to replay. It should NOT contain findings, notes, todo's or anything else ZERO EXCEPTIONS
- always use decimal in variable and function names to keep them human readable

## CSV-Only Workflow

**NEVER make changes directly in Ghidra.** All changes MUST be made in CSV files only.

### Why This Matters:
- Direct Ghidra changes are NOT persisted to CSVs
- This creates inconsistency between the CSV source of truth and the Ghidra state
- The Ghidra project can be rebuilt from CSVs, but not vice versa

### Correct Workflow:
1. **Edit CSV files** with your discoveries (function_renames.csv, global_variables.csv, etc.)
2. **Run import** (`./analyze.sh import`) to apply CSV changes
3. **Run export** (`./analyze.sh export`) to regenerate decompilation
4. **Verify the output** in `output/J90280.05.ghidra.cpp`
5. **Only commit after verification** - ensure output looks correct

### Pre-Commit Checklist:
- [ ] All changes are in CSV files (NOT made directly in Ghidra)
- [ ] `./analyze.sh import` was run
- [ ] `./analyze.sh export` was run
- [ ] Verified `output/J90280.05.ghidra.cpp` shows expected changes
