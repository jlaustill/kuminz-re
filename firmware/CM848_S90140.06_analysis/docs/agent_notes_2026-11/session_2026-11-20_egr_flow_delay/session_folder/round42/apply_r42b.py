"""Round 42 stage B: the engine retarder cylinder counts named after their e2m records (13D8 +2..+C
Jcomm_EB_Driver_N_Num_Cyl 'Indicates # of cyl. brakes driven by eb driver N for J1939 ret. map', 13D9 +0
Engine_Brake_On_Sum 'Indicates number of engine brake cylinders on'; the rows already cited them), the selected stage
table pointer of cm848_calculateEngineRetarderTorque named (was in_r6: live-in on the path where no table is
selected), and the plate's wording. Idempotent.  usage: apply_r42b.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 42"
ROWS = [(f"0x0005c4{0x7e + 2 * k:02x}", f"engine_retarder_stage_{k + 1}_weight",
         f"engine_retarder_driver_{k + 1}_cylinder_count") for k in range(6)]
ROWS.append(("0x0040ae5a", "engine_retarder_engaged_stage_count", "engine_retarder_cylinders_on_count"))
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "engine_retarder_cylinders_on_count" in names:
    print("already applied")
    sys.exit(0)
rows = ["address,name,old_label,kind,dims"]
for a, cur, new in ROWS:
    assert new not in names, new
    i = next(k for k, l in enumerate(g) if l.startswith(a + "," + cur + ","))
    p = g[i].split(",", 3)
    head = ("e2m 13D9 +0 Engine_Brake_On_Sum 'Indicates number of engine brake cylinders on': the sum of the engaged "
            "drivers' cylinder counts" if new.endswith("on_count") else
            f"e2m 13D8 Jcomm_EB_Driver_{new.split('_')[3]}_Num_Cyl: the cylinder brakes engine brake driver "
            f"{new.split('_')[3]} drives")
    g[i] = f"{a},{new},{p[2]},{head} (was {cur}; {R}) | earlier note: {p[3] if len(p) > 3 else ''}"
    rows.append(f"{a},{new},{cur},global,1")
open(gp, "w").write("\n".join(g))
lp = os.path.join(out, "local_variables.csv")
lv = open(lp).read()
row = ("0x00021314,cm848_calculateEngineRetarderTorque,in_r6,selected_stage_torque_values,word *,The "
       "engine_retarder_torque_stage_N_values table for engine_retarder_cylinders_on_count N (1 to 6); a count above 6 "
       f"selects none and the lookup then reads whatever r6 held ({R})")
if "selected_stage_torque_values" not in lv:
    lv = lv.rstrip("\n") + "\n" + row + "\n"
    open(lp, "w").write(lv)
fp = os.path.join(out, "function_renames.csv")
f = open(fp).read()
old = "selected by the number of engaged retarder stages (0 to 6)"
new = "selected by the number of braking cylinders (engine_retarder_cylinders_on_count, 0 to 6)"
if new not in f:
    assert f.count(old) == 1
    f = f.replace(old, new)
old2 = "transmits 125 minus the\n   percent (was cm848_calculateSpeedControlError)."
if "(was cm848_calculateSpeedControlError). A count above 6" not in f:
    i = f.index("0x00021314,cm848_calculateEngineRetarderTorque,")
    j = f.index("\n", i)
    line = f[i:j]
    assert "(was cm848_calculateSpeedControlError)" in line
    line = line.replace("(was cm848_calculateSpeedControlError)",
                        "(was cm848_calculateSpeedControlError). A count above 6 selects no table, so the lookup then "
                        "reads whatever r6 held (selected_stage_torque_values); the driver cylinder counts in this "
                        "calibration are 1 / 0 / 0 / 0 / 0 / 0, so the count is 0 or 1")
    f = f[:i] + line + f[j:]
open(fp, "w").write(f)
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(ROWS)} rows renamed, 1 local row, plate updated")
