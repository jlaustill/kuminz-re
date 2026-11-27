export const meta = {
  name: 'kuminz-naming-round-96',
  description: 'Round 96 naming (the periodic J1939 builders of both firmwares by PGN, CM550 request responders, CM550 placeholders 0x0-0x2dfff, CM848 boot kernel CMF tables): investigator + independent describer + judge per batch, restarted from notes on API errors',
  phases: [
    { title: 'Investigate', detail: 'one investigator and one blind role describer per family, in parallel' },
    { title: 'Judge', detail: 'a judge per family compares both and re-derives every disputed element' },
  ],
}

const REPO = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay'
const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r96'
const F = `${R}/frozen`
const T = '/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools'

const COMMON = `CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 96).
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
  { id: 'Q1', title: "The periodic J1939 broadcast builders of both firmwares, paired by PGN", text: `Both firmwares start their periodic J1939 broadcasts with 19 calls of scheduleJ1939PeriodicMessage(queue, PGN key, interval ms, first-send offset ms, builder) (CM550 0x1fe84 in mc68k_initializeJ1939Datalink, CM848 0x538c8c in cm848_j1939_system_init; both prototypes were typed in round 95). The builder argument is the function the periodic transmit code calls when the message is due. Pairing the calls by PGN (queue / PGN / interval / offset / CM550 builder / CM848 builder):
ENGINE 65265 100 0x46 j1939HandlePgn65265CruiseVehicleSpeed / cm848_buildPgn65265CruiseControlVehicleSpeedMessage
ENGINE 61444 0x14 0 sendPgn61444ElectronicEngineController1Message / the same (a twin)
ENGINE 61443 0x32 (CM848 0x14) 10 j1939HandlePgn61443Eec2 / cm848_buildPgn61443ElectronicEngineController2Message
ENGINE 65247 0xfa (CM848 0x32) 0x1e vp44_configParamCanBuilder / cm848_buildPgn65247ElectronicEngineController3Message
ENGINE 65251 5000 0x6e sendPgn65251EngineConfiguration1Message / the same (a twin)
RETARDER 61440 100 0x32 cm550_dutyCycleMonitorAltIsrHandler / cm848_buildPgn61440ElectronicRetarderController1Message
ENGINE 65266 100 0x5a cm550_fuelEconomyDataBuilder / (CM848 schedules 65241 cm848_buildPgn65241AuxiliaryInputOutputStatus1Message instead)
RETARDER 65249 5000 0x12d vp44CanMessage100ResponseBuilder / cm848_buildPgn65249RetarderConfigurationMessage
ENGINE 65262 1000 0x1ae cm550_buildPgn65262EngineTemperature1Message / cm848_buildPgn65262EngineTemperature1Message
ENGINE 65252 1000 0x6e cm550_buildPgn65252ShutdownMessage / (none)
ENGINE 65263 / 65264 / 65269 / 65270: cm550_buildPgn6526xxx... / cm848_buildPgn6526xxx... (named in round 95)
ENGINE 65271 1000 0xd2 cm550_retarderDataBuilder / cm848_j1939HandlePgn65271VehicleElectrical
ENGINE 65504 200 0xfa (CM848 only) cm848_j1939HandlePgn65504ProprietaryB
ENGINE 65226 1000 500 &LAB_0003229a (CM550: NO function yet) / cm848_processDm1FaultBroadcast
ENGINE 65213 1000 0x32 &LAB_000339fe (no function yet) / cm848_buildPgn65213FanDrive1Message
ENGINE 61441 100 0x14 &LAB_00032bbc (no function yet) / cm848_j1939BuildEngineControlByte
ENGINE 65279 10000 0x28 &LAB_00034496 (no function yet) / cm848_sendPgn65279WaterInFuelIndicatorMessage
YOUR TASK: for every builder of both firmwares, read its code and confirm what it builds and sends (the PGN's payload: use the j1939 Mongo PGN / SPN definitions through the j1939-lookup skill to name each byte it fills), then name it: <firmware prefix>_buildPgn<N><MessageName>Message for a builder that fills a payload (or send... when it also calls the send function and the repository already uses that word for the pair; follow the existing CM848 names), with the J1939-71 message name spelled out (ElectronicRetarderController1, VehicleElectricalPower1, ...). A builder whose code is identical in both firmwares is a twin and shares one unprefixed name (both rows renamed); otherwise each keeps its firmware prefix. Wrong names to correct include the "Handle" builders (they handle no received message), cm550_dutyCycleMonitorAltIsrHandler, vp44_configParamCanBuilder, vp44CanMessage100ResponseBuilder, cm550_retarderDataBuilder, cm550_fuelEconomyDataBuilder and cm848_j1939BuildEngineControlByte. The four CM550 builders with no function (0x3229a / 0x339fe / 0x32bbc / 0x34496) need a function row: give them in functions[] with current_name '' and say where each one ends (its rts) and that nothing else enters it. Name the payload / status / descriptor globals the builders own when the code and the PGN definition prove them (globals[] with the firmware).`},
  { id: 'Q2', title: "CM550's PGN 59904 request responders and the J1939 receive / request code 0x2ec50-0x2fbb2", text: `Round 95's N1 judge left these leads: cm550_diagnosticDataDump (0x2f538) is the request-responder registration list; 0x2f47e registers a PGN 59904 request responder (32 entries of 6 bytes at 0x801d5a: a PGN word and a function pointer; the count word at 0x801e1a) and 0x2f4be dispatches the requests; neither 0x2f47e nor the table has a row. The CM550 placeholders in this area are 0x2ec50 cm550_FUN_0002ec50; 0x2ed62 cm550_FUN_0002ed62; 0x2ef4a cm550_FUN_0002ef4a (it reads the byte 0x801d3c, eight bytes before j1939_powertrain_messages_received); 0x2f4be cm550_FUN_0002f4be; 0x2f606 cm550_FUN_0002f606; 0x2faa4 cm550_FUN_0002faa4; 0x2fbb2 cm550_FUN_0002fbb2.
YOUR TASK: name the registrar, the dispatcher, the registration list and every responder they register (each answers a request for one PGN: name it from the PGN with the j1939-lookup skill and from what it sends), the table and its count (a struct for the 6-byte entry if the code proves it: give its fields in notes with offsets / types / sizes), and the placeholders above. Find CM848's counterparts: CM848 registers its request responders too (the cm848_initialize...Handler functions, e.g. cm848_initializePgn65234Dm10Handler, and a PGN 59904 request dispatcher); twins share one unprefixed name. A function row is needed for any responder that has none (functions[] with current_name '').`},
  { id: 'Q3', title: "CM550's placeholders in 0x10000-0x1ffff", text: `These CM550 functions still carry the decompiler's placeholder name. Name each one from its code, as the earlier batches did (role, discriminator, relation to CM848, plate comment, evidence):
0x10e06 cm550_FUN_00010e06; 0x1266e mc68k_FUN_0001266e; 0x127c2 vp44_FUN_000127c2; 0x133fc cm550_FUN_000133fc; 0x133fe vp44_FUN_000133fe; 0x142d4 cm550_FUN_000142d4; 0x14348 cm550_FUN_00014348; 0x14812 cm550_FUN_00014812; 0x17baa cm550_FUN_00017baa; 0x183cc cm550_FUN_000183cc (round 95: it caps the five torque curve fueling points by the fault derate limit at each point's speed); 0x184c6 cm550_FUN_000184c6; 0x185f0 cm550_FUN_000185f0; 0x192e0 cm550_FUN_000192e0; 0x19702 cm550_FUN_00019702; 0x19caa mc68k_FUN_00019caa; 0x19e8e cm550_FUN_00019e8e; 0x1a298 cm550_FUN_0001a298; 0x1a350 mc68k_FUN_0001a350; 0x1a47c mc68k_FUN_0001a47c; 0x1a52a cm550_FUN_0001a52a; 0x1a89a cm550_FUN_0001a89a; 0x1a8a2 cm550_FUN_0001a8a2; 0x1b1ea mc68k_FUN_0001b1ea; 0x1b30a mc68k_FUN_0001b30a; 0x1b4b2 mc68k_FUN_0001b4b2; 0x1c7a8 cm550_FUN_0001c7a8; 0x1c824 cm550_FUN_0001c824; 0x1c8a0 cm550_FUN_0001c8a0; 0x1cad6 vp44_FUN_0001cad6; 0x1cb3c vp44_FUN_0001cb3c; 0x1cb48 cm550_FUN_0001cb48; 0x1cdf8 cm550_FUN_0001cdf8; 0x1dbd8 cm550_FUN_0001dbd8; 0x1ddb4 cm550_FUN_0001ddb4; 0x1de58 cm550_FUN_0001de58; 0x1e04c cm550_FUN_0001e04c; 0x1f4e8 cm550_FUN_0001f4e8.
A vp44_ / mc68k_ prefix is right only for code that handles the VP44 pump / a generic 68k or MC68336 driver; check it. Name the globals these functions own where the code and the e2m record prove them.`},
  { id: 'Q4', title: "CM550's other placeholders (0x0-0xffff and 0x20000-0x2dfff)", text: `These CM550 functions still carry the decompiler's placeholder name. Name each one from its code, as the earlier batches did (role, discriminator, relation to CM848, plate comment, evidence):
0xb3d0 cm550_FUN_0000b3d0; 0xc87c cm550_FUN_0000c87c; 0xc87e cm550_FUN_0000c87e; 0xc880 cm550_FUN_0000c880; 0xd3b2 cm550_FUN_0000d3b2; 0xd4ae cm550_FUN_0000d4ae; 0xf716 cm550_FUN_0000f716; 0xf99a cm550_FUN_0000f99a; 0xf99c cm550_FUN_0000f99c; 0xfa68 vp44_FUN_0000fa68; 0xff48 cm550_FUN_0000ff48; 0x22530 cm550_FUN_00022530; 0x2257c cm550_FUN_0002257c; 0x225e0 cm550_FUN_000225e0; 0x22646 cm550_FUN_00022646; 0x2268e cm550_FUN_0002268e; 0x226da cm550_FUN_000226da; 0x24804 cm550_FUN_00024804; 0x25806 cm550_FUN_00025806; 0x25a34 vp44_FUN_00025a34; 0x26616 cm550_FUN_00026616; 0x26b3a cm550_FUN_00026b3a; 0x26b82 cm550_FUN_00026b82; 0x26e86 cm550_FUN_00026e86; 0x26e8e cm550_FUN_00026e8e; 0x277e6 cm550_FUN_000277e6; 0x27c20 vp44_FUN_00027c20; 0x2cf52 cm550_FUN_0002cf52; 0x2cf7e cm550_FUN_0002cf7e; 0x2ddbc cm550_FUN_0002ddbc.
A vp44_ prefix is right only for code that handles the VP44 pump; check it. Name the globals these functions own where the code and the e2m record prove them.`},
  { id: 'Q5', title: "CM848's time-shared boot kernel RAM 0x3fdba4-0x3fdc38", text: `RAM 0x3fdba4-0x3fdc38 holds the boot reflash kernel's CMF (flash) erase / program parameters during boot and reflash (mpc555_cmfEraseBlocks 0x49d0, mpc555_cmfSelectBlockAndStartSequence / mpc555_cmfLoadProgramPage / mpc555_cmfApplyHighVoltagePulse / mpc555_cmfEndHighVoltagePulse / mpc555_cmfRestoreNormalMode 0x4320-0x46dc; mpc555_initHardwareConfig 0x1454 fills them), but some of the same addresses are read by application code at run time (firmware/CLAUDE.md names 0x3fdba4 / 0x3fdba8 / 0x3fdbb2 / 0x3fdbd1 / 0x3fdbd2 / 0x3fdbdc / 0x3fdbfe). Many rows there carry QADC names (qadc_control_word_cal / qadc_channel_config_mask_c ... / qadc_queue_timing_config ...) that look wrong: the boot code writes per-step CMFTST / CMFCTL values (0xc20, 0xd20 ... and 0x4f0000 / 0xf0000) into them.
YOUR TASK: for every row in 0x3fdba4-0x3fdc38, find its boot users and its application users (caller >= 0x7f60 in ROM or flash2; a name grep misses users that reach it through a base register: scan the disassembly). Boot-only rows take a name from their CMF role (the MPC555 CMF registers: CMFMCR / CMFTST / CMFCTL; the erase / program step tables, their counts and timings) and a type that fits (word[N] / dword[N] tables where the code indexes them). Dual-use rows keep an application-side name but it must be right for the application use (fix it if not) and their comment must document both roles. _cal only where the row lies in the EEPROM mirror 0x3fd482-0x3feec1 AND the application reads it as an EEPROM value (0x3fdba4-0x3fdc38 is inside the mirror range: check whether the application load covers it). Give each row as a globals[] element with firmware CM848.`},
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
