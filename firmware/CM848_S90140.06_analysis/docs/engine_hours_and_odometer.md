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
| **ECM run time (key-on seconds)**      | *none*                     | Svc 0x4A at EEPROM `0x01000400` (u32 × 0.2 s) | **In Svc 0x4A window — unverified, needs bench read** |
| **Engine run time (engine-running s)** | *none*                     | `0x0111BC00` is **not a physical address** — unreachable via known services | **Blocked** (see dead end below) |
| **PGN 0xFEE5 (Engine Hours/Revs)**     | **Does not exist in firmware** | —                                 | Ruled out        |

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

### 3. ECM run time (key-on seconds) — EEPROM direct, **unverified**

```bash
./kuminz-cli can0 --read-addr 01000400 2
./kuminz-cli can0 --read-addr 01000402 2
# u32 BE × 0.2 s → seconds
```

Source: `e2m_parameters.csv` (ECM_Run_Time @ 0x01000400, u32, 0.2 SEC).
Not referenced as a literal in `cm848_rom.ghidra.cpp`, so treat the address
as a hypothesis until bench-verified. Backup copy at `0x01002700`.

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

Fill in results here once run:

```
# ECM_Run_Time @ 0x01000400 raw: __________  decoded: ________ hours
# Odometer     @ 0x01000BD8 raw: __________  decoded: ________ miles
# FEE5 request response:          __________
# FFE0 passive capture:           __________
```

---

## Follow-ups (do not block the writeup)

- [ ] Add `tools/read_odometer.sh` (mirror of `update_odometer.sh` without writes).
- [ ] **Do not** implement `--resolve-param` / Service 0x15 / Service 0x16
      in `kuminz-cli`. Originally planned as Thread 5; investigation in
      `docs/parameter_by_id_system.md` shows CM848's parameter table has
      only 20 entries (none of which are engine hours), and the spec says
      CLIP 0x10/0x15 are stubs on this ECU. Deleted from the plan.
- [ ] Bench-verify `ECM_Run_Time` @ `0x01000400` increments at ~5 counts/s
      (0.2 s scale) with key on. This is now the *only* known near-term
      hours path.
- [ ] **RE task:** diff RAM `0x00408000-0x0040FFFF` and EEPROM
      `0x01000000-0x01001FFF` before/after 60 s engine run time to locate
      the lifetime engine-running-hours counter. This is the only way to
      recover `Engine_Run_Time` (CMEGTR) on CM848 — the e2m address
      `0x0111BC00` is not a physical address.
- [ ] Extend `scripts/pgn_scan.sh` (or create one if absent) to sweep
      `0xFF00-0xFFFF` and log any responders beyond FFE0.

## Cross-references

- `firmware/CM848_S90140.06_analysis/tools/update_odometer.sh`
- `firmware/CM848_S90140.06_analysis/known_pgns.txt`
- `firmware/CM848_S90140.06_analysis/docs/service_0x4a_protocol.md`
- `firmware/CM848_S90140.06_analysis/output/e2m_parameters.csv`
- `firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp` — see
  `cm848_initJ1939ProtocolHandlers` @ 0x232B4, TX enqueue list inside it,
  and `cm848_initPgn65248VehicleDistanceHandler` @ 0x26C6C.
- `work/docs/clip-protocol-spec.md` — CLIP service reference.
