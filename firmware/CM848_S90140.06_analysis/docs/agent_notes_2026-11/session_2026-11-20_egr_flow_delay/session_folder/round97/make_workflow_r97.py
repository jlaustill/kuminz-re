"""Round 97: write workflow_r97.js from round 96's script (the same schemas, retry wrapper and pipeline): new meta,
paths, batches, the round 96 facts in ESTABLISHED, rules for renaming globals, and an output instruction that covers
global-only batches. usage: make_workflow_r97.py"""
import re

SRC = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/workflow_r96.js"
DST = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/workflow_r97.js"
t = open(SRC).read()


def sub(old, new, count=1):
    global t
    assert t.count(old) == count, (old[:80], t.count(old))
    t = t.replace(old, new)


meta_end = t.index("}\n", t.index("export const meta = {")) + 2
t = """export const meta = {
  name: 'kuminz-naming-round-97',
  description: 'Round 97 naming (CM550 global families with Calterm-slug / abbreviated names - low speed, high / all speed governors, acceleration noise control, engine position, engine protection - and the round 96 judges leads): investigator + independent describer + judge per batch',
  phases: [
    { title: 'Investigate', detail: 'one investigator and one blind role describer per family, in parallel' },
    { title: 'Judge', detail: 'a judge per family compares both and re-derives every disputed element' },
  ],
}
""" + t[meta_end:]
sub("const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r96'", "const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r97'")
sub("CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 96).",
    "CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 97).")
sub("the TSC1 path (processEngineTsc1Request, findTsc1SourceConfiguration).",
    "the TSC1 path (processEngineTsc1Request, findTsc1SourceConfiguration); round 96: the periodic J1939 builders of both "
    "firmwares by PGN (cm550_build/sendPgn<number><Name>Message), registerJ1939PgnRequestHandler / registerJ1939ReceiveHandler / "
    "registerJ1939DiagnosticService with full prototypes, CM550's cylinder balancing (mc68k_fillCylinderBalanceSpeedBuffers, "
    "cm550_calculateCylinderBalanceTrims, the cylinder_balance_* arrays), the serial EEPROM write queue (eeprom_write_queue_*, "
    "cm550_queueEepromByteWrites), cm550_sendCanSingleFrame / cm550_transmitCanFrameOnMessageObject (an Intel 82527 CAN controller "
    "at 0xffd800).")
sub("- A NAME NEEDS A DISCRIMINATOR:",
    "- RENAMING GLOBALS: many CM550 global names are Calterm description slugs from an old automatic pass (the words of the e2m "
    "description, cut at a length limit, often with abbreviations, a value-range suffix such as _0_100 / _300_1000 and an address "
    "suffix such as _8246). Give each row the name of what it holds: read the code that writes and reads it (every user: "
    "python3 ${T}/abs_refs.py) and its e2m record (e2m_block_addresses.py --firmware cm550 --address 0x...: the mnemonic, description, "
    "unit and scale). When CM848 has a row for the SAME e2m record (same block and offset: e2m_block_addresses.py <block> without "
    "--firmware lists CM848's addresses and names), reuse CM848's name, changing only _cal by the memory map. Drop range and address "
    "suffixes. Keep the major concept first (low_speed_governor_..., engine_protection_...). Check the type against the access widths "
    "and correct it in proposed_type. A row whose meaning the code and the record do not settle goes to skipped[] (address, current "
    "name, what is missing).\n- A NAME NEEDS A DISCRIMINATOR:")
sub("YOUR OUTPUT: every function listed for this batch appears exactly once, in functions[] (with a proposed name, even when the "
    "current name is right - then proposed_name = current_name) or in skipped[] (not enough evidence: say what is missing).",
    "YOUR OUTPUT: every function listed for this batch appears exactly once, in functions[] (with a proposed name, even when the "
    "current name is right - then proposed_name = current_name) or in skipped[] (not enough evidence: say what is missing). In a "
    "batch that lists globals (a row file), every listed global appears exactly once, in globals[] (proposed_name = current_name "
    "when it is already right) or in skipped[] (address, current name, the reason).")
sub("Read the code of each function below (decompilation, and the disassembly where the decompilation is unclear) and say what "
    "each one does, what distinguishes it from its siblings, and which CM848 function does the same job (twin, counterpart or none).",
    "Read the code of each function below (decompilation, and the disassembly where the decompilation is unclear) and say what "
    "each one does, what distinguishes it from its siblings, and which CM848 function does the same job (twin, counterpart or none). "
    "In a batch that lists globals, give one roles[] entry per listed global as well (address = the global's address; role = what "
    "the code stores there, who writes and who reads it, and its e2m record; discriminator = how it differs from its neighbours; "
    "cm848_counterpart = the CM848 row of the same e2m record if any; suggested_name).")
start = t.index("const BATCHES = [")
end = t.index("]\n", t.index("{ id: 'Q5'")) + 2
FAM = "${R}/family_"
batches = r"""const BATCHES = [
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
"""
t = t[:start] + batches + t[end:]
open(DST, "w").write(t)
print("written", len(t))
