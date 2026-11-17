import json
import re
import runpy

RESULT = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_G1b.jsonl"
items = [json.loads(line) for line in open(RESULT)]


def find(kind, address):
    matches = [item for item in items if item["kind"] == kind and item.get("address", "").lower() == address.lower()]
    assert len(matches) == 1, (kind, address, len(matches))
    return matches[0]


# 1. 0x004090f6 becomes uncertain (state 2 and state 4 of the TPU handler use opposite polarity).
row = find("global", "0x004090f6")
row["verdict"] = "uncertain"
del row["new"]
row["evidence"] = (
    "Read in three places: state 2 of engine_injectionAngle_tpuChannel6EventHandler adds the main on-time (as an angle) "
    "to the third start angle when the value is nonzero, state 4 adds it when the value is 0 (opposite polarity), and "
    "cm848_calculateEngineFaultTiming subtracts the main on-time from the interval when it is 0. The e2m flag "
    "Aux_SOI_End_Of_Main_Adjust ('adjust Aux SOI to be relative to Main EOI') is the likely meaning, but the state 4 "
    "polarity does not fit, so no name until the handler's two angle paths are traced. Value 1 in the dump."
)

# 2. 0x0040b8a8 evidence closed with the fault decode.
row = find("global", "0x0040b8a8")
row["evidence"] = (
    "Writer cm848_checkProtectionFaultConditions sets it when any of 8 registered faults is enabled in "
    "engine_sync_enable_mask; one of them is fault 333 (fault_registered_bits_320_to_335 & 0x2000), which firmware/CLAUDE.md "
    "gives as P0251 fuel metering, the rail pressure actuator. The three readers are all fuel pressure limp-home "
    "substitutions: the pilot quantity default (DAT_00409e68), the main timing addend (DAT_00409e7c when set / DAT_00409e7e "
    "when clear, e2m Main_SOI_Fuelpr_Derate_Default / _No_Derate) and injection_timing_demand_cyl5 fault / normal. e2m "
    "HPCR_Fuelpr_Limp_Home is a one-byte flag: 'loss of fuelpr control resulting in timing & pilot qty adjust'. The other "
    "7 fault bits were not decoded."
)

# 3. 0x0040b766 evidence no longer says written only by one function.
row = find("global", "0x0040b766")
row["evidence"] = (
    "Computed in engine_injectionAngle_updateCutoutAndTimingDemand (also zeroed in one other place): "
    "fuel_demand_computed_snapshot x scale / 51200 + the per-cylinder trim, clamped 0..5888 (0x1700). It is the cylinder's "
    "whole quantity (pilot + main + auxiliary): copied to engine_timing_reference_high / _low, to injection_fuel_quantity_snapshot "
    "(added to injected_fuel_running_total per injection) and used as the load axis of the injection timing tables."
)

# 4. Plates for the pilot and auxiliary quantity functions: say what the code gates on, new names.
row = find("function", "0x0052ba30")
row["plate_comment"] = (
    "Computes the pilot injection quantity pilot_quantity_unscaled (0.0679 mm3 per count): the blended pilot_quantity map "
    "and the coolant, intake-temperature, ambient, boost and cold corrections are combined by sum / max / min wins "
    "(pilot_quantity_logic_select, 2 = min in the RAM dump), slew-limited, and capped at fuel_demand_computed x DAT_00409e66 / 4096 "
    "(half in the dump). The result is 0 when crank_position_valid_flag is set with the DAT_00409e62 switch on, or in the "
    "free-acceleration shutoff (coolant and intake limits are 300 F in the dump), and a fixed value while "
    "fuel_pressure_limp_home_active_flag is set. cm848_fuel_demand_state_capture snapshots it into 0x3fd07e and "
    "engine_injectionAngle_updateCutoutAndTimingDemand turns it into pilot_injection_quantity (was cm848_torque_limit_state_update)."
)
row = find("function", "0x000466a8")
row["plate_comment"] = (
    "Computes the auxiliary (third, after-main) injection quantity auxiliary_quantity_unscaled: the blended "
    "injection_quantity_auxiliary map and the coolant, ambient and boost terms are selected by max or min wins "
    "(auxiliary_quantity_logic_select: 1 = max, 2 = min), replaced by an override value when enabled, and set to 0 when "
    "crank_position_valid_flag is set with engine_sync_force_reset_cal = 1. cm848_fuel_demand_state_capture copies it to 0x3fd080 and "
    "engine_injectionAngle_updateCutoutAndTimingDemand uses it, scaled, as the cap of auxiliary_injection_quantity; the winning "
    "term goes to auxiliary_quantity_source_code (was cm848_calculateGovernorOutput)."
)

# 5. Evidence wording fixes.
row = find("global", "0x0040b956")
row["evidence"] = (
    "Written in cm848_torque_limit_state_update with the winning term: 1 map blend, 2 coolant, 3 intake temperature, 4 ambient, "
    "5 boost, 6 cold-start coolant curve, 7 override, 11 sum, 13 ratio cap reached, 14 forced zero or negative, 15 fuel pressure "
    "limp home, 16 / 17 cold correction, 19 cold-start override; packed with the other event source codes by "
    "cm848_updateEngineStatusFlags. e2m Pilot_Fuel_State."
)
row = find("global", "0x0040b820")
row["evidence"] = (
    "Written 3 times in cm848_calculateGovernorOutput, never read in code: 14 forced zero (crank_position_valid_flag set with "
    "the switch on), 7 override, 1 map blend, 2 coolant, 4 ambient, 5 boost. Diagnostic of which term controls the auxiliary "
    "quantity; e2m Aux_Quantity_State at offset 0xC."
)

# 6. Minimum on-time table names end with the quantity, like the maximum names.
for address, old_new in (("0x0005f230", "injection_pulse_width_minimum_axis"), ("0x0005f242", "injection_pulse_width_minimum_values")):
    find("global", address)["new"] = old_new

# 7. e2m note caveat.
for item in items:
    if item["kind"] == "note" and item["text"].startswith("Cross-check source for all the proposals above"):
        item["text"] = item["text"].replace(
            "Use these names for neighbouring globals; the e2m virtual addresses are not CM848 addresses, only the offsets match.",
            "Use these names for neighbouring globals. The match is by consecutive block layout (offsets and sizes, including the "
            "two dword fields), checked against the code behaviour and the RAM dump values; it is NOT by address, since the e2m "
            "virtual addresses are not CM848 addresses (the project's standing note against e2m cross-referencing is about address lookups).",
        )
        assert "NOT by address" in item["text"]

# 8. Plates cite the proposed new names (text before '(was ...)'); evidence keeps the current names.
mapping = {}
for item in items:
    if item["kind"] in ("global", "function") and item.get("new"):
        mapping[item["old"]] = item["new"]
ordered = sorted(mapping, key=len, reverse=True)
pattern = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(re.escape(name) for name in ordered) + r")(?![A-Za-z0-9_])")
for item in items:
    if item["kind"] == "function":
        head, separator, tail = item["plate_comment"].partition(" (was ")
        assert separator
        item["plate_comment"] = pattern.sub(lambda match: mapping[match.group(1)], head) + separator + tail

with open(RESULT, "w") as handle:
    for item in items:
        handle.write(json.dumps(item, ensure_ascii=False) + "\n")

runpy.run_path("/home/linux/.claude/jobs/d55ae3c6/tmp/renames/g1b_validate.py")
for item in items:
    if item["kind"] == "function":
        print(item["address"], item["new"])
        print("   ", item["plate_comment"][:700])
