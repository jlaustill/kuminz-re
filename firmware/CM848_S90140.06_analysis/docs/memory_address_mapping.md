# CM848 Memory Address Mapping

This document explains how e2m virtual addresses (used by Calterm) translate to actual ECU memory addresses.

## Memory Regions

The CM848 ECU has the following memory regions:

| Region | Address Range | Size | Purpose |
|--------|---------------|------|---------|
| Bank 1 (ROM) | 0x00000000 - 0x0006FFFF | 448 KB | Main firmware code |
| Bank 2 (FLASH2) | 0x00500000 - 0x0053D4EA | 245 KB | Utility functions |
| RAM | 0x003FA000 - 0x0043FE80 | 280 KB | Working memory |
| EEPROM | 0x01000000 - 0x01001FFF | 8 KB | Non-volatile storage |

## E2M Virtual Address Format

Calterm uses virtual addresses in the format: `0x01XXYYYYY`

- `01`: Calibration space prefix
- `XX`: Column3 value (module/block identifier)
- `YYYY`: Column4 value (offset within block)

### Address Translation Formula

```
Actual_RAM_Address = Base[Column3] + Column4
```

Each Column3 value maps to a unique base address. These mappings are ECU-specific.

## Known Column3 Mappings (CM848)

| Column3 | Base Address | Description | Parameter Count |
|---------|--------------|-------------|-----------------|
| 81AE | 0x00408ee2 | CBD calibration | ~50 |
| 81AF | TBD | CBD learned trims | ~20 |
| 81B0 | TBD | CBD monitoring | ~15 |

### Example: CBD_Enable

- **Calterm address**: 0x0181AE14
- **Column3**: 81AE → Base = 0x00408ee2
- **Column4**: 0x14 → Offset = 20 bytes
- **Actual RAM**: 0x00408ee2 + 0x14 = **0x00408ef6**

## Calibration Copy at Boot

The function `copyCalibrationToRam` at 0x00000340 copies ROM defaults to RAM:

```c
void copyCalibrationToRam(void) {
    // Source: ROM 0x00003c30 - 0x00007f5f (17,200 bytes)
    // Dest:   RAM 0x3f9800 - 0x3fdb30

    puVar1 = &DAT_00003c30;       // ROM calibration defaults
    puVar2 = (undefined4 *)0x3f97fc;  // RAM destination - 4
    do {
        puVar2 = puVar2 + 1;
        *puVar2 = *puVar1;
        puVar1 = puVar1 + 1;
    } while (puVar1 < &DAT_00007f60);
}
```

### Calibration Block A (copyCalibrationToRam)

| Attribute | Value |
|-----------|-------|
| ROM Source | 0x00003c30 - 0x00007f5f |
| RAM Destination | 0x003f9800 - 0x003fdb30 |
| Size | 17,200 bytes (0x4330) |
| Offset | RAM - ROM = 0x3f5bd0 |

**Note**: This block does NOT include the CBD calibration (0x00408exx region).

### Calibration Block B (CBD Parameters)

The CBD calibration at 0x00408exx is in a different region:

| Attribute | Value |
|-----------|-------|
| RAM Address | 0x00408ee2 - 0x00408f28 |
| Size | ~70 bytes |
| Contains | CBD thresholds, gains, DFT coefficients |

This region is within the larger RAM space but is initialized separately (mechanism TBD).

## Diagnostic Memory Access

The function `diagMemoryReadHandler` at 0x00001b48 handles memory read requests:

```c
if (address < 0x1000000) {
    // Direct memory copy (ROM/RAM access)
    FUN_003fc77c(dest, address, length);
} else {
    // EEPROM access via hardware interface
    eepromReadWords(address, dest, length);
}
```

This shows:
- Addresses < 0x1000000 (16 MB): Direct memory access
- Addresses >= 0x1000000: EEPROM/special hardware access

## Cross-Reference: E2M Parameters vs RAM Variables

| E2M Parameter | Calterm Address | RAM Address | Ghidra Variable |
|---------------|-----------------|-------------|-----------------|
| CBD_Enable | 0x0181AE14 | 0x00408ef6 | cbd_enable_flag |
| CBD_Lower_Speed_Limit | 0x0181AE06 | 0x00408ee8 | cbd_rpm_lower_limit |
| CBD_Upper_Speed_Limit | 0x0181AE04 | 0x00408ee6 | cbd_rpm_upper_limit |
| CBD_Trim_Max | 0x0181AE0C | 0x00408eee | cbd_trim_max_limit |
| CBD_Trim_Min | 0x0181AE0E | 0x00408ef0 | cbd_trim_min_limit |

## Open Questions

1. **How is the 0x00408exx calibration region initialized?**
   - Not covered by `copyCalibrationToRam`
   - May be in a different flash bank
   - May be mapped directly to flash (read-only)

2. **Complete Column3 mapping table**
   - 81AE confirmed
   - Other CBD blocks (81AF, 81B0) need verification
   - Hundreds of other Column3 values exist

3. **Relationship between e2m file binary and ECU flash**
   - E2M file contains both metadata and binary data
   - Binary data starts at 0x00008000 in e2m file
   - Need to map e2m binary offsets to ECU flash addresses

## Related Documentation

- [CBD Enable Experiment](cbd_enable_experiment.md) - CBD parameter addresses
- [Injector Feedback System](injector_feedback_system.md) - CBD algorithm documentation
- [E2M Integration](E2M_INTEGRATION.md) - E2M file format overview
