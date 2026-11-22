"""Round 37 fix: stale or over-reaching text from rounds 33-36 (comments only). Idempotent; keeps line endings.
usage: fix_text_r37.py <repo>"""
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
        assert t.count(old) == 1, (rel, old[:70], t.count(old))
        t = t.replace(old, new)
    with open(p, "w", newline="") as fh:
        fh.write(t)


OUT = "firmware/CM848_S90140.06_analysis/output/"
edit(OUT + "structure_definitions.csv", [
    ("header is j1939_msg_hdr_t, so &msg.header is what cm848_transmitCanMessage takes",
     "header is j1939_msg_hdr_t (the boot kernel's cm848_transmitCanMessage takes its whole twin record "
     "diagnostic_response_message_t since PR #53 round 35)"),
    ("(125 % in 1/256 % units / rounded) in J1939 byte order",
     "in J1939 byte order (read as 125 % in 1/256 % units / an inference from the constant)"),
    ("# j1939_pgn65263_payload_t: the J1939 EFL/P1 (PGN 65263) payload: 8 bytes (PR #53 round 36)",
     "# j1939_pgn65263_payload_t: the J1939 EFL/P1 (PGN 65263) payload: 8 bytes (PR #53 round 36). Bytes 1 / 4 / 7 and the "
     "bytes 5-6 word are set by the code; the SPNs of bytes 2 / 3 / 8 follow the J1939-71 sequence (the databases give "
     "no positions)"),
])
edit("firmware/CLAUDE.md", [
    ("    (`mpc555_cmfEraseBlocks`). The build log now reads 19 thunks / 13 call overrides.",
     "    (`mpc555_cmfEraseBlocks`). The build log then read 19 thunks / 13 call overrides.\n"
     "  - PR #53 round 33 added one more: the CI (PGN 65259) payload `j1939_pgn65259_payload` covers the 3 boot calls to\n"
     "    the RAM copy of `mpc555_can2TransmitInterruptHandler` at 0x3fab3c. The build log now reads 18 thunks / 14 call\n"
     "    overrides."),
])
edit("work/tasks/046-cm848-egr-flow-estimate.md", [
    ("    - six of tables that another cache already names, which need a per-function word (one table is looked up from\n"
     "      five functions);",
     "    - six of tables that another cache already names, which need a per-function word (one table is looked up from\n"
     "      five functions). The cache that took the bare name gets renamed with its siblings;"),
])
print("ok")
