// Apply Enums Script
// Parses enums.csv and creates enum data types in Ghidra for improved decompilation readability
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
import ghidra.program.model.data.*;

public class ApplyEnums extends GhidraScript {

    private DataTypeManager dtm;
    private Category enumCategory;

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY ENUMS - J90350.00");
        println("=".repeat(70));
        println("");

        dtm = currentProgram.getDataTypeManager();

        // Create category for our enums
        enumCategory = dtm.createCategory(new CategoryPath("/J90350_Enums"));

        // Get input file from arguments or use default
        String[] args = getScriptArgs();
        String csvPath;

        if (args.length > 0) {
            csvPath = args[0];
        } else {
            // Default to J90280.05's enums.csv since that's where the definitions are
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../../J90280.05_analysis/ghidra/CM550.rep/enums.csv";
        }

        println("Input file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: enums.csv not found at: " + csvPath);
            println("Try running with explicit path:");
            println("  ./analyze.sh enums /path/to/enums.csv");
            return;
        }

        // Phase 1: Parse CSV and group by enum name
        println("[Phase 1] Parsing enum definitions...");
        Map<String, List<EnumMember>> enumDefs = parseEnumDefinitions(csvPath);
        println("  Found " + enumDefs.size() + " enum types");
        println("");

        // Phase 2: Create Ghidra enum types
        println("[Phase 2] Creating enum types in Ghidra...");
        int created = createEnumTypes(enumDefs);
        println("  Created " + created + " enum types");
        println("");

        // Summary of enums
        println("[Summary] Enum types created:");
        int count = 0;
        for (Map.Entry<String, List<EnumMember>> entry : enumDefs.entrySet()) {
            count++;
            if (count <= 20) {
                println("  - " + entry.getKey() + " (" + entry.getValue().size() + " members)");
            }
        }
        if (count > 20) {
            println("  ... and " + (count - 20) + " more");
        }

        println("");
        println("=".repeat(70));
        println("ENUM APPLICATION COMPLETE!");
        println("Re-run export to see enums in decompiled output.");
        println("=".repeat(70));
    }

    private Map<String, List<EnumMember>> parseEnumDefinitions(String csvPath) throws Exception {
        Map<String, List<EnumMember>> enumDefs = new HashMap<>();

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

                // Parse CSV: enum_name,value,member_name,comment,size
                String[] parts = parseCSVLine(line);
                if (parts.length < 3) {
                    continue;
                }

                String enumName = parts[0].trim();
                String valueStr = parts[1].trim();
                String memberName = parts[2].trim();
                String comment = parts.length > 3 ? parts[3].trim() : "";
                int size = 4; // Default to 4 bytes
                if (parts.length > 4) {
                    try {
                        size = Integer.parseInt(parts[4].trim());
                    } catch (NumberFormatException e) {
                        // Keep default
                    }
                }

                // Skip if no enum name or member name
                if (enumName.isEmpty() || memberName.isEmpty()) {
                    continue;
                }

                // Parse value (supports hex 0x prefix)
                long value;
                try {
                    if (valueStr.startsWith("0x") || valueStr.startsWith("0X")) {
                        value = Long.parseLong(valueStr.substring(2), 16);
                    } else {
                        value = Long.parseLong(valueStr);
                    }
                } catch (NumberFormatException e) {
                    // Skip invalid values
                    continue;
                }

                // Create enum member
                EnumMember member = new EnumMember();
                member.name = memberName;
                member.value = value;
                member.comment = comment;
                member.size = size;

                // Add to enum
                if (!enumDefs.containsKey(enumName)) {
                    enumDefs.put(enumName, new ArrayList<>());
                }
                enumDefs.get(enumName).add(member);
            }
        }

        return enumDefs;
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

    private int createEnumTypes(Map<String, List<EnumMember>> enumDefs) throws Exception {
        int created = 0;
        int txId = dtm.startTransaction("Create Enums");

        try {
            for (Map.Entry<String, List<EnumMember>> entry : enumDefs.entrySet()) {
                String enumName = entry.getKey();
                List<EnumMember> members = entry.getValue();

                if (members.isEmpty()) {
                    continue;
                }

                // Determine enum size from members (use largest or first defined)
                int enumSize = members.get(0).size;
                for (EnumMember m : members) {
                    if (m.size > enumSize) {
                        enumSize = m.size;
                    }
                }

                // Ensure valid size (1, 2, 4, or 8 bytes)
                if (enumSize <= 0) enumSize = 1;
                else if (enumSize > 8) enumSize = 8;

                // Check if enum already exists
                DataType existing = dtm.getDataType(enumCategory.getCategoryPath(), enumName);
                if (existing != null) {
                    dtm.remove(existing, monitor);
                }

                // Create the enum
                EnumDataType enumType = new EnumDataType(enumCategory.getCategoryPath(), enumName, enumSize, dtm);

                // Add members
                for (EnumMember member : members) {
                    try {
                        enumType.add(member.name, member.value);
                        // Note: Ghidra EnumDataType doesn't support per-member comments
                    } catch (Exception e) {
                        // Skip duplicate values or other errors
                        println("  Warning: Could not add " + member.name + " to " + enumName + ": " + e.getMessage());
                    }
                }

                // Add to data type manager
                dtm.addDataType(enumType, DataTypeConflictHandler.REPLACE_HANDLER);
                created++;
            }
        } finally {
            dtm.endTransaction(txId, true);
        }

        return created;
    }

    // Helper class for enum member definitions
    private static class EnumMember {
        String name;
        long value;
        String comment;
        int size;
    }
}
