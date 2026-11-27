"""Round 25 closing: task 046, the PR body, the README, the todo line. Idempotent.
usage: apply_r25_closing.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = """## Done, round 25 (2026-11-22, same PR; the relayed "keep going" again): an enum and three shapes from the round 24 leads

Scripts are in `session_folder/round25/`.
- **Stage A (91a9b02, types):** `TRANSMISSION_SELECTED_GEAR`, the J1939 SPN 524 coding (one gear per bit, -125
  offset, 251 = park).
  - It types `transmission_selected_gear`, its `_previous` / `_last_valid` copies and
    `j1939_powertrain_control_state.etc2_transmission_selected_gear`.
  - Every literal they meet has a member: 54 renders, and no value renders as an OR of members.
  - The unapplied `PROTECTION_OVERRIDE` is gone; its members were named after the ASCII glyphs of 0x7e / 0x7f.
- **Stage B (930aac0, types): the TouCAN A register map.**
  - `mpc555_initCanController` proves the module registers sit at 0x307080-0x3070a7 and the message buffers at
    0x307100-0x3071ff.
  - The repo had put the module at 0x307000 (no code touches 0x307000-0x30707f) and modelled 0x307080 / 90 / a0 as
    message buffers 0-2.
  - New: `toucan_a` (`toucan_module_registers_t`, the register CSV's own mnemonics at the right base) and
    `toucan_a_message_buffers` (`toucan_message_buffer_t[16]`).
  - 31 global rows and 26 register rows went; pieces fell 492 -> 480.
- **Stage C (438b543, types): the executive frame timing (e2m 12A6).**
  - `executive_frame_timings` (`executive_frame_timing_t[40]`): one record per main loop phase.
  - Its two walking pointers are typed, so `main_loop` reads `->maximum_ticks` and so on.
  - The helpers are named, and 0x3feec0 has its row.
  - Stage C's commit message and first comment said 11 phases: a case count that missed the hex labels. `main_loop`
    has 40 phases (0-39), and record n holds phase n; stage D's commit fixed the comment.
- **Stage D (170236d, types): the boot kernel's two diagnostic response messages (0x303047 / 0x303056).**
  - They are `diagnostic_response_message_t`: the header, the data pointer and a status pointer. The last field
    points at the status byte after each record, so they are not `j1939_tx_msg_t`.
  - The status bytes are named, and the allocator returns the typed pointer.
- **Round 25 leads:**
  - The sensor channel blocks (round 24's lead, not started).
  - TouCAN B's base. The register CSV says 0x307400; no code uses TouCAN B, so nothing proves it.
  - `cm848_writeCan2ControllerTxMailbox` (boot ROM) and `cm848_writeCanControllerTxMailbox` both write TouCAN A, so
    the "Can2" looks wrong.
  - The kernel transport reads `msg_header[1].can_id` / `*(dword *)&msg_header[1].data_length`. Typed
    `diagnostic_response_message_t *`, its message parameter would make them `->data_pointer` / `->status_pointer`;
    check the callers first.
  - From round 24: named fault bits (the user's call) and `diag_clear_flags_t`.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 25 (the relayed \"keep going\" again): an enum and three shapes from the round 24 leads.**\n"
     "- **Stage A (91a9b02, types):** `TRANSMISSION_SELECTED_GEAR` (J1939 SPN 524) on the four gear words; the junk\n"
     "  `PROTECTION_OVERRIDE` enum gone.\n"
     "- **Stage B (930aac0, types):** the TouCAN A register map at its real base (`toucan_a`, `toucan_a_message_buffers`).\n"
     "- **Stage C (438b543, types):** the executive frame timing records (e2m 12A6) and their typed walking pointers.\n"
     "- **Stage D (170236d, types):** the boot kernel's two diagnostic response messages.\n"
     "- Open after round 25: the sensor channel blocks, TouCAN B's base, the kernel transport's message parameter,\n"
     "  named fault bits (the user's call), `diag_clear_flags_t` (task 046).\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 24: stages B, C and D are EQUIVALENT",
     "- [x] Round 25: stage A passes the enum proof (0 differences beyond the substitution); stages B, C and D pass the\n"
     "  token gate with only the intended functions changed (B: one same-address temporary, C: `main_loop`'s typed\n"
     "  pointers, D: the allocator's typed return); pieces 492 -> 480.\n"
     "- [x] Round 24: stages B, C and D are EQUIVALENT")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 25: an enum and three shapes (`session_folder/round25/`)\n\n"
       "- **Stage A:** `apply_r25a.py`, which is checked by `check_enum_proof3.py` from round 13.\n"
       "- **Stage B:** `apply_r25b.py`. `raw_addr_scan_any.py` is round 22's scanner with the `lis` base taken from\n"
       "  the range; round 22's version only tried 0x40 / 0x41.\n"
       "- **Stage C:** `apply_r25c.py`. **Stage D:** `apply_r25d.py`.\n"
       "- **The proofs:** `tokens_r25*.json`, checked by round 24's `prove_tokens.py`.\n"
       "- **Closing:** `apply_r25_closing.py`.\n")
if "## Round 25:" not in t:
    i = t.index("## Round 24:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "the throttle dword split - open: the task 046 leads",
     "the throttle dword split; round 25: TRANSMISSION_SELECTED_GEAR (SPN 524), the TouCAN A register map at its real "
     "base, the executive frame timing records, the boot kernel's response messages - open: the task 046 leads")
print("round 25 closing applied")
