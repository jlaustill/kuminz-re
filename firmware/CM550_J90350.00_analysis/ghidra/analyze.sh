#!/bin/bash
#
# J90350.00 Ghidra Analysis CLI
# Thin wrapper that sources shared infrastructure
#

set -e

# ============================================================================
# FIRMWARE-SPECIFIC CONFIGURATION
# ============================================================================

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$SCRIPT_DIR/.."

# Firmware identity
FIRMWARE_NAME="J90350.00"
PROJECT_NAME="J90350"

# Paths
FIRMWARE_FILE="$PROJECT_DIR/firmware/J90350.00.rom.bin"
PROCESS_FILE="J90350.00.rom.bin"
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

# The ONE deterministic build: fresh binary -> apply EVERY CSV -> decompilation.
# CM550 is single-bank (MC68336), so analyze runs first (no Bank2 seeding needed);
# memmap loads RAM/EEPROM; enums before import (DTM types); deletions after analyze.
cmd_build() {
    print_header "BUILD: $FIRMWARE_NAME — deterministic, from scratch"
    echo "Fresh binary -> apply every CSV -> decompilation. The .rep is disposable."
    echo ""

    cmd_init        # fresh import (-overwrite); zero history
    cmd_analyze     # deterministic auto-analysis
    cmd_memmap      # RAM + EEPROM regions (needed before structures)
    cmd_enums       # enum types into DTM (before global typing)
    cmd_import      # ApplyStructures + ImportAnalysis: force-create funcs + names + globals
    cmd_deletions   # remove spurious mid-function splits (deleted_functions.csv delta; no-op if absent)
    cmd_import      # re-assert names/types over analyze; recover globals at freed addresses
    cmd_hwregs      # MC68336 hardware register names
    cmd_labels      # code labels
    cmd_constants   # magic-number constants
    cmd_arrays      # array definitions
    cmd_export      # re-applies funcdefs+localvars, then ExportAnalysis -> .cpp + CSVs

    print_header "BUILD COMPLETE"
    print_success "$FIRMWARE_NAME built deterministically from CSVs"
}

# Override status
cmd_status() {
    print_header "PROJECT STATUS: $FIRMWARE_NAME"

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
        print_success "Function names exported ($((FUNCS-1)) functions)"
    else
        print_warning "Function names not built - run '$0 build'"
    fi

    if [ -f "$OUTPUT_DIR/${FIRMWARE_NAME}.ghidra.cpp" ]; then
        SIZE=$(du -h "$OUTPUT_DIR/${FIRMWARE_NAME}.ghidra.cpp" | cut -f1)
        print_success "Decompilation built ($SIZE)"
    else
        print_warning "Decompilation not built - run '$0 build'"
    fi

    # Count optional CSVs
    echo ""
    for csv in enums labels constants arrays structure_definitions local_variables function_definitions; do
        if [ -f "$OUTPUT_DIR/${csv}.csv" ]; then
            COUNT=$(wc -l < "$OUTPUT_DIR/${csv}.csv")
            print_success "${csv}.csv ($((COUNT-1)) entries)"
        fi
    done
}

# Override help
# cmd_help: use the shared one-shot-model help from common.sh.
# (cmd_status remains overridden above for CM550-specific output.)

# ============================================================================
# MAIN ENTRY POINT
# ============================================================================

dispatch_command "$@"
