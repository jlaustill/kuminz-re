# 1999 Dodge Ram Prototype ROM

## Source
- **Origin:** Physical chip dump from damaged ECU
- **Chip Reader Issue:** Original dump was byte-swapped (wrong endianness)
- **Status:** ROM only - no matching EEPROM available

## Identification

| Field | Value |
|-------|-------|
| Build Date | September 11, 1997 (091197) |
| Identifier | &I091197 |
| VIN Embedded | 3B7KF2368XG109539 |
| Vehicle | 1999 Dodge Ram 2500/3500 |
| Engine | Cummins 5.9L ISB |
| ROM Size | 256KB |

## VIN Decode

```
3B7KF2368XG109539
│││││││││└─ Serial: 109539
││││││││└── Plant: G (St. Louis)
│││││││└─── Model Year: X (1999)
││││││└──── Check Digit: 8
│││││└───── Transmission: 6 (Manual 5-speed)
││││└────── Engine: 3 (Cummins 5.9L diesel)
│││└─────── Body: 2 (2-door regular cab)
││└──────── GVWR: F (?)
│└───────── Series: K (8500 GVWR)
└────────── Make: 3B7 (Dodge Ram 2500/3500)
```

## Key Observations

1. **Pre-Production Firmware**: Build date Sept 1997 predates J90350.00 (April 1998) by 7 months
2. **Prototype Unit**: VIN embedded in ROM suggests this was a development/test ECU
3. **Non-Standard Identifier**: Uses `&I091197` instead of `Jxxxxx.xx` pattern
4. **Byte-Swap Required**: Original chip dump needed byte-order correction

## Files

```
1999_dodge_prototype/
├── originals/
│   └── 1999dodge.BIN          # Original byte-swapped dump (512KB)
├── firmware/
│   └── 1999dodge.rom.bin      # Corrected ROM (256KB)
└── README.md
```

## Analysis Status

- [ ] Load into Ghidra for analysis
- [ ] Compare with J90350.00 to identify code differences
- [ ] Determine if &I prefix indicates prototype/development build
- [ ] Add to relocation map for cross-firmware comparison

## Comparison with J90350.00

| Offset | J90350.00 | 1999dodge | Notes |
|--------|-----------|-----------|-------|
| 0x00-0x07 | `0081 0000 0000 001e` | `0081 0000 0000 001e` | Same SP/PC vectors |
| 0x0C-0x0D | `wl` | `&I` | Different build identifier |
| 0x0E-0x13 | `040798` | `091197` | Build date (7 months earlier) |
