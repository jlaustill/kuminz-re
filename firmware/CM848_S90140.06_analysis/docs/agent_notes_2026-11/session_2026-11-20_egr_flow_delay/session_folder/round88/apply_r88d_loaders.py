"""Round 88 stage D: load the two shifted dumps where their bytes belong (ScriptUtils.imageFromDumpWithGaps).
Idempotent; keeps line endings (SetupMemoryMap.java is CRLF). usage: apply_r88d_loaders.py <repo>
- CM848 SetupMemoryMapCM848.java: cm848_ram.bin (0x45F80 bytes from 0x3FA000) misses the chunk at 0x40c200; the RAM
  block becomes 0x3FA000-0x43FFFF with 0x40c200-0x40c27f unknown (0) and every later byte back at its address.
- CM550 SetupMemoryMap.java: J90350.00.extended_ram.bin (0x6DBE bytes) misses its first or second chunk; its bytes
  from offset 0x80 on belong at 0x8092C2 under both readings. EXT_RAM becomes 0x8091C2-0x80FFFF with
  0x8091C2-0x8092C1 unknown (0)."""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 88"


def edit(rel, old, new):
    p = os.path.join(repo, rel)
    t = open(p, newline="").read()
    if "\r\n" in t:
        old, new = old.replace("\n", "\r\n"), new.replace("\n", "\r\n")
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))


BYTES_METHOD = '''
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
'''

# ---- CM848
C8 = "firmware/scripts/SetupMemoryMapCM848.java"
edit(C8, "    private static final long RAM_BASE     = 0x3FA000L;   // 280 KB RAM\n",
     "    private static final long RAM_BASE     = 0x3FA000L;   // 280 KB RAM\n"
     "    private static final long RAM_END      = 0x440000L;   // the RAM block ends here (exclusive)\n"
     "    // cm848_ram.bin is 0x80 bytes short: the dump tool skipped the failed chunk at 0x40c200 without padding, so\n"
     "    // every byte from 0x40c280 on sits 0x80 low in the file (the collector end pointer 0x40c28a and the table\n"
     "    // address 0x3fddc4 read at file 0x40c200; PR #53 wave 14). The image puts them back and leaves the chunk 0.\n"
     f"    private static final long RAM_DUMP_GAP = 0x40C200L;   // {R}\n"
     "    private static final int RAM_DUMP_GAP_LENGTH = 0x80;\n")
edit(C8, '            addMemoryRegion(memory, "RAM", RAM_BASE, ramFile, true, true, true);\n',
     "            byte[] ram = ScriptUtils.imageFromDumpWithGaps(readFile(ramFile), 0, (int) (RAM_END - RAM_BASE),\n"
     "                    new int[][]{{(int) (RAM_DUMP_GAP - RAM_BASE), RAM_DUMP_GAP_LENGTH}}, (byte) 0);\n"
     '            println(String.format("  Dump gap 0x%06x-0x%06x left 0 (not in cm848_ram.bin)", RAM_DUMP_GAP,\n'
     "                    RAM_DUMP_GAP + RAM_DUMP_GAP_LENGTH - 1));\n"
     '            addMemoryRegionFromBytes(memory, "RAM", RAM_BASE, ram, true, true, true);\n')
edit(C8, "    /** Creates an initialized, executable block whose bytes are copied from a ROM source range. */\n",
     BYTES_METHOD.lstrip("\n") + "\n    /** Creates an initialized, executable block whose bytes are copied from a ROM source range. */\n")

# ---- CM550
C5 = "firmware/scripts/SetupMemoryMap.java"
edit(C5, "    private static final long EXTENDED_RAM_BASE = 0x8091C2L;\n",
     "    private static final long EXTENDED_RAM_BASE = 0x8091C2L;\n"
     "    private static final long EXTENDED_RAM_END = 0x810000L;     // the EXT_RAM block ends here (exclusive)\n"
     "    // J90350.00.extended_ram.bin is 0x80 bytes short: the dump tool skipped a failed 128-byte chunk without padding\n"
     "    // - the first (0x8091C2) or the second (0x809242). Under both readings the file's bytes from offset 0x80 on\n"
     "    // belong at 0x8092C2 (40 of 100 init-time constant stores match only at address - 0x80, none only at the\n"
     f"    // address; PR #53 round 87). The image leaves the uncertain 0x8091C2-0x8092C1 0 ({R}).\n"
     "    private static final int EXTENDED_RAM_DUMP_SKIP = 0x80;     // file bytes not placed\n"
     "    private static final int EXTENDED_RAM_UNKNOWN_LENGTH = 0x100;  // 0x8091C2-0x8092C1\n")
edit(C5, '            addMemoryRegion(memory, "EXT_RAM", EXTENDED_RAM_BASE, extRamFile, true, true, true);\n',
     "            byte[] extRam = ScriptUtils.imageFromDumpWithGaps(readFile(extRamFile), EXTENDED_RAM_DUMP_SKIP,\n"
     "                    (int) (EXTENDED_RAM_END - EXTENDED_RAM_BASE), new int[][]{{0, EXTENDED_RAM_UNKNOWN_LENGTH}},\n"
     "                    (byte) 0);\n"
     '            println(String.format("  Unknown 0x%06x-0x%06x left 0 (the dump skipped a chunk there)",\n'
     "                    EXTENDED_RAM_BASE, EXTENDED_RAM_BASE + EXTENDED_RAM_UNKNOWN_LENGTH - 1));\n"
     '            addMemoryRegionFromBytes(memory, "EXT_RAM", EXTENDED_RAM_BASE, extRam, true, true, true);\n')
edit(C5, "    private void printMemoryMap(Memory memory) {\n",
     BYTES_METHOD.lstrip("\n") + "\n    private void printMemoryMap(Memory memory) {\n")
print("stage D loaders applied")
