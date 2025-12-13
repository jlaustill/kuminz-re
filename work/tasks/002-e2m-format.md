# 002: E2M File Format Reverse Engineering

**Status:** Done
**Subproject:** e2m-analysis
**Created:** 2024-11-XX
**Completed:** 2024-12-XX

## Goal

Fully decode the Cummins Calterm e2m calibration file format to understand how parameters map to ECU memory addresses.

## Problem Statement

E2M files are CSV-format calibration files used by Calterm to configure Cummins ECUs. The file format was undocumented, with 16 columns of unclear purpose.

## Final Solution

### File Structure
- **Format:** CSV with 2 header rows, up to 16 data columns
- **Line 1:** 4-character hex CRC
- **Lines 2-3:** Headers
- **Lines 4+:** Parameter data

### Memory Address Formula (100% Decoded)
```
Memory Address = BaseLookup[Column3] + Column4
```

Where:
- **Column 3:** Memory page selector (521 unique values mapped)
- **Column 4:** Hex byte offset within page

### Column Purposes (All 16 Decoded)

| Column | Purpose | Notes |
|--------|---------|-------|
| 1 | Parameter name | Human-readable identifier |
| 2 | Display value | Current value with units |
| 3 | Memory page selector | Maps to base address via lookup |
| 4 | Byte offset | Added to base address |
| 5 | Memory region identifier | 549 unique values |
| 6 | Data type/size | Encoding information |
| 7 | Access control bits | Read/write permissions |
| 8-13 | Various metadata | Scaling, limits, etc. |
| 14 | Group ID | Links to Type G headers |
| 15 | Version/Build metadata | 30 unique values |
| 16 | Enum values | VALUE=DESCRIPTION format |

### Memory Zone Distribution

| Zone | Base Address Mappings | Parameters | Coverage |
|------|----------------------|------------|----------|
| External_RAM | 391 | 4,730 | 76.59% |
| EEPROM | 69 | 1,145 | 18.54% |
| CalTerm_Parameter_Storage | 53 | 287 | 4.65% |
| Flash | 8 | 14 | 0.23% |

### Validation Results
- **521 unique Column3 → Base Address mappings** discovered
- **6,176 parameters** validated against CM550 firmware
- **100% accuracy** - all computed addresses match firmware locations

## Key Documentation

- `e2m-analysis/docs/column3_base_address_lookup.md` - Complete 521-entry lookup table
- `e2m-analysis/docs/groups.md` - Parameter grouping mechanism (Type G analysis)
- `e2m-analysis/docs/column16_enums.md` - Enum value patterns
- `e2m-analysis/docs/column_stats.md` - Statistical analysis of 248K+ rows
- `e2m-analysis/base_addresses_complete.md` - Complete address reference

## Tools Created

```bash
cd e2m-analysis
npm install
npm run analyze:all           # Complete analysis suite
npm run analyze:groups        # Parameter grouping analysis
npm run analyze:col16         # Column 16 enum patterns
npm run analyze:access        # Column 7 access control
npx tsx src/tools/validate-against-firmware.ts   # Validate addresses
npx tsx src/tools/generate-verified-lookup.ts    # Generate lookup table
```

## Key Insights

1. **Column 3 is the key** - Maps to memory pages via 521-entry lookup
2. **Type G headers** - Group related parameters via Column 14
3. **Memory regions** - 76% External_RAM, 18% EEPROM, 5% CalTerm storage
4. **Enum patterns** - Column 16 uses VALUE=DESCRIPTION format for dropdowns

## Related Tasks

- 001 (CRC Paradox) - CRC validation for e2m files
- 004 (E2M Validation) - Cross-validate addresses against firmware
