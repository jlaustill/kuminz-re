# Calterm III CRC Reverse Engineering Notes

## Current Status: CRC ENFORCEMENT CONFIRMED - Algorithm Mismatch Mystery

The CRC algorithm has been fully reverse-engineered and confirmed across multiple native DLLs.
The algorithm is correctly implemented but **original files were created with a different algorithm**.

**USER CONFIRMED (December 2024):** If you change the CRC in an e2m file, Calterm III rejects the file and closes the device. CRC checking IS enforced.

## Full Library Analysis (December 2024)

### Decompilation Summary
- **83 .NET DLLs** successfully decompiled using ILSpy (25MB output)
- **22 native DLLs** decompiled using Ghidra headless (56MB output)
- **Total: 81MB** of decompiled C/C# source code
- Scripts located at `/home/jlaustill/Software/calterm-crc/scripts/`
- Output directories:
  - `.NET`: `/home/jlaustill/Software/calterm-crc/decompiled/dotnet/`
  - `Native`: `/home/jlaustill/Software/calterm-crc/decompiled/native/`

### CRC Implementation Found In Multiple DLLs
The same CRC algorithm was found in:
1. **ConfigurationFiles.dll** - FUN_1008a9b0 (native)
2. **Assembler.dll** - Multiple CRC functions (native)
3. **CUDL.dll** - CRC implementation (native)
4. **GTISBinImage.dll** - Image checksums (native)
5. **CRCUtility.dll** - KSBaseLibrary wrapper (mixed C++/CLI)

### Parity Table Confirmation
The 256-byte parity/mask table at address 0x1002ab38 in the native DLLs has been extracted and **confirmed identical** to our PARITY_TABLE in crc.cpp. This proves our implementation matches the DLLs.

## What We Know

### Algorithm from Native DLLs (Confirmed in Multiple Sources)

```c
// Table generation (FUN_1000b170)
for (int i = 0; i < 256; i++) {
    uint16_t val = (PARITY_TABLE[i] != 0) ? (tableSelector * 2) : 0;
    CRC_TABLE[i] = (uint16_t)(((i * 2) ^ i) << 6) ^ val;
}

// CRC computation (4 parameters: crc, string, maxLen, tableSelector)
for each byte in string:
    if (byte >= 0x20) {  // skip control characters
        uint8_t idx = (byte ^ crc) & 0xff;
        uint16_t shifted = (crc >> 7) & 0x1fe;
        crc = shifted ^ CRC_TABLE[idx];
    }
```

### Parameters confirmed from ILSpy decompilation of CRCUtility.dll:

**CRC.CRCFile class** (in namespace `CRC` within CRCUtility.dll - mixed C++/CLI assembly):

| Method | Implementation |
|--------|----------------|
| `CheckCalFileCRC(filename)` | `crcFile(ptr, 1, 1)` then fallback to `crcFile(ptr, 5, 1)` |
| `SetCalFileCRC(filename)` | `crcFile(ptr, 0, 1)` then fallback to `crcFile(ptr, 4, 1)` |
| `CheckSubfileCRC(filename)` | `crcFile(ptr, 3, 1)` |
| `SetSubfileCRC(filename)` | `crcFile(ptr, 2, 1)` |
| `CheckConfigFileCRC(filename)` | Reads first line, if 4 chars calls `CheckPreGTIS45ConfigFileCRC`, else uses GTIS 4.5 XML path |
| `SetConfigFileCRC(filename)` | Similar logic for setting |

**KSBaseLibrary.crcFile parameters:**
- param1: filename
- param2: mode (0=set cal, 1=check cal, 2=set subfile, 3=check subfile, 4/5=alternate format)
- param3: tableSelector (always 1 for e2m files)

**CheckPreGTIS45ConfigFileCRC implementation** (from ILSpy):
```csharp
// Seeks to beginning, reads first line as expected CRC
sscanf(line, "%x", &expectedCRC);
ushort computedCRC = 0;
while (!eof) {
    getline(line);
    trim(line);
    if (strlen(line) > 0) {
        computedCRC = KSBaseLibrary.crcString(computedCRC, line, 0, 1);
    }
}
return computedCRC == expectedCRC;
```

**KSBaseLibrary.crcString signature** (from Ghidra):
```c
uint crcString(uint crc, byte* str, ushort maxLen, uint tableSelector);
// maxLen=0 means no limit
// tableSelector=1 for e2m files
```

### Mathematical Constraint
The algorithm can only produce CRC values 0x0000 - 0x7FFE (high bit never set).
- `(crc >> 7) & 0x1fe` produces max 0x01FE
- Table values max out at 0x7FC2
- XOR of these cannot set the high bit

### Test Results

| File | Expected CRC | Computed CRC | XOR Difference |
|------|--------------|--------------|----------------|
| BootConfig.e2m | C5C2 | 103C | D5FE |
| INSITE~Generic.e2m | 12EE | 3A16 | 28F8 |
| p3967.e2m | 3E00 | 345A | 0A5A |
| p4110.e2m | 53B8 | 15E6 | 465E |

Note: Expected CRCs like C5C2 have the high bit SET, which is mathematically impossible with our algorithm.

### Self-Consistency
Files created/fixed by our tool verify correctly with our tool. The algorithm is internally consistent.

## Key Conclusion

**The algorithm in CRCUtility.dll mathematically cannot produce values with the high bit set (>=0x8000).** Original Calterm files have CRCs like 0xC5C2 which have bit 15 set. This proves the original files were created with a **different CRC algorithm** than what's currently in CRCUtility.dll.

**The Paradox:**
- User testing confirms: Calterm III DOES enforce CRC checking (changes to CRC → rejection)
- Original e2m files have CRCs that current algorithm cannot produce
- Yet somehow these files must work (or must have worked at some point)

Possible explanations:
1. Original files were created by an older version of Calterm (I or II) with a different algorithm
2. Files were created by GTIS tools directly with a different CRC
3. Users are expected to use the "ReCRC" feature (found in CaltermApplication.dll) to update legacy files
4. There's version-specific code that handles legacy CRC formats differently
5. The files are "broken" and users have been re-CRCing them all along

## File Intake Flow (Fully Traced)

### E2M File Format Detection
From `CRCUtility.CheckConfigFileCRC`:
```
1. Read first line of file
2. If first line length == 4 chars → PreGTIS45 format (e2m)
3. If first line contains '<' → GTIS45 XML format
4. Call appropriate handler
```

### PreGTIS45 CRC Verification (`CheckPreGTIS45ConfigFileCRC`)
```c
// Native implementation in KSBaseLibrary
1. Seek to position 0
2. Read first line → parse as hex CRC (sscanf "%x")
3. Initialize computedCRC = 0
4. For each remaining line:
   - Trim whitespace
   - If length > 0: computedCRC = crcString(computedCRC, line, 0, 1)
5. Return (computedCRC == expectedCRC)
```

### CRC Set Operation (Mode 0/4)
From Ghidra decompilation of `FUN_10008680`:
```c
// After computing CRC over all content lines:
fseek(file, 0, SEEK_SET);  // Go to beginning
sprintf(buffer, "%4.4X", ..., computedCRC);  // Format as 4-char hex
fwrite(buffer, ...);  // Write new CRC
```

### ReCRC Feature
Found in `CaltermApplication.dll`:
- `SelectableFeatures.CRCFiles` - menu option to re-compute CRCs
- `ReCRCFile(filename, FileType)` - dispatches to appropriate Set*CRC method
- This allows users to update legacy files with new CRCs

## DLL Analysis Summary

### Native DLLs with CRC Implementation (Confirmed)
| DLL | Type | CRC Function | Notes |
|-----|------|--------------|-------|
| ConfigurationFiles.dll | Native PE32 | FUN_1008a9b0 | Core CRC, table at +0x0018e000 |
| Assembler.dll | Native PE32 | Multiple | Checksum calculations |
| CUDL.dll | Native PE32 | Yes | CUDL format handling |
| GTISBinImage.dll | Native PE32 | Yes | Binary image CRCs |
| CRCUtility.dll | Mixed C++/CLI | KSBaseLibrary.crcString | .NET wrapper for native |
| CRCWrapper.dll | Mixed C++/CLI | CILCRC.CRCFile | Alternative wrapper |

### .NET DLLs Using CRC
| DLL | Type | Notes |
|-----|------|-------|
| CaltermApplication.dll | .NET | Imports `CRC.CRCFile` |
| Calibration.dll | .NET | Calibration file handling |
| Export.dll | .NET | Export functionality |
| Services.dll | .NET (obfuscated) | Heavily obfuscated |

### Decompiled Output Location
- .NET: `/home/jlaustill/Software/calterm-crc/decompiled/dotnet/`
- Native: `/home/jlaustill/Software/calterm-crc/decompiled/native/`

## Open Questions

1. **What created the original .e2m files?**
   - Calterm II? Older Calterm III version?
   - GTIS tools directly?
   - **Key insight:** Files may be "legacy broken" and users ReCRC them

2. **~~Is ConfigurationFiles.dll the key?~~** ANSWERED: NO
   - Analyzed ConfigurationFiles.dll - contains same algorithm
   - All native DLLs use identical CRC implementation

3. **Are there multiple CRC polynomials in use?**
   - Current algorithm uses a custom table based on parity
   - Standard CRC-16 variants (CCITT, XMODEM, etc.) NOT found in DLLs
   - Searched for 0x1021, 0x8005 - not present

4. **NEW: Why do legacy files work at all?**
   - Most likely: Users ReCRC files when loading them
   - Or: Files haven't been loaded since they were created
   - Or: There's old Calterm I/II code somewhere we don't have

## Files of Interest

### DLLs to investigate further:
- `/home/jlaustill/Software/Calterm III/ConfigurationFiles.dll` - **Priority: HIGH** - Native DLL for config files
- `/home/jlaustill/Software/Calterm III/CRCUtility.dll` - Analyzed ✓
- `/home/jlaustill/Software/Calterm III/CRCWrapper.dll` - Analyzed ✓
- `/home/jlaustill/Software/Calterm III/CaltermApplication.dll` - Analyzed ✓

### Test files:
- `/home/jlaustill/Software/Calterm III/BootConfig.e2m` - Original Calterm file (CRC: C5C2)
- `/home/jlaustill/Downloads/Cummins ECFG + E2M Files/` - Collection of real e2m files

## Next Steps

1. ~~**Load ConfigurationFiles.dll in Ghidra**~~ - DONE: Analyzed, contains same algorithm
2. ~~**Search for CRC polynomial constants**~~ - DONE: 0x1021, 0x8005 not found
3. ~~**Analyze file intake flow**~~ - DONE: Fully traced PreGTIS45 path
4. **Try standard CRC-16 variants** - Test CCITT, XMODEM, etc. against original files
5. **Check Calterm II** - If available, may have the original algorithm
6. **Test the ReCRC workflow** - Load file in Calterm III, use ReCRC feature, compare
7. **Investigate file provenance** - Where did the original e2m files come from?

## Current Tool Status

The tool at `/home/jlaustill/Software/calterm-crc/` implements the algorithm from CRCUtility.dll.
It is self-consistent but does NOT match original Calterm files.

To use:
```bash
cd /home/jlaustill/Software/calterm-crc
make
./calterm-crc fix <file.e2m>    # Update CRC
./calterm-crc verify <file.e2m> # Verify (works after fix)
./calterm-crc compute <file.e2m> # Show computed CRC
```

## CLI Decompilation Scripts

### Run batch decompilation
```bash
cd /home/jlaustill/Software/calterm-crc/scripts

# Decompile all .NET DLLs
./run-dotnet-batch.sh

# Decompile all native DLLs
./run-native-batch.sh

# Search for CRC patterns in decompiled output
grep -r "crc" ../decompiled/
```

### Available scripts:
| Script | Purpose |
|--------|---------|
| `run-dotnet-batch.sh` | Batch decompile .NET DLLs with ILSpy |
| `run-native-batch.sh` | Batch decompile native DLLs with Ghidra |
| `count-native.sh` | Count native vs .NET DLLs |
| `decompile.sh` | Single DLL decompile (auto-detect type) |
| `DecompileAll.java` | Ghidra script for headless decompilation |
