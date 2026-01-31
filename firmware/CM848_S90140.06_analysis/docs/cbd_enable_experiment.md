# CBD Enable Experiment Guide

This document outlines the minimum parameters needed to enable the Cylinder Balance Diagnostics (CBD) adaptive fuel trim system on CM848 ECUs. **This is experimental - CBD has been factory-disabled in all Chrysler calibrations.**

## ⚠️ WARNING

- CBD was disabled by Cummins for a reason (unknown - possibly untested on Chrysler application)
- Incorrect calibration could cause rough running, misfires, or engine damage
- Always have a way to restore your original calibration
- Test on a bench engine or dyno first if possible
- Monitor closely during initial testing

---

## Address Translation: Calterm to Actual RAM

The e2m addresses shown in Calterm (0x0181AExx) are virtual addresses. They translate to actual CM848 RAM addresses using:

```
Actual_Address = Base[Column3] + Column4
```

For CBD parameters (Column3 = 81AE):
- **Base[81AE] = 0x00408ee2** (CM848-specific)
- Example: CBD_Enable @ 0x0181AE14 → 0x00408ee2 + 0x14 = **0x00408ef6**

### CBD Parameter Address Map

| Parameter | Calterm Address | Actual RAM | Verified |
|-----------|-----------------|------------|----------|
| `CBD_Fueling_Filter_Constant` | 0x0181AE00 | 0x00408ee2 | ✓ |
| `CBD_Delta_Speed_Threshold` | 0x0181AE02 | 0x00408ee4 | ✓ |
| `CBD_Upper_Speed_Limit` | 0x0181AE04 | 0x00408ee6 | ✓ |
| `CBD_Lower_Speed_Limit` | 0x0181AE06 | 0x00408ee8 | ✓ |
| `CBD_FFT_Filter_Coeff` | 0x0181AE08 | 0x00408eea | ✓ |
| `CBD_Error_Filter_Constant` | 0x0181AE0A | 0x00408eec | ✓ |
| `CBD_Fueling_Trim_Maximum` | 0x0181AE0C | 0x00408eee | ✓ |
| `CBD_Fueling_Trim_Minimum` | 0x0181AE0E | 0x00408ef0 | ✓ |
| `CBD_FFT_Threshold` | 0x0181AE10 | 0x00408ef2 | ✓ |
| `CBD_Motoring_Fuel_Threshold` | 0x0181AE12 | 0x00408ef4 | ✓ |
| **`CBD_Enable`** | 0x0181AE14 | **0x00408ef6** | ✓ |
| `CBD_Limit_Option_Flag` | 0x0181AE15 | 0x00408ef7 | ✓ |

### Live ECU Finding

**Surprising discovery:** The RAM dump from a live CM848 ECU shows:
- `cbd_enable_flag` (0x00408ef6) = **0x01 (ENABLED!)**
- Someone has already enabled CBD on this specific ECU

Values from live ECU RAM:
- Upper RPM limit: 2000 RPM (raw: 0x3e80)
- Lower RPM limit: 650 RPM (raw: 0x1450)
- Trim limits: ±59 raw (±4 mm³)

This confirms CBD **CAN be enabled** and the ECU will use it.

---

## Quick Reference: Minimum Enable Parameters

| Parameter | Calterm Address | RAM Address | Factory Value | Enable Value | Description |
|-----------|-----------------|-------------|---------------|--------------|-------------|
| `CBD_Enable` | 0x0181AE14 | 0x00408ef6 | 0 | **1** | Master enable |
| `CBD_Compensation_Enable` | 0x0181AF10 | TBD | 0 | **1** | Apply trims to fueling |

These two parameters are the absolute minimum to turn CBD on. However, the system needs properly calibrated thresholds and gains to function correctly.

---

## Operating Condition Thresholds

These parameters define WHEN CBD operates. Conservative values are suggested:

| Parameter | Address | Scale | Suggested | Description |
|-----------|---------|-------|-----------|-------------|
| `CBD_Lower_Speed_Limit` | 0x0181AE06 | 0.125 RPM | 800 RPM (raw: 6400) | Min RPM for CBD |
| `CBD_Upper_Speed_Limit` | 0x0181AE04 | 0.125 RPM | 2000 RPM (raw: 16000) | Max RPM for CBD |
| `CBD_Coolant_Temp_Threshold` | 0x0181AE32 | 0.015625 °F | 160°F (raw: 10240) | Min coolant temp |
| `CBD_Intake_Air_Temp_Threshold` | 0x0181AE34 | 0.015625 °F | 40°F (raw: 2560) | Min intake temp |
| `CBD_Vehicle_Speed_Threshold` | 0x0181AE38 | 0.00390625 MPH | 60 MPH (raw: 15360) | Max vehicle speed |
| `CBD_Motoring_Fuel_Threshold` | 0x0181AE12 | 0.0679348 mm³ | 10 mm³ (raw: 147) | Min fueling (above decel) |
| `CBD_Cutout_Disable_Time` | 0x0181AE36 | 0.2 sec | 5 sec (raw: 25) | Delay after cylinder cutout |

**Rationale:**
- CBD works best at steady-state idle/cruise, not during transients
- Warmup required for consistent combustion
- Disabled at highway speeds where road noise masks signal
- Disabled during deceleration (no fuel = no acceleration signal)

---

## Filter and Gain Parameters

These control HOW FAST CBD learns and HOW MUCH it corrects:

| Parameter | Address | Scale | Conservative Start | Description |
|-----------|---------|-------|-------------------|-------------|
| `CBD_FFT_Filter_Coeff` | 0x0181AE08 | 0.0001220703125 | 0.1 (raw: 819) | FFT smoothing (higher = slower) |
| `CBD_Error_Filter_Constant` | 0x0181AE00 | 0.00012207 | 0.1 (raw: 819) | Error smoothing |
| `CBD_Fueling_Filter_Constant` | 0x0181AE02 | 0.0001220703125 | 0.1 (raw: 819) | Fuel demand smoothing |
| `CBD_Trim_Gain` | 0x0181AE10 | 0.067934784 mm³ | 0.5 mm³ (raw: 7) | Learning rate per cycle |
| `CBD_FFT_Threshold` | 0x0181AE3C | 1 | 100 | Min FFT magnitude to act |

**Rationale:**
- Start with slow learning (high filter constants) to avoid oscillation
- Small trim gain = gradual adaptation
- Threshold prevents acting on noise

---

## Trim Limits (Safety Bounds)

| Parameter | Address | Scale | Suggested | Description |
|-----------|---------|-------|-----------|-------------|
| `CBD_Fueling_Trim_Maximum` | 0x0181AE0C | 0.067934784 mm³ | +5 mm³ (raw: 74) | Max positive trim |
| `CBD_Fueling_Trim_Minimum` | 0x0181AE0E | 0.067934784 mm³ | -5 mm³ (raw: -74) | Max negative trim |
| `CBD_Limit_Option_Flag` | 0x0181AE15 | - | 1 | 0=None, 1=Reset to powerdown, 2=Reset to 0 |

**Rationale:**
- ±5 mm³ is conservative (~7% of typical idle fueling)
- Limit option 1 preserves learned values across restarts

---

## Engine Configuration

| Parameter | Address | Value | Description |
|-----------|---------|-------|-------------|
| `CBD_Cylinders` | 0x0181AE3E | 6 | Number of cylinders |
| `CBD_Start_Tooth` | 0x0181AE30 | TBD | Crank tooth to start measurement |
| `CBD_Comp_Ref_RPM` | 0x0181AE40 | 1000 RPM (raw: 8000) | Normalization speed for tooth error |

**Note:** `CBD_Start_Tooth` aligns measurement with cylinder firing order. The 5.9L ISB firing order is 1-5-3-6-2-4. This may need adjustment based on crank sensor location.

---

## DFT Reference Coefficients

These define the expected FFT signature of each cylinder. **Factory values may be for ISB truck, not Chrysler:**

| Parameter | Address | Scale | Description |
|-----------|---------|-------|-------------|
| `CBD_Reference_1_Cylinder_1_Real` | 0x0181AE16 | 0.00012207 | Cyl 1 reference (real) |
| `CBD_Reference_1_Cylinder_1_Imag` | 0x0181AE18 | 0.00012207 | Cyl 1 reference (imag) |
| `CBD_Reference_1_Cylinder_3_Real` | 0x0181AE1E | 0.00012207 | Cyl 3 reference (real) |
| `CBD_Reference_1_Cylinder_3_Imag` | 0x0181AE20 | 0.00012207 | Cyl 3 reference (imag) |
| `CBD_Reference_1_Cylinder_5_Real` | 0x0181AE1A | 0.00012207 | Cyl 5 reference (real) |
| `CBD_Reference_1_Cylinder_5_Imag` | 0x0181AE1C | 0.00012207 | Cyl 5 reference (imag) |
| `CBD_Reference_2_Cylinder_*` | 0x0181AE22-2E | 0.00012207 | Even cylinder bank references |
| `CBD_Reference_3` | 0x0181AE2E | 1 | Third harmonic reference |

**These are the HARDEST parameters to calibrate** - they define the expected crankshaft acceleration pattern for a balanced engine. Incorrect values will cause CBD to "correct" in the wrong direction.

**Initial approach:** Leave at factory defaults (from calibration pointer 0326) and monitor if system behaves sensibly.

---

## Dynamic Crank Tooth Compensation

Compensates for manufacturing variations in crank trigger wheel:

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CBD_Max_Dynamic_Corr` | 0x0181AE42 | Max tooth error compensation |
| `CBD_Min_Dynamic_Corr` | 0x0181AE44 | Min tooth error compensation |
| `CBD_Dynamics_Compensation_Reset` | 0x0181AE31 | Reset dynamics (0=disable, 1=enable) |

**Suggestion:** Enable dynamics compensation reset initially to learn crank wheel errors.

---

## Monitoring Parameters (Read-Only)

Watch these to verify CBD is working:

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CBD_Delta_Fueling_Trim_1-6` | 0x0181AF00-0A | Per-cylinder learned trims |
| `CBD_FFT_Real_Comp_1` | 0x0181B002 | FFT real component |
| `CBD_FFT_Imag_Comp_1` | 0x0181B004 | FFT imaginary component |
| `CBD_Accel_Buffer_1-6` | 0x0181B012-1C | Raw acceleration data |
| `CBD_Filtered_Fueling` | 0x0181B000 | Filtered fuel demand |
| `CBD_Results` | 0x0181B00C | Diagnostic results bitmap |
| `CBD_Trim_Limits_Exceeded` | 0x0181B00D | Trim limit flag |

---

## Suggested Test Procedure

### Phase 1: Verify Data Collection (CBD Learning Disabled)

1. Set `CBD_Enable = 1`
2. Keep `CBD_Compensation_Enable = 0` (learning only, no correction)
3. Run engine at steady idle (800 RPM, warmed up)
4. Monitor `CBD_Accel_Buffer_1-6` - should show non-zero values
5. Monitor `CBD_FFT_Real_Comp_1` and `CBD_FFT_Imag_Comp_1`
6. If buffers stay zero, CBD isn't seeing crank acceleration data

### Phase 2: Enable Learning with Conservative Limits

1. Set `CBD_Compensation_Enable = 1`
2. Use conservative trim limits (±3 mm³)
3. Use slow learning (high filter constants)
4. Run at steady idle for 10+ minutes
5. Monitor `CBD_Delta_Fueling_Trim_1-6` for movement
6. Trims should slowly converge (not oscillate wildly)

### Phase 3: Verify Correction Effect

1. With learned trims non-zero, observe idle quality
2. Compare idle roughness with CBD enabled vs disabled
3. If idle is WORSE with CBD, the reference coefficients may be wrong

### Phase 4: Expand Operating Range

1. Gradually increase RPM and load ranges
2. Monitor for any roughness or misfires
3. Adjust thresholds and gains as needed

---

## Troubleshooting

| Symptom | Possible Cause | Solution |
|---------|----------------|----------|
| Accel buffers always zero | Wrong start tooth, RPM out of range | Adjust `CBD_Start_Tooth`, verify RPM limits |
| Trims oscillate wildly | Gains too high, filters too fast | Reduce `CBD_Trim_Gain`, increase filter constants |
| Trims hit limits immediately | Reference coefficients wrong polarity | May need to invert reference signs |
| Idle rougher with CBD on | Incorrect reference pattern | Disable CBD, investigate references |
| No learning at all | Thresholds not met | Check temp, speed, load thresholds |

---

## Calterm Parameter Search Tips

In Calterm, search for:
- `CBD_` - All cylinder balance parameters
- `Cylinder Balance` - Description search
- Module `81AE`, `81AF`, `81B0` - Address ranges

---

## Summary: Minimum Changes to Enable

```
CBD_Enable                  = 1     (0x0181AE14)
CBD_Compensation_Enable     = 1     (0x0181AF10)
CBD_Lower_Speed_Limit       = 6400  (800 RPM)
CBD_Upper_Speed_Limit       = 16000 (2000 RPM)
CBD_Coolant_Temp_Threshold  = 10240 (160°F)
CBD_Fueling_Trim_Maximum    = 44    (+3 mm³)
CBD_Fueling_Trim_Minimum    = -44   (-3 mm³)
CBD_Trim_Gain               = 4     (0.27 mm³)
CBD_Cylinders               = 6
```

Everything else can start at factory defaults (from calibration pointer 0326).

---

## Related Documentation

- [Injector Feedback System](injector_feedback_system.md) - Complete CBD algorithm documentation
- [Tuning Parameters](tuning_parameters.md) - Engine geometry and fuel calculations
