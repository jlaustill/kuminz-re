// BatchForceAnalyzeNamed - Force function creation with explicit names from a CSV file
// CSV format: address,name (header line required)
// Use instead of BatchForceAnalyze when names are known upfront — ensures names stick
// by passing them to createFunction() rather than relying on setName() after the fact.
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

public class BatchForceAnalyzeNamed extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("Usage: BatchForceAnalyzeNamed.java <address-name-csv>");
            println("CSV format: address,name (with header row)");
            return;
        }

        String inputFile = args[0];

        println("======================================================================");
        println("BATCH FORCE ANALYZE (NAMED)");
        println("======================================================================");
        println("Input: " + inputFile);
        println("");

        List<long[]> addrs = new ArrayList<>();
        List<String> names = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
            String line;
            boolean header = true;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                if (header) { header = false; continue; }  // skip CSV header
                String[] parts = line.split(",", 2);
                if (parts.length < 2) continue;
                String addrStr = parts[0].trim();
                String name = parts[1].trim();
                try {
                    String hex = addrStr.startsWith("0x") || addrStr.startsWith("0X")
                            ? addrStr.substring(2) : addrStr;
                    addrs.add(new long[]{Long.parseLong(hex, 16)});
                    names.add(name);
                } catch (NumberFormatException e) {
                    println("  SKIP bad address: " + addrStr);
                }
            }
        }

        println("Functions to create: " + addrs.size());
        println("");

        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();

        int created = 0;
        int skipped = 0;
        int failed = 0;

        for (int i = 0; i < addrs.size(); i++) {
            long addrVal = addrs.get(i)[0];
            String name = names.get(i);
            Address addr = toAddr(addrVal);

            // Skip if already correctly named
            Function existing = fm.getFunctionAt(addr);
            if (existing != null && existing.getName().equals(name)) {
                skipped++;
                continue;
            }

            // Remove stale function
            if (existing != null) {
                fm.removeFunction(addr);
            }

            // Clear stale code units
            listing.clearCodeUnits(addr, addr.add(3), false);

            // Disassemble
            disassemble(addr);

            Instruction instr = listing.getInstructionAt(addr);
            if (instr == null) {
                println("  FAIL: no instruction @ " + addr + " (" + name + ")");
                failed++;
                continue;
            }

            // Create with explicit name — this ensures the name is the primary symbol
            Function func = createFunction(addr, name);
            if (func != null) {
                created++;
                if (created % 50 == 0) {
                    println("  Created " + created + " functions...");
                }
            } else {
                println("  FAIL: createFunction returned null @ " + addr + " (" + name + ")");
                failed++;
            }
        }

        println("");
        println("======================================================================");
        println("COMPLETE");
        println("  Created:  " + created);
        println("  Skipped:  " + skipped + " (already correctly named)");
        println("  Failed:   " + failed);
        println("======================================================================");
    }
}
