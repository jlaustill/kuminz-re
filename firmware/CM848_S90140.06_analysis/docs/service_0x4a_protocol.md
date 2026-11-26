# CM848 Service 0x4A Memory Read Protocol

This document describes how to read memory from CM848 ECUs using Service 0x4A (CLIP Memory Read).

## Overview

Service 0x4A is a Cummins CLIP protocol command that reads arbitrary memory addresses from the ECU. This is useful for reading live sensor data (RPM, boost, temperatures) that isn't broadcast via J1939 PGNs.

## CAN Configuration

| Parameter | Value |
|-----------|-------|
| Bit Rate | 250 kbps |
| ECU Address | 0x00 |
| Tool Address | 0xF9 |
| Request PGN | 0xEF00 (Proprietary A) |
| Response PGN | 0xEF00 (Proprietary A) |

## CAN Arbitration IDs

| Direction | CAN ID | Formula |
|-----------|--------|---------|
| Tool → ECU | 0x18EF00F9 | 6<<26 \| 0xEF<<16 \| ECU(0x00)<<8 \| Tool(0xF9) |
| ECU → Tool | 0x18EFF900 | 6<<26 \| 0xEF<<16 \| Tool(0xF9)<<8 \| ECU(0x00) |

**J1939 PDU1 format (PF < 0xF0):**
- Bits [28:26] = Priority (6 → 0x18 in upper nibble)
- Bits [23:16] = PF (0xEF = Proprietary A)
- Bits [15:8] = PS (destination address)
- Bits [7:0] = SA (source address)

## Request Format (8 bytes)

```
Byte 0:    0x4A (Service ID - Memory Read)
Bytes 1-4: Address (32-bit, big-endian)
Byte 5:    Length (1-255 bytes)
Bytes 6-7: 0x00 (unused)
```

**Example:** Read 2 bytes from 0x0040B7BA (engine_speed_state.filtered_engine_speed, e2m 819B +2C Filtered_Engine_Speed):
```
4A 00 40 B7 BA 02 00 00
```

## Response Format

### Single-Frame Response (1-5 bytes requested)

```
Byte 0:    0x4B (Response Service ID)
Bytes 1-4: Address (echo of request)
Byte 5:    Length (echo of request)
Bytes 6-7: Data (for 1-2 byte reads)
```

**Example:** Response with RPM data:
```
4B 00 40 B7 BA 02 15 8F
```
Decode: 0x158F = 5519 raw × 0.125 = **689.9 RPM**

### Transport Protocol Response (6+ bytes requested)

For larger reads, the ECU responds using J1939 Transport Protocol:

1. **RTS (Request to Send)** from ECU on PGN 0xEC00
2. **CTS (Clear to Send)** from tool
3. **Data Transfer** frames on PGN 0xEB00
4. **EOM (End of Message)** from ECU

## Key Memory Addresses

### Engine Speed Variables

| Address | Variable | Scale | Units | Verified |
|---------|----------|-------|-------|----------|
| 0x0040B7BA | `engine_speed_state.filtered_engine_speed` | × 0.125 | RPM | ✓ |
| 0x0040B78E | `engine_rpm_derivative` | varies | RPM/s | |
| 0x0040B7AC | `target_engine_rpm` | × 0.125 | RPM | |

**Not engine speed (corrected 2026-11-14, PR #48):** 0x0040B882, listed here before as `engine_speed_raw` × 0.125 RPM, is `fuel_metering_command`. It's the 0-4095 command (= 0-100 % on-time of the fuel metering PWM on TPU-B channel 11, P0251) computed by `cm848_calculateFuelMeteringCommand`. Reading it live shows the fuel metering command, not RPM.

### Fuel Pressure / Radiator Fan (from the DRB SCI table, 2026-11-14)

The flash2 SCI table 253 (0x53a5ec) maps each DRB "FD" read to a RAM byte (FD n → entry n − 1). The labels come from the DRB database (`mydb` `v_transaction`). Scales other than the fan speed's aren't confirmed yet.

| Address | Variable | DRB read / label | Scale |
|---------|----------|------------------|-------|
| 0x0040B8B0 | `fuel_pressure_sensor` | FD-23-24 FUEL PRESSURE SENSOR | ? (DRB converts to kPa / psi) |
| 0x0040B8B6 | `fuel_pressure_setpoint` | FD-27-28 FUEL PRESS SETPOINT | ? |
| 0x0040B8AE | `fuel_pressure_sensor_volts` | FD-29-2A FUEL PRESSURE VOLTS | ? |
| 0x0040B882 | `fuel_metering_command` | FD-21-22 FUEL PRESS REG OUTPUT | 0-4095 = 0-100 % |
| 0x0040B2F4 | `radiator_fan_speed` | FD-80-81 RAD FAN SPEED | × 0.125 rpm |
| 0x0040C13A | `cooling_fan_duty_command` | FD-82-83 DES RAD FAN PWM | 1/256 % |
| 0x0040A064 | (unnamed) | FD-A0-A1 BAROMETRIC PRESSURE | DRB 0.0159 per count ("mmHg" in the DB; likely inHg) |
| 0x0040A070 / 0x0040A06E | (unnamed) / `ambient_air_temperature_sensor_channel_state` | FD-A4-A5 AMBIENT AIR TEMP DEG / FD-A6-A7 AMBIENT AIR TEMP V | DRB 0.0156 °C / 0.0049 V |
| 0x003FDF98 + 2n | `percent_time_at_load_cal`[n] | FD-84-85 ... FD-96-97 % OF TIME @ 0-10% ... 91-100% LOAD | 1/256 % (EEPROM mirror) |
| 0x0040B75E-63 | `cylinder_1/5/3/6/2/4_contribution_percent` | FD-E1 ... FD-E6 Cyl. #1 / 5 / 3 / 6 / 2 / 4 Contribution (firing order) | 1 % |
| 0x0040B765 | `cylinder_contribution_test_status` | FD-EB Cylinder test status | 0 / 1 / 2 |

**Verified Working (2026-01-31):**
- Request: `4A 00 40 B7 BA 02 00 00`
- Response: `4B 00 40 B7 BA 02 17 70` → 0x1770 = 6000 × 0.125 = **750 RPM** (idle)

### Boost/MAP Sensor

| Address | Variable | Scale | Units | Verified |
|---------|----------|-------|-------|----------|
| 0x0040BD8E | `boost_pressure_sensor_value` | × 0.0159 | IN_HG | ✓ |

**Verified Working (2026-01-31):**
- Request: `4A 00 40 BD 8E 02 00 00`
- Response: `4B 00 40 BD 8E 02 06 87` → 0x0687 = 1671 × 0.0159 = **26.6 IN_HG** (atmospheric)

### Temperature Sensors

| Address | Variable | Scale | Units | Verified |
|---------|----------|-------|-------|----------|
| 0x0040BAF4 | `coolant_temp_sensor` | TBD | °F | |
| 0x0040BAF6 | `intake_air_temp_sensor` | TBD | °F | |

### Pressure Sensors

| Address | Variable | Scale | Units | Verified |
|---------|----------|-------|-------|----------|
| 0x0040BAF2 | `oil_pressure_sensor` | TBD | PSI | |

### Throttle Position

| Address | Variable | Scale | Units | Verified |
|---------|----------|-------|-------|----------|
| 0x0040BD86 | `throttle_position_demand` | TBD | % | |
| 0x004002E8 | `throttle_position_input` | TBD | % | |

### Engine Operating Mode

| Address | Variable | Size |
|---------|----------|------|
| 0x0040B000 | `engine_operating_mode` | 2 bytes |
| 0x0040B008 | `fuel_control_mode_select` | 2 bytes |

### CBD (Cylinder Balance) Calibration

| Address | Variable | Notes |
|---------|----------|-------|
| 0x00408EE2 | CBD calibration block base | Column3=81AE |
| 0x00408EF6 | `cylinder_balance_enable_flag` | 1 byte, 0=disabled, 1=enabled |

## Example: Reading RPM for Translator

### Arduino/ESP32 Pseudocode

```cpp
// CAN frame for RPM read request
uint8_t request[8] = {
    0x4A,       // Service ID
    0x00, 0x40, 0xB7, 0xBA,  // Address: engine_speed_state.filtered_engine_speed
    0x02,       // Length: 2 bytes
    0x00, 0x00  // Unused
};

// Send on CAN ID 0x18EF00F9 (Tool→ECU)
can.send(0x18EF00F9, request, 8);

// Wait for response on CAN ID 0x18EFF900 (ECU→Tool)
if (can.receive(&response)) {
    if (response.data[0] == 0x4B) {  // Valid response
        uint16_t raw = (response.data[6] << 8) | response.data[7];
        float rpm = raw * 0.125;
    }
}
```

### Polling Rate

- Minimum recommended interval: 50ms between requests
- Higher rates may cause ECU to throttle responses

## Accessible Memory Ranges

Based on Service 0x4A probing, these ranges are readable:

| Range | Description |
|-------|-------------|
| 0x003F9800 - 0x003FFFFF | ROM-to-RAM region + runtime RAM (verified 2026-04-08) |
| 0x00408000 - 0x0040FFFF | RAM (calibration, runtime variables) |
| 0x01000000 - 0x01001FFF | EEPROM (8KB) |

**Updated 2026-04-08:** the 0x003Fxxxx range IS readable via Service 0x4A,
contrary to prior documentation. Bench-verified: 0x003FA000, 0x003FDD6C,
0x003FDD70, 0x003FDDA0, 0x003FDDA4, 0x003FEE12 all returned valid data.
This includes the ROM-to-RAM calibration copy region (0x3F9800-0x3FDB30)
and runtime RAM beyond it.

**Not accessible via Service 0x4A:** ROM (use Service 0x36 block read instead)

## Troubleshooting

| Symptom | Cause | Solution |
|---------|-------|----------|
| No response | ECU not powered or wrong CAN ID | Verify ECU power, check CAN bus |
| Response with zeros | Address not in accessible range | Use documented addresses |
| Intermittent responses | CAN bus timing issues | Add delay between requests |

## Related Documentation

- [Memory Address Mapping](memory-mappings/README.md) - Calterm to RAM address translation
- [CBD Enable Experiment](cbd_enable_experiment.md) - CBD parameter addresses
- [TASK_dump_bank2.md](TASK_dump_bank2.md) - ECU version information

## Verified on Hardware

- **ECU:** CM848D (2004.5 Dodge Ram 5.9L Cummins HPCR)
- **Firmware Version:** V11.46.06
- **Date:** 2026-01-31
