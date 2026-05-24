// BatchForceAnalyze - Force disassembly + function creation for a list of addresses in one run
// Reads addresses (one per line, hex with or without 0x prefix) from an input file
// Much faster than running forceanalyze once per function
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

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

public class BatchForceAnalyze extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();

        if (args.length < 1) {
            println("Usage: BatchForceAnalyze.java <address-list-file>");
            println("File format: one hex address per line (with or without 0x prefix)");
            println("Example file contents:");
            println("  0x00501b4c");
            println("  0x005012dc");
            return;
        }

        String inputFile = args[0];

        println("======================================================================");
        println("BATCH FORCE ANALYZE");
        println("======================================================================");
        println("Input: " + inputFile);
        println("");

        List<Long> addresses = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                try {
                    String hex = line.startsWith("0x") || line.startsWith("0X")
                            ? line.substring(2) : line;
                    addresses.add(Long.parseLong(hex, 16));
                } catch (NumberFormatException e) {
                    println("  SKIP (bad address): " + line);
                }
            }
        }

        println("Addresses to process: " + addresses.size());
        println("");

        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();

        int created = 0;
        int alreadyExisted = 0;
        int failed = 0;

        for (long addrVal : addresses) {
            Address addr = toAddr(addrVal);

            // Skip if already a properly named function (not FUN_ prefix)
            Function existing = fm.getFunctionAt(addr);
            if (existing != null && !existing.getName().startsWith("FUN_")
                    && !existing.getName().startsWith("BYTE_")
                    && !existing.getName().startsWith("SUB_")) {
                alreadyExisted++;
                continue;
            }

            // Remove stale function/data at address
            if (existing != null) {
                fm.removeFunction(addr);
            }

            // Clear any stale code units
            listing.clearCodeUnits(addr, addr.add(3), false);

            // Disassemble
            boolean ok = disassemble(addr);
            if (!ok) {
                println("  WARN: disassemble returned false @ " + addr);
            }

            Instruction instr = listing.getInstructionAt(addr);
            if (instr == null) {
                println("  FAIL: no instruction at " + addr);
                failed++;
                continue;
            }

            // Create the function (no name — will be named via function_renames.csv import)
            Function func = createFunction(addr, null);
            if (func != null) {
                created++;
            } else {
                println("  FAIL: createFunction returned null @ " + addr);
                failed++;
            }
        }

        println("");
        println("======================================================================");
        println("BATCH FORCE ANALYZE COMPLETE");
        println("  Created:       " + created);
        println("  Already named: " + alreadyExisted);
        println("  Failed:        " + failed);
        println("  Total:         " + addresses.size());
        println("======================================================================");
    }
}
