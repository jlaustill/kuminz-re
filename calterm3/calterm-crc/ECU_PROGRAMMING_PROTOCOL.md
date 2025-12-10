# ECU Programming Protocol Documentation

This document describes the communication protocol used by Calterm III to interact with Cummins ECUs for calibration and data transfer operations.

## Protocol Stack Overview

```
+--------------------------------------------+
|           Application Layer                |
|  (Parameter Access, Memory Operations)     |
+--------------------------------------------+
|          CLIP Instruction Layer            |
|  (Cummins Insite Protocol Commands)        |
+--------------------------------------------+
|         J1939/J1708 Transport Layer        |
|  (CAN Bus / Serial Communication)          |
+--------------------------------------------+
```

## CLIP Instruction Layer

CLIP (Cummins Insite Protocol) is the proprietary instruction layer used for ECU communication. All commands use a common packet structure with instruction-specific payloads.

### Instruction Codes

| Code | Hex  | Name                    | Description                              |
|------|------|-------------------------|------------------------------------------|
| 16   | 0x10 | GetParametersByID       | Read parameter values by ID              |
| 17   | 0x11 | SetParametersByID       | Write parameter values by ID             |
| 18   | 0x12 | ExecuteOperation        | Execute an ECU operation                 |
| 20   | 0x14 | GetDataByAddress        | Read raw data from memory address        |
| 21   | 0x15 | SetDataByAddress        | Write raw data to memory address         |
| 22   | 0x16 | GetAddressByParameterID | Get memory address for a parameter       |

**Note:** Code 0x13 (19) appears to be reserved/unused.

### Common Packet Header

All CLIP packets share a common 2-byte header:

```
+--------+--------+
| Byte 0 | Byte 1 |
+--------+--------+
|  CMD   | SEQ_ID |
+--------+--------+
```

- **CMD**: Instruction code (0x10-0x16)
- **SEQ_ID**: Sequence identifier for matching requests to responses

---

## Parameter Access

### GetParametersByID (0x10)

Reads one or more parameter values from the ECU by their IDs.

**Packet Format:**
```
+------+--------+-------------+-------------+-----+
| CMD  | SEQ_ID | PARAM_ID[0] | PARAM_ID[1] | ... |
| 0x10 |   n    |   2 bytes   |   2 bytes   |     |
+------+--------+-------------+-------------+-----+
  [0]     [1]      [2..3]        [4..5]

Header size: 2 bytes
```

**Parameter ID Format:** 2-byte identifier, typically encoded as hex pairs.

**Code Reference:** `DeviceControl_ghidra.c:63619` - Instruction code 0x10 used

### SetParametersByID (0x11)

Writes one or more parameter values to the ECU by their IDs.

**Packet Format:**
```
+------+--------+-------------+-------+-------------+-------+-----+
| CMD  | SEQ_ID | PARAM_ID[0] | VALUE | PARAM_ID[1] | VALUE | ... |
| 0x11 |   n    |   2 bytes   |  var  |   2 bytes   |  var  |     |
+------+--------+-------------+-------+-------------+-------+-----+
  [0]     [1]      [2..3]      [4..n]

Header size: 2 bytes
```

**Code Reference:** `DeviceControl_ghidra.c:63939` - SetParametersByID implementation

---

## Memory Access

### GetDataByAddress (0x14)

Reads raw data from a specific memory address in the ECU.

**Packet Format:**
```
+------+--------+-----------+--------+
| CMD  | SEQ_ID |  ADDRESS  | LENGTH |
| 0x14 |   n    |  4 bytes  | 2 bytes|
+------+--------+-----------+--------+
  [0]     [1]      [2..5]     [6..7]

Header size: 8 bytes
Total request size: 8 bytes (no data payload for read)
```

**Address Format:**
- 4 bytes, **big-endian** byte order
- Byte-swapping applied via `FUN_10085790(address, 4, 2, 2, 1)`

**Length Format:**
- 2 bytes, **big-endian** byte order
- Byte-swapping applied via `FUN_10085790(length, 2, 2, 2, 1)`

**Code Reference:** `DeviceControl_ghidra.c:65183-65206` - Packet construction

### SetDataByAddress (0x15)

Writes raw data to a specific memory address in the ECU.

**Packet Format:**
```
+------+--------+-----------+--------+------+
| CMD  | SEQ_ID |  ADDRESS  | LENGTH | DATA |
| 0x15 |   n    |  4 bytes  | 2 bytes| var  |
+------+--------+-----------+--------+------+
  [0]     [1]      [2..5]     [6..7]  [8..n]

Header size: 8 bytes
```

**Data Section:** Variable length, copied after the 8-byte header.

---

## Operation Execution

### ExecuteOperation (0x12)

Executes a predefined operation on the ECU.

**Packet Format:**
```
+------+--------+-----------+------+
| CMD  | SEQ_ID |  OP_ID    | ARGS |
| 0x12 |   n    |  2 bytes  | var  |
+------+--------+-----------+------+
  [0]     [1]      [2..3]    [4..n]

Header size: 4 bytes
```

**Operation ID:** 2-byte identifier specifying which operation to execute.

**Arguments:** Variable-length operation-specific arguments.

**Code Reference:** `DeviceControl_ghidra.c:64009` - ExecuteOperation implementation

---

## Address Resolution

### GetAddressByParameterID (0x16)

Resolves the memory address for a given parameter ID.

**Packet Format:**
```
+------+--------+----------+
| CMD  | SEQ_ID | PARAM_ID |
| 0x16 |   n    | 2 bytes  |
+------+--------+----------+
  [0]     [1]     [2..3]

Header size: 2 bytes
```

**Response:** Returns the 4-byte memory address for the specified parameter.

**Code Reference:** `DeviceControl_ghidra.c:64081` - GetAddressByParameterID

---

## Packet Construction

The core packet construction logic is in `CLIPInstruction_sendData` (FUN_100445b0):

```c
// Allocate buffer based on instruction type
memset(buffer, 0, total_size);

// Copy payload data after header
memcpy(buffer + header_size, data, data_length);

// Set common header
buffer[0] = command_code;    // Instruction code
buffer[1] = sequence_id;     // Sequence ID

// For memory access commands (0x14, 0x15):
if (is_memory_access) {
    // Address: 4 bytes, big-endian
    address_swapped = byte_swap(address, 4, 2, 2, 1);
    memcpy(buffer + 2, &address_swapped, 4);

    // Length: 2 bytes, big-endian
    length_swapped = byte_swap(length, 2, 2, 2, 1);
    memcpy(buffer + 6, &length_swapped, 2);
}
```

### Maximum Message Size

The packet size is constrained by ECM capabilities:
```c
max_size = pECM->GetMaxMessageSize();
if (packet_size > max_size) {
    // Error: packet too large
}
```

---

## J1939 Transport Layer

The CLIP protocol operates over J1939 (CAN bus) or J1708 (serial) networks.

### Key PGN Values

| PGN    | Hex    | Name                | Description                    |
|--------|--------|---------------------|--------------------------------|
| 234    | 0xEA   | Request PGN         | Request for specific PGN       |
| 239    | 0xEF   | CLIP Response       | CLIP instruction response      |
| 65259  | 0xFEEB | Component ID        | ECU component identification   |

### Message Format (J1939)

```
+--------+--------+--------+----------+
| PGN[2] | PGN[1] | PGN[0] | DATA...  |
+--------+--------+--------+----------+
```

**PGN Byte Order:** Little-endian in J1939 messages.

### CJ1939Network_Transmit Signature

```c
CJ1939Network_Transmit(
    uint32_t pgn,           // Parameter Group Number
    uint8_t  source_addr,   // Source address
    uint8_t  dest_addr,     // Destination address
    char*    data_string,   // Hex-encoded data string
    size_t   data_length    // Data length
);
```

### Known Message Patterns

**ECM ID Request:**
```
Data: "43000000000002FF"
Decoded: CLIP command for ECM identification
```

**Component ID Request (PGN 0xFEEB):**
```
Data: "EBFE00FFFFFFFFFF"
PGN bytes: EB FE (0xFEEB little-endian)
Request type: Broadcast (FF)
```

### Response Processing

```c
// From ModuleDetection_ghidra.c:32352-32358
if (pgn[2] == 0xEF) {
    // CLIP response - process instruction result
    CJ1939Network_HandleResponse(this, pgn, data);
}
else if ((pgn[2] == 0xFE) && (pgn[1] == 0xEB)) {
    // Component ID response (PGN 0xFEEB)
    CJ1939Network_HandleComponentID(this, pgn, data, length);
}
```

---

## .NET Interface Definitions

### CLIP Instruction Enum (Interop.DeviceControl.cs:1430)

```csharp
public enum tagCICLIPInstructionEnum
{
    pakBadInstruction = 0,
    pakGoodInstruction = 1,
    pakDDInstruction = 2,
    // ...
    pakGetParametersByID = 16,      // 0x10
    pakSetParametersByID = 17,      // 0x11
    pakExecuteOperation = 18,       // 0x12
    pakGetDataByAddress = 20,       // 0x14
    pakSetDataByAddress = 21,       // 0x15
    pakGetAddressByParameterID = 22 // 0x16
}
```

### CLIPService Implementation (DataSource.cs:41130)

```csharp
// GetParametersByID: converts int[] parameter IDs to hex stream
public void GetParametersByID(int[] parameterIds) {
    // Convert each parameter ID to 2-byte hex representation
    // Build CLIP packet with header + parameter IDs
    // Send via transport layer
}
```

---

## Code References

### Native Code (DeviceControl_ghidra.c)

| Line Range   | Function/Class                    | Description                     |
|--------------|-----------------------------------|---------------------------------|
| 63470-65220  | CLIPInstruction class             | CLIP packet handling            |
| 63619        | GetParametersByID usage           | Instruction code 0x10           |
| 63939        | SetParametersByID usage           | Instruction code 0x11           |
| 64009        | ExecuteOperation usage            | Instruction code 0x12           |
| 64081        | GetAddressByParameterID usage     | Instruction code 0x16           |
| 65183-65206  | CLIPInstruction_sendData          | Packet construction logic       |

### Native Code (ModuleDetection_ghidra.c)

| Line Range   | Function                          | Description                     |
|--------------|-----------------------------------|---------------------------------|
| 32340-33145  | CJ1939Network class               | J1939 network communication     |
| 32352-32358  | PGN dispatch logic                | Response routing by PGN         |

### .NET Code

| File                    | Lines       | Description                       |
|-------------------------|-------------|-----------------------------------|
| Interop.DeviceControl.cs| 1430-1460   | CLIP instruction enum definition  |
| DataSource.cs           | 41130-41420 | CLIPService implementation        |
| Interfaces.cs           | 1180-1280   | PGN/SPN class definitions         |

---

## Appendix: Byte Swap Function

The byte-swapping function `FUN_10085790` converts between host and network byte order:

```c
// Signature: FUN_10085790(value, total_bytes, swap_unit, param3, param4)
// Example: FUN_10085790(address, 4, 2, 2, 1)
//   - Takes 4-byte address
//   - Swaps in 2-byte units (word swap)
//   - Results in big-endian format for transmission
```

This ensures addresses and lengths are transmitted in the byte order expected by the ECU.

---

# Business Logic Layer Implementation Guide

This section documents the business logic layer needed to implement CLIP communication, assuming an abstracted CAN adapter layer with `sendCanMsg()` and `getCanMsg()` primitives.

## Architecture Context

```
┌─────────────────────────────────────────┐
│           Display Layer (GUI)           │
├─────────────────────────────────────────┤
│      Business Logic Layer               │
│  ┌─────────────────────────────────┐    │
│  │     CLIP Instruction Builder    │    │
│  │  (GetParam, SetParam, ReadMem)  │    │
│  ├─────────────────────────────────┤    │
│  │       CLIP Session Manager      │    │
│  │   (Connection ID, State Machine)│    │
│  ├─────────────────────────────────┤    │
│  │      CLIP Transport Layer       │    │
│  │  (Fragmentation, Reassembly)    │    │
│  ├─────────────────────────────────┤    │
│  │       J1939 Message Builder     │    │
│  │    (Arbitration ID, PGN)        │    │
│  └─────────────────────────────────┘    │
├─────────────────────────────────────────┤
│           Data Layer (Adapter)          │
│   sendCanMsg(arb_id, data[])            │
│   getCanMsg() → (arb_id, data[])        │
└─────────────────────────────────────────┘
```

---

## CAN Arbitration ID Construction

### 29-bit Extended ID Format (J1939)

```
Bits [28:26] = Priority (3 bits, typically 6 = 0b110 for CLIP)
Bits [25:24] = Reserved/Data Page (2 bits, typically 0)
Bits [23:16] = PDU Format (PF) - determines PGN type
Bits [15:8]  = PDU Specific (PS) - destination or group extension
Bits [7:0]   = Source Address (SA)
```

**For CLIP Data (PGN 0x00EA00):**
```
Priority = 6 (0b110)
PF = 0xEA (234)
PS = Destination Address
SA = Tool Address (typically 0xF9 = 249)

Arbitration ID = 0x18EA[dest][src]
Example: Tool (0xF9) → ECU (0x00) = 0x18EA00F9
```

---

## CLIP Frame Format

Every CLIP frame has a 3-byte header:

```
Byte 0: (SessionID << 5) | ControlBits
        - Bits [7:5] = Session ID (0-7, for multiplexing)
        - Bits [4:0] = Control/Message type

Byte 1: Connection ID (remote session identifier)

Byte 2: Additional control/flags

Bytes 3-7: Payload data (max 5 bytes per CAN frame)
```

**Code Reference:** `DeviceControl_ghidra.c:69822-69826`
```c
*local_18 = *(char *)(iVar1 + 0x13) << 5 | 3;  // SessionID << 5 | 0x03
local_18[1] = *(byte *)(iVar1 + 5);             // Connection ID
local_18[2] = *(byte *)(iVar1 + 7);             // Control byte
```

### Message Types (Byte 0 lower bits)

| Value | Type | Description |
|-------|------|-------------|
| 0x02 | Seed Reply / Transport Open | Security challenge or transport session open |
| 0x03 | Data | Normal data transfer |
| 0x04 | Context Reply / CTS | Session established or clear-to-send |
| 0x05 | Connection Refused | ECU denied connection |

### Max Data Per Frame

- CAN frame: 8 bytes
- CLIP header: 3 bytes
- **Max payload per frame: 5 bytes**

---

## CLIP Session Manager

### Session State Machine

```
┌─────────┐
│  CLOSED │ (State 0x01)
└────┬────┘
     │ Open Request
     ▼
┌─────────┐
│ OPENING │ (State 0x02)
│         │◄─── Send open, wait for seed
└────┬────┘
     │ Seed Received (msg type 0x02)
     ▼
┌─────────┐
│ SEEDED  │ (State 0x05)
│         │◄─── Encrypt context with seed
└────┬────┘
     │ Context Reply (msg type 0x04)
     ▼
┌─────────┐
│  READY  │ (State 0x03)
│         │◄─── Data transfer enabled
└─────────┘
```

### Connection ID Management

- 1-byte identifier (0-255)
- Used to match requests with responses
- Allows up to 256 simultaneous sessions
- Increment for each new request, wrap at 255

### Timeouts

| Operation | Timeout | Retries |
|-----------|---------|---------|
| Session Open (seed) | 15,000 ms | 3 |
| Context Exchange | 15,000 ms | 3 |
| Data Request | 5,000 ms | configurable |

---

## Security/Encryption Handshake

### Session Authentication Flow

```
┌──────────┐                              ┌──────────┐
│   Tool   │                              │   ECU    │
└────┬─────┘                              └────┬─────┘
     │                                         │
     │  1. Open Request (4 bytes)              │
     │────────────────────────────────────────>│
     │                                         │
     │  2. Seed Reply (msg type 0x02)          │
     │<────────────────────────────────────────│
     │     [ConnID][0x02][EncLvl1][EncLvl2][Seed:4 bytes]
     │                                         │
     │  3. Encrypted Tool Context              │
     │────────────────────────────────────────>│
     │     [ConnID][type][encrypted_context...]│
     │                                         │
     │  4. Context Reply (msg type 0x04)       │
     │<────────────────────────────────────────│
     │     [ConnID][0x04][encrypted_remote_ctx]│
     │                                         │
     │  ═══ Session Authenticated ═══          │
     │                                         │
```

### Seed Reply Packet (Type 0x02)

```
Byte 0:    Connection ID
Byte 1:    0x02 (Seed Reply type)
Byte 2:    Encryption Level 1
Byte 3:    Encryption Level 2
Bytes 4-7: Seed value (4 bytes)
```

### Encryption Algorithm

The encryption is a **proprietary block cipher**:
- 8-byte blocks (64-bit)
- 32 rounds per block
- Key material derived from seed + hardcoded values in binary
- Output length: `((input_length + 7) / 8) * 8 + 4` (4-byte overhead)

### Session States

| State | Value | Description |
|-------|-------|-------------|
| CLOSED | 0x01 | No session |
| REQUESTING_SEED | 0x04 | Waiting for seed reply |
| SEEDED | 0x05 | Seed received, ready to encrypt |
| AUTHENTICATED | 0x07 | Context exchanged, data transfer OK |
| SECURED_LOCKED | 0x08 | Encryption required but not licensed |

**Code Reference:** `DeviceControl_ghidra.c:67039-67207`

---

## CLIP Transport Layer (Multi-Packet)

**Important:** Calterm uses a **proprietary CLIP transport layer**, NOT standard J1939 TP (BAM/RTS-CTS). Multi-packet handling is done entirely within the CLIP protocol.

### Transport Message Types

| Type | Value | Description |
|------|-------|-------------|
| Open | 0x02 | Initiator opens transport session |
| Data | 0x03 | Data transfer with sequence number |
| CTS | 0x04 | Clear-to-send / acknowledgment |

### Transport Message Formats

**Open Message (Type 0x02):**
```
Byte 0:    0x02 (Open type)
Byte 1:    0xFF (control)
Byte 2:    0x01 (control)
Byte 3:    Unknown control
Byte 4:    Expected packet count (0-3, defaults to 4)
Byte 5:    Unknown control
```

**Data Message (Type 0x03):**
```
Byte 0:    (SeqNum << 5) | 0x03
           - Bits [7:5] = 3-bit sequence number (0-7)
           - Bits [4:0] = 0x03 (data type)
Byte 1:    Connection ID
Byte 2:    Control byte
Bytes 3-7: Payload (max 5 bytes per frame)
```

**CTS Message (Type 0x04):**
```
Byte 0:    0x04 (CTS type)
Byte 1:    Control/status
```

### Sequence Number Handling

- **3-bit field** in bits [7:5] of byte 0
- Supports sequences 0-7 (max 8 fragments per transfer)
- Validation checks:
  - Match expected → Process data
  - Match previous → Duplicate, ignore with warning
  - Neither → Out of sequence, **fatal error**, close session

**Code Reference:** `DeviceControl_ghidra.c:70226-70280`

### Multi-Packet Flow

```
Initiator                              Responder
    │                                      │
    │  Open (type 0x02, packet_count=N)    │
    │─────────────────────────────────────>│
    │                                      │
    │          CTS (type 0x04)             │
    │<─────────────────────────────────────│
    │                                      │
    │  Data (seq=0, type 0x03, payload)    │
    │─────────────────────────────────────>│
    │                                      │
    │  Data (seq=1, type 0x03, payload)    │
    │─────────────────────────────────────>│
    │         ...                          │
    │  Data (seq=N-1, type 0x03, payload)  │
    │─────────────────────────────────────>│
    │                                      │
    │          ACK (type 0x04)             │
    │<─────────────────────────────────────│
```

### Transport Timeouts

| Operation | Timeout |
|-----------|---------|
| Clear-to-send wait | 29 seconds |
| Data transfer | Configurable |

---

## Error Handling

### Transport Errors

| Error | Description | Action |
|-------|-------------|--------|
| DCL_TRANSPORT_TIMEOUT | No response | Retry up to 3x |
| DCL_TRANSPORT_ABORTED | ECU aborted | Log, close session |
| DCL_TRANSPORT_COLLISION | Bus collision | Back off, retry |

### Request Status Codes

| Code | Name | Meaning |
|------|------|---------|
| 1 | REQUEST_SUCCESS | Complete |
| 2 | REQUEST_FAIL | Error occurred |
| 3 | REQUEST_PROCESSING | Still waiting |
| 4 | REQUEST_NEED_PROCESS | Needs to be sent |

---

## Implementation Pseudocode

### CLIPService Class

```python
class CLIPService:
    # States
    STATE_CLOSED = 0x01
    STATE_REQUESTING_SEED = 0x04
    STATE_SEEDED = 0x05
    STATE_AUTHENTICATED = 0x07

    def __init__(self, can_adapter):
        self.can = can_adapter
        self.session_id = 0
        self.connection_id = 0
        self.tool_address = 0xF9
        self.state = self.STATE_CLOSED
        self.seed = None

    def _build_arb_id(self, dest_address):
        """Build 29-bit J1939 arbitration ID for CLIP."""
        priority = 6
        pgn_pf = 0xEA  # CLIP data PGN
        return (priority << 26) | (pgn_pf << 16) | (dest_address << 8) | self.tool_address
        # Results in 0x18EA[dest][src]

    def send_clip_packet(self, dest_address, payload):
        """Send a CLIP packet, fragmenting if needed."""
        header = bytes([
            (self.session_id << 5) | 0x03,
            self.connection_id,
            0x00
        ])
        full_data = header + payload

        offset = 0
        while offset < len(full_data):
            chunk = full_data[offset:offset+8]
            arb_id = self._build_arb_id(dest_address)
            self.can.sendCanMsg(arb_id, chunk)
            offset += 8

    def get_parameter_by_id(self, dest_address, param_id):
        """Read a parameter from ECU."""
        payload = bytes([
            0x10,  # GetParametersByID
            self._next_seq_id(),
            (param_id >> 8) & 0xFF,
            param_id & 0xFF
        ])
        self.send_clip_packet(dest_address, payload)
        return self._wait_for_response(timeout=5000)

    def read_memory(self, dest_address, address, length):
        """Read raw memory from ECU."""
        payload = bytes([
            0x14,  # GetDataByAddress
            self._next_seq_id(),
            (address >> 24) & 0xFF,  # Big-endian address
            (address >> 16) & 0xFF,
            (address >> 8) & 0xFF,
            address & 0xFF,
            (length >> 8) & 0xFF,    # Big-endian length
            length & 0xFF
        ])
        self.send_clip_packet(dest_address, payload)
        return self._wait_for_response(timeout=5000)
```

### Response Handler

```python
def on_can_message(self, arb_id, data):
    """Called when CAN message received."""
    # Extract source from arbitration ID
    source_addr = (arb_id >> 8) & 0xFF

    # Check if CLIP message (PGN 0xEA)
    pgn_pf = (arb_id >> 16) & 0xFF
    if pgn_pf != 0xEA:
        return

    # Parse CLIP header
    session_id = (data[0] >> 5) & 0x07
    msg_type = data[0] & 0x1F
    conn_id = data[1]

    # Match to pending request
    if conn_id != self.connection_id:
        return

    # Handle by type
    if msg_type == 0x02:
        self._handle_seed(data[2:])
    elif msg_type == 0x03:
        self._handle_data_response(data[3:])
    elif msg_type == 0x04:
        self._handle_context_reply()
    elif msg_type == 0x05:
        self._handle_connection_refused()
```

---

## CLIP vs Standard J1939 Comparison

| Feature | Standard J1939 | Calterm CLIP |
|---------|---------------|--------------|
| Multi-packet transport | PGN 0xEC00 (TP.CM), 0xEB00 (TP.DT) | Proprietary types 0x02, 0x03, 0x04 |
| Flow control | BAM or RTS/CTS | Custom Open/CTS messages |
| Sequence numbers | 1-byte (0-255) | 3-bit (0-7) |
| Max fragments | 255 packets | 8 packets |
| Authentication | None | Seed/key + encrypted context |

---

## Additional Code References

| File | Line Range | Description |
|------|------------|-------------|
| DeviceControl_ghidra.c | 66987-67207 | CLIPSession::open() |
| DeviceControl_ghidra.c | 67725-67758 | Seed/context handling |
| DeviceControl_ghidra.c | 69799-69845 | CLIPTransport::sendGuaranteed() |
| DeviceControl_ghidra.c | 70158-70382 | CLIPTransport::DataReceived() |
| DeviceControl_ghidra.c | 70226-70280 | Sequence number validation |

---

# CM550 ECU-Specific Findings

This section documents ECU-side implementation details discovered through reverse engineering of the CM550 firmware (J90280.05). These findings are critical for understanding how the protocol behaves on actual hardware.

## Security Implementation

### systemSecurityCheck() - DISABLED!

**Location:** `0x00027e98` in CM550 firmware

```c
undefined1 systemSecurityCheck(void)
{
    return 0;  // Always returns 0 - security check disabled!
}
```

**Impact:** Authentication is NOT enforced on CM550 ECUs. The seed/key exchange still occurs, but the ECU accepts commands without completing the full handshake. This means:
- No encryption is needed for CM550
- Session can transition directly to AUTHENTICATED after receiving seed
- Other ECU types may still require proper encryption

### diagnosticServiceSecurityValidator()

**Location:** `0x0001b7e8` in CM550 firmware

This function validates security levels for diagnostic services but has minimal enforcement due to `systemSecurityCheck()` returning 0.

---

## Memory Address Validation

### addressRangeValidator() Function

**Location:** `0x0002b544` in CM550 firmware

The ECU validates all memory access requests against a table of allowed regions:

```c
bool addressRangeValidator(uint startAddr, uint endAddr, uint accessType)
{
    // Iterate through address_range_validation_table
    // Check if [startAddr, endAddr] falls within an allowed region
    // Verify accessType matches region permissions
}
```

### Address Range Validation Table

**Location:** `0x0002B512` in CM550 firmware

| Entry | Start Address | End Address | Permissions | Description |
|-------|--------------|-------------|-------------|-------------|
| 0 | 0x00000000 | 0x0003FFFF | 0x04 (Read) | ROM - Firmware (256KB) |
| 1 | 0x00800000 | 0x008091C2 | 0x03 (Read) | RAM - Runtime data (~37KB) |
| 2 | 0x008091C2 | 0x0080FFFF | 0x00 (DISABLED) | Protected RAM |
| 3 | 0x01000000 | 0x01000FFF | 0x05 (Read) | EEPROM - Calibration (4KB) |
| 4 | 0x00FFC800 | 0x00FFFFFF | 0x03 (Read) | Hardware registers (~14KB) |

### Permission Flags

| Flag | Meaning |
|------|---------|
| 0x00 | Disabled/protected - access denied |
| 0x03 | Read allowed (RAM/registers) |
| 0x04 | Read allowed (ROM) |
| 0x05 | Read allowed (EEPROM) |

---

## Memory Regions for Data Extraction

Based on the validation table, these regions can be read from CM550:

### 1. Firmware (ROM)
- **Address Range:** 0x00000000 - 0x0003FFFF
- **Size:** 256KB (262,144 bytes)
- **Contents:** Executable code, constant data, lookup tables
- **Extraction:** 5 requests at 0xD000 bytes each

### 2. Calibration Data (EEPROM)
- **Address Range:** 0x01000000 - 0x01000FFF
- **Size:** 4KB (4,096 bytes)
- **Contents:** Tunable parameters, customer calibration
- **Extraction:** Single request

### 3. Runtime Data (RAM)
- **Address Range:** 0x00800000 - 0x008091C2
- **Size:** ~37KB (37,314 bytes)
- **Contents:** Live sensor values, calculated values, state
- **Extraction:** 1 request at max block size

### 4. Hardware Registers
- **Address Range:** 0x00FFC800 - 0x00FFFFFF
- **Size:** ~14KB (14,336 bytes)
- **Contents:** Peripheral registers, I/O state
- **Note:** May contain volatile values

---

## Response Handling

### diagMemoryReadResponseBuilder()

**Location:** Found in CM550 firmware

This function constructs the response to GetDataByAddress (0x14) commands:

```c
void diagMemoryReadResponseBuilder(uint8_t* response, uint8_t* data, uint16_t length)
{
    response[0] = 0x14;           // Echo command
    response[1] = sequenceId;     // Echo sequence
    // Remaining bytes: raw memory data
    memcpy(response + 2, data, length);
}
```

**Response Format:**
```
Byte 0:    Command echo (0x14)
Byte 1:    Sequence ID echo
Bytes 2+:  Raw memory data
```

---

## Implementation Notes for CM550

### Recommended Session Flow for CM550

```
1. Send Transport Open request
2. Receive Seed Reply (store for logging, but ignore for auth)
3. Set session state to AUTHENTICATED immediately
4. Proceed with data requests
```

### Memory Dump Strategy

To extract full CM550 firmware:

```python
# Chunk size limited by protocol
CHUNK_SIZE = 0xD000  # 52,224 bytes

# ROM extraction (256KB)
for offset in range(0, 0x40000, CHUNK_SIZE):
    length = min(CHUNK_SIZE, 0x40000 - offset)
    data = read_memory(0x00000000 + offset, length)
    file.write(data)

# EEPROM extraction (4KB)
data = read_memory(0x01000000, 0x1000)
file.write(data)
```

---

## Open Questions for Other ECU Types

While CM550 has minimal security, other Cummins ECUs may differ:

1. **ISX/ISB engines** - May have active security enforcement
2. **Newer ECUs** - Likely require proper seed/key encryption
3. **Encryption algorithm** - Still needs reverse engineering for secured ECUs:
   - Location: `DeviceControl_ghidra.c:67039-67207`
   - Type: 64-bit block cipher, 32 rounds
   - Key derivation: Seed + hardcoded values

---

## Firmware Analysis References

| File | Description |
|------|-------------|
| `firmware/J90280.05_analysis/ghidra/CM550.rep/working/J90280.05.ghidra.c` | Full CM550 decompilation |
| Function at 0x00027e98 | systemSecurityCheck() |
| Function at 0x0002b544 | addressRangeValidator() |
| Function at 0x0001b7e8 | diagnosticServiceSecurityValidator() |
| Address 0x0002B512 | Address range validation table |
