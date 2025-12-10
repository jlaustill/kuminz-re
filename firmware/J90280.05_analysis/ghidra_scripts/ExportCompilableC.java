// Export Compilable C Script
// Generates a single compilable C file from Ghidra analysis + CSV type definitions
// @author J90280.05_analysis
// @category Analysis
// @keybinding ctrl shift C
// @menupath Tools.Export Compilable C
// @toolbar

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.util.task.TaskMonitor;

public class ExportCompilableC extends GhidraScript {

    // ========================================================================
    // Data Model Classes
    // ========================================================================

    private class EnumEntry {
        String enumName;
        long value;  // Use long to handle values like 0x80000000
        String memberName;
        String comment;
        int size; // 1, 2, or 4 bytes

        EnumEntry(String enumName, long value, String memberName, String comment, int size) {
            this.enumName = enumName;
            this.value = value;
            this.memberName = memberName;
            this.comment = comment;
            this.size = size;
        }
    }

    private class StructField {
        String structName;
        String address; // may be empty for abstract types
        String fieldName;
        String type;
        int size;
        String comment;
        String dependency;

        StructField(String structName, String address, String fieldName, String type,
                    int size, String comment, String dependency) {
            this.structName = structName;
            this.address = address;
            this.fieldName = fieldName;
            this.type = type;
            this.size = size;
            this.comment = comment;
            this.dependency = dependency;
        }
    }

    private class StructDef {
        String name;
        String address;
        List<StructField> fields;
        Set<String> dependencies;

        StructDef(String name, String address) {
            this.name = name;
            this.address = address;
            this.fields = new ArrayList<>();
            this.dependencies = new HashSet<>();
        }
    }

    private class GlobalVariable {
        long address;
        String name;
        String type;
        String comment;
        int length;

        GlobalVariable(long address, String name, String type, String comment, int length) {
            this.address = address;
            this.name = name;
            this.type = type;
            this.comment = comment;
            this.length = length;
        }
    }

    // Track statistics for header
    private int enumCount = 0;
    private int structCount = 0;
    private int globalCount = 0;
    private int functionCount = 0;

    // Known type names (enums + structs)
    private Set<String> knownTypeNames = new HashSet<>();

    // C reserved keywords to escape
    private static final Set<String> C_KEYWORDS = new HashSet<>();
    static {
        String[] keywords = {"auto", "break", "case", "char", "const", "continue", "default",
            "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
            "long", "register", "return", "short", "signed", "sizeof", "static", "struct",
            "switch", "typedef", "union", "unsigned", "void", "volatile", "while",
            "inline", "restrict", "_Bool", "_Complex", "_Imaginary"};
        for (String k : keywords) C_KEYWORDS.add(k);
    }

    // ========================================================================
    // Main Entry Point
    // ========================================================================

    @Override
    public void run() throws Exception {
        println("=".repeat(60));
        println("GENERATING COMPILABLE C FILE");
        println("=".repeat(60));
        println("");

        String projectDir = getProjectRootFolder().getProjectLocator()
                .getProjectDir().getAbsolutePath();
        String workingDir = projectDir + "/working";

        // Ensure working directory exists
        new File(workingDir).mkdirs();

        // CSV paths
        String enumsCSV = projectDir + "/enums.csv";
        String structsCSV = projectDir + "/structure_definitions.csv";
        String globalsCSV = projectDir + "/global_variables.csv";

        // Phase 1: Parse enums
        println("[1/8] Parsing enums.csv...");
        Map<String, List<EnumEntry>> enums = parseEnumsCSV(enumsCSV);
        enumCount = 0;
        for (List<EnumEntry> entries : enums.values()) enumCount += entries.size();
        println("  Found " + enums.size() + " enum types (" + enumCount + " total members)");

        // Collect enum names as known types
        knownTypeNames.addAll(enums.keySet());

        // Phase 2: Parse structures
        println("[2/8] Parsing structure_definitions.csv...");
        Map<String, StructDef> structs = parseStructuresCSV(structsCSV);
        structCount = structs.size();
        println("  Found " + structCount + " struct types");

        // Collect struct names as known types
        knownTypeNames.addAll(structs.keySet());

        // Phase 3: Parse global variables
        println("[3/8] Parsing global_variables.csv...");
        List<GlobalVariable> globals = parseGlobalVariablesCSV(globalsCSV);
        globalCount = globals.size();
        println("  Found " + globalCount + " global variables");

        // Phase 4: Resolve struct dependencies
        println("[4/8] Resolving struct dependencies...");
        List<String> structOrder = topologicalSortStructs(structs);
        println("  Sorted " + structOrder.size() + " structs by dependencies");

        // Phase 5: Initialize decompiler
        println("[5/8] Initializing decompiler...");
        DecompInterface decompiler = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        decompiler.setOptions(options);
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(true);
        decompiler.setSimplificationStyle("decompile");

        if (!decompiler.openProgram(currentProgram)) {
            throw new Exception("Failed to initialize decompiler");
        }

        // Phase 6: Collect functions
        println("[6/8] Collecting functions...");
        List<Function> functions = new ArrayList<>();
        FunctionIterator funcIter = currentProgram.getFunctionManager().getFunctions(true);
        while (funcIter.hasNext()) {
            functions.add(funcIter.next());
        }
        Collections.sort(functions, (f1, f2) -> f1.getEntryPoint().compareTo(f2.getEntryPoint()));
        functionCount = functions.size();
        println("  Found " + functionCount + " functions");

        // Phase 7: Generate C file
        println("[7/8] Generating C file...");
        String outputFile = workingDir + "/J90280.05.ghidra.c";

        try (FileWriter writer = new FileWriter(outputFile)) {
            writeFileHeader(writer);
            writeIncludes(writer);
            writeTypeAliases(writer);
            writeEnumDefinitions(writer, enums);
            writeStructForwardDeclarations(writer, structs.keySet());
            writeStructDefinitions(writer, structs, structOrder);
            writeStructInstanceMacros(writer, structs);
            writeGlobalVariables(writer, globals);
            writeFunctionForwardDeclarations(writer, functions, decompiler);
            writeFunctionBodies(writer, functions, decompiler);
        }

        decompiler.dispose();

        // Phase 8: Summary
        println("[8/8] Export complete!");
        println("");
        println("=".repeat(60));
        println("OUTPUT: " + outputFile);
        println("=".repeat(60));
        println("");
        println("Statistics:");
        println("  - Enum types:       " + enums.size() + " (" + enumCount + " members)");
        println("  - Struct types:     " + structCount);
        println("  - Global variables: " + globalCount);
        println("  - Functions:        " + functionCount);
        println("");
        println("Compile test:");
        println("  m68k-elf-gcc -c -Wall -Wextra " + outputFile);
        println("");
        println("Or with regular GCC (syntax check only):");
        println("  gcc -fsyntax-only -Wall " + outputFile);
    }

    // ========================================================================
    // CSV Parsing Methods
    // ========================================================================

    private Map<String, List<EnumEntry>> parseEnumsCSV(String csvPath) throws IOException {
        Map<String, List<EnumEntry>> enums = new LinkedHashMap<>();

        File file = new File(csvPath);
        if (!file.exists()) {
            println("  Warning: " + csvPath + " not found");
            return enums;
        }

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            boolean isFirstLine = true;

            while ((line = br.readLine()) != null) {
                // Skip header
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                // Skip comment lines
                if (line.trim().startsWith("#") || line.trim().isEmpty()) {
                    continue;
                }

                // Parse: enum_name,value,member_name,comment,size
                String[] parts = parseCSVLine(line);
                if (parts.length >= 3) {
                    String enumName = parts[0].trim();
                    String valueStr = parts[1].trim();
                    String memberName = parts[2].trim();
                    String comment = (parts.length >= 4) ? parts[3].trim() : "";
                    int size = (parts.length >= 5 && !parts[4].trim().isEmpty()) ?
                               Integer.parseInt(parts[4].trim()) : 2; // default to 2 bytes

                    // Parse value (handle hex) - use Long to handle values like 0x80000000
                    long value;
                    if (valueStr.toLowerCase().startsWith("0x")) {
                        value = Long.parseLong(valueStr.substring(2), 16);
                    } else {
                        value = Long.parseLong(valueStr);
                    }

                    // Add to map
                    enums.computeIfAbsent(enumName, k -> new ArrayList<>())
                         .add(new EnumEntry(enumName, value, memberName, comment, size));
                }
            }
        }

        return enums;
    }

    private Map<String, StructDef> parseStructuresCSV(String csvPath) throws IOException {
        Map<String, StructDef> structs = new LinkedHashMap<>();

        File file = new File(csvPath);
        if (!file.exists()) {
            println("  Warning: " + csvPath + " not found");
            return structs;
        }

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            boolean isFirstLine = true;

            while ((line = br.readLine()) != null) {
                // Skip header
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                // Skip comment lines
                if (line.trim().startsWith("#") || line.trim().isEmpty()) {
                    continue;
                }

                // Parse: struct_name,address,field_name,type,size,comment,dependency,Status
                String[] parts = parseCSVLine(line);
                if (parts.length >= 5) {
                    String structName = parts[0].trim();
                    String address = parts[1].trim();
                    String fieldName = parts[2].trim();
                    String fieldType = parts[3].trim();
                    int fieldSize = Integer.parseInt(parts[4].trim());
                    String comment = (parts.length >= 6) ? parts[5].trim() : "";
                    String dependency = (parts.length >= 7) ? parts[6].trim() : "";

                    // Get or create struct definition
                    StructDef structDef = structs.get(structName);
                    if (structDef == null) {
                        structDef = new StructDef(structName, address);
                        structs.put(structName, structDef);
                    }

                    // Add field
                    structDef.fields.add(new StructField(structName, address, fieldName,
                                                         fieldType, fieldSize, comment, dependency));

                    // Track dependency
                    if (!dependency.isEmpty()) {
                        structDef.dependencies.add(dependency);
                    }
                }
            }
        }

        return structs;
    }

    private List<GlobalVariable> parseGlobalVariablesCSV(String csvPath) throws IOException {
        List<GlobalVariable> globals = new ArrayList<>();

        File file = new File(csvPath);
        if (!file.exists()) {
            println("  Warning: " + csvPath + " not found");
            return globals;
        }

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            boolean isFirstLine = true;

            while ((line = br.readLine()) != null) {
                // Skip header
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                // Skip comment lines
                if (line.trim().startsWith("#") || line.trim().isEmpty()) {
                    continue;
                }

                // Parse: address,name,type,comment,length,calterm_type,unit,data_pattern
                String[] parts = parseCSVLine(line);
                if (parts.length >= 5) {
                    String addressStr = parts[0].trim();
                    String name = parts[1].trim();
                    String type = parts[2].trim();
                    String comment = parts[3].trim();
                    int length = Integer.parseInt(parts[4].trim());

                    // Parse address
                    long address;
                    if (addressStr.toLowerCase().startsWith("0x")) {
                        address = Long.parseLong(addressStr.substring(2), 16);
                    } else {
                        address = Long.parseLong(addressStr, 16);
                    }

                    globals.add(new GlobalVariable(address, name, type, comment, length));
                }
            }
        }

        // Sort by address
        Collections.sort(globals, (a, b) -> Long.compare(a.address, b.address));

        return globals;
    }

    /**
     * Parse a CSV line handling quoted fields
     */
    private String[] parseCSVLine(String line) {
        List<String> result = new ArrayList<>();
        boolean inQuotes = false;
        StringBuilder field = new StringBuilder();

        for (int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);

            if (c == '"') {
                inQuotes = !inQuotes;
            } else if (c == ',' && !inQuotes) {
                result.add(field.toString());
                field = new StringBuilder();
            } else {
                field.append(c);
            }
        }
        result.add(field.toString());

        return result.toArray(new String[0]);
    }

    // ========================================================================
    // Type Mapping
    // ========================================================================

    /**
     * Map CSV type to C type
     * Returns null if type is unknown (caller should use fallback)
     */
    private String mapCSVTypeToC(String csvType, int size) {
        if (csvType == null || csvType.isEmpty()) {
            return null;
        }

        String type = csvType.trim();

        // Handle array notation: byte[60] -> uint8_t[60]
        if (type.contains("[")) {
            int bracketPos = type.indexOf('[');
            String baseType = type.substring(0, bracketPos);
            String arrayPart = type.substring(bracketPos);
            String mappedBase = mapPrimitiveType(baseType);
            if (mappedBase != null) {
                return mappedBase + arrayPart;
            }
            // Unknown base type in array
            return null;
        }

        // Check primitives first
        String primitive = mapPrimitiveType(type);
        if (primitive != null) {
            return primitive;
        }

        // Check if it's a known struct/enum name
        if (knownTypeNames.contains(type)) {
            return type;
        }

        // Handle pointer notation: ptr:type
        if (type.toLowerCase().startsWith("ptr:")) {
            String baseType = type.substring(4).trim();
            String mappedBase = mapCSVTypeToC(baseType, 4);
            if (mappedBase != null) {
                return mappedBase + "*";
            }
            return "void*";
        }

        // Unknown type
        return null;
    }

    private String mapPrimitiveType(String type) {
        switch (type.toLowerCase()) {
            case "byte":
            case "uint8_t":
            case "uint8":
            case "uchar":
                return "uint8_t";

            case "sbyte":
            case "int8_t":
            case "int8":
            case "char":
                return "int8_t";

            case "word":
            case "uint16_t":
            case "uint16":
            case "ushort":
                return "uint16_t";

            case "sword":
            case "int16_t":
            case "int16":
            case "short":
                return "int16_t";

            case "dword":
            case "uint32_t":
            case "uint32":
            case "uint":
            case "ulong":
                return "uint32_t";

            case "sdword":
            case "int32_t":
            case "int32":
            case "int":
            case "long":
            case "slong":
                return "int32_t";

            case "qword":
            case "uint64_t":
            case "uint64":
                return "uint64_t";

            case "float":
                return "float";

            case "double":
                return "double";

            case "void":
                return "void";

            default:
                return null;
        }
    }

    /**
     * Get base type size in bytes
     */
    private int getBaseTypeSize(String cType) {
        if (cType == null) return 0;

        // Strip array notation
        if (cType.contains("[")) {
            cType = cType.substring(0, cType.indexOf('['));
        }

        // Strip pointer
        if (cType.endsWith("*")) {
            return 4; // 32-bit pointers on MC68000
        }

        switch (cType) {
            case "uint8_t":
            case "int8_t":
            case "char":
                return 1;

            case "uint16_t":
            case "int16_t":
            case "short":
                return 2;

            case "uint32_t":
            case "int32_t":
            case "int":
            case "long":
            case "float":
                return 4;

            case "uint64_t":
            case "int64_t":
            case "double":
                return 8;

            default:
                // Unknown - might be a struct
                return 0;
        }
    }

    /**
     * Get fallback C type based on size
     */
    private String getFallbackType(int size) {
        switch (size) {
            case 1: return "uint8_t";
            case 2: return "uint16_t";
            case 4: return "uint32_t";
            case 8: return "uint64_t";
            default:
                // For other sizes, use byte array
                return "uint8_t";
        }
    }

    /**
     * Escape C reserved keywords only
     * Note: Identifiers starting with digits should be fixed in CSV files, not here
     */
    private String escapeCKeyword(String name) {
        if (name == null || name.isEmpty()) {
            return "_unnamed";
        }
        // Check for reserved keywords
        if (C_KEYWORDS.contains(name)) {
            return "_" + name;
        }
        return name;
    }

    /**
     * Truncate comment to max length
     */
    private String truncateComment(String comment, int maxLen) {
        if (comment == null) return "";
        comment = comment.replace("*/", "* /"); // Escape comment end
        if (comment.length() > maxLen) {
            return comment.substring(0, maxLen - 3) + "...";
        }
        return comment;
    }

    // ========================================================================
    // Struct Dependency Resolution (Topological Sort)
    // ========================================================================

    private List<String> topologicalSortStructs(Map<String, StructDef> structs) {
        List<String> result = new ArrayList<>();
        Set<String> visited = new HashSet<>();
        Set<String> visiting = new HashSet<>();

        for (String structName : structs.keySet()) {
            if (!visited.contains(structName)) {
                visitStruct(structName, structs, visited, visiting, result);
            }
        }

        return result;
    }

    private void visitStruct(String structName, Map<String, StructDef> structs,
                             Set<String> visited, Set<String> visiting, List<String> result) {
        if (visiting.contains(structName)) {
            println("  Warning: Circular dependency involving " + structName);
            return;
        }

        if (visited.contains(structName)) {
            return;
        }

        StructDef structDef = structs.get(structName);
        if (structDef == null) {
            return;
        }

        visiting.add(structName);

        // Visit dependencies first
        for (String dependency : structDef.dependencies) {
            if (structs.containsKey(dependency)) {
                visitStruct(dependency, structs, visited, visiting, result);
            }
        }

        visiting.remove(structName);
        visited.add(structName);
        result.add(structName);
    }

    // ========================================================================
    // Section Writers
    // ========================================================================

    private void writeFileHeader(FileWriter writer) throws IOException {
        writer.write("/*\n");
        writer.write(" * Ghidra Decompilation Export - J90280.05 Firmware\n");
        writer.write(" * Cummins CM550 ECU - MC68000 Architecture (Big-Endian)\n");
        writer.write(" *\n");
        writer.write(" * Generated: " + new java.util.Date().toString() + "\n");
        writer.write(" *\n");
        writer.write(" * Data Sources:\n");
        writer.write(" *   - enums.csv (" + enumCount + " entries)\n");
        writer.write(" *   - structure_definitions.csv (" + structCount + " types)\n");
        writer.write(" *   - global_variables.csv (" + globalCount + " variables)\n");
        writer.write(" *   - Ghidra decompiler (" + functionCount + " functions)\n");
        writer.write(" *\n");
        writer.write(" * Target: m68k-elf-gcc\n");
        writer.write(" * Compile: m68k-elf-gcc -c -Wall -Wextra J90280.05.ghidra.c\n");
        writer.write(" */\n\n");
    }

    private void writeIncludes(FileWriter writer) throws IOException {
        writer.write("/* ============================================================ */\n");
        writer.write("/* Standard Includes                                            */\n");
        writer.write("/* ============================================================ */\n\n");

        writer.write("#include <stdint.h>\n");
        writer.write("#include <stdbool.h>\n");
        writer.write("#include <stddef.h>\n");
        writer.write("\n");
    }

    private void writeTypeAliases(FileWriter writer) throws IOException {
        writer.write("/* ============================================================ */\n");
        writer.write("/* Ghidra Decompiler Type Aliases                              */\n");
        writer.write("/* ============================================================ */\n\n");

        writer.write("typedef uint8_t byte;\n");
        writer.write("typedef int8_t sbyte;\n");
        writer.write("typedef uint16_t word;\n");
        writer.write("typedef int16_t sword;\n");
        writer.write("typedef uint32_t dword;\n");
        writer.write("typedef int32_t sdword;\n");
        writer.write("typedef uint16_t ushort;\n");
        writer.write("typedef uint32_t uint;\n");
        writer.write("typedef uint32_t ulong;\n");
        writer.write("typedef int32_t slong;\n");
        writer.write("typedef void* pointer;\n");
        writer.write("typedef uint8_t undefined;\n");
        writer.write("typedef uint8_t undefined1;\n");
        writer.write("typedef uint16_t undefined2;\n");
        writer.write("typedef uint8_t undefined3[3];\n");
        writer.write("typedef uint32_t undefined4;\n");
        writer.write("typedef uint8_t undefined5[5];\n");
        writer.write("typedef uint8_t undefined6[6];\n");
        writer.write("typedef uint8_t undefined7[7];\n");
        writer.write("typedef uint64_t undefined8;\n");
        writer.write("\n");
        writer.write("/* Ghidra decompiler type aliases */\n");
        writer.write("typedef uint64_t ulonglong;\n");
        writer.write("typedef uint8_t int3[3];  /* 3-byte integer (Ghidra artifact) */\n");
        writer.write("\n");
    }

    private void writeEnumDefinitions(FileWriter writer, Map<String, List<EnumEntry>> enums)
            throws IOException {
        writer.write("/* ============================================================ */\n");
        writer.write("/* Enum Definitions (from enums.csv)                           */\n");
        writer.write("/* ============================================================ */\n\n");

        for (Map.Entry<String, List<EnumEntry>> entry : enums.entrySet()) {
            String enumName = entry.getKey();
            List<EnumEntry> members = entry.getValue();

            if (members.isEmpty()) continue;

            // Determine size from first member
            int size = members.get(0).size;

            // Sort by value
            List<EnumEntry> sortedMembers = new ArrayList<>(members);
            Collections.sort(sortedMembers, (a, b) -> Long.compare(a.value, b.value));

            writer.write("typedef enum {\n");

            for (int i = 0; i < sortedMembers.size(); i++) {
                EnumEntry member = sortedMembers.get(i);
                // Use member name directly - CSV should have unique names
                String safeName = escapeCKeyword(member.memberName);
                String valueStr;

                // Use hex for values >= 16 or if original was hex-like
                if (member.value >= 16) {
                    // Use appropriate width for hex formatting
                    if (member.value > 0xFFFFFFFFL) {
                        valueStr = String.format("0x%016XUL", member.value);
                    } else if (member.value > 0xFFFF) {
                        valueStr = String.format("0x%08XUL", member.value);
                    } else if (member.value > 0xFF) {
                        valueStr = String.format("0x%04X", member.value);
                    } else {
                        valueStr = String.format("0x%02X", member.value);
                    }
                } else {
                    valueStr = String.valueOf(member.value);
                }

                String commentStr = "";
                if (member.comment != null && !member.comment.isEmpty()) {
                    commentStr = " /* " + truncateComment(member.comment, 50) + " */";
                }

                String comma = (i < sortedMembers.size() - 1) ? "," : "";
                writer.write(String.format("    %s = %s%s%s\n", safeName, valueStr, comma, commentStr));
            }

            // Add packed attribute for 1-byte enums
            if (size == 1) {
                writer.write("} __attribute__((packed)) " + enumName + ";\n\n");
            } else {
                writer.write("} " + enumName + ";\n\n");
            }
        }
    }

    private void writeStructForwardDeclarations(FileWriter writer, Set<String> structNames)
            throws IOException {
        writer.write("/* ============================================================ */\n");
        writer.write("/* Forward Struct Declarations                                  */\n");
        writer.write("/* ============================================================ */\n\n");

        List<String> sortedNames = new ArrayList<>(structNames);
        Collections.sort(sortedNames);

        for (String name : sortedNames) {
            writer.write("typedef struct " + name + " " + name + ";\n");
        }
        writer.write("\n");
    }

    private void writeStructDefinitions(FileWriter writer, Map<String, StructDef> structs,
                                        List<String> sortOrder) throws IOException {
        writer.write("/* ============================================================ */\n");
        writer.write("/* Struct Definitions (from structure_definitions.csv)         */\n");
        writer.write("/* ============================================================ */\n\n");

        for (String structName : sortOrder) {
            StructDef structDef = structs.get(structName);
            if (structDef == null) continue;

            // Write struct comment with address if available
            if (!structDef.address.isEmpty()) {
                writer.write("/* Instance at " + structDef.address + " */\n");
            }

            writer.write("struct " + structName + " {\n");

            for (StructField field : structDef.fields) {
                String cType = mapCSVTypeToC(field.type, field.size);
                String safeName = escapeCKeyword(field.fieldName);
                String commentStr = "";

                if (field.comment != null && !field.comment.isEmpty()) {
                    commentStr = " /* " + truncateComment(field.comment, 50) + " */";
                }

                if (cType == null) {
                    // Unknown type - use fallback
                    if (field.size == 1) {
                        writer.write(String.format("    uint8_t %s; /* orig: %s%s */\n",
                                safeName, field.type,
                                field.comment.isEmpty() ? "" : " - " + truncateComment(field.comment, 30)));
                    } else {
                        writer.write(String.format("    uint8_t %s[%d]; /* orig: %s%s */\n",
                                safeName, field.size, field.type,
                                field.comment.isEmpty() ? "" : " - " + truncateComment(field.comment, 30)));
                    }
                } else {
                    // Check if size suggests an array
                    int baseSize = getBaseTypeSize(cType);
                    if (baseSize > 0 && field.size > baseSize && !cType.contains("[")) {
                        int count = field.size / baseSize;
                        writer.write(String.format("    %s %s[%d];%s\n", cType, safeName, count, commentStr));
                    } else {
                        writer.write(String.format("    %s %s;%s\n", cType, safeName, commentStr));
                    }
                }
            }

            writer.write("} __attribute__((packed));\n\n");
        }
    }

    private void writeStructInstanceMacros(FileWriter writer, Map<String, StructDef> structs)
            throws IOException {
        writer.write("/* ============================================================ */\n");
        writer.write("/* Struct Instance Macros (for Ghidra structtype_t_ADDRESS refs) */\n");
        writer.write("/* ============================================================ */\n\n");

        int instanceCount = 0;
        for (Map.Entry<String, StructDef> entry : structs.entrySet()) {
            String structName = entry.getKey();
            StructDef structDef = entry.getValue();

            // Only generate if struct has a non-empty address
            if (structDef.address != null && !structDef.address.isEmpty()
                    && !structDef.address.equals("0x00000000")) {
                // Generate instance name: structname_t_ADDRESS (lowercase address, no 0x prefix)
                String addrLower = structDef.address.toLowerCase();
                if (addrLower.startsWith("0x")) {
                    addrLower = addrLower.substring(2);
                }
                // Pad to 8 chars
                while (addrLower.length() < 8) {
                    addrLower = "0" + addrLower;
                }
                String instanceName = structName + "_" + addrLower;

                // Generate macro
                String addrUpper = structDef.address.toUpperCase();
                if (!addrUpper.startsWith("0x") && !addrUpper.startsWith("0X")) {
                    addrUpper = "0x" + addrUpper;
                }
                writer.write(String.format("#define %s (*(volatile %s*)%sUL)\n",
                        instanceName, structName, addrUpper));
                instanceCount++;
            }
        }

        if (instanceCount > 0) {
            writer.write("\n");
        }
        println("  Generated " + instanceCount + " struct instance macros");
    }

    private void writeGlobalVariables(FileWriter writer, List<GlobalVariable> globals)
            throws IOException {
        writer.write("/* ============================================================ */\n");
        writer.write("/* Global Variables (Memory-Mapped via Pointer Macros)         */\n");
        writer.write("/* ============================================================ */\n\n");

        for (GlobalVariable var : globals) {
            String cType = mapCSVTypeToC(var.type, var.length);
            String safeName = escapeCKeyword(var.name);
            String comment = truncateComment(var.comment, 50);

            // Determine if this is an array
            boolean isExplicitArray = var.type.contains("[");
            int baseSize = (cType != null) ? getBaseTypeSize(cType) : 0;
            boolean isImplicitArray = !isExplicitArray && baseSize > 0 && var.length > baseSize;

            if (cType == null) {
                // Unknown type - use size-based fallback
                if (var.length == 1) {
                    cType = "uint8_t";
                    isImplicitArray = false;
                } else if (var.length == 2) {
                    cType = "uint16_t";
                    isImplicitArray = false;
                } else if (var.length == 4) {
                    cType = "uint32_t";
                    isImplicitArray = false;
                } else {
                    cType = "uint8_t";
                    isImplicitArray = true;
                }
            }

            // Build the macro
            String addressStr = String.format("0x%08XUL", var.address);
            String commentPart = comment.isEmpty() ? "" : " /* " + comment + " */";

            if (isExplicitArray) {
                // Explicit array: #define name ((volatile type*)addr)
                String baseType = cType;
                if (baseType.contains("[")) {
                    baseType = baseType.substring(0, baseType.indexOf('['));
                }
                writer.write(String.format("#define %s ((volatile %s*)%s)%s\n",
                        safeName, baseType, addressStr, commentPart));
            } else if (isImplicitArray) {
                // Implicit array based on size
                int count = var.length / Math.max(1, baseSize);
                String baseType = cType;
                if (baseType.contains("[")) {
                    baseType = baseType.substring(0, baseType.indexOf('['));
                }
                writer.write(String.format("#define %s ((volatile %s*)%s) /* [%d]%s */\n",
                        safeName, baseType, addressStr, count,
                        comment.isEmpty() ? "" : " " + comment));
            } else {
                // Scalar: #define name (*(volatile type*)addr)
                writer.write(String.format("#define %s (*(volatile %s*)%s)%s\n",
                        safeName, cType, addressStr, commentPart));
            }
        }

        writer.write("\n");
    }

    private void writeFunctionForwardDeclarations(FileWriter writer, List<Function> functions,
                                                   DecompInterface decompiler) throws IOException {
        writer.write("/* ============================================================ */\n");
        writer.write("/* Function Forward Declarations                                */\n");
        writer.write("/* ============================================================ */\n\n");

        int count = 0;
        for (Function func : functions) {
            String prototype = extractFunctionPrototype(func, decompiler);
            if (prototype != null) {
                writer.write(prototype + ";\n");
            } else {
                // Fallback
                writer.write("void " + escapeCKeyword(func.getName()) + "(void); /* decompile failed */\n");
            }

            count++;
            if (count % 100 == 0) {
                println("  Processed " + count + "/" + functions.size() + " function prototypes...");
            }
        }

        writer.write("\n");
    }

    private String extractFunctionPrototype(Function func, DecompInterface decompiler) {
        try {
            DecompileResults results = decompiler.decompileFunction(func, 30, TaskMonitor.DUMMY);
            if (results == null || !results.decompileCompleted()) {
                return null;
            }

            String code = results.getDecompiledFunction().getC();
            if (code == null || code.isEmpty()) {
                return null;
            }

            // Find the function signature (everything before first '{')
            int bracePos = code.indexOf('{');
            if (bracePos <= 0) {
                return null;
            }

            String sig = code.substring(0, bracePos).trim();

            // Remove any leading warning comments
            // Pattern: /* WARNING: ... */\n
            while (sig.contains("/*")) {
                int start = sig.indexOf("/*");
                int end = sig.indexOf("*/", start);
                if (end > start) {
                    sig = (sig.substring(0, start) + sig.substring(end + 2)).trim();
                } else {
                    break;
                }
            }

            // Remove leading newlines and get just the signature line
            String[] lines = sig.split("\n");
            for (int i = lines.length - 1; i >= 0; i--) {
                String line = lines[i].trim();
                if (!line.isEmpty() && !line.startsWith("//") && !line.startsWith("/*")) {
                    return line;
                }
            }

            return null;

        } catch (Exception e) {
            return null;
        }
    }

    private void writeFunctionBodies(FileWriter writer, List<Function> functions,
                                     DecompInterface decompiler) throws IOException {
        writer.write("/* ============================================================ */\n");
        writer.write("/* Function Implementations                                     */\n");
        writer.write("/* ============================================================ */\n\n");

        int count = 0;
        for (Function func : functions) {
            try {
                DecompileResults results = decompiler.decompileFunction(func, 30, TaskMonitor.DUMMY);

                String address = String.format("0x%08x", func.getEntryPoint().getOffset());
                writer.write("/*\n");
                writer.write(" * Function: " + func.getName() + " @ " + address + "\n");
                writer.write(" */\n");

                if (results != null && results.decompileCompleted()) {
                    String code = results.getDecompiledFunction().getC();
                    if (code != null && !code.isEmpty()) {
                        writer.write(code);
                    } else {
                        writer.write("/* ERROR: Empty decompilation */\n");
                        writer.write("void " + escapeCKeyword(func.getName()) + "(void) {\n");
                        writer.write("    /* Decompilation produced empty output */\n");
                        writer.write("}\n");
                    }
                } else {
                    writer.write("/* ERROR: Failed to decompile */\n");
                    writer.write("void " + escapeCKeyword(func.getName()) + "(void) {\n");
                    writer.write("    /* Decompilation failed */\n");
                    writer.write("}\n");
                }

                writer.write("\n\n");

            } catch (Exception e) {
                writer.write("/* ERROR: Exception during decompilation: " + e.getMessage() + " */\n");
                writer.write("void " + escapeCKeyword(func.getName()) + "(void) {\n");
                writer.write("    /* Decompilation exception */\n");
                writer.write("}\n\n\n");
            }

            count++;
            if (count % 50 == 0) {
                println("  Decompiled " + count + "/" + functions.size() + " functions...");
            }
        }
    }
}
