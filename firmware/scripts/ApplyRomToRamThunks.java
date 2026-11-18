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
// Time-shared RAM (todo 043): the application reuses this RAM for its own variables after boot.
// Where a named data row (a non-default label) sits in the 4 bytes a thunk would take, a thunk
// would clear those data units and adopt the data label as the function's name (so the boot call
// rendered as a call to the variable, and the next word's row was swallowed). There, no thunk is
// made: each call into the RAM address gets a primary CALL_OVERRIDE_UNCONDITIONAL reference to
// the ROM function instead, so the call renders with the function's name and the data rows stay.
// The same goes for a named struct or array that covers those bytes without a label of its own
// there (2026-11-18: the PGN 65270 transmit descriptor, typed j1939_tx_msg_t, covers the boot-called
// RAM copy of dispatchCanMessageHandlers at +4): a thunk would split the instance.
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
import ghidra.program.model.data.Array;
import ghidra.program.model.data.Composite;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.RefType;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceManager;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SymbolType;

import java.util.ArrayList;
import java.util.List;

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
        SymbolTable st = currentProgram.getSymbolTable();

        int made = 0, overridden = 0, skipped = 0, failed = 0;
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
                List<Reference> calls = new ArrayList<>();
                for (Reference ref : rm.getReferencesTo(ramAddr)) {
                    if (ref.getReferenceType().isCall()) calls.add(ref);
                }
                if (calls.isEmpty()) { skipped++; continue; }

                // Application data named in the thunk's 4 bytes: keep the data, override the calls.
                String dataName = namedLabelIn(st, ramAddr, 4);
                if (dataName == null) {
                    dataName = namedCompositeCovering(listing, st, ramAddr, 4);
                }
                if (dataName != null && fm.getFunctionAt(ramAddr) == null) {
                    for (Reference call : calls) {
                        Reference over = rm.addMemoryReference(call.getFromAddress(), romFunc.getEntryPoint(),
                                RefType.CALL_OVERRIDE_UNCONDITIONAL, SourceType.USER_DEFINED, call.getOperandIndex());
                        rm.setPrimary(over, true);
                    }
                    println(String.format("  Call override: %d call(s) to RAM 0x%06x -> ROM 0x%06x (%s); data %s kept",
                            calls.size(), ram, rom, romFunc.getName(), dataName));
                    overridden++;
                    continue;
                }

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
        println("ROM-TO-RAM THUNKS: made " + made + ", call overrides " + overridden + ", skipped " + skipped
                + ", failed " + failed);
        println("======================================================================");
    }

    /**
     * The name of a named struct or array that covers [start, start + length) from an address before start
     * (an instance with no label of its own in those bytes), or null. Only composite data counts: a scalar
     * row that overlaps is handled by namedLabelIn.
     */
    private static String namedCompositeCovering(Listing listing, SymbolTable st, Address start, int length) {
        for (int i = 0; i < length; i++) {
            Data d = listing.getDataContaining(start.add(i));
            if (d == null || !(d.getDataType() instanceof Composite || d.getDataType() instanceof Array)) {
                continue;
            }
            Symbol s = st.getPrimarySymbol(d.getMinAddress());
            if (s != null && s.getSource() != SourceType.DEFAULT) {
                return s.getName() + " (covering)";
            }
        }
        return null;
    }

    /** The first non-default label (a named data row) in [start, start + length), or null. */
    private static String namedLabelIn(SymbolTable st, Address start, int length) {
        for (int i = 0; i < length; i++) {
            for (Symbol s : st.getSymbols(start.add(i))) {
                if (s.getSymbolType() == SymbolType.LABEL && s.getSource() != SourceType.DEFAULT) {
                    return s.getName();
                }
            }
        }
        return null;
    }
}
