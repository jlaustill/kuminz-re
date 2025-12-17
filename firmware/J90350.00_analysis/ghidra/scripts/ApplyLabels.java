// Apply Labels Script
// Parses labels.csv and creates code labels in Ghidra for improved decompilation readability
// Can optionally use relocation_map.csv to translate J90280.05 addresses to J90350.00
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
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

public class ApplyLabels extends GhidraScript {

    private SymbolTable symbolTable;
    private Map<Long, Long> relocationMap = new HashMap<>();

    @Override
    public void run() throws Exception {
        println("=".repeat(70));
        println("APPLY LABELS - J90350.00");
        println("=".repeat(70));
        println("");

        symbolTable = currentProgram.getSymbolTable();

        // Get input files from arguments or use defaults
        String[] args = getScriptArgs();
        String csvPath;
        String relocationPath = null;

        if (args.length > 0) {
            csvPath = args[0];
            if (args.length > 1) {
                relocationPath = args[1];
            }
        } else {
            // Default to J90280.05's labels.csv
            csvPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../../J90280.05_analysis/ghidra/CM550.rep/labels.csv";
            relocationPath = getProjectRootFolder().getProjectLocator().getProjectDir() +
                    "/../output/relocation_map.csv";
        }

        // Check for local copy first
        String localLabels = getProjectRootFolder().getProjectLocator().getProjectDir() +
                "/../output/labels.csv";
        if (new File(localLabels).exists()) {
            csvPath = localLabels;
            println("Using local labels.csv (J90350.00 specific)");
        } else {
            println("Using J90280.05 labels.csv with relocation mapping");
        }

        println("Labels file: " + csvPath);
        println("");

        if (!new File(csvPath).exists()) {
            println("ERROR: labels.csv not found at: " + csvPath);
            return;
        }

        // Phase 1: Load relocation map if available
        if (relocationPath != null && new File(relocationPath).exists()) {
            println("[Phase 1] Loading relocation map...");
            int mapCount = loadRelocationMap(relocationPath);
            println("  Loaded " + mapCount + " address mappings");
            println("");
        } else {
            println("[Phase 1] No relocation map found - applying labels at exact addresses only");
            println("  ROM labels from J90280.05 will likely fail to apply");
            println("  RAM labels (0x800000+) should apply correctly");
            println("");
        }

        // Phase 2: Parse labels CSV
        println("[Phase 2] Parsing label definitions...");
        List<LabelDef> labels = parseLabelDefinitions(csvPath);
        println("  Found " + labels.size() + " labels");
        println("");

        // Phase 3: Apply labels
        println("[Phase 3] Applying labels...");
        ApplyResult result = applyLabels(labels);
        println("  Applied: " + result.applied);
        println("  Skipped (already exists): " + result.skipped);
        println("  Failed (invalid address): " + result.failed);
        println("  Translated via relocation map: " + result.translated);
        println("");

        println("=".repeat(70));
        println("LABEL APPLICATION COMPLETE!");
        println("=".repeat(70));
    }

    private int loadRelocationMap(String csvPath) throws Exception {
        int count = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;

            while ((line = reader.readLine()) != null) {
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }

                // Parse: j90280_addr,j90280_name,j90350_addr,match_type,confidence
                String[] parts = line.split(",");
                if (parts.length < 3) {
                    continue;
                }

                try {
                    long j90280Addr = parseAddressString(parts[0].trim());
                    long j90350Addr = parseAddressString(parts[2].trim());

                    if (j90350Addr > 0) {
                        relocationMap.put(j90280Addr, j90350Addr);
                        count++;
                    }
                } catch (Exception e) {
                    // Skip invalid entries
                }
            }
        }

        return count;
    }

    private List<LabelDef> parseLabelDefinitions(String csvPath) throws Exception {
        List<LabelDef> labels = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(csvPath))) {
            String line;
            boolean isFirstLine = true;

            while ((line = reader.readLine()) != null) {
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }

                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) {
                    continue;
                }

                // Parse: address,label_name,comment
                String[] parts = parseCSVLine(line);
                if (parts.length < 2) {
                    continue;
                }

                String addressStr = parts[0].trim();
                String labelName = parts[1].trim();
                String comment = parts.length > 2 ? parts[2].trim() : "";

                if (addressStr.isEmpty() || labelName.isEmpty()) {
                    continue;
                }

                try {
                    long address = parseAddressString(addressStr);

                    LabelDef label = new LabelDef();
                    label.originalAddress = address;
                    label.name = labelName;
                    label.comment = comment;

                    labels.add(label);
                } catch (Exception e) {
                    // Skip invalid addresses
                }
            }
        }

        return labels;
    }

    private String[] parseCSVLine(String line) {
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

    private ApplyResult applyLabels(List<LabelDef> labels) {
        ApplyResult result = new ApplyResult();
        int txId = currentProgram.startTransaction("Apply Labels");

        try {
            for (LabelDef label : labels) {
                long targetAddress = label.originalAddress;
                boolean wasTranslated = false;

                // Check if this is a ROM address that needs translation
                // RAM addresses (0x800000+) should be used directly
                if (targetAddress < 0x800000) {
                    // This is a ROM/Flash address - try to translate
                    Long translated = relocationMap.get(targetAddress);
                    if (translated != null) {
                        targetAddress = translated;
                        wasTranslated = true;
                    }
                }

                Address addr = toAddr(targetAddress);
                if (addr == null) {
                    result.failed++;
                    continue;
                }

                // Check if address is valid in current program
                if (currentProgram.getMemory().getBlock(addr) == null) {
                    result.failed++;
                    continue;
                }

                // Check if symbol already exists
                Symbol existing = symbolTable.getPrimarySymbol(addr);
                if (existing != null && existing.getName().equals(label.name)) {
                    result.skipped++;
                    continue;
                }

                try {
                    // Create or rename label
                    if (existing != null && !existing.getName().startsWith("LAB_") &&
                        !existing.getName().startsWith("DAT_")) {
                        // Don't overwrite meaningful existing names
                        result.skipped++;
                    } else {
                        symbolTable.createLabel(addr, label.name, SourceType.USER_DEFINED);
                        result.applied++;
                        if (wasTranslated) {
                            result.translated++;
                        }
                    }
                } catch (Exception e) {
                    result.failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(txId, true);
        }

        return result;
    }

    private long parseAddressString(String addressStr) {
        addressStr = addressStr.trim();
        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
            return Long.parseLong(addressStr.substring(2), 16);
        }
        return Long.parseLong(addressStr, 16);
    }

    // Helper class for label definitions
    private static class LabelDef {
        long originalAddress;
        String name;
        String comment;
    }

    // Helper class for apply results
    private static class ApplyResult {
        int applied = 0;
        int skipped = 0;
        int failed = 0;
        int translated = 0;
    }
}
