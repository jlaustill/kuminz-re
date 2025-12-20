# J90831.05 - Dodge Ram (Br/BE)

## Source
- **Origin:** Physical EEPROM chip dump from damaged ECU
- **Status:** EEPROM only - ROM chip was destroyed

## Identification

| Field | Value |
|-------|-------|
| Firmware | J90831.05 |
| Engine | 6BTA 5.9L (JCMMNS6BTA5.9 Li) |
| Application | Chrysler Br/BE (Dodge Ram 2nd gen) |
| Date Code | January 24, 2001 (012401) |
| Serial | 039474121C0302023 |
| Module ID | E1 (not EN!) |
| Part Number | FP98849 |

## Body Code Decode

`Br/BE` indicates:
- **BR** = Dodge Ram (2nd generation, 1994-2002)
- **BE** = Extended Cab (Club Cab) variant

## Module ID Discovery

This ECU uses Module ID `E1` instead of `EN` (0x454E) seen in J90350.00:
- `E1UU` at EEPROM offset 0x3A
- May indicate different ECU hardware revision
- Same EEPROM structure as EN modules (header `600d ABCDEF`)

## EEPROM Structure

Matches J90350.00 EEPROM format:
- Offset 0x00: Header `600d ABCDEF`
- Offset 0x3A: Module ID `E1UU`
- Offset 0x80: Date code `012401`
- Offset 0x280: Engine identifier
- Offset 0x2D3: Firmware version

## Files

```
J90831.05_DodgeRam/
├── originals/
│   ├── j90831_05.BIN    # Original 8KB chip dump
│   └── j90831_05.HEX    # Intel HEX format
├── eeprom/
│   └── J90831.05.eeprom.bin  # Extracted 4KB EEPROM
└── README.md
```

## Comparison with J90350.00

| Field | J90350.00 | J90831.05 |
|-------|-----------|-----------|
| Module ID | EN | E1 |
| Engine | ISB 195hp | 6BTA 5.9L |
| Application | GENERIC | Dodge Ram Br/BE |
| Date | 060498 | 012401 |
| Firmware | J90350.00 | J90831.05 |

## Notes

- This is a **Dodge Ram** ECU (BR/BE body codes confirm)
- Date code 012401 = January 2001 (late 2nd gen Ram production)
- Module ID E1 vs EN may indicate hardware revision difference
- No ROM available - cannot compare firmware code
