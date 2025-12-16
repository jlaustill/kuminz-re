# 003: CLIP Protocol Implementation

**Status:** In Progress
**Subproject:** kuminz-ui
**Created:** 2024-12-XX
**Updated:** 2024-12-13

## Progress Log

### 2024-12-13: Integrated Insite Protocol Analysis
- Updated timeout constants to match Insite specification:
  - Default timeout: 5000ms → **60000ms** (per PCLSystem_ghidra.c:43068)
  - Session timeout: 15000ms → **60000ms**
  - Added close timeout: **1000ms** (per PCLSystem_ghidra.c:45421)
  - Added max write params: **256** (per PCLSystem_ghidra.c:44816)
- Added `sendTransportClose()` to CLIPTransportLayer with proper close message
- Added `TransportClose` (0x06) message type enum
- Enhanced `closeSession()` to send CLIP close message
- Linked to Task 009 documentation: clip-protocol-spec.md, calibration-handling.md

### 2024-12-15: Service 5 Diagnostic Command Discovery & Hardware Testing
**MAJOR BREAKTHROUGH: Discovered Service 5 command format from firmware analysis!**

**Firmware Analysis Discoveries:**
- `diagnosticCommandDispatcher` @ 0x12484 expects Service 5 format
- Service numbers: 3 (system), 4 (control), **5 (memory/multi-packet)**, 6 (abort)
- Service 5 command codes: 0x60/0xC0/0xE0 (read), 0x80/0xA0 (write), 0xB0/0xF0 (multi-packet)
- `multiPacketReceiveHandler` @ 0x12d76 recognizes connection IDs 0x15, 0x17, **0x18**, 0x19
- `systemSecurityCheck()` @ 0x27e98 always returns 0 (no security blocking)

**clip-lib Updates:**
- Added `ServiceNum` and `Service5Cmd` enums to `Frame.h`
- Added `buildMemoryReadRequest()` and `buildMultiPacketReceiveRequest()` builders
- Updated CLI test tool with comprehensive Service 5 command tests
- Added conditional RX logging (quiet mode for --read)

**Hardware Test Results with Real CM550 ECU:**
- ✅ **Session Open (0x01)** → SUCCESS (0x0C) with connection ID 0x01
- ✅ **CTS (0x04)** → SUCCESS (0x0C)
- ❌ **ALL DataTransfer (0x03)** → Status (0x0D 0x18 0x03) - Acknowledged but not processed

**Tests Performed:**
| Test | Command | Result |
|------|---------|--------|
| MemoryRead2 (0xC0) | `03 01 05 C0 00 34 F8 04` | `0D 18 03 FF...` |
| MemoryRead1 (0xE0) | `03 01 05 E0 00 34 F8 04` | `0D 18 03 FF...` |
| MemoryRead3 (0x60) | `03 01 05 60 00 34 F8 04` | `0D 18 03 FF...` |
| MultiPktRecv (0xB0) | `03 01 05 B0 00 01 01 01` | `0D 18 03 FF...` |
| Service 4 Init (0x71, 0x73) | `03 01 04 71/73 00 00 00 00` | `0D 18 03 FF...` |
| With connId=0x18 | `03 18 05 C0 00 34 F8 04` | `0D 18 03 FF...` |
| Raw J1708-style | `07 05 C0 00 34 F8 04 00` | `0D 04 07 FF...` (different!) |

**Key Insight:**
The CLIP transport layer accepts sessions and acknowledges DataTransfer, but the diagnostic payload is NOT reaching `diagnosticCommandDispatcher`. The 0x18 in every response is either:
1. The ECU's diagnostic session ID
2. Default error code from `diagnosticServiceDispatcher`
3. Some session state indicator

**Next Steps for Firmware RE:**
1. Find where `0D 18 03` response is generated
2. Trace CAN RX path from interrupt to response generation
3. Look for session state machine gating DataTransfer processing
4. Check for "enable diagnostic" flags
5. Capture real Insite traffic for comparison

### 2024-12-15: ROOT CAUSE IDENTIFIED - Firmware RE Complete
**🎯 SOLVED: Found exactly why DataTransfer (0x03) fails!**

**Response Format Decoded:**
- `0x0D` = STATUS_RESPONSE (error indicator, byte 1 has error code)
- `0x18` = UNKNOWN_SERVICE_DEFAULT (service ID not found in dispatch table)
- `0x03` = Echoed input byte (our msgType from DataTransfer frame)

**Root Cause - Message Handler Gap:**
`insiteLiveDataHandler()` @ 0x19a0a only handles these msgTypes:
| msgType | Handler |
|---------|---------|
| 0x00 | "CLIP Get Status" - sets response flags |
| 0x80 | Multi-frame live data stream |
| 0xC3 | Sequence handling (0x30/0x31) |
| **0x03** | **NO HANDLER - falls through to else!** |

The else clause (line 14022-14024) just calls `responseBufferFinalize()` with no data.

**Call Chain Traced:**
```
main_loop → diagnosticCommunicationSlowCycle10Coordinator →
diagnosticCommandDispatcher → insiteLiveDataHandler
```

**Key Functions Documented:**
- `diagnosticServiceDispatcher` @ 0x2729a - Default error `cVar2 = '\x18'`
- `diagnosticMultiPacketResponseBuilder` @ 0x298d8 - Builds 0x0C (success) or 0x0D (error)
- `diag_multi_packet_status_code_table` @ 0x298BE - Status code lookup table

**CSV Updates Applied:**
- Added `INSITE_LIVE_DATA_MSG_TYPE` enum (0x00, 0x03, 0x80, 0xC3)
- Added `CAN_MULTIPACKET_RESPONSE` enum (0x0C success, 0x0D error)
- Added `DIAG_SERVICE_ERROR` enum (0x18 = unknown service)
- Documented global variables for dispatch table pointer

**Next Steps for Protocol Implementation:**
1. **Analyze Decompiled Insite** - Look in insite9/decompiled/ for message format clues
2. **Find Alternate Path** - May need different PGN or message format for diagnostics
3. **Session State Investigation** - Why does Session Open (0x01) succeed?
4. **Consider J1708** - Raw J1708-style message got different response (0x0D 0x04 0x07)

### 2024-12-15: PGN Routing Architecture Discovered
**🔑 MAJOR BREAKTHROUGH: Complete PGN handler mapping!**

**PGN Handler Registrations (via `coreSystemControlFunction` @ 0x1b1b4):**
| PGN | Handler | Purpose |
|-----|---------|---------|
| **0xEF00** | `diagnosticServiceDispatcher` @ 0x2729a | Service dispatch by first 2 bytes |
| **0xEC00** | `vp44CanMessageDispatcher` @ 0x1c846 | TP.CM - Routes by byte[0] (0x10/0x11/0x13/0xFF) |
| **0xEB00** | `vp44MultiFrameResponseHandler` @ 0x1c60e | TP.DT - Multi-frame data processing |
| 0xE300 | Function @ 0x27342 | Unknown |
| 0xF002 | Function @ 0x273d4 | Unknown |

**Why 0x11/0x13 on PGN 0xEF00 Fails:**
- PGN 0xEF00 → `diagnosticServiceDispatcher`
- Dispatcher looks for service IDs in its table (2-byte match)
- 0x11/0x13 not in table → Returns 0x18 "Unknown Service" error

**Why 0x11/0x13 on PGN 0xEC00 Fails Silently:**
- PGN 0xEC00 → `vp44CanMessageDispatcher` → `diagnosticParamRequestHandler`
- Handler validation requires:
  1. `diag_tp_state_t.diag_state == 1` (session active)
  2. `rx_msg->id == expected_id_low` (source address match)
  3. `sequence <= total_packets`
  4. `guard_word == expected_guard`
- `diag_state = 1` only set when ECU initiates multi-frame via `sendJ1939MultiFrame`
- 0x11/0x13 are TP **flow control** commands, not diagnostic request initiators!

**J1939 Request (PGN 0xEA00) Works:**
- Tested: Request PGN 0xFECA (DM1)
- ECU responds with TP.CM BAM + TP.DT multi-frame data
- Confirms ECU J1939 stack is functional

**Key Insight - Two Diagnostic Paths:**
1. **J1939 TP Path (PGN 0xEC00/0xEB00):** For multi-frame TP flow control
2. **Insite/Proprietary Path (PGN 0xEF00):** For diagnostic service dispatch

**Next Investigation:**
1. Find what services ARE registered in EF00 dispatch table
2. Understand `diagnosticCommandDispatcher` serial buffer input path
3. May need to use different service IDs on PGN 0xEF00

### 2024-12-15: Decompiled Insite Analysis - DPA Frame Format
**🔑 BREAKTHROUGH: Found CLIP message format from decompiled Insite code!**

**Source Files Analyzed:**
- `insite9/decompiled/dotnet/Interop.DeviceControl.cs` - CLIP protocol interfaces
- `insite9/decompiled/native/dpas32_ghidra.c` - DPA CAN frame construction

**CLIP Instruction Set (from Interop.DeviceControl.cs:3924-3932):**
| Code | Instruction | Purpose |
|------|-------------|---------|
| 0x00 | QueryInitialize | Initialize query session |
| 0x01 | QueryTerminate | Terminate query session |
| 0x10 | GetParametersByID | Read parameters by ID |
| 0x11 | SetParametersByID | Write parameters by ID |
| 0x12 | ExecuteOperation | Execute ECU operation |
| 0x13 | GetDataByAddress | Read memory by address |
| 0x14 | SetDataByAddress | Write memory by address |
| 0x15 | GetAddressByParameterID | Get parameter address |

**DPA Frame Structure (from dpas32_ghidra.c:2366-2370):**
```
CAN Frame Format (8 bytes):
  Byte 0: 0xC0 (async) or 0x80 (sync) - DPA frame type
  Byte 1: Reserved/padding (0x00)
  Byte 2: Reserved/padding (0x00)
  Byte 3: 0x49 (transmit) or 0x48 (receive) - DPA instruction
  Byte 4: CLIP instruction (0x00-0x15)
  Byte 5: Parameter byte
  Byte 6: Flags
  Byte 7: Payload/padding
```

**Two Protocol Layers Identified:**
1. **DPA/CAN Layer** - Handles CAN framing with 0xC0/0x80 headers and 0x49/0x48 instructions
2. **CLIP Instruction Layer** - Uses 0x00-0x15 operation codes within DPA payload

**clip-lib Updates:**
- Added `CLIPInstruction` enum (0x00-0x15) to `Frame.h`
- Added `DPAFrameType` enum (0xC0 async, 0x80 sync) to `Frame.h`
- Added `DPAInstruction` enum (0x49 transmit, 0x48 receive) to `Frame.h`
- Added DPA frame builders: `buildDPAFrame()`, `buildDPAGetParam()`, `buildDPAGetData()`, `buildDPAQueryInit()`
- Added CLI commands: `--dpa-init`, `--dpa-param`, `--dpa-data`, `--dpa-test`

**Next Steps:**
1. Test DPA frame format on real hardware
2. Map EF00 service dispatch table to see which CLIP instructions are recognized
3. Correlate decompiled CLIP instructions with firmware handlers

## Goal

Implement the Cummins CLIP (Cummins Link Interface Protocol) for ECU communication over CAN bus in the kuminz-ui Qt5 desktop application.

## Background

CLIP is Cummins' proprietary protocol for ECU communication. It runs over J1939 CAN bus (250kbps) and provides session management, reliable message transport, and parameter read/write operations.

## Requirements

- [ ] Session establishment (connect/disconnect with ECU)
- [ ] Reliable message transport with retries and acknowledgments
- [ ] J1939 message framing (29-bit CAN IDs)
- [ ] Parameter read operations
- [ ] Parameter write operations
- [ ] Error handling (timeout, NAK, etc.)

## Architecture

```
┌─────────────────────────────────────────────────────────┐
│                    ConnectionWidget                      │
│  (Adapter Setup + ECU Connection UI)                    │
└─────────────────────┬───────────────────────────────────┘
                      │
┌─────────────────────▼───────────────────────────────────┐
│                     ECUReader                            │
│  (High-level ECU interface)                             │
└─────────────────────┬───────────────────────────────────┘
                      │
┌─────────────────────▼───────────────────────────────────┐
│               CLIPSessionManager                         │
│  (Session lifecycle: connect, disconnect, state)        │
└─────────────────────┬───────────────────────────────────┘
                      │
┌─────────────────────▼───────────────────────────────────┐
│              CLIPTransportLayer                          │
│  (Reliable message delivery with retries)               │
└─────────────────────┬───────────────────────────────────┘
                      │
┌─────────────────────▼───────────────────────────────────┐
│              J1939MessageBuilder                         │
│  (CAN frame construction: PGN, SA, DA)                  │
└─────────────────────┬───────────────────────────────────┘
                      │
┌─────────────────────▼───────────────────────────────────┐
│               SocketCanAdapter                           │
│  (Linux SocketCAN interface)                            │
└─────────────────────────────────────────────────────────┘
```

## Implementation Progress

### Core Files Created
- [X] `src/clip/CLIPSessionManager.cpp/h` - Session lifecycle
- [X] `src/clip/CLIPTransportLayer.cpp/h` - Message transport
- [X] `src/clip/J1939MessageBuilder.cpp/h` - CAN frame building
- [X] `src/clip/CLIPInstructionBuilder.cpp/h` - Command construction
- [X] `src/clip/ECUReader.cpp/h` - High-level interface
- [X] `src/clip/types/EClipCommand.h` - Command enum
- [X] `src/clip/types/ESessionState.h` - Session state machine
- [X] `src/clip/types/TClipPacket.h` - Packet structure

### CAN Adapter Layer
- [X] `src/can/SocketCanAdapter.cpp/h` - Linux SocketCAN implementation
- [X] `src/can/CanDeviceManager.cpp/h` - Device detection & lifecycle
- [X] `src/types/ICanAdapter.h` - CAN interface definition

### UI Layer
- [X] `src/ui/widgets/ConnectionWidget.cpp/h` - Adapter + ECU connection UI
- [X] `src/ui/widgets/StatusBarWidget.cpp/h` - Status display
- [X] `src/ui/types/EAdapterState.h` - Hardware setup states
- [X] `src/ui/types/EConnectionState.h` - ECU connection states
- [X] `src/ui/types/TCanDevice.h` - Device info structure
- [X] `src/ui/types/TConnectionSettings.h` - Connection parameters

### Remaining Work
- [ ] CLIP message parsing and response handling
- [ ] Parameter read/write implementation
- [ ] Session timeout handling
- [ ] Error recovery logic
- [ ] Integration testing with real ECU

## Design Decisions

### 2024-12-XX: State machine separation
**Decision:** Separate Adapter Setup and ECU Connection into independent state machines
**Rationale:** Hardware layer (CAN adapter) and protocol layer (ECU session) are independent concerns. User can set up adapter without connecting to ECU.

### 2024-12-XX: SLCAN setup via PolicyKit
**Decision:** Use `pkexec` for slcand setup instead of requiring root
**Rationale:** Single password prompt via graphical dialog, better UX than running entire app as root

### 2024-12-XX: Default CAN speed
**Decision:** Default to 250kbps (-s5 for slcand)
**Rationale:** J1939 standard for Cummins ECUs

## Hardware Support

| Device | USB ID | Status |
|--------|--------|--------|
| OBDLink EX | 0403:6015 | Primary dev device |
| OBDLink SX/MX | Various | Supported |
| CANable | Various | Supported |
| Generic SLCAN | Various | Supported |
| Native SocketCAN | N/A | Supported |

## Device Detection Flow

1. **Native SocketCAN:** Scan `/sys/class/net/*/type` for value "280" (ARPHRD_CAN)
2. **Serial SLCAN:** Scan `/dev/serial/by-id/` symlinks, parse vendor/product
3. **Running slcand:** Scan `/proc/*/cmdline` for slcand processes

## SLCAN Setup Flow

```bash
# 1. Detect USB device via symlinks
ls /dev/serial/by-id/

# 2. Setup slcand with PolicyKit
pkexec sh -c "slcand -o -c -s5 /dev/ttyUSBx canX && ip link set canX up"

# 3. Verify interface
candump can0  # Note: network interface, not /dev/can0
```

## Critical Notes

- Use `pkill -x slcand` (exact match), NOT `pkill -f 'slcand.*'` (pattern match kills shell too)
- SocketCAN interfaces are network interfaces: use `candump can0` not `candump /dev/can0`
- J1939 uses 29-bit extended CAN IDs

## Testing

- [ ] Unit tests for J1939 message framing
- [ ] Unit tests for CLIP packet construction
- [ ] Integration test with real ECU (CM550)
- [ ] Error handling tests (timeout, NAK, disconnect)
- [ ] SLCAN setup/teardown tests

## Key Files

**CLIP Protocol:**
- `kuminz-ui/src/clip/CLIPSessionManager.cpp` - Session management
- `kuminz-ui/src/clip/CLIPTransportLayer.cpp` - Reliable transport
- `kuminz-ui/src/clip/J1939MessageBuilder.cpp` - CAN frame building

**CAN Adapter:**
- `kuminz-ui/src/can/SocketCanAdapter.cpp` - Linux SocketCAN
- `kuminz-ui/src/can/CanDeviceManager.cpp` - Device detection

**UI:**
- `kuminz-ui/src/ui/widgets/ConnectionWidget.cpp` - Main connection UI

## Reference Documentation (from Task 009 Insite RE)

| Document | Content |
|----------|---------|
| `work/docs/clip-protocol-spec.md` | CLIP/J1939 protocol details (timeouts, message types, session flow) |
| `work/docs/diagnostic-functions.md` | Fault codes (DTC), monitoring, data logging |
| `work/docs/calibration-handling.md` | Security levels, password types, flash process |
| `work/docs/database-schema.md` | Parameter organization (FnPDatabase) |

**Key Protocol Values from Insite Analysis:**
- Default timeout: **60,000 ms** (not 5,000 ms)
- Max parameters per write batch: **256**
- Close message timeout: **1,000 ms**
- Session validation: Check offset 0x74 for validity

## Related Tasks

- 001 (CRC Paradox) - May need CRC for calibration file transfers
- 002 (E2M Format) - Parameter definitions for read/write operations
- 009 (Insite RE) - **COMPLETE** - Protocol analysis source
