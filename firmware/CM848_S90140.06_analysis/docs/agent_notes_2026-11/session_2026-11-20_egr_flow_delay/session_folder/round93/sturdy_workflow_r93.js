export const meta = {
  name: 'cm550-function-names-round-93-sturdy',
  description: 'Round 93 function naming, self-healing: agents that die on API errors are restarted from their notes (investigator + independent describer + judge per family)',
  phases: [
    { title: 'Investigate', detail: 'one investigator and one blind role describer per family, in parallel' },
    { title: 'Judge', detail: 'a judge per family compares both and re-derives every disputed element' },
  ],
}

const REPO = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay'
const R = '/home/linux/.claude/jobs/374b0424/tmp/w15/r93'
const F = `${R}/frozen`
const T = `${R}/tools`

const COMMON = `CONTEXT (PR #53 of the kuminz-re Cummins ECU reverse engineering repository, round 93).
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
- THE CURRENT NAME OF A FUNCTION IS NOT EVIDENCE - not its words and not its prefix. Many CM550 names came from an old automatic pass (vp44SensorStatusMonitor turned out to be the idle shutdown state machine, cm550_engineRunTimeHistogramAccumulator a J1939 transmit schedule). Derive every role from the code.
- NAMING RULES: functions lowerCamelCase, globals lower_snake_case, enum members UPPER_SNAKE_CASE with the enum's prefix. Spell every word out: no invented abbreviations or initialisms (universal ones are fine: RPM, J1939, J1922, J1587, PGN, SPN, TSC1, DM1, DTC, ECM, EEPROM, RAM, ROM, CAN, PWM, ADC, ID, VP44, PTO is NOT fine - write powerTakeOff). Write initialize, never init. Never the bare word "protection": say protection of what. Numbers in names are decimal (PGN 65265, state 17), never hex. Name what the code DOES (a verb phrase for a function) from its own code and its users; put the major concept first where the repository does (see the neighbours). _cal only on values inside CM550's EEPROM mirror 0x803B0A-0x804155 (CM848: 0x3fd482-0x3feec1).
- PREFIX / TWIN RULE: a CM550 function with a CM848 TWIN takes ONE shared unprefixed name in both firmwares (both rows change). A twin needs proof: the same steps in the same order, the same constants and the same position in the call graph - a similar purpose is not enough. A function with a CM848 COUNTERPART (same role, different code) or with none takes a prefix: vp44_ (it handles the VP44 pump or its messages), mc68k_ (it accesses MC68336 registers or chip-select devices), else cm550_. CM848-only names use cm848_ / mpc555_ / hpcr_. When CM848 already has an unprefixed name for the twin, use that name.
- A NAME NEEDS A DISCRIMINATOR: an enable bit or a shared global proves the subsystem, not the role. Several functions here read the same bit. Each name must rest on what THIS body does that its siblings do not (which input, which output, which step). If the code does not show that, do not name the function: skip it and say what is missing.
- New names must be unique within their firmware (grep function_renames.csv / global_variables.csv) and must not collide with another proposal.
- GHIDRA NOTES: in x._38_2_ the offset 38 is DECIMAL bytes. '(ushort)algorithm_enable_flags_<n>_cal & 0x200' is a masked read of a bitfield word: look the bit up in the type. '_name' with a leading underscore is the row 'name' read wider than its type. DAT_/_DAT_ are unnamed addresses.`

const BATCHES = [
  { id: 'J1', title: "CM550's J1939 multiplexed input / override layer (0x201d6-0x211f4)", text: `The functions of this family (address, current name, code lines, callers, callees):
- 0x201d6 cm550_FUN_000201d6 (5 lines); called by: cm550_FUN_00020380, cm550_FUN_0002041c, cm550_outputControlState1Handler, cm550_FUN_00020784, cm550_FUN_00020890, cm550_FUN_00020e14, cm550_FUN_00020fac
- 0x20210 cm550_FUN_00020210 (5 lines); called by: cm550_outputControlState1Handler, cm550_FUN_00020784, cm550_FUN_00020e14
- 0x2024a cm550_FUN_0002024a (5 lines); called by: the same seven as 0x201d6
- 0x20284 cm550_FUN_00020284 (10 lines); called by: cm550_FUN_00021070, cm550_FUN_00021146
- 0x202a0 cm550_FUN_000202a0 (10 lines); called by: cm550_FUN_00021146
- 0x202bc cm550_FUN_000202bc (10 lines); called by: cm550_FUN_00021070, cm550_FUN_00021146
- 0x20310 cm550_FUN_00020310 (5 lines); called by: cm550_outputControlState1Handler, cm550_FUN_00020784, cm550_FUN_00020c98
- 0x20348 cm550_FUN_00020348 (5 lines); called by: cm550_FUN_00020380, cm550_FUN_0002041c, cm550_outputControlState1Handler, cm550_FUN_00020784, cm550_FUN_00020890, cm550_FUN_00020c98, cm550_FUN_00020fac
- 0x20380 cm550_FUN_00020380 (29 lines); called by: cm550_FUN_00021070; reads algorithm_enable_flags_13_cal.engine_retarder_switch_level_override
- 0x2041c cm550_FUN_0002041c (32 lines); called by: cm550_FUN_00021070; reads ...manual_fan_level_override
- 0x205c4 cm550_FUN_000205c4 (48 lines); called by: cm550_FUN_00020c98; reads ...j1939_multiplex_limp_home_on_analog_throttle_enable
- 0x206a8 cm550_FUN_000206a8 (28 lines); called by: cm550_FUN_00021070
- 0x20784 cm550_FUN_00020784 (42 lines); called by: cm550_FUN_00021146; reads remote_throttle_enable, remote_throttle_switch_override_enable
- 0x20890 cm550_FUN_00020890 (120 lines); called by: cm550_FUN_00021070
- 0x20c98 cm550_FUN_00020c98 (63 lines); called by: cm550_FUN_00021146; reads idle_switch_override_enable, sampled_throttle_override_enable
- 0x20e14 cm550_FUN_00020e14 (86 lines); called by: cm550_FUN_00021146; reads idle_switch_override_enable, sampled_throttle_override_enable
- 0x20fac cm550_FUN_00020fac (33 lines); called by: cm550_FUN_00021146
- 0x21070 cm550_FUN_00021070 (37 lines); called by: cm550_diagnosticMonitoringCoordinator, cm550_boostPressureControlInit
- 0x21146 cm550_FUN_00021146 (36 lines); called by: cm550_rpmBasedFuelLimiterCoordinator, cm550_sensorStatusHistorySlowCycle20Coordinator
- 0x211f4 cm550_FUN_000211f4 (5 lines); nothing calls it by name and its address is stored nowhere in the dumped ROM
Also inside this address range and already named (check the names against the family; propose a rename when one is wrong): cm550_outputControlState1Handler, setBitInArray (0x202d8).
Leads from round 92 (unverified hints): cm550_FUN_00020fac tests algorithm_enable_flags_20_cal & 0x200 before it lets the J1939 client of slot 9 (j1939_received_wet_tank_pressure) write analog_sensor_raw_override_values[0]; cm550_FUN_000206a8 and cm550_FUN_00020890 index the enable words from algorithm_enable_flags_0_cal at bit 0xd0 + switch number (word 13 onward = the switch override enables) before they store a J1939 multiplexed switch into the override value bytes 0x80bcde / 0x80bcdf; the 5-line helpers work on bit arrays around 0x800aa0. The scored CM848 candidates in firmware/cross_firmware_matches.csv for these addresses are all implausible (handleIdleSpeedControlFlag, processBoostPressureOffset, multiplyAccumulateFixed32 ...): ignore them and find CM848's J1939 multiplexing layer yourself (start from CM848's j1939_received_* bytes, j1939_input_signal_timeouts and the override value globals; CM848's e2m block 12F7 lists the J1939_Mux_* records).
Also name the family's globals that are still DAT_ / WORD_ / description-named when the code proves their role (the bit arrays, the client priority words such as _priority_of_client_overriding_raw_intake_manifold_temperature_0_ff, the per-input override values), with CM848's name where it is the same record.` },
  { id: 'J2', title: "CM550's J1939 receive dispatch, periodic transmit schedule, datalink control session history and the datalink fueling arbitration", text: `The functions of this family (address, current name, code lines, callers, callees):
- 0x1fdc0 cm550_j1939MessageTypeCounter (31 lines); called by: cm550_fuelArbitratorResetHandler, cm550_fuelDemandLimitOrchestrator; reads algorithm_enable_flags_2_cal.j1922_monitor_enable (round 92: it counts the control sessions of modes 1 / 2 / 3 with key-on hour stamps)
- 0x1ff38 cm550_engineRunTimeHistogramAccumulator (36 lines); called by: cm550_oddPhaseSchedulerTaskSet; reads ...j1939_communication_enable (round 92: a J1939 periodic transmit schedule)
- 0x212b2 mc68k_FUN_000212b2 (71 lines); nothing calls it by name; its address is stored in the ROM at 0x1b4da (round 91: the receive dispatcher that scans j1939_receive_handler_table; CM848's is cm848_dispatchJ1939ReceivedMessages)
- 0x2142c cm550_FUN_0002142c (19 lines); called by: cm550_oddPhaseSchedulerTaskSet; reads ...j1939_retarder_shift_assist_enable
- 0x216c6 cm550_FUN_000216c6 (9 lines); address stored in the ROM at 0x21888; calls cm550_j1939MemoryDataCopyResolver, cm550_memcpy
- 0x21778 cm550_FUN_00021778 (11 lines); address stored in the ROM at 0x218b8; calls cm550_j1939MemoryDataCopyResolver, cm550_memcpy
- 0x21872 cm550_FUN_00021872 (10 lines); called by: mc68k_initializeJ1939Datalink; calls registerJ1939DiagnosticService
- 0x21920 cm550_FUN_00021920 (18 lines); called by: j1939HandlePgn65226Dm1ActiveDtc, cm550_previousDtcListBuilder
- 0x21f4e cm550_diagnosticGroupPositionBufferStore (28 lines); called by: cm550_memoryRegisterController
- 0x21fac cm550_diagnosticGroupSnapshotCapture (33 lines); called by: cm550_memoryRegisterController
- 0x22070 cm550_memoryRegisterController (87 lines); address stored in the ROM at 0x1b4e6; reads ...j1939_monitor_enable (round 92: it records the J1939 speed control and retarder session history)
- 0x231da cm550_fuelArbitratorResetHandler (13 lines); called by: cm550_fuelDemandLimitOrchestrator; calls cm550_j1939MessageTypeCounter
- 0x23244 cm550_fuelDemandLimitOrchestrator (279 lines); address stored in the ROM at 0x1b4e0 (between the receive dispatcher's and 0x22070's entries); calls cm550_j1939MessageTypeCounter, cm550_fuelArbitratorResetHandler, cm550_FUN_00023216, cm550_ioControlEntryAdd, cm550_ioControlTimeoutEntryAdd
Also name cm550_FUN_00023216 and the helpers cm550_j1939MemoryDataCopyResolver / cm550_ioControlEntryAdd / cm550_ioControlTimeoutEntryAdd if their code shows the current names are wrong, and say what the ROM table at 0x1b4da-0x1b4e9 is (who walks it).
CM848 names to compare with (find more yourself): cm848_dispatchJ1939ReceivedMessages, registerJ1939ReceiveHandler, registerJ1939DiagnosticService, processEngineTsc1Request, findTsc1SourceConfiguration, the j1939_powertrain_control_state struct, the J1939 / J1922 "monitor" history records (CM848 e2m: search the labelled e2m for Monitor / JC39MR / JC22MR).
Also name the family's globals that are still DAT_ / description-named when the code proves their role (session counters, hour stamps, history buffers), with CM848's name where it is the same record; propose an array or struct type only with the layout proven from every access.` },
  { id: 'D1', title: "CM550's idle shutdown, in-range diagnostics, fault lamp sequencing, duty cycle monitor and the EEPROM write / RAM refresh loop step", text: `The functions of this family (address, current name, code lines, callers, callees):
- 0x0ac3c cm550_FUN_0000ac3c (150 lines); called by: cm550_FUN_0001b788, cm550_slowCycle8Coordinator; calls cm550_tableLookup2D; reads an enable bit duty_cycle_monitor_enable and ENGINE_STATE_STOPPED
- 0x0e998 cm550_FUN_0000e998 (78 lines); called by: cm550_FUN_0001b754; reads algorithm_enable_flags_27_cal.boost_pressure_in_range_diagnostic_enable while engine_state is RUNNING (round 92: the boost in-range high check with boost_threshold_for_bir_high_error_0_100 / time_needed_for_out_of_range_high_boost_for_setting_birh_error_0_60)
- 0x1b754 cm550_FUN_0001b754 (7 lines); called by: executiveFrameInterruptHandler; calls cm550_FUN_0000e998
- 0x1b788 cm550_FUN_0001b788 (8 lines); called by: executiveFrameInterruptHandler; calls cm550_FUN_0000ac3c, calculateSpeedRatioComponent, cm550_FUN_00026e2c
- 0x1b7f2 vp44_FUN_0001b7f2 (8 lines); called by: executiveFrameInterruptHandler; calls vp44SensorStatusMonitor
- 0x1d9b4 vp44SensorStatusMonitor (111 lines); called by: vp44_FUN_0001b7f2; reads idle_shutdown_enable, idle_shutdown_override_enable, idle_shutdown_temperature_enable, integrated_idle_management_enable (round 92: the idle shutdown state machine; its state word 0x80d674 is e2m ISST 'THE PRESENT STATE OF THE IDLE SHUTDOWN ALGORITHM' 0-5, now named vp44_sensor_monitor_state)
- 0x253b0 cm550_FUN_000253b0 (32 lines); called by: cm550_FUN_000254b6
- 0x254b6 cm550_FUN_000254b6 (34 lines); called by: cm550_dzgTimingAndPressureSlowCycle10Coordinator; calls cm550_ioControlMaskStateMachine, vp44_ioControlLampStateMachine, cm550_faultCodeDisplayController, cm550_activeFaultLampStateMachine, cm550_faultLampBlinkPatternGenerator, cm550_FUN_000253b0, cm550_periodicLampFlashController
- 0x26834 mc68k_FUN_00026834 (13 lines); called by: mc68k_FUN_00026854; calls mc68k_runSerialEepromWriteQueue
- 0x26852 cm550_FUN_00026852 (4 lines); called by: mc68k_FUN_00026854
- 0x26854 mc68k_FUN_00026854 (75 lines); called by: mc68k_applicationMain; calls mc68k_runSerialEepromWriteQueue, mc68k_FUN_00026834, cm550_FUN_00026852; reads RAM_REFRESH_ENABLED
Also: cm550_FUN_00026e2c (called by 0x1b788) and the wrappers' siblings if their role is clear. The three 7-8 line wrappers are executive frame tasks: name each from what it runs (the repository calls such wrappers <something>TaskSet / Coordinator; a wrapper around one function can take that function's name with a task suffix - look at how the named neighbours 0x1b500-0x1b880 are named and say if those names are themselves wrong).
For the idle shutdown machine: name its state word (CM848 has an idle shutdown state machine too - find it; a twin shares the name) and propose an enum for its states only if every state's meaning is proven by the code (name, value, evidence per member); name the timers / flags it uses from the e2m records at their addresses.
For 0x254b6 / 0x253b0: this is the fault lamp family; the callee names listed above were never verified - say for each whether its name fits its code, and propose renames for those that do not.` },
  { id: 'F1', title: 'the torque derate limiter chain and the unidentified FUELING_STATE members (both firmwares)', text: `CM550's FUELING_STATE enum (enums.csv) is the twin of CM848's; six members have no proven meaning and are named FUELING_STATE_UNIDENTIFIED_<n> with the Calterm label in the comment: 3 PSSPEED, 17 ANCDERAT, 18 EPF, 33 ESUOILLM, 36 PTPDERAT, 39 T2DERAT. Two more are unidentified in BOTH firmwares: 37 T2SPD and 38 T2TORQ (CM848 also has members above 41 - 42, 45, 46, 47, 49, 50, 52-55, 58, 59, 61, 62 - check whether any of them is UNIDENTIFIED too and can be named from CM848's code).
TASK A - name each unidentified member from the CODE that stores or compares that state (in CM550, and in CM848 for 37 / 38 and any other unidentified CM848 member): which limiter / governor writes it, with which limit value. Example of the evidence wanted: cm550_shutdownMinimumSelector21 stores FUELING_STATE_UNIDENTIFIED_17 into torque_derate_fuel_source_code when _anc_fuel_limit_value is below the running minimum - so 17 is the acceleration noise control derate (Calterm ANCDERAT). A member whose state no dumped code stores or tests stays UNIDENTIFIED unless the e2m records around it prove the meaning beyond doubt (say which). A member that exists in both firmwares is renamed in both (firmware: both).
TASK B - the limiter chain itself. The functions (address, current name, code lines, callers):
- 0x0b3b2 cm550_shutdownMinimumSelector21 (8 lines); called by cm550_FUN_00030c3c - it stores state 17, not 21
- 0x0b4ce cm550_fuelDemandLimitMinimumUpdater (9 lines); called by cm550_FUN_00030b34
- 0x0c2a0 cm550_shutdownMinimumSelector16 (10 lines); called by cm550_FUN_00030c3c
- 0x0c2ee cm550_FUN_0000c2ee (15 lines); called by cm550_FUN_00030b34
- 0x0c742 cm550_shutdownMinimumSelector15 (8 lines); called by cm550_FUN_00030c3c
- 0x12484 cm550_FUN_00012484 (20 lines); called by cm550_FUN_00030b34
- 0x17120 cm550_FUN_00017120 (9 lines); called by cm550_FUN_00030c3c - stores state 33 while engine_state is RUNNING and _high_rpm_fuel_limit_active is set
- 0x196e4 cm550_shutdownMinimumSelector29 (8 lines); called by cm550_FUN_00030c3c
- 0x1c152 fuelTimingOilPressureModeController (88 lines); called by cm550_periodicTaskSet_fuelTiming; calls cm550_diagnosticFuelLimitInterpolator, cm550_FUN_0001c0d4, cm550_FUN_00030c3c (round 92: it tests final_fueling_state_prev and stores final_fueling_state - it looks like the final fueling state selection, e2m FSFNFLST)
- 0x1ca54 cm550_fuelDemandLimitSelector11 (24 lines); called by periodicTaskSet_fuelDemand, vp44_evenPhaseSchedulerTaskSet (round 92: with the engine retarder active and algorithm_enable_flags_0_cal bit 0x40 set it clears the fuel shutoff output bit; it shares its body with vp44_canPinVp44StatusController 0x1ca5c)
- 0x1ce58 cm550_FUN_0001ce58 (9 lines); called by cm550_FUN_00030c3c - starts the minimum at _fueling_value_at_100_throttle_0_100 with state 19 MAXIMUM_THROTTLE and the group 2 minimum with state 40 NO_DERATE
- 0x2658c cm550_fuelDemandLimitSource2Selector (15 lines); called by mc68k_applicationMain
- 0x26af0 cm550_FUN_00026af0 (16 lines); called by cm550_FUN_00030b34; reads algorithm_enable_flags_32_cal.misfire_timing_limit_enable
- 0x2d9a8 cm550_FUN_0002d9a8 (8 lines); called by cm550_FUN_00030c3c
- 0x30ade cm550_FUN_00030ade (8 lines) and 0x30b0e cm550_FUN_00030b0e (4 lines); called by mc68k_applicationMain
- 0x30b10 cm550_fuelDemandLimitSelector4 (9 lines); called by cm550_FUN_00030b34
- 0x30b34 cm550_FUN_00030b34 (12 lines); called by vp44InjectionSystemStateController; calls cm550_fuelDemandLimitMinimumUpdater, cm550_FUN_0000c2ee, cm550_FUN_00012484, cm550_engineModeTransitionStateUpdater, cm550_FUN_00026af0, cm550_fuelDemandLimitSelector4, cm550_FUN_00034dba
- 0x30bf6 cm550_shutdownMinimumSelector28 (10 lines) and 0x30c14 cm550_shutdownMinimumSelector20 (11 lines); called by cm550_FUN_00030c3c
- 0x30c3c cm550_FUN_00030c3c (15 lines); called by fuelTimingOilPressureModeController; runs the chain: 0x1ce58, 0x2d9a8, Selector21, 16, 15, 29, 20, 28, 0x17120, then two undumped calls
- 0x34512 cm550_FUN_00034512 (9 lines); called by executiveFrameInterruptHandler; reads ENGINE_STATE_STOPPED
- 0x34dba cm550_FUN_00034dba (9 lines); called by cm550_FUN_00030b34
Name each limiter from the limit it applies and the state it stamps (the numbers in the current names are wrong or meaningless), the two chain runners (0x30c3c and 0x30b34 - a second chain: say what it limits; it may be the timing limit chain), and the chain's globals: fuel_limit_shutdown_minimum (the running minimum - CM848's row for the same role is torque_derate_fuel_quantity next to torque_derate_fuel_source_code; check), _smallest_derate_fueling_value_among_group_2_ah_derate_algori_0_100, each limiter's limit value (_anc_fuel_limit_value, _high_rpm_fuel_limit_value / _high_rpm_fuel_limit_active ...), using the e2m record at each address and CM848's name where it is the same record. CM848's chain: find the function(s) that store torque_derate_fuel_source_code / the FUELING_STATE members 13 / 15 / 19 / 20 / 28 / 29 / 40 and compare step by step - CM848 may do in one function what CM550 does in ten (then they are counterparts, not twins).
The scored CM848 candidates in cross_firmware_matches.csv for these addresses (initProtectionStateWithFuelDemand, checkProtectionParamLimit, sensorFaultDetection ...) are untrusted; verify or ignore.` },
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
      kind: { type: 'string', enum: ['function', 'global', 'enum_member'] },
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
  (pair, b) => (pair && pair.proposal) ? sturdy((n) => `You are the JUDGE for batch ${b.id} (${b.title}) of a firmware naming change. An investigator proposed the changes below; an independent describer, who did not see the proposals, described the same functions. Your job is to refute what is wrong before it reaches the repository.\n\nPROCEDURE\n1. For each function: compare the investigator's role with the describer's. Where they differ, or either is vague, or the discriminator is only an enable bit shared with a sibling, re-derive the role yourself from the code (decompilation and disassembly) and write it in own_role. Where they agree, still spot-check the discriminator in the code and write own_role.\n2. Check each name: it must state the role, follow the naming and prefix rules, be unique in its firmware (grep the frozen function_renames.csv / global_variables.csv; also against the other proposals), and not claim more than the code shows.\n3. Twins: read BOTH firmwares' code and check the steps, their order, the constants and the call graph position. A similar purpose is a counterpart (prefixed name; CM848 keeps its name). For a twin give final_cm848_address.\n4. Globals: check the address, the access width behind the type (python3 ${T}/abs_refs.py), every user, the e2m record at the address, and that a new array / struct swallows or splits no named row.\n5. Enum members: check every store and compare of that value in the firmware(s) concerned, and that the new member name is unique in the enum.\n6. Verdict per element: CONFIRMED, AMENDED (give the exact final_name / final_type / final_relation / final_comment) or REFUTED (final_name = the current name; default to this when the code does not clearly support the element). Give one verdict for EVERY proposed function, global and enum member, and say in 'overall' whether the investigator's skipped[] functions should stay skipped.\n\nTHE BATCH\n${b.text}\n\nTHE INVESTIGATOR'S PROPOSALS\n${JSON.stringify(pair.proposal, null, 1)}\n\nTHE INDEPENDENT DESCRIBER'S ROLES\n${pair.blind ? JSON.stringify(pair.blind, null, 1) : '(the describer returned nothing: re-derive every role yourself)'}\n\n${COMMON}\n\nKeep your scratch scripts and notes in ${R}/scratch/${b.id}/judge/.${NOTE(n, 'judge', b)}`,
    { label: `judge:${b.id}`, phase: 'Judge', schema: VERDICT }).then((v) => ({ batch: b.id, proposal: pair.proposal, blind: pair.blind, verdict: v })) : null,
)
const missing = BATCHES.filter((b) => WANTED.includes(b.id)).filter((b, i) => !results[i]).map((b) => b.id)
if (missing.length) log(`batches with no result: ${missing.join(', ')}`)
return { results: results.filter(Boolean) }
