"""Round 22 closing: the round 22 sections of task 046, the PR body, the session README and the todo line.
Idempotent. usage: apply_r22_closing.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t and t.count(old) <= t.count(new):
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


TASK = """## Done, round 22 (2026-11-22, same PR; the relayed "keep going" again): the engine protection leftovers

Scripts are in `session_folder/round22/`.
- **Stage A (14be183, label-only):** round 21's leads.
  - The boot / restart resets: `cm848_resetEngineProtectionShutdownState` (was `cm848_completeEngineStartSequence`;
    it is no part of an engine start), `cm848_resetEngineProtectionPrecrankState` (was
    `cm848_initSensorChannelDataStructures`), `cm848_resetEngineProtectionShutdownOverrideDetector`.
  - The override detector's words are logical switch 31's previous state and the pending request, not J1939 state.
    Task 025 had read them the same way.
  - The fault derate's J1939 torque curve (PGN 65251) adjustment: its initializer, its fuelings and speed points, its
    priority bit (1 << e2m EPF_Torque_Curve_Priority) and its lookup cache.
  - New rows: the shutdown channel recorded at power-up (`lha`), and the derate table's cache at the engine speed.
  - The configuration flags are documented bit by bit in their field comment. They are not a clean bitfield: most
    tests go through a whole word copy, with combined masks.
- **Closed leads:**
  - `function_definitions.csv`'s `int` maps to unsigned `dword` on purpose (`int32_t` is the signed one), and its
    `short` is an unsigned word, unlike the struct importer's. The importer says so in a comment and reports unknown
    types (`Error: Unknown type`). Write signed prototype types as `sword` / `int32_t`.
  - The 10DA engine overspeed log was already typed (`engine_overspeed_event_t[5]`). It has the fault log entry's
    shape but an unsigned value (the engine speed), so it stays a type of its own.
  - `DAT_0040a78c` only ever gets 0 (four `sth`, no load), so it stays unnamed.
- **Methods:** the scratch raw scanner (`raw_addr_scan.py`) accepted any `lis` of the base register in its 8-word
  window, not the nearest one, so it reported false hits (0x51f884 reads 0x40bd4e, not 0x3fbd4e). It never hid one.
  Fixed in `session_folder/round22/`; the round 19 control and the ANC range give the same counts.

## Leads (not in this PR)
"""
t46 = "work/tasks/046-cm848-egr-flow-estimate.md"
t = open(path(t46)).read()
if "## Done, round 22" not in t:
    assert t.count("## Leads (not in this PR)\n") == 1
    open(path(t46), "w").write(t.replace("## Leads (not in this PR)\n", TASK, 1))
PR_ROUND = """**Round 22 (the relayed "keep going" again): the engine protection leftovers.**
- **Stage A (14be183, label-only):** the module's boot / restart resets, the shutdown override detector's words, the
  fault derate's J1939 torque curve adjustment (PGN 65251), two new rows, and the configuration flags documented.

## Test plan
"""
edit(pr, "\n## Test plan\n", "\n" + PR_ROUND)
edit(pr, "- [x] Round 21: stages A and B pass a layout / containment / artifact gate",
     "- [x] Round 22: stage A is EQUIVALENT (12 names).\n"
     "- [x] Round 21: stages A and B pass a layout / containment / artifact gate")
edit(pr, "- **Open after round 21:**\n", "- **Open after round 22:**\n")
README = path("firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md")
t = open(README).read().rstrip("\n")
if "## Round 22" not in t:
    t += """

## Round 22: the engine protection leftovers (`session_folder/round22/`)

- **Stage A:** `worklist_r22a.py`, `apply_r22a2.py` (the two new rows and the configuration flags comment).
  **Closing:** `apply_r22_closing.py`. `raw_addr_scan.py` is the fixed scanner (the nearest `lis` decides).
"""
    open(README, "w").write(t + "\n")
TODO = path("work/todo.md")
lines = open(TODO).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("046 [>]"))
if "round 22" not in lines[i]:
    tail = " - open: the task 046 leads"
    assert lines[i].endswith(tail), lines[i][-60:]
    lines[i] = lines[i][:-len(tail)] + ("; round 22: the engine protection resets, override detector and J1939 torque "
                                        "curve derate named, the configuration flags documented" + tail)
    open(TODO, "w").write("\n".join(lines))
print("closing edits applied")
