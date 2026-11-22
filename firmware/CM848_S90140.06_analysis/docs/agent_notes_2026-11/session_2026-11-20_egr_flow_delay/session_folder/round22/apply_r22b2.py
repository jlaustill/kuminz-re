"""Round 22 stage B, part 2 (comments): the review found two stage A comments that went beyond the code read -
- cm848_applyFaultDerateToJ1939TorqueCurveFuelings: in the priority path the five fuelings are set to the derated
  values, not lowered (only the clamp-mask path takes the minimum);
- configuration_flags: 0x4 / 0x8 / 0xc / 0x40, now from cm848_isEngineProtectionInputMoreExtreme and
  cm848_calculateFaultDerateFuelLimit, which were read for this.
usage: apply_r22b2.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
FIXES = [
    ("function_renames.csv",
     "Looks the fault derate fuel limit up at the five J1939 torque curve speed points and lowers the J1939 torque "
     "curve fuelings (PGN 65251) to them: always where the clamp mask (fault_derate_curve_clamp_priority_mask) has "
     "the highest requester's bit, else only while fault_derate_torque_curve_priority_bit is the highest request",
     "Looks the fault derate fuel limit up at the five J1939 torque curve speed points. When the clamp mask "
     "(fault_derate_curve_clamp_priority_mask) has the highest requester's bit, each J1939 torque curve fueling (PGN "
     "65251) is clamped to the derated value (the minimum is kept); otherwise, while "
     "fault_derate_torque_curve_priority_bit is the highest request, the five fuelings are set to the derated values"),
    ("structure_definitions.csv",
     "0x4 the input is past its threshold when above it (clear: below); 0x8 the fault log's extreme value starts at "
     "0x7fff (the minimum is tracked; clear: 0x8000, the maximum); 0xc track the extreme at all;",
     "0x4 the input is past its threshold when above it (clear: below), and the fault log tracks the input's maximum; "
     "0x8 with 0x4 clear the log tracks the minimum (cm848_isEngineProtectionInputMoreExtreme); with neither (0xc "
     "clear) no extreme is tracked; the extreme starts at 0x7fff while 0x8 is set, else 0x8000;"),
    ("structure_definitions.csv",
     "0x40 the fueling restart index is 0x100 instead of interpolated;",
     "0x40 the fueling severity is the time-ramped index (cm848_rampEngineProtectionSeverityIndex) and the fueling "
     "restart index 0x100, instead of the input's place between the minimum and maximum thresholds "
     "(cm848_calculateFaultDerateFuelLimit, cm848_updateEngineProtectionRestartSeverityIndexes);"),
]
for name, old, new in FIXES:
    p = os.path.join(out, name)
    t = open(p).read()
    assert t.count(old) == 1, (name, old[:60], t.count(old))
    assert '"' not in new
    open(p, "w").write(t.replace(old, new))
print(len(FIXES), "comments corrected")
