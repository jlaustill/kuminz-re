// Apply Function Parameters Script
// Reads function_parameters.csv and applies typed parameter names to functions
// Improves decompilation readability by replacing param_1, param_2 with meaningful names
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

public class ApplyFunctionParameters extends GhidraScript {

    private FunctionManager functionManager;
    private DataTypeManager dtm;

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY FUNCTION PARAMETERS - J90350.00");
        println("=".repeat(70));
        println("");

        functionManager = currentProgram.getFunctionManager();
        dtm = currentProgram.getDataTypeManager();

        // Get input file from arguments or use default
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            // Default to local function_parameters.csv
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../output/function_parameters.csv";
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: function_parameters.csv not found at: " + csvPath);
            return;
        }

        // Phase 1: Parse CSV and collect parameter definitions
        println("[Phase 1] Parsing function parameter definitions...");
        List<ParamDef> params = parseParameterDefinitions(csvPath);
        println("  Found " + params.size() + " parameter definitions");
        println("");

        // Phase 2: Apply parameter types and names
        println("[Phase 2] Applying function parameter types...");
        ApplyResult result = applyParameters(params);
        println("  Applied: " + result.applied);
        println("  Skipped: " + result.skipped);
        println("  Failed: " + result.failed);
        println("");

        // Show examples of what was applied
        println("[Examples of applied parameters]");
        int shown = 0;
        for (ParamDef param : params) {
            if (param.wasApplied && shown < 10) {
                println(String.format("  %s[%d]: %s %s",
                    param.functionName, param.paramIndex, param.newType, param.newName));
                shown++;
            }
        }

        println("");
        println("=".repeat(70));
        println("FUNCTION PARAMETER TYPING COMPLETE!");
        println("Run 'export' to see changes in decompiled output.");
        println("=".repeat(70));
    }

    private List<ParamDef> parseParameterDefinitions(String csvPath) throws Exception {
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

                // Parse CSV: function_address,function_name,param_index,new_name,new_type,comment
                String[] parts = parseCSVLine(line);
                if (parts.length < 5) {
                    continue;
                }

                String addressStr = parts[0].trim();
                String functionName = parts[1].trim();
                String paramIndexStr = parts[2].trim();
                String newName = parts[3].trim();
                String newType = parts[4].trim();
                String comment = parts.length > 5 ? parts[5].trim() : "";

                if (addressStr.isEmpty() || functionName.isEmpty()) {
                    continue;
                }

                try {
                    long address = parseAddressString(addressStr);
                    int paramIndex = Integer.parseInt(paramIndexStr);

                    ParamDef param = new ParamDef();
                    param.functionAddress = address;
                    param.functionName = functionName;
                    param.paramIndex = paramIndex;
                    param.newName = newName;
                    param.newType = newType;
                    param.comment = comment;
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

    private ApplyResult applyParameters(List<ParamDef> params) {
        ApplyResult result = new ApplyResult();
        int txId = currentProgram.startTransaction("Apply Function Parameters");

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

                // Verify function name matches (warning only)
                if (!function.getName().equals(param.functionName)) {
                    println("  Warning: Function name mismatch at 0x" + Long.toHexString(param.functionAddress) +
                            " - expected '" + param.functionName + "', found '" + function.getName() + "'");
                }

                // Get data type for the parameter
                DataType dataType = getDataType(param.newType);
                if (dataType == null) {
                    println("  Error: Unknown data type '" + param.newType + "' for " + param.functionName);
                    result.failed++;
                    continue;
                }

                // Get current parameters - on MC68336, may be empty even if decompiler infers params
                Parameter[] existingParams = function.getParameters();

                try {
                    // Create new parameter with updated name and type
                    Parameter newParam = new ParameterImpl(param.newName, dataType, currentProgram);
                    newParam.setComment(param.comment);

                    // Build parameter list - extend if needed
                    java.util.List<Parameter> paramList = new java.util.ArrayList<>();

                    // Copy existing parameters
                    for (Parameter p : existingParams) {
                        paramList.add(p);
                    }

                    // Extend list if param index is beyond current size
                    while (paramList.size() <= param.paramIndex) {
                        // Add placeholder undefined4 parameters
                        paramList.add(new ParameterImpl("param_" + paramList.size(),
                            new Undefined4DataType(), currentProgram));
                    }

                    // Replace at the target index
                    paramList.set(param.paramIndex, newParam);

                    // Update function with new parameters
                    function.updateFunction(null, null, paramList,
                            Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,
                            true, SourceType.USER_DEFINED);

                    result.applied++;
                    param.wasApplied = true;

                } catch (Exception e) {
                    println("  Error: Failed to update " + param.functionName + "[" + param.paramIndex +
                            "]: " + e.getMessage());
                    result.failed++;
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
                // Try to find custom structure type
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
                // Try to find as custom type
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
    private static class ParamDef {
        long functionAddress;
        String functionName;
        int paramIndex;
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
