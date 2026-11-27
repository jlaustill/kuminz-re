"""Round 93 (CM550): comments that named a function together with its mid-function tail row ("X / tail", "X (its
tail Y)") read "X / X" after the refresh sent the removed tail names to the functions that hold them. This rewrites
each such spot to name the function once. Every replacement must match exactly once (or already be applied).
usage: fix_tail_mentions_r93.py <repo> [--show]"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
FIXES = {
    "global_variables.csv": [
        ("mc68k_initializeTpuChannel10PrimarySpeedInputDivided, mc68k_initializeTpuChannel10PrimarySpeedInputDivided and ",
         "mc68k_initializeTpuChannel10PrimarySpeedInputDivided and "),
        ("cm550_diagnosticDataCopyHandler (its tail cm550_diagnosticDataCopyHandler) copies",
         "cm550_diagnosticDataCopyHandler copies"),
        ("cm550_diagnosticDataCopyHandler (its tail cm550_diagnosticDataCopyHandler @ 0xd0fc) copies",
         "cm550_diagnosticDataCopyHandler (at 0xd0fc) copies"),
        ("cm550_diagnosticDataCopyHandler (0xd0e2, which falls into cm550_diagnosticDataCopyHandler at 0xd0fc) points",
         "cm550_diagnosticDataCopyHandler (0xd0e2; the store is past 0xd0fc) points"),
        ("sendPgn61444ElectronicEngineController1Message / sendPgn61444ElectronicEngineController1Message send ",
         "sendPgn61444ElectronicEngineController1Message sends "),
    ],
    "structure_definitions.csv": [
        ("(cm550_engineModeTimingAdjuster / cm550_engineModeTimingAdjuster: ", "(cm550_engineModeTimingAdjuster: "),
        ("(cm550_fuelDemandLimitSource2Selector / cm550_fuelDemandLimitSource2Selector: ", "(cm550_fuelDemandLimitSource2Selector: "),
        ("(cm550_fuelDemandLimitSelector11 / cm550_fuelDemandLimitSelector11)", "(cm550_fuelDemandLimitSelector11)"),
    ],
}
if "--show" in sys.argv:
    for name in FIXES:
        t = open(os.path.join(O, name), newline="").read()
        for m in re.finditer(r"(\w{12,}) (?:/|,|\(its tail|\(0x[0-9a-f]+, which falls into) ?\1\b[^,;]{0,40}", t):
            print(name, "|", m.group(0))
    sys.exit(0)
done = 0
for name, fixes in FIXES.items():
    p = os.path.join(O, name)
    t = open(p, newline="").read()
    for old, new in fixes:
        if old in t:
            assert t.count(old) == 1, (old, t.count(old))
            t = t.replace(old, new)
            done += 1
        else:
            assert new in t, f"neither the old nor the new text is in {name}: {old}"
    open(p, "w", newline="").write(t)
print(done, "spots rewritten")
