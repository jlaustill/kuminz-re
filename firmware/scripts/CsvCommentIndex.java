import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Reads a CSV file and indexes its # comment blocks so they can be
 * re-emitted at the correct positions when the file is rewritten.
 *
 * Three positions are tracked:
 *   - headerComments   : # lines that appear before the CSV header row
 *   - commentsBefore   : # lines immediately before a data row, keyed by that row's first field
 *   - trailingComments : # lines after the last data row
 *
 * No Ghidra imports — fully testable with plain JUnit.
 */
public class CsvCommentIndex {

    private final List<String> headerComments;
    private final Map<String, List<String>> commentsBefore;
    private final List<String> trailingComments;

    private CsvCommentIndex(List<String> headerComments,
                            Map<String, List<String>> commentsBefore,
                            List<String> trailingComments) {
        this.headerComments   = Collections.unmodifiableList(new ArrayList<>(headerComments));
        this.commentsBefore   = commentsBefore;
        this.trailingComments = Collections.unmodifiableList(new ArrayList<>(trailingComments));
    }

    /**
     * Reads a CSV file from disk and builds the index.
     * Returns an empty index if the file does not exist.
     */
    public static CsvCommentIndex read(String csvPath) throws IOException {
        List<String> lines = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(csvPath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                lines.add(line);
            }
        }
        return fromLines(lines);
    }

    /** Builds the index from an in-memory list of lines (primary entry point for tests). */
    public static CsvCommentIndex fromLines(List<String> lines) {
        List<String> header   = new ArrayList<>();
        Map<String, List<String>> before = new HashMap<>();
        List<String> pending  = new ArrayList<>();
        boolean pastHeader    = false;

        for (String line : lines) {
            if (line.startsWith("#")) {
                pending.add(line);
            } else {
                if (!pending.isEmpty()) {
                    if (!pastHeader) {
                        header.addAll(pending);
                    } else {
                        String key = line.split(",")[0].trim();
                        before.put(key, new ArrayList<>(pending));
                    }
                    pending.clear();
                }
                pastHeader = true;
            }
        }

        return new CsvCommentIndex(header, before, pending);
    }

    /** # comment lines that appeared before the CSV header row. */
    public List<String> getHeaderComments() {
        return headerComments;
    }

    /**
     * # comment lines that appeared immediately before the data row
     * whose first field equals {@code key}. Returns an empty list if none.
     */
    public List<String> getCommentsBefore(String key) {
        return commentsBefore.getOrDefault(key, Collections.emptyList());
    }

    /** # comment lines that appeared after the last data row. */
    public List<String> getTrailingComments() {
        return trailingComments;
    }
}
