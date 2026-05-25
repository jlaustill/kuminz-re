# Function Definitions CSV — Design Spec

**Date:** 2026-05-25
**Status:** Approved

## Problem

The Ghidra annotation pipeline has no way to set a function's return type via CSV. The
only workaround is typing a local variable that holds the return value — which silently
fails for functions that directly `return 0;` with no local variable at all. This is a
gap in the knowledge database: every function signature is potentially incomplete.

Discovery context: `cm848_resetDiagnosticSession` always returns `0` (DIAG_ACK) as part
of the J1939 diagnostic handler callback contract, but there is no local variable to type
and no CSV path to express this.

## Solution

Rename `function_parameters.csv` → `function_definitions.csv` and extend the schema with
a `"return"` sentinel in the `param_index` column to express return types. Rename the
corresponding Java script and shell command to match.

## Schema

```
function_address,function_name,param_index,name,type,comment
```

| Column | Notes |
|--------|-------|
| `function_address` | Hex address, e.g. `0x00021668` |
| `function_name` | Must match Ghidra function name (warning-only mismatch) |
| `param_index` | `"return"` for return type; `0`, `1`, `2`… for parameters |
| `name` | Parameter name applied to Ghidra; **empty for return type entries** |
| `type` | Data type string (enum name, pointer type, primitive, etc.) |
| `comment` | Human note, not applied to Ghidra |

### Return type entry

```
0x00021668,cm848_resetDiagnosticSession,return,,DIAG_RESPONSE,Always DIAG_ACK - unconditional state clear
```

`name` is always empty for `return` entries. A future iteration may repurpose it (e.g.,
as a human label), but no meaning is assigned today.

### Parameter entry (unchanged from current behavior)

```
0x00055ef4,lookupTableInterpolation,0,args,table_interp_args_t*,Pointer to table interpolation args
```

## Changes

### 1. `firmware/scripts/ApplyFunctionDefinitions.java` (renamed from `ApplyFunctionParameters.java`)

- Internal variable renames: `newName` → `name`, `newType` → `type`
- Add `"return"` sentinel handling before `parseInt`:

```java
if (paramIndexStr.equals("return")) {
    function.setReturnType(dataType, SourceType.USER_DEFINED);
    result.applied++;
    param.wasApplied = true;
} else {
    int paramIndex = Integer.parseInt(paramIndexStr);
    // existing parameter list logic (unchanged)
}
```

### 2. `firmware/scripts/common.sh`

- `cmd_funcparams` → `cmd_funcdefs`
- All references to `function_parameters.csv` → `function_definitions.csv`
- Help text: `"funcparams  Apply function parameter types"` → `"funcdefs    Apply function definitions (params + return types)"`
- Status CSV loop: `function_parameters` → `function_definitions`

### 3. Both `analyze.sh` wrappers (CM848 + CM550)

- Help text referencing `funcparams` updated to `funcdefs`
- Status CSV list updated

### 4. CSV files

- `firmware/CM848_S90140.06_analysis/output/function_parameters.csv` → `function_definitions.csv`
- `firmware/CM550_J90350.00_analysis/output/function_parameters.csv` → `function_definitions.csv`
- Header row: `param_index,new_name,new_type` → `param_index,name,type`
- All existing data rows: unchanged

### 5. `ExportAnalysis.java` — no changes

`function_definitions.csv` remains import-only, consistent with all other
knowledge-database CSVs in the pipeline. Return types are manually discovered
and annotated; they are not round-tripped through export.

## Initial Data (CM848)

First use of the new feature — five J1939 diagnostic handler return types:

```
# J1939 diagnostic handler return types - all share DIAG_RESPONSE callback contract
0x00021584,cm848_advanceDiagnosticActionState,return,,DIAG_RESPONSE,Returns DIAG_ACK(0) or DIAG_NACK_PROTECTED(7)
0x00021668,cm848_resetDiagnosticSession,return,,DIAG_RESPONSE,Always DIAG_ACK - unconditional state clear
0x000216e8,cm848_setColdStartActiveFlag,return,,DIAG_RESPONSE,Always DIAG_ACK - unconditional flag set
0x00021904,cm848_setColdStartMode2Flag,return,,DIAG_RESPONSE,Always DIAG_ACK - unconditional flag set
0x00021918,cm848_validateCalibrationMemory,return,,DIAG_RESPONSE,Returns DIAG_ACK(0) or DIAG_NACK_PROTECTED(7)
```

Note: `cm848_activateDiagnosticSession` and `cm848_forceActivateDiagnosticSession` already
have `DIAG_RESPONSE` expressed via `local_variables.csv` — no change needed.

## Out of Scope

- `ExportAnalysis.java` return type export (import-only is intentional)
- `new_name` repurposing for return type entries (deferred to future iteration)
- CM550 return type annotations (no return types identified for annotation yet)
