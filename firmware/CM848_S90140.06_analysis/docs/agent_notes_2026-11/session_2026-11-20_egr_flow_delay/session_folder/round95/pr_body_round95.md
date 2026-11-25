**Round 95.**
- **CM848's executive task sets by schedule slot (98c5f90b):** the 38 role-guessed / numbered task sets are
  `cm848_runEveryFrameTaskSet` / `cm848_runEvery<N>FramesTaskSetPhase<P>` (CM550's scheme), read from the ROM jump table
  at 0xc198 and the decompiled switch, which agree for all 40 frames.
- **The MPC555 register blocks follow the MPC555 User's Manual (699816aa):**
  - `ApplyMPC555Registers.java` had thrown in its first phase on every build since 2026-05-23 (its 0x300000 block
    overlaps the memory map's 0x302000 block), so `mpc555_registers.csv` never applied, and the build still printed
    "Hardware register naming complete". The stage now runs and never splits typed data, and `run_script` stops the
    build on any SCRIPT ERROR.
  - MIOS1 `SCRD` -> `SCR` (SCRD is the +4 duplicate address), QADC64 `CCW` / `RJURR` / `LJSRR` / `LJURR` ->
    `QACR0-2` / `QASR0`, the TPU3 module registers' pads -> TCR / DSCR / DSSR / LR / SGLR / DCNR / TPUMCR2 / TPUMCR3, and
    five rendered globals with wrong register names (`USIU_INITCFG` = SGPIOCR ...). Instances are named for their block
    (`tpu_a`, `qadc64_a`, `usiu_memory_controller`; 1048 renders were `tpu_a_mcr` / `tpu_b_mcr`). 125 rows that only
    shadowed typed data or sat at reserved addresses are gone.
- **The round 95 workflow (SHA_C):** an investigator, an independent describer and a judge per batch; nothing refuted.
  - CM550's 29 placeholders in 0x30000-0x34fff: the trip information task, the engine data trending feature
    (`trending_sample_record_t`), the J1939 builders and set-ups (three twins renamed in CM848 too).
  - CM550's 1-D lookup `cm550_lookupTableInterpolation` takes a 14-byte `table_lookup_1d_arguments_t`; its 66 records
    and their 89 tables are typed and named.
  - `scheduleJ1939PeriodicMessage`'s full prototype in both firmwares (`J1939_PERIODIC_TRANSMIT_QUEUE`), so its calls
    show the PGN, interval, offset and builder; `cm550_tableLookup2D` takes its record.
  - CM550's J1708 pointer record and `cm550_j1939_powertrain_messages_received_t`; CM848's maximum torque pair, the dead
    leaf 0x29ecc and the fuel pressure governor fault blend words (were `safety_*`).
