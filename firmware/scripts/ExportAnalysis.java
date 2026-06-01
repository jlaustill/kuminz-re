// Export Analysis Script
// Exports function names, global variables, and decompilation to CSV and text files
// Compatible with J90280.05 CSV format for consistency
// @author J90350.00_analysis
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.util.task.TaskMonitor;

public class ExportAnalysis extends GhidraScript {

    private String firmwareName;


    @Override
    public void run() throws Exception {
        // Get firmware name from program (e.g., "J90280.05.full.bin" -> "J90280.05")
        String programName = currentProgram.getName();
        firmwareName = ScriptUtils.extractFirmwareName(programName);

        println("=".repeat(70));
        println("EXPORT ANALYSIS - " + firmwareName);
        println("=".repeat(70));
        println("");

        // Get output directory from arguments or use default
        String[] args = getScriptArgs();
        String outputDir;

        if (args.length > 0) {
            outputDir = args[0];
        } else {
            outputDir = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../output";
        }

        // Create output directory if needed
        File outputFolder = new File(outputDir);
        if (!outputFolder.exists()) {
            outputFolder.mkdirs();
        }

        println("Output directory: " + outputDir);
        println("");

        try {
            // The build writes ONLY the decompilation. The CSVs (function_renames.csv,
            // global_variables.csv, ...) are hand-authored INPUTS — the source of truth —
            // and are never overwritten by a build. To name/type something, edit the CSV
            // (using this .cpp to spot FUN_/DAT_ symbols) and rebuild.
            println("Exporting decompilation...");
            int decompCount = exportDecompilation(outputDir);
            println("  Exported " + decompCount + " functions to " + firmwareName + ".ghidra.cpp");

            println("");
            println("=".repeat(70));
            println("EXPORT COMPLETE!");
            println("=".repeat(70));
            println("File written (the only build output):");
            println("  - " + outputDir + "/" + firmwareName + ".ghidra.cpp");

        } catch (Exception e) {
            println("ERROR during export: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private int exportDecompilation(String outputDir) throws Exception {
        String outputFile = outputDir + "/" + firmwareName + ".ghidra.cpp";

        // Initialize decompiler
        DecompInterface decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        decompiler.setOptions(options);
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(true);
        decompiler.setSimplificationStyle("decompile");

        if (!decompiler.openProgram(currentProgram)) {
            throw new Exception("Failed to initialize decompiler");
        }

        // Get all functions sorted by address
        List<Function> functions = new ArrayList<>();
        FunctionIterator funcIter = currentProgram.getFunctionManager().getFunctions(true);
        while (funcIter.hasNext()) {
            functions.add(funcIter.next());
        }

        Collections.sort(functions, (f1, f2) -> f1.getEntryPoint().compareTo(f2.getEntryPoint()));

        int functionCount = 0;

        try (FileWriter writer = new FileWriter(outputFile)) {
            writer.write("// Ghidra C++ Decompilation Export - " + firmwareName + " Firmware\n");
            writer.write("// Generated: " + new java.util.Date().toString() + "\n");
            writer.write("\n\n");

            for (Function function : functions) {
                try {
                    DecompileResults results = decompiler.decompileFunction(function, 30, TaskMonitor.DUMMY);

                    if (results != null && results.decompileCompleted()) {
                        String funcName = function.getName();
                        String address = String.format("0x%08x", function.getEntryPoint().getOffset());

                        writer.write("//\n");
                        writer.write("// Function: " + funcName + " @ " + address + "\n");
                        writer.write("//\n");

                        String decompiledCode = results.getDecompiledFunction().getC();
                        writer.write(decompiledCode);
                        writer.write("\n\n");

                        functionCount++;

                        if (functionCount % 50 == 0) {
                            println("  Decompiled " + functionCount + " functions...");
                        }
                    }

                } catch (Exception e) {
                    // Skip functions that fail to decompile
                }
            }

            writer.write("// Export complete - " + functionCount + " functions processed\n");

        } finally {
            decompiler.dispose();
        }

        return functionCount;
    }
}
