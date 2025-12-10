# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a reverse engineering monorepo for Cummins ECU systems across multiple generations. The project analyzes e2m calibration files, ECU firmware, and diagnostic tools (Calterm, Insite) to understand how Cummins engine controllers work. Since Cummins likely shared code across ECU generations, each reverse-engineered component provides insight into the evolution of their systems.

## Repository Structure

```
kuminz-re/
├── kuminz-ui/        # Qt5 C++ desktop app for ECU communication
├── e2m-analysis/     # E2M file format reverse engineering (COMPLETE)
├── e2m-db/           # PostgreSQL database for e2m parameter storage
├── firmware/
│   └── J90280.05_analysis/  # CM550 ECU firmware (first target)
├── calterm3/
│   └── calterm-crc/  # CRC algorithm reverse engineering for e2m files
└── insite3/          # Insite diagnostic tool analysis (future)
```

**Planned additions:** Dodge 2002/2004 truck ECU firmware, additional Calterm/Insite versions.

## Subproject Commands

### kuminz-ui (Qt5 C++)
```bash
cd kuminz-ui/build
cmake .. && make -j4    # Build the application
./kuminz-ui             # Run the application
```

**Architecture:**
- `src/can/` - CAN adapter abstraction (SocketCanAdapter, CanDeviceManager)
- `src/clip/` - CLIP protocol implementation for Cummins ECU communication
- `src/ui/widgets/` - Qt widgets (ConnectionWidget, StatusBarWidget)
- `src/ui/types/` - UI-layer type definitions (enums, structs)

**Key Components:**
- `CanDeviceManager` - Detects USB CAN adapters, manages slcand lifecycle
- `ConnectionWidget` - Two-section UI: Adapter Setup + ECU Connection
- `ECUReader` - CLIP protocol session management

**Hardware Support:**
- OBDLink EX (primary dev device, USB ID 0403:6015)
- OBDLink SX/MX, CANable, generic SLCAN adapters
- Native SocketCAN interfaces

**SLCAN Setup Flow:**
1. Detect devices via `/dev/serial/by-id/` symlinks
2. `pkexec sh -c "slcand -o -c -s5 /dev/ttyUSBx canX && ip link set canX up"`
3. Single password prompt via PolicyKit graphical dialog

**Critical Notes:**
- Use `pkill -x slcand` (exact match), NOT `pkill -f 'slcand.*'` (pattern match kills the shell too!)
- Default speed: 250kbps (-s5) for J1939 Cummins ECUs
- SocketCAN interfaces are network interfaces, use `candump can0` not `candump /dev/can0`

### e2m-analysis (TypeScript)
```bash
cd e2m-analysis
npm install
npm run typecheck        # TypeScript type checking
npm run lint             # ESLint
npm run analyze:all      # Run all analysis tools
npx tsx src/tools/validate-against-firmware.ts  # Validate addresses
npx tsx src/tools/generate-verified-lookup.ts   # Generate lookup table
```

### e2m-db (TypeScript + PostgreSQL)
```bash
cd e2m-db
npm install
npm run import           # Import e2m CSV data to PostgreSQL
```

### firmware/J90280.05_analysis (Ghidra + TypeScript)
```bash
cd firmware/J90280.05_analysis
npm install
npm run enhance-csv      # Process CSV files for Ghidra
./setup-hooks.sh         # Setup git hooks for CSV sorting
```

**Ghidra Workflow:**
- All changes go through CSV files in `ghidra/CM550.rep/`
- Press `Ctrl+Shift+E` in Ghidra to run ApplyAndExport
- NEVER use Ghidra MCP tools to modify data (read-only analysis only)

### calterm3/calterm-crc (C++)
```bash
cd calterm3/calterm-crc
make                     # Build the CRC tool
./calterm-crc verify <file.e2m>   # Verify CRC
./calterm-crc fix <file.e2m>      # Fix CRC
./calterm-crc compute <file.e2m>  # Show computed CRC
```

## Architecture Notes

### kuminz-ui Design Patterns

**Separation of Concerns:**
- Adapter Setup (hardware layer) and ECU Connection (protocol layer) are independent
- Each has its own state enum, status indicator, and button
- `EAdapterState`: NotReady, Setting_Up, Ready, Error
- `EConnectionState`: Disconnected, Connecting, Connected, Error

**Device Detection:**
- Native SocketCAN: Scan `/sys/class/net/*/type` for value "280" (ARPHRD_CAN)
- Serial SLCAN: Scan `/dev/serial/by-id/` symlinks, parse vendor/product from filename
- Running slcand: Scan `/proc/*/cmdline` for slcand processes, map serial→interface

**Type Conventions (matches global CLAUDE.md):**
- `E` prefix for enums (EAdapterState, EConnectionState)
- `T` prefix for structs (TCanDevice, TConnectionSettings)
- `I` prefix for interfaces (ICanAdapter)

### E2M File Format (100% Decoded)
- CSV format with 2 header rows, up to 16 columns
- Memory Address Formula: `BaseLookup[Column3] + Column4`
- 521 unique Column3 → Base Address mappings discovered
- Column 14 = Group ID linking to Type G headers

### Ghidra CSV Knowledge Database
For firmware analysis, discoveries are stored in CSV files (e.g., `ghidra/CM550.rep/`):
- `function_renames.csv` - Function names by address
- `global_variables.csv` - Typed global variables
- `structure_definitions.csv` - C structure definitions
- `enums.csv` - State machine enumerations
- `labels.csv` - Control flow labels

## Critical Constraints

1. **TypeScript Only** - No Python in e2m-analysis or e2m-db projects
2. **C++/Qt5 for kuminz-ui** - Desktop app uses Qt5 with CMake build system
3. **CSV-Only Workflow** - All Ghidra changes must go through CSV files, never direct modification
4. **Never Modify Originals** - Files in `originals/` directories are read-only source data
5. **Decimal in Names** - Use decimal (not hex) in variable/function names for readability
6. **MCP Tools Read-Only** - Ghidra MCP integration is for analysis only, not modification

## Cross-ECU Analysis Strategy

Each ECU firmware analyzed should:
1. Document memory layout and addressing schemes
2. Identify shared code patterns with other ECU versions
3. Track evolutionary changes between firmware versions
4. Build a unified parameter database across ECU generations
