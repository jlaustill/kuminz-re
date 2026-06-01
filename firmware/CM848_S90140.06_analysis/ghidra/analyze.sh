#!/bin/bash
#
# CM848 S90140.06 Ghidra Analysis CLI
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
FIRMWARE_NAME="CM848_S90140.06"
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

# The ONE deterministic build: fresh binary -> apply EVERY CSV -> decompilation.
# Order respects: memmap before analyze (Bank2/RAM loaded); import before analyze
# (Bank2 entry-point seeding); enums before import (DTM types); deletions after analyze;
# callingconv/hwregs before export's funcdef/localvar re-apply.
cmd_build() {
    print_header "BUILD: $FIRMWARE_NAME (PowerPC) — deterministic, from scratch"
    echo "Fresh binary -> apply every CSV -> decompilation. The .rep is disposable."
    echo ""

    cmd_init         # fresh import (-overwrite); zero history
    cmd_memmap       # FLASH2 + RAM + EEPROM + peripheral regions
    cmd_enums        # enum types into DTM (before global typing references them)
    cmd_import       # ApplyStructures + ImportAnalysis: force-create funcs (Bank2 seed) + names + globals
    cmd_analyze      # deterministic auto-analysis (cross-bank calls now resolve)
    cmd_deletions    # remove spurious mid-function splits (deleted_functions.csv delta)
    cmd_import       # re-assert names/types over analyze; recover globals at freed addresses
    cmd_romramthunks # resolve func_0x003fxxxx ROM-to-RAM calls -> named ROM functions
    cmd_callingconv  # Bank2 __stdcall convention
    cmd_hwregs       # MPC555 hardware register names
    cmd_labels       # code labels
    cmd_constants    # magic-number constants
    cmd_arrays       # array definitions
    cmd_export       # re-applies funcdefs+localvars, then ExportAnalysis -> .cpp (only)

    print_header "BUILD COMPLETE"
    print_success "$FIRMWARE_NAME built deterministically from CSVs"
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
        print_warning "Function names not found - run '$0 build'"
    fi

    if [ -f "$OUTPUT_DIR/global_variables.csv" ]; then
        VARS=$(wc -l < "$OUTPUT_DIR/global_variables.csv")
        print_success "Global variables ($((VARS-1)) variables)"
    else
        print_warning "Global variables not found"
    fi

    CPP=$(ls "$OUTPUT_DIR"/*.ghidra.cpp 2>/dev/null | head -1)
    if [ -n "$CPP" ]; then
        SIZE=$(du -h "$CPP" | cut -f1)
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

cmd_callingconv() {
    print_header "FIXING BANK 2 CALLING CONVENTIONS: $FIRMWARE_NAME"

    check_ghidra
    check_project

    echo "Setting __stdcall on all functions in Bank 2 (0x00500000-0x0053DFFF)..."
    echo ""

    run_script SetCallingConvention.java "00500000" "0053DFFF"

    print_success "Calling conventions set — run funcdefs + localvars + export to see changes"
}

# Build-internal: thunk the ROM-to-RAM call targets (func_0x003fxxxx) to their ROM source
# functions. Auto-discovers from the ROM source range; deterministic + idempotent.
cmd_romramthunks() {
    print_header "APPLYING ROM-TO-RAM THUNKS: $FIRMWARE_NAME"
    check_ghidra
    check_project
    run_script ApplyRomToRamThunks.java
    print_success "ROM-to-RAM thunks applied"
}

cmd_hwregs() {
    print_header "APPLYING MPC555 HARDWARE REGISTERS: $FIRMWARE_NAME"

    check_ghidra
    check_project

    echo "Applying MPC555 peripheral register names..."
    echo "Input: $OUTPUT_DIR/mpc555_registers.csv"
    echo ""

    run_script ApplyMPC555Registers.java "$OUTPUT_DIR/mpc555_registers.csv"

    print_success "Hardware register naming complete"
}

# cmd_help, cmd_status: use the shared one-shot-model help from common.sh
# (cmd_status remains overridden above for CM848-specific output).

# ============================================================================
# MAIN ENTRY POINT
# ============================================================================

dispatch_command "$@"
