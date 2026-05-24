// Setup Memory Map Script for CM848 (PowerPC)
// Adds RAM and EEPROM memory regions with data from live ECU dumps
// PowerPC memory layout for CM848 ECU
// @author CM848_S90140.06_analysis
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.File;
import java.io.FileInputStream;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;

public class SetupMemoryMapCM848 extends GhidraScript {

    // CM848 PowerPC Memory Map
    // Bank 1 (main ROM) is loaded during initial import at 0x00000000
    // Bank 2 (extended flash) contains utility functions called from main ROM
    private static final long FLASH2_BASE  = 0x500000L;   // 245 KB extended flash (utility functions)
    private static final long RAM_BASE     = 0x3FA000L;   // 280 KB RAM
    private static final long EEPROM_BASE  = 0x1000000L;  // 8 KB EEPROM
    // MPC555 USIU internal peripheral registers — not in any dump file, mapped
    // at MBAR+0x4000. Uninitialized block so ApplyStructures can place USIU
    // struct definitions (usiu_memc_t, usiu_pit_t, usiu_clock_t, etc.).
    private static final long USIU_BASE    = 0x002FC000L; // USIU internal registers
    private static final long USIU_LENGTH  = 0x1000L;    // 4 KB covers all known USIU structs
    // MPC555 peripheral bus register space (TPU3, MIOS1, TouCAN A/B, etc.)
    // Covers 0x302000-0x307FFF (includes all named peripheral structs)
    private static final long MBAR_PERIPH_BASE   = 0x00302000L; // MBAR+0xA000
    private static final long MBAR_PERIPH_LENGTH = 0x6000L;    // 24 KB: 0x302000-0x307FFF

    @Override
    public void run() throws Exception {
        println("======================================================================");
        println("SETUP MEMORY MAP - CM848 PowerPC");
        println("======================================================================");
        println("");

        // Get firmware directory from arguments or use default
        String[] args = getScriptArgs();
        String firmwareDir;

        if (args.length > 0) {
            firmwareDir = args[0];
        } else {
            firmwareDir = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../originals";
        }

        Memory memory = currentProgram.getMemory();

        // Add extended flash region (Bank 2 - utility functions)
        // Use live ECU dump (matches ROM version V11.46.06) instead of e2m
        // extraction (S90140.12 / V11.20.13.16) to avoid cross-bank call
        // resolution errors from firmware version mismatch
        String flash2File = firmwareDir + "/cm848_flash2_live.bin";
        if (new File(flash2File).exists()) {
            println("[1/3] Adding extended flash region (Bank 2 - live dump)...");
            addMemoryRegion(memory, "FLASH2", FLASH2_BASE, flash2File, true, false, true);
        } else {
            println("[1/3] SKIPPED: Flash2 live dump not found: " + flash2File);
            println("       Dump Bank 2 from live ECU using kuminz-cli");
        }

        // Add RAM region (CM848 has 280KB continuous RAM)
        String ramFile = firmwareDir + "/cm848_ram.bin";
        if (new File(ramFile).exists()) {
            println("[2/3] Adding RAM region...");
            addMemoryRegion(memory, "RAM", RAM_BASE, ramFile, true, true, true);
        } else {
            println("[2/3] SKIPPED: RAM file not found: " + ramFile);
        }

        // Add EEPROM region (CM848 has 8KB EEPROM)
        String eepromFile = firmwareDir + "/cm848_eeprom.bin";
        if (new File(eepromFile).exists()) {
            println("[3/4] Adding EEPROM region...");
            addMemoryRegion(memory, "EEPROM", EEPROM_BASE, eepromFile, true, true, false);
        } else {
            println("[3/4] SKIPPED: EEPROM file not found: " + eepromFile);
        }

        // Add MPC555 USIU peripheral register space (uninitialized — no backing data)
        // Enables ApplyStructures to place usiu_memc_t, usiu_pit_t, usiu_clock_t, etc.
        println("[4/4] Adding MPC555 USIU peripheral register space (uninitialized)...");
        addPeripheralRegion(memory, "USIU_PERIPH", USIU_BASE, USIU_LENGTH);

        // Add MPC555 peripheral bus space (TPU3, MIOS1, TouCAN A/B, etc.)
        // Uninitialized block — allows vartypes and structures to cover all peripheral registers
        println("[5/5] Adding MPC555 peripheral bus register space (uninitialized)...");
        addPeripheralRegion(memory, "MBAR_PERIPH", MBAR_PERIPH_BASE, MBAR_PERIPH_LENGTH);

        println("");
        println("======================================================================");
        println("MEMORY MAP COMPLETE");
        println("======================================================================");
        printMemoryMap(memory);
    }

    private void addMemoryRegion(Memory memory, String name, long baseAddress,
                                  String filePath, boolean read, boolean write, boolean execute)
            throws Exception {

        Address addr = toAddr(baseAddress);

        // Check if block already exists
        MemoryBlock existingBlock = memory.getBlock(addr);
        if (existingBlock != null) {
            println("  Block already exists at " + String.format("0x%08x", baseAddress) +
                    " (" + existingBlock.getName() + ")");
            println("  Removing existing block...");
            memory.removeBlock(existingBlock, monitor);
        }

        // Read file data
        File file = new File(filePath);
        byte[] data = new byte[(int) file.length()];

        try (FileInputStream fis = new FileInputStream(file)) {
            fis.read(data);
        }

        // Create memory block
        MemoryBlock block = memory.createInitializedBlock(
                name,
                addr,
                data.length,
                (byte) 0,
                monitor,
                false
        );

        // Set permissions
        block.setRead(read);
        block.setWrite(write);
        block.setExecute(execute);

        // Copy data into block
        memory.setBytes(addr, data);

        println("  Created " + name + " block:");
        println("    Address: " + String.format("0x%08x - 0x%08x", baseAddress, baseAddress + data.length - 1));
        println("    Size:    " + data.length + " bytes (" + (data.length / 1024) + " KB)");
        println("    Perms:   " + (read ? "r" : "-") + (write ? "w" : "-") + (execute ? "x" : "-"));
    }

    private void addPeripheralRegion(Memory memory, String name, long baseAddress, long length)
            throws Exception {

        Address addr = toAddr(baseAddress);

        MemoryBlock existingBlock = memory.getBlock(addr);
        if (existingBlock != null) {
            println("  Block already exists at " + String.format("0x%08x", baseAddress) +
                    " (" + existingBlock.getName() + ") — skipping");
            return;
        }

        MemoryBlock block = memory.createUninitializedBlock(name, addr, length, false);
        block.setRead(true);
        block.setWrite(true);
        block.setExecute(false);
        block.setVolatile(true);

        println("  Created " + name + " block (uninitialized):");
        println("    Address: " + String.format("0x%08x - 0x%08x", baseAddress, baseAddress + length - 1));
        println("    Size:    " + length + " bytes");
        println("    Perms:   rw- (volatile)");
    }

    private void printMemoryMap(Memory memory) {
        println("");
        println("Current Memory Map:");
        println("-------------------");

        for (MemoryBlock block : memory.getBlocks()) {
            String perms = (block.isRead() ? "r" : "-") +
                          (block.isWrite() ? "w" : "-") +
                          (block.isExecute() ? "x" : "-");

            println(String.format("  %-10s %s  0x%08x - 0x%08x  (%d KB)",
                    block.getName(),
                    perms,
                    block.getStart().getOffset(),
                    block.getEnd().getOffset(),
                    block.getSize() / 1024));
        }
    }
}
