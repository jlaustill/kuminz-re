"""Round 33 stage A: the comment lines refresh_references.py does not reach. Idempotent; keeps line endings.
usage: fix_text_r33a.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])


def edit(rel, pairs):
    p = os.path.join(repo, rel)
    with open(p, newline="") as fh:
        t = fh.read()
    for old, new in pairs:
        if new in t:
            continue
        assert t.count(old) == 1, (rel, old[:60], t.count(old))
        t = t.replace(old, new)
    with open(p, "w", newline="") as fh:
        fh.write(t)


edit("firmware/CM848_S90140.06_analysis/output/structure_definitions.csv", [
    ("# J1939 TX Message Descriptor - complete outgoing J1939 message with inline payload\n"
     "# Self-referential: data_ptr = &this.control_byte, data_end_ptr = &this.control_byte + 8\n"
     "# 22 bytes total (6 header + 4 data_ptr + 4 data_end_ptr + 8 payload)\n",
     "# J1939 transmit descriptor. It began as the ACK message's 22-byte struct (header + two pointers + the 8-byte\n"
     "# payload), split 2026-11-18 into j1939_tx_msg_t and j1939_ack_payload. Its third pointer was read as a data end\n"
     "# pointer because the ACK status byte sits right after the payload (0x3faaaa + 8 = 0x3faab2): it is the status\n"
     "# pointer (PR #53 round 33)\n"),
    ("(j1939_ackm_msg at 0x3faa9c, j1939_pgn<N>_tx_message, ...)",
     "(j1939_pgn59392_tx_message at 0x3faa9c, j1939_pgn<N>_tx_message, ...)"),
])
edit("firmware/CLAUDE.md", [
    ("  - The ACK message keeps `j1939_pgn59392_tx_message` and its payload is `j1939_ack_payload` "
     "(`j1939_acknowledgement_payload_t`).",
     "  - The ACK message is `j1939_pgn59392_tx_message` (was `j1939_ackm_msg`; PR #53 round 33) and its payload is "
     "`j1939_ack_payload` (`j1939_acknowledgement_payload_t`).\n"
     "  - `status_pointer` (was `data_end_pointer`; PR #53 round 33) points at the message's status byte\n"
     "    `j1939_<message>_transmit_status`: the send result or the transport session code (`j1939_tx_msg_t` lists\n"
     "    the codes). The multi-frame builders (EC1, DM1, DM2, DM4, RC) rebuild their payload only while its 0xf0\n"
     "    nibble is clear."),
])
print("ok")
