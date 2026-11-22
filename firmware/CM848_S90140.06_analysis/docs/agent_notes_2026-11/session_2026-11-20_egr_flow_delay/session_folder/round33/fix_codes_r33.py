"""Round 33 fix: the status codes. The first pass listed only the destination-specific (RTS / CTS) session codes;
the messages whose builders test the status (EC1 / DM1 / DM2 / DM4 / RC) are PDU2 broadcasts, which take the BAM
branch of initiateJ1939TransportProtocol and j1939_transport_singleFrame_send: 0x10 announced / 0x11 sending / 5
complete / 2 a session already active for that source address. Rewrites the code list in the 30 status row comments
and the j1939_tx_msg_t.status_pointer comment; corrects task 046, the PR body and memory. Idempotent.
usage: fix_codes_r33.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
OLD = ("0 queued / 1 zero length / 4 CAN transmit queue full from mpc555_sendJ1939SingleFrame; the application "
       "transport's 0x12 started / 0x13 sending / 9 complete / 10 aborted / 6 clear to send timeout / 7 data frame "
       "send failed / 8 another session busy / 3 source address not ours")
NEW = ("the send result (0 queued / 1 zero length / 4 CAN transmit queue full) or a transport session code: a "
       "broadcast (BAM) session 0x10 announced / 0x11 sending / 5 complete / 2 already active for that source "
       "address; a destination-specific (RTS / CTS) session 0x12 started / 0x13 sending / 9 complete / 10 aborted / "
       "6 clear to send timeout / 7 send failed / 8 busy; 3 source address not ours (0x1x = a session in progress)")
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read()
n = g.count(OLD)
g = g.replace(OLD, NEW)
open(gp, "w").write(g)
sd = os.path.join(out, "structure_definitions.csv")
s = open(sd).read()
OLD_S = ("in the application mpc555_sendJ1939SingleFrame stores its result there and initiateJ1939TransportProtocol / "
         "the j1939_transport_* handlers their session codes through j1939_multiframe_tx_status_ptr (0x12 started / "
         "0x13 sending / 9 complete / 10 aborted / 6 clear to send timeout / 7 send failed / 8 busy / 3 not our "
         "source address); the multi-frame builders rebuild only while its 0xf0 nibble is clear.")
NEW_S = ("in the application mpc555_sendJ1939SingleFrame stores its result there (0 queued / 1 zero length / 4 queue "
         "full) and the transport its session codes: a broadcast (BAM) session through the per source address "
         "records at 0x3fbd74 (initiateJ1939TransportProtocol / j1939_transport_singleFrame_send: 0x10 announced / "
         "0x11 sending / 5 complete / 2 already active) and a destination-specific (RTS / CTS) session through "
         "j1939_multiframe_tx_status_ptr (0x12 started / 0x13 sending / 9 complete / 10 aborted / 6 clear to send "
         "timeout / 7 send failed / 8 busy); 3 = not our source address. The multi-frame builders rebuild only while "
         "its 0xf0 nibble is clear (no session in progress).")
if NEW_S not in s:
    assert s.count(OLD_S) == 1
    s = s.replace(OLD_S, NEW_S)
    open(sd, "w").write(s)


def edit(p, old, new):
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (p, old[:60])
    open(p, "w").write(t.replace(old, new))


task = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
edit(task, "    `mpc555_sendJ1939SingleFrame` stores its result there (0 queued / 1 zero length / 4 queue full), and the\n"
           "    application transport stores its session codes there (0x12 started / 0x13 sending / 9 complete / 10 "
           "aborted /\n    6 clear to send timeout / 7 send failed / 8 busy / 3 not our source address).",
     "    `mpc555_sendJ1939SingleFrame` stores its result there (0 queued / 1 zero length / 4 queue full), and the\n"
     "    application transport stores its session codes there. A broadcast (BAM) session, which every PF 0xFE "
     "message\n    takes, writes 0x10 announced / 0x11 sending / 5 complete / 2 already active. A destination-specific "
     "(RTS / CTS)\n    session writes 0x12 started / 0x13 sending / 9 complete / 10 aborted / 6 clear to send timeout / 7 "
     "send failed /\n    8 busy. Both write 3 for a source address that is not ours.\n"
     "  - The stage A commit message (and the first comments) listed only the RTS / CTS codes, although the five\n"
     "    builders' messages are broadcasts; the comments were corrected in the round 33 closing fix.\n"
     "  - The stage B commit message calls the cleared code units at 0x3fab40 / 0x3fab4c RAM-dump bytes that analysis\n"
     "    disassembled. That is an inference: no code unit there was listed.")
edit(task, "  - Round 34: the application J1939 transport transmit session (`j1939_multiframe_tx_*`, the `ptr` / `addr` / "
           "`len`\n    abbreviations) as a struct,",
     "  - Round 34: the application J1939 transport's two transmit mechanisms as structs: the RTS / CTS session\n"
     "    (`j1939_multiframe_tx_*`, the `ptr` / `addr` / `len` abbreviations) and the two 32-byte broadcast (BAM) "
     "session\n    records at 0x3fbd74 / 0x3fbd94 (named `j1939_tp_rx_session_*`, though they transmit). 0x3fbd7c is "
     "record 0's\n    advancing data pointer; its derived label `PTR_j1939_pgn65242_transmit_status_003fbd7c` only "
     "shows that the dump's\n    last broadcast was the 47-byte SOFT payload (0x3fae80 + 47). Also as a struct,")
edit(task, "  - 29 new `j1939_<message>_transmit_status` byte rows (all `lbz`), and DM1's misnamed",
     "  - 29 new `j1939_<message>_transmit_status` byte rows (all `lbz`; 31 status bytes with DM1's and stage B's "
     "65259), and DM1's misnamed")
edit(pr, "- **Stage A (3c495a2, labels):** the J1939 transmit descriptor's third field is the status pointer (was\n"
         "  `data_end_pointer`). 30 status bytes are named,",
     "- **Stage A (3c495a2, labels):** the J1939 transmit descriptor's third field is the status pointer (was\n"
     "  `data_end_pointer`): the send result or the broadcast / RTS-CTS session code, 0x1x while a session runs.\n"
     "  30 status bytes are named (31 with stage B's 65259),")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
for name, old, new in [
        ("MEMORY.md", "30 transmit status bytes", "31 transmit status bytes"),
        ("typing_focus_2026_11.md", "transport session code; builders gate on the 0xf0 nibble), 30 status bytes",
         "broadcast 0x10 / 0x11 / 5 or RTS-CTS 0x12 / 0x13 / 9 session code; builders gate on the 0xf0 nibble), 31 "
         "status bytes")]:
    p = M + name
    t = open(p).read()
    if new not in t:
        assert t.count(old) == 1, (name, old)
        open(p, "w").write(t.replace(old, new))
print(f"{n} status rows rewritten")
