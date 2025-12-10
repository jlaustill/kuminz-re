// Force Decompile Script for Failed Functions
// @author J90280.05_analysis
// @category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;

public class ForceDecompile extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Address of the function that failed to decompile
        Address funcAddr = toAddr(0x000356f8);
        
        // Get the function
        Function func = currentProgram.getFunctionManager().getFunctionAt(funcAddr);
        if (func == null) {
            println("No function found at address " + funcAddr);
            return;
        }
        
        println("Attempting to force decompile function at " + funcAddr);
        
        // Create decompiler interface
        DecompInterface decompiler = new DecompInterface();
        
        try {
            // Initialize decompiler
            if (!decompiler.openProgram(currentProgram)) {
                println("Failed to initialize decompiler");
                return;
            }
            
            // Initialize decompiler options properly
            decompiler.toggleCCode(true);
            decompiler.toggleSyntaxTree(false);
            
            // Attempt decompilation
            DecompileResults results = decompiler.decompileFunction(func, 30, monitor);
            
            if (results != null && results.decompileCompleted()) {
                println("✓ Successfully decompiled function!");
                println("Decompiled C code:");
                println(results.getDecompiledFunction().getC());
            } else {
                println("✗ Decompilation failed again");
                if (results != null) {
                    println("Error: " + results.getErrorMessage());
                }
            }
            
        } finally {
            decompiler.dispose();
        }
    }
}