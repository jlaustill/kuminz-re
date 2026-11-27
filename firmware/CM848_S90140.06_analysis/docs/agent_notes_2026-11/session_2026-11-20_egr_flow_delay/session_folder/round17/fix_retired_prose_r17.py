"""Round 17 stage A: the retired engine retarder wording in current comment text of global_variables.csv (found by
retired_prose_r17.py). Idempotent. usage: fix_retired_prose_r17.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
FIXES = [
    ("Set in cm848_updateEngineRetarderActiveState when the request percent has just fallen to 0 or logical output 11 "
     "has just been cleared (and no shift hold);",
     "Set in cm848_updateEngineRetarderActiveState when engine_retarder_output_level_percent has just fallen to 0 or "
     "logical output 11 has just been cleared (and the engage inhibit flag is clear);"),
    ("Set 1 / 0 by cm848_updateEngineRetarderActiveState from the arbitrated request (held during a shift);",
     "Set 1 / 0 by cm848_updateEngineRetarderActiveState from engine_retarder_command_percent (held during a shift);"),
    ("100 / 0 from switch_input_state_bits[1] mask 0x10, forced to 100 in low_speed_governor_extended_idle_active_flag "
     "mode. Read by cm848_limitEngineRetarderPercentToOperatorSelection (retarder percent limit)",
     "100 / 0 from the exhaust brake switch (switch 12), forced to 100 in low_speed_governor_extended_idle_active_flag "
     "mode. Read by cm848_limitEngineRetarderPercentToOperatorSelection (the non-override command, source 3)"),
    ("read only by cm848_limitEngineRetarderPercentToCruisePermission (limit source code 2 = cruise control).",
     "read only by cm848_limitEngineRetarderPercentToCruisePermission (the non-override command, source 2 = cruise)."),
    ("and the service brake condition when required; enable state 2 needs it for a new request.",
     "and the service brake condition when required (algorithm_enable_flags_18_cal "
     "engine_retarder_service_brake_activate_enable); the allowed state OVERRIDE_OR_NON_OVERRIDE needs it for a new "
     "command."),
    ("enable state 1 (held off) is chosen while it is true.",
     "the allowed state OVERRIDE_ONLY (held off) is chosen while it is true."),
]
t = open(p).read()
for old, new in FIXES:
    if old not in t and new in t:
        continue
    assert t.count(old) == 1, (old[:60], t.count(old))
    t = t.replace(old, new)
open(p, "w").write(t)
print("retarder wording fixed")
