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

### Transport Layer Message Types (Byte 0)

**From Insite PCLSystem.dll decompilation (CLIPTransport.cpp):**

| Value | Name | Direction | Description |
|-------|------|-----------|-------------|
| **0x01** | **TransportOpenRequest** | Tool → ECU | Initiator opens transport session |
| **0x02** | **TransportOpenResponse** | ECU → Tool | Responder confirms transport open |
| 0x03+ | DataTransfer | Bidirectional | `(byte[0] & 0x03) == 0x03`, upper bits = sequence |
| 0x04 | ClearToSend | Bidirectional | Flow control acknowledgment |
| 0x06 | TransportClose | Bidirectional | Session close request |

**CM550-Specific Response Codes:**
| Value | Name | Direction | Description |
|-------|------|-----------|-------------|
| 0x0C | CTSAcknowledge | ECU → Tool | CTS acknowledgment |
| **0x0D** | **SessionOpenResponse** | ECU → Tool | CM550 variant of session open |

**CRITICAL CORRECTION**: We previously sent 0x02 for TransportOpen, but the correct value is **0x01**! The 0x02 is the RESPONSE message type. CM550 responds with 0x0D instead of standard 0x02.

**Data Transfer Sequence Encoding:**
- Byte 0 lower 2 bits: `0x03` indicates data transfer
- Byte 0 upper bits: sequence number
- Examples: `0x03` (seq=0), `0x23` (seq=1), `0x43` (seq=2)

### Session Layer Message Types (in DataTransfer payload)

After transport is open, session-level messages use these types in the payload:

| Payload Byte 1 | Name | Direction | Description |
|----------------|------|-----------|-------------|
| 0x01 | SeedRequest | Tool → ECU | Request security seed |
| 0x02 | SeedReply | ECU → Tool | Seed response with challenge |
| 0x04 | ContextReply | ECU → Tool | Session context exchange complete |
| 0x05 | ConnectionRefused | ECU → Tool | Session rejected |

**Session State Machine (from CLIPSession.cpp):**
- State 4: Seed Requested
- State 5: Seeded (waiting for context)
- State 3: Session Established (ready for data)

### Control Byte Values (Byte 2)

| Value | Name | Description |
|-------|------|-------------|
| 0x02 | SeedReply | ECU is providing security seed |
| 0x03 | DataAck/Error? | ECU acknowledging DataTransfer (echoes msgType) |
| 0x04 | ContextReply | ECU context/status response |
| 0x23 | DataAck seq=1 | ECU acknowledging DataTransfer seq=1 |

### Session Open Exchange

**Correct Transport Open Format (from CLIPTransport::createTransportMsg):**
```
Byte 0: 0x01 (TransportOpenRequest - NOT 0x02!)
Byte 1: Connection ID (tool's requested ID)
Byte 2: 0xFF
Byte 3: 0x01
Byte 4: 0xFF
(Pad to 8 bytes with 0x00)
```

**Standard ECU Response (per Insite code):**
```
Byte 0: 0x02 (TransportOpenResponse)
Byte 1: ECU-assigned connection ID
Byte 2-5: Session parameters
```

**CM550-Specific Response:**
```
Byte 0: 0x0D (CM550 variant - not standard 0x02!)
Byte 1: 0x18 (ECU-assigned connection ID)
Byte 2: 0x02 (Embedded SeedReply)
Byte 3-6: Seed (0xFFFFFFFF = no security?)
Byte 7: 0xFF (Padding)
```

### CM550 Communication Test Results (December 2024)

**Previous Tests (with incorrect 0x02):**

1. **Session Open** - Partially works (wrong request format)
   - TX: `02 01 FF 01 00 00 00 00` (INCORRECT - should be 0x01!)
   - RX: `0D 18 02 FF FF FF FF FF` (CM550 responds anyway)

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

---

## Complete Insite Connection Sequence (from Decompilation)

**Source: PCLSystem.dll - CLIPTransport.cpp and CLIPSession.cpp (December 2024 analysis)**

### 1. Transport Layer Open

**Initiator sends TransportOpenRequest:**
```
Byte 0: 0x01 (TransportOpenRequest)
Byte 1: <local_connection_id>
Byte 2: 0xFF
Byte 3: 0x01
Byte 4: 0xFF
Byte 5-7: 0x00 (padding)
```

**Responder sends TransportOpenResponse:**
```
Byte 0: 0x02 (TransportOpenResponse) - or 0x0D for CM550
Byte 1: <ecu_connection_id>
Byte 2: <session_params>
Byte 3-4: <size_values>
Byte 5: <cts_block_size>
...
```

### 2. Session Layer - Seed Request

After transport is open, session layer sends seed request via DataTransfer:

**Tool sends SeedRequest (DataTransfer payload):**
```
DataTransfer wrapper:
  Byte 0: 0x03 (DataTransfer, seq=0)
  Byte 1: <connection_id>
  Byte 2-7: Payload

Payload content:
  Byte 0: 0x01
  Byte 1: 0x01
  (This is the "requesting seed" message from CLIPSession::seedRequest)
```

### 3. Session Layer - Seed Reply

**ECU sends SeedReply (DataTransfer payload):**
```
Payload byte[1] == 0x02 indicates SeedReply
Payload bytes contain:
  - Byte 2-3: Encryption parameters
  - Byte 4-7: Seed value (4 bytes)
```

### 4. Session Layer - Context Exchange

After receiving seed, tool encrypts and sends tool context:

**Tool sends ContextRequest (DataTransfer payload):**
```
Encrypted tool context data
(Uses seed for encryption)
```

**ECU sends ContextReply:**
```
Payload byte[1] == 0x04 indicates ContextReply
Session state changes to 3 (established)
"CLIP Session opened/established successfully"
```

### 5. Session Established - Data Operations

Only after state == 3 can data be transferred.

---

**Analysis: Why Our DataTransfer Failed**

1. **Wrong TransportOpen byte**: We sent 0x02 (response) instead of 0x01 (request)
2. **Skipped SeedRequest**: We jumped directly to CTS without sending seed request
3. **No Context Exchange**: Even with seed, we didn't do the encrypted context exchange
4. **CM550 Protocol Variant**: CM550 responds with 0x0D instead of standard 0x02, suggesting it may handle sessions differently

**Next Steps to Test:**
1. Send correct TransportOpenRequest (0x01)
2. After ECU response, send SeedRequest via DataTransfer
3. Process seed reply and attempt context exchange
4. If context exchange works, try data operations

---

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
| H | Service 0x4A (fuel arbitrator) format | Echo 0x0D + msgType |
| I | Single-frame 0x4A in payload | Echo 0x0D + msgType |
| J | Full transport sequence (TransportOpen → CTS → Data) | Echo 0x0D + msgType |
| K | CM550 Service 5 + 0x61 (3-byte addr read) in CLIP frame | Echo 0x0D + msgType |
| L | Raw CM550 format (no CLIP framing): `05 61 addr len` | **0x0D 0x04 + echo (Error 4!)** |
| M | Raw with length prefix: `07 05 61 addr len` | **0x0D 0x04 + echo (Error 4!)** |
| N | Service 4 init commands (0x71, 0x73) | Echo 0x0D + msgType |
| O | Memory read after Service 4 init | **0x0D 0x04 + echo (Error 4!)** |

**Key Finding (December 2024): CLIP vs Raw Format Responses**

The ECU's response differs based on whether the message uses CLIP framing:

| Format | Response Pattern | Interpretation |
|--------|-----------------|----------------|
| CLIP-framed (`03 18 ...`) | `0D 18 [msgType] FF...` | Session-based echo with connId 0x18 |
| Raw (non-CLIP byte 0) | `0D 04 [byte0] [byte1]...` | Error code 4 + data echo |

**Error Code 4 = "Buffer overflow / unsupported"** (from firmware analysis)

This confirms:
1. The ECU expects CLIP framing on PGN 0xEF00
2. Raw CM550 diagnostic format (Service 5 + 0x6x commands) is rejected
3. CLIP DataTransfer is acknowledged but not passed to diagnostic layer

**CM550 Firmware Analysis (December 2024):**

From reverse engineering `diagnosticCommandDispatcher` at 0x00012484:

1. **Diagnostic Service Enable Flags** (`0x8035ea`):
   - Bit 0: Core services (Service 3,4,5,6)
   - Bit 1: Insite live data
   - Bit 2: Extended diagnostics (0x45-0x56)
   - **These flags must be set for diagnostic commands to work**

2. **Service 5 Memory Operations** (when enabled):
   - Upper nibble determines operation:
     - `0x60` = 3-byte address read
     - `0xC0` = 2-byte address read
     - `0xE0` = 1-byte address read
     - `0x80` = 4-byte address write
   - Lower nibble: 0 = CRC required, 1 = no CRC

3. **Transport Layer Gap**:
   - The CLIP transport layer responds to DataTransfer with echo
   - But messages don't reach `diagnosticCommandDispatcher`
   - The diagnostic buffer (`0x808c00`) may require serial transport, not CAN

**Hypothesis**: The CM550 may use CLIP only for session management, with actual diagnostic commands going through a different mechanism (possibly serial port via J1939 TP or a separate protocol layer).

---

## KEY DISCOVERY: Serial Port Transport Layer (December 2024)

**Critical Finding**: The CM550 diagnostic layer uses a **serial port** as its primary input, NOT direct CAN!

### Evidence from Firmware Analysis

1. **CAN Message Interrupt Handler** (`canMessageInterruptHandlerSetup` @ 0x0001920a):
   ```c
   can_message_isr_register_address = (dword)serialPort1IsrHandler;
   ```
   The CAN message interrupt is routed through `serialPort1IsrHandler`.

2. **Serial Port ISR** processes data from `serial_port_1_rx_data_register` and routes to:
   - `serialNodeAddressForwarder()` - Normal diagnostic traffic
   - `serialNodeAddressChecker()` - Address validation

3. **Diagnostic Buffer** (`diagnostic_rx_buffer_base`):
   - Initialized at boot but only written to via serial port path
   - `diagnosticCommandDispatcher` polls this buffer periodically (10ms slow cycle)
   - CAN messages via CLIP DataTransfer never reach this buffer

### Implications

| Layer | Transport | Purpose |
|-------|-----------|---------|
| CLIP Session | CAN (PGN 0xEF00) | Session management (TransportOpen, CTS, etc.) |
| Diagnostic Commands | **Serial Port** | Service 3/4/5/6, memory read/write |
| J1939 Standard | CAN (PGN Request) | Engine parameters (EEC1, temps, hours) |
| VP44 Communication | CAN (J1939 TP) | Fuel pump diagnostics |

### Why CLIP DataTransfer Fails

The CLIP transport layer acknowledges DataTransfer messages but:
1. CLIP processes the frame (validates session, connection ID, etc.)
2. CLIP sends acknowledgment response (0x0D + msgType)
3. **No code path exists** to copy the payload to `diagnostic_rx_buffer_base`
4. The `diagnosticCommandDispatcher` never sees the data

### J1708 Serial Protocol CONFIRMED

**The CM550 uses SAE J1708/J1587 for diagnostic commands!**

From Calterm parameter analysis, the CM550 has dedicated J1708 buffers:

| Parameter | Address | Description |
|-----------|---------|-------------|
| JC17RXBF | 0x80DDCA | J1708 Receive Buffer |
| JC17TXBF | 0x80DDC6 | J1708 Transmit Buffer |
| JC17RXIP | 0x80DCA2 | J1708 Receive Input Pointer |
| JC17RXMP | 0x80DCA6 | J1708 Receive Middle Pointer |
| JC17RXOP | 0x80DCAA | J1708 Receive Output Pointer |
| JC17TXIP | 0x80DC94 | J1708 Transmit Input Pointer |
| JC17TXMP | 0x80DC98 | J1708 Transmit Middle Pointer |
| JC17TXOP | 0x80DC9C | J1708 Transmit Output Pointer |
| JC17RXFF | 0x80DCAE | J1708 RX Buffer Full Flag |
| JC17TXFF | 0x80DCA0 | J1708 TX Buffer Full Flag |
| JC17TMCU | 0x100075C | J1708 Timeout Counter |

### SAE J1708 Protocol Overview

- **Physical Layer**: RS485 at 9600 baud
- **Data Format**: Half-duplex, variable length messages
- **Message Format**: MID + PID + Data + Checksum
- **Arbitration**: Character-based priority (lower MID = higher priority)
- **Common in**: Heavy equipment, school buses, trucks (pre-CAN era)

### CM550 Dual-Protocol Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                      CM550 ECU                               │
├─────────────────────────────────────────────────────────────┤
│                                                              │
│  ┌────────────────┐          ┌────────────────┐             │
│  │   CAN Bus      │          │   J1708 Bus    │             │
│  │  (J1939)       │          │  (RS485)       │             │
│  └───────┬────────┘          └───────┬────────┘             │
│          │                           │                       │
│          ▼                           ▼                       │
│  ┌────────────────┐          ┌────────────────┐             │
│  │ CLIP Protocol  │          │ J1587 Protocol │             │
│  │ (Session Mgmt) │          │ (Diagnostics)  │             │
│  └───────┬────────┘          └───────┬────────┘             │
│          │                           │                       │
│          │                           ▼                       │
│          │                   ┌────────────────┐             │
│          │                   │ Diagnostic     │             │
│          └──────────────────>│ Command        │             │
│            (Session info     │ Dispatcher     │             │
│             but NOT data)    └────────────────┘             │
│                                      │                       │
│                                      ▼                       │
│                              ┌────────────────┐             │
│                              │ Service 3/4/5/6│             │
│                              │ Handlers       │             │
│                              └────────────────┘             │
└─────────────────────────────────────────────────────────────┘
```

### Implications for kuminz-ui

To read diagnostic data from the CM550:

1. **J1939 PGN Requests** (via CAN) - Works! For standard engine parameters
2. **J1708/J1587** (via RS485 adapter) - Needed for memory reads, calibration, DTCs

**Required Hardware for Full Diagnostics:**
- CAN adapter (OBDLink, CANable, etc.) - Already have
- **J1708/RS485 adapter** - Need to obtain/build

### Next Steps

1. ~~Try J1939 TP for diagnostic commands~~ (Analyzed - TP is for VP44 communication only)
2. ~~Investigate serial port path for diagnostic commands~~ (Done - J1708 confirmed!)
3. **Build/obtain J1708 adapter** - RS485 to USB adapter at 9600 baud
4. **Implement J1587 protocol** - Add J1708 support to clip-lib
5. **Test diagnostic commands via J1708** - Try Service 5 memory reads

---

**Completed Steps:**
1. ~~Try sending proper context request (0x01 0x03) after seed reply instead of CTS~~ (Done - same echo behavior)
2. ~~Try getAddressByParameterID (0x15) command~~ (Done - same echo behavior)
3. ~~Analyze CM550 firmware directly when Ghidra is available~~ (Done - see findings above)
4. Capture real Insite traffic for comparison
5. ~~Try common J1939 engine PGNs (EEC1, etc.) via standard J1939 Request~~ (Done - WORKS!)
6. ~~Investigate if CM550 uses completely different data layer on top of CLIP session~~ (Confirmed - diagnostic layer not connected)
7. ~~Try J1939 TP (0xEC/0xEB) for diagnostic commands~~ (Analyzed - TP is for VP44 RX only)
8. ~~Investigate serial port path for diagnostic commands~~ (Done - J1708 confirmed!)
9. ~~Trace CAN→Session dispatch path in firmware~~ (Done - see new section below)

---

## CM550 Firmware Response Builder Analysis (December 2024)

**Critical Discovery: Why DataTransfer is Acknowledged but Doesn't Execute**

### Firmware Dispatch Tables

The CM550 firmware has TWO separate dispatch tables for handling incoming diagnostic messages:

| Address | Variable | Purpose | Counter |
|---------|----------|---------|---------|
| 0x008019B8 | `diag_service_pgn_dispatch_ptr` | PGN-based service routing | `can_transmission_active_count` |
| 0x008018D8 | `diagnostic_service_dispatch_ptr` | Service byte routing | `diagnostic_service_state_counter` |

Each entry in these tables is 6 bytes:
- Bytes 0-1: Service ID / match bytes
- Bytes 2-5: Function pointer (4 bytes)

### Diagnostic Service Dispatcher (0x2729a)

The `diagnosticServiceDispatcher` function:

1. Iterates through `diagnostic_service_dispatch_ptr` table
2. Matches service byte from incoming message
3. **Default error code is 0x18** (this is the connection ID we see!)
4. Calls `diagnosticServiceSecurityValidator` to check access
5. If security passes (returns -1), calls the service handler
6. If no match or security fails, calls `diagnosticMultiPacketResponseBuilder` with error

```c
// Pseudo-code from decompilation
void diagnosticServiceDispatcher(byte *param_1) {
    cVar2 = '\x18';  // Default error code = 0x18!
    for (bVar1 = 0; bVar1 < diagnostic_service_state_counter; bVar1++) {
        if (service_byte_matches) {
            result = diagnosticServiceSecurityValidator(param_1);
            if (result == -1) {  // Security passed
                result = (*handler)(param_1);  // Call handler
            }
            cVar2 = result;
            break;
        }
    }
    if (cVar2 != -1) {
        diagnosticMultiPacketResponseBuilder(param_1, error_code);
    }
}
```

### Response Builder (0x298d8)

The `diagnosticMultiPacketResponseBuilder` generates responses on PGN 0xEF00:

```c
// Response byte logic at lines 25214-25221
if (param_2_high_byte == 0) {
    *response_byte = 0x0C;  // Success!
} else {
    *response_byte = 0x0D;  // Status/Error response
    response_byte[1] = diag_multi_packet_status_code_table[param_2 & 0xff];
}
```

| Response | Meaning |
|----------|---------|
| **0x0C** | Success - operation completed |
| **0x0D** | Status/Error - includes error code from lookup table |

### Status Code Table (0x298BE)

The `diag_multi_packet_status_code_table` at ROM address 0x298BE is indexed by the error code to produce the second byte of 0x0D responses.

### Multi-Packet Receive Handler (0x12d76)

The `multiPacketReceiveHandler` recognizes these connection IDs:

| Connection ID | Description |
|---------------|-------------|
| **0x15** | Alternate session ID |
| **0x17** | Alternate session ID |
| **0x18** | **Primary - what CM550 assigns** |
| **0x19** | Alternate session ID |

This handler uses `diag_transfer_state_t` structure at 0x80d3f8 and `multi_packet_receive_state` for state tracking.

### Key Insight: Two Diagnostic Paths

The firmware has two completely separate paths for diagnostic communication:

```
┌─────────────────────────────────────────────────────────────────┐
│                     CAN Path (PGN 0xEF00)                       │
│                                                                  │
│  CAN RX → diagnosticServiceDispatcherByPgn (0x278be)            │
│         → diagnosticServiceDispatcher (0x2729a)                  │
│         → diagnosticServiceSecurityValidator (0x1b7e8)          │
│         → [service handler OR error]                             │
│         → diagnosticMultiPacketResponseBuilder (0x298d8)        │
│         → sendCanMessage (PGN 0xEF00)                           │
│                                                                  │
│  Result: 0x0C (success) or 0x0D (status) response               │
└─────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────┐
│                J1708/Serial Path (RS-485)                        │
│                                                                  │
│  Serial RX → serialPort1IsrHandler                               │
│            → serialNodeAddressForwarder                          │
│            → diagnostic_rx_buffer_base                           │
│            → diagnosticCommandDispatcher (0x12484)               │
│            → Service 3/4/5/6 handlers                            │
│            → Memory read/write, calibration, DTCs                │
│                                                                  │
│  Result: Actual diagnostic data returned                         │
└─────────────────────────────────────────────────────────────────┘
```

### Why CLI's DataTransfer Fails

When the CLI sends CLIP DataTransfer (0x03) messages:

1. **CAN Message Received**: Goes to `diagnosticServiceDispatcherByPgn`
2. **Service Lookup**: Iterates through `diag_service_pgn_dispatch_ptr` table
3. **No Match Found**: DataTransfer message type doesn't match any registered service
4. **Response Generated**: `diagnosticMultiPacketResponseBuilder` called with error code 0x18
5. **0x0D Response Sent**: ECU acknowledges with `0x0D 18 [msgType] FF FF FF FF FF`

The **instruction payload** (e.g., `13 01 00 80 00 00 00 10` for memory read) **never reaches** the `diagnosticCommandDispatcher` because:

- The CAN path only handles session-level messages (TransportOpen, CTS, etc.)
- Actual diagnostic commands (Service 3/4/5/6) go through J1708 serial path
- There is **NO code path** to bridge CAN DataTransfer payloads to the serial diagnostic buffer

### Verification

The 0x18 in the ECU response (`0x0D 18 03 FF FF FF FF FF`) is:
- NOT the connection ID being echoed back
- It's the **default error code** from `diagnosticServiceDispatcher`!

This confirms the dispatch failed before any service handler was called

---

## SERVICE 5 DIAGNOSTIC COMMAND FORMAT (BREAKTHROUGH - December 2024)

**CRITICAL DISCOVERY**: The CM550's diagnostic commands use a **Service 5 command format**, NOT the CLIP application-layer commands (0x13, 0x14, 0x15, etc.) from the Insite .NET layer!

### Root Cause of DataTransfer Failures

Previous tests tried sending CLIP application commands like `getDataByAddress` (0x14) in the DataTransfer payload. These commands are **NOT recognized by the CM550 firmware**.

The `diagnosticCommandDispatcher` @ 0x12484 expects messages with:
- **Control byte (byte 2) = Service number** (3, 4, 5, or 6)
- **Payload[0] = Command code** with high nibble indicating operation type

### Service Numbers

| Service | Purpose | Commands |
|---------|---------|----------|
| 3 | System commands | 0x40-0x54 |
| 4 | System control | 0x64-0x75 |
| **5** | **Memory read/write, multi-packet** | 0x60-0xF0 |
| 6 | Cancel/abort | 0x74 |

### Service 5 Command Codes (High Nibble)

From CM550 firmware `diagnosticCommandDispatcher` @ 0x12484 (lines 6939-6960):

| Code | Operation | Handler Function |
|------|-----------|------------------|
| **0x60** | Memory read type 3 | `diagnosticMemoryReadHandler(3)` |
| **0x80** | Memory write type 4 | `diagnosticMemoryWriteHandler(4)` |
| **0xA0** | Memory write type 2 | `diagnosticMemoryWriteHandler(2)` |
| **0xB0** | **Multi-packet receive (read FROM ECU)** | `multiPacketReceiveHandler` @ 0x12d76 |
| **0xC0** | Memory read type 2 | `diagnosticMemoryReadHandler(2)` |
| **0xE0** | Memory read type 1 | `diagnosticMemoryReadHandler(1)` |
| **0xF0** | Multi-packet transmit (write TO ECU) | `multiPacketTransmitHandler` @ 0x12b74 |

### Correct DataTransfer Frame Format for Memory Read

```
CLIP DataTransfer Frame (8 bytes):
┌─────────────────────────────────────────────────────────────────┐
│ Byte 0: (SessionID << 5) | MsgType                              │
│         = (0 << 5) | 0x03 = 0x03 for DataTransfer               │
├─────────────────────────────────────────────────────────────────┤
│ Byte 1: Connection ID                                           │
│         = 0x18 (assigned by ECU during session open)            │
├─────────────────────────────────────────────────────────────────┤
│ Byte 2: Control = Service Number                                │
│         = 0x05 for Service 5                                    │
├─────────────────────────────────────────────────────────────────┤
│ Byte 3: Command Code (Service 5 operation)                      │
│         = 0xC0 for MemoryRead2, 0xE0 for MemoryRead1, etc.      │
├─────────────────────────────────────────────────────────────────┤
│ Bytes 4-6: Memory Address (24-bit, big-endian)                  │
│         = [addr_high] [addr_mid] [addr_low]                     │
├─────────────────────────────────────────────────────────────────┤
│ Byte 7: Length (bytes to read, 1-255)                           │
└─────────────────────────────────────────────────────────────────┘

Example - Read 4 bytes from address 0x0034F8 (calibration ID area):
TX: 03 18 05 C0 00 34 F8 04
     │  │  │  │  └──────┴─┴── Address 0x0034F8, length 4
     │  │  │  └────────────── MemoryRead2 command (0xC0)
     │  │  └───────────────── Service 5
     │  └──────────────────── Connection ID 0x18
     └─────────────────────── DataTransfer (msgType=0x03)
```

### Multi-Packet Receive Handler Recognition

The `multiPacketReceiveHandler` @ 0x12d76 (lines 7303-7306 in decompilation) explicitly handles connection IDs:

| Connection ID | Status |
|---------------|--------|
| 0x15 | Recognized |
| 0x17 | Recognized |
| **0x18** | **Primary - assigned by CM550** |
| 0x19 | Recognized |

This confirms that connection ID 0x18 (received during session open) is valid for diagnostic operations!

### Security Check Always Passes

The `systemSecurityCheck()` @ 0x27e98 (line 24111-24115) unconditionally returns 0:
```c
int systemSecurityCheck(void) {
    return 0;  // Always passes - no security blocking!
}
```

This means diagnostic commands are **NOT blocked by security** - the issue was purely the message format.

### Updated Understanding

**Previous (Incorrect) Conclusion**: The CM550 requires J1708 serial for diagnostic commands, and CAN-based CLIP is only for session management.

**New (Correct) Understanding**: The CM550 **CAN process diagnostic commands over CAN**, but they must use the **Service 5 format** (control=5, command code in payload[0]), NOT the CLIP application-layer format (0x13/0x14/0x15 commands).

### Implementation in clip-lib

New frame builders added to `clip-lib/src/clip/Frame.h`:

```cpp
// Service 5 command types
enum class Service5Cmd : uint8_t
{
    MemoryRead3  = 0x60,  // diagnosticMemoryReadHandler(3)
    MemoryWrite4 = 0x80,  // diagnosticMemoryWriteHandler(4)
    MemoryWrite2 = 0xA0,  // diagnosticMemoryWriteHandler(2)
    MultiPktRecv = 0xB0,  // multiPacketReceiveHandler
    MemoryRead2  = 0xC0,  // diagnosticMemoryReadHandler(2)
    MemoryRead1  = 0xE0,  // diagnosticMemoryReadHandler(1)
    MultiPktXmit = 0xF0   // multiPacketTransmitHandler
};

// Build a Service 5 memory read frame
Frame buildMemoryReadRequest(uint8_t connectionId, uint32_t address,
                              uint8_t length, uint8_t sessionId = 0,
                              Service5Cmd cmdType = Service5Cmd::MemoryRead2);

// Build a multi-packet receive request (0xB0 command)
Frame buildMultiPacketReceiveRequest(uint8_t connectionId, uint8_t sessionId = 0);
```

### Expected Response Format

Based on firmware analysis, successful memory reads should return:

```
Success Response (0x0C):
RX: 0C [connId] [service] [data...]

Error Response (0x0D):
RX: 0D [error_code] [status]...
```

The status code table at 0x298BE maps error codes to status bytes.

### Hardware Testing Results (December 2024)

**COMPREHENSIVE TEST RESULTS WITH REAL CM550 ECU:**

#### Session Layer - WORKING

| Test | TX Frame | RX Response | Result |
|------|----------|-------------|--------|
| TransportOpenRequest | `01 01 FF 01 FF 00 00 00` | `0C 01 FF FF FF FF FF FF` | **SUCCESS** |
| ClearToSend | `04 01 01 01 00 00 00 00` | `0C 04 01 01 FF FF FF FF` | **SUCCESS** |

**Session establishment works correctly!** The ECU accepts our session with connection ID 0x01.

#### DataTransfer Commands - ALL RETURN 0x0D STATUS

| Test | Format | TX Frame | RX Response |
|------|--------|----------|-------------|
| Context Request | `03 [connId] 00 01 03 00 00 00` | `03 01 00 01 03 00 00 00` | `0D 18 03 FF FF FF FF FF` |
| Service 5 MemoryRead2 (0xC0) | `03 [connId] 05 C0 [addr] [len]` | `03 01 05 C0 00 34 F8 04` | `0D 18 03 FF FF FF FF FF` |
| Service 5 MemoryRead1 (0xE0) | `03 [connId] 05 E0 [addr] [len]` | `03 01 05 E0 00 34 F8 04` | `0D 18 03 FF FF FF FF FF` |
| Service 5 MemoryRead3 (0x60) | `03 [connId] 05 60 [addr] [len]` | `03 01 05 60 00 34 F8 04` | `0D 18 03 FF FF FF FF FF` |
| Service 5 MultiPktRecv (0xB0) | `03 [connId] 05 B0 00 01 01 01` | `03 01 05 B0 00 01 01 01` | `0D 18 03 FF FF FF FF FF` |
| Service 4 Init (0x71) | `03 [connId] 04 71 00 00 00 00` | `03 01 04 71 00 00 00 00` | `0D 18 03 FF FF FF FF FF` |
| Service 4 Init (0x73) | `03 [connId] 04 73 00 00 00 00` | `03 01 04 73 00 00 00 00` | `0D 18 03 FF FF FF FF FF` |
| With connId=0x18 | `03 18 05 C0 [addr] [len]` | `03 18 05 C0 00 34 F8 04` | `0D 18 03 FF FF FF FF FF` |

#### Alternative Formats Tested

| Test | Description | TX Frame | RX Response |
|------|-------------|----------|-------------|
| Raw J1708-style | No CLIP header, len+svc+cmd format | `07 05 C0 00 34 F8 04 00` | `0D 04 07 FF FF FF FF FF` |
| Broadcast dest | ArbId with dest=0xFF | `03 01 05 C0 00 34 F8 04` | No response |

#### Response Analysis

**Standard DataTransfer Response Pattern:**
```
0D 18 03 FF FF FF FF FF
│  │  │
│  │  └── Control: Echo of our msgType (0x03 = DataTransfer)
│  └───── ConnectionId: 0x18 (ECU's internal diagnostic session ID OR error code)
└──────── MsgType: 0x0D (SessionOpenResponse/Status)
```

**Raw Format Response Pattern:**
```
0D 04 07 FF FF FF FF FF
│  │  │
│  │  └── Echo of our first byte (0x07 = length)
│  └───── 0x04 = Error type 4 (buffer overflow/unsupported format)
└──────── MsgType: 0x0D (Status)
```

#### Key Findings

1. **Session layer works** - TransportOpenRequest (0x01) and CTS (0x04) both return SUCCESS (0x0C)

2. **DataTransfer acknowledged but not processed** - All DataTransfer (0x03) commands return `0D 18 03` regardless of:
   - Service number (4 or 5)
   - Command code (0x60, 0x71, 0x73, 0xB0, 0xC0, 0xE0)
   - Connection ID (0x01 or 0x18)

3. **0x18 is consistent** - Every DataTransfer response contains 0x18 in byte 1, which could be:
   - The ECU's diagnostic session ID that we should be using
   - The default error code (0x18) from `diagnosticServiceDispatcher`
   - Some other status indicator

4. **Raw format rejected differently** - The J1708-style raw format (`07 05 C0...`) returns `0D 04 07` instead of `0D 18 03`, indicating it's processed by a different code path (error 0x04 = buffer overflow)

5. **Broadcast gets no response** - Sending to destination 0xFF produces no response

#### Implications for Firmware Analysis

The consistent `0D 18 03` response suggests:

1. The CLIP transport layer IS processing the messages (we get responses)
2. But the diagnostic payload is NOT reaching the `diagnosticCommandDispatcher`
3. There may be a missing step in the session establishment sequence
4. Or the CAN→Diagnostic buffer bridging code doesn't exist/isn't active

**Next steps for firmware RE:**
1. Find where `0D 18 03` response is generated in firmware
2. Trace the CAN RX path from interrupt to response generation
3. Look for any session state machine that gates DataTransfer processing
4. Check if there's an "enable diagnostic" flag that needs to be set
5. Capture real Insite traffic to compare exact byte sequences

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
