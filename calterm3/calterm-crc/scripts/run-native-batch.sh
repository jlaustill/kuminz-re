#!/bin/bash
# Batch decompiler for native DLLs using Ghidra headless

CALTERM_DIR="/home/jlaustill/Software/Calterm III"
OUTPUT_DIR="/home/jlaustill/Software/calterm-crc/decompiled/native"
SCRIPT_DIR="/home/jlaustill/Software/calterm-crc/scripts"
GHIDRA="/opt/ghidra/support/analyzeHeadless"
TEMP_PROJECT="/tmp/ghidra_batch_$$"

mkdir -p "$OUTPUT_DIR"
mkdir -p "$TEMP_PROJECT"

echo "=== Native DLL Batch Decompiler (Ghidra) ==="
echo ""

count=0
ok=0
fail=0
skip=0

for dll in "$CALTERM_DIR"/*.dll; do
    name=$(basename "${dll%.dll}")

    # Skip runtime DLLs
    case "$name" in
        atl110|msvcp110|msvcr110)
            continue
            ;;
    esac

    # Skip .NET DLLs
    if file "$dll" | grep -q "Mono/.Net"; then
        continue
    fi

    count=$((count + 1))
    outfile="$OUTPUT_DIR/${name}_ghidra.c"

    # Skip if exists
    if [ -f "$outfile" ]; then
        echo "[$count] EXISTS: $name"
        skip=$((skip + 1))
        continue
    fi

    echo "[$count] Processing: $name ..."

    # Run Ghidra headless
    if $GHIDRA "$TEMP_PROJECT" "Project_$count" \
        -import "$dll" \
        -scriptPath "$SCRIPT_DIR" \
        -postscript DecompileAll.java "$outfile" \
        -deleteProject > /dev/null 2>&1; then

        if [ -f "$outfile" ]; then
            size=$(du -h "$outfile" | cut -f1)
            echo "[$count] OK: $name ($size)"
            ok=$((ok + 1))
        else
            echo "[$count] FAIL: $name (no output)"
            fail=$((fail + 1))
        fi
    else
        echo "[$count] FAIL: $name (ghidra error)"
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
