# CM848 Memory Address Mapping

This document maps the CM848D ECU memory regions and known address assignments discovered through firmware analysis, live ECU reads, and EEPROM dumps.

> **Note:** The e2m virtual address translation (Column3 → base address) was decoded for the CM550. The CM848D section below is **theoretical** — based on the same formula pattern but only one Column3 mapping (0x81AE(33198)) has been confirmed via live ECU reads. The S90140.12 e2m file in this directory is a different calibration version (V11.20.13.16) than the ECU (V11.46.06), so its addresses may not match.

## Memory Region Files

Detailed byte-level memory maps are in the companion files. Each file uses line-numbered format where the number is the decimal offset within that region:

| File | Region | Offset | Size |
|------|--------|--------|------|
| [bank1.txt](bank1.txt) | Bank 1 (ROM) | 0x00000000(0) | 448 KB |
| [bank2.txt](bank2.txt) | Bank 2 (FLASH2) | 0x00500000(5242880) | 245 KB |
| [ram.txt](ram.txt) | RAM | 0x003FA000(4169728) | 280 KB |
| [eeprom.txt](eeprom.txt) | EEPROM | 0x01000000(16777216) | 8 KB |

### File Format

```
# offset 0x01000000(16777216)
# comments start with #
0 DeviceId low byte
1 DeviceId high byte
# start data plate
2 VIN byte 1
3 VIN byte 2
```

- Line numbers are decimal offsets from the region base address
- To get the absolute address: `offset + base`
- Comment lines start with `#` and do not consume an address

## Memory Regions

The CM848 ECU has the following memory regions:

| Region | Address Range | Size | Purpose |
|--------|---------------|------|---------|
| Bank 1 (ROM) | 0x00000000(0) - 0x0006FFFF(458751) | 448 KB | Main firmware code |
| Bank 2 (FLASH2) | 0x00500000(5242880) - 0x0053D4EA(5493994) | 245 KB | Utility functions |
| RAM | 0x003FA000(4169728) - 0x0043FE80(4456064) | 280 KB | Working memory |
| EEPROM | 0x01000000(16777216) - 0x01001FFF(16785407) | 8 KB | Non-volatile storage |

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
| 0x81AE(33198) | 0x00408EE2(4231906) | CBD calibration | ~50 |
| 0x81AF(33199) | TBD | CBD learned trims | ~20 |
| 0x81B0(33200) | TBD | CBD monitoring | ~15 |

### Example: CBD_Enable

- **Calterm address**: 0x0181AE14(25259540)
- **Column3**: 0x81AE(33198) → Base = 0x00408EE2(4231906)
- **Column4**: 0x14(20) → Offset = 20(20) bytes
- **Actual RAM**: 0x00408EE2(4231906) + 0x14(20) = **0x00408EF6(4231926)**

## Calibration Copy at Boot

The function `copyCalibrationToRam` at 0x00000340(832) copies ROM defaults to RAM:

```c
void copyCalibrationToRam(void) {
    // Source: ROM 0x00003C30(15408) - 0x00007F5F(32607) (17,200 bytes)
    // Dest:   RAM 0x003F9800(4167680) - 0x003FDB30(4184880)

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
| ROM Source | 0x00003C30(15408) - 0x00007F5F(32607) |
| RAM Destination | 0x003F9800(4167680) - 0x003FDB30(4184880) |
| Size | 17,200(17200) bytes (0x4330(17200)) |
| Offset | RAM - ROM = 0x003F5BD0(4152272) |

**Note**: This block does NOT include the CBD calibration (0x00408Exx(4231xxx) region).

### Calibration Block B (CBD Parameters)

The CBD calibration at 0x00408Exx is in a different region:

| Attribute | Value |
|-----------|-------|
| RAM Address | 0x00408EE2(4231906) - 0x00408F28(4231976) |
| Size | ~70(70) bytes |
| Contains | CBD thresholds, gains, DFT coefficients |

This region is within the larger RAM space but is initialized separately (mechanism TBD).

## Diagnostic Memory Access

The function `diagMemoryReadHandler` at 0x00001B48(6984) handles memory read requests:

```c
if (address < 0x1000000(16777216)) {
    // Direct memory copy (ROM/RAM access)
    FUN_003fc77c(dest, address, length);
} else {
    // EEPROM access via hardware interface
    eepromReadWords(address, dest, length);
}
```

This shows:
- Addresses < 0x01000000(16777216): Direct memory access
- Addresses >= 0x01000000(16777216): EEPROM/special hardware access

## Cross-Reference: E2M Parameters vs RAM Variables

| E2M Parameter | Calterm Address | RAM Address | Ghidra Variable |
|---------------|-----------------|-------------|-----------------|
| CBD_Enable | 0x0181AE14(25259540) | 0x00408EF6(4231926) | cbd_enable_flag |
| CBD_Lower_Speed_Limit | 0x0181AE06(25259526) | 0x00408EE8(4231912) | cbd_rpm_lower_limit |
| CBD_Upper_Speed_Limit | 0x0181AE04(25259524) | 0x00408EE6(4231910) | cbd_rpm_upper_limit |
| CBD_Trim_Max | 0x0181AE0C(25259532) | 0x00408EEE(4231918) | cbd_trim_max_limit |
| CBD_Trim_Min | 0x0181AE0E(25259534) | 0x00408EF0(4231920) | cbd_trim_min_limit |

## EEPROM Layout (Verified 2026-01-31)

Key locations discovered via live ECU reads (see [eeprom.txt](eeprom.txt) for full byte-level map):

| Offset | Size | Content | Example Value |
|--------|------|---------|---------------|
| 0x0002(2) | 6 | Security Key | `ABCDEF` |
| 0x0046(70) | 10 | Calibration ID | `1504 2RSAO` |
| 0x0080(128) | 6 | Date Code | `060410` (2006-04-10) |
| 0x0130(304) | 4 | **Calibration Version** | `00 0B 2E 06` → V11.46.06 |
| 0x01D1(465) | 5 | Cummins Marker | `CMMNS` |
| 0x0217(535) | 2 | Module ID | `CC` (CM848) |
| 0x0286(646) | 17 | VIN | `3D3MU48C94G228471` |
| 0x02C0(704) | 127 | Data Plate | (mostly zeros) |
| 0x0BD8(3032) | 4 | Primary Odometer | u32, scale ×0.000125(0.000125) mi |
| 0x0BF8(3064) | 4 | Secondary Odometer | u32, scale ×0.000125(0.000125) mi |

### Calibration Version Format

At EEPROM 0x0130(304):
```
Byte 0: 0x00(0) (reserved)
Byte 1: Major version (0x0B(11) = 11)
Byte 2: Minor version (0x2E(46) = 46)
Byte 3: Patch version (0x06(6) = 6)
Byte 4-5: Build/revision
```

**This ECU:** V11.46.06
**S90140.12 e2m file:** V11.20.13.16 (different version = different Bank 2 code)

## ROM Header Layout

See [bank1.txt](bank1.txt) for full byte-level map.

| Offset | Size | Content | Example Value |
|--------|------|---------|---------------|
| 0x0000(0) | 8 | Reset vector | `48 00 2B CA` (branch) |
| 0x0008(8) | 8 | Exception vector | `48 00 16 DE` |
| 0x0100(256) | 8 | Metadata header | `48 00 16 DE 00 00 26 94` |
| 0x010C(268) | 6 | Build Date | `100902` (2002-10-09) |
| 0x0112(274) | 6 | Version bytes | `04 01 01 02 0C 08` |

## Keeping Files in Sync

When a new memory address is identified and named, it **must** be updated in both places:

1. **Ghidra CSVs** (`output/global_variables.csv`, `output/function_renames.csv`, etc.) — this is the source of truth for Ghidra analysis
2. **Memory mapping files** (`bank1.txt`, `bank2.txt`, `ram.txt`, or `eeprom.txt`) — this is the human-readable reference

The memory mapping txt files are generated from the Ghidra CSVs plus manually documented fields (EEPROM layout, ROM header). If you name a new variable or function:

1. Add/update the entry in the appropriate Ghidra CSV
2. Run `./analyze.sh build` to apply all CSVs and regenerate the decompilation
3. Add the corresponding line to the appropriate memory mapping txt file
4. Use the decimal offset as the line number and include the name and type

Failing to update both will cause the documentation to drift out of sync with the Ghidra project.

## Open Questions

1. **How is the 0x00408Exx(4231xxx) calibration region initialized?**
   - Not covered by `copyCalibrationToRam`
   - May be in a different flash bank
   - May be mapped directly to flash (read-only)

2. **Complete Column3 mapping table**
   - 0x81AE(33198) confirmed
   - Other CBD blocks (0x81AF(33199), 0x81B0(33200)) need verification
   - Hundreds of other Column3 values exist

3. ~~**Relationship between e2m file binary and ECU flash**~~ RESOLVED
   - E2M files contain two sections: CSV parameters + binary hex dumps
   - Binary section has raw code/data at absolute addresses
   - Binary is version-specific (compiled address operands)
   - See [E2M Integration](../E2M_INTEGRATION.md) for details

## Related Documentation

- [CBD Enable Experiment](../cbd_enable_experiment.md) - CBD parameter addresses
- [Injector Feedback System](../injector_feedback_system.md) - CBD algorithm documentation
- [E2M Integration](../E2M_INTEGRATION.md) - E2M file format overview
- [Service 0x4A Protocol](../service_0x4a_protocol.md) - Memory read protocol for translators
