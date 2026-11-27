// Bitfield piece rewriter: prints Ghidra's whole-word read-modify-writes of struct bitfields by their field names.
// Pure Java (no Ghidra imports) so firmware/script_tests can test it; ExportAnalysis supplies the field layout.
//
// Ghidra 12.1 names a bitfield when it is read or when a whole storage unit is stored, but not in a
// read-modify-write, which it prints as a piece of the struct:
//     fault_detected_cal._48_2_ = fault_detected_cal._48_2_ | 0x20;
// Each rewrite below is exact; anything else is left as Ghidra printed it:
// - `S._o_n_ = S._o_n_ | K;` (also wrapped after the `=`) becomes one `S.field = <all ones>;` line per field, when the bits of K are exactly
//   whole bitfields of S's n-byte unit at byte offset o.
// - `S._o_n_ = S._o_n_ & K;` becomes one `S.field = 0;` line per field cleared by K, under the same condition.
// - `(S._o_n_ & K) == 0` / `!= 0` becomes `S.field == 0` / `!= 0` when K is exactly one field.
// - `(S._o_n_ & K) == (T._o_n_ & K)` (or `!=`) becomes `S.field == T.field` when K is one field and the field has
//   the same name in T.

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public final class BitfieldPieceRewriter {

    /** One bitfield of an n-byte unit; lsb counts from the unit's least significant bit. */
    public static final class Field {
        final String name;
        final int lsb;
        final int bits;

        public Field(String name, int lsb, int bits) {
            this.name = name;
            this.lsb = lsb;
            this.bits = bits;
        }

        long mask() {
            return ((1L << bits) - 1) << lsb;
        }
    }

    /** The bitfields that lie wholly inside {@code symbol}'s {@code size}-byte unit at byte {@code offset}. */
    public interface FieldLayout {
        List<Field> fields(String symbol, int offset, int size);
    }

    private static final String ID = "(?<![\\w.>])([A-Za-z_][A-Za-z0-9_]*)";
    private static final String CONST = "(0x[0-9a-fA-F]+|\\d+)";

    private static final Pattern WRITE = Pattern.compile(
        "^([ \\t]*)" + ID + "\\._(\\d+)_(\\d+)_ =(?: |\\n[ \\t]*)\\2\\._\\3_\\4_ ([|&]) " + CONST + ";$", Pattern.MULTILINE);
    private static final Pattern CLEAR_SET = Pattern.compile(
        "^([ \\t]*)" + ID + "\\._(\\d+)_(\\d+)_ =(?: |\\n[ \\t]*)\\2\\._\\3_\\4_ & " + CONST + " \\| " + CONST + ";$",
        Pattern.MULTILINE);
    private static final Pattern PAIR_TEST = Pattern.compile(
        "\\(" + ID + "\\._(\\d+)_(\\d+)_ & " + CONST + "\\) (==|!=) \\(" + ID + "\\._\\2_\\3_ & \\4\\)");
    private static final Pattern ZERO_TEST = Pattern.compile(
        "\\(" + ID + "\\._(\\d+)_(\\d+)_ & " + CONST + "\\) (==|!=) 0(?![\\w.])");

    private final FieldLayout layout;
    private int rewrites;

    public BitfieldPieceRewriter(FieldLayout layout) {
        this.layout = layout;
    }

    /** The number of piece expressions rewritten so far. */
    public int rewrites() {
        return rewrites;
    }

    public String rewrite(String code) {
        if (code.indexOf("_ ") < 0) {
            return code;
        }
        code = rewriteWrites(code);
        code = rewriteClearSets(code);
        code = rewritePairTests(code);
        return rewriteZeroTests(code);
    }

    private String rewriteWrites(String code) {
        Matcher m = WRITE.matcher(code);
        StringBuilder out = new StringBuilder();
        while (m.find()) {
            String indent = m.group(1);
            String symbol = m.group(2);
            int offset = Integer.parseInt(m.group(3));
            int size = Integer.parseInt(m.group(4));
            boolean set = m.group(5).equals("|");
            long unit = unitMask(size);
            long k = parse(m.group(6));
            long touched = set ? k : ~k & unit;
            List<Field> fields = covering(symbol, offset, size, touched, unit, k);
            String replacement = m.group(0);
            if (fields != null) {
                StringBuilder lines = new StringBuilder();
                for (Field f : fields) {
                    if (lines.length() > 0) {
                        lines.append('\n');
                    }
                    long value = set ? (1L << f.bits) - 1 : 0;
                    lines.append(indent).append(symbol).append('.').append(f.name).append(" = ")
                        .append(value < 10 ? Long.toString(value) : "0x" + Long.toHexString(value)).append(';');
                }
                replacement = lines.toString();
                rewrites++;
            }
            m.appendReplacement(out, Matcher.quoteReplacement(replacement));
        }
        m.appendTail(out);
        return out.toString();
    }

    private String rewriteClearSets(String code) {
        Matcher m = CLEAR_SET.matcher(code);
        StringBuilder out = new StringBuilder();
        while (m.find()) {
            String indent = m.group(1);
            String symbol = m.group(2);
            int offset = Integer.parseInt(m.group(3));
            int size = Integer.parseInt(m.group(4));
            long unit = unitMask(size);
            long keep = parse(m.group(5));
            long set = parse(m.group(6));
            long cleared = ~keep & ~set & unit;
            List<Field> zeros = cleared == 0 ? new ArrayList<>() : covering(symbol, offset, size, cleared, unit, keep);
            List<Field> ones = covering(symbol, offset, size, set, unit, set);
            String replacement = m.group(0);
            if (zeros != null && ones != null && (keep & ~unit) == 0) {
                StringBuilder lines = new StringBuilder();
                for (Field f : zeros) {
                    lines.append(indent).append(symbol).append('.').append(f.name).append(" = 0;\n");
                }
                for (Field f : ones) {
                    long value = (1L << f.bits) - 1;
                    lines.append(indent).append(symbol).append('.').append(f.name).append(" = ")
                        .append(value < 10 ? Long.toString(value) : "0x" + Long.toHexString(value)).append(";\n");
                }
                replacement = lines.substring(0, lines.length() - 1);
                rewrites++;
            }
            m.appendReplacement(out, Matcher.quoteReplacement(replacement));
        }
        m.appendTail(out);
        return out.toString();
    }

    private String rewritePairTests(String code) {
        Matcher m = PAIR_TEST.matcher(code);
        StringBuilder out = new StringBuilder();
        while (m.find()) {
            int offset = Integer.parseInt(m.group(2));
            int size = Integer.parseInt(m.group(3));
            long k = parse(m.group(4));
            Field left = single(m.group(1), offset, size, k);
            Field right = single(m.group(6), offset, size, k);
            String replacement = m.group(0);
            if (left != null && right != null && left.name.equals(right.name)) {
                replacement = m.group(1) + "." + left.name + " " + m.group(5) + " " + m.group(6) + "." + right.name;
                rewrites++;
            }
            m.appendReplacement(out, Matcher.quoteReplacement(replacement));
        }
        m.appendTail(out);
        return out.toString();
    }

    private String rewriteZeroTests(String code) {
        Matcher m = ZERO_TEST.matcher(code);
        StringBuilder out = new StringBuilder();
        while (m.find()) {
            Field f = single(m.group(1), Integer.parseInt(m.group(2)), Integer.parseInt(m.group(3)),
                parse(m.group(4)));
            String replacement = m.group(0);
            if (f != null) {
                replacement = m.group(1) + "." + f.name + " " + m.group(5) + " 0";
                rewrites++;
            }
            m.appendReplacement(out, Matcher.quoteReplacement(replacement));
        }
        m.appendTail(out);
        return out.toString();
    }

    /** The fields whose bits are exactly {@code touched}, lowest first; null if no exact cover exists. */
    private List<Field> covering(String symbol, int offset, int size, long touched, long unit, long k) {
        if (size < 1 || size > 4 || touched == 0 || (k & ~unit) != 0) {
            return null;
        }
        List<Field> fields = layout.fields(symbol, offset, size);
        if (fields == null) {
            return null;
        }
        List<Field> chosen = new ArrayList<>();
        long covered = 0;
        for (Field f : fields) {
            long fm = f.mask();
            if ((fm & touched) == 0) {
                continue;
            }
            if ((fm & touched) != fm || (fm & covered) != 0) {
                return null;
            }
            covered |= fm;
            chosen.add(f);
        }
        if (covered != touched) {
            return null;
        }
        chosen.sort((a, b) -> Integer.compare(a.lsb, b.lsb));
        return chosen;
    }

    private Field single(String symbol, int offset, int size, long k) {
        List<Field> fields = covering(symbol, offset, size, k, unitMask(size), k);
        return fields != null && fields.size() == 1 ? fields.get(0) : null;
    }

    private static long unitMask(int size) {
        return size >= 1 && size <= 4 ? (1L << (8 * size)) - 1 : 0;
    }

    private static long parse(String constant) {
        return constant.startsWith("0x") || constant.startsWith("0X")
            ? Long.parseLong(constant.substring(2), 16)
            : Long.parseLong(constant);
    }
}
