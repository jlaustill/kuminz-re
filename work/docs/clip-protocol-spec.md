# Cummins ECU Communication Protocol Specification

This document describes the communication protocols used by Insite/Calterm to communicate with Cummins ECUs, reverse engineered from the Insite 9 decompilation.

## Protocol Stack Overview

```
+--------------------------------------------------+
|           Application Layer (UI/Services)        |
|    ECMServices.dll (.NET), CaltermApplication    |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|          Protocol Implementation Layer           |
|    CLIPProtocolManager, J1939CPPProtocolManager  |
|                  PCLSystem.dll                   |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|              DPA (Device Protocol Adapter)       |
|    MailBox operations, buffer management         |
|                  datalink.dll                    |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|              Hardware Driver Layer               |
|    DPAS32.DLL (CommLink), DPAI32.DLL (PCCard)   |
+--------------------------------------------------+
                        |
+--------------------------------------------------+
|              Physical Layer (CAN Bus)            |
|    SocketCAN / SLCAN / OBDLink adapters         |
+--------------------------------------------------+
```

## Supported Protocol Types

From `Cummins.INSITE.Kernel.ECMServicesCommonTypes.Protocol`:

| Value | Name    | Description |
|-------|---------|-------------|
| 0     | Image   | Calibration image/file protocol |
| 1     | ICL     | Insite Communications Library |
| 2     | CC      | Cummins Communications (legacy) |
| 3     | PJ1939  | J1939 CAN protocol |
| 4     | UDS     | Unified Diagnostic Services (ISO 14229) |
| 5     | PCL     | Protocol Communications Library (CLIP) |

## J1939 Addressing for CLIP

**IMPORTANT: CLIP uses J1939 Proprietary A (PGN 0xEF00), NOT the Request PGN (0xEA00)!**

### CAN Arbitration ID Format (29-bit Extended)

| Bits | Field | Description |
|------|-------|-------------|
| 28:26 | Priority | 6 for CLIP messages |
| 25:24 | Reserved | 0 |
| 23:16 | PF | **0xEF** (Proprietary A) |
| 15:8 | PS | Destination address |
| 7:0 | SA | Source address |

### CLIP Message Addressing

| Direction | Arb ID Example | Description |
|-----------|----------------|-------------|
| Tool → ECU | `0x18EF00F9` | PF=0xEF, Dest=0x00 (ECU), Src=0xF9 (Tool) |
| ECU → Tool | `0x18EFF900` | PF=0xEF, Dest=0xF9 (Tool), Src=0x00 (ECU) |

### Common Mistake

**PF=0xEA (PGN 0xEA00) is the J1939 Request PGN** - used to request data from OTHER PGNs, NOT for CLIP data transport. Sending CLIP frames on PF=0xEA will result in ECU NACK responses.

### Verified with CM550 (2024-12)

```
TX: 18EF00F9 [8] 02 01 FF 01 00 00 00 00   ← Correct: PF=0xEF
RX: 18EFF900 [8] 0D 18 02 FF FF FF FF FF   ← ECU responds on PF=0xEF
```

---

## CLIP Frame Format

### CAN Frame Structure (8 bytes)

| Byte | Field | Description |
|------|-------|-------------|
| 0 | SessionId (3 bits) + MsgType (5 bits) | `(session << 5) \| msgType` |
| 1 | ConnectionId | Session/connection identifier |
| 2 | Control | Control flags / response type |
| 3-7 | Payload | Up to 5 bytes of payload data |

### Message Types (Byte 0, lower 5 bits)

| Value | Name | Direction | Description |
|-------|------|-----------|-------------|
| 0x02 | TransportOpen | Tool → ECU | Session open request |
| 0x03 | DataTransfer | Bidirectional | Data transfer (sequence in upper 3 bits) |
| 0x04 | ClearToSend | ECU → Tool | Flow control acknowledgment |
| 0x05 | ConnectionRefused | ECU → Tool | Session rejected |
| 0x06 | TransportClose | Bidirectional | Session close request |
| **0x0C** | **CTSAcknowledge** | **ECU → Tool** | **CTS acknowledgment (CM550)** |
| **0x0D** | **SessionOpenResponse** | **ECU → Tool** | **Session accepted (CM550 variant)** |

**Note**: The Insite tool expects ECU to respond with byte[0]==0x02 for transport open response, but CM550 firmware uses 0x0D. This may be a protocol version difference.

### Control Byte Values (Byte 2)

| Value | Name | Description |
|-------|------|-------------|
| 0x02 | SeedReply | ECU is providing security seed |
| 0x03 | DataAck/Error? | ECU acknowledging DataTransfer (echoes msgType) |
| 0x04 | ContextReply | ECU context/status response |
| 0x23 | DataAck seq=1 | ECU acknowledging DataTransfer seq=1 |

### Session Open Exchange (CM550)

**Tool Request**:
```
Byte 0: 0x02 (TransportOpen)
Byte 1: 0x01 (Tool's requested connection ID)
Byte 2: 0xFF (Control: request)
Byte 3: 0x01 (Flags)
Byte 4-7: 0x00 (Reserved)
```

**ECU Response** (CM550-specific):
```
Byte 0: 0x0D (SessionOpenResponse - CM550 uses this instead of 0x02)
Byte 1: 0x18 (ECU-assigned connection ID)
Byte 2: 0x02 (Control: SeedReply)
Byte 3-6: Seed (0xFFFFFFFF = no security required?)
Byte 7: 0xFF (Padding)
```

### CM550 Communication Test Results (December 2024)

**Successful Operations:**

1. **Session Open** - Works correctly
   - TX: `02 01 FF 01 00 00 00 00`
   - RX: `0D 18 02 FF FF FF FF FF` (SeedReply, connId=0x18, seed=0xFFFFFFFF)

2. **CTS Authentication** - Works correctly
   - TX: `04 18 01 01 00 00 00 00` (CTS with ECU connId)
   - RX: `0D 04 04 18 01 FF FF FF` (ContextReply = authenticated)

3. **Session Close** - Works correctly
   - TX: `06 18 00 ...` (TransportClose)
   - RX: `0C ...` (Close acknowledgment)

**Unresolved: DataTransfer Instruction Format**

Extensive testing of multiple frame formats (Dec 2024):

**Format Variations Tested:**

| Test | byte[1] (connId) | byte[2] (control) | Result |
|------|------------------|-------------------|--------|
| A | ECU's (0x18) | 0x00 | Echo 0x0D + msgType |
| B | Local (0x01) | ECU's (0x18) | Echo 0x0D + msgType |
| C | Local (0x01) | 0x08 (length) | Echo 0x0D + msgType |
| D | ECU's (0x18) | 0x13 (cmd) | Echo 0x0D + msgType |

**8-Byte Instruction Format (from Insite decompilation):**
```
[cmd(1)] [reqId(1)] [addr(4, big-endian)] [len(2, big-endian)]
Example: 13 01 00 80 00 00 00 10 = getDataByAddress(0x00800000, 16)
```

**DataTransfer Frame Format:**
```
byte[0]: (sequence << 5) | 0x03  (e.g., 0x03 for seq=0, 0x23 for seq=1)
byte[1]: connection ID
byte[2]: control byte
bytes[3-7]: instruction data (5 bytes per frame)
```

**Observed ECU Response Pattern:**
```
All DataTransfer → 0x0D [connId] [echo_msgType] FF FF FF FF FF
  - TX: 03 18 00 13 01 00 80 00
  - RX: 0D 18 03 FF FF FF FF FF  (control=0x03 echoes our msgType)

  - TX: 23 18 00 00 00 10 00 00
  - RX: 0D 18 23 FF FF FF FF FF  (control=0x23 echoes our seq+msgType)
```

The ECU consistently acknowledges receipt but never returns actual data.

**Current Hypotheses:**

1. **Incomplete Authentication**: After receiving seed=0xFFFFFFFF, Insite sends a proper context request (0x01 0x03 + encrypted tool context data) rather than CTS. The ECU accepts CTS as valid for session establishment but may require proper tool context for data operations.

2. **Different CLIP Variant**: The CM550 may use an older/different CLIP protocol version that doesn't support getDataByAddress (0x13). The ECU's echo behavior (0x0D + msgType) may indicate "command not supported" rather than "command received".

3. **Missing State Transition**: From Insite analysis, session states are:
   - State 4: Requesting seed
   - State 5: Seeded (waiting for context)
   - State 3: Session established (ready for data)

   We may be stuck in state 5 because we sent CTS instead of context request.

4. **Parameter ID Required**: CM550 might only support parameter-based reads (getAddressByParameterID 0x15) rather than direct memory reads (getDataByAddress 0x13).

**J1939 Standard PGN Support Test Results (December 2024):**

Major breakthrough! The CM550 ECU **DOES respond to standard J1939 PGN requests** with actual data!

**Working PGNs (Return Real Data):**

| PGN | Name | Example Response | Decoded Value |
|-----|------|-----------------|---------------|
| 0xF003 | EEC3 - Engine Controller 3 | `F9 FE FE 00 FF FF FF FF` | Friction Torque = 249% |
| 0xFEE5 | Engine Hours/Revolutions | `C8 D5 03 00 FF FF FF FF` | **12,566.8 engine hours** |
| 0xFEE9 | Fuel Consumption (Liquid) | `6A 85 03 00 6A 85 03 00` | Fuel data |
| 0xFEEE | Engine Temperature 1 | `88 17 FF FF FF FF FF FF` | **96°C coolant temp** |
| 0xFEEF | Engine Fluid Level/Pressure 1 | `FF FF 00 56 FF FF 00 FF` | Pressure data |
| 0xFEF1 | CCVS - Cruise/Vehicle Speed | `F3 00 00 50 00 68 00 C0` | Speed data |
| 0xFEF5 | Ambient Conditions | `00 FF FF FF FF FF FF FF` | Ambient data |
| 0xFECA | Engine Configuration | Multi-frame (J1939 TP) | **50 bytes via TP.CM/TP.DT** |
| 0xFECE | DM6 - Pending DTCs | `0C 02 00 00 00 00 00 10` | DTC status |

**Not Supported PGNs (NACK 0x01):**

| PGN | Name |
|-----|------|
| 0xF002 | Electronic Throttle Controller |
| 0xF004 | EEC1 (RPM, Torque) - **Surprisingly not supported** |
| 0xF005 | ETC1 - Electronic Transmission Controller |
| 0xFD09 | High Resolution Fuel Consumption |
| 0xFDC5 | ECU Identification Information |
| 0xFDD1 | Engine Fluid Level/Pressure 2 |
| 0xFEAE | Air Supply Pressure |
| 0xFEC1 | EEC2 |
| 0xFECF | DM12 - Emissions DTCs |
| 0xFED3 | DM2 - Previously Active DTCs |
| 0xFEDA | Software Identification |
| 0xFEDB | Component Identification |
| 0xFEDF | EEC Composite |
| 0xFEFC | Dash Display |

**Engine Configuration Multi-Frame Response:**

The Engine Configuration PGN (0xFECA) returns a large response via J1939 Transport Protocol:
```
TX: 18EA00F9 [3] CA FE 00  (Request PGN 0xFECA)
RX: 18ECFF00 [8] 20 32 00 08 FF CA FE 00  (TP.CM - BAM, 50 bytes, 8 frames)
RX: 18EBFF00 [8] 01 04 FF 00 0B 64 81 00  (TP.DT frame 1)
RX: 18EBFF00 [8] 02 0D E2 81 00 0D 23 81  (TP.DT frame 2)
... (6 more frames)
```

**Decoding Examples:**

1. **Engine Hours (PGN 0xFEE5):**
   - Bytes 0-3: `C8 D5 03 00` = 0x0003D5C8 = 251,336
   - Resolution: 0.05 hours/bit
   - Actual: 251,336 × 0.05 = **12,566.8 hours**

2. **Engine Temperature (PGN 0xFEEE):**
   - Byte 0: `88` = 136 decimal
   - Offset: -40°C
   - Actual: 136 - 40 = **96°C coolant temperature**

**Implications:**

- **Standard J1939 data access WORKS** for many engine parameters
- **CLIP DataTransfer remains non-functional** - ECU just echoes messages
- The CM550 may have limited CLIP instruction support
- **Recommended approach: Hybrid J1939 + CLIP**
  - Use CLIP for session establishment and authentication
  - Use standard J1939 PGN requests for data retrieval
  - Some large responses (Engine Configuration) use J1939 Transport Protocol

**Note on EEC1 (0xF004):**

The CM550 surprisingly does NOT support EEC1 via J1939 Request PGN, which normally contains engine RPM and torque. This might mean:
1. The CM550 broadcasts EEC1 periodically instead of on-request
2. EEC1 requires CLIP authentication to access
3. The CM550 uses a different PGN for RPM data

**J1939 Transport Protocol Notes:**

The Engine Configuration response demonstrates J1939 TP usage:
- `0x18ECFF00` = TP.CM (Connection Management) broadcast
- `0x18EBFF00` = TP.DT (Data Transfer) broadcast
- BAM (Broadcast Announce Message) mode: `20 32 00 08` = 50 bytes, 8 packets

**Additional Format Variations Tested (December 2024):**

| Test | Format Description | Result |
|------|-------------------|--------|
| A | Control = total message length (0x08) | Echo 0x0D + msgType |
| B | msgType = 0x02 (TransportOpen-like) | Echo 0x0D + 0x02 |
| C | Pure msgType 0x03 without sequence bits | Echo 0x0D + msgType |
| D | getAddressByParameterID (0x15) | Echo 0x0D + msgType |
| E | Local connId (0x01) for DataTransfer | Echo 0x0D + msgType |
| G | Instruction embedded in context format (0x01 0x03 + cmd) | Echo 0x0D + msgType |

**Next Steps:**
1. ~~Try sending proper context request (0x01 0x03) after seed reply instead of CTS~~ (Done - same echo behavior)
2. ~~Try getAddressByParameterID (0x15) command~~ (Done - same echo behavior)
3. Analyze CM550 firmware directly when Ghidra is available
4. Capture real Insite traffic for comparison
5. Try common J1939 engine PGNs (EEC1, etc.) via standard J1939 Request
6. Investigate if CM550 uses completely different data layer on top of CLIP session

---

## CLIP Protocol (PCL)

**Source**: `insite9/decompiled/native/PCLSystem_ghidra.c`
**Build Date**: Wed May 16 12:00:29 2012

### Key Constants

| Constant | Value | Description |
|----------|-------|-------------|
| Default Timeout | 60,000 ms | Response timeout for all CLIP operations |
| Max Write Params | 256 | Maximum parameters per write batch |
| Close Message Timeout | 1,000 ms | Timeout for session close |

### CLIPProtocolManager Methods

| Method | Source Line | Description |
|--------|-------------|-------------|
| `connect()` | 44568 | Establish connection to ECU |
| `closeSession()` | 45421 | Close current session |
| `close()` | 45491 | Full connection teardown |
| `requestGetParameterValues()` | 44671 | Read parameters by name |
| `requestGetParameterValueByIDs()` | 44742 | Read parameters by ID |
| `requestSetParameterValues()` | 44816 | Write parameters (max 256) |
| `requestSetParameterValueByID()` | 44902 | Write single parameter by ID |
| `requestSetSessionAccess()` | 44964 | Establish session access level |
| `requestExecuteService()` | 45053 | Execute ECU service/command |
| `requestGetParameterAddress()` | 45227 | Get parameter memory address |
| `instructionSplitResponse()` | 45567 | Handle split response messages |
| `getDefaultAppTimeoutMsec()` | 43068 | Returns 60000 (60 seconds) |

### Session Management

#### Connection Flow
```
1. CLIPProtocolManager::connect()
   - Validates address (wildcards not supported)
   - Creates client RX filter (PCLClientRxFilter)
   - Initializes session state

2. CLIPProtocolManager::requestSetSessionAccess()
   - Establishes session access level
   - Increments session state counter at offset 0x76
   - Error if session already in bad state

3. [Perform operations...]

4. CLIPProtocolManager::closeSession()
   - Sends "CLIPCloseMsgRequest" message
   - 1000ms timeout for close acknowledgment
   - Sets close-pending flag at offset 0x75

5. CLIPProtocolManager::close()
   - Full cleanup including RX filter removal
   - Sets state to "closed" (value 3 at offset 0x2c)
```

#### Session Validation

All CLIP operations check `*(char*)((int)this + 0x74)` for session validity:
- `0x00` = Valid session
- Non-zero = Invalid session (throws "No valid Session available")

### Error Messages

| Error | Context |
|-------|---------|
| "Wildcard (*) address spec is not supported" | connect() with invalid address |
| "No valid Session available" | Any operation without active session |
| "Must request at least one parameter" | Empty parameter list |
| "Sorry - CLIP only supports writing max 256 parameter at a time." | Write batch too large |
| "Input Arguments Expected !!" | Service execution missing args |
| "Wrong Input Arguments, Refer Metadata!!" | Service args don't match metadata |
| "Wrong number of Input Arguments!!" | Service arg count mismatch |
| "Response timeout" | 60 second timeout exceeded |
| "Error in ProtocolManager::closeSession()" | Close operation failed |
| "Not a Service" | ExecuteService called on non-service parameter |

## J1939 Protocol (PJ1939)

**Source**: `insite9/decompiled/native/PCLSystem_ghidra.c`
**Build Date**: Mon Jan 23 21:46:16 2012

### J1939CPPProtocolManager Methods

| Method | Source Line | Description |
|--------|-------------|-------------|
| `connect()` | 43305 | Establish J1939 connection |
| `requestSetSessionAccess()` | 42634 | Set session access level |
| `requestGetParameterAddress()` | 42675 | Get parameter memory address |
| `requestGetValueByAddress()` | 42720 | Read value at memory address |
| `requestSetValueByAddress()` | 42770 | Write value at memory address |
| `requestExecuteService()` | 42823 | Execute ECU service |
| `requestSetParameterValueByID()` | 42867 | Write parameter by ID |
| `setCPPPassword()` | 42899 | Set CPP authentication password |
| `requestGetParameterValues()` | 43391 | Read parameters by name |
| `requestSetParameterValues()` | 43516 | Write parameters |
| `syncNotifyRxMsg()` | 43009 | Handle received message |

### Password Authentication

J1939 protocol supports password authentication via `setCPPPassword()`:

```c
// Password is 6 bytes stored at offset 0x7c-0x81 in protocol manager
*(undefined4*)((int)this + 0x7c) = *param_1;        // First 4 bytes
*(undefined2*)((int)this + 0x80) = *(param_1 + 1);  // Last 2 bytes
```

### Address-Based Operations

Unlike CLIP which uses parameter names/IDs, J1939 supports direct memory address operations:
- `requestGetValueByAddress()` - Read from ECU memory address
- `requestSetValueByAddress()` - Write to ECU memory address

## DPA Layer (Device Protocol Adapter)

**Source**: `insite9/decompiled/native/datalink_ghidra.c`

### Device Types

DPA routes operations based on device type bitmask:

| Bitmask | Device | DLL |
|---------|--------|-----|
| 0x0000  | CommLink (Serial) | DPAS32.DLL |
| 0x8000  | PCCard | DPAI32.DLL |
| 0x4000  | Reserved | Error 0x21 |

### DPA Functions

| Function | Description |
|----------|-------------|
| `InitDPA(param_1, param_2)` | Initialize device, routes to InitCommLink or InitPCCard |
| `RestoreDPA(param_1)` | Restore device state based on bitmask |
| `LoadDPABuffer(...)` | Load data into DPA buffer |
| `ReadDPABuffer(...)` | Read data from DPA buffer |

### MailBox Operations

The MailBox system manages CAN frame queuing:

| Function | Description |
|----------|-------------|
| `LoadMailBox(handle, data)` | Queue a frame for transmission |
| `UnloadMailBox(handle)` | Remove frame from queue |
| `TransmitMailBox(handle, data)` | Send frame synchronously |
| `TransmitMailBoxAsync(handle, data)` | Send frame asynchronously |
| `ReceiveMailBox(handle)` | Receive queued frame |
| `UpdateTransmitMailBox(...)` | Update pending transmit |
| `UpdateReceiveMailBox(...)` | Update pending receive |
| `UpdateTransMailBoxData(...)` | Update transmit data |
| `UpdateTransMailBoxDataAsync(...)` | Async transmit data update |

### DPA Configuration

Configuration is read from `dg121032.ini`:
- Value 0: CommLink device
- Value 1: PCCard device
- Value 2: Error (unsupported)

## Implementation Notes for kuminz-ui

### Recommended Approach

1. **Use CLIP (PCL) protocol** for modern ECU communication
2. **Fall back to J1939** for older ECUs or specific operations
3. **Implement 60-second timeout** for all operations
4. **Batch writes to 256 parameters maximum**
5. **Always establish session before operations**

### Session Lifecycle

```cpp
// Pseudo-code for kuminz-ui CLIP implementation

class ECUSession {
    bool connect(const QString& address) {
        // 1. Validate address (no wildcards)
        if (address.contains("*")) return false;

        // 2. Initialize transport layer (SocketCAN)
        // 3. Send connection request
        // 4. Wait for response (60s timeout)
        return true;
    }

    bool setSessionAccess(int level) {
        // Must be called after connect()
        // Sets read/write permissions
    }

    QVector<ParameterValue> getParameters(QStringList names) {
        // Must have valid session
        // At least one parameter required
    }

    bool setParameters(QMap<QString, QVariant> values) {
        // Must have valid session
        // Max 256 parameters per call
        if (values.size() > 256) {
            // Split into multiple calls
        }
    }

    void closeSession() {
        // Send CLIPCloseMsgRequest
        // 1000ms timeout
    }
};
```

## Source Files Reference

| File | Size | Key Content |
|------|------|-------------|
| `PCLSystem_ghidra.c` | 292 KB | CLIP & J1939 protocol managers |
| `datalink_ghidra.c` | ~50 KB | DPA MailBox layer |
| `Cummins.INSITE.Kernel.ECMServices.cs` | 57 KB | .NET facade |
| `Cummins.INSITE.Kernel.ECMServicesCommonTypes.cs` | 5 KB | Protocol enum |

## Related Tasks

- Task 003: CLIP Protocol Implementation (kuminz-ui)
- Task 009: Insite Reverse Engineering Process

---
*Generated from Insite 9 decompilation analysis - December 2024*
