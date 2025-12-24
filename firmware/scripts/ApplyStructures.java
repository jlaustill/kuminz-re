// Apply Structures Script
// Parses structure_definitions.csv and creates/applies structure types in Ghidra
// @author J90350.00_analysis
// @category Analysis
// @keybinding
// @menupath
// @toolbar

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.SourceType;

public class ApplyStructures extends GhidraScript {

    private DataTypeManager dtm;
    private Listing listing;
    private Map<String, StructureDataType> createdStructures = new HashMap<>();
    private Category structCategory;

    // Map CSV type names to Ghidra data types
    private static final Map<String, String> TYPE_MAP = new HashMap<>();
    static {
        TYPE_MAP.put("byte", "byte");
        TYPE_MAP.put("word", "word");
        TYPE_MAP.put("dword", "dword");
        TYPE_MAP.put("short", "short");
        TYPE_MAP.put("ushort", "ushort");
        TYPE_MAP.put("uint16_t", "ushort");
        TYPE_MAP.put("uint32_t", "uint");
        TYPE_MAP.put("int", "int");
        TYPE_MAP.put("uint", "uint");
        TYPE_MAP.put("undefined1", "byte");
        TYPE_MAP.put("undefined2", "word");
        TYPE_MAP.put("undefined4", "dword");
        TYPE_MAP.put("undefined3", "undefined3");
        TYPE_MAP.put("ptr", "pointer");
    }

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY STRUCTURES - J90350.00");
        println("=".repeat(70));
        println("");

        dtm = currentProgram.getDataTypeManager();
        listing = currentProgram.getListing();

        // Create category for our structures
        structCategory = dtm.createCategory(new CategoryPath("/J90350_Structures"));

        // Get input file from arguments or use default
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../output/structure_definitions.csv";
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: structure_definitions.csv not found!");
            return;
        }

        // Phase 1: Parse CSV and create structure types
        println("[Phase 1] Parsing structure definitions...");
        Map<String, List<FieldDef>> structDefs = parseStructureDefinitions(csvPath);
        println("  Found " + structDefs.size() + " structure types");
        println("");

        // Phase 2: Create Ghidra structure types
        println("[Phase 2] Creating structure types in Ghidra...");
        int created = createStructureTypes(structDefs);
        println("  Created " + created + " structure types");
        println("");

        // Phase 3: Apply structures at specified addresses
        println("[Phase 3] Applying structures to memory...");
        int applied = applyStructuresToMemory(structDefs);
        println("  Applied " + applied + " structure instances");
        println("");

        println("=".repeat(70));
        println("STRUCTURE APPLICATION COMPLETE!");
        println("=".repeat(70));
    }

    private Map<String, List<FieldDef>> parseStructureDefinitions(String csvPath) throws Exception {
        Map<String, List<FieldDef>> structDefs = new HashMap<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;

            while ((line = reader.readLine()) != null) {
                // Skip header
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                line = line.trim();

                // Skip empty lines and comments
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }

                // Parse CSV: struct_name,address,field_name,type,size,comment,dependency,status
                String[] parts = parseCSVLine(line);
                if (parts.length < 5) {
                    continue;
                }

                String structName = parts[0].trim();
                String addressStr = parts[1].trim();
                String fieldName = parts[2].trim();
                String typeName = parts[3].trim();
                String sizeStr = parts[4].trim();
                String comment = parts.length > 5 ? parts[5].trim() : "";

                // Skip if no struct name
                if (structName.isEmpty()) {
                    continue;
                }

                // Parse size
                int size = 0;
                try {
                    if (!sizeStr.isEmpty() && !sizeStr.equals("variable")) {
                        size = Integer.parseInt(sizeStr);
                    }
                } catch (NumberFormatException e) {
                    // Skip variable-size fields
                    continue;
                }

                // Create field definition
                FieldDef field = new FieldDef();
                field.name = fieldName;
                field.typeName = typeName;
                field.size = size;
                field.comment = comment;
                field.address = addressStr;

                // Add to structure
                if (!structDefs.containsKey(structName)) {
                    structDefs.put(structName, new ArrayList<>());
                }
                structDefs.get(structName).add(field);
            }
        }

        return structDefs;
    }

    private String[] parseCSVLine(String line) {
        // Simple CSV parser that handles commas in quoted fields
        List<String> parts = new ArrayList<>();
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

    private int createStructureTypes(Map<String, List<FieldDef>> structDefs) throws Exception {
        int created = 0;
        int txId = dtm.startTransaction("Create Structures");

        try {
            for (Map.Entry<String, List<FieldDef>> entry : structDefs.entrySet()) {
                String structName = entry.getKey();
                List<FieldDef> fields = entry.getValue();

                // Calculate total structure size from fields
                int totalSize = 0;
                for (FieldDef field : fields) {
                    totalSize += field.size;
                }

                if (totalSize == 0) {
                    // Try to calculate from largest offset + size
                    for (FieldDef field : fields) {
                        if (!field.address.isEmpty()) {
                            // Has specific address - this is an instance, not contributing to type size
                            continue;
                        }
                    }
                    // Default minimum size
                    if (totalSize == 0) {
                        totalSize = calculateStructureSizeFromFields(fields);
                    }
                }

                if (totalSize <= 0) {
                    totalSize = 1; // Minimum size
                }

                // Create the structure
                StructureDataType struct = new StructureDataType(structCategory.getCategoryPath(),
                                                                  structName, totalSize, dtm);

                // Add fields
                int offset = 0;
                for (FieldDef field : fields) {
                    if (field.size <= 0) continue;

                    DataType fieldType = getDataType(field.typeName, field.size);
                    if (fieldType != null) {
                        try {
                            // Clear existing bytes at offset
                            struct.replaceAtOffset(offset, fieldType, field.size, field.name, field.comment);
                        } catch (Exception e) {
                            // If replace fails, try insert
                            try {
                                struct.insertAtOffset(offset, fieldType, field.size, field.name, field.comment);
                            } catch (Exception e2) {
                                // Field addition failed, skip
                            }
                        }
                    }
                    offset += field.size;
                }

                // Add to data type manager
                DataType existing = dtm.getDataType(structCategory.getCategoryPath(), structName);
                if (existing != null) {
                    dtm.remove(existing, monitor);
                }

                dtm.addDataType(struct, DataTypeConflictHandler.REPLACE_HANDLER);
                createdStructures.put(structName, struct);
                created++;
            }
        } finally {
            dtm.endTransaction(txId, true);
        }

        return created;
    }

    private int calculateStructureSizeFromFields(List<FieldDef> fields) {
        int size = 0;
        for (FieldDef field : fields) {
            size += field.size;
        }
        return size > 0 ? size : 1;
    }

    private DataType getDataType(String typeName, int size) {
        // Handle pointer types
        if (typeName.startsWith("ptr:") || typeName.equals("pointer")) {
            return PointerDataType.dataType;
        }

        // Handle array types (e.g., "byte" with size > 1)
        String baseType = TYPE_MAP.getOrDefault(typeName.toLowerCase(), typeName);

        DataType dt = null;
        switch (baseType.toLowerCase()) {
            case "byte":
            case "undefined1":
                dt = ByteDataType.dataType;
                break;
            case "word":
            case "ushort":
            case "uint16_t":
            case "undefined2":
                dt = WordDataType.dataType;
                break;
            case "short":
                dt = ShortDataType.dataType;
                break;
            case "dword":
            case "uint":
            case "uint32_t":
            case "undefined4":
                dt = DWordDataType.dataType;
                break;
            case "int":
                dt = IntegerDataType.dataType;
                break;
            case "pointer":
                dt = PointerDataType.dataType;
                break;
            default:
                // Check if it's a reference to another structure
                if (createdStructures.containsKey(typeName)) {
                    dt = createdStructures.get(typeName);
                } else {
                    // Default to byte array
                    dt = ByteDataType.dataType;
                }
        }

        // Create array if size is larger than base type
        if (dt != null && size > dt.getLength()) {
            int count = size / dt.getLength();
            if (count > 1) {
                dt = new ArrayDataType(dt, count, dt.getLength());
            }
        }

        return dt;
    }

    private int applyStructuresToMemory(Map<String, List<FieldDef>> structDefs) throws Exception {
        int applied = 0;

        // Collect unique addresses with their structure types
        Map<Long, String> addressToStruct = new HashMap<>();

        for (Map.Entry<String, List<FieldDef>> entry : structDefs.entrySet()) {
            String structName = entry.getKey();
            List<FieldDef> fields = entry.getValue();

            for (FieldDef field : fields) {
                if (!field.address.isEmpty()) {
                    try {
                        long addr = parseAddressString(field.address);
                        // Only record if we haven't seen this struct at this address
                        if (!addressToStruct.containsKey(addr)) {
                            addressToStruct.put(addr, structName);
                        }
                    } catch (Exception e) {
                        // Skip invalid addresses
                    }
                }
            }
        }

        // Apply structures at addresses
        int txId = currentProgram.startTransaction("Apply Structures to Memory");
        try {
            for (Map.Entry<Long, String> entry : addressToStruct.entrySet()) {
                long addrValue = entry.getKey();
                String structName = entry.getValue();

                Address addr = toAddr(addrValue);
                StructureDataType struct = createdStructures.get(structName);

                if (struct != null && addr != null) {
                    try {
                        // Clear existing data at address
                        Data existingData = listing.getDataAt(addr);
                        if (existingData != null) {
                            listing.clearCodeUnits(addr, addr.add(struct.getLength() - 1), false);
                        }

                        // Apply structure
                        listing.createData(addr, struct);
                        applied++;
                    } catch (Exception e) {
                        // Failed to apply at this address - might overlap with code
                        println("  Warning: Could not apply " + structName + " at " + addr + ": " + e.getMessage());
                    }
                }
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        return applied;
    }

    private long parseAddressString(String addressStr) {
        addressStr = addressStr.trim();
        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
            return Long.parseLong(addressStr.substring(2), 16);
        }
        return Long.parseLong(addressStr, 16);
    }

    // Helper class for field definitions
    private static class FieldDef {
        String name;
        String typeName;
        int size;
        String comment;
        String address;
    }
}
