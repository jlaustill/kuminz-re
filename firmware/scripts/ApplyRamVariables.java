// Apply RAM Variables Script
// Imports RAM variable names from J90280.05 global_variables.csv
// RAM addresses are fixed between firmware versions, so they transfer directly
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
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Data;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

public class ApplyRamVariables extends GhidraScript {

    // RAM address range
    private static final long RAM_START = 0x800000L;
    private static final long RAM_END = 0x810000L;

    @Override
    public void run() throws Exception {
        println("======================================================================");
        println("APPLY RAM VARIABLES - From J90280.05");
        println("======================================================================");
        println("");

        // Get CSV path from arguments or use default
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../../J90280.05_analysis/ghidra/CM550.rep/global_variables.csv";
        }

        File csvFile = new File(csvPath);
        if (!csvFile.exists()) {
            println("ERROR: CSV file not found at " + csvPath);
            return;
        }

        println("Reading variables from: " + csvPath);
        println("RAM range: " + String.format("0x%08x - 0x%08x", RAM_START, RAM_END));
        println("");

        // Check if RAM block exists
        Memory memory = currentProgram.getMemory();
        MemoryBlock ramBlock = memory.getBlock(toAddr(RAM_START));
        if (ramBlock == null) {
            println("WARNING: RAM memory block not found at 0x800000");
            println("Run 'memmap' command first to add RAM region");
            println("Continuing anyway - labels will be created but data won't be accessible");
            println("");
        }

        SymbolTable symbolTable = currentProgram.getSymbolTable();
        DataTypeManager dtm = currentProgram.getDataTypeManager();

        int createdCount = 0;
        int renamedCount = 0;
        int skippedCount = 0;
        int failedCount = 0;
        int totalRamVars = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(csvFile))) {
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

                // Parse CSV: address,name,type,comment,length,...
                String[] parts = line.split(",", -1);
                if (parts.length < 4) {
                    continue;
                }

                String addressStr = parts[0].trim();
                String name = parts[1].trim();
                String typeStr = parts[2].trim();
                String comment = parts[3].trim();

                // Parse address
                long addressValue;
                try {
                    if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
                        addressValue = Long.parseLong(addressStr.substring(2), 16);
                    } else {
                        addressValue = Long.parseLong(addressStr, 16);
                    }
                } catch (NumberFormatException e) {
                    continue;
                }

                // Only process RAM addresses
                if (addressValue < RAM_START || addressValue >= RAM_END) {
                    continue;
                }

                totalRamVars++;
                Address address = toAddr(addressValue);

                try {
                    // Check if symbol already exists
                    Symbol existingSymbol = symbolTable.getPrimarySymbol(address);

                    if (existingSymbol != null) {
                        String existingName = existingSymbol.getName();
                        // Skip if already has a non-default name
                        if (!existingName.startsWith("DAT_") &&
                            !existingName.startsWith("BYTE_") &&
                            !existingName.startsWith("WORD_") &&
                            !existingName.startsWith("DWORD_")) {
                            skippedCount++;
                            continue;
                        }
                        // Rename existing symbol
                        existingSymbol.setName(name, SourceType.USER_DEFINED);
                        renamedCount++;
                    } else {
                        // Create new label
                        symbolTable.createLabel(address, name, SourceType.USER_DEFINED);
                        createdCount++;
                    }

                    // Set comment if provided
                    if (!comment.isEmpty()) {
                        setEOLComment(address, comment);
                    }

                    // Try to apply data type
                    applyDataType(address, typeStr, dtm);

                } catch (Exception e) {
                    failedCount++;
                }

                // Progress indicator
                if (totalRamVars % 500 == 0) {
                    println("  Processed " + totalRamVars + " RAM variables...");
                }
            }
        }

        println("");
        println("======================================================================");
        println("RESULTS");
        println("----------------------------------------------------------------------");
        println("  RAM variables found:   " + totalRamVars);
        println("  Labels created:        " + createdCount);
        println("  Labels renamed:        " + renamedCount);
        println("  Skipped (named):       " + skippedCount);
        println("  Failed:                " + failedCount);
        println("  Total applied:         " + (createdCount + renamedCount));
        println("======================================================================");

        if (failedCount == 0) {
            println("SUCCESS: RAM variables applied!");
        } else {
            println("WARNING: Some variables failed - see log for details");
        }
    }

    private void applyDataType(Address address, String typeStr, DataTypeManager dtm) {
        if (typeStr.isEmpty()) {
            return;
        }

        try {
            DataType dataType = null;

            // Map common type strings to Ghidra data types
            String typeLower = typeStr.toLowerCase();

            if (typeLower.equals("byte")) {
                dataType = ByteDataType.dataType;
            } else if (typeLower.equals("word")) {
                dataType = WordDataType.dataType;
            } else if (typeLower.equals("dword")) {
                dataType = DWordDataType.dataType;
            } else if (typeLower.equals("qword")) {
                dataType = QWordDataType.dataType;
            } else if (typeLower.startsWith("byte[")) {
                // Parse array size: byte[60]
                int start = typeLower.indexOf('[') + 1;
                int end = typeLower.indexOf(']');
                if (start > 0 && end > start) {
                    int size = Integer.parseInt(typeLower.substring(start, end));
                    dataType = new ArrayDataType(ByteDataType.dataType, size, 1);
                }
            } else if (typeLower.startsWith("word[")) {
                int start = typeLower.indexOf('[') + 1;
                int end = typeLower.indexOf(']');
                if (start > 0 && end > start) {
                    int size = Integer.parseInt(typeLower.substring(start, end));
                    dataType = new ArrayDataType(WordDataType.dataType, size, 2);
                }
            }

            if (dataType != null) {
                // Clear any existing data first
                Data existingData = currentProgram.getListing().getDataAt(address);
                if (existingData != null) {
                    clearListing(address, address.add(dataType.getLength() - 1));
                }
                createData(address, dataType);
            }
        } catch (Exception e) {
            // Silently ignore data type errors - label is still useful
        }
    }
}
