# Function Definitions CSV Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Rename `function_parameters.csv` → `function_definitions.csv`, clean up column names, and add `"return"` sentinel support so function return types can be annotated via CSV.

**Architecture:** A single Java script (`ApplyFunctionDefinitions.java`) handles both parameter and return type annotation. When `param_index` is the string `"return"`, it calls `function.setReturnType()` instead of modifying the parameter list. All pipeline wiring (common.sh, both analyze.sh wrappers) is updated to reference the new names.

**Tech Stack:** Java (Ghidra scripting API), bash, CSV

---

### Task 1: Create `ApplyFunctionDefinitions.java`

**Files:**
- Create: `firmware/scripts/ApplyFunctionDefinitions.java`

- [ ] **Step 1: Create the new script**

Write `firmware/scripts/ApplyFunctionDefinitions.java` with this exact content:

```java
// Apply Function Definitions Script
// Reads function_definitions.csv and applies typed parameter names and return types to functions
// param_index = "return" sets the function return type
// param_index = 0, 1, 2... sets the named parameter at that index
// @author J90350.00_analysis
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.symbol.SourceType;

public class ApplyFunctionDefinitions extends GhidraScript {

    private FunctionManager functionManager;
    private DataTypeManager dtm;

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY FUNCTION DEFINITIONS - CM848/CM550");
        println("=".repeat(70));
        println("");

        functionManager = currentProgram.getFunctionManager();
        dtm = currentProgram.getDataTypeManager();

        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../output/function_definitions.csv";
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: function_definitions.csv not found at: " + csvPath);
            return;
        }

        println("[Phase 1] Parsing function definitions...");
        List<ParamDef> params = parseDefinitions(csvPath);
        println("  Found " + params.size() + " definitions");
        println("");

        println("[Phase 2] Applying function definitions...");
        ApplyResult result = applyDefinitions(params);
        println("  Applied: " + result.applied);
        println("  Skipped: " + result.skipped);
        println("  Failed:  " + result.failed);
        println("");

        println("[Examples of applied definitions]");
        int shown = 0;
        for (ParamDef param : params) {
            if (param.wasApplied && shown < 10) {
                String indexLabel = param.isReturnType ? "return" : String.valueOf(param.paramIndex);
                println(String.format("  %s[%s]: %s %s",
                    param.functionName, indexLabel, param.type, param.name));
                shown++;
            }
        }

        println("");
        println("=".repeat(70));
        println("FUNCTION DEFINITION TYPING COMPLETE!");
        println("Run 'export' to see changes in decompiled output.");
        println("=".repeat(70));
    }

    private List<ParamDef> parseDefinitions(String csvPath) throws Exception {
        List<ParamDef> params = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;

            while ((line = reader.readLine()) != null) {
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }

                // CSV: function_address,function_name,param_index,name,type,comment
                String[] parts = parseCSVLine(line);
                if (parts.length < 5) {
                    continue;
                }

                String addressStr   = parts[0].trim();
                String functionName = parts[1].trim();
                String indexStr     = parts[2].trim();
                String name         = parts[3].trim();
                String type         = parts[4].trim();
                String comment      = parts.length > 5 ? parts[5].trim() : "";

                if (addressStr.isEmpty() || functionName.isEmpty()) {
                    continue;
                }

                try {
                    long address = parseAddressString(addressStr);
                    ParamDef param = new ParamDef();
                    param.functionAddress = address;
                    param.functionName    = functionName;
                    param.name            = name;
                    param.type            = type;
                    param.comment         = comment;

                    if (indexStr.equals("return")) {
                        param.isReturnType = true;
                        param.paramIndex   = -1;
                    } else {
                        param.isReturnType = false;
                        param.paramIndex   = Integer.parseInt(indexStr);
                    }

                    params.add(param);
                } catch (Exception e) {
                    println("  Warning: Skipping invalid entry: " + line);
                }
            }
        }

        return params;
    }

    private String[] parseCSVLine(String line) {
        List<String> parts = new ArrayList<>();
        StringBuilder current = new StringBuilder();
        boolean inQuotes = false;

        for (char c : line.toCharArray()) {
            if (c == '"') {
                inQuotes = !inQuotes;
            } else if (c == ',' && !inQuotes) {
                parts.add(current.toString());
                current = new StringBuilder();
            } else {
                current.append(c);
            }
        }
        parts.add(current.toString());

        return parts.toArray(new String[0]);
    }

    private ApplyResult applyDefinitions(List<ParamDef> params) {
        ApplyResult result = new ApplyResult();
        int txId = currentProgram.startTransaction("Apply Function Definitions");

        try {
            for (ParamDef param : params) {
                Address addr = toAddr(param.functionAddress);
                if (addr == null) {
                    result.failed++;
                    continue;
                }

                Function function = functionManager.getFunctionAt(addr);
                if (function == null) {
                    println("  Warning: No function at 0x" + Long.toHexString(param.functionAddress) +
                            " (" + param.functionName + ")");
                    result.failed++;
                    continue;
                }

                if (!function.getName().equals(param.functionName)) {
                    println("  Warning: Function name mismatch at 0x" + Long.toHexString(param.functionAddress) +
                            " - expected '" + param.functionName + "', found '" + function.getName() + "'");
                }

                DataType dataType = getDataType(param.type);
                if (dataType == null) {
                    println("  Error: Unknown data type '" + param.type + "' for " + param.functionName);
                    result.failed++;
                    continue;
                }

                try {
                    if (param.isReturnType) {
                        // Set the function return type
                        function.setReturnType(dataType, SourceType.USER_DEFINED);
                    } else {
                        // Set a named, typed parameter at the given index
                        Parameter[] existingParams = function.getParameters();
                        Parameter newParam = new ParameterImpl(param.name, dataType, currentProgram);
                        newParam.setComment(param.comment);

                        List<Parameter> paramList = new java.util.ArrayList<>();
                        for (Parameter p : existingParams) {
                            paramList.add(p);
                        }

                        // Extend list if param index is beyond current size
                        while (paramList.size() <= param.paramIndex) {
                            paramList.add(new ParameterImpl("param_" + paramList.size(),
                                new Undefined4DataType(), currentProgram));
                        }

                        paramList.set(param.paramIndex, newParam);

                        function.updateFunction(null, null, paramList,
                                Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,
                                true, SourceType.USER_DEFINED);
                    }

                    result.applied++;
                    param.wasApplied = true;

                } catch (Exception e) {
                    String indexLabel = param.isReturnType ? "return" : String.valueOf(param.paramIndex);
                    println("  Error: Failed to update " + param.functionName +
                            "[" + indexLabel + "]: " + e.getMessage());
                    result.failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        return result;
    }

    private DataType getDataType(String typeString) {
        if (typeString.endsWith("*")) {
            String baseType = typeString.substring(0, typeString.length() - 1).trim();
            DataType baseDataType = getDataType(baseType);
            if (baseDataType == null) {
                baseDataType = findDataTypeByName(baseType);
            }
            if (baseDataType != null) {
                return new PointerDataType(baseDataType);
            }
            return null;
        }

        switch (typeString.toLowerCase()) {
            case "uint8_t":
            case "byte":
            case "char":
                return ByteDataType.dataType;
            case "uint16_t":
            case "word":
            case "ushort":
            case "short":
                return WordDataType.dataType;
            case "uint32_t":
            case "dword":
            case "uint":
            case "int":
                return DWordDataType.dataType;
            case "uint64_t":
            case "qword":
            case "ulong":
            case "long":
                return QWordDataType.dataType;
            case "float":
                return FloatDataType.dataType;
            case "double":
                return DoubleDataType.dataType;
            case "void":
                return VoidDataType.dataType;
            default:
                return findDataTypeByName(typeString);
        }
    }

    private DataType findDataTypeByName(String typeName) {
        java.util.Iterator<DataType> dtIter = dtm.getAllDataTypes();
        while (dtIter.hasNext()) {
            DataType dt = dtIter.next();
            if (dt.getName().equals(typeName)) {
                return dt;
            }
        }
        return null;
    }

    private long parseAddressString(String addressStr) {
        addressStr = addressStr.trim();
        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
            return Long.parseLong(addressStr.substring(2), 16);
        }
        return Long.parseLong(addressStr, 16);
    }

    private static class ParamDef {
        long functionAddress;
        String functionName;
        boolean isReturnType;
        int paramIndex;
        String name;
        String type;
        String comment;
        boolean wasApplied = false;
    }

    private static class ApplyResult {
        int applied = 0;
        int skipped = 0;
        int failed = 0;
    }
}
```

- [ ] **Step 2: Verify file exists**

```bash
ls -la firmware/scripts/ApplyFunctionDefinitions.java
```

Expected: file present, non-zero size.

---

### Task 2: Update `common.sh`

**Files:**
- Modify: `firmware/scripts/common.sh`

- [ ] **Step 1: Rename `cmd_funcparams` to `cmd_funcdefs` and update all references**

Six changes in `firmware/scripts/common.sh`:

| Line | Old | New |
|------|-----|-----|
| 268 | `cmd_funcparams()` | `cmd_funcdefs()` |
| 269 | `APPLYING FUNCTION PARAMETER TYPES` | `APPLYING FUNCTION DEFINITIONS` |
| 274 | `PARAMS_CSV="$OUTPUT_DIR/function_parameters.csv"` | `PARAMS_CSV="$OUTPUT_DIR/function_definitions.csv"` |
| 277 | `function_parameters.csv not found` | `function_definitions.csv not found` |
| 285 | `run_script ApplyFunctionParameters.java` | `run_script ApplyFunctionDefinitions.java` |
| 287 | `Function parameter types applied` | `Function definitions applied` |
| 461 | `... function_parameters` (in CSV status loop) | `... function_definitions` |
| 483 | `funcparams Apply function parameter types` | `funcdefs    Apply function definitions (params + return types)` |
| 515 | `funcparams) cmd_funcparams ;;` | `funcdefs)   cmd_funcdefs ;;` |

- [ ] **Step 2: Verify no old references remain**

```bash
grep -n "funcparams\|function_parameters\|ApplyFunctionParam" firmware/scripts/common.sh
```

Expected: no output.

---

### Task 3: Update shell files and CLAUDE.md

**Files:**
- Modify: `firmware/CM848_S90140.06_analysis/ghidra/analyze.sh`
- Modify: `firmware/CM550_J90350.00_analysis/ghidra/analyze.sh`
- Modify: `firmware/CLAUDE.md`

- [ ] **Step 1: Update CM848 `analyze.sh`**

In `firmware/CM848_S90140.06_analysis/ghidra/analyze.sh`:

| Line | Old | New |
|------|-----|-----|
| 118 | `... function_parameters` (status CSV loop) | `... function_definitions` |
| 201 | `funcparams Apply function parameter types` | `funcdefs    Apply function definitions (params + return types)` |

- [ ] **Step 2: Update CM550 `analyze.sh`**

In `firmware/CM550_J90350.00_analysis/ghidra/analyze.sh`:

| Line | Old | New |
|------|-----|-----|
| 117 | `... function_parameters` (status CSV loop) | `... function_definitions` |
| 141 | `funcparams Apply function parameter types` | `funcdefs    Apply function definitions (params + return types)` |

- [ ] **Step 3: Update `firmware/CLAUDE.md` Available Commands table**

In `firmware/CLAUDE.md`, find the Available Commands section and change:

```
./analyze.sh funcparams # Apply function parameter types
```
→
```
./analyze.sh funcdefs   # Apply function definitions (params + return types)
```

- [ ] **Step 4: Verify no old references in any of the three files**

```bash
grep -n "funcparams\|function_parameters" \
  firmware/CM848_S90140.06_analysis/ghidra/analyze.sh \
  firmware/CM550_J90350.00_analysis/ghidra/analyze.sh \
  firmware/CLAUDE.md
```

Expected: no output.

---

### Task 4: Migrate CM848 CSV

**Files:**
- Create: `firmware/CM848_S90140.06_analysis/output/function_definitions.csv`
- Delete: `firmware/CM848_S90140.06_analysis/output/function_parameters.csv`

- [ ] **Step 1: Copy CSV with updated header**

```bash
cp firmware/CM848_S90140.06_analysis/output/function_parameters.csv \
   firmware/CM848_S90140.06_analysis/output/function_definitions.csv
```

- [ ] **Step 2: Update header row**

In `firmware/CM848_S90140.06_analysis/output/function_definitions.csv`, change line 1:

```
function_address,function_name,param_index,new_name,new_type,comment
```
→
```
function_address,function_name,param_index,name,type,comment
```

- [ ] **Step 3: Add the five diagnostic handler return type entries**

Find the `# EF00 Service Dispatch System` section (near the bottom) and add a new section after `processJ1939DiagnosticRequest` and `registerDiagnosticService` entries:

```
# -----------------------------------------------------------------------------
# J1939 Diagnostic Handler Return Types
# All handlers registered via processJ1939DiagnosticRequest share the
# DIAG_RESPONSE callback contract (ACK=0, NACK_NOT_READY=4, NACK_PROTECTED=7)
# -----------------------------------------------------------------------------
0x00021584,cm848_advanceDiagnosticActionState,return,,DIAG_RESPONSE,Returns DIAG_ACK(0) or DIAG_NACK_PROTECTED(7)
0x00021668,cm848_resetDiagnosticSession,return,,DIAG_RESPONSE,Always DIAG_ACK - unconditional state clear
0x000216e8,cm848_setColdStartActiveFlag,return,,DIAG_RESPONSE,Always DIAG_ACK - unconditional flag set
0x00021904,cm848_setColdStartMode2Flag,return,,DIAG_RESPONSE,Always DIAG_ACK - unconditional flag set
0x00021918,cm848_validateCalibrationMemory,return,,DIAG_RESPONSE,Returns DIAG_ACK(0) or DIAG_NACK_PROTECTED(7)
```

- [ ] **Step 4: Delete the old file**

```bash
rm firmware/CM848_S90140.06_analysis/output/function_parameters.csv
```

- [ ] **Step 5: Verify**

```bash
head -3 firmware/CM848_S90140.06_analysis/output/function_definitions.csv
grep "return,,DIAG_RESPONSE" firmware/CM848_S90140.06_analysis/output/function_definitions.csv | wc -l
```

Expected: header shows `name,type` (not `new_name,new_type`), count = 5.

---

### Task 5: Migrate CM550 CSV

**Files:**
- Create: `firmware/CM550_J90350.00_analysis/output/function_definitions.csv`
- Delete: `firmware/CM550_J90350.00_analysis/output/function_parameters.csv`

- [ ] **Step 1: Copy CSV with updated header**

```bash
cp firmware/CM550_J90350.00_analysis/output/function_parameters.csv \
   firmware/CM550_J90350.00_analysis/output/function_definitions.csv
```

- [ ] **Step 2: Update header row**

In `firmware/CM550_J90350.00_analysis/output/function_definitions.csv`, change line 1:

```
function_address,function_name,param_index,new_name,new_type,comment
```
→
```
function_address,function_name,param_index,name,type,comment
```

- [ ] **Step 3: Delete the old file**

```bash
rm firmware/CM550_J90350.00_analysis/output/function_parameters.csv
```

- [ ] **Step 4: Verify**

```bash
head -3 firmware/CM550_J90350.00_analysis/output/function_definitions.csv
ls firmware/CM550_J90350.00_analysis/output/function_parameters.csv 2>&1
```

Expected: header shows `name,type`, ls reports file not found.

---

### Task 6: Delete old script

**Files:**
- Delete: `firmware/scripts/ApplyFunctionParameters.java`

- [ ] **Step 1: Remove the old script**

```bash
rm firmware/scripts/ApplyFunctionParameters.java
```

- [ ] **Step 2: Verify no stale references anywhere**

```bash
grep -r "ApplyFunctionParameters\|function_parameters\|funcparams\|new_name,new_type" \
  firmware/ --include="*.java" --include="*.sh" --include="*.csv" --include="*.md"
```

Expected: no output.

---

### Task 7: Integration verification (CM848)

No Ghidra unit test framework exists — the integration test is running `./analyze.sh import` and checking the decompiled output.

- [ ] **Step 1: Run import on CM848**

```bash
cd firmware/CM848_S90140.06_analysis/ghidra
./analyze.sh funcdefs
```

Expected output contains:
```
APPLYING FUNCTION DEFINITIONS
Applied: <N>
Failed:  0
```

The five return type entries should appear in the examples section as `[return]: DIAG_RESPONSE`.

- [ ] **Step 2: Export and verify decompiled output**

```bash
./analyze.sh export
grep -A8 "cm848_resetDiagnosticSession" ../output/cm848_rom.ghidra.cpp | head -10
```

Expected: function signature shows `DIAG_RESPONSE` instead of `undefined4`.

---

### Task 8: Commit

- [ ] **Step 1: Stage all changes**

```bash
git add firmware/scripts/ApplyFunctionDefinitions.java
git add -u firmware/scripts/ApplyFunctionParameters.java
git add firmware/scripts/common.sh
git add firmware/CM848_S90140.06_analysis/ghidra/analyze.sh
git add firmware/CM550_J90350.00_analysis/ghidra/analyze.sh
git add firmware/CLAUDE.md
git add firmware/CM848_S90140.06_analysis/output/function_definitions.csv
git add -u firmware/CM848_S90140.06_analysis/output/function_parameters.csv
git add firmware/CM550_J90350.00_analysis/output/function_definitions.csv
git add -u firmware/CM550_J90350.00_analysis/output/function_parameters.csv
git add docs/superpowers/specs/2026-05-25-function-definitions-design.md
git add docs/superpowers/plans/2026-05-25-function-definitions.md
```

- [ ] **Step 2: Commit**

```bash
git commit -m "feat(firmware): rename function_parameters → function_definitions; add return type support

- ApplyFunctionDefinitions.java replaces ApplyFunctionParameters.java
- param_index=\"return\" calls function.setReturnType() in Ghidra
- Column names cleaned up: new_name/new_type → name/type
- cmd_funcparams → cmd_funcdefs in common.sh and analyze.sh wrappers
- Initial return type entries: 5 J1939 diagnostic handlers annotated as DIAG_RESPONSE"
```
