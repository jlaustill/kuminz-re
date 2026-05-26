// Export Analysis Script
// Exports function names, global variables, and decompilation to CSV and text files
// Compatible with J90280.05 CSV format for consistency
// @author J90350.00_analysis
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.Enum;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SymbolType;
import ghidra.util.task.TaskMonitor;

public class ExportAnalysis extends GhidraScript {

    private String firmwareName;

    // Ghidra primitive type names — anything NOT in this set is a user-named type
    // (struct, enum, typedef) that must be preserved through the export cycle.
    private static final Set<String> PRIMITIVE_TYPES = new HashSet<>(Arrays.asList(
        "word", "byte", "dword", "qword",
        "sbyte", "sword", "sdword", "sqword",
        "pointer", "bool",
        "short", "int", "long",
        "ushort", "uint", "ulong",
        "undefined", "undefined1", "undefined2", "undefined4", "undefined8",
        "float", "double", "unicode"
    ));

    @Override
    public void run() throws Exception {
        // Get firmware name from program (e.g., "J90280.05.full.bin" -> "J90280.05")
        String programName = currentProgram.getName();
        firmwareName = programName.replaceAll("\\.full\\.bin$", "").replaceAll("\\.rom\\.bin$", "").replaceAll("\\.bin$", "");

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
            println("  Exported " + decompCount + " functions to " + firmwareName + ".ghidra.cpp");

            println("");
            println("=".repeat(70));
            println("EXPORT COMPLETE!");
            println("=".repeat(70));
            println("Files created:");
            println("  - " + outputDir + "/function_renames.csv");
            println("  - " + outputDir + "/global_variables.csv");
            println("  - " + outputDir + "/" + firmwareName + ".ghidra.cpp");

        } catch (Exception e) {
            println("ERROR during export: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private int exportFunctionNames(String outputDir) throws IOException {
        String outputFile = outputDir + "/function_renames.csv";

        // Preserve comment lines from existing CSV (keyed by following address)
        Map<String, List<String>> commentsBefore = new HashMap<>();
        List<String> headerComments = new ArrayList<>();
        if (new File(outputFile).exists()) {
            try (BufferedReader reader = new BufferedReader(new FileReader(outputFile))) {
                String line;
                List<String> pendingComments = new ArrayList<>();
                boolean pastHeader = false;
                while ((line = reader.readLine()) != null) {
                    if (line.startsWith("#")) {
                        pendingComments.add(line);
                    } else {
                        if (!pendingComments.isEmpty()) {
                            if (!pastHeader) {
                                headerComments.addAll(pendingComments);
                            } else {
                                // Key comments by the address line that follows them
                                String addr = line.split(",")[0].trim();
                                commentsBefore.put(addr, new ArrayList<>(pendingComments));
                            }
                            pendingComments.clear();
                        }
                        pastHeader = true;
                    }
                }
                // Trailing comments (after last entry) - attach to special key
                if (!pendingComments.isEmpty()) {
                    commentsBefore.put("__trailing__", new ArrayList<>(pendingComments));
                }
            }
        }

        // Get all functions and sort by address
        List<Function> functions = new ArrayList<>();
        FunctionIterator funcIter = currentProgram.getFunctionManager().getFunctions(true);
        while (funcIter.hasNext()) {
            functions.add(funcIter.next());
        }

        Collections.sort(functions, (f1, f2) -> f1.getEntryPoint().compareTo(f2.getEntryPoint()));

        try (FileWriter writer = new FileWriter(outputFile)) {
            // Write header comments (before the CSV header)
            for (String comment : headerComments) {
                writer.write(comment + "\n");
            }

            // Write header
            writer.write("address,name\n");

            for (Function func : functions) {
                String name = func.getName();
                // Skip default function names (FUN_xxxxx)
                if (name.startsWith("FUN_")) {
                    continue;
                }

                String address = String.format("0x%08x", func.getEntryPoint().getOffset());

                // Write any comment lines that preceded this address
                List<String> comments = commentsBefore.get(address);
                if (comments != null) {
                    for (String comment : comments) {
                        writer.write(comment + "\n");
                    }
                }

                String plateComment = currentProgram.getListing().getComment(CodeUnit.PLATE_COMMENT, func.getEntryPoint());
                if (plateComment != null && !plateComment.isEmpty()) {
                    writer.write(address + "," + name + "," + plateComment + "\n");
                } else {
                    writer.write(address + "," + name + "\n");
                }
            }

            // Write any trailing comments
            List<String> trailing = commentsBefore.get("__trailing__");
            if (trailing != null) {
                for (String comment : trailing) {
                    writer.write(comment + "\n");
                }
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

        // Phase A: Read existing CSV to preserve named type annotations and comments.
        // Ghidra may revert manually-applied enum/struct types to primitives between
        // sessions, so the CSV is the authoritative record of user-defined type intent.
        Map<String, String> existingTypes    = new HashMap<>();
        Map<String, String> existingComments = new HashMap<>();
        Map<String, List<String>> commentsBefore = new HashMap<>();
        List<String> headerComments = new ArrayList<>();

        if (new File(outputFile).exists()) {
            try (BufferedReader reader = new BufferedReader(new FileReader(outputFile))) {
                String line;
                List<String> pendingComments = new ArrayList<>();
                boolean pastHeader = false;
                while ((line = reader.readLine()) != null) {
                    if (line.startsWith("#")) {
                        pendingComments.add(line);
                    } else {
                        // Split into at most 4 fields: address, name, type, comment
                        // (4-arg limit keeps commas inside the comment field intact)
                        String[] parts = line.split(",", 4);
                        String addr = parts[0].trim();

                        if (!pendingComments.isEmpty()) {
                            if (!pastHeader) {
                                headerComments.addAll(pendingComments);
                            } else {
                                commentsBefore.put(addr, new ArrayList<>(pendingComments));
                            }
                            pendingComments.clear();
                        }
                        pastHeader = true;

                        // Skip the header row itself
                        if (addr.equals("address")) continue;

                        if (parts.length >= 3) existingTypes.put(addr, parts[2].trim());
                        if (parts.length >= 4) existingComments.put(addr, parts[3].trim());
                    }
                }
                if (!pendingComments.isEmpty()) {
                    commentsBefore.put("__trailing__", new ArrayList<>(pendingComments));
                }
            } catch (IOException e) {
                // First run — no existing CSV; maps stay empty
            }
        }

        // Phase B: Collect non-function, non-default symbols sorted by address
        SymbolTable symbolTable = currentProgram.getSymbolTable();
        List<Symbol> variables = new ArrayList<>();

        SymbolIterator symbols = symbolTable.getAllSymbols(true);
        while (symbols.hasNext()) {
            Symbol sym = symbols.next();

            if (sym.getSymbolType() == SymbolType.FUNCTION) continue;

            String name = sym.getName();
            if (name.startsWith("DAT_") || name.startsWith("LAB_") || name.startsWith("s_")) continue;
            if (sym.isExternal()) continue;

            variables.add(sym);
        }

        Collections.sort(variables, (s1, s2) -> s1.getAddress().compareTo(s2.getAddress()));

        // Phase C: Write output with merged type selection
        try (FileWriter writer = new FileWriter(outputFile)) {
            // Preserve # comments that preceded the header
            for (String comment : headerComments) {
                writer.write(comment + "\n");
            }

            writer.write("address,name,type,comment\n");

            for (Symbol sym : variables) {
                String address = String.format("0x%08x", sym.getAddress().getOffset());
                String name = sym.getName();

                // Get the type Ghidra currently has at this address
                String ghidraType = "";
                try {
                    ghidra.program.model.listing.Data data =
                            currentProgram.getListing().getDataAt(sym.getAddress());
                    if (data != null && data.getDataType() != null) {
                        ghidraType = data.getDataType().getName();
                    }
                } catch (Exception e) {
                    // Ignore type errors
                }

                // Type selection: prefer named (user-defined) types over Ghidra primitives.
                // Priority: named Ghidra type > named CSV type > primitive Ghidra type.
                String csvType = existingTypes.getOrDefault(address, "");
                String finalType;
                if (!isPrimitiveType(ghidraType)) {
                    // Ghidra has a named type (struct or enum it knows about) — trust it
                    finalType = ghidraType;
                } else if (!isPrimitiveType(csvType)) {
                    // Ghidra reverted to a primitive; CSV has a named type the user set — keep it
                    finalType = csvType;
                } else {
                    // Both primitive — use Ghidra's (may have more accurate width info)
                    finalType = ghidraType;
                }

                // Preserve the comment from the existing CSV
                String comment = existingComments.getOrDefault(address, "");

                // Write any # comment lines that preceded this address in the old CSV
                List<String> priorComments = commentsBefore.get(address);
                if (priorComments != null) {
                    for (String c : priorComments) {
                        writer.write(c + "\n");
                    }
                }

                writer.write(address + "," + name + "," + finalType + "," + comment + "\n");
            }

            // Write any trailing # comments from the old CSV
            List<String> trailing = commentsBefore.get("__trailing__");
            if (trailing != null) {
                for (String comment : trailing) {
                    writer.write(comment + "\n");
                }
            }
        }

        return variables.size();
    }

    // Returns true for Ghidra built-in primitive type names.
    // Anything NOT in this set is a user-named type (struct, enum, typedef) to preserve.
    private boolean isPrimitiveType(String typeName) {
        if (typeName == null || typeName.trim().isEmpty()) return true;
        String trimmed = typeName.trim().toLowerCase();
        // "byte *", "word *" → primitive pointer; "my_struct_t *" → named pointer
        if (trimmed.endsWith(" *")) {
            return PRIMITIVE_TYPES.contains(trimmed.substring(0, trimmed.length() - 2).trim());
        }
        return PRIMITIVE_TYPES.contains(trimmed);
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
