"""Round 91 closing: task 046, PR body, session README, todo, the memory round log. Idempotent.
usage: apply_r91_closing.py <repo> <pr_body.md> <count>"""
import os
import re
import sys

repo, pr, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p, newline="").read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))


T46 = """## Done, round 91 (2026-11-24, same PR): the fault count / datalogger / gain set structs; the J1939 receive layer twins

Peer relays started and continued the round (15:49, 16:19, 16:49). The scripts and the workflow's items
(`item_S1..T2.json`: each proposal with its skeptic verdicts) are in `session_folder/round91/`.
- **900ff89c, workflow wf_368d2db4-707 (10 agents):** 216 elements confirmed and 11 amended (comment text); none
  refuted.
  - **S1:** `fault_count_record_t` / `fault_count_table[125]` (0x805a1c, e2m 1031). The 27 J90280.05-map rows inside
    it are gone, and the 0x1452e split went to deleted_functions.csv. The fault countdown functions are counterparts
    in both firmwares (`cm550_countDownPreviouslyActiveFault(s)` / `cm848_countDownPreviouslyActiveFault(s)`,
    `cm550_processFaultScanGroup`, `cm550_resetFaultStatus`).
  - **S2:** the user datalogger (e2m 1282 / 1283): `datalogger_trigger_t[4]`, `datalogger_data_parameter_t[5]`,
    `datalogger_trigger_information_t`, its working RAM and 9 functions. 63 rows inside the new arrays are gone.
    0x800358 `main_loop_phase_index` was a stale claim (it is `scheduler_phase_index` 0x80068c); two docs and an enum
    comment were corrected.
  - **S3:** CM550 takes CM848's `all_speed_governor_gain_set_t`: the TSC1 condition gain sets [4], the throttle mode
    and application sets, and `all_speed_governor_gain_set_pointer`.
  - **T1:** the J1939 receive layer is CM848's twin. The six handlers and `registerJ1939ReceiveHandler` share one
    unprefixed name, and CM550's 0x21a5c / 0x21c3c are created as functions. Also typed: the receive handler table,
    the input signal descriptor table (it now indexes `[i].logical_switch`), the timeouts, and the 23 receiver bytes
    with CM848's names.
  - **T2:** `findTsc1SourceConfiguration` (twin); CM550's `tsc1_source_configuration_table[5]` and its three
    pointers, named like CM848's fields (`*_ptr` -> `*_pointer`); `j1939_received_wet_tank_pressure` in both
    firmwares (CM848's was `j1939_received_accelerator_pedal_position_2`).
  - **`refresh_references.py`** protects a whole "were a / b / c" list; a 120-character window had let the later
    names be refreshed. A test fails on the old window.
  - **Proof:** CM550 verify DETERMINISTIC (the split removed and the 2 handlers added, on purpose; 42 functions
    changed; caller artifacts unchanged); CM848 label-only; tests pass; headers 0 errors; _cal HARD 0.
- **firmware/CLAUDE.md:** the J1939 input layer bullet names the twins, through the refresh (the full lines are in
  the commit's report).
- **Leads (round 92):**
  - Indexed struct-array reads whose stride the code builds with shifts / adds still print as byte arithmetic on a
    field, `(int)&datalogger_triggers_cal[0].parameter_offset + offset`.
  - The CM550 audit's 478 named rows that disagree with their description.
  - A fueling state enum for CM550.
  - Carried: the misnamed PGN builders; `linearization_table_ch15_x_axis` (channel 0's table); 0x803f40 `_cal`;
    ESCMES / ENGRPM; the DIAG enum members 0x42 / 0x52 / 0x54; the descriptor rows 0x801ab6-0x801b0d;
    `cm550_peakTorqueFuelCorrection`; `cm550_j1939TorqueControlMode*`; `cm848_mathMultiplyDivide32`'s fall-through;
    0x80ddd3; the A/D array-end bound render; the one stage C type that could not be applied.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "\n**Round 91.**\n"
     "- **900ff89c:** a second skeptic-verified workflow:\n"
     "  - CM550's fault count table, its user datalogger records and the all-speed governor gain sets as structs;\n"
     "  - the J1939 receive layer (6 handlers + the registration function) and the TSC1 source configuration finder\n"
     "    as twins of CM848's, with one name in both;\n"
     "  - `refresh_references.py` keeps a long history list intact.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-90):**", "- **Beyond CM848 (rounds 72-91):**")
edit(pr, "- [x] Round 90: D: ",
     "- [x] Round 91: CM550 verify DETERMINISTIC (the 0x1452e split removed and the 2 receive handlers added on purpose; 42 functions changed; caller artifacts unchanged); CM848 verify DETERMINISTIC, label-only; test suites pass (a new refresh test fails on the old 120-character window); headers 0 g++ errors; _cal HARD 0.\n"
     "- [x] Round 90: D: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 91: structs and J1939 twins (`session_folder/round91/`)\n\n"
       "- `rows_in_ranges_r91.py` (the rows inside each struct candidate), `item_S1..T2.json` (the workflow's proposals and\n"
       "  verdicts), `peek_r91.py` / `dump_items_r91.py`, `apply_r91.py` (applies the verified elements, with the\n"
       "  amendments), `keep_lists_r91.py`, `run_r91.sh` (apply + refresh), `review_refresh_r91.py` (every refresh change\n"
       "  against the post-apply snapshot), `fix_phase_index_docs_r91.py`.\n"
       "- **Closing:** `apply_r91_closing.py`, `update_large_tar_r91.sh`.\n")
if "## Round 91:" not in t:
    i = t.index("## Round 90:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "a 162-row naming wave, CM848's DM8 payload - open:",
     "a 162-row naming wave, CM848's DM8 payload; round 91: the fault count / datalogger / gain set structs, the J1939 "
     "receive layer twins - open:")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
for name, pat, rep in (("MEMORY.md", r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)"),
                       ("pr53_egr_flow_delay_rounds.md", r"is still OPEN on 2026-11-24\n\(\d+ commits\)",
                        f"is still OPEN on 2026-11-24\n({count} commits)")):
    p = M + name
    s = open(p).read()
    s2 = re.sub(pat, rep, s)
    assert f"{count} commits" in s2, name
    open(p, "w").write(s2)
log = M + "pr53_egr_flow_delay_rounds.md"
s = open(log).read()
note = ("- Round 91 (a 10-agent workflow: CM550 fault_count_table / datalogger records / all_speed_governor_gain_set_t "
        "structs; the J1939 receive layer + findTsc1SourceConfiguration are twins (one unprefixed name in both); "
        "refresh_references.py now protects a whole were-list (the 120-char window rewrote long histories); struct "
        "arrays whose stride is built with shifts / adds still print as byte arithmetic on a field)\n")
if "- Round 91 (" not in s:
    open(log, "w").write(s.rstrip("\n") + "\n" + note)
print("round 91 closing applied")
