# J90350.00 Firmware Analysis

## ECU Details

| Field | Value |
|-------|-------|
| **Firmware Version** | J90350.00 |
| **Calibration Code** | 100898231658 |
| **Engine** | Cummins ISB 195hp |
| **ECU Type** | CM550 |
| **Serial Number** | T03942860 |
| **Date Code** | 060498 |

## Extraction Details

| Field | Value |
|-------|-------|
| **Extraction Date** | 2024-12-16 |
| **Method** | Service 0x4A memory read via kuminz-cli |
| **CAN Interface** | can0 (OBDLink EX @ 250kbps) |
| **Protocol** | J1939 Transport Protocol (RTS/CTS/DT) |

## Files

| File | Size | Description |
|------|------|-------------|
| `firmware/J90350.00.rom.bin` | 262,144 bytes (256KB) | ROM/Flash memory dump |
| `firmware/J90350.00.ram.bin` | 37,314 bytes (37KB) | RAM snapshot at extraction time |
| `firmware/J90350.00.eeprom.bin` | 4,096 bytes (4KB) | EEPROM calibration data |

## Memory Map (MC68336)

| Region | Address Range | Size | Status |
|--------|---------------|------|--------|
| ROM | 0x000000-0x03FFFF | 256KB | Extracted |
| RAM | 0x800000-0x8091C1 | 37KB | Extracted |
| EEPROM | 0x1000000-0x1000FFF | 4KB | Extracted |
| HW Registers | 0xFFC800-0xFFFFFF | ~14KB | Not extracted |
| Extended RAM | 0x8091C2-0x80FFFF | ~28KB | Protected |

## Relationship to J90280.05

This firmware (J90350.00) was extracted from a **physical CM-550 ECU**. The previous analysis work was done on J90280.05, which was the closest available firmware binary.

Both are CM550 ECUs for Cummins ISB engines, likely sharing significant code. Comparison opportunities:
- Identify shared vs unique functions
- Map calibration differences
- Understand firmware evolution

## Next Steps

- [ ] Compare ROM binaries (J90350.00 vs J90280.05)
- [ ] Import into Ghidra with MC68336 memory map
- [ ] Cross-reference function names from J90280.05 analysis
- [ ] Document differences in calibration regions

## Related Projects

- `../J90280.05_analysis/` - Reference firmware (100% functions named)
- `../../kuminz-cli/` - CLI tool used for extraction
- `../../clip-core/` - CLIP protocol library
