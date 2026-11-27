
**Round 11 (a "keep going" relayed from another session): the e2m discrete I/O maps.**
- **The e2m tables of the discrete I/O:**
  - 1577 names the 80 logical output requests (output N = byte N/8, mask 1 << N%8) and 1612 the 32 switches; 12A7 /
    12A8 are their override priorities.
  - They confirm round 10's DRB names. Output 16 is Transmission_VFS_Battery_Driver, the relay's battery feed to
    the solenoids.
  - They also confirm the switch findings: 20 = park / neutral, 12 = the exhaust brake select.
- **Stage A (3c1f706, label-only):**
  - **The lift pump control:** `cm848_controlLiftPump` / `cm848_initializeLiftPumpControl`, its run reason and
    stopped timer, and the e2m 8A6F calibrations: override state, the run times after cranking 20 s / key-on 35 s /
    running 0 s, override enable. This calibration has a fixed key-on word, so 11.45's records after +2 sit one word
    later.
  - **The SCI output status word** (`cm848_sciPackOutputStatusWord`, was `FUN_0051dfdc`).
  - **Two cache names**, and the 1612 switch map.
- **Stage B (9e292a9, types):**
  - Bitfield structs for six request bytes, from 1577: the engine brake drivers 1-5, the A/C clutch, the intake air
    heaters, the lift pump, the EGR valve and VGT drives.
  - `LIFT_PUMP_RUN_REASON`.
  - No new `._N_1_` pieces.
- **Stage C (2da9b14, types): `switch_input_state_t`.** Byte 2 (park / neutral, the O/D OFF button, the relay and
  solenoid feedbacks) is a bitfield unit; bytes 0 / 1 / 3 are byte fields with their bit maps.
  - Their bits have read-modify-write setters, which the firmware/CLAUDE.md wave 11 rule keeps as bytes.
  - The all-bitfield pilot measured 216 named reads against 10 piece lines in 3 setters plus a `field_0x0` in the
    scanner. It is not shipped; it is left to the user.
- **Stage D (label-only):** output 54 is `fuel_shutoff_request`. Its requesters are the fuel pressure fault
  reactions.
