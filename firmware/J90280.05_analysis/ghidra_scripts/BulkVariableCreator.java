// Ghidra Bulk Global Variable Creator Script
// Reads from global_variables.csv and creates global variables with proper data types
// @author J90280.05_analysis
// @category Analysis
// @keybinding 
// @menupath 
// @toolbar 

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SourceType;

public class BulkVariableCreator extends GhidraScript {
    
    @Override
    public void run() throws Exception {
        // Path to CSV file
        String csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() + 
                        "/global_variables.csv";
        
        
        // Read CSV file and create variables
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
                
                // Parse CSV: address,name,type,comment,length,calterm_type,unit,data_pattern
                String[] parts = parseCSVLine(line);
                if (parts.length >= 4) {
                    String addressStr = parts[0].trim();
                    String varName = parts[1].trim();
                    String typeStr = parts[2].trim();
                    String comment = parts[3].trim();
                    
                    // Enhanced fields for better type detection
                    int length = parts.length > 4 && !parts[4].trim().isEmpty() ? 
                                Integer.parseInt(parts[4].trim()) : 2;
                    int caltermType = parts.length > 5 && !parts[5].trim().isEmpty() ? 
                                     Integer.parseInt(parts[5].trim()) : 0;
                    String unit = parts.length > 6 ? parts[6].trim() : "";
                    String dataPattern = parts.length > 7 ? parts[7].trim() : "";
                    
                    try {
                        // Parse address
                        long addressLong;
                        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
                            addressLong = Long.parseLong(addressStr.substring(2), 16);
                        } else {
                            addressLong = Long.parseLong(addressStr, 16);
                        }
                        
                        Address addr = toAddr(addressLong);
                        
                        // Try custom structure or enum type first
                        DataType dataType = findDataTypeByName(currentProgram.getDataTypeManager(), typeStr);
                        if (dataType == null) {
                            // Fall back to enhanced data type detection
                            dataType = getEnhancedDataType(typeStr, length, caltermType, dataPattern, unit);
                            if (dataType != null) {
                                println("✓ " + addressStr + ": Found custom data type '" + typeStr + "' (" + dataType.getClass().getSimpleName() + ")");
                            } else {
                                println("✗ " + addressStr + ": Unknown data type '" + typeStr + "'");
                                println("  Available primitive types: uint8_t, uint16_t, uint32_t, byte, word, dword");
                                println("  Searching for custom structures in DataTypeManager...");
                                
                                // Debug: List available structures and enums
                                java.util.Iterator<DataType> dtIter = currentProgram.getDataTypeManager().getAllDataTypes();
                                int structCount = 0;
                                int enumCount = 0;
                                while (dtIter.hasNext() && (structCount + enumCount) < 10) {
                                    DataType dt = dtIter.next();
                                    if (dt instanceof Structure) {
                                        println("    Found structure: " + dt.getName());
                                        structCount++;
                                    } else if (dt instanceof ghidra.program.model.data.Enum) {
                                        println("    Found enum: " + dt.getName());
                                        enumCount++;
                                    }
                                }
                                if (structCount == 0 && enumCount == 0) {
                                    println("    No structures or enums found in DataTypeManager");
                                }
                                
                                failCount++;
                                continue;
                            }
                        }
                        
                        // Clear existing data at this address
                        clearListing(addr, addr.add(dataType.getLength() - 1));
                        
                        // Create data with the specified type
                        Data data = createData(addr, dataType);
                        if (data == null) {
                            println("✗ " + addressStr + ": Failed to create data");
                            failCount++;
                            continue;
                        }
                        
                        // Rename the symbol at this address
                        // Use getSymbolAt + setName approach which properly renames dynamic DAT_ symbols
                        Symbol existingSymbol = getSymbolAt(addr);
                        boolean symbolSuccess = false;

                        if (existingSymbol != null) {
                            // Rename existing symbol (works for dynamic DAT_ symbols)
                            try {
                                existingSymbol.setName(varName, SourceType.USER_DEFINED);
                                symbolSuccess = true;
                            } catch (Exception e) {
                                // If rename fails, try creating a new label
                                println("  Note: Could not rename existing symbol, creating new label");
                            }
                        }

                        if (!symbolSuccess) {
                            // Fall back to creating a new label if no symbol exists or rename failed
                            SymbolTable symbolTable = currentProgram.getSymbolTable();
                            Symbol newSymbol = symbolTable.createLabel(addr, varName, SourceType.USER_DEFINED);
                            if (newSymbol != null) {
                                newSymbol.setPrimary();
                                symbolSuccess = true;
                            }
                        }

                        if (symbolSuccess) {
                            // Enhanced comment with CalTerm metadata
                            String enhancedComment = comment;
                            if (!unit.isEmpty() || caltermType != 0 || !dataPattern.isEmpty()) {
                                enhancedComment += String.format(" [%s%s%s]", 
                                    !unit.isEmpty() ? unit : "NONE",
                                    caltermType != 0 ? " CT:" + caltermType : "",
                                    !dataPattern.isEmpty() ? " " + dataPattern : "");
                            }
                            setEOLComment(addr, enhancedComment);

                            successCount++;
                        } else {
                            println("✗ " + addressStr + ": Failed to set symbol name '" + varName + "'");
                            failCount++;
                        }
                        
                    } catch (NumberFormatException e) {
                        println("✗ " + addressStr + ": Invalid address format");
                        failCount++;
                    } catch (Exception e) {
                        println("✗ " + addressStr + ": Error creating variable - " + e.getMessage());
                        failCount++;
                    }
                }
            }
            
            println("Results: " + successCount + " successful, " + failCount + " failed");
            
            if (successCount > 0) {
            }
            
        } catch (IOException e) {
            println("Error reading CSV file: " + e.getMessage());
            println("Make sure global_variables.csv is in your project root directory");
            return;
        }
    }
    
    // Enhanced data type creation using CalTerm metadata
    private DataType getEnhancedDataType(String typeStr, int length, int caltermType, String dataPattern, String unit) {
        // If explicit type provided, try it first
        DataType explicitType = getDataType(typeStr);
        if (explicitType != null) {
            return explicitType;
        }
        
        // Use CalTerm type patterns for intelligent type selection
        switch (caltermType) {
            case 0: // Individual runtime values - use appropriate primitive
                return getPrimitiveByLength(length);
                
            case 4: // X-axis arrays (RPM, fueling, throttle axes)
                if (dataPattern.contains("axis") || dataPattern.contains("AXIS")) {
                    return createArrayType(length, "word"); // Axis values typically 16-bit
                }
                return getPrimitiveByLength(length);
                
            case 6: // Z-axis lookup tables (timing, fuel tables)
                if (dataPattern.contains("lookup") || dataPattern.contains("table") || 
                    dataPattern.contains("LOOKUP") || dataPattern.contains("TABLE")) {
                    return createArrayType(length, "word"); // Table values typically 16-bit
                }
                return getPrimitiveByLength(length);
                
            case 2: case 3: case 5: case 8: case 18: case 21: case 25:
                // Linearization tables - always arrays for conversion
                if (dataPattern.contains("linearization") || dataPattern.contains("LINEARIZATION")) {
                    return createArrayType(length, "word");
                }
                return getPrimitiveByLength(length);
                
            default:
                return getPrimitiveByLength(length);
        }
    }
    
    // Helper method to create primitive type based on length
    private DataType getPrimitiveByLength(int length) {
        switch (length) {
            case 1: return new ByteDataType();
            case 2: return new WordDataType();
            case 4: return new DWordDataType();
            case 8: return new QWordDataType();
            default: return new WordDataType(); // Default to word
        }
    }
    
    // Helper method to create array types
    private DataType createArrayType(int elementCount, String elementTypeStr) {
        DataType elementType = getDataType(elementTypeStr);
        if (elementType == null) {
            elementType = new WordDataType(); // Default to word elements
        }
        
        try {
            return new ArrayDataType(elementType, elementCount, elementType.getLength());
        } catch (Exception e) {
            // If array creation fails, return element type
            return elementType;
        }
    }
    
    // Helper method to convert string type to Ghidra DataType
    private DataType getDataType(String typeString) {
        switch (typeString.toLowerCase()) {
            case "uint8_t":
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
    
    // Helper method to find DataType by name (handles both structures and enums)
    private DataType findDataTypeByName(DataTypeManager dtm, String typeName) {
        java.util.Iterator<DataType> dtIter = dtm.getAllDataTypes();
        while (dtIter.hasNext()) {
            DataType dt = dtIter.next();
            if (dt.getName().equals(typeName)) {
                return dt;
            }
        }
        return null;
    }

    // CSV parser that handles quoted fields with commas
    private String[] parseCSVLine(String line) {
        java.util.List<String> fields = new java.util.ArrayList<>();
        StringBuilder current = new StringBuilder();
        boolean inQuotes = false;

        for (int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);

            if (c == '"') {
                // Check for escaped quote ""
                if (inQuotes && i + 1 < line.length() && line.charAt(i + 1) == '"') {
                    current.append('"');
                    i++; // Skip next quote
                } else {
                    inQuotes = !inQuotes;
                }
            } else if (c == ',' && !inQuotes) {
                fields.add(current.toString());
                current = new StringBuilder();
            } else {
                current.append(c);
            }
        }
        fields.add(current.toString()); // Add last field

        return fields.toArray(new String[0]);
    }
}