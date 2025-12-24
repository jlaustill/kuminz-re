# J90280.05 Firmware Analysis (Reference Firmware)

## Quick Workflow Reference

```bash
# 1. Edit CSV files in ghidra/CM550.rep/
#    - function_renames.csv, global_variables.csv, enums.csv, etc.

# 2. Apply changes in Ghidra GUI
#    Press Ctrl+Shift+E (runs ApplyAndExport script)

# 3. Verify output
#    Check: ghidra/CM550.rep/working/J90280.05.ghidra.cpp

# 4. Commit (pre-commit hook auto-sorts CSVs)
```

**CSV Location:** `ghidra/CM550.rep/`
**Ghidra Project:** Open `ghidra/CM550.rep/` in Ghidra GUI
**Apply Command:** `Ctrl+Shift+E` in Ghidra

---

## General Guidelines

- Please never tell me to go try something again, this project is about reverse engineering the firmware, NOT manual testing.
- docs/common_parameters.json contains a reverse engineered set of calterm parameters from e2m files, reference it for parameter names and descriptions
  * **WARNING**: Memory addresses in common_parameters.json may be INCORRECT - they were extracted from e2m files and have not been verified against the actual firmware
  * One goal of this reverse engineering effort is to verify these addresses or identify which ones are wrong
  * When you find a verified address mapping, note it in the CSV comment field
- NEVER make assumptions, ZERO acceptions! If definitive proof isn't available, ask the user for more data!
- the playbook should only contain steps the user should take to replay. It should NOT contain findings, notes, todo's or anything else ZERO EXCEPTIONS
- always use decimal in variable and function names to keep them human readable

## ⚠️ CRITICAL: CSV-Only Workflow (No Direct Ghidra Changes)

**NEVER make changes directly in Ghidra using MCP tools or manual edits.** All changes MUST be made in CSV files only.

### Why This Matters:
- Direct Ghidra changes (via MCP `rename_*`, `set_*` tools) modify the database but are NOT persisted to CSVs
- This creates inconsistency between the CSV source of truth and the Ghidra state
- Direct changes can cause unexpected side effects (e.g., variable types changing to `undefined`)
- The Ghidra project can be rebuilt from CSVs, but not vice versa

### Correct Workflow:
1. **Edit CSV files** with your discoveries (function_renames.csv, global_variables.csv, etc.)
2. **Run ApplyAndExport** (`Ctrl+Shift+E`) in Ghidra to apply CSV changes
3. **Verify the output** in `ghidra/CM550.rep/working/J90280.05.ghidra.cpp`
4. **Only commit after verification** - ensure ApplyAndExport was run and output looks correct

### Pre-Commit Checklist:
- [ ] All changes are in CSV files (NOT made directly in Ghidra)
- [ ] ApplyAndExport (`Ctrl+Shift+E`) was run in Ghidra
- [ ] Verified `ghidra/CM550.rep/working/J90280.05.ghidra.cpp` shows expected changes
- [ ] No unexpected type changes (e.g., `byte *` becoming `undefined *`)