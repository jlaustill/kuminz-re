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
./analyze.sh export     # Export to CSVs + decompiled C
./analyze.sh import     # Import CSV changes back into Ghidra
./analyze.sh structures # Apply structure definitions
./analyze.sh enums      # Apply enum definitions
./analyze.sh hwregs     # Apply MC68336 hardware register names
./analyze.sh labels     # Apply code labels
./analyze.sh funcdefs   # Apply function definitions (params + return types)
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
| `function_definitions.csv` | Function parameter types and return types |
| `local_variables.csv` | Local variable names/types |

---

## General Guidelines

- All changes must go through CSV files, never directly in Ghidra
- Use `./analyze.sh status` to check current project state
- Output decompilation is at `output/J90350.00.ghidra.cpp`
- See `../CLAUDE.md` for detailed workflow order, underscore fixes, and RAM loading requirements
