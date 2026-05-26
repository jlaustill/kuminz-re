// DeleteFunctions.java
// Removes spurious function records at specified addresses without recreating them.
// Useful when Ghidra incorrectly split a function at a mid-code address (e.g. after a
// force-analyze on an address that is actually inside an existing function).
// Usage: pass addresses as hex strings, one per arg
//   ./analyze.sh deletefuncs 0x00025050 0x00025d88 0x00025fd8 0x0002661c
// @author kuminz-re
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

public class DeleteFunctions extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length == 0) {
            println("Usage: DeleteFunctions.java <addr> [addr ...]");
            return;
        }

        FunctionManager fm = currentProgram.getFunctionManager();
        int txId = currentProgram.startTransaction("Delete spurious functions");
        int removed = 0;
        int notFound = 0;

        try {
            for (String arg : args) {
                String addrStr = arg.trim();
                long addrVal;
                if (addrStr.startsWith("0x") || addrStr.startsWith("0X")) {
                    addrVal = Long.parseLong(addrStr.substring(2), 16);
                } else {
                    addrVal = Long.parseLong(addrStr, 16);
                }

                Address addr = toAddr(addrVal);
                Function func = fm.getFunctionAt(addr);
                if (func == null) {
                    println("  Not found (no function at " + addr + ")");
                    notFound++;
                } else {
                    String name = func.getName();
                    fm.removeFunction(addr);
                    println("  Removed: " + name + " @ " + addr);
                    removed++;
                }
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        println("======================================================================");
        println("DELETE FUNCTIONS COMPLETE");
        println("  Removed:   " + removed);
        println("  Not found: " + notFound);
        println("======================================================================");
        println("Run 'export' to update decompilation output.");
    }
}
