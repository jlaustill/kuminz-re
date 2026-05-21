# Task 021: CM848D J1939 Broadcast Trigger

**Status:** In Progress  
**Area:** firmware + kuminz-cli  
**Goal:** Identify which CLIP EF00 service byte makes the CM848D start periodically sending J1939 PGNs (EEC1, EEC2, EEC3, etc.), then implement it in kuminz-cli/kuminz-ui.

---

## Problem

The CM848D **never broadcasts J1939 messages autonomously** — it only responds to explicit requests (confirmed by the OCT project at `~/code/oct`). Something in the EF00 command set must trigger the ECU into periodic-transmit mode. Finding that command eliminates the need to poll every PGN individually from kuminz-cli.

**Note:** Capturing Insite/Calterm traffic is NOT an option. No working e2m/Calterm setup exists for this ECU. The trigger must be found via firmware RE.

---

## What We Know (2026-05-20)

### Architecture Correction (Flash2 binary fix, PR #21, 2026-05-20)

The prior investigation was done with a mismatched Flash2 binary. Every Flash2 function at 0x005xxxxx was decompiled incorrectly. The "broadcast gate" theory and all "output control enable" conclusions were **wrong** — entirely artifacts of the old binary.

Correct Flash2 binary is `cm848_flash2_live.bin` (live ECU dump). All analysis below uses this.

### J1939 Output Control: `output_enable_bitmap`

The broadcast master switch. Lives at a RAM address accessed via ECU base register.

| Value | Meaning | Set by |
|-------|---------|--------|
| 0 | J1939 output disabled | Service 0x0a (`cm848_initJ1939MessageBuffers`) |
| 1 | J1939 output enabled | Service 0x07 (`cm848_enableJ1939Output`) — **the trigger** |
| 1 | J1939 output enabled | Service 0x16 (`cm848_enableJ1939OutputDirect`) — alternate path |
| 1 | J1939 output enabled | `cm848_enableJ1939OutputAndSync` (Flash2 0x00539D18), called from cold-start init chain |

### Session State: `torque_value_a346._0_1_`

Byte-sized state tag used alongside `output_enable_bitmap`:

| Value | Meaning |
|-------|---------|
| 0xea | Diagnostic/init mode — set by service 0x0a |
| 0xee | Output active — set by services 0x07 and 0x16 |

### `_j1939_message_buffer_init` flag

Handshake flag between services 0x0a and 0x07:
- Set to `1` by service 0x0a (init/disable sequence)
- Service 0x07 checks `== 1` before enabling; sets it back to `0`
- Service 0x16 skips this precondition check entirely

### Complete EF00 Service Map

`cm848_j1939DiagnosticServiceHandler` (ROM 0x00022128) dispatches via `ef00_service_dispatch_table`:

| Service | Handler | What it does |
|---------|---------|-------------|
| 0x01 | `cm848_advanceDiagnosticActionState` (ROM 0x00021584) | State machine advance for diagnostic enable sequence |
| 0x05 | `cm848_processBoostPressureOffset` (Flash2) | Boost pressure offset calculation — unrelated to broadcasts |
| 0x06 | `cm848_setColdStartActiveFlag` (ROM 0x000216e8) | Sets `_cold_start_active_flag = 1` |
| 0x07 | **`cm848_enableJ1939Output` (ROM 0x00021624)** | **Sets `output_enable_bitmap = 1`, `_j1939_message_buffer_init = 0`, state tag = 0xee. Requires `_j1939_message_buffer_init == 1` (i.e., 0x0a sent first).** |
| 0x0a | `cm848_initJ1939MessageBuffers` (ROM 0x00021668) | Sets `output_enable_bitmap = 0`, `_j1939_message_buffer_init = 1`, state tag = 0xea. Disables J1939 output and arms the 0x07 precondition. |
| 0x0b | `cm848_j1939ProcessRxQueueParam` (ROM 0x000218dc) | ECU reflash entry point — remaps MPC555 chip selects, jumps to RAM stub |
| 0x0c | inline | Special case inline handler |
| 0x0d | inline | Special case inline handler |
| 0x15 | `cm848_validateCalibrationMemory` (ROM 0x00021918) | RAM checksum validation |
| 0x16 | **`cm848_enableJ1939OutputDirect` (ROM 0x00021694)** | **Sets `output_enable_bitmap = 1`, state tag = 0xee. No precondition check — can enable without 0x0a first.** |
| 0x18 | `cm848_setColdStartMode2Flag` (ROM 0x00021904) | Sets `_cold_start_mode_2_flag = 1` |
| 0x41–0x4d | CLIP memory R/W | Read/write CLIP memory regions |
| 0x46 | `cm848_processJ1939DataBlock` (Flash2) stub | 1-arg registration |
| 0x48 | `cm848_processJ1939DataBlock` (Flash2) | `UNK_0050c734` |

### Calterm Handshake Sequence (reverse-engineered)

Based on service handler bodies, the sequence Calterm likely uses:

1. **Send EF00 service 0x0a** → `cm848_initJ1939MessageBuffers` runs:
   - `output_enable_bitmap = 0` (disables any current TX)
   - `_j1939_message_buffer_init = 1` (arms the precondition)
   - state tag = `0xea`
2. **Send EF00 service 0x07** → `cm848_enableJ1939Output` runs:
   - Checks `_j1939_message_buffer_init == 1` (set by step 1)
   - `output_enable_bitmap = 1` (enables J1939 TX)
   - `_j1939_message_buffer_init = 0`
   - state tag = `0xee`

**Alternative (no init required):** Service 0x16 alone sets `output_enable_bitmap = 1` without the 0x0a precondition.

### Timer Dispatch Infrastructure (J1939 TX Scheduler)

J1939 periodic TX is managed through timer dispatch tables in RAM:

| Function | Address | Table | Gate condition |
|----------|---------|-------|----------------|
| `cm848_dispatchFaultTimerHandlers` | Flash2 0x00538D3C | 0x3FD2E2 (group A, max 20), 0x3FD3AA (group B, max 10) | `j1939_dispatch_mode_flags & 8` AND `protection_condition_flags & 4/8` AND `governor_derivative_term_masked & 4/8` |
| `cm848_dispatchCommandSequenceHandlers` | Flash2 0x0053A110 | Jump table at 0x53AC4A | Iterates 48 command slots, updates `command_sequence_state` bitmap |

**NOTE (2026-05-21 correction):** Flash2 0x005378A4 is `cm848_dispatchProtectionTimerCallbacks` — a protection accumulator, NOT the J1939 TX dispatcher. Tables previously listed as 0x3FD2C2/0x3FD38A were wrong. Correct tables are at 0x3FD2E2 (group A) and 0x3FD3AA (group B).

Timer entries are 10-byte records: `[interval:2][padding:2][handler_ptr:4][counter:2]`.
- `j1939_group_a_entry_count` (0x3FD40E) and `j1939_group_b_entry_count` (0x3FD40F) track counts.
- `j1939_group_a_tick_counter` (0x3FD410) and `j1939_group_b_tick_counter` (0x3FD412) are phase-match ticks.
- Tables are populated at boot by `cm848_buildDiagnosticMessageSequence`.

**Triple gate for EEC1/EEC2 broadcasts — all three required:**
1. `j1939_dispatch_mode_flags & 8` (0x3FD5B2) — set during engine-start completion
2. `protection_condition_flags & 4` or `& 8` (0x40ADEE) — requires protection system active (engine running)
3. `governor_derivative_term_masked & 4` or `& 8` (0x40ADE4) — three-channel consensus: `governor_derivative_term[0] & [1] & [2]`; requires engine running

**Conclusion (2026-05-21):** Service 0x16 alone is NOT sufficient. EEC1/EEC2 periodic broadcasts require a physically running engine. Testing requires the truck to be started.

### `j1939_protection_mode_active` (formerly `output_enable_bitmap`)

Variable at 0x0040C04A. Name "output_enable_bitmap" was misleading:

| Value | Set by | Meaning |
|-------|--------|---------|
| 1 | Boot (`cm848_initializeProtectionPointerTable`) | Protection/normal-operation mode active |
| 1 | Service 0x07, 0x16, `cm848_enableJ1939OutputAndSync` | Same — "enable" is re-enabling protection mode |
| 0 | Service 0x0a (`cm848_initJ1939MessageBuffers`) | Basic status mode — simple status queuing active |

**Important:** Basic status messages (`cm848_j1939QueueStatusMessage`) only queue when this is 0. EEC1/EEC2 broadcasts via `cm848_dispatchFaultTimerHandlers` don't gate on this directly — they gate on the protection condition flags above.

### Queued TX Gate: `j1939_queued_tx_in_flight` (0x3FB4CD)

- `mpc555_j1939ConfigureMultiFrame` gates on `j1939_queued_tx_in_flight == 0` before queuing a broadcast frame.
- Should be cleared by `cm848_j1939ProcessTransmitQueue`, but **Flash2 version at 0x0050D2B8 is a no-op stub** (`return;`).
- ROM version at 0x0003DBC0 correctly resets it.
- CLIP response frames bypass this gate entirely via `mpc555_sendJ1939SingleFrame` (direct CAN TX).

### Governor Derivative Term Array (Three-Channel)

`cm848_updateGovernorTimers` proves this is a stride-3 array:
- `governor_derivative_term` (0x0040ADDC) — channel 0
- `governor_derivative_term_1` (0x0040ADE2) — channel 1
- `governor_derivative_term_2` (0x0040ADE8) — channel 2
- `governor_derivative_term_masked` (0x0040ADE4) — AND of all three channels

### J1939 RX/TX Infrastructure

| Function | Address | Role |
|----------|---------|------|
| `cm848_processJ1939RxDispatch` | Flash2 0x00538EF4 | Reads CAN RX queue at 0x40AD30, dispatches by PGN to handlers at 0x3FD414 |
| `cm848_lookupJ1939PgnHandlerByHash` | Flash2 0x00539768 | Hash-based PGN lookup: `PGN % 0x761 → 0x53AF76 index → 0x53BE38 chain` |
| `cm848_enableJ1939OutputAndSync` | Flash2 0x00539D18 | Sets `j1939_protection_mode_active = 1`, busy-waits for protection timer sync |
| `cm848_syncProtectionCalibrationChunk` | Flash2 0x00538A84 | Copies 100 words/call of protection calibration from Flash2 to RAM during cold-start |
| `initDiagnosticBufferPointers` | Flash2 0x00537CF8 | Registers 16 PGNs at boot (EEC1, EEC2, EEC3, etc.) |
| `cm848_initEec1TxDescriptor` | ROM 0x00025AB8 | Initializes EEC1 TX descriptor at 0x3FAD98 with PGN 0xF004 |
| `cm848_engineStartCompletionB` | ROM 0x00054D30 | Second engine-start completion path: loops `cm848_syncProtectionCalibrationChunk` until flag ≠ 0, then calls `cm848_enableJ1939OutputAndSync` |

---

## Next Steps

### Step 1: Test with engine running

OCT cipher fix is complete and confirmed working (`0C 16 FF FF FF FF FF FF` response = service 0x16 success). No EEC1/EEC2 broadcasts appear on bench because the triple gate requires a running engine.

**Action:** Flash OCT, start truck engine, monitor CAN2 for EEC1 (PGN 0xF004) and EEC2 (PGN 0xF003) periodic frames.

**Expected result if firmware analysis is correct:** Broadcasts appear within seconds of engine start, at ~10ms (EEC1) and ~50ms (EEC2) intervals.

**If broadcasts still don't appear with engine running:**
- Check `j1939_dispatch_mode_flags & 8` (0x3FD5B2) — may need a different boot sequence
- Check `j1939_queued_tx_in_flight` (0x3FB4CD) — Flash2 no-op stub may permanently block queued TX path; ROM version may need to be called
- Read `protection_condition_flags` (0x40ADEE) via service 0x4A to verify bits 4/8 are set

### Step 2: If engine-running test confirms broadcasts

Update todo.md to mark task 021 complete. Document confirmed sequence in task file.

---

## Investigation Log

### 2026-05-19

**Pipeline fix:** Discovered prior Ghidra pipeline ran `analyze` before `memmap`/`import`, leaving Flash2 absent. Fixed `analyze.sh full` order to `init → memmap → import → analyze → export`. Rebuilt decompilation from scratch.

**EEPROM correction:** Flash2[0x505F98] was previously misidentified as a J1939 TX scheduler. After rebuild, confirmed it is `cm848_processProtectionParameterData` — EEPROM scatter write engine.

**Broadcast infrastructure mapped:** All 16 registered PGNs visible in `initDiagnosticBufferPointers` decompilation.

### 2026-05-20

**Flash2 binary fix impact:** All prior "broadcast gate" and "output control enable" conclusions were wrong — artifacts of old e2m-extracted Flash2 binary. Variables `j1939_broadcast_gate_a/b` @ 0x0040BA74/76 renamed to `protection_event_accumulator_a/b` (protection counters, unrelated to J1939 TX). Functions `cm848_updateOutputControlMask*` / `cm848_registerOutputControlOperations` renamed to `cm848_selectBoostDemandSource*` / `cm848_setBoostDemandNumerator` (boost pressure control).

**All 5 unknown EF00 service handlers decoded** by adding their ROM addresses to `function_renames.csv` (forcing Ghidra to create functions at what were previously code labels):

- Service 0x01 → `cm848_advanceDiagnosticActionState`: state machine; sets `_j1939_comm_handler_state` bits
- Service 0x06 → `cm848_setColdStartActiveFlag`: sets `_cold_start_active_flag = 1`
- **Service 0x07 → `cm848_enableJ1939Output`: THE BROADCAST TRIGGER — sets `output_enable_bitmap = 1` after checking `_j1939_message_buffer_init == 1`**
- Service 0x16 → `cm848_enableJ1939OutputDirect`: alternate enable, no precondition
- Service 0x18 → `cm848_setColdStartMode2Flag`: sets `_cold_start_mode_2_flag = 1`

**Corrected Flash2 function names** (5 wrong names from old binary fixed):
- `cm848_processProtectionDiagnosticState` → `cm848_dispatchProtectionTimerCallbacks`
- `cm848_updateOutputControlMask` → `cm848_selectBoostDemandSource`
- `cm848_updateOutputControlMaskIndex4/5` → `cm848_selectBoostDemandSourceFromParam` / `cm848_copyBoostDemandToBuffer`
- `cm848_registerOutputControlOperations` → `cm848_setBoostDemandNumerator`

**Named 6 previously unnamed Flash2 dataTable_ stubs:**
- `cm848_noOpStub`, `cm848_processJ1939RxDispatch`, `cm848_lookupJ1939PgnHandlerByHash`
- `cm848_initTouCanAndJ1939Handlers`, `cm848_enableJ1939OutputAndSync`, `cm848_dispatchCommandSequenceHandlers`

**Conclusion:** Complete Calterm handshake is EF00 0x0a → EF00 0x07. Service 0x16 is a shortcut that skips the init step. The broadcast trigger is now fully identified.

### 2026-05-20 (continued) — Boot chain confirmed in decompiled output

**Flash2 memory stale data:** Flash2 block had wrong content at 0x539xxx — `ForceAnalyzeFunction` was reading garbage bytes and "successfully" creating broken functions. Root cause: `memmap` must be run before `forceanalyze` to ensure the Flash2 block holds live-dump data. After `memmap`, forceanalyze correctly disassembles.

**`clearCodeUnits` required before `disassemble`:** `ForceAnalyzeFunction.java` updated to call `listing.clearCodeUnits(addr, addr.add(3), false)` before `disassemble(addr)`. Without this, stale "bad instruction" code units at the entry point block the disassembler silently (returns `true` but writes nothing). Re-running `./analyze.sh analyze` after forceanalyze does NOT fix this — Ghidra skips already-analyzed addresses.

**Auto-analysis does not fix already-known broken functions:** Running `./analyze.sh analyze` after the functions existed as stale records did nothing — the aggressive instruction finder skips addresses that already have function records. `forceanalyze` (delete → clearCodeUnits → disassemble → createFunction) is the correct fix.

**Name correction:** `cm848_clearProtectionStateAndEvalSensors` (0x00539868) was renamed to `cm848_initTouCanAndJ1939Handlers`. Real decompilation shows TouCAN A hardware init (clears IMASK, configures MB0, zeros 16 mailbox data bytes, clears MCR) followed by `cm848_initAllJ1939Handlers()`. Protection state clearing was a wrong-binary artifact.

**Boot chain visible in decompiled output:** `hpcr_exceptionHandler` calls many init functions, then calls `FUN_00527860` which is the last visible call. The code from 0x00054a9c onwards is a second init batch Ghidra thought was dead code. Created `cm848_initializationContinuation` at 0x00054a9c via forceanalyze — it now appears in the decompilation and includes the call to `cm848_initTouCanAndJ1939Handlers`. Full chain now visible:

```
hpcr_exceptionHandler (boot reset handler)
  → cm848_initializationContinuation (0x00054a9c) [second init batch]
      → cm848_initTouCanAndJ1939Handlers (0x00539868) [TouCAN init + J1939 setup]
          → cm848_initAllJ1939Handlers (0x00539190) [registers all PGN handlers]
              → cm848_registerJ1939DiagnosticHandlers [populates EF00 dispatch table]
```

Added `forceanalyze` command to `analyze.sh` / `common.sh` (backed by `ForceAnalyzeFunction.java`) for future use on functions missed by Ghidra auto-analysis.

### 2026-05-21 — Response decoding, broadcast root cause, naming cleanup

**`cm848_sendJ1939ResponseFrame` decoded (0x000249C4):**
- Response prefix `0x0C` = service returned 0 (success)
- Response prefix `0x0D` = service returned non-zero (error); next byte is return code, then service byte
- Response prefix `0x0E` = extended response (data follows)
- OCT log `0C 16 FF FF FF FF FF FF` confirms service 0x16 succeeded and `j1939_protection_mode_active = 1`

**Broadcast root cause identified — engine must be running:**
`cm848_dispatchFaultTimerHandlers` (Flash2 0x00538D3C) — the actual J1939 EEC1/EEC2 periodic TX dispatcher — has a triple gate that all requires the engine running:
1. `j1939_dispatch_mode_flags & 8` (0x3FD5B2) — set during engine-start completion via `cm848_initializationContinuation` / `cm848_engineStartCompletionB`
2. `protection_condition_flags & 4` or `& 8` (0x40ADEE, type corrected to `word`) — protection monitoring active
3. `governor_derivative_term_masked & 4` or `& 8` — three-channel governor consensus, all channels non-zero only when engine is running and controlling speed

Service 0x16 alone cannot trigger periodic broadcasts on a bench without a running engine.

**`j1939_protection_mode_active` (formerly `output_enable_bitmap`, 0x0040C04A):**
Name "output_enable_bitmap" was misleading — value 1 = normal/protection mode (set at boot and by service 0x07/0x16); value 0 = basic status mode (set by service 0x0a). Basic status messages only queue when it's 0; EEC1/EEC2 broadcasts don't gate on this directly.

**`j1939_queued_tx_in_flight` (0x3FB4CD):**
Queued J1939 TX path (`mpc555_j1939ConfigureMultiFrame`) is permanently gated unless this = 0. Flash2 `cm848_j1939ProcessTransmitQueue` (0x0050D2B8) is a no-op stub — never clears it. ROM version (0x0003DBC0) works correctly. CLIP responses bypass this via `mpc555_sendJ1939SingleFrame` directly.

**Three-channel governor derivative array confirmed:**
Stride-3 array: `governor_derivative_term` (0x0040ADDC), `governor_derivative_term_1` (0x0040ADE2), `governor_derivative_term_2` (0x0040ADE8). Previously `0x0040ADE8` was misnamed `governor_derivative_mask`.

**CSV changes applied (2026-05-21):**
- function_renames: +`cm848_syncProtectionCalibrationChunk` (0x538A84), +`cm848_initEec1TxDescriptor` (0x25AB8), +`cm848_engineStartCompletionB` (0x54D30)
- global_variables: renamed `output_enable_bitmap` → `j1939_protection_mode_active`, `governor_derivative_mask` → `governor_derivative_term_2`; type fix `protection_condition_flags` byte→word; added 9 new variables: `j1939_queued_tx_in_flight`, `protection_calibration_changed_flag`, `protection_calibration_sync_prev_mode`, `j1939_group_a/b_entry_count`, `j1939_group_a/b_tick_counter`, `j1939_dispatch_mode_flags`, `governor_derivative_term_1`
