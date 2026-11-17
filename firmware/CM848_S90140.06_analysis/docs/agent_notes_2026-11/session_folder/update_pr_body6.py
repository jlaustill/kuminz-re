"""PR #50 body: the rename-wave review pass."""
import sys

p = sys.argv[1]
t = open(p).read()
for old, new in [("`cm848_calculateAuxiliaryInjectionQuantity` (was `cm848_calculateGovernorOutput`)",
                  "`cm848_calculateAuxiliaryInjectionQuantityLimit` (was `cm848_calculateGovernorOutput`)"),
                 ("the governor PID gains", "the governor compensator coefficients")]:
    assert t.count(old) == 1, old
    t = t.replace(old, new)
anchor = "    - **Proof:** mapping every new name back to its old one gives back the previous `.cpp`, plate comments aside; three functions only reorder their declarations. One new row is `i16`: typing it `word` added casts, which the proof caught. `verify` is deterministic.\n"
add = ("    - **Review pass (f813725):**\n"
       "      - 473 comments and 18 plates that cited renamed identifiers now use the new names.\n"
       "      - Five names were tightened where the evidence was weaker: auxiliary quantity *limit*, governor *compensator coefficients*, *governed-speed* (not \"idle\"), and a neutral oil-change accumulator name at a time-shared address.\n"
       "      - Decoded from ROM: fault 411 = P2609, and the limp-home flag's triggers are P0193 / P0192 / P0088 / P0251.\n"
       "      - Checked: 155 of 234 renamed globals are used only inside the verified functions, and the outside users of the rest fit their names. The e2m parameter blocks match CM848 RAM by relative offset (two blocks verified, same scales).\n"
       "      - Recorded in task 042: CM550 shares three of the old names, and 21 duplicate names predate this wave.\n")
assert t.count(anchor) == 1, "anchor"
open(p, "w").write(t.replace(anchor, anchor + add))
print("ok")
