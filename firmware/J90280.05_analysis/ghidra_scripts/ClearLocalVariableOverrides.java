// Ghidra Clear Local Variable Overrides Script
// Clears all local variable name/type overrides for specified functions
// This resets variables back to Ghidra's auto-generated names (iVar1, bVar2, etc.)
// @author J90280.05_analysis
// @category Analysis
// @keybinding
// @menupath Tools.Clear Local Variable Overrides
// @toolbar

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Variable;
import ghidra.program.model.symbol.SourceType;

public class ClearLocalVariableOverrides extends GhidraScript {

    @Override
    public void run() throws Exception {
        // Path to CSV file that lists functions to clear
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                        "/clear_local_overrides.csv";

        println("=== Clear Local Variable Overrides ===");
        println("Reading from: " + csvPath);
        println("");
        println("This script clears USER_DEFINED local variable overrides,");
        println("resetting them back to Ghidra's auto-inferred names/types.");
        println("");

        FunctionManager functionManager = currentProgram.getFunctionManager();

        Set<Long> functionsToClear = new HashSet<>();

        // Read CSV file
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;

            while ((line = br.readLine()) != null) {
                // Skip header line
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                // Skip empty lines and comments
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }

                // Parse CSV: function_address,function_name,reason
                String[] parts = line.split(",");
                if (parts.length < 1) {
                    continue;
                }

                String functionAddressStr = parts[0].trim();

                try {
                    long addr = parseHexAddress(functionAddressStr);
                    functionsToClear.add(addr);
                } catch (NumberFormatException e) {
                    println("⚠ Invalid address: " + functionAddressStr);
                }
            }

        } catch (IOException e) {
            println("Note: No clear_local_overrides.csv found.");
            println("Creating template file...");
            createTemplateFile(csvPath);
            println("Created: " + csvPath);
            println("");
            println("Add function addresses to clear, then re-run this script.");
            return;
        }

        if (functionsToClear.isEmpty()) {
            println("No functions specified to clear.");
            println("Add entries to clear_local_overrides.csv");
            return;
        }

        int clearedCount = 0;
        int functionCount = 0;

        for (Long addrLong : functionsToClear) {
            Address addr = toAddr(addrLong);
            Function function = functionManager.getFunctionAt(addr);

            if (function == null) {
                println("✗ No function at 0x" + Long.toHexString(addrLong));
                continue;
            }

            println("Processing: " + function.getName() + " @ 0x" + Long.toHexString(addrLong));
            functionCount++;

            // Get all local variables (not parameters)
            Variable[] localVars = function.getLocalVariables();

            for (Variable var : localVars) {
                // Check if this variable has a user-defined override
                if (var.getSource() == SourceType.USER_DEFINED) {
                    String oldName = var.getName();
                    try {
                        // Remove the variable override by deleting it
                        // This forces Ghidra to re-infer the variable
                        function.removeVariable(var);
                        println("  ✓ Cleared override: " + oldName);
                        clearedCount++;
                    } catch (Exception e) {
                        println("  ✗ Failed to clear " + oldName + ": " + e.getMessage());
                    }
                }
            }
        }

        println("");
        println("=== Summary ===");
        println("Functions processed: " + functionCount);
        println("Overrides cleared: " + clearedCount);
        println("");
        println("Run ApplyAndExport to regenerate decompiled output.");
    }

    private long parseHexAddress(String addressStr) {
        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
            return Long.parseLong(addressStr.substring(2), 16);
        }
        return Long.parseLong(addressStr, 16);
    }

    private void createTemplateFile(String csvPath) throws IOException {
        java.io.FileWriter writer = new java.io.FileWriter(csvPath);
        writer.write("function_address,function_name,reason\n");
        writer.write("# Add function addresses here to clear their local variable overrides\n");
        writer.write("# Example:\n");
        writer.write("# 0x0000a6fa,sensorFaultDebounceMonitor,Reset corrupted variable types\n");
        writer.close();
    }
}
