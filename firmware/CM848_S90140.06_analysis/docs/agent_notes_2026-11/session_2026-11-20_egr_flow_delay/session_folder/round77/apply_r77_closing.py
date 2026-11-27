"""Round 77 closing: task 046, PR body, session README, todo, memory. Idempotent (each edit skips when its new text is
already there).  usage: apply_r77_closing.py <repo> <pr_body.md> <hash A> <count> <proof A>"""
import os
import re
import sys

repo, pr, ha, count, proof_a_file = os.path.abspath(sys.argv[1]), *sys.argv[2:6]
proof_a = open(proof_a_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 77 (2026-11-23, same PR): CM550's malformed J1708 state structs; the J1708 bus timer

A peer relay started the round; the scripts are in `session_folder/round77/`. These are round 76's leads.
- **The scan:** `multi_address_structs.py` lists the structs whose field rows each carry their own address.
  ApplyStructures builds one type from all of a name's rows and puts an instance at every listed address. CM550 had 18
  such structs and CM848 has none.
- **Stage A ({ha}), CM550:** the worst two, `j1708_tx_state_t` / `j1708_rx_state_t`, are removed.
  - The receive type's instance at its last field's address, 0x80DCAF, covered the J1708 globals at 0x80DCB0-0x80DCBC.
    Their 61 accesses rendered as pieces of it.
  - The globals are typed from their m68k accesses: the six buffer pointers are dwords, the flags and counters bytes,
    and the transmit state a dword. That drops the pointers' `_` prefixes.
  - `j1708_message_checksum` (0x80DCB3): the SCI interrupt handler adds every byte and sends ~sum + 1.
  - `j1708_bus_timer_armed_flag` (0x80DCBA, was `j1708_tpu_channel_active`).
  - Two functions are renamed for what they drive, the CTM4 MCSM11 timer rather than a TPU channel:
    - `mc68k_armJ1708BusTimer` (was `mc68k_tpuTimerChannelEnable`). Its void prototype replaces a never-read
      `channel_mask` parameter, which had given the SCI interrupt handler a bogus `channel_mask = (word)in_D0`.
    - `mc68k_j1708BusTimerInterruptHandler` (was `mc68k_tpuChannelStateMachine`): the MCSM11 interrupt handler, which
      closes received messages and starts pending transmissions.
  - **Proof:** {proof_a}
- **firmware/CLAUDE.md:** none.
- **Leads:**
  - **The other 16 multi-address structs:** most are the declared types of existing globals (`engine_rpm_buffer_t` on
    `current_engine_rpm`, `scheduler_control_t`, `fuel_arbitrator_diag_t`, ...). Each needs its own reading: a real
    struct with one address and markers, or flat globals.
  - `j1708_pending_abort_count`: the bus timer interrupt handler adds 1 when it closes a message of 3 or more bytes and
    writes a 2 / 6 / 0x74 record. The name is not checked against that.
  - The pointer low-byte labels inside the typed pointers (`j1708_receive_buffer_index_low`,
    `j1708_transmit_buffer_index_low`) no longer render; their roles are in the pointer comments.
  - From round 76: the external devices at 0xFFC800 / 0xFFD000 / 0xFFD800, and the 1280-byte parameter buffer at
    0x80C7A8.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 77.**\n"
     f"- **Stage A ({ha}):** CM550's malformed J1708 state structs (one instance covered 61 accesses to separate globals)\n"
     "  are removed. The J1708 driver's globals are typed from their m68k accesses, and the CTM4 bus timer functions are\n"
     "  named for what they drive.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-76):**", "- **Beyond CM848 (rounds 72-77):**")
edit(pr, "- [x] Round 76:", f"- [x] Round 77: A: {proof_a}\n- [x] Round 76:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 77: CM550's malformed J1708 state structs; the J1708 bus timer (`session_folder/round77/`)\n\n"
       "- **Stage A (CM550):** `multi_address_structs.py` (structs whose field rows carry several addresses),\n"
       "  `apply_r77a.py` (the two J1708 state structs removed and the globals typed), `apply_r77a2.py` (the bus timer\n"
       "  functions, flag and prototype), `map_r77a2.csv`.\n"
       "- **Proof:** `prove_r77a_cm550.py` and `statements_r77a_cm550.py` (a statement-level comparison that line wrapping\n"
       "  cannot fool). **Closing:** `apply_r77_closing.py`, `update_large_tar_r77.sh`.\n")
if "## Round 77:" not in t:
    i = t.index("## Round 76:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 76: CM550's MC68336 register map - open: the task 046 leads",
     "round 76: CM550's MC68336 register map; round 77: CM550's malformed J1708 state structs, the J1708 bus timer - "
     "open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the external chips at 0xFFC800 / 0xFFD000 / 0xFFD800); task 046 leads"
new = ("the external chips at 0xFFC800 / 0xFFD000 / 0xFFD800) + round 77 (CM550 had 18 structs with a separate address on "
       "each field row - one oversize type + an instance per row, CM848 none, r77/multi_address_structs.py; the J1708 "
       "state pair removed - its 0x80DCAF instance covered 61 accesses; mc68k_armJ1708BusTimer / "
       "mc68k_j1708BusTimerInterruptHandler = CTM4 MCSM11, not TPU; 16 such structs left); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
print("round 77 closing applied")
