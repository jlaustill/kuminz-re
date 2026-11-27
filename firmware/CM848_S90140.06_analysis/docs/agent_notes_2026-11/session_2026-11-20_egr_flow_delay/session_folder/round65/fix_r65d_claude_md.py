"""Round 65: two firmware/CLAUDE.md lines the name refresh could not finish (factual, from the CSVs):
- line 217 named the receive handlers as a brace list j1939_receivePgn{57344,...}Handler (the refresh matched only the
  registrar on that line);
- line 230 said the two ROM CCVS1 / EEC2 transmit builders' "names not yet fixed" - both were renamed in earlier
  rounds (0x24178 / 0x25b10 in function_renames.csv). Idempotent.  usage: fix_r65d_claude_md.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CLAUDE.md")
s = open(p).read()
EDITS = [
    ("Bank-2 receive handlers `j1939_receivePgn{57344,61441,61443,65252,65264,65265}Handler` (registered by "
     "`cm848_registerJ1939ReceiveHandler`)",
     "Bank-2 receive handlers `cm848_receivePgn57344CabMessage1` / `cm848_receivePgn61441ElectronicBrakeController1Message` "
     "/ `cm848_receivePgn61443ElectronicEngineController2Message` / `cm848_receivePgn65252ShutdownMessage` / "
     "`cm848_receivePgn65264PowerTakeoffInformationMessage` / `cm848_receivePgn65265CruiseControlVehicleSpeedMessage` "
     "(were `j1939_receivePgn{57344,61441,61443,65252,65264,65265}Handler`; registered by "
     "`cm848_registerJ1939ReceiveHandler`)"),
    ("- The ROM `j1939HandlePgn65265CruiseVehicleSpeed` (0x24178) and `j1939HandlePgn61443Eec2` (0x25b10) are the ECM's "
     "own CCVS1 / EEC2 **transmit** builders (they end in `cm848_sendJ1939Message`), not receive handlers — names not "
     "yet fixed.",
     "- The ROM `cm848_buildPgn65265CruiseControlVehicleSpeedMessage` (0x24178) and "
     "`cm848_buildPgn61443ElectronicEngineController2Message` (0x25b10) are the ECM's own CCVS1 / EEC2 **transmit** "
     "builders (they end in `cm848_sendJ1939Message`), not receive handlers (were `j1939HandlePgn65265CruiseVehicleSpeed` "
     "/ `j1939HandlePgn61443Eec2`)."),
]
for old, new in EDITS:
    if new in s:
        continue
    assert s.count(old) == 1, old[:70]
    s = s.replace(old, new)
open(p, "w").write(s)
print("firmware/CLAUDE.md: 2 lines")
