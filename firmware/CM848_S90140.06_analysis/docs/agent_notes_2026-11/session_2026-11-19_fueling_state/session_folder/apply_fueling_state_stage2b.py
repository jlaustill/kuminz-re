"""Stage 2b: FUELING_STATE_UNIDENTIFIED_<n> members for every code the firmware stores or compares but whose
algorithm is not proved yet. Without an exact member Ghidra 12.1 prints such a code as an OR of other members
(15 rendered as HIGH_SPEED_GOVERNOR | TSC1_SPEED_CONTROL | TSC1_TORQUE_CONTROL), which reads as a flag set.
Usage: apply_fueling_state_stage2b.py <CM848 output dir>"""
import os
import sys

OUT = sys.argv[1]
PLACEHOLDERS = {
    15: "stored - torque_derate_fuel_source_code (cm848_protection_limits): fuel_correction_upper_limit "
        "(cm848_calibrationGroup5_periodic) below the running derate",
    16: "stored - fuel_demand_minimum_tracked_state (cm848_trackMinimumFuelDemand): fuel_demand_load_based "
        "(cm848_fuelDemandBlendCalculator) below fuel_demand_minimum_tracked. RAM dump: 16",
    24: "stored - final_fueling_state (cm848_selectFuelDemandSource): cold_start_phase 4 (named ENGINE_RETARDER_ACTIVE - "
        "its own comment disagrees); the fuel is the ROM word 0x5c308",
    25: "stored - final_fueling_state (cm848_selectFuelDemandSource): cold_start_phase 5 (named ENGINE_OVERSPEED - its "
        "own comment disagrees); the fuel is the ROM word 0x5c30a",
    27: "stored - final_fueling_state (cm848_selectFuelDemandSource): cold_start_phase 8 (named ENGINE_STANDBY); the "
        "fuel is timing_limit_upper",
    32: "stored - final_fueling_state / fuel_demand_arbitrated_state: fuel_limit_mode_active_flag set without "
        "fuel_limit_secondary_flag - the fuel is fuel_demand_arbitrated_a",
    34: "stored - governor_fuel_limit_cap_state (cm848_checkProtectionParamLimit): governor_fuel_limit_override lowers "
        "governor_fuel_limit_cap while governor_fuel_active_flag (the power take-off flag of code 4) is 1",
    37: "only compared (engine_operating_mode / operating_mode_governor_output.mode_code / cruise_fuel_demand_mode_prev) - "
        "never stored in this build; e2m ASRFST lists 37 among the all-speed governor reference states",
    38: "only compared (engine_operating_mode / operating_mode_governor_output.mode_code / cruise_fuel_demand_mode_prev) - "
        "never stored in this build; e2m FSDSFLST lists 38 among the user fueling states",
    40: "stored - governor_fuel_limit_cap_state default (cm848_processProtectionSelection) and the starting value of "
        "fuel_demand_minimum_tracked_state (cm848_initProtectionStateWithFuelDemand)",
    42: "stored - torque_derate_fuel_source_code (cm848_applyProtectionLimit): protection_fuel_limit_working "
        "(cm848_calculateFuel2DTableLookup) in the variable speed governor (engine_operating_mode 7) while "
        "injection_timing_enable_flags bit 0 is set",
    46: "stored - torque_derate_fuel_source_code (protection_fuel_limit_check): cold_start_fuel_demand_ramp_output "
        "(fuel_coldStart_demandRamp_rateLimiter)",
    47: "only compared (final_fueling_state) - never stored in this build",
    49: "only compared (final_fueling_state) - never stored in this build",
    50: "only compared (final_fueling_state) - never stored in this build",
    59: "stored - fuel_demand_minimum_tracked_state (cm848_trackFuelDemandMinimum): fuel_demand_rate_output (the rate "
        "limiter of cm848_calculateFuelDemandLimit) while fault_feature_config_flags bit 2 is set",
}
for value, comment in PLACEHOLDERS.items():
    assert "," not in comment and '"' not in comment, value

OLD_TAIL = ("Codes stored but not proved yet: 15 16 24 25 27 32 34 40 42 46 59; codes only compared - never stored - so "
            "they have no member: 37 38 47 49 50")
NEW_TAIL = ("FUELING_STATE_UNIDENTIFIED_<n> members are codes the firmware stores (15 16 24 25 27 32 34 40 42 46 59) or "
            "only compares (37 38 47 49 50) whose algorithm is not proved yet: without an exact member Ghidra prints such "
            "a code as an OR of other members")

path = os.path.join(OUT, "enums.csv")
with open(path, newline="") as f:
    text = f.read()
eol = "\r\n" if "\r\n" in text else "\n"
lines = text.split(eol)
header = [i for i, line in enumerate(lines) if line.startswith("# Fueling State (renamed 2026-11-19") and OLD_TAIL in line]
assert len(header) == 1, header
lines[header[0]] = lines[header[0]].replace(OLD_TAIL, NEW_TAIL)
rows = [j for j, line in enumerate(lines) if line.startswith("FUELING_STATE,")]
assert rows == list(range(rows[0], rows[0] + 30)), "FUELING_STATE rows are not one block of 30"
members = {int(lines[j].split(",")[1], 0): lines[j] for j in rows}
assert not set(members) & set(PLACEHOLDERS), sorted(set(members) & set(PLACEHOLDERS))
for value, comment in PLACEHOLDERS.items():
    members[value] = f"FUELING_STATE,{value},FUELING_STATE_UNIDENTIFIED_{value},{comment},2"
lines[rows[0]:rows[-1] + 1] = [members[v] for v in sorted(members)]
with open(path, "w", newline="") as f:
    f.write(eol.join(lines))
print(f"applied stage 2b: {len(members)} members")
