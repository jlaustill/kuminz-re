# 016: CLIP Command Execution

**Status:** Todo
**Subproject:** clip-core, kuminz-cli
**Created:** 2024-12-24
**Depends On:** 003 (CLIP Session Management - COMPLETE)

## Problem Statement

CLIP session management is working (Task 003), but CLIP commands (0x14 GetDataByAddress, 0x15 SetDataByAddress) are being rejected by the CM550 ECU.

**Current Behavior:**
```
Session open: SUCCESS (ECU accepts session, connection ID 24)
Read command (0x14): ECU returns 0x0D 0x18 0x03 (error)
Write command (0x15): ECU returns 0x0D 0x18 0x23 (error)
```

**Error Response Analysis:**
- Byte 0: 0x0D = SessionOpenResponse/Error message type
- Byte 1: 0x18 = Connection ID (24 decimal)
- Byte 2: 0x03 or 0x23 = Error code (TBD)

## Working vs Non-Working Paths

| Method | Status | Notes |
|--------|--------|-------|
| Service 0x4A (J1708-style) | ✅ Working | Uses J1939 TP, not CLIP |
| CLIP Session Open | ✅ Working | ECU accepts at connId 24 |
| CLIP Session Close | ✅ Working | ECU acknowledges |
| CLIP 0x14 (GetDataByAddress) | ❌ Failing | Error 0x03 |
| CLIP 0x15 (SetDataByAddress) | ❌ Failing | Error 0x23 |

## Investigation Areas

### 1. Command Format
- [ ] Verify CLIP command packet structure matches Insite
- [ ] Check if command needs DPA wrapper (0xC0/0x80 header)
- [ ] Verify byte ordering (big-endian for address/length)

**Current Format (from CLIPInstructionBuilder):**
```
GetDataByAddress (0x14): [CMD][SEQ][Addr:4BE][Len:2BE]
SetDataByAddress (0x15): [CMD][SEQ][Addr:4BE][Len:2BE][Data]
```

### 2. Multi-Frame Transport
- [ ] Verify DataTransfer (0x03) frame encoding is correct
- [ ] Check if sequence numbering in sessionId field is correct
- [ ] Determine if handshake (TransportOpen/CTS) is needed for commands

**Current Multi-Frame Approach:**
- Commands > 5 bytes split into DataTransfer frames
- Sequence number stored in sessionId field (bits 7:5)
- No TransportOpen/CTS handshake (removed to avoid "existing session" error)

### 3. Error Code Analysis
- [ ] Find where 0x03 and 0x23 error codes are generated in firmware
- [ ] Map error codes to meanings (invalid command? wrong format? permission denied?)
- [ ] Check if control byte carries additional status info

### 4. Alternative Approaches
- [ ] Try single-frame commands (< 5 bytes) to isolate multi-frame issues
- [ ] Test with different connection IDs
- [ ] Try DPA frame wrapper around CLIP commands
- [ ] Analyze real Insite traffic (if possible)

## Firmware Functions to Investigate

| Address | Function | Purpose |
|---------|----------|---------|
| 0x2729a | diagnosticServiceDispatcher | Routes incoming service requests |
| 0x19a0a | insiteLiveDataHandler | Handles msgType routing |
| 0x298d8 | diagnosticMultiPacketResponseBuilder | Builds 0x0C/0x0D responses |
| 0x27e98 | systemSecurityCheck | Always returns 0 (no auth) |

## Files to Analyze

- `clip-core/src/CLIPTransportLayer.cpp` - Multi-frame encoding
- `clip-core/src/CLIPInstructionBuilder.cpp` - Command packet building
- `insite9/decompiled/native/DeviceControl_ghidra.c` - CLIP command implementation
- `insite9/decompiled/dotnet/Interop.DeviceControl.cs` - CLIP instruction definitions
- `firmware/J90350.00_analysis/output/J90350.00.ghidra.cpp` - ECU-side handlers

## Test Commands

```bash
# Test current CLIP write (fails)
./kuminz-cli can0 --write-clip 0x00803586 0xB522

# Working Service 0x4A read for comparison
./kuminz-cli can0 --svc-4a 0x00803586 2
```

## Success Criteria

1. CLIP 0x14 (GetDataByAddress) returns actual memory data
2. CLIP 0x15 (SetDataByAddress) successfully writes to ECU memory
3. Verification read confirms written data

## Related Tasks

- 003 (CLIP Protocol) - Session management complete, command layer pending
- 011 (RAM Dump Correlation) - Uses Service 0x4A (working path)
