# CM848 Wastegate Control Path Documentation

## Overview

The CM848 ECU controls boost pressure via a PWM-driven wastegate solenoid (CWG - Controlled WasteGate). This is an open-loop pressure control system that modulates wastegate duty cycle based on manifold pressure targets derived from fuel demand and engine operating conditions.

## Control Architecture

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                         WASTEGATE CONTROL FLOW                               │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                              │
│  ┌──────────────────┐                                                        │
│  │ Boost Pressure   │                                                        │
│  │ Sensor (ADC)     │                                                        │
│  └────────┬─────────┘                                                        │
│           │                                                                  │
│           ▼                                                                  │
│  ┌──────────────────┐     ┌──────────────────┐                              │
│  │ sensorChannel3_  │────▶│ boost_pressure_  │                              │
│  │ boostPressure    │     │ sensor_raw       │                              │
│  │ Process()        │     │ (0x0040bd8e)     │                              │
│  └──────────────────┘     └────────┬─────────┘                              │
│                                    │                                         │
│           ┌────────────────────────┼────────────────────────┐               │
│           │                        │                        │               │
│           ▼                        ▼                        ▼               │
│  ┌──────────────────┐     ┌──────────────────┐     ┌──────────────────┐    │
│  │ Turbo Ratio      │     │ Boost Protection │     │ Load Normalizer  │    │
│  │ Calculation      │     │ Conditions       │     │ Selection        │    │
│  └────────┬─────────┘     └────────┬─────────┘     └────────┬─────────┘    │
│           │                        │                        │               │
│           ▼                        ▼                        ▼               │
│  ┌──────────────────┐     ┌──────────────────┐     ┌──────────────────┐    │
│  │ turbo_blend_     │     │ boost_protection │     │ boost_denominator│    │
│  │ output           │     │ _mode            │     │ _min128          │    │
│  │ (0x0040a378)     │     │ (0x0040a606)     │     │ (0x0040a5f8)     │    │
│  └────────┬─────────┘     └────────┬─────────┘     └──────────────────┘    │
│           │                        │                                         │
│           └────────────┬───────────┘                                         │
│                        ▼                                                     │
│           ┌──────────────────────────┐                                       │
│           │ Manifold Pressure Target │                                       │
│           │ Calculation              │                                       │
│           │ (2D table lookup)        │                                       │
│           └────────────┬─────────────┘                                       │
│                        ▼                                                     │
│           ┌──────────────────────────┐                                       │
│           │ manifold_pressure_target │                                       │
│           │ (0x0040a450)             │                                       │
│           └────────────┬─────────────┘                                       │
│                        ▼                                                     │
│           ┌──────────────────────────┐                                       │
│           │ processBoostProtection   │                                       │
│           │ Mode()                   │                                       │
│           │ @ 0x00013aec             │                                       │
│           └────────────┬─────────────┘                                       │
│                        ▼                                                     │
│           ┌──────────────────────────┐                                       │
│           │ wastegate_pressure_      │                                       │
│           │ filtered                 │                                       │
│           │ (0x0040a452)             │                                       │
│           └────────────┬─────────────┘                                       │
│                        ▼                                                     │
│           ┌──────────────────────────┐                                       │
│           │ Wastegate PWM Output     │                                       │
│           │ (Duty Cycle 0-100%)      │                                       │
│           └──────────────────────────┘                                       │
│                                                                              │
└─────────────────────────────────────────────────────────────────────────────┘
```

## Key Functions

### 1. Sensor Input Stage

**Function:** `sensorChannel3_boostPressureInit()` / `sensorChannel3_boostPressureProcess()`
**Address:** 0x0000cc04 / 0x0000cc90

Reads boost pressure from ADC channel and outputs to:
- `boost_pressure_sensor_raw` (0x0040bd8e) - Raw sensor value
- `boost_pressure_sensor_filtered` (0x0040bda6) - Filtered value
- `boost_protection_input` (0x0040be20) - Protection system input

**Scale Factor:** 0.0159064138077 IN_HG per raw count

---

### 2. Turbo Ratio Calculation

**Function:** `calculateTurboRatioWithMode()`
**Address:** 0x00010d3c

Calculates turbo ratio based on operating mode:

```c
void calculateTurboRatioWithMode(void) {
    // Select base or alternate ratio based on mode
    uVar1 = _turbo_ratio_base_value;
    if (_turbo_mode_selector == 1) {
        uVar1 = _turbo_ratio_alt_value;
    }

    // Lookup and scale turbo ratio
    uVar2 = lookupTableInterpolation(&turbo_ratio_filter_coeff_a,
                                      _turbo_ratio_sensor_input, ...);
    _turbo_ratio_scaled_output = (uVar1 * uVar2) >> 15;

    // Apply multiplier and limit
    sVar3 = lookupTableInterpolation(&turbo_ratio_filter_coeff_b, ...);
    uVar5 = sVar3 * _turbo_ratio_multiplier;

    // Clamp to limit
    if (sVar4 < _turbo_ratio_limit_max) {
        sVar3 = sVar4;
    }

    // Filter the result
    _turbo_blend_input = signedFirstOrderFilter(sVar3, &turbo_ratio_filter_ptr_a);

    calculateTurboBlendOutput();
}
```

---

### 3. Turbo Blend Output

**Function:** `calculateTurboBlendOutput()`
**Address:** 0x00010b28

Determines final turbo blend output based on mode state:

```c
void calculateTurboBlendOutput(void) {
    // Set mode state based on setpoint vs thresholds
    if (_turbo_mode_setpoint < _turbo_mode_threshold_high) {
        if (_turbo_mode_setpoint <= _turbo_mode_threshold_low) {
            _turbo_mode_state = 0;  // Normal mode
        }
    } else {
        _turbo_mode_state = 1;  // Active mode
    }

    // Select input source based on enable flag
    if (_turbo_control_enable_flag != 0) {
        iVar3 = _turbo_ratio_a_filtered;
    }

    // Calculate output based on mode
    uVar4 = _load_ema_denominator + iVar3 * -2;

    // Select final output
    if ((_turbo_ratio_a_enable == 0) &&
        (_turbo_mode_active == 0) &&
        (_engine_run_state == 0)) {
        _turbo_blend_output = _turbo_blend_base_value;
        _turbo_blend_select = 0;
    } else if ((uVar4 & 0xffff) < _turbo_blend_base_value) {
        _turbo_blend_output = (ushort)uVar4;
        _turbo_blend_select = 1;
    }
}
```

---

### 4. Boost Protection Mode Processing

**Function:** `processBoostProtectionMode()`
**Address:** 0x00013aec

Calculates wastegate pressure demand with protection logic:

```c
void processBoostProtectionMode(void) {
    // Set boost control word based on protection mode
    if ((_boost_protection_mode == 2) ||
        ((_calibration_feature_flags & 0x4000) == 0)) {
        _boost_control_word = 0x80;  // Override mode
    } else if (_boost_protection_mode == 1) {
        _boost_control_word = 0x40;  // Limited mode
    } else {
        _boost_control_word = 0;     // Normal mode
    }

    // Select wastegate mode value based on fuel demand mode
    switch (_fuel_demand_intermediate_1) {
        case 1: unaff_r31 = _wastegate_mode_value_1; break;
        case 2: unaff_r31 = _wastegate_mode_value_2; break;
        case 3: unaff_r31 = _wastegate_mode_value_3; break;
        case 4: unaff_r31 = _wastegate_mode_value_4; break;
    }

    // Calculate raw wastegate pressure
    _wastegate_pressure_raw = filterInputValue(unaff_r31, param_2,
                                               _wastegate_mode_value_0, ...);

    // Calculate pressure with derivative term (pseudo-PD control)
    iVar1 = ((_manifold_pressure_error - _wastegate_pressure_raw) *
             _pressure_derivative_multiplier >> 11) +
            _manifold_pressure_offset +
            _manifold_pressure_target;

    // Clamp to limits (-0xc80 to 0x5780)
    if (iVar1 < -0xc80) iVar1 = -0xc80;
    else if (iVar1 > 0x5780) iVar1 = 0x5780;

    // Apply first-order filter
    _wastegate_pressure_filtered = signedFirstOrderFilter(iVar1, &PTR_DAT_003fa60e);
}
```

---

### 5. Boost Protection Conditions

**Function:** `processBoostProtectionConditions()`
**Address:** 0x00013774

Evaluates conditions for boost protection activation:

```c
void processBoostProtectionConditions(void) {
    // Check system enable states and config
    if (((_system_enable_state & 0x100) == 0) ||
        ((boost_protection_config_byte & 1) == 0)) {
        uVar2 = 0;  // Disable protection
    }

    // Calculate boost deviation
    uVar3 = (_boost_torque_offset_ema - _boost_pressure_sensor_raw) -
            _boost_table_lookup_1;
    if (uVar3 < 0) uVar3 = -uVar3;  // Absolute value

    // Check if deviation exceeds threshold
    _boost_deviation_exceeded = (_boost_deviation_threshold < uVar3);

    processBoostControlState();
}
```

---

### 6. Manifold Pressure Input Selection

**Function:** `processManifoldPressureInput()` (implicit in control loop)
**Address:** 0x00013e08

Selects manifold pressure input source based on override conditions:

```c
// Condition evaluation
if (((uVar4 & 0x80) == 0) || (((uVar4 & 2) == 0 && ((uVar4 & 0x20) == 0)))) {
    if (((uVar4 & 2) == 0) && ((uVar4 & 0x20) == 0)) {
        _boost_override_active = 0;
        _manifold_pressure_input = sVar1;  // Normal: calculated value
    } else {
        _boost_override_active = 1;
        _manifold_pressure_input = _wastegate_pressure_filtered;  // Override
    }
} else {
    _manifold_pressure_input = _throttle_position_secondary;  // Fallback
    _boost_override_active = 2;
}
```

---

## Key Variables

### Sensor Inputs
| Address | Name | Description |
|---------|------|-------------|
| 0x0040bd8e | boost_pressure_sensor_raw | Raw MAP sensor value |
| 0x0040bda6 | boost_pressure_sensor_filtered | Filtered MAP value |
| 0x0040be20 | boost_protection_input | Input to protection system |

### Turbo Ratio Control
| Address | Name | Description |
|---------|------|-------------|
| 0x0040a196 | turbo_ratio_sensor_input | Sensor input for ratio calc |
| 0x0040a380 | turbo_ratio_scaled_output | Scaled calculation result |
| 0x0040a378 | turbo_blend_output | Final turbo blend value |
| 0x0040a37e | turbo_ratio_a_filtered | Filtered ratio A |
| 0x0040a384 | turbo_ratio_b_filtered | Filtered ratio B |
| 0x0040a388 | turbo_mode_active | Mode active flag |
| 0x003fa12e | turbo_mode_state | Current mode (0=normal, 1=active) |

### Calibration Parameters
| Address | Name | Description |
|---------|------|-------------|
| 0x003ff730 | turbo_ratio_base_value | Base turbo ratio |
| 0x003ff73e | turbo_ratio_alt_value | Alternate ratio for mode 1 |
| 0x003ff72e | turbo_ratio_multiplier | Scaling multiplier |
| 0x003ff740 | turbo_ratio_limit_max | Maximum ratio limit |
| 0x003ff736 | turbo_mode_threshold_high | High threshold for mode |
| 0x003ff738 | turbo_mode_threshold_low | Low threshold for mode |
| 0x003fd7de | turbo_control_enable_flag | Master enable |

### Wastegate Control
| Address | Name | Description |
|---------|------|-------------|
| 0x0040a450 | manifold_pressure_target | Target pressure from tables |
| 0x0040a608 | manifold_pressure_error | Pressure error term |
| 0x0040a454 | wastegate_pressure_raw | Raw wastegate demand |
| 0x0040a452 | wastegate_pressure_filtered | Filtered wastegate output |
| 0x004051f6-fe | wastegate_mode_value_0-4 | Mode-dependent values |
| 0x00405202 | manifold_pressure_offset | Pressure offset constant |
| 0x00405204 | pressure_derivative_multiplier | Derivative gain |

### Protection System
| Address | Name | Description |
|---------|------|-------------|
| 0x0040a606 | boost_protection_mode | 0=normal, 1=limited, 2=override |
| 0x0040a60c | boost_control_word | Control state flags |
| 0x0040a5fa | boost_deviation_exceeded | Deviation threshold flag |
| 0x003ff06f | boost_protection_config_byte | Protection enable bits |

---

## PWM Output (CWG - Controlled WasteGate)

### E2M Parameters
| Parameter | Address | Description |
|-----------|---------|-------------|
| CWG_Monitor_Enable | 0x01106B28 bit 0x0008 | Wastegate enable flag |
| CWG_PWM_Duty_Cycle_Min | 0x018C5E08 | Minimum duty cycle |
| CWG_PWM_Duty_Cycle_Max | 0x018C5E06 | Maximum duty cycle |
| CWG_PWM_Duty_Cycle_Invert | 0x018C5E01 | Invert polarity flag |
| Wastegate_Pressure_Control_Driver_Map | 0x01156516 | Hardware channel index |
| Wastegate_Pressure_Control_Driver_Frequency | 0x018C5E02 | PWM frequency (Hz) |
| Wastegate_Pressure_Control_Driver_Duty_Cycle | 0x01151C16 | Output duty cycle |

### Hardware Output
The wastegate solenoid is driven by a PWM output on one of the MIOS/TPU channels. The `Wastegate_Pressure_Control_Driver_Map` parameter defines which hardware channel is used.

---

## Control Loop Timing

The wastegate control runs as part of the main engine control loop:

1. **Sensor Processing** (periodicTaskGroup0/1) - Read boost pressure
2. **Control Loop** (periodicTaskGroup2) - Calculate turbo ratios, boost targets
3. **Protection Processing** (periodicTaskGroup6/16) - Evaluate protection conditions
4. **Output Processing** (periodicTaskGroup8/24) - Update PWM output

The main loop executes in 40 phases (0x00-0x27), with boost-related functions called every 2nd or 4th phase depending on the function.

---

## Protection Modes

| Mode | Value | Description |
|------|-------|-------------|
| Normal | 0 | Normal boost control |
| Limited | 1 | Reduced boost due to protection condition |
| Override | 2 | Fixed/safe boost level |

Protection activates when:
- `boost_deviation_exceeded` is set (actual vs target deviation too large)
- System enable flags indicate fault conditions
- Sensor errors detected

---

## Notes

1. This is an **open-loop** pressure control system - no direct position feedback
2. The wastegate solenoid is **normally closed** - 0% duty = max boost, 100% duty = min boost
3. The `CWG_PWM_Duty_Cycle_Invert` parameter can reverse this polarity
4. Boost is indirectly limited through fuel demand (AFC tables) as well as direct wastegate control
5. The HE351CW turbo on the 2004.5 Dodge 5.9L uses this wastegate control system
