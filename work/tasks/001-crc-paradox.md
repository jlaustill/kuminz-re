# 001: CRC Paradox Investigation

**Status:** In Progress
**Subproject:** calterm-crc
**Created:** 2024-12-07
**Updated:** 2024-12-13

## Problem Statement

Original Calterm e2m files have CRC values like 0xC5C2 (high bit set), but the extracted algorithm from CRCUtility.dll can only produce values 0x0000-0x7FFE (high bit NEVER set). This is a mathematical impossibility with the current algorithm.

**User Confirmed (Dec 2024):** CRC checking IS enforced - changing the CRC causes Calterm III to reject the file.

## Current Understanding

- Algorithm extracted from CRCUtility.dll - verified correct
- Parity table (256 bytes) confirmed byte-for-byte identical
- Mathematical constraint: `(crc >> 7) & 0x1fe` max = 0x01FE, table max = 0x7FC2
- XOR of these values cannot set high bit (bit 15)
- Tool is self-consistent: fix → verify works perfectly

## Algorithm (Confirmed in Multiple DLLs)

```cpp
// Table generation (tableSelector = 1 for e2m files)
for (int i = 0; i < 256; i++) {
    uint16_t val = (PARITY_TABLE[i] != 0) ? (tableSelector * 2) : 0;
    CRC_TABLE[i] = (uint16_t)(((i * 2) ^ i) << 6) ^ val;
}

// CRC computation (4 params: crc, string, maxLen, tableSelector)
for each byte in string:
    if (byte >= 0x20) {  // skip control characters
        uint8_t idx = (byte ^ crc) & 0xff;
        uint16_t shifted = (crc >> 7) & 0x1fe;
        crc = shifted ^ CRC_TABLE[idx];
    }
```

## Investigation Log

### 2024-12-05: Initial decompilation
- Decompiled 83 .NET DLLs with ILSpy (25MB output, readable C#)
- Decompiled 22 native DLLs with Ghidra (56MB output, needs annotation)
- Found CRC algorithm in multiple DLLs - all identical

### 2024-12-06: Algorithm implementation
- Extracted crcString from KSBaseLibrary
- Implemented in C++ (`calterm3/calterm-crc/crc.cpp`)
- Tool builds and runs successfully

### 2024-12-07: Annotation work
- Renamed 1,496 functions across 19 native DLLs
- Cross-referenced COM interfaces with .NET Interop files
- **Finding:** All DLLs use the same CRC algorithm

### 2024-12-07: Test against original files
| File | Expected CRC | Computed CRC | XOR Delta |
|------|--------------|--------------|-----------|
| BootConfig.e2m | C5C2 | 103C | D5FE |
| INSITE~Generic.e2m | 12EE | 3A16 | 28F8 |
| p3967.e2m | 3E00 | 345A | 0A5A |
| p4110.e2m | 53B8 | 15E6 | 465E |

**Key observation:** Expected CRC C5C2 has high bit SET - mathematically impossible with current algorithm.

### 2024-12-07: Self-consistency test
- Created test file, computed CRC, wrote it back
- Verify command succeeds
- **Finding:** Algorithm is internally consistent, just doesn't match originals

### 2024-12-08: Parity table verification
- Extracted 256-byte parity table from 0x1002ab38 in ConfigurationFiles.dll
- Compared byte-for-byte with our PARITY_TABLE
- **Result:** IDENTICAL - not the source of mismatch

### 2024-12-08: Table selector bruteforce
- Tested tableSelector values 0-255
- None produced matching CRCs for original files
- **Result:** Table selector is not the issue

### 2024-12-08: Standard CRC polynomials search
- Searched for 0x1021 (CRC-CCITT), 0x8005 (CRC-16) in DLLs
- **Result:** Not found - Calterm uses custom algorithm, not standard CRC-16

## Theories

### Explored and Ruled Out
1. **Wrong parity table** - Verified byte-for-byte match
2. **Wrong table selector** - Tested all 256 values
3. **Standard CRC polynomial** - 0x1021, 0x8005 not found in binaries
4. **Wrong DLL version** - Same algorithm in all versions found

### Still To Investigate
- [ ] Legacy Calterm I/II algorithm - May use different CRC entirely
- [ ] GTIS45 vs PreGTIS45 format difference - Different code paths exist
- [ ] File creation tool - Were files created by GTIS tools directly?
- [ ] ReCRC workflow - Does Calterm expect users to re-CRC legacy files?

## ReCRC Feature Discovery

Found in CaltermApplication.dll:
- `SelectableFeatures.CRCFiles` - Menu option to re-compute CRCs
- `ReCRCFile(filename, FileType)` - Dispatches to appropriate Set*CRC method

**Hypothesis:** Legacy files may have "broken" CRCs, and users are expected to ReCRC them when loading into modern Calterm III.

## Key Files

**Implementation:**
- `calterm3/calterm-crc/crc.cpp` - Current C++ implementation
- `calterm3/calterm-crc/REVERSE_ENGINEERING_NOTES.md` - Full documentation

**DLLs Analyzed:**
- `ConfigurationFiles.dll` - Native, CRC at FUN_1008a9b0, parity table at 0x1002ab38
- `CRCUtility.dll` - Mixed C++/CLI wrapper for KSBaseLibrary
- `Assembler.dll` - Multiple CRC functions
- `GTISBinImage.dll` - Binary image checksums

**Test Files:**
- `/home/jlaustill/Software/Calterm III/BootConfig.e2m` - CRC: C5C2
- `/home/jlaustill/Downloads/Cummins ECFG + E2M Files/` - Collection of real e2m files

## Next Steps

1. [ ] Find Calterm I or II binaries and extract their CRC algorithm
2. [ ] Test the ReCRC workflow in Calterm III - load file, use ReCRC, compare
3. [ ] Analyze file creation timestamps vs Calterm versions
4. [ ] Check if there's a "legacy mode" CRC anywhere in the codebase
5. [ ] Try standard CRC-16 variants (CCITT, XMODEM) against original files

## Tool Usage

```bash
cd calterm3/calterm-crc
make
./calterm-crc verify <file.e2m>     # Check CRC
./calterm-crc fix <file.e2m>        # Update CRC to computed value
./calterm-crc compute <file.e2m>    # Show computed CRC
./calterm-crc debug <file.e2m>      # Verbose output
./calterm-crc table [selector]      # Display lookup table
./calterm-crc bruteforce <file.e2m> # Test algorithm variations
```

## Related Tasks

- 002 (E2M Format) - Understanding e2m structure helps CRC analysis
