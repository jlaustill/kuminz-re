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
│  │ handleJ1939WriteMemoryService       │                                     │
│  │ @ 0x217de                           │                                     │
│  │                                     │                                     │
│  │ • Parse J1939 message               │                                     │
│  │ • Extract: address, length, flags   │                                     │
│  │ • Extract: data + auth payload      │                                     │
│  └─────────────────┬───────────────────┘                                     │
│                    ▼                                                         │
│  ┌─────────────────────────────────────┐                                     │
│  │ writeJ1939DiagnosticMemory          │                                     │
│  │ @ 0x2148a                           │                                     │
│  │                                     │                                     │
│  │ • Validate message length           │──── FAIL ──▶ Return 0x02            │
│  │   (expected vs actual)              │             (INVALID_LENGTH)        │
│  └─────────────────┬───────────────────┘                                     │
│                    ▼                                                         │
│  ┌─────────────────────────────────────┐                                     │
│  │ lookupApplicationMemoryRegionType   │                                     │
│  │ @ 0x3460e                           │                                     │
│  │                                     │                                     │
│  │ • Check address against 5-entry     │                                     │
│  │   region table @ ROM 0x345dc        │                                     │
│  │                                     │                                     │
│  │ Returns MEMORY_REGION_TYPE:         │                                     │
│  └─────────────────┬───────────────────┘                                     │
│                    │                                                         │
│    ┌───────────────┼───────────────┬───────────────┬───────────────┐         │
│    ▼               ▼               ▼               ▼               ▼         │
│  ┌─────┐       ┌─────┐         ┌─────┐         ┌─────┐         ┌─────┐       │
│  │0x00 │       │0x03 │         │0x04 │         │0x05 │         │0x09 │       │
│  │DIRECT│      │SECURED│       │DENIED│        │EEPROM │       │INVALID│     │
│  └──┬──┘       └──┬──┘         └──┬──┘         └──┬──┘         └──┬──┘       │
│     │             │               │               │               │          │
│     ▼             ▼               ▼               ▼               ▼          │
│  Write         Check if        Return          Check            Return       │
│  directly      auth payload    0x0A            not-safe         0x09         │
│  to RAM        present         (WRITE_         state            (RANGE_      │
│                                DENIED)                          INVALID)     │
│     │             │                               │                          │
│     │             ▼                               ▼                          │
│     │      ┌──────────────┐              ┌──────────────┐                    │
│     │      │ Auth payload │              │ Not safe and │                    │
│     │      │ present?     │              │ refresh on?  │                    │
│     │      └──────┬───────┘              └──────┬───────┘                    │
│     │         YES │ NO                      NO │ YES                         │
│     │             │  │                          │  │                         │
│     │             ▼  ▼                          ▼  ▼                         │
│     │     ┌────────┐ Return 0x03         Write   Return 0x07                 │
│     │     │ validateSecurityKey          to      (NOT_SAFE)                  │
│     │     │ @ 0x2fcdc                    EEPROM                               │
│     │     │                       │         │                                │
│     │     │ 1. Check retry count  │         │                                │
│     │     │    (< 17 attempts)    │         │                                │
│     │     │                       │         │                                │
│     │     │ 2. Call               │         │                                │
│     │     │  unscrambleSecurityKey│         │                                │
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

`application_memory_region_table` at ROM 0x345dc (`MEMORY_REGION_TYPE`; the first matching entry wins; the type while development mode is on / off - PR #53 round 73):

| Address Range             | Type        | Behavior |
|---------------------------|-------------|----------|
| 0x000000 - 0x07FFFF       | 0x04        | Main flash - write refused (0x0A) |
| 0x800000 - 0x8091DC       | 0x03        | Main RAM - copied after the security key |
| 0x8091DC - 0x80FFFF       | 0x00        | Extended RAM - copied without a check |
| 0x1000000 - 0x1001FFF     | 0x05        | EEPROM - refused (0x07) while not safe to program with RAM refresh on; else after the key through the EEPROM byte write queue and the mirror at 0x803B0A |
| 0xFFC800 - 0xFFFFFF       | 0x03 / 0x0A | Registers - after the key in development mode, else refused (0x0A) |

### Return Codes

| Code   | Name                   | Meaning                        |
|--------|------------------------|--------------------------------|
| 0x00   | SUCCESS                | Write completed                |
| 0x02   | INVALID_LENGTH         | Message length wrong           |
| 0x03   | AUTH_FAILED            | Security check failed          |
| 0x07   | NOT_SAFE               | EEPROM write refused: not safe to program (`not_safe_to_program_flag` is 1) while RAM refresh is on - CM848's J1939_DIAGNOSTIC_RESULT_NOT_SAFE |
| 0x0A   | WRITE_DENIED           | ROM region - blocked           |
| 0x1A   | AUTH_REQUIRED_MISSING  | EEPROM write without the key (a type 3 write without it returns 0x03 here; CM848 returns 0x1A for both - PR #53 round 73) |

### unscrambleSecurityKey Lookup Tables (ROM @ 0x2fbc4)

| Table                        | Address  | Values (hex)                    |
|------------------------------|----------|---------------------------------|
| `security_key_scramble_mask` | 0x2fbc4  | `46 58 9a 32 70 87 23 99 85 64` |
| `security_key_byte_order`    | 0x2fbce  | `06 08 01 02 00 07 03 09 05 04` - the XOR step reads it forwards, the reorder step backwards from 0x2fbd7 |

CM848 holds the same bytes at 0x5839a / 0x583a4, and its `unscrambleSecurityKey` (0x555cc) is the same function - the J1939 memory write path is shared code (PR #53 round 72).

For detailed analysis, see [firmware/docs/service_0x4b_analysis.md](firmware/docs/service_0x4b_analysis.md).

## Documentation

See `CLAUDE.md` for detailed project structure, commands, and development guidelines.
