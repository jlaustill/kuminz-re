# Service 0x4B Memory Write Path Analysis

Cross-firmware comparison of the J1939 memory write implementation between J90280.05 (reference) and J90350.00 (live ECU).

## Executive Summary

| Aspect | J90280.05 | J90350.00 |
|--------|-----------|-----------|
| Security Function | `systemSecurityCheckStub_AlwaysPasses` | `hourMeterSecurityValidator` |
| Security Status | **DISABLED** (stub always returns 0) | **ENABLED** (validates auth payload) |
| Message Handlers | 2 separate functions | Consolidated into 1 |
| Core Dispatcher | 86% match | 86% match |
| Address Validator | 100% match | 100% match |

**Key Finding**: The security subsystem in J90280.05 is compiled out (likely via `#ifdef`), not just bypassed. J90350.00 includes the full security implementation using hour meter-based authentication.

---

## Function Address Mapping

| Function | J90280.05 | J90350.00 | Match % |
|----------|-----------|-----------|---------|
| `memoryOperationDispatcher` | 0x0001b37a | 0x0002148a | 86% |
| `addressRangeValidator` | 0x0002b544 | 0x0003460e | 100% |
| `memoryOperationFromMessage` | 0x0001b6ce | (consolidated) | - |
| `memoryOperationFromMessageExtended` | 0x0001b716 | 0x000217de | 92% |
| `systemSecurityCheckStub_AlwaysPasses` | 0x0002ab30 | - | - |
| `hourMeterSecurityValidator` | - | 0x0002fcdc | - |
| `bitPackingAlgorithm` | - | 0x0002fbd8 | - |
| `SECURITY_MASK_TABLE` | - | 0x0002fbc4 | - |
| `SECURITY_XOR_TABLE` | - | 0x0002fbce | - |

---

## Security Implementation Evolution

### J90280.05: Security Disabled

```c
// systemSecurityCheckStub_AlwaysPasses @ 0x0002ab30
// This stub ALWAYS returns 0 (success), effectively disabling security
char systemSecurityCheckStub_AlwaysPasses(int auth_payload_ptr) {
    return 0;  // Always passes - security check bypassed
}
```

In J90280.05, the `memoryOperationDispatcher` calls `systemSecurityCheckStub_AlwaysPasses`:
- Any auth payload format is accepted
- Writes to secured RAM regions (flag 0x03) succeed with any 10-byte payload
- EEPROM writes (flag 0x05) also bypass security

**Implication**: The security code path is excluded from J90280.05's build, likely via preprocessor directive (`#ifdef` or similar).

### J90350.00: Real Security Implementation

```c
// hourMeterSecurityValidator @ 0x0002fcdc
// Validates 10-byte auth payload against stored security key + hour meter
// Returns: 0 = success, 1 = failure
// Lockout after 17 (0x11) failed attempts
char hourMeterSecurityValidator(byte* auth_payload_ptr) {
    // Uses bitPackingAlgorithm @ 0x2fbd8 for key derivation
    // Validates 6-byte security key against _security_key[6]
    // Validates 4-byte hour meter against _hour_meter_ecm_run_time
    // Increments _security_retry_counter on failure
}
```

J90350.00's security requires:
1. Correct 6-byte security key (derived from "ABCDEF" via bit packing)
2. Valid hour meter value (read from ECU before write)
3. Retry counter below lockout threshold (17 attempts)

### bitPackingAlgorithm @ 0x2fbd8 (J90350.00 Only)

This function transforms the 10-byte authentication payload before validation. It does **not exist** in J90280.05 (compiled out with the rest of the security subsystem).

```c
void bitPackingAlgorithm(byte *input_buffer, byte *output_buffer) {
    // Phase 1: BIT SCATTERING
    // - For each input byte (0-9), for each bit (0-7):
    //   - Read mask bit from SECURITY_MASK_TABLE
    //   - If mask bit = 0: Pack into "backward" buffer (bytes 0→9)
    //   - If mask bit = 1: Pack into "forward" buffer (bytes 9→0)

    // Phase 2: XOR SHUFFLE
    // - For each byte i (0-9):
    //   - buffer[i] ^= buffer[XOR_TABLE[i]]

    // Phase 3: REORDER OUTPUT
    // - For each byte i (0-9):
    //   - output[REORDER_TABLE[9-i]] = buffer[i]
}
```

#### Lookup Tables (ROM @ 0x2fbc4)

| Table | Address | Values (hex) | Purpose |
|-------|---------|--------------|---------|
| `SECURITY_MASK_TABLE` | 0x2fbc4 | `46 58 9a 32 70 87 23 99 85 64` | Bit routing mask |
| `SECURITY_XOR_TABLE` | 0x2fbce | `06 08 01 02 00 07 03 09 05 04` | XOR shuffle indices |
| `SECURITY_REORDER_TABLE` | 0x2fbd7 | (same data, read backwards) | Output reordering |

#### Security Characteristics

- **Reversible**: Deterministic transform, not encryption
- **Obfuscation only**: Prevents casual sniffing of password from CAN bus
- **Shared implementation**: Insite must use identical tables to produce matching auth payload

---

## Function Consolidation

### J90280.05: Two Separate Handlers

```
memoryOperationFromMessage @ 0x1b6ce
├── Handles shorter message format
├── Extracts 2-byte params
└── Calls memoryOperationDispatcher

memoryOperationFromMessageExtended @ 0x1b716
├── Handles extended message format
├── Extracts 4-byte params
└── Calls memoryOperationDispatcher
```

### J90350.00: Consolidated Handler

```
memoryOperationFromMessageExtended @ 0x217de
├── Handles both message formats
├── Extracts params from J1939 message
└── Calls memoryOperationDispatcher

memoryOperationFromMessage8Byte @ 0x21826
├── 8-byte variant (new in J90350.00)
└── Calls memoryOperationDispatcher
```

**Change**: The 2-byte handler was consolidated into the extended handler, while an 8-byte variant was added.

---

## Shared Components (Unchanged)

### addressRangeValidator (100% Match)

Both firmware versions use identical address range validation logic:

```c
// addressRangeValidator
// Returns: MEMORY_ACCESS_FLAG enum
//   0x00 = DIRECT_ACCESS (Extended RAM - no security)
//   0x03 = SECURITY_REQUIRED (Main RAM - requires auth)
//   0x04 = WRITE_DENIED (ROM/Flash - blocked)
//   0x05 = LOGGING_MODE (EEPROM - requires logging state)
//   0x09 = RANGE_INVALID (address not in table)

// Uses 5-entry address_range_validation_table:
// Entry format: [start_addr:4][end_addr:4][read_flag:1][write_flag:1]
```

### Memory Region Table

| Range | Flag | Read | Write |
|-------|------|------|-------|
| 0x000000-0x03FFFF | 0x04 | Yes | **DENIED** (ROM) |
| 0x800000-0x8091C1 | 0x03 | Yes | With auth |
| 0x8091C2-0x80FFFF | 0x00 | Yes | Direct |
| 0x010000-0x010FFF | 0x05 | Yes | Logging mode |

### Return Codes (MEMORY_OP_RESULT)

| Code | Name | Description |
|------|------|-------------|
| 0x00 | SUCCESS | Operation completed |
| 0x02 | INVALID_LENGTH | Message length mismatch |
| 0x03 | AUTH_FAILED | Security check failed |
| 0x07 | LOGGING_STATE_ERROR | EEPROM logging state blocked |
| 0x0A | WRITE_DENIED | ROM/Flash write attempted |
| 0x0B | BUFFER_WRITE_FAIL | Circular buffer error |
| 0x1A | AUTH_REQUIRED_MISSING | Auth needed but not provided |

---

## RAM Variables

Key RAM variables used by both versions:

| Variable | Address | Purpose |
|----------|---------|---------|
| `_security_bypass_flag` | 0x803586 | 0xFF = bypass security checks |
| `_security_retry_counter` | varies | Failed auth attempt counter |
| `_system_logging_state` | 0x80dc92 | EEPROM logging state (1=active) |

**Note**: Setting `_security_bypass_flag` to 0xB522 in J90350.00 disables security checks, making it behave like J90280.05.

---

## Protocol Flow

### Service 0x4B Write Request

```
Request Format:
[0x4B][Addr:4 BE][Len:1][Data:N][Auth:10 optional]

Response: EOM ACK on success, error code on failure
```

### Write Path Call Stack

```
J1939 Dispatch Table @ 0x801c7a
└── Service 0x4B → memoryOperationFromMessageExtended
    └── memoryOperationDispatcher
        ├── addressRangeValidator
        │   └── address_range_validation_table
        ├── Case 0: Direct write (Extended RAM)
        ├── Case 3: Security check + write (Main RAM)
        │   └── hourMeterSecurityValidator (J90350.00)
        │   └── systemSecurityCheckStub_AlwaysPasses (J90280.05)
        ├── Case 4: Return WRITE_DENIED (ROM)
        └── Case 5: Logging check + write (EEPROM)
```

---

## Implications for Tool Development

1. **Authentication Required**: Tools targeting J90350.00 must implement proper authentication using the hour meter-based system.

2. **J90280.05 Security Compiled Out**: J90280.05 accepts any auth payload due to security subsystem being excluded from the build.

3. **Security Bypass**: The `_security_bypass_flag` at 0x803586 can temporarily disable security in J90350.00, but resets on power cycle.

4. **Shared Core Logic**: The `addressRangeValidator` and return codes are identical, so tools work with both versions once authenticated.

---

## Files Modified

### J90350.00
- `output/local_variables.csv` - Variable names for write path functions
- `output/enums.csv` - MEMORY_OP_RESULT enum
- `output/function_parameters.csv` - Parameter documentation

### J90280.05
- `output/local_variables.csv` - Variable names + cross-reference comments
- `output/enums.csv` - MEMORY_OP_RESULT enum (with stub note)
- `output/function_parameters.csv` - Parameter documentation

---

---

## Insite/Calterm Correlation

### Password System Discovery

From decompiled Insite code (`ECMServicesAdapter.cs`):

```csharp
// Default password - matches firmware security key length!
physicalConnectionConfiguration.Password = "ABCDEF";
```

**Key Finding**: The default password `"ABCDEF"` is exactly 6 bytes - matching the security key length in `hourMeterSecurityValidator`.

### Password Hierarchy

From `Interop.CONMANAPILib.cs`:

| Type | Value | Access Level |
|------|-------|--------------|
| `PTE_MASTER_PASSWORD` | 1 | Full access |
| `PTE_OEM_PASSWORD` | 2 | OEM level |
| `PTE_ADJUSTABLE_PASSWORD` | 3 | Adjustment only |
| `PTE_RESET_PASSWORD` | 4 | Reset only |

### ECMPasswordType Enum

From `Cummins.INSITE.Kernel.ECMServicesAPI.cs`:

```csharp
public enum PasswordType {
    Master = 1,      // Full access to all parameters
    OEM = 2,         // OEM-specific access
    Adjustable = 3,  // Can modify adjustable parameters
    Reset = 4,       // Can reset parameters only
}
```

### Firmware Correlation

| Insite Concept | Firmware Implementation |
|----------------|------------------------|
| Password = "ABCDEF" | `_security_key[6]` in RAM |
| Master Password | `_security_bypass_flag = 0xB522` |
| Hour Meter validation | `hourMeterSecurityValidator()` uses ECM run time |
| Write protection | `addressRangeValidator()` returns region flags |

### Authentication Flow

1. **Insite** sends password + hour meter in auth payload
2. **Firmware** (`hourMeterSecurityValidator`) extracts via `bitPackingAlgorithm`
3. Compares 6-byte key against stored `_security_key`
4. Validates hour meter matches ECM run time
5. Returns 0 (success) or 1 (failure)

### Key Files for Further Analysis

| File | Purpose |
|------|---------|
| `ECMServicesAdapter.cs` | Connection and password handling |
| `Cummins.INSITE.AddIns.FeaturesAndParameters.cs` | Parameter access control |
| `Interop.ECMSERVICESAPILib.cs` | Low-level ECU communication interface |

---

*Generated: 2025-12-26*
*Firmware versions analyzed: J90280.05 (reference), J90350.00 (live ECU)*
*Insite version analyzed: 7.6.0.272*
