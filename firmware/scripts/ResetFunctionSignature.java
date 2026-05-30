// ResetFunctionSignature - revert a function's prototype to uncommitted/dynamic.
//
// The inverse of ApplyFunctionDefinitions. Use when a committed return type or
// parameter list is WRONG and you want Ghidra's decompiler to analyze the function
// dynamically again (e.g. an r4-return helper where r4 is not a parameter slot:
// committing any scalar return makes the decompiler assume r4 is preserved across
// the call, swapping in the wrong operand at call sites. Only the uncommitted state
// models r4-as-output correctly, surfacing it as extraout_r4 — ugly but correct).
//
// Usage: ./analyze.sh resetsig <address> [<address> ...]
// @author kuminz-re
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.DataType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;

public class ResetFunctionSignature extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("Usage: ResetFunctionSignature.java <address> [<address> ...]");
            return;
        }

        FunctionManager fm = currentProgram.getFunctionManager();
        int reset = 0;
        int missing = 0;

        int txId = currentProgram.startTransaction("Reset function signatures");
        try {
            for (String raw : args) {
                long addrVal = ScriptUtils.parseAddress(raw);
                Address addr = toAddr(addrVal);
                Function func = (addr == null) ? null : fm.getFunctionAt(addr);
                if (func == null) {
                    println("  Warning: no function at " + raw);
                    missing++;
                    continue;
                }

                // Drop user-defined custom storage, return type, and the committed
                // signature source so the decompiler re-derives the prototype itself.
                func.setCustomVariableStorage(false);
                func.setReturnType(DataType.DEFAULT, SourceType.DEFAULT);
                func.setSignatureSource(SourceType.DEFAULT);

                println("  Reset: " + func.getName() + " @ " + addr +
                        " (signature source now DEFAULT — decompiler will re-analyze)");
                reset++;
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        println("");
        println("Reset " + reset + " function(s), " + missing + " not found.");
        println("Run 'export' to regenerate decompilation.");
    }
}
