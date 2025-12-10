# CM550 ADC Sensor System Architecture

## Overview

The CM550 ECU uses a sophisticated ADC (Analog-to-Digital Converter) sensor system that processes up to 25 analog sensors. Each sensor reading goes through filtering, fault detection, and linearization before being used by the engine control algorithms.

## Memory Layout

### Three Primary Buffer Types

| Buffer Type | Base Address | Entry Size | Purpose |
|-------------|--------------|------------|---------|
| Config Table | 0x8068EA | 24 bytes | Sensor configuration parameters (fault thresholds, error codes, etc.) |
| Runtime Buffer | 0x8091E2 | 22 bytes | Runtime state (filter state, fault counters, debounce) |
| Output Buffer | 0x80A2B2 | 22 bytes | Final sensor values (filtered, unfiltered, raw) |

### Address Calculation

For any sensor index `N`:
```
Config address  = 0x8068EA + (N * 24)
Runtime address = 0x8091E2 + (N * 22)
Output address  = 0x80A2B2 + (N * 22)
```

## Table Interpolation Args Array

The linearization table pointers are stored in a separate array at **0x809526**.

### Structure: `table_interp_args_t` (12 bytes)

| Offset | Size | Field | Description |
|--------|------|-------|-------------|
| +0x00 | 2 | config_value | Configuration flags (always 2) |
| +0x02 | 4 | x_axis_ptr | Pointer to X-axis (input) lookup table |
| +0x06 | 2 | input_value | Current input value for interpolation |
| +0x08 | 4 | y_axis_ptr | Pointer to Y-axis (output) lookup table |

### Address Calculation

For sensor index `N`:
```
Args base = 0x809526 + (N * 12)
X-axis pointer stored at: Args base + 2
Y-axis pointer stored at: Args base + 8
```

## Sensor Output Structure

Each sensor's 22-byte output buffer contains:

| Offset | Size | Field | Description |
|--------|------|-------|-------------|
| +0x00 | 4 | config_ptr | Pointer to config table entry |
| +0x04 | 4 | filter_state | Digital filter accumulator |
| +0x08 | 2 | interpolated_value | Final filtered & linearized value |
| +0x0A | 2 | lookup_result | Table interpolation result |
| +0x0C | 2 | fault_counter | Fault detection counter |
| +0x0E | 1 | fault_flag | Active fault indicator |
| +0x0F | 1 | sample_counter | Sample period counter |
| +0x10 | 2 | adc_raw_value | Raw ADC reading (0-1023) |
| +0x12 | 4 | reserved | Reserved/padding |

## Key Functions

### `initADCChannelConfiguration` (0x0000AC1C)

Initializes the sensor system at boot:
1. Sets up table pointers in the args array (0x809526)
2. Initializes runtime buffers
3. Checks fault flags and sets default values

### `sensorFaultDebounceMonitor` (0x0000A6FA)

Main sensor processing loop, called periodically:
1. Iterates through sensors 0-24
2. Reads raw ADC value from hardware
3. Checks high/low fault thresholds
4. Calls `lookupTableInterpolation()` for X-Y linearization
5. Calls `coreTableInterpolation()` for filtering
6. Updates fault flags and output values

### `lookupTableInterpolation` (0x000356A0)

Performs piecewise linear interpolation:
- Input: `table_interp_args_t*` with table pointers and input value
- Searches X-axis table to find bracketing entries
- Interpolates corresponding Y-axis values
- Returns linearized output

### `coreTableInterpolation` (0x000356F8)

Applies digital filtering to interpolated values:
- Uses filter constant from sensor config
- Maintains filter state in runtime buffer
- Produces final smoothed output

## Linearization Table Format

Tables are stored as arrays of 16-bit words in the firmware_tables region (RAM 0x8062D2+, Flash 0x37EAE+).

### X-Axis Table (Input)
- Contains ADC count values (0-1023 range)
- Entries in ascending order
- First entry is table size (number of data entries)

### Y-Axis Table (Output)
- Contains engineering unit values
- Same number of entries as X-axis
- Units depend on sensor type (DEGF, INHG, PSIG, etc.)

### Flash Address Calculation

```
flash_address = ram_address - 0x8062D2 + 0x37EAE
```

## Known Sensor Mappings

| Index | Sensor Name | CalTerm | Output Address |
|-------|-------------|---------|----------------|
| 0 | Intake Manifold Temp | ADIMTP | 0x80A2B2 |
| 1 | Fuel Temperature | ADFLTP | 0x80A2C8 |
| 2 | Coolant Level | ADCV | 0x80A2DE |
| 3 | Fuel Pressure | ADSYFP | 0x80A2F4 |
| 4 | Oil Pressure | ADOLPR | 0x80A30A |
| 5 | **Boost Pressure** | ADBSPR | 0x80A320 |
| 6 | Coolant Temperature | ADCLTP | 0x80A336 |
| 11 | Remote Throttle | ADRTH | 0x80A3A4 |
| 12 | Ambient Air Pressure | ADAAP | 0x80A3BA |
| 13 | Battery Voltage | ADBATV | 0x80A3D0 |

See `sensor_linearization_tables.csv` for complete mapping.

## Important Discovery: Boost Pressure Tables

The boost pressure linearization tables were incorrectly labeled in the original analysis. Through code tracing:

- **Sensor Index**: 5
- **X-axis (ADBSPRXA)**: RAM 0x806C4A, Flash 0x038826, 5 entries
- **Y-axis (ADBSPRYA)**: RAM 0x806C54, Flash 0x038830, 5 entries
- **Output (ADFTBSPR)**: 0x80A320

Previously these addresses were mislabeled as ADTHSV (throttle SV) parameters.

## Numbering Schemes

**CRITICAL**: There are two different numbering schemes that DO NOT MATCH:

### 1. Sensor Index (0-24)
Used in runtime/output buffers and `table_interp_args_t` array:
- Determined by position in `sensorFaultDebounceMonitor` processing loop
- Used to calculate buffer addresses
- **This is what the code actually uses**

### 2. ADC Channel (0-25)
Used in `initADCChannelConfiguration` variable names:
- May not match sensor index
- The channel numbers in the decompiled code (e.g., `adc_channel_5_filter_ptr`)
  correspond to the args array offset, NOT the physical sensor
- **Do not assume channel X = sensor X**

### Example of the Mismatch
- Sensor index 5 = Boost Pressure (output at 0x80A320)
- But `adc_channel_5_filter_ptr` in the decompiler points to a different sensor's config
- The table pointers at args offset 0x3C-0x44 (sensor 5) point to 0x806C4A/0x806C54

### Recommendation
Always verify sensor identity by:
1. Checking the output buffer address against known CalTerm labels
2. Tracing the actual table pointer values from disassembly
3. Cross-referencing with `sensor_linearization_tables.csv`

## Data Flow

```
                    +------------------+
                    |  ADC Hardware    |
                    |  (0xFFF2B0+)     |
                    +--------+---------+
                             |
                             v
                    +------------------+
                    | Raw ADC Reading  |
                    | (10-bit, 0-1023) |
                    +--------+---------+
                             |
              +--------------+--------------+
              |                             |
              v                             v
     +----------------+            +------------------+
     | Fault Check    |            | Table Lookup     |
     | (High/Low)     |            | (X-Y Interp)     |
     +-------+--------+            +--------+---------+
             |                              |
             v                              v
     +----------------+            +------------------+
     | Fault Counter  |            | Linearized Value |
     | & Flags        |            | (Eng. Units)     |
     +----------------+            +--------+---------+
                                            |
                                            v
                                   +------------------+
                                   | Digital Filter   |
                                   | (IIR/Exponential)|
                                   +--------+---------+
                                            |
                                            v
                                   +------------------+
                                   | Final Output     |
                                   | (ADFT* values)   |
                                   +------------------+
```

## References

- `sensor_linearization_tables.csv` - Complete sensor-to-table mapping
- `global_variables.csv` - RAM address labels
- `flash_to_ram_mappings.csv` - Boot-time copy operations
- `structure_definitions.csv` - Related structure definitions
