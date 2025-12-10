#!/bin/bash
# Simple batch decompiler for .NET DLLs

CALTERM_DIR="/home/jlaustill/Software/Calterm III"
OUTPUT_DIR="/home/jlaustill/Software/calterm-crc/decompiled/dotnet"
ILSPYCMD="$HOME/.dotnet/tools/ilspycmd"

mkdir -p "$OUTPUT_DIR"

total=$(ls "$CALTERM_DIR"/*.dll 2>/dev/null | wc -l)
echo "Found $total DLLs"

count=0
ok=0
fail=0
skip=0

for dll in "$CALTERM_DIR"/*.dll; do
    count=$((count + 1))
    name=$(basename "${dll%.dll}")

    # Skip runtime DLLs
    case "$name" in
        atl110|msvcp110|msvcr110)
            echo "[$count/$total] SKIP: $name (runtime)"
            skip=$((skip + 1))
            continue
            ;;
    esac

    # Check if .NET
    if ! file "$dll" | grep -q "Mono/.Net"; then
        skip=$((skip + 1))
        continue
    fi

    outfile="$OUTPUT_DIR/${name}.cs"

    # Skip if exists
    if [ -f "$outfile" ]; then
        echo "[$count/$total] EXISTS: $name"
        continue
    fi

    # Decompile
    if $ILSPYCMD "$dll" > "$outfile" 2>/dev/null; then
        size=$(du -h "$outfile" | cut -f1)
        echo "[$count/$total] OK: $name ($size)"
        ok=$((ok + 1))
    else
        echo "[$count/$total] FAIL: $name"
        rm -f "$outfile"
        fail=$((fail + 1))
    fi
done

echo ""
echo "=== Summary ==="
echo "OK: $ok"
echo "Failed: $fail"
echo "Skipped: $skip"
echo "Output: $OUTPUT_DIR"
