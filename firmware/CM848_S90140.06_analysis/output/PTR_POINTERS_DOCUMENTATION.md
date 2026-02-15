# CM848 Bank 2 PTR_ Pointer Documentation

This document catalogs the 221 PTR_* global variables found in the CM848 firmware,
organized by their functional purpose.

## J1939 Handler Table

**Location:** ROM 0x00539508-0x00539600  
**Structure:** 19 entries × 6 bytes each (command byte + 4-byte pointer + padding)  
**Purpose:** Dispatches J1939 messages by PGN to appropriate handlers

| Entry | Command | Address | Handler Function | PGN/Service |
|-------|---------|---------|------------------|-------------|
| 0 | 0x00 | 0x00022674 | j1939_handle_pgn_65226_dm1_active_dtc | PGN 65226 DM1 Active DTC |
| 1 | 0x01 | 0x000227a0 | j1939HandleDm1RequestMessage | DM1 request handler |
| 2 | 0x02 | 0x00023e8c | j1939_handle_pgn_65269_ambient_conditions | PGN 65269 Ambient Conditions |
| 3 | 0x03 | 0x00024178 | j1939_handle_pgn_65265_cruise_vehicle_speed | PGN 65265 Cruise/Vehicle Speed |
| 4 | 0x04 | 0x000246fc | j1939_handle_pgn_65261_cruise_control_setup | PGN 65261 Cruise Control Setup |
| 5 | 0x05 | 0x00024870 | j1939_handle_pgn_65259_component_id | PGN 65259 Component ID |
| 6 | 0x06 | 0x00024b28 | j1939_handle_pgn_65234_dm11_clear_active | PGN 65234 DM11 Clear Active |
| 7 | 0x07 | 0x00024be8 | j1939_handle_pgn_65226_dm1_active_dtc | PGN 65226 DM1 Active DTC |
| 8 | 0x08 | 0x00024e78 | j1939_handle_pgn_65227_dm2_previous_dtc | PGN 65227 DM2 Previous DTC |
| 9 | 0x09 | 0x00025390 | j1939_handle_pgn_65229_dm4_freeze_frame | PGN 65229 DM4 Freeze Frame |
| 10 | 0x0A | 0x00025458 | j1939_handle_pgn_65230_dm5_readiness | PGN 65230 DM5 Readiness |
| 11 | 0x0B | 0x00025b10 | j1939_handle_pgn_61443_eec2 | PGN 61443 EEC2 |
| 12 | 0x0C | 0x00025eb4 | j1939_handle_pgn_65263_fluid_level_pressure | PGN 65263 Fluid Level/Pressure |
| 13 | 0x0D | 0x00026024 | j1939_handle_pgn_65262_engine_temp | PGN 65262 Engine Temperature |
| 14 | 0x0E | 0x000264d8 | j1939_handle_pgn_65270_inlet_exhaust_conditions | PGN 65270 Inlet/Exhaust |
| 15 | 0x0F | 0x00026884 | j1939_handle_pgn_65242_software_id | PGN 65242 Software ID |
| 16 | 0x10 | 0x000269f4 | j1939_handle_pgn_65504_proprietary_a | PGN 65504 Proprietary A |
| 17 | 0x11 | 0x00026bb0 | j1939_handle_pgn_65248_vehicle_distance | PGN 65248 Vehicle Distance |
| 18 | 0x12 | 0x00026cf0 | j1939_handle_pgn_65271_vehicle_electrical | PGN 65271 Vehicle Electrical |
| 19 | 0x13 | 0x00026db4 | j1939_handle_pgn_65260_vehicle_id | PGN 65260 Vehicle ID |
| 20 | 0x14 | 0x0002bd58 | j1939_handle_pgn_65264_pto | PGN 65264 PTO |

**Usage:** `dispatchByCommandCode()` iterates through this table comparing `*command_buffer_pointer` against the command byte.

---

## J1939 Callback Pointers (RAM)

**Location:** RAM 0x003FA000-0x0040C000

| Address | Variable Name | Handler | Purpose | Assignment Function |
|---------|---------------|---------|---------|---------------------|
| 0x003FA9AA | PTR_j1939_handle_pgn_61443_eec2_003fa9aa | j1939_handle_pgn_61443_eec2 | EEC2 message handler | initJ1939MessageTables |
| 0x003FB372 | PTR_j1939PeriodicTimerCallback_003fb372 | j1939PeriodicTimerCallback | Periodic timer callback | initJ1939PeriodicConfig |
| 0x003FB8E8 | PTR_j1939ProtectionDataResponse_003fb8e8 | j1939ProtectionDataResponse | Protection response | protectionConditionMonitor |
| 0x0040B37F | PTR_j1939MessageResponseCallback_0040b37f | j1939MessageResponseCallback | Message response | initJ1939TransmitSchedule |

**Note:** PTR_j1939ProtectionDataResponse_003fb8e8 is reassigned dynamically based on protection state:
- j1939ProtectionConfigResponse - normal operation
- protectionConfigSelector - configuration mode
- validateSensorData - sensor validation

---

## Periodic Task Calibration Pointers

**Location:** RAM 0x003FB000-0x00406000

| Address | Variable Name | Value | Purpose |
|---------|---------------|-------|---------|
| 0x003FB6B3 | PTR_periodicTaskGroup21_calibration_003fb6b3 | 0x00 | Task group 21 (active) |
| 0x00405110 | PTR_periodicTaskGroup21_calibration_00405110 | 0x00 | Task group 21 (inactive) |

**Usage:** These pointers are used in turbo compensation calculations and are set to 0 when tasks are inactive.

---

## Wastegate Filter Parameters

**Location:** RAM 0x003FA600-0x003FA640

| Address | Variable Name | Type | Purpose |
|---------|---------------|------|---------|
| 0x003FA624 | PTR_wastegate_filter_params_003fa624 | &wastegate_filter | First-order filter gain |
| 0x003FA62C | PTR_wastegate_filter_params_003fa62c | &wastegate_filter | Filter output |

**Usage:** `signedFirstOrderFilter()` uses these pointers in the boost control algorithm.

---

## Sensor Raw Data Pointers

**Location:** RAM 0x0040A000-0x0040B000

| Address | Variable Name | Type | Purpose |
|---------|---------------|------|---------|
| 0x0040A8D3 | PTR_sensor_raw_ch7_0040a8d3 | &sensor_raw | Channel 7 raw sensor data |

---

## Function Pointers (ROM)

**Location:** ROM 0x00000000-0x00540000

| Address | Variable Name | Function | Purpose |
|---------|---------------|----------|---------|
| 0x00007F80 | PTR_FUN_00007f80 | ? | Boot/initialization |
| 0x000582DE | PTR_FUN_000582de | ? | ? |
| 0x003FD2C8 | PTR_FUN_003fd2c8 | ? | ? |
| 0x00539510 | PTR_FUN_00539510 | ? | Command handler table entry 0 |
| 0x0053AD4E | PTR_FUN_0053ad4e | ? | Bank 2 function |

---

## RAM Table Pointers (170 entries)

**Location:** RAM 0x003FA000-0x003FB000

The majority of PTR_ variables (170 entries) are in the RAM region 0x003FA000-0x003FB000,
organized into tables for:
- Sensor channel data (0x003FA000-0x003FA200)
- Filter parameters (0x003FA600-0x003FA800)
- J1939 communication state (0x003FB000-0x003FB500)
- Protection system state (0x003FB800-0x003FBC00)

**Pattern:** Each table has 2-byte offset entries pointing to 4-byte aligned data structures.

---

## Summary Statistics

| Category | Count |
|----------|-------|
| J1939 PGN Handlers | 21 |
| J1939 Callback Pointers | 4 |
| Periodic Task Pointers | 2 |
| Wastegate Filter Pointers | 2 |
| Sensor Raw Pointers | 1 |
| Function Pointers (ROM) | 5 |
| RAM Table Pointers | 170 |
| **Total** | **221** |
