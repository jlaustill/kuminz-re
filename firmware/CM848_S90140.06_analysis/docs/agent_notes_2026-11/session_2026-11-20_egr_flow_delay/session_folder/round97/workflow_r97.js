export const meta = {
  name: 'kuminz-naming-round-97',
  description: 'Round 97 naming (CM550 global families with Calterm-slug / abbreviated names - low speed, high / all speed governors, acceleration noise control, engine position, engine protection - and the round 96 judges leads): investigator + independent describer + judge per batch',
  phases: [
    { title: 'Investigate', detail: 'one investigator and one blind role describer per family, in parallel' },
    { title: 'Judge', detail: 'a judge per family compares both and re-derives every disputed element' },
  ],
}

const REPO = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay'
const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97'
const F = `${R}/frozen`
const T = '/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools'

const COMMON = `CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 97).
EVERYTHING IS READ-ONLY for you: never edit, create or delete a repository file, never run ./analyze.sh, never run git commands that change anything. Scratch files only under ${R}/scratch/<batch>/<your role>/.
- CM550 (Cummins J90350.00, MC68336 / CPU32, VP44 pump engine): FROZEN copies in ${F}/cm550/ - J90350.00.ghidra.cpp (each function starts with "// Function: <name> @ <address>"), function_renames.csv (address,name,plate comment), global_variables.csv (address,name,type,comment), function_definitions.csv, structure_definitions.csv, local_variables.csv, enums.csv (enum_name,value,member_name,comment,size). ROM: ${REPO}/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin (file offset = address, big-endian; the dump ends at 0x40000 - call targets above it print as func_0x0004xxxx and are not dumped). RAM dump J90350.00.ram.bin (address - 0x800000, up to 0x8091C1) and J90350.00.extended_ram.bin (file offset = address - 0x809242) in the same folder.
- CM848 (Cummins S90140.06, MPC555 PowerPC, common rail; the better named firmware): FROZEN copies in ${F}/cm848/ - cm848_rom.ghidra.cpp, function_renames.csv, global_variables.csv, structure_definitions.csv, enums.csv, function_definitions.csv, local_variables.csv. Images: ${REPO}/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin (base 0) and cm848_flash2_live.bin (base 0x500000).
- TOOLS:
  - python3 ${T}/body.py <cpp> <function name> [...]  prints the decompiled bodies.
  - python3 ${T}/m68k.py ${REPO}/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin <start hex> <end hex>  disassembles CM550 code (CPU32). Do NOT use llvm-mc for m68k: on this ROM it mis-decodes andi / tst / clr / moveq and loses sync. A '.word' line is data (a jump table) or an opcode the tool does not know: decode it by hand.
  - python3 ${T}/abs_refs.py ${REPO} 0x<address> [...]  lists every absolute-long reference to a CM550 address in the ROM with the access width.
  - CM848 PowerPC: python3 ${REPO}/firmware/scripts/disasm_func.py <function|0xADDR> [0xDATA_ADDR] (run it from ${REPO}/firmware).
  - e2m (Calterm) records: python3 ${REPO}/firmware/scripts/e2m_block_addresses.py --firmware cm550 --address 0x0080d330   |   --firmware cm550 1051   (CM848: without --firmware). CM550's e2m is ${REPO}/e2m-analysis/originals/v64t6_s.e2m (columns: mnemonic, unit, block, offset, region, type N/S/B/T/X/Y/Z, access, length, precision, signed, scale or - for S records - the bit mask, minimum, subfile, group, crc; the description after ';' and the range after '~'). CM848's labelled e2m: ${REPO}/e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m. 58 more e2m files of the same family are in ${REPO}/e2m-analysis/originals/ and ${REPO}/e2m-analysis/CHR/.
  - J1939 definitions (PGN / SPN layouts): a local MongoDB (database j1939, collection pgns, PGN field "number") is reachable through the MongoDB MCP tools (load them with ToolSearch "mongodb find"; connect to mongodb://localhost:27017/j1939 first). Optional.
- A function that nothing calls by name is reached through a pointer: search the ROM for its big-endian 4-byte address (task tables of the scheduler sit around 0x1b4c0-0x1b500; J1939 handlers are registered with registerJ1939ReceiveHandler / registerJ1939DiagnosticService) and say which table / registration reaches it.
- ESTABLISHED IN EARLIER ROUNDS (trust these names, they were verified): engine_state is ENGINE_STATE (1 STOPPED .. 8 SHUTDOWN); the fueling state words are FUELING_STATE in both firmwares (the Calterm labels are in each member's comment in enums.csv); CM550's algorithm enable words are algorithm_enable_flags_<n>_cal with bitfields whose comments quote the Calterm record of each bit (structure_definitions.csv, types algorithm_enable_flags_<n>_t / cm550_algorithm_enable_flags_<n>_t); the J1939 receive layer (registerJ1939ReceiveHandler, receivePgn<number><Name>Message handlers, j1939_input_signal_timeouts, the j1939_received_* bytes); the TSC1 path (processEngineTsc1Request, findTsc1SourceConfiguration); round 96: the periodic J1939 builders of both firmwares by PGN (cm550_build/sendPgn<number><Name>Message), registerJ1939PgnRequestHandler / registerJ1939ReceiveHandler / registerJ1939DiagnosticService with full prototypes, CM550's cylinder balancing (mc68k_fillCylinderBalanceSpeedBuffers, cm550_calculateCylinderBalanceTrims, the cylinder_balance_* arrays), the serial EEPROM write queue (eeprom_write_queue_*, cm550_queueEepromByteWrites), cm550_sendCanSingleFrame / cm550_transmitCanFrameOnMessageObject (an Intel 82527 CAN controller at 0xffd800).
- CM550's EEPROM image is RAM 0x803b0a-0x804f93 (round 94: the start-up load is 0x148a bytes), so a new CM550 global name there ends in _cal; CM848's is 0x3fd482-0x3feec1. THE CURRENT NAME OF A FUNCTION IS NOT EVIDENCE - not its words and not its prefix. Many CM550 names came from an old automatic pass (vp44SensorStatusMonitor turned out to be the idle shutdown state machine, cm550_engineRunTimeHistogramAccumulator a J1939 transmit schedule). Derive every role from the code.
- NAMING RULES: functions lowerCamelCase, globals lower_snake_case, enum members UPPER_SNAKE_CASE with the enum's prefix. Spell every word out: no invented abbreviations or initialisms (universal ones are fine: RPM, J1939, J1922, J1587, PGN, SPN, TSC1, DM1, DTC, ECM, EEPROM, RAM, ROM, CAN, PWM, ADC, ID, VP44, PTO is NOT fine - write powerTakeOff). Write initialize, never init. Never the bare word "protection": say protection of what. Numbers in names are decimal (PGN 65265, state 17), never hex. Name what the code DOES (a verb phrase for a function) from its own code and its users; put the major concept first where the repository does (see the neighbours). _cal only on values inside CM550's EEPROM mirror 0x803B0A-0x804155 (CM848: 0x3fd482-0x3feec1).
- PREFIX / TWIN RULE: a CM550 function with a CM848 TWIN takes ONE shared unprefixed name in both firmwares (both rows change). A twin needs proof: the same steps in the same order, the same constants and the same position in the call graph - a similar purpose is not enough. A function with a CM848 COUNTERPART (same role, different code) or with none takes a prefix: vp44_ (it handles the VP44 pump or its messages), mc68k_ (it accesses MC68336 registers or chip-select devices), else cm550_. CM848-only names use cm848_ / mpc555_ / hpcr_. When CM848 already has an unprefixed name for the twin, use that name.
- RENAMING GLOBALS: many CM550 global names are Calterm description slugs from an old automatic pass (the words of the e2m description, cut at a length limit, often with abbreviations, a value-range suffix such as _0_100 / _300_1000 and an address suffix such as _8246). Give each row the name of what it holds: read the code that writes and reads it (every user: python3 ${T}/abs_refs.py) and its e2m record (e2m_block_addresses.py --firmware cm550 --address 0x...: the mnemonic, description, unit and scale). When CM848 has a row for the SAME e2m record (same block and offset: e2m_block_addresses.py <block> without --firmware lists CM848's addresses and names), reuse CM848's name, changing only _cal by the memory map. Drop range and address suffixes. Keep the major concept first (low_speed_governor_..., engine_protection_...). Check the type against the access widths and correct it in proposed_type. A row whose meaning the code and the record do not settle goes to skipped[] (address, current name, what is missing).
- A NAME NEEDS A DISCRIMINATOR: an enable bit or a shared global proves the subsystem, not the role. Several functions here read the same bit. Each name must rest on what THIS body does that its siblings do not (which input, which output, which step). If the code does not show that, do not name the function: skip it and say what is missing.
- New names must be unique within their firmware (grep function_renames.csv / global_variables.csv) and must not collide with another proposal.
- GHIDRA NOTES: in x._38_2_ the offset 38 is DECIMAL bytes. '(ushort)algorithm_enable_flags_<n>_cal & 0x200' is a masked read of a bitfield word: look the bit up in the type. '_name' with a leading underscore is the row 'name' read wider than its type. DAT_/_DAT_ are unnamed addresses.`

const BATCHES = [
  { id: 'R1', title: "CM550's low speed governor globals (lsg names)", text: `The 56 CM550 global rows listed in ${R}/family_R1.txt (one 'address name type' line each) use the abbreviation lsg; many are Calterm description slugs (offset_to_lsg_reference_speed_over_which_lsg_integrator_m_1000_1000, added_to_4d_fueling_at_lsg_adj_ref_speed_to_determine_lsg_integ_5_5_8246). They belong to the low speed governor: cm550_runLowSpeedGovernor (0x25b1c), cm550_presetLowSpeedGovernorIntegrator (0x25a34), cm550_initializeLowSpeedGovernor (0x26078), cm550_calculateLowSpeedGovernorColdIdleSpeed (0x26616) and their callees. CM848's low speed governor is named (cm848_runLowSpeedGovernor and its low_speed_governor_* words): reuse its names for the same e2m records.
YOUR TASK: a proper name and a checked type for every listed row (globals[]), or skipped[]. Review the names of this family's functions too, and rename one only with a discriminator.`},
  { id: 'R2', title: "CM550's high speed and all speed governor globals (hsg / asg names)", text: `The 100 CM550 global rows listed in ${R}/family_R2.txt use hsg or asg (the high speed governor and the all speed governor; hsg_maximum_filtered_engine_speed_error_0_1000, asg_reset_state_x1_2000_2000 ...). Their users include the shared high speed governor block (runHighSpeedGovernorPid 0x1ce7c, presetHighSpeedGovernorIntegrator 0x1d252, selectHighSpeedGovernorGainSet, selectEngineSpeedLimit 0x1d5a0, initializeEngineSpeedLimitDefaults 0x1d94e - twins with CM848 already) and the all speed governor (cm550_calculateAllSpeedGovernorDroopFueling 0xf716, cm550_initializeAllSpeedGovernorReferenceSpeedSets 0xd3b2, cm550_selectVariableSpeedGovernorMode 0xd4ae and their siblings). CM848 names these words high_speed_governor_* / all_speed_governor_* (rename waves 6 / 8 / 9 / 15): reuse them for the same e2m records.
YOUR TASK: a proper name and a checked type for every listed row (globals[]), or skipped[].`},
  { id: 'R3', title: "CM550's acceleration noise control, road speed governor, air fuel control and power take-off globals", text: `The 75 CM550 global rows listed in ${R}/family_R3.txt use anc / rsg / afc / pto / accel / decel (acceleration noise control, the road speed governor of cruise, the air fuel control derate, power take-off; anc_speed_limit_hold_timer, high_limit_for_cruise_rsg_error_delta_0_255, afc_fueling_derate_value_when_afc_override_is_enabled_0_100, pto_engage_debounce_counter ...). Also name the two ANC inhibit timers 0x80003c / 0x80003e (siblings of acceleration_noise_control_timing_limit_inhibit_timer 0x800040). Users include cm550_calculateAccelerationNoiseControlTimingLimit (0xb3d0) and the ANC timing functions, the cruise / road speed governor functions, cm550_calculateAirFuelControl... and the power take-off functions (applyPowerTakeOffTorqueLimit 0x2d9a8 and its twins). Reuse CM848's names for the same e2m records (CM848: road_speed_governor_*, cruise_*, power_take_off_*, air_fuel_control_*).
YOUR TASK: a proper name and a checked type for every listed row (globals[]), or skipped[].`},
  { id: 'R4', title: "CM550's engine position sensor and speed measurement globals", text: `The 114 CM550 global rows listed in ${R}/family_R4.txt use eps / pmm / ess / meas / crk / dzg (the engine position sensor, period measurement, the engine speed sensor, crank, the dead zone gap: eps_diagnostic_table_ptr, period_meas_per_average_num_of_primary_speed_pulse_periods_mea_0_255, crank_deg_per_period_meas_crank_degrees_between_primary_speed_0_720, dzg_timing_control_params ...). Also the pulse 0 line records 0x80847a / 0x80847c (round 96's Q4 judge: they still carry old names). Users include the TPU channel 0 / 1 / 10 speed input set-ups and interrupt handlers (mc68k_initializeTpuChannel10PrimarySpeedInputMode1 0x19caa, mc68k_tpuChannel10PrimarySpeedInterruptHandlerMode1 0x19e90, mc68k_initializeTpuChannel1BackupSpeedPeriodInput 0x1b1ea ...), cm550_checkEnginePositionSensorPhaseOnBackupPeriod (0x1a298), cm550_calculateEnginePositionPhaseLag (0x26e8e) and the engine speed calculation. CM848's engine speed module is e2m 819B (filtered_engine_speed, main_engine_speed, backup_engine_speed, the cam / crank sync counters, the *_time_ticks start times): reuse its names for the same records. Several rows may be pointer tables or arrays: type them as what the code indexes.
YOUR TASK: a proper name and a checked type for every listed row (globals[]), or skipped[].`},
  { id: 'R5', title: "CM550's engine protection code: the bare 'protection' functions and the epf / prot globals", text: `CM550's engine protection code still carries guessed names with the bare word "protection". FUNCTIONS (name each one from its code; most sit in 0x18620-0x1952c): 0x18620 cm550_engineProtectionMultiStateSlowCycle40Coordinator; 0x186ae cm550_protectionThresholdCalculationHelper; 0x18708 cm550_protectionPercentageCalculator; 0x1873e vp44_engineProtectionSystemInit; 0x18968 cm550_protectionConditionEvaluator; 0x18a26 protectionState0FaultDurationCounter (unprefixed: check whether CM848 has a twin of that name, else prefix it); 0x18ac4 cm550_diagnosticProtectionEvaluator; 0x18c1c cm550_diagnosticProtectionProcessor; 0x18cb6 cm550_protectionState1DiagnosticValidator; 0x18dae cm550_updateEngineProtectionRestartLimitationCommands (round 96; confirm or correct); 0x192e0 cm550_initializeEngineProtectionShutdownCounting; 0x192f2 cm550_protectionCalculationHelper; 0x19332 protectionStateProcessor and 0x19436 protectionStateValidator (unprefixed: check for CM848 twins); 0x1952c cm550_protectionState3bRpmMonitor; 0x30b04 cm550_protectionLimitValueInit; 0x3458c cm550_engine_protection_coordinator (not even lowerCamelCase); 0xc66a cm550_rpmHistogramAndProtectionStatisticsAccumulator; 0xd5e6 cm550_initBoostProtectionSystem. GLOBALS: the 50 rows in ${R}/family_R5.txt (epf / prot slugs: severity_index_for_epf_coolant_level_fault_0_0_1_0, index_into_epf_fault_log_for_coolant_level_fueling_0_4 ...) and the per-channel tables the loop in 0x18cb6 walks (settings records from 0x807032, state records from 0x80d0dc, the EEPROM-backed records from 0x8057c0, the enable bit index from 112): type them as struct arrays when the layout is proven by the code (prove each field's offset and width), else name the rows. Cummins calls this feature engine protection (EPF / EPS e2m records): say protection of WHAT (coolant temperature / coolant level / oil pressure / intake temperature / boost ...) in every name.
YOUR TASK: functions[] for every listed function and globals[] for every listed row and table (or skipped[]).`},
  { id: 'R6', title: "CM550's J1939 set-ups, senders and the PGN 61184 request chain (round 96 Q1 / Q2 leads)", text: `Round 96's judges left these CM550 leads (check each one from the code; do not trust the lead itself): 0x32244 (a DM10 set-up, said to be a twin of CM848 0x24b64), 0x323be (a DM1 set-up), 0x33aea (a PGN 65257 set-up, not 65249), 0x33064 (the EEC2 set-up), 0x33ce2 and 0x343d2 (vp44_ prefixes that may be wrong), 0x31b22 (the PGN 59392 acknowledgement sender: control byte 0 = ACK, 1 = NACK), 0x32b38 (the DM8 sender), 0x322ae j1939HandlePgn65226Dm1ActiveDtc (the DM1 sender shared by name with CM848 0x24be8: check the twin and give it a build / send name), the J1587 length helpers 0x2ed6a / 0x2edb2 and the dispatcher 0x2eea2, 0x803613 (IC1 byte 6, the SPN 173 low byte, no row yet), 0x80a9cc (e2m 117D +8 EBCOAG: CM848's ENGINE_RETARDER_COMMAND_SOURCE enum may fit), 0x3407a (a void(void) prototype would remove its in_D0 / uint return), and the RC '=' bug at 0x340b6 (it overwrites 0x8081fe with 1; document it in the plate). THE REQUEST CHAIN: the PGN 61184 service handlers (registered with registerJ1939DiagnosticService), cm550_diagnosticServiceDispatcher and writeJ1939DiagnosticMemory take the received frame as dword / int; the frame is a can_std_rx_desc_t (+0 id dword, +4 length word, +6 data_ptr): give full prototypes (prototypes[]: every parameter with its stack offset; CM550 uses 2-byte argument slots, see stack_parameter_layout.csv) that type it as can_std_rx_desc_t* through the whole chain, so the bodies read request->data_ptr instead of *(int *)(param_1 + 6).
YOUR TASK: functions[] for every listed function, globals[] / enum_members[] / prototypes[] where the code proves them.`},
  { id: 'R7', title: "The round 96 Q3 / Q4 leads and the numbered empty stubs", text: `Check each lead from the code. CM550 FUNCTIONS: 0x143b6 and 0x1c640 (said to be twins of CM848 functions); 0x19ac2, 0x1b39a, 0x1af32, 0x1a6e8, 0x17a8e, 0x17b8a, 0xfa06 and 0xfb26 (said to be misnamed); 0x23be8 diagnosticMainStateProcessor (unprefixed, but CM848 0x1d9b8 by that name is a different function, the fault scanner: give the CM550 one its own prefixed name, and check the CM848 one's name too); the numbered empty functions cm550_emptyStubFunction4 (0x15f8c), 7 (0x19aca), 10 (0x26852), 11 (0x30b0e) and 12 (0x26b82): name each by its one call site's role, the way round 96 named cm550_emptyExecutiveFrame5ExtraTask and cm550_emptyEnginePositionSignalConfiguration1ThirdStep. CM848 FUNCTIONS (cm848_functions[]): the numbered empty functions cm848_emptyStubFunction (0x54220), 3 (0x1806c), 5 (0x26f7c), 6 (0x2c0fc) and 8 (0x55e9c) the same way; hpcr_cbdFillAccelerationBuffers, hpcr_cbdCalculateCylinderTrims and hpcr_cbdInitFilterState (cbd is an invented abbreviation; they are the counterparts of CM550's mc68k_fillCylinderBalanceSpeedBuffers / cm550_calculateCylinderBalanceTrims / cm550_initializeCylinderBalancing) and any other cbd-named CM848 function or global. CM550 GLOBALS: the cylinder balance projection words 0x8002ac (load_trending_table_2_ptr), 0x8002b0 (fuel_timing_blend_rpm_input_2) and 0x8002b4 (no row) that cm550_calculateCylinderBalanceTrims writes (each = a reference vector x the adjusted component 2 sum), STUOTHGV 0x80a982 and LSCIRF 0x80db04 (old names). ENUM: CM550's J1939_DIAGNOSTIC_SERVICE members 0x43 / 0x46 / 0x48 / 0x4a / 0x4c are said to be stale; CM848's READ_BY_PARAMETER_ID_LONG_LENGTH / _SHORT_OFFSET / _LONG_OFFSET / READ_MEMORY / READ_MEMORY_LONG_LENGTH may fit the CM550 handlers: check each handler's request parsing and give enum_members[] for both firmwares where they share the member.
YOUR TASK: functions[], cm848_functions[], globals[] and enum_members[] for every listed element (or skipped[]).`},
]

const PROPOSAL = {
  type: 'object',
  properties: {
    batch: { type: 'string' },
    summary: { type: 'string', description: 'what this family is and how it works, in 3-6 sentences' },
    functions: { type: 'array', items: { type: 'object', properties: {
      address: { type: 'string', description: 'CM550 function address, hex' },
      current_name: { type: 'string' },
      proposed_name: { type: 'string', description: 'the full new CM550 name (with its prefix, or unprefixed for a twin); the current name when it is already right' },
      role: { type: 'string', description: 'one sentence: what the code does' },
      discriminator: { type: 'string', description: 'what this body does that its siblings / the other readers of the same enable bit do not' },
      relation: { type: 'string', enum: ['twin', 'counterpart', 'standalone'] },
      cm848_address: { type: 'string', description: 'for a twin or counterpart: the CM848 function address; else empty' },
      cm848_current_name: { type: 'string' },
      plate_comment: { type: 'string', description: 'the comment for the function row: 1-4 sentences on what it does, its inputs / outputs, the Calterm records involved; no commas problem - plain text' },
      evidence: { type: 'string', description: 'code facts with addresses (instruction addresses, file:line, ROM bytes); for a twin the step by step match' },
      confidence: { type: 'string', enum: ['high', 'medium', 'low'] },
    }, required: ['address', 'current_name', 'proposed_name', 'role', 'discriminator', 'relation', 'plate_comment', 'evidence', 'confidence'] } },
    skipped: { type: 'array', items: { type: 'object', properties: { address: { type: 'string' }, current_name: { type: 'string' }, reason: { type: 'string' } }, required: ['address', 'current_name', 'reason'] } },
    globals: { type: 'array', items: { type: 'object', properties: {
      firmware: { type: 'string', enum: ['CM550', 'CM848'] },
      address: { type: 'string' },
      current_name: { type: 'string', description: 'the row name, or empty when there is no row (DAT_ / WORD_)' },
      proposed_name: { type: 'string' },
      proposed_type: { type: 'string', description: 'byte / word / dword / sbyte / short / an enum or struct name / T[N]; from the access widths' },
      comment: { type: 'string' },
      evidence: { type: 'string' },
      confidence: { type: 'string', enum: ['high', 'medium', 'low'] },
    }, required: ['firmware', 'address', 'current_name', 'proposed_name', 'proposed_type', 'comment', 'evidence', 'confidence'] } },
    enum_members: { type: 'array', items: { type: 'object', properties: {
      firmware: { type: 'string', enum: ['CM550', 'CM848', 'both'] },
      enum_name: { type: 'string' },
      value: { type: 'number' },
      current_member: { type: 'string', description: 'empty for a new member' },
      proposed_member: { type: 'string' },
      comment: { type: 'string' },
      evidence: { type: 'string' },
      confidence: { type: 'string', enum: ['high', 'medium', 'low'] },
    }, required: ['firmware', 'enum_name', 'value', 'current_member', 'proposed_member', 'comment', 'evidence', 'confidence'] } },
    prototypes: { type: 'array', description: 'function prototypes (batch N3): one function_definitions.csv row set per function', items: { type: 'object', properties: {
      firmware: { type: 'string', enum: ['CM550', 'CM848'] },
      address: { type: 'string' },
      function_name: { type: 'string' },
      return_type: { type: 'string', description: 'the return type keyword, or void' },
      params: { type: 'array', items: { type: 'object', properties: { index: { type: 'number' }, name: { type: 'string' }, type: { type: 'string' }, comment: { type: 'string' } }, required: ['index', 'name', 'type', 'comment'] } },
      evidence: { type: 'string', description: 'the stack offsets / registers each parameter is read from, the return register and how callers use it' },
      confidence: { type: 'string', enum: ['high', 'medium', 'low'] },
    }, required: ['firmware', 'address', 'function_name', 'return_type', 'params', 'evidence', 'confidence'] } },
    cm848_functions: { type: 'array', description: 'CM848-only function renames: address = the CM848 function address', items: { type: 'object', properties: {
      address: { type: 'string' },
      current_name: { type: 'string' },
      proposed_name: { type: 'string' },
      role: { type: 'string' },
      discriminator: { type: 'string' },
      plate_comment: { type: 'string' },
      evidence: { type: 'string' },
      confidence: { type: 'string', enum: ['high', 'medium', 'low'] },
    }, required: ['address', 'current_name', 'proposed_name', 'role', 'discriminator', 'plate_comment', 'evidence', 'confidence'] } },
    notes: { type: 'string', description: 'leads for later rounds, things that did not fit, judgment calls' },
  },
  required: ['batch', 'summary', 'functions', 'skipped'],
}
const BLIND = {
  type: 'object',
  properties: {
    batch: { type: 'string' },
    roles: { type: 'array', items: { type: 'object', properties: {
      address: { type: 'string' },
      role: { type: 'string', description: 'one or two sentences: what the code does, from the code only' },
      discriminator: { type: 'string', description: 'what distinguishes it from its siblings in this family' },
      cm848_counterpart: { type: 'string', description: 'CM848 function name @ address that does the same job, with twin / counterpart / none and why; empty when you did not find one' },
      suggested_name: { type: 'string', description: 'a name by the rules, or empty when the code does not support one' },
      confidence: { type: 'string', enum: ['high', 'medium', 'low'] },
    }, required: ['address', 'role', 'discriminator', 'suggested_name', 'confidence'] } },
    enum_roles: { type: 'array', items: { type: 'object', properties: { enum_name: { type: 'string' }, value: { type: 'number' }, meaning: { type: 'string' }, evidence: { type: 'string' } }, required: ['enum_name', 'value', 'meaning', 'evidence'] } },
    notes: { type: 'string' },
  },
  required: ['batch', 'roles'],
}
const VERDICT = {
  type: 'object',
  properties: {
    batch: { type: 'string' },
    verdicts: { type: 'array', items: { type: 'object', properties: {
      kind: { type: 'string', enum: ['function', 'global', 'enum_member', 'cm848_function', 'prototype'] },
      firmware: { type: 'string', enum: ['CM550', 'CM848', 'both'] },
      address: { type: 'string', description: 'function / global address (hex); for an enum_member: <ENUM_NAME>:<decimal value>' },
      verdict: { type: 'string', enum: ['CONFIRMED', 'AMENDED', 'REFUTED'] },
      own_role: { type: 'string', description: 'for a function: the role you derived yourself from the code' },
      final_name: { type: 'string', description: 'the exact name to apply (the proposal, your amendment, or the current name when REFUTED)' },
      final_type: { type: 'string', description: 'global: the exact type to apply; else empty' },
      final_relation: { type: 'string', description: 'function: twin / counterpart / standalone' },
      final_cm848_address: { type: 'string', description: 'function, twin only: the CM848 address whose row takes the same name' },
      final_comment: { type: 'string', description: 'the full corrected comment text when the proposal comment has an error; empty to keep the proposal comment' },
      reason: { type: 'string' },
    }, required: ['kind', 'firmware', 'address', 'verdict', 'final_name', 'reason'] } },
    overall: { type: 'string' },
  },
  required: ['batch', 'verdicts'],
}

const OPTIONS = (args && typeof args === 'object' && !Array.isArray(args)) ? args : {}
const WANTED = Array.isArray(OPTIONS.batches) && OPTIONS.batches.length ? OPTIONS.batches : BATCHES.map((b) => b.id)
const GIVEN = (b) => (OPTIONS.given && OPTIONS.given[b.id]) || {}
const TRIES = 4
const NOTE = (n, role, b) => `\n\nKEEP NOTES: write each finding you are sure of into ${R}/scratch/${b.id}/${role}/notes.md as soon as you have it (one short entry per function / global / enum member, with its evidence), so the work survives an interruption. ` + (n > 1
  ? `THIS IS ATTEMPT ${n}: the attempt before this one was cut off by a server error. Read ${R}/scratch/${b.id}/${role}/notes.md and the scripts in that folder first and continue from them (re-check what you reuse); do not start over.`
  : `An earlier run of this exact task may have been cut off by a server error: if ${R}/scratch/${b.id}/${role}/ already holds notes or scripts, read them first and continue from them (re-check what you reuse).`)
async function sturdy(makePrompt, opts) {
  for (let n = 1; n <= TRIES; n++) {
    const r = await agent(makePrompt(n), { ...opts, label: n === 1 ? opts.label : `${opts.label} (try ${n})` })
    if (r) return r
    log(`${opts.label}: attempt ${n} returned nothing (API error); ${n < TRIES ? 'starting it again' : 'giving up'}`)
  }
  return null
}
const results = await pipeline(
  BATCHES.filter((b) => WANTED.includes(b.id)),
  (b) => parallel([
    () => GIVEN(b).proposal ? Promise.resolve(GIVEN(b).proposal) : sturdy((n) => `You are the INVESTIGATOR for batch ${b.id} (${b.title}).\n\n${b.text}\n\n${COMMON}\n\nYOUR OUTPUT: every function listed for this batch appears exactly once, in functions[] (with a proposed name, even when the current name is right - then proposed_name = current_name) or in skipped[] (not enough evidence: say what is missing). In a batch that lists globals (a row file), every listed global appears exactly once, in globals[] (proposed_name = current_name when it is already right) or in skipped[] (address, current name, the reason). Fill role and discriminator from the code before you choose a name. Decide twin / counterpart / standalone for each function by reading the CM848 code. Add globals[] and enum_members[] where the code proves them. Give exact, applicable values and the evidence for each. Leave out anything the code does not support. Keep your scratch scripts and notes in ${R}/scratch/${b.id}/investigator/.${NOTE(n, 'investigator', b)}`,
      { label: `investigate:${b.id}`, phase: 'Investigate', schema: PROPOSAL }),
    () => GIVEN(b).blind ? Promise.resolve(GIVEN(b).blind) : sturdy((n) => `You are an INDEPENDENT DESCRIBER for batch ${b.id} (${b.title}). Another agent is naming these functions; you will not see its work, and a judge will compare your descriptions with its proposals. Read the code of each function below (decompilation, and the disassembly where the decompilation is unclear) and say what each one does, what distinguishes it from its siblings, and which CM848 function does the same job (twin, counterpart or none). In a batch that lists globals, give one roles[] entry per listed global as well (address = the global's address; role = what the code stores there, who writes and who reads it, and its e2m record; discriminator = how it differs from its neighbours; cm848_counterpart = the CM848 row of the same e2m record if any; suggested_name).${b.id === 'F1' ? ' Also give, in enum_roles[], the meaning of each unidentified FUELING_STATE member the code lets you prove (which function stores or tests it, with which limit).' : ''} Describe only what the code shows; write an empty suggested_name when the code does not support a name.\n\n${b.text}\n\n${COMMON}\n\nKeep your scratch scripts and notes in ${R}/scratch/${b.id}/describer/ and do not read ${R}/scratch/${b.id}/investigator/ or any other agent's folder.${NOTE(n, 'describer', b)}`,
      { label: `describe:${b.id}`, phase: 'Investigate', schema: BLIND }),
  ]).then(([proposal, blind]) => ({ proposal, blind })),
  (pair, b) => (pair && pair.proposal) ? sturdy((n) => `You are the JUDGE for batch ${b.id} (${b.title}) of a firmware naming change. An investigator proposed the changes below; an independent describer, who did not see the proposals, described the same functions. Your job is to refute what is wrong before it reaches the repository.\n\nPROCEDURE\n1. For each function: compare the investigator's role with the describer's. Where they differ, or either is vague, or the discriminator is only an enable bit shared with a sibling, re-derive the role yourself from the code (decompilation and disassembly) and write it in own_role. Where they agree, still spot-check the discriminator in the code and write own_role.\n2. Check each name: it must state the role, follow the naming and prefix rules, be unique in its firmware (grep the frozen function_renames.csv / global_variables.csv; also against the other proposals), and not claim more than the code shows.\n3. Twins: read BOTH firmwares' code and check the steps, their order, the constants and the call graph position. A similar purpose is a counterpart (prefixed name; CM848 keeps its name). For a twin give final_cm848_address.\n4. Globals: check the address, the access width behind the type (python3 ${T}/abs_refs.py), every user, the e2m record at the address, and that a new array / struct swallows or splits no named row.\n5. Enum members: check every store and compare of that value in the firmware(s) concerned, and that the new member name is unique in the enum.\n6. Verdict per element: CONFIRMED, AMENDED (give the exact final_name / final_type / final_relation / final_comment) or REFUTED (final_name = the current name; default to this when the code does not clearly support the element). Give one verdict for EVERY proposed function, CM848 function (kind cm848_function, firmware CM848), prototype (kind prototype; final_comment = the full corrected parameter list when you amend it), global and enum member, and say in 'overall' whether the investigator's skipped[] functions should stay skipped.\n\nTHE BATCH\n${b.text}\n\nTHE INVESTIGATOR'S PROPOSALS\n${JSON.stringify(pair.proposal, null, 1)}\n\nTHE INDEPENDENT DESCRIBER'S ROLES\n${pair.blind ? JSON.stringify(pair.blind, null, 1) : '(the describer returned nothing: re-derive every role yourself)'}\n\n${COMMON}\n\nKeep your scratch scripts and notes in ${R}/scratch/${b.id}/judge/.${NOTE(n, 'judge', b)}`,
    { label: `judge:${b.id}`, phase: 'Judge', schema: VERDICT }).then((v) => ({ batch: b.id, proposal: pair.proposal, blind: pair.blind, verdict: v })) : null,
)
const missing = BATCHES.filter((b) => WANTED.includes(b.id)).filter((b, i) => !results[i]).map((b) => b.id)
if (missing.length) log(`batches with no result: ${missing.join(', ')}`)
return { results: results.filter(Boolean) }
