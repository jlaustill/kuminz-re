# Firmware Analysis Guide

This directory contains reverse-engineered Cummins CM550 ECU firmware from different sources.

## Firmware Versions

| Directory | Source | Status | Purpose |
|-----------|--------|--------|---------|
| `J90280.05_analysis/` | Static binary | Complete (793 functions) | Reference firmware |
| `J90350.00_analysis/` | Live ECU dump | Active (489 functions) | Live bench ECU |

---

## Workflow Comparison

| Aspect | J90280.05 | J90350.00 |
|--------|-----------|-----------|
| **CSV Location** | `ghidra/CM550.rep/` | `output/` |
| **Apply Command** | `Ctrl+Shift+E` in Ghidra GUI | `./analyze.sh import` |
| **Export Command** | (same as apply) | `./analyze.sh export` |
| **Output File** | `working/J90280.05.ghidra.cpp` | `output/J90350.00.ghidra.cpp` |
| **Ghidra Mode** | GUI with MasterAnalysisSetup | Headless CLI |

---

## Quick Reference

### J90280.05 (GUI Workflow)
```bash
# Edit: ghidra/CM550.rep/*.csv
# Apply: Ctrl+Shift+E in Ghidra
# Verify: ghidra/CM550.rep/working/J90280.05.ghidra.cpp
```

### J90350.00 (CLI Workflow)
```bash
# Edit: output/*.csv
cd ghidra && ./analyze.sh import && ./analyze.sh export
# Verify: output/J90350.00.ghidra.cpp
```

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

Both firmwares use the same CSV structure:

| File | Purpose |
|------|---------|
| `function_renames.csv` | Function names by address |
| `global_variables.csv` | Typed global variables |
| `enums.csv` | Enum definitions for magic numbers |
| `labels.csv` | Code labels for control flow |
| `structure_definitions.csv` | C structure definitions |

---

## Guidelines

- **CSV is source of truth** - Never edit Ghidra directly
- **Verify before commit** - Check decompiled output after applying changes
- **Decimal in names** - Use decimal, not hex, in variable/function names
