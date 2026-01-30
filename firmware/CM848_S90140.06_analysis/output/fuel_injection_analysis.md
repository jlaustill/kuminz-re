# CM848 HPCR Fuel Injection System Analysis

## Overview

The CM848 ECU controls a High Pressure Common Rail (HPCR) diesel injection system for the 5.9L Cummins engine. This document details the fuel injection architecture, data flow, and key parameters.

## System Architecture

### Injection Events per Cycle

The HPCR system supports multiple injection events:

1. **Pilot Injection** - Small pre-injection (~15% of main) for:
   - Reduced combustion noise
   - Lower NOx emissions
   - Smoother pressure rise

2. **Main Injection** - Primary fuel delivery

3. **Auxiliary Injection** (optional) - Post-injection for:
   - DPF regeneration (future applications)
   - Emissions control

### Hardware Interface

The MPC555 MIOS (Modular I/O Subsystem) controls injector timing:

| Register Range | Purpose |
|---------------|---------|
| 0x306000-0x3060FF | MIOS MPWM - Pulse Width Modulation |
| 0x306100-0x3061FF | MIOS MDASM - Dual Action Submodule (timing) |
| 0x002FC024-0x002FC028 | USIU Timer registers |

Key functions:
- `injectorTimingCalculation()` @ 0x000529b8 - Controls injector timing via MIOS
- `injectorPulseWidthCalc()` @ 0x000533e0 - Controls pulse width

### Injector Control Variables

| Address | Name | Purpose |
|---------|------|---------|
| 0x0040c117 | `injector_enable_ch0_7` | Enable bits for injectors 0-7 |
| 0x0040c118 | `injector_enable_ch8_15` | Enable bits for injectors 8-15 |
| 0x0040c11a | `injector_timing_mode` | Timing mode selector |
| 0x0040c11b | `injector_output_ch0` | Output state channel 0 |
| 0x0040c11c | `injector_fault_flags` | Injector fault detection |
| 0x0040c11d | `injector_output_ch1` | Output state channel 1 |

## Software Data Flow

### Fuel Quantity Calculation

```
Throttle Position / Speed Governor
           │
           ▼
┌──────────────────────────────────────────┐
│    fuelDemandCoordinator() @ 0x17980     │
│    ├─ fuelDemandModeSelector()           │
│    ├─ fuelDemandEnableChecker()          │
│    ├─ fuelDemandRateLimiterStateMachine()│
│    └─ fuelDemandSmoothingController()    │
└──────────────────────────────────────────┘
           │
           ▼
┌──────────────────────────────────────────┐
│  fuelDemandFinalCalculation() @ 0x1782c  │
│  Output: fuel_demand_calculated          │
└──────────────────────────────────────────┘
           │
           ▼
┌──────────────────────────────────────────┐
│         FUEL LIMITING                    │
│  ├─ AFC_Fueling (boost/RPM limits)       │
│  ├─ Altitude_Derate_Fueling              │
│  ├─ Thermal_Fuel_Limit                   │
│  └─ Protection_Fuel_Limit                │
└──────────────────────────────────────────┘
           │
           ▼
      Final_Fueling (FSFNFL)
      Units: MM3S (mm³/stroke)
```

### Key Fuel Demand Variables

| Address | Name | Description |
|---------|------|-------------|
| 0x003fa6cc | `fuel_demand_rpm_table_ptr` | Pointer to RPM lookup table |
| 0x003fa6e8 | `fuel_demand_limited` | After limits applied |
| 0x003fa6ea | `fuel_demand_lower_boundary` | Minimum allowed |
| 0x003fa6ec | `fuel_demand_upper_boundary` | Maximum allowed |
| 0x003fa6ee | `fuel_demand_target` | Target value |
| 0x0040a57a | `fuel_demand_calculated` | Final output |
| 0x0040a57c | `fuel_demand_mode` | Mode selector |
| 0x0040a57e | `fuel_demand_enable_flag` | System enable |
| 0x0040a580 | `fuel_rate_limiter_state` | Rate limiter state |
| 0x0040a584 | `fuel_demand_throttle_based` | Throttle contribution |
| 0x0040a586 | `fuel_demand_override_value` | Diagnostic override |
| 0x0040a588 | `fuel_demand_override_active` | Override flag |
| 0x0040a58a | `fuel_demand_rate_limited` | After rate limiting |

### Injection Timing Calculation

```
┌──────────────────────────────────────────┐
│ calculateFuelInjectionTiming() @ 0x16a90 │
│ Inputs:                                  │
│  - fuel_demand_calculated                │
│  - boost_pressure                        │
│  - engine_rpm                            │
│  - manifold_pressure                     │
└──────────────────────────────────────────┘
           │
           ▼
┌──────────────────────────────────────────┐
│ Timing Corrections Applied:              │
│  - Air temp correction                   │
│  - Coolant temp correction               │
│  - Ambient pressure correction           │
│  - Boost pressure correction             │
└──────────────────────────────────────────┘
           │
           ▼
      Final_Timing (TVC)
      Units: Degrees BTDC
```

## E2M Parameters

### Final Output Parameters

| Parameter | Code | Address | Units | Scale |
|-----------|------|---------|-------|-------|
| Final_Fueling | FSFNFL | 0x01105100 | MM3S | 0.0679 |
| Final_Timing | TVC | 0x01105B02 | deg BTDC | 0.117 |
| Pilot_SOI | - | 0x01806C00 | deg BTDC | 0.117 |
| Pilot_Fuel_Quantity | - | 0x01806A02 | MM3S | 0.0679 |
| Pilot_Fueling | - | 0x01120C0C | MM3S | 0.0679 |

### AFC Fueling Limits

| Parameter | Code | Address | Description |
|-----------|------|---------|-------------|
| AFC_Fueling | AFFL | 0x01104C00 | Calculated limit |
| AFC_Fueling_Table | AFFLLMZA | 0x01104F00 | 2D table (boost x RPM) |
| AFC_Low_Boost_Fueling | - | 0x01104C02 | Low boost limit |

### Pilot Injection Tables

| Parameter | Address | Description |
|-----------|---------|-------------|
| Pilot_Quantity_Base_Speed_Axis | 0x01806000 | RPM axis |
| Pilot_Quantity_Base_Fueling_Axis | 0x01806100 | Fueling axis |
| Pilot_Quantity_Base_Pilot_Axis | 0x01806200 | Output axis |
| Max_Pilot_Fuel | 0x01806A14 | Ratio limit |
| HPCR_Pilot_To_Main_Ratio_Limit | 0x01805F1C | Max pilot/main ratio |

### Main SOI Corrections

| Parameter | Address | Description |
|-----------|---------|-------------|
| Main_SOI_Cool_Correction | 0x0180860C | Coolant temp adjust |
| Main_SOI_Air_Temp_Correction | 0x01808606 | Intake air adjust |
| Main_SOI_Air_Press_Correction | 0x01808600 | Ambient pressure adjust |
| Main_SOI_Boost_Correction | 0x0180861A | Boost pressure adjust |
| Main_SOI_Selection_Switch | 0x01808500 | Timing mode selector |

## Scheduler Integration

The fuel injection system runs in two periodic task groups:

### periodicTaskGroup0_fuelFinal (High Priority)
Runs every 4th phase (phases 0, 4, 8, 12, 16, 20, 24, 28, 32, 36)

Contains:
- `injectorPulseWidthCalc()` - Hardware register updates
- `fuelDemandFinalCalculation()` - Final fuel quantity
- `calculateFuelDemandLimitOutput()` - Limit processing
- `sensorChannel3_boostPressureInit()` - MAP sensor processing

### periodicTaskGroup35_fuelDemand (Lower Priority)
Runs on phases 10 and 30

Contains:
- `fuelDemandCoordinator()` - Mode selection and coordination

## Unit Conversions

### Fuel Quantity (MM3S)
- Raw value × 0.06793478 = mm³/stroke
- Typical idle: ~15 mm³/stroke (raw ~220)
- Typical full load: ~150 mm³/stroke (raw ~2200)

### Injection Timing (CRANK_DEG_BTDC)
- Raw value × 0.1171875 = degrees BTDC
- Typical main SOI: 5-15° BTDC
- Typical pilot SOI: 20-40° BTDC

### Pressure (IN_HG)
- Raw value × 0.0159 = inches of mercury
- 1 bar ≈ 29.53 in-Hg
- 10-bar MAP range: 0-295 in-Hg (raw 0-18570)

## Safety Features

### Fuel Cut Conditions
- Engine overspeed protection
- Coolant over-temperature
- Fuel pressure fault
- Sensor failures

### Protection Variables

| Address | Name | Description |
|---------|------|-------------|
| 0x0040a6f0 | `fuel_demand_fault_flag` | Fault condition active |
| 0x003fdd5a | `fuel_demand_enable_threshold` | Enable threshold |
| 0x003fe9d8 | `fuel_demand_fault_conditions` | Fault bitmap |
| 0x00407838 | `protection_fuel_threshold_min` | Minimum protection |
| 0x0040b6e4 | `protection_fuel_rate_limit` | Rate limit protection |

## Related Functions

### Fuel Demand Calculation Chain
1. `throttleBasedFuelCalculation()` @ 0x000128a0
2. `boostBasedFuelModifier()` @ 0x00012ad4
3. `loadBasedFuelAdjustment()` @ 0x00012cf4
4. `fuelDemandWithLoadCompensation()` @ 0x00012dc4
5. `calculateFuelDemandMode1/2/3()` @ 0x00014610/0x000149a4/0x000150b0
6. `fuelDemandFinalCalculation()` @ 0x0001782c

### Timing Calculation Chain
1. `calculateFuelInjectionTiming()` @ 0x00016a90
2. `calculateFuelTimingBlend()` @ 0x0000fcd0
3. `calculateFuelTimingTarget()` @ 0x0000fe5c
4. `fuelTimingCompensation()` @ 0x0000e8f0
5. `fuelTimingOilPressureModeController()` @ 0x0000ea00
