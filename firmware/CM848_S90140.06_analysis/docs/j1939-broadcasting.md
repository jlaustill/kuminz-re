# CM848D J1939 Broadcasting — Definitive Reference

**Firmware:** S90140.06 (Bank 1 ROM + Bank 2 Flash2, MPC555 PowerPC)  
**Status:** Solved — three-step EF00 enable sequence confirmed working in truck (2026-05-21)  
**See also:** `j1939_broadcast_investigation.md` for the full RE journey

---

## Summary

The CM848D **does not broadcast J1939 messages at key-on** unless a CLIP EF00 service sequence
enables them. Once enabled, the ECU broadcasts EEC1, EEC2, EEC3, ET1, IC1, EFL/P1, VEP1, AMB,
and others continuously. Broadcasts stop if the ECU resets or if a protection event clears the
gate variable.

---

## Why Broadcasts Are Gated

### The dispatch gate

`cm848_processProtectionDiagnosticState @ Flash2[0x5378A4]` runs periodically and fires all
registered PGN handlers. It checks two gate variables before sending anything:

| Variable | Address | Key-off value |
|----------|---------|---------------|
| `j1939_broadcast_gate_a` | `0x0040BA74` | `0x0000` |
| `j1939_broadcast_gate_b` | `0x0040BA76` | `0x0000` |

Both must be non-zero for broadcasts to fire. At key-on without the enable sequence, both are
`0x0000` — the ECU sits silent.

### The latch point

`flash2_cm848_checkJ1939ParameterValidityType2` (triggered by EF00 service 0x05) writes to
`protection_condition_flags @ 0x0040ADEE`, setting bits 2 and 3 (mask `0x000C`). This is what
the enable sequence ultimately sets. If bits 2+3 are cleared (by a protection event or ECU reset),
broadcasts stop — the full enable sequence must be re-sent.

The exact propagation path from `0x0040ADEE` → `0x0040BA74/BA76` is partially resolved
(one is set by 0x0A, the other by the 0x05 call) but not fully traced in Ghidra.

---

## Enable Sequence

Three EF00 service frames, sent to the ECU via CLIP on PGN 0xEF00 with 200ms between each step.

| Step | Service byte(s) | Firmware function | What it does |
|------|----------------|-------------------|--------------|
| 1 | `0x0A` | `cm848_initJ1939MessageBuffers` | Arms the J1939 buffer precondition flag; clears `j1939_protection_mode_active` |
| 2 | `0x07` | `cm848_enableJ1939Output` | Sets `j1939_protection_mode_active = 1` |
| 3 | `0x05 0x01 0x01` | `flash2_cm848_checkJ1939ParameterValidityType2` | Sets `protection_condition_flags \|= 0x0C` — **this is the key step** |

Without step 3, `protection_condition_flags` stays `0x0000` and the EEC1/EEC2 timer dispatch
is permanently blocked regardless of what steps 1 and 2 did.

### Why `0x05 0x01 0x01` and not just `0x05`?

Service 0x05 dispatches based on the payload bytes. `0x01 0x01` selects the
"set bits" path inside `flash2_cm848_checkJ1939ParameterValidityType2`. Without those data bytes
the call takes a different branch that does not set the protection flags.

### kuminz-cli command

```bash
kuminz-cli <can-interface> --enable-j1939
```

This sends all three steps in order with appropriate delays and logs each step:

```
[1/3] Sending service 0x0a (cm848_initJ1939MessageBuffers)...
      Clears j1939_protection_mode_active, arms _j1939_message_buffer_init

[2/3] Sending service 0x07 (cm848_enableJ1939Output)...
      Sets j1939_protection_mode_active=1

[3/3] Sending service 0x05 01 01 (flash2_cm848_checkJ1939ParameterValidityType2)...
      Sets protection_condition_flags |= 0x0C (unlocks EEC1/EEC2 timer dispatch)
```

---

## CLIP Frame Format

All EF00 service frames use the J1939 proprietary protocol (PGN 0xEF00). The ECU source
address is `0x00`; the tool address is `0xF9` (Calterm/Insite convention).

| Direction | CAN ID (extended) | Description |
|-----------|-------------------|-------------|
| Tool → ECU | `0x18EF00F9` | Request: priority 6, PGN EF00, dest=0x00, src=0xF9 |
| ECU → Tool | `0x18EFF900` | Response: priority 6, PGN EF00, dest=0xF9, src=0x00 |

Single-frame EF00 request format (8 bytes, zero-padded):
```
[service_id] [data0] [data1] ... [0x00] [0x00] ...
```

Example — step 3 (`0x05 0x01 0x01`):
```
05 01 01 00 00 00 00 00
```

---

## J1939 PGN Table

Once the enable sequence is sent, the ECU broadcasts the following PGNs. All frames use
source address `0x00`. Unused bytes are `0xFF` per SAE J1939-71 ("not available").

### High-rate broadcasts (ECU firmware: 20ms)

| PGN | Name | CAN ID | Rate |
|-----|------|--------|------|
| 61444 | EEC1 — Engine Electronic Control 1 | `0x0CF00400` | 20ms |
| 61443 | EEC2 — Engine Electronic Control 2 | `0x0CF00300` | 20ms (10ms offset) |

### Mid-rate broadcasts (ECU firmware: 50ms)

| PGN | Name | CAN ID | Rate |
|-----|------|--------|------|
| 65247 | EEC3 — Engine Electronic Control 3 | `0x18FEDF00` | 50ms |

### Low-rate broadcasts (ECU firmware: 500ms–1000ms)

| PGN | Name | CAN ID | Rate |
|-----|------|--------|------|
| 65262 | ET1 — Engine Temperature 1 | `0x18FEEE00` | 1000ms |
| 65270 | IC1 — Inlet/Exhaust Conditions 1 | `0x18FEF600` | ~500ms |
| 65263 | EFL/P1 — Engine Fluid Level/Pressure 1 | `0x18FEEF00` | ~500ms |
| 65271 | VEP1 — Vehicle Electrical Power 1 | `0x18FEF700` | ~1000ms |
| 65269 | AMB — Ambient Conditions | `0x18FEF500` | ~1000ms |

The firmware registers 16 PGNs total at boot via `initDiagnosticBufferPointers @ Flash2[0x537CF8]`.
The 8 above are confirmed by in-truck capture. Additional PGNs (DM1, EH, CCVS, etc.) may also
broadcast — run `candump <interface>` after enabling to see the full set.

---

## SPN Byte Layouts (Confirmed from In-Truck Data)

### PGN 61444 — EEC1

| Byte | SPN | Parameter | Encoding |
|------|-----|-----------|----------|
| 0 | 899 | Engine torque mode | `0xFF` (not available) |
| 1 | 512 | Driver demand — percent torque | `0xFF` (not available) |
| 2 | 513 | Actual engine percent torque | uint8, 1%/bit, −125% offset → `val = byte − 125` |
| 3–4 | 190 | Engine speed | uint16 LE, 0.125 rpm/bit → `rpm = (buf[4]<<8 \| buf[3]) × 0.125` |
| 5 | 1483 | Source address of controlling device | `0x00` (ECU itself) |
| 6 | 2432 | Engine starter mode | `0xF0` (not available) |
| 7 | — | Reserved | `0xFF` |

### PGN 61443 — EEC2

| Byte | SPN | Parameter | Encoding |
|------|-----|-----------|----------|
| 0 | — | Reserved | `0xFF` |
| 1 | 91 | Accelerator pedal position 1 | uint8, 0.4%/bit → `apps% = byte × 0.4` |
| 2 | 92 | Engine % load at current speed | uint8, 1%/bit → `load% = byte` |
| 3–7 | — | Remaining SPNs | `0xFF` (not available) |

### PGN 65262 — ET1 (Engine Temperature 1)

| Byte | SPN | Parameter | Encoding |
|------|-----|-----------|----------|
| 0 | 110 | Engine coolant temperature | uint8, 1°C/bit, −40°C offset → `°C = byte − 40` |
| 1–3 | — | Engine fuel, oil temps | `0xFF` (not available) |
| 4 | 52 | Engine intercooler temperature | uint8, 1°C/bit, −40°C offset → `°C = byte − 40` |
| 5–7 | — | Reserved | `0xFF` |

### PGN 65270 — IC1 (Inlet/Exhaust Conditions 1)

| Byte | SPN | Parameter | Encoding |
|------|-----|-----------|----------|
| 0–2 | — | Turbo outlet pressure, boost pressure | TBD — not decoded |
| 3 | 105 | Intake manifold 1 temperature | uint8, 1°C/bit, −40°C offset → `°C = byte − 40` |
| 4–7 | — | Remaining SPNs | TBD |

### PGN 65263 — EFL/P1 (Engine Fluid Level/Pressure 1)

| Byte | SPN | Parameter | Encoding |
|------|-----|-----------|----------|
| 0–3 | — | Fuel delivery pressure, fuel filter diff | TBD |
| 4 | 100 | Engine oil pressure | uint8, 4 kPa/bit → `kPa = byte × 4` |
| 5–7 | — | Remaining | TBD |

### PGN 65271 — VEP1 (Vehicle Electrical Power 1)

| Byte | SPN | Parameter | Encoding |
|------|-----|-----------|----------|
| 0–3 | — | Net battery current, alternator current | TBD |
| 4–5 | 168 | Battery potential (voltage) | uint16 LE, 0.05V/bit → `V = (buf[5]<<8 \| buf[4]) × 0.05` |
| 6–7 | — | Reserved | `0xFF` |

### PGN 65269 — AMB (Ambient Conditions)

| Byte | SPN | Parameter | Encoding |
|------|-----|-----------|----------|
| 0 | 108 | Barometric pressure | TBD |
| 1–2 | — | Cab interior temp | `0xFF` (not available) |
| 3–4 | 171 | Ambient air temperature | uint16 LE, 0.03125°C/bit, −273.15°C offset → `°C = (buf[4]<<8 \| buf[3]) × 0.03125 − 273.15` |
| 5–7 | — | Reserved | `0xFF` |

Note: on this truck the AMB sensor lives after the air filter but before the turbo — it reads
intake air temperature, not ambient outside temperature.

---

## Watchdog Behaviour (Embedded OCT Device)

The oct embedded bridge (Teensy 4.1, `~/code/oct`) runs a watchdog to handle ECU resets:

1. After enabling, monitor for EEC1 frames on CAN ID `0x0CF00400`.
2. If EEC1 is absent for 1000ms, read `protection_condition_flags @ 0x0040ADEE` via CLIP service 0x4A.
3. If bits 2+3 (`mask 0x000C`) are cleared → re-run the full enable sequence from step 1.
4. If bits 2+3 are still set → engine is off, no re-enable needed.

For kuminz-cli (one-shot tool), re-enabling is manual: re-run `--enable-j1939` if broadcasts stop.
Check the protection flags first:

```bash
kuminz-cli <can-interface> --read-addr 0040ADEE 2
```

Bits 2+3 of the returned word must be `1` for broadcasts to be active.

---

## Verification

After running `kuminz-cli <can-interface> --enable-j1939`, verify with candump:

```bash
candump <can-interface>
```

Within ~100ms you should see EEC1 and EEC2 appearing at ~50 frames/second combined:

```
can0  0CF00400   [8]  F0 FF D3 00 00 00 F0 FF   # EEC1: ~0 RPM (engine off)
can0  0CF00300   [8]  FF 00 00 FF FF FF FF FF    # EEC2: APPS=0%, load=0%
can0  18FEDF00   [8]  ...                         # EEC3
can0  18FEEE00   [8]  42 FF FF FF 52 FF FF FF    # ET1: coolant=26°C, intercooler=42°C
```

If you see no frames after 2 seconds, the enable sequence did not take. Check that:
1. The CAN interface is connected to the Cummins bus (not the J1939 ATA bus).
2. The ECU is powered (key-on).
3. The CLIP session established successfully (watch for session errors in kuminz-cli output).

---

## CLIP EF00 Service Dispatch Table (Partial)

From `cm848_j1939DiagnosticServiceHandler @ ROM[0x00022128]`:

| Service byte | Handler | Notes |
|-------------|---------|-------|
| 0x01 | LAB_00021584 | Unknown |
| 0x05 | `flash2_cm848_checkJ1939ParameterValidityType2` | Sets protection flags — **broadcast gate** |
| 0x06 | LAB_000216E8 | Unknown |
| 0x07 | `cm848_enableJ1939Output` | Sets `j1939_protection_mode_active = 1` |
| 0x0A | `cm848_initJ1939MessageBuffers` | Arms buffer precondition flag |
| 0x0B | `cm848_j1939ProcessRxQueueParam` | RX queue param |
| 0x0C | (inline in handler) | Special case |
| 0x0D | (inline in handler) | Special case |
| 0x15 | `cm848_validateCalibrationMemory` | Calibration |
| 0x16 | LAB_00021694 | Was originally tried as a broadcast enable — **does not work** |
| 0x18 | LAB_00021904 | Unknown |
| 0x41–0x4D | Various | CLIP memory read/write |

Output control operations 4 (disable) and 5 (enable) are registered separately via
`cm848_registerOutputControlOperations`. Op 5 calls `cm848_updateOutputControlMaskIndex5`,
which writes a bit pattern (`0x0C`) to an output control mask variable.

---

## Related Files

| File | Purpose |
|------|---------|
| `docs/j1939_broadcast_investigation.md` | Full RE journey: dead ends, corrections, binary decodes |
| `clip-core/src/ECUReader.cpp` | `enableJ1939Broadcasts()` implementation |
| `kuminz-cli/src/main.cpp` | `--enable-j1939` CLI command handler |
| `~/code/oct/src/data/cm848-broadcast-controller.cpp` | Embedded watchdog implementation |
| `~/code/oct/src/data/cm848-j1939-receiver.cpp` | Full SPN decode for all 7 parsed PGNs |
