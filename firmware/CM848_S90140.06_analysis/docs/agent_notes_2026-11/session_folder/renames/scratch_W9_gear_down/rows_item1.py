# Item (1): the "thermal / gear-down" cluster is Torque Management (e2m Torque_Mgmt_*)
ROWS = []


def F(address, old, new, plate, evidence, verdict="confirmed"):
    r = {"kind": "function", "address": address, "old": old, "verdict": verdict}
    if new:
        r["new"] = new
    if plate:
        r["plate_comment"] = plate
    r["evidence"] = evidence
    ROWS.append(r)


def G(address, old, new, evidence, verdict="confirmed", extra=None):
    r = {"kind": "global", "address": address, "old": old, "verdict": verdict}
    if new:
        r["new"] = new
    r["evidence"] = evidence
    if extra:
        r.update(extra)
    ROWS.append(r)


def N(text):
    ROWS.append({"kind": "note", "text": text})


N("[W9 item 1 - READING] The cluster is NOT gear down and NOT thermal: it is the Cummins TORQUE MANAGEMENT fuel limiter (e2m "
  "Torque_Mgmt_*), the transmission-protection fuel limit keyed on the drivetrain gear ratio. CODE: cm848_runTorqueManagement "
  "(called from cm848_periodicTaskSet_protection, cpp 6873) builds a fuel quantity limit from a requirement flag "
  "(cm848_evaluateTorqueManagementRequired: transmission_type_cal, vehicle_speed, drivetrain_ratio, transmission_current_gear), a "
  "table limit (rpm table, stage 0-2 = the 4-D fuelling tables at a throttle breakpoint), an entry ramp down (limit = previous fuel "
  "demand or limit minus a step until it reaches the table limit), an exit hold timer and an exit ramp up (limit + step until above "
  "fuel_demand_computed + offset); the limit goes into the running fuel limit protection_fuel_limit_active with source code 45 "
  "(0x2d) and straight into the min() of cm848_calculateEffectiveFuelLimit. e2m (corroboration, nine consecutive words, same roles "
  "and the same scale in each): Torque_Mgmt_Delay_Time / Manual_GR / Neg_Slew_Rate / Pos_Slew_Rate / Final_Fueling_Offset / 47RE_GR / "
  "Manual_GR0 / GR1 / GR2 at e2m 0x018A5700..0x018A5710 = our 0x408d26..0x408d36 (e2m = ours + 0x149C9DA, the block's own delta; the "
  "HSG delta 0xCFC008 does not apply); Torque_Mgmt_Fueling / Torque_Mgmt_Required at e2m 0x018A5800 / 02 = our 0x40b61c / 0x40b61e "
  "(e2m = ours + 0x149A1E4); Torque_Mgmt_Engine_Speed_Axis / Alpha_Axis / Fueling_Table (21 rpm x 2 alpha) = ROM 0x5b4d6 / 0x5b502 / "
  "0x5b508 (21 rpm breakpoints, alpha axis 0 and 16384, 2 x 21 grid; dimensions and order match, no delta applies to ROM tables). "
  "Gear_Down_Active (0x018B8906) / Gear_Down_Gear_Ratio (0x018B8B00) are road speed governor words (RSG_Reference_Speed, SR_Reference_"
  "Speed, 'down from top gear') with NO offset match to anything here: the W8 gear-down reading is rejected. e2m 40 ms is the e2m's "
  "own statement of the pass period (Torque_Mgmt_Neg_Slew_Rate / Pos_Slew_Rate 'every 40 ms', Torque_Mgmt_Delay_Time scale 0.04 s); the "
  "code only counts passes. NOT in use here ('off in this calibration', not dead code): engine_feature_enable_flags_cal = 0x27EF and "
  "protection_feature_flags = 0x67BE both have mask 0x1000 clear (disassembly: rlwinm r,r,0,19,19 at 0x3ed20 / 0x3ed74 / 0x3f2c8 / "
  "0x3f2d8) and transmission_type_cal = 3 (48RE) makes cm848_runTorqueManagement store 0x1700 (no limit) before anything else; "
  "RAM dump 0: required 0, stage 3, limit 5888.")

N("[W9 item 1 - enable bits, with one e2m mismatch] The two flag words are the e2m algorithm-enable words: the e2m enable table "
  "0x01106B02 + 2 x n matches our 0x3fd59c + 2 x n (algorithm_enable_flags_6_cal 0x3fd5a8 = n 6 = e2m 0x01106B0E, "
  "combustion_override_and_estimation_enable_flags_cal 0x3fd5a6 = n 5 = 0x01106B0C), so engine_feature_enable_flags_cal 0x3fd5ec = "
  "n 40 = e2m 0x01106B52, protection_feature_flags 0x3fd5f0 = n 42 = 0x01106B56, fuel_feature_control_flags 0x3fd5f2 = n 43 = "
  "0x01106B58. Agreeing bits (code mask = e2m mask): 0x3fd5ec bit 0x4 OPG_Enable (low oil pressure, the oil pressure processing "
  "bit), 0x40 J1850_Communication_Enable (the PCI message timeouts bit), 0x1000 Torque_Mgmt_Enable (this cluster), 0x2000 "
  "Trip_Info_Enable (the trip counters bit); 0x3fd5f0 bit 0x4 HPCR_Fuelpr_Crank_Mode_Enable (the setpoint cranking phase), 0x20 "
  "TC_Stall_Enable (the converter slip monitor gate), 0x40 J1939_Lost_TSC_No_Broadcast_Enable (the datalink_broadcast_enable_flags "
  "0xfff3 shut-off beside fuel_demand_timing_enable_flag), 0x200 Torque_Mgmt_Cold_Increment_Enable (cold delta fuel added to the "
  "table limit: fuel_demand_offset_correction = Cold_Delta_Fuel). MISMATCH: e2m Torque_Mgmt_GR_Enable is mask 0x0800 of 0x01106B56 "
  "(description cut off: 'Enable to'), but the code tests protection_feature_flags & 0x1000 (rlwinm 0,19,19, verified) for the "
  "gear-ratio stage thresholds; e2m lists nothing at 0x400 / 0x1000 for that word. The code mask is the fact; the name of that bit "
  "(a manual-transmission gear ratio stage enable) is left to the caller. Comment suggestions: engine_feature_enable_flags_cal "
  "'bit 12 (0x1000) torque management enable (e2m Torque_Mgmt_Enable; off here)'; protection_feature_flags 'bit 12 (0x1000) the "
  "manual transmission gear ratio stages of torque management; bit 9 (0x200) cold delta fuel added to the torque management table "
  "limit (e2m Torque_Mgmt_Cold_Increment_Enable); bit 5 (0x20) converter stall torque management (e2m TC_Stall_Enable); bit 6 (0x40) "
  "J1939 broadcast shut-off on lost TSC1 (e2m J1939_Lost_TSC_No_Broadcast_Enable); bit 2 (0x4) crank rail pressure table (e2m "
  "HPCR_Fuelpr_Crank_Mode_Enable)'.")

# ---- functions ----
F("0x0003ecdc", "cm848_evaluateThermalProtectionActive", "cm848_evaluateTorqueManagementRequired",
  "Decides whether torque management is required this pass (torque_management_required_flag) and which table stage applies "
  "(torque_management_gear_ratio_stage): manual transmission (transmission_type_cal 0) compares drivetrain_ratio with the manual "
  "threshold and, with protection_feature_flags bit 0x1000, the three stage thresholds; type 1 uses the manual threshold while "
  "fuel_demand_timing_enable_flag is 1; type 2 (47RE) is required in gear 4, or in unknown gear 255 at or below the 47RE "
  "threshold; type 3 only stores a mode word and is never reached. Only called by cm848_runTorqueManagement. "
  "(was cm848_evaluateThermalProtectionActive)",
  "Read in full (cpp 40689): the writes are 0x40b61e (flag) and 0x3fb4fe (stage 0 / 1 / 2 / 3); the three stage thresholds and the "
  "manual / 47RE thresholds are the e2m Torque_Mgmt_Manual_GR0..GR2 / Manual_GR / 47RE_GR words (see the reading note). The drivetrain "
  "ratio is engine speed over vehicle speed x 2048; that it equals the transmission gear ratio is an inference from the e2m "
  "names (11530 = 5.63 equals the 5.63:1 first gear of the NV5600 6-speed manual - outside knowledge, not from the firmware; "
  "8192 / 4096 / 1741 = 4.0 / 2.0 / 0.85).")
F("0x0003eea8", "cm848_calculateThermalLimitValue", "cm848_calculateTorqueManagementFuelTableLimit",
  "Computes torque_management_table_fuel_limit: stage 3 is a 2-D lookup of engine speed and combustion_alpha_input in the torque "
  "management table (ROM 0x5b508, 2944 = 200 mm3 everywhere in this calibration); stages 0-2 read the two 4-D fuelling table sets at "
  "throttle breakpoint (stage) over engine speed and blend them by thermal_fuel_limit_factor, skipping a set when the factor is 0 or "
  "0x4000. Adds fuel_demand_offset_correction when protection_feature_flags bit 0x200 is set. "
  "(was cm848_calculateThermalLimitValue)",
  "Read in full (cpp 40760); mask 0x200 verified (rlwinm 0,22,22 at 0x3f024); table dumps: x axis 21 rpm breakpoints (1060 - 3035 "
  "rpm), alpha axis {0, 16384}, grid 2944 x 42; the stage 0-2 tables are identical pairs here (4 throttle rows 0 / 100 / 200 / 400 "
  "counts of 0.25 percent, row 0 all zero, row 1 peaks at 515, row 2 at 1030, row 3 at 2134 counts).")
F("0x0003f054", "cm848_processThermalDelayTimer", "cm848_holdTorqueManagementFuelLimitDuringExitDelay",
  "On the pass torque management stops being required, reloads torque_management_exit_delay_timer from "
  "torque_management_exit_delay_time; while the timer is nonzero it holds the limit at the previous pass's "
  "torque_management_fuel_limit_previous and counts the timer down. (was cm848_processThermalDelayTimer)",
  "Read in full (cpp 40812); e2m Torque_Mgmt_Delay_Time 'delay time for fueling transition from torq mgmt to full fueling' is the "
  "reload word 0x408d26 (0 in this ROM).")
F("0x0003f0b8", "cm848_processThermalRecovery", "cm848_rampTorqueManagementFuelLimitUpOnExit",
  "Sets torque_management_exit_ramp_flag when torque management stops being required; once the exit delay timer is 0 the limit "
  "rises each pass by torque_management_fuel_increase_step from the previous pass limit, and the flag clears when the limit "
  "exceeds fuel_demand_computed plus torque_management_final_fuel_offset. (was cm848_processThermalRecovery)",
  "Read in full (cpp 40831); e2m Torque_Mgmt_Pos_Slew_Rate 'amount by which fuel will be increased every 40 ms when exiting' = "
  "0x408d2c (75) and Torque_Mgmt_Final_Fueling_Offset 'added to final fueling' = 0x408d2e (74).")
F("0x0003f154", "cm848_processThermalProtectionState", "cm848_rampTorqueManagementFuelLimitDownOnEntry",
  "Sets torque_management_entry_ramp_flag when torque management becomes required; while it is set the limit is the previous pass "
  "fuel demand (first pass) or limit (later passes) minus torque_management_fuel_decrease_step, floored at 0, and the flag clears "
  "when the limit would fall below torque_management_table_fuel_limit, which then becomes the limit. "
  "(was cm848_processThermalProtectionState)",
  "Read in full (cpp 40853); e2m Torque_Mgmt_Neg_Slew_Rate 'amount by which fuel will be reduced every 40 ms when entering' = "
  "0x408d2a (2950 = 200 mm3, so the first pass already drops far).")
F("0x0003f218", "cm848_calculateThermalFuelLimit", "cm848_selectTorqueManagementFuelLimitOutsideTransitions",
  "With no ramp and no exit delay running: the limit is 0x1700 (5888, the full fuel quantity: no limit) while torque management "
  "is not required and torque_management_table_fuel_limit while it is. (was cm848_calculateThermalFuelLimit)",
  "Read in full (cpp 40887).")
F("0x0003f2b0", "cm848_processThermalProtection", "cm848_runTorqueManagement",
  "Torque management pass (cm848_periodicTaskSet_protection): when neither enable bit 0x1000 (engine_feature_enable_flags_cal, "
  "protection_feature_flags) is set, or transmission_type_cal is 3, the limit is 0x1700 (no limit); otherwise it evaluates the "
  "requirement, the table limit, the exit delay, the exit ramp and the entry ramp, selects the limit and stores the previous-pass "
  "copies. Off in this calibration. (was cm848_processThermalProtection)",
  "Read in full (cpp 40907); mask disassembly at 0x3f2c8 / 0x3f2d8 (rlwinm 0,19,19); type test lha 0x3fd934 at 0x3f2e8.")
F("0x0003f35c", "cm848_applyThermalFuelLimit", "cm848_applyTorqueManagementFuelLimit",
  "If torque_management_fuel_limit is below the running fuel limit torque_derate_fuel_quantity, takes it and records source code "
  "45 (0x2d) in torque_derate_fuel_source_code; called from cm848_processProtectionLimits (cm848_calculateEffectiveFuelLimit also "
  "takes the minimum with torque_management_fuel_limit directly). (was cm848_applyThermalFuelLimit)",
  "Read in full (cpp 40934); caller cpp 43026.")
F("0x0003f38c", "cm848_initThermalProtectionState", "cm848_initializeTorqueManagement",
  "Boot initialization of torque management: required flag, previous required flag and both ramp flags 0, the limit and its "
  "previous-pass copies 0x1700 (no limit), the two table lookup cache words 2 and stage 3 (none). "
  "(was cm848_initThermalProtectionState)",
  "Read in full (cpp 40950); called from cm848_applicationMain (cpp 55433).")
F("0x0003eca4", "mpc555_initThermalProtectionFilters", "cm848_initializeConverterSlipEngineSpeedLimit",
  "Boot initialization of the converter slip engine speed limit: both words of its table lookup cache "
  "(engine_speed_limit_converter_slip_interpolation_state and the word after it, 0x3fb4ea) are 2 and "
  "engine_speed_limit_converter_slip is engine_speed_limit_default_cal. (was mpc555_initThermalProtectionFilters)",
  "Not part of torque management at all (the W8 note and the old name both put it in this cluster): the three stores are the cache of "
  "the converter slip table lookup and the limit cm848_monitorConverterSlipAndEngineSpeedLimit (source 13) writes just above it; "
  "disasm_func.py: sth r3,2(r4) at 0x3ecb4 with r4 = 0x3fb4e8, width word. Called from cm848_applicationMain (cpp 55496).")
F("0x0003eccc", "cm848_setThermalProtectionMode5", None, None,
  "Uncertain, no rename. It is a stw of 5 at 0x3fb500 (disasm 0x3ecd4; the low word 0x3fb502 = 5); xref_addr.py reports 0 "
  "references only because the cpp prints it as _subsystem_init_code (underscore overlap). A raw scan of both banks for the low "
  "half 0xb500 / 0xb502 finds no reader of either word (the other 0xb500 hits 0x290e8 lhz and 0x3afb0 sth belong to other base "
  "addresses; 0xb502 hits are the ROM pointer 0x5b502 and unrelated byte accesses). Its only caller is the "
  "transmission_type_cal = 3 branch of cm848_evaluateTorqueManagementRequired, which cm848_runTorqueManagement never reaches (it "
  "returns for type 3 first), so the call is unreachable; the word 0x3fb500 is in the time-shared window, so no type or name change "
  "is proposed for subsystem_init_code (0x3fb500).",
  verdict="uncertain")
F("0x0003f6fc", "cm848_resetEngineLoadTracker", "cm848_resetTransmissionTemperatureValidation",
  "Boot reset of the transmission temperature stability check: clears the unchanged-reading latch (rate_limit_flags bit 2), the "
  "previous raw reading and the unchanged-reading counter, and sets transmission_temperature_early_substitute_countdown to 10. "
  "(was cm848_resetEngineLoadTracker)",
  "Read in full (cpp 41076); it touches only the words cm848_selectTransmissionTemperatureInUse uses; called once from "
  "cm848_applicationMain (cpp 55540).")

# ---- globals: RAM state ----
G("0x003fb4f0", "torque_limit_enable_flag", "torque_management_required_previous_flag",
  "Copy of torque_management_required_flag stored at the end of cm848_runTorqueManagement; the edge detectors compare it with the "
  "new flag (1 -> 0 starts the exit delay and ramp, 0 -> 1 the entry ramp). Dump 0. Time-shared window: raw scan of the low half "
  "0xb4f0 finds only the cluster (0x3f060 / 0x3f0bc / 0x3f158 / 0x3f338 / 0x3f39c), nothing below 0x7F60.")
G("0x003fb4f2", "protection_fuel_min_raw", "torque_management_fuel_limit_previous",
  "Previous pass copy of torque_management_fuel_limit (stored at the end of cm848_runTorqueManagement; the exit hold and ramp and "
  "the entry ramp start from it). Dump 0x1700. Cluster only (raw scan of 0xb4f2: 0x3f09c / 0x3f110 / 0x3f1bc / 0x3f348 / 0x3f3b0; "
  "the 0x3aa54 hit is a stb to another address).")
G("0x003fb4f4", "protection_fuel_demand_working", "torque_management_fuel_demand_previous",
  "Previous pass copy of fuel_demand_computed (stored at the end of cm848_runTorqueManagement); the first pass of the entry ramp "
  "starts from it. Dump 0x1700. Cluster only (raw scan of 0xb4f4: 0x3f19c / 0x3f328 / 0x3f3b8; 0x3a4e0 is an unrelated addi).")
G("0x003fb4f6", "torque_limit_active_flag_b", "torque_management_exit_ramp_flag",
  "Set when torque management stops being required (cm848_rampTorqueManagementFuelLimitUpOnExit), cleared when the rising limit "
  "passes fuel_demand_computed plus the final offset; while it is set and the exit delay is over the limit rises by "
  "torque_management_fuel_increase_step per pass. Dump 0. Cluster only (raw scan of 0xb4f6).")
G("0x003fb4f8", "torque_limit_stable_flag", "torque_management_entry_ramp_flag",
  "Set when torque management becomes required (cm848_rampTorqueManagementFuelLimitDownOnEntry), cleared when the falling limit "
  "reaches torque_management_table_fuel_limit; while it is set the limit falls by torque_management_fuel_decrease_step per pass. "
  "Dump 0. Cluster only (raw scan of 0xb4f8: 0x3f160 / 0x3f24c / 0x3f290 / 0x3f3dc; the 0x3a9c4 hit is a stb elsewhere).")
G("0x003fb4fa", "torque_limit_entry_timer", "torque_management_exit_delay_timer",
  "Loaded from torque_management_exit_delay_time on the pass torque management stops being required and counted down once per "
  "pass (cm848_holdTorqueManagementFuelLimitDuringExitDelay); the limit is held at the previous pass limit while it is nonzero. The "
  "old name says 'entry' but the load is on the falling edge: this is the exit delay. Dump 0 (and the calibration value is 0).")
G("0x003fb4fc", "fuel_demand_offset_working", "torque_management_table_fuel_limit",
  "Output of cm848_calculateTorqueManagementFuelTableLimit: the fuel quantity limit from the torque management table or the 4-D "
  "tables (plus the cold delta fuel when protection_feature_flags bit 0x200 is set); the limit steady state while torque management "
  "is required and the floor of the entry ramp. e2m: Torque_Mgmt_Fueling is the final limit (0x40b61c), this is its table input. "
  "Dump 0 (not required). Cluster only (raw scan of 0xb4fc: 0x3f014 / 0x3f1f8 / 0x3f2a4).")
G("0x003fb4fe", "fuel_injection_state", "torque_management_gear_ratio_stage",
  "Stage chosen by cm848_evaluateTorqueManagementRequired: 0 / 1 / 2 = the manual transmission ratio is at or above stage 0 / 1 / 2 "
  "threshold (the 4-D fuelling table is read at throttle breakpoint 0 / 1 / 2, e2m 'use 4D table bpkt 0 / 1 / 2'), 3 = no stage (the "
  "torque management table, or not required). Dump 3. Cluster only (raw scan of 0xb4fe: seven hits, all 0x3eda0..0x3f3e8).")
G("0x003fb4ec", "protection_limit_init_state_a", "torque_management_fuel_table_interpolation_state",
  "Lookup cache (x segment offset, the next word is y) of the stage 3 table in cm848_calculateTorqueManagementFuelTableLimit "
  "(cm848_dualAxisTableInterpolation, cache pointer argument); set to 2 by cm848_initializeTorqueManagement. Label only. Cluster "
  "only; no user below 0x7F60 (cluster hits only).")
G("0x003fb4ee", "protection_limit_init_state_b", "torque_management_fuel_table_interpolation_state_y",
  "Second word (y segment offset) of the same lookup cache; set to 2 by cm848_initializeTorqueManagement and never accessed "
  "otherwise (the lookup routine updates it through the cache pointer). Label only.")
G("0x0040b61c", "protection_fuel_min_source", "torque_management_fuel_limit",
  "The torque management fuel quantity limit: 0x1700 (5888, no limit) unless required or in a ramp / exit delay; read by "
  "cm848_applyTorqueManagementFuelLimit (running limit with source 45) and as one of the minima in cm848_calculateEffectiveFuelLimit "
  "(cpp 20729). e2m Torque_Mgmt_Fueling (0x018A5800 = ours + 0x149A1E4): 'fueling limit as calculated by Torque Mgmt algorithm'. "
  "Dump 5888. Written only in the cluster (cpp 40822-40965).")
G("0x0040b61e", "torque_limit_active_flag", "torque_management_required_flag",
  "1 when the vehicle conditions require torque management (cm848_evaluateTorqueManagementRequired): the output that drives the "
  "limit; e2m Torque_Mgmt_Required (0x018A5802 = ours + 0x149A1E4, right after Torque_Mgmt_Fueling like 0x40b61c / 0x40b61e) "
  "'vehicle conditions are met that require torque mgmt'. Dump 0. Ten accesses, all in 0x3ed5c-0x3f394 (cluster).")
# ---- globals: ROM-copied calibration words (no _cal) ----
G("0x00408d26", "torque_limit_entry_timer_cal", "torque_management_exit_delay_time",
  "Reload value of torque_management_exit_delay_timer (passes of the periodic task; e2m Torque_Mgmt_Delay_Time 'delay time for "
  "fueling transition from torq mgmt to full fueling', scale 0.04 s, so 40 ms per pass by the e2m). 0 here. Address 0x408d26 is "
  "ROM-copied (not in the EEPROM window 0x3fd482-0x3feec1), so the _cal goes. First word of the e2m block (0x018A5700).")
G("0x00408d28", "engine_temp_protection_threshold_cal", "torque_management_manual_gear_ratio_threshold",
  "drivetrain_ratio (x 2048) at or above which a manual transmission - or type 1 while fuel_demand_timing_enable_flag is 1 - "
  "needs torque management (also when vehicle_speed is 0): 11530 = 5.63 - which equals the 5.63:1 first gear of the NV5600 "
  "6-speed manual (outside knowledge; reading drivetrain_ratio as the transmission gear ratio is an inference from the "
  "e2m names). e2m Torque_Mgmt_Manual_GR "
  "'gear ratio above which will cause manual TX to be in torq mgmt', scale 1/2048 like drivetrain_ratio. ROM-copied, no _cal.")
G("0x00408d2a", "protection_fuel_deadband", "torque_management_fuel_decrease_step",
  "Amount the limit falls per pass in the entry ramp (2950 = 200 mm3, so it normally drops straight to the table limit). e2m "
  "Torque_Mgmt_Neg_Slew_Rate 'amount by which fuel will be reduced every 40 ms when entering torq mgmt'. Not a dead band: it is "
  "subtracted from the previous demand or limit. ROM-copied, no _cal.")
G("0x00408d2c", "torque_limit_fuel_min_offset_cal", "torque_management_fuel_increase_step",
  "Amount the limit rises per pass in the exit ramp (75 = 5.1 mm3). e2m Torque_Mgmt_Pos_Slew_Rate 'amount by which fuel will be "
  "increased every 40 ms when exiting torq mgmt'. ROM-copied, no _cal.")
G("0x00408d2e", "torque_limit_fuel_demand_offset_cal", "torque_management_final_fuel_offset",
  "Offset added to fuel_demand_computed in the exit ramp end test: the ramp stops when the rising limit exceeds demand plus this "
  "(74 = 5.0 mm3). e2m Torque_Mgmt_Final_Fueling_Offset 'torque mgmt fueling offset for positive slew rate limit; added to final "
  "fueling'. ROM-copied, no _cal.")
G("0x00408d30", "engine_temp_protection_l4_threshold_cal", "torque_management_47re_gear_ratio_threshold",
  "For transmission_type_cal 2 with unknown gear (transmission_current_gear 255): torque management is required at or below this "
  "drivetrain_ratio (a top gear ratio); in gear 4 it is required regardless. 0 here. e2m Torque_Mgmt_47RE_GR 'gear ratio below which "
  "will cause 47RE trans to be in torq mgmt'. ROM-copied, no _cal. The 47RE is the e2m's name for the type 2 automatic (a "
  "transmission model, not an abbreviation made up here).")
G("0x00408d32", "engine_temp_injection_cutout_threshold_cal", "torque_management_manual_gear_ratio_stage_0_threshold",
  "Manual transmission with protection_feature_flags bit 0x1000: drivetrain_ratio at or above this (8192 = 4.0) selects stage 0, "
  "the 4-D fuelling table at throttle breakpoint 0 (all zero fuel in this ROM, hence the old 'cutout'). e2m Torque_Mgmt_Manual_GR0 "
  "'gear ratio above which will cause manual TX to use 4D table bpkt 0'. ROM-copied, no _cal.")
G("0x00408d34", "engine_temp_injection_reduce_threshold_cal", "torque_management_manual_gear_ratio_stage_1_threshold",
  "Same for stage 1 (4096 = 2.0; the table row is 25 percent throttle, 342-515 counts = 23-35 mm3). e2m Torque_Mgmt_Manual_GR1. "
  "ROM-copied, no _cal.")
G("0x00408d36", "engine_temp_injection_partial_threshold_cal", "torque_management_manual_gear_ratio_stage_2_threshold",
  "Same for stage 2 (1741 = 0.85; the table row is 50 percent throttle, 699-1030 counts = 47-70 mm3); below it the stage is 3 and "
  "torque management is not required. e2m Torque_Mgmt_Manual_GR2. ROM-copied, no _cal.")

# ---- transmission temperature validation leftovers (same files) ----
G("0x003fb504", "fuel_flow_rate_counter", "transmission_temperature_adc_unchanged_reading_counter",
  "Counts passes in cm848_selectTransmissionTemperatureInUse (cpp 41017-41070) in which the raw reading of the transmission "
  "temperature slot equals transmission_temperature_adc_previous_reading; at the limit it clears and sets the unchanged-reading "
  "latch (rate_limit_flags bit 2); a changed reading clears it and re-forces the sensor value. Cleared by "
  "cm848_resetTransmissionTemperatureValidation. Time-shared window: the raw scan of 0xb504 (0x3f640 / 0x3f6d4 / 0x3f720) has no "
  "user below 0x7F60. No fuel flow involved.")
G("0x00408d3a", "fuel_flow_rate_counter_threshold_cal", "transmission_temperature_adc_unchanged_reading_limit",
  "Consecutive unchanged raw readings (3) after which the stability latch is set. ROM-copied, no _cal. No fuel flow involved.")
G("0x00408d3c", "fuel_flow_rate_protection_cap_cal", "transmission_temperature_early_substitute_countdown_reload",
  "Reload value (120000) of transmission_temperature_early_substitute_countdown, applied in park / neutral (switch 20, "
  "switch_input_state_bits[2] mask 0x10) while the countdown is nonzero. ROM-copied dword, no _cal.")
G("0x0040b622", "fuel_flow_rate_working", "transmission_temperature_early_substitute_countdown",
  "While nonzero a double sensor fault gives transmission_temperature_early_substitute, at 0 the late one; it counts down by one "
  "per pass only while the engine is at the governor setpoint, the vehicle is above "
  "transmission_temperature_late_substitute_minimum_vehicle_speed and park / neutral is off, is reloaded in park / neutral while "
  "nonzero, and starts at 10 (cm848_resetTransmissionTemperatureValidation). Dump 120000 (the cap: the dump was taken in park / "
  "neutral). Written only in cm848_selectTransmissionTemperatureInUse and the reset; the 'fuel flow rate' reading of the old name "
  "has no fuel input anywhere.")

N("[W9 item 1 - things deliberately NOT renamed] (a) The 4-D fuelling tables and their factor, read by torque management and by SIX "
  "other functions (cm848_calculateDualAxisFuelLimit, cm848_calculateFuelDemandWithTrim, cm848_processActiveFaultList, "
  "cm848_processSpeedSensorCompensation, cm848_throttlePositionProcessing, governorCruiseStateMachine): fuel_demand_rpm_threshold_cal "
  "0x40688a / fuel_demand_rpm_limit_low_cal 0x4068b6 / fuel_demand_rpm_limit_high_cal 0x4068c0 and governor_fuel_table_xaxis_cal "
  "0x406968 / governor_fuel_table_ystart_cal 0x406994 / governor_fuel_table_yend_cal 0x40699e (rpm axis of 21, a throttle axis of 4 = "
  "0 / 25 / 50 / 100 percent, a 4 x 21 fuel grid; identical in the two sets here) with the lookup caches 0x40a8a1 / a3 / a5 / a7 and "
  "thermal_fuel_limit_factor 0x40a889 (Q14, 0x4000 = first set only, 0 = second set only; = combustion_alpha_input after the clamp "
  "unless fault status bit 0x10). e2m: Steady_State_RPM_Axis_4_D_Fuel / Steady_State_Throttle_Axis_4_D_Fuel / Steady_State_Table_4_D_"
  "Fuel and the Transient_* triple (21 values / 4 values / 4 x 21) at e2m 0x01105400-0x01105900, and the block 0x01105300 matches "
  "0x40a887 + n (e2m = ours + 0xCFAA79): Four_D_Fueling +0 = governor_proportional_gain_calc, Fuel_Interp_Factor +2 = "
  "thermal_fuel_limit_factor, +8 Filtered_Commanded_Throttle = fuel_demand_ema_tracked, +A the throttle decrease / transient flags = "
  "fuel_limit_mode_flags. So these are very probably the steady state (factor 1, 'open road' alpha) and transient (factor 0, 'urban') "
  "4-D fuelling tables and thermal_fuel_limit_factor is Fuel_Interp_Factor; the set order is the e2m order, which the data (equal "
  "sets) cannot confirm. That is a re-domaining of the driver demand fuel path and needs its own wave, not a rename of one cluster. "
  "(b) fuel_demand_timing_enable_flag 0x40b1ee (read by the type 1 branch): written only by "
  "cm848_updateParkNeutralFlagAndTsc1Activity (cpp 69805-69885) and fuel_demand_timing_initialize (1): 1 at boot, set when the "
  "TSC1 active-duration counter says TSC1 is lost / intermittent (fault 356 bit 0x10 set, the engine adds the three TSC1 sources to "
  "the ignored-request list and, with protection_feature_flags bit 0x40, shuts off the J1939 broadcasts), cleared when TSC1 has been "
  "active long enough; candidate j1939_tsc1_ignored_flag - not proposed (the name of the fault is not verified).")
