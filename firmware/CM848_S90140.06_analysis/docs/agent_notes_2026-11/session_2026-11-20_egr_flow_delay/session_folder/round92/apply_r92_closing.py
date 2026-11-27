"""Round 92 closing: task 046, PR body, session README, todo, the memory round log. Idempotent.
usage: apply_r92_closing.py <repo> <pr_body.md> <count>"""
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


T46 = """## Done, round 92 (2026-11-24, same PR): CM550's fueling state enum; the algorithm enable words as bitfields

Peer relays started and continued the round (17:19, 17:50, 17:58, 19:19, 19:49, 20:19, 20:49). The scripts and the
workflow's batches (`batch_W1..W4.json`: each proposal with its skeptic verdicts) are in `session_folder/round92/`.
- **Stage B (79bac6ef), `FUELING_STATE` for CM550:** CM550's e2m (FSFNFLST) labels codes 0x00-0x29 with CM848's
  numbering, so the enum is CM848's twin: 32 codes take CM848's member names; 10 have no CM848 member (4 named from
  plain labels, 6 `FUELING_STATE_UNIDENTIFIED_<n>`). Seven carriers are typed; four take CM848's names for the same
  e2m records (`final_fueling_state`, `adjusted_user_fueling_state`, `torque_derate_fuel_source_code`,
  `power_take_off_or_user_fueling_state`).
  - **Proof:** CM550 verify DETERMINISTIC; 43 functions changed by the four renames and 166 member renders; no value
    renders as an OR of members; caller artifacts unchanged.
- **Stage A (bd662d12), the algorithm enable words (e2m 106B, CM550 0x803c92):** workflow wf_5794b4eb-1ec, an
  investigator and a skeptic per batch of words. Four of its agents were refused by a weekly usage limit; the run was
  resumed after the session's model changed. 437 elements confirmed, 28 amended (27 comment texts, one field name),
  none refuted.
  - Every row is `algorithm_enable_flags_<n>_cal` (11 renamed - the old names used five patterns and one wrong
    number - and 18 new).
  - 4 words share CM848's type bit for bit (1, 4, 11, 25); 14 get `cm550_algorithm_enable_flags_<n>_t`; 11 stay
    plain words (the length, word 0 - the base of the indexed bit tests - and the words reached only by index).
  - CM848 gains four field names from its own e2m (word 3 bits 12-14: the acceleration noise control enables; word
    12 bit 1: `overspeed_fuel_shutoff_enable`), and word 3 bit 8 is `gear_down_protection_enable`.
  - Two previous-pass copies: `user_fueling_state_previous_pass`, `final_fueling_state_prev`.
  - **Proof:** CM550 verify DETERMINISTIC; 90 functions changed; all 132 mask tests in the census became the field
    of exactly that bit on the same word (`mask_exact_r92.py`); no store renders as a piece; caller artifacts
    unchanged. CM848 label-only. Tests pass; headers 0 errors; _cal HARD 0 (CM550 MISSING 25 -> 14).
- **firmware/CLAUDE.md:** one sentence in the bitfield bullet: CM550's Ghidra 12.2 renders bitfield names too.
- **Leads (round 93):**
  - Function names the bitfield agents found wrong (`bitfield_notes_r92.txt` and the field comments):
    - `vp44SensorStatusMonitor` (0x1d9ca) is the idle shutdown state machine;
    - `cm550_engineRunTimeHistogramAccumulator` (0x1ff4e) is the J1939 periodic transmit schedule;
    - `mc68k_FUN_000212b2` is the J1939 receive dispatch;
    - `vp44_communication_state_machine` (0x13616) is the data collector sampler;
    - `cm550_j1939MessageTypeCounter` / `cm550_memoryRegisterController` record the J1922 / J1939 control session
      history.
  - The six `FUELING_STATE_UNIDENTIFIED_<n>` labels (PSSPEED, ANCDERAT, EPF, ESUOILLM, PTPDERAT, T2DERAT): name them
    from the code that stores each state.
  - The fault snapshot records: 48-byte slots at 0x80426e / 0x80462e (the final fueling state at +26).
  - Enable words 10, 21, 24, 29-31 and 34 have no reference and no row; about 28 places print
    `(ushort)algorithm_enable_flags_<n>_cal & mask` where the code keeps the masked value.
  - Carried: indexed struct-array reads printing as byte arithmetic; the audit's disagreeing rows; the misnamed PGN
    builders; `linearization_table_ch15_x_axis`; 0x803f40 `_cal`; ESCMES / ENGRPM; the DIAG enum members 0x42 / 0x52 /
    0x54; the descriptor rows 0x801ab6-0x801b0d; `cm550_peakTorqueFuelCorrection`; `cm550_j1939TorqueControlMode*`;
    `cm848_mathMultiplyDivide32`'s fall-through; 0x80ddd3; the A/D array-end bound render.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "\n**Round 92.**\n"
     "- **Stage B (79bac6ef):** CM550's `FUELING_STATE` enum, the twin of CM848's (the same Calterm labels), and its\n"
     "  seven carriers.\n"
     "- **Stage A (bd662d12):** CM550's algorithm enable words (e2m 106B) as bitfield structs from a skeptic-verified\n"
     "  workflow: `algorithm_enable_flags_<n>_cal`, 4 types shared with CM848, 14 `cm550_` types, 11 plain words; four\n"
     "  CM848 reserved bits named from its own e2m.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-91):**", "- **Beyond CM848 (rounds 72-92):**")
edit(pr, "- [x] Round 91: ",
     "- [x] Round 92: A: CM550 verify DETERMINISTIC (0 functions removed / added; 90 changed; 132 of 132 mask tests became the field of that exact bit on the same word; no piece render; caller artifacts unchanged); CM848 verify DETERMINISTIC, label-only; test suites pass; headers 0 g++ errors; _cal HARD 0.\n"
     "- [x] Round 92: B: CM550 verify DETERMINISTIC (43 functions changed by 4 renames and 166 enum member renders; no OR render; caller artifacts unchanged); headers 0 g++ errors; _cal HARD 0.\n"
     "- [x] Round 91: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 92: CM550's fueling state enum and algorithm enable bitfields (`session_folder/round92/`)\n\n"
       "- **Stage B:** `compare_fueling_state_r92.py` (CM848's members against CM550's Calterm labels), `apply_r92b.py`.\n"
       "- **Stage A:** `enable_words_r92.py` (the e2m records of each word), `pilot_bitfield_r92.py` (the thrown-away pilot:\n"
       "  bitfield names render on CM550), `batch_W1..W4.json` (the workflow's proposals and verdicts),\n"
       "  `dump_words_r92.py` / `check_shared_r92.py`, `make_amend_r92a.py` -> `amend_r92a.json` (the skeptics' amendments\n"
       "  as exact values), `apply_r92a.py`, `fix_cm848_word3_comment_r92.py`, `apply_r92a_prev.py` / `abs_refs_r92.py` (the\n"
       "  two previous-pass rows and their access widths), `apply_r92a_word20.py`, `mask_exact_r92.py` (the proof that each\n"
       "  mask test became the field of that bit), `bitfield_notes_r92.txt`, `scratch/` (the agents' own scripts).\n"
       "- **Closing:** `apply_r92_claude_md.py`, `apply_r92_closing.py`, `update_large_tar_r92.sh`.\n")
if "## Round 92:" not in t:
    i = t.index("## Round 91:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 91: the fault count / datalogger / gain set structs, the J1939 receive layer twins - open:",
     "round 91: the fault count / datalogger / gain set structs, the J1939 receive layer twins; round 92: CM550's "
     "FUELING_STATE enum and algorithm enable bitfields - open:")
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
note = ("- Round 92 (CM550 FUELING_STATE = CM848's twin enum from the e2m FSFNFLST labels; CM550's AENBLFLG words "
        "0x803c92 as algorithm_enable_flags_<n>_cal bitfields - 4 shared CM848 types, 14 cm550_ types, plain words where "
        "indexed; Ghidra 12.2 renders 68k bitfields; a usage-limit-refused workflow resumes with resumeFromRunId after a "
        "model change; mask_exact proof = census mask -> field bit)\n")
if "- Round 92 (" not in s:
    open(log, "w").write(s.rstrip("\n") + "\n" + note)
print("round 92 closing applied")
