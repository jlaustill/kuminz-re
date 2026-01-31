# Task: Dump CM848 Flash Bank 2 from Live ECU

## Background

During reverse engineering of CM848 firmware, we discovered the ECU has **two flash banks**:

| Bank | Address Range | Size | Status |
|------|---------------|------|--------|
| Bank 1 (ROM) | 0x00000000 - 0x0006FFFF | 448KB | Already dumped as `cm848_rom.bin` |
| Bank 2 (FLASH2) | 0x00500000 - 0x0053D4EA | 245KB | **Needs live dump** |

Bank 2 contains utility functions (sensor processing, math routines) that are called from Bank 1. We extracted it from the e2m calibration file, but a live dump would:
1. Verify the extraction accuracy
2. Capture the exact bytes running on this specific ECU
3. Detect any calibration-specific differences

## Dump Parameters

```
Start Address: 0x00500000
End Address:   0x0053E000  (round up to 253,952 bytes / 248KB)
Expected Size: ~245-250 KB
```

## Current Memory Dumps (for reference)

Located in `originals/`:
| File | Address | Size |
|------|---------|------|
| `cm848_rom.bin` | 0x00000000 | 458,752 bytes (448KB) |
| `cm848_ram.bin` | 0x003FA000 | 286,592 bytes (280KB) |
| `cm848_eeprom.bin` | 0x01000000 | 8,192 bytes (8KB) |
| `cm848_flash2.bin` | 0x00500000 | 251,114 bytes (245KB) - *extracted from e2m* |

## Dump Procedure

### Prerequisites
1. CAN interface configured at 250kbps (J1939 standard)
2. ECU powered and connected
3. kuminz-cli built and working

### Option A: Using kuminz-cli (if it supports custom ranges)

Check if kuminz-cli supports custom address ranges:
```bash
cd /home/linux/code/kuminz-re/kuminz-cli/build
./kuminz-cli --help
```

If custom range supported:
```bash
./kuminz-cli can0 --dump-range 0x00500000 0x0053E000 cm848_flash2_live.bin
```

### Option B: Add Bank 2 dump to kuminz-cli

If not supported, the ECUReader in clip-core may need a new dump function. Key files:
- `clip-core/src/ECUReader.cpp` - Add `dumpFlash2()` method
- `clip-core/include/types/TClipPacket.h` - Add FLASH2 constants:
  ```cpp
  static constexpr uint32_t FLASH2_BASE = 0x00500000;
  static constexpr uint32_t FLASH2_SIZE = 0x3E000;  // 248KB
  ```

The CLIP protocol memory read should work the same way - it's just a different address range.

### Option C: Manual dump via CLIP commands

If needed, use raw CLIP memory read commands. The existing ROM dump logic in ECUReader can be adapted.

## After Dumping

### 1. Save the dump
```bash
cp cm848_flash2_live.bin /home/linux/code/kuminz-re/firmware/CM848_S90140.06_analysis/originals/
```

### 2. Compare with e2m extraction
```bash
cd /home/linux/code/kuminz-re/firmware/CM848_S90140.06_analysis/originals

# Check sizes
ls -la cm848_flash2.bin cm848_flash2_live.bin

# Binary diff
cmp cm848_flash2.bin cm848_flash2_live.bin

# If different, see where:
xxd cm848_flash2.bin > /tmp/e2m.hex
xxd cm848_flash2_live.bin > /tmp/live.hex
diff /tmp/e2m.hex /tmp/live.hex | head -50
```

### 3. If they match
- Great! The e2m extraction is verified
- Can delete the e2m-extracted version or keep both

### 4. If they differ
- Determine if differences are meaningful (code changes vs calibration data)
- Update Ghidra project with live dump:
  ```bash
  # Replace the flash2 file
  cp cm848_flash2_live.bin cm848_flash2.bin

  # Re-run memory map and analysis
  cd ../ghidra
  ./analyze.sh memmap
  ./analyze.sh analyze
  ./analyze.sh export
  ```

## ECU Details

- **ECU:** CM848D (Cummins)
- **Vehicle:** 2004.5 Dodge Ram 5.9L Cummins HPCR
- **Processor:** PowerPC MPC5xx series
- **CAN Protocol:** J1939 at 250kbps
- **Diagnostic Protocol:** CLIP (Cummins proprietary)

## Files Referenced

| Path | Purpose |
|------|---------|
| `originals/cm848_flash2.bin` | Current Bank 2 (extracted from e2m) |
| `scripts/extract_flash2.py` | Script that extracted Bank 2 from e2m |
| `docs/S90140.12.e2m` | Source e2m calibration file |
| `ghidra/analyze.sh` | Ghidra CLI wrapper |
| `../scripts/SetupMemoryMapCM848.java` | Memory map script (includes FLASH2) |

## Success Criteria

- [x] Live dump obtained from ECU at 0x00500000
- [x] Dump size is ~245-250KB (253,952 bytes / 248KB)
- [x] Comparison with e2m extraction completed
- [x] ECU firmware version identified: **V11.46.06** (vs e2m V11.20.13.16)
- [ ] Ghidra project updated if needed
- [x] Document any differences found

## Results (2026-01-31)

**Live dump completed successfully.**

| File | Size | Source |
|------|------|--------|
| `cm848_flash2.bin` | 251,114 bytes | e2m extraction (S90140.12) |
| `cm848_flash2_live.bin` | 253,952 bytes | Live ECU dump |

### Comparison Results

**Major finding: Files are ~79% different (198,265 bytes differ)**

The differences are NOT calibration data - they're different **code addresses** embedded in PowerPC instructions. Example from offset 0x10-0x30:

| Offset | Live | E2M | Interpretation |
|--------|------|-----|----------------|
| 0x14 | `bd88` | `b8fe` | RAM address operand |
| 0x1E | `bdae` | `b924` | RAM address operand |
| 0x28 | `be28` | `b99e` | RAM address operand |

**Conclusion:** The live ECU runs a different firmware version than S90140.12 (the e2m calibration file). The code structure is identical but compiled against a different RAM layout.

### Next Steps

1. Use `cm848_flash2_live.bin` for Ghidra analysis (actual ECU code)
2. Determine ECU's actual firmware version from ROM dump
3. Consider renaming analysis directory to match actual version

### Open Research Questions

The e2m file has different address operands baked into Bank 2 instructions than the live ECU. Two hypotheses:

**Hypothesis A: E2M contains code compiled for a different RAM layout**
- Different firmware versions have different RAM variable addresses
- Bank 2 code references RAM, so instructions have version-specific operands
- E2M (S90140.12) was built for different firmware than what's on this ECU

**Hypothesis B: Calterm queries ECU for Bank 2 binary at runtime**
- E2M file might just be a template/reference
- Calterm uses GetAddressByParameterID (0x16) to resolve addresses
- The Bank 2 section in e2m might not be directly used

**Calterm RE Findings (2026-01-31):**

1. **Does Calterm read Bank 2 code from e2m file or query it from ECU?**
   - **ANSWER: Primarily from e2m file, with ECU query as fallback**
   - CUDL code shows: "Failed to load BDS from parameter" → falls back to "Using Generic e2m for download"
   - BDS = Block Data Structure, defines memory blocks (start/end addresses + data)
   - Calterm tries to query ECU first for BDS, but uses e2m file if query fails

2. **E2M file structure confirms it contains Bank 2 code:**
   ```
   [Header Records]     - CalibrationVersion, ModuleID, etc.
   [Data Records]       - Hex dumps at absolute addresses:
     0x00010000-0x00060000  ROM
     0x00500000-0x00530000  Bank 2 (FLASH2)
     0x01000000            EEPROM
   ```

3. **Why addresses differ between e2m and live ECU:**
   - E2M was built for a specific firmware version (S90140.12)
   - Bank 2 code contains RAM address operands compiled at build time
   - Different firmware versions = different RAM layouts = different operands
   - This ECU has firmware that doesn't match S90140.12

4. **GetAddressByParameterID (0x16) is for parameters only:**
   - Used to resolve tuning parameter addresses in RAM
   - NOT used for code regions like Bank 2
   - Parameters are data, Bank 2 is executable code

**RESOLVED: ECU Firmware Version Identified (2026-01-31)**

| Location | Raw Bytes | Decoded |
|----------|-----------|---------|
| ROM 0x10C | `31 30 30 39 30 32` | "100902" (build date 2002-10-09) |
| EEPROM 0x130 | `00 0B 2E 06 00 24` | **Calibration V11.46.06** |
| EEPROM 0x46 | `31 35 30 34 20 32 52 53 41 4F` | "1504 2RSAO" (calibration ID) |
| EEPROM 0x217 | `43 43` | "CC" (module ID = CM848) |
| EEPROM 0x1D1 | `43 4D 4D 4E 53` | "CMMNS" (Cummins marker) |
| EEPROM 0x286 | VIN | `3D3MU48C94G228471` (2004 Dodge Ram) |
| EEPROM 0x02 | `41 42 43 44 45 46` | "ABCDEF" (security key) |

**Version Mismatch Confirmed:**
- **ECU calibration:** V11.46.06
- **E2M file (S90140.12):** V11.20.13.16

This explains the 79% difference in Bank 2 code - different calibration versions have different RAM layouts, so compiled address operands differ.

**Remaining questions:**
- Does Cummins maintain version-specific e2m files for each firmware release?
- Can the e2m extraction be considered "correct for S90140.12" even if it doesn't match this ECU?

**Files investigated:**
- `calterm3/calterm-crc/decompiled/native/CUDL_ghidra.c` - Download/BDS handling
- `calterm3/calterm-crc/ECU_PROGRAMMING_PROTOCOL.md` - CLIP protocol docs
- `firmware/CM848_S90140.06_analysis/docs/S90140.12.e2m` - E2M file structure
