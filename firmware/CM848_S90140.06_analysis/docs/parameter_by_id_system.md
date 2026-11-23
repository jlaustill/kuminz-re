# CM848 Parameter-by-ID System

This document describes the parameter-by-ID lookup system in the CM848 firmware, reverse engineered from ROM analysis.

## Corrections (2026-11-23, PR #53 round 63)

The rest of this page predates these findings. Where it disagrees, these hold:

- **Two kernels and two tables.** The 20-entry table at ROM 0x3CDC (`boot_parameter_id_table`) and the handlers at
  0x19E8 / 0x1D5C belong to the boot kernel, which dispatches through `cm848_dispatchDiagnosticService`.
  - The application dispatcher `cm848_j1939DiagnosticServiceHandler` (0x22128) never reaches them.
  - Its service 0x41 is `cm848_handleJ1939GetAddressByParameterIdService` (0x50C318). Its ID lookup is
    `cm848_lookupParameterIdAddress` (0x539768) over the 1886-record table at flash2 0x53BE38, described in
    `firmware/CLAUDE.md`. So CM848 has far more than 20 parameter IDs.
- **Service 0x43's bytes 3-6 are the length, not an offset**, in both kernels.
  - The read starts at the resolved address.
  - A read under 256 bytes answers with 0x44 and copies byte 6 (the length's low byte) into the 1-byte length slot.
  - The services with an offset are 0x46 (2-byte offset, 1-byte length) and 0x48 (4-byte offset, 4-byte length).
- **Service 0x46 is registered** by the application (`cm848_registerJ1939MemoryReadServices`). The boot kernel does
  not register it.
- **0x10 and 0x15 are not stubs of one kind.** 0x0F / 0x10 are accepted no-ops (they return 0). 0x15 commits the
  EEPROM mirror (`cm848_commitEepromMirrorToEeprom`).
- **The service IDs** are the `J1939_DIAGNOSTIC_SERVICE` enum (was `EF00_SERVICE_ID`) in `output/enums.csv`. Its
  header lists the reply pairs and the boot kernel's own table.
- **Open:** clip-core's `ECUReader::readParameterService43` sends bytes 3-6 as an offset. On CM848 that asks for a
  length, so it needs a bench check (task 046 leads).

## Overview

The CM848 provides a simple parameter lookup mechanism via EF00 services 0x41 and 0x43. Unlike CM550 which has 723 parameter IDs, CM848 has only **20 parameter entries** - this is by design, not an extraction bug.

## Architecture

```
EF00 Service Request (0x41 or 0x43)
            │
            ▼
┌─────────────────────────────┐
│  j1939DiagnosticServiceHandler  │
│  @ 0x00022128                    │
│  Dispatches via ef00_dispatch_table │
└─────────────────────────────┘
            │
            ├──── Service 0x41 ────▶ diagService65_handler @ 0x19E8
            │                        Returns resolved address
            │
            └──── Service 0x43 ────▶ diagService67_memoryReadOffset @ 0x1D5C
                                     Reads data at resolved address + offset
            │
            ▼
┌─────────────────────────────┐
│  lookupTableEntryByKey      │
│  ROM @ 0x00003F70           │
│  RAM @ 0x003F9B40 (copy)    │
│  Linear search through table │
└─────────────────────────────┘
            │
            ▼
┌─────────────────────────────┐
│  param_id_lookup_table      │
│  ROM @ 0x00003CDC           │
│  RAM @ 0x003F98AC (copy)    │
│  20 entries × 6 bytes       │
└─────────────────────────────┘
```

## Lookup Function

### `lookupTableEntryByKey` (ROM 0x3F70 → RAM 0x3F9B40)

```c
uint32_t lookupTableEntryByKey(uint16_t param_id) {
    uint16_t *entry = (uint16_t *)0x003F98AC;  // Table start in RAM

    // Linear search through sorted table (20 entries max)
    while (*entry < param_id && entry < (uint16_t *)0x003F9924) {
        entry += 3;  // Each entry is 6 bytes (3 × uint16_t)
    }

    if (*entry == param_id) {
        return *(uint32_t *)(entry + 1);  // Return 4-byte address
    }
    return 0;  // Not found
}
```

## Parameter Lookup Table

### Location
- **ROM**: 0x00003CDC (source, read-only)
- **RAM**: 0x003F98AC (copied at boot by `copyCalibrationToRam`)

### Entry Format (6 bytes)
```c
typedef struct {
    uint16_t param_id;   // Parameter ID (0x0000-0x12A9)
    uint32_t address;    // Resolved memory address
} param_id_entry_t;
```

### Table Contents (20 entries)

| Param ID | Address | Region | Variable/Purpose |
|----------|---------|--------|------------------|
| 0x0000 | 0x01000036 | EEPROM | |
| 0x0002 | 0x0000010C | ROM | Build date/version |
| 0x0003 | 0x01000080 | EEPROM | |
| 0x0004 | 0x00302012 | MPC555 | qadc_a_portqb (ADC port) |
| 0x0005 | 0x01000002 | EEPROM | |
| 0x000B | 0x01000000 | EEPROM | Calibration status indicator |
| 0x000C | 0x0030252E | MPC555 | |
| 0x000D | 0x00302738 | MPC555 | |
| 0x000E | 0x00302002 | MPC555 | qadc_a_mcr (ADC control reg) |
| 0x0010 | 0x00302736 | MPC555 | |
| 0x0012 | 0x01000090 | EEPROM | Tool compatibility version |
| 0x0013 | 0x00302894 | MPC555 | |
| 0x0015 | 0x00302898 | MPC555 | |
| 0x0018 | 0x0030287C | MPC555 | qadc_a_result_ch4 |
| 0x0019 | 0x0100003A | EEPROM | |
| 0x0045 | 0x00000112 | ROM | |
| 0x0048 | 0x0100003A | EEPROM | (same as 0x0019) |
| 0x1000 | 0x0100008E | EEPROM | Calibration parameter |
| 0x12A3 | 0x00000116 | ROM | |
| 0x12A9 | 0x00000108 | ROM | |

### Address Distribution
- **EEPROM** (0x01xxxxxx): 8 entries - non-volatile configuration
- **MPC555 Registers** (0x003xxxxx): 7 entries - ADC/hardware status
- **ROM** (0x000xxxxx): 5 entries - build info and constants

## Service Protocol

### Service 0x41: Get Address by Parameter ID

**Request Format:**
```
Byte 0: 0x41 (service ID)
Byte 1-2: Parameter ID (big-endian)
```

**Response Format:**
```
Byte 0: 0x42 (response ID)
Byte 1-2: Parameter ID (echo)
Byte 3-6: Resolved address (big-endian)
```

### Service 0x43: Memory Read with Parameter ID + Offset

**Request Format:**
```
Byte 0: 0x43 (service ID)
Byte 1-2: Parameter ID (big-endian)
Byte 3-6: Offset (big-endian)   <- wrong: the length (see Corrections)
```

**Response Format:** Raw data bytes from (resolved_address + offset) <- the read starts at the resolved address;
the reply is 0x45 (0x44 under 256 bytes)

## Dispatch Tables

### EF00 Service Dispatch (0x003FA8B2)
- Populated by `processJ1939DiagnosticRequest`
- Max 32 entries × 6 bytes each
- Entry format: `ef00_dispatch_entry_t`
- Count stored at 0x003FA972

### Diagnostic Service Dispatch (0x003FDB30)
- Populated by `registerDiagnosticService`
- Max 20 entries × 5 bytes each
- Entry format: `diag_dispatch_entry_t`
- Count stored at 0x003FDB94

## Comparison with CM550

| Aspect | CM550 | CM848 |
|--------|-------|-------|
| Parameter count | 723 | 20 |
| Table location (ROM) | 0x35224 | 0x3CDC |
| Entry size | 8 bytes | 6 bytes |
| Dual-bank support | Yes | No |
| RAM params | Many | None |
| Service 0x46 | Implemented | Registered by the application (not by the boot kernel) |

## Why CM848 Has Only 20 Parameters

1. **Simpler architecture** - CM848 is an older ECU (2004 era)
2. **Direct memory access preferred** - Service 0x4A (raw address) is primary method
3. **No runtime parameters** - All entries point to static config, not live data
4. **CLIP services limited** - 0x10/0x15 are stubs, not full implementations

## Files Modified

- `output/global_variables.csv` - Added dispatch table and lookup table entries
- `output/structure_definitions.csv` - Added param_id_entry_t, ef00_dispatch_entry_t, diag_dispatch_entry_t
- `output/function_definitions.csv` - Added parameter types for lookup functions
- `output/enums.csv` - Added implementation status comments for EF00_SERVICE_ID
