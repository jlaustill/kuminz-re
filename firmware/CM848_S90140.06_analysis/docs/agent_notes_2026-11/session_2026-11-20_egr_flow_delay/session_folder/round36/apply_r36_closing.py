"""Round 36 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r36_closing.py <repo> <pr_body.md> <hash A> <hash B> <commit count>"""
import os
import sys

repo, pr, ha, hb, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 36 (2026-11-22, same PR): two more payloads and the boot diagnostic request path

A peer relay started the round. Scripts are in `session_folder/round36/`.
- **Stage A ({ha}, types):**
  - The EFL/P1 (PGN 65263) payload. The word at bytes 5-6 is SPN 101 crankcase pressure (was
    `j1939_diag_response_word_b`), and byte 3 (oil level) is never written.
  - The PGN 65504 payload: engine speed and net output torque, then the main injection timing XOR-scrambled with a
    key from the time base (`TBLr`) into bytes 5 / 6 / 8.
- **Stage B ({hb}, prototypes):**
  - `cm848_sendDiagServiceResponse(j1939_rx_msg_t *request, dword result_code)`.
  - `cm848_dispatchDiagnosticService(j1939_rx_msg_t *request)`. Its old (service_code, data_ptr, data_length) rows
    made the boot data packet handler's call print a service code 0x2d, which was really the low byte of the receive
    session's message view 0x30292d (the disassembly: `addi r3,r31,8`).
  - `mpc555_sendJ1939TransportEndOfMessageAcknowledge(destination_address, transported_pgn)`.
- **Leads:**
  - Type `eeprom_diag_callback` / `diag_write_request_state.pending_request` as `j1939_rx_msg_t *`. They store
    requests, and four calls now cast them.
  - The next functions on `messy_functions.py`'s ranking (round 32).

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 36.**\n"
     f"- **Stage A ({ha}, types):** the EFL/P1 (PGN 65263) and PGN 65504 payloads as structs (SPN 101 crankcase\n"
     "  pressure was `j1939_diag_response_word_b`; PGN 65504 carries a time-base-scrambled injection timing).\n"
     f"- **Stage B ({hb}, prototypes):** the boot diagnostic request path. The dispatcher's old rows printed a fake\n"
     "  service code 0x2d (the low byte of the receive session's message view).\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 35: stage A is EQUIVALENT",
     "- [x] Round 36: stages A / B are token-equal apart from the 2 / 9 hand-read functions and one declaration\n"
     "  reorder.\n- [x] Round 35: stage A is EQUIVALENT")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 36: two payloads and the boot diagnostic request path (`session_folder/round36/`)\n\n"
       "- **Stage A:** `apply_r36a.py`. **Stage B:** the prototype rows (in the commit). **Closing:** "
       "`apply_r36_closing.py`.\n")
if "## Round 36:" not in t:
    i = t.index("## Round 35:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 35: the boot transport and the receive session - open: the task 046 leads",
     "round 35: the boot transport and the receive session; round 36: EFL/P1 + PGN 65504 payloads, the boot "
     "diagnostic request path - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = m.replace("(cm848/egr-flow-delay-model, 181 commits)", f"(cm848/egr-flow-delay-model, {count} commits)")
old = ("both _pad2 fields; the boot record / diagnostic chain prototypes); task 046 leads")
new = ("both _pad2 fields; the boot record / diagnostic chain prototypes) + round 36 (EFL/P1 + PGN 65504 payloads; "
       "the boot diagnostic request prototypes: a fake service code 0x2d was a pointer's low byte); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 36 (2026-11-22): {ha} the EFL/P1 / PGN 65504 payload structs (65504 scrambles the injection timing "
        f"with TBLr); {hb} cm848_dispatchDiagnosticService / cm848_sendDiagServiceResponse / the boot EoMA sender "
        "take the j1939_rx_msg_t record (a byte-typed first parameter hid a pointer: the call showed its low byte "
        "as a constant). Lesson: a CONCAT31(in_register, param) in a body means the parameter is wider than "
        "declared - check the call site's disassembly.\n")
if "Round 36 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 36 closing applied")
