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
                        function.setReturnType(dataType, SourceType.USER_DEFINED);
                    } else {
                        Parameter[] existingParams = function.getParameters();
                        Parameter newParam = new ParameterImpl(param.name, dataType, currentProgram);
                        newParam.setComment(param.comment);

                        List<Parameter> paramList = new java.util.ArrayList<>();
                        for (Parameter p : existingParams) {
                            paramList.add(p);
                        }

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
