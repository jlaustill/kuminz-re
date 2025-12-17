// Apply Relocation Map Script
// Reads relocation_map.csv and applies function names from J90280.05 to J90350.00
// Creates functions at target addresses and renames them
// @author J90350.00_analysis
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.symbol.SourceType;

public class ApplyRelocationMap extends GhidraScript {

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY RELOCATION MAP - Bootstrap J90350.00 from J90280.05");
        println("=".repeat(70));
        println("");

        // Get CSV path from script arguments or use default
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            // Default path relative to project
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../output/relocation_map.csv";
        }

        File csvFile = new File(csvPath);
        if (!csvFile.exists()) {
            println("ERROR: CSV file not found at " + csvPath);
            println("Usage: Pass CSV path as script argument");
            return;
        }

        println("Reading relocation map: " + csvPath);
        println("");

        FunctionManager functionManager = currentProgram.getFunctionManager();

        int createdCount = 0;
        int renamedCount = 0;
        int skippedCount = 0;
        int failedCount = 0;
        int totalProcessed = 0;

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

                // Parse CSV: source_address,source_name,target_address,confidence,status
                String[] parts = line.split(",");
                if (parts.length < 5) {
                    continue;
                }

                String sourceAddressStr = parts[0].trim();
                String sourceName = parts[1].trim();
                String targetAddressStr = parts[2].trim();
                String confidenceStr = parts[3].trim();
                String status = parts[4].trim();

                // Skip entries with N/A target address
                if (targetAddressStr.equals("N/A") || targetAddressStr.isEmpty()) {
                    skippedCount++;
                    continue;
                }

                // Apply matches with confidence >= 60% (includes "similar" functions)
                int confidence;
                try {
                    confidence = Integer.parseInt(confidenceStr);
                } catch (NumberFormatException e) {
                    skippedCount++;
                    continue;
                }

                if (confidence < 60) {
                    skippedCount++;
                    continue;
                }

                totalProcessed++;

                try {
                    // Parse target address
                    long targetAddress;
                    if (targetAddressStr.startsWith("0x") || targetAddressStr.startsWith("0X")) {
                        targetAddress = Long.parseLong(targetAddressStr.substring(2), 16);
                    } else {
                        targetAddress = Long.parseLong(targetAddressStr, 16);
                    }

                    Address address = toAddr(targetAddress);

                    // Check if function exists at this address
                    Function existingFunction = functionManager.getFunctionAt(address);

                    if (existingFunction == null) {
                        // Try to create function
                        try {
                            existingFunction = createFunction(address, sourceName);
                            if (existingFunction != null) {
                                createdCount++;
                            } else {
                                println("FAILED to create: " + sourceName + " @ " + targetAddressStr);
                                failedCount++;
                                continue;
                            }
                        } catch (Exception e) {
                            println("ERROR creating " + sourceName + " @ " + targetAddressStr + ": " + e.getMessage());
                            failedCount++;
                            continue;
                        }
                    }

                    // Rename the function
                    String oldName = existingFunction.getName();
                    if (!oldName.equals(sourceName)) {
                        try {
                            existingFunction.setName(sourceName, SourceType.USER_DEFINED);
                            renamedCount++;
                        } catch (Exception e) {
                            println("ERROR renaming " + targetAddressStr + ": " + e.getMessage());
                            failedCount++;
                            continue;
                        }
                    }

                    // Add comment with source info
                    String comment = String.format("From J90280.05 @ %s (confidence: %d%%)",
                            sourceAddressStr, confidence);
                    setPreComment(address, comment);

                } catch (NumberFormatException e) {
                    println("Invalid address: " + targetAddressStr);
                    failedCount++;
                }

                // Progress indicator
                if (totalProcessed % 50 == 0) {
                    println("  Processed " + totalProcessed + " functions...");
                }
            }
        } catch (Exception e) {
            println("ERROR reading CSV: " + e.getMessage());
            return;
        }

        println("");
        println("=".repeat(70));
        println("RESULTS");
        println("-".repeat(70));
        println("  Functions created:  " + createdCount);
        println("  Functions renamed:  " + renamedCount);
        println("  Skipped (low conf): " + skippedCount);
        println("  Failed:             " + failedCount);
        println("  Total high-conf:    " + totalProcessed);
        println("=".repeat(70));

        if (failedCount == 0) {
            println("SUCCESS: Bootstrap complete!");
        } else {
            println("WARNING: Some functions failed - review output above");
        }
    }
}
