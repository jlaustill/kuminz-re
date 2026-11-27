"""Round 37 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r37_closing.py <repo> <pr_body.md> <hash A> <commit count>"""
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


T46 = f"""## Done, round 37 (2026-11-22, same PR): 120 lookup cache words named from their own lookups

A peer relay started the round. Scripts are in `session_folder/round37/`.
- **Stage A ({ha}, labels, types):** `cache_names.py` names every unnamed cache word from its interpolator calls:
  `<table>_cached_axis_offset` (word, 1-D) / `_cached_axis_offsets` (word[2], 2-D), where `<table>` is the lookup's
  data table.
  - 119 caches are named that way. By hand, 0x3fd134 is the pilot blend maps' shared 2-D cache (was
    `timing_limit_boost_blend_cached_axis_offset`, word).
  - These were the DAT_ words of the injection state initializers that led round 32's ranking.
  - `prove_caches.py` (a canonical form for the 2-D `&DAT_a` -> `name` change): every function matches apart from a
    declaration reorder and one type-only `WORD_` render.
- **Leads:**
  - Eleven caches skipped:
    - six of tables that another cache already names, which need a per-function word (one table is looked up from
      five functions);
    - three of unnamed tables (`WORD_ARRAY_00406778` / `WORD_ARRAY_0040770e` / a `PTR_` label);
    - two whose tables keep legacy names (`injection_timing_temp_corr_axis1_cal`, `safety_fuel_limit_rpm_axis_cal`):
      rename those tables first.
  - Named cache rows whose names do not match their lookups (0x3fd134 was one): an audit like `cache_names.py`
    over the named rows.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 37.**\n"
     f"- **Stage A ({ha}, labels, types):** 120 lookup cache words named from their own lookups\n"
     "  (`<table>_cached_axis_offset(s)`); 0x3fd134 was named for the wrong table.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 36: stages A / B are token-equal",
     "- [x] Round 37: every function matches the canonical form apart from one declaration reorder and one\n"
     "  `WORD_` render of the same cache.\n- [x] Round 36: stages A / B are token-equal")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 37: 120 lookup cache words (`session_folder/round37/`)\n\n"
       "- `cache_users.py` (a cache range's lookups), `cache_names.py` (names every unnamed cache from its lookups), "
       "`apply_r37a.py`, the proof `prove_caches.py`. **Closing:** `apply_r37_closing.py`.\n")
if "## Round 37:" not in t:
    i = t.index("## Round 36:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 36: EFL/P1 + PGN 65504 payloads, the boot diagnostic request path - open: the task 046 "
                     "leads",
     "round 36: EFL/P1 + PGN 65504 payloads, the boot diagnostic request path; round 37: 120 lookup cache words - "
     "open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = m.replace("(cm848/egr-flow-delay-model, 184 commits)", f"(cm848/egr-flow-delay-model, {count} commits)")
old = ("the boot diagnostic request prototypes: a fake service code 0x2d was a pointer's low byte); task 046 leads")
new = ("the boot diagnostic request prototypes: a fake service code 0x2d was a pointer's low byte) + round 37 (120 "
       "lookup cache words named from their own lookups, cache_names.py); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 37 (2026-11-22): {ha} 120 lookup cache words named <data table>_cached_axis_offset(s) by "
        "cache_names.py (r37 folder; name from the data table, not the axis - axes are shared). Proof: canonicalize "
        "the 2-D &DAT_a -> name / name[0] / name[1] change (prove_caches.py). Leads: 11 skipped caches, an audit of "
        "named cache rows.\n")
if "Round 37 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 37 closing applied")
