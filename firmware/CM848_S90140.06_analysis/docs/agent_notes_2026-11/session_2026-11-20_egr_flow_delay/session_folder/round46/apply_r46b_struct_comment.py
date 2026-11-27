"""Round 46 stage B: the enable bit's comment in structure_definitions.csv names the three renamed functions;
refresh_references.py does not cover that file. Idempotent.  usage: apply_r46b_struct_comment.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
t = open(p).read()
for old, new in [("cm848_calculateParkNeutralExitEngineSpeedLimit", "cm848_calculateRockCycleEngineSpeedLimit"),
                 ("cm848_updateParkNeutralExitEngineSpeedLimitWindow", "cm848_updateRockCycleEngineSpeedLimitWindow"),
                 ("cm848_initializeParkNeutralExitEngineSpeedLimit", "cm848_initializeRockCycleEngineSpeedLimit")]:
    t = t.replace(old, new)
open(p, "w").write(t)
print("struct comment refreshed")
