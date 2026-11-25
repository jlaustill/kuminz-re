export const meta = {
  name: 'kuminz-naming-leads-round-94',
  description: 'Round 94 naming leads (CM550 fuel limits, J1939 datalink, 2D lookup records, CM848 bare protection names): investigator + independent describer + judge per batch, restarted from notes on API errors',
  phases: [
    { title: 'Investigate', detail: 'one investigator and one blind role describer per family, in parallel' },
    { title: 'Judge', detail: 'a judge per family compares both and re-derives every disputed element' },
  ],
}

const REPO = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay'
const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94'
const F = `${R}/frozen`
const T = '/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools'

const COMMON = `CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 94).
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
- ESTABLISHED IN EARLIER ROUNDS (trust these names, they were verified): engine_state is ENGINE_STATE (1 STOPPED .. 8 SHUTDOWN); the fueling state words are FUELING_STATE in both firmwares (the Calterm labels are in each member's comment in enums.csv); CM550's algorithm enable words are algorithm_enable_flags_<n>_cal with bitfields whose comments quote the Calterm record of each bit (structure_definitions.csv, types algorithm_enable_flags_<n>_t / cm550_algorithm_enable_flags_<n>_t); the J1939 receive layer (registerJ1939ReceiveHandler, receivePgn<number><Name>Message handlers, j1939_input_signal_timeouts, the j1939_received_* bytes); the TSC1 path (processEngineTsc1Request, findTsc1SourceConfiguration).
- CM550's EEPROM image is RAM 0x803b0a-0x804f93 (round 94: the start-up load is 0x148a bytes), so a new CM550 global name there ends in _cal; CM848's is 0x3fd482-0x3feec1. THE CURRENT NAME OF A FUNCTION IS NOT EVIDENCE - not its words and not its prefix. Many CM550 names came from an old automatic pass (vp44SensorStatusMonitor turned out to be the idle shutdown state machine, cm550_engineRunTimeHistogramAccumulator a J1939 transmit schedule). Derive every role from the code.
- NAMING RULES: functions lowerCamelCase, globals lower_snake_case, enum members UPPER_SNAKE_CASE with the enum's prefix. Spell every word out: no invented abbreviations or initialisms (universal ones are fine: RPM, J1939, J1922, J1587, PGN, SPN, TSC1, DM1, DTC, ECM, EEPROM, RAM, ROM, CAN, PWM, ADC, ID, VP44, PTO is NOT fine - write powerTakeOff). Write initialize, never init. Never the bare word "protection": say protection of what. Numbers in names are decimal (PGN 65265, state 17), never hex. Name what the code DOES (a verb phrase for a function) from its own code and its users; put the major concept first where the repository does (see the neighbours). _cal only on values inside CM550's EEPROM mirror 0x803B0A-0x804155 (CM848: 0x3fd482-0x3feec1).
- PREFIX / TWIN RULE: a CM550 function with a CM848 TWIN takes ONE shared unprefixed name in both firmwares (both rows change). A twin needs proof: the same steps in the same order, the same constants and the same position in the call graph - a similar purpose is not enough. A function with a CM848 COUNTERPART (same role, different code) or with none takes a prefix: vp44_ (it handles the VP44 pump or its messages), mc68k_ (it accesses MC68336 registers or chip-select devices), else cm550_. CM848-only names use cm848_ / mpc555_ / hpcr_. When CM848 already has an unprefixed name for the twin, use that name.
- A NAME NEEDS A DISCRIMINATOR: an enable bit or a shared global proves the subsystem, not the role. Several functions here read the same bit. Each name must rest on what THIS body does that its siblings do not (which input, which output, which step). If the code does not show that, do not name the function: skip it and say what is missing.
- New names must be unique within their firmware (grep function_renames.csv / global_variables.csv) and must not collide with another proposal.
- GHIDRA NOTES: in x._38_2_ the offset 38 is DECIMAL bytes. '(ushort)algorithm_enable_flags_<n>_cal & 0x200' is a masked read of a bitfield word: look the bit up in the type. '_name' with a leading underscore is the row 'name' read wider than its type. DAT_/_DAT_ are unnamed addresses.`

const BATCHES = [
  { id: 'L1', title: "CM550's fuel limit leads: the torque limit to fuel conversion, the hour meter load, the engine warmup protection machine, the throttle fueling writer, and the HIGH_RPM_PROTECTION enums (both firmwares)", text: `Leads left by the round 93 / 94 judges (each one is a lead, not a result: prove or refute it from the code).
CM550 functions (address, current name, the lead):
- 0x1c0d4 cm550_FUN_0001c0d4: the torque limit to fuel conversion - like CM848 0x1e4e8 (cm848_calculateProtectionRateLimited), but CM848 resets the limit in the caller. Decide twin / counterpart from both bodies.
- 0x1c308 cm550_FUN_0001c308: the start-up initializer of that limit.
- 0x3452a cm550_FUN_0003452a: like CM848 cm848_loadHourMetersFromEeprom (0x5067bc).
- 0x16dd4 cm550_highRpmEngineProtectionStateMachine: the lead says it is the engine warmup protection state machine (CM550 has FUELING_STATE_ENGINE_WARMUP_PROTECTION = 33, stored by cm550_applyEngineWarmupProtectionFuelLimit 0x17120).
- 0x1709e cm550_fuelTemperatureLimitingSecondary: the lead says it is that state machine's initializer.
- 0x1cc72 cm550_FUN_0001cc72: writes throttle_100_fueling and throttle_100_fueling_low_horsepower_curve (e2m 105A FSMXTHFL / FST0MXFL); cm550_updateElectronicSmartPowerTau reads the second.
Enums: HIGH_RPM_PROTECTION_STATE and HIGH_RPM_PROTECTION_FLAGS (enums.csv of BOTH firmwares): the lead says they are leftovers whose FLAGS masks are the J1587 PID 71 idle shutdown status byte at CM550 0xefa2. Check every user of each enum (the globals typed with it, the compares and stores of its values) in both firmwares; propose the right enum member names (enum_members[]) or say in notes that the enum should go and which rows use it.
Globals: name the globals these functions own (the limits, timers, state words) where the code and the e2m record prove them.`},
  { id: 'L2', title: "CM550's J1939 / J1587 datalink leads: the periodic message scheduler, the TSC1 message bytes, the PGN 65252 shutdown builders, the fault processing enable word and the 2D lookups of 0x269f2", text: `Leads left by the round 93 / 94 judges (prove or refute each from the code).
CM550 functions (address, current name, the lead):
- 0x1fe84 (no function_renames.csv row, renders FUN_0001fe84): mc68k_initializeJ1939Datalink reaches it through movea.l #0x1fe84,a4 (the operand at 0x28b8c); the lead says it is the counterpart of CM848 cm848_scheduleJ1939PeriodicMessage (0x538c8c). Name it (a new function row) if the code proves it.
- 0x33d38 (no row): the lead says it is the PGN 65252 Shutdown payload builder (PGN 65252 byte 1 = the idle shutdown state mapping 0:00 1:40 2:44 3:unchanged 4:10 5:01).
- 0x33dfa vp44_engineHoursPGN_65252_Builder: the lead says the name is wrong. Derive what it builds.
- The two cm550_tableLookup2D argument records that the removed can_buffer_setup_t had covered are typed and named already (round 94 stage C, from the Calterm tables their pointers point at): maximum_torque_map_lookup (0x801a94: e2m MTTQMPXA / MTTQMPYA / MTTQMPZA, maximum torque by engine speed and alpha) and injection_timing_misfire_limit_lookup (0x801aaa: BSTABSXA / BSTAESYA / BSTATBZA, the minimum advance for misfire). Name the four functions around them from what they do with the result: 0x269f2 cm550_FUN_000269f2 (looks up maximum_torque_map_lookup), 0x26a2e cm550_FUN_00026a2e (fills it), cm550_fuelDemandTablePointersInit (fills injection_timing_misfire_limit_lookup) and cm550_rpmLoadParameterLookup (looks it up; the round 93 judge of F1 saw it store the misfire timing limit used by cm550_applyMisfireTimingLimit).
Globals:
- 0x801d44 / 0x801d48 (tsc1_message_*): the lead says they are the ETC1 bytes that 0x2efd0 (the ETC1 handler) stores. Rename them from the code.
- 0x806abe fault_confirm_status_word_1: the lead says it is word 1 of e2m DGFUIDEN, the fault processing enable bitmap (not confirm bits). Check the whole DGFUIDEN record (its length, the other words, their rows).`},
  { id: 'L3', title: "CM550's cm550_tableLookup2D argument records and the duty cycle monitor axis tables", text: `cm550_tableLookup2D (0x35088) takes one argument: a pointer to a 22-byte RAM record, now the struct table_lookup_2d_arguments_t (structure_definitions.csv): x_axis_offset word +0 (cached, written back), x_axis_pointer word* +2, x_input word +6, y_axis_offset word +8, y_axis_pointer word* +0xa, y_input word +0xe, z_values_pointer word* +0x10, no_interpolation_flag word +0x14. Two records are typed already (0x800010 duty_cycle_monitor_steady_state_fueling_lookup, 0x800026 duty_cycle_monitor_transient_fueling_lookup); about twenty more are passed to it (pea / move.l #addr,-(a7) before each jsr 0x35088).
YOUR TASK (globals[] only; functions[] may stay empty): find EVERY call of cm550_tableLookup2D (the decompiled calls and the disassembly: callers may load the address into an address register first), list each record address, and propose for each record a global row typed table_lookup_2d_arguments_t whose name says which table it looks up. Name a record from the Calterm records of the tables its pointers point at (the RAM dump in the frozen folder's sibling ${REPO}/firmware/CM550_J90350.00_analysis/firmware/ holds the pointer values - check the file names there; e2m_block_addresses.py --address gives the e2m record at a table address) and from what the caller does with the result. List in each record's comment every live row that lies inside it (they must be removed: give their addresses and names). Records at 0x800010 / 0x800026 / 0x801a94 / 0x801aaa are typed and named already: skip them.
Also: the duty cycle monitor's axis tables. 0x807d1e (e2m DCMNESTB: a byte count word of 18 + 9 engine speed values) and 0x807d32 (DCMNLDTB: byte count 14 + 7 load values) are whole tables; the live rows 0x807d20, 0x807d2c, 0x807d2e, 0x807d30 and 0x807d34-0x807d40 lie inside them (only 0x807d20 / 0x807d34 / 0x807d40 are referenced; 0x807d40 is the 7th load value 10000). The lead proposes duty_cycle_monitor_engine_speed_axis word[10] at 0x807d1e and duty_cycle_monitor_load_axis word[8] at 0x807d32. Prove or amend that (sizes from the byte count words in the dump, every reader), and list the rows inside.`},
  { id: 'L4', title: "CM848's functions named with a bare 'protection' (protection of WHAT?) and CM848 0x50e000", text: `CM848 ONLY: these are CM848 function renames. Put each one in cm848_functions[] (not functions[]). The user's rule: never name 'protection' bare - always protection of WHAT (engine speed / coolant / oil / load / turbocharger ...); and new names write 'initialize', never 'init'. Many CM848 'protection' names came from an old automatic pass (the 0x2e17c-0x2f6a0 'engine load protection' cluster turned out to be the VGT position servo). Derive each role from the code, the globals it reads and writes (their e2m records: python3 ${REPO}/firmware/scripts/e2m_block_addresses.py --address 0x...) and its callers.
CM848 functions (address, current name):
- 0x0000bb68 cm848_periodicTaskSet_protection, 0x0000bce8 cm848_periodicTaskSet_protection2, 0x0000beb4 cm848_periodicTaskSet_protection3, 0x0000c050 hpcr_periodicTaskSet_protection4 (task sets: name them by their schedule slot like their siblings if their callees do not share one role - read how the neighbouring periodic task sets are named in the frozen function_renames.csv)
- 0x0001e4e8 cm848_calculateProtectionRateLimited (the lead: the torque limit to fuel conversion; CM550's 0x1c0d4 is like it - batch L1 decides that relation, you name the CM848 side)
- 0x0001ea6c cm848_initProtectionTableSizes
- 0x00020b84 cm848_updateProtectionParameters
- 0x00020bfc cm848_updateProtectionInputs
- 0x00021c3c cm848_updateProtectionThresholdsIfLow
- 0x00023a9c cm848_initGovernorProtectionState
- 0x00029e24 cm848_initProtectionFilterAccumulators
- 0x0002c100 cm848_initProtectionLimitVariables
- 0x00038a98 cm848_initProtectionFilterLimits
- 0x0003eccc cm848_setThermalProtectionMode5
- 0x0004280c cm848_processProtectionLimits (the lead: it runs a fuel limit chain; CM550's counterpart is cm550_runFuelLimitChains 0x30c3c)
- 0x0004eeb8 hpcr_initProtectionAndOutputCycle
- 0x0050e000 cm848_validateFuelDemandRelativeToTiming (the lead: it computes engine_load_low_horsepower_curve_percent, so cm848_calculateEngineLoadLowHorsepowerCurvePercent fits; CM550's counterpart is cm550_calculateEngineLoadLowHorsepowerCurvePercent 0x26e2c)
Keep a CM848 prefix (cm848_ / mpc555_ / hpcr_ as the code warrants) on each new name; a CM848 function with a CM550 twin keeps the shared unprefixed name only when you prove the twin (then say so in its evidence). Also propose globals[] (firmware CM848) for the 'protection_*' globals these functions own when the code and the e2m record prove a better name.`},
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
    cm848_functions: { type: 'array', description: 'CM848-only function renames (batch L4): address = the CM848 function address', items: { type: 'object', properties: {
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
      kind: { type: 'string', enum: ['function', 'global', 'enum_member', 'cm848_function'] },
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
    () => GIVEN(b).proposal ? Promise.resolve(GIVEN(b).proposal) : sturdy((n) => `You are the INVESTIGATOR for batch ${b.id} (${b.title}).\n\n${b.text}\n\n${COMMON}\n\nYOUR OUTPUT: every function listed for this batch appears exactly once, in functions[] (with a proposed name, even when the current name is right - then proposed_name = current_name) or in skipped[] (not enough evidence: say what is missing). Fill role and discriminator from the code before you choose a name. Decide twin / counterpart / standalone for each function by reading the CM848 code. Add globals[] and enum_members[] where the code proves them. Give exact, applicable values and the evidence for each. Leave out anything the code does not support. Keep your scratch scripts and notes in ${R}/scratch/${b.id}/investigator/.${NOTE(n, 'investigator', b)}`,
      { label: `investigate:${b.id}`, phase: 'Investigate', schema: PROPOSAL }),
    () => GIVEN(b).blind ? Promise.resolve(GIVEN(b).blind) : sturdy((n) => `You are an INDEPENDENT DESCRIBER for batch ${b.id} (${b.title}). Another agent is naming these functions; you will not see its work, and a judge will compare your descriptions with its proposals. Read the code of each function below (decompilation, and the disassembly where the decompilation is unclear) and say what each one does, what distinguishes it from its siblings, and which CM848 function does the same job (twin, counterpart or none).${b.id === 'F1' ? ' Also give, in enum_roles[], the meaning of each unidentified FUELING_STATE member the code lets you prove (which function stores or tests it, with which limit).' : ''} Describe only what the code shows; write an empty suggested_name when the code does not support a name.\n\n${b.text}\n\n${COMMON}\n\nKeep your scratch scripts and notes in ${R}/scratch/${b.id}/describer/ and do not read ${R}/scratch/${b.id}/investigator/ or any other agent's folder.${NOTE(n, 'describer', b)}`,
      { label: `describe:${b.id}`, phase: 'Investigate', schema: BLIND }),
  ]).then(([proposal, blind]) => ({ proposal, blind })),
  (pair, b) => (pair && pair.proposal) ? sturdy((n) => `You are the JUDGE for batch ${b.id} (${b.title}) of a firmware naming change. An investigator proposed the changes below; an independent describer, who did not see the proposals, described the same functions. Your job is to refute what is wrong before it reaches the repository.\n\nPROCEDURE\n1. For each function: compare the investigator's role with the describer's. Where they differ, or either is vague, or the discriminator is only an enable bit shared with a sibling, re-derive the role yourself from the code (decompilation and disassembly) and write it in own_role. Where they agree, still spot-check the discriminator in the code and write own_role.\n2. Check each name: it must state the role, follow the naming and prefix rules, be unique in its firmware (grep the frozen function_renames.csv / global_variables.csv; also against the other proposals), and not claim more than the code shows.\n3. Twins: read BOTH firmwares' code and check the steps, their order, the constants and the call graph position. A similar purpose is a counterpart (prefixed name; CM848 keeps its name). For a twin give final_cm848_address.\n4. Globals: check the address, the access width behind the type (python3 ${T}/abs_refs.py), every user, the e2m record at the address, and that a new array / struct swallows or splits no named row.\n5. Enum members: check every store and compare of that value in the firmware(s) concerned, and that the new member name is unique in the enum.\n6. Verdict per element: CONFIRMED, AMENDED (give the exact final_name / final_type / final_relation / final_comment) or REFUTED (final_name = the current name; default to this when the code does not clearly support the element). Give one verdict for EVERY proposed function, CM848 function (kind cm848_function, firmware CM848), global and enum member, and say in 'overall' whether the investigator's skipped[] functions should stay skipped.\n\nTHE BATCH\n${b.text}\n\nTHE INVESTIGATOR'S PROPOSALS\n${JSON.stringify(pair.proposal, null, 1)}\n\nTHE INDEPENDENT DESCRIBER'S ROLES\n${pair.blind ? JSON.stringify(pair.blind, null, 1) : '(the describer returned nothing: re-derive every role yourself)'}\n\n${COMMON}\n\nKeep your scratch scripts and notes in ${R}/scratch/${b.id}/judge/.${NOTE(n, 'judge', b)}`,
    { label: `judge:${b.id}`, phase: 'Judge', schema: VERDICT }).then((v) => ({ batch: b.id, proposal: pair.proposal, blind: pair.blind, verdict: v })) : null,
)
const missing = BATCHES.filter((b) => WANTED.includes(b.id)).filter((b, i) => !results[i]).map((b) => b.id)
if (missing.length) log(`batches with no result: ${missing.join(', ')}`)
return { results: results.filter(Boolean) }
