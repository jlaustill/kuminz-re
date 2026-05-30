// CreateRomToRamThunks - resolve func_0x003fxxxx calls in the ROM-to-RAM code region.
//
// CM848 copies ROM 0x3C30-0x7F60 to RAM 0x3F9800-0x3FDB30 at boot and executes it
// from RAM for speed. Calls into that RAM (bl 0x3Fxxxx) have no function target, so
// Ghidra emits func_0x003fxxxx(). The RAM dump bytes there are CAN-overwritten garbage,
// but the code is identical to its ROM source, so we create a THUNK at each RAM address
// pointing to the named ROM function. Mapping: ROM = 0x3C30 + (RAM - 0x3F9800).
//
// Usage: ./analyze.sh romramthunks <ram_addr> [<ram_addr> ...]
// @author kuminz-re
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.function.CreateThunkFunctionCmd;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;

public class CreateRomToRamThunks extends GhidraScript {

    private static final long RAM_LO  = 0x3F9800L;
    private static final long RAM_HI  = 0x3FDB30L;
    private static final long ROM_BASE = 0x3C30L;   // ROM = ROM_BASE + (RAM - RAM_LO)

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("Usage: CreateRomToRamThunks.java <ram_addr> [<ram_addr> ...]");
            return;
        }

        FunctionManager fm = currentProgram.getFunctionManager();
        Memory mem = currentProgram.getMemory();
        int made = 0, skipped = 0, failed = 0;

        int txId = currentProgram.startTransaction("Create ROM-to-RAM thunks");
        try {
            for (String raw : args) {
                long ram = ScriptUtils.parseAddress(raw);
                if (ram < RAM_LO || ram > RAM_HI) {
                    println("  Skip " + raw + ": outside ROM-to-RAM region");
                    skipped++;
                    continue;
                }
                long rom = ROM_BASE + (ram - RAM_LO);
                Address ramAddr = toAddr(ram);
                Address romAddr = toAddr(rom);

                if (ramAddr == null || !mem.contains(ramAddr)) {
                    println(String.format("  Skip RAM 0x%06x: not in mapped memory", ram));
                    skipped++;
                    continue;
                }
                Function romFunc = fm.getFunctionAt(romAddr);
                if (romFunc == null) {
                    println(String.format("  Skip RAM 0x%06x -> ROM 0x%06x: no function at ROM source", ram, rom));
                    skipped++;
                    continue;
                }
                Function existing = fm.getFunctionAt(ramAddr);
                if (existing != null && existing.isThunk()) {
                    println(String.format("  Already a thunk: RAM 0x%06x -> %s", ram, romFunc.getName()));
                    skipped++;
                    continue;
                }
                if (existing != null) {
                    fm.removeFunction(ramAddr);
                }

                // The RAM bytes are CAN-overwritten garbage, so we must NOT let the command
                // disassemble them. Clear any stale code unit and hand it an explicit 4-byte
                // body (one PowerPC instruction) so it builds a pure thunk over that range.
                Listing listing = currentProgram.getListing();
                listing.clearCodeUnits(ramAddr, ramAddr.add(3), false);
                AddressSet body = new AddressSet(ramAddr, ramAddr.add(3));

                CreateThunkFunctionCmd cmd = new CreateThunkFunctionCmd(ramAddr, body, romAddr);
                boolean ok = cmd.applyTo(currentProgram, monitor);
                if (ok) {
                    println(String.format("  Thunk: RAM 0x%06x -> ROM 0x%06x (%s)", ram, rom, romFunc.getName()));
                    made++;
                } else {
                    println(String.format("  FAILED RAM 0x%06x -> ROM 0x%06x: %s", ram, rom, cmd.getStatusMsg()));
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        println("");
        println("Thunks created: " + made + ", skipped: " + skipped + ", failed: " + failed);
        println("Run 'export' to regenerate decompilation.");
    }
}
