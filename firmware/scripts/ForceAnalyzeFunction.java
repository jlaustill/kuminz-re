// ForceAnalyzeFunction - force disassembly + function creation at an address
// For functions missed by auto-analysis (e.g. indirect-only call targets in Flash2)
// Usage: ./analyze.sh forceanalyze <address> [name]
// @author kuminz-re
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;

public class ForceAnalyzeFunction extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();

        if (args.length < 1) {
            println("Usage: ForceAnalyzeFunction.java <address> [name]");
            println("Example: ForceAnalyzeFunction.java 0x00539190 cm848_initAllJ1939Handlers");
            return;
        }

        String addrStr = args[0].trim();
        String name = args.length > 1 ? args[1].trim() : null;

        long addrVal;
        if (addrStr.startsWith("0x") || addrStr.startsWith("0X")) {
            addrVal = Long.parseLong(addrStr.substring(2), 16);
        } else {
            addrVal = Long.parseLong(addrStr, 16);
        }

        Address addr = toAddr(addrVal);
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();

        // Remove any existing stale function so we get clean re-analysis
        Function existing = fm.getFunctionAt(addr);
        if (existing != null) {
            println("Removing stale function: " + existing.getName() + " @ " + addr);
            fm.removeFunction(addr);
        }

        // Clear any existing (possibly corrupt) code unit at the entry point before
        // disassembling. removeFunction() only removes the function record; stale
        // "bad instruction" code units survive and block the disassembler.
        println("Clearing code units at " + addr + "...");
        listing.clearCodeUnits(addr, addr.add(3), false);

        // Force disassembly — the disassembler will decode instructions and clear
        // any conflicting code units as it traces the function body
        println("Disassembling at " + addr + "...");
        boolean ok = disassemble(addr);
        println("Disassemble returned: " + ok);

        // Check if an instruction was actually written to the database
        Instruction instr = listing.getInstructionAt(addr);
        if (instr != null) {
            println("Instruction at " + addr + ": " + instr.toString());
        } else {
            println("WARNING: No instruction created at " + addr + " — disassembly may have failed silently");
            // Try reading raw bytes to diagnose
            byte[] bytes = new byte[4];
            currentProgram.getMemory().getBytes(addr, bytes);
            println("Raw bytes at " + addr + ": " +
                String.format("%02x %02x %02x %02x", bytes[0], bytes[1], bytes[2], bytes[3]));
        }

        // Create the function at the now-disassembled address
        println("Creating function...");
        Function func = createFunction(addr, name);

        if (func != null) {
            println("SUCCESS: " + func.getName() + " @ " + addr);
        } else {
            println("ERROR: Failed to create function at " + addr);
        }
    }
}
