"""Stage 2 follow-up: the plate comments name the delay lines instead of their addresses.
Usage: fix_stage2_plates.py <firmware output dir>"""
import os
import sys

out = sys.argv[1]
EDITS = {
    "0x000128a0,": [
        ("into the 256-sample delay line at 0x3fa1b6 (cm848_delayUnsignedSample)",
         "into the 256-sample delay line egr_oxygen_fraction_delay_line (cm848_delayUnsignedSample)"),
        ("into the delay line at 0x3fa3b8 (cm848_delaySignedSample)",
         "into egr_mass_flow_delay_line (cm848_delaySignedSample)"),
    ],
    "0x000123dc,": [
        ("at the line's write index (the byte at +0x200, after a ring of 256 words)",
         "at delay_line->write_index (the byte at +0x200, after the 256-word ring delay_line->samples)"),
        ("(the residual oxygen fraction, delay line at 0x3fa1b6)",
         "(the residual oxygen fraction, egr_oxygen_fraction_delay_line)"),
    ],
    "0x00012404,": [
        ("(the EGR mass flow before delay, delay line at 0x3fa3b8)",
         "(the EGR mass flow before delay, egr_mass_flow_delay_line)"),
    ],
}
path = os.path.join(out, "function_renames.csv")
lines = open(path).read().split("\n")
for i, line in enumerate(lines):
    for prefix, pairs in EDITS.items():
        if line.startswith(prefix):
            for old, new in pairs:
                assert line.count(old) == 1, (prefix, old)
                line = line.replace(old, new)
            lines[i] = line
open(path, "w").write("\n".join(lines))
print("ok")
