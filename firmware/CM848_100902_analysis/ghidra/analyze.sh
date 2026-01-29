#!/bin/bash
#
# CM848_100902 Ghidra Analysis CLI
# Thin wrapper that sources shared infrastructure
# CM848 uses PowerPC processor (unlike CM550 which uses MC68336)
#

set -e

# ============================================================================
# FIRMWARE-SPECIFIC CONFIGURATION
# ============================================================================

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$SCRIPT_DIR/.."

# Firmware identity
FIRMWARE_NAME="CM848_100902"
PROJECT_NAME="CM848"

# Paths
FIRMWARE_FILE="$PROJECT_DIR/originals/cm848_rom.bin"
PROCESS_FILE="cm848_rom.bin"
PROJECT_LOCATION="$SCRIPT_DIR/project"
OUTPUT_DIR="$PROJECT_DIR/output"
FIRMWARE_DIR="$PROJECT_DIR/originals"

# Override processor for PowerPC (CM848 uses MPC5xx series)
PROCESSOR="PowerPC:BE:32:default"

# ============================================================================
# SOURCE SHARED INFRASTRUCTURE
# ============================================================================

source "$SCRIPT_DIR/../../scripts/common.sh"

# ============================================================================
# FIRMWARE-SPECIFIC COMMANDS
# ============================================================================

cmd_memmap() {
    print_header "SETTING UP MEMORY MAP: $FIRMWARE_NAME (PowerPC)"

    check_ghidra
    check_project

    echo "Adding RAM and EEPROM memory regions..."
    echo "Firmware directory: $FIRMWARE_DIR"
    echo ""

    # CM848 uses different script due to different memory layout
    run_script SetupMemoryMapCM848.java "$FIRMWARE_DIR"

    print_success "Memory map setup complete"
}

cmd_full() {
    print_header "FULL ANALYSIS PIPELINE: $FIRMWARE_NAME (PowerPC)"

    echo "This will run: init -> analyze -> memmap -> import -> export"
    echo ""

    cmd_init
    cmd_analyze
    cmd_memmap
    cmd_import
    cmd_export

    print_header "FULL PIPELINE COMPLETE"
    print_success "$FIRMWARE_NAME analysis is ready!"
    echo ""
    echo "Output files:"
    echo "  - $OUTPUT_DIR/function_renames.csv"
    echo "  - $OUTPUT_DIR/global_variables.csv"
    echo "  - $OUTPUT_DIR/${FIRMWARE_NAME}.ghidra.cpp"
}

cmd_status() {
    print_header "PROJECT STATUS: $FIRMWARE_NAME (PowerPC)"

    echo "Project location: $PROJECT_LOCATION"
    echo "Output directory: $OUTPUT_DIR"
    echo "Processor: $PROCESSOR"
    echo ""

    if [ -d "$PROJECT_LOCATION/$PROJECT_NAME.rep" ]; then
        print_success "Ghidra project exists"
        echo "  Size: $(du -sh "$PROJECT_LOCATION" | cut -f1)"
    else
        print_warning "Ghidra project not found - run '$0 init'"
    fi

    echo ""

    if [ -f "$OUTPUT_DIR/function_renames.csv" ]; then
        FUNCS=$(wc -l < "$OUTPUT_DIR/function_renames.csv")
        print_success "Function names ($((FUNCS-1)) functions)"
    else
        print_warning "Function names not found - run '$0 export'"
    fi

    if [ -f "$OUTPUT_DIR/global_variables.csv" ]; then
        VARS=$(wc -l < "$OUTPUT_DIR/global_variables.csv")
        print_success "Global variables ($((VARS-1)) variables)"
    else
        print_warning "Global variables not found"
    fi

    if [ -f "$OUTPUT_DIR/${FIRMWARE_NAME}.ghidra.cpp" ]; then
        SIZE=$(du -h "$OUTPUT_DIR/${FIRMWARE_NAME}.ghidra.cpp" | cut -f1)
        print_success "Decompilation exported ($SIZE)"
    else
        print_warning "Decompilation not exported - run '$0 export'"
    fi

    # Count optional CSVs
    echo ""
    for csv in enums labels constants arrays structure_definitions local_variables function_parameters; do
        if [ -f "$OUTPUT_DIR/${csv}.csv" ]; then
            COUNT=$(wc -l < "$OUTPUT_DIR/${csv}.csv")
            print_success "${csv}.csv ($((COUNT-1)) entries)"
        fi
    done
}

cmd_help() {
    echo "$FIRMWARE_NAME Ghidra Analysis CLI (PowerPC)"
    echo ""
    echo "Usage: $0 <command> [options]"
    echo ""
    echo "Commands:"
    echo "  init       Import firmware into new Ghidra project (no analysis)"
    echo "  analyze    Run Ghidra auto-analysis on the project"
    echo "  memmap     Add RAM and EEPROM memory regions"
    echo "  export     Export function names and decompilation to CSV/CPP"
    echo "  import     Import CSV changes back into Ghidra"
    echo "  structures Apply structure definitions"
    echo "  enums      Apply enum definitions for magic number replacement"
    echo "  labels     Apply code labels"
    echo "  funcparams Apply function parameter types"
    echo "  localvars  Apply local variable types"
    echo "  vartypes   Apply global variable types (clears stale types first)"
    echo "  constants  Apply constant definitions (magic numbers with names)"
    echo "  arrays     Apply array definitions"
    echo "  decompile  Decompile a single function by address or name"
    echo "  full       Run complete pipeline: init -> analyze -> memmap -> import -> export"
    echo "  status     Show project status"
    echo "  help       Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 full                    # Complete setup from scratch"
    echo "  $0 decompile 0x1000        # Decompile function at address"
    echo ""
    echo "Typical workflow:"
    echo "  1. $0 full                 # Initial setup"
    echo "  2. Edit output/*.csv"
    echo "  3. $0 import               # Apply changes"
    echo "  4. $0 export               # Update decompilation"
    echo ""
    echo "Note: CM848 uses PowerPC processor (unlike CM550 which uses MC68336/68K)"
}

# ============================================================================
# MAIN ENTRY POINT
# ============================================================================

dispatch_command "$@"
