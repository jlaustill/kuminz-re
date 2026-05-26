import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Pure utility logic shared by all Ghidra analysis scripts.
 * No Ghidra imports — fully testable with plain JUnit.
 */
public class ScriptUtils {

    // ── CSV parsing ──────────────────────────────────────────────────────────

    /** Splits a CSV line respecting double-quoted fields that may contain commas. */
    public static String[] parseCSVLine(String line) {
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

    // ── Address / numeric parsing ────────────────────────────────────────────

    /**
     * Parses an address string that may have a "0x"/"0X" prefix or be bare hex.
     * Trims surrounding whitespace before parsing.
     */
    public static long parseAddress(String addressStr) {
        addressStr = addressStr.trim();
        if (addressStr.startsWith("0x") || addressStr.startsWith("0X")) {
            return Long.parseLong(addressStr.substring(2), 16);
        }
        return Long.parseLong(addressStr, 16);
    }

    /**
     * Parses a numeric value that may be hex (0x prefix) or decimal.
     * Trims surrounding whitespace before parsing.
     */
    public static long parseIntValue(String valueStr) {
        valueStr = valueStr.trim();
        if (valueStr.startsWith("0x") || valueStr.startsWith("0X")) {
            return Long.parseLong(valueStr.substring(2), 16);
        }
        return Long.parseLong(valueStr);
    }

    // ── Type name logic ──────────────────────────────────────────────────────

    /** Ghidra built-in primitive type names. Anything not in this set is a user-named type. */
    public static final Set<String> PRIMITIVE_TYPES = new HashSet<>(Arrays.asList(
        "word", "byte", "dword", "qword",
        "sbyte", "sword", "sdword", "sqword",
        "pointer", "bool",
        "short", "int", "long",
        "ushort", "uint", "ulong",
        "undefined", "undefined1", "undefined2", "undefined4", "undefined8",
        "float", "double", "unicode"
    ));

    /**
     * Returns true for Ghidra built-in primitive type names (including primitive pointers
     * like "byte *"). Named types (structs, enums) and named pointers ("my_struct_t *") return false.
     */
    public static boolean isPrimitiveType(String typeName) {
        if (typeName == null || typeName.trim().isEmpty()) return true;
        String trimmed = typeName.trim().toLowerCase();
        if (isPointerType(trimmed)) {
            return PRIMITIVE_TYPES.contains(stripPointer(trimmed));
        }
        return PRIMITIVE_TYPES.contains(trimmed);
    }

    /**
     * Selects the best type annotation to write during export.
     * Priority: named Ghidra type > named CSV type > primitive Ghidra type.
     *
     * Rationale: Ghidra can revert manually-applied enum/struct types to primitives
     * between headless sessions, so the CSV is the authoritative record of user intent.
     * But if Ghidra has independently discovered a named type (e.g. a new struct), trust that.
     */
    public static String selectType(String ghidraType, String csvType) {
        if (!isPrimitiveType(ghidraType)) return ghidraType;
        if (!isPrimitiveType(csvType))    return csvType;
        return ghidraType;
    }

    /**
     * Returns true if the type name is a pointer — handles both compact "struct_t*"
     * and spaced "struct_t *" forms used inconsistently across scripts.
     */
    public static boolean isPointerType(String typeName) {
        if (typeName == null) return false;
        return typeName.trim().endsWith("*");
    }

    /**
     * Strips the trailing '*' and surrounding whitespace, returning the base type name.
     * Works for both "struct_t*" and "struct_t *".
     */
    public static String stripPointer(String typeName) {
        String trimmed = typeName.trim();
        return trimmed.substring(0, trimmed.length() - 1).trim();
    }

    // ── Enum size ────────────────────────────────────────────────────────────

    /**
     * Returns the nearest valid Ghidra enum size (1, 2, 4, or 8 bytes) for a given raw size.
     * Rounds up to the next power of 2; clamps above 8 to 8.
     *
     * The raw size is typically the max of all member sizes declared in the CSV.
     * Ghidra's EnumDataType only accepts 1, 2, 4, or 8 — passing anything else throws or
     * silently produces a broken type.
     */
    public static int selectEnumSize(int rawSize) {
        if (rawSize <= 1) return 1;
        if (rawSize <= 2) return 2;
        if (rawSize <= 4) return 4;
        if (rawSize <= 8) return 8;
        return 8; // clamp; Ghidra has no enum type larger than 8 bytes
    }

    // ── Firmware name ────────────────────────────────────────────────────────

    /**
     * Extracts the firmware version string from a Ghidra program name.
     * "J90280.05.full.bin" → "J90280.05", "cm848_rom.bin" → "cm848_rom"
     */
    public static String extractFirmwareName(String programName) {
        return programName
            .replaceAll("\\.full\\.bin$", "")
            .replaceAll("\\.rom\\.bin$",  "")
            .replaceAll("\\.bin$",        "");
    }
}
