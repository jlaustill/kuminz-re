# J90350.00 Firmware Analysis

**Status: Analysis Complete** - 489 named functions, 5,372 RAM variables, full decompilation available.

## ECU Details

| Field | Value |
|-------|-------|
| **Firmware Version** | J90350.00 |
| **Calibration Code** | 100898231658 |
| **Engine** | Cummins ISB 195hp |
| **ECU Type** | CM550 |
| **Serial Number** | T03942860 |
| **Compilation Date** | October 8, 1998 |

## Extraction Details

| Field | Value |
|-------|-------|
| **Extraction Date** | 2024-12-16 |
| **Method** | Service 0x4A memory read via kuminz-cli |
| **CAN Interface** | can0 (OBDLink EX @ 250kbps) |
| **Protocol** | J1939 Transport Protocol (RTS/CTS/DT) |

## Current Analysis State

| Metric | Count |
|--------|-------|
| Named functions | 489 |
| RAM variables | 5,372 |
| Total global variables | 5,866 |
| Structure definitions | 274 fields |
| Decompiled C code | 1.0MB |
| Memory regions | 4 (ROM + RAM + EXT_RAM + EEPROM) |

## Files

### Firmware Dumps

| File | Size | Description |
|------|------|-------------|
| `firmware/J90350.00.rom.bin` | 256KB | ROM/Flash memory dump |
| `firmware/J90350.00.ram.bin` | 37KB | RAM snapshot at extraction time |
| `firmware/J90350.00.extended_ram.bin` | 28KB | Extended RAM (scheduler data, J1708 buffers) |
| `firmware/J90350.00.eeprom.bin` | 4KB | EEPROM calibration data |

### Analysis Output

| File | Description |
|------|-------------|
| `output/function_renames.csv` | 489 named functions |
| `output/global_variables.csv` | 5,866 named variables |
| `output/relocation_map.csv` | Function mapping from J90280.05 |
| `output/structure_definitions.csv` | 219 structure field definitions |
| `output/J90350.00.ghidra.cpp` | Full decompilation (1.1MB) |

### Ghidra Scripts

| Script | Purpose |
|--------|---------|
| `ghidra/scripts/ApplyRelocationMap.java` | Bootstrap function names from J90280.05 |
| `ghidra/scripts/ApplyRamVariables.java` | Apply RAM variable names from J90280.05 |
| `ghidra/scripts/SetupMemoryMap.java` | Add RAM and EEPROM memory regions |
| `ghidra/scripts/ExportAnalysis.java` | Export to CSV and decompiled C |
| `ghidra/scripts/ImportAnalysis.java` | Import CSV changes |
| `ghidra/scripts/DecompileFunction.java` | On-demand function decompilation |

## Quick Start

```bash
# Install dependencies
npm install

# Complete analysis from scratch (takes ~2 minutes)
npm run ghidra:full

# Or run individual steps:
npm run ghidra:init       # Import firmware
npm run ghidra:analyze    # Auto-analysis
npm run ghidra:memmap     # Add RAM + EEPROM regions
npm run ghidra:ramvars    # Apply 5,227 RAM variable names
npm run ghidra:bootstrap  # Apply 643 function names
npm run ghidra:export     # Export CSV + decompilation
```

## CLI Commands

### Ghidra Headless Analysis

```bash
./ghidra/analyze.sh <command>

Commands:
  init       Import firmware into Ghidra project
  analyze    Run Ghidra auto-analysis
  memmap     Add RAM and EEPROM memory regions
  ramvars    Apply RAM variable names from J90280.05
  bootstrap  Apply function names via relocation map
  export     Export to CSV and decompiled C
  import     Import CSV changes back into Ghidra
  decompile  Decompile a single function
  full       Run complete pipeline
  status     Show project status
```

### On-Demand Decompilation

```bash
# By address
npm run ghidra:decompile -- 0x22e5e

# By function name
npm run ghidra:decompile -- vp44CanMessageDispatcher
```

### Binary Comparison Tools

```bash
npm run stats        # Binary statistics
npm run regions      # Memory region analysis
npm run match        # Function matching
```

## Iterative Analysis Workflow

1. **Make discoveries** - Identify new functions/variables in decompiled code
2. **Edit CSVs** - Update `output/function_renames.csv` or `output/global_variables.csv`
3. **Import changes** - `npm run ghidra:import`
4. **Re-export** - `npm run ghidra:export`

## Memory Map (MC68336)

See [docs/memory_map.md](docs/memory_map.md) for full details including peripheral registers.

| Region | Address Range | Size | Permissions | Status |
|--------|---------------|------|-------------|--------|
| ROM | 0x000000-0x03FFFF | 256KB | rx | Extracted |
| RAM | 0x800000-0x8091C1 | 37KB | rwx | Extracted |
| EXT_RAM | 0x8091C2-0x80FF7F | 28KB | rwx | Extracted |
| EEPROM | 0x1000000-0x1000FFF | 4KB | rw- | Extracted |
| MC68336 Peripherals | 0xFFD000-0xFFFFFF | 12KB | - | Hardware registers (not extractable) |

**Total extracted: 325KB** - 100% of data memory regions.

## Comparison with J90280.05

| Metric | Value |
|--------|-------|
| Byte-level similarity | 20.2% |
| Function match (≥80%) | 293 (36.9%) |
| Function similar (60-80%) | 350 (44.1%) |
| Combined usable | **643 (81.1%)** |

**Key finding:** Same codebase, different memory layout. Boot code is structurally identical.

## Why J90350.00 is Source of Truth

1. **Live ECU available** - Can test and validate findings
2. **100% memory coverage** - All 4 data regions extracted (ROM + RAM + EXT_RAM + EEPROM)
3. **RAM state snapshot** - See actual runtime values
4. **J90280.05 as reference** - 793 functions and 6,108 variables to bootstrap from

## Related Projects

- `../J90280.05_analysis/` - Reference firmware (793 functions named)
- `../../kuminz-cli/` - CLI tool used for extraction
- `../../clip-core/` - CLIP protocol library
