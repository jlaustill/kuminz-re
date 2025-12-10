// Ghidra Bulk Constant Creator Script
// Reads from constants.csv and adds meaningful comments to immediate values
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.scalar.Scalar;

public class BulkConstantCreator extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Path to CSV file
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/constants.csv";
        
        
        // Read CSV file and add constant comments
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;
            int successCount = 0;
            int failCount = 0;
            
            
            while ((line = br.readLine()) != null) {
                // Skip header line
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }
                
                // Parse CSV: address,constant_name,value,comment
                String[] parts = line.split(",");
                if (parts.length >= 4) {
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
                            println("✗ " + addressStr + ": No instruction found at this address");
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
                            println("✗ " + addressStr + ": Invalid value format '" + valueStr + "'");
                            failCount++;
                            continue;
                        }
                        
                        // Check if instruction contains the expected immediate value
                        boolean foundValue = false;
                        Object[] operands = instruction.getOpObjects(0);  // Get all operands
                        
                        // Check all operands for scalars (immediate values)
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
                        
                        if (foundValue) {
                            // Create comprehensive comment with constant name and explanation
                            String fullComment = constantName + " = " + valueStr + " (" + comment + ")";
                            
                            // Set both EOL comment and pre-comment for visibility
                            setEOLComment(addr, fullComment);
                            setPreComment(addr, "Constant: " + constantName + " = " + valueStr);
                            
                            successCount++;
                        } else {
                            // Still add comment but note the value mismatch
                            String fullComment = constantName + " = " + valueStr + " (Expected: " + comment + ")";
                            setEOLComment(addr, fullComment);
                            
                            println("⚠ " + addressStr + ": " + constantName + " - Value " + valueStr + " not found in instruction, but comment added");
                            successCount++;
                        }
                        
                    } catch (NumberFormatException e) {
                        println("✗ " + addressStr + ": Invalid address format");
                        failCount++;
                    } catch (Exception e) {
                        println("✗ " + addressStr + ": Error processing constant - " + e.getMessage());
                        failCount++;
                    }
                }
            }
            
            println("Results: " + successCount + " successful, " + failCount + " failed");
            
            if (successCount > 0) {
                println("Constants are now documented with meaningful names and explanations.");
            }
            
        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
            println("Make sure constants.csv is in your project root directory");
            return;
        }
    }
}