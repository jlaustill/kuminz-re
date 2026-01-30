# CM848 Pilot Injection Tables Analysis

## Overview

The HPCR (High Pressure Common Rail) system uses pilot injection to reduce combustion noise and NOx emissions. A small quantity of fuel is injected before the main injection event.

## Pilot Injection Benefits

1. **Reduced combustion noise** - Pre-heats the combustion chamber
2. **Lower peak cylinder pressure** - More gradual pressure rise
3. **Reduced NOx emissions** - Lower peak temperatures
4. **Improved cold start** - Better combustion at low temperatures

## Table Architecture

### Pilot Quantity Calculation

The pilot fuel quantity is calculated using a base map plus multiple correction factors:

```
Pilot_Fuel_Quantity = Pilot_Base_Fuel_Quantity
                    + Pilot_Quantity_Cool_Corr_Value
                    + Pilot_Quantity_Air_Temp_Correction
                    + Pilot_Quantity_Ambient_Correction
                    + Pilot_Quantity_Boost_Correction
                    + Chi2/Chi3/Chi4 corrections
                    + Alpha1 correction
                    + AECD corrections (emissions)
                    + Crank corrections (if cranking)
```

### Base Pilot Quantity Map (3D)

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| Pilot_Quantity_Base_Speed_Axis | 0x01806000 | RPM | 0.125 | X-Axis: Engine speed |
| Pilot_Quantity_Base_Fueling_Axis | 0x01806100 | MM3S | 0.0679 | Y-Axis: Main fueling |
| Pilot_Quantity_Base_Pilot_Axis | 0x01806200 | MM3S | 0.0679 | Z-Axis: Pilot output |

**Typical Base Map Structure:**
- Speed breakpoints: 600, 800, 1000, 1200, 1500, 2000, 2500, 3000 RPM
- Fueling breakpoints: 0, 20, 40, 60, 80, 100, 120, 150 mm³/stroke
- Pilot output: 2-20 mm³/stroke typical

### Correction Factor Tables

#### 1. Coolant Temperature Correction

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Pilot_Quantity_Cool_Corr_Temp_Axis | 0x01806300 | DEG_F | 0.0156 |
| Pilot_Quantity_Cool_Corr_Factor_Axis | 0x018B6700 | - | 0.000244 |
| Pilot_Quantity_Cool_Corr_IMT_Axis | 0x018B6600 | DEG_F | 0.0156 |

**Output:** `Pilot_Quantity_Cool_Corr_Value` @ 0x01806A06
- Cold engine: Increases pilot quantity (better ignition)
- Warm engine: Baseline pilot quantity

#### 2. Air Temperature Correction

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Pilot_Quantity_Air_Temp_Corr_Temp_Axis | 0x018AA900 | DEG_F | 0.0156 |
| Pilot_Quantity_Air_Temp_Corr_Factor_Axis | 0x018AAA00 | - | 0.000244 |
| Pilot_Quantity_Air_Temp_Precorr_Speed_Axis | 0x018AAB00 | RPM | 0.125 |
| Pilot_Quantity_Air_Temp_Precorr_Fueling_Axis | 0x018AAC00 | MM3S | 0.0679 |
| Pilot_Quantity_Air_Temp_Precorr_Axis | 0x018AAD00 | MM3S | 0.0679 |

**Output:** `Pilot_Quantity_Air_Temp_Correction` @ 0x01806A0E
- Cold air: Increases pilot (denser charge needs more pre-heat)
- Hot air: Reduces pilot (easier ignition)

#### 3. Ambient Pressure Correction

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Pilot_Quantity_Ambient_Corr_Pres_Axis | 0x018AF900 | IN_HG | 0.0156 |
| Pilot_Quantity_Ambient_Corr_Temp_Axis | 0x018AFA00 | DEG_F | 0.0156 |
| Pilot_Quantity_Ambient_Corr_Factor_Axis | 0x018AFB00 | - | 0.000244 |
| Pilot_Quantity_Ambient_Precorr_Speed_Axis | 0x018AF200 | RPM | 0.125 |
| Pilot_Quantity_Ambient_Precorr_Fueling_Axis | 0x018AF700 | MM3S | 0.0679 |
| Pilot_Quantity_Ambient_Precorr_Axis | 0x018AF800 | MM3S | 0.0679 |

**Output:** `Pilot_Quantity_Ambient_Correction` @ 0x01806A12
- Low altitude (high pressure): Baseline
- High altitude (low pressure): May increase pilot for better ignition

#### 4. Boost Pressure Correction

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Pilot_Quantity_Boost_Factor_Speed_Axis | 0x018C6F00 | RPM | 0.125 |
| Pilot_Quantity_Boost_Factor_Boost_Axis | 0x018C6E00 | IN_HG | 0.0159 |
| Pilot_Quantity_Boost_Factor_Axis | 0x018C6D00 | - | 0.000305 |
| Pilot_Quantity_Boost_Precorr_Speed_Axis | 0x018C7200 | RPM | 0.125 |
| Pilot_Quantity_Boost_Precorr_Fueling_Axis | 0x018C7100 | MM3S | 0.0679 |
| Pilot_Quantity_Boost_Precorr_Axis | 0x018C7000 | MM3S | 0.0679 |

**Output:** `Pilot_Quantity_Boost_Correction` @ 0x01806A1A (4 bytes)
- Low boost: May need more pilot for ignition assist
- High boost: Higher cylinder temps, less pilot needed

### Chi Correction Tables (Emissions)

Chi tables provide additional corrections for emissions compliance:

| Table | Speed Axis | Fueling Axis | Output Axis |
|-------|------------|--------------|-------------|
| Chi2 | 0x018C9100 | 0x018C9200 | 0x018C9300 |
| Chi3 | 0x018C9400 | 0x018C9500 | 0x018C9600 |
| Chi4 | 0x018C9700 | 0x018C9800 | 0x018C9900 |

### Alpha1 Correction Table

Alternative correction path:

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Pilot_Quantity_Alpha1_Speed_Axis | 0x018B5E00 | RPM | 0.125 |
| Pilot_Quantity_Alpha1_Fueling_Axis | 0x018B5F00 | MM3S | 0.0679 |
| Pilot_Quantity_Alpha1_Pilot_Axis | 0x018B6000 | MM3S | 0.0679 |

### AECD (Auxiliary Emission Control Device) Tables

For emissions control strategies:

| Parameter | Address | Description |
|-----------|---------|-------------|
| Pilot_Quantity_AECD_Corr_Temp_Axis | 0x018D4200 | Temperature axis |
| Pilot_Quantity_AECD_Corr_IMT_Axis | 0x018D4300 | IMT axis |
| Pilot_Quantity_AECD_Corr_Factor_Axis | 0x018D4400 | Factor output |
| Pilot_Quantity_AECD_Setpt_Speed_Axis | 0x018D4500 | Speed axis |
| Pilot_Quantity_AECD_Setpt_Fueling_Axis | 0x018D4600 | Fueling axis |
| Pilot_Quantity_AECD_Setpt_Output_Axis | 0x018D4700 | Setpoint output |

**Logic Select:** `Pilot_Quantity_AECD_Logic_Select` @ 0x01805F20
- 0 = Sum all corrections
- 1 = Max wins
- 2 = Min wins
- 3 = Default (no AECD adjustment)

## Pilot Quantity Limits

| Parameter | Address | Unit | Scale | Description |
|-----------|---------|------|-------|-------------|
| Max_Pilot_Fuel | 0x01806A14 | MM3S | 0.0679 | Calculated max based on ratio |
| HPCR_Pilot_To_Main_Ratio_Limit | 0x01805F1C | - | 0.000244 | Max pilot/main ratio |
| Pilot_Quantity_Max_Increment | 0x01805F08 | MM3S/SEC | 0.0000518 | Rate limit up |
| Pilot_Quantity_Max_Decrement | 0x01805F04 | MM3S/SEC | 0.0000518 | Rate limit down |

**Typical ratio limit:** 15-20% of main fueling

## Pilot Quantity Override

| Parameter | Address | Description |
|-----------|---------|-------------|
| Pilot_Quantity_Override_Switch | 0x01805F00 | 1=use override, 0=normal |
| Pilot_Quantity_Override_Value | 0x01805F02 | Override quantity (MM3S) |
| Pilot_Quantity_Fuelpr_Limp_Home_Default | 0x01805F1E | Limp home pilot qty |

## Pilot Quantity Output Variables

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| Pilot_Base_Fuel_Quantity | 0x01806A00 | MM3S | Base map output |
| Pilot_Fuel_Quantity | 0x01806A02 | MM3S | Final pilot quantity |
| Pilot_Fuel_State | 0x01806A1E | Bitmap | Which contributor controls |
| Pilot_Fueling | 0x01120C0C | MM3S | Desired pilot fueling |
| Injected_Pilot_Fuel | 0x01819214 | MM3S | Actually injected |
| FSS_Pilot_SOI | 0x01819218 | deg BTDC | Actual timing used |

---

## Pilot SOI (Start of Injection Timing)

### Pilot SOI Calculation

Similar structure to pilot quantity:

```
Pilot_SOI = Pilot_SOI_Base
          + Pilot_SOI_Cool_Correction
          + Pilot_SOI_Air_Temp_Correction
          + Pilot_SOI_Air_Press_Correction
          + Pilot_SOI_Boost_Correction
          + Chi2/Chi3/Chi4 corrections
          + Alpha1 correction
```

### Base Pilot SOI Map (3D)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| Pilot_SOI_Base_Speed_Axis | 0x01807E00 | RPM | 0.125 |
| Pilot_SOI_Base_Fueling_Axis | 0x01807F00 | MM3S | 0.0679 |
| Pilot_SOI_Base_Axis | 0x01808000 | deg BTDC | 0.117 |

**Output:** `Pilot_SOI_Base` @ 0x01806C0E (degrees BTDC)
- Typical range: 20-45 degrees BTDC
- Earlier at low loads, later at high loads

### Pilot SOI Correction Tables

| Correction | Factor Address | Precorr Address | Output Address |
|------------|----------------|-----------------|----------------|
| Coolant | 0x01807100 | 0x01808100 | 0x01806C10 |
| Air Temp | 0x01807300 | 0x01808200 | 0x01806C08 |
| Air Press | 0x01807500 | 0x01808300 | 0x01806C02 |
| Boost | 0x018AA400 | 0x01808400 | 0x01806C1E |

### Pilot-to-Main Separation

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| Pilot_SOI_to_Main_SOI_Distance | 0x01806C26 | deg BTDC | Separation angle |
| Pilot_SOI_Penultimate_Dist | 0x01806C24 | deg BTDC | Pre-final separation |
| Pilot_SOI_Constant_Time_Flag | 0x01806C28 | - | 1=fixed time interval |
| Pilot_SOI_Constant_Time_RPM_Window | 0x01806D0A | RPM | Window for fixed timing |

**Typical separation:** 15-25 degrees between pilot and main

### Pilot SOI Limits

| Parameter | Address | Description |
|-----------|---------|-------------|
| Max_Pilot_SOI_Offset | 0x01806D0C | Max offset from possible timing |
| Max_Allowable_Pilot_SOI | 0x01806C2E | Calculated limit |
| Max_Possible_Pilot_SOI | 0x01806C30 | Hardware limit |
| Pilot_SOI_Before_Limit | 0x01806C32 | Before limiting applied |
| Pilot_SOI_Limit_Exceeded_Counter | 0x01806C34 | Times limit enforced |

### Pilot SOI Output

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| Pilot_SOI | 0x01806C00 | deg BTDC | Final pilot timing |
| Pilot_SOI_State | 0x01806C38 | Bitmap | Which factor controls |
| Pilot_SOI_Input_Engine_Speed | 0x01806C2A | RPM | Speed used for lookup |

---

## HPCR Pilot Duration Map

The actual injector pulse duration for pilot injection:

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| HPCR_Pilot1_Map_Fuel_Axis | 0x01805200 | MM3S | 0.0679 |
| HPCR_Pilot1_Map_Fuelpr_Axis | 0x01805300 | MPa | 0.0488 |
| HPCR_Pilot1_Map_Duration_Axis | 0x01805400 | USEC | 0.4 |

This 3D map converts pilot fuel quantity and rail pressure into injector on-time in microseconds.

---

## Calibration Tips for 10-Bar MAP Upgrade

When upgrading to a 10-bar MAP sensor for higher boost levels:

### Pilot Quantity Adjustments

1. **Boost Correction Tables** - Extend boost axis range from ~45 psi to ~145 psi
2. **Chi Tables** - May need adjustment for higher boost points
3. **Ratio Limit** - Consider reducing at high boost (more main, less pilot needed)

### Pilot SOI Adjustments

1. **Boost Correction** - May need retard at higher boost
2. **Pilot-to-Main Separation** - Higher boost may need more separation
3. **Constant Time Window** - Review for higher RPM/boost operation

### Key Breakpoint Extensions

For boost correction tables, extend:
- Current boost axis: 0-45 psi range
- 10-bar capable: 0-145 psi range

Add breakpoints at:
- 50, 60, 75, 90, 105, 120, 135, 145 psi

---

## E2M Parameter Cross-Reference

| Feature | Quantity Parameters | Timing Parameters |
|---------|--------------------|--------------------|
| Base Map | 0x01806000-0x01806200 | 0x01807E00-0x01808000 |
| Coolant | 0x01806300, 0x018B6600-0x018B6700 | 0x01807000-0x01807100 |
| Air Temp | 0x018AA900-0x018AAD00 | 0x01807200-0x01807300 |
| Ambient | 0x018AF200-0x018AFB00 | 0x01807400-0x01807500 |
| Boost | 0x018C6D00-0x018C7200 | 0x01807600-0x01807700 |
| Chi2 | 0x018C9100-0x018C9300 | 0x018C9A00-0x018C9C00 |
| Chi3 | 0x018C9400-0x018C9600 | 0x018C9D00-0x018C9F00 |
| Chi4 | 0x018C9700-0x018C9900 | 0x018CA000-0x018CA200 |
| Alpha1 | 0x018B5E00-0x018B6000 | 0x018B6100-0x018B6300 |
