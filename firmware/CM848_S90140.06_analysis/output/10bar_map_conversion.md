# CM848 10-Bar MAP Sensor Conversion Guide

## Overview

This document details the parameters required to upgrade from the OEM 3-bar MAP sensor to a 10-bar MAP sensor on the 2004.5 Dodge Cummins 5.9L HPCR (CM848D ECU).

**Key Finding:** There is NO single "max boost" parameter. The ECU indirectly limits boost through:
1. AFC (Air-Fuel Control) tables that reduce fueling as boost increases
2. BIR (Boost In Range) diagnostic thresholds for fault detection
3. Sensor linearization tables that define the ADC-to-pressure mapping

---

## 1. Sensor Linearization Tables (CRITICAL)

These tables convert raw ADC counts to pressure in IN_HG. Both must be recalibrated for the 10-bar sensor's output characteristics.

### ADC-to-Pressure Lookup Tables

| Parameter | EEPROM Address | Unit | Scale | Size | Description |
|-----------|---------------|------|-------|------|-------------|
| **ADBSPRXA** (Boost_Pressure_X_Axis) | 0x01101600 | CNTS | 1.0 | **8 x u16 (16 bytes)** | ADC breakpoint table (input axis) |
| **ADBSPRYA** (Boost_Pressure_Y_Axis) | 0x01101500 | IN_HG | 0.0159064138077 | **8 x u16 (16 bytes)** | Pressure output table (output axis) |

**Table Size Confirmed:** 8 breakpoints per axis (verified from ROM default tables at 0x0005937a/0x0005938c — first word is byte count 0x0010 = 16 bytes, pattern confirmed across multiple sensor channels).

**Scale Factor:** Raw value × 0.0159064138077 = IN_HG
- Example: Raw 1024 = 16.29 IN_HG ≈ 0.55 bar
- For 10-bar: Raw 65535 max × 0.0159064138077 = 1042 IN_HG ≈ 35.3 bar (sufficient for 10-bar)

### OEM 3-Bar Sensor Characteristics
- 3-bar absolute = ~2 bar gauge boost = ~58.8 IN_HG (absolute)
- 0.5V = 0 bar absolute (vacuum reference)
- 4.5V = 3 bar absolute (~29.4 IN_HG gauge at sea level)
- ADC range: 0-1023 (10-bit)

### 10-Bar Sensor Characteristics (Typical)
- 10-bar absolute = ~9 bar gauge boost = ~264.2 IN_HG (absolute)
- 0.5V = 0 bar absolute
- 4.5V = 10 bar absolute
- Same ADC range but different pressure/volt slope

**Action Required:** Recalculate X/Y table values based on new sensor's voltage-to-pressure curve.

---

## 2. Sensor Fault Detection Parameters

These must be adjusted so the ECU doesn't set fault codes with the new sensor's different voltage output at normal boost levels.

### ADC Range Limits

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| **ADBSPRHL** (Boost_Pressure_High_Limit) | 0x0114B004 | CNTS | 1.0 | Max valid ADC value |
| **ADBSPRLL** (Boost_Pressure_Low_Limit) | 0x0114B006 | CNTS | 1.0 | Min valid ADC value |

**Action Required:** May need adjustment if 10-bar sensor operates at different ADC range at idle/WOT.

### Fault Counter Parameters

| Parameter | Address | Description |
|-----------|---------|-------------|
| ADBSPRIC | 0x0114B008 | Fault increment (counts up when out of range) |
| ADBSPRDT | 0x0114B00A | Fault decrement (counts down when in range) |
| ADBSPRSE | 0x0114B00C | Fault set threshold |
| ADBSPRCC | 0x0114B00E | Fault clear threshold |

---

## 3. AFC (Air-Fuel Control) Tables (CRITICAL)

AFC limits fueling based on boost pressure. These tables MUST be extended for higher boost operation.

### Main AFC Tables

| Parameter | Address | Unit | Scale | Size | Description |
|-----------|---------|------|-------|------|-------------|
| **AFFLLMYA** (AFC_Boost_Pressure_Axis) | 0x01104D00 | IN_HG | 0.0159062501 | 14 values | Boost axis breakpoints |
| **AFFLLMXA** (AFC_Engine_Speed_Axis) | 0x01104E00 | RPM | 0.125 | 21 values | RPM axis breakpoints |
| **AFFLLMZA** (AFC_Fueling_Table) | 0x01104F00 | MM3S | 0.06793478400 | 14×21 table | Max fuel vs boost/RPM |

**How AFC Works:**
1. ECU reads current boost pressure and RPM
2. Interpolates into AFFLLMZA table
3. Limits commanded fuel to table value
4. Higher boost = more allowed fuel (up to table limit)

**Action Required:**
- Extend AFFLLMYA axis to include higher boost values
- Add corresponding fueling limits in AFFLLMZA for high-boost operation

### AFC Low Boost Protection

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| AFC_Low_Boost_Derate_Enable | 0x01106B02 | - | - | Enable/disable low boost protection |
| AFC_Low_Boost_Engine_Speed_Axis | 0x018D0800 | RPM | 0.125 | RPM axis for low boost |
| AFC_Low_Boost_Pressure_Axis | 0x018D0900 | IN_HG | 0.0159062501 | Boost axis for low boost |
| AFC_Low_Boost_Fueling_Table | 0x018D0A00 | MM3S | 0.06793478400 | Fuel limit when boost is low |
| AFC_Low_Boost_Time_Delay | 0x0111D518 | SEC | 0.02 | Time before error set |
| AFC_Normal_Boost_Time_Delay | 0x0111D51E | SEC | 0.02 | Time before error clears |
| AFC_Neg_Fueling_Slew_Rate | 0x0111D520 | MM3S | 0.06793478400 | Negative slew rate |

---

## 4. BIR (Boost In Range) Diagnostics

These thresholds determine when the ECU sets "boost out of range" fault codes.

### High Boost Fault Parameters

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| **BIR_Stabilized_Boost_Threshold** (DGSTBSTD) | 0x01163108 | IN_HG | 0.0159062501 | High boost error threshold |
| BIR_Boost_High_Time_Threshold (DGBSHTTD) | 0x01163102 | SEC | 0.10 | Time at high boost before error |
| BIR_Boost_Decay_Time_Threshold (DGBSDCTR) | 0x01163100 | SEC | 0.10 | Low boost time before BIRH check |
| BIR_Low_Load_Threshold (DGLWTD) | 0x01163104 | % | 0.00390625 | Load threshold for high boost check |
| BIR_LSG_Ref_Speed_Offset (DGLSRSOF) | 0x01163106 | RPM | 0.125 | RPM limit offset for BIRH test |

**Action Required:** Increase `BIR_Stabilized_Boost_Threshold` to prevent fault codes at higher boost levels.

### Low Boost Fault Parameters

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| BIR_Low_Boost_Threshold | 0x01163116 | IN_HG | 0.01590625 | Low boost error threshold |
| BIR_Low_Time_Threshold | 0x01163112 | SEC | 0.1 | Time at low boost before error |
| BIR_Low_Stabilized_Time_Threshold | 0x0116310E | SEC | 0.1 | Time before BIRL error check |
| BIR_High_Engine_Speed_Threshold | 0x01163110 | RPM | 0.125 | RPM limit for BIRL test |
| BIR_High_Load_Threshold | 0x01163114 | % | 0.00390625 | Load threshold for BIRL check |

### Startup Diagnostics

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| BIR_Keyon_Max_Pressure_Delta | 0x01163118 | IN_HG | 0.0159064138077 | Max boost delta at key-on |
| BIR_Startup_Threshold | 0x0116310A | IN_HG | 0.0159062501 | Startup fault threshold |
| BIR_Wait_Time | 0x0116310C | SEC | 0.1 | Delay before startup diagnostics |

---

## 5. Additional Boost-Related Parameters

### Turbo/Wastegate Monitor

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| Turbo_Maximum_High_Boost_Pressure | 0x01162E02 | IN_HG | 0.0159064138077 | High threshold for wastegate monitor |
| Turbo_Maximum_Low_Boost_Pressure | 0x01162E06 | IN_HG | 0.0159064138077 | Low threshold for wastegate monitor |

### Engine Brake Boost Limit

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| EB_Maximum_Boost_Pressure | 0x01107106 | IN_HG | 0.0159064138077 | Max boost for engine brake enable |

---

## 6. Complete Parameter Change Checklist

### Priority 1 - Required for Basic Operation

| Step | Parameter | Current | Suggested | Notes |
|------|-----------|---------|-----------|-------|
| 1 | ADBSPRXA (X-axis) | OEM 3-bar curve | Recalculate for 10-bar | ADC breakpoints |
| 2 | ADBSPRYA (Y-axis) | OEM 3-bar curve | Recalculate for 10-bar | Pressure values |
| 3 | BIR_Stabilized_Boost_Threshold | ~30 IN_HG? | ~100+ IN_HG | Prevent high boost fault |

### Priority 2 - Required for Performance

| Step | Parameter | Action |
|------|-----------|--------|
| 4 | AFFLLMYA (AFC boost axis) | Extend to include target boost levels |
| 5 | AFFLLMZA (AFC fuel table) | Add fueling values for extended boost range |
| 6 | Turbo_Maximum_High_Boost_Pressure | Increase to match target boost |

### Priority 3 - Recommended Adjustments

| Step | Parameter | Action |
|------|-----------|--------|
| 7 | BIR_Keyon_Max_Pressure_Delta | Adjust if startup faults occur |
| 8 | BIR_Startup_Threshold | Adjust if startup faults occur |
| 9 | AFC_Low_Boost tables | Extend if low-boost derate is used |
| 10 | EB_Maximum_Boost_Pressure | Increase if using engine brake at high boost |

---

## 7. ROM Sensor Configuration Data

The ROM contains sensor channel 3 (boost) default/fallback linearization tables at 0x5937a/0x5938c. These are overridden by EEPROM calibration values (ADBSPRXA/ADBSPRYA) when valid.

### ROM Config Structure (0x0005936a, 16 bytes)
```
388f 0000 03e0 002d 0001 0001 0177 0000
```

### ROM Default X-Axis (0x0005937a) — ADC Breakpoints
```
Format: [byte_count] [data...]
0010  0000 0011 0012 0066 0399 03fd 03fe 03ff
```

| Word | Hex | Decimal | Meaning |
|------|-----|---------|---------|
| 0 | 0x0010 | 16 | Byte count (16 bytes = 8 breakpoints) |
| 1 | 0x0000 | 0 | ADC min |
| 2 | 0x0011 | 17 | |
| 3 | 0x0012 | 18 | |
| 4 | 0x0066 | 102 | |
| 5 | 0x0399 | 921 | |
| 6 | 0x03FD | 1021 | |
| 7 | 0x03FE | 1022 | |
| 8 | 0x03FF | 1023 | ADC max (10-bit) |

### ROM Default Y-Axis (0x0005938c) — Pressure Output (IN_HG)
```
Format: [byte_count] [data...]
0010  02f2 02f2 02f2 02f2 19b9 19b9 19b9 19b9
```

| Word | Hex | Raw | IN_HG (×0.0159064) | PSI |
|------|-----|-----|---------------------|-----|
| 0 | 0x0010 | 16 | Byte count | — |
| 1-4 | 0x02F2 | 754 | 11.99 | 5.89 |
| 5-8 | 0x19B9 | 6585 | 104.73 | 51.46 |

**Note:** ROM defaults are a simple two-step function (fallback only). Live ECU EEPROM values at 0x01101600/0x01101500 contain the actual calibration curve.

### Table Format Convention
The first u16 word of each sensor linearization table is the **byte count** of the data that follows. Number of breakpoints = byte_count / 2. This pattern is consistent across all sensor channels:
- Channels 0, 2, 3 (boost): 0x0010 = 16 bytes = **8 breakpoints**
- Channel 4+: 0x0016 = 22 bytes = **11 breakpoints**

---

## 8. Data Flow Summary

```
                    ┌─────────────────────────┐
                    │     10-Bar MAP Sensor   │
                    │      0.5-4.5V output    │
                    └───────────┬─────────────┘
                                │
                                ▼
                    ┌─────────────────────────┐
                    │      ADC Channel 8/9    │
                    │      10-bit (0-1023)    │
                    └───────────┬─────────────┘
                                │
                                ▼
          ┌──────────────────────────────────────────────┐
          │         Sensor Linearization                  │
          │  ADBSPRXA (ADC) → ADBSPRYA (Pressure IN_HG)  │
          └───────────┬────────────────────────────┬─────┘
                      │                            │
                      ▼                            ▼
            boost_pressure_sensor_raw      boost_pressure_sensor_filtered
            (0x0040bd8e)                   (0x0040bda6)
                      │
                      ▼
          ┌─────────────────────────┐
          │  selectLoadNormalizer() │
          │  (0x0040a430 selector)  │
          └───────────┬─────────────┘
                      │
          ┌───────────┼───────────────────────────┐
          │           │                           │
          ▼           ▼                           ▼
    AFC Tables    Fuel Calcs                BIR Diagnostics
    (AFFLLMZA)   (boost_denominator)       (fault detection)
```

---

## 9. HP Tuners User Defined Parameters

### Live Monitoring (Scanner UDP)

| Parameter | RAM Address | Data Type | Scale | Offset | Unit | Description |
|-----------|-------------|-----------|-------|--------|------|-------------|
| Boost Raw | 0x0040BD8E | u16 | 0.0159064138077 | 0 | IN_HG | Unfiltered MAP sensor reading |
| Boost Filtered | 0x0040BDA6 | u16 | 0.0159064138077 | 0 | IN_HG | Filtered MAP sensor reading |

### Calibration Editing (EEPROM Tables)

**Sensor Linearization (8 breakpoints each, 16 bytes per table):**

| Table | EEPROM Address | Data Type | Scale | Unit | Description |
|-------|---------------|-----------|-------|------|-------------|
| ADBSPRXA | 0x01101600 | 8 x u16 | 1.0 | CNTS | ADC breakpoints (0-1023 range) |
| ADBSPRYA | 0x01101500 | 8 x u16 | 0.0159064138077 | IN_HG | Pressure output values |

**AFC Fuel Limiting:**

| Table | EEPROM Address | Data Type | Scale | Unit | Size |
|-------|---------------|-----------|-------|------|------|
| AFFLLMYA | 0x01104D00 | u16 | 0.0159062501 | IN_HG | 14 values (boost axis) |
| AFFLLMXA | 0x01104E00 | u16 | 0.125 | RPM | 21 values (RPM axis) |
| AFFLLMZA | 0x01104F00 | u16 | 0.06793478400 | MM3/stroke | 14x21 table |

**BIR Thresholds (single values):**

| Parameter | EEPROM Address | Data Type | Scale | Unit |
|-----------|---------------|-----------|-------|------|
| BIR_Stabilized_Boost | 0x01163108 | u16 | 0.0159062501 | IN_HG |
| Turbo_Max_High_Boost | 0x01162E02 | u16 | 0.0159064138077 | IN_HG |
| Turbo_Max_Low_Boost | 0x01162E06 | u16 | 0.0159064138077 | IN_HG |

---

## Notes

- All calibration addresses are in the 0x01xxxxxx range (EEPROM/cal flash)
- RAM addresses (0x0040xxxx) are for live monitoring only
- Scale factors must be applied when reading/writing values
- Test changes incrementally - start with linearization tables, then AFC
- Always verify with diagnostic scan tool after changes
- Back up original calibration before any modifications

**Generated from CM848 S90140.06 firmware reverse engineering analysis**
