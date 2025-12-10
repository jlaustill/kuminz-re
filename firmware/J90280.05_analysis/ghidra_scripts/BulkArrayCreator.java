// Ghidra Bulk Array Creator Script
// Reads from arrays.csv and creates array data types at specified memory locations
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
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Data;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SourceType;

public class BulkArrayCreator extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Path to CSV file
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/arrays.csv";
        
        
        // Read CSV file and create arrays
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
                
                // Parse CSV: address,array_name,element_type,element_count,comment
                String[] parts = line.split(",");
                if (parts.length >= 5) {
                    String addressStr = parts[0].trim();
                    String arrayName = parts[1].trim();
                    String elementTypeStr = parts[2].trim();
                    String elementCountStr = parts[3].trim();
                    String comment = parts[4].trim();
                    
                    try {
                        // Parse address
                        long addressLong;
                        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
                            addressLong = Long.parseLong(addressStr.substring(2), 16);
                        } else {
                            addressLong = Long.parseLong(addressStr, 16);
                        }
                        
                        Address addr = toAddr(addressLong);
                        
                        // Parse element count
                        int elementCount = Integer.parseInt(elementCountStr);
                        
                        // Get element data type
                        DataType elementType = getDataType(elementTypeStr);
                        if (elementType == null) {
                            println("✗ " + addressStr + ": Unknown element type '" + elementTypeStr + "'");
                            failCount++;
                            continue;
                        }
                        
                        // Create array data type
                        ArrayDataType arrayType = new ArrayDataType(elementType, elementCount, 
                                                                  elementType.getLength());
                        
                        // Calculate total size
                        int totalSize = elementType.getLength() * elementCount;
                        
                        // Clear existing data at this address range
                        Address endAddr = addr.add(totalSize - 1);
                        clearListing(addr, endAddr);
                        
                        // Create array data at the address
                        Data arrayData = createData(addr, arrayType);
                        if (arrayData == null) {
                            println("✗ " + addressStr + ": Failed to create array data");
                            failCount++;
                            continue;
                        }
                        
                        // Create symbol (array name) at this address
                        SymbolTable symbolTable = currentProgram.getSymbolTable();
                        
                        // Remove any existing non-function symbols
                        Symbol[] existingSymbols = symbolTable.getSymbols(addr);
                        for (Symbol symbol : existingSymbols) {
                            if (symbol.getSymbolType() != ghidra.program.model.symbol.SymbolType.FUNCTION) {
                                symbolTable.removeSymbolSpecial(symbol);
                            }
                        }
                        
                        // Create new symbol for the array
                        Symbol newSymbol = symbolTable.createLabel(addr, arrayName, SourceType.USER_DEFINED);
                        if (newSymbol != null) {
                            // Set comment on the array
                            setEOLComment(addr, comment);
                            successCount++;
                        } else {
                            println("✗ " + addressStr + ": Failed to create symbol '" + arrayName + "'");
                            failCount++;
                        }
                        
                    } catch (NumberFormatException e) {
                        println("✗ " + addressStr + ": Invalid address or count format");
                        failCount++;
                    } catch (Exception e) {
                        println("✗ " + addressStr + ": Error creating array - " + e.getMessage());
                        failCount++;
                    }
                }
            }
            
            println("Results: " + successCount + " successful, " + failCount + " failed");
            
            if (successCount > 0) {
                println("Arrays are now properly typed and named in the listing.");
                println("\nArray benefits:");
                println("• Proper indexing: array[0], array[1], array[2]...");
                println("• Size validation: Prevents out-of-bounds access");
                println("• Type safety: Elements have correct data types");
                println("• Navigation: Click array name to jump to definition");
                println("• Cross-references: See all code that uses each array");
            }
            
        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
            println("Make sure arrays.csv is in your project root directory");
            return;
        }
    }
    
    // Helper method to convert string type to Ghidra DataType
    private DataType getDataType(String typeString) {
        switch (typeString.toLowerCase()) {
            case "byte":
            case "uint8":
            case "char":
                return new ByteDataType();
            case "word":
            case "uint16":
            case "short":
                return new WordDataType();
            case "dword":
            case "uint32":
            case "int":
                return new DWordDataType();
            case "qword":
            case "uint64":
            case "long":
                return new QWordDataType();
            case "float":
                return new FloatDataType();
            case "double":
                return new DoubleDataType();
            case "pointer":
            case "ptr":
                return new PointerDataType();
            default:
                return null;
        }
    }
}