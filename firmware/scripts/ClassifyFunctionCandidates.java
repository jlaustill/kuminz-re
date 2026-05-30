// ClassifyFunctionCandidates.java
// Classifies candidate function addresses by their INCOMING references, to distinguish a
// real function entry (target of a CALL) from a spurious mid-function split (reached only by
// jump or fallthrough). Used to vet deletion candidates before they go into
// deleted_functions.csv: CALL-targets must NOT be deleted; jump/fallthrough-only entries are
// the splits auto-analysis over-creates.
//
// Input: a file of addresses (one per line, '#'/header lines ignored).
// Usage: ./analyze.sh classifyfuncs <addr-file> [out.csv]
// @author kuminz-re
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceManager;
import ghidra.program.model.symbol.RefType;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class ClassifyFunctionCandidates extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length == 0) {
            println("Usage: ClassifyFunctionCandidates.java <addr-file> [out.csv]");
            return;
        }
        String outPath = args.length > 1 ? args[1] : null;
        ReferenceManager rm = currentProgram.getReferenceManager();
        StringBuilder sb = new StringBuilder("address,call_refs,jump_refs,other_refs,classification\n");
        int real = 0, split = 0;

        try (BufferedReader r = new BufferedReader(new FileReader(args[0]))) {
            String line;
            while ((line = r.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#") || line.startsWith("address")) continue;
                String addrStr = line.split(",", 2)[0].trim();
                long v;
                try { v = ScriptUtils.parseAddress(addrStr); } catch (Exception e) { continue; }
                Address a = toAddr(v);

                int call = 0, jump = 0, other = 0;
                for (Reference ref : rm.getReferencesTo(a)) {
                    RefType t = ref.getReferenceType();
                    if (t.isCall()) call++;
                    else if (t.isJump()) jump++;
                    else other++;
                }
                String cls;
                if (call > 0) { cls = "REAL_call_target"; real++; }
                else { cls = (jump > 0) ? "SPLIT_jump_only" : "SPLIT_fallthrough_or_none"; split++; }
                sb.append(String.format("0x%08x,%d,%d,%d,%s%n", v, call, jump, other, cls));
            }
        }

        if (outPath != null) {
            try (FileWriter w = new FileWriter(outPath)) { w.write(sb.toString()); }
            println("Wrote classification to " + outPath);
        } else {
            print(sb.toString());
        }
        println("REAL_call_target: " + real + "   SPLIT (jump/fallthrough only): " + split);
    }
}
