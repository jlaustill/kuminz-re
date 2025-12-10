// Ghidra Bulk Function Parameter Renamer Script
// Reads from function_parameters.csv and renames/retypes function parameters
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.listing.Variable;
import ghidra.program.model.symbol.SourceType;

public class BulkFunctionParameterRenamer extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Path to CSV file
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/function_parameters.csv";
        
        
        FunctionManager functionManager = currentProgram.getFunctionManager();
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        
        // Read CSV file and rename parameters
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;
            int successCount = 0;
            int failCount = 0;
            
            
            while ((line = br.readLine()) != null) {
                // Skip header line
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }
                
                // Parse CSV: function_address,function_name,param_index,new_name,new_type,comment
                String[] parts = line.split(",");
                if (parts.length >= 6) {
                    String functionAddressStr = parts[0].trim();
                    String functionName = parts[1].trim();
                    String paramIndexStr = parts[2].trim();
                    String newParamName = parts[3].trim();
                    String newTypeStr = parts[4].trim();
                    String comment = parts[5].trim();
                    
                    try {
                        // Parse function address
                        long functionAddressLong;
                        if (functionAddressStr.startsWith("0x") || functionAddressStr.startsWith("0X")) {
                            functionAddressLong = Long.parseLong(functionAddressStr.substring(2), 16);
                        } else {
                            functionAddressLong = Long.parseLong(functionAddressStr, 16);
                        }
                        
                        Address functionAddr = toAddr(functionAddressLong);
                        int paramIndex = Integer.parseInt(paramIndexStr);
                        
                        // Get function
                        Function function = functionManager.getFunctionAt(functionAddr);
                        if (function == null) {
                            println("✗ " + functionAddressStr + ": No function found at address");
                            failCount++;
                            continue;
                        }
                        
                        // Verify function name matches (optional safety check)
                        if (!function.getName().equals(functionName)) {
                            println("⚠ " + functionAddressStr + ": Function name mismatch - expected '" + 
                                   functionName + "', found '" + function.getName() + "' (continuing anyway)");
                        }
                        
                        // Get data type for the parameter
                        DataType dataType = getDataType(newTypeStr);
                        if (dataType == null) {
                            println("  Primitive type '" + newTypeStr + "' not found, searching DataTypeManager...");
                            // Try to find custom structure type
                            dataType = findDataTypeByName(dtm, newTypeStr);
                            if (dataType != null) {
                            }
                        }
                        if (dataType == null) {
                            println("✗ " + functionAddressStr + ": Unknown data type '" + newTypeStr + "'");
                            println("  Available primitive types: uint8_t, uint16_t, uint32_t, byte, word, dword, pointers (type*)");
                            println("  Searching DataTypeManager for custom types...");
                            
                            // Debug: List available structures
                            java.util.Iterator<DataType> dtIter = dtm.getAllDataTypes();
                            int structCount = 0;
                            while (dtIter.hasNext() && structCount < 5) {
                                DataType dt = dtIter.next();
                                if (dt instanceof Structure) {
                                    println("    Found structure: " + dt.getName());
                                    structCount++;
                                }
                            }
                            if (structCount == 0) {
                                println("    No structures found in DataTypeManager");
                            }
                            
                            failCount++;
                            continue;
                        }
                        
                        // Get current parameters
                        Parameter[] parameters = function.getParameters();
                        
                        if (paramIndex >= parameters.length) {
                            println("✗ " + functionAddressStr + " (" + functionName + "): Parameter index " + 
                                   paramIndex + " out of range (function has " + parameters.length + " parameters)");
                            failCount++;
                            continue;
                        }
                        
                        // Get the parameter to modify
                        Parameter oldParam = parameters[paramIndex];
                        String oldName = oldParam.getName();
                        String oldType = oldParam.getDataType().getName();
                        
                        try {
                            // Create new parameter with updated name and type
                            Parameter newParam = new ParameterImpl(newParamName, dataType, currentProgram);
                            newParam.setComment(comment);
                            
                            // Update the parameter
                            parameters[paramIndex] = newParam;
                            function.updateFunction(null, null, java.util.Arrays.asList(parameters), 
                                                   Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, 
                                                   true, SourceType.USER_DEFINED);
                            successCount++;
                            
                        } catch (Exception e) {
                            println("✗ " + functionAddressStr + ": Failed to update parameter[" + paramIndex + 
                                   "] '" + oldName + "' → '" + newParamName + "' - " + e.getMessage());
                            failCount++;
                        }
                        
                    } catch (NumberFormatException e) {
                        println("✗ " + functionAddressStr + ": Invalid address or parameter index format");
                        failCount++;
                    } catch (Exception e) {
                        println("✗ " + functionAddressStr + ": Error processing parameter - " + e.getMessage());
                        failCount++;
                    }
                }
            }
            
            println("Results: " + successCount + " successful, " + failCount + " failed");
            
            if (successCount > 0) {
                println("Parameter changes will be visible in the Decompiler view.");
            }
            
        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
            println("Make sure function_parameters.csv is in your project root directory");
            return;
        }
    }
    
    // Helper method to convert string type to Ghidra DataType
    private DataType getDataType(String typeString) {
        // Handle pointer types specially
        if (typeString.endsWith("*")) {
            String baseType = typeString.substring(0, typeString.length() - 1).trim();
            println("    Handling pointer type: '" + typeString + "' -> base type: '" + baseType + "'");
            
            DataType baseDataType = getDataType(baseType);
            if (baseDataType == null) {
                println("    Base type '" + baseType + "' not found as primitive, checking DataTypeManager...");
                // Try to find custom structure type
                baseDataType = findDataTypeByName(currentProgram.getDataTypeManager(), baseType);
                if (baseDataType != null) {
                    println("    Found base type '" + baseType + "' in DataTypeManager: " + baseDataType.getClass().getSimpleName());
                } else {
                    println("    Base type '" + baseType + "' not found in DataTypeManager either");
                }
            } else {
                println("    Found base type '" + baseType + "' as primitive");
            }
            
            if (baseDataType != null) {
                PointerDataType ptrType = new PointerDataType(baseDataType);
                println("    Created pointer type: " + ptrType.getName());
                return ptrType;
            }
            println("    Failed to create pointer type for '" + typeString + "'");
            return null;
        }
        
        switch (typeString.toLowerCase()) {
            case "uint8_t":
            case "byte":
            case "uint8":
            case "char":
                return new ByteDataType();
            case "uint16_t":
            case "word":
            case "uint16":
            case "short":
                return new WordDataType();
            case "uint32_t":
            case "dword":
            case "uint32":
            case "int":
                return new DWordDataType();
            case "uint64_t":
            case "qword":
            case "uint64":
            case "long":
                return new QWordDataType();
            case "float":
                return new FloatDataType();
            case "double":
                return new DoubleDataType();
            case "undefined4":
                return new Undefined4DataType();
            case "void":
                return new VoidDataType();
            default:
                return null;
        }
    }
    
    // Helper method to find DataType by name (handles category paths)
    private DataType findDataTypeByName(DataTypeManager dtm, String typeName) {
        java.util.Iterator<DataType> dtIter = dtm.getAllDataTypes();
        while (dtIter.hasNext()) {
            DataType dt = dtIter.next();
            if (dt.getName().equals(typeName)) {
                return dt;
            }
        }
        return null;
    }
}