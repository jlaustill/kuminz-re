"""Round 34 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r34_closing.py <repo> <pr_body.md> <hash A> <hash B> <hash C> <commit count>"""
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


T46 = f"""## Done, round 34 (2026-11-22, same PR): the application J1939 transport's transmit sessions

A peer relay started the round. Scripts are in `session_folder/round34/`.
- **Stage A ({ha}, labels):**
  - The transport functions: `cm848_sendJ1939BroadcastDataPacket` / `cm848_sendJ1939ConnectionModeDataPackets` /
    `cm848_serviceJ1939TransportSessions` / `cm848_initializeJ1939Transport`. They were
    `j1939_transport_singleFrame_send` / `_dataFrame_bulkSend` / `phase_group_a_triggerControllerUpdates` /
    `j1939_pgn_handler_init_ec00eb00`.
  - `j1939_broadcast_no_packet_delay_flag` (was `j1939_tp_bam_session_active`). The disassembly sets it only for PF
    and PS both 0xff (PGN 65535), and it turns the 5-pass packet delay to 0.
- **Stage B ({hb}, types):**
  - `j1939_broadcast_transmit_sessions[2]` of `j1939_broadcast_transmit_session_t`: the two 32-byte broadcast
    records per source address. They were `j1939_tp_rx_session_*` and DAT_, although they only transmit.
  - Two frame buffers.
  - The packet sender reads `j1939_broadcast_transmit_sessions[param_1].packet_delay_timer`. Round 33's misleading
    `PTR_j1939_pgn65242_transmit_status_003fbd7c` is gone.
- **Stage C ({hc}, types):**
  - The RTS / CTS transmit session has the boot twin's 28-byte layout, and its code is the twin's. It is the
    application instance `j1939_transport_transmit_session` of `j1939_transport_transmit_session_t`.
  - The type's pointer fields are `byte*`. The prototypes are `initiateJ1939TransportProtocol(j1939_tx_msg_t *msg)`
    and `mpc555_sendJ1939SingleFrame(can_id, data_length (ushort), data, result)`.
  - Casts: `(undefined1 *)` 100 -> 80.
  - `cm848_sendDataCollectorBuffer`'s wait loop (0x10 / 0x11 / 5) confirms the broadcast codes.
  - `j1939_multiframe_tx_active` (shared with CM550) stays flat.
- **Leads (round 35):**
  - The boot session's flag / destination bytes 0x302903 / 0x302904 are misnamed `qadc_a_queue_status_1` /
    `qadc_a_active_channel_id`, and stale `qadc_a_*` rows sit inside `boot_j1939_transport_transmit_session`.
    Check CM550 for the shared names first.
  - `mpc555_sendJ1939TransportRequestToSend` takes a `j1939_msg_hdr_t *` that is really a whole message record
    (`diagnostic_response_message_t`), so it reads `msg_header[1].can_id` as the data pointer.
  - The receive session `j1939_multiframe_rx_*` (0x3fbdef-0x3fbe00) as a struct.
  - Round 33's EFL/P1 `j1939_diag_response_word_b` and the stale +1 rows at 0x3faeb0-0x3faeb3.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 34.**\n"
     f"- **Stage A ({ha}, labels):** the transport's send / service / initialize functions and the PGN 65535 delay\n"
     "  flag named from the code.\n"
     f"- **Stage B ({hb}, types):** the two broadcast transmit session records as a struct array (were\n"
     "  `j1939_tp_rx_session_*` / DAT_).\n"
     f"- **Stage C ({hc}, types):** the RTS / CTS transmit session as the boot twin's type, that type's pointers as\n"
     "  `byte*`, and the prototypes of `initiateJ1939TransportProtocol` / `mpc555_sendJ1939SingleFrame`.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 33: stage A is EQUIVALENT",
     "- [x] Round 34: stage A is EQUIVALENT; stages B / C are token-equal apart from declaration reorders and 4 / 18\n"
     "  hand-read functions.\n- [x] Round 33: stage A is EQUIVALENT")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 34: the application J1939 transport's transmit sessions (`session_folder/round34/`)\n\n"
       "- `area_users.py` (who uses an address range). **Stage A:** `worklist_r34a.py`. **Stage B:** `apply_r34b.py`. "
       "**Stage C:** `apply_r34c.py`. The proofs reuse round 33's `diff_functions.py` / `check_reorders_r33b.py` and "
       "round 32's `flatten_cpp.py` / `make_tokens_r32a.py`. **Closing:** `apply_r34_closing.py`.\n")
if "## Round 34:" not in t:
    i = t.index("## Round 33:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 33: the J1939 transmit status bytes, the RC / CI / SOFT payload structs - open: the task "
                     "046 leads",
     "round 33: the J1939 transmit status bytes, the RC / CI / SOFT payload structs; round 34: the J1939 transport's "
     "transmit sessions as structs - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = m.replace("(cm848/egr-flow-delay-model, 173 commits)", f"(cm848/egr-flow-delay-model, {count} commits)")
old = ("(j1939_tx_msg_t.status_pointer was data_end_pointer: 31 transmit status bytes; the RC / CI / SOFT payload "
       "structs); task 046 leads")
new = ("(j1939_tx_msg_t.status_pointer was data_end_pointer: 31 transmit status bytes; the RC / CI / SOFT payload "
       "structs) + round 34 (the J1939 transport's broadcast records + RTS/CTS session as structs, the boot twin's "
       "type reused); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 34 (2026-11-22): {ha} / {hb} / {hc} the application J1939 transport: cm848_sendJ1939* senders "
        "named, j1939_broadcast_transmit_sessions[2] (32-byte BAM records, were tp_rx_*), the RTS/CTS session = an "
        "instance of the boot twin's j1939_transport_transmit_session_t (pointer fields byte*), initiator / single "
        "frame prototypes. Lessons: untype rows inside a new instance (file order); a new prototype renames callers' "
        "locals after its parameters (a local_variables row can go dead); ushort for 16-bit length params avoids "
        "(uint) casts. Next: the boot session's misnamed qadc_a_* bytes, the receive session.\n")
if "Round 34 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 34 closing applied")
