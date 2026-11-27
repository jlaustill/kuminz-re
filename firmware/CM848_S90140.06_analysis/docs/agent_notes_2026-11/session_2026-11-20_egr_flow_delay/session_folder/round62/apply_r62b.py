"""Round 62 stage B (from the advisor's closing checks): stage A named the registrar of services 0x0f / 0x10 / 4 / 5
"...ParameterAndBroadcastServices" from the EF00_SERVICE_ID member names, but j1939_diagService15And16Handler only
returns 0: services 0x0f / 0x10 are accepted no-ops in this build. The handler becomes the application's twin of the
boot kernel's cm848_diagServiceAcknowledgeNoOperation and the registrar is named for what it registers. Also the
e2m citation on the pedal fault mode filter coefficient (e2m 10CE +0 Limp_Home_Engine_Speed_Filter_Constant).
Idempotent.  usage: apply_r62b.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 62"
fp = os.path.join(O, "function_renames.csv")
f = open(fp).read()
if "cm848_j1939DiagnosticServiceAcknowledgeNoOperation," in f:
    print("already applied")
    sys.exit(0)
FUNCS = [
    ("j1939_diagService15And16Handler", "cm848_j1939DiagnosticServiceAcknowledgeNoOperation",
     "PGN 61184 diagnostic services 0x0f / 0x10: returns 0 (accepted) and does nothing - the application's twin of the "
     "boot kernel's cm848_diagServiceAcknowledgeNoOperation. Registered by "
     "cm848_registerJ1939BroadcastAndNoOperationServices"),
    ("cm848_registerJ1939ParameterAndBroadcastServices", "cm848_registerJ1939BroadcastAndNoOperationServices",
     "From cm848_j1939_system_init: registers the PGN 61184 services 4 / 5 (disable / enable broadcast) and 0x0f / 0x10 "
     "(accepted no-ops - cm848_j1939DiagnosticServiceAcknowledgeNoOperation) in j1939_diagnostic_service_table. Stage A "
     "of this round named it ...ParameterAndBroadcastServices from the EF00_SERVICE_ID member names"),
]
original = f
mapping = ["address,name,old_label,kind,dims"]
for cur, new, plate in FUNCS:
    m = re.search(rf"^(0x[0-9a-f]{{8}}),{cur}(,[^\n]*)?$", f, re.M)
    assert m, cur
    assert re.fullmatch(r"cm848_[a-z][A-Za-z0-9]*", new) and not re.search(rf"\b{new}\b", original), new
    assert "," not in plate
    old_plate = (m.group(2) or ",")[1:].strip()
    if cur.startswith("cm848_registerJ1939ParameterAndBroadcastServices"):
        old_plate = old_plate.split(" (was j1939_diag_request_batch_init;", 1)[0]
        text = f"{plate} (was j1939_diag_request_batch_init; {R})"
    else:
        text = f"{plate} (was {cur}; {R})" + (f" | earlier note: {old_plate}" if old_plate else "")
    f = f[:m.start()] + f"{m.group(1)},{new},{text}" + f[m.end():]
    mapping.append(f"{m.group(1)},{new},{cur},function,1")
open(fp, "w").write(f)
gp = os.path.join(O, "global_variables.csv")
g = open(gp).read()
old = "0x0005c48e,pedal_fault_mode_engine_speed_filter_coefficient,word,The weight of the previous value (1/65536)"
assert g.count(old) == 1
g = g.replace(old, "0x0005c48e,pedal_fault_mode_engine_speed_filter_coefficient,word,e2m 10CE +0 "
                   "Limp_Home_Engine_Speed_Filter_Constant (the e2m's limp home is the pedal fault mode; block 10CE holds "
                   "the pedal_fault_mode_* settings): the weight of the previous value (1/65536)")
open(gp, "w").write(g)
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print("2 functions renamed, 1 citation")
