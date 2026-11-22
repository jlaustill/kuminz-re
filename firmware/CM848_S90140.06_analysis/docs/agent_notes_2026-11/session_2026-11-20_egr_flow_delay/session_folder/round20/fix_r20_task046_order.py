"""Round 20 stage F closing, task 046 touch-ups: stage D's summary line still said 'from a single spelled-out
record' (the tier rule below it is the corrected one), and the stage F bullet sat before stage E's. Idempotent.
usage: fix_r20_task046_order.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "work/tasks/046-cm848-egr-flow-estimate.md")
t = open(p).read()
t = t.replace("117 bits are named from a matching reader, 50 from a single spelled-out record, and 105 are reserved.",
              "117 bits are named from a matching reader, 50 from a single record, and 105 are reserved.")
start = t.index("- **Stage F (16f967b,")
end = t.index("- **Stage E (32df48c, label-only):**")
if start < end:
    f_block = t[start:end]
    t = t[:start] + t[end:]
    methods = t.index("- **Methods:**", t.index("## Done, round 20"))
    t = t[:methods] + f_block + t[methods:]
assert t.index("- **Stage E (32df48c") < t.index("- **Stage F (16f967b") < t.index("- **Methods:**", t.index("## Done, round 20"))
open(p, "w").write(t)
print("stage D wording fixed; stage F after stage E")
