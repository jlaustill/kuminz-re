import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.Arrays;
import java.util.List;

class CsvCommentIndexTest {

    private static List<String> lines(String... lines) {
        return Arrays.asList(lines);
    }

    // ── No comments ───────────────────────────────────────────────────────────

    @Test void noComments_allListsEmpty() {
        CsvCommentIndex idx = CsvCommentIndex.fromLines(lines(
            "address,name",
            "0x00001234,foo",
            "0x00005678,bar"
        ));
        assertTrue(idx.getHeaderComments().isEmpty());
        assertTrue(idx.getCommentsBefore("0x00001234").isEmpty());
        assertTrue(idx.getTrailingComments().isEmpty());
    }

    @Test void emptyFile_allListsEmpty() {
        CsvCommentIndex idx = CsvCommentIndex.fromLines(lines());
        assertTrue(idx.getHeaderComments().isEmpty());
        assertTrue(idx.getTrailingComments().isEmpty());
    }

    // ── Header comments ───────────────────────────────────────────────────────

    @Test void headerComments_capturedBeforeCsvHeader() {
        CsvCommentIndex idx = CsvCommentIndex.fromLines(lines(
            "# This file documents J1939 types",
            "# Do not edit manually",
            "address,name",
            "0x00001234,foo"
        ));
        assertEquals(
            List.of("# This file documents J1939 types", "# Do not edit manually"),
            idx.getHeaderComments()
        );
        assertTrue(idx.getCommentsBefore("0x00001234").isEmpty());
    }

    // ── Per-row comments ──────────────────────────────────────────────────────

    @Test void rowComment_keyedByFirstField() {
        CsvCommentIndex idx = CsvCommentIndex.fromLines(lines(
            "address,name",
            "0x00001234,foo",
            "# J1939 receive message struct",
            "# 18 bytes per slot",
            "0x00405678,j1939_rx_msg_t"
        ));
        assertEquals(
            List.of("# J1939 receive message struct", "# 18 bytes per slot"),
            idx.getCommentsBefore("0x00405678")
        );
        assertTrue(idx.getCommentsBefore("0x00001234").isEmpty());
    }

    @Test void rowComment_missingKeyReturnsEmptyList() {
        CsvCommentIndex idx = CsvCommentIndex.fromLines(lines(
            "address,name",
            "0x00001234,foo"
        ));
        assertTrue(idx.getCommentsBefore("0x99999999").isEmpty());
        assertTrue(idx.getCommentsBefore("").isEmpty());
    }

    // ── Trailing comments ─────────────────────────────────────────────────────

    @Test void trailingComments_capturedAfterLastRow() {
        CsvCommentIndex idx = CsvCommentIndex.fromLines(lines(
            "address,name",
            "0x00001234,foo",
            "# end of file marker",
            "# generated 2026-05-26"
        ));
        assertEquals(
            List.of("# end of file marker", "# generated 2026-05-26"),
            idx.getTrailingComments()
        );
    }

    // ── Mixed ─────────────────────────────────────────────────────────────────

    @Test void allThreePositions_preservedIndependently() {
        CsvCommentIndex idx = CsvCommentIndex.fromLines(lines(
            "# header comment",
            "address,name",
            "# before foo",
            "0x00001234,foo",
            "# before bar",
            "0x00005678,bar",
            "# trailing"
        ));
        assertEquals(List.of("# header comment"),  idx.getHeaderComments());
        assertEquals(List.of("# before foo"),       idx.getCommentsBefore("0x00001234"));
        assertEquals(List.of("# before bar"),       idx.getCommentsBefore("0x00005678"));
        assertEquals(List.of("# trailing"),         idx.getTrailingComments());
    }

    @Test void commentsOnlyFile_allGoToHeader() {
        // Degenerate case: a file that's all comments and no data rows
        CsvCommentIndex idx = CsvCommentIndex.fromLines(lines(
            "# just comments",
            "# nothing else"
        ));
        // No non-# line was ever seen, so pastHeader never became true — all pending
        // comments at EOF end up as trailing comments (never assigned to header).
        assertEquals(List.of("# just comments", "# nothing else"), idx.getTrailingComments());
        assertTrue(idx.getHeaderComments().isEmpty());
    }

    @Test void headerComments_returnedListIsUnmodifiable() {
        CsvCommentIndex idx = CsvCommentIndex.fromLines(lines(
            "# comment",
            "address,name"
        ));
        assertThrows(UnsupportedOperationException.class,
            () -> idx.getHeaderComments().add("# injected"));
    }

    @Test void trailingComments_returnedListIsUnmodifiable() {
        CsvCommentIndex idx = CsvCommentIndex.fromLines(lines(
            "address,name",
            "# trailing"
        ));
        assertThrows(UnsupportedOperationException.class,
            () -> idx.getTrailingComments().add("# injected"));
    }
}
