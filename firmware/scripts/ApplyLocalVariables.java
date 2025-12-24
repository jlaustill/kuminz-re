// Apply Local Variables Script
// Reads local_variables.csv and applies typed variable names to functions
// Uses HighFunctionDBUtil to properly commit decompiler variable changes
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
import java.util.HashMap;
import java.util.Map;

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.data.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Variable;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighFunctionDBUtil;
import ghidra.program.model.pcode.HighSymbol;
import ghidra.program.model.pcode.LocalSymbolMap;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;

public class ApplyLocalVariables extends GhidraScript {

    private FunctionManager functionManager;
    private DataTypeManager dtm;
    private DecompInterface decompiler;

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY LOCAL VARIABLES - J90350.00");
        println("=".repeat(70));
        println("");

        functionManager = currentProgram.getFunctionManager();
        dtm = currentProgram.getDataTypeManager();

        // Initialize decompiler with simplification style that preserves names
        decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        decompiler.setOptions(options);
        decompiler.setSimplificationStyle("decompile");
        decompiler.openProgram(currentProgram);

        // Get input file from arguments or use default
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            // Navigate from project directory (ghidra/project/J90350.rep) up to analysis root
            // ghidra/project/J90350.rep -> ghidra/project -> ghidra -> J90350.00_analysis
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../../../output/local_variables.csv";
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: local_variables.csv not found at: " + csvPath);
            decompiler.dispose();
            return;
        }

        // Phase 1: Parse CSV and collect variable definitions
        println("[Phase 1] Parsing local variable definitions...");
        List<VarDef> vars = parseVariableDefinitions(csvPath);
        println("  Found " + vars.size() + " variable definitions");
        println("");

        // Phase 2: Group by function for batch processing
        Map<Long, List<VarDef>> funcVars = new HashMap<>();
        for (VarDef var : vars) {
            funcVars.computeIfAbsent(var.functionAddress, k -> new ArrayList<>()).add(var);
        }
        println("  Across " + funcVars.size() + " functions");
        println("");

        // Phase 3: Apply variable types and names
        println("[Phase 2] Applying local variable types...");
        ApplyResult result = applyVariables(funcVars);
        println("  Applied: " + result.applied);
        println("  Skipped: " + result.skipped);
        println("  Failed: " + result.failed);
        println("");

        // Show examples of what was applied
        println("[Examples of applied variables]");
        int shown = 0;
        for (VarDef var : vars) {
            if (var.wasApplied && shown < 10) {
                println(String.format("  %s.%s -> %s %s",
                    var.functionName, var.oldName, var.newType, var.newName));
                shown++;
            }
        }

        println("");
        println("=".repeat(70));
        println("LOCAL VARIABLE TYPING COMPLETE!");
        println("Run 'export' to see changes in decompiled output.");
        println("=".repeat(70));

        decompiler.dispose();
    }

    private List<VarDef> parseVariableDefinitions(String csvPath) throws Exception {
        List<VarDef> vars = new ArrayList<>();

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

                String[] parts = parseCSVLine(line);
                if (parts.length < 5) {
                    continue;
                }

                String addressStr = parts[0].trim();
                String functionName = parts[1].trim();
                String oldName = parts[2].trim();
                String newName = parts[3].trim();
                String newType = parts[4].trim();
                String comment = parts.length > 5 ? parts[5].trim() : "";

                if (addressStr.isEmpty() || functionName.isEmpty()) {
                    continue;
                }

                try {
                    long address = parseAddressString(addressStr);

                    VarDef var = new VarDef();
                    var.functionAddress = address;
                    var.functionName = functionName;
                    var.oldName = oldName;
                    var.newName = newName;
                    var.newType = newType;
                    var.comment = comment;
                    vars.add(var);
                } catch (Exception e) {
                    println("  Warning: Skipping invalid entry: " + line);
                }
            }
        }

        return vars;
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

    private ApplyResult applyVariables(Map<Long, List<VarDef>> funcVars) {
        ApplyResult result = new ApplyResult();
        int txId = currentProgram.startTransaction("Apply Local Variables");

        try {
            for (Map.Entry<Long, List<VarDef>> entry : funcVars.entrySet()) {
                long funcAddr = entry.getKey();
                List<VarDef> varList = entry.getValue();

                Address addr = toAddr(funcAddr);
                if (addr == null) {
                    result.failed += varList.size();
                    continue;
                }

                Function function = functionManager.getFunctionAt(addr);
                if (function == null) {
                    println("  Warning: No function at 0x" + Long.toHexString(funcAddr));
                    result.failed += varList.size();
                    continue;
                }

                // Decompile the function to get high-level variables
                DecompileResults decompResults = decompiler.decompileFunction(function, 30, monitor);
                if (!decompResults.decompileCompleted()) {
                    println("  Warning: Decompilation failed for " + function.getName());
                    result.failed += varList.size();
                    continue;
                }

                HighFunction highFunc = decompResults.getHighFunction();
                if (highFunc == null) {
                    println("  Warning: No high function for " + function.getName());
                    result.failed += varList.size();
                    continue;
                }

                LocalSymbolMap localSymbolMap = highFunc.getLocalSymbolMap();

                // Process each variable definition for this function
                for (VarDef var : varList) {
                    boolean found = false;

                    // Search for the variable by its old name in decompiler's local symbol map
                    java.util.Iterator<HighSymbol> symbols = localSymbolMap.getSymbols();
                    while (symbols.hasNext()) {
                        HighSymbol symbol = symbols.next();
                        if (symbol.getName().equals(var.oldName)) {
                            try {
                                DataType dataType = getDataType(var.newType);
                                if (dataType == null) {
                                    println("  Error: Unknown type '" + var.newType + "' for " +
                                            var.functionName + "." + var.oldName);
                                    result.failed++;
                                    found = true;
                                    break;
                                }

                                // Commit the variable rename using HighFunctionDBUtil
                                // This creates a database entry that the decompiler will use
                                HighFunctionDBUtil.updateDBVariable(
                                    symbol, var.newName, dataType, SourceType.USER_DEFINED);

                                result.applied++;
                                var.wasApplied = true;
                                found = true;
                                break;

                            } catch (Exception e) {
                                // If HighFunctionDBUtil fails, try direct database symbol approach
                                try {
                                    Symbol dbSymbol = symbol.getSymbol();
                                    if (dbSymbol != null) {
                                        DataType dataType = getDataType(var.newType);
                                        dbSymbol.setName(var.newName, SourceType.USER_DEFINED);
                                        result.applied++;
                                        var.wasApplied = true;
                                    } else {
                                        println("  Note: " + var.functionName + "." + var.oldName +
                                                " - " + e.getMessage());
                                        result.skipped++;
                                    }
                                } catch (Exception e2) {
                                    println("  Error: " + var.functionName + "." + var.oldName +
                                            " - " + e2.getMessage());
                                    result.failed++;
                                }
                                found = true;
                                break;
                            }
                        }
                    }

                    if (!found) {
                        // Try searching in function's committed local variables (stack vars)
                        Variable[] localVars = function.getLocalVariables();
                        for (Variable localVar : localVars) {
                            if (localVar.getName().equals(var.oldName)) {
                                try {
                                    DataType dataType = getDataType(var.newType);
                                    if (dataType != null) {
                                        localVar.setName(var.newName, SourceType.USER_DEFINED);
                                        localVar.setDataType(dataType, SourceType.USER_DEFINED);
                                        result.applied++;
                                        var.wasApplied = true;
                                        found = true;
                                    }
                                } catch (Exception e) {
                                    // Ignore
                                }
                                break;
                            }
                        }
                    }

                    if (!found) {
                        println("  Warning: Variable '" + var.oldName + "' not found in " + var.functionName);
                        result.skipped++;
                    }
                }
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        return result;
    }

    private DataType getDataType(String typeString) {
        // Handle pointer types
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

        // Handle primitive types
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

    // Helper classes
    private static class VarDef {
        long functionAddress;
        String functionName;
        String oldName;
        String newName;
        String newType;
        String comment;
        boolean wasApplied = false;
    }

    private static class ApplyResult {
        int applied = 0;
        int skipped = 0;
        int failed = 0;
    }
}
