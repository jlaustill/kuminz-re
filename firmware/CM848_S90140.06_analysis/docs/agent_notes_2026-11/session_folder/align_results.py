"""Vocabulary pass over the verification results: write renames/aligned_*.jsonl and renames/manual.jsonl."""
import json
import os
import sys

d = sys.argv[1]
PREFIX = [("pilot_injection_timing_offset_", "injection_timing_pilot_offset_"),
          ("pilot_quantity_", "injection_quantity_pilot_"),
          ("auxiliary_quantity_", "injection_quantity_auxiliary_")]
SUFFIX = [("_lookup_cached_offset", "_cached_axis_offset"), ("_interpolation_state", "_cached_axis_offset")]
EXACT = {"fuel_pressure_governor_demand_idle_check_minimum_coolant_temperature":
         "fuel_pressure_governor_demand_idle_minimum_coolant_temperature"}
NEW_ROWS = {"0x0040b8b8", "0x0040b8be", "0x0040b8ea"}      # unnamed DAT_: added as new rows by hand


def fix(name):
    for o, n in PREFIX:
        if name.startswith(o):
            name = n + name[len(o):]
    for o, n in SUFFIX:
        if name.endswith(o):
            name = name[: -len(o)] + n
    return EXACT.get(name, name)


def fix_text(text):
    for o, n in PREFIX + SUFFIX:
        text = text.replace(o, n)
    for o, n in EXACT.items():
        text = text.replace(o, n)
    return text


changed = 0
for g in ("G1a", "G1b", "G2", "G3", "G4"):
    out = []
    for line in open(os.path.join(d, f"result_{g}.jsonl")):
        line = line.strip()
        if not line:
            continue
        r = json.loads(line)
        if r.get("kind") == "global" and r.get("address") in NEW_ROWS:
            continue
        if r.get("new"):
            n = fix(r["new"])
            changed += n != r["new"]
            r["new"] = n
        for k in ("plate_comment", "evidence"):
            if r.get(k):
                r[k] = fix_text(r[k])
        out.append(json.dumps(r))
    open(os.path.join(d, f"aligned_{g}.jsonl"), "w").write("\n".join(out) + "\n")
manual = [
    {"kind": "function", "address": "0x0052d140", "old": "cm848_pressure_control_state_load", "verdict": "confirmed",
     "new": "cm848_calculatePilotInjectionTiming",
     "plate_comment": "Pilot injection timing: calls cm848_calculatePilotInjectionTimingOffset (unless the override "
                      "DAT_00409e6e is set), adds the offset to main_injection_timing (unless DAT_00409e72 is set), "
                      "uses injection_timing_pilot_offset_governor_limit_floor while the governor speed limit holds the "
                      "main timing at its limit, then caps the result at the earliest schedulable angle for the engine "
                      "speed. The result pilot_injection_timing is the TPU-A channel 5 slot 4 angle. RAM dump: 87 + 162 "
                      "= 249. (was cm848_pressure_control_state_load)",
     "evidence": "verified 2026-11-16 from the decompiled body; G1a traced the consumer chain"},
    {"kind": "global", "address": "0x00409e76", "old": "injection_timing_offset_governor_limit_floor", "verdict": "confirmed",
     "new": "injection_timing_pilot_offset_governor_limit_floor",
     "evidence": "the pilot timing offset used in place of the computed one while governor_speed_limit_active_flag is set "
                 "and the main timing sits at its governor limit (cm848_calculatePilotInjectionTiming)"},
    {"kind": "global", "address": "0x0040b998", "old": "engine_timing_arb_byte_24_31", "verdict": "confirmed",
     "new": "injection_timing_pilot_source_code",
     "evidence": "which term set the pilot timing: 0 computed offset, 7 the override DAT_00409e6e, 8 the governor-limit "
                 "floor (cm848_calculatePilotInjectionTiming)"},
]
open(os.path.join(d, "manual.jsonl"), "w").write("\n".join(json.dumps(m) for m in manual) + "\n")
print("names changed by the vocabulary pass:", changed)
