#!/bin/bash
# Extract Access databases to CSV using mdbtools

INSITE_DIR="/home/jlaustill/code/kuminz-re/insite9"
OUTPUT_DIR="/home/jlaustill/code/kuminz-re/insite9/decompiled/databases"

mkdir -p "$OUTPUT_DIR"

extract_mdb() {
    local db="$1"

    if [ ! -f "$db" ]; then
        echo "ERROR: File not found: $db"
        return 1
    fi

    local name=$(basename "${db%.*}")
    local outdir="$OUTPUT_DIR/$name"
    mkdir -p "$outdir"

    echo "=== Extracting: $name ==="
    echo "    Source: $db"
    echo "    Output: $outdir"
    echo ""

    # Schema
    echo "  Extracting schema..."
    mdb-schema "$db" > "$outdir/schema.sql" 2>/dev/null

    # Get table list
    local tables=$(mdb-tables -1 "$db" 2>/dev/null)
    local table_count=$(echo "$tables" | wc -l)
    echo "  Found $table_count tables"
    echo ""

    # Export each table
    local count=0
    while IFS= read -r table; do
        [ -z "$table" ] && continue
        count=$((count + 1))

        # Sanitize table name for filename
        local safe_table=$(echo "$table" | tr ' /' '_')
        local outfile="$outdir/${safe_table}.csv"

        if mdb-export "$db" "$table" > "$outfile" 2>/dev/null; then
            local rows=$(wc -l < "$outfile")
            rows=$((rows - 1))  # Subtract header
            [ $rows -lt 0 ] && rows=0
            echo "    [$count/$table_count] $table ($rows rows)"
        else
            echo "    [$count/$table_count] $table (FAILED)"
            rm -f "$outfile"
        fi
    done <<< "$tables"

    echo ""
    echo "  Done: $outdir"
    echo ""
}

echo "============================================"
echo "Insite Database Extraction"
echo "============================================"
echo ""

# Process all known databases
extract_mdb "$INSITE_DIR/FnPDatabase.mdb"
extract_mdb "$INSITE_DIR/Help/INSITEHelp.mdb"
extract_mdb "$INSITE_DIR/Metadata.accdb"

echo "============================================"
echo "Extraction complete!"
echo "Output directory: $OUTPUT_DIR"
echo "============================================"
