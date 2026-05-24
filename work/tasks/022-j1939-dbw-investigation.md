# Task 022 — CM848D J1939 Drive-By-Wire Investigation

## Goal
Determine if the CM848D's built-in J1939 governor speed control (TSC1 / PGN 0) can be
enabled via calibration, and if so, build a working proof-of-concept in oct that controls
engine speed via J1939 from the Cummins Bus.

## Problem Statement
The CM848D firmware contains a fully-implemented J1939 governor control subsystem that
is gated behind `j1939_governor_config_flags & 0x40`. Dodge didn't enable it — they use
an external cruise module that manipulates the APP signal instead. If the gate can be
opened (via cal change, CLIP write, or EEPROM write), the ECU would accept standard
J1939 TSC1 speed/torque commands from any J1939 device on the bus.

## What We Know (2026-05-24)

### Infrastructure confirmed in firmware
- `j1939_tsc1_active_flag` — set/cleared by cruise state machine (ROM line 39655/39659)
- `j1939_tsc1_override_enable` — set to 1 in `cm848_processFuelDemandCallback` when
  auth succeeds and fuel demand command 0x13 is received (ROM line 40374)
- `j1939_governor_speed_demand` — calculated from incoming J1939 data, clamped by
  `governor_speed_request_maximum` (ROM line 21582)
- `j1939_tsc1_status_shadow`, `j1939_tsc1_mode_shadow` — full TSC1 state shadows
- PGN 65265 (CCVS1) — ECU *transmits* cruise/override status back on J1939 bus
- PGN 65261 (Cruise Control Setup) — ECU transmits governor capability (max/min speed);
  returns 0xFF when `j1939_governor_config_flags & 0x40` is clear
- PGN 65264 (PTO) — registered and handled (`cm848_j1939HandlePgn65264Pto`)
- `j1939_msgSlotE_governorAuth_check` — handles PDU1 messages with PGN < 101 (TSC1 = PGN 0)
  Runs challenge-response auth before setting `governor_fuel_mode_status_bit = 1`

### The two gates
1. **Config gate** — `j1939_governor_config_flags & 0x40` at RAM address `0x003fd5a2`
   - Never written at runtime — loaded at startup from calibration ROM
   - If 0: CCVS1 broadcasts 0xFF (not supported), cruise engage/disengage blocked
   - If 1: full J1939 governor mode available
2. **Auth gate** — `governor_fuel_mode_status_bit` set by `j1939_msgSlotE_governorAuth_check`
   - Per-session, requires the CLIP security handshake (already working in oct)
   - The `cm848InverseCipher` + timer response is exactly what oct's `sendDTs()` does

### Auth protocol (SOLVED in oct `cummins-bus.cpp`)
1. CLIP read: `0x0040A64C` (4-byte rolling timer)
2. Build target: `[0x41,0x42,0x43,0x44,0x45,0x46, T0,T1,T2, 0x00]` = "ABCDEF" + timer low 3 bytes
3. `cm848InverseCipher(target, payload)` — inverts ECU's bit-scatter/XOR transform
4. Send via J1939 TP (service byte 0x16), 2 DT frames
5. ECU accepts → `governor_fuel_mode_status_bit = 1`
6. oct enters WS_ARMED, sends keep-alive 0x16 every 1 second

### Other relevant flags
- `j1939_governor_config_flags & 0x80` — gates max speed setpoint in CCVS1 transmit
- `j1939_governor_config_flags & 0x100` — alternate protection ramp mode; checked with
  `governor_j1939_bypass_flag`
- `j1939_governor_config_flags & 0x10` — gates PTO governor data in PGN 65264 transmit
- `j1939_governor_feature_byte` — secondary feature flag, checked with bits 0x01, 0x02
- `ram0x003fee00` — additional enable condition checked alongside `& 0x40`
- `governor_j1939_bypass_flag` — when set, bypasses 0x100 mode

## Investigation Plan

### Phase 1 — Read the live value (can do now with oct)
- [ ] Add CLIP read of `0x003fd5a2` (2 bytes) to oct's discovery log or serial command
- [ ] Read `j1939_governor_config_flags` on live truck to see current value
- [ ] Also read `ram0x003fee00` (find its address in global_variables.csv)
- [ ] Read `j1939_governor_feature_byte` address
- Goal: confirm which bits are currently set; if 0x40 is already set we just need auth

### Phase 2 — Determine if writable via CLIP
- [ ] Find the CLIP memory WRITE service number (likely 0x3B or similar)
- [ ] Determine if 0x003fd5a2 is writable at runtime or is ROM-only
- [ ] If writable: add a CLIP write to oct after auth to set `j1939_governor_config_flags |= 0x40`
- [ ] If ROM-only: identify the corresponding e2m calibration block / Calterm parameter

### Phase 3 — Trace the complete TSC1 receive path
- [ ] Find where incoming J1939 TSC1 (PGN 0, PDU1) arrives in the message dispatch table
- [ ] Confirm j1939_msgSlotE = TSC1 handler path
- [ ] Trace how `j1939_governor_speed_demand` is populated from the TSC1 SPN 898 payload
- [ ] Identify what conditions allow it to reach the fuel governor output

### Phase 4 — Safety interlocks
- [ ] Document all inhibit conditions in `governor_cruise_fuelCorrection_inhibitCheck`
- [ ] Document disengage conditions in `governor_cruise_disengage_check`
- [ ] Identify VSS/brake/clutch interlock inputs
- [ ] Understand what `j1939_receive_status_flags & 0x2000` means (cruise speed target min cal)

### Phase 5 — Proof of concept in oct
- [ ] After Phase 1-3: implement TSC1 transmit in oct (J1939 Bus, not Cummins Bus)
- [ ] Send TSC1 with Override Control Mode = 01 (speed control), Priority = 11 (low)
- [ ] SPN 898: requested speed in 0.125 rpm/bit units
- [ ] SPN 518: requested torque = 0x7D (125% = "don't limit torque")
- [ ] Verify ECU responds with matching speed via CLIP read of engine RPM

## Key Addresses
| Symbol | Address | Type | Notes |
|--------|---------|------|-------|
| `j1939_governor_config_flags` | `0x003fd5a2` | word | Config gate — read first; likely ROM cal |
| `j1939_tsc1_active_flag` (cal) | `0x003fd530` | byte | ROM-side copy |
| `j1939_tsc1_active_flag` (ram) | `0x0040b558` | word | Runtime copy — written at line 39655/39659 |
| `j1939_tsc1_override_enable` | `0x0040b51c` | byte | Set by fuel demand cmd 0x13 |
| `j1939_governor_speed_demand` | `0x003faa70` | word | Target RPM from J1939 |
| `governor_fuel_mode_status_bit` | `0x0040b512` | word | Set by auth handshake |
| `cruise_speed_command` | `0x0040a26a` | word | Active cruise setpoint |
| `j1939_governor_feature_byte` | `0x003fd902` | byte | Secondary feature flags (bits 0x01, 0x02) |
| `ram0x003fee00` | `0x003fee00` | byte | Runtime engage flag — SET to 1 by engage_check |
| `CLIP_ADDR_TIMER` | `0x0040A64C` | dword | Auth rolling timer |

**Critical insight on `ram0x003fee00`**: Despite appearing as `sensor_channel_cmd_address+3`
in global_variables.csv (Ghidra struct layout artifact), this IS a live runtime flag. It is:
- Set to 1 at bank2_functions.cpp:10811 when `governor_cruise_engage_check()` passes
- Cleared at cm848_rom.ghidra.cpp:17196, 17249 on disengage
- Checked alongside `j1939_governor_config_flags & 0x40` as a dual gate
Since it lives in RAM it may be directly writable via CLIP write.

## TSC1 Message Format (PGN 0, 8 bytes)
| Byte | Bits | SPN | Value for speed control |
|------|------|-----|------------------------|
| 1 | 1-2 | 695 | `01` = speed control mode |
| 1 | 3-4 | 696 | `01` = stability (driveline disengaged) |
| 1 | 5-6 | 897 | `11` = low priority |
| 2-3 | all | 898 | RPM × 8 (0.125 rpm/bit), little-endian |
| 4 | all | 518 | `FA` = 125 = max torque (no limit) |
| 5 | 1-3 | 3349 | `101` = 50ms rate |
| 5 | 4-8 | 3350 | `00001` = P2 = cruise control purpose |
| 6 | 1-4 | 4191 | `1111` = high-res torque N/A |
| 8 | 1-4 | 4206 | rolling counter 0-7 |
| 8 | 5-8 | 4207 | checksum |

CAN ID for TSC1 → ECU: `0x0C000003` (priority 3, PGN 0, dest=ECU addr 0x00, src=0x03)

## Investigation Log

### 2026-05-24 — Initial discovery
- Grepped decompiled firmware; confirmed j1939_tsc1_* variables and TSC1 infrastructure
- Found `j1939_governor_config_flags & 0x40` as the primary config gate
- Oct already has working auth via `cm848InverseCipher` + timer CLIP read
- PGN 65261/65265 handlers confirmed; ECU transmits capability status
- **Next step**: read `0x003fd5a2` live on truck via oct serial command
