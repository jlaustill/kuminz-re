"""Stage 1 follow-up: bare old field names in five comments that refresh_references.py cannot see (a bare
'reserved_0c' also names fields of other structs, so only these rows are edited).
Usage: fix_bare_fields.py <firmware output dir>"""
import os
import sys

out = sys.argv[1]
EDITS = {
    "function_renames.csv": {
        "0x0001242c,": [("rpm_conversion = +E", "downstream_egr_pressure_ratio = +E"),
                        ("reserved_0c = +C", "downstream_egr_corrected_flow = +C"),
                        ("reserved_16 = +16", "egr_orifice_temperature_rankine_square_root = +16"),
                        ("load_based_trim = +8", "downstream_egr_mass_flow = +8")],
        "0x000125f4,": [("reserved_12 = +12", "upstream_egr_corrected_flow = +12"),
                        ("reserved_10 = +10", "exhaust_temperature_rankine_square_root = +10"),
                        ("rpm_based_trim = +A", "upstream_egr_mass_flow = +A")],
        "0x000127bc,": [("(upstream, rpm_based_trim)", "(upstream, upstream_egr_mass_flow)"),
                        ("(downstream, load_based_trim)", "(downstream, downstream_egr_mass_flow)")],
    },
    "global_variables.csv": {
        "0x0040a404,": [("into throttle_conversion.", "into egr_flow_estimate_terms.oxygen_flow_delay_milliseconds.")],
        "0x0040a564,": [("first-order filter of final_trim)",
                         "first-order filter of egr_flow_estimate_terms.egr_mass_flow_before_delay)")],
    },
}
for name, rows in EDITS.items():
    path = os.path.join(out, name)
    lines = open(path).read().split("\n")
    for i, line in enumerate(lines):
        for prefix, pairs in rows.items():
            if line.startswith(prefix):
                for old, new in pairs:
                    assert line.count(old) == 1, (name, prefix, old)
                    line = line.replace(old, new)
                lines[i] = line
    open(path, "w").write("\n".join(lines))
print("ok")
