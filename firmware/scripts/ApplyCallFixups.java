// Apply Call Fixups Script
// Reads call_fixups.csv (address,function_name,fixup_name,comment) and folds the
// named compiler-runtime helper calls into inline p-code, so the decompiler shows
// the operation (e.g. division) instead of an opaque call. Fixup p-code bodies are
// stored as XML in <scriptsDir>/callfixups/<fixup_name>.xml and registered as
// program-stored compiler-spec extensions (reproducible; no Ghidra install edits).
// Args: <csvPath> <callfixupsDir>
// @category Analysis

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.nio.file.Files;
import java.util.HashSet;
import java.util.Set;

import ghidra.app.script.GhidraScript;
import ghidra.program.database.SpecExtension;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class ApplyCallFixups extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("Usage: ApplyCallFixups <csvPath> <callfixupsDir>");
            return;
        }
        File csv = new File(args[0]);
        File fixupDir = new File(args[1]);
        if (!csv.exists()) {
            println("No call_fixups.csv at " + csv + " - skipping");
            return;
        }

        SpecExtension ext = new SpecExtension(currentProgram);
        Set<String> registered = new HashSet<>();
        int applied = 0;
        int txId = currentProgram.startTransaction("Apply Call Fixups");
        try (BufferedReader reader = new BufferedReader(new FileReader(csv))) {
            String line;
            boolean first = true;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (first) { first = false; continue; }          // header
                if (line.isEmpty() || line.startsWith("#")) continue;

                String[] p = ScriptUtils.parseCSVLine(line);
                if (p.length < 3) continue;
                String addrStr = p[0].trim();
                String fixupName = p[2].trim();
                if (addrStr.isEmpty() || fixupName.isEmpty()) continue;

                // Register the fixup definition once (program-stored spec extension).
                if (!registered.contains(fixupName)) {
                    File xml = new File(fixupDir, fixupName + ".xml");
                    if (!xml.exists()) {
                        println("  WARN: fixup XML not found: " + xml + " - skipping " + addrStr);
                        continue;
                    }
                    String doc = new String(Files.readAllBytes(xml.toPath()));
                    ext.addReplaceCompilerSpecExtension(doc, monitor);
                    registered.add(fixupName);
                    println("  registered call-fixup: " + fixupName);
                }

                Address addr = toAddr(ScriptUtils.parseAddress(addrStr));
                Function f = getFunctionAt(addr);
                if (f == null) {
                    println("  WARN: no function at " + addrStr + " (" + fixupName + ")");
                    continue;
                }
                f.setCallFixup(fixupName);
                applied++;
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }
        println("Applied " + applied + " call fixups (" + registered.size() + " distinct definitions)");
    }
}
