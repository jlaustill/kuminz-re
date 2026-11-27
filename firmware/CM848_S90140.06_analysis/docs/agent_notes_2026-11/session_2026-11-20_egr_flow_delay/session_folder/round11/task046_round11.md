## Done, round 11 (2026-11-21, same PR; a "keep going" relayed from another session): the e2m output and switch maps

Scripts are in `session_folder/round11/`.
- **The e2m tables of the discrete I/O** (not in the dumped part of the parameter ID table except 12A7 / 12A8):
  | Block | Contents | Layout |
  |---|---|---|
  | 1577 | the 80 logical output requests (`<Name>_Driver`) | output N = byte N/8, mask 1 << N%8, at 0x40c080 |
  | 12A7 | the per-output override priorities | 0x40c094, `logical_output_request_priority` |
  | 1578 / 1579 / 157A | inversion, hardware map, previous command | per output |
  | 1612 | the 32 debounced discrete inputs (switches) | switch N = byte N/8 bit N%8, `switch_input_state_bits` at 0x40c050 |
  | 12A8 | the per-input override priorities | 0x40c058 |
  - They confirm the round 10 DRB names (16 = Transmission_VFS_Battery_Driver, the relay's battery feed of the
    solenoids) and the earlier switch findings (20 = park / neutral, 12 = Engine_Brake_Select_1, the exhaust brake
    switch, 13 = A/C).
- **Stage A (3c1f706, label-only):**
  - **The lift pump control:** `cm848_controlLiftPump` / `cm848_initializeLiftPumpControl`,
    `lift_pump_run_reason`, `lift_pump_engine_stopped_time`, and the 8A6F calibrations at 0x408976 (override state,
    the run times after cranking 20 s / key-on 35 s / running 0 s, override enable).
  - **Why 8A6F is shifted:** 11.45 computes the key-on time from a temperature table (8D2C / 8D2D into RAM 8D2E).
    This calibration has a fixed word at +4, so 11.45's +4 / +6 records sit at +6 / +8, and Temp_Source has no
    word. The code decides: the override gate is +8 and the reason 1 / 2 / 3 limits are +4 / +6 / +2.
  - **The SCI output status word:** `cm848_sciPackOutputStatusWord` (was `FUN_0051dfdc`) / `sci_output_status_word`.
  - **Two cache names**, and the request byte at 0x40c084 renamed `logical_output_request_bits_32_to_39`.
  - **The 1612 switch map** in the `switch_input_state_bits` comment.
- **Stage B (9e292a9, types):**
  - Bitfield structs for request bytes 1 / 4 / 5 / 6 / 8 / 9 from 1577: the tested bits named, the rest
    `reserved_bit_N` with the record. Every access is a masked read, so there are no pieces.
  - Byte 0 stays a byte: the set / clear functions index the array from it.
  - `LIFT_PUMP_RUN_REASON`.
  - The proof: `bitfield_normalize.py` (field to `(instance & mask)`, enum members to values) +
    `cast_normalized_diff.py`.
- **Stage C (2da9b14, types): `switch_input_state_t`** at 0x40c050, from 1612.
  - **The shape:** byte 2 (switches 16-23: park / neutral, the O/D OFF button, remote PTO, the relay and solenoid
    feedbacks) is a bitfield unit. Bytes 0 / 1 / 3 are byte fields (`switches_0_to_7` / `_8_to_15` / `_24_to_31`),
    each with its bit map. Five setter functions update their bits with | / & (switches 2 / 13 / 31).
  - **The pilot (all 32 as bitfields)** measured 216 named reads, but also 10 `._N_1_` piece lines in 3 of the 5
    setters (2 folded into `unwired_switch = 1 / 0`), and the scanner printed
    `(&switch_input_state_bits.field_0x0)[i]` (`round11/pilot_r11c_numbers.txt`).
  - **Left to the user:** the pilot failed the no-pieces gate and the firmware/CLAUDE.md rule. Taking the full
    struct means swapping in the pilot's rows (`apply_r11c_switch_struct.py`) and amending the rule.
  - **The proof:** `switch_normalize2.py` + `cast_normalized_diff.py`.
- **Stage D (label-only):** output 54 is `fuel_shutoff_request` (was stage B's `injector_driver_asic_shutoff_request`).
  Its requesters are the fuel pressure fault reactions (`output_requesters.py 0x36`); the injector diagnostics only
  read it.
- **Round 11 leads:**
  - **The switch bytes 0 / 1 / 3 as bitfields:** the user's call (the numbers above).
  - **`fuel_pressure_setpoint_map_cached_axis_offsets`** is a `word` row with a plural name: type it `word[16]`.
  - **`cruise_setpoint_interp_prev`** (0x3fd006) is a value looked up by vehicle speed (its change per pass is
    clamped to +-0x66), not a setpoint: name it with the cruise governor.
  - **The input priority array** at 0x40c058 (e2m 12A8) has no code reference by name yet.
  - The cam_sync tables, the end-of-line test sequencer, 8C80 / 8C2D and the SCI high-speed words stay open from
    round 10.
