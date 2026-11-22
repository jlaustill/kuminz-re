"""Round 17 stage D: rename algorithm_enable_flags_41_t bit 0 engine_retarder_speed_limit_enable ->
engine_retarder_extended_idle_enable (label-only field). Its two readers: with low_speed_governor_extended_idle_active_flag
(e2m 1496 +A LSG_Extended_Idle_Status) set, cm848_calculateEngineRetarderSelectionPercent forces the selection to 100 and
cm848_updateEngineRetarderAllowedState forces the allowed state to OVERRIDE_OR_NON_OVERRIDE, while
cm848_updateEngineRetarderActiveState keeps engine_retarder_active_flag at 0: the exhaust brake runs at extended idle
(a warm-up use) without reporting braking. usage: apply_r17d_field.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
lines = open(p).read().split("\n")
prefix = "algorithm_enable_flags_41_t,,engine_retarder_speed_limit_enable,bitfield:1@0,2,"
k = [i for i, l in enumerate(lines) if l.startswith(prefix)]
assert len(k) == 1
old_comment = lines[k[0]][len(prefix):]
assert old_comment.startswith('"') and old_comment.endswith('",,verified'), old_comment[-30:]
body = old_comment[1:-len('",,verified')]
new_body = ("No e2m name; code only (PR #53 round 17). With low_speed_governor_extended_idle_active_flag (e2m 1496 +A "
            "LSG_Extended_Idle_Status) set, cm848_calculateEngineRetarderSelectionPercent forces the selection to 100 and "
            "cm848_updateEngineRetarderAllowedState forces the allowed state to OVERRIDE_OR_NON_OVERRIDE, while "
            "cm848_updateEngineRetarderActiveState keeps engine_retarder_active_flag at 0: the exhaust brake runs at "
            "extended idle (a warm-up use) without reporting braking (was engine_retarder_speed_limit_enable, from the "
            "flag's old name governor_speed_limit_active_flag) | earlier note: " + body.replace('"', "'"))
lines[k[0]] = "algorithm_enable_flags_41_t,,engine_retarder_extended_idle_enable,bitfield:1@0,2,\"" + new_body + "\",,verified"
open(p, "w").write("\n".join(lines))
with open(map_path, "a") as f:
    f.write(",engine_retarder_extended_idle_enable,engine_retarder_speed_limit_enable,field\n")
print("field renamed")
