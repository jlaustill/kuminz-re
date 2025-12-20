# J90270.06 - Chrysler T-300 Commercial Truck

## Source
- **Origin:** Physical EEPROM chip dump from damaged ECU
- **Status:** EEPROM only - ROM chip was destroyed

## Identification

| Field | Value |
|-------|-------|
| Firmware | J90270.06 |
| Engine | 6BTA 5.9L (JCMMNS6BTA5.9 Li) |
| Application | Chrysler T-300 (commercial truck) |
| Date Code | June 28, 2000 (062800) |
| Serial | 4J,J039479121A0505648 |
| Module ID | E1 (not EN!) |
| Part Number | FP98456 |

## Module ID Discovery

This ECU uses Module ID `E1` instead of `EN` (0x454E) seen in J90350.00:
- `E1UU` at EEPROM offset 0x3A
- May indicate different ECU hardware revision or module family
- Same EEPROM structure as EN modules (header `600d ABCDEF`)

## EEPROM Structure

Matches J90350.00 EEPROM format:
- Offset 0x00: Header `600d ABCDEF`
- Offset 0x3A: Module ID `E1UU`
- Offset 0x80: Date code `062800`
- Offset 0x2E2: Engine identifier
- Offset 0x333: Firmware version

## Files

```
J90270.06_T300/
├── originals/
│   ├── j90270_06.BIN    # Original 8KB chip dump
│   └── j90270_06.HEX    # Intel HEX format
├── eeprom/
│   └── J90270.06.eeprom.bin  # Extracted 4KB EEPROM
└── README.md
```

## Notes

- **Not a Dodge Ram** - This is from a Chrysler T-300 commercial truck
- T-300 was a medium-duty commercial vehicle platform
- Useful for comparing calibration data with Dodge Ram EEPROMs
- No ROM available for code analysis
