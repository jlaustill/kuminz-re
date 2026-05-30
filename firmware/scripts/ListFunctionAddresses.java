// ListFunctionAddresses - dump every function entry-point address (named OR FUN_).
// Diagnostic for reproducibility checks: compare the function SET across rebuilds.
// Unlike export (which skips FUN_ functions), this lists ALL of them.
//
// Usage: ./analyze.sh listfuncs <outfile>
// @author kuminz-re
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ListFunctionAddresses extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        List<String> addrs = new ArrayList<>();
        while (it.hasNext()) {
            Function f = it.next();
            addrs.add(String.format("0x%08x", f.getEntryPoint().getOffset()));
        }
        Collections.sort(addrs);

        if (args.length > 0) {
            try (FileWriter w = new FileWriter(args[0])) {
                for (String a : addrs) w.write(a + "\n");
            }
            println("Wrote " + addrs.size() + " function addresses to " + args[0]);
        } else {
            for (String a : addrs) println(a);
            println("Total: " + addrs.size());
        }
    }
}
