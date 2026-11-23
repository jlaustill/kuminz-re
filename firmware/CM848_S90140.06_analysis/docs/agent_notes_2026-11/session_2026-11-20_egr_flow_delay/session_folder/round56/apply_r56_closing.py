"""Round 56 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent.
usage: apply_r56_closing.py <repo> <pr_body.md> <hash A> <count> <proof> <unprefixed left>"""
import os
import re
import sys

repo, pr, ha, count, proof, left = os.path.abspath(sys.argv[1]), *sys.argv[2:7]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 56 (2026-11-23, same PR): the discrete output overrides replace the last protection_* names

A peer relay started the round; the scripts are in `session_folder/round56/`.
- **Stage A ({ha}):** the 0x514048-0x514394 "protection" cluster and its globals are the discrete output overrides.
  - **The blocks:** e2m 8B5B (the override priority word and five enable / value byte pairs) and 8C29 (six more
    pairs). Neither is in the parameter ID table. They tile the gap from 8A79 (ends at 0x408787) to 8A5F (0x4087a0)
    exactly, and every pair is passed with the logical output its e2m record names. The output's own module and its
    round 32 read-back check use the same number.
  - **The types:** `discrete_output_override_t` (enable / value), with 11 instances named from the read-back stems.
    Also `discrete_output_override_priority` and the 11 `<stem>_output_override_enable_previous` words.
  - **The functions:** `cm848_applyDiscreteOutputOverride`, `cm848_applyDiscreteOutputOverrides`,
    `cm848_initializeDiscreteOutputOverrides`, `cm848_addCoolantOverheatLevelTimersToTotals` (8A72 timers into the
    8A73 totals at power-down) and `cm848_initializeOverdriveSwitchAndShift`.
  - **No prototype for the per-output helper.** Pilot builds that committed its four parameter names with `dword`,
    `int32_t` or `undefined4` each put a `(uint)` cast on all 33 call arguments (11 -> 44 casts), because a committed
    parameter locks the argument types. The plate names `param_1`-`param_4` instead.
  - **The trap:** the legacy suffixes are decimal output numbers, but `protection_event_11_reset` drove output 0x11
    (17). The script asserts its output table against the decompile's call arguments.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - {left} unprefixed CM848-only functions remain.
  - These 11 logical outputs now have proven names (the other outputs were not counted this round). A
    `LOGICAL_OUTPUT` enum on the first parameter of `cm848_setLogicalOutputRequest` /
    `cm848_clearLogicalOutputRequest` would name them at every call site. This round shows that committing a
    parameter casts every argument that differs from its type, so pilot it and count the casts.
  - Parameter names without the cast cost are untried. The `local_variables.csv` route (it already renames
    `cm848_validateWriteAuth`'s `param_1`) commits the parameter through `updateDBVariable` too, so it may cast the
    same way; a build would tell. Otherwise `ApplyFunctionDefinitions` would have to name parameters without locking
    the prototype, a shared-script change that needs both firmwares rebuilt.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 56.**\n"
     f"- **Stage A ({ha}):** the last `protection_*` names are the discrete output overrides (e2m 8B5B / 8C29, placed by\n"
     "  tiling and by each pair's logical output): `discrete_output_override_t` x 11, the priority word, the previous\n"
     "  enables, and 5 functions.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 55:", f"- [x] Round 56: {proof}\n- [x] Round 55:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 56: the discrete output overrides (`session_folder/round56/`)\n\n"
       "- **Stage A:** `apply_r56a.py`, `map_r56a.csv`, `params_r56a.csv`. Proof: `prove_r56.sh` (the parameter renames "
       "per function, plus a struct-piece count). **Closing:** `apply_r56_closing.py`, `update_large_tar_r56.sh`.\n")
if "## Round 56:" not in t:
    i = t.index("## Round 55:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 55: the fault manager core (15 functions) - open: the task 046 leads",
     "round 55: the fault manager core (15 functions); round 56: the discrete output overrides (e2m 8B5B / 8C29) - "
     "open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "two old names swapped in meaning); task 046 leads"
new = ("two old names swapped in meaning) + round 56 (the discrete output overrides e2m 8B5B / 8C29 replace the last "
       "protection_* names: discrete_output_override_t x 11); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 56 (2026-11-23): {ha}. The discrete output overrides (e2m 8B5B / 8C29, not in the parameter ID table: "
        "tiled + each pair's logical output). Legacy decimal suffixes vs hex output numbers: build such tables from the "
        "call arguments and assert them.\n")
if "Round 56 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 56 closing applied")
