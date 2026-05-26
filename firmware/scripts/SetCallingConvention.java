// SetCallingConvention.java
// Sets the calling convention for all functions in an address range.
// Usage: pass start and end address as hex strings (e.g. "00500000" "0053DFFF")
// Defaults to Bank 2 (0x00500000-0x0053DFFF) if no args given.
// Run funcdefs + localvars + export after this to see the effect.
// @author kuminz-re
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;

import java.util.ArrayList;
import java.util.List;

public class SetCallingConvention extends GhidraScript {

    // Must match a <prototype name="..."> in the processor .cspec file.
    // PowerPC 32-bit big-endian (ppc_32_be.cspec) defines only "__stdcall".
    private static final String TARGET_CC = "__stdcall";

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();

        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();

        Address rangeStart, rangeEnd;
        if (args.length >= 2) {
            rangeStart = space.getAddress(Long.parseLong(args[0], 16));
            rangeEnd   = space.getAddress(Long.parseLong(args[1], 16));
        } else {
            rangeStart = space.getAddress(0x00500000L);
            rangeEnd   = space.getAddress(0x0053DFFFL);
        }

        println("Setting calling convention '" + TARGET_CC + "' on functions in " +
                rangeStart + " - " + rangeEnd);

        AddressSet range = new AddressSet(rangeStart, rangeEnd);
        FunctionIterator functions = currentProgram.getListing().getFunctions(range, true);

        int txId = currentProgram.startTransaction("Set calling conventions");
        int updated = 0;
        int alreadySet = 0;
        List<String> updatedNames = new ArrayList<>();

        try {
            while (functions.hasNext()) {
                Function func = functions.next();
                String current = func.getCallingConventionName();
                if (TARGET_CC.equals(current)) {
                    alreadySet++;
                    continue;
                }
                func.setCallingConvention(TARGET_CC);
                updatedNames.add(func.getName() + " @ " + func.getEntryPoint());
                updated++;
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        println("======================================================================");
        println("CALLING CONVENTION UPDATE COMPLETE");
        println("  Range:         " + rangeStart + " - " + rangeEnd);
        println("  Updated:       " + updated);
        println("  Already set:   " + alreadySet);
        println("======================================================================");
        for (String name : updatedNames) {
            println("  " + name);
        }
        println("Run funcdefs + localvars + export to see changes in decompiled output.");
    }
}
