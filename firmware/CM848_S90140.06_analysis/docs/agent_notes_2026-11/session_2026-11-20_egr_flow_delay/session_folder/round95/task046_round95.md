## Done, round 95 (2026-11-25, same PR): CM848's task sets by slot, the MPC555 register blocks, CM550's last placeholders and 1-D lookups

Peer relays started and continued the round (09:53, 10:23, 10:53, 11:23). Scripts, proofs, the workflow script and
results, the agents' scratch folders and the MPC555 manual extracts the register work used are in
`session_folder/round95/`. Three commits; every build verify DETERMINISTIC.
- **98c5f90b, CM848's executive task sets by schedule slot (38 renames):** `cm848_runEveryFrameTaskSet` /
  `cm848_runEvery<N>FramesTaskSetPhase<P>`, the scheme CM550 has used since round 93. The schedule is read from the
  ROM's 40-entry jump table at 0xc198 and from the decompiled switch; both agree for all 40 frames. The old names were
  role guesses (`cm848_periodicTaskSet_canTx` runs the vehicle speed updates), ordinals and snake_case phase names.
- **699816aa, the MPC555 register blocks against the MPC555 User's Manual:**
  - **The register stage had not run since 2026-05-23.** `ApplyMPC555Registers.java` threw in Phase 0 (its 0x300000
    block overlaps the memory map's 0x302000 block) on every build, and `run_script` hid it because analyzeHeadless
    exits 0. The script now leaves a partly mapped range alone and never splits typed data; a SCRIPT ERROR now stops
    the build (neither firmware logs another).
  - MIOS1: SCRD is the +4 duplicate address of SCR (+6); every `.SCRD` render was SCR. QADC64: +0xA-0x10 are
    QACR0-2 / QASR0, not the CCW / result tables (those are at +0x200 / +0x280 ...). TPU3: the pads and R028 / R02A
    are TCR / DSCR / DSSR / LR / SGLR / DCNR / TPUMCR2 / TPUMCR3. One type per module kind.
  - Wrong rendered names: USIU_INITCFG = SGPIOCR, USIU_EMCR = PDMCR, qsmcm_sccr0 = QDSCI_IL, mios1_ext_816 = MCPSMSCR,
    mios1_sched_ctrl = MIOS1LVL0; instances are named for their block (`tpu_a`, `qadc64_a`, `usiu_memory_controller`).
  - 122 named rows inside typed spans go (guards for a stage that never ran; most had shifted or wrong names), and
    three SIU rows at reserved addresses (a copy of the map shifted by 12 bytes).
- **SHA_C, the round 95 workflow** (N1-N3; 9 agents; nothing refuted):
  - CM550's 29 placeholders in 0x30000-0x34fff: the trip information task (`cm550_updateTripInformation`,
    `TRIP_INFORMATION_ENGINE_STATE`), the engine data trending feature (100 `trending_sample_record_t` records), the
    J1939 builders and set-ups (three twins renamed in CM848 too), `cm550_calculateWetStackTimingAdvance`.
  - CM550's 1-D lookup: `cm550_lookupTableInterpolation` takes a 14-byte `table_lookup_1d_arguments_t`
    (`table_interp_args_t` missed the no-interpolation flag); 66 records and the 89 tables they point at are typed and
    named, and 184 rows inside them go.
  - `scheduleJ1939PeriodicMessage`'s full prototype in both firmwares (the queue as `J1939_PERIODIC_TRANSMIT_QUEUE`),
    so its 19 calls per firmware show the PGN, the interval, the offset and the builder. CM550 0x1fe84 renders as a
    function for the first time. `cm550_tableLookup2D` takes its record pointer and returns a word.
  - CM550's J1708 pointer record, the engine position sensor words, `cm550_j1939_powertrain_messages_received_t`;
    CM848's maximum torque pair, the dead leaf at 0x29ecc, the fuel pressure governor fault blend words (were
    `safety_*`) and the all-speed governor blend weight words.
  - Two return types had side effects that the proof caught. CM848's last scheduler call fed its new byte return to
    `cm848_initJ1939DiagnosticServiceHandler`; a void row locks that function. CM550's `cm550_FUN_000183cc` returned a
    `CONCAT22(extraout_D0u ...)`; its caller ignores the result, so it is void.
- **Proof notes:** the local declaration order follows unrelated CSV changes (each input still builds
  deterministically), so a proof compares sorted declarations. The apply keeps a live type of a different width
  unless told otherwise; 0x801d44 kept `byte` until it was typed by hand.

### Leads after round 95
- CM550: the J1939 builders that `scheduleJ1939PeriodicMessage` receives render as `&LAB_0003229a` ...: they have no
  function yet (each is reached only through the scheduler); name them from their PGNs. `cm550_FUN_000183cc` caps
  the five torque curve fueling points by the fault derate limit at each point's speed.
- CM848: the `qadc_*` rows at 0x3fdbb2-0x3fdc1e are the boot reflash kernel's CMF erase / program step tables
  (time-shared RAM); the oil change monitor record 0x3fee34-0x3fee41 (boot / application time-share) still renders
  `register0x0000002c = ram0x003fee36 + 1`: a union of the two layouts may read better; the QADC CCW tables
  (0x304A00 / 0x304E00, word[64]) and result registers have no array rows; the peripheral type names keep
  abbreviations (`tpua_ch1_params_t`, `qsmcm_sci1_regs_t`).
