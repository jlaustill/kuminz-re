# Firmware Region Analysis

Generated: 2025-12-17T01:47:07.690Z

## J90280.05 (Reference Firmware)

| Start | End | Size | Type | Entropy | Description |
|-------|-----|------|------|---------|-------------|
| 0x000000 | 0x004000 | 16.0KB | erased | 0.00 | Erased flash (0xFF) |
| 0x004000 | 0x006000 | 8.0KB | calibration | 1.07 | Structured data/calibration (entropy 1.48) |
| 0x006000 | 0x008000 | 8.0KB | erased | 0.00 | Erased flash (0xFF) |
| 0x008000 | 0x009000 | 4.0KB | calibration | 2.77 | Structured data/calibration (entropy 2.77) |
| 0x009000 | 0x00a000 | 4.0KB | unknown | 0.74 | Unknown region (entropy 0.74) |
| 0x00a000 | 0x021000 | 92.0KB | code | 6.04 | Executable code (56 instructions detected) |
| 0x021000 | 0x022000 | 4.0KB | unknown | 7.30 | Unknown region (entropy 7.30) |
| 0x022000 | 0x025000 | 12.0KB | compressed | 7.85 | High entropy (7.90) - likely compressed/encrypted |
| 0x025000 | 0x036000 | 68.0KB | code | 5.57 | Executable code (154 instructions detected) |
| 0x036000 | 0x038000 | 8.0KB | calibration | 2.35 | Structured data/calibration (entropy 3.15) |
| 0x038000 | 0x03a000 | 8.0KB | unknown | 5.13 | Unknown region (entropy 5.03) |
| 0x03a000 | 0x03b000 | 4.0KB | calibration | 2.67 | Structured data/calibration (entropy 2.67) |
| 0x03b000 | 0x040000 | 20.0KB | erased | 0.00 | Erased flash (0xFF) |

## J90350.00 (Extracted Firmware)

| Start | End | Size | Type | Entropy | Description |
|-------|-----|------|------|---------|-------------|
| 0x000000 | 0x003000 | 12.0KB | compressed | 7.86 | High entropy (7.78) - likely compressed/encrypted |
| 0x003000 | 0x004000 | 4.0KB | code | 6.23 | Executable code (75 instructions detected) |
| 0x004000 | 0x00b000 | 28.0KB | calibration | 2.24 | Structured data/calibration (entropy 2.30) |
| 0x00b000 | 0x029000 | 120.0KB | code | 5.96 | Executable code (57 instructions detected) |
| 0x029000 | 0x02c000 | 12.0KB | compressed | 7.82 | High entropy (7.64) - likely compressed/encrypted |
| 0x02c000 | 0x02d000 | 4.0KB | unknown | 7.32 | Unknown region (entropy 7.32) |
| 0x02d000 | 0x035000 | 32.0KB | code | 5.99 | Executable code (98 instructions detected) |
| 0x035000 | 0x036000 | 4.0KB | data | 4.52 | Data tables (entropy 4.52) |
| 0x036000 | 0x039000 | 12.0KB | calibration | 1.92 | Structured data/calibration (entropy 3.02) |
| 0x039000 | 0x040000 | 28.0KB | erased | 0.00 | Erased flash (0xFF) |

## Summary

### J90280.05
- Code regions: 2 (160KB)
- Compressed regions: 1

### J90350.00
- Code regions: 3 (156KB)
- Compressed regions: 2

## Key Observations

1. **Memory Layout Difference**: The two firmwares have different memory organizations
2. **Code Relocation**: Functions are at different addresses between firmwares
3. **Compressed Data**: J90350.00 contains compressed data in early memory regions
