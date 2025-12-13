#!/bin/bash
# Batch decompile .NET DLLs from insite9

INSITE_DIR="/home/jlaustill/code/kuminz-re/insite9"
OUTPUT_DIR="/home/jlaustill/code/kuminz-re/insite9/decompiled/dotnet"
ILSPYCMD="$HOME/.dotnet/tools/ilspycmd"

mkdir -p "$OUTPUT_DIR"

total=$(find "$INSITE_DIR" -maxdepth 1 -name "*.dll" -exec file {} \; | grep -c "Mono/.Net")
echo "Found $total .NET DLLs to process"
echo ""

count=0
ok=0
fail=0
skip=0

for dll in "$INSITE_DIR"/*.dll; do
    [ -f "$dll" ] || continue
    name=$(basename "${dll%.dll}")

    # Skip if not .NET
    if ! file "$dll" | grep -q "Mono/.Net"; then
        continue
    fi

    count=$((count + 1))
    outfile="$OUTPUT_DIR/${name}.cs"

    # Skip if exists
    if [ -f "$outfile" ]; then
        echo "[$count/$total] EXISTS: $name"
        skip=$((skip + 1))
        continue
    fi

    if $ILSPYCMD "$dll" > "$outfile" 2>/dev/null; then
        size=$(du -h "$outfile" | cut -f1)
        echo "[$count/$total] OK: $name ($size)"
        ok=$((ok + 1))
    else
        rm -f "$outfile"
        echo "[$count/$total] FAIL: $name"
        fail=$((fail + 1))
    fi
done

echo ""
echo "=== Summary ==="
echo "OK: $ok"
echo "Failed: $fail"
echo "Skipped (already exist): $skip"
echo "Total .NET: $count"
echo "Output: $OUTPUT_DIR"
