import static org.junit.jupiter.api.Assertions.assertEquals;

import java.util.List;

import org.junit.jupiter.api.Test;

class BitfieldPieceRewriterTest {

    // faults: word at offset 2 holds one-bit fields bit0..bit15, the word at offset 4 holds a 2-bit field at bits 4-5
    // and a 1-bit field at bit 0; plain: the word at offset 0 is not bitfields.
    private static final BitfieldPieceRewriter.FieldLayout LAYOUT = (symbol, offset, size) -> {
        if (!symbol.startsWith("faults") || size != 2) {
            return null;
        }
        if (offset == 2) {
            return java.util.stream.IntStream.range(0, 16)
                .mapToObj(i -> new BitfieldPieceRewriter.Field("bit" + i, i, 1)).toList();
        }
        if (offset == 4) {
            return List.of(new BitfieldPieceRewriter.Field("pair", 4, 2), new BitfieldPieceRewriter.Field("low", 0, 1));
        }
        return null;
    };

    private static String rewrite(String code) {
        return new BitfieldPieceRewriter(LAYOUT).rewrite(code);
    }

    @Test
    void setWriteNamesEachField() {
        assertEquals("    faults_a.bit5 = 1;", rewrite("    faults_a._2_2_ = faults_a._2_2_ | 0x20;"));
        assertEquals("  faults_a.bit6 = 1;\n  faults_a.bit9 = 1;",
            rewrite("  faults_a._2_2_ = faults_a._2_2_ | 0x240;"));
        assertEquals("faults_a.bit2 = 1;", rewrite("faults_a._2_2_ = faults_a._2_2_ | 4;"));
        assertEquals("    faults_a.bit4 = 0;", rewrite("    faults_a._2_2_ =\n         faults_a._2_2_ & 0xffef;"));
        assertEquals("  faults_a.bit4 = 0;\n  faults_a.bit5 = 1;",
            rewrite("  faults_a._2_2_ = faults_a._2_2_ & 0xffef | 0x20;"));
        assertEquals("faults_b._4_2_ = faults_b._4_2_ & 0xffcf | 0x10;",
            rewrite("faults_b._4_2_ = faults_b._4_2_ & 0xffcf | 0x10;"));
    }

    @Test
    void clearWriteNamesEachClearedField() {
        assertEquals("  faults_a.bit15 = 0;", rewrite("  faults_a._2_2_ = faults_a._2_2_ & 0x7fff;"));
        assertEquals("faults_a.bit4 = 0;\nfaults_a.bit5 = 0;", rewrite("faults_a._2_2_ = faults_a._2_2_ & 0xffcf;"));
    }

    @Test
    void multiBitFieldOnlyWhenWhollyCovered() {
        assertEquals("faults_a.pair = 3;", rewrite("faults_a._4_2_ = faults_a._4_2_ | 0x30;"));
        assertEquals("faults_a.pair = 0;", rewrite("faults_a._4_2_ = faults_a._4_2_ & 0xffcf;"));
        String partial = "faults_a._4_2_ = faults_a._4_2_ | 0x10;";
        assertEquals(partial, rewrite(partial));
        String unnamedBits = "faults_a._4_2_ = faults_a._4_2_ | 0x2;";
        assertEquals(unnamedBits, rewrite(unnamedBits));
    }

    @Test
    void leavesOtherShapesAlone() {
        String[] unchanged = {
            "plain._0_2_ = plain._0_2_ | 0x20;",
            "faults_a._0_2_ = faults_a._0_2_ | 0x20;",
            "faults_a._2_2_ = faults_b._2_2_ | 0x20;",
            "faults_a._2_2_ = uVar1;",
            "uVar1 = faults_a._2_2_ & 0xffef | 0x20;",
            "x.faults_a._2_2_ = x.faults_a._2_2_ | 0x20;",
            "if ((faults_a._2_2_ & 0x100) != 1) {",
            "if ((faults_a._2_2_ & 0x300) != 0) {",
            "flag = faults_a._2_2_ & 0x8000;",
        };
        for (String line : unchanged) {
            assertEquals(line, rewrite(line));
        }
    }

    @Test
    void zeroAndPairTests() {
        assertEquals("if (faults_a.bit8 != 0) {", rewrite("if ((faults_a._2_2_ & 0x100) != 0) {"));
        assertEquals("if (faults_a.bit0 == 0) {", rewrite("if ((faults_a._2_2_ & 1) == 0) {"));
        assertEquals("if ((faults_a.bit5 == faults_prev.bit5) &&",
            rewrite("if (((faults_a._2_2_ & 0x20) == (faults_prev._2_2_ & 0x20)) &&"));
        assertEquals("faults_a.bit5 != faults_prev.bit5",
            rewrite("(faults_a._2_2_ & 0x20) != (faults_prev._2_2_ & 0x20)"));
    }

    @Test
    void countsRewrites() {
        BitfieldPieceRewriter r = new BitfieldPieceRewriter(LAYOUT);
        r.rewrite("faults_a._2_2_ = faults_a._2_2_ | 0x240;\nfaults_a._0_2_ = faults_a._0_2_ | 1;\n");
        assertEquals(1, r.rewrites());
    }
}
