# Items (2) and (3): the uncertain rows, the fuel limit pair, source 16 and the W7 note-87 leftovers
ROWS = []


def F(address, old, new, plate, evidence, verdict="confirmed"):
    r = {"kind": "function", "address": address, "old": old, "verdict": verdict}
    if new:
        r["new"] = new
    if plate:
        r["plate_comment"] = plate
    r["evidence"] = evidence
    ROWS.append(r)


def G(address, old, new, evidence, verdict="confirmed", kind="global", typ=None):
    r = {"kind": kind, "address": address}
    if kind == "global":
        r["verdict"] = verdict
        if old:
            r["old"] = old
    if new:
        r["new"] = new
    if kind == "new_global":
        r["type"] = typ or "word"
    r["evidence"] = evidence
    ROWS.append(r)


def N(text):
    ROWS.append({"kind": "note", "text": text})


# ---------------- (2) the three uncertain rows ----------------
G("0x003fdd38", "torque_source_count", None,
  "Still uncertain, no new name. CODE (cm848_applySwitchSelectedEngineSpeedLimit): the alternate droop cap "
  "engine_speed_limit_droop_cap_alternate_cal replaces engine_speed_limit_droop_cap_cal only when this word is above 1 "
  "(signed compare), engine_speed_limit_droop_cap_alternate_disable is 0 and switch 31 is on; one read, never written, EEPROM "
  "0x8b6 (inside the _cal window), dump 1. e2m (corroboration only; its 0x0100xxxx addresses do NOT equal our EEPROM offsets, e.g. "
  "e2m 0x01000828 is ASG_Droop_Gain1_2 but our EEPROM 0x828 is an output channel word): the HSG has THREE parameter sets - "
  "HSG_Isochronous_Speed / _2 / _3 at 0x0112EA04 / 06 / 08, HSG_Breakpoint_Speed_2 / _3, HSG_Droop_Slope_2 / _3, 'Alternate' - and "
  "a fault 'DG0524JC OEM - Alternate droop switch validation fault'; our droop cap pair (0x3fd80e / 0x3fd810) matches the first "
  "two isochronous speeds in order and adjacency. That makes 'number of droop parameter sets (1 to 3)' the likeliest meaning, "
  "which the code (> 1 enables set 2) does not contradict but does not prove: no code here reads a value of 3. Candidate if the "
  "caller accepts the e2m reading: engine_speed_limit_droop_cap_set_count_cal.", verdict="uncertain")
G("0x003fa8a4", "torque_limit_working_reference", None,
  "Still uncertain, no new name; the reading is now precise. cm848_updateProtectionStateMachine (cpp 21046-21056) stores "
  "engine_speed_limit_arbitrated when the winning source number (engine_speed_limit_arbitration.limiting_source_number) is 1 / 2 / "
  "4 / 5 / 12 and engine_speed_limit_reference otherwise, every pass, before it switches on a 3-bit case (bit 4: the governor "
  "speed limit output is farther than DAT_0005c366 from the governor integrator high word; bit 2: the fuel limit source "
  "governor_fuel_mode_command is 15, or 16 with fault bits 8 / 9 of fault_detected_bits_0_to_15; bit 1: that source list). "
  "cm848_processJ1939RxMessage (0x20c64, called from cases 3 only in its twice-evaluated form) turns a FUEL quantity into the "
  "engine speed on the droop line: slope x (engine_speed_limit_ramped_maximum_fuel_quantity - fuel) x 8 / 0x8888 + "
  "engine_speed_limit_arbitrated (capped at 40000), or this word when the slope is 0 (a vertical droop line), and stores "
  "that speed and the fuel in the protection_* threshold words; it is called from case 3 of that switch with "
  "protection_output_select_cal or protection_integrator_cal as the fuel argument, which is chosen by comparing this word with "
  "DAT_0005c35e. So "
  "it is the speed of the droop line when the line has no slope, chosen between the arbitrated limit (limits that act as the "
  "governor reference) and the reference limit - 'the engine speed reference of the protection threshold curve'. The "
  "protection_* threshold words and the DAT_0005c34c-0005c366 constants form one structure (speed / fuel breakpoint pairs with "
  "'level' variants selected by that 3-bit case) that needs its own wave. Time-shared window; one writer function (two stores) "
  "and no boot-ROM user by immediate scan (W8). Candidate: engine_speed_limit_droop_line_reference_speed.",
  verdict="uncertain")
G("0x0040a280", "torque_limit_init_flag", None,
  "Still uncertain, no name. xref_addr.py: 0 reads / 1 write, a single sth r10 at 0x204a0 in "
  "cm848_initializeEngineSpeedLimitDefaults (width WORD); 0x40a282 has no reference at all. So the dword type of the row is "
  "wrong - the store is a halfword to 0x40a280 only. Type edit (not a time-shared address, so allowed): global_variables.csv "
  "'0x0040a280,torque_limit_init_flag,dword,' -> '0x0040a280,torque_limit_init_flag,word,' (the name stays until a role is "
  "found; a write-only word cleared at initialization has none to name). No e2m parameter was found at the matching offset "
  "(W8).", verdict="uncertain")

# ---------------- (3a) the fuel quantity limit pair ----------------
N("[W9 item 3 - the fuel limit pair 0x40afac / 0x40afae = e2m Torque_Derate_Fueling / Torque_Derate_Fueling_State] e2m block "
  "0x01105D00 + 2n = our 0x40afac + 2n (delta 0xCFAD54): +0 Torque_Derate_Fueling [FSLMFL] 'smallest derate fueling value "
  "produced by the derate algorithms' = 0x40afac protection_fuel_limit_active; +2 Torque_Derate_Fueling_State [FSLMFLST] "
  "'indicator as to which algorithm is controlling fuel after it has been limited' = 0x40afae governor_fuel_mode_command; +4 "
  "FSS_Fueling_Derate [FSAPLMFL] 'fuel system specific fuel derate that is input to the core system' = 0x40afb0 "
  "fuel_pressure_fault_fuel_limit_working (the HPCR rail pressure fault limit: a fuel-system-specific derate, name already "
  "consistent); +6 Torque_Derate_Fueling_2 'smallest derate fueling value among group 2 (AH) derate algorithms' = 0x40afb2 "
  "fuel_demand_minimum_tracked; +8 Torque_Derate_Fueling_State_2 = 0x40afb4 governor_fuel_mode_input: five consecutive words, "
  "same roles. CODE (cm848_processProtectionSelection cpp 19365 and the writers): each pass cm848_initProtectionStateWithFuelDemand "
  "(cpp 19939) - its only caller is cm848_processProtectionLimits (cpp 43018), which cm848_processProtectionSelection runs every "
  "pass while governor_feature_flags bit 0x10 is clear - resets protection_fuel_limit_active to protection_fuel_limit_cal_active "
  "with source code 0x13; every limiter then "
  "does 'if my limit < protection_fuel_limit_active: take it and store my source code in governor_fuel_mode_command' (lowest wins, "
  "the fuel quantity twin of the engine speed limit arbitration); cm848_processProtectionSelection then compares it with the "
  "governor fuel demand (governor_fuel_demand_value / mode) into fuel_demand_arbitration_working and "
  "governor_fuel_mode_arbitrated, and with the group 2 minimum into fuel_demand_arbitrated. The 13 write sites (12 distinct "
  "source codes plus one pass-through of the group 2 code governor_fuel_mode_input, cpp 19420, which can be 16 or 59) and their "
  "source codes (decimal): 13 cm848_processProtectionSelection (governor_feature_flags bit 0x10 SET, the limiters are skipped: "
  "protection_fuel_limit_c_working); 15 "
  "cm848_protection_limits (Bank 2, fuel_correction_upper_limit); 19 cm848_initProtectionStateWithFuelDemand (start of pass); 20 "
  "cm848_applySpeedControlProtectionLimit (J1939 TSC1 / ETC1 mode 3 torque limit); 28 cm848_applyFuelPressureFaultFuelLimit; 29 "
  "cm848_enforceFuelLimitProtection (fault_derate_fuel_limit); 40 cached default (governor_fuel_mode_command_cached, "
  "cm848_calculateProtectionRateLimited); 42 cm848_applyProtectionLimit (protection_fuel_limit_working); 45 "
  "cm848_applyTorqueManagementFuelLimit; 46 protection_fuel_limit_check (cold_start_fuel_demand_ramp_output); 61 "
  "cm848_limitFuelQuantityOnRailPressureShortfall; 62 cm848_processSafetyConditionProtection. Group 2 writers: "
  "cm848_trackMinimumFuelDemand (source 16, fuel_demand_load_based) and cm848_trackFuelDemandMinimum (source 59, "
  "fuel_demand_rate_output, with fault_feature_config_flags bit 0x4). Readers of the source code: cm848_calculateEffectiveFuelLimit "
  "(source 20 test), cm848_updateProtectionStateMachine (15 / 16), j1939GetEngineStateCode (compares it with governor_mode_code).")
G("0x0040afac", "protection_fuel_limit_active", "torque_derate_fuel_quantity",
  "The lowest fuel quantity limit of the derate sources (fuel demand scale, 5888 = 400 mm3 = none), reset every pass of "
  "cm848_processProtectionLimits and lowered by the limiters listed in the note; e2m Torque_Derate_Fueling (0x01105D00 = ours + 0xCFAD54, five-word block "
  "match). Dump 1030 with source 62 (the safety condition limit, the last pass). 'Torque derate' is the e2m term and keeps the "
  "name apart from the engine speed limits.")
G("0x0040afae", "governor_fuel_mode_command", "torque_derate_fuel_source_code",
  "Source code of the limiter that set torque_derate_fuel_quantity (13 / 15 / 19 / 20 / 28 / 29 / 40 / 42 / 45 / 46 / 61 / 62, "
  "table in the note); e2m Torque_Derate_Fueling_State 'indicator as to which algorithm is controlling fuel after it has been "
  "limited'. It is not a command: nothing sends it anywhere, the arbitration only compares it. Dump 62 (0x3e). An enum of the "
  "codes would be a natural follow-up; the group 2 word governor_fuel_mode_input and the arbitrated copies share the code space "
  "(16 / 59 / 32 appear there).")
G("0x0040afb2", "fuel_demand_minimum_tracked", None,
  "Uncertain, no name. e2m Torque_Derate_Fueling_2 'smallest derate fueling value among group 2 (AH) derate algorithms' sits at "
  "the matching +6 of the same block; the two writers here are cm848_trackMinimumFuelDemand (fuel_demand_load_based, source 16) "
  "and cm848_trackFuelDemandMinimum (fuel_demand_rate_output, source 59); that group 2 is air handling (AH) was not verified from "
  "the code. Candidate: air_handling_torque_derate_fuel_quantity (and governor_fuel_mode_input -> "
  "air_handling_torque_derate_fuel_source_code, 0x40afb4).", verdict="uncertain")

# ---------------- (3c) W7 note 87 leftovers ----------------
F("0x00507c44", "cm848_resetGovernorStartupReadyFlag", "cm848_runFaultDerateScheduler",
  "Fault derate scheduler: with the derate feature bit 0x10 of governor_feature_config_word clear it sets the derate outputs to "
  "their defaults (engine_speed_limit_fault_derate = engine_speed_limit_default_cal, fault_derate_fuel_limit = fuel_demand_maximum, "
  "flags 0, state 3); otherwise it runs the cold start trigger and one derate task per call selected by "
  "governor_faultDerate_task_index (0 event counters, 1 trigger latch clear and channel iteration, 2 "
  "cm848_calculateFaultDerateFuelLimit, 3 cm848_calculateFaultDerateEngineSpeedLimit and channel processing). "
  "(was cm848_resetGovernorStartupReadyFlag)",
  "Read the first 26 lines of the body (cpp, Bank 2 0x507c44), not the last tasks; the name matches what W7 / W8 saw ('the fault "
  "derate scheduler') and the writers listed in the fault_derate_active_flag row. The old name is the reset of a flag that was "
  "itself renamed.")
G("0x0005c306", "timing_limit_lower", "fuel_demand_maximum",
  "ROM constant 5888 (0x1700) = the full scale of the fuel demand words (400 mm3 per stroke): the 'no limit' initial value of "
  "the fuel limits (fault_derate_fuel_limit = it in cm848_runFaultDerateScheduler and the reset; 8 readers, 0 writers: "
  "cm848_initColdStartTablePointers, cm848_selectFuelDemandSource, cm848_updateProtectionStateMachine, "
  "cm848_initializeFuelDemandAndLimitInterpolationStates, cm848_calibrationGroup5_periodic, lhz in the five listed). The old "
  "name says "
  "timing and 'lower'; it is a fuel quantity and the upper bound. Bank 1 ROM, no _cal. The fault_derate_fuel_limit comment "
  "already says '5888 = none'.")
G("0x0005c30c", "timing_limit_upper", None,
  "Uncertain, no name: ROM word 0 here, read as lha / lhz by cm848_selectFuelDemandSource (2), cm848_calculateDualAxisFuelLimit "
  "(2), cm848_processActiveFaultList, cm848_calculateFuelDemandWithTrim; by the pairing with 0x5c306 (5888 = maximum) it is "
  "probably the fuel demand minimum (0), but the clamp use was not read.", verdict="uncertain")
F("0x005031b4", "cm848_protection_init", "cm848_initializeVehicleSpeedAndCruiseState",
  "Boot initialization: cruise_control_engaged_flag, cruise_speed_command, vehicle_speed, drivetrain_ratio, "
  "drivetrain_ratio_unsettled_flag and j1939_prop_status_tx_state are 0 and engine_speed_limit_source_2 is "
  "engine_speed_limit_default_cal. (was cm848_protection_init)",
  "Read in full (cpp 'Function: cm848_protection_init @ 0x005031b4'): seven stores, none of them a protection state.")
F("0x00525134", "governor_cruise_speedError_torqueAdj", None, None,
  "Uncertain, no rename. It is a proportional term: governor_cruise_speed_error_net x cruise_pid_rate_gain_working / 1000 (at "
  "least one count of the right sign when the error is nonzero) x cruise_pid_rate_gain_scale >> 7, clamped to +/-10000. The "
  "domain of the cruise_pid_* words after the wave 4-6 pedal findings was not re-checked.", verdict="uncertain")
N("[W9 item 3 - not reached] The governor_pid_t fields proportional_gain / integral_term (0x40af5a / 0x40af5c), "
  "j1939_dm1_spn_a_word / j1939_dm1_spn_fmi_byte and the protection_* threshold words (0x3fa8a4 note above) were not read in "
  "this wave (budget); they stay with the earlier notes.")
