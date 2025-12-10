// Export Analysis Results Script
// Exports assembly listing and C++ decompilation to working/ directory for Claude Code
// @author J90280.05_analysis
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
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.util.task.TaskMonitor;

public class ExportAnalysisResults extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        println("📤 EXPORTING ANALYSIS RESULTS FOR CLAUDE CODE");
        println("==============================================");
        
        // Get project directory for output
        String projectDir = getProjectRootFolder().getProjectLocator().getProjectDir().getAbsolutePath();
        String workingDir = projectDir + "/working";
        
        // Create working directory if it doesn't exist
        File workingFolder = new File(workingDir);
        if (!workingFolder.exists()) {
            workingFolder.mkdirs();
            println("Created working directory: " + workingDir);
        }
        
        println("Exporting to: " + workingDir);
        println("");
        
        try {
            // Export 1: Assembly Listing
            println("[1/2] Exporting assembly listing...");
            exportAssemblyListing(workingDir);
            println("✓ Assembly exported to J90280.05.ghidra.asm");
            
            // Export 2: C++ Decompilation
            println("[2/2] Exporting C++ decompilation...");
            exportDecompilation(workingDir);
            println("✓ Decompilation exported to J90280.05.ghidra.cpp");
            
            println("");
            println("🎉 EXPORT COMPLETE!");
            println("==================");
            println("Claude Code can now see your latest analysis:");
            println("• working/J90280.05.ghidra.asm - Full assembly with your renamed functions/variables");
            println("• working/J90280.05.ghidra.cpp - C++ decompilation with meaningful names");
            println("");
            println("🔄 Perfect Workflow:");
            println("1. Analyze firmware in Ghidra");
            println("2. Update CSV files with discoveries"); 
            println("3. Run MasterAnalysisSetup.java");
            println("4. Run ExportAnalysisResults.java");
            println("5. Claude Code instantly sees your changes!");
            
        } catch (Exception e) {
            println("❌ Error during export: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
    private void exportAssemblyListing(String workingDir) throws IOException {
        String outputFile = workingDir + "/J90280.05.ghidra.asm";
        
        try (FileWriter writer = new FileWriter(outputFile)) {
            writer.write("; Ghidra Assembly Export - J90280.05 Firmware\n");
            writer.write("; Generated with renamed functions, variables, and labels\n");
            writer.write("; " + new java.util.Date().toString() + "\n");
            writer.write(";\n\n");
            
            Listing listing = currentProgram.getListing();
            AddressSetView addresses = currentProgram.getMemory().getLoadedAndInitializedAddressSet();
            
            int instructionCount = 0;
            
            for (Address addr : addresses.getAddresses(true)) {
                CodeUnit codeUnit = listing.getCodeUnitAt(addr);
                if (codeUnit != null && codeUnit instanceof Instruction) {
                    Instruction instruction = (Instruction) codeUnit;
                    
                    // Write address and instruction
                    String addressStr = String.format("%08x", addr.getOffset());
                    String mnemonic = instruction.getMnemonicString();
                    String operands = instruction.getDefaultOperandRepresentation(0);
                    
                    // Add additional operands if they exist
                    for (int i = 1; i < instruction.getNumOperands(); i++) {
                        operands += "," + instruction.getDefaultOperandRepresentation(i);
                    }
                    
                    // Get any comments
                    String eolComment = listing.getComment(CodeUnit.EOL_COMMENT, addr);
                    String preComment = listing.getComment(CodeUnit.PRE_COMMENT, addr);
                    
                    // Write pre-comment if exists
                    if (preComment != null && !preComment.trim().isEmpty()) {
                        writer.write("; " + preComment.replace("\n", "\n; ") + "\n");
                    }
                    
                    // Write the instruction line
                    String line = String.format("%-8s %-8s %-20s", addressStr + ":", mnemonic, operands);
                    
                    // Add EOL comment if exists
                    if (eolComment != null && !eolComment.trim().isEmpty()) {
                        line += " ; " + eolComment;
                    }
                    
                    writer.write(line + "\n");
                    instructionCount++;
                    
                    // Update progress every 1000 instructions
                    if (instructionCount % 1000 == 0) {
                        println("  Processed " + instructionCount + " instructions...");
                    }
                }
            }
            
            writer.write("\n; Export complete - " + instructionCount + " instructions exported\n");
            println("  Total instructions exported: " + instructionCount);
        }
    }
    
    private void exportDecompilation(String workingDir) throws Exception {
        String outputFile = workingDir + "/J90280.05.ghidra.cpp";
        
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
        
        try (FileWriter writer = new FileWriter(outputFile)) {
            writer.write("// Ghidra C++ Decompilation Export - J90280.05 Firmware\n");
            writer.write("// Generated with renamed functions, variables, and meaningful types\n");
            writer.write("// " + new java.util.Date().toString() + "\n");
            writer.write("\n\n");
            
            // Get all functions and sort by address
            List<Function> functions = new ArrayList<>();
            FunctionIterator funcIter = currentProgram.getFunctionManager().getFunctions(true);
            while (funcIter.hasNext()) {
                functions.add(funcIter.next());
            }
            
            // Sort functions by entry point address
            Collections.sort(functions, (f1, f2) -> f1.getEntryPoint().compareTo(f2.getEntryPoint()));
            
            int functionCount = 0;
            
            for (Function function : functions) {
                try {
                    // Decompile the function
                    DecompileResults results = decompiler.decompileFunction(function, 30, TaskMonitor.DUMMY);
                    
                    if (results != null && results.decompileCompleted()) {
                        // Write function header
                        String funcName = function.getName();
                        String address = String.format("0x%08x", function.getEntryPoint().getOffset());
                        
                        writer.write("//\n");
                        writer.write("// Function: " + funcName + " @ " + address + "\n");
                        writer.write("//\n");
                        
                        // Write the decompiled C code
                        String decompiledCode = results.getDecompiledFunction().getC();
                        writer.write(decompiledCode);
                        writer.write("\n\n");
                        
                        functionCount++;
                        
                        // Update progress every 10 functions
                        if (functionCount % 10 == 0) {
                            println("  Decompiled " + functionCount + " functions...");
                        }
                        
                    } else {
                        // Function failed to decompile
                        String funcName = function.getName();
                        String address = String.format("0x%08x", function.getEntryPoint().getOffset());
                        
                        writer.write("//\n");
                        writer.write("// Function: " + funcName + " @ " + address + "\n");
                        writer.write("// ERROR: Failed to decompile\n");
                        writer.write("//\n\n");
                    }
                    
                } catch (Exception e) {
                    println("  Warning: Failed to decompile function " + function.getName() + ": " + e.getMessage());
                }
            }
            
            writer.write("// Export complete - " + functionCount + " functions processed\n");
            println("  Total functions processed: " + functionCount);
            
        } finally {
            decompiler.dispose();
        }
    }
}