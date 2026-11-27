export const meta = {
  name: 'kuminz-naming-round-95',
  description: 'Round 95 naming (CM550 placeholder functions 0x30000-0x34fff, CM550 1-D lookup records, prototypes and leads): investigator + independent describer + judge per batch, restarted from notes on API errors',
  phases: [
    { title: 'Investigate', detail: 'one investigator and one blind role describer per family, in parallel' },
    { title: 'Judge', detail: 'a judge per family compares both and re-derives every disputed element' },
  ],
}

const REPO = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay'
const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r95'
const F = `${R}/frozen`
const T = '/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools'

const COMMON = `CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 95).
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
  { id: 'N1', title: "CM550's placeholder functions in 0x30000-0x34fff", text: `These CM550 functions still carry the decompiler's placeholder name (address, current name). Name each one from its code, as the earlier batches did (role, discriminator, relation to CM848, plate comment, evidence):
0x30498 cm550_FUN_00030498; 0x306ca cm550_FUN_000306ca; 0x30a5e cm550_FUN_00030a5e; 0x30b0e cm550_FUN_00030b0e (round 93's F1 judge: a single rts with one start-up caller 0x28774 and no CM848 counterpart - name it as an empty stub if that holds); 0x31496 cm550_FUN_00031496; 0x315be cm550_FUN_000315be; 0x31a68 cm550_FUN_00031a68; 0x31bce cm550_FUN_00031bce; 0x31ed2 cm550_FUN_00031ed2; 0x32052 cm550_FUN_00032052; 0x32c22 vp44_FUN_00032c22; 0x33164 vp44_FUN_00033164; 0x333d6 cm550_FUN_000333d6; 0x33460 cm550_FUN_00033460; 0x334ec cm550_FUN_000334ec; 0x3366a cm550_FUN_0003366a; 0x33716 cm550_FUN_00033716; 0x33754 cm550_FUN_00033754; 0x337c4 cm550_FUN_000337c4; 0x33a1e cm550_FUN_00033a1e; 0x33a62 cm550_FUN_00033a62; 0x33e58 cm550_FUN_00033e58; 0x33f5a cm550_FUN_00033f5a; 0x341e6 cm550_FUN_000341e6; 0x34232 cm550_FUN_00034232; 0x34394 cm550_FUN_00034394; 0x34440 cm550_FUN_00034440; 0x344ce vp44_FUN_000344ce; 0x34d52 vp44_FUN_00034d52.
Their neighbours in this range are named (0x30bf6 applyFuelSystemDerateFuelLimit, 0x30c3c cm550_runFuelLimitChains, 0x33d38 cm550_buildPgn65252ShutdownMessage, 0x3452a loadHourMetersFromEeprom, 0x34de0 lookupTableInterpolation ...): read them for context. A vp44_ prefix is right only for code that handles the VP44 pump; check it. Name the globals these functions own where the code and the e2m record prove them.`},
  { id: 'N2', title: "CM550's 1-D lookup argument records (lookupTableInterpolation, 0x34de0)", text: `lookupTableInterpolation (0x34de0) takes one argument: a pointer to a RAM record typed table_interp_args_t in structure_definitions.csv (current_index word +0, x_axis_ptr dword +2, input_value word +6, y_axis_ptr dword +8: 12 bytes). abs_refs finds 44 jsr (0x34de0).l references and the decompilation 53 calls (some callers load 0x34de0 into an address register first). No global row is typed with the struct yet.
YOUR TASK:
1. Read 0x34de0's code and confirm or correct the record layout (offsets, widths, which fields it writes back, the axis / values table formats). Propose a spelled-out struct for it in notes: the type name table_lookup_1d_arguments_t (it pairs with table_lookup_2d_arguments_t, the argument record of cm550_tableLookup2D 0x35088: x_axis_offset / x_axis_pointer / x_input / y_axis_offset / y_axis_pointer / y_input / z_values_pointer / no_interpolation_flag) and fields named the same way, with their exact offsets, types and sizes. Also say whether CM550's lookupTableInterpolation shares its unprefixed name with a true CM848 twin (CM848's lookupTableInterpolation 0x55ef4 takes five register arguments) or should be cm550_lookupTableInterpolation (a counterpart), and give that as a functions[] element.
2. Find EVERY call of 0x34de0 (the decompiled calls and the disassembly) and every record address; propose one globals[] row per record, typed table_lookup_1d_arguments_t (that is the type the apply will create), named from the Calterm records of the tables its pointers point at (the RAM dump ${REPO}/firmware/CM550_J90350.00_analysis/firmware/J90350.00.ram.bin holds the pointers; e2m_block_addresses.py --address gives the record at a table address) and from what the caller does with the result. List in each record's comment every live row that lies inside it (they will be removed: give addresses and names).
3. Name the tables the records point at when they have no row (word[N] from the byte count word; the repository's table names are <base>_axis / <base>_values for 1-D tables).`},
  { id: 'N3', title: "Prototypes and the round 94 leads", text: `Leads left by the round 94 judges (prove or refute each from the code).
PROTOTYPES (put each in prototypes[]: the full parameter list in order with names and types, and the return type; CM550's stack_parameter_layout places every parameter from its row - check the stack offsets each body reads; CM848 parameters are r3-r10):
- CM550 0x1fe84 scheduleJ1939PeriodicMessage (round 94's L2 judge: queue dword, PGN word, interval_milliseconds word, first_send_offset_milliseconds word, builder pointer; returns a byte). It is the twin of CM848 0x538c8c (same name): give CM848's prototype too when its code supports one.
- CM550 0x35088 cm550_tableLookup2D: its function_definitions row says (short* table_args) under an old name; the parameter is a table_lookup_2d_arguments_t* (the struct exists); the decompilation shows an undefined8 return built with CONCAT44 - find what it really returns (d0 word?) and how the callers use it.
GLOBALS / STRUCTS:
- CM550 0x80dc98 j1708_transmit_buffer_2_32_dc98 and 0x80dca2 j1708_receive_buffer_pointer_2_32_dca2: hex in the names; find what they are (their users) and name them.
- CM550 0x80d03e io_control_bit0_state: a dword the code adds to and subtracts from (sub.l / add.l at 0x19b22 ...); name it from its users.
- CM550 0x801d44-0x801d58 (j1939_received_pgn61442_byte_1 / _byte_5, the tsc1_accepted_* bytes ...): the bytes CM550's PGN 61442 / TSC1 receive code stores. Decide whether they form one struct (CM848 has j1939_powertrain_messages_received_t; the layout differs) and propose it (globals[] row typed with the struct; the struct's fields in notes with offsets / types / sizes).
CM848 (functions in cm848_functions[], globals with firmware CM848):
- cm848_calculateFuelDemandFilter / cm848_initFuelDemandFilterDimensions: round 94's L4 judge says they compute / initialize the maximum torque at the current engine speed (maximum_torque_at_current_engine_speed 0x40aee6).
- the uncalled leaf at 0x29ecc (after the blr at 0x29ec8: it copies main_injection_timing_copy into main_injection_timing_before_misfire_limit; nothing reaches it): name it as what it does, or say it is dead.
- the safety_* fault blend globals 0x40b31e-0x40b326.
- governor_tuning_set_blend_weight: every user is an all-speed governor function; should it take an all_speed_governor_ prefix?`},
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
    () => GIVEN(b).proposal ? Promise.resolve(GIVEN(b).proposal) : sturdy((n) => `You are the INVESTIGATOR for batch ${b.id} (${b.title}).\n\n${b.text}\n\n${COMMON}\n\nYOUR OUTPUT: every function listed for this batch appears exactly once, in functions[] (with a proposed name, even when the current name is right - then proposed_name = current_name) or in skipped[] (not enough evidence: say what is missing). Fill role and discriminator from the code before you choose a name. Decide twin / counterpart / standalone for each function by reading the CM848 code. Add globals[] and enum_members[] where the code proves them. Give exact, applicable values and the evidence for each. Leave out anything the code does not support. Keep your scratch scripts and notes in ${R}/scratch/${b.id}/investigator/.${NOTE(n, 'investigator', b)}`,
      { label: `investigate:${b.id}`, phase: 'Investigate', schema: PROPOSAL }),
    () => GIVEN(b).blind ? Promise.resolve(GIVEN(b).blind) : sturdy((n) => `You are an INDEPENDENT DESCRIBER for batch ${b.id} (${b.title}). Another agent is naming these functions; you will not see its work, and a judge will compare your descriptions with its proposals. Read the code of each function below (decompilation, and the disassembly where the decompilation is unclear) and say what each one does, what distinguishes it from its siblings, and which CM848 function does the same job (twin, counterpart or none).${b.id === 'F1' ? ' Also give, in enum_roles[], the meaning of each unidentified FUELING_STATE member the code lets you prove (which function stores or tests it, with which limit).' : ''} Describe only what the code shows; write an empty suggested_name when the code does not support a name.\n\n${b.text}\n\n${COMMON}\n\nKeep your scratch scripts and notes in ${R}/scratch/${b.id}/describer/ and do not read ${R}/scratch/${b.id}/investigator/ or any other agent's folder.${NOTE(n, 'describer', b)}`,
      { label: `describe:${b.id}`, phase: 'Investigate', schema: BLIND }),
  ]).then(([proposal, blind]) => ({ proposal, blind })),
  (pair, b) => (pair && pair.proposal) ? sturdy((n) => `You are the JUDGE for batch ${b.id} (${b.title}) of a firmware naming change. An investigator proposed the changes below; an independent describer, who did not see the proposals, described the same functions. Your job is to refute what is wrong before it reaches the repository.\n\nPROCEDURE\n1. For each function: compare the investigator's role with the describer's. Where they differ, or either is vague, or the discriminator is only an enable bit shared with a sibling, re-derive the role yourself from the code (decompilation and disassembly) and write it in own_role. Where they agree, still spot-check the discriminator in the code and write own_role.\n2. Check each name: it must state the role, follow the naming and prefix rules, be unique in its firmware (grep the frozen function_renames.csv / global_variables.csv; also against the other proposals), and not claim more than the code shows.\n3. Twins: read BOTH firmwares' code and check the steps, their order, the constants and the call graph position. A similar purpose is a counterpart (prefixed name; CM848 keeps its name). For a twin give final_cm848_address.\n4. Globals: check the address, the access width behind the type (python3 ${T}/abs_refs.py), every user, the e2m record at the address, and that a new array / struct swallows or splits no named row.\n5. Enum members: check every store and compare of that value in the firmware(s) concerned, and that the new member name is unique in the enum.\n6. Verdict per element: CONFIRMED, AMENDED (give the exact final_name / final_type / final_relation / final_comment) or REFUTED (final_name = the current name; default to this when the code does not clearly support the element). Give one verdict for EVERY proposed function, CM848 function (kind cm848_function, firmware CM848), prototype (kind prototype; final_comment = the full corrected parameter list when you amend it), global and enum member, and say in 'overall' whether the investigator's skipped[] functions should stay skipped.\n\nTHE BATCH\n${b.text}\n\nTHE INVESTIGATOR'S PROPOSALS\n${JSON.stringify(pair.proposal, null, 1)}\n\nTHE INDEPENDENT DESCRIBER'S ROLES\n${pair.blind ? JSON.stringify(pair.blind, null, 1) : '(the describer returned nothing: re-derive every role yourself)'}\n\n${COMMON}\n\nKeep your scratch scripts and notes in ${R}/scratch/${b.id}/judge/.${NOTE(n, 'judge', b)}`,
    { label: `judge:${b.id}`, phase: 'Judge', schema: VERDICT }).then((v) => ({ batch: b.id, proposal: pair.proposal, blind: pair.blind, verdict: v })) : null,
)
const missing = BATCHES.filter((b) => WANTED.includes(b.id)).filter((b, i) => !results[i]).map((b) => b.id)
if (missing.length) log(`batches with no result: ${missing.join(', ')}`)
return { results: results.filter(Boolean) }
