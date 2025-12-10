# CRC Test Plan for E2M Files

Generated: 2025-08-13T22:15:00.000Z

## 🎯 Objective

Reverse-engineer the CRC algorithm used in Cummins Calterm e2m files to enable programmatic generation of valid e2m files.

## 🔍 What We've Discovered

### Column 15 = CRC Component
- All Column 15 values end in "99999"
- Removing Column 15 causes Calterm "invalid CRC value" error
- This column is integral to the CRC calculation

### Header Structure
- **Row 1**: File CRC value (hex, e.g., "DFCE")
- **Row 2**: Secondary metadata (possibly file size/version)
- Each file has unique CRC based on content

### CRC Validation
- Calterm validates file integrity using CRC
- Invalid CRC prevents file loading
- CRC must be recalculated when file is modified

## 🧪 Test Files Created

Based on `originals/v64t6_s.e2m` (Original CRC: `DFCE`, 6443 parameters):

| Test File | Modification | Purpose |
|-----------|--------------|---------|
| `test1_remove_last.e2m` | Removed last parameter | Test parameter order sensitivity |
| `test2_remove_first.e2m` | Removed first parameter | Compare with test1 for order effects |
| `test3_duplicate_first.e2m` | Duplicated first parameter | Test addition vs removal patterns |
| `test4_modify_col15.e2m` | Changed Column 15 (8700199999→8700199998) | Verify Column 15 CRC influence |
| `test5_empty.e2m` | Headers only, no data | Test CRC with minimal content |

## 📋 Testing Procedure

### Step 1: Load Test Files in Calterm
For each test file:
1. Open file in Calterm
2. Record result:
   - ✅ **Loads successfully** - Record displayed CRC
   - ❌ **CRC error** - Record expected vs actual CRC
   - ⚠️ **Other error** - Note error message

### Step 2: Document Results
Create table:

| Test File | Result | Expected CRC | Actual CRC | Notes |
|-----------|--------|--------------|------------|-------|
| test1_remove_last.e2m | | | | |
| test2_remove_first.e2m | | | | |
| test3_duplicate_first.e2m | | | | |
| test4_modify_col15.e2m | | | | |
| test5_empty.e2m | | | | |

### Step 3: Pattern Analysis
Compare results to determine:
- **Parameter sensitivity**: Do position changes affect CRC differently?
- **Column 15 influence**: How much does Column 15 change affect CRC?
- **Data scope**: Is entire file content included in CRC?
- **Algorithm type**: Linear checksum vs polynomial CRC?

## 🔍 CRC Algorithm Hypotheses

### Most Likely Candidates:
1. **CRC-16** with standard polynomial (0x8005 or 0x1021)
2. **Custom Cummins CRC** with proprietary polynomial
3. **Simple checksum** of specific columns/data
4. **XOR-based checksum** of file content

### Algorithm Clues:
- **16-bit output** (4 hex digits like DFCE)
- **Includes Column 15** (99999 pattern significant)
- **Content-sensitive** (modification detection)
- **Deterministic** (same content = same CRC)

## 🎯 Expected Outcomes

### If CRC-16 Standard:
- Predictable bit patterns in CRC changes
- Linear relationship between content changes and CRC
- Possible to implement with standard CRC libraries

### If Custom Algorithm:
- Irregular CRC patterns
- May require byte-level reverse engineering
- Could involve proprietary Cummins modifications

### If Simple Checksum:
- Additive relationship between changes
- Easy to implement once pattern is found
- Likely involves Column 15 "99999" values

## 🚀 Next Steps After Testing

1. **Analyze test results** to identify CRC algorithm
2. **Implement CRC function** in TypeScript
3. **Validate implementation** against known good files
4. **Create e2m generation tools** with automatic CRC calculation
5. **Enable programmatic file modification** for firmware work

## 💡 Implementation Strategy

Once algorithm is identified:

```typescript
function calculateE2MCRC(dataLines: string[]): string {
  // Implementation based on test results
  // Return 4-character hex CRC
}

function generateValidE2M(parameters: Parameter[]): string {
  const dataLines = parameters.map(formatParameter);
  const crc = calculateE2MCRC(dataLines);
  return [crc, metadata, ...dataLines].join('\n');
}
```

## 🎯 Success Criteria

- [ ] Understand CRC algorithm completely
- [ ] Generate valid CRC for any file modification
- [ ] Create/modify e2m files programmatically
- [ ] Enable firmware analysis with accurate parameter data

---

**Status**: Ready for Calterm testing
**Files location**: `test_files/`
**Next action**: Load test files and document CRC behavior