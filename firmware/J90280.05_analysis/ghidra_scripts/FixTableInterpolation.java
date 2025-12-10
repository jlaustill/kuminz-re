// Fix Table Interpolation Function Script
// Attempts multiple strategies to fix FUN_000356f8 decompilation
// @author J90280.05_analysis
// @category Analysis

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Parameter;
import ghidra.program.model.listing.ParameterImpl;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.app.cmd.function.ApplyFunctionSignatureCmd;
import ghidra.program.model.listing.FunctionSignature;
import ghidra.program.model.symbol.Namespace;

public class FixTableInterpolation extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Address of the problematic function
        Address funcAddr = toAddr(0x000356f8);
        
        // Get the function
        Function func = currentProgram.getFunctionManager().getFunctionAt(funcAddr);
        if (func == null) {
            println("No function found at address " + funcAddr);
            return;
        }
        
        println("Attempting multiple fixes for function at " + funcAddr);
        
        try {
            // Strategy 1: Clear and recreate function
            println("Strategy 1: Clearing existing function...");
            currentProgram.getFunctionManager().removeFunction(funcAddr);
            
            // Recreate function
            func = currentProgram.getFunctionManager().createFunction("coreTableInterpolation", 
                funcAddr, null, SourceType.USER_DEFINED);
            
            if (func == null) {
                println("✗ Failed to recreate function");
                return;
            }
            
            // Strategy 2: Define proper function signature
            println("Strategy 2: Setting function signature...");
            
            // Create parameter types
            DataType pointerType = new PointerDataType();
            DataType ushortType = new UnsignedShortDataType();
            DataType uintType = new UnsignedIntegerDataType();
            
            // Create parameters
            Parameter[] params = new Parameter[3];
            params[0] = new ParameterImpl("table_descriptor", pointerType, currentProgram);
            params[1] = new ParameterImpl("input_value", ushortType, currentProgram);
            params[2] = new ParameterImpl("scaling_factor", ushortType, currentProgram);
            
            // Set function signature
            func.setReturnType(uintType, SourceType.USER_DEFINED);
            func.replaceParameters(java.util.Arrays.asList(params), 
                Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
            
            println("✓ Function signature applied");
            
            // Strategy 3: Force analysis refresh
            println("Strategy 3: Forcing analysis refresh...");
            currentProgram.flushEvents();
            
            println("✓ Analysis complete. Try decompiling again in Ghidra.");
            println("If still fails, the function may need manual analysis due to complex MC68K assembly.");
            
        } catch (Exception e) {
            println("Error during fix attempt: " + e.getMessage());
            e.printStackTrace();
        }
    }
}