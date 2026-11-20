"""Stage 8 comment fixes after the wave-13 apply:
- 0x3fed94: restore the two proved facts of its old comment (the apply dropped it as wrong), with 0x40a813's
  current name;
- the comment sweep's stale tokens: FUN_00529284 / cm848_protection_condition_eval_set1 (0x40b875),
  governor_status_overspeed_flag_snapshot (0x3fe9c6), safety_bits_1 / safety_bits_2 (renamed to
  system_status_flags_t fields) outside "(was ...)" notes.
usage: fix_stage8_comments.py <CM848 output dir>"""
import os
import re
import sys

out = sys.argv[1]
TOKENS = {"safety_bits_1": "fault_detected_bits_48_to_63", "safety_bits_2": "fault_detected_bits_64_to_79"}


def outside_was(text, fn):
    parts = re.split(r"(\((?:was|were) [^)]*\))", text)
    return "".join(p if re.match(r"\((?:was|were) ", p) else fn(p) for p in parts)


def tokens(text):
    for old, new in TOKENS.items():
        text = re.sub(rf"(?<![A-Za-z0-9_]){old}(?![A-Za-z0-9_])", new, text)
    return text


EXACT = [
    ("0x003fed94", " (was fault_pending_flags)",
     " Width dword (lwz / stw r12,0(r5) @ 0x52d634). Distinct from system_switch_status / system_switch_status_2"
     " (0x40a813 / 0x40a815). (was fault_pending_flags)"),
    ("0x0040b875", "FUN_00529284 + cm848_protection_condition_eval_set1",
     "engine_injectionAngle_computeLoadCh6 + cm848_scheduleInjectionAnglesInSpeedLimpHome"),
    ("0x003fe9c6", "the sibling governor_status_overspeed_flag_snapshot is a wrong write-only name",
     "the sibling variable_geometry_turbocharger_closed_adjustment_error_snapshot (0x3fb078) samples its fault 670 bit"),
]
counts = {}
for name in ("global_variables.csv", "function_renames.csv", "structure_definitions.csv"):
    path = os.path.join(out, name)
    lines = open(path, newline="").read().split("\n")
    changed = 0
    for i, line in enumerate(lines):
        new = line
        for address, old_text, new_text in EXACT:
            if name == "global_variables.csv" and line.startswith(address + ","):
                assert new.count(old_text) == 1, (address, old_text)
                new = new.replace(old_text, new_text)
        new = outside_was(new, tokens)
        if new != line:
            lines[i] = new
            changed += 1
    open(path, "w", newline="").write("\n".join(lines))
    counts[name] = changed
print(counts)
