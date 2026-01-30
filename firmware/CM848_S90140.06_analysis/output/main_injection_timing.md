# CM848 Main Injection Timing Analysis

## Overview

The HPCR main injection timing (Main SOI - Start of Injection) controls when the primary fuel delivery event occurs. Unlike pilot injection which uses a simple 3D base map, Main SOI uses a **correction-based architecture** where multiple environmental factors are summed to determine final timing.

## Timing Benefits Trade-offs

| Advance Timing (Earlier) | Retard Timing (Later) |
|--------------------------|----------------------|
| More power/torque | Lower NOx emissions |
| Better fuel economy | Reduced combustion noise |
| Higher peak cylinder pressure | Lower peak temperatures |
| Higher NOx emissions | Slightly lower efficiency |

## Architecture

### Correction-Based Calculation

Main SOI timing is calculated by summing multiple correction factors:

```
Main_SOI = Base_Timing
         + Main_SOI_Cool_Correction
         + Main_SOI_Air_Temp_Correction
         + Main_SOI_Air_Press_Correction
         + Main_SOI_Boost_Correction
         + Chi2/Chi3/Chi4 corrections
         + Alpha1 correction
         + Cranking corrections (if cranking)
         + CT_Derate correction (if overtemp)
```

### Two-Stage Correction Pattern

Each environmental correction uses a two-stage pattern:

```
Stage 1: Precorr Table (3D)
  Inputs: RPM × Fueling
  Output: Base correction amount (degrees)

Stage 2: Factor Curve (1D or 2D)
  Input: Environmental sensor value
  Output: Multiplier (0.0 - 2.0 typical)

Final Correction = Precorr × Factor
```

This allows calibrators to:
- Set the maximum correction magnitude via the Precorr table
- Shape the response curve via the Factor table

---

## Selection and Control Parameters

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| Main_SOI_Selection_Switch | 0x01808500 | - | 3 | Timing algorithm selector |
| Final_Timing | 0x01105B02 | deg BTDC | 0.117 | Final TVC output |
| Final_Timing_State | 0x01103B08 | bitmap | - | Which algorithm controls |
| Final_Timing_Adjustments_Flag | 0x01808622 | bitmap | - | Active adjustments |

---

## Coolant Temperature Correction

Cold engines need advanced timing for better combustion; warm engines use baseline timing.

### Precorr Table (3D)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Main_SOI_Cool_Precorr_Speed_Axis | 0x01809600 | RPM | 0.125 |
| Main_SOI_Cool_Precorr_Fueling_Axis | 0x01809700 | MM3S | 0.0679 |
| Main_SOI_Cool_Precorr_Axis | 0x01809800 | deg BTDC | 0.117 |

**Output:** `Main_SOI_Cool_Precorr` @ 0x01808610

### Factor Curve (2D - Coolant × IMT)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Main_SOI_Cool_Temp_Axis | 0x01808900 | DEG_F | 0.0156 |
| Main_SOI_Cool_IMT_Axis | 0x01880200 | DEG_F | 0.0156 |
| Main_SOI_Cool_Factor_Axis | 0x01808A00 | - | 0.000244 |

**Output:** `Main_SOI_Cool_Factor` @ 0x0180860E

### Final Correction

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| Main_SOI_Cool_Correction | 0x0180860C | deg BTDC | Precorr × Factor |

**Typical behavior:**
- Cold (-20°F): Factor ~1.5-2.0 (advance timing)
- Warm (180°F): Factor ~1.0 (baseline)
- Hot (220°F+): Factor ~0.8 (slight retard)

---

## Intake Air Temperature Correction

Cold dense air needs timing adjustment; hot thin air behaves differently.

### Precorr Table (3D)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Main_SOI_Air_Temp_Precorr_Speed_Axis | 0x01809900 | RPM | 0.125 |
| Main_SOI_Air_Temp_Precorr_Fueling_Axis | 0x01809A00 | MM3S | 0.0679 |
| Main_SOI_Air_Temp_Precorr_Axis | 0x01809B00 | deg BTDC | 0.117 |

**Output:** `Main_SOI_Air_Temp_Precorr` @ 0x0180860A

### Factor Curve (1D)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Main_SOI_Air_Temp_Axis | 0x01808B00 | DEG_F | 0.0156 |
| Main_SOI_Air_Temp_Factor_Axis | 0x01808C00 | - | 0.000244 |

**Output:** `Main_SOI_Air_Temp_Factor` @ 0x01808608

### Final Correction

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| Main_SOI_Air_Temp_Correction | 0x01808606 | deg BTDC | Precorr × Factor |

---

## Ambient Air Pressure Correction

Altitude compensation - lower atmospheric pressure affects combustion.

### Precorr Table (3D)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Main_SOI_Air_Press_Precorr_Speed_Axis | 0x01809C00 | RPM | 0.125 |
| Main_SOI_Air_Press_Precorr_Fueling_Axis | 0x01809D00 | MM3S | 0.0679 |
| Main_SOI_Air_Press_Precorr_Axis | 0x01809E00 | deg BTDC | 0.117 |

**Output:** `Main_SOI_Air_Press_Precorr` @ 0x01808604

### Factor Curve (1D)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Main_SOI_Air_Press_Axis | 0x01808D00 | IN_HG | 0.0159 |
| Main_SOI_Air_Press_Factor_Axis | 0x01808E00 | - | 0.000244 |

**Output:** `Main_SOI_Air_Press_Factor` @ 0x01808602

### Final Correction

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| Main_SOI_Air_Press_Correction | 0x01808600 | deg BTDC | Precorr × Factor |

**Typical behavior:**
- Sea level (29.9 in-Hg): Factor ~1.0
- 5000 ft (~24.9 in-Hg): Factor ~1.1-1.2
- 10000 ft (~20.6 in-Hg): Factor ~1.3-1.5

---

## Boost Pressure Correction

Higher boost = higher cylinder pressure = may need timing retard to control peak pressure.

### Precorr Table (3D)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Main_SOI_Boost_Precorr_Speed_Axis | 0x01809F00 | RPM | 0.125 |
| Main_SOI_Boost_Precorr_Fueling_Axis | 0x0180A000 | MM3S | 0.0679 |
| Main_SOI_Boost_Precorr_Axis | 0x0180A100 | deg BTDC | 0.117 |

**Output:** `Main_SOI_Boost_Precorr` @ 0x0180861E

### Factor Table (2D - RPM × Boost)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Main_SOI_Boost_Factor_Speed_Axis | 0x01880100 | RPM | 0.125 |
| Main_SOI_Boost_Factor_Boost_Axis | 0x01808F00 | IN_HG | 0.0159 |
| Main_SOI_Boost_Factor_Axis | 0x01809000 | - | 0.000244 |

**Output:** `Main_SOI_Boost_Factor` @ 0x0180861C

### Final Correction

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| Main_SOI_Boost_Correction | 0x0180861A | deg BTDC | Precorr × Factor |

**Typical behavior:**
- Low boost (15 psi): Factor ~1.0
- Medium boost (30 psi): Factor ~0.8-0.9 (retard)
- High boost (45+ psi): Factor ~0.6-0.7 (more retard)

---

## Cranking Timing

Special timing during engine cranking for reliable starts.

### Cranking Table (2D - RPM × Coolant)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Main_SOI_Cranking_Speed_Axis | 0x01809100 | RPM | 0.125 |
| Main_SOI_Cranking_Cool_Temp_Axis | 0x01809200 | DEG_F | 0.0156 |
| Main_SOI_Cranking_SOI_Axis | 0x01809300 | deg BTDC | 0.117 |

**Output:** `Main_SOI_Crank_Air_Correction` @ 0x01808612

**Typical cranking timing:** 5-15° more advanced than running timing for reliable ignition at low RPM.

---

## Coolant Temperature Derate

When coolant exceeds 224°F, special timing protection activates.

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| CT_Derate_Main_SOI | 0x018A722A | deg BTDC | 0.117 | Active derate value |
| CT_Derate_Main_SOI_Slew_Rate | 0x018A7120 | deg/SEC | 1.172 | Rate of change limit |
| CT_Derate_Main_SOI_Speed_Axis | 0x018B2F00 | RPM | 0.125 | Speed breakpoints |
| CT_Derate_Main_SOI_Table | 0x018B3000 | deg BTDC | 0.117 | Derate amount by RPM |

This retards timing to reduce combustion temperatures when the engine is overheating.

---

## Fuel Pressure Limp Mode

When fuel rail pressure is out of spec, fallback timing is used.

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| Main_SOI_Fuelpr_Derate_Default | 0x01808506 | deg BTDC | Limp-home timing |
| Main_SOI_Fuelpr_No_Derate | 0x01808508 | deg BTDC | Normal operation timing |
| Main_SOI_Fuelpr_Derate_Correction | 0x01808628 | deg BTDC | Pressure-based adjustment |

---

## Extended Idle Timing

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| LSG_Extended_Idle_Main_SOI | 0x01808504 | deg BTDC | Low-speed governor idle timing |

---

## Timing Limits

| Parameter | Address | Description |
|-----------|---------|-------------|
| Main_Penultimate_SOI | 0x01808620 | Next-to-final (before limiting) |
| Max_Main_SOI | (in code) | Maximum allowed advance |
| Min_Main_SOI | (in code) | Maximum allowed retard |

---

## Relationship to Pilot Timing

The pilot injection occurs before main injection. The separation is controlled by:

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| Pilot_SOI_to_Main_SOI_Distance | 0x01806C26 | deg BTDC | Separation angle |

**Typical separation:** 15-25 degrees between pilot and main SOI.

If pilot occurs at 35° BTDC and separation is 20°, main occurs at 15° BTDC.

---

## Auxiliary Injection (Post-Main)

For applications with post-injection (DPF regen, etc.):

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| Main_SOI_to_Aux_SOI_Distance | 0x0180CE12 | deg ATDC | Main to aux separation |
| aux_soi_end_of_main_adjust | 0x01805C0E | flag | 0=SOI-SOI, 1=EOI-SOI |

---

## Functions

### calculateFuelInjectionTiming() @ 0x00016a90

Primary timing calculation function. Performs:
1. Base timing lookup
2. All correction factor calculations
3. Summing of corrections
4. Output to timing registers

**Key variables used:**
- `injection_timing_raw` @ 0x0040a53e - Raw calculated timing
- `injection_timing_ratio` @ 0x0040a53c - Blend ratio
- `injection_timing_offset` @ 0x0040a542 - Offset from base
- `injection_timing_lookup_1` @ 0x0040a540 - First table result
- `injection_timing_lookup_2` @ 0x0040a544 - Second table result

### processFuelTimingCalculations() @ 0x00016e90

Post-processing that applies:
- Manifold pressure corrections
- Final limiting
- Rate limiting for smooth transitions

### periodicTaskGroup7_timing @ 0x0000bb90

Scheduler task that calls timing functions periodically.

---

## Calibration Tips for 10-Bar MAP Upgrade

When upgrading to 10-bar MAP sensor for higher boost:

### Boost Correction Tables

1. **Extend boost axis range:**
   - Current: 0-45 psi typical
   - 10-bar capable: 0-145 psi

2. **Add breakpoints at:**
   - 50, 60, 75, 90, 105, 120, 135, 145 psi

3. **Factor curve extension:**
   - Higher boost typically needs more timing retard
   - Factor values 0.4-0.6 may be needed at extreme boost

### Safety Considerations

- At high boost (>60 psi), timing must be conservative
- Peak cylinder pressure limits (~2500-2800 psi typical)
- Retard timing 1-2° for every 10 psi above stock max boost

---

## E2M Parameter Cross-Reference

| Correction | Precorr Table | Factor Table | Output |
|------------|---------------|--------------|--------|
| Coolant | 0x01809600-0x01809800 | 0x01808900-0x01808A00 | 0x0180860C |
| Air Temp | 0x01809900-0x01809B00 | 0x01808B00-0x01808C00 | 0x01808606 |
| Ambient | 0x01809C00-0x01809E00 | 0x01808D00-0x01808E00 | 0x01808600 |
| Boost | 0x01809F00-0x0180A100 | 0x01808F00-0x01809000 | 0x0180861A |
| Cranking | 0x01809100-0x01809300 | - | 0x01808612 |

---

## Unit Conversions

### Timing (CRANK_DEG_BTDC)
- Raw value × 0.1171875 = degrees BTDC
- 1 raw unit ≈ 0.117° (high resolution for precise timing)
- Typical main SOI: 5-20° BTDC

### Temperature (DEG_F)
- Raw value × 0.015625 = degrees Fahrenheit
- 180°F = raw 11520

### Pressure (IN_HG)
- Raw value × 0.0159 = inches of mercury
- 1 bar ≈ 29.53 in-Hg
- 30 psi ≈ 61 in-Hg (raw ~3840)
