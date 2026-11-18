ROWS = []

# ---------------------------------------------------------------- fuel_demand_mode_code = e2m SOI_State
ROWS.append({
    "kind": "global", "address": "0x0040a2f2", "old": "fuel_demand_mode_code", "verdict": "confirmed",
    "new": "injection_timing_intermediate_source_code", "new_type": "INJECTION_TIMING_INTERMEDIATE_SOURCE",
    "evidence": (
        "Not a fuel demand word: it is the intermediate main injection timing state. CODE: the only stores are cm848_calculateInjectionTimingOffset "
        "(0 = timing offset from the two maps, 2 = fixed injection_timing_offset_cal while engine_mode_control_flags bit 8 is set), "
        "cm848_applyCombustionTimingLimits (28 = the minimum limit applied, 27 = the maximum limit applied) and cm848_storeFuelDemandPreviousValues "
        "(25, one of the last tasks of every pass of cm848_periodicTaskSet_auxiliaryControl); its only readers are the copies injection_timing_source_code_before_combustion_limits / "
        "_after_minimum_limit and cm848_calculateMainInjectionTiming, which turns 28 / 27 into the final source codes 30 / 29 when the base command "
        "won. E2M (relative offset): the block 0x40a2ee-0x40a2f6 = 0x01103B00-0x01103B08 (Four_D_Timing = the map offset, SOI, SOI_State 'Intermediate "
        "timing state used before final timing selection' TSTPTAST = this word, Timing_State_Incr TSSTIC = the flags word, Final_Timing_State "
        "TSFNTAST = main_injection_timing_source_code). Dump 25."),
})
ROWS.append({
    "kind": "global", "address": "0x0040a2f4", "old": "fuel_demand_mode_flags", "verdict": "confirmed",
    "new": "injection_timing_increment_flags",
    "evidence": (
        "Timing increment flags, e2m Timing_State_Incr (TSSTIC, 'Timing state increment parameter', HEX) at the same relative offset. CODE: "
        "cm848_setTimingIncrementFlags ORs 0x40 (fuel-limited increment), 0x20 (off-nominal timing adjustment) and 0x10 (user increment); "
        "cm848_calculateInjectionTimingOffset sets 1 when governor_feature_config_word bit 0x4000 adds injection_timing_offset_increment_cal; "
        "cm848_calculateCombustionTimingReference clears it at the end of the pass. The function name already says timing increment flags; the "
        "word was named for a fuel demand mode it never held."),
})
ROWS.append({
    "kind": "global", "address": "0x0040a476", "old": "injection_timing_source_code_before_combustion_limits", "verdict": "confirmed",
    "new_type": "INJECTION_TIMING_INTERMEDIATE_SOURCE",
    "evidence": "Write-only copy of the intermediate source code; type it with the same enum (not in a time-shared window). The copy at 0x3fa644 is in the 0x3F9800-0x3FDB30 window: leave it a word.",
})
ROWS.append({
    "kind": "global", "address": "0x0040a2f6", "old": "main_injection_timing_source_code", "verdict": "confirmed",
    "new_type": "MAIN_INJECTION_TIMING_SOURCE",
    "evidence": (
        "All 14 values are stored by constants (scan of both banks + .cpp): 5 cm848_calculateMainInjectionTiming cold start map; 7 "
        "cm848_updateMainInjectionTimingByDeliveryMode (delivery mode 2); 8 cm848_initTimingFilterStates; 11 demand floor; 18 base command (sum "
        "or winner); 19 / 20 / 21 / 22 intake temperature / coolant / barometric pressure / boost component winning; 23 governor limit minimum; 24 "
        "working minimum; 29 / 30 the combustion maximum / minimum limit (from intermediate 27 / 28); 31 fuel pressure limp home component. Not in a "
        "time-shared window. Needs one build to confirm the rendering."),
})

# ---------------------------------------------------------------- the enum rows
INTERMEDIATE = [
    (0, "OFFSET_MAPS", "cm848_calculateInjectionTimingOffset: the timing offset comes from the two engine speed x fuel demand maps blended by the combustion alpha (engine_mode_control_flags bit 8 clear)"),
    (2, "FIXED_OFFSET_CALIBRATION", "cm848_calculateInjectionTimingOffset: the fixed injection_timing_offset_cal while engine_mode_control_flags bit 8 is set"),
    (25, "PREVIOUS_VALUES_STORED", "cm848_storeFuelDemandPreviousValues: one of the last tasks of every pass stores the compensated reference as the previous value"),
    (27, "COMBUSTION_MAXIMUM_LIMIT", "cm848_applyCombustionTimingLimits: the timing reached the combustion maximum limit (cm848_calculateMainInjectionTiming turns it into 29)"),
    (28, "COMBUSTION_MINIMUM_LIMIT", "cm848_applyCombustionTimingLimits: the timing with the user increment is at or below the combustion minimum limit (becomes 30)"),
]
MAIN = [
    (5, "COLD_START_MAP", "cm848_calculateMainInjectionTiming: the cold start engine speed x coolant temperature map while cold_start_phase is CSP_ABOVE_RPM_TRIGGER / CSP_ABOVE_RPM_VIA_EVENTS / CSP_SETPOINT_UNDERRUN"),
    (7, "FIXED_OFFSET_CALIBRATION", "cm848_updateMainInjectionTimingByDeliveryMode: injection_delivery_mode 2 uses the fixed injection_timing_offset_cal"),
    (8, "INITIAL", "cm848_initTimingFilterStates: the value before the first pass"),
    (11, "DEMAND_FLOOR", "cm848_calculateMainInjectionTiming: the demand was raised to injection_timing_demand_floor"),
    (18, "BASE_COMMAND", "cm848_calculateMainInjectionTiming: the sum of the base command and the components (combination mode 0) or the base command won the highest / lowest comparison"),
    (19, "INTAKE_TEMPERATURE_COMPONENT", "cm848_calculateMainInjectionTiming: the intake temperature component won (combination mode 1 / other)"),
    (20, "COOLANT_COMPONENT", "cm848_calculateMainInjectionTiming: the coolant component won"),
    (21, "BAROMETRIC_PRESSURE_COMPONENT", "cm848_calculateMainInjectionTiming: the barometric pressure component won"),
    (22, "BOOST_COMPONENT", "cm848_calculateMainInjectionTiming: the boost component won"),
    (23, "GOVERNOR_LIMIT_MINIMUM", "cm848_calculateMainInjectionTiming: raised to injection_timing_main_governor_limit_minimum while governor_speed_limit_active_flag is set"),
    (24, "WORKING_MINIMUM", "cm848_calculateMainInjectionTiming: raised to injection_timing_demand_min_working"),
    (29, "COMBUSTION_MAXIMUM_LIMIT", "cm848_calculateMainInjectionTiming: the base command won and the intermediate source code was 27"),
    (30, "COMBUSTION_MINIMUM_LIMIT", "cm848_calculateMainInjectionTiming: the base command won and the intermediate source code was 28"),
    (31, "FUEL_PRESSURE_LIMP_HOME_COMPONENT", "cm848_calculateMainInjectionTiming: injection_timing_main_fuel_pressure_limp_home_component won"),
]
enum_rows = []
for v, n, c in INTERMEDIATE:
    enum_rows.append(f"INJECTION_TIMING_INTERMEDIATE_SOURCE,{v},INJECTION_TIMING_INTERMEDIATE_SOURCE_{n},{c},2")
for v, n, c in MAIN:
    enum_rows.append(f"MAIN_INJECTION_TIMING_SOURCE,{v},MAIN_INJECTION_TIMING_SOURCE_{n},{c},2")

ROWS.append({
    "kind": "note",
    "text": (
        "ENUMS (lead 3, fuel_demand_mode_code 27 / 28): two NEW enums, every value proven by a constant store; append to enums.csv "
        "(enum_name,value,member_name,comment,size; comments have no commas; size 2: all accesses are words). The two spaces share numbers with "
        "nothing else (25 / 27 / 28 mean something different in the fuel state space below). Typing: global_variables.csv 0x0040a2f2 word -> "
        "INJECTION_TIMING_INTERMEDIATE_SOURCE (loads lhz in cm848_applyCombustionTimingLimits, lha in cm848_calculateMainInjectionTiming; stores sth), "
        "0x0040a476 word -> the same, 0x0040a2f6 word -> MAIN_INJECTION_TIMING_SOURCE; no local or prototype change is needed because every store "
        "and compare is a plain global access in the .cpp. One build confirms the rendering. EXACT ROWS: " + " | ".join(enum_rows)
    ),
})

# ---------------------------------------------------------------- engine operating mode 37 / 38
ROWS.append({
    "kind": "note",
    "text": (
        "ENGINE_OPERATING_MODE 37 (0x25) and 38 (0x26): re-checked, NO members. A constant scan of both banks finds exactly eight stores of 0x40b000: "
        "30 cm848_restoreEngineOperatingMode (0xfb50), 7 cm848_initEngineOperatingMode (0x10154), 8 cm848_initEngineOperatingState (0x1e828), 1 "
        "cm848_setEngineOperatingMode1 (0x428bc), 5 cm848_setEngineOperatingMode5 (0x42900), 0 cm848_resetEngineOperatingMode (0x42938), 2 "
        "cm848_engineMode_reset (0x50309c), 6 cm848_transitionEngineOperatingMode (0x50db68). 37 is only compared (cm848_runOperatingModeSpeedGovernor "
        "runs the all-speed governor for 7 / 2 / 30 / 37, .cpp 9076, still printed as 0x25) and 38 only passed through "
        "(cm848_updateGovernorFromProtection, cm848_calculateDriverDemandPercentTorque); nothing in this build can produce them, so they stay "
        "numeric. A member would have to be named from a store."
    ),
})

# ---------------------------------------------------------------- the fuel state code space (0x40a4f0 etc.)
ROWS.append({
    "kind": "note",
    "text": (
        "REFERENCE SOURCE CODE 0x40a4f0 (23 / 52-58) is one value of the FUEL STATE code space, not a space of its own; NO enum rows proposed, with the "
        "proof table. The space is the e2m 'indicator as to which algorithm is in control of fueling' family: governor_mode_code 0x40a2d0 (final), "
        "governor_fuel_mode_command 0x40afae = Torque_Derate_Fueling_State FSLMFLST 0x01105D02 and governor_fuel_mode_input 0x40afb4 = "
        "Torque_Derate_Fueling_State_2 FSLMAHST 0x01105D08 (6 apart in both), governor_fuel_mode_command_cached 0x40a2da, governor_fuel_mode_snapshot "
        "0x40a2e2, governor_fuel_mode_working 0x3fa6d0 and injection_quantity_combustion_reference_source_code 0x40a4f0 = e2m CBR_Fuel_Ref_State "
        "0x0116A570 ('Enumerated source of CBR Fuel Reference', same relative offset as CBR_Chi_Source / CBR_Base_Chi_Source). The values are "
        "moved between these words (0x40a4f0 is copied into governor_mode_code by cm848_selectFuelDemandSource, governor_fuel_mode_working from the "
        "snapshot), so a store scan cannot show the value set of one word is closed. CONSTANTS STORED (value: function that stores it; the .cpp scan of "
        "every assignment by name + the instruction scan): 11 cm848_processProtectionSelection; 13 cm848_processProtectionSelection; 15 "
        "cm848_protection_limits; 16 cm848_trackMinimumFuelDemand; 19 cm848_initProtectionStateWithFuelDemand (initial); 20 "
        "cm848_applySpeedControlProtectionLimit; 22 cm848_selectFuelDemandSource (cold start rpm output); 23 cm848_selectFuelDemandSource (working "
        "target, governor_feature_flags bit 2) and cm848_calculateCombustionFuelReference (override calibration, mask 0x200); 24 "
        "cm848_selectFuelDemandSource (CSP_FUEL_MODE_SWITCH); 25 (CSP_SUSPENDED); 26 (CSP_CRANKING); 27 (CSP_ENGINE_STANDBY); 28 "
        "cm848_applyFuelPressureFaultFuelLimit; 29 cm848_enforceFuelLimitProtection; 32 cm848_selectFuelDemandSource (fuel limit mode active); 34 "
        "cm848_checkProtectionParamLimit; 40 cm848_processProtectionSelection and the initial value of governor_fuel_mode_input; 41 "
        "cm848_selectFuelDemandSource (immobilizer fuel disable); 42 cm848_applyProtectionLimit; 45 cm848_applyThermalFuelLimit; 46 "
        "protection_fuel_limit_check; 52 and 55 cm848_calculateCombustionGrossFuel (52 the normal gross, 55 the calibrated gross override); 54 "
        "cm848_calculateCombustionFuelReference (temperature headroom cap); 58 the same (oxygen limit); 59 cm848_trackFuelDemandMinimum; 61 "
        "cm848_limitFuelQuantityOnRailPressureShortfall; 62 cm848_processSafetyConditionProtection. Also compared: 12 = the high speed governor "
        "(selectFuelDemandSource, presetHighSpeedGovernorIntegrator), 49 (0x31), 62 in the dump of 0x40a4f0 (= the incoming demand source). Why no "
        "enum yet: about a third of the storing functions still carry the generic 'protection' names (their roles are not settled) and the e2m has "
        "no enumeration text, so most member names would be guesses. Once those functions are named, the member names follow from this table. "
        "Collision to remember: 25 / 27 / 28 are different things in INJECTION_TIMING_INTERMEDIATE_SOURCE."
    ),
})
