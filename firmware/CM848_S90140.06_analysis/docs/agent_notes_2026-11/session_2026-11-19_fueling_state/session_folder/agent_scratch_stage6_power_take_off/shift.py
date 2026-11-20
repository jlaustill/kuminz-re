"""Per-function line shift between the snapshot and the live .cpp.  usage: shift.py <live cpp>"""
import re
import sys

LIVE = sys.argv[1]
SNAP = "/tmp/pto_research/snap.cpp"


def starts(path):
    out = {}
    for i, line in enumerate(open(path, errors="replace"), 1):
        m = re.match(r"^// Function: (\S+) @", line)
        if m:
            out[m.group(1)] = i
    return out


a, b = starts(SNAP), starts(LIVE)
names = ["cm848_calculatePowerTakeOffGovernorSpeedError", "cm848_runPowerTakeOffGovernorPid",
         "cm848_presetPowerTakeOffGovernorOnEngagement", "cm848_runPowerTakeOffGovernor",
         "cm848_initProtectionFilterState", "cm848_smoothPowerTakeOffReferenceEngineSpeed",
         "cm848_setProtectionParamFromRpm", "cm848_initProtectionSmoothingPointer",
         "cm848_updatePowerTakeOffGovernorJ1939State", "cm848_runPowerTakeOffGovernorStateMachine",
         "cm848_rampPowerTakeOffReferenceEngineSpeed", "cm848_initializePowerTakeOffGovernorState",
         "cm848_resetProtectionBypass", "cm848_j1939HandlePgn65264Pto", "cm848_initJ1939PtoBuffer",
         "cm848_dispatchModeHandlers", "cm848_applicationMain", "cm848_initJ1939ProtocolHandlers",
         "cm848_j1939_system_init"]
for n in names:
    print(f"{n}: snap={a.get(n)} live={b.get(n)} shift={(b.get(n) or 0) - (a.get(n) or 0)}")
