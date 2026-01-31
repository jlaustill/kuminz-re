# CM848 Engine Tuning Parameters

This document catalogs calibration parameters related to engine configuration, fuel calculation, and injection control. These are the parameters a tuner would modify to adapt the ECU for engine swaps (e.g., 5.9L → 6.7L) or performance modifications.

## Engine Geometry Configuration (CHP Module)

The **CHP (Charge/HP)** module uses a physics-based model to calculate volumetric efficiency and air mass from engine geometry. These parameters define the engine's physical characteristics.

### Core Engine Dimensions

| Parameter | Address | Units | Scale | Description |
|-----------|---------|-------|-------|-------------|
| `C_CHP_Engine_Displacement` | 0x01177C08 | IN³ | 0.03125 | Total engine displacement in cubic inches |
| `C_CHP_Veff_Bore` | 0x01177C0A | IN | 0.000122 | Cylinder bore diameter |
| `C_CHP_Veff_Stroke` | 0x01177C06 | IN | 0.000122 | Piston stroke length |
| `C_CHP_Number_Of_Cylinders` | 0x01174F00 | - | 1 | Number of cylinders |
| `C_CHP_Veff_Valve_Diameter` | 0x01177C0C | IN | 0.000122 | Intake valve diameter |

### Example Values for Engine Swaps

| Engine | Displacement (L) | Displacement (IN³) | Raw Value | Bore (IN) | Stroke (IN) |
|--------|-----------------|-------------------|-----------|-----------|-------------|
| 5.9L ISB | 5.883 | 359.0 | 11,488 | 4.02 | 4.72 |
| 6.7L ISB | 6.690 | 408.2 | 13,062 | 4.21 | 4.88 |

**Conversion formulas:**
- Raw displacement = (cubic inches) / 0.03125
- Cubic inches = liters × 61.02

### Volumetric Efficiency (Veff) Configuration

The firmware calculates volumetric efficiency using two lookup tables and polynomial parameters:

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `C_CHP_Veff_Mach_Table` | 0x01178300 | - | 2D Veff table (piston speed based) |
| `C_CHP_Veff_Sqrt_Table` | 0x01196200 | - | Veff table based on energy/temperature |
| `C_CHP_Veff_Piston_Speed_Axis` | 0x01178200 | IN*RPM | X-axis for Mach table |
| `C_CHP_Veff_Tmptr_Axis` | 0x01196100 | DEG_R | Temperature axis for Sqrt table |
| `C_CHP_Veff_Parameter_A` | 0x01177C12 | - | Polynomial coefficient A |
| `C_CHP_Veff_Parameter_B` | 0x01177C14 | - | Polynomial coefficient B |
| `C_CHP_Veff_Parameter_C` | 0x01177C16 | - | Polynomial coefficient C |
| `C_CHP_Veff_Max` | 0x01177C0E | - | Maximum Veff limit |
| `C_CHP_Veff_Min` | 0x01177C10 | - | Minimum Veff limit |

### Calculated Veff Outputs

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CHP_Volumetric_Efficiency` | 0x01177D00 | Final calculated Veff |
| `CHP_Veff_Mach` | 0x01177D04 | Mach table output component |
| `CHP_Veff_Sqrt` | 0x01177D06 | Sqrt table output component |

---

## In-Cylinder Mass Calculations (CBP Module)

The **CBP (Cylinder Block Parameters)** module calculates mass quantities per cylinder per cycle. These depend on displacement and Veff.

### Air and Fuel Mass

| Parameter | Address | Units | Scale | Description |
|-----------|---------|-------|-------|-------------|
| `CBP_Air_Mass` | 0x01174E04 | MM3S | 0.1359 | Fresh air mass per cylinder |
| `CBP_Charge_Mass` | 0x01174E02 | MM3S | 0.1359 | Total charge mass (air + EGR) |
| `CBP_Fuel_Mass` | 0x01174E00 | MM3S | 0.5 | Fuel mass per injection |
| `CBP_EGR_Mass` | 0x01174E06 | MM3S | 0.1359 | EGR mass per cylinder |
| `CBP_Residual_Mass` | 0x01173402 | MM3S | 0.1359 | Residual exhaust mass |
| `CBP_Charge_Plus_Fuel_Mass` | 0x01174E08 | MM3S | 0.1359 | Total cylinder contents |

### Air-Fuel Ratio Calculations

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `CBP_Air_Fuel_Ratio` | 0x01177302 | - | Calculated A/F ratio |
| `CBP_Charge_Fuel_Ratio` | 0x01177300 | - | Total charge / fuel ratio |
| `CBP_Phi` | 0x01177304 | - | Equivalence ratio (actual/stoich) |
| `CBP_Intake_Charge_O2_Fraction` | 0x01177306 | - | Oxygen fraction in intake charge |

### Oxygen Tracking

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `CBP_O2_Mass_Air` | 0x01174E0A | MM3S | O2 mass in fresh air |
| `CBP_O2_Mass_Burnt` | 0x01174E10 | MM3S | O2 consumed in combustion |
| `CBP_O2_Mass_Exhaust` | 0x01174E0C | MM3S | O2 remaining in exhaust |
| `CBP_O2_Frac_Residual` | 0x01174E12 | - | O2 fraction in residual |

---

## Charge Flow Estimation

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `C_CHP_Charge_Flow_Fil_Cnst` | 0x01177C00 | - | Filter constant for charge flow |
| `C_CHP_Charge_Flow_Max` | 0x01177C02 | LB/MIN | Maximum charge flow limit |
| `C_CHP_Charge_Flow_Min` | 0x01177C04 | LB/MIN | Minimum charge flow limit |
| `C_CHP_Fresh_Air_Flow_Fil_Cnst` | 0x011A0F00 | - | Fresh air flow filter constant |

---

## Pumping Torque Estimation

The firmware estimates parasitic pumping torque for load calculations:

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `C_CHP_Pumping_Torque_Max` | 0x01178000 | FT*LB | Max pumping torque limit |
| `C_CHP_Pumping_Torque_Min` | 0x01178002 | FT*LB | Min pumping torque limit |
| `C_CHP_Pump_Torque_Multiplier` | 0x01178004 | - | Pumping torque multiplier |
| `C_CHP_Pump_Torque_Offset` | 0x01178006 | - | Pumping torque offset |
| `C_CHP_Pump_Torque_Deadband` | 0x01178008 | IN_HG | Deadband for smoothing |
| `C_CHP_Pump_Torque_Min_Fuel` | 0x0117800A | MM3S | Minimum fuel threshold |
| `C_CHP_Nominal_Delta_P_Table` | 0x01195400 | IN_HG | Nominal engine ΔP table |

### Calculated Outputs

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CHP_Pumping_Torque_Adj` | 0x01178102 | Adjusted pumping torque |
| `CHP_Pumping_Torque_No_Offset` | 0x01178104 | Raw pumping torque |
| `CHP_Nominal_Engine_Delta_P` | 0x01178100 | Nominal intake-exhaust ΔP |

---

## Combustion Reference (CBR Module)

The **CBR (Combustion Reference)** module converts torque demand to fuel quantity and manages emissions strategies.

### Fuel Conversion

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `CBR_Gross_Fuel` | 0x0116A500 | MM3S | Torque converted to fuel |
| `CBR_Gross_Fuel_Before_Adj` | 0x0116A51C | MM3S | Before SOI adjustment |
| `CBR_Fuel_Ref` | 0x0116A504 | MM3S | Fuel reference (unlimited) |
| `CBR_Density_Max_Fuel` | 0x0116A56E | MM3S | Density-based fuel limit |
| `CBR_Max_Chi_Fuel` | 0x0116A56A | MM3S | Chi-based fuel limit |

### Combustion Strategy (Chi/Alpha)

Chi (χ) and Alpha (α) are emissions strategy parameters:

| Parameter | Address | Description |
|-----------|---------|-------------|
| `CBR_Chi_Value` | 0x0116A51E | Active combustion strategy scalar |
| `CBR_Alpha` | 0x0116A514 | Emissions mode alpha value |
| `CBR_Chi_Source` | 0x0116A524 | Source of current chi |
| `CBR_EGR_Off` | 0x0116A516 | EGR disabled flag |

---

## Combustion Output Parameters (CBO Module)

The **CBO (Combustion Output)** module provides delta values for closed-loop corrections:

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `CBO_Delta_Charge_Tmptr` | 0x0117110A | DEG_F | Charge temp error |
| `CBO_Delta_EGR_Frac` | 0x01171112 | - | EGR fraction error |
| `CBO_Delta_MCF` | 0x0117110E | LB/MIN | Mass charge flow error |
| `CBO_bsNOx` | 0x0117111A | G/HP*HR | Brake-specific NOx |
| `CBO_Off` | 0x01171122 | - | CBO disabled flag |

---

## Torque to Fuel Conversion (CBP)

| Parameter | Address | Units | Description |
|-----------|---------|-------|-------------|
| `CBP_Adj_Total_Fueling` | 0x01177A08 | MM3S | Adjusted total fuel quantity |
| `CBP_Combustion_Torque` | 0x01177A0A | FT*LB | Estimated combustion torque |
| `CBP_Net_Combustion_Torque` | 0x01177A00 | FT*LB | Net torque (gross - pumping) |
| `CBP_SOI_Torque_Adj_Gain` | 0x01177A04 | MM3S/deg | SOI correction gain |

---

## Alternate Cylinder Count Locations

Multiple locations store cylinder count for different subsystems:

| Parameter | Address | Size | Subsystem |
|-----------|---------|------|-----------|
| `C_CHP_Number_Of_Cylinders` | 0x01174F00 | 2 | CHP module |
| `CBD_Cylinders` | 0x0181AE3E | 2 | Cylinder Balance Diagnostics |
| `EST2CY` (Engine_Cylinders) | 0x0181944C | 1 | Engine timing/scheduler |

---

## Calculation Flow

```
Engine Geometry (CHP)
├── Displacement, Bore, Stroke
├── Veff Tables + Parameters
└── Calculated Volumetric Efficiency
           │
           ▼
Mass Calculations (CBP)
├── Air Mass = f(Veff, Displacement, MAP, RPM)
├── Charge Mass = Air Mass + EGR Mass
├── Fuel Mass = f(Torque Demand, SOI)
└── A/F Ratio, Phi
           │
           ▼
Combustion Reference (CBR)
├── Torque → Fuel conversion
├── Chi/Alpha emissions strategy
└── Fuel limits (density, chi-based)
           │
           ▼
Final Fueling (FSS)
└── FSS_Total_Fueling → Injector control
```

---

## Firmware Function Map

### Scheduler Entry Points

The fuel demand calculations run in periodic task groups:

| Function | Address | Frequency | Purpose |
|----------|---------|-----------|---------|
| `periodicTaskGroup0_fuelFinal` | 0x0000b8fc | High (every 4th phase) | Final fuel calculations, injector control |
| `periodicTaskGroup35_fuelDemand` | 0x0000bf08 | Medium (phases 10, 30) | Fuel demand coordination |

### Fuel Demand Calculation Chain

```
periodicTaskGroup35_fuelDemand() @ 0x0000bf08
├── fuelDemandCoordinator() @ 0x00017980
│   ├── fuelDemandModeSelector() @ 0x00017150
│   ├── fuelDemandEnableChecker() @ 0x000172b0
│   ├── fuelDemandRateLimiterStateMachine() @ 0x000172e8
│   └── fuelDemandSmoothingController() @ 0x00017560
├── updateEngineLoadPercentage() @ 0x00523148 (Bank 2)
├── checkFuelDemandEnableConditions() @ 0x0050370c (Bank 2)
└── initCalibrationSequenceHandler() @ 0x00537584 (Bank 2)
```

### Fuel Final Calculation Chain

```
periodicTaskGroup0_fuelFinal() @ 0x0000b8fc
├── injectorPulseWidthCalc() @ 0x000533e0
├── selectFuelFlowMode()
├── setEngineRpmFromCalibration()
├── calculateFuelDemandLimitOutput()
├── sensorChannel3_boostPressureInit() (MAP sensor)
├── updateEngineCycleOutputs()
├── processFuelDemandEnableFlag()
├── fuelDemandFinalCalculation() @ 0x0001782c
└── processColdStartMainLoop()
```

### Key Fuel Functions (Bank 1 - ROM)

| Function | Address | Role |
|----------|---------|------|
| `fuelDemandCoordinator` | 0x00017980 | Master fuel demand orchestrator |
| `fuelDemandFinalCalculation` | 0x0001782c | Final fuel quantity output |
| `fuelDemandModeSelector` | 0x00017150 | Select calculation mode |
| `fuelDemandEnableChecker` | 0x000172b0 | Validate enable conditions |
| `fuelDemandRateLimiterStateMachine` | 0x000172e8 | Rate of change limiting |
| `fuelDemandSmoothingController` | 0x00017560 | Output smoothing filter |
| `fuelDemandWithLoadCompensation` | 0x00012dc4 | Load-based fuel adjustment |
| `fuelDemandErrorCalculation` | 0x00012eb4 | Error term calculation |
| `fuelDemandBlendCalculation` | 0x0000dcdc | Blend multiple demands |
| `injectorPulseWidthCalc` | 0x000533e0 | Injector pulse width |
| `calculateFuelInjectionTiming` | 0x00016a90 | Injection timing (SOI) |

### Key Utility Functions (Bank 2 - Flash)

| Function | Address | Role |
|----------|---------|------|
| `updateEngineLoadPercentage` | 0x00523148 | Calculate engine load % |
| `checkFuelDemandEnableConditions` | 0x0050370c | Fuel enable flag logic |
| `initCalibrationSequenceHandler` | 0x00537584 | Calibration sequence init |
| `sensorChannelConfigInit` | 0x00500234 | Sensor channel setup |
| `updateSensorChannelWithConfig` | 0x00500a4c | Sensor value updates |

### Architecture Notes

1. **Two-Bank Design**: Bank 1 (ROM @ 0x00xxxxxx) contains control logic; Bank 2 (Flash @ 0x005xxxxx) contains utility math and sensor processing

2. **Calibration Addresses**: The CHP/CBP parameters (0x0117xxxx range) are in calibration flash, accessed via indirect addressing from ROM functions

3. **Execution Order**:
   - `periodicTaskGroup0_fuelFinal` runs first (high priority)
   - `periodicTaskGroup35_fuelDemand` runs later for demand calculation
   - Both write to shared RAM variables for coordination

---

## Tuning Notes

### 5.9L → 6.7L Engine Swap

For a displacement swap, modify at minimum:

1. **C_CHP_Engine_Displacement** - Primary displacement value
2. **C_CHP_Veff_Bore** - New bore diameter
3. **C_CHP_Veff_Stroke** - New stroke length
4. **Veff tables** - May need rescaling for different port flow characteristics

The larger displacement will:
- Increase calculated air mass at same MAP/RPM
- Allow proportionally more fuel before hitting A/F limits
- Change pumping torque estimates
- Affect EGR fraction calculations

### Parameters NOT to Change

- **C_CHP_Number_Of_Cylinders** - Same for 5.9/6.7L (6 cylinders)
- **Injector timing parameters** - Same injector count/type
- **Sensor calibrations** - Same sensors used

---

## Related Documentation

- [Fuel Injection Analysis](../output/fuel_injection_analysis.md) - Injection timing and quantity
- [Pilot Injection Tables](../output/pilot_injection_tables.md) - Pilot injection calibration
- [Fuel Rail Pressure Control](../output/fuel_rail_pressure_control.md) - HPCR system
- [Main Injection Timing](../output/main_injection_timing.md) - SOI calibration
