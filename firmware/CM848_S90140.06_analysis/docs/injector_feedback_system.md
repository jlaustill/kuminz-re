# CM848 Injector Feedback and Adaptation System

This document describes how the CM848 ECU monitors and adapts injector fuel delivery without relying solely on bench calibration.

## Overview

The CM848 uses **crankshaft acceleration sensing** to detect and compensate for cylinder-to-cylinder fuel delivery variations in real-time. This is more sophisticated than simple bench calibration codes (IQA/IMA) used in later systems.

---

## Cylinder Balance Diagnostics (CBD) Module

The CBD module is the core adaptive fuel trim system. It uses **FFT (Fast Fourier Transform)** analysis of crankshaft speed variations to detect which cylinders are producing more or less power.

### How It Works

1. **Crankshaft Speed Analysis**: The ECU measures time between crank sensor teeth
2. **Acceleration Calculation**: Per-cylinder acceleration buffers track instantaneous speed changes
3. **FFT Processing**: Frequency analysis extracts per-cylinder contribution
4. **Trim Calculation**: Error generates fuel trim corrections
5. **EEPROM Storage**: Trims are saved at power-down and restored at startup

### CBD Configuration Parameters

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `CBD_Enable` | 0x0181AE14 | - | Master enable for cylinder balancing |
| `CBD_Compensation_Enable` | 0x0181AF10 | - | Enable compensation output |
| `CBD_Cylinders` | 0x0181AE3E | - | Number of cylinders (6) |
| `CBD_Start_Tooth` | 0x0181AE30 | - | Crank tooth to start measurement |

### Operating Conditions

CBD only operates under specific conditions:

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CBD_Coolant_Temp_Threshold` | 0x0181AE32 | Min coolant temp (disabled when cold) |
| `CBD_Intake_Air_Temp_Threshold` | 0x0181AE34 | Min intake air temp |
| `CBD_Lower_Speed_Limit` | 0x0181AE06 | Min RPM for operation |
| `CBD_Upper_Speed_Limit` | 0x0181AE04 | Max RPM for operation |
| `CBD_Vehicle_Speed_Threshold` | 0x0181AE38 | Max vehicle speed (disabled at highway) |
| `CBD_Motoring_Fuel_Threshold` | 0x0181AE12 | Min fueling (disabled during decel) |

### Per-Cylinder Fuel Trims

The system maintains individual fuel trims for each cylinder:

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `CBD_Delta_Fueling_Trim_1` | 0x0181AF00 | MM3S | Cylinder 1 trim, saved at power-down |
| `CBD_Delta_Fueling_Trim_2` | 0x0181AF02 | MM3S | Cylinder 2 trim, saved at power-down |
| `CBD_Delta_Fueling_Trim_3` | 0x0181AF04 | MM3S | Cylinder 3 trim, saved at power-down |
| `CBD_Delta_Fueling_Trim_4` | 0x0181AF06 | MM3S | Cylinder 4 trim, saved at power-down |
| `CBD_Delta_Fueling_Trim_5` | 0x0181AF08 | MM3S | Cylinder 5 trim, saved at power-down |
| `CBD_Delta_Fueling_Trim_6` | 0x0181AF0A | MM3S | Cylinder 6 trim, saved at power-down |
| `CBD_Delta_Fueling_Trim_7` | 0x0181AF0C | MM3S | Spare (8-cylinder support) |
| `CBD_Delta_Fueling_Trim_8` | 0x0181AF0E | MM3S | Spare (8-cylinder support) |

**Scale Factor**: 0.0679 mm³/stroke per raw count

### Trim Limits

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CBD_Fueling_Trim_Maximum` | 0x0181AE0C | Max positive trim allowed |
| `CBD_Fueling_Trim_Minimum` | 0x0181AE0E | Max negative trim allowed |
| `CBD_Trim_Gain` | 0x0181AE10 | Learning rate (fueling increment) |
| `CBD_Error_Filter_Constant` | 0x0181AE0A | Filter constant for error calculation |

### Reset Behavior

| Parameter | Address | Values |
|-----------|---------|--------|
| `CBD_Limit_Option_Flag` | 0x0181AE15 | 0=None, 1=Reset to last powerdown, 2=Reset to 0 |
| `CBD_Dynamics_Compensation_Reset` | 0x0181AE31 | Reset dynamics compensation |

### FFT Processing

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CBD_FFT_Filter_Coeff` | 0x0181AE08 | FFT filter constant |
| `CBD_FFT_Threshold` | 0x0181AE3C | Threshold for FFT detection |
| `CBD_FFT_Real_Comp_1` | 0x0181B002 | FFT real component |
| `CBD_FFT_Imag_Comp_1` | 0x0181B004 | FFT imaginary component |

### Acceleration Buffers

Raw acceleration data per cylinder:

| Parameter | Address |
|-----------|---------|
| `CBD_Accel_Buffer_1` | 0x0181B012 |
| `CBD_Accel_Buffer_2` | 0x0181B014 |
| `CBD_Accel_Buffer_3` | 0x0181B016 |
| `CBD_Accel_Buffer_4` | 0x0181B018 |
| `CBD_Accel_Buffer_5` | 0x0181B01A |
| `CBD_Accel_Buffer_6` | 0x0181B01C |

### Crank Sensor Tooth Error Compensation

The CBD also compensates for crank wheel manufacturing variations:

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CBD_Comp_Ref_RPM` | 0x0181AE40 | Reference RPM for tooth error compensation |
| `CBD_Max_Dynamic_Corr` | 0x0181AE42 | Maximum tooth error correction |
| `CBD_Min_Dynamic_Corr` | 0x0181AE44 | Minimum tooth error correction |

---

## Injector Current Sensing

The ECU monitors injector solenoid current for diagnostics:

### Current Monitoring

| Parameter | Address | Description |
|-----------|---------|-------------|
| `Bank_1_Injector_Current_Map` | 0x01151F70 | Hardware channel mapping |
| `Bank_2_Injector_Current_Map` | 0x01151F72 | Hardware channel mapping |
| `HPCR_ISOLLA_Current` | 0x01804116 | Pull-in current level (Amps) |
| `HPCR_ISOLLH_Current` | 0x01804114 | Hold current level (Amps) |

### Fast Decay Detection

Detects injector circuit faults:

| Parameter | Address | Description |
|-----------|---------|-------------|
| `HPCR_Fast_Decay` | 0x0180B900 | Bitmap - LSB is injector 1 |
| `HPCR_Fast_Decay_Debounce_Counts` | 0x018A8800 | Consecutive errors before fault |

### Injector Shutdown Protection

| Parameter | Address | Description |
|-----------|---------|-------------|
| `HPCR_Bank_Retest_Count` | 0x0181C900 | Cam revs to disable bank after fault |
| `HPCR_Injector_Shutdown_Threshold` | 0x0181C905 | Shutdowns before permanent disable |

---

## Rail Pressure Feedback (CUSUM)

The ECU monitors fuel rail pressure deviation using cumulative sum (CUSUM) analysis:

### Pressure Deviation Tracking

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `HPCR_Cusum_Delta` | 0x01162708 | MPa | Current deviation from setpoint |
| `HPCR_Cusum_Pos` | 0x01162700 | MPa | Accumulated positive deviation |
| `HPCR_Cusum_Neg` | 0x01162704 | MPa | Accumulated negative deviation |

### Fault Thresholds

| Parameter | Address | Description |
|-----------|---------|-------------|
| `HPCR_Cusum_Pos_Threshold` | 0x01162600 | Threshold for positive deviation fault |
| `HPCR_Cusum_Neg_Threshold` | 0x01162604 | Threshold for negative deviation fault |

### Leak Detection

| Parameter | Address | Description |
|-----------|---------|-------------|
| `HPCR_Cusum_Leak_Delta` | 0x0118F004 | Deviation for leak detection |
| `HPCR_Cusum_Leak_Pos` | 0x0118F000 | Accumulated positive deviation for leaks |

---

## Other Learned Parameters

The ECU saves various learned values at power-down:

| Parameter | Address | Description |
|-----------|---------|-------------|
| `AC_Pressure_Learned` | 0x018B3800 | A/C pressure sensor baseline |
| `Cruise_AD_Learned` | 0x018B0D00 | Cruise control A/D baseline |
| `EB_Learned` | 0x018B5A00 | Exhaust brake learned |
| `Cruise_Saved_Set_Speed_On_Poweroff` | 0x01119100 | Last cruise set speed |

---

## What's NOT Present: IQA/IMA Codes

The 2004 CM848 does **NOT** appear to use injector-specific bench calibration codes (IQA = Injector Quantity Adjustment, IMA = Injector Metering Adjustment) that are found in later Cummins systems.

Instead, the CBD system provides **real-time adaptive compensation** that:
- Does not require programming individual injector codes
- Automatically adapts to injector wear over time
- Compensates for engine-specific variations (compression, timing, etc.)

This suggests the HPCR injectors of this era were more consistent than later piezo injectors that require individual calibration codes.

---

## Calculation Flow

```
Crankshaft Speed Sensor
         │
         ▼
┌─────────────────────────────────┐
│  Tooth-to-Tooth Timing          │
│  (Acceleration Calculation)     │
└─────────────────────────────────┘
         │
         ▼
┌─────────────────────────────────┐
│  CBD Acceleration Buffers       │
│  (Per-cylinder data)            │
└─────────────────────────────────┘
         │
         ▼
┌─────────────────────────────────┐
│  FFT Analysis                   │
│  (Extract cylinder harmonics)   │
└─────────────────────────────────┘
         │
         ▼
┌─────────────────────────────────┐
│  Error Calculation              │
│  (Compare to reference pattern) │
└─────────────────────────────────┘
         │
         ▼
┌─────────────────────────────────┐
│  CBD_Delta_Fueling_Trim_N       │
│  (Per-cylinder correction)      │
└─────────────────────────────────┘
         │
         ▼
┌─────────────────────────────────┐
│  Cylinder_Fueling @ 0x01819200  │
│  (Final per-cylinder fuel qty)  │
└─────────────────────────────────┘
```

---

## Firmware Functions

### CBD Calculation Pipeline

The CBD calculations run in periodic task groups. Based on firmware analysis:

**Scheduler Entry Points:**

| Function | Address | Task Group | Purpose |
|----------|---------|------------|---------|
| `periodicTaskGroup5_diagnostics` | 0x0000bb40 | 5 | Sensor diagnostics |
| `periodicTaskGroup10_monitoring` | 0x0000bc08 | 10 | Sensor monitoring |
| `periodicTaskGroup19_diagnostics` | 0x0000bfb0 | 19 | Protection diagnostics |

**Sensor/Acceleration Processing:**

| Function | Address | Purpose |
|----------|---------|---------|
| `sensorMonitoringMainLoop` | 0x00019b20 | Main sensor monitoring entry |
| `processSensorMonitoringLogic` | 0x000191e8 | Monitoring state machine |
| `updateSensorDiagnosticFlags` | 0x000191a0 | Update fault flags |
| `calculateSensorDiagnosticValue` | 0x00018f8c | Diagnostic metric calculation |
| `updateSensorDiagnostics` | 0x00006b24 | Update sensor state |

**Fuel Trim Application:**

| Function | Address | Purpose |
|----------|---------|---------|
| `calculateFuelTrimOutput` | 0x0000e518 | Final fuel trim calculation |
| `calculateFuelTrimValues` | 0x0000ff04 | Compute trim values |
| `temperatureBasedFuelTrim` | 0x0000e78c | Temperature corrections |
| `calculateLoadBasedFuelTrim` | 0x0001242c | Load-based corrections |
| `calculateRpmBasedFuelTrim` | 0x000125f4 | RPM-based corrections |
| `selectFuelTrimMode` | 0x000127bc | Mode selection |

**Crank Sensor Processing:**

| Function | Address | Purpose |
|----------|---------|---------|
| `initEngineCrankSequence` | 0x00044cc8 | Initialize crank sensor |
| `updateEngineCrankState` | 0x000457d0 | Update crank state |
| `processEngineRpmDerivative` | 0x00038760 | RPM derivative (acceleration) |
| `processEnginePositionDiagnostics` | 0x00049264 | Position diagnostics |

**EEPROM Functions (Save Learned Values):**

| Function | Address | Purpose |
|----------|---------|---------|
| `eepromWriteWords` | 0x00000bec | Write learned trims |
| `eepromValidationCycle` | 0x00002310 | Validate EEPROM data |
| `eepromProgressNotify` | 0x000003ec | Progress notification |

### FFT Complex Number Processing

The CBD uses complex number arithmetic (Real/Imaginary components) for FFT-like harmonic analysis:

**FFT Reference Parameters (Pre-programmed calibration):**

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CBD_Reference_1_Cylinder_1_Real` | 0x0181AE16 | Cyl 1 reference (real) |
| `CBD_Reference_1_Cylinder_1_Imag` | 0x0181AE18 | Cyl 1 reference (imag) |
| `CBD_Reference_1_Cylinder_3_Real` | 0x0181AE1E | Cyl 3 reference (real) |
| `CBD_Reference_1_Cylinder_3_Imag` | 0x0181AE20 | Cyl 3 reference (imag) |
| `CBD_Reference_1_Cylinder_5_Real` | 0x0181AE1A | Cyl 5 reference (real) |
| `CBD_Reference_1_Cylinder_5_Imag` | 0x0181AE1C | Cyl 5 reference (imag) |

**Note:** References are for cylinders 1, 3, 5 (one bank). The even cylinders (2, 4, 6) use Reference_2 set.

**Calculated FFT Components:**

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CBD_FFT_Real_Comp_1` | 0x0181B002 | Calculated real component |
| `CBD_FFT_Imag_Comp_1` | 0x0181B004 | Calculated imaginary component |
| `CBD_Adjusted_Real_Comp_2` | 0x0181B006 | Adjusted real (after compensation) |
| `CBD_Adjusted_Imag_Comp_2` | 0x0181B008 | Adjusted imaginary |

**Dynamic Compensation:**

| Parameter | Address | Description |
|-----------|---------|-------------|
| `Real_Dynamic_Compensation` | 0x0181AF12 | Dynamic crank error (real) |
| `Imag_Dynamic_Compensation` | 0x0181AF14 | Dynamic crank error (imag) |

### CBD Core Algorithm Functions (Bank 1)

The CBD FFT-like algorithm is implemented in Bank 1 ROM:

| Function | Address | Purpose |
|----------|---------|---------|
| `cbdFillAccelerationBuffers` | 0x00042bd0 | Fills per-cylinder acceleration buffers from crank timing |
| `cbdCalculateCylinderTrims` | 0x00042d78 | Main DFT/FFT algorithm - calculates per-cylinder trims |
| `cbdInitFilterState` | 0x00043a5c | Initializes CBD filter state |
| `processLoadThrottle` | 0x00042cfc | Throttle/load filtering for CBD enable |

**Algorithm Details (cbdCalculateCylinderTrims @ 0x00042d78):**

1. **DFT Decomposition** - Uses sum/difference patterns to extract harmonics:
   - First harmonic: `((accel_1 + accel_4) - accel_2) - accel_3`
   - Imaginary component scaled by twiddle factor 0x377 (887 decimal)

2. **Complex Multiply** - Per-cylinder DFT outputs:
   ```
   local_48[0] = (DAT_00408ef8 * real + DAT_00408efa * imag) >> 13
   local_48[3] = -local_48[0]  // Opposite cylinder
   ```

3. **DFT Coefficient Tables** (ROM):
   - 0x57bde - 6-cylinder DFT matrix 1
   - 0x57c5e - 6-cylinder DFT matrix 2
   - 0x57cde - Reference matrix
   - 0x57cfe - 4-cylinder DFT matrix

4. **Per-Cylinder Trim Accumulation**:
   ```
   DAT_003fee82[i] = DAT_003fee82[i] + cylinder_trim_adjustment[i]
   ```

### CBD RAM Variables

Intermediate calculation values in RAM:

| Variable | Address | Description |
|----------|---------|-------------|
| `cbd_accel_buffer_1..6` | 0x0040b74c-0x0040b756 | Per-cylinder acceleration data |
| `cbd_fft_real_filtered` | 0x0040b73c | Filtered FFT real component |
| `cbd_fft_imag_filtered` | 0x0040b73e | Filtered FFT imaginary component |
| `cbd_harmonic_real` | 0x0040b740 | Harmonic real output |
| `cbd_harmonic_imag` | 0x0040b742 | Harmonic imaginary output |
| `cbd_dc_offset` | 0x0040b744 | DC offset component |
| `cbd_cylinder_trim_accum` | 0x003fee82 | Per-cylinder trim accumulator array |
| `cbd_dynamic_comp_real` | 0x003fee94 | Dynamic compensation (real) |
| `cbd_dynamic_comp_imag` | 0x003fee96 | Dynamic compensation (imag) |
| `timing_filter_state` | 0x0040b73a | CBD filter state machine |

### CBD Calibration Coefficients

| Coefficient | Address | Purpose |
|-------------|---------|---------|
| `cbd_twiddle_1` | 0x00408ef8 | DFT coefficient for cyl 1 real |
| `cbd_twiddle_2` | 0x00408efa | DFT coefficient for cyl 1 imag |
| `cbd_twiddle_3` | 0x00408efc | DFT coefficient for cyl 2 real |
| `cbd_twiddle_4` | 0x00408efe | DFT coefficient for cyl 2 imag |
| `cbd_trim_max` | 0x00408eee | Maximum trim limit |
| `cbd_trim_min` | 0x00408ef0 | Minimum trim limit |
| `cbd_threshold` | 0x00408ef2 | FFT magnitude threshold |
| `cbd_filter_coef` | 0x00408eec | Filter coefficient |
| `cbd_enable_flag` | 0x00408ef6 | CBD master enable |

### Bank 2 Utility Functions

| Function | Address | Purpose |
|----------|---------|---------|
| `updateEngineLoadPercentage` | 0x00523148 | Engine load calculation |
| `checkFuelDemandEnableConditions` | 0x0050370c | Fuel enable logic |

### Stop Compensation Tables

Special handling during engine shutdown:

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CBD_Stop_Compensation_Flag` | 0x0181B00C | Stop compensation active |
| `CBD_Stop_Compensation_Speed_Vector` | 0x0181B100 | Speed breakpoints |
| `CBD_Stop_Compensation_Fueling_Vector` | 0x0181B200 | Fueling breakpoints |
| `CBD_Stop_Compensation_Table` | 0x0181B300 | 2D compensation table |

---

## Diagnostic Applications

### Reading CBD Trims

To read current cylinder balance trims:
1. Read `CBD_Delta_Fueling_Trim_1` through `_6`
2. Scale by 0.0679 mm³/stroke
3. Positive = more fuel, Negative = less fuel

### Interpreting Results

| Trim Value | Meaning |
|------------|---------|
| ~0 mm³ | Cylinder balanced |
| +3 mm³ | Adding fuel (weak cylinder) |
| -3 mm³ | Removing fuel (strong cylinder) |
| At limits | Possible injector or mechanical issue |

### Cylinder Cutout Test

The system supports cylinder cutout testing:
- `CBD_Cutout_Disable_Time` - Delay before CBD resumes after cutout
- Service tool can cut individual cylinders to verify contribution

---

## Related Documentation

- [Tuning Parameters](tuning_parameters.md) - Engine geometry configuration
- [Fuel Injection Analysis](../output/fuel_injection_analysis.md) - Injection timing/quantity
- [Fuel Rail Pressure Control](../output/fuel_rail_pressure_control.md) - HPCR system
