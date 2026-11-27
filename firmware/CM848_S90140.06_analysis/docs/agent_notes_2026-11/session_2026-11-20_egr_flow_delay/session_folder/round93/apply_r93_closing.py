"""Round 93 closing: task 046, PR body, session README, todo, the memory round log. Idempotent.
usage: apply_r93_closing.py <repo> <pr_body.md> <count>"""
import os
import re
import sys

repo, pr, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new, optional=False):
    p = path(rel)
    t = open(p, newline="").read()
    if new in t:
        return
    if optional and old not in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))


T46_FILE = "work/tasks/046-cm848-egr-flow-estimate.md"
# the round 92 leads gave two instruction addresses for function rows
edit(T46_FILE, "`vp44SensorStatusMonitor` (0x1d9ca) is the idle shutdown state machine;",
     "`vp44SensorStatusMonitor` (0x1d9b4; its first enable test is at 0x1d9ca) is the idle shutdown state machine;", optional=True)
edit(T46_FILE, "`cm550_engineRunTimeHistogramAccumulator` (0x1ff4e) is the J1939 periodic transmit schedule;",
     "`cm550_engineRunTimeHistogramAccumulator` (0x1ff38; the test is at 0x1ff4e) is the J1939 periodic transmit schedule;", optional=True)
T46 = """## Done, round 93 (2026-11-24, same PR): CM550 structure fixes, freeze frames, task sets, two typing passes

Peer relays started and continued the round (21:19, 21:50, 22:20). Scripts and proofs are in
`session_folder/round93/`. Eight commits; every build verify DETERMINISTIC; no firmware/CLAUDE.md change.
- **1f9043ef, a round 91 defect fixed:** seven CM848 plate comments (the J1939 receive twins) had been replaced by the
  literal text "APPEND to the current comment: ..." from a proposal. Restored from the commit before round 91. The
  round 93 apply script refuses a comment that reads like an instruction.
- **a417e39e + 392a66f9 + 96ffcfa8, 52 function rows that were not functions:** rows on an address in the middle of a
  function (21 inside the executive frame task sets, 30 elsewhere, 1 on a switch case). Each made Ghidra cut a
  function and print its tail a second time under an unrelated name; two functions shared one name
  (`vp44_evenPhaseSchedulerTaskSet`).
  - **Proof per row, from the ROM:** no jsr / jmp operand, branch displacement, pointer or PC-relative reference
    reaches it; a linear disassembly lands on it; the instruction before it does not leave; control flow from the
    holding function's entry reaches it.
  - **Result:** 756 -> 704 functions by address, no remaining function changed its code; 1426 lines of repeated
    code are gone.
  - CM848 has no such row (`cm848_entry_scan_r93.py`: its 213 unreferenced rows all start after a blr).
- **96ffcfa8:** `cm550_initializeEnginePositionSignalInputs` (was cm550_canControllerConfigInit) and
  `engine_position_signal_configuration` (e2m 11CA +3 EPCMTY; was speed_measurement_mode).
- **32ce65c3, the fault freeze frames:** CM550 `cm550_fault_entry_t` (48 bytes) and
  `fault_freeze_frame_entries[40]` at 0x80426a (20 first captures + 20 latest), the counterpart of CM848's
  `fault_entry_t[16]`. Sources named by their Calterm records (`system_switch_status` / `_2` / `_3`,
  `engine_load_at_current_speed_percent`, `engine_hour_meter`, `final_fueling`, three VP44 RAM image words). Six
  CM550 functions and their four CM848 counterparts take parallel names (`..._captureFaultFreezeFrame`,
  `..._assignFaultFreezeFrameEntry`, `..._findOldestFreezeFrameEntryByFaultStatus`; CM550's DM4 handler was
  `evaluateTemperatureDiagnosticState`).
- **7cf52470, the executive frame schedule:** the 45 task sets are `cm550_runEveryFrameTaskSet` and
  `cm550_runEvery<N>FramesTaskSetPhase<P>` (N = 2 / 4 / 8 / 10 / 20), read from the handler's 40-case switch. A frame
  is 5 ms (the hour meters step once per 40 frames and count 0.2 s).
- **31f911b4 + bf0c580d, typing:** 1943 global rows leave 'undefined' (4475 -> 2519).
  - Pass 1 (614 rows): every ROM access has one width, the decompiler printed the row only at that width, and the
    Calterm length agrees (418 of 419).
  - Pass 2 (1329 rows): the Calterm record's length and sign, with no ROM access or decompiler render against it.
  - Signed rows are i16 / i32 (by the code's casts in pass 1, by the Calterm sign flag in both).
  - Underscore renders (a read wider than the row's type) fall from 6373 to 1651.
- **The naming workflow** (an investigator, an independent describer and a judge per call-graph family: J1939
  multiplexed inputs, J1939 dispatch / session history, idle shutdown and diagnostics, the fuel limit chain and the
  unidentified fueling states) lost seven agents to 'API Error: 529 Overloaded'. It was relaunched in a form that
  restarts a dead agent from its notes (`make_sturdy_workflow_r93.py`). Its batches are not applied yet.
- **Leads (round 94):**
  - Apply the workflow's judged batches (`apply_r93.py`; the agents read copies frozen before this round's renames, so
    refresh all round 93 maps afterwards; their names for the three task sets 0x1b754 / 0x1b788 / 0x1b7f2 are dropped).
    159 placeholder function names remain.
  - Families not started: trending / trip information / the data collector; the fuel limit stages and programmable
    power; governors and throttle (with a `commanded_throttle_state` struct: e2m 1047, 13 words; CM848 has it).
  - `hpcr_injectorPulseWidthCalc` (0x26b88) is the only hpcr_ name in CM550 and computes no pulse width.
  - `vp44_messageQueueDispatcher` (0x230ee) sits in the J1939 task set where CM848 runs
    cm848_serviceJ1939TransportSessions.
  - 15 function rows after a return that nothing in the dump calls.
  - Typing left: 235 rows still print with an underscore (array bases such as the system error status words); four
    pointer rows need a pointee type; 0x80a992 has a 4-byte Calterm record but only word accesses.
  - Carried from round 92: the six unidentified fueling states (in the workflow), enable words 10 / 21 / 24 / 29-31 /
    34, the `(ushort)word & mask` renders, and the older carried leads.

## Leads (not in this PR)"""
edit(T46_FILE, "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "\n**Round 93.**\n"
     "- **Structure (a417e39e, 392a66f9, 96ffcfa8):** 52 CM550 function rows sat in the middle of a function (or on a\n"
     "  switch case) and are removed; two functions had shared one name.\n"
     "- **Freeze frames (32ce65c3):** CM550's `cm550_fault_entry_t[40]`, the counterpart of CM848's `fault_entry_t[16]`,\n"
     "  with parallel function names in both firmwares.\n"
     "- **Schedule (7cf52470):** the 45 executive frame task sets named by their slot (`cm550_runEvery<N>FramesTaskSetPhase<P>`).\n"
     "- **Typing (31f911b4, bf0c580d):** 1943 CM550 global rows typed from the ROM, the decompiler and Calterm.\n"
     "- **Fix (1f9043ef):** seven CM848 plate comments that round 91 had overwritten.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-92):**", "- **Beyond CM848 (rounds 72-93):**")
edit(pr, "- [x] Round 92: A: ",
     "- [x] Round 93: typing: CM550 verify DETERMINISTIC twice (614 + 1329 rows; no typed row prints with an underscore or as a piece; 0 functions removed / added; statement counts equal but for one temporary in 5 functions each pass; caller artifacts unchanged).\n"
     "- [x] Round 93: task sets: CM550 verify DETERMINISTIC (45 names, 0 other token changes); schedule read from the ROM's 40-case switch.\n"
     "- [x] Round 93: freeze frames: CM550 verify DETERMINISTIC (57 functions changed by names and field renders; every field store pairs with its source); CM848 verify DETERMINISTIC, label-only.\n"
     "- [x] Round 93: structure: CM550 verify DETERMINISTIC three times (756 -> 704 functions by address; no remaining function changed its code); each removed row proven unreachable from the ROM.\n"
     "- [x] Round 93: fix: CM848 verify DETERMINISTIC (comments only).\n"
     "- [x] Round 92: A: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 93: CM550 structure fixes, freeze frames, task sets, typing (`session_folder/round93/`)\n\n"
       "- **The round 91 plate comment fix:** `fix_r91_plate_comments_r93.py`.\n"
       "- **Mid-function rows:** `call_sites_r93.py` (how the ROM reaches each function row), `apply_r93_midbody.py` (the 21\n"
       "  task set rows), `midfunction_rows_r93.py` / `midbody2_survey_r93.py` / `apply_r93_midbody2.py` (the 30 others),\n"
       "  `midbody2_flow_check_r93.py` (control flow from the holding function), `pc_relative_refs_r93.py`,\n"
       "  `switch_case_rows_r93.py` / `apply_r93_switchcase.py`, `midbody_proof_r93.py` (the by-address proof),\n"
       "  `fix_tail_mentions_r93.py`, `cm848_entry_scan_r93.py` (CM848 has none).\n"
       "- **Freeze frames:** `apply_r93_freeze_frame.py`, `apply_r93_freeze_frame_cm848.py`, `width_census_r93.py`,\n"
       "  `pointer_table_r93.py`, `fix_dm4_comment_r93.py`.\n"
       "- **Position inputs:** `apply_r93_position_inputs.py`.\n"
       "- **Task sets:** `frame_schedule_r93.py` (+ `.tsv`: the 40-phase schedule), `apply_r93_task_sets.py`.\n"
       "- **Typing:** `untyped_width_scan_r93.py`, `untyped_cpp_check_r93.py`, `apply_r93_types.py`, `signedness_r93.py`,\n"
       "  `apply_r93_types_signed.py`, `e2m_width_sign_r93.py`, `apply_r93_types_signed_e2m.py` (pass 1);\n"
       "  `e2m_type_candidates_r93.py`, `apply_r93_types_e2m.py`, `pointer_rows_r93.py` (pass 2); `types_proof_r93.py`,\n"
       "  `line_count_diff_r93.py`, `underscore_census_r93.py`.\n"
       "- **The naming workflow (not applied yet):** `function_candidates_r93.py`, `families_r93.py`,\n"
       "  `batch_tables_r93.py`, `make_retry_workflow_r93.py`, `make_sturdy_workflow_r93.py` (+ the `.js`),\n"
       "  `apply_r93.py` with `test_apply_r93.sh` and `patch_apply_guard_r93.py`, `dump_batches_r93.py`, `run_r93.sh`.\n"
       "- **Shared:** `refresh_r93.sh`, `review_refresh_r93.py`, `round_counts_r93.py`, the `map_r93*.csv` rename maps,\n"
       "  the commit messages. **Closing:** `apply_r93_closing.py`, `update_large_tar_r93.sh`.\n")
if "## Round 93:" not in t:
    i = t.index("## Round 92:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 92: CM550's FUELING_STATE enum and algorithm enable bitfields - open:",
     "round 92: CM550's FUELING_STATE enum and algorithm enable bitfields; round 93: 52 mid-function rows removed, "
     "freeze frame struct, task sets by schedule slot, 1943 rows typed - open:")
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
note = ("- Round 93 (CM550: 52 function rows sat mid-function - scan the ROM for every way a row is entered before trusting a "
        "function row, incl. PC-relative and switch tables; fault freeze frames = cm550_fault_entry_t[40] at 0x80426a; "
        "executive task sets cm550_runEvery<N>FramesTaskSetPhase<P>, frame = 5 ms; typing passes with three witnesses "
        "(ROM access widths, decompiler underscore renders, Calterm N-record length + sign flag in column 10) typed 1943 "
        "rows; an apply must refuse proposal comments that are instructions ('APPEND to ...'); workflow agents die on "
        "'529 Overloaded' - wrap agent() in a retry loop that continues from a notes.md, and pass finished results in "
        "via args; the naming workflow's batches J1 / J2 / D1 / F1 still to apply in round 94)\n")
if "- Round 93 (" not in s:
    open(log, "w").write(s.rstrip("\n") + "\n" + note)
print("round 93 closing applied")
