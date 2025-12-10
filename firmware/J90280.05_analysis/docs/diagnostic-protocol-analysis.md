# CM550 Diagnostic Protocol Analysis

**FACTS ONLY - Derived from Assembly/Decompilation Analysis**

---

## Overview

The CM550 ECU implements a proprietary diagnostic protocol for communication with Cummins tools (CalTerm, Insite). The main dispatcher is `diagnosticCommandDispatcher` at `0x12484`.

---

## Protocol Architecture

### Message Flow

```
CAN Reception → Buffer (0x80d2xx) → diagnosticCommandDispatcher → Handler Functions → Response Buffer → CAN Transmission
```

### Key Memory Locations

| Address | Purpose |
|---------|---------|
| `0x80d2b4` | Transmit buffer pointer |
| `0x80d2bc` | Buffer boundary check |
| `0x80d2cd` | Message offset |
| `0x80d2ce` | Processing flag |
| `0x8035ea` | Protocol enable flags (bit 0=service, bit 1=Insite, bit 2=extended) |
| `0x800F34` | Transport protocol state (`diag_tp_state_t`) |

---

## Message Routing (diagnosticCommandDispatcher @ 0x12484)

The dispatcher routes messages based on **Service ID** (byte at offset +1):

### Service ID < 8: Core Diagnostic Services

| Service | Handler | Description |
|---------|---------|-------------|
| **3** | Security + Sub-functions | **Secured write operations** - requires `systemSecurityCheck()` |
| **4** | Direct sub-handlers | System control operations |
| **5** | Memory read/write | Address-based data transfer |
| **6** | Special ('t' command) | Timing/control functions |

### Service ID 0x45-0x56: Extended Diagnostics (bit 2 of 0x8035ea)

| Code | Handler | Purpose |
|------|---------|---------|
| `0x4A` | `FUN_0001a5b0` | **Fuel arbitrator control** (4 sub-modes) |
| `0x4C` | `FUN_0001a910` | Unknown extended function |
| `0x4F` | `FUN_0001a97e` | Unknown extended function |
| `0x51` | `FUN_0001ac64` | Unknown extended function |

### Service ID >= 0x80: Insite Live Data (bit 1 of 0x8035ea)

Handled by `FUN_00019a0a` - processes live parameter monitoring requests.

---

## Service 3: Secured Operations (CalTerm Write)

**Security Check**: `systemSecurityCheck()` at `0x27e98` - **Currently returns 0 (always passes)**

After security verification, routes by sub-function code:

| Sub-Code | Handler | Description |
|----------|---------|-------------|
| `0x40` | `FUN_0000f89c` | Unknown secured operation |
| `0x41` | `FUN_0000f8b6` | Unknown secured operation |
| `0x42` | `FUN_0000f8d8` | Unknown secured operation |
| `0x43` | `FUN_0000f8f6` | Unknown secured operation |
| `0x50` | (direct return 0) | Success/acknowledgment |
| `0x51` | `memoryPatchingSystem` | **RAM patching system** (0x258e0) |
| `0x52` | `FUN_0000f9e4` | Unknown secured operation |
| `0x53` | (direct return 4) | Error code 4 |
| `0x54` | `canMessageBufferLogger` | CAN message logging (0xf9f0) |

### Security Response Codes
- `0x00` = Success
- `0x03` = Security check failed
- `0x18` = Unknown sub-function
- `-1 (0xFF)` = No response needed

---

## Service 4: System Control Operations

| Sub-Code | Handler | Description |
|----------|---------|-------------|
| `0x64` (100) | `FUN_00025768` | Unknown control function |
| `0x65` (101) | `FUN_0000f86a` | Returns success (0) |
| `0x66` (102) | Direct | Clears `0x809d3e` to 0 |
| `0x69` (105) | `FUN_0000f876` | Returns result code |
| `0x70` (112) | Response 4 | Error/unsupported |
| `0x71` (113) | Direct | Sets bit 0 of `0x809d3e` |
| `0x72` (114) | Response 4 | Error/unsupported |
| `0x73` (115) | Direct | Sets bit 1 of `0x809d3e` |
| `0x74` (116) | `FUN_0002588c` | Unknown control function |
| `0x75` (117) | `FUN_000258aa` | Unknown control function |
| `0x76` (118) | Response 4 | Error/unsupported |

---

## Service 5: Memory Operations

The upper nibble determines operation type:

| Upper Nibble | Handler | Operation |
|--------------|---------|-----------|
| `0x60` | `FUN_00019e62(3)` | Memory read (3-byte addressing) |
| `0x80` | `FUN_00019cf0(4)` | Memory write (4-byte addressing) |
| `0xA0` | `FUN_00019cf0(2)` | Memory write (2-byte addressing) |
| `0xB0` | `FUN_00012d76` | **Multi-packet data receive** |
| `0xC0` | `FUN_00019e62(2)` | Memory read (2-byte addressing) |
| `0xE0` | `FUN_00019e62(1)` | Memory read (1-byte addressing) |
| `0xF0` | `FUN_00012b74` | **Multi-packet data transmit** |

### Address Validation
All memory operations use `addressRangeValidator()` at `0x2b544`:
- Returns `9` or `10` = Invalid address (error response)
- Returns `3` or `5` = Special memory region (patch handling)

---

## Service 0x4A: Fuel Arbitrator Control (FUN_0001a5b0)

**Purpose**: Control fuel delivery modes for diagnostics/testing

### Sub-Modes (lower 2 bits)

| Mode | Description |
|------|-------------|
| 0 | Reset/clear arbitrator state |
| 1 | Set RPM target (2-byte parameter) |
| 2 | Set throttle percentage mode |
| 3 | Set fuel limit mode (signed value) |

### Flags (upper bits)
- Bit 2: Disable speed limiting
- Bit 3: Enable/disable specific control

---

## Service >= 0x80: Insite Live Data (FUN_00019a0a)

Processes real-time parameter monitoring requests:

### Message Structure
- Byte 0: Length
- Byte 1: Command type
- Byte 2+: Parameter identifiers

### Special Commands
| Command | Description |
|---------|-------------|
| `0x00` | Single parameter request |
| `0x80` | Extended parameter (with `0x80` modifier) |
| `0xC3` | **PID/DTC request** (followed by address bytes) |
| `0xC4` | PID response acknowledgment |

### Parameter Lookup Table
- Base address: `0x8089e0`
- Up to 10 parameter slots
- Validates against bit masks at `0x8055fe`

---

## Response Message Building

### Message 0x45 (diagnosticMessage45Builder @ 0x1a192)

6-byte status response containing:

| Byte | Content |
|------|---------|
| 0 | Length (6) |
| 1 | Message ID (0x45) |
| 2 | High byte of `0x80bd8e` |
| 3 | Derate percentage (calculated) |
| 4 | Status flags (protection bits) |
| 5 | Parameter limit value >> 7 |
| 6 | Config byte |

**Status Flag Bits (Byte 4)**:
- Bit 0: Protection system enabled
- Bit 1: Oil pressure protection active
- Bit 2: Diagnostic state = 10
- Bit 3: I/O control fault
- Bit 4: Derate threshold exceeded
- Bit 5: Derate not active
- Bit 6: Data changed flag

### Message 0x46 (FUN_0001a398)

22-byte extended status with RPM, fuel, speed parameters.

---

## Multi-Packet Transfer Protocol

### Transmit (0xF0 - FUN_00012b74)

1. Parse address from bytes 3-4 (`0x80d3f8`)
2. Parse length from bytes 5-6 (`0x80d400`)
3. Validate address with `addressRangeValidator`
4. Build response packets (max 14 bytes data per packet)
5. Header format: `07 | (length | 0xB0) | addr_hi | addr_lo | len_hi | len_lo | data...`

### Receive (0xB0 - FUN_00012d76)

1. Check `DAT_0080d405` state flag
2. Validate sequence against `0x80d3f8`
3. Copy data to target address
4. Supports special handling for addresses 0x15, 0x17, 0x18, 0x19
5. Uses `_memory_patch_count` for tracking multi-block writes

---

## Transport Protocol State (diag_tp_state_t @ 0x800F34)

```c
struct diag_tp_state_t {
    byte diag_state;        // 0=idle, 1=active
    byte expected_id_low;   // Expected CAN ID low byte
    word expected_guard;    // Guard word validation
    byte total_packets;     // ((total_bytes-1)/7)+1
    byte req_start;         // Current sequence (1-based)
    byte req_count;         // Remaining packets
    byte pre_status;        // Abort flag (non-zero = abort)
    word total_bytes;       // Total payload length
    ptr  src_data_ptr;      // Source payload pointer
    ptr  resp_byte_ptr;     // Response status pointer
    byte status_code;       // 0x37 init, 0x70 delay
    byte reserved;          // Padding
    uint32 tx_header_id;    // Composed CAN ID
    uint16 tx_length;       // DLC for frame
    ptr  tx_cm_buf;         // 8-byte scratch buffer
};
```

---

## Error Response Codes

| Code | Meaning |
|------|---------|
| 0 | Success |
| 2 | Invalid message length |
| 3 | Security check failed |
| 4 | Buffer overflow / unsupported |
| 8 | Address validation failed |
| 9 | Invalid address range |
| 10 | Invalid address range (alt) |
| 0x14 | Checksum mismatch |
| 0x18 | Unknown sub-function |

---

## Key Discoveries

### 1. Security System is DISABLED
`systemSecurityCheck()` at `0x27e98` unconditionally returns 0. This means:
- **All Service 3 operations are accessible without authentication**
- Memory patching, logging, and write operations have no security barrier

### 2. Memory Patching System
`memoryPatchingSystem` at `0x258e0` allows:
- Runtime RAM modifications
- Tracked by `_memory_patch_count`
- Uses protected area check at `0x8062cb`

### 3. Protocol Enable Flags (0x8035ea)
- **Bit 0**: Core service enable
- **Bit 1**: Insite live data enable
- **Bit 2**: Extended diagnostics (0x45-0x56)

### 4. Circular Response Buffer
- Located at `0x80d2b4` to `0x80d2bc`
- 256-byte circular buffer
- Overflow sets error flag at `0x805e00` bit 2

---

## Next Steps for Further Analysis

1. **Map sub-function handlers** (0x40-0x43, 0xf89c-0xf8f6)
2. **Decode Insite parameter IDs** at `0x8089e0`
3. **Analyze memory patch validation** at `addressRangeValidator`
4. **Document PID/DTC table** accessed via 0xC3 commands
5. **Reverse CAN ID composition** for transport protocol

---

## Function Reference

| Address | Name | Purpose |
|---------|------|---------|
| 0x12484 | `diagnosticCommandDispatcher` | Main message router |
| 0x19a0a | `FUN_00019a0a` | Insite live data handler |
| 0x19cf0 | `FUN_00019cf0` | Memory write operations |
| 0x19e62 | `FUN_00019e62` | Memory read operations |
| 0x1a192 | `diagnosticMessage45Builder` | Status message builder |
| 0x1a5b0 | `FUN_0001a5b0` | Fuel arbitrator control |
| 0x12b74 | `FUN_00012b74` | Multi-packet transmit |
| 0x12d76 | `FUN_00012d76` | Multi-packet receive |
| 0x27e98 | `systemSecurityCheck` | Security (disabled) |
| 0x258e0 | `memoryPatchingSystem` | RAM patching |
| 0xf9f0 | `canMessageBufferLogger` | CAN logging |
| 0x2b544 | `addressRangeValidator` | Address validation |

---

*Analysis derived from Ghidra decompilation of J90280.05 firmware*
