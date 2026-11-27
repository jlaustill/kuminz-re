## Done, round 97 (2026-11-25, same PR): the abbreviation sweep, then seven judged batches (CM550's governors, engine protection, the J1939 request chain)

A peer relay started the round (14:54); later relays (15:21, 15:50, 16:20, 16:50) continued it. Scripts, maps, proofs, the
workflow script and results and the agents' scratch folders are in `session_folder/round97/`. Every build verify
DETERMINISTIC.
- **6d1058da, 139 parameter / local / field names spelled out (stage A):** 100 parameter names, 6 locals and 33 struct
  fields in both firmwares (`rx_msg` -> `received_message`, `config_ptr` -> `configuration_pointer`, `handler_func` ->
  `handler`, `dividend_hi` -> `dividend_high` ...). A first pass also rewrote some history notes; a scan of every history
  span for a new name found them, and they are restored.
- **32b7f149, enum types and members spelled out (stage B):** 51 types and 198 members (`DIAG_SERVICE_ID` ->
  `DIAGNOSTIC_SERVICE_ID`, `VP44_CMD_STATUS` -> `VP44_COMMAND_STATUS`, `SPN_91_ACCEL_PEDAL` -> `SPN_91_ACCELERATOR_PEDAL`);
  three members take their enum's prefix where the plain spelling repeats another enum's member.
- **de66d286, 162 function names spelled out (stage C):** 116 CM848 and 46 CM550; `init` becomes `initialize` (as the
  verb), `Initialization` (mid-name) or moves to the front; diag / tx / rx / temp / param / calc / ack / config / aux /
  info / eps are spelled out. Two twin names change in both firmwares (`initializeQadcModule`,
  `initializePgn65261CruiseControlSetupStruct`).
- **e7d6d5f5, the last 11 struct types with abbreviations (stage D):** `can_std_rx_desc_t` ->
  `can_standard_receive_descriptor_t`, `sensor_channel_config_t` -> `sensor_channel_configuration_t`,
  `diag_clear_flags_t` -> `diagnostic_clear_flags_t` ...
- **The round 97 workflow (`workflow_r97.js`):** seven batches R1-R7, each with an investigator, an independent describer
  and an adversarial judge. Their proposals were remapped to the stage A-D names before the apply. Nothing was refuted
  except one CM848 row (0x40ae80, already right).
- **7c65a16f, CM550's governor families (stage E, batches R1-R4):** 13 functions and 314 globals; the low speed governor
  gain set is a struct (`cm550_low_speed_governor_gain_set_t`, six instances behind the two gain set pointers) with a new
  `LOW_SPEED_GOVERNOR_GAIN_STATE` enum in both firmwares; 130 rows inside judged spans are gone;
  `cm550_updateLowSpeedGovernorAggressiveGainLogic` returns void, which removes its gotos and CONCAT22 return tracking
  (34 -> 18 statements, every branch checked against the machine code).
- **SHA_F, batches R5-R7 (stage F):** 57 CM550 and 36 CM848 functions, 64 CM550 and 3 CM848 globals, 11 enum members,
  47 CM550 prototypes.
  - **R5, engine protection:** four new CM550 struct types (the channel configuration, state, history and fault log
    entry records; their field names follow CM848's types for the same e2m records). The nine-channel tables at
    0x807032 / 0x80d0dc / 0x8057c0 and the fault logs are typed, and 407 flat rows inside them are gone; each removed
    name maps to its `table[i].field` path. PROTECTION_STATE is ENGINE_PROTECTION_TASK, with the scheduler's five
    tasks.
  - **R6, the PGN 61184 request chain:** the dispatcher, its validator, the ten memory service handlers and their
    workers take `can_standard_receive_descriptor_t *` (the bodies read `request->data_pointer`) and return the
    worker's result. 0x224f4 exports a body, so its caller shows four arguments; 0x1ffd2, the no-operation handler, is
    created from its label. The DM8 / DM10 / EEC2 / IC1 set-ups and senders are named. CM550 gets the enum
    ENGINE_RETARDER_COMMAND_SOURCE.
  - **R7:** the cylinder balance projections are one i32[6]; the numbered empty stubs are named by their call sites;
    six J1939_DIAGNOSTIC_SERVICE members take CM848's names; CM848's `hpcr_cbd*` functions are spelled out.
  - **The proof review** was a workflow: five checkers compared each of the 29 changed statement counts with the
    machine code, with two skeptics per finding. It found one real loss, which this stage fixed: the hand-written
    prototype step had dropped `cm550_sendPgn59392AcknowledgementMessage`'s second parameter, so its three callers had
    lost the ACK / NACK argument. It also found an older defect, now a lead (below).
  - **Settled while reviewing:** CM550 0x18f86 is CM848 0x508834's twin (`countEngineProtectionShutdownTime`, a full
    prototype), and 0x800620 / 0x80061a take CM848's names (`engine_protection_engine_start_flag`,
    `engine_protection_previous_engine_speed`). 382 rows that repeated their history note keep one copy (the applies
    appended a note the judged comment already ended with).

### Leads after round 97
- **Engine protection (R5 judge):**
  - 0x18fcc processDiagnosticLimitStatus against CM848 `cm848_updateEngineProtectionShutdown`: twin or counterpart?
    Its words carry CM848's names now.
  - 0x19960 (the fault derate fuel limit reset); 0x1c630, a twin candidate of CM848 0x1e810.
  - 0x8058ce / 0x8058d0 (e2m 10B3 +0 / +2, named in CM848).
  - `algorithm_enable_flags_9_cal` / `_26_cal` as bitfields; the describer's ENGINE_PROTECTION_CHANNEL enum.
- **J1939 (R6 judge):**
  - The set-ups 0x31c1a / 0x32e08 / 0x33120 / 0x331ae / 0x339b0 / 0x33c28 / 0x3401a / 0x34334.
  - The transport layer 0x23186 / 0x22e5e / 0x22c26 and its record 0x8012cc; the J1708 parser 0x1e956.
  - 0x80a9ca EBSWSS; 0x803f7a (e2m 1254 +2C, CM848's `j1939_pgn65270_priority_cal`).
  - The dispatcher's handler call renders `(short)request`: the handler field needs a function-pointer type, which
    `ApplyStructures` cannot express yet.
- **R7 judge:** CM550 0x17d2a against CM848 0x1bf44 (the same skeleton); 0x19f82 (the configuration 1 channel 0
  handler, no row); 0x80d0cd (e2m CRSYSS, misnamed `cam_sync_status`); `cm550_initializeSpeedMeasurementMode3` reads as
  configuration 3; CM848 `cm848_calculateColdStartTemperatureTable` ('Temp').
- **R1-R4 judges:** the misnamed all speed governor functions 0xd0e2 / 0xd3e6 / 0xc8a0 / 0xd23c / 0xd1a4 / 0xd218 /
  0xd584 / 0xd2be / 0xfb26 / 0xfaa6; the acceleration noise control functions 0xb2aa / 0xb4f2 / 0xb666 / 0x10394 /
  0x2dcb0; CM848's engine acceleration names for 0x800048 / 0x80a294 / 0x80a296; LSCIRF 0x80db04.
- **Rendering (found by the proof review):**
  - `cm550_calculateCylinderBalanceTrims` drops six pass-1 stores to `cylinder_balance_reference_projections` (before
    and after round 97): the decompiler does not see the argmax loop's pointer read them.
  - The interrupt masks (`move.w sr` / `ori.w #0x700,sr`) render nowhere in the .cpp.
  - Local names for the new prototypes: `pcVar7` (the channel state) in processDiagnosticLimitStatus, and `local_6` /
    `local_a` / `local_e` (parameter ID / offset / length) in the read / write by parameter ID handlers.
- **Tooling:** the round 97 apply appended a history note even when the judged comment already ended with it; round 98's
  copy must test for the note first. Two skill files (`.claude/skills/investigate-firmware-symbol`) still cite
  `cm848_initEepromDriverAndLoadMirror` and `initPgn65261CruiseControlSetupStruct`: skills are the user's to edit.
