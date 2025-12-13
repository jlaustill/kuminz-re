# 003: CLIP Protocol Implementation

**Status:** In Progress
**Subproject:** kuminz-ui
**Created:** 2024-12-XX
**Updated:** 2024-12-13

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

## Related Tasks

- 001 (CRC Paradox) - May need CRC for calibration file transfers
- 002 (E2M Format) - Parameter definitions for read/write operations
