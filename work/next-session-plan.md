# RAM/EEPROM Write Implementation - BREAKTHROUGH!

## Dec 25 Session - MEMORY WRITES WORKING!

### Major Discovery: Service 0x4B is the J1939 Write Service

**Previous attempts failed because Service 0x05 is J1708-ONLY!**

The J1939 dispatch table at 0x801c7a does NOT include Service 0x05. Instead:
- **Service 0x4A** = Memory READ (dispatch @ 0x22646 → `diagMemoryReadWrapper5Byte`)
- **Service 0x4B** = Memory WRITE (dispatch @ 0x0217de → `memoryOperationFromMessageExtended`)

Service 0x05 goes through `j1708DiagnosticCommandDispatcher` at 0x15f8e - this is the J1708 (serial) protocol handler, NOT J1939 (CAN).

---

### Working Write Format (Service 0x4B)

```
[0x4B][Addr:4BE][Len:1][Data:N][Auth:10]
```

**Verified Working:**
```bash
./kuminz-cli can0 --write-service4b 800100 AA55
```

**Test Results:**
- Wrote 0xAA55 to 0x800100: SUCCESS ✓
- Wrote 0x1234 to 0x800100: SUCCESS ✓
- Restored 0x0000 to 0x800100: SUCCESS ✓

**Protocol Flow:**
1. Read hour meter (for auth payload generation)
2. Build message: `[0x4B][Addr:4][Len:1][Data:N][Auth:10]`
3. Send via J1939 Transport Protocol (RTS/CTS/DT)
4. Receive EOM ACK = SUCCESS

---

### Service Comparison (J1939 vs J1708)

| Service | Protocol | Purpose | Status |
|---------|----------|---------|--------|
| 0x4A | J1939 | Memory READ | WORKING |
| 0x4B | J1939 | Memory WRITE | **WORKING** |
| 0x05 | J1708 | Memory access | N/A (not CAN) |
| 0x03 | J1708 | Secured commands | N/A (not CAN) |

---

### Memory Region Validation Reminder

| Range | Flag | Read | Write |
|-------|------|------|-------|
| 0x800000-0x8091C1 | 0x03 | ✓ | ✓ (with auth) |
| 0x8091DC-0x80FFFF | 0x00 | ✓ | ✗ (read-only) |
| 0x010000-0x010FFF | 0x05 | ✓ | ? (needs logging mode) |

---

### Files Modified This Session

- `clip-core/include/clip/ECUReader.h` - Added `writeMemoryService4B()`
- `clip-core/src/ECUReader.cpp` - Implemented Service 0x4B write
- `kuminz-cli/src/main.cpp` - Added `--write-service4b` command

### Key Functions in Firmware

| Function | Address | Purpose |
|----------|---------|---------|
| memoryOperationFromMessageExtended | 0x0217de | Service 0x4B dispatcher |
| memoryOperationDispatcher | 0x02148a | Performs actual memory write |
| diagMemoryReadWrapper5Byte | 0x22646 | Service 0x4A read handler |
| hourMeterSecurityValidator | - | Validates auth payload |

---

## Next Steps

### Immediate Tasks
1. ~~Test EEPROM writes (0x010000 range)~~ - **DONE** ✓ Works with Service 0x4B!
2. ~~Test Extended RAM writes without auth (0x8091DC+)~~ - **NOT POSSIBLE** (flag 0x00 = read-only)
3. ~~Test larger data blocks (>2 bytes)~~ - **DONE** ✓

### Larger Data Block Test Results (Dec 25)

| Size | Result | Notes |
|------|--------|-------|
| 4 bytes | ✓ | Works, verified |
| 8 bytes | ✓ | Works, verified |
| 16 bytes | ✓ | Works, verified |
| 32 bytes | ✓ | Works, some RAM locations have live counters that reset |

**Note:** Some RAM addresses (e.g., 0x800100) are actively used by ECU scheduler and get overwritten.
Choose less-active memory locations for persistent writes.

### EEPROM Write Test Results (Dec 25)

**EEPROM writes work with Service 0x4B!**

| Test | Result |
|------|--------|
| Write 0xDEADBEEF to 0x01000050 | ✓ SUCCESS |
| Checksums changed? | **NO** - Checksums only cover specific parameter blocks |
| Restore to 0x00000000 | ✓ SUCCESS |
| **Power cycle persistence** | ✓ **CONFIRMED** - Value survived ECU restart |

**Safe EEPROM test addresses (verified unused):**
- 0x01000050-0x0100007F (48-byte unused region)
- 0x010000D6 (blank_spot)
- 0x0100010A-0x0100012C (blank_spots)

**Note:** The firmware's `memoryOperationDispatcher` logging mode check may only apply to
certain EEPROM regions (like checksum-protected parameter blocks), not the entire EEPROM.

### EEPROM Write Investigation (Obsolete)
The `memoryOperationDispatcher` case 5 (EEPROM flag 0x05) requires:
- `_DAT_0080dc92 == 1` AND `_DAT_0080dc6c != 0` → returns error 0x07
- Need to find what sets `_DAT_0080dc6c = 1`

### Security Bypass - ENABLED!

**Successfully wrote 0xB522 to 0x803586!**

```bash
./kuminz-cli can0 --write-service4b 803586 B522
```

**Verification:**
```
00803580 | 00 00 00 F0 00 00 B5 22  00 00 18 FE BD 00 00 02
                         ↑↑↑↑
                      0x803586 = B5 22 (security bypass active)
```

**Effect per firmware analysis:**
- `diagnosticServiceSecurityValidator` skips auth for Services 3 & 4
- `memoryOperationDispatcher` allows writes without security check
- This is a RAM value, so it resets on power cycle
