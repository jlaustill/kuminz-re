# J90350.00 Firmware Analysis

**Status: analysis in progress** - 610 named functions of 713, 5,221 RAM variable rows (2,906 global rows typed), full decompilation available.

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

Counted from the CSVs for PR #53 round 94 (2026-11-25):

| Metric | Count |
|--------|-------|
| Function rows | 713 (610 named, 103 placeholders) |
| Global variable rows | 5,313 (5,221 in RAM and extended RAM; 2,906 typed) |
| Structure types | 77 (636 fields) |
| Decompiled C code | 1.4 MB |
| Memory regions | 4 (ROM + RAM + EXT_RAM + EEPROM) |

## Files

### Firmware Dumps

| File | Size | Description |
|------|------|-------------|
| `firmware/J90350.00.rom.bin` | 256KB | ROM/Flash memory dump |
| `firmware/J90350.00.ram.bin` | 37KB | RAM snapshot at extraction time |
| `firmware/J90350.00.extended_ram.bin` | 28KB | Extended RAM (scheduler data, J1708 buffers) |
| `firmware/J90350.00.eeprom.bin` | 4KB | EEPROM calibration data: the first 4 KB of the 0x148A-byte EEPROM image (the RAM dump holds the rest at 0x804B0A-0x804F93) |

### Analysis Output

The CSVs in `output/` are the only source of truth; the build reads them and writes only the decompilation.

| File | Description |
|------|-------------|
| `output/function_renames.csv` | Function names and plate comments |
| `output/global_variables.csv` | Named and typed globals |
| `output/structure_definitions.csv` | Structure types and their instances |
| `output/function_definitions.csv` / `output/local_variables.csv` | Prototypes and local variable names |
| `output/enums.csv` / `labels.csv` / `constants.csv` / `arrays.csv` / `deleted_functions.csv` | The other CSV inputs (see `CLAUDE.md`) |
| `output/relocation_map.csv` | Historical function mapping (J90280.05 removed) |
| `output/J90350.00.ghidra.cpp` | Full decompilation, the build's only output |
| `output/firmware_types.hpp` / `firmware_globals.hpp` / `firmware_functions.hpp` | Headers generated from the CSVs (`../scripts/generate_headers.py`) |

### Ghidra Scripts

The build's Ghidra scripts are shared with CM848 in `../scripts/` (see `../CLAUDE.md`). Two stages are CM550's own:
`SetupMemoryMap.java` (the RAM, extended RAM and EEPROM blocks, including the extended RAM dump's 0x80-byte shift) and
`ApplyHardwareRegisters.java` (the MC68336 register names, from the 0xFFxxxx rows of `output/global_variables.csv`).

## Quick Start

```bash
cd ghidra
./analyze.sh build      # fresh binary -> apply every CSV -> output/J90350.00.ghidra.cpp
./analyze.sh verify     # build twice and check that the output is byte-identical
```

The build needs Ghidra 12.2 PUBLIC (the CPU32 language) and JDK 25; `../CLAUDE.md` gives the paths. `npm install`
is only needed for the TypeScript comparison tools below.

## CLI Commands

### Ghidra Headless Analysis

```bash
./ghidra/analyze.sh <command>

Commands:
  build                        Fresh binary -> apply every CSV -> decompilation (the only producer)
  verify                       Build twice and assert byte-identical output
  deletefuncs <addr>...        Record spurious function addresses in output/deleted_functions.csv
  status                       Project status (read-only)
  decompile <addr|name>        Decompile one function from the last build (read-only)
  listfuncs <out>              List every function entry address (read-only)
  classifyfuncs <addrs> <out>  Classify addresses by their incoming references (read-only)
```

The partial commands (`init` / `analyze` / `memmap` / `import` / `export` / ...) were removed: edit the CSVs and run
`build`.

### On-Demand Decompilation

```bash
# By address
./ghidra/analyze.sh decompile 0x22e5e

# By function name
./ghidra/analyze.sh decompile vp44CanMessageDispatcher
```

### Binary Comparison Tools

```bash
npm run stats        # Binary statistics
npm run regions      # Memory region analysis
npm run match        # Function matching
```

## Iterative Analysis Workflow

1. **Make discoveries** - Identify new functions and variables in the decompiled code
2. **Edit CSVs** - `output/function_renames.csv`, `output/global_variables.csv`, ... (the `editing-firmware-csvs` skill has the rules for each file)
3. **Build** - `./ghidra/analyze.sh build` (or `verify`), then check the new names in `output/J90350.00.ghidra.cpp`
4. **Regenerate the headers** after renames (`../CLAUDE.md`)

## Memory Map (MC68336)

See [docs/memory_map.md](docs/memory_map.md) for full details including peripheral registers. The 25 A/D channels' configuration and runtime records, with their Calterm names, are in [docs/analog_sensor_channels.md](docs/analog_sensor_channels.md).

| Region | Address Range | Size | Permissions | Status |
|--------|---------------|------|-------------|--------|
| ROM | 0x000000-0x03FFFF | 256KB | rx | Extracted |
| RAM | 0x800000-0x8091C1 | 37KB | rwx | Extracted |
| EXT_RAM | 0x8091C2-0x80FFFF | 28KB | rwx | Extracted, 0x80 bytes short (below) |
| EEPROM | 0x1000000-0x1001489 | 0x148A (5 KB) | rw- | 0x1000000-0x1000FFF extracted |
| MC68336 Peripherals | 0xFFD000-0xFFFFFF | 12KB | - | Hardware registers (not extractable) |

**The extended RAM dump is 0x80 bytes short.** `J90350.00.extended_ram.bin` (0x6DBE bytes) was read in 128-byte chunks from 0x8091C2 (kuminz-cli asks for 0x8091C2-0x80FFFF, 0x6E3E bytes), and the dump tool skipped one failed chunk - the first (0x8091C2) or the second (0x809242) - without padding. So from 0x8092C2 on, each value sits at file offset address - 0x809242 (address - 0x80 from the region start): of 100 init-time constant stores, 40 match the dump only at address - 0x80 and none only at the address (PR #53 round 87). 0x8091C2-0x8092C1 is uncertain. clip-core's `ECUReader` pads a failed chunk with 0xFF and lists it in `<dump>.gaps.txt` since PR #53 round 88, so new dumps stay aligned. `SetupMemoryMap.java` loads the file's bytes from offset 0x80 at 0x8092C2 and leaves 0x8091C2-0x8092C1 0 (`ScriptUtils.imageFromDumpWithGaps`, PR #53 round 88; it used to load the file at 0x8091C2, 0x80 too high).

**Total extracted: 325KB** - 100% of data memory regions.

## Why J90350.00 is Source of Truth

1. **Live ECU available** - Can test and validate findings
2. **100% memory coverage** - All 4 data regions extracted (ROM + RAM + EXT_RAM + EEPROM)
3. **RAM state snapshot** - See actual runtime values

## Related Projects

- `../CM848_S90140.06_analysis/` - CM848D firmware (PowerPC, HPCR)
- `../../kuminz-cli/` - CLI tool used for extraction
- `../../clip-core/` - CLIP protocol library
