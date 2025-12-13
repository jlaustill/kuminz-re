#!/bin/bash
# Batch decompile native DLLs from insite9

INSITE_DIR="/home/jlaustill/code/kuminz-re/insite9"
OUTPUT_DIR="/home/jlaustill/code/kuminz-re/insite9/decompiled/native"
GHIDRA="/opt/ghidra/support/analyzeHeadless"
SCRIPT_DIR="/home/jlaustill/code/kuminz-re/calterm3/calterm-crc/scripts"
TEMP_PROJECT="/tmp/ghidra_insite_$$"

mkdir -p "$OUTPUT_DIR"
mkdir -p "$TEMP_PROJECT"

# Count native DLLs
total=$(find "$INSITE_DIR" -maxdepth 1 -name "*.dll" -exec file {} \; | grep -vc "Mono/.Net")
echo "Found $total native DLLs to process"
echo "This will take approximately $(( total * 2 / 60 )) hours"
echo ""

count=0
ok=0
fail=0
skip=0

for dll in "$INSITE_DIR"/*.dll; do
    [ -f "$dll" ] || continue
    name=$(basename "${dll%.dll}")

    # Skip .NET DLLs
    if file "$dll" | grep -q "Mono/.Net"; then
        continue
    fi

    # Skip runtime DLLs
    case "$name" in
        atl*|msvc*|mfc*)
            continue
            ;;
    esac

    count=$((count + 1))
    outfile="$OUTPUT_DIR/${name}_ghidra.c"

    # Skip if exists
    if [ -f "$outfile" ]; then
        echo "[$count/$total] EXISTS: $name"
        skip=$((skip + 1))
        continue
    fi

    echo "[$count/$total] Processing: $name ..."

    if $GHIDRA "$TEMP_PROJECT" "Insite_$name" \
        -import "$dll" \
        -scriptPath "$SCRIPT_DIR" \
        -postscript DecompileAll.java "$outfile" \
        -deleteProject > /dev/null 2>&1; then

        if [ -f "$outfile" ]; then
            size=$(du -h "$outfile" | cut -f1)
            echo "[$count/$total] OK: $name ($size)"
            ok=$((ok + 1))
        else
            echo "[$count/$total] FAIL: $name (no output)"
            fail=$((fail + 1))
        fi
    else
        echo "[$count/$total] FAIL: $name (ghidra error)"
        fail=$((fail + 1))
    fi
done

# Cleanup
rm -rf "$TEMP_PROJECT"

echo ""
echo "=== Summary ==="
echo "OK: $ok"
echo "Failed: $fail"
echo "Skipped (already exist): $skip"
echo "Total native: $count"
echo "Output: $OUTPUT_DIR"
