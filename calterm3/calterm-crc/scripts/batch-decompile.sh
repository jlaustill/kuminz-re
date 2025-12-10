#!/bin/bash
# batch-decompile.sh - Batch decompile all Calterm III DLLs
# Processes .NET DLLs with ILSpy, native DLLs with RetDec/Ghidra

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
CALTERM_DIR="/home/jlaustill/Software/Calterm III"
OUTPUT_DIR="$(dirname "$SCRIPT_DIR")/decompiled"

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Skip these runtime DLLs
SKIP_DLLS=(
    "atl110.dll"
    "msvcp110.dll"
    "msvcr110.dll"
)

# Detect DLL type
detect_type() {
    if file "$1" | grep -q "Mono/.Net"; then
        echo "dotnet"
    else
        echo "native"
    fi
}

# Check if DLL should be skipped
should_skip() {
    local basename=$(basename "$1")
    for skip in "${SKIP_DLLS[@]}"; do
        if [ "$basename" = "$skip" ]; then
            return 0
        fi
    done
    return 1
}

# Main
main() {
    local mode="${1:-all}"  # all, dotnet, native, single
    local single_dll="$2"

    echo -e "${BLUE}============================================${NC}"
    echo -e "${BLUE}Calterm III Batch Decompiler${NC}"
    echo -e "${BLUE}============================================${NC}"
    echo ""

    # Counters
    local total=0
    local dotnet_count=0
    local native_count=0
    local skipped=0
    local failed=0

    # Create output directories
    mkdir -p "$OUTPUT_DIR/dotnet" "$OUTPUT_DIR/native"

    # Count DLLs first
    for dll in "$CALTERM_DIR"/*.dll; do
        if [ -f "$dll" ]; then
            ((total++))
        fi
    done

    echo -e "Found ${YELLOW}$total${NC} DLLs in $CALTERM_DIR"
    echo ""

    # Process each DLL
    local current=0
    for dll in "$CALTERM_DIR"/*.dll; do
        if [ ! -f "$dll" ]; then
            continue
        fi

        ((current++))
        local basename=$(basename "$dll")
        local name="${basename%.dll}"

        # Skip runtime DLLs
        if should_skip "$dll"; then
            echo -e "[${current}/${total}] ${YELLOW}SKIP${NC} $basename (runtime DLL)"
            ((skipped++))
            continue
        fi

        local type=$(detect_type "$dll")

        # Filter by mode
        if [ "$mode" = "dotnet" ] && [ "$type" != "dotnet" ]; then
            continue
        fi
        if [ "$mode" = "native" ] && [ "$type" != "native" ]; then
            continue
        fi

        echo -e "[${current}/${total}] Processing ${BLUE}$basename${NC} (${type})"

        if [ "$type" = "dotnet" ]; then
            local outfile="$OUTPUT_DIR/dotnet/${name}.cs"
            if [ -f "$outfile" ]; then
                echo -e "  ${YELLOW}EXISTS${NC} - skipping (use --force to regenerate)"
                continue
            fi

            if $HOME/.dotnet/tools/ilspycmd "$dll" > "$outfile" 2>/dev/null; then
                echo -e "  ${GREEN}OK${NC} -> dotnet/${name}.cs"
                ((dotnet_count++))
            else
                echo -e "  ${RED}FAILED${NC}"
                rm -f "$outfile"
                ((failed++))
            fi
        else
            local outfile="$OUTPUT_DIR/native/${name}_retdec.c"
            if [ -f "$outfile" ]; then
                echo -e "  ${YELLOW}EXISTS${NC} - skipping"
                continue
            fi

            # Try RetDec (faster)
            if /snap/retdec/current/bin/retdec-decompiler.py -o "$outfile" "$dll" 2>/dev/null; then
                echo -e "  ${GREEN}OK${NC} -> native/${name}_retdec.c"
                ((native_count++))
            else
                echo -e "  ${RED}FAILED${NC} (RetDec)"
                rm -f "$outfile" "${outfile%.c}.dsm" "${outfile%.c}.bc" "${outfile%.c}.ll" 2>/dev/null
                ((failed++))
            fi
        fi
    done

    echo ""
    echo -e "${BLUE}============================================${NC}"
    echo -e "${BLUE}Summary${NC}"
    echo -e "${BLUE}============================================${NC}"
    echo -e "Total DLLs:     $total"
    echo -e ".NET decompiled: ${GREEN}$dotnet_count${NC}"
    echo -e "Native decompiled: ${GREEN}$native_count${NC}"
    echo -e "Skipped:        ${YELLOW}$skipped${NC}"
    echo -e "Failed:         ${RED}$failed${NC}"
    echo ""
    echo -e "Output directory: $OUTPUT_DIR"
}

# Handle arguments
case "$1" in
    --help|-h)
        echo "Usage: $0 [mode]"
        echo ""
        echo "Modes:"
        echo "  all     - Process all DLLs (default)"
        echo "  dotnet  - Process only .NET DLLs"
        echo "  native  - Process only native DLLs"
        echo ""
        exit 0
        ;;
    *)
        main "$@"
        ;;
esac
