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
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
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

        // Import 2: Global variables
        String varFile = inputDir + "/global_variables.csv";
        if (new File(varFile).exists()) {
            println("[2/2] Importing global variables...");
            int varChanges = importGlobalVariables(varFile);
            println("  Applied " + varChanges + " variable names");
            totalChanges += varChanges;
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
                if (line.isEmpty()) {
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

    private int importGlobalVariables(String csvPath) throws Exception {
        SymbolTable symbolTable = currentProgram.getSymbolTable();
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
                if (line.isEmpty()) {
                    continue;
                }

                // Parse: address,name,type,comment
                String[] parts = line.split(",");
                if (parts.length < 2) {
                    continue;
                }

                String addressStr = parts[0].trim();
                String newName = parts[1].trim();

                try {
                    long addressValue = parseAddressString(addressStr);
                    Address address = toAddr(addressValue);

                    // Check if symbol already exists with this name
                    Symbol existingSymbol = symbolTable.getPrimarySymbol(address);
                    if (existingSymbol != null && existingSymbol.getName().equals(newName)) {
                        skipped++;
                        continue;
                    }

                    // Create or rename symbol
                    if (existingSymbol != null) {
                        existingSymbol.setName(newName, SourceType.USER_DEFINED);
                    } else {
                        symbolTable.createLabel(address, newName, SourceType.USER_DEFINED);
                    }

                    changesApplied++;

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

        return changesApplied;
    }

    private long parseAddressString(String addressStr) {
        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
            return Long.parseLong(addressStr.substring(2), 16);
        }
        return Long.parseLong(addressStr, 16);
    }
}
