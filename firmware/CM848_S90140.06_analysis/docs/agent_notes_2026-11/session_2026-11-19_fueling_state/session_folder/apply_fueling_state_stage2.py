"""Stage 2 of the FUELING_STATE change (2026-11-19, PR #52): the limiter, combustion and final stages.
Adds the members whose setter proves them, types the ten carriers of those stages with FUELING_STATE and names the
state words after the fuel value each one belongs to. Every old row is asserted before it is replaced.
Usage: apply_fueling_state_stage2.py <CM848 output dir>"""
import os
import sys

OUT = sys.argv[1]


def edit(path, fn):
    with open(path, newline="") as f:
        text = f.read()
    eol = "\r\n" if "\r\n" in text else "\n"
    lines = fn(text.split(eol))
    with open(path, "w", newline="") as f:
        f.write(eol.join(lines))


def one(lines, predicate, what):
    hits = [i for i, line in enumerate(lines) if predicate(line)]
    if len(hits) != 1:
        sys.exit(f"expected one {what}, found {len(hits)}")
    return hits[0]


# ---------------------------------------------------------------- enums.csv
NEW = {
    13: ("CALIBRATED_FIXED_FUEL_LIMIT", "torque_derate_fuel_source_code (cm848_processProtectionSelection): while "
         "governor_feature_flags bit 0x10 is set the EEPROM limit protection_fuel_limit_c_working (EEPROM 0x380) "
         "replaces the whole derate chain. Off in the dump: the flags are 0x1020 and the limit is 5888"),
    19: ("MAXIMUM_FUEL_CURVE", "torque_derate_fuel_source_code starting value (cm848_initProtectionStateWithFuelDemand): "
         "protection_fuel_limit_cal_active - cm848_processActiveFaultList(engine speed / 400) blends two engine speed x "
         "400 fuel tables by thermal_fuel_limit_factor - before any derate source takes over"),
    20: ("TSC1_TORQUE_LIMIT", "torque_derate_fuel_source_code (cm848_applySpeedControlProtectionLimit): J1939 TSC1 "
         "override control mode 3 with etc1_mode3_torque_limit below the running derate"),
    22: ("ENGINE_STARTING", "final_fueling_state (cm848_selectFuelDemandSource): cold_start_phase 2 / 6 (above the start "
         "rpm trigger) or 7 with the command below it; the fuel is governor_cold_start_rpm_output"),
    23: ("FUEL_OVERRIDE", "final_fueling_state while governor_feature_flags bit 2 is set (fuel_timing_target_working) "
         "and injection_quantity_combustion_reference_source_code while "
         "combustion_override_and_estimation_enable_flags_cal bit 9 is set "
         "(injection_quantity_combustion_reference_override_value)"),
    26: ("ENGINE_STOPPED", "final_fueling_state (cm848_selectFuelDemandSource): cold_start_phase 1 - the final fuel is 0. "
         "RAM dump (key on / engine stopped): 26 with cold_start_phase 1"),
    28: ("FUEL_PRESSURE_FAULT_LIMIT", "torque_derate_fuel_source_code (cm848_applyFuelPressureFaultFuelLimit): "
         "fuel_pressure_fault_fuel_limit_working from cm848_applyFuelLimitsForFuelPressureFaults (rail pressure faults) - "
         "e2m block 105D +4 FSAPLMFL fuel system specific fuel derate"),
    29: ("FAULT_DERATE", "torque_derate_fuel_source_code (cm848_enforceFuelLimitProtection): fault_derate_fuel_limit from "
         "cm848_calculateFaultDerateFuelLimit. The CM550-era e2m label for 29 is ATDERAT: CM848 numbers its limiters "
         "differently above 12"),
    41: ("IMMOBILIZER_FUEL_DISABLE", "final_fueling_state (cm848_selectFuelDemandSource): immobilizer_fuel_disable_flag "
         "is 1 - the final fuel is 0"),
    45: ("TORQUE_MANAGEMENT", "torque_derate_fuel_source_code (cm848_applyTorqueManagementFuelLimit): "
         "torque_management_fuel_limit"),
    52: ("COMBUSTION_DENSITY_MAXIMUM", "injection_quantity_combustion_gross_source_code "
         "(cm848_calculateCombustionGrossFuel): the density maximum (engine speed x ambient_air_density) limits the "
         "gross fuel"),
    53: ("COMBUSTION_CHI_MAXIMUM", "injection_quantity_combustion_gross_source_code (cm848_calculateCombustionGrossFuel): "
         "the chi maximum fuel limits the gross fuel"),
    54: ("COMBUSTION_TEMPERATURE_HEADROOM", "injection_quantity_combustion_reference_source_code "
         "(cm848_calculateCombustionFuelReference): injection_quantity_temperature_headroom_cap"),
    55: ("COMBUSTION_GROSS_FUEL_OVERRIDE", "injection_quantity_combustion_gross_source_code: "
         "combustion_override_and_estimation_enable_flags_cal bit 10 - injection_quantity_combustion_gross_override_value"),
    58: ("COMBUSTION_OXYGEN_LIMIT", "injection_quantity_combustion_reference_source_code "
         "(cm848_calculateCombustionFuelReference): injection_quantity_oxygen_limit"),
    61: ("RAIL_PRESSURE_SHORTFALL_LIMIT", "torque_derate_fuel_source_code "
         "(cm848_limitFuelQuantityOnRailPressureShortfall)"),
    62: ("FUEL_PRESSURE_GOVERNOR_FAULT_BLEND", "torque_derate_fuel_source_code (cm848_processSafetyConditionProtection "
         "while safety_system_enable_cal is set): injection_quantity_combustion_chi_maximum - blended toward an engine "
         "speed table limit while fault 57 / 58 / 60 (P1221 / P1222 / P1223 - the fuel pressure governor plausibility "
         "checks) or 59 is set. RAM dump: 62"),
}
for value, (_, comment) in NEW.items():
    assert "," not in comment and '"' not in comment, value

OLD_HEADER_START = "# Fueling State (renamed 2026-11-19 from ENGINE_OPERATING_MODE)"
NEW_HEADER = (
    "# Fueling State (renamed 2026-11-19 from ENGINE_OPERATING_MODE): the code of the algorithm in control of the fuel - "
    "one numbering for every fueling stage (Cummins e2m FSDSFLST user fueling state 1-8 / 38 - FSGVFLST governed "
    "fueling state 1-12 - FSLMFLST limited state 13-41 - FSFNFLST final state 1-41; CM848 uses codes up to 62). "
    "Carriers: engine_operating_mode (the user stage; members 1-8 / 30 corrected 2026-11-17 from every store of "
    "0x40b000) -> operating_mode_governor_output.mode_code (power take-off selection adds 4) -> "
    "governor_fuel_demand_working_mode (cruise adds 9) -> governor_fuel_demand_mode (the governed stage adds 10 / 11 / "
    "12) -> requested_fueling_state / fuel_demand_arbitrated_state (cm848_processProtectionSelection: the governed fuel "
    "against torque_derate_fuel_source_code - the derate stage 13-62 - and fuel_demand_minimum_tracked_state) -> "
    "injection_quantity_combustion_gross_source_code / _reference_source_code (the combustion stage 52-58) -> "
    "final_fueling_state (the engine-state overrides 22-41). Codes stored but not proved yet: 15 16 24 25 27 32 34 40 "
    "42 46 59; codes only compared - never stored - so they have no member: 37 38 47 49 50")


def enums(lines):
    i = one(lines, lambda line: line.startswith(OLD_HEADER_START), "FUELING_STATE header")
    lines[i] = NEW_HEADER
    rows = [j for j, line in enumerate(lines) if line.startswith("FUELING_STATE,")]
    assert rows == list(range(rows[0], rows[0] + 13)), "FUELING_STATE rows are not one block of 13"
    existing = {int(lines[j].split(",")[1], 0): lines[j] for j in rows}
    assert not set(existing) & set(NEW), "a new value already has a member"
    merged = dict(existing)
    for value, (name, comment) in NEW.items():
        merged[value] = f"FUELING_STATE,{value},FUELING_STATE_{name},{comment},2"
    lines[rows[0]:rows[-1] + 1] = [merged[v] for v in sorted(merged)]
    return lines


edit(os.path.join(OUT, "enums.csv"), enums)

# ---------------------------------------------------------------- global_variables.csv
GLOBALS = {   # address: (old name, old type, new name, new comment or None to keep and append)
    "0x0040afae": ("torque_derate_fuel_source_code", "word", "torque_derate_fuel_source_code", None),
    "0x0040a2d4": ("governor_fuel_mode_arbitrated", "word", "requested_fueling_state",
                   "State of fuel_demand_arbitration_working (Cummins FSLMDSST requested fueling state): "
                   "cm848_processProtectionSelection writes governor_fuel_demand_mode when the governed fuel is below "
                   "torque_derate_fuel_quantity - else torque_derate_fuel_source_code (as CM550 writes FSLMDSST from its "
                   "1-12 or 13-41 word); nothing reads it (was governor_fuel_mode_arbitrated)"),
    "0x003fa874": ("governor_fuel_mode_prev", "word", "fuel_demand_arbitrated_state",
                   "State of fuel_demand_arbitrated, set with it in cm848_processProtectionSelection: "
                   "requested_fueling_state or fuel_demand_minimum_tracked_state (or 32 / 11 in the limit-mode and low "
                   "speed governor branches); copied to fuel_demand_arbitrated_state_snapshot. Not a previous-pass value "
                   "(was governor_fuel_mode_prev)"),
    "0x0040a2e2": ("governor_fuel_mode_snapshot", "word", "fuel_demand_arbitrated_state_snapshot",
                   "fuel_demand_arbitrated_state copied at the end of cm848_processProtectionSelection (with "
                   "fuel_demand_arbitrated_prev_snapshot); cm848_calculateCombustionGrossFuel passes it on to "
                   "injection_quantity_combustion_gross_source_code. RAM dump: 62 (was governor_fuel_mode_snapshot)"),
    "0x0040afb4": ("governor_fuel_mode_input", "word", "fuel_demand_minimum_tracked_state",
                   "State of fuel_demand_minimum_tracked: 40 from cm848_initProtectionStateWithFuelDemand - then 16 "
                   "(cm848_trackMinimumFuelDemand: fuel_demand_load_based) or 59 (cm848_trackFuelDemandMinimum: "
                   "fuel_demand_rate_output) when theirs is lower. RAM dump: 16 (was governor_fuel_mode_input)"),
    "0x0040a2da": ("governor_fuel_mode_command_cached", "word", "governor_fuel_limit_cap_state",
                   "The code cm848_calculateProtectionRateLimited gives its scaled limit in "
                   "torque_derate_fuel_source_code: 40 - or 34 when cm848_checkProtectionParamLimit lowers "
                   "governor_fuel_limit_cap to governor_fuel_limit_override while governor_fuel_active_flag is 1 (was "
                   "governor_fuel_mode_command_cached)"),
    "0x003fa6d0": ("governor_fuel_mode_working", "word", "injection_quantity_combustion_gross_source_code",
                   "State of injection_quantity_combustion_gross (cm848_calculateCombustionGrossFuel): "
                   "fuel_demand_arbitrated_state_snapshot - or 55 for the override calibration - or 52 / 53 when the "
                   "density / chi maximum limits it. RAM dump: 62 (was governor_fuel_mode_working)"),
    "0x0040a4f0": ("injection_quantity_combustion_reference_source_code", "word",
                   "injection_quantity_combustion_reference_source_code", None),
    "0x0040a2d0": ("governor_mode_code", "word", "final_fueling_state",
                   "The final fueling state (Cummins FSFNFLST - e2m block 1051 +2 with FSFNFL = fuel_demand_computed at "
                   "+0): cm848_selectFuelDemandSource starts from injection_quantity_combustion_reference_source_code "
                   "and overrides it by the engine state (22 starting / 26 stopped / 41 immobilizer / 23 override / 24 "
                   "25 27 by cold_start_phase / 32 limit mode). Freeze frames keep its low byte "
                   "(fault_entry_t.final_fueling_state). RAM dump: 26 (was governor_mode_code)"),
    "0x0040a2de": ("governor_mode_code_prev", "word", "final_fueling_state_prev",
                   "final_fueling_state of the last pass (was governor_mode_code_prev)"),
}


def globals_(lines):
    for address, (old, old_type, new, comment) in GLOBALS.items():
        i = one(lines, lambda line, a=address, o=old: line.startswith(f"{a},{o},"), f"row {address} {old}")
        parts = lines[i].split(",", 3)
        assert parts[2] == old_type, (address, parts[2])
        old_comment = parts[3] if len(parts) > 3 else ""
        if comment is None:
            comment = (old_comment + " | " if old_comment else "") + "typed FUELING_STATE 2026-11-19"
            if address == "0x0040afae":
                comment += (" (Cummins FSLMFLST - e2m block 105D +2 with FSLMFL = torque_derate_fuel_quantity at +0 "
                            "and FSAPLMFL = fuel_pressure_fault_fuel_limit_working at +4). RAM dump: 62")
            else:
                comment += ". RAM dump: 62"
        lines[i] = f"{address},{new},FUELING_STATE,{comment}"
    return lines


edit(os.path.join(OUT, "global_variables.csv"), globals_)

# ---------------------------------------------------------------- structure_definitions.csv
OLD_FIELD = "fault_entry_t,,governor_mode_code,byte,1,Pressure fuel adjustment byte,,verified"
NEW_FIELD = ("fault_entry_t,,final_fueling_state,byte,1,Low byte of final_fueling_state when the freeze frame was "
             "stored (hpcr_setFaultActiveStatus) (was governor_mode_code - Pressure fuel adjustment byte),,verified")


def structs(lines):
    lines[one(lines, lambda line: line == OLD_FIELD, "fault_entry_t.governor_mode_code")] = NEW_FIELD
    return lines


edit(os.path.join(OUT, "structure_definitions.csv"), structs)
print("applied stage 2")
