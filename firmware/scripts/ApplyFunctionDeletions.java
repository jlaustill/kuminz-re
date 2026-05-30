// ApplyFunctionDeletions.java
// Removes function records listed in deleted_functions.csv — the deletion delta that makes
// the function set reproducible from CSVs. Auto-analysis can create spurious functions
// (mid-code splits, false entries from indirect jumps); deleting them is the only function
// delta `import` does not already capture, so it must be recorded here and re-applied after
// every `analyze`. The CSV-driven counterpart to the ad-hoc `deletefuncs` command.
//
// CSV format (header required, '#' comment lines ignored):
//   address,reason
//   0x00025050,spurious mid-function split
//
// Usage: ./analyze.sh deletions   (wired to ApplyFunctionDeletions.java <csv>)
// @author kuminz-re
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class ApplyFunctionDeletions extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length == 0) {
            println("Usage: ApplyFunctionDeletions.java <deleted_functions.csv>");
            return;
        }
        String csvPath = args[0];
        if (!new File(csvPath).exists()) {
            println("No deletions file at " + csvPath + " — nothing to do.");
            return;
        }

        FunctionManager fm = currentProgram.getFunctionManager();
        int txId = currentProgram.startTransaction("Apply function deletions");
        int removed = 0;
        int notFound = 0;
        int badRows = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean header = true;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                if (header) { header = false; continue; }   // skip CSV header row

                String addrStr = line.split(",", 2)[0].trim();
                long addrVal;
                try {
                    addrVal = ScriptUtils.parseAddress(addrStr);
                } catch (NumberFormatException e) {
                    println("  Bad address: '" + addrStr + "'");
                    badRows++;
                    continue;
                }

                Address addr = toAddr(addrVal);
                Function func = (addr == null) ? null : fm.getFunctionAt(addr);
                if (func == null) {
                    // Idempotent: already absent (e.g. a daily import->export cycle where
                    // analyze never ran) is not an error.
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
        println("APPLY FUNCTION DELETIONS COMPLETE");
        println("  Removed:   " + removed);
        println("  Not found: " + notFound + " (already absent — fine)");
        if (badRows > 0) println("  Bad rows:  " + badRows);
        println("======================================================================");
        println("Run 'import' (to re-apply globals at freed addresses) then 'export'.");
    }
}
