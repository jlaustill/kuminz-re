# Task 005: Document Parameter Lookup System

## Status: [X] Done

**Started:** 2024-12-17
**Completed:** 2024-12-17

## Goal

Document how the CM550 firmware looks up and calculates parameter values, including the relationship between calibration tables, e2m addresses, and runtime calculations.

## Key Functions

### 1. param_address_calc (0x165f2)

**Purpose:** Core division function with saturation (overflow protection)

```c
uint param_address_calc(uint param_1, undefined4 param_2) {
    // If result would overflow 16-bit, saturate to 0xFFFF
    if ((uint)param_2._0_2_ * 0xffff <= param_1) {
        return CONCAT22((short)((uint)param_2._0_2_ * 0xffff >> 0x10), 0xffff);
    }
    return param_1 / param_2._0_2_;
}
```

**Usage:** Called by param_lookup_1 and param_lookup_3 to calculate percentage/ratio values.

**Match:** 100% identical to J90280.05 @ 0x012afa

---

### 2. param_lookup_1 (0xf8c6)

**Purpose:** Calculate fuel ratio based on determined peak fueling vs maximum non-injecting fuel

```c
void param_lookup_1(void) {
    // Skip if determined fueling is below injection threshold
    if (determined_peak_engine_fueling - max_non_inject_fuel < 1) {
        result = 0;
        return;
    }

    // Calculate: (current - threshold) * 25600 / (100% - threshold)
    result = param_address_calc((current - threshold) * 0x6400);

    // Clamp to 32000 (125% scale factor)
    if (result > 32000) result = 32000;
}
```

**RAM Variables Used:**
- `_determined_peak_engine_fueling_0_100` - Current fueling demand
- `maximum_fueling_value_that_does_not_inject_fuel_0_100` - Injection threshold
- `_DAT_0080da16` - Output result

**Match:** 81% similar to J90280.05 @ 0x00d632

---

### 3. param_lookup_3 (0xf930)

**Purpose:** Calculate J1939 percent load (PGN 61443 - Engine Percent Load at Current Speed)

```c
void param_lookup_3(void) {
    // Same logic as param_lookup_1, but outputs to J1939 parameter
    // Output: jcomm_ind_percent_load_ratio_of_actual_engine_torque_to_max_to_0_125
}
```

**J1939 Integration:** This function directly calculates the value broadcast on J1939 PGN 61443.

**Match:** 81% similar to J90280.05 @ 0x00d756

---

### 4. addressLookupFunction (0x21964)

**Purpose:** Look up byte value from ROM table based on index

```c
uint addressLookupFunction(undefined4 param_1) {
    if (param_1._1_1_ > 0x40) {
        // Table lookup at ROM address 0x21915
        return *(byte *)((short)(ushort)param_1._1_1_ + 0x21915);
    }
    return 0;  // Index out of range
}
```

**ROM Table:** 0x21915 - Parameter index to value mapping table

**Match:** 92% similar to J90280.05 @ 0x01b7ca

---

### 5. parameterLookupForInsite (0x2edb2)

**Purpose:** Map Insite parameter request IDs to response sizes

```c
undefined2 parameterLookupForInsite(void) {
    // DAT_0080dde5 = parameter request ID from Insite

    if (DAT_0080dde5 < 0x80)  return 2;   // Small response
    if (DAT_0080dde5 < 0xC0)  return 3;   // Medium response
    if (DAT_0080dde5 == 0xC1) return calculated_from_599c;
    if (DAT_0080dde5 == 0xC2) return calculated_from_5998;
    if (DAT_0080dde5 == 0xC4) return 4 or 7 based on state;
    if (DAT_0080dde5 == 0xEA) return 0x18; // 24 bytes
    if (DAT_0080dde5 == 0xED) return 0x16; // 22 bytes
    if (DAT_0080dde5 == 0xF3) return 0x1F; // 31 bytes
    return 6;  // Default
}
```

**Parameter ID Ranges:**
| ID Range | Response Size | Description |
|----------|---------------|-------------|
| 0x00-0x7F | 2 bytes | Simple parameters |
| 0x80-0xBF | 3 bytes | Extended parameters |
| 0xC0-0xC4 | Calculated | Complex parameters |
| 0xEA | 24 bytes | Multi-value block |
| 0xED | 22 bytes | Multi-value block |
| 0xF3 | 31 bytes | Large data block |

**Match:** 94% similar to J90280.05 @ 0x0271b0

---

### 6. FUN_00035088 (0x35088) - 2D Table Interpolation

**Purpose:** Perform 2D interpolation on calibration tables (e.g., RPM vs Load maps)

**Algorithm:**
1. Look up X-axis breakpoints (e.g., RPM)
2. Look up Y-axis breakpoints (e.g., Load)
3. Find bounding cell indices
4. Bilinear interpolation between 4 corners

**Table Structure:**
```
param_1+0: X-axis offset pointer
param_1+2: Pointer to X-axis breakpoint table
param_1+4: Y-axis offset
param_1+6: Pointer to Y-axis breakpoint table
param_1+8: Current X value (e.g., RPM)
param_1+10: Current Y value (e.g., Load)
```

**Example Call:**
```c
// From rpmLoadParameterLookup:
FUN_00035088(0x801aaa);  // Table descriptor at RAM 0x801aaa
```

---

## Parameter Addressing Architecture

### Memory Regions for Parameters

| Region | Address Range | Purpose |
|--------|---------------|---------|
| ROM Tables | 0x004000-0x00b000 | Calibration lookup tables |
| ROM Code | 0x00b000-0x035000 | Parameter calculation code |
| RAM Variables | 0x800000-0x8091C2 | Runtime parameter values |
| EEPROM | 0x1000000-0x1000FFF | Persistent configuration |

### Calculation Flow

```
1. Sensor Input (ADC) → Raw Value
                            ↓
2. Scaling/Filtering → Calibrated Value (RAM)
                            ↓
3. Table Lookup (2D interpolation) → Intermediate Value
                            ↓
4. param_address_calc → Ratio/Percentage
                            ↓
5. Output → J1939 Broadcast / Actuator Command
```

### E2M Integration

The e2m files store calibration parameters that correspond to:
- **Table breakpoints** - X/Y axis values for lookup tables
- **Table cells** - Interpolation data values
- **Scalar parameters** - Direct values (limits, thresholds)

**Address Formula:** `BaseAddress[Column3] + Column4 = Final ROM Address`

---

## Relationship to E2M Analysis

| E2M Concept | Firmware Implementation |
|-------------|------------------------|
| Base Address | ROM table start offset |
| Column4 Offset | Row/column index |
| Parameter Value | Table cell or scalar |
| Group ID (Column14) | Functional grouping |

---

## Related Functions (Not Fully Analyzed)

| Address | Name | Purpose |
|---------|------|---------|
| 0x00f8c6 | param_lookup_1 | Load ratio calculation |
| 0x00f930 | param_lookup_3 | J1939 percent load |
| 0x0026ab8 | rpmLoadParameterLookup | RPM/Load table access |
| 0x035088 | FUN_00035088 | 2D bilinear interpolation |

---

## Next Steps

1. **Map ROM tables** - Identify all calibration tables in 0x4000-0xB000
2. **Correlate with e2m** - Match e2m base addresses to ROM table locations
3. **Document table formats** - Header structure, breakpoint layout, data types
4. **Trace Insite parameters** - Follow parameterLookupForInsite to understand each ID

---

## Files Referenced

- `firmware/J90350.00_analysis/output/J90350.00.ghidra.cpp` - Decompiled source
- `firmware/J90350.00_analysis/output/function_renames.csv` - Function names
- `firmware/J90350.00_analysis/output/global_variables.csv` - RAM variable names
