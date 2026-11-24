// Setup Memory Map Script
// Adds RAM and EEPROM memory regions with data from live ECU dumps
// MC68336 memory layout for CM550 ECU
// @author J90350.00_analysis
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

public class SetupMemoryMap extends GhidraScript {

    // MC68336 CM550 Memory Map
    private static final long RAM_BASE = 0x800000L;
    private static final long EXTENDED_RAM_BASE = 0x8091C2L;
    private static final long EXTENDED_RAM_END = 0x810000L;     // the EXT_RAM block ends here (exclusive)
    // J90350.00.extended_ram.bin is 0x80 bytes short: the dump tool skipped a failed 128-byte chunk without padding
    // - the first (0x8091C2) or the second (0x809242). Under both readings the file's bytes from offset 0x80 on
    // belong at 0x8092C2 (40 of 100 init-time constant stores match only at address - 0x80, none only at the
    // address; PR #53 round 87). The image leaves the uncertain 0x8091C2-0x8092C1 0 (PR #53 round 88).
    private static final int EXTENDED_RAM_DUMP_SKIP = 0x80;     // file bytes not placed
    private static final int EXTENDED_RAM_UNKNOWN_LENGTH = 0x100;  // 0x8091C2-0x8092C1
    private static final long EEPROM_BASE = 0x1000000L;

    @Override
    public void run() throws Exception {
        println("======================================================================");
        println("SETUP MEMORY MAP - MC68336 CM550");
        println("======================================================================");
        println("");

        // Get firmware directory from arguments or use default
        String[] args = getScriptArgs();
        String firmwareDir;

        if (args.length > 0) {
            firmwareDir = args[0];
        } else {
            firmwareDir = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../firmware";
        }

        Memory memory = currentProgram.getMemory();

        // Add RAM region
        String ramFile = firmwareDir + "/J90350.00.ram.bin";
        if (new File(ramFile).exists()) {
            println("[1/3] Adding RAM region...");
            addMemoryRegion(memory, "RAM", RAM_BASE, ramFile, true, true, true);
        } else {
            println("[1/3] SKIPPED: RAM file not found: " + ramFile);
        }

        // Add Extended RAM region (0x8091C2 - 0x80FFFF)
        String extRamFile = firmwareDir + "/J90350.00.extended_ram.bin";
        if (new File(extRamFile).exists()) {
            println("[2/3] Adding Extended RAM region...");
            byte[] extRam = ScriptUtils.imageFromDumpWithGaps(readFile(extRamFile), EXTENDED_RAM_DUMP_SKIP,
                    (int) (EXTENDED_RAM_END - EXTENDED_RAM_BASE), new int[][]{{0, EXTENDED_RAM_UNKNOWN_LENGTH}},
                    (byte) 0);
            println(String.format("  Unknown 0x%06x-0x%06x left 0 (the dump skipped a chunk there)",
                    EXTENDED_RAM_BASE, EXTENDED_RAM_BASE + EXTENDED_RAM_UNKNOWN_LENGTH - 1));
            addMemoryRegionFromBytes(memory, "EXT_RAM", EXTENDED_RAM_BASE, extRam, true, true, true);
        } else {
            println("[2/3] SKIPPED: Extended RAM file not found: " + extRamFile);
        }

        // Add EEPROM region
        String eepromFile = firmwareDir + "/J90350.00.eeprom.bin";
        if (new File(eepromFile).exists()) {
            println("[3/3] Adding EEPROM region...");
            addMemoryRegion(memory, "EEPROM", EEPROM_BASE, eepromFile, true, true, false);
        } else {
            println("[3/3] SKIPPED: EEPROM file not found: " + eepromFile);
        }

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

    /** Creates an initialized block holding data (a memory image already built from its dump). */
    private void addMemoryRegionFromBytes(Memory memory, String name, long baseAddress, byte[] data,
                                          boolean read, boolean write, boolean execute) throws Exception {
        Address addr = toAddr(baseAddress);
        MemoryBlock existingBlock = memory.getBlock(addr);
        if (existingBlock != null) {
            println("  Removing existing block " + existingBlock.getName() + "...");
            memory.removeBlock(existingBlock, monitor);
        }
        MemoryBlock block = memory.createInitializedBlock(name, addr, data.length, (byte) 0, monitor, false);
        block.setRead(read);
        block.setWrite(write);
        block.setExecute(execute);
        memory.setBytes(addr, data);
        println("  Created " + name + " block:");
        println("    Address: " + String.format("0x%08x - 0x%08x", baseAddress, baseAddress + data.length - 1));
        println("    Size:    " + data.length + " bytes (" + (data.length / 1024) + " KB)");
    }

    private static byte[] readFile(String path) throws Exception {
        File file = new File(path);
        byte[] data = new byte[(int) file.length()];
        try (FileInputStream fis = new FileInputStream(file)) {
            int done = 0;
            while (done < data.length) {
                int n = fis.read(data, done, data.length - done);
                if (n < 0) break;
                done += n;
            }
        }
        return data;
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
