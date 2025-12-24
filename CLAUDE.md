# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a reverse engineering monorepo for Cummins ECU systems across multiple generations. The project analyzes e2m calibration files, ECU firmware, and diagnostic tools (Calterm, Insite) to understand how Cummins engine controllers work. Since Cummins likely shared code across ECU generations, each reverse-engineered component provides insight into the evolution of their systems.

## Repository Structure

```
kuminz-re/
├── work/             # Task tracking (todo.md + task files)
├── docs/             # Cross-project documentation
│   └── cross-firmware-analysis.md  # Firmware comparison methodology
├── clip-core/        # Shared CLIP protocol library (Qt-free, used by CLI and UI)
├── kuminz-cli/       # CLI tool for ECU memory dumps
├── kuminz-ui/        # Qt5 C++ desktop app for ECU communication
├── e2m-analysis/     # E2M file format reverse engineering (COMPLETE)
├── e2m-db/           # PostgreSQL database for e2m parameter storage
├── firmware/
│   ├── J90280.05_analysis/  # CM550 ECU firmware (reference)
│   ├── J90350.00_analysis/  # CM550 ISB 195hp (live extraction)
│   └── feature_comparison.csv  # Cross-firmware feature matrix
├── calterm3/
│   └── calterm-crc/  # CRC algorithm reverse engineering for e2m files
├── insite9/          # Insite diagnostic tool analysis (100% decompiled)
└── ecu_identification.md  # ECU hardware/software database
```

**Planned additions:** Dodge 2002/2004 truck ECU firmware, additional Calterm/Insite versions.

## Subproject Commands

### clip-core (Shared C++ Library)

**Architecture Principle: Thin Clients, Fat Library**

The `clip-core` library contains ALL CLIP protocol business logic. Both `kuminz-cli` and `kuminz-ui` are thin wrappers that only handle interface-specific concerns (CLI args or Qt widgets).

```bash
cd clip-core/build
cmake .. && make -j4    # Build the library
```

**Components:**
- `ECUReader` - High-level API for memory dumps and ECU communication
- `CLIPSessionManager` - CLIP session state machine
- `CLIPTransportLayer` - Multi-frame transport protocol
- `CLIPInstructionBuilder` - Command packet construction
- `J1939MessageBuilder` - J1939 CAN frame formatting
- `SocketCanAdapter` - Linux SocketCAN implementation
- `ICanAdapter` - CAN adapter interface

**Memory Region Constants (in types/TClipPacket.h):**
| Region | Address | Size |
|--------|---------|------|
| ROM | 0x00000000 | 256KB |
| RAM | 0x00800000 | 37KB |
| Extended RAM | 0x008091C2 | 28KB |
| EEPROM | 0x01000000 | 4KB |

### kuminz-cli (CLI Tool)
```bash
cd kuminz-cli/build
cmake .. && make -j4    # Build the CLI

# Usage (CAN interface must be configured first)
./kuminz-cli can0 --dump-ram [file]           # Dump 37KB RAM
./kuminz-cli can0 --dump-eeprom [file]        # Dump 4KB EEPROM
./kuminz-cli can0 --dump-rom [file]           # Dump 256KB ROM/Flash
./kuminz-cli can0 --dump-extended-ram [file]  # Dump 28KB extended RAM
./kuminz-cli can0 --dump-all [dir]            # Dump all regions
./kuminz-cli --help                           # Show help
```

**Note:** CAN interface must be configured before running:
```bash
sudo ip link set can0 type can bitrate 250000
sudo ip link set can0 up
```

### kuminz-ui (Qt5 C++)
```bash
cd kuminz-ui/build
cmake .. && make -j4    # Build the application
./kuminz-ui             # Run the application
```

**Architecture (thin wrapper over clip-core):**
- `src/can/` - Qt-dependent device discovery (CanDeviceManager only)
- `src/ui/widgets/` - Qt widgets (ConnectionWidget, StatusBarWidget)
- `src/ui/types/` - UI-layer type definitions (enums, structs)
- Links to `clip-core` for all protocol logic

**Key Components:**
- `CanDeviceManager` - Detects USB CAN adapters, manages slcand lifecycle
- `ConnectionWidget` - Two-section UI: Adapter Setup + ECU Connection
- `ECUReader` - From clip-core library (CLIP protocol session management)

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

### Firmware Analysis (Ghidra + CLI)

Two firmware versions are actively analyzed with the **same CLI workflow**:

| Firmware | Source | CSV Location | Apply Command |
|----------|--------|--------------|---------------|
| J90280.05 | Static binary (reference) | `output/` | `./analyze.sh import && export` |
| J90350.00 | Live ECU dump | `output/` | `./analyze.sh import && export` |

**Unified CLI Workflow (Both Firmwares):**
```bash
cd firmware/[J90280.05|J90350.00]_analysis/ghidra
# 1. Edit CSV files in ../output/
./analyze.sh import      # Apply CSV changes to Ghidra
./analyze.sh export      # Regenerate decompilation
# Verify: ../output/[firmware].ghidra.cpp
```

**Shared Scripts:** All Ghidra Java scripts are in `firmware/scripts/` (shared by all firmwares).

**Common Rules:**
- All changes go through CSV files (function_renames.csv, global_variables.csv, enums.csv, etc.)
- Never modify Ghidra directly - CSV is the source of truth
- See `firmware/CLAUDE.md` for detailed workflow and command reference

### calterm3/calterm-crc (C++)
```bash
cd calterm3/calterm-crc
make                     # Build the CRC tool
./calterm-crc verify <file.e2m>   # Verify CRC
./calterm-crc fix <file.e2m>      # Fix CRC
./calterm-crc compute <file.e2m>  # Show computed CRC
```

### insite9 (Decompiled Analysis)
```bash
cd insite9

# Decompilation (already complete)
./scripts/insite-dotnet-batch.sh   # .NET DLLs → C# source
./scripts/insite-native-batch.sh   # Native DLLs → C pseudocode (slow)
./scripts/extract-databases.sh     # Access databases → CSV

# Search decompiled code
grep -r "J1939" decompiled/dotnet/      # Protocol references in .NET
grep -r "CLIP" decompiled/dotnet/       # CLIP protocol usage
grep -r "CAN" decompiled/native/        # CAN bus code in native DLLs

# Database analysis
cat decompiled/databases/FnPDatabase/schema.sql  # View schema
ls decompiled/databases/FnPDatabase/             # List 358 tables
```

**Decompiled Output (294MB total):**
- `decompiled/dotnet/` - 105 .NET DLLs → 16MB C# source
- `decompiled/native/` - 253 Native DLLs → 269MB C pseudocode
- `decompiled/databases/` - 362 tables extracted from Access DBs

**Key DLLs for Analysis:**
| DLL | Type | Purpose |
|-----|------|---------|
| CureCore | Native | Core diagnostic engine (5MB) |
| DeviceControl | Native | ECU communication layer |
| DataMonitoring | Native | Parameter monitoring |
| ToolSecurity | Native | Security/licensing (3.2MB, complex) |
| Cummins.INSITE.Kernel.ECMServices | .NET | ECU service interfaces |

**Notable Databases:**
- `FnPDatabase/` - 358 tables (FEATURE_*, PARAMETER_*, SUBFEATURE_*)
- `INSITEHelp/` - 56,834 help topics mapped to fault codes

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
6. **No Insite Traffic Capture** - Capturing real Insite diagnostic traffic is NOT an option; protocol must be reverse-engineered from firmware analysis and decompiled code only

## Task Tracking System

Project tasks are tracked in `/work/` with a simple markdown-based system.

### Structure
```
/work/
├── todo.md              # Master task list (one line per item)
└── tasks/
    ├── 001-crc-paradox.md
    ├── 002-e2m-format.md
    └── ...
```

### Status Markers
- `[ ]` Todo
- `[>]` In Progress
- `[?]` Testing
- `[X]` Done

### todo.md Format
```
001 [>] [calterm-crc] Resolve CRC paradox - why legacy files have impossible values
002 [X] [e2m-analysis] Decode e2m file format (100% complete)
```

### Session Workflow

**Session Startup:**
1. Read `/work/todo.md` for current task status
2. Review any `[>]` in-progress tasks in `/work/tasks/`
3. Continue work or pick next `[ ]` todo item

**During Work:**
- Update task file with findings, decisions, progress
- Mark subtasks complete as you go
- Add investigation log entries with dates

**Session End:**
- Update todo.md status if changed
- Add session log entry to active task file
- Note any new tasks discovered

### Task File Templates

**Investigation tasks** (research/reverse-engineering):
- Problem Statement, Current Understanding
- Investigation Log (dated entries, what was tried, findings)
- Theories to Explore (with checkboxes)
- Key Files

**Implementation tasks** (building features):
- Goal, Requirements (with checkboxes)
- Design Decisions (dated entries with rationale)
- Implementation Progress
- Testing checklist

## Cross-ECU Analysis Strategy

Each ECU firmware analyzed should:
1. Document memory layout and addressing schemes
2. Identify shared code patterns with other ECU versions
3. Track evolutionary changes between firmware versions
4. Build a unified parameter database across ECU generations

### Documentation Files

| File | Purpose |
|------|---------|
| `ecu_identification.md` | ECU hardware/software identification database |
| `docs/cross-firmware-analysis.md` | Methodology for comparing firmware versions |
| `firmware/feature_comparison.csv` | Cross-firmware feature presence matrix |

### Feature Tracking Categories

When comparing firmware versions, track four types of differences:

1. **Excluded Features** - Code that doesn't exist due to `#ifdef` preprocessor directives
2. **Method Versioning** - Same function with code changes between versions
3. **Added Features** - New functionality in newer firmware
4. **Removed Features** - Features dropped (often detected via engine parameters)

### Relocation Map

Each firmware analysis directory contains `output/relocation_map.csv` mapping function addresses between firmware versions:

| Status | Meaning |
|--------|---------|
| `matched` | Identical function at different address |
| `similar` | Function exists but code differs |
| `not_found` | Function doesn't exist in target |

**Current J90280.05 → J90350.00:** 293 matched, 350 similar, 150 not_found
