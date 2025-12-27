# kuminz-re

Reverse engineering monorepo for Cummins ECU systems. Analyzes e2m calibration files, ECU firmware, and diagnostic tools to understand how Cummins engine controllers work.

## Constraints

- **No Insite Traffic Capture** - Capturing real Insite diagnostic traffic is NOT an option. Protocol must be reverse-engineered from firmware analysis and decompiled code only.

## Service 0x4B Authenticated Write Flow

The following diagram shows the complete authentication process for writing to secured RAM regions on Cummins CM550 ECUs (J90350.00 firmware):

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                    SERVICE 0x4B AUTHENTICATED WRITE FLOW                     │
│                              (J90350.00)                                     │
└─────────────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────┐
│  TOOL (Insite/kuminz-cli)            │
│                                      │
│  1. Read hour meter from ECU         │
│     (Service 0x4A read 0x80xxxx)     │
│                                      │
│  2. Construct auth payload:          │
│     [password:6] + [hour_meter:4]    │
│     "ABCDEF"     + 4-byte value      │
│                                      │
│  3. Send Service 0x4B request:       │
│     [0x4B][Addr:4][Len:1][Data:N]    │
│     [Auth:10]                        │
└──────────────────┬───────────────────┘
                   │ CAN Bus (J1939 TP)
                   ▼
┌──────────────────────────────────────────────────────────────────────────────┐
│  ECU FIRMWARE                                                                │
├──────────────────────────────────────────────────────────────────────────────┤
│                                                                              │
│  ┌─────────────────────────────────────┐                                     │
│  │ memoryOperationFromMessageExtended  │                                     │
│  │ @ 0x217de                           │                                     │
│  │                                     │                                     │
│  │ • Parse J1939 message               │                                     │
│  │ • Extract: address, length, flags   │                                     │
│  │ • Extract: data + auth payload      │                                     │
│  └─────────────────┬───────────────────┘                                     │
│                    ▼                                                         │
│  ┌─────────────────────────────────────┐                                     │
│  │ memoryOperationDispatcher           │                                     │
│  │ @ 0x2148a                           │                                     │
│  │                                     │                                     │
│  │ • Validate message length           │──── FAIL ──▶ Return 0x02            │
│  │   (expected vs actual)              │             (INVALID_LENGTH)        │
│  └─────────────────┬───────────────────┘                                     │
│                    ▼                                                         │
│  ┌─────────────────────────────────────┐                                     │
│  │ addressRangeValidator               │                                     │
│  │ @ 0x3460e                           │                                     │
│  │                                     │                                     │
│  │ • Check address against 5-entry     │                                     │
│  │   validation table @ 0x801be8       │                                     │
│  │                                     │                                     │
│  │ Returns MEMORY_ACCESS_FLAG:         │                                     │
│  └─────────────────┬───────────────────┘                                     │
│                    │                                                         │
│    ┌───────────────┼───────────────┬───────────────┬───────────────┐         │
│    ▼               ▼               ▼               ▼               ▼         │
│  ┌─────┐       ┌─────┐         ┌─────┐         ┌─────┐         ┌─────┐       │
│  │0x00 │       │0x03 │         │0x04 │         │0x05 │         │0x09 │       │
│  │DIRECT│      │SECURED│       │DENIED│        │LOGGING│       │INVALID│     │
│  └──┬──┘       └──┬──┘         └──┬──┘         └──┬──┘         └──┬──┘       │
│     │             │               │               │               │          │
│     ▼             ▼               ▼               ▼               ▼          │
│  Write         Check if        Return          Check            Return       │
│  directly      auth payload    0x0A            logging          0x09         │
│  to RAM        present         (WRITE_         state            (RANGE_      │
│                                DENIED)                          INVALID)     │
│     │             │                               │                          │
│     │             ▼                               ▼                          │
│     │      ┌──────────────┐              ┌──────────────┐                    │
│     │      │ Auth payload │              │ Logging      │                    │
│     │      │ present?     │              │ state = 1?   │                    │
│     │      └──────┬───────┘              └──────┬───────┘                    │
│     │         YES │ NO                      YES │ NO                         │
│     │             │  │                          │  │                         │
│     │             ▼  ▼                          ▼  ▼                         │
│     │     ┌────────┐ Return 0x1A         Write   Return 0x07                 │
│     │     │ hourMeterSecurityValidator   to      (LOGGING_                   │
│     │     │ @ 0x2fcdc                    EEPROM  STATE_ERROR)                 │
│     │     │                       │         │                                │
│     │     │ 1. Check retry count  │         │                                │
│     │     │    (< 17 attempts)    │         │                                │
│     │     │                       │         │                                │
│     │     │ 2. Call               │         │                                │
│     │     │    bitPackingAlgorithm│         │                                │
│     │     │    @ 0x2fbd8          │         │                                │
│     │     │    ┌──────────────────┴──┐      │                                │
│     │     │    │ Transform 10-byte   │      │                                │
│     │     │    │ auth payload:       │      │                                │
│     │     │    │                     │      │                                │
│     │     │    │ • Bit scatter using │      │                                │
│     │     │    │   MASK_TABLE        │      │                                │
│     │     │    │ • XOR shuffle using │      │                                │
│     │     │    │   XOR_TABLE         │      │                                │
│     │     │    │ • Reorder using     │      │                                │
│     │     │    │   REORDER_TABLE     │      │                                │
│     │     │    └──────────┬──────────┘      │                                │
│     │     │               ▼                 │                                │
│     │     │ 3. Compare transformed          │                                │
│     │     │    output against:              │                                │
│     │     │    • _security_key[6]           │                                │
│     │     │    • _hour_meter_ecm_run_time   │                                │
│     │     │               │                 │                                │
│     │     │         MATCH │ NO MATCH        │                                │
│     │     │               │    │            │                                │
│     │     └───────────────┘    ▼            │                                │
│     │             │       Increment         │                                │
│     │             │       retry counter     │                                │
│     │             │       Return 0x03       │                                │
│     │             │       (AUTH_FAILED)     │                                │
│     │             ▼                         │                                │
│     │      ┌──────────────────────┐         │                                │
│     └─────▶│ WRITE TO RAM         │◀────────┘                                │
│            │                      │                                          │
│            │ memcpy(addr, data,   │                                          │
│            │        length)       │                                          │
│            └──────────┬───────────┘                                          │
│                       ▼                                                      │
│               Return 0x00 (SUCCESS)                                          │
│                                                                              │
└──────────────────────────────────────────────────────────────────────────────┘
```

### Memory Region Table

| Address Range           | Flag   | Behavior                      |
|-------------------------|--------|-------------------------------|
| 0x000000 - 0x03FFFF     | 0x04   | ROM - Write DENIED            |
| 0x800000 - 0x8091C1     | 0x03   | Main RAM - Requires AUTH      |
| 0x8091C2 - 0x80FFFF     | 0x00   | Extended RAM - Direct write   |
| 0x010000 - 0x010FFF     | 0x05   | EEPROM - Requires logging state |

### Return Codes

| Code   | Name                   | Meaning                        |
|--------|------------------------|--------------------------------|
| 0x00   | SUCCESS                | Write completed                |
| 0x02   | INVALID_LENGTH         | Message length wrong           |
| 0x03   | AUTH_FAILED            | Security check failed          |
| 0x07   | LOGGING_STATE_ERROR    | EEPROM logging not active      |
| 0x0A   | WRITE_DENIED           | ROM region - blocked           |
| 0x1A   | AUTH_REQUIRED_MISSING  | Secured region, no auth provided |

### bitPackingAlgorithm Lookup Tables (ROM @ 0x2fbc4)

| Table                  | Address  | Values (hex)                          |
|------------------------|----------|---------------------------------------|
| SECURITY_MASK_TABLE    | 0x2fbc4  | `46 58 9a 32 70 87 23 99 85 64`       |
| SECURITY_XOR_TABLE     | 0x2fbce  | `06 08 01 02 00 07 03 09 05 04`       |
| SECURITY_REORDER_TABLE | 0x2fbd7  | (same data, read backwards)           |

For detailed analysis, see [firmware/docs/service_0x4b_analysis.md](firmware/docs/service_0x4b_analysis.md).

## Documentation

See `CLAUDE.md` for detailed project structure, commands, and development guidelines.
