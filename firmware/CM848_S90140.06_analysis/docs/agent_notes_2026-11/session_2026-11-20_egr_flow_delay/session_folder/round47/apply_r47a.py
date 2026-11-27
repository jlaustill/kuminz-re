"""Round 47 stage A: rows the dumped parameter ID table resolves to a default-e2m record they did not cite, inside blocks
whose other rows match their records (uncited_table_rows.py / block_reliability.py), checked against the code:
- 0x40a336 j1939_broadcast_enable_flag (dword) = 120C +6 FSS_Torque_Load_Calculation_Flag ('sets bdcst for Actual Eng
  %Torque and %Load to 0xFE'): the EEC1 and EEC2 builders read its word (lhz @ 0x25a68 / 0x25ca4) and then send 0xFE
  for the actual torque byte and the percent load byte. Retyped to word; nothing reads 0x40a338.
- 0x3fad92 j1939_dm1_spn_fmi_byte is the EEC1 actual engine percent torque byte (torque + 0x7D, or 0xFE).
- 0x40be5e sensor_diag_default_a = 1963 +4A TVA_Position_Status (the block's other rows are the sensor fault statuses).
- sendPgn61444ElectronicEngineController1Message keeps its name: it is shared with its CM550 twin (0x32c76).
Idempotent.  usage: apply_r47a.py <repo> <map.csv> <globals map.csv>"""
import ast
import os
import re
import sys

repo, map_path, gmap_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
gp, fp = os.path.join(out, "global_variables.csv"), os.path.join(out, "function_renames.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 47"
g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "j1939_torque_and_load_not_available_flag" in names:
    print("already applied")
    sys.exit(0)
ROWS = [
    ("0x0040a336", "j1939_broadcast_enable_flag", "j1939_torque_and_load_not_available_flag", "word",
     "e2m 120C +6 FSS_Torque_Load_Calculation_Flag 'When active, this flag sets bdcst for Actual Eng %Torque and %Load "
     "to 0xFE.' (UNITLESS, 1 per count). sendPgn61444 / cm848_buildPgn61443 read it (lhz @ 0x25a68 / 0x25ca4): at 1 the "
     "EEC1 actual engine percent torque byte and the EEC2 percent load byte go out as 0xFE. Was a dword; nothing reads "
     "its second word 0x40a338 (120C +8 Engine_System_State)"),
    ("0x003fad92", "j1939_dm1_spn_fmi_byte", "j1939_eec1_actual_engine_percent_torque_byte", None,
     "The EEC1 (PGN 61444) actual engine percent torque byte: sendPgn61444ElectronicEngineController1Message "
     "stores actual_engine_percent_torque_times_256 >> 8 + 0x7D, or 0xFE while "
     "j1939_torque_and_load_not_available_flag is 1; its only uses"),
    ("0x0040be5e", "sensor_diag_default_a", "throttle_valve_actuator_position_sensor_fault_status", None,
     "e2m 1963 +4A TVA_Position_Status 'TVA_Position_Status .' (UNITLESS): the block's other rows are the sensor fault "
     "statuses (1963 matches 33 of 34 rows). cm848_initSensorDefaults writes 10 at start-up; nothing reads it"),
]
mapping, gmapping = ["address,name,old_label,kind,dims"], ["address,name,old_label,kind,dims"]
for a, cur, new, typ, head in ROWS:
    p = g[idx[a]].split(",", 3)
    p += [""] * (4 - len(p))
    assert p[1] == cur, (a, p[1], cur)
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
    g[idx[a]] = f"{a},{new},{typ or p[2]},{head} (was {cur}; {R})" + (f" | earlier note: {p[3]}" if p[3] else "")
    names.add(new)
    mapping.append(f"{a},{new},{cur},global,1")
    gmapping.append(f"{a},{new},{cur},global,1")
open(gp, "w").write("\n".join(g))
for path, rows_ in ((map_path, mapping), (gmap_path, gmapping)):
    with open(path, "w") as fh:
        fh.write("\n".join(rows_) + "\n")
print("3 globals renamed (one retyped)")
