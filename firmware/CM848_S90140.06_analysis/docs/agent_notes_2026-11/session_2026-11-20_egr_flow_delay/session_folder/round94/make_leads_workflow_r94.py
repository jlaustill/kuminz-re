"""Round 94 tooling: derive the leads workflow from round 93's self-healing naming workflow (same investigator /
independent describer / judge prompts and schemas, same sturdy() restarts) with:
- R = the round 94 folder (scratch under r94/scratch/<batch>/<role>/), F = r94/frozen (the state after the round 94
  apply), the tools of round 93;
- four new batches, L1-L4, from the round 93 / 94 judges' leads;
- a CM848-only function list: PROPOSAL.cm848_functions[] and VERDICT kind 'cm848_function' (round 93 could rename a
  CM848 function only as the twin of a CM550 one).
usage: make_leads_workflow_r94.py <sturdy_workflow_r93.js> <out.js>"""
import sys

src, out = sys.argv[1], sys.argv[2]
s = open(src).read()


def rep(old, new, count=1):
    global s
    assert s.count(old) == count, (old[:80], s.count(old))
    s = s.replace(old, new)


rep("name: 'cm550-function-names-round-93-sturdy',", "name: 'kuminz-naming-leads-round-94',")
rep("description: 'Round 93 function naming, self-healing: agents that die on API errors are restarted from their notes (investigator + independent describer + judge per family)',",
    "description: 'Round 94 naming leads (CM550 fuel limits, J1939 datalink, 2D lookup records, CM848 bare protection names): investigator + independent describer + judge per batch, restarted from notes on API errors',")
rep("const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r93'", "const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r94'")
rep("const T = `${R}/tools`", "const T = '/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools'")
rep("CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 93).",
    "CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 94).")
# the batches
start = s.index("const BATCHES = [")
end = s.index("\n]\n", start) + 3
BATCHES = r"""const BATCHES = [
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
"""
s = s[:start] + BATCHES + s[end:]
# the CM848-only function list
rep("    notes: { type: 'string', description: 'leads for later rounds, things that did not fit, judgment calls' },\n  },\n  required: ['batch', 'summary', 'functions', 'skipped'],",
    """    cm848_functions: { type: 'array', description: 'CM848-only function renames (batch L4): address = the CM848 function address', items: { type: 'object', properties: {
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
  required: ['batch', 'summary', 'functions', 'skipped'],""")
rep("      kind: { type: 'string', enum: ['function', 'global', 'enum_member'] },",
    "      kind: { type: 'string', enum: ['function', 'global', 'enum_member', 'cm848_function'] },")
rep("Give one verdict for EVERY proposed function, global and enum member,",
    "Give one verdict for EVERY proposed function, CM848 function (kind cm848_function, firmware CM848), global and enum member,")
rep("THE CURRENT NAME OF A FUNCTION IS NOT EVIDENCE",
    "CM550's EEPROM image is RAM 0x803b0a-0x804f93 (round 94: the start-up load is 0x148a bytes), so a new CM550 global name there ends in _cal; CM848's is 0x3fd482-0x3feec1. THE CURRENT NAME OF A FUNCTION IS NOT EVIDENCE")
open(out, "w").write(s)
print("written", out, len(s))
