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

- [ ] Live dump obtained from ECU at 0x00500000
- [ ] Dump size is ~245-250KB
- [ ] Comparison with e2m extraction completed
- [ ] Ghidra project updated if needed
- [ ] Document any differences found
