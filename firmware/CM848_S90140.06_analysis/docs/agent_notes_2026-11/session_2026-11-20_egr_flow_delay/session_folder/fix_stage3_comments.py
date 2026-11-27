"""Stage 3 follow-up: the struct field comment that refresh_references.py cannot reach (structure_definitions.csv),
and the 0x128a0 plate's 'charge properties' wording (the e2m never spells CHP out).
Usage: fix_stage3_comments.py <firmware output dir>"""
import os
import sys

out = sys.argv[1]
EDITS = {
    "structure_definitions.csv": [
        ("upstream_egr_corrected_flow x boost_pressure_current_raw (e2m 1A5D +0 Exhaust_Press)",
         "upstream_egr_corrected_flow x exhaust_pressure (e2m 1A5D +0 Exhaust_Press)"),
    ],
    "function_renames.csv": [
        ("EGR transport delay stage of the charge properties model (e2m 177F, resolved by the ECU's parameter ID "
         "table)",
         "EGR transport delay stage of the CHP charge flow model (CHP is the e2m prefix of the charge, EGR and fresh "
         "air flow records and is never spelled out; e2m 177F, resolved by the ECU's parameter ID table)"),
    ],
}
for name, pairs in EDITS.items():
    path = os.path.join(out, name)
    text = open(path).read()
    for old, new in pairs:
        assert text.count(old) == 1, (name, old)
        text = text.replace(old, new)
    open(path, "w").write(text)
print("ok")
