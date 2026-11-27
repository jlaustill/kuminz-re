"""Round 28 closing: task 046, PR body, README, todo. Idempotent.
usage: apply_r28_closing.py <repo> <pr_body.md> <stage A hash> <stage B hash>"""
import os
import sys

repo, pr, ha, hb = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 28 (2026-11-22, same PR): the sensor-present flags, the boot CAN ring state

A peer relay started the round; the leads come from rounds 25-27. Scripts are in `session_folder/round28/`.
- **Stage A ({ha}, label-only):**
  - Three e2m flag records whose row names had turned into readings of their effect:
    - `absolute_boost_pressure_sensor_present_flag` (11D5 +4, was `boost_is_gauge_pressure_flag`). Set,
      `cm848_calculateBoostPressure` subtracts the barometric reference; clear, the sensor's reading is the boost.
      The result is gauge boost either way; the old comment read the clear case as absolute.
    - `barometric_pressure_sensor_present_flag` (11D5 +2, was `boost_uses_barometric_pressure_flag`).
    - `two_speed_axle_switch_present_cal` (1180 +E Rear_Axle_Ratio_Switch_Present, was `two_speed_axle_enable_cal`).
    - `present_flags.py` scanned every table-resolved `*_Present` / `*_Installed` record; these were the only three
      whose row dropped the word.
  - `cm848_writeBootKernelCanTxMailbox` (was `cm848_writeCan2ControllerTxMailbox`): the boot kernel image's
    byte-for-byte copy of `cm848_writeCanControllerTxMailbox`. Both write TouCAN A (the round 25 lead).
  - `can_ring_state_t` / `boot_can_ring_state` (were `can_tx_ring_t` / `j1939_can_ring_buf`): the boot ROM and
    kernel CAN driver's transmit and receive rings. Only boot-side code uses it.
    - Its pointer fields are spelled out.
    - Five stale name-only rows inside it (`qadc_a_ccw_*`, `qadc_a_queue*_wrap_flag`) became dotted rows.
- **Stage B ({hb}, types):**
  - `_pad16` became `transmit_ring_full_flag` / `receive_ring_full_flag` / `reserved_18`.
  - Full prototypes for the two mailbox writers (`can_module`, `mailbox_number`, `frame_words`). Two call sites
    that rendered with two arguments now show the frame they send: the kernel's
    `mpc555_manageCan1TransmitBuffer` and the application's `mpc555_processJ1939TxBufferSend`.
  - The proof: 9 functions differ after the flag tokens. Each matches its old statements with the temps
    anonymized, apart from the frame argument (`diff_flag_users_r28b.py`).
- **Checked and closed:**
  - The 11D5 air fuel control slew rates are already dwords (the wave 15 lead).
  - TouCAN B has no code users, so nothing can prove its base.
- **Still open:** the boot kernel transport's message parameter. Typing it `diagnostic_response_message_t *` needs
  the six callers of `cm848_sendDiagServiceResponse` read for what they pass.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 28 (the round 25-27 leads).**\n"
     f"- **Stage A ({ha}, label-only):** three sensor-present flags named from e2m: the absolute boost sensor flag read\n"
     "  backwards, plus the barometric sensor and the two-speed axle switch. The boot kernel's copy of the CAN transmit\n"
     "  mailbox writer (the old \"Can2\" was not a second controller). The boot CAN ring state struct and its fields.\n"
     f"- **Stage B ({hb}, types):** the ring's two full flags split out of `_pad16`; full prototypes for the mailbox\n"
     "  writers, so two calls that hid their frame argument show it.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 27: stages A and C are EQUIVALENT;",
     "- [x] Round 28: stage A is EQUIVALENT; stage B's 9 differing functions match statement by statement apart from the\n"
     "  frame argument.\n- [x] Round 27: stages A and C are EQUIVALENT;")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 28: the sensor-present flags, the boot CAN ring state (`session_folder/round28/`)\n\n"
       "- **Stage A:** `present_flags.py` (the e2m flag scan), `worklist_r28a.py`, `spec_r28a.py`, `dotted_rows_r28a.py`.\n"
       "- **Stage B:** `apply_r28b.py`, `tokens_r28b.json`, `diff_flag_users_r28b.py` (the statement check).\n"
       "- **Closing:** `apply_r28_closing.py`.\n")
if "## Round 28:" not in t:
    i = t.index("## Round 27:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "one bitfield per fault - open: the task 046 leads",
     "one bitfield per fault; round 28: the sensor-present flags, the boot CAN ring state - open: the task 046 leads")
print("round 28 closing applied")
