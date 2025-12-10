// Ghidra Bulk Local Variable Renamer Script
// Reads from local_variables.csv and renames/retypes local variables in the decompiler
// Matches variables by first-use address for stability (variable names can shift during renames)
// @author J90280.05_analysis
// @category Analysis
// @keybinding
// @menupath Tools.Bulk Local Variable Renamer
// @toolbar

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
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
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighFunctionDBUtil;
import ghidra.program.model.pcode.HighSymbol;
import ghidra.program.model.pcode.LocalSymbolMap;
import ghidra.program.model.pcode.HighVariable;
import ghidra.program.model.pcode.Varnode;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.symbol.SourceType;

public class BulkLocalVariableRenamer extends GhidraScript {

    private DecompInterface decompiler;

    // Holds pending renames for a single function
    private static class VariableRename {
        String firstUseAddress;
        String newVarName;
        String newTypeStr;
        String comment;

        VariableRename(String firstUseAddress, String newVarName, String newTypeStr, String comment) {
            this.firstUseAddress = firstUseAddress;
            this.newVarName = newVarName;
            this.newTypeStr = newTypeStr;
            this.comment = comment;
        }
    }

    @Override
    public void run() throws Exception {
        // Path to CSV file
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                        "/local_variables.csv";

        println("=== Bulk Local Variable Renamer (First-Use Address Matching) ===");
        println("Reading from: " + csvPath);
        println("");

        FunctionManager functionManager = currentProgram.getFunctionManager();
        DataTypeManager dtm = currentProgram.getDataTypeManager();

        // Initialize decompiler
        decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        decompiler.setOptions(options);

        if (!decompiler.openProgram(currentProgram)) {
            println("ERROR: Failed to initialize decompiler");
            return;
        }

        int successCount = 0;
        int failCount = 0;
        int skipCount = 0;

        // Group renames by function address for efficient processing
        Map<Long, List<VariableRename>> renamesByFunction = new HashMap<>();
        Map<Long, String> functionNames = new HashMap<>();

        // Read CSV file and group by function
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;

            while ((line = br.readLine()) != null) {
                // Skip header line
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                // Skip empty lines and comments
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }

                // Parse CSV: function_address,function_name,first_use_address,new_variable_name,type,comment
                String[] parts = line.split(",", 6);
                if (parts.length < 5) {
                    println("⚠ Skipping malformed line: " + line);
                    skipCount++;
                    continue;
                }

                String functionAddressStr = parts[0].trim();
                String functionName = parts[1].trim();
                String firstUseAddress = parts[2].trim();
                String newVarName = parts[3].trim();
                String newTypeStr = parts[4].trim();
                String comment = parts.length > 5 ? parts[5].trim() : "";

                try {
                    long functionAddressLong = parseHexAddress(functionAddressStr);

                    // Group by function
                    renamesByFunction.computeIfAbsent(functionAddressLong, k -> new ArrayList<>())
                        .add(new VariableRename(firstUseAddress, newVarName, newTypeStr, comment));
                    functionNames.put(functionAddressLong, functionName);

                } catch (NumberFormatException e) {
                    println("✗ " + functionAddressStr + ": Invalid address format");
                    failCount++;
                }
            }

        } catch (IOException e) {
            println("ERROR: Cannot read CSV file: " + e.getMessage());
            println("Make sure local_variables.csv exists in your project directory");
            decompiler.dispose();
            return;
        }

        // Process each function
        for (Map.Entry<Long, List<VariableRename>> entry : renamesByFunction.entrySet()) {
            long functionAddressLong = entry.getKey();
            List<VariableRename> renames = entry.getValue();
            String functionName = functionNames.get(functionAddressLong);
            String functionAddressStr = "0x" + String.format("%08x", functionAddressLong);

            Address functionAddr = toAddr(functionAddressLong);
            Function function = functionManager.getFunctionAt(functionAddr);

            if (function == null) {
                println("✗ 0x" + Long.toHexString(functionAddressLong) + ": No function found at address");
                failCount += renames.size();
                continue;
            }

            println("\nProcessing function: " + functionName + " @ 0x" + Long.toHexString(functionAddressLong));

            // Process each rename, re-decompiling after each successful rename
            for (VariableRename rename : renames) {
                // Decompile (or re-decompile) the function
                DecompileResults results = decompiler.decompileFunction(function, 30, monitor);
                if (!results.decompileCompleted()) {
                    println("  ✗ Decompilation failed for " + rename.newVarName);
                    failCount++;
                    continue;
                }

                HighFunction highFunc = results.getHighFunction();
                if (highFunc == null) {
                    println("  ✗ No high function available for " + rename.newVarName);
                    failCount++;
                    continue;
                }

                // Check if this is an index-based discovery request (small integer 0-99)
                long addrValue = parseHexAddress(rename.firstUseAddress);
                if (addrValue >= 0 && addrValue < 100) {
                    int varIndex = (int) addrValue;
                    // Get variables sorted by first-use address and select by index
                    List<HighSymbol> sortedVars = getVariablesSortedByFirstUse(highFunc);

                    if (varIndex < sortedVars.size()) {
                        HighSymbol targetSymbol = sortedVars.get(varIndex);
                        Address discoveredAddr = getFirstUseAddress(targetSymbol);
                        String oldName = targetSymbol.getName();

                        if (discoveredAddr != null) {
                            String addrHex = "0x" + Long.toHexString(discoveredAddr.getOffset());

                            // Update CSV with discovered address
                            try {
                                updateCsvAddress(csvPath, functionAddressStr, rename.firstUseAddress,
                                                rename.newVarName, addrHex);
                                println("  ✓ Index " + varIndex + " → '" + oldName + "' at " + addrHex);
                                println("      CSV updated with address. Applying rename...");
                            } catch (IOException e) {
                                println("  ⚠ CSV update failed: " + e.getMessage());
                                // Continue with rename anyway
                            }

                            // Now apply the rename
                            DataType dataType = null;
                            if (!rename.newTypeStr.isEmpty() && !rename.newTypeStr.equals("-")) {
                                dataType = getDataType(rename.newTypeStr, dtm);
                            }

                            try {
                                if (dataType != null) {
                                    HighFunctionDBUtil.updateDBVariable(
                                        targetSymbol, rename.newVarName, dataType, SourceType.USER_DEFINED);
                                    println("  ✓ " + oldName + " → " + rename.newVarName +
                                           " (" + dataType.getName() + ")");
                                } else {
                                    HighFunctionDBUtil.updateDBVariable(
                                        targetSymbol, rename.newVarName, null, SourceType.USER_DEFINED);
                                    println("  ✓ " + oldName + " → " + rename.newVarName);
                                }
                                successCount++;
                            } catch (Exception e) {
                                println("  ✗ Rename failed: " + e.getMessage());
                                failCount++;
                            }
                        } else {
                            println("  ✗ Could not determine address for index " + varIndex);
                            failCount++;
                        }
                    } else {
                        println("  ✗ Index " + varIndex + " out of range (function has " +
                               sortedVars.size() + " variables)");
                        println("      Available variables (sorted by first-use address):");
                        for (int i = 0; i < sortedVars.size() && i < 20; i++) {
                            HighSymbol sym = sortedVars.get(i);
                            Address addr = getFirstUseAddress(sym);
                            String addrStr = (addr != null) ? "0x" + Long.toHexString(addr.getOffset()) : "unknown";
                            println("        [" + i + "] " + sym.getName() + " (" +
                                   sym.getDataType().getName() + ") at " + addrStr);
                        }
                        failCount++;
                    }
                    continue;
                }

                // Find variable by first-use address
                HighSymbol targetSymbol = findVariableByFirstUseAddress(highFunc, rename.firstUseAddress);

                if (targetSymbol == null) {
                    println("  ✗ No variable found with first-use at " + rename.firstUseAddress);
                    println("      Searching for: " + rename.newVarName);
                    listVariablesWithAddresses(highFunc);
                    failCount++;
                    continue;
                }

                // Get or create the data type
                DataType dataType = null;
                if (!rename.newTypeStr.isEmpty() && !rename.newTypeStr.equals("-")) {
                    dataType = getDataType(rename.newTypeStr, dtm);
                    if (dataType == null) {
                        println("  ⚠ Unknown type '" + rename.newTypeStr + "', will rename without retyping");
                    }
                }

                // Rename the variable
                try {
                    String oldName = targetSymbol.getName();

                    if (dataType != null) {
                        HighFunctionDBUtil.updateDBVariable(
                            targetSymbol, rename.newVarName, dataType, SourceType.USER_DEFINED);
                        println("  ✓ " + oldName + " → " + rename.newVarName +
                               " (" + dataType.getName() + ") [first-use: " + rename.firstUseAddress + "]");
                    } else {
                        HighFunctionDBUtil.updateDBVariable(
                            targetSymbol, rename.newVarName, null, SourceType.USER_DEFINED);
                        println("  ✓ " + oldName + " → " + rename.newVarName +
                               " [first-use: " + rename.firstUseAddress + "]");
                    }
                    successCount++;

                } catch (Exception e) {
                    println("  ✗ Failed to rename to '" + rename.newVarName + "' - " + e.getMessage());
                    failCount++;
                }
            }
        }

        // Cleanup
        decompiler.dispose();

        println("");
        println("=== Summary ===");
        println("Successful: " + successCount);
        println("Failed: " + failCount);
        println("Skipped: " + skipCount);

        if (successCount > 0) {
            println("");
            println("Variable renames will be visible in the Decompiler view.");
            println("You may need to re-decompile functions to see changes.");
        }
    }

    /**
     * Find a HighSymbol by its first-use/definition address
     */
    private HighSymbol findVariableByFirstUseAddress(HighFunction highFunc, String targetAddressStr) {
        long targetAddr = parseHexAddress(targetAddressStr);

        LocalSymbolMap localSymbolMap = highFunc.getLocalSymbolMap();
        Iterator<HighSymbol> symbols = localSymbolMap.getSymbols();

        while (symbols.hasNext()) {
            HighSymbol sym = symbols.next();

            // Get the first use/definition address for this symbol
            Address firstUse = getFirstUseAddress(sym);

            if (firstUse != null && firstUse.getOffset() == targetAddr) {
                return sym;
            }
        }

        return null;
    }

    /**
     * Get the address where a variable is first used/defined
     */
    private Address getFirstUseAddress(HighSymbol symbol) {
        // Try to get the PCAddress (where the symbol is defined/first used)
        Address pcAddr = symbol.getPCAddress();
        if (pcAddr != null && !pcAddr.equals(Address.NO_ADDRESS)) {
            return pcAddr;
        }

        // Fallback: examine the HighVariable's varnodes for the defining PcodeOp
        HighVariable highVar = symbol.getHighVariable();
        if (highVar != null) {
            Varnode[] instances = highVar.getInstances();
            Address earliest = null;

            for (Varnode vn : instances) {
                // Check if this varnode has a defining PcodeOp
                PcodeOp defOp = vn.getDef();
                if (defOp != null) {
                    Address defAddr = defOp.getSeqnum().getTarget();
                    if (earliest == null || defAddr.getOffset() < earliest.getOffset()) {
                        earliest = defAddr;
                    }
                }
            }

            if (earliest != null) {
                return earliest;
            }
        }

        return null;
    }

    /**
     * List all variables with their first-use addresses for debugging
     */
    private void listVariablesWithAddresses(HighFunction highFunc) {
        println("      Available variables:");
        LocalSymbolMap localSymbolMap = highFunc.getLocalSymbolMap();
        Iterator<HighSymbol> symbols = localSymbolMap.getSymbols();
        int count = 0;

        while (symbols.hasNext() && count < 20) {
            HighSymbol sym = symbols.next();
            Address firstUse = getFirstUseAddress(sym);
            String addrStr = (firstUse != null) ? "0x" + Long.toHexString(firstUse.getOffset()) : "unknown";
            println("        - " + sym.getName() + " (" + sym.getDataType().getName() +
                   ") first-use: " + addrStr);
            count++;
        }
    }

    /**
     * Parse address string to long
     */
    private long parseHexAddress(String addressStr) {
        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
            return Long.parseLong(addressStr.substring(2), 16);
        }
        return Long.parseLong(addressStr, 16);
    }

    /**
     * Convert string type to Ghidra DataType
     */
    private DataType getDataType(String typeString, DataTypeManager dtm) {
        // Handle pointer types
        if (typeString.endsWith("*")) {
            String baseType = typeString.substring(0, typeString.length() - 1).trim();
            DataType baseDataType = getDataType(baseType, dtm);
            if (baseDataType != null) {
                return new PointerDataType(baseDataType);
            }
            DataType foundType = findDataTypeByName(dtm, baseType);
            if (foundType != null) {
                return new PointerDataType(foundType);
            }
            return null;
        }

        // Check primitive types
        switch (typeString.toLowerCase()) {
            case "uint8_t":
            case "byte":
            case "uint8":
            case "uchar":
            case "unsigned char":
                return new ByteDataType();
            case "char":
            case "int8_t":
            case "int8":
                return new CharDataType();
            case "uint16_t":
            case "word":
            case "uint16":
            case "ushort":
            case "unsigned short":
                return new UnsignedShortDataType();
            case "short":
            case "int16_t":
            case "int16":
                return new ShortDataType();
            case "uint32_t":
            case "dword":
            case "uint32":
            case "uint":
            case "unsigned int":
                return new UnsignedIntegerDataType();
            case "int":
            case "int32_t":
            case "int32":
                return new IntegerDataType();
            case "uint64_t":
            case "qword":
            case "uint64":
            case "unsigned long":
                return new UnsignedLongDataType();
            case "long":
            case "int64_t":
            case "int64":
                return new LongDataType();
            case "float":
                return new FloatDataType();
            case "double":
                return new DoubleDataType();
            case "bool":
            case "boolean":
                return new BooleanDataType();
            case "void":
                return new VoidDataType();
            case "undefined":
            case "undefined1":
                return new Undefined1DataType();
            case "undefined2":
                return new Undefined2DataType();
            case "undefined4":
                return new Undefined4DataType();
            default:
                return findDataTypeByName(dtm, typeString);
        }
    }

    /**
     * Find DataType by name in DataTypeManager
     */
    private DataType findDataTypeByName(DataTypeManager dtm, String typeName) {
        Iterator<DataType> dtIter = dtm.getAllDataTypes();
        while (dtIter.hasNext()) {
            DataType dt = dtIter.next();
            if (dt.getName().equals(typeName)) {
                return dt;
            }
        }
        return null;
    }

    /**
     * Get all local variables sorted by first-use address (lowest to highest)
     * This provides a stable ordering for index-based selection
     */
    private List<HighSymbol> getVariablesSortedByFirstUse(HighFunction highFunc) {
        List<HighSymbol> variables = new ArrayList<>();
        LocalSymbolMap localSymbolMap = highFunc.getLocalSymbolMap();
        Iterator<HighSymbol> symbols = localSymbolMap.getSymbols();

        while (symbols.hasNext()) {
            HighSymbol sym = symbols.next();
            // Only include local variables (not parameters)
            if (sym.getHighVariable() != null) {
                variables.add(sym);
            }
        }

        // Sort by first-use address
        variables.sort((a, b) -> {
            Address addrA = getFirstUseAddress(a);
            Address addrB = getFirstUseAddress(b);
            if (addrA == null && addrB == null) return 0;
            if (addrA == null) return 1;
            if (addrB == null) return -1;
            return Long.compare(addrA.getOffset(), addrB.getOffset());
        });

        return variables;
    }

    /**
     * Update CSV file with discovered first-use address
     * Replaces index placeholder with actual address for matching entry
     */
    private void updateCsvAddress(String csvPath, String functionAddr, String oldIndex,
                                  String varName, String newAddress) throws IOException {
        List<String> lines = Files.readAllLines(Paths.get(csvPath));
        List<String> updatedLines = new ArrayList<>();

        for (String line : lines) {
            // Preserve comments, empty lines, and header
            if (line.startsWith("#") || line.trim().isEmpty() || line.startsWith("function_address")) {
                updatedLines.add(line);
                continue;
            }

            String[] parts = line.split(",", 6);
            if (parts.length >= 4 &&
                parts[0].trim().equals(functionAddr) &&
                parts[3].trim().equals(varName) &&
                parts[2].trim().equals(oldIndex)) {
                // Update this line with discovered address
                parts[2] = newAddress;
                updatedLines.add(String.join(",", parts));
            } else {
                updatedLines.add(line);
            }
        }

        Files.write(Paths.get(csvPath), updatedLines);
    }
}
