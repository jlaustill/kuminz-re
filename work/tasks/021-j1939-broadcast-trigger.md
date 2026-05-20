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
| `cm848_dispatchProtectionTimerCallbacks` | Flash2 0x005378A4 | 0x3FD2C2 (group A), 0x3FD38A (group B) | `output_control_mask & 4/8` AND `protection_diagnostic_state_flags & 4/8` |
| `cm848_dispatchCommandSequenceHandlers` | Flash2 0x0053A110 | Jump table at 0x53AC4A | Iterates 48 command slots, updates `command_sequence_state` bitmap |

Timer entries are 10-byte records: `[interval:2][padding:2][handler_ptr:4][counter:2]`.

**Who populates these tables?** Not yet traced — this is still open. Setting `output_enable_bitmap = 1` via service 0x07 or 0x16 may be sufficient if the tables are populated at boot, or the tables may need seeding by a separate step.

### J1939 RX/TX Infrastructure

| Function | Address | Role |
|----------|---------|------|
| `cm848_processJ1939RxDispatch` | Flash2 0x00538EF4 | Reads CAN RX queue at 0x40AD30, dispatches by PGN to handlers at 0x3FD414 |
| `cm848_lookupJ1939PgnHandlerByHash` | Flash2 0x00539768 | Hash-based PGN lookup: `PGN % 0x761 → 0x53AF76 index → 0x53BE38 chain` |
| `cm848_enableJ1939OutputAndSync` | Flash2 0x00539D18 | Sets `output_enable_bitmap = 1`, busy-waits for protection timer sync |
| `initDiagnosticBufferPointers` | Flash2 0x00537CF8 | Registers 16 PGNs at boot (EEC1, EEC2, EEC3, etc.) |

---

## Next Steps

### Step 1: Implement in kuminz-cli (ready to do now)

The trigger is known. Add `--enable-j1939` to kuminz-cli that sends:
1. EF00 service 0x0a (disable/init)
2. EF00 service 0x07 (enable)

Or equivalently, just EF00 service 0x16 (direct enable, no precondition).

Then capture CAN traffic to verify J1939 PGNs start appearing.

### Step 2: Verify timer table population

After sending service 0x07 or 0x16, monitor CAN for periodic EEC1/EEC2 traffic. If it doesn't appear, the timer dispatch tables at 0x3FD2C2/0x3FD38A may also need seeding — trace `initDiagnosticBufferPointers` call chain to understand boot vs. on-demand population.

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
- `cm848_clearProtectionStateAndEvalSensors`, `cm848_enableJ1939OutputAndSync`, `cm848_dispatchCommandSequenceHandlers`

**Conclusion:** Complete Calterm handshake is EF00 0x0a → EF00 0x07. Service 0x16 is a shortcut that skips the init step. The broadcast trigger is now fully identified.
