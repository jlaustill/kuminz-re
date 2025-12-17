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
import java.io.IOException;
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
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SymbolType;
import ghidra.util.task.TaskMonitor;

public class ExportAnalysis extends GhidraScript {

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("EXPORT ANALYSIS - J90350.00");
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
            // Export 1: Function names
            println("[1/3] Exporting function names...");
            int funcCount = exportFunctionNames(outputDir);
            println("  Exported " + funcCount + " functions to function_renames.csv");

            // Export 2: Global variables/labels
            println("[2/3] Exporting global variables...");
            int varCount = exportGlobalVariables(outputDir);
            println("  Exported " + varCount + " variables to global_variables.csv");

            // Export 3: Decompilation
            println("[3/3] Exporting decompilation...");
            int decompCount = exportDecompilation(outputDir);
            println("  Exported " + decompCount + " functions to J90350.00.ghidra.cpp");

            println("");
            println("=".repeat(70));
            println("EXPORT COMPLETE!");
            println("=".repeat(70));
            println("Files created:");
            println("  - " + outputDir + "/function_renames.csv");
            println("  - " + outputDir + "/global_variables.csv");
            println("  - " + outputDir + "/J90350.00.ghidra.cpp");

        } catch (Exception e) {
            println("ERROR during export: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private int exportFunctionNames(String outputDir) throws IOException {
        String outputFile = outputDir + "/function_renames.csv";

        // Get all functions and sort by address
        List<Function> functions = new ArrayList<>();
        FunctionIterator funcIter = currentProgram.getFunctionManager().getFunctions(true);
        while (funcIter.hasNext()) {
            functions.add(funcIter.next());
        }

        Collections.sort(functions, (f1, f2) -> f1.getEntryPoint().compareTo(f2.getEntryPoint()));

        try (FileWriter writer = new FileWriter(outputFile)) {
            // Write header
            writer.write("address,name\n");

            for (Function func : functions) {
                String name = func.getName();
                // Skip default function names (FUN_xxxxx)
                if (name.startsWith("FUN_")) {
                    continue;
                }

                String address = String.format("0x%08x", func.getEntryPoint().getOffset());
                writer.write(address + "," + name + "\n");
            }
        }

        // Count non-default functions
        int count = 0;
        for (Function func : functions) {
            if (!func.getName().startsWith("FUN_")) {
                count++;
            }
        }

        return count;
    }

    private int exportGlobalVariables(String outputDir) throws IOException {
        String outputFile = outputDir + "/global_variables.csv";

        SymbolTable symbolTable = currentProgram.getSymbolTable();
        List<Symbol> variables = new ArrayList<>();

        // Collect non-function, non-default symbols
        SymbolIterator symbols = symbolTable.getAllSymbols(true);
        while (symbols.hasNext()) {
            Symbol sym = symbols.next();

            // Skip functions
            if (sym.getSymbolType() == SymbolType.FUNCTION) {
                continue;
            }

            // Skip default names (DAT_xxxxx, LAB_xxxxx)
            String name = sym.getName();
            if (name.startsWith("DAT_") || name.startsWith("LAB_") || name.startsWith("s_")) {
                continue;
            }

            // Skip external symbols
            if (sym.isExternal()) {
                continue;
            }

            variables.add(sym);
        }

        // Sort by address
        Collections.sort(variables, (s1, s2) -> s1.getAddress().compareTo(s2.getAddress()));

        try (FileWriter writer = new FileWriter(outputFile)) {
            // Write header matching J90280.05 format
            writer.write("address,name,type,comment\n");

            for (Symbol sym : variables) {
                String address = String.format("0x%08x", sym.getAddress().getOffset());
                String name = sym.getName();

                // Try to get type info
                String type = "";
                try {
                    ghidra.program.model.listing.Data data =
                            currentProgram.getListing().getDataAt(sym.getAddress());
                    if (data != null && data.getDataType() != null) {
                        type = data.getDataType().getName();
                    }
                } catch (Exception e) {
                    // Ignore type errors
                }

                writer.write(address + "," + name + "," + type + ",\n");
            }
        }

        return variables.size();
    }

    private int exportDecompilation(String outputDir) throws Exception {
        String outputFile = outputDir + "/J90350.00.ghidra.cpp";

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
            writer.write("// Ghidra C++ Decompilation Export - J90350.00 Firmware\n");
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
