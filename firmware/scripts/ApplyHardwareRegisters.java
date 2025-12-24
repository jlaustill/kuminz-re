// Apply Hardware Register Names Script
// Applies MC68336 peripheral register names from J90280.05 global_variables.csv
// Hardware registers (0x00FFxxxx) are identical between firmware versions
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
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

public class ApplyHardwareRegisters extends GhidraScript {

    private SymbolTable symbolTable;
    private Listing listing;
    private DataTypeManager dtm;

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY HARDWARE REGISTER NAMES - J90350.00");
        println("=".repeat(70));
        println("");

        symbolTable = currentProgram.getSymbolTable();
        listing = currentProgram.getListing();
        dtm = currentProgram.getDataTypeManager();

        // Get input file from arguments or use default
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            // Default to J90280.05's global_variables.csv
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../../J90280.05_analysis/ghidra/CM550.rep/global_variables.csv";
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: global_variables.csv not found at: " + csvPath);
            return;
        }

        // Phase 0: Ensure peripheral register memory region exists
        println("[Phase 0] Ensuring MC68336 peripheral register memory region exists...");
        ensurePeripheralMemoryRegion();
        println("");

        // Parse CSV and filter for hardware registers
        println("[Phase 1] Parsing hardware register definitions...");
        List<RegisterDef> registers = parseHardwareRegisters(csvPath);
        println("  Found " + registers.size() + " hardware register definitions");
        println("");

        // Apply register names
        println("[Phase 2] Applying hardware register names...");
        ApplyResult result = applyRegisterNames(registers);
        println("  Applied: " + result.applied);
        println("  Skipped (already named): " + result.skipped);
        println("  Failed: " + result.failed);
        println("");

        // Show some examples of what was applied
        println("[Examples of applied registers]");
        int shown = 0;
        for (RegisterDef reg : registers) {
            if (reg.wasApplied && shown < 15) {
                println(String.format("  0x%08x -> %s (%s)", reg.address, reg.name, reg.comment));
                shown++;
            }
        }
        if (result.applied > 15) {
            println("  ... and " + (result.applied - 15) + " more");
        }

        println("");
        println("=".repeat(70));
        println("HARDWARE REGISTER NAMING COMPLETE!");
        println("Run 'export' to see changes in decompiled output.");
        println("=".repeat(70));
    }

    private void ensurePeripheralMemoryRegion() throws Exception {
        Memory memory = currentProgram.getMemory();

        // MC68336 peripheral register space: 0x00FFD000 - 0x00FFFFFF (12KB)
        // This includes SIM, QSM, QADC, TPU modules
        long PERIPH_BASE = 0x00FFD000L;
        long PERIPH_SIZE = 0x3000L;  // 12KB

        Address addr = toAddr(PERIPH_BASE);
        MemoryBlock existingBlock = memory.getBlock(addr);

        if (existingBlock != null) {
            println("  Peripheral register region already exists: " + existingBlock.getName());
            return;
        }

        println("  Creating MC68336 peripheral register region...");
        println("    Address: 0x" + Long.toHexString(PERIPH_BASE) + " - 0x" + Long.toHexString(PERIPH_BASE + PERIPH_SIZE - 1));
        println("    Size: " + PERIPH_SIZE + " bytes");

        int txId = currentProgram.startTransaction("Create Peripheral Memory Region");
        try {
            // Create uninitialized block for hardware registers
            MemoryBlock block = memory.createUninitializedBlock(
                "MC68336_PERIPH",
                addr,
                PERIPH_SIZE,
                false  // not overlay
            );

            // Hardware registers are readable and writable, not executable
            block.setRead(true);
            block.setWrite(true);
            block.setExecute(false);
            block.setVolatile(true);  // Mark as volatile (hardware registers change)

            println("  Created MC68336_PERIPH block successfully");
        } finally {
            currentProgram.endTransaction(txId, true);
        }
    }

    private List<RegisterDef> parseHardwareRegisters(String csvPath) throws Exception {
        List<RegisterDef> registers = new ArrayList<>();

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

                // Parse CSV: address,name,type,comment,...
                String[] parts = parseCSVLine(line);
                if (parts.length < 2) {
                    continue;
                }

                String addressStr = parts[0].trim();
                String name = parts[1].trim();
                String type = parts.length > 2 ? parts[2].trim() : "";
                String comment = parts.length > 3 ? parts[3].trim() : "";

                if (addressStr.isEmpty() || name.isEmpty()) {
                    continue;
                }

                try {
                    long address = parseAddressString(addressStr);

                    // Filter for MC68336 peripheral register space (0x00FFxxxx)
                    // Also include 0x00FDxxxx (SIM module)
                    if ((address >= 0x00FFD000 && address <= 0x00FFFFFF) ||
                        (address >= 0x00FD0000 && address <= 0x00FDFFFF)) {

                        RegisterDef reg = new RegisterDef();
                        reg.address = address;
                        reg.name = name;
                        reg.type = type;
                        reg.comment = comment;
                        registers.add(reg);
                    }
                } catch (Exception e) {
                    // Skip invalid entries
                }
            }
        }

        return registers;
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

    private ApplyResult applyRegisterNames(List<RegisterDef> registers) {
        ApplyResult result = new ApplyResult();
        int txId = currentProgram.startTransaction("Apply Hardware Register Names");

        try {
            for (RegisterDef reg : registers) {
                Address addr = toAddr(reg.address);
                if (addr == null) {
                    result.failed++;
                    continue;
                }

                // Check if address is valid in current program
                if (currentProgram.getMemory().getBlock(addr) == null) {
                    result.failed++;
                    continue;
                }

                // Check if symbol already exists with a meaningful name
                Symbol existing = symbolTable.getPrimarySymbol(addr);
                if (existing != null) {
                    String existingName = existing.getName();
                    // Skip if already has a meaningful name (not DAT_ prefix)
                    if (!existingName.startsWith("DAT_") && !existingName.startsWith("_DAT_")) {
                        result.skipped++;
                        continue;
                    }
                }

                try {
                    // Create or rename label
                    symbolTable.createLabel(addr, reg.name, SourceType.USER_DEFINED);

                    // Also try to set the data type
                    DataType dt = getDataType(reg.type);
                    if (dt != null) {
                        try {
                            listing.clearCodeUnits(addr, addr.add(dt.getLength() - 1), false);
                            listing.createData(addr, dt);
                        } catch (Exception e) {
                            // Data type application failed, but name was set
                        }
                    }

                    // Set comment if provided
                    if (!reg.comment.isEmpty()) {
                        try {
                            listing.setComment(addr, ghidra.program.model.listing.CodeUnit.EOL_COMMENT, reg.comment);
                        } catch (Exception e) {
                            // Comment failed, not critical
                        }
                    }

                    result.applied++;
                    reg.wasApplied = true;

                } catch (Exception e) {
                    result.failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        return result;
    }

    private DataType getDataType(String typeName) {
        if (typeName == null || typeName.isEmpty()) {
            return null;
        }

        switch (typeName.toLowerCase()) {
            case "byte":
                return ByteDataType.dataType;
            case "word":
            case "ushort":
                return WordDataType.dataType;
            case "dword":
            case "uint":
                return DWordDataType.dataType;
            case "short":
                return ShortDataType.dataType;
            default:
                return null;
        }
    }

    private long parseAddressString(String addressStr) {
        addressStr = addressStr.trim();
        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
            return Long.parseLong(addressStr.substring(2), 16);
        }
        return Long.parseLong(addressStr, 16);
    }

    // Helper class
    private static class RegisterDef {
        long address;
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
