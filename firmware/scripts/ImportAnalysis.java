// Import Analysis Script
// Imports function names and global variables from CSV files
// Applies changes incrementally to Ghidra project
// @author J90350.00_analysis
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.DataTypeManager;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.data.ByteDataType;
import ghidra.program.model.data.WordDataType;
import ghidra.program.model.data.DWordDataType;
import ghidra.program.model.data.QWordDataType;
import ghidra.program.model.data.SignedByteDataType;
import ghidra.program.model.data.SignedWordDataType;
import ghidra.program.model.data.SignedDWordDataType;
import ghidra.program.model.data.Undefined1DataType;
import ghidra.program.model.data.Undefined2DataType;
import ghidra.program.model.data.Undefined4DataType;
import ghidra.program.model.data.Undefined8DataType;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

public class ImportAnalysis extends GhidraScript {

    @Override
    public void run() throws Exception {
        // Get firmware name from program (e.g., "J90280.05.full.bin" -> "J90280.05")
        String programName = currentProgram.getName();
        String firmwareName = programName.replaceAll("\\.full\\.bin$", "").replaceAll("\\.rom\\.bin$", "").replaceAll("\\.bin$", "");

        println("=".repeat(70));
        println("IMPORT ANALYSIS - " + firmwareName);
        println("=".repeat(70));
        println("");

        // Get input directory from arguments or use default
        String[] args = getScriptArgs();
        String inputDir;

        if (args.length > 0) {
            inputDir = args[0];
        } else {
            inputDir = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../output";
        }

        println("Input directory: " + inputDir);
        println("");

        int totalChanges = 0;

        // Import 1: Function names
        String funcFile = inputDir + "/function_renames.csv";
        if (new File(funcFile).exists()) {
            println("[1/2] Importing function names...");
            int funcChanges = importFunctionNames(funcFile);
            println("  Applied " + funcChanges + " function renames");
            totalChanges += funcChanges;
        } else {
            println("[1/2] Skipping function names - file not found");
        }

        // Import 2: Global variables (names and types)
        String varFile = inputDir + "/global_variables.csv";
        if (new File(varFile).exists()) {
            println("[2/2] Importing global variables...");
            int[] varResults = importGlobalVariables(varFile);
            println("  Applied " + varResults[0] + " variable names");
            println("  Applied " + varResults[1] + " data types");
            totalChanges += varResults[0] + varResults[1];
        } else {
            println("[2/2] Skipping global variables - file not found");
        }

        println("");
        println("=".repeat(70));
        println("IMPORT COMPLETE!");
        println("Total changes applied: " + totalChanges);
        println("=".repeat(70));
    }

    private int importFunctionNames(String csvPath) throws Exception {
        FunctionManager functionManager = currentProgram.getFunctionManager();
        int changesApplied = 0;
        int skipped = 0;
        int failed = 0;

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
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }

                // Parse: address,name
                String[] parts = line.split(",", 2);
                if (parts.length < 2) {
                    continue;
                }

                String addressStr = parts[0].trim();
                String newName = parts[1].trim();

                try {
                    long addressValue = parseAddressString(addressStr);
                    Address address = toAddr(addressValue);

                    Function func = functionManager.getFunctionAt(address);
                    if (func == null) {
                        // Try to create function
                        func = createFunction(address, newName);
                        if (func != null) {
                            changesApplied++;
                        } else {
                            failed++;
                        }
                        continue;
                    }

                    // Check if name already matches
                    if (func.getName().equals(newName)) {
                        skipped++;
                        continue;
                    }

                    // Apply rename
                    func.setName(newName, SourceType.USER_DEFINED);
                    changesApplied++;

                } catch (NumberFormatException e) {
                    failed++;
                } catch (Exception e) {
                    failed++;
                }
            }
        }

        if (failed > 0) {
            println("  WARNING: " + failed + " function imports failed");
        }

        return changesApplied;
    }

    private int[] importGlobalVariables(String csvPath) throws Exception {
        SymbolTable symbolTable = currentProgram.getSymbolTable();
        Listing listing = currentProgram.getListing();
        int nameChanges = 0;
        int typeChanges = 0;
        int typeSkippedMatch = 0;
        int typeSkippedNoType = 0;
        int typeSkippedOutOfRange = 0;
        int typeFailed = 0;
        int skipped = 0;
        int failed = 0;

        long maxAddress = currentProgram.getMaxAddress().getOffset();

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
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }

                // Parse: address,name,type,comment
                String[] parts = line.split(",", -1);  // -1 to keep empty trailing fields
                if (parts.length < 2) {
                    continue;
                }

                String addressStr = parts[0].trim();
                String newName = parts[1].trim();
                String typeStr = (parts.length > 2) ? parts[2].trim() : "";

                try {
                    long addressValue = parseAddressString(addressStr);
                    Address address = toAddr(addressValue);

                    // Apply name if different
                    Symbol existingSymbol = symbolTable.getPrimarySymbol(address);
                    boolean nameMatches = (existingSymbol != null && existingSymbol.getName().equals(newName));

                    if (!nameMatches) {
                        if (existingSymbol != null) {
                            existingSymbol.setName(newName, SourceType.USER_DEFINED);
                        } else {
                            symbolTable.createLabel(address, newName, SourceType.USER_DEFINED);
                        }
                        nameChanges++;
                    }

                    // Apply data type if specified
                    if (!typeStr.isEmpty()) {
                        // Skip addresses outside loaded memory
                        if (addressValue > maxAddress) {
                            typeSkippedOutOfRange++;
                            continue;
                        }

                        DataType dataType = mapCsvTypeToDataType(typeStr);
                        if (dataType == null) {
                            typeSkippedNoType++;
                            continue;
                        }

                        // Check if type already matches
                        Data existingData = listing.getDataAt(address);
                        boolean typeMatches = (existingData != null &&
                            existingData.getDataType().getName().equals(dataType.getName()));

                        if (typeMatches) {
                            typeSkippedMatch++;
                            continue;
                        }

                        try {
                            // Clear existing data at address if needed
                            if (existingData != null) {
                                listing.clearCodeUnits(address, address.add(dataType.getLength() - 1), false);
                            }
                            // Create data with the specified type
                            listing.createData(address, dataType);
                            typeChanges++;
                        } catch (Exception e) {
                            // Type application failed - might conflict with existing code/data
                            typeFailed++;
                        }
                    }

                } catch (NumberFormatException e) {
                    failed++;
                } catch (Exception e) {
                    failed++;
                }
            }
        }

        if (failed > 0) {
            println("  WARNING: " + failed + " variable imports failed");
        }

        // Debug output for type application
        if (typeSkippedOutOfRange > 0 || typeFailed > 0) {
            println("  Type stats: " + typeSkippedOutOfRange + " out-of-range, " +
                    typeSkippedMatch + " already match, " +
                    typeSkippedNoType + " unmapped type, " +
                    typeFailed + " failed (in code)");
        }

        return new int[] { nameChanges, typeChanges };
    }

    /**
     * Maps CSV type strings to Ghidra DataType objects.
     * Supports both our CSV format (u8, u16, etc.) and Ghidra's export format (byte, word, etc.)
     */
    private DataType mapCsvTypeToDataType(String typeStr) {
        switch (typeStr.toLowerCase()) {
            // Unsigned integers (CSV format)
            case "u8":
            case "byte":
                return ByteDataType.dataType;
            case "u16":
            case "word":
                return WordDataType.dataType;
            case "u32":
            case "dword":
                return DWordDataType.dataType;
            case "u64":
            case "qword":
                return QWordDataType.dataType;

            // Signed integers
            case "i8":
                return SignedByteDataType.dataType;
            case "i16":
                return SignedWordDataType.dataType;
            case "i32":
                return SignedDWordDataType.dataType;

            // Pointer
            case "pointer":
                return PointerDataType.dataType;

            // Undefined (explicit size)
            case "undefined1":
                return Undefined1DataType.dataType;
            case "undefined2":
                return Undefined2DataType.dataType;
            case "undefined4":
                return Undefined4DataType.dataType;
            case "undefined8":
                return Undefined8DataType.dataType;

            // Skip these - they're Ghidra defaults or not useful to apply
            case "undefined":
            case "undefined *":
            case "":
                return null;

            default:
                // Unknown type - skip
                return null;
        }
    }

    private long parseAddressString(String addressStr) {
        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
            return Long.parseLong(addressStr.substring(2), 16);
        }
        return Long.parseLong(addressStr, 16);
    }
}
