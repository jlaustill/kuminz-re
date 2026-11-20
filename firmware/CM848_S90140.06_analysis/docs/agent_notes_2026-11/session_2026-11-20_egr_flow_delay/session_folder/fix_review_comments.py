"""Review fixes (advisor, 2026-11-20): above a fraction of 1.0 it is the scaled term that becomes 0xffff, not the
delay; the first delay line's comment names its boot call target too.
Usage: fix_review_comments.py <firmware output dir>"""
import os
import sys

out = sys.argv[1]
EDITS = {
    "global_variables.csv": {
        "0x004002e8,": [("above it the delay is 0xffff.",
                         "above it the scaled term is 0xffff instead, so the delay is 0xffff x 1000 / (volumetric "
                         "efficiency x rpm): 40959 ms at the 1600-count floor in the RAM dump.")],
        "0x003fa1b6,": [("Inside the boot kernel's RAM image (0x3f9800-0x3fdb30): the application reuses this RAM after "
                         "boot.",
                         "Inside the boot kernel's RAM image (0x3f9800-0x3fdb30): the application reuses this RAM after "
                         "boot. It covers the boot ROM's call target 0x3fa2f0 (the RAM copy of "
                         "cm848_runFlashProgramStateMachine), so the thunk stage keeps it and points that boot call at "
                         "the ROM function (a call override).")],
    },
    "function_renames.csv": {
        "0x000128a0,": [("and a fraction above 8192 (1.0) is replaced by 0xffff.",
                         "and above a fraction of 8192 (1.0) the scaled fraction term (fraction x 120 >> 10) is "
                         "0xffff instead.")],
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
