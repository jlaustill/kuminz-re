// Apply Arrays Script
// Reads from arrays.csv and creates array data types at specified memory locations
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
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Data;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SourceType;

public class ApplyArrays extends GhidraScript {

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY ARRAYS");
        println("=".repeat(70));
        println("");

        // Get input file from arguments
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            println("ERROR: arrays.csv path required as argument");
            println("Usage: ./analyze.sh arrays /path/to/arrays.csv");
            return;
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: arrays.csv not found at: " + csvPath);
            return;
        }

        // Read CSV file and create arrays
        try (BufferedReader br = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;
            int successCount = 0;
            int failCount = 0;
            int skippedCount = 0;

            println("[Processing arrays...]");

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

                // Parse CSV: address,array_name,element_type,element_count,comment
                String[] parts = parseCSVLine(line);
                if (parts.length < 5) {
                    skippedCount++;
                    continue;
                }

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
                        println("  ✗ " + addressStr + ": Unknown element type '" + elementTypeStr + "'");
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
                        println("  ✗ " + addressStr + ": Failed to create array data");
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
                        println("  ✓ " + arrayName + " @ " + addressStr + " (" + elementCount + " x " + elementTypeStr + ")");
                        successCount++;
                    } else {
                        println("  ✗ " + addressStr + ": Failed to create symbol '" + arrayName + "'");
                        failCount++;
                    }

                } catch (NumberFormatException e) {
                    failCount++;
                } catch (Exception e) {
                    println("  ✗ " + addressStr + ": " + e.getMessage());
                    failCount++;
                }
            }

            println("");
            println("=".repeat(70));
            println("ARRAY APPLICATION COMPLETE!");
            println("  " + successCount + " arrays created");
            println("  " + failCount + " failed");
            println("  " + skippedCount + " skipped (invalid format)");
            println("=".repeat(70));
            println("");
            println("Array benefits:");
            println("  • Proper indexing: array[0], array[1], array[2]...");
            println("  • Size validation: Prevents out-of-bounds access");
            println("  • Type safety: Elements have correct data types");

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
