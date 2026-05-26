import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.Arrays;
import java.util.List;

class ScriptUtilsTest {

    // ── parseCSVLine ─────────────────────────────────────────────────────────

    @Test void parseCSVLine_simple() {
        assertArrayEquals(new String[]{"a", "b", "c"}, ScriptUtils.parseCSVLine("a,b,c"));
    }

    @Test void parseCSVLine_quotedFieldWithComma() {
        String[] result = ScriptUtils.parseCSVLine("j1939_rx_msg_t,0x40b7ba,\"field,with,commas\",word");
        assertEquals(4, result.length);
        assertEquals("field,with,commas", result[2]);
    }

    @Test void parseCSVLine_emptyField() {
        String[] result = ScriptUtils.parseCSVLine("a,,c");
        assertEquals(3, result.length);
        assertEquals("", result[1]);
    }

    @Test void parseCSVLine_trailingComma() {
        String[] result = ScriptUtils.parseCSVLine("a,b,");
        assertEquals(3, result.length);
        assertEquals("", result[2]);
    }

    @Test void parseCSVLine_singleField() {
        assertArrayEquals(new String[]{"only"}, ScriptUtils.parseCSVLine("only"));
    }

    @Test void parseCSVLine_emptyString() {
        assertArrayEquals(new String[]{""}, ScriptUtils.parseCSVLine(""));
    }

    // ── parseAddress ─────────────────────────────────────────────────────────

    @Test void parseAddress_hexLowerPrefix() {
        assertEquals(0x40b7baL, ScriptUtils.parseAddress("0x40b7ba"));
    }

    @Test void parseAddress_hexUpperPrefix() {
        assertEquals(0x40B7BAL, ScriptUtils.parseAddress("0X40B7BA"));
    }

    @Test void parseAddress_bareHex() {
        assertEquals(0x40b7baL, ScriptUtils.parseAddress("40b7ba"));
    }

    @Test void parseAddress_trimsWhitespace() {
        assertEquals(0x40b7baL, ScriptUtils.parseAddress("  0x40b7ba  "));
    }

    @Test void parseAddress_zero() {
        assertEquals(0L, ScriptUtils.parseAddress("0x00000000"));
    }

    // ── parseIntValue ────────────────────────────────────────────────────────

    @Test void parseIntValue_hexPrefix() {
        assertEquals(255L, ScriptUtils.parseIntValue("0xff"));
    }

    @Test void parseIntValue_decimal() {
        assertEquals(255L, ScriptUtils.parseIntValue("255"));
    }

    @Test void parseIntValue_decimalZero() {
        assertEquals(0L, ScriptUtils.parseIntValue("0"));
    }

    @Test void parseIntValue_hexZero() {
        assertEquals(0L, ScriptUtils.parseIntValue("0x0"));
    }

    @Test void parseIntValue_trimsWhitespace() {
        assertEquals(10L, ScriptUtils.parseIntValue("  10  "));
    }

    // ── isPrimitiveType ───────────────────────────────────────────────────────
    // Bug from commit 84d27a3: "my_struct_t *" was incorrectly treated as primitive

    @Test void isPrimitive_namedPointerIsNotPrimitive() {
        assertFalse(ScriptUtils.isPrimitiveType("j1939_rx_msg_t *"));
        assertFalse(ScriptUtils.isPrimitiveType("tsc1_payload_t *"));
        assertFalse(ScriptUtils.isPrimitiveType("j1939_ack_msg_t *"));
    }

    @Test void isPrimitive_namedPointerCompactFormIsNotPrimitive() {
        assertFalse(ScriptUtils.isPrimitiveType("j1939_rx_msg_t*"));
    }

    @Test void isPrimitive_primitivePointerIsPrimitive() {
        assertTrue(ScriptUtils.isPrimitiveType("byte *"));
        assertTrue(ScriptUtils.isPrimitiveType("word *"));
        assertTrue(ScriptUtils.isPrimitiveType("dword *"));
        assertTrue(ScriptUtils.isPrimitiveType("byte*"));
    }

    @Test void isPrimitive_plainPrimitives() {
        assertTrue(ScriptUtils.isPrimitiveType("byte"));
        assertTrue(ScriptUtils.isPrimitiveType("word"));
        assertTrue(ScriptUtils.isPrimitiveType("dword"));
        assertTrue(ScriptUtils.isPrimitiveType("undefined4"));
        assertTrue(ScriptUtils.isPrimitiveType("undefined"));
    }

    @Test void isPrimitive_namedTypeIsNotPrimitive() {
        assertFalse(ScriptUtils.isPrimitiveType("j1939_rx_msg_t"));
        assertFalse(ScriptUtils.isPrimitiveType("J1939_ACK_TYPE"));
        assertFalse(ScriptUtils.isPrimitiveType("COLD_START_PHASE"));
    }

    @Test void isPrimitive_nullAndEmptyArePrimitive() {
        assertTrue(ScriptUtils.isPrimitiveType(null));
        assertTrue(ScriptUtils.isPrimitiveType(""));
        assertTrue(ScriptUtils.isPrimitiveType("  "));
    }

    @Test void isPrimitive_caseInsensitive() {
        assertTrue(ScriptUtils.isPrimitiveType("BYTE"));
        assertTrue(ScriptUtils.isPrimitiveType("Word"));
        assertTrue(ScriptUtils.isPrimitiveType("DWORD"));
    }

    // ── selectType ───────────────────────────────────────────────────────────
    // Bug from commit 84d27a3: enum/struct names were overwritten by primitive Ghidra types on export

    @Test void selectType_namedGhidraTypeWins() {
        assertEquals("J1939_ACK_TYPE", ScriptUtils.selectType("J1939_ACK_TYPE", "byte"));
    }

    @Test void selectType_namedCsvTypeWinsWhenGhidraReverted() {
        // Ghidra reverted to a primitive; CSV holds the user's named type — keep it
        assertEquals("J1939_ACK_TYPE", ScriptUtils.selectType("byte", "J1939_ACK_TYPE"));
        assertEquals("COLD_START_PHASE", ScriptUtils.selectType("word", "COLD_START_PHASE"));
    }

    @Test void selectType_bothPrimitiveUsesGhidraType() {
        // Ghidra's primitive may have more accurate width info
        assertEquals("word", ScriptUtils.selectType("word", "byte"));
    }

    @Test void selectType_namedPointerInCsvIsPreserved() {
        assertEquals("j1939_rx_msg_t *", ScriptUtils.selectType("byte", "j1939_rx_msg_t *"));
    }

    @Test void selectType_emptyCsvDoesNotOverrideGhidra() {
        assertEquals("word", ScriptUtils.selectType("word", ""));
    }

    // ── isPointerType / stripPointer ─────────────────────────────────────────
    // Bug from commit 3afd499: trailing-* type names fell through to ByteDataType.
    // Inconsistency: some scripts used "struct*", others "struct *" — both must work.

    @Test void isPointer_compactForm() {
        assertTrue(ScriptUtils.isPointerType("tsc1_payload_t*"));
        assertTrue(ScriptUtils.isPointerType("j1939_rx_msg_t*"));
    }

    @Test void isPointer_spacedForm() {
        assertTrue(ScriptUtils.isPointerType("tsc1_payload_t *"));
        assertTrue(ScriptUtils.isPointerType("j1939_rx_msg_t *"));
    }

    @Test void isPointer_primitivePointers() {
        assertTrue(ScriptUtils.isPointerType("byte*"));
        assertTrue(ScriptUtils.isPointerType("byte *"));
        assertTrue(ScriptUtils.isPointerType("word *"));
    }

    @Test void isPointer_nonPointerReturnsFalse() {
        assertFalse(ScriptUtils.isPointerType("tsc1_payload_t"));
        assertFalse(ScriptUtils.isPointerType("byte"));
        assertFalse(ScriptUtils.isPointerType(""));
        assertFalse(ScriptUtils.isPointerType(null));
    }

    @Test void stripPointer_compactForm() {
        assertEquals("tsc1_payload_t", ScriptUtils.stripPointer("tsc1_payload_t*"));
    }

    @Test void stripPointer_spacedForm() {
        assertEquals("tsc1_payload_t", ScriptUtils.stripPointer("tsc1_payload_t *"));
    }

    @Test void stripPointer_primitiveCompact() {
        assertEquals("byte", ScriptUtils.stripPointer("byte*"));
    }

    @Test void stripPointer_primitiveSpaced() {
        assertEquals("byte", ScriptUtils.stripPointer("byte *"));
    }

    // ── extractFirmwareName ───────────────────────────────────────────────────

    @Test void extractFirmwareName_fullBin() {
        assertEquals("J90280.05", ScriptUtils.extractFirmwareName("J90280.05.full.bin"));
    }

    @Test void extractFirmwareName_romBin() {
        assertEquals("cm848_rom", ScriptUtils.extractFirmwareName("cm848_rom.bin"));
    }

    @Test void extractFirmwareName_plainBin() {
        assertEquals("firmware", ScriptUtils.extractFirmwareName("firmware.bin"));
    }

    @Test void extractFirmwareName_noSuffix() {
        assertEquals("J90350.00", ScriptUtils.extractFirmwareName("J90350.00"));
    }

    // ── parseFunctionRenameLine ───────────────────────────────────────────────
    // Verifies that the 3-field limit keeps unquoted commas in plate comments whole.
    // Replacing split(",",3) with parseCSVLine would break this — do not "fix" it.

    @Test void parseFunctionRenameLine_twoFields() {
        String[] r = ScriptUtils.parseFunctionRenameLine("0x00001234,my_func");
        assertEquals(2, r.length);
        assertEquals("0x00001234", r[0]);
        assertEquals("my_func",    r[1]);
    }

    @Test void parseFunctionRenameLine_threeFields() {
        String[] r = ScriptUtils.parseFunctionRenameLine("0x00001234,my_func,plate comment");
        assertEquals(3, r.length);
        assertEquals("plate comment", r[2]);
    }

    @Test void parseFunctionRenameLine_commaInPlateComment_preservedWhole() {
        // If we used line.split(",") without limit, "reads RPM, not torque" would be split.
        String[] r = ScriptUtils.parseFunctionRenameLine("0x00001234,my_func,reads RPM, not torque");
        assertEquals(3, r.length);
        assertEquals("reads RPM, not torque", r[2]);
    }

    @Test void parseFunctionRenameLine_emptyComment() {
        String[] r = ScriptUtils.parseFunctionRenameLine("0x00001234,my_func,");
        assertEquals(3, r.length);
        assertEquals("", r[2]);
    }

    // ── parseGlobalVariableLine ───────────────────────────────────────────────
    // Verifies that the 4-field limit keeps unquoted commas in comments whole,
    // and that the type field (index 2) is never corrupted by a comma in the comment.

    @Test void parseGlobalVariableLine_twoFields() {
        String[] r = ScriptUtils.parseGlobalVariableLine("0x0040b7ba,engine_rpm");
        assertEquals(2, r.length);
    }

    @Test void parseGlobalVariableLine_threeFields() {
        String[] r = ScriptUtils.parseGlobalVariableLine("0x0040b7ba,engine_rpm,dword");
        assertEquals(3, r.length);
        assertEquals("dword", r[2]);
    }

    @Test void parseGlobalVariableLine_fourFields() {
        String[] r = ScriptUtils.parseGlobalVariableLine("0x0040b7ba,engine_rpm,dword,scale factor");
        assertEquals(4, r.length);
        assertEquals("dword",        r[2]);
        assertEquals("scale factor", r[3]);
    }

    @Test void parseGlobalVariableLine_commaInComment_preservedWhole() {
        // split(",", -1) (old ImportAnalysis code) would produce 5 parts here; type at [2]
        // would still be correct but the comment field would be split.
        String[] r = ScriptUtils.parseGlobalVariableLine("0x0040b7ba,engine_rpm,dword,scale: RPM, not torque");
        assertEquals(4, r.length);
        assertEquals("dword",                r[2]);
        assertEquals("scale: RPM, not torque", r[3]);
    }

    @Test void parseGlobalVariableLine_typeFieldUnaffectedByCommaInComment() {
        // Regression guard: the named type must survive even when a comment has commas.
        // This is the exact scenario from ExportAnalysis's re-read phase.
        String[] r = ScriptUtils.parseGlobalVariableLine("0x0040b7ba,engine_rpm,J1939_ACK_TYPE,some, comment");
        assertEquals("J1939_ACK_TYPE", r[2]);
    }

    // ── calculateArrayCount ───────────────────────────────────────────────────
    // Bug: old ApplyStructures code used size/dt.getLength() (integer division),
    // silently truncating the last bytes when size is not evenly divisible.

    @Test void calculateArrayCount_exactDivisible() {
        assertEquals(3, ScriptUtils.calculateArrayCount(6, 2));
        assertEquals(4, ScriptUtils.calculateArrayCount(8, 2));
        assertEquals(2, ScriptUtils.calculateArrayCount(8, 4));
    }

    @Test void calculateArrayCount_notDivisible_returnsNegOne() {
        // Old code: 5/2 = 2 (array of 4 bytes), silently dropping 1 byte.
        assertEquals(-1, ScriptUtils.calculateArrayCount(5, 2));
        assertEquals(-1, ScriptUtils.calculateArrayCount(7, 4));
        assertEquals(-1, ScriptUtils.calculateArrayCount(3, 2));
    }

    @Test void calculateArrayCount_byteBase_alwaysDivisible() {
        // byte (size 1) divides everything — fallback-to-byte-array path never needed
        assertEquals(7, ScriptUtils.calculateArrayCount(7, 1));
        assertEquals(5, ScriptUtils.calculateArrayCount(5, 1));
    }

    @Test void calculateArrayCount_zeroBaseSize_returnsNegOne() {
        assertEquals(-1, ScriptUtils.calculateArrayCount(5, 0));
    }

    @Test void calculateArrayCount_negativeBaseSize_returnsNegOne() {
        assertEquals(-1, ScriptUtils.calculateArrayCount(5, -1));
    }

    // ── selectEnumSize ────────────────────────────────────────────────────────
    // Bug: comment said "1, 2, 4, or 8 bytes" but clamp allowed 3, 5, 6, 7 through to Ghidra.

    @Test void selectEnumSize_zero_clampsTo1() {
        assertEquals(1, ScriptUtils.selectEnumSize(0));
    }

    @Test void selectEnumSize_negative_clampsTo1() {
        assertEquals(1, ScriptUtils.selectEnumSize(-1));
    }

    @Test void selectEnumSize_1_returns1() {
        assertEquals(1, ScriptUtils.selectEnumSize(1));
    }

    @Test void selectEnumSize_2_returns2() {
        assertEquals(2, ScriptUtils.selectEnumSize(2));
    }

    @Test void selectEnumSize_3_roundsUpTo4() {
        // Was the bug: old clamp returned 3, which Ghidra rejects
        assertEquals(4, ScriptUtils.selectEnumSize(3));
    }

    @Test void selectEnumSize_4_returns4() {
        assertEquals(4, ScriptUtils.selectEnumSize(4));
    }

    @Test void selectEnumSize_5_roundsUpTo8() {
        assertEquals(8, ScriptUtils.selectEnumSize(5));
    }

    @Test void selectEnumSize_6_roundsUpTo8() {
        assertEquals(8, ScriptUtils.selectEnumSize(6));
    }

    @Test void selectEnumSize_7_roundsUpTo8() {
        assertEquals(8, ScriptUtils.selectEnumSize(7));
    }

    @Test void selectEnumSize_8_returns8() {
        assertEquals(8, ScriptUtils.selectEnumSize(8));
    }

    @Test void selectEnumSize_above8_clampsTo8() {
        assertEquals(8, ScriptUtils.selectEnumSize(9));
        assertEquals(8, ScriptUtils.selectEnumSize(100));
    }
}
