// Apply MPC555 Hardware Register Names Script
// Applies MPC555 peripheral register names for CM848 firmware
// @author CM848_S90140.06_analysis
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

public class ApplyMPC555Registers extends GhidraScript {

    private SymbolTable symbolTable;
    private Listing listing;
    private DataTypeManager dtm;

    // MPC555 Peripheral Register Ranges
    private static final long USIU_BASE = 0x002FC000L;  // System Integration Unit
    private static final long USIU_SIZE = 0x4000L;       // 16KB
    private static final long IMB3_BASE = 0x00300000L;  // Internal Module Bus 3
    private static final long IMB3_SIZE = 0x8000L;       // 32KB (covers TPU, QADC, QSMCM, MIOS, TouCAN)

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY MPC555 HARDWARE REGISTER NAMES - CM848");
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
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../output/mpc555_registers.csv";
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: mpc555_registers.csv not found at: " + csvPath);
            return;
        }

        // Phase 0: Ensure peripheral register memory regions exist
        println("[Phase 0] Ensuring MPC555 peripheral register memory regions exist...");
        ensurePeripheralMemoryRegions();
        println("");

        // Parse CSV and get all hardware registers
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
            if (reg.wasApplied && shown < 20) {
                println(String.format("  0x%08x -> %s", reg.address, reg.name));
                shown++;
            }
        }
        if (result.applied > 20) {
            println("  ... and " + (result.applied - 20) + " more");
        }

        println("");
        println("=".repeat(70));
        println("MPC555 HARDWARE REGISTER NAMING COMPLETE!");
        println("Run 'export' to see changes in decompiled output.");
        println("=".repeat(70));
    }

    private void ensurePeripheralMemoryRegions() throws Exception {
        Memory memory = currentProgram.getMemory();

        // Create USIU region (System Integration Unit)
        createPeripheralRegion(memory, "MPC555_USIU", USIU_BASE, USIU_SIZE,
            "MPC555 System Integration Unit (clocks, interrupts, memory controller)");

        // Create IMB3 region (Internal Module Bus 3 - peripherals)
        createPeripheralRegion(memory, "MPC555_IMB3", IMB3_BASE, IMB3_SIZE,
            "MPC555 Peripherals (TPU, QADC, QSMCM, MIOS, TouCAN)");
    }

    private void createPeripheralRegion(Memory memory, String name, long base, long size, String comment)
            throws Exception {

        Address addr = toAddr(base);
        MemoryBlock existingBlock = memory.getBlock(addr);

        if (existingBlock != null) {
            println("  " + name + " region already exists: " + existingBlock.getName());
            return;
        }

        println("  Creating " + name + " region...");
        println("    Address: 0x" + Long.toHexString(base) + " - 0x" + Long.toHexString(base + size - 1));
        println("    Size: " + size + " bytes (" + (size / 1024) + " KB)");

        int txId = currentProgram.startTransaction("Create " + name + " Memory Region");
        try {
            MemoryBlock block = memory.createUninitializedBlock(
                name,
                addr,
                size,
                false  // not overlay
            );

            block.setRead(true);
            block.setWrite(true);
            block.setExecute(false);
            block.setVolatile(true);
            block.setComment(comment);

            println("  Created " + name + " block successfully");
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

                String[] parts = ScriptUtils.parseCSVLine(line);
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
                    long address = ScriptUtils.parseAddress(addressStr);

                    // Accept MPC555 peripheral addresses:
                    // USIU: 0x002FC000 - 0x002FFFFF
                    // IMB3: 0x00300000 - 0x00307FFF
                    if ((address >= 0x002FC000 && address <= 0x002FFFFF) ||
                        (address >= 0x00300000 && address <= 0x00307FFF)) {

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

    private String[] ScriptUtils.parseCSVLine(String line) {
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
        int txId = currentProgram.startTransaction("Apply MPC555 Hardware Register Names");

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
                    boolean isAutoGenerated = existingName.startsWith("DAT_") ||
                                             existingName.startsWith("_DAT_") ||
                                             existingName.startsWith("Ram");
                    if (!isAutoGenerated) {
                        result.skipped++;
                        continue;
                    }
                }

                try {
                    symbolTable.createLabel(addr, reg.name, SourceType.USER_DEFINED);

                    DataType dt = getDataType(reg.type);
                    if (dt != null) {
                        try {
                            listing.clearCodeUnits(addr, addr.add(dt.getLength() - 1), false);
                            listing.createData(addr, dt);
                        } catch (Exception e) {
                            // Data type application failed
                        }
                    }

                    if (!reg.comment.isEmpty()) {
                        try {
                            listing.setComment(addr, ghidra.program.model.listing.CodeUnit.EOL_COMMENT, reg.comment);
                        } catch (Exception e) {
                            // Comment failed
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
            case "u8":
            case "byte":
                return ByteDataType.dataType;
            case "u16":
            case "word":
            case "ushort":
                return WordDataType.dataType;
            case "u32":
            case "dword":
            case "uint":
                return DWordDataType.dataType;
            case "i16":
            case "short":
                return ShortDataType.dataType;
            case "i32":
            case "int":
                return SignedDWordDataType.dataType;
            default:
                return null;
        }
    }



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
