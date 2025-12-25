// Apply Global Variable Types Script
// Reads global_variables.csv and applies data types at each address
// Clears existing data before applying to handle stale types
// @author J90350.00_analysis
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;
import java.util.HashMap;
import java.util.Map;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.SymbolTable;

public class ApplyGlobalVariableTypes extends GhidraScript {

    private DataTypeManager dtm;
    private Listing listing;
    private SymbolTable symbolTable;

    // Map CSV type names to Ghidra data types
    private static final Map<String, String> TYPE_MAP = new HashMap<>();
    static {
        TYPE_MAP.put("byte", "byte");
        TYPE_MAP.put("word", "word");
        TYPE_MAP.put("dword", "dword");
        TYPE_MAP.put("short", "short");
        TYPE_MAP.put("ushort", "ushort");
        TYPE_MAP.put("uint16_t", "ushort");
        TYPE_MAP.put("uint32_t", "uint");
        TYPE_MAP.put("int", "int");
        TYPE_MAP.put("uint", "uint");
        TYPE_MAP.put("undefined", "undefined");
        TYPE_MAP.put("undefined1", "byte");
        TYPE_MAP.put("undefined2", "word");
        TYPE_MAP.put("undefined4", "dword");
    }

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY GLOBAL VARIABLE TYPES");
        println("=".repeat(70));
        println("");

        dtm = currentProgram.getDataTypeManager();
        listing = currentProgram.getListing();
        symbolTable = currentProgram.getSymbolTable();

        // Get input file from arguments or use default
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../output/global_variables.csv";
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: global_variables.csv not found!");
            return;
        }

        int applied = 0;
        int cleared = 0;
        int skipped = 0;
        int failed = 0;

        int txId = currentProgram.startTransaction("Apply Global Variable Types");

        try (BufferedReader reader = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;

            while ((line = reader.readLine()) != null) {
                // Skip header
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                line = line.trim();

                // Skip empty lines and comments
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }

                // Parse CSV: address,name,type,comment
                String[] parts = line.split(",");
                if (parts.length < 2) {
                    continue;
                }

                String addressStr = parts[0].trim();
                String varName = parts[1].trim();
                String typeName = parts.length > 2 ? parts[2].trim() : "";

                // Skip entries with empty type - leave as is
                if (typeName.isEmpty()) {
                    skipped++;
                    continue;
                }

                // Skip entries that are struct field references (contain '.')
                if (varName.contains(".")) {
                    skipped++;
                    continue;
                }

                try {
                    long addressValue = parseAddressString(addressStr);
                    Address addr = toAddr(addressValue);

                    // Get the data type to apply
                    DataType newType = getDataType(typeName);

                    if (newType == null) {
                        // Type not recognized - might be a struct type
                        // Try to find it in the data type manager
                        newType = findStructureType(typeName);
                    }

                    if (newType == null) {
                        // Still not found - skip but don't count as failed
                        skipped++;
                        continue;
                    }

                    // Clear existing data at this address
                    Data existingData = listing.getDataAt(addr);
                    if (existingData != null) {
                        int existingLen = existingData.getLength();
                        try {
                            listing.clearCodeUnits(addr, addr.add(existingLen - 1), false);
                            cleared++;
                        } catch (Exception e) {
                            // Clear failed - skip this address
                            failed++;
                            continue;
                        }
                    }

                    // Apply the new type
                    try {
                        listing.createData(addr, newType);
                        applied++;
                    } catch (Exception e) {
                        failed++;
                    }

                } catch (NumberFormatException e) {
                    failed++;
                } catch (Exception e) {
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        println("");
        println("=".repeat(70));
        println("RESULTS:");
        println("  Types applied: " + applied);
        println("  Data cleared:  " + cleared);
        println("  Skipped:       " + skipped + " (empty type or struct fields)");
        println("  Failed:        " + failed);
        println("=".repeat(70));
    }

    private DataType getDataType(String typeName) {
        if (typeName == null || typeName.isEmpty()) {
            return null;
        }

        String lowerType = typeName.toLowerCase();

        switch (lowerType) {
            case "byte":
            case "undefined1":
                return ByteDataType.dataType;
            case "word":
            case "ushort":
            case "uint16_t":
            case "undefined2":
                return WordDataType.dataType;
            case "short":
                return ShortDataType.dataType;
            case "dword":
            case "uint":
            case "uint32_t":
            case "undefined4":
                return DWordDataType.dataType;
            case "int":
                return IntegerDataType.dataType;
            case "undefined":
                return Undefined1DataType.dataType;
            default:
                return null; // Let caller try struct lookup
        }
    }

    private DataType findStructureType(String typeName) {
        // Search in our custom category first
        CategoryPath customPath = new CategoryPath("/J90350_Structures");
        DataType dt = dtm.getDataType(customPath, typeName);
        if (dt != null) {
            return dt;
        }

        // Search in root
        dt = dtm.getDataType("/" + typeName);
        if (dt != null) {
            return dt;
        }

        // Search all categories
        java.util.Iterator<DataType> dtIter = dtm.getAllDataTypes();
        while (dtIter.hasNext()) {
            DataType foundDt = dtIter.next();
            if (foundDt.getName().equals(typeName)) {
                return foundDt;
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
}
