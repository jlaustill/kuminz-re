#!/bin/bash
#
# J90280.05 Ghidra Analysis CLI
# Thin wrapper that sources shared infrastructure
# This is the REFERENCE firmware - other firmwares bootstrap from this one
#

set -e

# ============================================================================
# FIRMWARE-SPECIFIC CONFIGURATION
# ============================================================================

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$SCRIPT_DIR/.."

# Firmware identity
FIRMWARE_NAME="J90280.05"
PROJECT_NAME="J90280"

# Paths
FIRMWARE_FILE="$PROJECT_DIR/firmware/J90280.05.full.bin"
PROCESS_FILE="J90280.05.full.bin"
PROJECT_LOCATION="$SCRIPT_DIR/project"
OUTPUT_DIR="$PROJECT_DIR/output"
FIRMWARE_DIR="$PROJECT_DIR/firmware"

# ============================================================================
# SOURCE SHARED INFRASTRUCTURE
# ============================================================================

source "$SCRIPT_DIR/../../scripts/common.sh"

# ============================================================================
# FIRMWARE-SPECIFIC COMMANDS
# ============================================================================

# J90280.05 is the reference firmware - it doesn't need ramvars or bootstrap
# since IT is the source that other firmwares bootstrap FROM

cmd_hwregs() {
    print_header "APPLYING HARDWARE REGISTER NAMES"

    check_ghidra
    check_project

    VARS_CSV="$OUTPUT_DIR/global_variables.csv"

    if [ ! -f "$VARS_CSV" ]; then
        print_error "global_variables.csv not found: $VARS_CSV"
        exit 1
    fi

    echo "Applying MC68336 hardware register names..."
    echo "Source: $VARS_CSV"
    echo "Filter: 0x00FFxxxx peripheral register space"
    echo ""

    run_script ApplyHardwareRegisters.java "$VARS_CSV"

    print_success "Hardware register names applied"
    echo ""
    echo "Run '$0 export' to see changes like:"
    echo "  DAT_00fffa27 -> REG_SIM_SWSR (Software Watchdog Service Register)"
}

cmd_full() {
    print_header "FULL ANALYSIS PIPELINE: $FIRMWARE_NAME (Reference Firmware)"

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
    echo ""
    echo "This is the REFERENCE firmware."
    echo "Other firmwares (J90350.00, etc.) bootstrap their analysis from this one."
}

# Override status to show reference firmware info
cmd_status() {
    print_header "PROJECT STATUS: $FIRMWARE_NAME (Reference Firmware)"

    echo "Project location: $PROJECT_LOCATION"
    echo "Output directory: $OUTPUT_DIR"
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

# Override help to show J90280.05-specific commands
cmd_help() {
    echo "$FIRMWARE_NAME Ghidra Analysis CLI (Reference Firmware)"
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
    echo "  hwregs     Apply MC68336 hardware register names"
    echo "  labels     Apply code labels"
    echo "  funcparams Apply function parameter types"
    echo "  localvars  Apply local variable types"
    echo "  constants  Apply constant definitions (magic numbers with names)"
    echo "  arrays     Apply array definitions"
    echo "  decompile  Decompile a single function by address or name"
    echo "  full       Run complete pipeline: init -> analyze -> memmap -> import -> export"
    echo "  status     Show project status"
    echo "  help       Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 full                    # Complete setup from scratch"
    echo "  $0 decompile 0xa5c0        # Decompile function at address"
    echo "  $0 decompile initFuelSystem # Decompile function by name"
    echo ""
    echo "Typical workflow:"
    echo "  1. $0 full                 # Initial setup"
    echo "  2. Edit output/*.csv"
    echo "  3. $0 import               # Apply changes"
    echo "  4. $0 export               # Update decompilation"
    echo ""
    echo "Note: This is the REFERENCE firmware. Other firmwares bootstrap from this one."
}

# ============================================================================
# MAIN ENTRY POINT
# ============================================================================

dispatch_command "$@"
