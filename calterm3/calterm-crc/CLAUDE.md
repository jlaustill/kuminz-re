# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a reverse-engineering project for the Calterm III CRC algorithm used in Cummins engine calibration (.e2m) files. The main tool computes and verifies CRCs for e2m configuration files. The project also includes batch decompilation scripts for analyzing Calterm III DLLs.

**Important Discovery:** The CRC algorithm in current CRCUtility.dll can only produce values 0x0000-0x7FFE (high bit never set), but original Calterm files have CRCs like 0xC5C2. This indicates original files were created with a different (older) algorithm.

## Workflow Note

**CLI-Only Workflow:** All analysis is done using CLI tools and text editors. The Ghidra GUI project is abandoned. Work directly with the decompiled `.c` and `.cs` files in the `decompiled/` directory.

## Build Commands

```bash
make              # Build the calterm-crc tool
make clean        # Remove compiled binary
```

## Usage

```bash
./calterm-crc verify <file.e2m>     # Check CRC (use after 'fix')
./calterm-crc fix <file.e2m>        # Update file with computed CRC
./calterm-crc compute <file.e2m>    # Show computed CRC without modifying
./calterm-crc debug <file.e2m>      # Verbose output for debugging
./calterm-crc table [selector]      # Display CRC lookup table
./calterm-crc bruteforce <file.e2m> # Test various algorithm variations
```

## Decompilation Scripts

Located in `scripts/`:

```bash
./scripts/run-dotnet-batch.sh       # Batch decompile .NET DLLs (ILSpy)
./scripts/run-native-batch.sh       # Batch decompile native DLLs (Ghidra)
./scripts/decompile.sh <dll>        # Auto-detect and decompile single DLL
./scripts/count-native.sh           # Count native vs .NET DLLs
```

**Dependencies:**
- ILSpy CLI: `~/.dotnet/tools/ilspycmd`
- Ghidra headless: `/opt/ghidra/support/analyzeHeadless`
- RetDec (optional): `/snap/retdec/current/bin/retdec-decompiler.py`

## Project Structure

- `crc.cpp` - Main CRC tool implementation (C++17)
- `scripts/` - Batch decompilation scripts
- `decompiled/dotnet/` - Decompiled .NET DLLs (87 files, C# source, already readable)
- `decompiled/native/` - Decompiled native DLLs (22 files, C pseudocode, needs annotation)
- `REVERSE_ENGINEERING_NOTES.md` - Detailed findings and algorithm documentation

## Decompiled Code Status

| Type | Files | Size | Readability |
|------|-------|------|-------------|
| .NET | 87 | 25MB | Excellent - meaningful names preserved |
| Native | 22 | 56MB | Poor - 90% auto-generated names (FUN_*, DAT_*, param_*) |

Native code annotation uses rename mapping files and sed/grep for bulk renaming.

## CRC Algorithm (from crc.cpp)

The algorithm was reverse-engineered from `KSBaseLibrary.crcString`:

```cpp
// Table generation (tableSelector typically = 1)
for (int i = 0; i < 256; i++) {
    uint16_t val = (PARITY_TABLE[i] != 0) ? (tableSelector * 2) : 0;
    CRC_TABLE[i] = (uint16_t)(((i * 2) ^ i) << 6) ^ val;
}

// CRC computation
for each byte in string:
    if (byte > 0x1f) {  // skip control characters
        uint8_t idx = (byte ^ crc) & 0xff;
        uint16_t shifted = (crc >> 7) & 0x1fe;
        crc = shifted ^ CRC_TABLE[idx];
    }
```

## E2M File Format

- Line 1: 4-character uppercase hex CRC (e.g., "C5C2")
- Remaining lines: INI-style configuration data
- CRC computed over all lines after line 1

## Calterm III Installation Path

The Calterm III installation being analyzed is at:
`/home/jlaustill/Software/Calterm III/`

Test e2m files are at:
`/home/jlaustill/Downloads/Cummins ECFG + E2M Files/`
