# Design: EF00 Services 0x43/0x46 for Parameter-by-ID Reads

## Problem

kuminz-cli can read ECU memory by raw address (Service 0x4A), but cannot read by parameter ID. The firmware has a built-in parameter lookup table (723 entries on CM550, 20 on CM848) that maps parameter IDs to RAM/EEPROM/ROM addresses. Services 0x43 and 0x46 expose this lookup to diagnostic tools without requiring a CLIP session.

## Approach

Add EF00 direct services 0x43 and 0x46 alongside the existing 0x4A, following the same sessionless pattern. Raw hex dump of responses (format unverified until live test).

## Protocol Details

### Service 0x46: Read by Parameter ID

Request (8 bytes, PGN 0xEF00):
```
[0x46][ParamID_HI][ParamID_LO][0x00][0x00][0x00][0x00][0x00]
```

Response: Unknown format. ECU calls `diagnosticMemoryAddressResolver(paramId)` internally, reads the data at the resolved address, and sends back a response. Expected to be single-frame on PGN 0xEF00 or J1939 TP for larger data.

### Service 0x43: Read by Parameter ID + Offset

Request (7-8 bytes, PGN 0xEF00):
```
[0x43][ParamID_HI][ParamID_LO][Offset_3][Offset_2][Offset_1][Offset_0]
```

Response: Similar to 0x46. Reads from `resolved_address + offset`.

### Known Parameter ID Ranges (CM550)

| Range | Count | Description |
|-------|-------|-------------|
| 0x0000-0x002E | 35 | System params (EEPROM, ROM, status) |
| 0x1000-0x1478 | 577 | CLIP calibration params (RAM, EEPROM) |
| 0x8000-0x8265 | 111 | Extended params (RAM) |
| **Total** | **723** | |

## Changes

### clip-core/include/clip/ECUReader.h

Add two methods:
```cpp
bool readParameterService46(uint16_t paramId, std::vector<uint8_t>& data, int timeoutMs = 5000);
bool readParameterService43(uint16_t paramId, uint32_t offset, std::vector<uint8_t>& data, int timeoutMs = 5000);
```

### clip-core/src/ECUReader.cpp

Implement both methods following the `readMemoryService4A()` pattern:
1. Build request bytes
2. Send on PGN 0xEF00
3. Wait for response (single-frame or J1939 TP)
4. Return raw response bytes (no parsing, format unknown)

### kuminz-cli/src/main.cpp

Add CLI flags:
```
--read-param <id>              Read parameter by ID (hex, Service 0x46)
--read-param-offset <id> <off> Read param+offset (hex, Service 0x43)
```

Output: raw hex dump of response bytes for initial format discovery.

## Testing

1. Build clip-core and kuminz-cli
2. Test with known parameter IDs from the lookup table:
   - `--read-param 0004` (hour_meter_ecm_run_time_none, RAM 0x0080BDA4)
   - `--read-param 1000` (EEPROM 0x0100008E)
   - `--read-param 0002` (ROM 0x00000010)
3. Compare raw response bytes to understand the response format
4. Once format is known, add proper response parsing in a follow-up

## Future Work

- Parse response format once discovered from live testing
- Add CLIP session mode (Services 0x10/0x16) for batch parameter reads
- Build named parameter dashboard combining lookup table with live reads
