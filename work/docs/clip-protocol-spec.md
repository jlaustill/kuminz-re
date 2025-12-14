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
