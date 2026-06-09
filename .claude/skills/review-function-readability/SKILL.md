---
name: review-function-readability
description: Use when a decompiled Cummins firmware function has poorly named symbols (globals, called functions, locals) and you want to rename them holistically so the function reads like a book. Takes a function address/name, analyzes ALL symbols in context, proposes coherent names, applies CSV edits, builds, and creates a commit + PR. Covers CM848 and CM550.
---

# Review Function Readability (CM848 / CM550)

## Overview

Take a **function** (by address or name) and make it **read like a book** by renaming all its poorly named symbols — globals, called functions, and locals — with names that tell a coherent story about what the function does.

This is the **end-to-end workflow**: investigate → propose → apply → build → commit → PR. Unlike `investigate-firmware-symbol` (read-only, one symbol) or `running-naming-campaigns` (bulk DAT_ naming), this skill focuses on **coherent readability** of a single function.

**The key insight:** A symbol's best name often only becomes clear when you understand the function's PURPOSE. `sensor_fault_mode_active` sounds reasonable in isolation, but when you see the function dispatches EEPROM writes, `eeprom_write_request_type` is obviously correct.

## Input

- A function address (e.g., `0x000038f4`) or name (e.g., `cm848_diagRequestTypeDispatcher`)
- The firmware: CM848 or CM550

## The workflow

### Phase 1: Extract and understand

1. **Decompile the function** — read it from the `.cpp` output, or use `./analyze.sh decompile <addr>` if project exists.

2. **List all symbols to review:**
   - Global variables used (named or `DAT_`)
   - Functions called (named or `FUN_`)
   - Local variables with generic names (`uVar1`, `in_register_*`, etc.)
   - Magic numbers that could be enums

3. **Understand the function's purpose** — read the code flow, understand what it DOES, not what the current names SAY. This is the critical step that distinguishes this skill from mechanical renaming.

### Phase 2: Investigate each symbol

For each symbol, gather evidence (lightweight version of `investigate-firmware-symbol`):

1. **Usages** — grep in the `.cpp`, note read vs write, values compared
2. **Assembly width** (for globals) — run `python3 scripts/disasm_func.py <func> <addr>` to get actual load/store width
3. **Context** — what role does this symbol play in the function's story?
4. **Current name analysis** — is the name misleading? Based on wrong domain? Inherited from a template?

### Phase 3: Propose coherent names

Create a rename table with rationale:

```
| Current Name | Proposed Name | Type | Rationale |
|--------------|---------------|------|-----------|
| sensor_fault_mode_active | eeprom_write_request_type | byte | Value 1/2 dispatches EEPROM ops, not sensor faults |
| cm848_diagRequestTypeDispatcher | cm848_dispatchEepromWriteRequest | func | Dispatches by EEPROM write type |
```

**Naming principles:**
- Names should tell the function's story
- Major concept first (`eeprom_write_*` not `write_eeprom_*`)
- Match the actual behavior, not inherited/template names
- Type width must match assembly access

### Phase 4: Apply changes

Edit the appropriate CSVs (see `editing-firmware-csvs` skill for column formats):

| Change Type | CSV File |
|-------------|----------|
| Global variable rename/retype | `global_variables.csv` |
| Function rename | `function_renames.csv` |
| Function prototype (fix decompiler artifacts) | `function_definitions.csv` |
| Local variable rename | `local_variables.csv` |
| Magic numbers | `enums.csv` |

**Decompiler artifact fixes:**
- `CONCAT31(in_register_*, param)` → add void prototype to clear phantom params
- `in_register_0000000c` locals → often indicates function takes no params (callers set regs but callee ignores)

### Phase 5: Build and verify

```bash
cd firmware/<fw>_analysis/ghidra
./analyze.sh build
```

Verify in the `.cpp`:
- All renames propagated
- Decompiler artifacts eliminated
- No new `_` prefix warnings (or document if unavoidable)
- Function now reads clearly

### Phase 6: Commit and PR

```bash
# Stage the changed files
git add firmware/<fw>_analysis/output/global_variables.csv
git add firmware/<fw>_analysis/output/function_renames.csv
git add firmware/<fw>_analysis/output/function_definitions.csv
git add firmware/<fw>_analysis/output/cm848_rom.ghidra.cpp  # or J90350.00.ghidra.cpp

# Commit with descriptive message
git commit -m "$(cat <<'EOF'
<fw>: rename <old_pattern> symbols to <new_pattern>

<Brief explanation of why the old names were wrong and what the function
actually does.>

Changes:
- <old_name> → <new_name>
- <old_name> → <new_name>
- Add void prototypes for <func> to eliminate <artifact>

Co-Authored-By: Claude Opus 4.5 <noreply@anthropic.com>
EOF
)"

# Push and create PR
git push -u origin <branch>
gh pr create --title "<fw>: <short description>" --body "$(cat <<'EOF'
## Summary
- <bullet points of key changes>

## Test plan
- [x] `./analyze.sh build` completes successfully
- [x] Renames propagate throughout decompilation
- [x] Decompiler artifacts eliminated
- [x] Function reads clearly

🤖 Generated with [Claude Code](https://claude.com/claude-code)
EOF
)"
```

## Output

The skill produces:
1. A **before/after comparison** showing the improved function
2. A **commit** with all CSV and `.cpp` changes
3. A **pull request** ready for review

## Example session

**Input:** "Review `cm848_diagRequestTypeDispatcher` at 0x000038f4"

**Before:**
```c
void cm848_diagRequestTypeDispatcher(byte service_code, byte *request_ptr)
{
  undefined3 in_register_0000000c;

  cm848_resetEepromCalibrationState(CONCAT31(in_register_0000000c,service_code));
  if (sensor_fault_mode_active._0_1_ == '\x01') {
    cm848_beginEepromCalibrationWrite();
  }
  else if (sensor_fault_mode_active._0_1_ == '\x02') {
    cm848_updateEepromMagicAndReload();
  }
  ...
}
```

**After:**
```c
void cm848_dispatchEepromWriteRequest(byte service_code, byte *request_ptr)
{
  cm848_resetEepromCalibrationState();  // CONCAT31 artifact gone!
  if (eeprom_write_request_type == 1) {
    cm848_beginEepromCalibrationWrite();
  }
  else if (eeprom_write_request_type == 2) {
    cm848_updateEepromMagicAndReload();
  }
  ...
}
```

**Renames applied:**
- `sensor_fault_mode_active` → `eeprom_write_request_type` (byte) — dispatches EEPROM ops, not sensor faults
- `sensor_fault_mode_pending` → `eeprom_write_request_pending`
- `cm848_diagRequestTypeDispatcher` → `cm848_dispatchEepromWriteRequest`
- Added void prototypes to eliminate CONCAT31 artifact

## When NOT to use this skill

- **Bulk unnamed DAT_ symbols** → use `running-naming-campaigns`
- **Single symbol investigation (read-only)** → use `investigate-firmware-symbol`
- **CSV mechanics questions** → use `editing-firmware-csvs`
- **Function is already readable** → no action needed

## Working directories

| Firmware | ghidra dir | output .cpp |
|----------|------------|-------------|
| CM848 | `firmware/CM848_S90140.06_analysis/ghidra` | `output/cm848_rom.ghidra.cpp` |
| CM550 | `firmware/CM550_J90350.00_analysis/ghidra` | `output/J90350.00.ghidra.cpp` |

## Common mistakes

- **Renaming based on current names, not behavior** — always understand what the function DOES first
- **Skipping the assembly width check** — type width must match actual load/store instruction
- **Not fixing decompiler artifacts** — void prototypes often needed to eliminate CONCAT/in_register noise
- **Forgetting related symbols** — if you rename `foo_active`, check for `foo_pending`, `foo_init`, etc.
- **Committing timestamp-only churn** — if only the `// Generated:` header changed, `git checkout` the file
