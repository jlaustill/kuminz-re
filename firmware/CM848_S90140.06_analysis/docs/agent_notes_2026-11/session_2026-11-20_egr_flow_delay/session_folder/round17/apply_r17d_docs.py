"""Round 17 stage D docs: task 046's round 17 section after the review. usage: apply_r17d_docs.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "work/tasks/046-cm848-egr-flow-estimate.md")
t = open(p).read()
EDITS = [
    ("- **The vocabulary is the e2m's, and it fits the code exactly:**",
     "- **The vocabulary is the e2m's, and it fits the code:**"),
    ("  - e2m 1070 +10 / +20 (a 0-255 switch sum, a 1/8192 fraction) do not explain the code's 0 / 100 values, so\n"
     "    `engine_retarder_switch_percent` / `_2` keep their code-derived names.",
     "  - e2m 1070 +10 / +20 and 117D +6 (a 0-255 switch sum, a 1/8192 fraction, a 0-3 switch status) do not explain\n"
     "    the code's 0 / 100 values, so `engine_retarder_switch_percent` / `_2` and\n"
     "    `engine_retarder_selection_percent_fault_masked` keep their code-derived names.\n"
     "  - 'Request' stays only where the code means a request: the TSC1 requests and the request chain\n"
     "    (`cm848_processEngineRetarderRequest`). Stage D moved the counters next to the command and the output level."),
    ("- **Round 17 leads:**",
     "- **Stage D (label-only, after the review):**\n"
     "  - `engine_retarder_command_age_counter`, `engine_retarder_output_on_delay_counter` / `_passes` (were\n"
     "    `engine_retarder_request_*`).\n"
     "  - `algorithm_enable_flags_41_t` bit 0 is `engine_retarder_extended_idle_enable` (was\n"
     "    `engine_retarder_speed_limit_enable`). The old name came from the extended idle flag's old name,\n"
     "    `governor_speed_limit_active_flag`; e2m 1496 +A is `LSG_Extended_Idle_Status`. With the flag and the bit set,\n"
     "    the selection is 100 and the allowed state 2, while the active flag stays 0: the exhaust brake runs at\n"
     "    extended idle (a warm-up use) without reporting braking.\n"
     "- **Round 17 leads:**"),
    ("  - **`algorithm_enable_flags_41_t.engine_retarder_speed_limit_enable`** forces the retarder selection to 100 during\n"
     "    extended idle, a warm-up use. The bit's name and the e2m record for it are still open.\n",
     "  - **`algorithm_enable_flags_41_t.engine_retarder_extended_idle_enable`** has no e2m record yet (named from the\n"
     "    code in stage D).\n"),
]
for old, new in EDITS:
    if old not in t and new in t:
        continue
    assert t.count(old) == 1, (old[:60], t.count(old))
    t = t.replace(old, new)
open(p, "w").write(t)
print("task 046 updated")
