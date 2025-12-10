# Proposed Structure Definitions for CM550 ECU

This document proposes struct definitions based on analysis of contiguous address ranges
and functionally related variables in the global_variables.csv file.

## 1. GovernorState (0x00800088 - 0x008000A6)
**Size: 30 bytes**

```c
typedef struct {
    uint16_t rpm_reference;              // 0x00 - Governor current RPM reference
    uint32_t pid_integral;               // 0x02 - PID controller integral term (note: may have alignment padding)
    uint16_t pid_output;                 // 0x06 - PID controller output value
    uint16_t diagnostic_status_prev;     // 0x08 - Previous diagnostic status
    uint16_t final_fuel_command;         // 0x0A - Final fuel command output
    uint16_t reserved_0C;                // 0x0C - (gap)
    uint16_t reserved_0E;                // 0x0E - (gap)
    uint16_t reserved_10;                // 0x10 - (gap)
    uint16_t reserved_12;                // 0x12 - (gap)
    uint16_t reserved_14;                // 0x14 - (gap)
    uint16_t reserved_16;                // 0x16 - (gap)
    uint16_t reserved_18;                // 0x18 - (gap)
    uint16_t interpolation_factor;       // 0x1A - Interpolation factor
    uint16_t fuel_reference;             // 0x1C - Fuel reference for interpolation
} GovernorState;                         // Base: 0x00800088
```

## 2. FaultPersistenceCounters (0x008000C8 - 0x008000CF)
**Size: 8 bytes**

```c
typedef struct {
    uint8_t periodic_monitor_phase;      // 0x00 - 5-phase counter for periodic fault monitoring
    uint8_t can_pin_fault;               // 0x01 - CAN pin switching fault persistence
    uint8_t io_fault_1;                  // 0x02 - I/O control fault 1 persistence
    uint8_t io_fault_2;                  // 0x03 - I/O control fault 2 persistence
    uint8_t io_fault_3;                  // 0x04 - I/O control fault 3 persistence
    uint8_t io_fault_4;                  // 0x05 - I/O control fault 4 persistence
    uint8_t io_fault_5;                  // 0x06 - I/O control fault 5 persistence
    uint8_t io_fault_6;                  // 0x07 - I/O control fault 6 persistence
} FaultPersistenceCounters;              // Base: 0x008000C8
```

## 3. DerateState (0x008003E4 - 0x008003EE)
**Size: 12 bytes**

```c
typedef struct {
    uint16_t bit4_previous_state;        // 0x00 - Derate bit 4 previous state
    uint16_t bit4_changed_flag;          // 0x02 - Derate bit 4 changed flag
    uint16_t bit8_previous_state;        // 0x04 - Derate bit 8 previous state
    uint16_t bit8_changed_flag;          // 0x06 - Derate bit 8 changed flag
    uint16_t reference_value;            // 0x08 - Derate reference for change detection
    uint16_t value_changed_flag;         // 0x0A - Derate value changed flag
} DerateState;                           // Base: 0x008003E4
```

## 4. VP44FsoFaultState (0x0080348F - 0x008034C0)
**Size: 50 bytes (approximately)**

```c
typedef struct {
    uint8_t circuit_fault_flag;          // 0x00 - VP44 FSO circuit fault detected
    uint8_t reserved_01[16];             // 0x01-0x10 - gap
    uint8_t fault_active_flag;           // 0x11 - FSO fault active status
    uint8_t detection_enable;            // 0x12 - FSO circuit fault detection enable
    uint8_t reserved_13[14];             // 0x13-0x20 - gap
    uint16_t previous_value;             // 0x21 - FSO fault detection previous value
    uint16_t latched_value;              // 0x23 - FSO fault latched value when detected
    uint8_t reserved_25[3];              // 0x25-0x27 - gap
    uint8_t debounce_counter;            // 0x27 - FSO fault debounce counter
    uint8_t reserved_28[4];              // 0x28-0x2B - gap
    uint8_t range1_fault_counter;        // 0x2C - VP44 FSO range 1 fault counter
    uint8_t range2_fault_counter;        // 0x2D - VP44 FSO range 2 fault counter
    uint8_t recovery_counter;            // 0x2E - VP44 FSO fault recovery counter
    uint8_t bit1_range1_fault_counter;   // 0x2F - VP44 FSO bit1 range 1 fault counter
    uint8_t bit1_range2_fault_counter;   // 0x30 - VP44 FSO bit1 range 2 fault counter
    uint8_t bit1_recovery_counter;       // 0x31 - VP44 FSO bit1 fault recovery counter
} VP44FsoFaultState;                     // Base: 0x0080348F
```

## 5. FaultStatusRegisters (0x00805DF2 - 0x00805E02)
**Size: 16 bytes**

This is a critical struct - status registers for active faults.

```c
typedef struct {
    uint16_t sensor_fault_status;        // 0x00 - Sensor fault status register
    uint16_t fault_status_2;             // 0x02 - Fault status flags register 2
    uint16_t engine_fault_status;        // 0x04 - Engine fault status register
    uint16_t reserved_06;                // 0x06 - gap
    uint16_t io_fault_status_1;          // 0x08 - IO fault status register 1
    uint16_t io_fault_status_2;          // 0x0A - IO fault status register 2
    uint16_t io_fault_status_3;          // 0x0C - IO fault status register 3
    uint16_t io_fault_status_4;          // 0x0E - IO fault status register 4
} FaultStatusRegisters;                  // Base: 0x00805DF2
```

## 6. FaultLatchRegisters (0x00805E32 - 0x00805E42)
**Size: 16 bytes**

Mirrors FaultStatusRegisters - latched (historical) faults.

```c
typedef struct {
    uint16_t sensor_fault_latch;         // 0x00 - Sensor fault latch register
    uint16_t fault_status_8_previous;    // 0x02 - Previous state for edge detection
    uint16_t engine_fault_latch;         // 0x04 - Engine fault latch register
    uint16_t reserved_06;                // 0x06 - gap
    uint16_t io_fault_latch_1;           // 0x08 - IO fault latch register 1
    uint16_t io_fault_latch_2;           // 0x0A - IO fault latch register 2
    uint16_t io_fault_latch_3;           // 0x0C - IO fault latch register 3
    uint16_t io_fault_latch_4;           // 0x0E - IO fault latch register 4
} FaultLatchRegisters;                   // Base: 0x00805E32
```

## 7. VP44FaultRegisters (0x00805E14 - 0x00805E16 and 0x00805E54 - 0x00805E56)
**Size: 4 bytes each**

```c
typedef struct {
    uint16_t vp44_fault_status;          // 0x00 - VP44 fault status register
    uint16_t vp44_fso_fault_status_2;    // 0x02 - VP44 FSO fault status 2
} VP44FaultStatusRegs;                   // Base: 0x00805E14

typedef struct {
    uint16_t vp44_fault_latch;           // 0x00 - VP44 fault latch register
    uint16_t vp44_fso_fault_latched_2;   // 0x02 - VP44 FSO fault latched 2
} VP44FaultLatchRegs;                    // Base: 0x00805E54
```

## 8. ADSensorFaultConfig (18 bytes each, repeating pattern)
**Base addresses: 0x00806AE2, 0x00806AFA, 0x00806B12, etc.**

```c
typedef struct {
    uint16_t global_default_value;       // 0x00 - Global default value
    uint16_t fault_clear_counts;         // 0x02 - A/D fault clear counts
    uint16_t fault_decrement;            // 0x04 - A/D fault decrement
    uint16_t fault_increment;            // 0x06 - A/D fault increment
    uint16_t fault_set;                  // 0x08 - A/D fault set threshold
    uint16_t reserved_0A;                // 0x0A - Padding/gap to next struct
    uint16_t reserved_0C;                // 0x0C - Padding
    uint16_t reserved_0E;                // 0x0E - Padding
    uint16_t reserved_10;                // 0x10 - Padding
} ADSensorFaultConfig;                   // Size: 18 bytes
```

**Instances:**
- `ADSensorFaultConfig intake_manifold_temp_config;`  // 0x00806AE2
- `ADSensorFaultConfig fuel_temp_config;`             // 0x00806AFA
- `ADSensorFaultConfig coolant_level_config;`         // 0x00806B12
- `ADSensorFaultConfig generic_sensor_config;`        // 0x00806B2A
- `ADSensorFaultConfig oil_pressure_config;`          // 0x00806B42
- `ADSensorFaultConfig boost_pressure_config;`        // 0x00806B5C
- `ADSensorFaultConfig coolant_temp_config;`          // 0x00806B72

## 9. HighRpmProtectionState (0x0080CC6A - 0x0080CC72)
**Size: 10 bytes**

```c
typedef struct {
    uint16_t fault_flag;                 // 0x00 - High RPM protection fault active
    uint16_t state;                      // 0x02 - State machine state
    uint16_t timer;                      // 0x04 - Countdown timer
    uint16_t reserved_06;                // 0x06 - gap
    uint16_t warning_flag;               // 0x08 - Warning active flag
} HighRpmProtectionState;                // Base: 0x0080CC6A
```

## 10. EngineOperatingModeState (0x0080C810 - 0x0080C812)
**Size: 4 bytes**

```c
typedef struct {
    uint16_t state;                      // 0x00 - Engine operating mode state (1-8)
    uint16_t shutdown_complete_flag;     // 0x02 - Engine shutdown complete flag
} EngineOperatingModeState;              // Base: 0x0080C810
```

## 11. FuelDemandControl (0x0080C9A4 - 0x0080C9B2)
**Size: 16 bytes**

```c
typedef struct {
    uint16_t demand_command;             // 0x00 - Current fuel demand value
    uint8_t  source_identifier;          // 0x02 - Source of fuel command (FUEL_SOURCE_ID enum)
    uint8_t  reserved_03;                // 0x03 - padding
    uint16_t diagnostic_param_buffer;    // 0x04 - Diagnostic parameter buffer
    uint16_t timing_blend_factor;        // 0x06 - Fuel timing blend factor 0-16384
    uint16_t table_output;               // 0x08 - Fuel demand table output
    uint16_t limit_minimum;              // 0x0A - Fuel limit minimum value
    uint16_t demand_source_id;           // 0x0C - Fuel demand source identifier
    uint16_t adjustment_active_flag;     // 0x0E - Fuel adjustment active flag
} FuelDemandControl;                     // Base: 0x0080C9A4
```

## 12. FuelLimitArbitration (0x0080CC4A - 0x0080CC5A)
**Size: 18 bytes**

```c
typedef struct {
    uint16_t source_id;                  // 0x00 - ID of current fuel limit source
    uint16_t demand_limited;             // 0x02 - Rate-limited fuel demand
    uint16_t arbitration_threshold;      // 0x04 - Arbitration threshold
    uint16_t demand_delta;               // 0x06 - Fuel demand delta
    uint16_t maximum_limit;              // 0x08 - Maximum fuel demand limit
    uint16_t offset_value;               // 0x0A - Fuel limit offset
    uint16_t comparison_low;             // 0x0C - Fuel limit comparison low
    uint16_t comparison_high;            // 0x0E - Fuel limit comparison high
    uint16_t rate_limit;                 // 0x10 - Fuel demand rate limiting
} FuelLimitArbitration;                  // Base: 0x0080CC4A
```

## 13. BoostPressureControl (0x00809746 - 0x0080974A)
**Size: 6 bytes**

```c
typedef struct {
    uint16_t state_machine;              // 0x00 - Boost pressure state machine state
    uint16_t active_flag;                // 0x02 - Boost pressure calculation active
    uint16_t interpolation_result;       // 0x04 - Boost pressure interpolation result
} BoostPressureControl;                  // Base: 0x00809746
```

## 14. FuelTempProtection (0x008096FE - 0x0080971E)
**Size: 34 bytes**

```c
typedef struct {
    uint16_t validation_active_flag;     // 0x00 - Fuel temp validation active
    uint16_t limit_state_1;              // 0x02 - Fuel temp limit state 1
    uint16_t limit_state_2;              // 0x04 - Fuel temp limit state 2
    uint16_t reserved_06;                // 0x06 - gap
    uint16_t limit_primary;              // 0x08 - Primary output
    uint16_t limit_secondary;            // 0x0A - Secondary output
    uint16_t limit_output;               // 0x0C - Final output
    uint16_t reserved_0E;                // 0x0E - gap
    uint16_t timer_1;                    // 0x10 - Timer 1
    uint16_t timer_2;                    // 0x12 - Timer 2
    uint16_t reserved_14[3];             // 0x14-0x18 - gaps
    uint16_t timer_3;                    // 0x1A - Timer 3
    uint16_t protection_current;         // 0x1C - Current value
    uint16_t calculated_limit;           // 0x1E - Calculated limit
    uint16_t limit_delta;                // 0x20 - Delta value
} FuelTempProtection;                    // Base: 0x008096FE
```

## 15. RpmCalculationState (0x0080C750 - 0x0080C78A)
**Size: ~60 bytes**

```c
typedef struct {
    uint32_t period_accumulator;         // 0x00 - RPM period accumulator
    uint16_t reserved_04;                // 0x04 - gap
    uint16_t reserved_06;                // 0x06 - gap
    uint16_t sample_count;               // 0x08 - Count of RPM samples
    uint16_t reserved_0A;                // 0x0A - gap
    uint32_t tpu_timer_capture;          // 0x0C - TPU timer capture value
    // ... additional fields with gaps
    uint16_t limit_1;                    // 0x22 - RPM-based limit 1
    uint16_t limit_2;                    // 0x24 - RPM-based limit 2
    uint16_t scaling_divisor_mode_0;     // 0x26 - RPM scaling divisor mode 0
    uint16_t reserved_28;                // 0x28 - gap
    uint16_t scaling_divisor_mode_1;     // 0x2A - RPM scaling divisor mode 1
    uint16_t reserved_2C;                // 0x2C - gap
    uint32_t filter_buffer_end;          // 0x2E - End pointer for RPM filter buffer
    uint16_t reserved_32[2];             // 0x32-0x34 - gaps
    uint32_t filter_read_ptr;            // 0x36 - RPM filter circular buffer read pointer
} RpmCalculationState;                   // Base: 0x0080C750
```

## 16. TimingModeControl (0x0080965A - 0x0080967C)
**Size: 36 bytes**

```c
typedef struct {
    uint16_t blend_factor;               // 0x00 - Fuel timing mode blend factor Q14
    uint16_t protection_blend_ramp;      // 0x02 - Timing protection blend ramp 0-16384
    uint16_t source_selector;            // 0x04 - Timing mode source selector 0-4
    uint16_t transition_result;          // 0x06 - Timing mode transition result
    uint16_t fuel_blend_result;          // 0x08 - Timing fuel blend result
    uint16_t oil_pressure_result;        // 0x0A - Timing oil pressure condition
    uint16_t mode_11_result;             // 0x0C - Timing mode 11 countdown result
    uint16_t protection_counter_1;       // 0x0E - Timing protection counter 1
    uint16_t protection_counter_2;       // 0x10 - Timing protection counter 2
    uint16_t blend_state;                // 0x12 - Timing blend state
    uint16_t reserved_14[2];             // 0x14-0x16 - gaps
    uint16_t blend_accumulator;          // 0x18 - Timing blend accumulator
    uint16_t reserved_1A;                // 0x1A - gap
    uint16_t fuel_source_mode_11_state;  // 0x1C - Fuel source mode 11 state
    uint16_t fuel_source_mode_11_timer;  // 0x1E - Fuel source mode 11 timer
    uint16_t fuel_mode_transition_state; // 0x20 - Fuel mode transition state
    uint16_t fuel_mode_transition_timer; // 0x22 - Fuel mode transition timer
} TimingModeControl;                     // Base: 0x0080965A
```

## 17. RPMThresholds (0x00807D5E - 0x00807D62)
**Size: 6 bytes**

```c
typedef struct {
    uint16_t overspeed_entry;            // 0x00 - Engine RPM overspeed entry threshold
    uint16_t overspeed_exit;             // 0x02 - Engine RPM overspeed exit threshold
    uint16_t overspeed_counter_limit;    // 0x04 - Engine overspeed counter timeout
} RPMThresholds;                         // Base: 0x00807D5E
```

## Implementation Notes

1. **Alignment**: The M68000/68336 processor requires word (16-bit) and long (32-bit)
   alignment. All structs should maintain proper alignment.

2. **Byte Order**: M68000 is big-endian. Ghidra should handle this automatically.

3. **Struct Application Strategy**:
   - Start with the smallest, most clearly defined structs
   - Apply FaultStatusRegisters and FaultLatchRegisters first (high confidence)
   - Apply HighRpmProtectionState and EngineOperatingModeState next
   - Progress to larger, more complex structs

4. **Expected Benefits**:
   - Fixes overlapping symbol issues in decompiler
   - Groups related variables logically
   - Improves code readability significantly
   - Makes function signatures more meaningful

5. **Testing Approach**:
   - After applying each struct, verify decompiler output
   - Check that symbol names appear correctly (no `_DAT_` prefix)
   - Verify structure member access looks correct (e.g., `struct->field`)
