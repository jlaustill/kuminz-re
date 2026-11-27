"""Round 44 stage C (advisor review of stage B):
- The pedal learning's "total step" pair is a time limit. cm848_learnAcceleratorPedalIdlePositions increments the counter
  on every pass in which either channel's learning conditions hold, whether or not a step is taken, and its limit is
  e2m 8BAC +0x18 PPS_AZ_Time_Limit ('Time allowed from key on for pps auto zero when auto zero conditions exist',
  MSEC, 100 per count).
- The PPS block is inactive in this calibration: 0x408a84 = 8BAC +0x12 Accelerator_Position_Sensor_Type is 0 (TPS).
Idempotent.  usage: apply_r44c.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
gp, fp = os.path.join(out, "global_variables.csv"), os.path.join(out, "function_renames.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 44"
g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "accelerator_pedal_idle_learning_timer" in names:
    print("already applied")
    sys.exit(0)
CITE = ("e2m 8BAC +18 PPS_AZ_Time_Limit 'Time allowed from key on for pps auto zero when auto zero conditions exist' "
        "(MSEC, 100 per count; 299 = 29900 here).")


def row(a):
    return g[idx[a]].split(",", 3)


p = row("0x00408a8a")
assert p[1] == "accelerator_pedal_idle_learning_total_step_limit" and p[3].startswith(CITE), p[3][:120]
old_note = p[3][len(CITE):].strip()
g[idx["0x00408a8a"]] = (f"0x00408a8a,accelerator_pedal_idle_learning_time_limit,{p[2]},{CITE} "
                        "cm848_learnAcceleratorPedalIdlePositions (100 ms passes) learns only while "
                        "accelerator_pedal_idle_learning_timer is at or below it: 29.9 s of passes with the learning "
                        f"conditions met (was accelerator_pedal_idle_learning_total_step_limit; {R}) | earlier note: {old_note}")
p = row("0x003fb42e")
assert p[1] == "accelerator_pedal_idle_learning_total_step_counter", p[1]
g[idx["0x003fb42e"]] = (f"0x003fb42e,accelerator_pedal_idle_learning_timer,{p[2]},Counts the 100 ms passes of "
                        "cm848_learnAcceleratorPedalIdlePositions in which either channel's learning conditions hold "
                        "(debounced below its idle position + deadband, under accelerator_pedal_idle_learning_channel_step_limit), "
                        "whether or not a step is taken; learning stops above accelerator_pedal_idle_learning_time_limit "
                        "(e2m 8BAC +18 PPS_AZ_Time_Limit) (was accelerator_pedal_idle_learning_total_step_counter; "
                        f"{R}) | earlier note: {p[3]}")
for new in ("accelerator_pedal_idle_learning_time_limit", "accelerator_pedal_idle_learning_timer"):
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
p = row("0x00408a76")
old = "(78 >= 68 in the dump), the test cell case."
assert old in p[3]
g[idx["0x00408a76"]] = ",".join(p[:3]) + "," + p[3].replace(
    old, old + " The whole PPS block is inactive in this calibration: 0x408a84 (8BAC +0x12 Accelerator_Position_Sensor_Type) "
    "is 0, TPS.")
p = row("0x00408a84")
old = "(1 per count; 0 = 0 here)."
assert old in p[3]
g[idx["0x00408a84"]] = ",".join(p[:3]) + "," + p[3].replace(
    old, "(1 per count; 0 here = TPS, so the PPS block is inactive in this calibration).")
open(gp, "w").write("\n".join(g))
f = open(fp).read()
old = "for at most accelerator_pedal_idle_learning_channel_step_limit steps, and"
new = ("for at most accelerator_pedal_idle_learning_channel_step_limit steps (e2m PPS_AZ_Update_Limit) while "
       "accelerator_pedal_idle_learning_timer, the 100 ms passes with the learning conditions met, is at or below "
       "accelerator_pedal_idle_learning_time_limit (e2m PPS_AZ_Time_Limit), and")
if new not in f:
    assert f.count(old) == 1
    f = f.replace(old, new)
    open(fp, "w").write(f)
with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x00408a8a,accelerator_pedal_idle_learning_time_limit,accelerator_pedal_idle_learning_total_step_limit,global,1\n"
             "0x003fb42e,accelerator_pedal_idle_learning_timer,accelerator_pedal_idle_learning_total_step_counter,global,1\n")
print("2 renames, 2 comments, 1 plate")
