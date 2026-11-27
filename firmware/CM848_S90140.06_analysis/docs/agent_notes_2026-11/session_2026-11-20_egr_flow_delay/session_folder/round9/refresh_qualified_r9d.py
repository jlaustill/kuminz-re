"""Round 9 stage D: refresh struct-qualified field references (<instance>.<field>, <type>.<field>) in the CSV comment
columns and firmware/CLAUDE.md, which the generic refresh cannot do safely (field names like 'flags' are too common).
A mention right after 'was' / 'were' stays (history). String edits only.
usage: refresh_qualified_r9d.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import apply_r9d_structs_data as D  # noqa: E402

PAIRS = []
for old_t, new_t, old_i, new_i, _, fields in D.STRUCTS:
    for old_f, (new_f, _) in fields.items():
        PAIRS += [(f"{old_i}.{old_f}", f"{new_i}.{new_f}"), (f"{old_t}.{old_f}", f"{new_t}.{new_f}")]
for k, (name, _) in enumerate(D.SPLIT):
    PAIRS += [(f"protection_status_flags_t_0040b0f2.flags[{k}]", f"transmission_shift_strategy_flags.{name}"),
              (f"protection_status_flags_t.flags[{k}]", f"transmission_shift_strategy_flags_t.{name}")]
PAIRS += [("protection_status_flags_t_0040b0f2.flags", "transmission_shift_strategy_flags.anti_hunt_flags"),
          ("protection_status_flags_t.flags", "transmission_shift_strategy_flags_t.anti_hunt_flags")]
HISTORY = re.compile(r"(\bwas|\bwere|\(was)\s*`?$")
files = [os.path.join(out, f) for f in ("global_variables.csv", "function_renames.csv", "structure_definitions.csv",
                                        "enums.csv", "labels.csv", "constants.csv")] + [os.path.join(repo, "firmware", "CLAUDE.md")]
for path in files:
    text = open(path).read()
    total = 0
    for old, new in PAIRS:
        pat = re.compile(r"(?<![A-Za-z0-9_])" + re.escape(old) + r"(?![A-Za-z0-9_\[])")

        def sub(m):
            nonlocal_total[0] += 1 if not HISTORY.search(text[max(0, m.start() - 12):m.start()]) else 0
            return m.group(0) if HISTORY.search(text[max(0, m.start() - 12):m.start()]) else new
        nonlocal_total = [0]
        text = pat.sub(sub, text)
        total += nonlocal_total[0]
    open(path, "w").write(text)
    print(os.path.basename(path), total)
