# J90350.00 Firmware Analysis (Live ECU Extraction)

## Quick Workflow Reference

```bash
# 1. Edit CSV files in output/
#    - function_renames.csv, global_variables.csv, enums.csv, etc.

# 2. Apply changes via CLI
cd ghidra
./analyze.sh import

# 3. Export updated decompilation
./analyze.sh export

# 4. Verify output
#    Check: output/J90350.00.ghidra.cpp

# 5. Commit changes
```

**CSV Location:** `output/`
**Ghidra Project:** `ghidra/project/J90350/`
**Apply Command:** `./analyze.sh import` then `./analyze.sh export`

---

## Full Command Reference

The `ghidra/analyze.sh` script provides all analysis commands:

```bash
./analyze.sh init       # Import firmware (no analysis)
./analyze.sh analyze    # Run Ghidra auto-analysis
./analyze.sh memmap     # Add RAM/EEPROM regions from live dumps
./analyze.sh ramvars    # Apply 5,227 RAM variables from J90280.05
./analyze.sh bootstrap  # Apply function names via relocation map
./analyze.sh export     # Export to CSVs + decompiled C
./analyze.sh import     # Import CSV changes back into Ghidra
./analyze.sh structures # Apply structure definitions
./analyze.sh enums      # Apply enum definitions
./analyze.sh hwregs     # Apply MC68336 hardware register names
./analyze.sh labels     # Apply code labels
./analyze.sh funcparams # Apply function parameter types
./analyze.sh localvars  # Apply local variable types
./analyze.sh decompile <addr|name>  # Decompile single function
./analyze.sh full       # Run complete pipeline from scratch
./analyze.sh status     # Show project status
```

---

## Typical Workflows

### Initial Setup (from scratch)
```bash
cd ghidra
./analyze.sh full    # Runs: init -> analyze -> memmap -> ramvars -> bootstrap -> export
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
./analyze.sh decompile 0x22e5e           # By address
./analyze.sh decompile sendJ1939MultiFrame  # By name
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
| `relocation_map.csv` | Maps J90280.05 functions to J90350.00 addresses |

---

## Cross-Reference with J90280.05

This firmware was bootstrapped from J90280.05 (the reference firmware):

- **Relocation Map:** `output/relocation_map.csv` maps function addresses between versions
- **Shared Enums:** Falls back to J90280.05's enums.csv if not present locally
- **RAM Variables:** Identical between versions (same memory layout)

To update from J90280.05 discoveries:
```bash
./analyze.sh ramvars   # Re-apply RAM variables
./analyze.sh enums     # Re-apply enum definitions
./analyze.sh bootstrap # Re-apply function names via relocation map
```

---

## General Guidelines

- All changes must go through CSV files, never directly in Ghidra
- Use `./analyze.sh status` to check current project state
- Output decompilation is at `output/J90350.00.ghidra.cpp`
