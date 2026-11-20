"""Stage 9b token refresh that refresh_references.py does not cover:
- the struct renames: `<old instance>.<old field>` -> `<new instance>.<new field>`, `<old type>.<old field>` ->
  `<new type>.<new field>`, then the bare old instance / type names (outside "(was ...)" notes and the "the struct was
  <old type>" history phrases);
- the old enum members of DEVELOPMENT_MODE_STATE (SESSION_ACTIVE / STANDING_BY), as whole tokens;
- CM550 relocation_map.csv: the two rows whose source_name is now a shared name.
usage: refresh_stage9b_tokens.py <repo>"""
import os
import re
import sys

repo = sys.argv[1]
O848 = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
FIELDS = {"boost_pressure_state_t": ("charge_flow_estimate_terms_t", "boost_pressure_state_t_0040a406",
                                     "charge_flow_estimate_terms",
                                     {"load_input": "intake_manifold_temperature_rankine",
                                      "rpm_modifier": "volumetric_efficiency_mach",
                                      "lookup_result": "volumetric_efficiency_square_root",
                                      "computed_value": "flow_area_constant", "reserved_0a": "charge_flow_source",
                                      "reserved_0e": "fresh_air_flow_source"}),
          "engine_sync_state_t": ("fuel_pressure_governor_state_t", "engine_sync_state_t_0040b87f",
                                  "fuel_pressure_governor_state", {"reserved_05": "filtered_battery_voltage"})}
ENUM = {"SESSION_ACTIVE": "DEVELOPMENT_MODE_OFF", "STANDING_BY": "DEVELOPMENT_MODE_ON"}
HISTORY = re.compile(r"(\((?:was|were) [^)]*\)|the struct was (?:boost_pressure_state_t|engine_sync_state_t)\b)")


def refresh(text):
    for old_type, (new_type, old_instance, new_instance, fields) in FIELDS.items():
        for base_old, base_new in ((old_instance, new_instance), (old_type, new_type)):
            text = re.sub(rf"\b{re.escape(base_old)}\.(\w+)",
                          lambda m: f"{base_new}.{fields.get(m.group(1), m.group(1))}", text)
        text = re.sub(rf"\b{re.escape(old_instance)}\b", new_instance, text)
        text = re.sub(rf"\b{re.escape(old_type)}\b", new_type, text)
    for old, new in ENUM.items():
        text = re.sub(rf"\b{old}\b", new, text)
    return text


counts = {}
for name in ("global_variables.csv", "function_renames.csv", "structure_definitions.csv", "enums.csv",
             "function_definitions.csv", "local_variables.csv", "labels.csv", "deleted_functions.csv"):
    path = os.path.join(O848, name)
    if not os.path.exists(path):
        continue
    lines = open(path, newline="").read().split("\n")
    changed = 0
    for i, line in enumerate(lines):
        if not line.startswith(("0x", "\"", )) and "," not in line:
            continue
        if name == "structure_definitions.csv" and line.split(",", 1)[0] in ("charge_flow_estimate_terms_t",
                                                                              "fuel_pressure_governor_state_t"):
            pass                                             # the struct rows themselves were rewritten by the apply
        parts = HISTORY.split(line)
        new = "".join(p if HISTORY.fullmatch(p) else refresh(p) for p in parts)
        if new != line:
            lines[i] = new
            changed += 1
    open(path, "w", newline="").write("\n".join(lines))
    counts[name] = changed
reloc = os.path.join(repo, "firmware", "CM550_J90350.00_analysis", "output", "relocation_map.csv")
text = open(reloc, newline="").read()
for old, new in (("0x00b3ae,timingProtectionFlagsOrchestrator,0x00c582,", "0x00b3ae,calculateAlphaBase,0x00c582,"),
                 ("0x035488,vp44RpmBasedFaultDetector,0x00c326,", "0x035488,calculateAlpha,0x00c326,")):
    assert text.count(old) == 1, old
    text = text.replace(old, new)
open(reloc, "w", newline="").write(text)
print(counts, "| relocation_map.csv: 2 rows")
