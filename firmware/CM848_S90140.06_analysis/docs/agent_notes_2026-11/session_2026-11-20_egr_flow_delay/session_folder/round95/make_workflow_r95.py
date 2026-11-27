"""Round 95 tooling: derive the round 95 workflow from round 94's leads workflow (the same investigator / independent
describer / judge prompts, schemas and sturdy() restarts) with:
- R = the round 95 folder (scratch under r95/scratch/<batch>/<role>/, frozen copies in r95/frozen, HEAD de1d93d8);
- three batches: N1 (CM550 placeholder functions 0x30000-0x34fff), N2 (CM550's 1-D lookup records), N3 (prototypes
  and the round 94 leads);
- a prototype element: PROPOSAL.prototypes[] and VERDICT kind 'prototype' (a function_definitions.csv row set).
usage: make_workflow_r95.py <leads_workflow_r94.js> <out.js>"""
import sys

src, out = sys.argv[1], sys.argv[2]
s = open(src).read()


def rep(old, new, count=1):
    global s
    assert s.count(old) == count, (old[:80], s.count(old))
    s = s.replace(old, new)


rep("name: 'kuminz-naming-leads-round-94',", "name: 'kuminz-naming-round-95',")
rep("description: 'Round 94 naming leads (CM550 fuel limits, J1939 datalink, 2D lookup records, CM848 bare protection names): investigator + independent describer + judge per batch, restarted from notes on API errors',",
    "description: 'Round 95 naming (CM550 placeholder functions 0x30000-0x34fff, CM550 1-D lookup records, prototypes and leads): investigator + independent describer + judge per batch, restarted from notes on API errors',")
rep("const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94'", "const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r95'")
rep("CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 94).",
    "CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 95).")
start = s.index("const BATCHES = [")
end = s.index("\n]\n", start) + 3
BATCHES = r"""const BATCHES = [
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
"""
s = s[:start] + BATCHES + s[end:]
rep("    cm848_functions: { type: 'array', description: 'CM848-only function renames (batch L4): address = the CM848 function address', items: { type: 'object', properties: {",
    """    prototypes: { type: 'array', description: 'function prototypes (batch N3): one function_definitions.csv row set per function', items: { type: 'object', properties: {
      firmware: { type: 'string', enum: ['CM550', 'CM848'] },
      address: { type: 'string' },
      function_name: { type: 'string' },
      return_type: { type: 'string', description: 'the return type keyword, or void' },
      params: { type: 'array', items: { type: 'object', properties: { index: { type: 'number' }, name: { type: 'string' }, type: { type: 'string' }, comment: { type: 'string' } }, required: ['index', 'name', 'type', 'comment'] } },
      evidence: { type: 'string', description: 'the stack offsets / registers each parameter is read from, the return register and how callers use it' },
      confidence: { type: 'string', enum: ['high', 'medium', 'low'] },
    }, required: ['firmware', 'address', 'function_name', 'return_type', 'params', 'evidence', 'confidence'] } },
    cm848_functions: { type: 'array', description: 'CM848-only function renames: address = the CM848 function address', items: { type: 'object', properties: {""")
rep("      kind: { type: 'string', enum: ['function', 'global', 'enum_member', 'cm848_function'] },",
    "      kind: { type: 'string', enum: ['function', 'global', 'enum_member', 'cm848_function', 'prototype'] },")
rep("Give one verdict for EVERY proposed function, CM848 function (kind cm848_function, firmware CM848), global and enum member,",
    "Give one verdict for EVERY proposed function, CM848 function (kind cm848_function, firmware CM848), prototype (kind prototype; final_comment = the full corrected parameter list when you amend it), global and enum member,")
open(out, "w").write(s)
print("written", out, len(s))
