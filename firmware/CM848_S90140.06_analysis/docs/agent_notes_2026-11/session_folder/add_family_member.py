"""Add 0x5a462 (mode-6 member of the per-mode family) to bin 12 as a synthetic lookup."""
import json
import sys

d = sys.argv[1]
lookups = json.load(open(f"{d}/lookups.json"))
template = next(lk for lk in lookups if any(t["address"] == "0x0005a458" for t in lk["tables"]))
axis = next(t for t in template["tables"] if t["role"] == "x_axis")
synthetic = {
    "id": "L237", "interpolator": "lookupTableInterpolation", "kind": "1-D",
    "tables": [axis, {"role": "values", "address": "0x0005a462", "current_name": None, "to_name": True,
                      "shared_by_lookups": ["L237"],
                      "contents": {"region": "rom", "words": 5, "values_unsigned": [0, 0, 0, 350]}}],
    "calls": [{"function": "cm848_calculateSpeedControlError",
               "statement": "in_r6 = <table chosen by fuel_operation_mode_index: 1 -> WORD_ARRAY_0005a430, 2 -> "
                            "WORD_ARRAY_0005a43a, 3 -> WORD_ARRAY_0005a444, 4 -> WORD_ARRAY_0005a44e, 5 -> "
                            "WORD_ARRAY_0005a458, 6 -> WORD_ARRAY_0005a462>; wVar1 = lookupTableInterpolation "
                            "(&fuel_ema_mode_slot_state_1,engine_rpm_state_t_0040b7ac.current_rpm,"
                            "governor_load_xaxis_cal,in_r6,0); ... j1939_engine_torque_encoded = (wVar1 * "
                            "throttle_demand_integrator) / WORD_ARRAY_0005a462[4]; (C line ~20066); also "
                            "governor_speed_percentage_cal = WORD_ARRAY_0005a462[4] (mode 6 default, C line ~21606)",
               "inputs": ["engine_rpm_state_t_0040b7ac.current_rpm"], "output_argument": None}],
    "note": "0x0005a462 is the mode-6 member of the same six-table family as the tables of L225..L229 "
            "(fuel_operation_mode_index 1..6); name all six consistently (same base pattern, the mode "
            "number as the only difference)."}
assert template["tables"][0]["role"] == "x_axis"
lookups.append(synthetic)
json.dump(lookups, open(f"{d}/lookups.json", "w"), indent=1)
b = json.load(open(f"{d}/bin_12.json"))
b["assigned_tables"].append("0x0005a462")
b["lookups"].append(synthetic)
json.dump(b, open(f"{d}/bin_12.json", "w"), indent=1)
print("added; values check:", synthetic["tables"][1]["contents"])
