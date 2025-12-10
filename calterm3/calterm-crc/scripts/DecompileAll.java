// DecompileAll.java - Ghidra headless script to decompile all functions
// Usage: analyzeHeadless <project_dir> <project_name> -import <binary> -postscript DecompileAll.java <output_file>

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.util.task.TaskMonitor;

import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompileAll extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outputFile = args.length > 0 ? args[0] : "decompiled_output.c";

        println("Decompiling to: " + outputFile);

        DecompInterface decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        decompiler.setOptions(options);

        if (!decompiler.openProgram(currentProgram)) {
            println("Failed to initialize decompiler");
            return;
        }

        PrintWriter writer = new PrintWriter(new FileWriter(outputFile));

        // Write header
        writer.println("/*");
        writer.println(" * Decompiled from: " + currentProgram.getName());
        writer.println(" * Using Ghidra " + ghidra.framework.Application.getApplicationVersion());
        writer.println(" */");
        writer.println();

        // Iterate all functions
        FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
        int count = 0;
        int total = currentProgram.getFunctionManager().getFunctionCount();

        while (functions.hasNext() && !monitor.isCancelled()) {
            Function function = functions.next();
            count++;

            // Skip external/thunk functions
            if (function.isExternal() || function.isThunk()) {
                continue;
            }

            monitor.setMessage("Decompiling " + count + "/" + total + ": " + function.getName());

            DecompileResults results = decompiler.decompileFunction(function, 60, monitor);

            if (results != null && results.decompileCompleted()) {
                String decompiledCode = results.getDecompiledFunction().getC();
                if (decompiledCode != null && !decompiledCode.isEmpty()) {
                    writer.println("// Function: " + function.getName() + " at " + function.getEntryPoint());
                    writer.println(decompiledCode);
                    writer.println();
                }
            } else {
                writer.println("// Failed to decompile: " + function.getName() + " at " + function.getEntryPoint());
                writer.println();
            }
        }

        writer.close();
        decompiler.dispose();

        println("Decompilation complete. Output: " + outputFile);
        println("Functions processed: " + count);
    }
}
