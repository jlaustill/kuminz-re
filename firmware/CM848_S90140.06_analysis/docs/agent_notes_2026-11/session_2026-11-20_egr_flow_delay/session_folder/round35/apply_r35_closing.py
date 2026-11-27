"""Round 35 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r35_closing.py <repo> <pr_body.md> <hash A> <hash B> <hash C> <commit count>"""
import os
import sys

repo, pr, ha, hb, hc, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5], \
    sys.argv[6]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 35 (2026-11-22, same PR): the boot kernel's J1939 transport and the receive session

A peer relay started the round. Scripts are in `session_folder/round35/`.
- **Stage A ({ha}, labels):** the boot kernel's transport state at 0x302903-0x302934 carried QADC names.
  0x302903 / 0x302904 are `boot_j1939_transport_transmit_active` / `_destination_address`, the twins of the
  application's flat bytes. Eight stale `qadc_a_*` rows inside `boot_j1939_transport_transmit_session` became dotted
  rows.
- **Stage B ({hb}, types):**
  - Both kernels' receive session: `j1939_transport_receive_session_t` (18 bytes). The two kernels' handlers access
    it at the same offsets and widths.
  - The boot instance replaces `j1939_tp_pause_t` (whose `_pad2` word was the next packet number and the granted
    packet count) and flat `qadc_a_*` rows. The application instance replaces `j1939_multiframe_rx_*`.
  - `eeprom_block_tracking._pad2` is `failed_write_authorization_count` (`cm848_validateWriteAuth`).
  - No `_pad2` renders any more, and pieces went 1412 -> 1402.
- **Stage C ({hc}, prototypes):**
  - The boot record senders take a `diagnostic_response_message_t *`. Their old rows made the callers pass a leftover
    r4 and an unset r5.
  - `mpc555_canTransmitQueuePush` has a prototype.
  - The diagnostic service chain takes a `j1939_rx_msg_t *`. The application transport hands it the receive record's
    tail from +8 as the received message.
  - Two widths stay dword: a 16-bit / 8-bit parameter there printed `CONCAT22` / `CONCAT31` with a phantom register
    half.
- **Leads (round 36):**
  - `cm848_sendDiagServiceResponse` (the boot twin of `cm848_sendJ1939ResponseFrame`) still takes its request as raw
    bytes.
  - Round 33's EFL/P1 `j1939_diag_response_word_b` and the stale +1 rows at 0x3faeb0-0x3faeb3.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 35.**\n"
     f"- **Stage A ({ha}, labels):** the boot kernel's transmit session flag / destination (were QADC names).\n"
     f"- **Stage B ({hb}, types):** the J1939 transport receive session as one type with boot and application\n"
     "  instances (were `j1939_tp_pause_t` / `qadc_a_*` / `j1939_multiframe_rx_*`); both `_pad2` fields named.\n"
     f"- **Stage C ({hc}, prototypes):** the boot record senders, the boot queue push and the diagnostic service chain.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 34: stage A is EQUIVALENT",
     "- [x] Round 35: stage A is EQUIVALENT; stages B / C are token-equal apart from declaration reorders and 8 / 16\n"
     "  hand-read functions.\n- [x] Round 34: stage A is EQUIVALENT")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 35: the boot kernel's J1939 transport and the receive session (`session_folder/round35/`)\n\n"
       "- **Stage A:** `apply_r35a.py`. **Stage B:** `apply_r35b.py`. **Stage C:** `apply_r35c.py` (its first run was "
       "not idempotent: the clean-up is in the stage C commit message). **Closing:** `apply_r35_closing.py`.\n")
if "## Round 35:" not in t:
    i = t.index("## Round 34:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 34: the J1939 transport's transmit sessions as structs - open: the task 046 leads",
     "round 34: the J1939 transport's transmit sessions as structs; round 35: the boot transport and the receive "
     "session - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = m.replace("(cm848/egr-flow-delay-model, 177 commits)", f"(cm848/egr-flow-delay-model, {count} commits)")
old = ("+ round 34 (the J1939 transport's broadcast records + RTS/CTS session as structs, the boot twin's type reused); "
       "task 046 leads")
new = ("+ round 34 (the J1939 transport's broadcast records + RTS/CTS session as structs, the boot twin's type reused) "
       "+ round 35 (the boot transport's QADC-named bytes; j1939_transport_receive_session_t for both kernels; both "
       "_pad2 fields; the boot record / diagnostic chain prototypes); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 35 (2026-11-22): {ha} / {hb} / {hc} the boot kernel's transport (0x302903-0x302934 were qadc_a_* "
        "names), j1939_transport_receive_session_t with boot + app instances (j1939_tp_pause_t._pad2 = next packet / "
        "granted count; eeprom_block_tracking._pad2 = failed_write_authorization_count), prototypes for the boot "
        "record senders + diagnostic chain (j1939_rx_msg_t). Lessons: a 16-/8-bit parameter whose body uses the "
        "whole register prints CONCAT22/31 with a phantom half - keep dword; a field row in a refresh map renames "
        "matching text in CLAUDE.md tables too; make apply scripts idempotent before the second run.\n")
if "Round 35 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 35 closing applied")
