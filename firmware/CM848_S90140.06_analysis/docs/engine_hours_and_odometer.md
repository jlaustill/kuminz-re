# Engine Hours & Odometer — CM848D (S90140.06)

Authoritative map of every path known or ruled out for reading engine hours
and vehicle odometer from a 2004.5 Dodge 5.9L Cummins CM848D over J1939.

**Firmware analyzed:** `cm848_rom.bin` (Bank 1, 448 KB) + `cm848_flash2_live.bin`
(Bank 2, 248 KB). Calibration V11.46.06 (S90140.06).

**Caveat up front:** addresses pulled from `output/e2m_parameters.csv` come from
the shipped S90140.12 e2m file (V11.20.13.16). That is a *different* calibration
than the live ECU's firmware and the literals below do **not** appear in
`cm848_rom.ghidra.cpp`. Any address in the "via CLIP memory read" section must
be re-verified on the bench before being trusted — see
[Verification](#verification) at the bottom.

---

## TL;DR

| Value                                  | J1939 path                 | CLIP path                             | Status            |
| -------------------------------------- | -------------------------- | ------------------------------------- | ----------------- |
| **Vehicle distance (trip + total)**    | PGN 0xFEE0 (VD)            | —                                     | Works today       |
| **Odometer (ECU-internal, miles)**     | *none*                     | Svc 0x4A at EEPROM `0x01000BD8` (u32) | Works (read-back path exercised by `tools/update_odometer.sh`) |
| **Rolls odometer buffer**              | *none*                     | Svc 0x4A at EEPROM `0x01001A84` (u16) | Works             |
| **ECM run time (key-on seconds)**      | *none*                     | Svc 0x4A at EEPROM `0x01000030` (u32) — firmware-traced via `mpc555_keyOnStateMachine` | **Needs truck verification** (see below) |
| **ECM run time (RAM, live)**           | *none*                     | Svc 0x4A at RAM `0x00302012` (`ecm_runtime_accumulator`) | **Needs truck verification** |
| **Session time (RAM, live)**           | *none*                     | Svc 0x4A at RAM `0x0040B150` (`session_time_counter`, 1.5 Hz) | Bench-verified 2026-04-08 |
| **Engine run time (engine-running s)** | *none*                     | `0x0111BC00` is **not a physical address** — unreachable via known services | **Blocked** (see dead end below) |
| **PGN 0xFEE5 (Engine Hours/Revs)**     | **Does not exist in firmware** | —                                 | Ruled out        |

---

## Update 2026-06-07 — static re-analysis (post working-RAM naming campaign)

After naming the full `0x0040xxxx` working-RAM ≥5-ref tier and adding
`scripts/xref_addr.py` (whole-binary access + NEVER-WRITTEN detector), I re-checked
the open engine-hours question. **Conclusion: bench-blocked, not static-blocked** —
persistence lives in MPC555-module RAM (`0x003xxxxx`) plus a computed-address EEPROM
scatter save that fires only on key-off, so more static RE won't pin the address.
Three concrete results:

### New untested candidate: `Hour_Meter` @ EEPROM `0x01001C00`

`e2m_parameters.csv:5529` — `Hour_Meter,,0x01001C00,4,MIN,0.00333329989,HOUR METER
(ECM RUN TIME)`: u32, 1/300 min/bit (= 0.2 s/bit, same as `Engine_Run_Time`).
**Not in the 2026-04-08 results table — never tested.** Worth a bench read because:
- it sits INSIDE the readable Svc-0x4A EEPROM window (`0x01000000–0x01001FFF`;
  `0x1C00 < 0x2000`), unlike the unreachable virtual `0x0111BC00` / `0x01140500`;
- it is the only parameter literally named "HOUR METER (ECM RUN TIME)".
Caveat: e2m `0x01xxxxxx` addrs are Calterm-virtual and have been wrong before
(odometer e2m `0x018A1322` ≠ real `0x01000BD8`) — a candidate to test, not confirmed.
Key-cycle test (EEPROM is write-on-shutdown): `--read-addr 01001C00 2` + `01001C02 2`.

### Firmware-traced `0x01000030` re-confirmed (static)

`mpc555_eepromWriteWords(0x3fee2a,&eeprom_config_block,4)` and `eeprom_config_block`
is at EEPROM `0x01000030` — consistent with the 2026-04-09 trace of
`ecm_runtime_accumulator → 0x01000030`. Still bench-unverified.

### Naming conflicts to reconcile on the next bench

The working-RAM campaign assigned asm-cited names that DISAGREE with this doc's
bench labels. One side is wrong — resolve by reading these live while watching for
the 1.5 Hz tick:

| Address | Campaign name (asm-derived) | This doc's bench label |
|---------|------------------------------|------------------------|
| `0x0040B150` | `protection_fuel_demand_snapshot` (written by sensor-buffer copy) | `session_time_counter` (1.5 Hz) |
| `0x0040B2C2` | `cold_start_injection_protection_flag` (bit7 protection cfg) | "copy of session_time_counter" |
| `0x0040BDF6` | `sensor_channel102_raw` | "scatter write pointer" |

If the bench re-confirms a 1.5 Hz tick at `0x0040B150`, the campaign name is wrong
and the CSV should be corrected; if not, the bench address was approximate.

---

## J1939 PGN inventory (what this ECU actually speaks)

From `cm848_rom.ghidra.cpp` lines 95932–95951 — the periodic TX registration
table inside `cm848_initJ1939ProtocolHandlers` (0x232B4) calling
`cm848_enqueueDataRecord(queue, tag, period_ms, offset, handler)`:

| Tag    | Period | Handler              | J1939 PGN this produces |
| ------ | ------ | -------------------- | ----------------------- |
| 0xFEF1 | 100 ms | `0x243F0`            | CCVS (Cruise/Vehicle Speed) |
| 0xF004 | 20 ms  | `LAB_00025B04`       | EEC1 (RPM/Torque)       |
| 0xF003 | 20 ms  | `0x25D88`            | EEC2 (Accelerator Pedal)|
| 0xFEDF | 50 ms  | `0x26060`            | EEC3                    |
| 0xFEE3 | 5000 ms| `0x1B9A8`            | EC1 Engine Config       |
| 0xF000 | 100 ms | `LAB_000264B0`       | ETC1                    |
| 0xFEE1 | 5000 ms| `0x268C8`            | WFI                     |
| 0xFEEE | 1000 ms| `0x2629C`            | ET1 Engine Temp 1       |
| 0xFED9 | 250 ms | `0x242A0`            | PTODE                   |
| 0xFEEF | 500 ms | `0x2612C`            | EFL/P                   |
| 0xFEF0 | 100 ms | `0x2BFD0`            | PTO                     |
| 0xFEF5 | 1000 ms| `0x24104`            | AMB                     |
| 0xFEF6 | 500 ms | `0x26750`            | IC1                     |
| 0xFEF7 | 1000 ms| `LAB_00026F68`       | VEP                     |
| **0xFFE0** | **200 ms** | **`cm848_initPgn65248VehicleDistanceHandler`** | See note below |
| 0xFECA | 1000 ms| `0x24FF0`            | DM1                     |
| 0xFEBD | 1000 ms| `0x26694`            | BJM1                    |
| 0xF001 | 100 ms | `0x258F4`            | ETC2                    |
| 0xFEFF | 10000 ms| `0x27108`           | ACKM?                   |

**There is no row for 0xFEE5 (Engine Hours) and no row for anything that
could plausibly carry an odometer value as a distinct PGN.**

### The "0xFFE0 vehicle-distance" oddity

The `0xFFE0` tag in the enqueue call does *not* mean the ECU broadcasts as
Proprietary A. `cm848_initPgn65248VehicleDistanceHandler` @ 0x26C6C
hard-codes the transmitted CAN ID:

```c
_DAT_003faec8 = CONCAT13(((byte)PTR_DAT_003fd86a._0_2_ & 7) << 2, 0xfee000);
// ...
_DAT_003faec8 = CONCAT31(_DAT_003faec8, (char)j1939_source_address);
cm848_j1939RegisterPgnHandler(0xe0, 0xb0, param_3);
```

The constructed ID puts PGN = **0xFEE0** (Vehicle Distance) with a priority
pulled from calibration `PTR_DAT_003fd86a`, then overlays the ECU source
address. The `0xFFE0` in the enqueue table is a handler-table slot tag, not
the wire PGN. Bench scan confirms: request `18EAFF00#E0FE00` → response
`18FEE000#…` (working as standard FEE0).

**TODO on the bench:** run a 60 s passive `candump -t a can0 | grep '18FFE0'`
to confirm FFE0 is not *also* being broadcast. The all-zero response to a
FFE0 request in `known_pgns.txt` suggests there is *some* FFE0 handler on
the RX side, which is not obviously explained by this code.

---

## Why engine hours (PGN 0xFEE5) does not work

Four checks, all negative:

1. **Literal search in decompile:** `grep -i 'fee5\|65253'` in
   `cm848_rom.ghidra.cpp` → **0 hits**. No code constructs the PGN.
2. **TX registration:** FEE5 is absent from the `cm848_enqueueDataRecord`
   list (lines 95932–95951). Nothing schedules it for periodic broadcast.
3. **RX registration:** FEE5 is absent from every `cm848_j1939RegisterPgnHandler`
   call site (greppable list in `cm848_rom.ghidra.cpp` — only 0xCA, 0xCB,
   0xCC, 0xCD, 0xCE, 0xD2, 0xDA, 0xE0, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF0,
   0xF1, 0xF5, 0xF6, 0xF7, and 0x03 are registered). A `18EAFF00#E5FE00`
   request walks the 32-entry table, falls through, and `cm848_sendJ1939NegativeAck`
   fires.
4. **Calibration byte:** `e2m_parameters.csv` lists
   `Jcomm_Engine_Hours_Message_Default_Priority (JCEGTMPZ)` at `0x0112543A`
   — but *no firmware path references that priority byte*, because the
   builder it would configure is not compiled in.

**Conclusion:** the engine-hours broadcast path is not `#ifdef`-disabled at
runtime — it is **absent from the binary**. Changing a calibration byte
cannot make it appear. Dodge did not ship this feature on the 2004.5 CM848D.

CM550 firmware (Insite decompile) has `engineHoursPGN_65252_Builder`, so
the feature exists in the Cummins codebase — it was compiled out for this
OEM variant. Not worth more RE time.

---

## What *does* work: read the values via CLIP Service 0x4A

### 1. Vehicle distance (bench-verified)

Simplest path — J1939-native:

```bash
cansend can0 18EAFF00#E0FE00
# response: 18FEE000#00 00 00 00 12 B1 00 00
#   bytes 0-3: trip distance   (u32 LE × 0.125 km)
#   bytes 4-7: total distance  (u32 LE × 0.125 km)
#   0x0000B112 × 0.125 km = 5666.25 km
```

Already in `known_pgns.txt`. No memory read needed.

### 2. Odometer (miles) — EEPROM direct

```bash
./kuminz-cli can0 --read-addr 01000BD8 2   # high word
./kuminz-cli can0 --read-addr 01000BDA 2   # low word
# combine as u32 BE, multiply by 0.000125 → miles
```

This address is used by `tools/update_odometer.sh` for *writes* against a
live ECU, so we have strong circumstantial evidence it is correct for
S90140.06. Add a `tools/read_odometer.sh` that only does the read.

### 3. ECM run time (key-on seconds) — EEPROM 0x01000030, firmware-traced

**Previous hypothesis:** e2m listed `0x01000400` — bench-verified as wrong
(static value 0x12, never changes).

**Firmware-traced path (2026-04-09):**

`mpc555_watchdogTimerTick` @ 0x7608 runs periodically. Every 40 ticks
(`watchdog_tick_prescaler` reaches 0x28), it increments both:
- `ecm_runtime_accumulator` @ 0x00302012 (lifetime counter)
- `keyon_duration_counter` @ 0x003028a6 (session counter)

`mpc555_keyOnStateMachine` @ 0x184 saves to EEPROM in two scenarios:
1. **Periodic save:** `keyon_duration_counter > 0x2903` (10,499 ticks)
2. **Key-off save:** `mios_key_off_detection` bit 15 set AND
   `eeprom_version_marker.magic == 0x600d`

Save path: `ecm_runtime_accumulator` → `eeprom_runtime_write_staging`
(0x003fee2a) → `mpc555_eepromWriteWords(0x3fee2a, &DAT_01000030, 4)`
→ **EEPROM 0x01000030**.

On boot, `mpc555_watchdogTimerTick_midEntry` @ 0x76B4 reloads
`ecm_runtime_accumulator` from `eeprom_version_marker.config_dword`,
which is read from EEPROM 0x01000034 (line 669).

```bash
# Read EEPROM runtime counter (firmware-traced, needs truck verification)
./kuminz-cli can0 --read-addr 01000030 4

# Read live RAM accumulator (may be in 0x003xxxxx window — needs verification)
./kuminz-cli can0 --read-addr 00302012 4
```

**Scale factor unknown.** The watchdog tick rate determines the time-per-count.
Bench session showed `session_time_counter` at 0x0040B150 runs at 1.5 Hz
with a different prescaler. The watchdog prescaler is 40 ticks, so if the
watchdog runs at 60 Hz, each `ecm_runtime_accumulator` count = 40/60 = 0.667s
(matching the 1.5 Hz observation). **Needs truck verification to confirm.**

### 4. Engine run time (engine-running seconds) — **dead end via known services**

`Engine_Run_Time` (CMEGTR) is listed in `e2m_parameters.csv` at `0x0111BC00`,
but this is **not** a physical address on CM848. Investigation:

- **Not in any Service 0x4A window.** `docs/service_0x4a_protocol.md`
  documents the only accessible ranges as `0x00408000–0x0040FFFF` (RAM)
  and `0x01000000–0x01001FFF` (8 KB EEPROM). `0x0111BC00` is far outside
  both.
- **Not a parameter ID either.** `docs/parameter_by_id_system.md` shows
  the CM848 parameter lookup table has exactly 20 entries, all in the
  `0x0000–0x12A9` range (hardware registers + 8 EEPROM config bytes).
  No entry maps to anything resembling `0x0111BC00`, and the doc explicitly
  notes: *"CLIP services 0x10/0x15 are stubs, not full implementations"*.
  Service 0x41/0x43 (Get/Read By Parameter ID) exist but only cover those
  20 entries.
- **Not a physical RAM address referenced by the firmware.** `grep -i
  '01000400\|0111bc00\|01002700\|01140500'` in `cm848_rom.ghidra.cpp` →
  zero literal hits. None of the e2m engine-hours/run-time addresses
  appear anywhere in the decompiled ROM.
- **`_engine_run_state_timer_counter` @ `0x0040b7da` is not it.** This
  variable is incremented in `mpc555_updateEngineRunState` @ 0x45478 (line
  42324), but it resets to 0 every time `engine_start_counter.run_state`
  hits 0 (line 42309). It is a transition-state settling timer, not a
  lifetime accumulator.

**Interpretation:** the e2m "address" `0x0111BC00` is a database key in a
logical address space specific to the Calterm/Insite tool — possibly
resolved by a service that CM848 does not implement, or one only reachable
through a session this ECU does not export. The CM550 might honor this
style of address (CM550 has 723 parameter entries vs CM848's 20), but on
CM848 S90140.06 it is unreachable.

**Paths left to explore** (all substantial follow-up RE tasks, not quick wins):

- Find the physical RAM/EEPROM mirror of the engine-running-time counter
  by instrumenting the bench ECU: read `0x00408000–0x0040FFFF` and
  `0x01000000–0x01001FFF` before/after 60 s of engine run time, diff, and
  look for a u32/u16 counter that advanced by ~300 (0.2 s × 5 Hz × 60 s)
  or ~6000 (0.01 s scale). The "update odometer" tool already inherits an
  address `0x01001A84` which is inside the window even though it's past
  the 4 KB boundary originally documented — the same technique may find
  hours.
- Check whether the CM550 firmware (J90350.00) has a mapped lifetime-hours
  counter at a known RAM address, then use the cross-firmware fingerprint
  (`firmware/cross_firmware_matches.csv`) to port it to CM848.
- Passive-listen for the hours counter leaking into any J1939 proprietary
  broadcast we haven't scanned yet.

### 5. Multiplex Engine Run Timer — same dead end as #4

`Multiplex_Engine_Run_Timer (JCMXRNTR) @ 0x0112F722` is in the same
parameter-space address range as `Engine_Run_Time`. Not reachable via any
CM848 service we know about.

---

## Verification

Run on the bench with engine at key-on (and key-on+running) and
`can0` up at 250 kbps. Record results at the bottom of this document.

```bash
# 0. Sanity: existing known-good read
./kuminz-cli can0 --read-addr 40B7BA 2      # RPM, × 0.125

# 1. J1939 vehicle distance — already known to work
cansend can0 18EAFF00#E0FE00 && candump -n 1 can0,18FEE000:1FFFFFFF

# 2. Odometer — verify against known tool value
./kuminz-cli can0 --read-addr 01000BD8 2
./kuminz-cli can0 --read-addr 01000BDA 2

# 3. ECM run time — UNVERIFIED: expect monotonically increasing
./kuminz-cli can0 --read-addr 01000400 2
./kuminz-cli can0 --read-addr 01000402 2
sleep 30
./kuminz-cli can0 --read-addr 01000400 2
./kuminz-cli can0 --read-addr 01000402 2
# ΔLo should be ≈ 150 counts (30 s / 0.2 s-per-count)

# 4. FEE5 negative confirmation — expect NACK or silence
cansend can0 18EAFF00#E5FE00
candump -T 2000 can0      # nothing on 18FEE500, expect 18E8xxxx NACK

# 5. FFE0 passive broadcast check (the tag-vs-PGN mystery)
timeout 10 candump -t a can0 | grep -iE '18ffe0' || echo "no FFE0 broadcast"
```

---

## Verification Results

### Bench Session (2026-04-08)

Tested using OCT Teensy MicroMod bench firmware on CAN2 (FlexCAN_T4).
ECU was HP Tuners-flashed — all EEPROM runtime counters were reset by the
flash. Dash odometer reads 293,199 miles (stored in instrument cluster, not
ECU). Full test output saved in `/tmp/bench_output.txt`, `/tmp/eeprom_scan.txt`,
`/tmp/ram_scan.txt`, `/tmp/hours_id.txt`, `/tmp/post_shutdown.txt`.

### Confirmed working

| Address | Value | Notes |
|---------|-------|-------|
| **J1939 PGN FEE0** | trip=0 km, total=355.62 km | Accumulated since HP Tuners flash, not lifetime |
| **EEPROM 0x01000BD8** (odometer) | raw=0x03736429 = 7,236.74 miles | Accumulated since flash; dash shows 293,199 mi |
| **EEPROM 0x01001A84** (Rolls_Odometer) | 0x0280 (640) | Working |
| **RAM 0x0040B7BA** (RPM) | 750 RPM (engine running), 0 (key on only) | Confirmed |

### Service 0x4A window is WIDER than documented

The documented window was `0x00408000–0x0040FFFF` (RAM) + `0x01000000–0x01001FFF`
(EEPROM). Bench probing confirmed **0x003Fxxxx is also readable**:

| Address | Value | Variable |
|---------|-------|----------|
| 0x003FDD6C | 0x000C7E46 (818,758) | `total_vehicle_distance_raw` |
| 0x003FDD70 | 0x00000000 | `trip_vehicle_distance_raw` |
| 0x003FDDA0 | 0x00000000 | `eeprom_save_cycle_counter` |
| 0x003FDDA4 | 0x00000000 | `eeprom_scatter_source_table` |
| 0x003FA000 | 0x0000 | `key_on_flag` area |
| 0x003FEE12 | 0x0000 | EEPROM mirror area |

### EEPROM is write-on-shutdown only

Full 8KB EEPROM dump (0x01000000–0x01001FFF) before/after 60 seconds with
engine running: **zero bytes changed**. The ECU accumulates counters in RAM
and only flushes to EEPROM on key-off shutdown. The scatter-gather RAM
write pointer at 0x0040BDF6 WAS moving (0x722→0x730 across test cycles),
confirming the save system is active in RAM — but the SPI flush to physical
EEPROM doesn't happen during operation.

### ECM_Run_Time @ 0x01000400 — NOT the hours counter

Reads raw=0x12 (18) = 3.6 seconds. **Never changes** — not while running,
not after key cycle. This is a static EEPROM calibration value at this
offset on S90140.06 firmware, not a runtime counter. The e2m database
address was wrong for this firmware version.

### EEPROM 0x10000D6 / 0x10000F4 — NOT hours counters either

Initially looked promising (0x1F9C40 = 2,071,616 and 0x1FC1F1 = 2,081,265,
which at various scales could represent ~115-384 hours). But:
- Did not change during 3 minutes of engine-running operation
- **Did not change after key-off/key-on cycle**
- These are static calibration or configuration values, not runtime counters

### Live session-time counter FOUND in RAM

**RAM 0x0040B150** (and copies at 0x0040B2C2, 0x0040BA44) contains a live
session-time counter that:
- Starts near 0 at key-on
- Increments at **1.5 Hz** (one count every 0.667 seconds)
- Was at 9545 counts after ~106 minutes of key-on time (9545 × 0.667s = 6363s = 106 min ✓)
- Resets to 0 on each key cycle

Rate confirmed by delta test: 177-182 counts per 120 seconds = 1.48-1.52/s,
centered on exactly 1.5 Hz.

**Unsolved: where this session counter gets persisted to EEPROM on shutdown.**
The EEPROM delta test after key-off showed zero changes at the two candidate
addresses. The lifetime hours accumulator location in EEPROM is still unknown.

### What's still needed

The ECU was HP Tuners-flashed, which zeroed all EEPROM runtime data. The
shutdown save path has been traced (see section 3 above), identifying
EEPROM 0x01000030 as the target. Remaining:

1. **Truck verification of EEPROM 0x01000030:** read before/after key cycle
   to confirm accumulation. See [Truck Testing Plan](#truck-testing-plan).
2. **Scale factor determination:** measure time-per-count to convert raw
   counter to hours/seconds.
3. **HP Tuners EEPROM diff (optional):** dump EEPROM → flash HP Tuners → dump
   again → diff. Reveals all addresses that get zeroed.

## Follow-ups

- [ ] Add `tools/read_odometer.sh` (mirror of `update_odometer.sh` without writes).
- [ ] **Truck verification of EEPROM 0x01000030** — read this address at key-on,
      drive/idle for a period, key-off, key-on, read again. Confirm it accumulates.
      See [Truck Testing Plan](#truck-testing-plan) below.
- [ ] **HP Tuners EEPROM diff:** dump EEPROM → flash HP Tuners → dump again → diff.
      This will reveal all runtime counter EEPROM addresses at once.
- [ ] Update `docs/service_0x4a_protocol.md` to document the wider Service
      0x4A window (0x003Fxxxx is readable, not just 0x00408000+).
- [X] ~~Trace the ECU shutdown path~~ — found `mpc555_keyOnStateMachine` @ 0x184
      saves `ecm_runtime_accumulator` to EEPROM 0x01000030 (2026-04-09).
- [X] ~~Bench-verify `ECM_Run_Time` @ `0x01000400`~~ — confirmed NOT the
      hours counter (static value, never changes).
- [X] ~~Implement `--resolve-param` / Service 0x15/0x16~~ — deleted, CM848
      has only 20 parameter IDs, services are stubs.

## Truck Testing Plan

**Context:** The ECU is in a running 2004.5 Dodge 5.9L, not on a bench.
CAN adapter connects via OBD-II port. All reads use `kuminz-cli` over
Service 0x4A. The ECU was HP Tuners-flashed, which zeroed all EEPROM
runtime data, so current values will be small.

### Prerequisites

```bash
sudo ip link set can0 type can bitrate 250000
sudo ip link set can0 up
```

### Test 1: Baseline Read (key-on, engine off)

Purpose: Confirm EEPROM 0x01000030 is readable and capture current value.

```bash
# 1a. Sanity check — RPM should be 0 (engine off)
./kuminz-cli can0 --read-addr 40B7BA 2

# 1b. EEPROM runtime counter (firmware-traced target)
./kuminz-cli can0 --read-addr 01000030 2
./kuminz-cli can0 --read-addr 01000032 2
# Combine as u32 BE. Record value as BASELINE_EEPROM.

# 1c. RAM runtime accumulator (may or may not be in 0x4A window)
./kuminz-cli can0 --read-addr 00302012 2
./kuminz-cli can0 --read-addr 00302014 2
# If this returns data, record as BASELINE_RAM. If NACK, address
# is outside the Service 0x4A window — skip RAM reads in later tests.

# 1d. Session time counter (known-good, bench-verified)
./kuminz-cli can0 --read-addr 0040B150 2
# Should be small (just powered on). Record as BASELINE_SESSION.

# 1e. Known-good odometer for reference
./kuminz-cli can0 --read-addr 01000BD8 2
./kuminz-cli can0 --read-addr 01000BDA 2
```

### Test 2: Live Accumulation (engine running, 5 minutes)

Purpose: Watch the RAM counters tick up while the engine runs.

```bash
# Start engine, wait for idle to stabilize (~10 seconds)

# 2a. Confirm engine is running
./kuminz-cli can0 --read-addr 40B7BA 2
# Expect ~750 RPM (raw ÷ 8 × 0.125)

# 2b. Read session counter
./kuminz-cli can0 --read-addr 0040B150 2
# Record value. Wait 120 seconds...

# 2c. Re-read session counter
./kuminz-cli can0 --read-addr 0040B150 2
# Expect delta ≈ 180 counts (120s × 1.5 Hz). Confirms counter is live.

# 2d. If RAM 0x302012 was readable in Test 1:
./kuminz-cli can0 --read-addr 00302012 2
./kuminz-cli can0 --read-addr 00302014 2
# Record value. If it changed from BASELINE_RAM, the accumulator
# is live and ticking.
```

### Test 3: Key-Off → Key-On EEPROM Flush (THE KEY TEST)

Purpose: Confirm `mpc555_keyOnStateMachine` flushes the runtime counter
to EEPROM 0x01000030 on shutdown.

```bash
# 3a. With engine running, note approximate time since key-on.
#     This tells us expected delta in EEPROM counter.

# 3b. Turn ignition OFF. Wait 30 seconds for full ECU shutdown.
#     (ECU needs time to complete SPI EEPROM flush before power dies.)

# 3c. Turn ignition ON (don't start engine).
#     Wait 3 seconds for ECU boot.

# 3d. Read EEPROM runtime counter again
./kuminz-cli can0 --read-addr 01000030 2
./kuminz-cli can0 --read-addr 01000032 2
# Combine as u32 BE. Record as POST_CYCLE_EEPROM.

# EXPECTED: POST_CYCLE_EEPROM > BASELINE_EEPROM
# The delta should correspond to the key-on duration.
# If watchdog runs at 60 Hz with 40x prescaler → 1 count per 0.667s.
# 5 min key-on ≈ 300s ÷ 0.667 ≈ 450 counts delta.
```

### Test 4: Scale Factor Calibration

Purpose: Determine the exact time-per-count for `ecm_runtime_accumulator`.

```bash
# 4a. At key-on, immediately read EEPROM and note wall-clock time
./kuminz-cli can0 --read-addr 01000030 2
./kuminz-cli can0 --read-addr 01000032 2
# Record as T0_EEPROM, T0_CLOCK

# 4b. Leave key on (engine can be on or off) for exactly 30 minutes.

# 4c. Key off, wait 30 seconds, key on, read again
./kuminz-cli can0 --read-addr 01000030 2
./kuminz-cli can0 --read-addr 01000032 2
# Record as T1_EEPROM, T1_CLOCK

# CALCULATE:
# delta_counts = T1_EEPROM - T0_EEPROM
# delta_seconds = T1_CLOCK - T0_CLOCK (should be ~1830s including shutdown)
# scale = delta_seconds / delta_counts
# Expected: ~0.667 s/count (matching 1.5 Hz bench observation)
# Or: ~0.2 s/count (matching e2m database claim for ECM_Run_Time)
```

### Test 5: Keyon-Duration Threshold Check (optional)

Purpose: Verify the 0x2903 (10,499) threshold on `keyon_duration_counter`.
At 1.5 Hz, that's ~7000 seconds = ~117 minutes. This means a key-on session
shorter than ~2 hours may NOT trigger a periodic save — only the key-off
save would fire.

```bash
# Short session test: key on for 5 minutes, key off, key on, read EEPROM.
# If delta is present → key-off save path works (most likely).
# If delta is zero → ECU didn't have time to flush before power died.
#   This would mean the truck's keep-alive power duration matters.
```

### Recording Results

Add results to the [Bench Results](#bench-results-2026-04-08) section
(rename to "Verification Results"). Key values to record:

| Test | Address | Raw Value | Computed | Notes |
|------|---------|-----------|----------|-------|
| 1b | 0x01000030 | | | EEPROM baseline |
| 1c | 0x00302012 | | | RAM baseline (or NACK) |
| 1d | 0x0040B150 | | | Session counter baseline |
| 3d | 0x01000030 | | | Post key-cycle EEPROM |
| 4 | | | | Scale factor s/count |

### Failure Modes

- **EEPROM 0x01000030 returns NACK:** Address outside 0x4A window at that
  offset. Try reading the surrounding area (0x01000020–0x01000040).
- **EEPROM value doesn't change after key cycle:** The key-off save needs
  sufficient keep-alive power. Dodge trucks typically hold ECU power for
  ~10-30 seconds after key-off, but if the battery is weak or there's a
  relay issue, the ECU may lose power before the SPI flush completes.
- **RAM 0x302012 returns NACK:** This address is in MPC555 module space,
  which may not be in the Service 0x4A accessible window. Not a problem —
  the EEPROM address is the important one.
- **Delta doesn't match expected scale:** The watchdog tick rate assumption
  (60 Hz) may be wrong. Calculate the actual scale from measured data.

## Cross-references

- `firmware/CM848_S90140.06_analysis/tools/update_odometer.sh`
- `firmware/CM848_S90140.06_analysis/known_pgns.txt`
- `firmware/CM848_S90140.06_analysis/docs/service_0x4a_protocol.md`
- `firmware/CM848_S90140.06_analysis/output/e2m_parameters.csv`
- `firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp` — see
  `cm848_initJ1939ProtocolHandlers` @ 0x232B4, TX enqueue list inside it,
  and `cm848_initPgn65248VehicleDistanceHandler` @ 0x26C6C.
- `work/docs/clip-protocol-spec.md` — CLIP service reference.
