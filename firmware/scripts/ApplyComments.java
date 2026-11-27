// Apply Comments Script
// Reads comments.csv (address,comment) and sets each comment as a PRE comment on the
// instruction at that address; the decompiler prints it above the statement it belongs to.
// @author kuminz-re
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;

public class ApplyComments extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length == 0) {
            println("ERROR: comments.csv path required as argument");
            return;
        }
        String csvPath = args[0];
        if (!new File(csvPath).exists()) {
            println("ERROR: comments.csv not found at: " + csvPath);
            return;
        }

        int applied = 0;
        int failed = 0;
        try (BufferedReader reader = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;
            while ((line = reader.readLine()) != null) {
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }
                String[] parts = ScriptUtils.parseCSVLine(line);
                if (parts.length < 2 || parts[1].trim().isEmpty()) {
                    continue;
                }
                try {
                    Address addr = toAddr(ScriptUtils.parseAddress(parts[0].trim()));
                    if (getInstructionAt(addr) == null) {
                        println("  WARNING: no instruction at " + parts[0].trim() + " - comment not applied");
                        failed++;
                        continue;
                    }
                    setPreComment(addr, parts[1].trim());
                    applied++;
                } catch (Exception e) {
                    println("  WARNING: bad row '" + line + "': " + e.getMessage());
                    failed++;
                }
            }
        }
        println("Comments applied: " + applied + ", failed: " + failed);
    }
}
