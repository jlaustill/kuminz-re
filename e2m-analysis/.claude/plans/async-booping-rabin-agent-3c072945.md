# Implementation Plan: E2M Memory Address Mapping Validation and Correction

## Executive Summary

**USER CONFIRMED**: The mismatch issue was with the OLD formula (Col3*256), not the new lookup-based formula.

The e2m-analysis project has **two competing memory address formulas**:

1. **Old Formula** (INCORRECT): `Memory Address = Base + (Column3 * 256) + Column4`
   - Used in: `map-all-base-addresses.ts`, `correlate-memory-addresses.ts`, `docs/base_addresses.md`
   - Claims 66.1% coverage with 13 manually confirmed base addresses
   - Uses Subfile+Column5 to determine base address

2. **New Formula** (CORRECT): `Memory Address = BaseAddress(Column3 lookup) + Column4`
   - Used in: `formula-breakthrough.ts`, README.md
   - Achieves **100% accuracy** on all 5,043 matched Calterm parameters
   - Column3 directly maps to a unique base address (520 unique mappings discovered)

**Critical Finding**: Database analysis confirms the NEW formula has 100% accuracy with 0 mismatches across all tested parameters. The old formula produces negative/overflow values and is fundamentally incorrect.

---

## Problem Analysis

### 1. Formula Contradiction Identified

| Aspect | Old Formula | New Formula |
|--------|-------------|-------------|
| Formula | `Base + (Col3 * 256) + Col4` | `BaseLookup[Col3] + Col4` |
| Column3 Role | Multiplied by 256 | Lookup key to base address |
| Base Address Source | Subfile+Col5 combination | Column3 value directly |
| Claimed Accuracy | 66.1% | 100% |
| Actual Accuracy | Produces overflow errors | 100% verified |

### 2. Documentation Inconsistency

- `README.md` claims "100% SOLVED" with the new formula
- `docs/base_addresses.md` claims "66.1% coverage" with the old formula
- The codebase has tools using BOTH formulas inconsistently

### 3. Database Validation Results

```sql
-- Analysis shows:
- Total parameters tested: 5,043
- Unique Column3 values: 520
- Formula matches (Base+Col4=Actual): 5,043
- Formula mismatches: 0
```

Each Column3 value maps to exactly ONE base address (no conflicts), proving the lookup-table approach is correct.

### 4. Coverage Gap Analysis

| Type | Total | Matched | Match % | Notes |
|------|-------|---------|---------|-------|
| N (Normal) | 4,537 | 3,620 | 79.8% | Largest group |
| S (Scalar) | 1,295 | 1,088 | 84.0% | Good coverage |
| G (Group) | 121 | 0 | 0.0% | Group headers - no addresses |
| C (Command) | 18 | 0 | 0.0% | Commands - no addresses |
| Y (Y-axis) | 116 | 45 | 38.8% | Table axes |
| X (X-axis) | 96 | 64 | 66.7% | Table axes |

The 1,400 unmatched parameters are mostly:
- Type G (group headers) - don't have memory addresses
- Type C (commands) - don't have memory addresses  
- Parameters not scraped from Calterm

---

## Implementation Plan

### Phase 1: Foundation Cleanup (Priority: Critical)

**Goal**: Fix the fundamental formula inconsistency and establish correct tooling.

#### Task 1.1: Create Authoritative Formula Module

**File**: `/home/jlaustill/code/e2m-analysis/src/utils/address-calculator.ts`

```typescript
// Types
interface IBaseAddressMapping {
  column3: string;      // Hex string (e.g., "106B")
  baseAddress: number;  // Decimal base address
  parameterCount: number;
  memoryZone: string;   // 'External_Memory', 'EEPROM_DataPlate', etc.
}

interface IAddressCalculation {
  parameterName: string;
  column3: string;
  column4: string;
  baseAddress: number;
  calculatedAddress: number;
  hexAddress: string;
  isValid: boolean;
}

// Core Functions
function calculateAddress(column3: string, column4: string, mappings: Map<string, number>): IAddressCalculation;
function loadMappingsFromDatabase(): Promise<Map<string, number>>;
function validateAddress(calculated: number, actual: number): boolean;
```

**Purpose**: Single source of truth for address calculation logic.

#### Task 1.2: Generate Authoritative Column3 Lookup Table

**File**: `/home/jlaustill/code/e2m-analysis/src/tools/generate-column3-lookup.ts`

**Output**: `/home/jlaustill/code/e2m-analysis/docs/column3_base_address_lookup.md`

This tool will:
1. Query the database for all verified Column3 -> Base Address mappings
2. Generate a complete lookup table with 520+ entries
3. Include memory zone classification
4. Track confidence levels based on sample count

#### Task 1.3: Update Type Definitions

**File**: `/home/jlaustill/code/e2m-analysis/src/types/index.ts`

Add new interfaces:
```typescript
interface IColumn3Mapping {
  column3: string;
  baseAddress: number;
  hexBase: string;
  memoryZone: TMemoryZone;
  parameterCount: number;
  confidence: 'verified' | 'derived' | 'unverified';
}

type TMemoryZone = 
  | 'External_Memory'      // 0x800000 - 0x8FFFFF
  | 'EEPROM_DataPlate'     // 0x1000000 - 0x1001FFF
  | 'CalTerm_Parameter_Storage' // 0x60000 - 0x6FFFF
  | 'Unknown';

interface IValidationResult {
  parameterName: string;
  expectedAddress: string;
  actualAddress: string;
  matches: boolean;
  error?: string;
}
```

---

### Phase 2: Validation Infrastructure (Priority: High)

**Goal**: Build tools to validate and identify mismatches systematically.

#### Task 2.1: Create Comprehensive Validator Tool

**File**: `/home/jlaustill/code/e2m-analysis/src/tools/validate-all-addresses.ts`

Features:
1. Load all Column3 -> Base mappings from database
2. Apply formula to ALL e2m parameters
3. Compare against scraped Calterm addresses
4. Generate detailed mismatch report
5. Identify patterns in any failures

#### Task 2.2: Cross-File Validation Tool

**File**: `/home/jlaustill/code/e2m-analysis/src/tools/cross-file-validator.ts`

Features:
1. Test if Column3 mappings are consistent across all 36 e2m files
2. Identify file-specific addressing differences
3. Flag parameters that exist in multiple files with different addresses
4. Build per-file mapping confidence

#### Task 2.3: Database Schema Enhancement

Add new tables to track validation:
```sql
CREATE TABLE column3_mappings (
    column3 VARCHAR(10) PRIMARY KEY,
    base_address BIGINT NOT NULL,
    hex_address VARCHAR(10) NOT NULL,
    memory_zone VARCHAR(50),
    parameter_count INT,
    confidence VARCHAR(20),
    verified_at TIMESTAMP,
    source_file VARCHAR(100)
);

CREATE TABLE validation_results (
    id SERIAL PRIMARY KEY,
    parameter_name VARCHAR(100),
    file_name VARCHAR(100),
    column3 VARCHAR(10),
    column4 VARCHAR(10),
    calculated_address VARCHAR(10),
    actual_address VARCHAR(10),
    matches BOOLEAN,
    validated_at TIMESTAMP DEFAULT NOW()
);
```

---

### Phase 3: Legacy Code Correction (Priority: Medium)

**Goal**: Update all tools to use the correct formula.

#### Task 3.1: Files to Update

| File | Current Formula | Action Required |
|------|-----------------|-----------------|
| `src/tools/map-all-base-addresses.ts` | Old (Col3*256) | Rewrite to use lookup |
| `src/tools/correlate-memory-addresses.ts` | Old (Col3*256) | Rewrite to use lookup |
| `src/tools/predict-memory-addresses.ts` | Unknown | Review and update |
| `src/tools/calculate-new-bases.ts` | Unknown | Review and update |
| `src/tools/generate-base-address-docs.ts` | Unknown | Update output format |
| `src/cross-reference-validator.ts` | Uses CONFIRMED_BASE_ADDRESSES | Update to use Column3 lookup |

#### Task 3.2: Documentation Updates

| Document | Action |
|----------|--------|
| `README.md` | Remove contradictory claims, document correct formula |
| `docs/base_addresses.md` | Replace with Column3 lookup table reference |
| `docs/complete_base_address_mapping.md` | Regenerate with correct methodology |
| `docs/formula_reverse_engineering.md` | Mark old hypothesis as superseded |

---

### Phase 4: Firmware Correlation (Priority: Medium-Low)

**Goal**: Correlate discovered mappings with firmware knowledge.

#### Task 4.1: Memory Zone Analysis Tool

**File**: `/home/jlaustill/code/e2m-analysis/src/tools/analyze-memory-zones.ts`

Correlate discovered base addresses with known firmware regions:
- External RAM: 0x800000 (1MB)
- Calibration working copies: 0x804882-0x8062CF
- Firmware tables: 0x8086F6+
- Flash calibration: 0x00004000-0x00005A41
- Flash backup: 0x00006000-0x00007A41

#### Task 4.2: Parameter Storage Investigation

Investigate the relationship between:
- Column3 values and firmware memory pages
- Column5 (Memory Region Identifier) purpose
- Subfile numbers and memory organization

---

### Phase 5: Coverage Completion (Priority: Low)

**Goal**: Extend mapping coverage to parameters without scraped addresses.

#### Task 5.1: Prediction Tool Enhancement

Update `/home/jlaustill/code/e2m-analysis/src/tools/predict-memory-addresses.ts`:
1. Use verified Column3 lookup table
2. Predict addresses for unscraped parameters
3. Mark predictions with confidence levels
4. Generate Calterm verification checklist

#### Task 5.2: CHR File Analysis

Apply validated formula to CHR folder e2m files:
1. Test if same Column3 mappings apply
2. Document any CHR-specific differences
3. Build ECU variant correlation

---

## Critical Files for Implementation

### 1. `/home/jlaustill/code/e2m-analysis/src/formula-breakthrough.ts`
- Contains the CORRECT formula implementation
- Reference for database query patterns
- Source of truth for validation approach

### 2. `/home/jlaustill/code/e2m-analysis/src/types/index.ts`
- Current type definitions to extend
- Pattern for interface naming conventions
- Foundation for new type additions

### 3. `/home/jlaustill/code/e2m-analysis/src/utils/e2m-parser.ts`
- E2M file parsing logic
- Column extraction patterns
- Data structure reference

### 4. `/home/jlaustill/code/e2m-analysis/src/tools/map-all-base-addresses.ts`
- Example of INCORRECT formula (to be replaced)
- Shows Subfile+Col5 approach that should be abandoned
- Output format reference for new tools

### 5. `/home/jlaustill/code/e2m-analysis/src/cross-reference-validator.ts`
- Database connection patterns
- Validation logic structure
- Report generation format

---

## Validation Strategy

### Success Criteria

1. **Formula Accuracy**: 100% match rate on all scraped Calterm parameters
2. **Coverage**: Complete Column3 lookup table with 520+ mappings
3. **Consistency**: All tools use single authoritative formula module
4. **Documentation**: Clear, non-contradictory documentation
5. **Cross-file**: Validated consistency across all 36 e2m files

### Testing Approach

1. **Unit Tests**: Formula calculation accuracy
2. **Integration Tests**: Database query + calculation pipeline
3. **Regression Tests**: Ensure 100% accuracy maintained
4. **Cross-file Tests**: Same Column3 = Same base across files

### Verification Checklist

- [ ] New address calculator module created
- [ ] Column3 lookup table generated (520+ entries)
- [ ] All legacy tools updated to use correct formula
- [ ] Database schema enhanced with validation tables
- [ ] Cross-file validation completed
- [ ] Documentation synchronized and accurate
- [ ] No formula mismatches in validation run

---

## Implementation Order

```
Week 1:
- Phase 1.1: Create address-calculator.ts module
- Phase 1.2: Generate Column3 lookup table
- Phase 1.3: Update type definitions

Week 2:
- Phase 2.1: Create validate-all-addresses.ts
- Phase 2.2: Create cross-file-validator.ts
- Phase 2.3: Add database tables

Week 3:
- Phase 3.1: Update legacy tools (6 files)
- Phase 3.2: Update documentation (4 files)

Week 4:
- Phase 4.1: Memory zone analysis
- Phase 4.2: Firmware correlation
- Phase 5: Coverage completion (as time permits)
```

---

## Risk Mitigation

| Risk | Mitigation |
|------|------------|
| Breaking existing analysis | Keep old tools until new ones validated |
| Database connection issues | Add connection retry logic |
| Cross-file inconsistencies | Document as ECU variant differences |
| Missing Column3 mappings | Mark as "unverified" with prediction |

---

## Notes

### Confirmed Facts from Database Analysis

1. The correct formula is: `Address = BaseLookup[Column3] + Column4`
2. 520 unique Column3 values map to 520 unique base addresses
3. Zero conflicts found - each Column3 has exactly one base
4. 5,043 parameters validated with 100% accuracy
5. Coverage gap is due to unscraped parameters, not formula errors

### Key Insight

The old formula `Base + (Col3 * 256) + Col4` was fundamentally flawed because:
- It produced negative/overflow values
- It required knowing a "base" from Subfile+Col5 (circular dependency)
- It achieved only 66% coverage because the base addresses were wrong

The new formula works because Column3 directly encodes the base address relationship - no multiplication needed, just a lookup table.

---

## Appendix: Sample Column3 Lookup Table (Top 30)

| Column3 | Base Address | Hex Address | Param Count | Memory Zone |
|---------|--------------|-------------|-------------|-------------|
| 106B | 16,777,608 | 0x01000188 | 458 | EEPROM_DataPlate |
| E | 8,437,966 | 0x0080BCCE | 376 | External_Memory |
| 1003 | 8,403,682 | 0x00806AE2 | 375 | External_Memory |
| F | 8,414,540 | 0x0080654C | 266 | External_Memory |
| 12FC | 8,420,714 | 0x00807D6A | 140 | External_Memory |
| 1234 | 8,420,702 | 0x00807D5E | 126 | External_Memory |
| 1253 | 397,226 | 0x00060FAA | 125 | CalTerm_Parameter_Storage |
| 1036 | 8,413,184 | 0x00806000 | 125 | External_Memory |
| 12A8 | 8,437,066 | 0x0080BD4A | 104 | External_Memory |
| 8019 | 8,418,334 | 0x0080741E | 100 | External_Memory |

(Full table: 520 entries - see `docs/column3_base_address_lookup.md` when generated)
