# Task 021: CM848D J1939 Broadcast Trigger

**Status:** In Progress  
**Area:** firmware + kuminz-cli  
**Goal:** Identify which CLIP EF00 service byte enables J1939 broadcasts on the CM848D, then implement it in kuminz-cli/kuminz-ui so broadcasts work without Calterm.

---

## Problem

The CM848D does not broadcast J1939 messages (EEC1, EEC2, EEC3, etc.) until something enables them. Calterm triggers broadcasts on connect. kuminz-cli/kuminz-ui cannot because we don't know what Calterm sends.

**Important:** Capturing Insite/Calterm traffic is NOT an option (no hardware, that's why this project exists). The trigger must be found via firmware RE.

---

## What We Know (2026-05-19)

### Broadcast Infrastructure (fully mapped)

| Component | Location | Role |
|-----------|----------|------|
| `initDiagnosticBufferPointers` | Flash2[0x537CF8] | Registers 16 PGNs at boot (EEC1, EEC2, EEC3, etc.) |
| `cm848_processProtectionDiagnosticState` | Flash2[0x5378A4] | Periodic dispatcher — fires PGN handlers when timers expire |
| `cm848_updateOutputControlMaskIndex5` | Flash2[0x5099B8] | Enable function — sets gate bit pattern 0xc |
| `cm848_updateOutputControlMaskIndex4` | Flash2[0x5099B4] | Disable function |

### Broadcast Gates

Both must be non-zero for broadcasts to fire:

| Gate | Address | Key-off value |
|------|---------|--------------|
| Gate A | `0x0040BA74` | `0x0000` |
| Gate B | `0x0040BA76` | `0x0000` |

Binary-verified from `cm848_processProtectionDiagnosticState`:
```asm
lis r31, 0x41 / addi r31, r31, -0x458c  → r31 = 0x0040BA74  (gate_A)
lis r27, 0x41 / addi r27, r27, -0x458a  → r27 = 0x0040BA76  (gate_B)
```

### Enable Path

`cm848_updateOutputControlMaskIndex5` is registered as **output control op 5** via `cm848_registerOutputControlOperations`. When triggered, it calls `cm848_updateOutputControlMask(param_1, 1)` which writes to **0x0040A7D4** (not 0x0040A9B0 as Ghidra names it).

The relationship between 0x0040A7D4 (write target) and 0x0040BA74/76 (gate reads) is not yet clear — they may be the same physical location read via different register-computed offsets, or the gate variable may be derived from 0x0040A7D4 via some transformation.

### CLIP EF00 Service Map (partial)

`cm848_j1939DiagnosticServiceHandler @ ROM[0x00022128]` dispatches on first payload byte:

| Service | Handler |
|---------|---------|
| 0x01 | unknown |
| 0x06 | unknown |
| 0x07 | unknown |
| 0x0a | `cm848_initJ1939MessageBuffers` |
| 0x0b | `cm848_j1939ProcessRxQueueParam` |
| 0x0c | special case |
| 0x0d | special case |
| 0x15 | `cm848_validateCalibrationMemory` |
| 0x16 | unknown |
| 0x18 | unknown |
| 0x41–0x4d | CLIP memory R/W |

Output control ops 4 and 5 are registered separately. The EF00 service bytes that trigger them are not yet mapped.

---

## Investigation Paths (no Calterm required)

### Path A: Ghidra trace — EF00 → op code dispatch table

The output control dispatcher has a table that maps EF00 command bytes to op codes. Find it:
1. Trace callers of `cm848_registerOutputControlOperations` in `cm848_rom.ghidra.cpp`
2. Look for the command dispatch table near `0x0040A7D0` (write target of op 5 is at `0x0040A7D4`)
3. Find the table entry that maps some EF00 byte → op code 5

Look for code pattern: `lbz rN, offset(r_payload)` followed by compare/branch to the output control handler.

### Path B: Direct gate write — bypass the EF00 question

Add a kuminz-cli command that writes `0x000c` (the bit pattern `cm848_updateOutputControlMaskIndex5` sets) directly to `0x0040BA74` and `0x0040BA76`, then observe whether the ECU starts broadcasting on the CAN bus.

This tests the hypothesis that setting the gate variables is sufficient, regardless of what EF00 service byte normally triggers it. If broadcasts start, we have a working implementation (even if not the "proper" Calterm path).

Note: `--write-addr` was removed from kuminz-cli in commit 01d5096. Would need to be re-added or a targeted `--enable-broadcasts` command added.

### Path C: Flash2[0x539868] decode

This boot-init function passes through the call chain from `hpcr_exceptionHandler` to `initDiagnosticBufferPointers`. It hits bad instructions in Ghidra (floating-point register save/restore: `stfd`, `lfd`). Manual binary decode of the first 48 bytes suggests it initializes MPC555 CAN hardware registers (0x003070xx = TouCAN peripheral). Full decode may reveal additional broadcast control initialization.

---

## Investigation Log

### 2026-05-19

**Pipeline fix:** Discovered that prior Ghidra pipeline ran `analyze` before `memmap`/`import`, leaving Flash2 absent during analysis. Fixed `analyze.sh full` order to `init → memmap → import → analyze → export`. Rebuilt entire decompilation from scratch.

**EEPROM correction:** Flash2[0x505F98] was previously misidentified as a J1939 TX scheduler. After rebuild, confirmed it is `cm848_processProtectionParameterData` — an EEPROM scatter write engine. Removed 5 wrong `j1939_tx_` variable names, added correct `eeprom_` names.

**Broadcast infrastructure mapped:** All 16 registered PGNs visible in `initDiagnosticBufferPointers` decompilation. Gate addresses confirmed via binary decode (not Ghidra decompilation, which had wrong addresses).

**Remaining unknown:** Which EF00 service byte triggers output control op 5. This is the only gap between current state and working kuminz-cli broadcast enable.
