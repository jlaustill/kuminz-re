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
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.data.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.FunctionPrototype;
import ghidra.program.model.pcode.HighSymbol;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.TaskMonitor;

public class ApplyFunctionDefinitions extends GhidraScript {

    private FunctionManager functionManager;
    private DataTypeManager dtm;
    private DecompInterface decompiler;

    /** A parameter as recovered by the decompiler (name + type), captured before we commit a prototype. */
    private static class RecoveredParam {
        final String name;
        final DataType type;
        RecoveredParam(String name, DataType type) { this.name = name; this.type = type; }
    }

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
                String[] parts = ScriptUtils.parseCSVLine(line);
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
                    long address = ScriptUtils.parseAddress(addressStr);
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

    private ApplyResult applyDefinitions(List<ParamDef> params) {
        ApplyResult result = new ApplyResult();
        int txId = currentProgram.startTransaction("Apply Function Definitions");

        // Group all params by function address so each function gets one updateFunction call.
        // This ensures the param list is sized to exactly max_index+1, trimming any stale
        // params that remain from a previous run with more parameters.
        Map<Long, List<ParamDef>> byFunction = new LinkedHashMap<>();
        for (ParamDef param : params) {
            byFunction.computeIfAbsent(param.functionAddress, k -> new ArrayList<>()).add(param);
        }

        // Decompiler is used to see what parameters Ghidra currently recovers for each function
        // BEFORE we commit a prototype (which would turn off that dynamic inference).
        decompiler = new DecompInterface();
        decompiler.setOptions(new DecompileOptions());
        decompiler.toggleSyntaxTree(true);
        decompiler.setSimplificationStyle("decompile");
        boolean decompilerReady = decompiler.openProgram(currentProgram);
        if (!decompilerReady) {
            println("  Warning: decompiler unavailable — parameter reconciliation disabled for this run");
        }

        try {
            for (Map.Entry<Long, List<ParamDef>> entry : byFunction.entrySet()) {
                Address addr = toAddr(entry.getKey());
                if (addr == null) {
                    result.failed += entry.getValue().size();
                    continue;
                }

                Function function = functionManager.getFunctionAt(addr);
                if (function == null) {
                    String name = entry.getValue().get(0).functionName;
                    println("  Warning: No function at 0x" + Long.toHexString(entry.getKey()) +
                            " (" + name + ")");
                    result.failed += entry.getValue().size();
                    continue;
                }

                String firstName = entry.getValue().get(0).functionName;
                if (!function.getName().equals(firstName)) {
                    println("  Warning: Function name mismatch at 0x" + Long.toHexString(entry.getKey()) +
                            " - expected '" + firstName + "', found '" + function.getName() + "'");
                }

                // Separate return type entry from positional params
                ParamDef returnDef = null;
                int maxIndex = -1;
                List<ParamDef> positional = new ArrayList<>();
                for (ParamDef p : entry.getValue()) {
                    if (p.isReturnType) {
                        returnDef = p;
                    } else {
                        positional.add(p);
                        if (p.paramIndex > maxIndex) maxIndex = p.paramIndex;
                    }
                }

                try {
                    // See what params Ghidra recovers now, before committing anything.
                    List<RecoveredParam> detected = decompilerReady ? recoverParams(function)
                                                                    : new ArrayList<>();
                    int definedCount = maxIndex + 1;            // 0 when no positional rows
                    int detectedCount = detected.size();
                    ScriptUtils.ParamReconciliation decision =
                            ScriptUtils.reconcileParams(definedCount, detectedCount);

                    if (returnDef != null) {
                        DataType dt = getDataType(returnDef.type);
                        if (dt == null) {
                            println("  Error: Unknown return type '" + returnDef.type + "' for " + firstName);
                            result.failed++;
                        } else {
                            function.setReturnType(dt, SourceType.USER_DEFINED);
                            function.setCallingConvention("__stdcall");
                            result.applied++;
                            returnDef.wasApplied = true;
                        }
                    }

                    switch (decision) {
                        case PRESERVE_DETECTED:
                            // Return-only row but Ghidra recovered args — committing the return type
                            // would strip them. Carry the recovered params into the committed signature.
                            println("  Note: " + firstName + " has a return-only definition but Ghidra " +
                                    "recovered " + detectedCount + " param(s); preserving them so call " +
                                    "arguments are not dropped. Add explicit param rows to name/type them.");
                            applyDetectedParams(function, detected);
                            break;

                        case WARN_MISMATCH:
                            println("  Warning: " + firstName + " defines " + definedCount +
                                    " param row(s) but Ghidra recovered " + detectedCount +
                                    " — applying the CSV's " + definedCount + " (verify this is intended)");
                            applyCsvParams(function, positional, maxIndex, firstName, result);
                            break;

                        case OK:
                            if (maxIndex >= 0) {
                                applyCsvParams(function, positional, maxIndex, firstName, result);
                            }
                            break;
                    }

                } catch (Exception e) {
                    println("  Error: Failed to update " + firstName + ": " + e.getMessage());
                    result.failed += entry.getValue().size();
                }
            }
        } finally {
            currentProgram.endTransaction(txId, true);
            if (decompiler != null) {
                decompiler.dispose();
                decompiler = null;
            }
        }

        return result;
    }

    /**
     * Returns the parameters the decompiler currently recovers for {@code function}.
     * Best-effort: returns an empty list if decompilation fails, so reconciliation simply
     * falls back to the prior behavior rather than erroring.
     */
    private List<RecoveredParam> recoverParams(Function function) {
        List<RecoveredParam> out = new ArrayList<>();
        try {
            DecompileResults res = decompiler.decompileFunction(function, 30, TaskMonitor.DUMMY);
            if (res == null || !res.decompileCompleted()) return out;
            HighFunction hf = res.getHighFunction();
            if (hf == null) return out;
            FunctionPrototype proto = hf.getFunctionPrototype();
            if (proto == null) return out;
            int n = proto.getNumParams();
            for (int i = 0; i < n; i++) {
                HighSymbol p = proto.getParam(i);
                if (p == null) continue;
                out.add(new RecoveredParam(p.getName(), p.getDataType()));
            }
        } catch (Exception e) {
            // best-effort; ignore and behave as if nothing was recovered
        }
        return out;
    }

    /** Commits the decompiler-recovered params verbatim, preserving call-site arguments. */
    private void applyDetectedParams(Function function, List<RecoveredParam> detected) throws Exception {
        List<Parameter> paramList = new ArrayList<>();
        int i = 0;
        for (RecoveredParam rp : detected) {
            DataType dt = rp.type != null ? rp.type : new Undefined4DataType();
            String name = (rp.name != null && !rp.name.isEmpty()) ? rp.name : ("param_" + i);
            paramList.add(new ParameterImpl(name, dt, currentProgram));
            i++;
        }
        function.updateFunction("__stdcall", null, paramList,
                Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,
                true, SourceType.USER_DEFINED);
    }

    /** Applies the CSV-declared positional params, sizing the list to exactly maxIndex+1. */
    private void applyCsvParams(Function function, List<ParamDef> positional, int maxIndex,
                                String firstName, ApplyResult result) throws Exception {
        // Build param list sized to exactly maxIndex+1 — no stale extra params
        List<Parameter> paramList = new ArrayList<>();
        for (int i = 0; i <= maxIndex; i++) {
            paramList.add(new ParameterImpl("param_" + i, new Undefined4DataType(), currentProgram));
        }
        for (ParamDef p : positional) {
            DataType dt = getDataType(p.type);
            if (dt == null) {
                println("  Error: Unknown type '" + p.type + "' for " +
                        firstName + "[" + p.paramIndex + "]");
                result.failed++;
                continue;
            }
            Parameter newParam = new ParameterImpl(p.name, dt, currentProgram);
            newParam.setComment(p.comment);
            paramList.set(p.paramIndex, newParam);
        }

        function.updateFunction("__stdcall", null, paramList,
                Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,
                true, SourceType.USER_DEFINED);

        for (ParamDef p : positional) {
            p.wasApplied = true;
            result.applied++;
        }
    }

    private DataType getDataType(String typeString) {
        if (ScriptUtils.isPointerType(typeString)) {
            String baseType = ScriptUtils.stripPointer(typeString);
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
