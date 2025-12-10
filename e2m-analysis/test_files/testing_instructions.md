# CRC Testing Instructions

Generated: 2025-08-13T22:10:48.382Z
Source: originals/v64t6_s.e2m
Original CRC: DFCE (hex) = 57294 (decimal)

## Test Files Created

1. **test1_remove_last.e2m** - Removed last parameter
2. **test2_remove_first.e2m** - Removed first parameter
3. **test3_duplicate_first.e2m** - Duplicated first parameter
4. **test4_modify_col15.e2m** - Changed Column 15 value (8700199999 → 8700199998)
5. **test5_empty.e2m** - Headers only, no data

## Testing Process

1. **Load each test file in Calterm**
2. **Note the CRC error message or new CRC value**
3. **Record which files Calterm accepts vs rejects**
4. **Compare CRC changes with file modifications**

## Expected Results

- **test1_remove_last**: Should show different CRC (missing parameter)
- **test2_remove_first**: Should show different CRC (missing parameter)
- **test3_duplicate_first**: Should show different CRC (extra parameter)
- **test4_modify_col15**: Should show different CRC (Column 15 is part of CRC)
- **test5_empty**: Should show very different CRC (no data)

## CRC Algorithm Clues

Based on test results, we can determine:
- **Parameter order sensitivity**: Compare test1 vs test2 CRC differences
- **Column 15 influence**: Compare original vs test4
- **Data inclusion**: Compare original vs test5
- **Addition vs removal**: Compare test3 pattern

## Next Steps

1. Test all files in Calterm
2. Record CRC values or error messages
3. Analyze patterns to reverse-engineer algorithm
4. Implement CRC generation function
5. Validate with known good files