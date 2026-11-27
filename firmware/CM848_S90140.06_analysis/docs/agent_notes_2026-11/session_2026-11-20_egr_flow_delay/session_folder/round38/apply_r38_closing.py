"""Round 38 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r38_closing.py <repo> <pr_body.md> <hash A> <commit count>"""
import os
import sys

repo, pr, ha, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 38 (2026-11-22, same PR): the named lookup cache rows audited

A peer relay started the round. Scripts are in `session_folder/round38/`.
- **Stage A ({ha}, labels, types):** `cache_audit.py` checks the 345 named cache rows against their own lookups.
  - 34 2-D caches typed as one word were widened to `word[2]`. Fifteen y halves that were separate rows became
    `name[1]` dotted rows; ten of them were `_y` rows, five had legacy names.
  - 24 misnamed caches now carry their own table's name: `fault_slot_state_5` / `_7`, `diag_state_group1_a` / `_c`,
    the `fuel_pressure_diagnostic_*` set, `governor_pid_init_state_*`, and the injection pulse width / pilot
    correction caches that had timing names.
  - Proof: all 1968 functions match `prove_caches.py`'s canonical form.
  - The re-audit leaves 6 width / 23 name findings, all of them skips.
- **Leads:**
  - Rename the legacy `_cal` tables, then their caches: `cylinder_event_values_*_cal`, `cylinder_seq_yend_cal`,
    `j1939_fuel_table_yend_cal`, `governor_fuel_demand_output_cal`, `engine_sync_speed_correction_values_cal`,
    `engine_event_countdown_values_cal`, `injection_timing_temp_corr_axis1_cal`, `safety_fuel_limit_rpm_axis_cal`.
  - `engine_retarder_torque_cached_axis_offset`: its lookup's data argument renders as the phantom `in_r6`, a
    prototype question.
  - The tables with several caches need per-function cache words (round 37's lead).

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 38.**\n"
     f"- **Stage A ({ha}, labels, types):** the named lookup cache rows audited against their own lookups: 34\n"
     "  2-D caches widened to `word[2]` (15 y halves merged) and 24 misnamed caches renamed after their tables.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 37: every function matches the canonical form",
     "- [x] Round 38: all 1968 functions match the canonical form.\n"
     "- [x] Round 37: every function matches the canonical form")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 38: the named lookup cache audit (`session_folder/round38/`)\n\n"
       "- `cache_audit.py` (named caches vs their lookups), `second_words.py` (a 2-D cache's y half), `apply_r38a.py`; "
       "the proof is round 37's `prove_caches.py`. **Closing:** `apply_r38_closing.py`.\n")
if "## Round 38:" not in t:
    i = t.index("## Round 37:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 37: 120 lookup cache words - open: the task 046 leads",
     "round 37: 120 lookup cache words; round 38: the named cache audit (34 widened / 24 renamed) - open: the task 046 "
     "leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = m.replace("(cm848/egr-flow-delay-model, 187 commits)", f"(cm848/egr-flow-delay-model, {count} commits)")
old = "+ round 37 (120 lookup cache words named from their own lookups, cache_names.py); task 046 leads"
new = ("+ round 37 (120 lookup cache words named from their own lookups, cache_names.py) + round 38 (named cache audit: "
       "34 2-D caches widened to word[2], 24 renamed); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 38 (2026-11-22): {ha} cache_audit.py over the 345 named caches: 34 2-D caches typed word widened to "
        "word[2] (15 separate y-half rows merged as name[1]), 24 legacy-guess names replaced by <table>_cached_axis_"
        "offset(s) (_2 where a table has a second cache). Next: rename the legacy _cal tables, then their caches.\n")
if "Round 38 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 38 closing applied")
