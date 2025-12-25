#!/bin/bash
#
# Common functions for Ghidra firmware analysis
# Sourced by each firmware's analyze.sh wrapper
#

# Required variables from caller:
#   FIRMWARE_NAME       - e.g., "J90350.00" or "J90280.05"
#   PROJECT_NAME        - e.g., "J90350" or "J90280"
#   FIRMWARE_FILE       - Full path to binary (e.g., .../firmware/J90350.00.rom.bin)
#   PROCESS_FILE        - Binary filename only (e.g., "J90350.00.rom.bin")
#   PROJECT_LOCATION    - Path to ghidra/project/ directory
#   OUTPUT_DIR          - Path to output/ directory
#   FIRMWARE_DIR        - Path to firmware/ directory (for RAM/EEPROM dumps)

# Find shared scripts directory (relative to this file)
SHARED_SCRIPTS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Find Ghidra installation
GHIDRA_DIR="${GHIDRA_DIR:-$HOME/code/ghidra}"

find_ghidra_headless() {
    if [ -f "$GHIDRA_DIR/build/dist/ghidra_12.0_DEV/support/analyzeHeadless" ]; then
        echo "$GHIDRA_DIR/build/dist/ghidra_12.0_DEV/support/analyzeHeadless"
    elif [ -f "$GHIDRA_DIR/support/analyzeHeadless" ]; then
        echo "$GHIDRA_DIR/support/analyzeHeadless"
    else
        echo "$GHIDRA_DIR/Ghidra/RuntimeScripts/Linux/support/analyzeHeadless"
    fi
}

GHIDRA_HEADLESS="$(find_ghidra_headless)"

# MC68336 processor configuration
PROCESSOR="68000:BE:32:default"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

print_header() {
    echo ""
    echo "======================================================================"
    echo "$1"
    echo "======================================================================"
    echo ""
}

print_success() {
    echo -e "${GREEN}✓ $1${NC}"
}

print_error() {
    echo -e "${RED}✗ $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}! $1${NC}"
}

check_ghidra() {
    if [ ! -f "$GHIDRA_HEADLESS" ]; then
        print_error "Ghidra headless analyzer not found at: $GHIDRA_HEADLESS"
        print_error "Please set GHIDRA_DIR or install Ghidra to ~/code/ghidra"
        exit 1
    fi
}

check_project() {
    if [ ! -d "$PROJECT_LOCATION/$PROJECT_NAME.rep" ]; then
        print_error "Project not found. Run '$0 init' first."
        exit 1
    fi
}

# Run a Ghidra script with arguments
run_script() {
    local script_name="$1"
    shift
    local script_args=("$@")

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "$PROCESS_FILE" \
        -noanalysis \
        -scriptPath "$SHARED_SCRIPTS_DIR" \
        -postScript "$script_name" "${script_args[@]}"
}

# ============================================================================
# COMMAND IMPLEMENTATIONS
# ============================================================================

cmd_init() {
    print_header "INITIALIZING GHIDRA PROJECT: $FIRMWARE_NAME"

    check_ghidra

    mkdir -p "$PROJECT_LOCATION"

    echo "Importing firmware: $FIRMWARE_FILE"
    echo "Project location: $PROJECT_LOCATION"
    echo "Processor: $PROCESSOR"
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -import "$FIRMWARE_FILE" \
        -processor "$PROCESSOR" \
        -loader BinaryLoader \
        -loader-baseAddr 0x0 \
        -noanalysis \
        -overwrite

    print_success "Import complete (no analysis yet)"
    echo ""
    echo "Next step: Run '$0 analyze' to perform auto-analysis"
}

cmd_analyze() {
    print_header "RUNNING AUTO-ANALYSIS: $FIRMWARE_NAME"

    check_ghidra
    check_project

    echo "Running Ghidra auto-analysis..."
    echo "This may take several minutes..."
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "$PROCESS_FILE" \
        -recursive

    print_success "Auto-analysis complete"
}

cmd_memmap() {
    print_header "SETTING UP MEMORY MAP: $FIRMWARE_NAME"

    check_ghidra
    check_project

    echo "Adding RAM and EEPROM memory regions..."
    echo "Firmware directory: $FIRMWARE_DIR"
    echo ""

    run_script SetupMemoryMap.java "$FIRMWARE_DIR"

    print_success "Memory map setup complete"
}

cmd_export() {
    print_header "EXPORTING ANALYSIS: $FIRMWARE_NAME"

    check_ghidra

    mkdir -p "$OUTPUT_DIR"

    echo "Exporting to: $OUTPUT_DIR"
    echo ""

    run_script ExportAnalysis.java "$OUTPUT_DIR"

    print_success "Export complete"
    echo ""
    echo "Files created:"
    ls -la "$OUTPUT_DIR"/*.csv "$OUTPUT_DIR"/*.cpp 2>/dev/null || true
}

cmd_import() {
    print_header "IMPORTING CSV CHANGES: $FIRMWARE_NAME"

    check_ghidra

    echo "Importing from: $OUTPUT_DIR"
    echo ""

    run_script ImportAnalysis.java "$OUTPUT_DIR"

    print_success "Import complete"
}

cmd_structures() {
    print_header "APPLYING STRUCTURE DEFINITIONS: $FIRMWARE_NAME"

    check_ghidra
    check_project

    STRUCT_CSV="$OUTPUT_DIR/structure_definitions.csv"

    if [ ! -f "$STRUCT_CSV" ]; then
        print_error "structure_definitions.csv not found: $STRUCT_CSV"
        exit 1
    fi

    echo "Applying structures from: $STRUCT_CSV"
    echo ""

    run_script ApplyStructures.java "$STRUCT_CSV"

    print_success "Structure definitions applied"
}

cmd_enums() {
    print_header "APPLYING ENUM DEFINITIONS: $FIRMWARE_NAME"

    check_ghidra
    check_project

    ENUMS_CSV="$OUTPUT_DIR/enums.csv"

    if [ ! -f "$ENUMS_CSV" ]; then
        print_error "enums.csv not found: $ENUMS_CSV"
        exit 1
    fi

    echo "Applying enum definitions..."
    echo "Source: $ENUMS_CSV"
    echo ""

    run_script ApplyEnums.java "$ENUMS_CSV"

    print_success "Enum definitions applied"
    echo ""
    echo "Run '$0 export' to regenerate decompilation with enum values."
}

cmd_labels() {
    print_header "APPLYING CODE LABELS: $FIRMWARE_NAME"

    check_ghidra
    check_project

    LABELS_CSV="$OUTPUT_DIR/labels.csv"
    RELOCATION_MAP="$OUTPUT_DIR/relocation_map.csv"

    if [ ! -f "$LABELS_CSV" ]; then
        print_error "labels.csv not found: $LABELS_CSV"
        exit 1
    fi

    echo "Applying code labels..."
    echo "Labels source: $LABELS_CSV"
    if [ -f "$RELOCATION_MAP" ]; then
        echo "Relocation map: $RELOCATION_MAP"
        run_script ApplyLabels.java "$LABELS_CSV" "$RELOCATION_MAP"
    else
        echo "No relocation map"
        run_script ApplyLabels.java "$LABELS_CSV"
    fi

    print_success "Code labels applied"
}

cmd_funcparams() {
    print_header "APPLYING FUNCTION PARAMETER TYPES: $FIRMWARE_NAME"

    check_ghidra
    check_project

    PARAMS_CSV="$OUTPUT_DIR/function_parameters.csv"

    if [ ! -f "$PARAMS_CSV" ]; then
        print_error "function_parameters.csv not found: $PARAMS_CSV"
        exit 1
    fi

    echo "Applying function parameter types..."
    echo "Source: $PARAMS_CSV"
    echo ""

    run_script ApplyFunctionParameters.java "$PARAMS_CSV"

    print_success "Function parameter types applied"
}

cmd_localvars() {
    print_header "APPLYING LOCAL VARIABLE TYPES: $FIRMWARE_NAME"

    check_ghidra
    check_project

    LOCALVARS_CSV="$OUTPUT_DIR/local_variables.csv"

    if [ ! -f "$LOCALVARS_CSV" ]; then
        print_error "local_variables.csv not found: $LOCALVARS_CSV"
        exit 1
    fi

    echo "Applying local variable types..."
    echo "Source: $LOCALVARS_CSV"
    echo ""

    run_script BulkLocalVariableRenamer.java

    print_success "Local variable types applied"
}

cmd_vartypes() {
    print_header "APPLYING GLOBAL VARIABLE TYPES: $FIRMWARE_NAME"

    check_ghidra
    check_project

    VARS_CSV="$OUTPUT_DIR/global_variables.csv"

    if [ ! -f "$VARS_CSV" ]; then
        print_error "global_variables.csv not found: $VARS_CSV"
        exit 1
    fi

    echo "Applying variable types from: $VARS_CSV"
    echo "This clears stale types before applying new ones."
    echo ""

    run_script ApplyGlobalVariableTypes.java "$VARS_CSV"

    print_success "Global variable types applied"
}

cmd_constants() {
    print_header "APPLYING CONSTANT DEFINITIONS: $FIRMWARE_NAME"

    check_ghidra
    check_project

    CONSTANTS_CSV="$OUTPUT_DIR/constants.csv"

    if [ ! -f "$CONSTANTS_CSV" ]; then
        print_error "constants.csv not found: $CONSTANTS_CSV"
        exit 1
    fi

    echo "Applying constant definitions..."
    echo "Source: $CONSTANTS_CSV"
    echo ""

    run_script ApplyConstants.java "$CONSTANTS_CSV"

    print_success "Constant definitions applied"
}

cmd_arrays() {
    print_header "APPLYING ARRAY DEFINITIONS: $FIRMWARE_NAME"

    check_ghidra
    check_project

    ARRAYS_CSV="$OUTPUT_DIR/arrays.csv"

    if [ ! -f "$ARRAYS_CSV" ]; then
        print_error "arrays.csv not found: $ARRAYS_CSV"
        exit 1
    fi

    echo "Applying array definitions..."
    echo "Source: $ARRAYS_CSV"
    echo ""

    run_script ApplyArrays.java "$ARRAYS_CSV"

    print_success "Array definitions applied"
}

cmd_decompile() {
    local target="$1"

    if [ -z "$target" ]; then
        print_error "Usage: $0 decompile <address|function_name>"
        print_error "Examples:"
        print_error "  $0 decompile 0x22e5e"
        print_error "  $0 decompile vp44CanMessageDispatcher"
        exit 1
    fi

    check_ghidra

    run_script DecompileFunction.java "$target"
}

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
        print_warning "Function names not exported - run '$0 export'"
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
    echo "$FIRMWARE_NAME Ghidra Analysis CLI"
    echo ""
    echo "Usage: $0 <command> [options]"
    echo ""
    echo "Commands:"
    echo "  init       Import firmware into new Ghidra project (no analysis)"
    echo "  analyze    Run Ghidra auto-analysis on the project"
    echo "  memmap     Add RAM and EEPROM memory regions from live dumps"
    echo "  export     Export function names and decompilation to CSV/CPP"
    echo "  import     Import CSV changes back into Ghidra"
    echo "  structures Apply structure definitions from structure_definitions.csv"
    echo "  enums      Apply enum definitions for magic number replacement"
    echo "  labels     Apply code labels for improved readability"
    echo "  funcparams Apply function parameter types"
    echo "  localvars  Apply local variable types"
    echo "  vartypes   Apply global variable types (clears stale types first)"
    echo "  constants  Apply constant definitions (magic numbers with names)"
    echo "  arrays     Apply array definitions"
    echo "  decompile  Decompile a single function by address or name"
    echo "  full       Run complete pipeline (firmware-specific)"
    echo "  status     Show project status"
    echo "  help       Show this help message"
    echo ""
    echo "Typical workflow:"
    echo "  1. $0 full                 # Initial setup"
    echo "  2. Edit output/*.csv"
    echo "  3. $0 import               # Apply changes"
    echo "  4. $0 export               # Update decompilation"
}

# Dispatch command (called from firmware-specific script)
dispatch_command() {
    local cmd="${1:-help}"
    shift || true

    case "$cmd" in
        init)       cmd_init ;;
        analyze)    cmd_analyze ;;
        memmap)     cmd_memmap ;;
        export)     cmd_export ;;
        import)     cmd_import ;;
        structures) cmd_structures ;;
        enums)      cmd_enums ;;
        labels)     cmd_labels ;;
        funcparams) cmd_funcparams ;;
        localvars)  cmd_localvars ;;
        vartypes)   cmd_vartypes ;;
        constants)  cmd_constants ;;
        arrays)     cmd_arrays ;;
        decompile)  cmd_decompile "$@" ;;
        status)     cmd_status ;;
        help|--help|-h) cmd_help ;;
        *)
            # Check if firmware-specific handler exists
            if type "cmd_$cmd" &>/dev/null; then
                "cmd_$cmd" "$@"
            else
                print_error "Unknown command: $cmd"
                echo ""
                cmd_help
                exit 1
            fi
            ;;
    esac
}
