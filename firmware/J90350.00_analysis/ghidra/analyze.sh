#!/bin/bash
#
# J90350.00 Ghidra Analysis CLI
# Headless analyzer wrapper for reproducible firmware analysis
#

set -e

# Paths
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$SCRIPT_DIR/.."
GHIDRA_DIR="$HOME/code/ghidra"

# Find analyzeHeadless - try built version first, then source scripts
if [ -f "$GHIDRA_DIR/build/dist/ghidra_12.0_DEV/support/analyzeHeadless" ]; then
    GHIDRA_HEADLESS="$GHIDRA_DIR/build/dist/ghidra_12.0_DEV/support/analyzeHeadless"
elif [ -f "$GHIDRA_DIR/support/analyzeHeadless" ]; then
    GHIDRA_HEADLESS="$GHIDRA_DIR/support/analyzeHeadless"
else
    GHIDRA_HEADLESS="$GHIDRA_DIR/Ghidra/RuntimeScripts/Linux/support/analyzeHeadless"
fi

# Project configuration
PROJECT_LOCATION="$SCRIPT_DIR/project"
PROJECT_NAME="J90350"
FIRMWARE_FILE="$PROJECT_DIR/firmware/J90350.00.rom.bin"
SCRIPTS_DIR="$SCRIPT_DIR/scripts"
OUTPUT_DIR="$PROJECT_DIR/output"

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

cmd_init() {
    print_header "INITIALIZING GHIDRA PROJECT"

    check_ghidra

    # Create project directory
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
    print_header "RUNNING AUTO-ANALYSIS"

    check_ghidra

    if [ ! -d "$PROJECT_LOCATION/$PROJECT_NAME.rep" ]; then
        print_error "Project not found. Run '$0 init' first."
        exit 1
    fi

    echo "Running Ghidra auto-analysis..."
    echo "This may take several minutes..."
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -recursive

    print_success "Auto-analysis complete"
}

cmd_memmap() {
    print_header "SETTING UP MEMORY MAP"

    check_ghidra

    if [ ! -d "$PROJECT_LOCATION/$PROJECT_NAME.rep" ]; then
        print_error "Project not found. Run '$0 init' first."
        exit 1
    fi

    FIRMWARE_DIR="$PROJECT_DIR/firmware"

    echo "Adding RAM and EEPROM memory regions..."
    echo "RAM file:    $FIRMWARE_DIR/J90350.00.ram.bin"
    echo "EEPROM file: $FIRMWARE_DIR/J90350.00.eeprom.bin"
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript SetupMemoryMap.java "$FIRMWARE_DIR"

    print_success "Memory map setup complete"
}

cmd_ramvars() {
    print_header "APPLYING RAM VARIABLES FROM J90280.05"

    check_ghidra

    if [ ! -d "$PROJECT_LOCATION/$PROJECT_NAME.rep" ]; then
        print_error "Project not found. Run '$0 init' first."
        exit 1
    fi

    VARS_CSV="$PROJECT_DIR/../J90280.05_analysis/ghidra/CM550.rep/global_variables.csv"

    if [ ! -f "$VARS_CSV" ]; then
        print_error "J90280.05 global_variables.csv not found"
        exit 1
    fi

    echo "Applying RAM variable names from J90280.05..."
    echo "Source: $VARS_CSV"
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript ApplyRamVariables.java "$VARS_CSV"

    print_success "RAM variables applied"
}

cmd_bootstrap() {
    print_header "BOOTSTRAPPING FROM RELOCATION MAP"

    check_ghidra

    RELOCATION_MAP="$OUTPUT_DIR/relocation_map.csv"

    if [ ! -f "$RELOCATION_MAP" ]; then
        print_error "Relocation map not found: $RELOCATION_MAP"
        print_error "Run 'npm run match' first to generate the map"
        exit 1
    fi

    echo "Applying function names from J90280.05..."
    echo "Source: $RELOCATION_MAP"
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript ApplyRelocationMap.java "$RELOCATION_MAP"

    print_success "Bootstrap complete - function names applied"
}

cmd_export() {
    print_header "EXPORTING ANALYSIS"

    check_ghidra

    mkdir -p "$OUTPUT_DIR"

    echo "Exporting to: $OUTPUT_DIR"
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript ExportAnalysis.java "$OUTPUT_DIR"

    print_success "Export complete"
    echo ""
    echo "Files created:"
    ls -la "$OUTPUT_DIR"/*.csv "$OUTPUT_DIR"/*.cpp 2>/dev/null || true
}

cmd_import() {
    print_header "IMPORTING CSV CHANGES"

    check_ghidra

    echo "Importing from: $OUTPUT_DIR"
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript ImportAnalysis.java "$OUTPUT_DIR"

    print_success "Import complete"
}

cmd_structures() {
    print_header "APPLYING STRUCTURE DEFINITIONS"

    check_ghidra

    STRUCT_CSV="$OUTPUT_DIR/structure_definitions.csv"

    if [ ! -f "$STRUCT_CSV" ]; then
        print_error "structure_definitions.csv not found: $STRUCT_CSV"
        exit 1
    fi

    echo "Applying structures from: $STRUCT_CSV"
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript ApplyStructures.java "$STRUCT_CSV"

    print_success "Structure definitions applied"
}

cmd_enums() {
    print_header "APPLYING ENUM DEFINITIONS"

    check_ghidra

    if [ ! -d "$PROJECT_LOCATION/$PROJECT_NAME.rep" ]; then
        print_error "Project not found. Run '$0 init' first."
        exit 1
    fi

    # Default to J90280.05's enums.csv
    ENUMS_CSV="$PROJECT_DIR/../J90280.05_analysis/ghidra/CM550.rep/enums.csv"

    # Check for local copy first
    if [ -f "$OUTPUT_DIR/enums.csv" ]; then
        ENUMS_CSV="$OUTPUT_DIR/enums.csv"
    fi

    if [ ! -f "$ENUMS_CSV" ]; then
        print_error "enums.csv not found"
        print_error "Expected at: $ENUMS_CSV"
        exit 1
    fi

    echo "Applying enum definitions for improved decompilation readability..."
    echo "Source: $ENUMS_CSV"
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript ApplyEnums.java "$ENUMS_CSV"

    print_success "Enum definitions applied"
    echo ""
    echo "Run '$0 export' to regenerate decompilation with enum values."
}

cmd_hwregs() {
    print_header "APPLYING HARDWARE REGISTER NAMES"

    check_ghidra

    if [ ! -d "$PROJECT_LOCATION/$PROJECT_NAME.rep" ]; then
        print_error "Project not found. Run '$0 init' first."
        exit 1
    fi

    # Use J90280.05's global_variables.csv (hardware registers are identical)
    VARS_CSV="$PROJECT_DIR/../J90280.05_analysis/ghidra/CM550.rep/global_variables.csv"

    if [ ! -f "$VARS_CSV" ]; then
        print_error "J90280.05 global_variables.csv not found"
        exit 1
    fi

    echo "Applying MC68336 hardware register names..."
    echo "Source: $VARS_CSV"
    echo "Filter: 0x00FFxxxx peripheral register space"
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript ApplyHardwareRegisters.java "$VARS_CSV"

    print_success "Hardware register names applied"
    echo ""
    echo "Run '$0 export' to see changes like:"
    echo "  DAT_00fffa27 -> REG_SIM_SWSR (Software Watchdog Service Register)"
}

cmd_labels() {
    print_header "APPLYING CODE LABELS"

    check_ghidra

    if [ ! -d "$PROJECT_LOCATION/$PROJECT_NAME.rep" ]; then
        print_error "Project not found. Run '$0 init' first."
        exit 1
    fi

    # Check for local labels.csv first, then fall back to J90280.05
    if [ -f "$OUTPUT_DIR/labels.csv" ]; then
        LABELS_CSV="$OUTPUT_DIR/labels.csv"
    else
        LABELS_CSV="$PROJECT_DIR/../J90280.05_analysis/ghidra/CM550.rep/labels.csv"
    fi

    RELOCATION_MAP="$OUTPUT_DIR/relocation_map.csv"

    if [ ! -f "$LABELS_CSV" ]; then
        print_error "labels.csv not found"
        print_error "Expected at: $LABELS_CSV"
        exit 1
    fi

    echo "Applying code labels for improved decompilation readability..."
    echo "Labels source: $LABELS_CSV"
    if [ -f "$RELOCATION_MAP" ]; then
        echo "Relocation map: $RELOCATION_MAP"
    else
        echo "No relocation map - RAM labels only"
    fi
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript ApplyLabels.java "$LABELS_CSV" "$RELOCATION_MAP"

    print_success "Code labels applied"
    echo ""
    echo "Run '$0 export' to regenerate decompilation with labels."
}

cmd_funcparams() {
    print_header "APPLYING FUNCTION PARAMETER TYPES"

    check_ghidra

    if [ ! -d "$PROJECT_LOCATION/$PROJECT_NAME.rep" ]; then
        print_error "Project not found. Run '$0 init' first."
        exit 1
    fi

    PARAMS_CSV="$OUTPUT_DIR/function_parameters.csv"

    if [ ! -f "$PARAMS_CSV" ]; then
        print_error "function_parameters.csv not found"
        print_error "Expected at: $PARAMS_CSV"
        exit 1
    fi

    echo "Applying function parameter types for improved decompilation readability..."
    echo "Source: $PARAMS_CSV"
    echo ""

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript ApplyFunctionParameters.java "$PARAMS_CSV"

    print_success "Function parameter types applied"
    echo ""
    echo "Run '$0 export' to see changes like:"
    echo "  void vp44CanMessageDispatcher(undefined4 param_1)"
    echo "  -> void vp44CanMessageDispatcher(can_std_rx_desc_t *rx_msg)"
}

cmd_decompile() {
    if [ -z "$2" ]; then
        print_error "Usage: $0 decompile <address|function_name>"
        print_error "Examples:"
        print_error "  $0 decompile 0x22e5e"
        print_error "  $0 decompile vp44CanMessageDispatcher"
        exit 1
    fi

    check_ghidra

    "$GHIDRA_HEADLESS" \
        "$PROJECT_LOCATION" \
        "$PROJECT_NAME" \
        -process "J90350.00.rom.bin" \
        -noanalysis \
        -scriptPath "$SCRIPTS_DIR" \
        -postScript DecompileFunction.java "$2"
}

cmd_full() {
    print_header "FULL ANALYSIS PIPELINE"

    echo "This will run: init -> analyze -> memmap -> ramvars -> bootstrap -> export"
    echo ""

    cmd_init
    cmd_analyze
    cmd_memmap
    cmd_ramvars
    cmd_bootstrap
    cmd_export

    print_header "FULL PIPELINE COMPLETE"
    print_success "J90350.00 analysis is ready!"
    echo ""
    echo "Output files:"
    echo "  - $OUTPUT_DIR/function_renames.csv"
    echo "  - $OUTPUT_DIR/global_variables.csv"
    echo "  - $OUTPUT_DIR/J90350.00.ghidra.cpp"
}

cmd_status() {
    print_header "PROJECT STATUS"

    echo "Project location: $PROJECT_LOCATION"
    echo ""

    if [ -d "$PROJECT_LOCATION/$PROJECT_NAME.rep" ]; then
        print_success "Ghidra project exists"
        echo "  Size: $(du -sh "$PROJECT_LOCATION" | cut -f1)"
    else
        print_warning "Ghidra project not found - run '$0 init'"
    fi

    echo ""

    if [ -f "$OUTPUT_DIR/relocation_map.csv" ]; then
        MATCHED=$(grep -c ",matched" "$OUTPUT_DIR/relocation_map.csv" || echo 0)
        print_success "Relocation map exists ($MATCHED matched functions)"
    else
        print_warning "Relocation map not found - run 'npm run match'"
    fi

    if [ -f "$OUTPUT_DIR/function_renames.csv" ]; then
        FUNCS=$(wc -l < "$OUTPUT_DIR/function_renames.csv")
        print_success "Function names exported ($((FUNCS-1)) functions)"
    else
        print_warning "Function names not exported - run '$0 export'"
    fi

    if [ -f "$OUTPUT_DIR/J90350.00.ghidra.cpp" ]; then
        SIZE=$(du -h "$OUTPUT_DIR/J90350.00.ghidra.cpp" | cut -f1)
        print_success "Decompilation exported ($SIZE)"
    else
        print_warning "Decompilation not exported - run '$0 export'"
    fi
}

cmd_help() {
    echo "J90350.00 Ghidra Analysis CLI"
    echo ""
    echo "Usage: $0 <command> [options]"
    echo ""
    echo "Commands:"
    echo "  init       Import firmware into new Ghidra project (no analysis)"
    echo "  analyze    Run Ghidra auto-analysis on the project"
    echo "  memmap     Add RAM and EEPROM memory regions from live dumps"
    echo "  ramvars    Apply RAM variable names from J90280.05 (5,227 variables)"
    echo "  bootstrap  Apply J90280.05 function names via relocation map"
    echo "  export     Export function names and decompilation to CSV/CPP"
    echo "  import     Import CSV changes back into Ghidra"
    echo "  structures Apply structure definitions from structure_definitions.csv"
    echo "  enums      Apply enum definitions from J90280.05 (776 enums for magic number replacement)"
    echo "  hwregs     Apply MC68336 hardware register names (DAT_00fffa27 -> REG_SIM_SWSR)"
    echo "  labels     Apply code labels from J90280.05 (3,496 labels with address translation)"
    echo "  funcparams Apply function parameter types (param_1 -> rx_msg with type)"
    echo "  decompile  Decompile a single function by address or name"
    echo "  full       Run complete pipeline: init -> analyze -> memmap -> ramvars -> bootstrap -> export"
    echo "  status     Show project status"
    echo "  help       Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 full                    # Complete setup from scratch"
    echo "  $0 decompile 0x22e5e       # Decompile function at address"
    echo "  $0 decompile sendJ1939     # Decompile function by name"
    echo ""
    echo "Typical workflow:"
    echo "  1. $0 full                 # Initial setup"
    echo "  2. Edit output/function_renames.csv"
    echo "  3. $0 import               # Apply changes"
    echo "  4. $0 export               # Update decompilation"
}

# Main entry point
case "${1:-help}" in
    init)
        cmd_init
        ;;
    analyze)
        cmd_analyze
        ;;
    memmap)
        cmd_memmap
        ;;
    ramvars)
        cmd_ramvars
        ;;
    bootstrap)
        cmd_bootstrap
        ;;
    export)
        cmd_export
        ;;
    import)
        cmd_import
        ;;
    structures)
        cmd_structures
        ;;
    enums)
        cmd_enums
        ;;
    hwregs)
        cmd_hwregs
        ;;
    labels)
        cmd_labels
        ;;
    funcparams)
        cmd_funcparams
        ;;
    decompile)
        cmd_decompile "$@"
        ;;
    full)
        cmd_full
        ;;
    status)
        cmd_status
        ;;
    help|--help|-h)
        cmd_help
        ;;
    *)
        print_error "Unknown command: $1"
        echo ""
        cmd_help
        exit 1
        ;;
esac
