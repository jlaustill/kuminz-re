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
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
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
    private Map<String, DataType> createdStructures = new HashMap<>();
    private Set<String> unionTypes = new HashSet<>();
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
                String[] parts = ScriptUtils.parseCSVLine(line);
                if (parts.length < 5) {
                    continue;
                }

                String structName = parts[0].trim();
                String addressStr = parts[1].trim();
                String fieldName = parts[2].trim();
                String typeName = parts[3].trim();
                String sizeStr = parts[4].trim();
                String comment = parts.length > 5 ? parts[5].trim() : "";
                String kind = parts.length > 8 ? parts[8].trim() : "";
                if ("union".equals(kind)) {
                    unionTypes.add(structName);
                }

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


    private int createStructureTypes(Map<String, List<FieldDef>> structDefs) throws Exception {
        int created = 0;
        int txId = dtm.startTransaction("Create Structures");

        try {
            // Pass 1: create empty shells for every struct type so that forward
            // references (e.g. etc1_governor_state_t has a field typed etc1_config_entry_t*
            // but etc1_config_entry_t hasn't been processed yet) resolve correctly in Pass 2.
            for (Map.Entry<String, List<FieldDef>> entry : structDefs.entrySet()) {
                String structName = entry.getKey();
                List<FieldDef> fields = entry.getValue();

                int totalSize = calculateStructureSizeFromFields(fields);
                if (totalSize <= 0) totalSize = 1;

                // Remove canonical entry and any .conflict leftovers from prior runs
                DataType existing = dtm.getDataType(structCategory.getCategoryPath(), structName);
                if (existing != null) dtm.remove(existing, monitor);
                DataType conflictExisting = dtm.getDataType(structCategory.getCategoryPath(), structName + ".conflict");
                if (conflictExisting != null) dtm.remove(conflictExisting, monitor);

                DataType shell;
                if (unionTypes.contains(structName)) {
                    shell = new UnionDataType(structCategory.getCategoryPath(), structName, dtm);
                } else {
                    shell = new StructureDataType(structCategory.getCategoryPath(), structName, totalSize, dtm);
                }
                DataType addedShell = dtm.addDataType(shell, DataTypeConflictHandler.DEFAULT_HANDLER);
                createdStructures.put(structName, addedShell);
            }

            // Pass 2: mutate each DTM-managed shell in place.
            // Two sub-passes: unions first so their sizes are finalised before
            // structs that embed them call replaceAtOffset with the correct length.
            // Sub-pass A — unions (all members at offset 0, no ordering dependency)
            for (Map.Entry<String, List<FieldDef>> entry : structDefs.entrySet()) {
                String structName = entry.getKey();
                if (!unionTypes.contains(structName)) continue;
                DataType composite = createdStructures.get(structName);
                if (composite == null) continue;
                for (FieldDef field : entry.getValue()) {
                    if (field.size <= 0) continue;
                    DataType fieldType = getDataType(field.typeName, field.size);
                    if (fieldType != null) {
                        String fieldName = field.name.isEmpty() ? null : field.name;
                        String fieldComment = field.comment.isEmpty() ? null : field.comment;
                        ((Union) composite).add(fieldType, field.size, fieldName, fieldComment);
                    }
                }
                created++;
            }

            // Sub-pass B — structs (existing replaceAtOffset logic, offset increments as before).
            // This preserves the shell's database key so any Pointer32->shell
            // types built during this pass remain valid even after the shell is
            // populated with real field types.
            for (Map.Entry<String, List<FieldDef>> entry : structDefs.entrySet()) {
                String structName = entry.getKey();
                if (unionTypes.contains(structName)) continue;
                List<FieldDef> fields = entry.getValue();

                // Use the object stored by Pass 1 (guaranteed to be the DTM-managed
                // shell, regardless of what name addDataType gave it).
                DataType composite = createdStructures.get(structName);
                if (composite == null) continue;

                int offset = 0;
                for (FieldDef field : fields) {
                    if (field.size <= 0) continue;

                    DataType fieldType = getDataType(field.typeName, field.size);
                    if (fieldType != null) {
                        Structure struct = (Structure) composite;
                        try {
                            struct.replaceAtOffset(offset, fieldType, field.size, field.name, field.comment);
                        } catch (Exception e) {
                            try {
                                struct.insertAtOffset(offset, fieldType, field.size, field.name, field.comment);
                            } catch (Exception e2) {
                                // Field addition failed, skip
                            }
                        }
                        offset += field.size;
                    }
                }
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
        // Handle pointer types (trailing * with or without preceding space)
        if (ScriptUtils.isPointerType(typeName)) {
            String baseTypeName = ScriptUtils.stripPointer(typeName);
            DataType baseType = getDataType(baseTypeName, 0);
            return dtm.getPointer(baseType != null ? baseType : VoidDataType.dataType, 4);
        }

        // Handle explicit ptr: prefix or bare "pointer"
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
                        long addr = ScriptUtils.parseAddress(field.address);
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
                DataType dataType = createdStructures.get(structName);

                if (dataType != null && addr != null) {
                    try {
                        // Always clear the full struct range — typed data anywhere within
                        // the range (not just at the base) would block createData otherwise
                        listing.clearCodeUnits(addr, addr.add(dataType.getLength() - 1), false);

                        // Apply structure
                        listing.createData(addr, dataType);
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


    // Helper class for field definitions
    private static class FieldDef {
        String name;
        String typeName;
        int size;
        String comment;
        String address;
    }
}
