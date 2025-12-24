// Apply Constants Script
// Reads from constants.csv and adds meaningful comments to immediate values
// @author kuminz-re
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;
import java.io.IOException;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.scalar.Scalar;

public class ApplyConstants extends GhidraScript {

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY CONSTANTS");
        println("=".repeat(70));
        println("");

        // Get input file from arguments
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            println("ERROR: constants.csv path required as argument");
            println("Usage: ./analyze.sh constants /path/to/constants.csv");
            return;
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: constants.csv not found at: " + csvPath);
            return;
        }

        // Read CSV file and add constant comments
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;
            int successCount = 0;
            int failCount = 0;
            int skippedCount = 0;

            println("[Processing constants...]");

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

                // Parse CSV: address,constant_name,value,comment
                String[] parts = parseCSVLine(line);
                if (parts.length < 4) {
                    skippedCount++;
                    continue;
                }

                String addressStr = parts[0].trim();
                String constantName = parts[1].trim();
                String valueStr = parts[2].trim();
                String comment = parts[3].trim();

                try {
                    // Parse address
                    long addressLong;
                    if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
                        addressLong = Long.parseLong(addressStr.substring(2), 16);
                    } else {
                        addressLong = Long.parseLong(addressStr, 16);
                    }

                    Address addr = toAddr(addressLong);

                    // Get the instruction at this address
                    Instruction instruction = getInstructionAt(addr);
                    if (instruction == null) {
                        failCount++;
                        continue;
                    }

                    // Parse the expected value
                    long expectedValue;
                    try {
                        if (valueStr.startsWith("0x") || valueStr.startsWith("0X")) {
                            expectedValue = Long.parseLong(valueStr.substring(2), 16);
                        } else {
                            expectedValue = Long.parseLong(valueStr);
                        }
                    } catch (NumberFormatException e) {
                        failCount++;
                        continue;
                    }

                    // Check if instruction contains the expected immediate value
                    boolean foundValue = false;
                    for (int i = 0; i < instruction.getNumOperands(); i++) {
                        Object[] opObjects = instruction.getOpObjects(i);
                        for (Object obj : opObjects) {
                            if (obj instanceof Scalar) {
                                Scalar scalar = (Scalar) obj;
                                long scalarValue = scalar.getUnsignedValue();
                                if (scalarValue == expectedValue) {
                                    foundValue = true;
                                    break;
                                }
                            }
                        }
                        if (foundValue) break;
                    }

                    // Create comprehensive comment with constant name and explanation
                    String fullComment = constantName + " = " + valueStr + " (" + comment + ")";

                    // Set both EOL comment and pre-comment for visibility
                    setEOLComment(addr, fullComment);
                    setPreComment(addr, "Constant: " + constantName + " = " + valueStr);

                    successCount++;

                } catch (NumberFormatException e) {
                    failCount++;
                } catch (Exception e) {
                    failCount++;
                }
            }

            println("");
            println("=".repeat(70));
            println("CONSTANT APPLICATION COMPLETE!");
            println("  " + successCount + " constants documented");
            println("  " + failCount + " failed");
            println("  " + skippedCount + " skipped (invalid format)");
            println("=".repeat(70));

        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
        }
    }

    private String[] parseCSVLine(String line) {
        // Simple CSV parser that handles commas in quoted fields
        java.util.List<String> parts = new java.util.ArrayList<>();
        StringBuilder current = new StringBuilder();
        boolean inQuotes = false;

        for (char c : line.toCharArray()) {
            if (c == '"') {
                inQuotes = !inQuotes;
            } else if (c == ',' && !inQuotes) {
                parts.add(current.toString());
                current = new StringBuilder();
            } else {
                current.append(c);
            }
        }
        parts.add(current.toString());

        return parts.toArray(new String[0]);
    }
}
