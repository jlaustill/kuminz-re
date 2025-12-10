// Bulk Function Creator - Creates functions at specified addresses from CSV
// Ensures functions exist before renaming attempts
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;

public class BulkFunctionCreator extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Path to CSV file (relative to project directory)
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/function_renames.csv";
        File csvFile = new File(csvPath);
        
        if (!csvFile.exists()) {
            println("✗ Error: CSV file not found at " + csvPath);
            return;
        }
        
        FunctionManager functionManager = currentProgram.getFunctionManager();
        int createdCount = 0;
        int existingCount = 0;
        int failedCount = 0;
        
        try (BufferedReader reader = new BufferedReader(new FileReader(csvFile))) {
            String line;
            boolean isFirstLine = true;
            
            while ((line = reader.readLine()) != null) {
                // Skip header line
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }
                
                // Skip empty lines
                line = line.trim();
                if (line.isEmpty()) {
                    continue;
                }
                
                // Parse CSV: address,newName
                String[] parts = line.split(",", 2);
                if (parts.length < 2) {
                    println("✗ Skipping invalid line: " + line);
                    continue;
                }
                
                String addressStr = parts[0].trim();
                String functionName = parts[1].trim();
                
                try {
                    // Parse address (remove 0x prefix if present)
                    if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
                        addressStr = addressStr.substring(2);
                    }
                    
                    long addressValue = Long.parseLong(addressStr, 16);
                    Address address = toAddr(addressValue);
                    
                    // Check if function already exists
                    Function existingFunction = functionManager.getFunctionAt(address);
                    
                    if (existingFunction != null) {
                        existingCount++;
                    } else {
                        // Try to create function at this address
                        try {
                            Function newFunction = createFunction(address, functionName);
                            if (newFunction != null) {
                                createdCount++;
                            } else {
                                println("✗ " + String.format("0x%08X", addressValue) + ": Failed to create function " + functionName);
                                failedCount++;
                            }
                        } catch (Exception e) {
                            println("✗ " + String.format("0x%08X", addressValue) + ": Error creating function " + functionName + " - " + e.getMessage());
                            failedCount++;
                        }
                    }
                    
                } catch (NumberFormatException e) {
                    println("✗ Invalid address format: " + addressStr);
                    failedCount++;
                }
            }
        } catch (Exception e) {
            println("✗ Error reading CSV file: " + e.getMessage());
            return;
        }
        
        // Only show final results
        println("Results: " + createdCount + " created, " + existingCount + " existing, " + failedCount + " failed");
        if (failedCount == 0) {
            println("✓ Functions created");
        }
    }
}