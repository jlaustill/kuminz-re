# Column 7 Analysis

Generated: 2025-08-13T21:34:40.810Z
Sources: 3 files analyzed

## 🎯 Column 7 Value Distribution

**Total unique values**: 5
**Values found**: 0, 17, 20, 3, 37

### Column 7 = "0" (399 parameters)

**Representations:**
- Hex: 0x0
- Decimal: 0
- Binary: 00000000

**Distribution by File:**
- 74c0.e2m: 145 parameters
- v64t6_s.e2m: 127 parameters
- v74t3_t.e2m: 127 parameters

**Distribution by Type:**
- Type N: 323 parameters
- Type C: 54 parameters
- Type A: 12 parameters
- Type B: 10 parameters

**Distribution by Subfile:**
- Subfile 3: 358 parameters
- Subfile 0: 22 parameters
- Subfile 6: 14 parameters
- Subfile 2: 5 parameters

**Example Parameters:**
- ACCHEA (Type: N, Subfile: 0, Group: 71)
- ACKFAULT (Type: C, Subfile: 3, Group: 3E)
- ADAAPRCA (Type: N, Subfile: 3, Group: 3E)
- ADAAPRHE (Type: N, Subfile: 3, Group: 3E)
- ADAAPRLE (Type: N, Subfile: 3, Group: 3E)

---

### Column 7 = "17" (3 parameters)

**Representations:**
- Hex: 0x17
- Decimal: 23
- Binary: 00010111

**Distribution by File:**
- v64t6_s.e2m: 1 parameters
- 74c0.e2m: 1 parameters
- v74t3_t.e2m: 1 parameters

**Distribution by Type:**
- Type N: 3 parameters

**Distribution by Subfile:**
- Subfile 0: 3 parameters

**Example Parameters:**
- EPAERPST (Type: N, Subfile: 0, Group: 4A)
- EPAERPST (Type: N, Subfile: 0, Group: 004A)
- EPAERPST (Type: N, Subfile: 0, Group: 4A)

---

### Column 7 = "20" (3 parameters)

**Representations:**
- Hex: 0x20
- Decimal: 32
- Binary: 00100000

**Distribution by File:**
- v64t6_s.e2m: 1 parameters
- 74c0.e2m: 1 parameters
- v74t3_t.e2m: 1 parameters

**Distribution by Type:**
- Type N: 3 parameters

**Distribution by Subfile:**
- Subfile 2: 3 parameters

**Example Parameters:**
- CTIDFTDY (Type: N, Subfile: 2, Group: 2A)
- CTIDFTDY (Type: N, Subfile: 2, Group: 002A)
- CTIDFTDY (Type: N, Subfile: 2, Group: 2A)

---

### Column 7 = "3" (3 parameters)

**Representations:**
- Hex: 0x3
- Decimal: 3
- Binary: 00000011

**Distribution by File:**
- v64t6_s.e2m: 1 parameters
- 74c0.e2m: 1 parameters
- v74t3_t.e2m: 1 parameters

**Distribution by Type:**
- Type N: 3 parameters

**Distribution by Subfile:**
- Subfile 0: 3 parameters

**Example Parameters:**
- SSBLSM (Type: N, Subfile: 0, Group: 24)
- SSBLSM (Type: N, Subfile: 0, Group: 0024)
- SSBLSM (Type: N, Subfile: 0, Group: 24)

---

### Column 7 = "37" (22155 parameters)

**Representations:**
- Hex: 0x37
- Decimal: 55
- Binary: 00110111

**Distribution by File:**
- 74c0.e2m: 8268 parameters
- v74t3_t.e2m: 7574 parameters
- v64t6_s.e2m: 6313 parameters

**Distribution by Type:**
- Type N: 15098 parameters
- Type S: 5045 parameters
- Type B: 645 parameters
- Type G: 407 parameters
- Type Y: 392 parameters
- Type X: 332 parameters
- Type T: 159 parameters
- Type Z: 77 parameters

**Distribution by Subfile:**
- Subfile 0: 11114 parameters
- Subfile 7: 2376 parameters
- Subfile 8: 2267 parameters
- Subfile 6: 2029 parameters
- Subfile 2: 1772 parameters

**Example Parameters:**
- 4DTA00XA (Type: X, Subfile: 5, Group: 1041)
- 4DTA00YA (Type: Y, Subfile: 5, Group: 1041)
- 4DTA00ZA (Type: Z, Subfile: 5, Group: 0)
- 4DTA01XA (Type: X, Subfile: 5, Group: 103E)
- 4DTA01YA (Type: Y, Subfile: 5, Group: 103E)

---

## Cross-Pattern Analysis

### Potential "Available Offline" Correlation

**Hypothesis**: Column 7 might control parameter availability in offline mode

**Type vs Column 7 Matrix:**
| Type | 0 | 17 | 20 | 3 | 37 |
|------|---|---|---|---|---|
| X | 0 | 0 | 0 | 0 | 332 |
| Y | 0 | 0 | 0 | 0 | 392 |
| Z | 0 | 0 | 0 | 0 | 77 |
| N | 323 | 3 | 3 | 3 | 15098 |
| G | 0 | 0 | 0 | 0 | 407 |
| C | 54 | 0 | 0 | 0 | 0 |
| B | 10 | 0 | 0 | 0 | 645 |
| T | 0 | 0 | 0 | 0 | 159 |
| A | 12 | 0 | 0 | 0 | 0 |
| S | 0 | 0 | 0 | 0 | 5045 |

## Key Observations

1. **Limited Values**: Only 5 unique values across all files
2. **Most Common**: Value "37" appears to dominate
3. **Pattern Analysis**: Binary representations may reveal bit flags
4. **Type Correlation**: Different parameter types may use different Column 7 values
5. **Next Step**: Correlate with Calterm "Available Offline" setting