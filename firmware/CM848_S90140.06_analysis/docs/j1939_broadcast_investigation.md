# CM848D J1939 Broadcast Trigger Investigation

**Status:** RESOLVED — see `j1939-broadcasting.md` for the definitive operational reference  
**Firmware:** Bank 1 `cm848_rom.bin` (448KB) + Bank 2 `cm848_flash2_live.bin` (248KB), S90140.06

---

## The Question

The CM848D does **not** broadcast J1939 messages until something enables them.
Calterm triggers broadcasts when it connects; kuminz-cli/kuminz-ui do not because
we haven't identified which CLIP EF00 service Calterm sends to enable them.

---

## Session 2026-05-19 Correction: Flash2[0x505F98] is EEPROM, Not J1939

The prior analysis incorrectly identified Flash2[0x505F98] as a "J1939 TX scheduler."
It is actually `cm848_processProtectionParameterData` — an **EEPROM scatter write engine**.
The three "gates" decoded previously correspond to EEPROM control variables, not J1939.

**Consequence:** The variable names applied to 0x003FDDB6–0x003FDDC4 (j1939_tx_path_selector, etc.)
are WRONG. These addresses are EEPROM-related. They have been **removed from global_variables.csv**.

`fuel_timing_feature_flags @ 0x003FD59C` remains valid — it's used by multiple ROM timing functions
(confirmed from `cm848_rom.ghidra.cpp`) and is non-zero (0x9C12) at key-off.

---

## Broadcast Execution Chain (Corrected)

Broadcasts are registered at boot via `initDiagnosticBufferPointers @ Flash2[0x537CF8]`,
called once from the boot-init chain:

```
hpcr_exceptionHandler @ ROM[0x544C4]
  └─ cm848_dataTable_00539868 @ Flash2[0x539868]  (bad instructions - Ghidra can't decode)
       └─ [indirect] → mpc555_calculatePressureDropOffset @ Flash2[0x5383D0]
            └─ initDiagnosticBufferPointers @ Flash2[0x537CF8]
                 └─ cm848_enqueueDataRecord(0, 0xF004, 20ms, 0, cm848_j1939SendPgn61444_F004_EngineSpeedTorqueEec1)
                    cm848_enqueueDataRecord(0, 0xF003, 20ms, 10, cm848_j1939SendPgn61443_F003_AcceleratorPedalEec2)
                    cm848_enqueueDataRecord(0, 0xFEDF, 50ms, ...)  ← EEC3
                    cm848_enqueueDataRecord(0, 0xFEEE, 1000ms, ...) ← EngineTemp1
                    ... (16 PGNs total, EEC1/EEC2/EEC3/TSC1/DM1/etc.)
```

Note: `cm848_dataTable_00539868` hits "bad instruction" in Ghidra due to floating-point register
save/restore opcodes that Ghidra's PPC spec can't decode. The call chain through it is reconstructed
from binary analysis.

Separately, the ISR loop calls the broadcast dispatcher every tick:

```
main_loop @ ROM[0xC0A0]  — 8-phase MIOS ISR
  └─ cm848_phase_group_b_processing @ ROM[0xB854]
       └─ cm848_processJ1939DiagnosticMessages()   ← receives incoming J1939
          cm848_processJ1939ReceivedMessages()
          cm848_processProtectionParameterData(0)  ← EEPROM scatter engine (NOT J1939 TX)
```

The periodic broadcast **dispatcher** is `cm848_processProtectionDiagnosticState @ Flash2[0x5378A4]`,
called separately from the main loop. It fires registered PGN handlers when their timers expire,
but only when the broadcast gates pass.

---

## Broadcast Gates (Corrected)

`cm848_processProtectionDiagnosticState @ Flash2[0x5378A4]` checks two gate variables.
Confirmed by binary decode of the function:

```asm
Flash2[0x5378b4]  lis r31, 0x41
Flash2[0x5378b8]  addi r31, r31, -0x458c    ; r31 = 0x0040BA74
Flash2[0x5378bc]  lhz r11, 0(r31)           ; r11 = gate_A @ 0x0040BA74
Flash2[0x5378b0]  bc → skip_broadcasts      ; if (r11 & r30) == 0 → skip

Flash2[0x5378f4]  lis r27, 0x41
Flash2[0x5378f8]  addi r27, r27, -0x458a    ; r27 = 0x0040BA76
Flash2[0x5378fc]  lhz r31, 0(r27)           ; r31 = gate_B @ 0x0040BA76
Flash2[0x53790c]  bc → skip_broadcasts      ; if (r31 & mask) == 0 → skip
```

| Gate | Address | Key-off value | Blocks? |
|------|---------|--------------|---------|
| Gate A | `0x0040BA74` | `0x0000` | **Yes** — zero at key-off |
| Gate B | `0x0040BA76` | `0x0000` | **Yes** — zero at key-off |

**Both gates are zero at key-off without Calterm.** One or both must be set for broadcasts to fire.

Note: Ghidra decompiles these as `output_control_mask` (0x0040A9B0) and `protection_diagnostic_state_flags`
(0x0040A998), but those are WRONG addresses — those variables are also 0 at key-off and are NOT what
the binary accesses. The binary-verified gate addresses are 0x0040BA74 and 0x0040BA76.

---

## Broadcast Enable Function

`cm848_updateOutputControlMaskIndex5 @ Flash2[0x5099B8]` enables broadcasts:

```c
// When called with specific payload bytes (cVar1=1, cVar2=1):
// Sets gate_A bit pattern 0xc (bits 2+3) → enables both PGN queues
cm848_updateOutputControlMask(param_1, 1);  // 1 = set bits
```

This is registered as **output control operation 5** via `cm848_registerOutputControlOperations`.
The corresponding disable is operation 4 (`cm848_updateOutputControlMaskIndex4`).

The actual memory write (confirmed in binary): `sth r6, -0x582c(r12)` → writes to **0x0040A7D4**,
not to 0x0040A9B0 as Ghidra names. The exact relationship between 0x0040A7D4 and the gate at
0x0040BA74 is unclear — they may be separate variables in the same region, or the gate variable
may be read differently.

---

## CLIP EF00 Service Map

Registered via `cm848_processJ1939DiagnosticRequest(service_code, handler)`:

| Service | Handler | Notes |
|---------|---------|-------|
| 0x01 | LAB_00021584 | unknown |
| 0x06 | LAB_000216E8 | unknown |
| 0x07 | LAB_00021624 | unknown |
| 0x0a | `cm848_initJ1939MessageBuffers` | buffer init |
| 0x0b | `cm848_j1939ProcessRxQueueParam` | rx queue param |
| 0x0c | (direct in handler) | special case |
| 0x0d | (direct in handler) | special case |
| 0x15 | `cm848_validateCalibrationMemory` | calibration |
| 0x16 | LAB_00021694 | unknown |
| 0x18 | LAB_00021904 | unknown |
| 0x41–0x4d | read/write parameter services | CLIP memory R/W |

Output control services (registered separately, service codes for op codes 4 and 5 not yet mapped
to EF00 service bytes):
- Op 4 → `cm848_updateOutputControlMaskIndex4` (disable broadcasts)
- Op 5 → `cm848_updateOutputControlMaskIndex5` (enable broadcasts)

---

## Open Questions / Next Steps

**Note:** Calterm is NOT available — that is why this project exists. All paths below are firmware RE or direct ECU memory writes via kuminz-cli.

### Path A (Ghidra): Trace EF00 → op code dispatch table
The output control dispatcher has a table that maps EF00 command bytes to op codes.
Look for: callers of `cm848_registerOutputControlOperations` in `cm848_rom.ghidra.cpp`,
then find the dispatch table entry near `0x0040A7D0` that routes an EF00 byte to op 5.
Pattern to find: `lbz rN, offset(r_payload)` followed by compare/branch to output control handler.

### Path B (kuminz-cli): Direct gate write — bypass the EF00 question entirely
Write `0x000c` directly to `0x0040BA74` and `0x0040BA76` via kuminz-cli and observe
whether the ECU starts broadcasting EEC1/EEC2/etc. on the CAN bus.
If yes: we have a working implementation regardless of which EF00 byte Calterm uses.
Note: `--write-addr` was removed in commit 01d5096 — would need a new `--enable-broadcasts`
command or targeted write support re-added.

### Path C (binary): Decode Flash2[0x539868]
Function has floating-point save/restore opcodes (`stfd`/`lfd`) that Ghidra can't decode.
First 48 bytes suggest MPC555 TouCAN peripheral init (0x003070xx registers).
Full decode may reveal additional broadcast control initialization.
Called once at boot: `hpcr_exceptionHandler @ ROM[0x544C4]` → this function → `initDiagnosticBufferPointers`.

---

## Naming in global_variables.csv

Session 2026-05-19 (initial, since corrected):
- ~~0x003FDDB6 → j1939_tx_path_selector~~ (REMOVED — was EEPROM variable)
- ~~0x003FDDB8 → j1939_tx_busy_flag~~ (REMOVED — was EEPROM variable)
- ~~0x003FDDBA → j1939_tx_state~~ (REMOVED — was EEPROM variable)
- ~~0x003FDDC0 → j1939_tx_message_counter~~ (REMOVED — was EEPROM variable)
- ~~0x003FDDC4 → j1939_tx_buffer_ptr~~ (REMOVED — was EEPROM variable)
- `0x003FD59C` → `fuel_timing_feature_flags` (word) — VALID, used by ROM timing functions

Session 2026-05-19 (corrected, after Ghidra rebuild):
- `0x0040BA74` → `j1939_broadcast_gate_a` (word) — zero at key-off, Gate A
- `0x0040BA76` → `j1939_broadcast_gate_b` (word) — zero at key-off, Gate B
