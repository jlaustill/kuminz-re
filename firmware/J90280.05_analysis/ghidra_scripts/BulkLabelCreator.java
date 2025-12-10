// Ghidra Bulk Label Creator Script
// Reads from labels.csv and creates labels at specified addresses
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
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SourceType;

public class BulkLabelCreator extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Path to CSV file
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/labels.csv";
        
        
        // Read CSV file and create labels
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
                
                // Parse CSV: address,label_name,comment
                String[] parts = line.split(",");
                if (parts.length >= 3) {
                    String addressStr = parts[0].trim();
                    String labelName = parts[1].trim();
                    String comment = parts[2].trim();
                    
                    try {
                        // Parse address
                        long addressLong;
                        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
                            addressLong = Long.parseLong(addressStr.substring(2), 16);
                        } else {
                            addressLong = Long.parseLong(addressStr, 16);
                        }
                        
                        Address addr = toAddr(addressLong);
                        
                        // Get symbol table
                        SymbolTable symbolTable = currentProgram.getSymbolTable();
                        
                        // Check if there's already a function at this address
                        // If so, we don't want to override the function name
                        Symbol[] existingSymbols = symbolTable.getSymbols(addr);
                        boolean hasFunctionSymbol = false;
                        String existingName = "";
                        
                        for (Symbol symbol : existingSymbols) {
                            if (symbol.getSymbolType() == ghidra.program.model.symbol.SymbolType.FUNCTION) {
                                hasFunctionSymbol = true;
                                existingName = symbol.getName();
                                break;
                            }
                        }
                        
                        if (hasFunctionSymbol) {
                            // Add comment to existing function instead of creating new label
                            setEOLComment(addr, comment);
                        } else {
                            // Remove any existing non-function symbols
                            for (Symbol symbol : existingSymbols) {
                                if (symbol.getSymbolType() != ghidra.program.model.symbol.SymbolType.FUNCTION) {
                                    symbolTable.removeSymbolSpecial(symbol);
                                }
                            }
                            
                            // Create new label
                            Symbol newSymbol = symbolTable.createLabel(addr, labelName, SourceType.USER_DEFINED);
                            if (newSymbol != null) {
                                // Add comment
                                setEOLComment(addr, comment);
                            } else {
                                println("✗ " + addressStr + ": Failed to create label '" + labelName + "'");
                                failCount++;
                                continue;
                            }
                        }
                        
                        successCount++;
                        
                    } catch (NumberFormatException e) {
                        println("✗ " + addressStr + ": Invalid address format");
                        failCount++;
                    } catch (Exception e) {
                        println("✗ " + addressStr + ": Error creating label - " + e.getMessage());
                        failCount++;
                    }
                }
            }
            
            println("Results: " + successCount + " successful, " + failCount + " failed");
            if (failCount == 0) {
                println("✓ Labels created");
            }
            
        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
            println("Make sure labels.csv is in your project root directory");
            return;
        }
    }
}