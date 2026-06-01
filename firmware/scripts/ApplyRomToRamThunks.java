// ApplyRomToRamThunks.java
// Deterministic build step: resolve func_0x003fxxxx() calls in the ROM-to-RAM code region.
//
// CM848 copies ROM 0x3C30-0x7F60 into RAM 0x3F9800-0x3FDB30 at boot and runs it from RAM.
// Calls into that RAM (bl 0x3Fxxxx) have no function target, so Ghidra emits func_0x003fxxxx().
// The live RAM bytes there are CAN-overwritten garbage, so we create a THUNK at each called RAM
// address that redirects to its ROM source function. Map: RAM = 0x3F9800 + (ROM - 0x3C30).
//
// Auto-discovering (no args): iterates ROM functions in the source range, and thunks a RAM
// address ONLY when it is actually called (has an incoming CALL reference) — so the output
// gains real names without unused-thunk clutter. Idempotent.
//
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
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceManager;

public class ApplyRomToRamThunks extends GhidraScript {

    // ROM source range copied to RAM at boot, and the RAM destination base.
    private static final long ROM_LO  = 0x3C30L;
    private static final long ROM_HI  = 0x7F60L;   // exclusive
    private static final long RAM_LO  = 0x3F9800L; // RAM = RAM_LO + (ROM - ROM_LO)

    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        Memory mem = currentProgram.getMemory();
        Listing listing = currentProgram.getListing();
        ReferenceManager rm = currentProgram.getReferenceManager();

        int made = 0, skipped = 0, failed = 0;
        int txId = currentProgram.startTransaction("Apply ROM-to-RAM thunks");
        try {
            FunctionIterator it = fm.getFunctions(toAddr(ROM_LO), true);
            while (it.hasNext()) {
                Function romFunc = it.next();
                long rom = romFunc.getEntryPoint().getOffset();
                if (rom < ROM_LO) continue;
                if (rom >= ROM_HI) break;            // past the copied source range
                if (romFunc.isThunk()) continue;

                long ram = RAM_LO + (rom - ROM_LO);
                Address ramAddr = toAddr(ram);
                if (ramAddr == null || !mem.contains(ramAddr)) { skipped++; continue; }

                // Only thunk addresses that are actually called from somewhere — that is what
                // turns a func_0x003fxxxx() into a named call. Unreferenced RAM copies are left
                // alone (no clutter).
                boolean called = false;
                for (Reference ref : rm.getReferencesTo(ramAddr)) {
                    if (ref.getReferenceType().isCall()) { called = true; break; }
                }
                if (!called) { skipped++; continue; }

                Function existing = fm.getFunctionAt(ramAddr);
                if (existing != null) {
                    if (existing.isThunk()) { skipped++; continue; }   // idempotent
                    // Never override a CURATED name at a RAM address (someone deliberately
                    // named/analyzed the RAM copy, e.g. *_ramcopy). Only replace Ghidra's
                    // auto-defaults. The genuine func_0x targets have no function at all.
                    String en = existing.getName();
                    boolean auto = en.startsWith("FUN_") || en.startsWith("BYTE_")
                            || en.startsWith("SUB_") || en.startsWith("LAB_") || en.startsWith("DAT_");
                    if (!auto) { skipped++; continue; }
                    fm.removeFunction(ramAddr);
                }

                // RAM bytes are garbage — do NOT disassemble. Clear the stale unit and supply an
                // explicit 4-byte body so the cmd builds a pure thunk to ROM.
                listing.clearCodeUnits(ramAddr, ramAddr.add(3), false);
                AddressSet body = new AddressSet(ramAddr, ramAddr.add(3));
                CreateThunkFunctionCmd cmd = new CreateThunkFunctionCmd(ramAddr, body, romFunc.getEntryPoint());
                if (cmd.applyTo(currentProgram, monitor)) {
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

        println("======================================================================");
        println("ROM-TO-RAM THUNKS: made " + made + ", skipped " + skipped + ", failed " + failed);
        println("======================================================================");
    }
}
