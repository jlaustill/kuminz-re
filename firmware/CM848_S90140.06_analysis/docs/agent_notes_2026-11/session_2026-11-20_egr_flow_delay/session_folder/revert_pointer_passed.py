"""Stage 8 refinement: revert the sweep's i16 on rows whose address is passed to a 'word *' parameter (the sensor
channel value / default outputs and two duty limits): as i16 every such call gained a (word *) cast.
Usage: revert_pointer_passed.py <firmware output dir> <names file>"""
import os
import sys

out, names_file = sys.argv[1:3]
names = {n.strip() for n in open(names_file) if n.strip()}
NOTE = " | retyped word -> i16 2026-11-20 (e2m signed, every load lha)"
path = os.path.join(out, "global_variables.csv")
lines = open(path).read().split("\n")
done = 0
for i, line in enumerate(lines):
    p = line.split(",", 3)
    if p[0].startswith("0x") and p[1] in names:
        assert p[2] == "i16" and p[3].endswith(NOTE), p[:3]
        p[2] = "word"
        p[3] = p[3][:-len(NOTE)] + (" | kept word 2026-11-20: e2m signed and every load lha, but the address is passed "
                                    "to a word * parameter (i16 casts every call)" if p[1] != "variable_geometry_turbocharger_position" else " | kept word 2026-11-20: e2m signed and its direct loads lha, but a shared pointer in cm848_updateVariableGeometryTurbochargerStagedPositionCommand reads it with lhz")
        lines[i] = ",".join(p)
        done += 1
assert done == len(names), (done, len(names))
open(path, "w").write("\n".join(lines))
print("reverted", done)
