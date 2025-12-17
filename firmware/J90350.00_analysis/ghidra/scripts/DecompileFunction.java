// Decompile Function Script
// Decompiles a single function and outputs C code to stdout
// For use with headless analyzer to get on-demand decompilation
// @author J90350.00_analysis
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.util.task.TaskMonitor;

public class DecompileFunction extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();

        if (args.length == 0) {
            println("ERROR: No function address or name provided");
            println("Usage: DecompileFunction.java <address|name>");
            println("Examples:");
            println("  DecompileFunction.java 0x22e5e");
            println("  DecompileFunction.java vp44CanMessageDispatcher");
            return;
        }

        String target = args[0].trim();
        Function function = findFunction(target);

        if (function == null) {
            println("ERROR: Function not found: " + target);
            return;
        }

        // Initialize decompiler
        DecompInterface decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        decompiler.setOptions(options);
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(true);
        decompiler.setSimplificationStyle("decompile");

        if (!decompiler.openProgram(currentProgram)) {
            println("ERROR: Failed to initialize decompiler");
            return;
        }

        try {
            DecompileResults results = decompiler.decompileFunction(function, 60, TaskMonitor.DUMMY);

            if (results != null && results.decompileCompleted()) {
                String funcName = function.getName();
                String address = String.format("0x%08x", function.getEntryPoint().getOffset());

                // Output header
                println("// ============================================================");
                println("// Function: " + funcName);
                println("// Address:  " + address);
                println("// ============================================================");
                println("");

                // Output decompiled code
                String decompiledCode = results.getDecompiledFunction().getC();
                println(decompiledCode);

            } else {
                println("ERROR: Decompilation failed for " + function.getName());
                if (results != null) {
                    println("Reason: " + results.getErrorMessage());
                }
            }

        } finally {
            decompiler.dispose();
        }
    }

    private Function findFunction(String target) {
        FunctionManager functionManager = currentProgram.getFunctionManager();

        // Try to parse as address first
        try {
            long addressValue;
            if (target.startsWith("0x") || target.startsWith("0X")) {
                addressValue = Long.parseLong(target.substring(2), 16);
            } else if (target.matches("[0-9a-fA-F]+")) {
                addressValue = Long.parseLong(target, 16);
            } else {
                // Not an address, try as name
                return findFunctionByName(target);
            }

            Address address = toAddr(addressValue);
            Function func = functionManager.getFunctionAt(address);

            if (func != null) {
                return func;
            }

            // Try to find function containing this address
            func = functionManager.getFunctionContaining(address);
            if (func != null) {
                println("NOTE: Address is within function " + func.getName() +
                        " @ " + String.format("0x%08x", func.getEntryPoint().getOffset()));
                return func;
            }

        } catch (NumberFormatException e) {
            // Not a valid hex number, try as function name
        }

        return findFunctionByName(target);
    }

    private Function findFunctionByName(String name) {
        FunctionManager functionManager = currentProgram.getFunctionManager();

        // Iterate through all functions to find matching name
        for (Function func : functionManager.getFunctions(true)) {
            if (func.getName().equals(name)) {
                return func;
            }
        }

        // Try case-insensitive match
        for (Function func : functionManager.getFunctions(true)) {
            if (func.getName().equalsIgnoreCase(name)) {
                println("NOTE: Using case-insensitive match: " + func.getName());
                return func;
            }
        }

        // Try partial match
        for (Function func : functionManager.getFunctions(true)) {
            if (func.getName().toLowerCase().contains(name.toLowerCase())) {
                println("NOTE: Using partial match: " + func.getName());
                return func;
            }
        }

        return null;
    }
}
