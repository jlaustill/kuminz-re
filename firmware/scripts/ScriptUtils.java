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

    // ── Function-definition parameter reconciliation ─────────────────────────

    /** Outcome of comparing CSV-defined params against Ghidra's decompiler-recovered params. */
    public enum ParamReconciliation {
        /** Counts agree (or both zero) — apply the definition as written. */
        OK,
        /** CSV defines params but the count differs from Ghidra's — may be a legit override; warn and proceed. */
        WARN_MISMATCH,
        /**
         * CSV defines NO params but Ghidra recovered some — committing a return type would
         * silently strip those arguments. Preserve the recovered params instead.
         */
        PRESERVE_DETECTED
    }

    /**
     * Decides how to handle a function definition given the number of parameter rows in the
     * CSV ({@code definedCount}) versus the number the decompiler recovered ({@code detectedCount}).
     *
     * Committing any prototype element (return type / calling convention) turns OFF Ghidra's
     * dynamic parameter inference, so a return-only row (definedCount==0) on a function whose
     * args were only ever inferred (detectedCount>0) collapses the signature to {@code (void)}
     * and drops the call-site arguments. PRESERVE_DETECTED flags that case so the caller can
     * carry the recovered params into the committed signature.
     */
    public static ParamReconciliation reconcileParams(int definedCount, int detectedCount) {
        if (definedCount == 0) {
            return detectedCount > 0 ? ParamReconciliation.PRESERVE_DETECTED
                                     : ParamReconciliation.OK;
        }
        return definedCount == detectedCount ? ParamReconciliation.OK
                                             : ParamReconciliation.WARN_MISMATCH;
    }

    /**
     * The param_index literal of a function_definitions.csv row that declares an EMPTY parameter list.
     *
     * A return-only row keeps the parameters the decompiler recovers (PRESERVE_DETECTED), which is right for a
     * function nobody has studied. It is wrong for a function that is known to take none but reads its argument
     * registers anyway: an exception handler saves r3 / r4 like every volatile register, and the decompiler shows
     * that as two parameters. The 'none' row commits the empty list.
     */
    public static final String NO_PARAMETERS_ROW = "none";

    /**
     * A 'none' row and positional rows contradict each other. Returns the problem text for the build log, or null
     * when the rows of one function agree ({@code definedCount} = highest positional index + 1; 0 without any).
     */
    public static String noParametersRowProblem(boolean hasNoParametersRow, int definedCount) {
        if (hasNoParametersRow && definedCount > 0) {
            return "a '" + NO_PARAMETERS_ROW + "' row (no parameters) next to " + definedCount + " parameter row(s)";
        }
        return null;
    }

    // ── CSV row parsers ──────────────────────────────────────────────────────

    /**
     * Splits a function_renames.csv data row into [address, name, plateComment].
     * plateComment is the 3rd column and may contain unquoted commas — split(",", 3)
     * absorbs everything from the 3rd delimiter onward into a single field.
     */
    public static String[] parseFunctionRenameLine(String line) {
        return line.split(",", 3);
    }

    /**
     * Splits a global_variables.csv data row into [address, name, type, comment].
     * comment is the 4th column and may contain unquoted commas — split(",", 4)
     * absorbs everything from the 4th delimiter onward into a single field.
     */
    public static String[] parseGlobalVariableLine(String line) {
        return line.split(",", 4);
    }

    // ── Array count ──────────────────────────────────────────────────────────

    /**
     * Returns the element count for an array field, or -1 if {@code fieldSize}
     * is not evenly divisible by {@code baseTypeSize}.
     *
     * Callers should fall back to a byte array when -1 is returned rather than
     * using integer-truncated division, which silently drops trailing bytes.
     */
    public static int calculateArrayCount(int fieldSize, int baseTypeSize) {
        if (baseTypeSize <= 0) return -1;
        if (fieldSize % baseTypeSize != 0) return -1;
        return fieldSize / baseTypeSize;
    }

    // ── Array type syntax ────────────────────────────────────────────────────

    /** The element type name and element count of a CSV array type such as {@code word[10]}. */
    public static final class ArrayTypeSpec {
        public final String elementType;
        public final int count;

        ArrayTypeSpec(String elementType, int count) {
            this.elementType = elementType;
            this.count = count;
        }
    }

    private static final java.util.regex.Pattern ARRAY_TYPE =
            java.util.regex.Pattern.compile("^\\s*([A-Za-z_][A-Za-z0-9_]*(?:\\s*\\*)?)\\s*\\[\\s*(\\d+)\\s*\\]\\s*$");

    /**
     * True for the global_variables.csv types the importer leaves to Ghidra on purpose
     * (blank, {@code undefined}, {@code undefined *}): they are neither applied nor reported.
     * Any other type the importer cannot map is reported, so a typo never vanishes silently.
     */
    public static boolean isIgnoredGlobalType(String typeStr) {
        if (typeStr == null) return true;
        String t = typeStr.trim().toLowerCase();
        return t.isEmpty() || t.equals("undefined") || t.equals("undefined *");
    }

    /**
     * Parses a CSV array type {@code <element>[<count>]} — {@code word[10]}, {@code byte[17]},
     * {@code my_struct_t[4]}, or an array of pointers such as {@code fault_entry_t *[8]} (the element
     * keeps its {@code *}, so the caller's pointer mapping resolves it). Returns null when the string is
     * not an array type or the count is not positive, so callers can fall through to their scalar type
     * mapping.
     */
    public static ArrayTypeSpec parseArrayType(String typeStr) {
        if (typeStr == null) return null;
        java.util.regex.Matcher m = ARRAY_TYPE.matcher(typeStr);
        if (!m.matches()) return null;
        int count;
        try {
            count = Integer.parseInt(m.group(2));
        } catch (NumberFormatException e) {
            return null;
        }
        if (count <= 0) return null;
        return new ArrayTypeSpec(m.group(1), count);
    }

    // ── Function type syntax ─────────────────────────────────────────────────

    /** The return type and the parameters ({type, name} each) of a structure_definitions.csv function type row. */
    public static final class FunctionTypeSpec {
        public final String returnType;
        public final List<String[]> parameters;

        FunctionTypeSpec(String returnType, List<String[]> parameters) {
            this.returnType = returnType;
            this.parameters = parameters;
        }
    }

    private static final java.util.regex.Pattern FUNCTION_TYPE = java.util.regex.Pattern.compile(
            "^\\s*function:\\s*([A-Za-z_][A-Za-z0-9_]*)((?:\\s*\\*)*)\\s*\\((.*)\\)\\s*$");
    // "<type> <name>": the type and the name are apart by white space or by the type's '*'
    private static final java.util.regex.Pattern FUNCTION_PARAMETER = java.util.regex.Pattern.compile(
            "^\\s*([A-Za-z_][A-Za-z0-9_]*)(?:((?:\\s*\\*)+)\\s*|\\s+)([A-Za-z_][A-Za-z0-9_]*)\\s*$");

    /**
     * Parses a function type {@code function:<return>(<type> <name>;<type> <name>)} - the type column of a
     * structure_definitions.csv row that defines a function type named like the row, which a field or a prototype
     * parameter then holds as {@code <name>*}. Parameters are separated by ';' (the CSV splits on ','), each needs
     * a type and a name, and {@code ()} or {@code (void)} means none. A '*' belongs to the type wherever it is
     * written. Returns null when the string is not a function type or is malformed, so the caller can warn.
     */
    public static FunctionTypeSpec parseFunctionType(String typeStr) {
        if (typeStr == null) return null;
        java.util.regex.Matcher m = FUNCTION_TYPE.matcher(typeStr);
        if (!m.matches()) return null;
        String returnType = m.group(1) + m.group(2).replaceAll("\\s+", "");
        List<String[]> parameters = new ArrayList<>();
        String list = m.group(3).trim();
        if (!list.isEmpty() && !list.equals("void")) {
            for (String part : list.split(";", -1)) {
                java.util.regex.Matcher p = FUNCTION_PARAMETER.matcher(part);
                if (!p.matches()) return null;
                String stars = p.group(2) == null ? "" : p.group(2).replaceAll("\\s+", "");
                parameters.add(new String[] { p.group(1) + stars, p.group(3) });
            }
        }
        return new FunctionTypeSpec(returnType, parameters);
    }

    // ── Stack parameter layout ───────────────────────────────────────────────

    /** A firmware's stack parameter layout (output/stack_parameter_layout.csv). */
    public static final class StackParameterLayout {
        public final String language;
        public final int firstOffset;
        public final int slotSize;

        public StackParameterLayout(String language, int firstOffset, int slotSize) {
            this.language = language;
            this.firstOffset = firstOffset;
            this.slotSize = slotSize;
        }
    }

    /**
     * Parses stack_parameter_layout.csv: blank and '#' lines are skipped, the first other line is the header, and each
     * later row is setting,value[,comment]. It needs language, first_stack_offset (even, not negative) and slot_size
     * (2 or 4). An unknown setting is an error, so a typo cannot pass silently.
     */
    public static StackParameterLayout parseStackParameterLayout(List<String> lines) {
        String language = null;
        Integer first = null;
        Integer slot = null;
        boolean header = true;
        for (String raw : lines) {
            String line = raw.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            if (header) { header = false; continue; }
            String[] parts = parseCSVLine(line);
            if (parts.length < 2) throw new IllegalArgumentException("bad row: " + line);
            String setting = parts[0].trim();
            String value = parts[1].trim();
            switch (setting) {
                case "language": language = value; break;
                case "first_stack_offset": first = Integer.parseInt(value); break;
                case "slot_size": slot = Integer.parseInt(value); break;
                default: throw new IllegalArgumentException("unknown setting '" + setting + "'");
            }
        }
        if (language == null || first == null || slot == null)
            throw new IllegalArgumentException("needs language, first_stack_offset and slot_size");
        if (slot != 2 && slot != 4) throw new IllegalArgumentException("slot_size must be 2 or 4");
        if (first < 0 || first % 2 != 0) throw new IllegalArgumentException("first_stack_offset must be even");
        return new StackParameterLayout(language, first, slot);
    }

    /**
     * Stack offsets for parameters of the given byte lengths, in parameter order: the first starts at firstOffset,
     * each takes ceil(length / slotSize) slots and sits right-justified in them (big-endian: a byte in a 2-byte slot is
     * at slot + 1). There is no padding for a type's alignment (the CM550 compiler puts a long at +6 after a word).
     * slotSize 4 gives 68000.cspec __stdcall's layout (align 4, right-justified) for 1 / 2 / 4 / 8-byte types.
     */
    public static int[] packStackParameters(int[] lengths, int firstOffset, int slotSize) {
        int[] offsets = new int[lengths.length];
        int next = firstOffset;
        for (int i = 0; i < lengths.length; i++) {
            if (lengths[i] <= 0) throw new IllegalArgumentException("parameter " + i + " has no fixed length");
            int space = (lengths[i] + slotSize - 1) / slotSize * slotSize;
            offsets[i] = next + space - lengths[i];
            next += space;
        }
        return offsets;
    }

    // ── Dumps with gaps ──────────────────────────────────────────────────────

    /**
     * Builds a memory image from a dump that is missing some ranges. A dump tool that skipped a failed chunk without
     * padding (clip-core's ECUReader before PR #53 round 88) shifts every later byte down by that chunk; this puts each
     * byte back at its own offset. The image is imageLength bytes: each gap {imageOffset, length} holds fill, and the
     * dump's bytes from dumpStart on fill every other image byte in order. Dump bytes beyond the image are dropped;
     * image bytes the dump does not reach stay fill. A gap that reaches outside the image is clipped.
     */
    public static byte[] imageFromDumpWithGaps(byte[] dump, int dumpStart, int imageLength, int[][] gaps, byte fill) {
        if (dumpStart < 0 || imageLength < 0) throw new IllegalArgumentException("negative dump start or image length");
        byte[] image = new byte[imageLength];
        java.util.Arrays.fill(image, fill);
        boolean[] inGap = new boolean[imageLength];
        for (int[] gap : gaps) {
            if (gap.length != 2 || gap[1] < 0) throw new IllegalArgumentException("a gap is {imageOffset, length}");
            for (int i = Math.max(0, gap[0]); i < Math.min(imageLength, gap[0] + gap[1]); i++) inGap[i] = true;
        }
        int source = dumpStart;
        for (int i = 0; i < imageLength && source < dump.length; i++) {
            if (!inGap[i]) image[i] = dump[source++];
        }
        return image;
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
