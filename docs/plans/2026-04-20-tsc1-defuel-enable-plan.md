# Plan: CM848D J1939 TSC1 Defuel Enable

## Context

The CM848D ECU has a dormant J1939 TSC1 (Torque/Speed Control, PGN 0xF002) handler that is blocked
by two gates: an EEPROM vocation config byte (must be 4 or 5 for Allison driveline) and a source
address filter. The handler, arbitration path, and fuel delivery integration are all present in
firmware — just gated off. The goal is to safely enable TSC1 defuel response so an Allison TCM can
command fuel cuts during gear shifts.

**Safety rule #1: Never write EEPROM without a pre-dump and checksum verification.**
**Safety rule #2: Never proceed to a later phase without fully verifying the prior phase.**
**Safety rule #3: This plan is the artifact of this session. No firmware/EEPROM/code changes
are made until this plan is reviewed, approved, and merged to main.**

## The Naming Hook (Runs Pre and Post Every Step)

Renaming is not a phase — it is a discipline applied continuously. Before starting any step,
commit what we already know. After completing any step, capture everything learned. Never miss
an opportunity to make the code self-documenting.

### Hook procedure (pre and post every step):
1. Review what was just learned or what is already known
2. Update `output/function_renames.csv`, `output/global_variables.csv`, `output/enums.csv`
   with any new names, corrections, or removals
3. Run `./analyze.sh import && ./analyze.sh export`
4. Read the regenerated decompiled output for the touched functions — does it read clearly?
   If a name is wrong or misleading, fix it immediately (course correct, don't accumulate debt)
5. Commit the CSV changes with a descriptive message before proceeding

### Names already known from planning (apply in the very first pre-hook, before Step 1):

**function_renames.csv additions:**
```
<find addr of lines 18927-19088 arbitration fn>,cm848_arbitrateFuelLimitSources
```

**global_variables.csv additions:**
```
0x0005c386,tsc1_torque_mode_timer_init
0x0005c388,tsc1_torque_active_timer_init
0x0005c38a,tsc1_message_timeout_init
0x0005c38c,tsc1_torque_mode_timer_alt
0x0005c38e,tsc1_speed_override_timer_init
0x0005c390,tsc1_torque_limit_timer_init
0x0005c3a0,tsc1_mode_activation_timeout_init
0x0005c3a2,tsc1_speed_command_timeout_init
0x0005c3a4,tsc1_initial_speed_cmd_timeout
0x0005c3a6,tsc1_override_timeout_init
0x0005a470,tsc1_source_address_filter
0x0005c39a,tsc1_torque_limit_calibration_value
0x003fd816,pressure_ramp_mode_selector
0x003fefea,pressure_ramp_threshold
0x0040b648,proprietary_torque_limit_ptr
```

**enums.csv additions:**
```
FUEL_LIMIT_SOURCE,0,fuel_limit_source_none
FUEL_LIMIT_SOURCE,2,fuel_limit_source_pressure_ramp
FUEL_LIMIT_SOURCE,4,fuel_limit_source_pressure_ramp_flag
FUEL_LIMIT_SOURCE,5,fuel_limit_source_protection_min
FUEL_LIMIT_SOURCE,6,fuel_limit_source_protection_current
FUEL_LIMIT_SOURCE,7,fuel_limit_source_torque_request_base
FUEL_LIMIT_SOURCE,8,fuel_limit_source_tsc1_torque_limit
FUEL_LIMIT_SOURCE,9,fuel_limit_source_tsc1_mode3_defuel
FUEL_LIMIT_SOURCE,10,fuel_limit_source_default_torque
FUEL_LIMIT_SOURCE,11,fuel_limit_source_fuel_nominal
FUEL_LIMIT_SOURCE,13,fuel_limit_source_fuel_override
FUEL_LIMIT_SOURCE,14,fuel_limit_source_fuel_minimum
FUEL_LIMIT_SOURCE,15,fuel_limit_source_torque_output
```

---

## Step 1: Read Live State (Observe Only)

**Goal**: Understand the current runtime state before any writes. Zero risk.

**Pre-hook**: Apply all names listed above. Verify decompiled output reads clearly for
`cm848_j1939ProcessTorqueSpeedControl` and `cm848_arbitrateFuelLimitSources`.

```bash
./kuminz-cli can0 --read-addr 0005a470 1   # tsc1_source_address_filter (ROM)
./kuminz-cli can0 --read-addr 0040ae10 2   # disable_control flag
./kuminz-cli can0 --read-addr 0040ae08 2   # tsc1_control_word_stored.mode
./kuminz-cli can0 --read-addr 0040a2f4 2   # limit_source_priority.fuel_minimum
./kuminz-cli can0 --read-addr 0040a2f6 1   # limit_source_priority.source_active
./kuminz-cli can0 --read-addr 0040a57a 2   # fuel_demand_calculated (baseline)
./kuminz-cli can0 --read-addr 003fdda6 1   # vocation byte in RAM (confirm 0x00)
```

**Post-hook**: Record all observed values in `docs/plans/tsc1-defuel-implementation.md`.
Name any previously unnamed variables revealed by the live values (e.g., if `source_active`
shows an unexpected value, investigate and name that source).

---

## Step 2: RAM Patch Testing (Option 2) — No EEPROM Writes

**Goal**: Prove TSC1 defuel works end-to-end. Fully reversible on key-off.
Engine running, transmission in neutral/park.

**Pre-hook**: Confirm all Step 1 readings are documented. Re-read the decompiled
`cm848_j1939ProcessTorqueSpeedControl` and `cm848_arbitrateFuelLimitSources` — do they
read as clearly as expected after the pre-Step-1 naming pass?

### 2a. Apply RAM patches
```bash
# Clear disable_control so TSC1 handler is no longer blocked
./kuminz-cli can0 --write-addr 0040ae10 01 00

# If tsc1_source_address_filter was not 0xFF, set to wildcard
./kuminz-cli can0 --write-addr 0005a470 01 ff   # only if needed
```

### 2b. Send TSC1 Mode 3 from Teensy SLCAN bridge
Transmit J1939 PGN 0xF002 (TSC1):
- Byte[0]: mode = 3 (defuel/coast-brake)
- Bytes[1-2]: requested torque = 0x0000 (full cutoff)
- Source address: 0x03 (Allison TCM default)

### 2c. Verify defuel
```bash
./kuminz-cli can0 --read-addr 0040a57a 2   # fuel_demand_calculated — expect near 0
./kuminz-cli can0 --read-addr 0040a2f6 1   # source_active — expect 0x09
./kuminz-cli can0 --read-addr 0040a2f4 2   # fuel_minimum — expect 0x0000
```

### 2d. Verify release
Stop TSC1 transmission. Confirm fuel demand returns to normal within ~300ms.

**Post-hook**: Document every new thing learned (actual timer values, exact arbitration
behavior, edge cases). Were any variable names misleading once we saw them in action?
Correct them. Did we discover any new unnamed functions in the call path? Name them.

### Gate: Step 3 does not begin until defuel is confirmed working and all RAM-phase
learnings are committed to CSVs.

---

## Step 3: Checksum Reverse Engineering

**Goal**: Confirm it is safe to write EEPROM offset `0x0DA6` (inside region `0x0D00–0x0DC4`
which HP Tuners zeros). Must know if checksums cover this region before any EEPROM write.

**Pre-hook**: Re-read the EEPROM loading function `mpc555_loadEepromCalibration()` in the
decompiled output. Are the scatter-load mechanism and checksum validation fully named and
readable? If not, fix it now.

### 3a. Test write to a sacrificial byte in the region
Choose a byte inside `0x0D00–0x0DC4` that is known-zero across all three dumps and not
the vocation byte. Write a known value, key-cycle, dump EEPROM, diff.

```bash
./kuminz-cli can0 --dump-eeprom eeprom_dumps/eeprom_checksum_test_before.bin
./kuminz-cli can0 --write-addr 010009c0 01 AA   # example sacrificial byte
# key off, key on
./kuminz-cli can0 --dump-eeprom eeprom_dumps/eeprom_checksum_test_after.bin
# diff the two dumps — which checksum fields changed?
```

### 3b. Map checksum coverage
Candidate checksum fields:
- `0x01000E6C` / `0x01000E6E` — changed in HP Tuners diff
- `0x01000032` — calibration header checksum
- `0x01000B48` — mid-EEPROM checksum

If the checksum field does NOT change after modifying the region, `0x0DA6` is safe to write
without any checksum update. If it does change, the algorithm must be reverse-engineered
(similar to the calterm-crc project) before proceeding to Step 4.

**Post-hook**: Document checksum coverage map in `eeprom_dumps/README.md`. Name any checksum
validation functions discovered in the decompiled output.

### Gate: Step 4 does not begin until checksum behavior is confirmed and documented.

---

## Step 4: EEPROM Vocation Write (Option 1) via HP Tuners UDP

**Goal**: Make TSC1 enable persistent across key cycles and HP Tuners flashes.

**Pre-hook**: Re-read all functions in the TSC1 path. The code should read like a book at
this point. If anything still reads as opaque, fix it before making permanent changes.

### 4a. Pre-write dump
```bash
./kuminz-cli can0 --dump-eeprom eeprom_dumps/eeprom_before_vocation_write.bin
```

### 4b. HP Tuners user-defined parameter
Define a UDP at EEPROM address `0x0DA6`:
- Data type: u8, value: `0x04`, label: "J1939 Vocation Mode (4=Allison TCM)"

Flash tune. HP Tuners zeroes the region first, then writes the UDP — net result: `0x04`.

### 4c. Post-write verification
```bash
./kuminz-cli can0 --dump-eeprom eeprom_dumps/eeprom_after_vocation_write.bin
./kuminz-cli can0 --read-addr 01000da6 1   # EEPROM — expect 0x04
./kuminz-cli can0 --read-addr 003fdda6 1   # RAM scatter-loaded — expect 0x04
./kuminz-cli can0 --read-addr 0040ae10 2   # disable_control — expect 0x00 (no RAM patch needed)
```

### 4d. Full end-to-end re-test, zero RAM patches
Repeat Step 2b–2d with NO RAM writes. TSC1 defuel must work based solely on EEPROM.

### 4e. Flash durability test
Reflash with HP Tuners (same tune). Confirm vocation byte is still `0x04` — UDP survives
re-flash.

**Post-hook**: Final naming pass on everything touched. The entire TSC1 path — from CAN RX
through arbitration through fuel delivery — should read as clearly as if it were original
source code with comments.

---

## Deliverable: Implementation Notes Document

Each step produces entries in `docs/plans/tsc1-defuel-implementation.md`:
- Observed live values from Step 1
- RAM patch sequence and exact verified behavior from Step 2
- Checksum map from Step 3
- HP Tuners UDP configuration and before/after diff from Step 4

---

## Key Addresses Quick Reference

| Address | Variable | Notes |
|---|---|---|
| EEPROM `0x0DA6` | vocation_config_byte | Target: `0x04` (Allison) |
| RAM `0x003FDDA6` | eeprom_scatter_source_table._2_2_ | Scatter-loaded from EEPROM |
| ROM `0x0005A470` | tsc1_source_address_filter | May need `0xFF` wildcard |
| RAM `0x0040AE10` | tsc1_control_word_stored.disable_control | Step 2: write `0x00` |
| RAM `0x0040AE08` | tsc1_control_word_stored.mode | Mode 3 = defuel |
| RAM `0x0040A2F4` | limit_source_priority.fuel_minimum | Verify goes to 0x0000 |
| RAM `0x0040A2F6` | limit_source_priority.source_active | Verify = 9 (tsc1_mode3_defuel) |
| RAM `0x0040A57A` | fuel_demand_calculated | Primary defuel verification |

## Files Involved

| File | Role |
|---|---|
| `firmware/CM848_S90140.06_analysis/output/function_renames.csv` | Naming hook target |
| `firmware/CM848_S90140.06_analysis/output/global_variables.csv` | Naming hook target |
| `firmware/CM848_S90140.06_analysis/output/enums.csv` | Arbitration source enum |
| `firmware/CM848_S90140.06_analysis/eeprom_dumps/` | All before/after dumps |
| `firmware/CM848_S90140.06_analysis/eeprom_dumps/README.md` | Checksum coverage map |
| `firmware/CM848_S90140.06_analysis/docs/plans/tsc1-defuel-implementation.md` | Session notes |
| `firmware/CM848_S90140.06_analysis/ghidra/analyze.sh` | Import/export workflow |
