"""Round 19 stage D: 'cold start' -> 'cranking' in the current text (before any '| earlier note:') of the lines that
describe the renamed cranking maps. usage: fix_cranking_prose.py <output dir>"""
import os
import re
import sys

out = sys.argv[1]
TARGETS = {"global_variables.csv": ["0x0040b8ba,", "0x00", "0x00", "0x00"], "function_renames.csv": []}
KEYS = {
    "global_variables.csv": ("fuel_pressure_setpoint_transition_state", "replaced by the cold correction or cold-start "
                             "override value", "before the cold-start table / transition", "or from the cold-start curve "
                             "while cranking"),
    "function_renames.csv": ("While cranking it uses the cold-start table",),
}
for name, keys in KEYS.items():
    p = os.path.join(out, name)
    lines = open(p).read().split("\n")
    for key in keys:
        hits = [i for i, l in enumerate(lines) if key in l]
        assert len(hits) == 1, (name, key, hits)
        i = hits[0]
        cur, sep, hist = lines[i].partition("| earlier note:")
        new = re.sub(r"[Cc]old-start", lambda m: "Cranking" if m.group(0)[0] == "C" else "cranking", cur)
        new = new.replace("cold correction or cranking override value", "cranking correction value")
        lines[i] = new + sep + hist
    open(p, "w").write("\n".join(lines))
print("cranking wording refreshed")
