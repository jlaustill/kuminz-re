# CM848 HPCR Fuel Rail Pressure Control System

## Overview

The High Pressure Common Rail (HPCR) system maintains precise fuel rail pressure using a closed-loop PID controller. The CP3 high-pressure pump is controlled via PWM duty cycle to the MPROP (Metering/Pressure Regulator) valve.

## System Components

### Hardware

| Component | Function |
|-----------|----------|
| CP3 Pump | Bosch high-pressure pump (up to 1600 bar capable) |
| MPROP Valve | Inlet metering valve controlling pump displacement |
| Rail Pressure Sensor | Measures actual rail pressure (0-200+ MPa) |
| Injectors | 6 solenoid injectors with fast decay control |

### Control Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│                    OUTER LOOP (Pressure Control)                │
│                                                                 │
│  ┌──────────────┐    ┌─────────────┐    ┌──────────────────┐   │
│  │   Setpoint   │───►│  PID        │───►│  Dutycycle       │   │
│  │   Tables     │    │  Controller │    │  Output          │   │
│  └──────────────┘    └─────────────┘    └──────────────────┘   │
│         ▲                   ▲                    │              │
│         │                   │                    ▼              │
│         │            ┌──────┴──────┐    ┌──────────────────┐   │
│         │            │  Pressure   │    │  INNER LOOP      │   │
│         │            │  Error      │    │  (Current Comp)  │   │
│         │            └─────────────┘    └──────────────────┘   │
│         │                   ▲                    │              │
│         │                   │                    ▼              │
│         │            ┌──────┴──────┐    ┌──────────────────┐   │
│  Speed, Fueling,     │  Filtered   │    │  MPROP Valve     │   │
│  Coolant, Ambient    │  Pressure   │◄───│  (CP3 Pump)      │   │
│                      └─────────────┘    └──────────────────┘   │
└─────────────────────────────────────────────────────────────────┘
```

## Pressure Setpoint Calculation

### Base Pressure Map (3D)

| Parameter | Address | Unit | Scale |
|-----------|---------|------|-------|
| HPCR_Fuelpr_Base_Map_RPM_Axis | 0x01802D00 | RPM | 0.125 |
| HPCR_Fuelpr_Base_Map_Fuel_Axis | 0x01802E00 | MM3S | 0.0679 |
| HPCR_Fuelpr_Base_Map_Pressure_Axis | 0x01802F00 | MPa | 0.0488 |

**Output:** `HPCR_Fuelpr_Base_Setpoint` @ 0x01803F08

**Typical pressure ranges:**
- Idle: 30-40 MPa (4,350-5,800 psi)
- Part load: 60-100 MPa (8,700-14,500 psi)
- Full load: 140-160 MPa (20,300-23,200 psi)

### Correction Tables

#### Coolant Temperature Correction

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Fuelpr_Coolant_Map_RPM_Axis | 0x01803600 | Speed axis |
| HPCR_Fuelpr_Coolant_Map_Fuel_Axis | 0x01803700 | Fuel axis |
| HPCR_Fuelpr_Coolant_Map_Pressure_Axis | 0x01803800 | Pressure output |
| HPCR_Fuelpr_Setpoint_Scaling_Coolant_Temp_Axis | 0x01802500 | Temp axis |
| HPCR_Fuelpr_Setpoint_Scaling_Coolant_Factor_Axis | 0x018B6500 | Factor output |

- Cold engine: Higher rail pressure for better atomization
- Warm engine: Nominal pressure

#### Ambient Pressure Correction

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Fuelpr_Ambient_Pressure_Map_Speed_Axis | 0x018AFD00 | Speed axis |
| HPCR_Fuelpr_Ambient_Pressure_Map_Fuel_Axis | 0x018AFE00 | Fuel axis |
| HPCR_Fuelpr_Ambient_Pressure_Map_Pressure_Axis | 0x018AFF00 | Pressure output |
| HPCR_Fuelpr_Ambient_Pressure_Factor_Temp_Axis | 0x018B0000 | Temp axis |
| HPCR_Fuelpr_Ambient_Pressure_Factor_Press_Axis | 0x018B0100 | Ambient pres axis |
| HPCR_Fuelpr_Ambient_Pressure_Factor_Axis | 0x018B0200 | Factor output |

#### Chi Tables (Emissions)

| Table | Speed Axis | Fuel Axis | Output |
|-------|------------|-----------|--------|
| Chi2 | 0x018C8800 | 0x018C8900 | 0x018C8A00 |
| Chi3 | 0x018C8B00 | 0x018C8C00 | 0x018C8D00 |
| Chi4 | 0x018C8E00 | 0x018C8F00 | 0x018C9000 |

#### Alpha1 Alternative Map

| Parameter | Address |
|-----------|---------|
| HPCR_Fuelpr_Alpha1_Map_RPM_Axis | 0x018B1900 |
| HPCR_Fuelpr_Alpha1_Map_Fuel_Axis | 0x018B1A00 |
| HPCR_Fuelpr_Alpha1_Map_Pressure_Axis | 0x018B1B00 |

### Cranking Mode Pressure

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Fuelpr_Crank_Map_Speed_Axis | 0x018B0F00 | RPM axis |
| HPCR_Fuelpr_Crank_Map_Coolant_Temp_Axis | 0x018B1000 | Temp axis |
| HPCR_Fuelpr_Crank_Map_Pressure_Axis | 0x018B1100 | Pressure output |
| HPCR_Crank_Fuelpr_Setpoint | 0x01803F02 | Crank setpoint |
| HPCR_Fuelpr_Crank_Mode_Enable | 0x01106B56 (bit 0x0004) | Enable flag |
| HPCR_Min_Fuelpr_Crank | 0x0180221C | Min crank pressure |
| HPCR_Fuelpr_Crank_Run_Slew_Rate_Limit | 0x0180220C | Crank→Run slew |

### Setpoint Selection Logic

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Fuelpr_Selection_Switch | 0x01802207 | 0=increment, 1=MIN WINS |
| HPCR_Fuelpr_Setpoint_Max | 0x01802210 | Maximum allowed setpoint |
| HPCR_Fuelpr_Increment_Limit | 0x0180220E | Max increase per loop |
| HPCR_Fuelpr_Setpoint_Hysteresis | 0x0180221A | Deadband (MPa) |

**Final Setpoint:** `HPCR_Fuelpr_Setpoint` @ 0x01803F00

---

## PID Controller

### Controller Structure

The fuel pressure controller uses a **nonlinear PID** with separate gains for:
- Small signal (near setpoint)
- Large positive error (pressure too low)
- Large negative error (pressure too high)

### Proportional Component

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| HPCR_Propgain_Small_Signal | 0x01801400 | %/MPa | Near setpoint |
| HPCR_Propgain_Positive_Large_Signal | 0x01801404 | %/MPa | Pressure too low |
| HPCR_Propgain_Negative_Large_Signal | 0x01801408 | %/MPa | Pressure too high |
| HPCR_Propgain_Positive_Window_Width | 0x0180140C | MPa | Transition threshold |
| HPCR_Propgain_Negative_Window_Width | 0x0180140E | MPa | Transition threshold |

**Output:** `HPCR_Fuelpr_Prop_Dutycycle` @ 0x01801907

### Integral Component

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| HPCR_Integral_Gain_Small_Signal | 0x01801500 | %/MPa/SEC | Near setpoint |
| HPCR_Integral_Gain_Positive_Large_Signal | 0x01801504 | %/MPa/SEC | Pressure too low |
| HPCR_Integral_Gain_Negative_Large_Signal | 0x01801508 | %/MPa/SEC | Pressure too high |
| HPCR_Integral_Gain_Positive_Window_Width | 0x0180150C | MPa | Transition threshold |
| HPCR_Integral_Gain_Negative_Window_Width | 0x0180150E | MPa | Transition threshold |

**Output:** `HPCR_Fuelpr_Integral_Dutycycle` @ 0x01801909

### Derivative Component

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| HPCR_Derivative_Gain_Constant | 0x0180EF00 | - | Filter constant |
| HPCR_Derivative_Gain_Small_Signal | 0x0180EF02 | %/MPa/SEC | Near setpoint |
| HPCR_Derivative_Gain_Positive_Large_Signal | 0x0180EF06 | %/MPa/SEC | Pressure rising |
| HPCR_Derivative_Gain_Negative_Large_Signal | 0x0180EF0A | %/MPa/SEC | Pressure falling |
| HPCR_Fuel_Pressure_Filter_Constant | 0x01800032 | - | Pressure filter |

**Output:** `HPCR_Fuelpr_Derivative_Dutycycle` @ 0x0180190B

### RPM-Based Gain Scheduling

Each PID gain has an RPM-based scaling factor:

| Component | RPM Axis | Scale Factor Axis |
|-----------|----------|-------------------|
| P Small | 0x01800500 | 0x01800800 |
| P +Large | 0x01800600 | 0x01800900 |
| P -Large | 0x01800700 | 0x01800A00 |
| I Small | 0x01800B00 | 0x01800E00 |
| I +Large | 0x01800C00 | 0x01800F00 |
| I -Large | 0x01800D00 | 0x01801000 |
| D Small | 0x0180E700 | 0x0180EA00 |
| D +Large | 0x0180E800 | 0x0180EB00 |
| D -Large | 0x0180E900 | 0x0180EC00 |

### Throttle Feed-Forward

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Throttle_FF_Deriv_Gain | 0x01800036 | Feed-forward gain |
| HPCR_Throttle_FF_Filter_Constant | 0x01800034 | Filter TC |
| HPCR_Max_Throttle_Deriv | 0x0180003A | Max contribution |
| HPCR_Min_Throttle_Deriv | 0x01800038 | Min contribution |

**Output:** `HPCR_Fuelpr_Throttle_FF_Dutycycle` @ 0x0180190D

---

## Inner Current Loop

The duty cycle output is refined by an inner current compensation loop:

### Current Measurement

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Current_Pressure_Regulator | 0x01801D00 | Measured current (mA) |
| HPCR_Current_Max | 0x01801A02 | Maximum allowed |
| HPCR_Current_Min | 0x01801A14 | Open-circuit threshold |
| HPCR_Measured_Current_Filter_Constant | 0x0180002C | Filter TC |

### Current-to-Duty Cycle Conversion

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Current_Scaling_Voltage_Axis | 0x01801B00 | Battery voltage axis |
| HPCR_Current_Scaling_Axis | 0x01801C00 | Current axis |
| HPCR_Current_Scaling_Dutycycle_Axis | 0x01800100 | Duty cycle axis |
| HPCR_Current_Scaling_Current_Axis | 0x01800200 | Current output |

### Current Compensation PID

| Parameter | Address | Unit |
|-----------|---------|------|
| HPCR_Currentcomp_Propgain_Small_Signal | 0x01801600 | CNTS/mA |
| HPCR_Currentcomp_Propgain_Positive_Large_Signal | 0x01801604 | CNTS/mA |
| HPCR_Currentcomp_Propgain_Negative_Large_Signal | 0x01801608 | CNTS/mA |
| HPCR_Currentcomp_Integral_Gain_Small_Signal | 0x01801700 | CNTS/mA/SEC |
| HPCR_Currentcomp_Integral_Gain_Poslarge_Signal | 0x01801704 | CNTS/mA/SEC |
| HPCR_Currentcomp_Integral_Gain_Neglarge_Signal | 0x01801708 | CNTS/mA/SEC |

**Error:** `HPCR_Fuelpr_Current_Comp_Error_Current` @ 0x0180190F

---

## Duty Cycle Output

### Final Output

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Dutycycle_Output | 0x01801903 | Final PWM output (%) |
| HPCR_Dutycycle_Output_Max | 0x0180003C | Maximum limit |
| HPCR_Dutycycle_Output_Min | 0x0180003E | Minimum limit |
| HPCR_Dutycycle_Monitoring | 0x01801901 | For diagnostics |

### Pre-Control (Open Loop)

During startup before closed-loop engages:

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Dutycycle_Precontrol_Map_RPM_Axis | 0x01801100 | RPM axis |
| HPCR_Dutycycle_Precontrol_Map_Fuel_Axis | 0x01801200 | Fuel axis |
| HPCR_Dutycycle_Precontrol_Map_Dutycycle_Axis | 0x01801300 | Duty output |
| HPCR_Precontrol | 0x01800001 | Enable switch |

### Closed-Loop Transition

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Min_Pressure_Switch_Closedloop | 0x0180000A | Min pressure to enter |
| HPCR_Min_RPM_Switch_Closedloop | 0x0180000C | Min RPM to enter |
| HPCR_Min_Pressure_Stay_Closedloop | 0x0180000E | Min pressure to stay |
| HPCR_Min_RPM_Stay_Closedloop | 0x01800010 | Min RPM to stay |
| HPCR_Count_Rev | 0x01800008 | Rev count for transition |

### Battery Voltage Compensation

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Filtered_Battery_Voltage | 0x01801905 | Filtered voltage |
| HPCR_Battery_Voltage_Filter_Constant | 0x01800030 | Filter TC |
| HPCR_Battery_Correction_Voltage_Axis | 0x0180B700 | Voltage axis |
| HPCR_Battery_Correction_Scaling_Factor_Axis | 0x0180B800 | Scale factor |

---

## Operating Modes

| Mode | Parameter | Description |
|------|-----------|-------------|
| Pre-control | HPCR_Precontrol = 1 | Open-loop at startup |
| Closed-loop | Pressure > threshold | Normal operation |
| Deflate | Engine stopping | Pressure bleed-down |
| Testbench | HPCR_Testbench = 1 | Fixed duty cycle |
| Limp Home | Sensor fault | Default pressure |

**Mode indicator:** `HPCR_Fuelpr_Operating_Mode` @ 0x01801900

---

## Pressure Sensing

| Parameter | Address | Unit | Description |
|-----------|---------|------|-------------|
| HPCR_Voltage_Fuelpr | 0x01802100 | V | Raw sensor voltage |
| HPCR_Fuel_Pressure | 0x01802102 | MPa | Converted pressure |
| HPCR_Filtered_Fuelpr | 0x01802104 | MPa | Filtered pressure |
| HPCR_Filtered_Fuelpr_Control | 0x01801912 | MPa | For controller |
| HPCR_Fuelpr_Filter_Constant | 0x01801E0A | - | Filter time constant |

### Sensor Calibration

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Fuelpr_Scaling_Voltage_Axis | 0x01801F00 | Voltage input axis |
| HPCR_Fuelpr_Scaling_Pressure_Axis | 0x01802000 | Pressure output axis |
| HPCR_MIN_Fuelpr_Voltage | 0x01801E02 | Min valid voltage |
| HPCR_MAX_Fuelpr_Voltage | 0x01801E00 | Max valid voltage |

---

## Diagnostics

### Cusum Deviation Detection

Cumulative sum algorithm detects persistent pressure deviations:

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Cusum_Pos | 0x01162700 | Accumulated positive error |
| HPCR_Cusum_Neg | 0x01162704 | Accumulated negative error |
| HPCR_Cusum_Delta | 0x01162708 | Current deviation |
| HPCR_Cusum_Pos_Threshold | 0x01162600 | Positive threshold |
| HPCR_Cusum_Neg_Threshold | 0x01162604 | Negative threshold |
| HPCR_Cusum_Timer | 0x01162608 | Accumulation period |
| HPCR_Cusum_Scale | 0x01162612 | Scaling factor |

**Enable:** `HPCR_Cusum_Monitor_Enable` @ 0x01106B56 (bit 0x4000)

### Leak Detection

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Cusum_Leak_Pos | 0x0118F000 | Leak accumulator |
| HPCR_Cusum_Leak_Pos_Threshold | 0x0118F100 | Leak threshold |
| HPCR_Cusum_Leak_Delta | 0x0118F004 | Leak deviation |
| HPCR_Leak_Fuel_Limit | 0x01801A26 | Fuel limit during leak |
| HPCR_Leak_RPM_Limit | 0x01801A2A | RPM limit during leak |
| HPCR_Leak_Fuelpr_Limit | 0x01801A28 | Pressure limit |

**Enable:** `HPCR_Cusum_Leak_Monitor_Enable` @ 0x01106B56 (bit 0x8000)

### Over-Pressure Protection

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Fuelpr_Max_Limit | 0x01801A08 | Overpressure threshold |
| HPCR_Fuelpr_Monitor_Max | 0x01801A00 | Max valid pressure |
| HPCR_High_Fuelpr_Shutdown | 0x01801A2C | Enable shutdown |
| HPCR_Fuelpr_Test_Samples | 0x01801A1A | Samples before shutdown |

### CP3 Current Faults

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_CP3_High_Current_Error | 0x01103620 (bit 0x0200) | High current |
| HPCR_CP3_Low_Current_Error | 0x01103620 (bit 0x0100) | Low/open circuit |
| HPCR_CP3_Max_Dutycycle_Limit | 0x01801A24 | High diag threshold |
| HPCR_CP3_Min_Dutycycle_Limit | 0x01801A22 | Low diag threshold |
| HPCR_Current_Fault_Time | 0x01801A16 | Debounce time |

### Limp Home Mode

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Fuelpr_Limp_Home | 0x01801D0C | Limp home active flag |
| HPCR_Fuelpr_Default | 0x01801E10 | Default pressure value |
| HPCR_Fuelpr_Fault_Fuel_Limit | 0x01801A1C | Fuel limit in fault |
| HPCR_Fuelpr_Fault_RPM_Limit | 0x01801A1E | RPM limit in fault |

---

## MPROP Coil Temperature Estimation

Estimates coil temperature from resistance:

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_MPROP_Coil_Resistance | 0x01801916 | Estimated resistance (Ω) |
| HPCR_MPROP_Coil_Initial_Resistance | 0x018B3C16 | Cold resistance |
| HPCR_MPROP_Temperature_Gain | 0x018B3C1C | R→T slope |
| HPCR_MPROP_Temperature_Offset | 0x018B3C1E | R→T offset |
| HPCR_Coil_Resistance_Filter_Coeff | 0x018B3C0E | Filter coefficient |

**Temperature-based startup:**
| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Cold_MPROP_Temperature | 0x018B3C00 | Cold threshold |
| HPCR_Hot_MPROP_Temperature | 0x018B3C02 | Hot threshold |
| HPCR_Hot_Start_Dutycycle_Speed_Axis | 0x018B3900 | Hot start RPM axis |
| HPCR_Hot_Start_Dutycycle_Axis | 0x018B3A00 | Hot start duty |

---

## Override Parameters

For calibration and diagnostics:

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Fuel_Pressure_Override_Switch | 0x01801E0C | Override enable |
| HPCR_Fuel_Pressure_Override_Value | 0x01801E0D | Override pressure |
| HPCR_Fuel_Pressure_Setpoint_Override_Switch | 0x01802202 | Setpoint override |
| HPCR_Fuel_Pressure_Setpoint_Override_Value | 0x01802203 | Setpoint value |
| HPCR_Fuelpr_Dutycycle_Override_Switch | 0x01800026 | Duty override |
| HPCR_Fuelpr_Dutycycle_Override_Value | 0x01800027 | Duty value |

---

## Key Output Variables

| Parameter | Address | Description |
|-----------|---------|-------------|
| HPCR_Fuelpr_Setpoint | 0x01803F00 | Target pressure |
| HPCR_Fuel_Pressure | 0x01802102 | Actual pressure |
| HPCR_Fuelpr_Setpoint_State | 0x01803F14 | Which table controls |
| HPCR_Fuelpr_Status | 0x01801D03 | System status |
| HPCR_Fuelpr_Limp_Home | 0x01801D0C | Limp home flag |
| HPCR_Dutycycle_Output | 0x01801903 | PWM to MPROP |

---

## Calibration Tips

### Tuning the PID Controller

1. **Start with proportional gain** - Set I and D to minimum
2. **Increase P until oscillation** - Then reduce by 50%
3. **Add integral** - To eliminate steady-state error
4. **Add derivative** - For faster response if needed
5. **Use separate gains** for positive/negative errors

### Rail Pressure Setpoint

- Higher pressure = better atomization, more power
- Lower pressure = reduced pump load, better efficiency
- Balance NVH (noise) vs performance

### Common Issues

| Symptom | Possible Cause | Check |
|---------|---------------|-------|
| Slow response | Low P/I gains | HPCR_Propgain_*, HPCR_Integral_* |
| Oscillation | High gains | Reduce P, check D |
| Undershoot | Low precontrol | HPCR_Dutycycle_Precontrol_* |
| Overshoot | High FF gain | HPCR_Throttle_FF_* |
| Cusum fault | Persistent deviation | Check pump, injectors |
