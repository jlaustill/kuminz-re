#!/bin/bash
# decompile.sh - Universal decompiler wrapper for Calterm DLLs
# Auto-detects DLL type and uses appropriate decompiler

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
GHIDRA_HEADLESS="/opt/ghidra/support/analyzeHeadless"
RETDEC="/snap/retdec/current/bin/retdec-decompiler.py"
ILSPYCMD="$HOME/.dotnet/tools/ilspycmd"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

usage() {
    echo "Usage: $0 <dll_file> [output_dir] [--tool <tool>]"
    echo ""
    echo "Options:"
    echo "  dll_file    Path to the DLL to decompile"
    echo "  output_dir  Output directory (default: ./decompiled)"
    echo "  --tool      Force specific tool: ilspy, ghidra, retdec"
    echo ""
    echo "Examples:"
    echo "  $0 CRCUtility.dll"
    echo "  $0 ConfigurationFiles.dll ./output --tool ghidra"
    exit 1
}

# Detect if DLL is .NET/Mono or native
detect_type() {
    local dll="$1"
    if file "$dll" | grep -q "Mono/.Net"; then
        echo "dotnet"
    else
        echo "native"
    fi
}

# Decompile using ILSpy (for .NET)
decompile_ilspy() {
    local dll="$1"
    local outdir="$2"
    local basename=$(basename "${dll%.dll}")
    local outfile="$outdir/dotnet/${basename}.cs"

    echo -e "${GREEN}[ILSpy]${NC} Decompiling $basename..."
    mkdir -p "$outdir/dotnet"

    if $ILSPYCMD "$dll" > "$outfile" 2>/dev/null; then
        echo -e "${GREEN}[ILSpy]${NC} Success: $outfile"
        return 0
    else
        echo -e "${RED}[ILSpy]${NC} Failed to decompile $basename"
        return 1
    fi
}

# Decompile using Ghidra headless
decompile_ghidra() {
    local dll="$1"
    local outdir="$2"
    local basename=$(basename "${dll%.dll}")
    local outfile="$outdir/native/${basename}_ghidra.c"
    local temp_project="/tmp/ghidra_decompile_$$"

    echo -e "${GREEN}[Ghidra]${NC} Decompiling $basename..."
    mkdir -p "$outdir/native"

    # Create temp project directory
    mkdir -p "$temp_project"

    if $GHIDRA_HEADLESS "$temp_project" "TempProject" \
        -import "$dll" \
        -scriptPath "$SCRIPT_DIR" \
        -postscript DecompileAll.java "$outfile" \
        -deleteProject \
        -noanalysis 2>/dev/null | grep -v "^INFO\|^WARN" ; then

        if [ -f "$outfile" ]; then
            echo -e "${GREEN}[Ghidra]${NC} Success: $outfile"
            rm -rf "$temp_project"
            return 0
        fi
    fi

    # Try with analysis enabled if quick mode failed
    echo -e "${YELLOW}[Ghidra]${NC} Retrying with full analysis..."
    if $GHIDRA_HEADLESS "$temp_project" "TempProject" \
        -import "$dll" \
        -scriptPath "$SCRIPT_DIR" \
        -postscript DecompileAll.java "$outfile" \
        -deleteProject 2>/dev/null | grep -v "^INFO\|^WARN" ; then

        if [ -f "$outfile" ]; then
            echo -e "${GREEN}[Ghidra]${NC} Success: $outfile"
            rm -rf "$temp_project"
            return 0
        fi
    fi

    echo -e "${RED}[Ghidra]${NC} Failed to decompile $basename"
    rm -rf "$temp_project"
    return 1
}

# Decompile using RetDec
decompile_retdec() {
    local dll="$1"
    local outdir="$2"
    local basename=$(basename "${dll%.dll}")
    local outfile="$outdir/native/${basename}_retdec.c"

    echo -e "${GREEN}[RetDec]${NC} Decompiling $basename..."
    mkdir -p "$outdir/native"

    if $RETDEC -o "$outfile" "$dll" 2>/dev/null; then
        echo -e "${GREEN}[RetDec]${NC} Success: $outfile"
        return 0
    else
        echo -e "${RED}[RetDec]${NC} Failed to decompile $basename"
        return 1
    fi
}

# Main logic
main() {
    local dll=""
    local outdir="$PROJECT_DIR/decompiled"
    local force_tool=""

    # Parse arguments
    while [[ $# -gt 0 ]]; do
        case $1 in
            --tool)
                force_tool="$2"
                shift 2
                ;;
            --help|-h)
                usage
                ;;
            *)
                if [ -z "$dll" ]; then
                    dll="$1"
                else
                    outdir="$1"
                fi
                shift
                ;;
        esac
    done

    if [ -z "$dll" ]; then
        usage
    fi

    if [ ! -f "$dll" ]; then
        echo -e "${RED}Error:${NC} File not found: $dll"
        exit 1
    fi

    local type=$(detect_type "$dll")
    echo -e "Detected type: ${YELLOW}$type${NC}"

    # Handle forced tool
    if [ -n "$force_tool" ]; then
        case $force_tool in
            ilspy)
                decompile_ilspy "$dll" "$outdir"
                ;;
            ghidra)
                decompile_ghidra "$dll" "$outdir"
                ;;
            retdec)
                decompile_retdec "$dll" "$outdir"
                ;;
            *)
                echo -e "${RED}Unknown tool:${NC} $force_tool"
                exit 1
                ;;
        esac
        return $?
    fi

    # Auto-select based on type
    if [ "$type" = "dotnet" ]; then
        decompile_ilspy "$dll" "$outdir"
    else
        # For native, try RetDec first (faster), then Ghidra
        echo -e "${YELLOW}Native DLL - trying multiple decompilers...${NC}"
        decompile_retdec "$dll" "$outdir" || true
        decompile_ghidra "$dll" "$outdir" || true
    fi
}

main "$@"
